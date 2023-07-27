#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd1, fd2;
    char c;

    fd1 = open("foo.txt", O_RDONLY, 0);
    fd2 = open("foo.txt", O_RDONLY, 0);
    read(fd1, &c, 1);
    dup2(fd1, fd2);
    read(fd2, &c, 1);
    printf("c = %c\n", c);
    exit(0);
}
