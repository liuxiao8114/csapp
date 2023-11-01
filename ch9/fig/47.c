void *mm_malloc(size_t size) {
  size_t asize;      /* Adjusted block size */
  size_t extendsize; /* Amount to extend heap if no fit */
  char *bp;

  /* Ignore spurious requests */
  if (size == 0)
    return NULL;

  /* Adjust block size to include overhead and alignment reqs. */
  if (size <= DSIZE)
    asize = 2 * DSIZE;
  else
    asize = DSIZE * ((size + (DSIZE) + (DSIZE-1)) / DSIZE);

  /* Search the free list for a fit */
  if ((bp = find_fit(asize)) != NULL) {
    place(bp, asize);
    return bp;
  }

  /* No fit found. Get more memory and place the block */
  extendsize = MAX(asize, CHUNKSIZE);
  if ((bp = extend_heap(extendsize / WSIZE)) == NULL)
    return NULL;

  place(bp, asize);
  return bp;
}

// p9.8 should perform a first-fit search of the implicit free list.
static void *find_fit(size_t asize) {
  void *bp;

  for(bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp))
    if(GET_SIZE(HDRP(bp)) >= asize)
      return bp;

  return NULL;
}

// p9.9 should place the requested block at the beginning of the free
// block, splitting only if the size of the remainder would equal or
// exceed the minimum block size.

static void place(void *bp, size_t asize) {
  PUT(bp, 0); // demand-zero
  PUT(HDRP(bp), PACK(asize, 1));           /* block header */
  PUT(FTRP(bp), GET(HDRP(PREV_BLKP(bp)))); /* block footer */


  if(GET_SIZE(HDRP(bp)) - asize >= DSIZE * 2)
    mm_free(bp + asize); // split
}

static void place(void *bp, size_t asize)
{
    size_t csize = GET_SIZE(HDRP(bp));

    if ((csize - asize) >= (2 * DSIZE)) {
        PUT(HDRP(bp), PACK(asize, 1));
        PUT(FTRP(bp), PACK(asize, 1));
        bp = NEXT_BLKP(bp);
        PUT(HDRP(bp), PACK(csize - asize, 0));
        PUT(FTRP(bp), PACK(csize - asize, 0));
    }
    else {
        PUT(HDRP(bp), PACK(csize, 1));
        PUT(FTRP(bp), PACK(csize, 1));
    }
}
