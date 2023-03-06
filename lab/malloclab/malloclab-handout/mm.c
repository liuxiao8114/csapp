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

enum { INIT, FREE, ALLOC, REALLOC, EXTEND, FREE_INSERT, FREE_UPDATE, FREE_DELETE } MM_CHECK_TYPE;

static void *extend_heap(size_t size);
static void mm_check(unsigned char, void *, size_t);
static void *coalesce(void *bp);
static char getFreeListIndex(size_t size);
static void *update(void *bp, size_t csize, size_t nsize);
static void *insert(void *);
static void delete(void *);
static void deleteWithSize(void *, size_t);
static void *findFit(size_t);

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

  // mm_check(INIT, NULL, 0);
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

  if (p == NULL)
    return NULL;

  size_t psize = GET_SIZE(HDRP(p));

  delete(p);
  PUT(HDRP(p), PACK(asize, 1));
  PUT(FTRP(p), PACK(asize, 1));

  // Splitting
  if(psize > asize) {
    char *sp = NEXT_BLKP(p);
    PUT(HDRP(sp), PACK(psize - asize, 0));
    PUT(FTRP(sp), PACK(psize - asize, 0));
    insert(sp);
  }

  mm_check(ALLOC, p, psize);

  return p;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr) {
  size_t size = GET_SIZE(HDRP(ptr));
  mm_check(FREE, ptr, size);

  PUT(HDRP(ptr), PACK(size, 0));
  PUT(FTRP(ptr), PACK(size, 0));
  coalesce(ptr);
}

static void *extend_heap(size_t size) {
  char *bp;

  if ((long)(bp = mem_sbrk(size)) == -1)
    return NULL;

  // printf("extend_heap(%p: %ld)\n", bp, size);

  PUT(HDRP(bp), PACK(size, 0));         /* Block header */
  PUT(FTRP(bp), PACK(size, 0));         /* Block footer */
  PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));  /* Epilogue */

  // mm_check(EXTEND, bp, size);
  return coalesce(bp);
}

/*
 * init_freeListp - init explicit segregated free list by given size type.
 */
