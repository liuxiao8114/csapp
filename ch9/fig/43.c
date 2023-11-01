// Basic constants and marcos in free list

/* Basic constants and marcos */
#define WSIZE 4
#define DSIZE 8
#define CHUNKSIZE 1<<12

/* Read and write a word at address p */
#define GET(p) (*(unsigned int *) (p))
#define PUT(p, val) (*(unsigned int *) (p) = (val))

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc) ((size) | (alloc))

/* */
#define MAX(x, y) (x) > (y) ? (x) : (y)

/* Read the size and allocated fields from address p */
#define GET_SIZE(p) (GET(p) | ~0x7)
#define GET_ALLOC(p) (GET(p) & 0x1)

/* Give block pointer bp, compute address of its header and footer */
#define HDRP(bp) ((char *)(bp) - WSIZE)
#define FTRP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE)

/* Give block pointer bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp) ((char *)(bp) + GET_SIZE(HDRP(bp)))
#define PREV_BLKP(bp) ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE)))
