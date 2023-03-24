/*
 * mm-naive.c - The fastest, least memory-efficient malloc package.
 *
 * In this naive approach, a block is allocated by simply incrementing
 * the brk pointer.  A block is pure payload. There are no headers or
 * footers.  Blocks are never coalesced or reused. Realloc is
 * implemented directly using mm_malloc and mm_free.
 *
 * NOTE TO STUDENTS: Replace this header comment with your own header
 * comment that gives a high level description of your solution.
 */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "mm.h"
#include "memlib.h"

/*********************************************************
 * NOTE TO STUDENTS: Before you do anything else, please
 * provide your team information in the following struct.
 ********************************************************/
team_t team = {
    /* Team name */
    "Captain Rou",
    /* First member's full name */
    "Rou Ba",
    /* First member's email address */
    "rouba@163.com",
    /* Second member's full name (leave blank if none) */
    "",
    /* Second member's email address (leave blank if none) */
    ""
};

/* single word (4) or double word (8) alignment */
#define ALIGNMENT DSIZE

/* rounds up to the nearest multiple of ALIGNMENT */
#define ALIGN(size) (((size) + (ALIGNMENT) + (ALIGNMENT-1)) & ~0x7)

#define MIN_SIZE (ALIGN(sizeof(size_t)))
#define FREE_LIST_SIZE 32

#define GET_NEXT_FREE(fp) (*(void **)(fp))
#define GET_PREV_FREE(fp) (*((void **)(fp) + 1))
#define PUT_NEXT_FREE(fp, val) (*(void **)(fp) = (val))
#define PUT_PREV_FREE(fp, val) (*((void **)(fp) + 1) = (val))

/* global heap pointer */
static void *heapListp;

/* explicit free list: pointer to free block */
static void **freeListp;

static unsigned aCount = 0;

enum { FREE, ALLOC, REALLOC, EXTEND } MM_CHECK_TYPE;
enum { UNKNOWN, NONE, PREV, NEXT, BOTH } COALESCE_TYPE;

static void *extend_heap(size_t size);
static void mm_check(unsigned char, void *, size_t);
static void *coalesce(void *bp);
static char getFreeListIndex(size_t size);
static void *update(void *bp, size_t csize, size_t nsize);
static void *insert(void *);
static void delete(void *, size_t);
static void *findFit(size_t);
static void *findReallocFit(void *bp, size_t psize, size_t asize);
static void *updateRe(void *bp, size_t currentSize, size_t nextSize, char type);

/*
 * mm_init - initialize the malloc package.
 */
int mm_init(void) {
  if((heapListp = mem_sbrk(FREE_LIST_SIZE * ALIGNMENT + 4 * WSIZE)) == (void *)-1)
    return -1;

  PUT(heapListp, 0);

  /* Explicit free block */
  freeListp = heapListp + WSIZE;
  for(int i = 0; i < FREE_LIST_SIZE; i++)
    *(freeListp + i) = NULL;

  PUT(heapListp + FREE_LIST_SIZE * ALIGNMENT + 1*WSIZE, PACK(DSIZE, 1)); /* Prologue header */
  PUT(heapListp + FREE_LIST_SIZE * ALIGNMENT + 2*WSIZE, PACK(DSIZE, 1)); /* Prologue footer */
  PUT(heapListp + FREE_LIST_SIZE * ALIGNMENT + 3*WSIZE, PACK(0, 1));     /* Epilogue header */
  heapListp += (FREE_LIST_SIZE * ALIGNMENT + 2*WSIZE);

  if(extend_heap(CHUNKSIZE) == NULL)
    return -1;

  return 0;
}

/*
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size) {
  size_t asize = ALIGN(size);
  char *p = findFit(asize);
  int nleft;

  if (p == NULL)
    return NULL;

  size_t psize = GET_SIZE(HDRP(p));
  delete(p, psize);

  PUT(HDRP(p), PACK(asize, 1));
  PUT(FTRP(p), PACK(asize, 1));

  // Splitting
  if((nleft = psize - asize) > 0) {
    char *sp = NEXT_BLKP(p);
    PUT(HDRP(sp), PACK(nleft, 0));
    PUT(FTRP(sp), PACK(nleft, 0));

    if(nleft >= MIN_SIZE)
      insert(sp);
  }

  // mm_check(ALLOC, p, psize);

  return p;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr) {
  size_t size = GET_SIZE(HDRP(ptr));
  // mm_check(FREE, ptr, size);

  PUT(HDRP(ptr), PACK(size, 0));
  PUT(FTRP(ptr), PACK(size, 0));
  coalesce(ptr);
}

static void *extend_heap(size_t size) {
  char *bp;

  if ((long)(bp = mem_sbrk(size)) == -1)
    return NULL;

  PUT(HDRP(bp), PACK(size, 0));         /* Block header */
  PUT(FTRP(bp), PACK(size, 0));         /* Block footer */
  PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1)); /* Epilogue */

  return coalesce(bp);
}

