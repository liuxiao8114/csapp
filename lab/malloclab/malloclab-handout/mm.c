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
#define ALIGN(size) (((size) + (ALIGNMENT-1)) & ~0x7)

#define MIN_SIZE (ALIGN(sizeof(size_t)))
#define FREE_LIST_SIZE 32

#define GET_FREE_SIZE(fp) (*(unsigned int *) (fp))
#define GET_NEXT_FREE(fp) ((char *)(fp) + ALIGNMENT)
#define GET_PREV_FREE(fp) ((char *)(fp) + ALIGNMENT * 2)
#define PUT_NEXT_FREE(fp, val) (*(void **)(fp + ALIGNMENT) = (val))
#define PUT_PREV_FREE(fp, val) (*(void **)(fp + ALIGNMENT * 2) = (val))

/* global heap pointer */
static void *heapListp;

/* explicit free list: pointer to free block */
static void **freeListp;

enum { INIT, FREE, ALLOC, REALLOC, EXTEND } MM_CHECK_TYPE;

static void *extend_heap(size_t size, size_t index);
static void mm_check(int, size_t);
static void *coalesce(void *bp);
static size_t getFreeListIndex(size_t size);
static void *update(void *bp, size_t size, size_t type);
static void *insert(void *lp, void *bp);
static void delete(void *bp, size_t newsize);
static void *findFit(size_t size, size_t index);

/*
 * mm_init - initialize the malloc package.
 */
int mm_init(void) {
  if((heapListp = mem_sbrk(36 * WSIZE)) == (void *)-1)
    return -1;

  PUT(heapListp, 0);

  /* Explicit free block */
  freeListp = heapListp + WSIZE;
  PUT(heapListp + 33*WSIZE, PACK(DSIZE, 1)); /* Prologue header */
  PUT(heapListp + 34*WSIZE, PACK(DSIZE, 1)); /* Prologue footer */
  PUT(heapListp + 35*WSIZE, PACK(0, 1));     /* Epilogue header */
  heapListp += 34*WSIZE;

  mm_check(INIT, 0);

  size_t size = CHUNKSIZE / WSIZE;
  if(extend_heap(size, getFreeListIndex(size)) == NULL)
    return -1;

  return 0;
}

/*
 * mm_malloc - Allocate a block by incrementing the brk pointer.
 *     Always allocate a block whose size is a multiple of the alignment.
 */
void *mm_malloc(size_t size) {
  size_t asize = ALIGN(size);
  char *p = findFit(asize, getFreeListIndex(asize));

  if (p == NULL)
    return NULL;

  PUT(p, 0);   // demand zero
  PUT(HDRP(p), PACK(asize, 1));
  PUT(FTRP(p), PACK(asize, 1));

  // place and update free list
  update(p, asize, ALLOC);
  return p;
}

/*
 * mm_free - Freeing a block does nothing.
 */
void mm_free(void *ptr) {
  size_t size = GET_SIZE(HDRP(ptr));

  PUT(HDRP(ptr), PACK(size, 0));
  PUT(FTRP(ptr), PACK(size, 0));
  coalesce(ptr);
}

static void *extend_heap(size_t size, size_t index) {
  char *bp;
  size_t asize = ALIGN(size);

  if ((long)(bp = mem_sbrk(asize)) == -1)
    return NULL;

  PUT(HDRP(bp), PACK(asize, 0));         /* Block header */
  PUT(FTRP(bp), PACK(asize, 0));         /* Block footer */
  PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));  /* Epilogue */

  insert(*(freeListp + index), bp);
  mm_check(EXTEND, asize);

  return coalesce(bp);
}

/*
 * init_freeListp - init explicit segregated free list by given size type.
 */
