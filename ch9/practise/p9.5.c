/*
Write a C program mmapcopy.c that uses mmap to copy an arbitrary-size disk file to
stdout. The name of the input file should be passed as a command-line argument
*/
#include <sys/mman.h>
#include <sys/stat.h>
#include <stddef.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  int fd;
  size_t length;
  struct stat sb;
  off_t offset, pa_offset;
  char* addr;
  ssize_t s;

  if(argc < 3 || argc > 4) {
    fprintf(stderr, "%s file offset [length]\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  fd = open(argv[1], O_RDONLY);
  fstat(fd, &sb);

  offset = atoi(argv[2]);
  pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) - 1);

  printf("   offset: %ld\n", offset);
  printf("pa_offset: %ld\n", pa_offset);

  if(argc == 4)
    length = atoi(argv[3]);
  else
    length = sb.st_size - offset;

  addr = mmap(NULL, length + offset - pa_offset, PROT_READ, MAP_PRIVATE, fd, pa_offset);
  s = write(STDOUT_FILENO, addr + offset - pa_offset, length);

  if(s != length) {
    fprintf(stderr, "partial write\n");
    exit(EXIT_FAILURE);
  }

  munmap(addr, length + offset - pa_offset);
  close(fd);

  exit(EXIT_SUCCESS);
}

































// int main2(int argc, char *argv[]) {
//   char *addr;
//   int fd;
//   struct stat sb;
//   off_t offset, pa_offset;
//
//   fd = open(argv[1], O_RDONLY);
//   offset = atoi(argv[2]);
//   pa_offset = offset & ~(sysconf(_SC_PAGE_SIZE) - 1);
//
//   addr = mmap(
//     NULL, length + offset - pa_offset, PROT_READ, MAP_PRIVATE, fd, pa_offset);
//   sb = write(STDOUT_FILENO, addr + offset - pa_offset, length);
//
//   if(s != length) {
//     exit(EXIT_FAILURE);
//   }
//
//   munmap(addr, length + offset - pa_offset);
//   close(fd);
//
//   exit(EXIT_SUCCESS);
// }