/*
 * init_freeListp - init explicit segregated free list by given size type.
 */
static void mm_check(unsigned char type, void *bp, size_t asize) {
  switch (type) {
    case FREE:
      printf("F[%3u]: %p(%d), %p(%d)\n", aCount-1, HDRP(bp), GET_SIZE(HDRP(bp)), FTRP(bp), GET_SIZE(FTRP(bp)));
      break;
    case ALLOC:
      printf("A[%3u]: %p(%ld), %p(%d), %p(%d)\n", aCount++, bp, asize, HDRP(bp), GET_SIZE(HDRP(bp)), FTRP(bp), GET_SIZE(FTRP(bp)));
      break;
    case REALLOC:
      printf("R[%3u]: %p(%ld), %p(%d), %p(%d)\n", aCount-1, bp, asize, HDRP(bp), GET_SIZE(HDRP(bp)), FTRP(bp), GET_SIZE(FTRP(bp)));
      break;
    case EXTEND:
      printf("mm_check: EXTEND\n");
      printf(" EXTEND address : %p\n", bp);
      printf(" EXTENDED HEADER: %p\n", HDRP(bp));
      printf(" EXTENDED FOOTER: %p\n", FTRP(bp));
      printf(" EXTENDED SIZE  : %d\n", GET_SIZE(HDRP(bp)));
      printf(" NEXT BLOCK     : %p\n", NEXT_BLKP(bp));
      printf("mm_check: EXTEND end\n");
      break;
    default:
      printf("mm_check: UNKNOWN[%d]\n", type);
      printf("mm_check: UNKNOWN end\n");
  }
}

/*
 * coalesce - init explicit segregated free list by given size type.
 */
static void *coalesce(void *bp) {
  void *prev = PREV_BLKP(bp);
  void *next = NEXT_BLKP(bp);
  size_t tempSize, newSize;

  if(GET_ALLOC(HDRP(prev))) {
    if(GET_ALLOC(HDRP(next)))
      return insert(bp);

    tempSize = GET_SIZE(HDRP(next));
    newSize = GET_SIZE(HDRP(bp)) + tempSize;

    if(tempSize >= MIN_SIZE)
      delete(next, tempSize);

    PUT(HDRP(bp), PACK(newSize, 0));
    PUT(FTRP(bp), PACK(newSize, 0));
    return insert(bp);
  }

  if(GET_ALLOC(HDRP(next)))
    newSize = GET_SIZE(HDRP(bp)) + GET_SIZE(HDRP(prev));
  else {
    tempSize = GET_SIZE(HDRP(next));
    newSize = GET_SIZE(HDRP(bp)) + GET_SIZE(HDRP(prev)) + tempSize;

    if(tempSize >= MIN_SIZE)
      delete(next, tempSize);
  }

  tempSize = GET_SIZE(HDRP(prev));
  PUT(HDRP(prev), PACK(newSize, 0));
  PUT(FTRP(prev), PACK(newSize, 0));
  return update(prev, tempSize, newSize);
}

// TODO: try sth here!
static char getFreeListIndex(size_t base) {
  char x = 0;
  while(base >= MIN_SIZE) {
    base >>= 1;
    x++;
  }

  return x;
}

