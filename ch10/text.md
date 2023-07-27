## 10.3 Open and Close Files


## 10.8 Sharing Files
Descriptor table.
  Each process has its own separate descriptor table whose entries
  are indexed by the process’s open file descriptors. Each open descriptor
  entry points to an entry in the file table.
File table.
  The set of open files is represented by a file table that is shared by all
  processes. Each file table entry consists of (for our purposes) the current
  file position, a reference count of the number of descriptor entries that
  currently point to it, and a pointer to an entry in the v-node table. Closing
  a descriptor decrements the reference count in the associated file table
  entry. The kernel will not delete the file table entry until its reference
  count is zero.
v-node table.
  Like the file table, the v-node table is shared by all processes. Each
  entry contains most of the information in the stat structure, including the
  st_mode and st_size members.

Fig10.12
      Descriptor table        Open file table       v-node table
stdin   fd0                       File A
stdout  fd1
stderr  fd2
        fd3
        fd4
Typically, descriptor 1 and 4 reference two different files through different file table entries.
Multiple descriptors can also reference the same file through different file table entries. i.e call the *open* function twice with the same file name.(problem 10.2)

## 10.9 I/O Redirection


## 10.10 Standard I/O
The standard I/O library models an open file as a stream. To the programmer, a stream is a pointer to a structure of type FILE. Every ANSI C program begins with three open streams, stdin, stdout, and stderr, which correspond to standard input, standard output, and standard error, respectively:
```c
#include <stdio.h>
extern FILE *stdin;  /* Standard input (descriptor 0) */
extern FILE *stdout; /* Standard output (descriptor 1) */
extern FILE *stderr; /* Standard error (descriptor 2) */
```

A stream of type FILE is an abstraction for a file descriptor and a stream
buffer. The purpose of the stream buffer is the same as the Rio read buffer: to
minimize the number of expensive Linux I/O system calls. For example, suppose
we have a program that makes repeated calls to the standard I/O getc function,
where each invocation returns the next character from a file. When getc is called
the first time, the library fills the stream buffer with a single call to the read function and then returns the first byte in the buffer to the application. As long as there are unread bytes in the buffer, subsequent calls to getc can be served directly from the stream buffer.
