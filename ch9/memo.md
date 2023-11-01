relocate file
ld
=>  elf file

./
=>  shell


vma - code segment
      data segment

init


dynamic share
fork
execve

9.7.1
page size: 4KB(Linux choice) or 4MB
VA: 2^64
pages: 2^(64 - 12) = 2^52

          V                 A
VPN(36-bits) unused(4-bits) VPO(12-bits)
36-bts




1k -> 1k(2^10)
10 -> 10
9 -> 9 -> 9 -> 9

9.1 - 9.2
Virtual Address VS. Physical Address
Why?


9.3
Virtual Page(N)
  Page size in Linux: 4KB(2^12) or 4MB(2^22)
Physical Page(M)
Page Table
  page hit
  page fault
  Page Table Entry(PTE) 8Bytes

9.6
64-bit virtual address
n = 64
p = 10
VPO address space: p
VPN address space: n-p

m = 32
p = 10

VPN | VPN | VPN | VPN | VPO
PPN                   | PPO

9.8 Memory Mapping
Linux initializes the content of a virtual memory area by associating it with an object on disk,
a process known as memory mapping. Areas can be mapped to one of two types of objects:

1. Regular file in the Linux file system.
VA -> MMU -> PTE -> VP -> PTE -> PP
step1, VA -> MMU:

page size 4KB
2^32 / 2^12 = 2^20 pages

task_struct -> mm_struct -> vm_start_area
------------------------------------------
mm          ->    pgd
                  ...
                  mmap
                  ...