static void *update(void *bp, size_t currentSize, size_t nextSize) {
  char currentIndex = getFreeListIndex(currentSize);
  char nextIndex = getFreeListIndex(nextSize);
  void *lp;

  // If next and current in the diff freeList, delete current first.
  if(nextIndex != currentIndex) {
    void *prev, *next;

    if(currentIndex > 1) {
      // NOT the first element in freeList
      if((prev = GET_PREV_FREE(bp)) != NULL) {
        // has next
        if((next = GET_NEXT_FREE(bp)) != NULL) {
          PUT_NEXT_FREE(prev, next);
          PUT_PREV_FREE(next, prev);
        }
        // the last element in freeList
        else
          PUT_NEXT_FREE(prev, NULL);
      }
      // the first element in freeList
      else if((next = GET_NEXT_FREE(bp)) != NULL) {
        PUT_PREV_FREE(next, NULL);
        *(freeListp + currentIndex) = next;
      }
      // the ONLY one in freeList
      else
        *(freeListp + currentIndex) = NULL;
    }
    // free block size = 1
    else if (currentIndex == 1) {
      lp = *(freeListp + currentIndex);

      if(lp == bp)
        *(freeListp + currentIndex) = GET_NEXT_FREE(bp);
      else {
        while(GET_NEXT_FREE(lp) != bp)
          lp = GET_NEXT_FREE(lp);

        PUT_NEXT_FREE(lp, GET_NEXT_FREE(bp));
      }
    }
  }

  lp = *(freeListp + nextIndex);

  // If next freeList is not initialized yet, init it with bp.
  if(lp == NULL) {
    PUT_NEXT_FREE(bp, NULL);
    if(nextIndex > 1)
      PUT_PREV_FREE(bp, NULL);
    return *(freeListp + nextIndex) = bp;
  }

  // free block size > 1
  if(nextIndex > 1) {
    // NOT insert in the first
    if(lp < bp) {
      while(lp < bp && GET_NEXT_FREE(lp))
        lp = GET_NEXT_FREE(lp);
      // insert in the last
      if(lp < bp) {
        PUT_NEXT_FREE(lp, bp);
        PUT_PREV_FREE(bp, lp);
        PUT_NEXT_FREE(bp, NULL);
      }
      // insert in the middle
      else if(lp > bp) {
        PUT_NEXT_FREE(GET_PREV_FREE(lp), bp);
        PUT_NEXT_FREE(bp, lp);
        PUT_PREV_FREE(bp, GET_PREV_FREE(lp));
        PUT_PREV_FREE(lp, bp);
      }
    }
    // insert in the first
    else if(lp > bp) {
      PUT_NEXT_FREE(bp, lp);
      PUT_PREV_FREE(lp, bp);
      PUT_PREV_FREE(bp, NULL);
      *(freeListp + nextIndex) = bp;
    }
  }
  // free block size = 1
  else {
    PUT_NEXT_FREE(bp, lp);
    *(freeListp + nextIndex) = bp;
  }

  return bp;
}

static void *insert(void *bp) {
  char index = getFreeListIndex(GET_SIZE(HDRP(bp)));
  void *lp = *(freeListp + index);

  if(lp == NULL) {
    PUT_NEXT_FREE(bp, NULL);
    if(index > 1)
      PUT_PREV_FREE(bp, NULL);
    return *(freeListp + index) = bp;
  }

  // free block size > 1 that has enough space to save dual-linkes(prev and next)
  if(index > 1) {
    if(lp < bp) {
      while(lp < bp && GET_NEXT_FREE(lp))
        lp = GET_NEXT_FREE(lp);

      // insert bp at the last of the list
      if(lp < bp) {
        PUT_NEXT_FREE(lp, bp);
        PUT_PREV_FREE(bp, lp);
        PUT_NEXT_FREE(bp, NULL);
      }
      else if(lp > bp) {
        // Dual-Linklist insertion
        PUT_NEXT_FREE(GET_PREV_FREE(lp), bp);
        PUT_NEXT_FREE(bp, lp);
        PUT_PREV_FREE(bp, GET_PREV_FREE(lp));
        PUT_PREV_FREE(lp, bp);
      }
    }
    // insert in the first
    else if(lp > bp) {
      PUT_NEXT_FREE(bp, lp);
      PUT_PREV_FREE(lp, bp);
      PUT_PREV_FREE(bp, NULL);
      *(freeListp + index) = bp;
    }
  }
  // free block size = 1
  else {
    PUT_NEXT_FREE(bp, lp);
    *(freeListp + index) = bp;
  }

  return bp;
}

static void delete(void *bp, size_t size) {
  if(size < MIN_SIZE)
    return;

  void *prev, *next;
  char index = getFreeListIndex(size);

  if(index > 1) {
    // NOT the first element in freeList
    if((prev = GET_PREV_FREE(bp)) != NULL) {
      // has next
      if((next = GET_NEXT_FREE(bp)) != NULL) {
        PUT_NEXT_FREE(prev, next);
        PUT_PREV_FREE(next, prev);
      }
      // the last element in freeList
      else
        PUT_NEXT_FREE(prev, NULL);
    }
    // the first element in freeList
    else {
      // has next
      if((next = GET_NEXT_FREE(bp)) != NULL) {
        PUT_PREV_FREE(next, NULL);
        *(freeListp + index) = next;
      }
      // the ONLY one in freeList
      else
        *(freeListp + index) = NULL;
    }

    PUT_NEXT_FREE(bp, NULL);
    PUT_PREV_FREE(bp, NULL);
  } else {
    char *lp = *(freeListp + index);

    if(lp == bp)
      *(freeListp + index) = GET_NEXT_FREE(bp);
    else {
      while(GET_NEXT_FREE(lp) != bp)
        lp = GET_NEXT_FREE(lp);

      PUT_NEXT_FREE(lp, GET_NEXT_FREE(bp));
    }

    PUT_NEXT_FREE(bp, NULL);
  }
}