static void mm_check(int type, size_t size) {
  switch (type) {
    case INIT:
      printf("mm_check: INIT\n");
      printf("heapListp start at addr: %p\n", heapListp);
      printf("freeListp start at addr: %p\n", freeListp);
      printf("mm_check end\n");
      break;
    case FREE:
      printf("mm_check: FREE\n");
      printf("mm_check end\n");
      break;
    case ALLOC:
      printf("mm_check: ALLOC\n");
      printf("mm_check end\n");
      break;
    case REALLOC:
      printf("mm_check: REALLOC\n");
      printf("mm_check end\n");
      break;
    case EXTEND:
      printf("mm_check: EXTEND\n");
      printf("  EXTEND: %ld\n", size);
      printf("mm_check end\n");
      break;
    default:
      printf("Unknown mm_check type: %d\n", type);
      printf("mm_check end\n");
  }
}

/*
 * coalesce - init explicit segregated free list by given size type.
 */
static void *coalesce(void *bp) {
  void *prev = PREV_BLKP(bp);
  void *next = NEXT_BLKP(bp);
  size_t currentSize = GET_SIZE(HDRP(bp));

  if(GET_ALLOC(prev)) {
    if(!GET_ALLOC(next))
      PUT(bp, PACK((currentSize += GET_SIZE(next)), 0));

    return update(bp, currentSize, FREE);
  }

  if(GET_ALLOC(next))
    PUT(prev, PACK((currentSize += GET_SIZE(prev)), 0));
  else
    PUT(prev, PACK((currentSize += GET_SIZE(prev) + GET_SIZE(next)), 0));

  return update(prev, currentSize, FREE);
}

static size_t getFreeListIndex(size_t base) {
  size_t x = 0;

  while(base > 1) {
    base >>= 1;
    x++;
  }

  return x;
}

static void *update(void *bp, size_t size, size_t type) {
  size_t index = getFreeListIndex(size);
  size_t rsize, rindex;

  switch (type) {
    case ALLOC:
      rsize = GET_SIZE(HDRP(bp)) - size;

      if(rsize == 0) {
        delete(bp, 0);
        return NULL;
      }

      rindex = getFreeListIndex(rsize);
      if(rindex == index)
        return NULL;

      delete(bp,rsize);
      insert(*(freeListp + index), bp);
      break;
    case FREE:
      delete(bp, size);
      insert(*(freeListp + index), bp);
      break;
    default:
      printf("Unknown Type to update free list: %ld\n", type);
      return NULL;
  }

  return bp;
}

static void *insert(void *lp, void *bp) {
  if(lp == NULL)
    return lp = bp;

  while(lp < bp && GET_NEXT_FREE(lp))
    lp = GET_NEXT_FREE(lp);

  // insert bp at the last of the list
  if(lp < bp) {
    PUT_NEXT_FREE(lp, bp);
    PUT_PREV_FREE(bp, lp);
  }
  else {
    // Dual-Linklist insertion
    PUT_NEXT_FREE(bp, lp);
    PUT_PREV_FREE(bp, GET_PREV_FREE(lp));
    PUT_PREV_FREE(lp, bp);
  }

  return lp;
}

static void delete(void *bp, size_t newsize) {
  void *prev, *next;

  if((prev = GET_PREV_FREE(bp)) != NULL) {
    if((next = GET_NEXT_FREE(bp)) != NULL) {
      PUT_NEXT_FREE(prev, next);
      PUT_PREV_FREE(next, prev);
    }
    else {
      PUT_NEXT_FREE(prev, NULL);
    }
  }
  else if((next = GET_NEXT_FREE(bp)) != NULL) {
    PUT_PREV_FREE(next, prev);
  }

  *(unsigned int *)bp = newsize;
  PUT_NEXT_FREE(bp, 0);
  PUT_PREV_FREE(bp, 0);
}

static void *findFit(size_t size, size_t index) {
  void *fp;

  for(int i = index; fp == NULL && i <= FREE_LIST_SIZE; i++)
    for(int j = 0; fp == NULL; j++)
      fp = *(freeListp + i) + j;

  if(fp == NULL)
    fp = extend_heap(size, index);

  return fp;
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
