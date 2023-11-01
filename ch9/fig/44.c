// Creating the Initial Free List
int mm_init(void) {
  if((heap_listp = mem_sbrk(4 * WSIZE)) == (void *)-1)
    return -1;

  PUT(heap_listp, 0); /* Alignment padding */
  PUT(heap_listp + 1*WSIZE, PACK(DSIZE, 1)); /* Prologue header */
  PUT(heap_listp + 2*WSIZE, PACK(DSIZE, 1)); /* Prologue footer */
  PUT(heap_listp + 3*WSIZE, PACK(0, 1)); /* Epilogue header */
  heap_listp += 2*WSIZE;

  if(extend_heap(CHUNKSIZE / WSIZE) == NULL)
    return -1;
    
  return 0;
}
