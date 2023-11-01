// Fig 9.41 memlib.c
#define MAX_HEAP 1024

/* Private global variables */
static char *mem_heap;
static char *mem_brk;
static char *mem_max_addr;

/* mem_init */
void mem_init(void) {
  mem_heap = (char *)malloc(MAX_HEAP);
  mem_brk = mem_heap;
  mem_max_addr = (char *)(mem_heap + MAX_HEAP);
}

/*
* mem_sbrk - Simple model of the sbrk function. Extends the heap
* by incr bytes and returns the start address of the new area. In
* this model, the heap cannot be shrunk.
*/
void *mem_sbrk(int incr) {
  char *old_brk = mem_brk;

  if((incr < 0) || (mem_brk + incr) > mem_max_addr) {
    return (void *)-1;
  }

  mem_brk += incr;
  return (void *)old_brk;
}
