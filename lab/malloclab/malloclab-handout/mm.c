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

// typedef struct fBlock *fb;
//
// struct fBlock {
//   unsigned int size;
//   fb prev;
//   fb next;
// };

/* global heap pointer */
static void *heapListp;

/* explicit free list: pointer to free block */
static void **freeListp;
static size_t freeListSize = 0;

enum { INIT, FREE, ALLOC, REALLOC, EXTEND } MM_CHECK_TYPE;

/*
 * mm_init - initialize the malloc package.
 */
int mm_init(void) {
  if((heapListp = mem_sbrk(6 * WSIZE)) == (void *)-1)
    return -1;

  PUT(heapListp, 0);

  /* Explicit free block */
  freeListp = heapListp + WSIZE;
  PUT(freeListp, 0); /* freeList start point */

  PUT(heapListp + 3*WSIZE, PACK(DSIZE, 1)); /* Prologue header */
  PUT(heapListp + 4*WSIZE, PACK(DSIZE, 1)); /* Prologue footer */
  PUT(heapListp + 5*WSIZE, PACK(0, 1));     /* Epilogue header */
  heapListp += 4*WSIZE;

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
  size_t asize = ALIGN(size + MIN_SIZE);
  char *fp = findFit(asize, getFreeListIndex(asize));

  if (fp == NULL)
    return NULL;

  size_t fsize = GET_SIZE(HDRP(fp));

  PUT(fp, 0);   // demand zero
  PUT(HDRP(fp), PACK(asize, 1));
  PUT(FTRP(fp), PACK(asize, 1));

  if(fsize > asize) {
    updateFreeList(fp, fsize - asize, ALLOC);
  }

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
  // size_t asize = (size % 2) ? (size + 1) / WSIZE : size / WSIZE;
  size_t asize = ALIGN(size + MIN_SIZE);

  if ((long)(bp = mem_sbrk(asize)) == -1)
    return NULL;

  PUT(HDRP(bp), PACK(asize, 0));         /* Block header */
  PUT(FTRP(bp), PACK(asize, 0));         /* Block footer */
  PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1));  /* Epilogue */

  mm_check(EXTEND);

  // mm_init
  if(*(freeListp + index) == NULL) {
    *freeListp = bp + WSIZE;
    PUT(freeListp, ++freeListSize);
    PUT(freeListp + DSIZE, 0);
    PUT(freeListp + 2*DSIZE, 0);

    return bp;
  }

  return coalesce(bp);
}

/*
 * init_freeListp - init explicit segregated free list by given size type.
 */
static void mm_check(int type) {
  printf("mm_check: %d\n", type);
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
      PUT(bp, PACK((currentSize += GET_SIZE(next)), 0);

    // return updateFreeList(bp, currentSize, FREE);
    return bp;
  }

  if(GET_ALLOC(next))
    PUT(prev, PACK((currentSize += GET_SIZE(prev)), 0);
  else
    PUT(prev, PACK((currentSize += GET_SIZE(prev) + GET_SIZE(next)), 0);

  // return updateFreeList(prev, currentSize, FREE);
  return prev;
}

static size_t getFreeListIndex(size_t size) {
  size_t x = 0;

  while(base > 1) {
    base >>= 1;
    x++;
  }

  return x;
}

static void *updateFreeList(void *bp, size_t size, size_t type) {
  void *fp;
  size_t index = getFreeListIndex(size);

  switch (type) {
    case ALLOC:
    case FREE:
    default:
      fp = freeListp + index;
      while(fp)
  }

  return bp;
}

static void *findFit(size_t size, size_t index) {
  void *fp;

  for(int i = index; *fp == NULL && i <= freeListSize; i <<= 1) {
    for(int j = 0; *fp != NULL; j++)
      fp = freeListp + i + j;
  }

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