static void *findFit(size_t size) {
  for(char i = getFreeListIndex(size); i < FREE_LIST_SIZE; i++)
    if(*(freeListp + i) != NULL)
      for(char *fp = *(freeListp + i); fp != NULL; fp = GET_NEXT_FREE(fp))
        if(GET_SIZE(HDRP(fp)) >= size)
          return fp;

  return extend_heap(size);
}

void *mm_realloc(void *p, size_t size) {
  // mm_check(REALLOC, p, size);
  if(p == NULL)
    return mm_malloc(size);
  if(size == 0) {
    mm_free(p);
    return p;
  }

  size_t currentSize = GET_SIZE(HDRP(p));
  size_t asize = ALIGN(size);

  // if the new size < psize, takes the original p as found
  if(currentSize > asize)
    return findReallocFit(p, currentSize, asize);

  if(currentSize < asize) {
    void *prev = PREV_BLKP(p);
    void *next = NEXT_BLKP(p);
    size_t newSize;

    if(GET_ALLOC(HDRP(prev))) {
      // Case1: prev and next both alloced.
      if(GET_ALLOC(HDRP(next)))
        return updateRe(p, currentSize, asize, NONE);

      newSize = currentSize + GET_SIZE(HDRP(next));
      // Case2-1: next is free but doesn't have enough size.
      if(newSize < asize)
        return updateRe(p, currentSize, asize, NEXT);

      // Case2-2: next is free and enough for realloc.
      delete(next, GET_SIZE(HDRP(next)));
      return findReallocFit(p, newSize, asize);
    }

    if(GET_ALLOC(HDRP(next))) {
      newSize = currentSize + GET_SIZE(HDRP(prev));
      // Case3-1: prev is free but doesn't have enough size.
      if(newSize < asize)
        return updateRe(p, currentSize, asize, PREV);

      // Case3-2: prev is free and enough for realloc.
      delete(prev, GET_SIZE(HDRP(prev)));
      memmove(prev, p, currentSize - DSIZE);
      findReallocFit(prev, newSize, asize);
      return prev;
    }

    newSize = currentSize + GET_SIZE(HDRP(prev)) + GET_SIZE(HDRP(next));
    if(newSize < asize)
      return updateRe(p, currentSize, asize, BOTH);

    delete(prev, GET_SIZE(HDRP(prev)));
    delete(next, GET_SIZE(HDRP(next)));
    memmove(prev, p, currentSize - DSIZE);
    findReallocFit(prev, newSize, asize);
    return prev;
  }

  return p;
}

static void *findReallocFit(void *bp, size_t psize, size_t asize) {
  ssize_t nleft;

  PUT(HDRP(bp), PACK(asize, 1));
  PUT(FTRP(bp), PACK(asize, 1));

  // Splitting
  if((nleft = psize - asize) > 0) {
    char *sp = NEXT_BLKP(bp);
    PUT(HDRP(sp), PACK(nleft, 0));
    PUT(FTRP(sp), PACK(nleft, 0));

    if(nleft >= MIN_SIZE)
      insert(sp);
  }

  return bp;
}

static void *updateRe(void *bp, size_t currentSize, size_t nextSize, char type) {
  char *newbp = mm_malloc(nextSize);

  if (newbp == NULL)
    return NULL;

  memcpy(newbp, bp, currentSize - DSIZE);
  mm_free(bp);
  // memset(bp, 0, currentSize - DSIZE);
  /*
  switch (type) {
    case NONE:
      PUT(HDRP(bp), PACK(asize, 0));
      PUT(FTRP(bp), PACK(asize, 0));
      insert(bp);
      break;
    case PREV:
      break;
    case NEXT:
      break;
    case BOTH:
      break;
    default:
      printf("UNKNOWN type: %d\n", type);
  }
  */

  return newbp;
}