static void mm_check(unsigned char type, void *bp, size_t asize) {
  printf("------------------------------------------------\n");
  switch (type) {
    case INIT:
      printf("mm_check: INIT\n");
      printf(" heapListp start at addr: %p\n", heapListp);
      printf(" freeListp start at addr: %p\n", freeListp);
      printf("mm_check: INIT end\n");
      break;
    case FREE:
      printf("mm_check: FREE\n");
      printf(" HDRP addr(GET_SIZE)     : %p(%d)\n", HDRP(bp), GET_SIZE(HDRP(bp)));
      printf(" FTRP addr(GET_SIZE)     : %p(%d)\n", FTRP(bp), GET_SIZE(FTRP(bp)));
      printf("mm_check end\n");
      break;
    case ALLOC:
      printf("mm_check: ALLOC\n");
      printf(" alloc at addr(fit size) : %p(%ld)\n", bp, asize);
      printf(" HDRP addr(GET_SIZE)     : %p(%d)\n", HDRP(bp), GET_SIZE(HDRP(bp)));
      printf(" FTRP addr(GET_SIZE)     : %p(%d)\n", FTRP(bp), GET_SIZE(FTRP(bp)));
      printf("mm_check end\n");
      break;
    case REALLOC:
      printf("mm_check: REALLOC\n");
      printf("mm_check end\n");
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
  printf("------------------------------------------------\n");
}

/*
 * coalesce - init explicit segregated free list by given size type.
 */
static void *coalesce(void *bp) {
  void *prev = PREV_BLKP(bp);
  void *next = NEXT_BLKP(bp);
  size_t currentSize, newSize;

  if(GET_ALLOC(HDRP(prev))) {
    if(GET_ALLOC(HDRP(next))) {
      // printf("coalesce pattern [1]: Both prev and next are allocated.\n");
      return insert(bp);
    }

    newSize = GET_SIZE(HDRP(bp)) + GET_SIZE(HDRP(next));
    delete(next);
    PUT(HDRP(bp), PACK(newSize, 0));
    PUT(FTRP(bp), PACK(newSize, 0));
    // printf("coalesce pattern [2]: Prev is allocated and next is free.\n");
    return insert(bp);
  }

  if(GET_ALLOC(HDRP(next))) {
    // printf("coalesce pattern [3]: Next is allocated and prev is free.\n");
    newSize = GET_SIZE(HDRP(bp)) + GET_SIZE(HDRP(prev));
  }
  else {
    // printf("coalesce pattern [4]: Both prev and next are free.\n");
    newSize = GET_SIZE(HDRP(bp)) + GET_SIZE(HDRP(prev)) + GET_SIZE(HDRP(next));
    delete(next);
  }

  currentSize = GET_SIZE(HDRP(prev));
  PUT(HDRP(prev), PACK(newSize, 0));
  PUT(FTRP(prev), PACK(newSize, 0));
  return update(prev, currentSize, newSize);
}

static char getFreeListIndex(size_t base) {
  char x = 0;

  while(base >= MIN_SIZE) {
    base >>= 1;
    x++;
  }

  if(x == 0)
    printf("[WARNING]: getFreeListIndex() will return 0, which would cause some unexpect bugs.\n");

  return x;
}

static void *update(void *bp, size_t current, size_t next) {
  char currentIndex = getFreeListIndex(current);
  char nextIndex = getFreeListIndex(next);

  // printf("update(freeList[%d] -> freeList[%d]: %p)\n", currentIndex, nextIndex, bp);

  // If next and current in the diff freeList, delete current first.
  if(nextIndex != currentIndex) {
    void *prev, *next;
    // printf(" delete(freeList[%d]: %p)\n", currentIndex, bp);

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
    else {
      char *lp = *(freeListp + currentIndex);

      if(lp == bp)
        *(freeListp + currentIndex) = NULL;
      else {
        while(GET_NEXT_FREE(lp) != bp)
          lp = GET_NEXT_FREE(lp);

        PUT_NEXT_FREE(lp, GET_NEXT_FREE(bp));
      }
    }
  }

  void *lp = *(freeListp + nextIndex);

  // If next freeList is not initialized yet, init it with bp.
  if(lp == NULL) {
    PUT_NEXT_FREE(bp, NULL);
    if(nextIndex > 1)
      PUT_PREV_FREE(bp, NULL);
    // printf(
    //   " init freeList[%d] at [%p]:[%p]\n",
    //   nextIndex, freeListp + nextIndex, bp
    // );
    return *(freeListp + nextIndex) = bp;
  }

  if(nextIndex > 1) {
    if(lp != bp) {
      while(lp < bp && GET_NEXT_FREE(lp))
        lp = GET_NEXT_FREE(lp);

      // insert bp as the last element
      if(lp < bp) {
        PUT_NEXT_FREE(lp, bp);
        PUT_PREV_FREE(bp, lp);
        PUT_NEXT_FREE(bp, NULL);
      } else {
        // Dual-Linklist insertion
        PUT_NEXT_FREE(bp, lp);
        PUT_PREV_FREE(bp, GET_PREV_FREE(lp));
        PUT_PREV_FREE(lp, bp);
      }
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

  // printf("insert(freeList[%d]: %p)\n", index, bp);

  if(lp == NULL) {
    PUT_NEXT_FREE(bp, NULL);
    if(index > 1)
      PUT_PREV_FREE(bp, NULL);
    // printf(" init freeList[%d] at [%p]:[%p]\n", index, freeListp + index, bp);
    return *(freeListp + index) = bp;
  }

  // free block size > 1 that has enough space to save dual-linkes(prev and next)
  if(index > 1) {
    if(lp != bp) {
      while(lp < bp && GET_NEXT_FREE(lp))
        lp = GET_NEXT_FREE(lp);

      // insert bp at the last of the list
      if(lp < bp) {
        PUT_NEXT_FREE(lp, bp);
        PUT_PREV_FREE(bp, lp);
        PUT_NEXT_FREE(bp, NULL);
      } else {
        // Dual-Linklist insertion
        PUT_NEXT_FREE(bp, lp);
        PUT_PREV_FREE(bp, GET_PREV_FREE(lp));
        PUT_PREV_FREE(lp, bp);
      }
    }
  }
  // free block size = 1
  else {
    PUT_NEXT_FREE(bp, lp);
    *(freeListp + index) = bp;
  }

  return bp;
}

static void delete(void *bp) {
  void *prev, *next;
  char index = getFreeListIndex(GET_SIZE(HDRP(bp)));

  // printf("delete(freeList[%d]: %p)\n", index, bp);

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
      *(freeListp + index) = NULL;
    else {
      while(GET_NEXT_FREE(lp) != bp)
        lp = GET_NEXT_FREE(lp);

      PUT_NEXT_FREE(lp, GET_NEXT_FREE(bp));
    }

    PUT_NEXT_FREE(bp, NULL);
  }
}

static void deleteWithSize(void *bp, size_t size) {
  void *prev, *next;
  char index = getFreeListIndex(size);

  // printf("delete(freeList[%d]: %p)\n", index, bp);

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
      *(freeListp + index) = NULL;
    else {
      while(GET_NEXT_FREE(lp) != bp)
        lp = GET_NEXT_FREE(lp);

      PUT_NEXT_FREE(lp, GET_NEXT_FREE(bp));
    }

    PUT_NEXT_FREE(bp, NULL);
  }
}

static void *findFit(size_t size) {
  for(char i = getFreeListIndex(size); i < FREE_LIST_SIZE; i++) {
    if(*(freeListp + i) != NULL) {
      for(char *fp = *(freeListp + i); fp != NULL; fp = GET_NEXT_FREE(fp)) {
        if(GET_SIZE(HDRP(fp)) >= size)
          return fp;
      }
    }
  }

  return extend_heap(size);
}

/*
 * mm_realloc - Implemented simply in terms of mm_malloc and mm_free
 */
void *mm_realloc(void *ptr, size_t size) {
  void *oldptr = ptr;
  void *newptr;
  size_t copySize;

  newptr = mm_malloc(size);
  if (newptr == NULL)
    return NULL;
  copySize = *(size_t *)((char *)oldptr - MIN_SIZE);
  if (size < copySize)
    copySize = size;
  memcpy(newptr, oldptr, copySize);
  mm_free(oldptr);
  return newptr;
}
