## 9.1 Physical and Virtual Addressing
With virtual addressing, the CPU accesses main memory by generating a virtual address(VA), which is converted to the appropriate physical address before being send to main memory.

## 9.2 Address Spaces
The concept of an address space is important because it makes clear distinction between data objects(bytes) and their attributes(addresses)...We can generalize and allow each data object to have multiple independent addresses, each chosen from a address space. This is the basic idea of virtual memory.

## 9.3 VM as a Tool for Caching
As with any other cache in the memory hierarchy, the data on disk is partitioned into blocks that serve as the transfer units between the disk and the main memory. VM systems handle this by partitioning the virtual memory into fixed-sizes blocks called virtual pages. Similarly

### 9.3.1 DRAM cache organization
Because of the large miss penalty and the expense of accessing the first byte, virtual pages tend to be large.
Due to the large miss penalty, DRAM caches are fully associative, that is, any virtual page can be placed in any physical page.

The replacement policy on misses also assumes greater importance, because the penalty associated with replacing the wrong virtual page is so high.

### 9.3.2 Page tables
As with any cache, the VM system must have some way to determine if a VP is cached somewhere in DRAM.
If so, the system must determine which PP it is cached in.
If there is a miss, the system must determine where the VP is stored on disk, select a victim page in physical memory, and copy the VP from disk to DRAM, replacing the victim page.
These capabilities are provided by a combination of
+ operation system software
+ address translation hardware in the MMU(memory management unit)
+ a data structure stored in physical memory known as a *page table* that maps virtual pages to physical pages
The address translation hardware reads the page table each time it converts a virtual address to a physical address. The operating system is responsible for maintaining the contents of the page table and transferring pages back and forth between disk and DRAM.

A page table is an array of page table entries(PTE). Each page in the virtual address space has a PTE at a fixed offset in the page table...because the DRAM cache is fully associative, any physical page can contain any virtual page.

### 9.3.3 Page Hits
### 9.3.4 Page Faults
In virtual memory parlance, a DRAM cache miss is known as a page fault. Figure
9.6 shows the state of our example page table before the fault. The CPU has
referenced a word in VP 3, which is not cached in DRAM. The address translation
hardware reads PTE 3 from memory, infers from the valid bit that VP 3 is
not cached, and triggers a page fault exception. The page fault exception invokes
a page fault exception handler in the kernel, which selects a victim page — in this
case, VP 4 stored in PP 3. If VP 4 has been modified, then the kernel copies it back
to disk. In either case, the kernel modifies the page table entry for VP 4 to reflect
the fact that VP 4 is no longer cached in main memory

In virtual memory parlance, blocks are known as pages. The activity of transferring a page between disk and memory is known as swapping or paging. Pages are swapped in (paged in) from disk to DRAM, and swapped out (paged out) from DRAM to disk. The strategy of waiting until the last moment to swap in a page, when a miss occurs, is known as demand paging. Other approaches, such as trying to predict misses and swap pages in before they are actually referenced, are possible. However, all modern systems use demand paging.

### 9.3.5 Allocating Pages
As a result of calling malloc, the OS allocates a new page of virtual memory.

## 9.4 VM as a Tool for Memory Management
Virtual memory greatly simplified memory management and provided a natural way to protect memory.
Thus far, we have assumed a single page table that maps a single virtual address to the physical address. In fact, operating system provides a separate page table, and thus a separate virtual address, for each process.

+ Simplifying linking
+ Simplifying loading
  To load the .text and .data sections of an object file into a newly created process, the Linux loader allocates virtual pages for the code and data segments, mark them as invalid(i.e. not cached), and points their page table entries to the appropriate location in the object file.
  The loader never actually copies any data from disk to memory. The data are loaded automatically on demand  

  The notion of mapping a set of contiguous virtual pages to an arbitrary location in an arbitrary file is known as memory mapping.
+ Shared location

## 9.6 Address Translation
a page hit:
step.1 The processor generates a VA and sends it to the MMU
step.2 The MMU generates the PTE address and requests it from the cache/main memory
step.3 The cache/main memory returns the PTE to the MMU
step.4 The MMU constructs the physical address and sends it to the cache/main memory
step.5 The cache/main memory returns the requested data word to the processor

a page fault:
step.1 to 3 the same as a page hit.
step.4 The valid bit in the PTE is 0, so the MMU triggers an exception, which transfers control in the CPU to a page fault exception handler in the operating system kernel.
step.5 The fault handler identifies a victim page in physical memory, and if that page has been modified, pages it out to disk.

### 9.6.1 Integrating Caches and VM
In any system that uses both virtual memory and SRAM caches, there is the issue of whether to use virtual or physical addresses to access the SRAM cache. Although a detailed discussion of the trade-offs is beyond our scope here, most systems opt for physical addressing. With physical addressing, it is straightforward for multiple processes to have blocks in the cache at the same time and to share blocks from the same virtual pages. Further, the cache does not have to deal with protection issues, because access rights are checked as part of the address translation process.
Figure 9.14 shows how a physically addressed cache might be integrated with
virtual memory. The main idea is that the address translation occurs before the
cache lookup. Notice that page table entries can be cached, just like any other
data words.


### 9.6.2 Speeding Up Address Translation with a TLB
As we have seen, every time the CPU generates a virtual address, the MMU must
refer to a PTE in order to translate the virtual address into a physical address. In
the worst case, this requires an additional fetch from memory, at a cost of tens to
hundreds of cycles. If the PTE happens to be cached in L1, then the cost goes down
to a handful of cycles. However, many systems try to eliminate even this cost by
including a small cache of PTEs in the MMU called a translation lookaside buffer
(TLB)

A TLB is a small, virtually addressed cache where each line holds a block consisting of a single PTE. The index and tag fields are used for set selection and line matching are extracted from the VPN in the VA.
If the TLB has T = 2^t sets, then the TLB index(TLBI) consists of the t least significant bits of the VPN, and the TLB tag(TLBT) consists of the remaining bits in the VPN.

a TLB hit(Fig 9.16(a)): All of the address translation steps are performed inside the on-chip MMU
step.1    The CPU generates a VA.
step.2&3  The MMU fetches the appropriate PTE from the TLB.
step.4    The MMU translates the virtual address to a physical address and sends it  and sends it to the cache/main memory
step.5    The cache/main memory returns the requested data word to the CPU.

a TLB miss(Fig 9.16(b))
The MMU must fetch the PTE from the L1 cache or lower level.

### 9.6.3 Multi-level Page Tables
32-bits memory, 4KB page size, 4 bytes PTE

2^(32 - 12) * 4 = 2^20 * 4 = 4MB page table

we would need a 4 MB page table resident in memory at all times, even if
the application referenced only a small chunk of the virtual address space. The
problem is compounded for systems with 64-bit address spaces.

Each PTE in the level 1 table is responsible for mapping a 4 MB chunk of the virtual address space, where each chunk consists of 1,024 contiguous pages. Given that the address space is 4 GB, 1,024 PTEs are sufficient to cover the entire space.
(level1 table pages size(4MB) * consists 1024 pages)

If every page in chunk i is unallocated, then level 1 PTE i is null.
If at least one page in chunk i is allocated, then level 1 PTE i points to the base of a level 2 page table.

Each PTE in a level 2 page table is responsible for mapping a 4-KB page of
virtual memory, just as before when we looked at single-level page tables. Notice
that with 4-byte PTEs, each level 1 and level 2 page table is 4 kilobytes, which
conveniently is the same size as a page.

This scheme reduces memory requirements in two ways:
+ if a PTE in the level 1 table is null, then the corresponding level 2 page table does not even have to exist. This represents a significant potential savings, since most of the 4 GB
virtual address space for a typical program is unallocated.
+ only the level1 table needs to be in main memory at all times. The level 2 page tables can be created and paged in and out by the VM system as they are needed, which reduces pressure on main memory. Only the most heavily used level 2 page tables need to be cached in main memory.

Fig9.17 A two-level page table hierarchy
level 1   --->   level 2                Virtual Memory
PTE0  ---------- PTE0                   VP0
                 ...                    ...
                 PTE1023                VP1023
PTE1  ---------- PTE0                   VP1024
                 ...                    ...
                 PTE1023                VP2047
PTE2(null)                              Gap
PTE3(null)                              ...
PTE4(null)                              ...
PTE5(null)                              ...
PTE6(null)                              ...
PTE7(null)                              Gap
PTE8

Fig9.18 Address translation with a k-level page table

Fig9.18 summarizes address translation with a k-level page table hierarchy. The virtual address is partitioned into k VPNs and a VPO. Each VPN i(1 <= i < k) is an index into a page table at level i.

### 9.6.4 Put it together
+ Virtual addresses are 14-bits wide. <n = 14>
+ Page size is 64 bytes. <P = 64, p = 6, n - p = 8>
+ The TLB is 4-way set associative with 16 total entries. <cache 16 PTE, TLBI set 2-bits>
+ The L1 d-cache is physically addressed and direct mapped, with a 4-byte line size and 16 total sets.

Bit position
VA = 0x03d4

VPN                     VPO
TLBT          | TLBI
13 12 11 10 9 8 7 6     5 4 3 2 1 0
 0  0  0  0 1 1 1 1     0 1 0 1 0 0


TLBT|TLBI
0x03 0x03





0x0f 0x14
TLBT TLBI
VPN VPO
To begin, the MMU extracts the VPN (0x0F) from the virtual address and
checks with the TLB to see if it has cached a copy of PTE 0x0F from some previous
memory reference. The TLB extracts the TLB index (0x03) and the TLB tag (0x3)
from the VPN, hits on a valid match in the second entry of set 0x3, and returns
the cached PPN (0x0D) to the MMU.
If the TLB had missed, then the MMU would need to fetch the PTE from main
memory. However, in this case, we got lucky and had a TLB hit. The MMU now
has everything it needs to form the physical address. It does this by concatenating
thePPN(0x0D) from thePTEwith theVPO(0x14) from the virtual address, which
forms the physical address (0x354).
Next, the MMU sends the physical address to the cache, which extracts the
cache offset CO (0x0), the cache set index CI (0x5), and the cache tag CT (0x0D)
from the physical address.

## 9.7 The Intel Core i7/Linux Memory System
### 9.7.1 Core i7 Address Translation
Figure 9.22 summarizes the entire Core i7 address translation process, from the
time the CPU generates a virtual address until a data word arrives from memory.
The Core i7 uses a four-level page table hierarchy. Each process has its own private
page table hierarchy. When a Linux process is running, the page tables associated
with allocated pages are all memory-resident, although the Core i7 architecture
allows these page tables to be swapped in and out. The CR3 control register
contains the physical address of the beginning of the level 1 (L1) page table. The
value of CR3 is part of each process context, and is restored during each context
switch.

Figure 9.23 shows the format of an entry in a level 1, level 2, or level 3
page table. When P = 1 (which is always the case with Linux), the address field
contains a 40-bit physical page number (PPN) that points to the beginning of the
appropriate page table. Notice that this imposes a 4KB alignment requirement
on page tables.

Figure 9.24 shows the format of an entry in a level 4 page table. When P = 1,
the address field contains a 40-bit PPN that points to the base of some page in
physical memory. Again, this imposes a 4 KB alignment requirement on physical
pages.
The PTE has three permission bits that control access to the page. The R/W bit
determines whether the contents of a page are read/write or read-only. The U/S
bit, which determines whether the page can be accessed in user mode, protects
code and data in the operating system kernel from user programs. The XD (execute
disable) bit, which was introduced in 64-bit systems, can be used to disable
instruction fetches from individual memory pages. This is an important new feature
that allows the operating system kernel to reduce the risk of buffer overflow
attacks by restricting execution to the read-only code segment.

As the MMU translates each virtual address, it also updates two other bits that
can be used by the kernel’s page fault handler.
The MMU sets the A bit, which　is known as a reference bit, each time a page is accessed. The kernel can use the reference bit to implement its page replacement algorithm.
The MMU sets the D bit, or dirty bit, each time the page is written to. A page that has been modified is
sometimes called a dirty page. The dirty bit tells the kernel whether or not it must

Figure 9.25 shows how the Core i7 MMU uses the four levels of page tables
to translate a virtual address to a physical address. The 36-bit VPN is partitioned
into four 9-bit chunks, each of which is used as an offset into a page table. The
CR3 register contains the physical address of the L1 page table. VPN 1 provides
an offset to an L1 PTE, which contains the base address of the L2 page table. VPN
2 provides an offset to an L2 PTE, and so on

### 9.7.2 Linux Virtual Memory System
Linux maintains a separate virtual address space for each process of the form
shown in Figure 9.26. We have seen this picture a number of times already, with
its familiar code, data, heap, shared library, and stack segments. Now that we
understand address translation, we can fill in some more details about the kernel
virtual memory that lies above the user stack.

The kernel virtual memory contains the code and data structures in the kernel.
Some regions of the kernel virtual memory are mapped to physical pages that are shared by all processes.
---------------------------------------???
Linux also maps a set of contiguous virtual pages (equal in size to the total amount of DRAM in the system) to the corresponding set of contiguous physical pages. This provides the kernel with a convenient way to access any specific location in physical memory — for example, when it needs to access page tables or to perform memory-mapped I/O operations on devices that are mapped to particular physical memory locations.
---------------------------------------???
Other regions of kernel virtual memory contain data that differ for each process. Examples include page tables, the stack that the kernel uses when it is executing code in the context of the process, and various data structures that keep track of the current organization of the virtual address space.

#### Linux Virtual Memory Areas
Linux organizes the virtual memory as a collection of areas (also called segments). An area is a contiguous chunk of existing (allocated) virtual memory whose pages are related in some way.
For example, the code segment, data segment, heap, shared library segment, and user stack are all distinct areas.
Each existing virtual page is contained in some area, and any virtual page that is not part of some area does not exist and cannot be referenced by the process.
The notion of an area is important because it allows the virtual address space to have gaps. The kernel does not keep track of virtual pages that do not exist, and such pages do not consume any additional resources in memory, on disk, or in the kernel itself.
```c
  struct task_struct {
    struct mm_struct *mm;
  };

```

Figure 9.27 highlights the kernel data structures that keep track of the virtual
memory areas in a process. The kernel maintains a distinct task structure (task_
struct in the source code) for each process in the system. The elements of the task
structure either contain or point to all of the information that the kernel needs to run the process (e.g., the PID, pointer to the user stack, name of the executable object file, and program counter).
One of the entries in the task structure points to an mm_struct that characterizes the current state of the virtual memory. The two fields of interest to us:
  + pgd, which points to the base of the level 1 table (the page global directory),
  + mmap, which points to a list of vm_area_structs (area structs), each of which characterizes an area of the current virtual address space. When the kernel runs this process, it stores pgd in the CR3 control register.
#### Linux Page Fault Exception Handling
1. Is the virtual address A legal? Does A lie within an area defined by any area struct?
Because a process can create an arbitrary number of new virtual memory areas (using the mmap function described in the next section), a sequential search of the list of area structs might be very costly. So in practice, Linux superimposes a tree on the list, using some fields that we have not shown, and performs the search on this tree.
2. Is the attempted memory access legal? Permission,
In other words, does the process have
permission to read, write, or execute the pages in this area? For example,
was the page fault the result of a store instruction trying to write to a read-only
page in the code segment? Is the page fault the result of a process
running in user mode that is attempting to read a word from kernel virtual
memory? If the attempted access is not legal, then the fault handler triggers a
protection exception, which terminates the process. This situation is labeled
“2” in Figure 9.28.

## 9.8 Memory Mapping
Linux initializes the contents of a virtual memory area by associating it with an object on disk, a process known as memory mapping. Areas can be mapped to one of two types of objects:
1. Regular file in the Linux file system: An area can be mapped to a contiguous section of a regular disk file, such as an executable object file. The file section is divided into page-size pieces, with each piece containing the initial contents of a virtual page. Because of demand paging, none of these virtual pages is actually swapped into physical memory until the CPU first touches the page (i.e., issues a virtual address that falls within that page’s region of the address space). If the area is larger than the file section, then the area is padded with zeros.
2. Anonymous file: An area can also be mapped to an anonymous file, created by the kernel, that contains all binary zeros. The first time the CPU touches a virtual page in such an area, the kernel finds an appropriate victim page in physical memory, swaps out the victim page if it is dirty, overwrites the victim page with binary zeros, and updates the page table to mark the page as resident. Notice that no data are actually transferred between disk and memory. For this reason, pages in areas that are mapped to anonymous files are sometimes called demand-zero pages.

In either case, once a virtual page is initialized, it is swapped back and forth
between a special swap file maintained by the kernel. The swap file is also known
as the swap space or the swap area. An important point to realize is that at any
point in time, the swap space bounds the total amount of virtual pages that can be
allocated by the currently running processes.

### 9.8.1 Shared Objects revisited
The idea of memory mapping resulted from a clever insight that if the virtual memory system could be integrated into the conventional file system, then it could provide a simple and efficient way to load programs and data into memory.
As we have seen, the process abstraction promises to provide each process
with its own private virtual address space that is protected from errant writes
or reads by other processes.
However, many processes have identical read-only code areas. For example, each process that runs the Linux shell program bash has the same code area.
Further, many programs need to access identical copies of read-only run-time library code. For example, every C program requires functions from the standard C library such as printf.
It would be extremely wasteful for each process to keep duplicate copies of these commonly used codes in physical.

Fortunately, memory mapping provides us with a clean mechanism for controlling how objects are shared by multiple processes. An object can be mapped into an area of virtual memory as either a shared object or a private object. If a process maps a shared object into an area of its virtual address space, then any writes that the process makes to that area are visible to
any other processes that have also mapped the shared object into their virtual
memory. Further, the changes are also reflected in the original object on disk.
Changes made to an area mapped to a private object, on the other hand, are
not visible to other processes, and any writes that the process makes to the area
are not reflected back to the object on disk. A virtual memory area into which a
shared object is mapped is often called a shared area. Similarly for a private area.

For each process that maps the private object, the page table entries for the corresponding private area are flagged as read-only, and the area struct is flagged as private copy-on-write. So long as neither process attempts
to write to its respective private area, they continue to share a single copy of the
object in physical memory. However, as soon as a process attempts to write to
some page in the private area, the write triggers a protection fault.
When the fault handler notices that the protection exception was caused by
the process trying to write to a page in a private copy-on-write area, it creates a
new copy of the page in physical memory, updates the page table entry to point
to the new copy, and then restores write permissions to the page, as shown in
Figure 9.30(b). When the fault handler returns, the CPU re-executes the write,
which now proceeds normally on the newly created page.
By deferring the copying of the pages in private objects until the last possible
moment, copy-on-write makes the most efficient use of scarce physical memory.

### 9.8.2 The fork Function Revisited
Now that we understand virtual memory and memory mapping, we can get a clear
idea of how the fork function creates a new process with its own independent
virtual address space.
When the fork function is called by the current process, the kernel creates
various data structures for the new process and assigns it a unique PID. To create
the virtual memory for the new process, it creates exact copies of
  + the current process’s mm_struct,
  + area structs,
  + and page tables.
It flags each page in both processes as read-only, and flags each area struct in both processes as private copy-on-write. When the fork returns in the new process, the new process now has an exact copy of the virtual memory as it existed when the fork was called. When either of the processes performs any subsequent writes, the copy-on-write mechanism creates new pages, thus preserving the abstraction of a private address space for each process.

### 9.8.3 The execve Function Revisited
Virtual memory and memory mapping also play key roles in the process of loading programs into memory. Now that we understand these concepts, we can understand how the execve function really loads and executes programs. Suppose that the program running in the current process makes the following call:
execve("a.out", NULL, NULL);
As you learned in Chapter 8, the execve function loads and runs the program contained in the executable object file a.out within the current process, effectively replacing the current program with the a.out program. Loading and running a.out requires the following steps:

1. Delete existing user areas. Delete the existing area structs in the user portion
of the current process’s virtual address.
2. Map private areas. Create new area structs for the code, data, bss, and stack
areas of the new program. All of these new areas are private copy-on-write.
The code and data areas are mapped to the .text and .data sections of the
a.out file. The bss area is demand-zero, mapped to an anonymous file whose
size is contained in a.out. The stack and heap area are also demand-zero,
initially of zero length. Figure 9.31 summarizes the different mappings of the
private areas.
3. Map shared areas. If the a.out program was linked with shared objects, such
as the standard C library libc.so, then these objects are dynamically linked
into the program, and then mapped into the shared region of the user’s virtual
address space.
4. Set the program counter (PC). The last thing that execve does is to set the
program counter in the current process’s context to point to the entry point
in the code area.
The next time this process is scheduled, it will begin execution

### 9.8.4 The mmap Function
The mmap function asks the kernel to create a new virtual memory area, preferably
one that starts at address start, and to map a contiguous chunk of the object
specified by file descriptor fd to the new area. The contiguous object chunk has a
size of length bytes and starts at an offset of offset bytes from the beginning of
the file. The start address is merely a hint, and is usually specified as NULL. For
our purposes, we will always assume a NULL start address. Figure 9.32 depicts the
meaning of these arguments.
The prot argument contains bits that describe the access permissions of the
newly mapped virtual memory area (i.e., the vm_prot bits in the corresponding
area struct).
PROT_EXEC. Pages in the area consist of instructions that may be executed
by the CPU.
PROT_READ. Pages in the area may be read.
PROT_WRITE. Pages in the area may be written.
PROT_NONE. Pages in the area cannot be accessed.
The flags argument consists of bits that describe the type of the mapped
object. If the MAP_ANON flag bit is set, then the backing store is an anonymous
object and the corresponding virtual pages are demand-zero. MAP_PRIVATE
indicates a private copy-on-write object, and MAP_SHARED indicates a shared
object. For example,
  int *bufp = mmap(NULL, )

asks the kernel to create a new read-only, private, demand-zero area of virtual
memory containing size bytes. If the call is successful, then bufp contains the
address of the new area.
The munmap function deletes regions of virtual memory:
#include <unistd.h>
#include <sys/mman.h>
int munmap(void *start, size_t length);
Returns: 0 if OK, −1 on error
The munmap function deletes the area starting at virtual address start and consisting
of the next length bytes. Subsequent references to the deleted region result
in segmentation faults.


## 9.9 Dynamic memory allocation
A dynamic memory allocator maintains an area of a process’s virtual memory
known as the heap (Figure 9.33). Details vary from system to system, but without
loss of generality, we will assume that the heap is an area of demand-zero memory
that begins immediately after the uninitialized data area and grows upward
(toward higher addresses). For each process, the kernel maintains a variable brk
(pronounced “break”) that points to the top of the heap.

An allocator maintains the heap as a collection of various-size blocks. Each
block is a contiguous chunk of virtual memory that is either allocated or free. An
allocated block has been explicitly reserved for use by the application. A free block is available to be allocated. A free block remains free until it is explicitly allocated by the application. An allocated block remains allocated until it is freed, either explicitly by the application or implicitly by the memory allocator itself.

Allocators come in two basic styles. Both styles require the application to explicitly allocate blocks. They differ about which entity is responsible for freeing allocated blocks.
. Explicit allocators require the application to explicitly free any allocated
blocks. For example, the C standard library provides an explicit allocator
called the malloc package. C programs allocate a block by calling the malloc
function, and free a block by calling the free function. The new and delete
calls in C++ are comparable.
. Implicit allocators, on the other hand, require the allocator to detect when
an allocated block is no longer being used by the program and then free
the block. Implicit allocators are also known as garbage collectors, and the
process of automatically freeing unused allocated blocks is known as garbage
collection. For example, higher-level languages such as Lisp, ML, and Java rely
on garbage collection to free allocated blocks.

The remainder of this section discusses the design and implementation of
explicit allocators. We will discuss implicit allocators in Section 9.10. For concreteness, our discussion focuses on allocators that manage heap memory. However, you should be aware that memory allocation is a general idea that arises in a variety
of contexts. For example, applications that do intensive manipulation of graphs
will often use the standard allocator to acquire a large block of virtual memory
and then use an application-specific allocator to manage the memory within that
block as the nodes of the graph are created and destroyed.

### 9.9.1 The malloc and free Functions
The C standard library provides an explicit allocator known as the malloc package.
Programs allocate blocks from the heap by calling the malloc function.
The malloc function returns a pointer to a block of memory of at least size bytes
that is suitably aligned for any kind of data object that might be contained in the
block.
In practice, the alignment depends on whether the code is compiled to run in 32-bit mode (gcc -m32) or 64-bit mode (the default). In 32-bit mode, malloc
returns a block whose address is always a multiple of 8. In 64-bit mode, the address is always a multiple of 16.
If malloc encounters a problem (e.g., the program requests a block of memory
that is larger than the available virtual memory), then it returns NULL and sets
errno. Malloc does not initialize the memory it returns. Applications that want
initialized dynamic memory can use calloc, a thin wrapper around the malloc
function that initializes the allocated memory to zero.
Applications that want to change the size of a previously allocated block can use the realloc function.
Dynamic memory allocators such as malloc can allocate or deallocate heap memory explicitly by using the mmap and munmap functions, or they can use the sbrk function:
```c
#include <unistd.h>
void *sbrk(intptr_t incr);
// Returns: old brk pointer on success, −1 on error
```

The sbrk function grows or shrinks the heap by adding incr to the kernel’s brk
pointer. If successful, it returns the old value of brk, otherwise it returns −1 and sets errno to ENOMEM. If incr is zero, then sbrk returns the current value of
brk. Calling sbrk with a negative incr is legal but tricky because the return value
(the old value of brk) points to abs(incr) bytes past the new top of the heap.

Programs free allocated heap blocks by calling the free function.
```c
#include <stdlib.h>
void free(void *ptr);
// Returns: nothing
```

The ptr argument must point to the beginning of an allocated block that was
obtained from malloc, calloc, or realloc. If not, then the behavior of free
is undefined. Even worse, since it returns nothing, free gives no indication to
the application that something is wrong. As we shall see in Section 9.11, this can
produce some baffling run-time errors.


### 9.9.2 Why Dynamic Memory Allocation?
The most important reason that programs use dynamic memory allocation is that
often they do not know the sizes of certain data structures until the program
actually runs. For example, suppose we are asked to write a C program that reads
a list of n ASCII integers, one integer per line, from stdin into a C array. The
input consists of the integer n, followed by the n integers to be read and stored
into the array. The simplest approach is to define the array statically with some
hard-coded maximum array size:
```c
#include "csapp.h"
#define MAXN 15213

int array[MAXN];

int main()
{
  int i, n;

  scanf("%d", &n);
  if (n > MAXN)
  app_error("Input file too big");
  for (i = 0; i < n; i++)
  scanf("%d", &array[i]);
  exit(0);
}
```

Allocating arrays with hard-coded sizes like this is often a bad idea. The value
of MAXN is arbitrary and has no relation to the actual amount of available virtual
memory on the machine. Further, if the user of this program wanted to read a file
that was larger than MAXN, the only recourse would be to recompile the program
with a larger value of MAXN. While not a problem for this simple example, the
presence of hard-coded array bounds can become a maintenance nightmare for
large software products with millions of lines of code and numerous users.
A better approach is to allocate the array dynamically, at run time, after the
value of n becomes known. With this approach, the maximum size of the array is
limited only by the amount of available virtual memory.

### 9.9.3 Allocator Requirements and Goals
Explicit allocators must operate within some rather stringent constraints:

  + Handling arbitrary request sequences.
  An application can make an arbitrary sequence of allocate and free requests, subject to the constraint that each free request must correspond to a currently allocated block obtained from a previous allocate request. Thus, the allocator cannot make any assumptions
  about the ordering of allocate and free requests. For example, the
  allocator cannot assume that all allocate requests are accompanied by a
  matching free request, or that matching allocate and free requests are
  nested.

  + Making immediate responses to requests.
  The allocator must respond immediately
  to allocate requests. Thus, the allocator is not allowed to reorder or
  buffer requests in order to improve performance.

  + Using only the heap.
  In order for the allocator to be scalable, any non-scalar data
  structures used by the allocator must be stored in the heap itself.

  + Aligning blocks (alignment requirement).
  The allocator must align blocks in such a way that they can hold any type of data object.

  + Not modifying allocated blocks.
  Allocators can only manipulate or change free blocks.
  In particular, they are not allowed to modify or move blocks once they are allocated.
  Thus, techniques such as compaction of allocated blocks are not permitted.

Working within these constraints, the author of an allocator attempts to meet
the often conflicting performance goals of maximizing throughput and memory utilization.

Goal 1: Maximizing throughput. Given some sequence of n allocate and free requests
    R0, R1, . . . , Rk, . . . , Rn−1
we would like to maximize an allocator’s throughput, which is defined as the
number of requests that it completes per unit time. For example, if an allocator
completes 500 allocate requests and 500 free requests in 1 second, then its
throughput is 1,000 operations per second. In general, we can maximize throughput
by minimizing the average time to satisfy allocate and free requests. As we’ll
see, it is not too difficult to develop allocators with reasonably good performance
where the worst-case running time of an allocate request is linear in the number
of free blocks and the running time of a free request is constant.

Goal 2: Maximizing memory utilization. Native programmers often incorrectly
assume that virtual memory is an unlimited resource. In fact, the total amount
of virtual memory allocated by all of the processes in a system is limited by the
amount of swap space on disk. Good programmers know that virtual memory is
a finite resource that must be used efficiently. This is especially true for a dynamic
memory allocator that might be asked to allocate and free large blocks of memory.
There are a number of ways to characterize how efficiently an allocator uses
the heap. In our experience, the most useful metric is peak utilization. As before,
we are given some sequence of n allocate and free requests
    R0, R1, . . . , Rk, . . . , Rn−1

If an application requests a block of p bytes, then the resulting allocated block has
a payload of p bytes. After request Rk has completed, let the aggregate payload,
denoted Pk, be the sum of the payloads of the currently allocated blocks, and let
Hk denote the current (monotonically nondecreasing) size of the heap.
Then the peak utilization over the first k + 1 requests, denoted by Uk, is
given by
    Uk = maxi≤k Pi / Hk

The objective of the allocator, then, is to maximize the peak utilization Un−1 over the entire sequence.
As we will see, there is a tension between maximizing throughput and utilization.
In particular, it is easy to write an allocator that maximizes throughput at the expense of heap utilization.
One of the interesting challenges in any allocator design is finding an appropriate balance between the two goals.

### 9.9.4 Fragmentation
The primary cause of poor heap utilization is a phenomenon known as fragmentation,
which occurs when otherwise unused memory is not available to satisfy allocate requests. There are two forms of fragmentation: internal fragmentation and external fragmentation.
Internal fragmentation occurs when an allocated block is larger than the payload.
This might happen for a number of reasons.
For example, the implementation of an allocator might impose a minimum size on allocated blocks that is greater than some requested payload. Or, as we saw in Figure 9.34(b), the allocator might increase the block size in order to satisfy alignment constraints.

Internal fragmentation is straightforward to quantify. It is simply the sum of
the differences between the sizes of the allocated blocks and their payloads. Thus,
at any point in time, the amount of internal fragmentation depends only on the
pattern of previous requests and the allocator implementation.

External fragmentation occurs when there is enough aggregate free memory to satisfy an allocate request, but no single free block is large enough to handle the request.
For example, if the request in Figure 9.34(e) were for eight words rather than two words, then the request could not be satisfied without requesting additional virtual memory from the kernel, even though there are eight free words remaining in the heap. The problem arises because these eight words are spread over two free blocks.

External fragmentation is much more difficult to quantify than internal fragmentation
because it depends
 <not only on the pattern of previous requests and the allocator implementation but also on the pattern of future requests.>
For example,
suppose that after k requests all of the free blocks are exactly four words in size.
Does this heap suffer from external fragmentation? The answer depends on the
pattern of future requests. If all of the future allocate requests are for blocks that
are smaller than or equal to four words, then there is no external fragmentation.
On the other hand, if one or more requests ask for blocks larger than four words,
then the heap does suffer from external fragmentation.
Since external fragmentation is difficult to quantify and impossible to predict,
allocators typically employ heuristics that attempt to maintain small numbers of
larger free blocks rather than large numbers of smaller free blocks.

### 9.9.5 Implementation Issues
The simplest imaginable allocator would organize the heap as a large array of
bytes and a pointer p that initially points to the first byte of the array.
To allocate size bytes, malloc would save the current value of p on the stack, increment p by
size, and return the old value of p to the caller. Free would simply return to the
caller without doing anything.

This naive allocator is an extreme point in the design space. Since each malloc
and free execute only a handful of instructions, throughput would be extremely
good. However, since the allocator never reuses any blocks, memory utilization
would be extremely bad. A practical allocator that strikes a better balance between
throughput and utilization must consider the following issues:

  + Free block organization. How do we keep track of free blocks?
  + Placement. How do we choose an appropriate free block in which to place a newly allocated block?
  + Splitting. After we place a newly allocated block in some free block, what do we do with the remainder of the free block?
  + Coalescing. What do we do with a block that has just been freed?

The rest of this section looks at these issues in more detail. Since the basic
techniques of placement, splitting, and coalescing cut across many different free
block organizations, we will introduce them in the context of a simple free block
organization known as an implicit free list.

### 9.9.6 Implicit Free Lists
Any practical allocator needs some data structure that allows it
  + to distinguish block boundaries and
  + to distinguish between allocated and free blocks.

Most allocators embed this information in the blocks themselves. One simple approach is shown in Figure 9.35. In this case, a block consists of
  + a one-word header,
  + the payload, and
  + possibly some additional padding.

The header encodes the block size (including the header and any padding) as well as whether the block is allocated or free.
If we impose a double-word alignment constraint, then the block size is always a multiple of 8 and the 3 low-order bits of the block size are always zero. Thus, we need to store only the 29 high-order bits of the block size, freeing the remaining 3 bits to encode other information. In this case, we are using the least significant of these bits(the allocated bit) to indicate whether the block is allocated or free.

Fig9.35 Format of a simple heap block.
Header
Block size
Payload(allocated block only)
Padding(option)

The header is followed by the payload that the application requested when it called malloc.
The payload is followed by a chunk of unused padding that can be any size. There are a number of reasons for the padding. For example,
  + the padding might be part of an allocator’s strategy for combating external fragmentation Or
  + it might be needed to satisfy the alignment requirement.
Given the block format in Figure 9.35, we can organize the heap as a sequence of contiguous allocated and free blocks, as shown in Figure 9.36.

We call this organization an implicit free list because the free blocks are linked implicitly by the size fields in the headers.
The allocator can indirectly traverse the entire set of free blocks by traversing all of the blocks in the heap.
Notice that we need some kind of specially marked end block — in this example, a terminating header with the allocated bit set and a size of zero. (As we will see in Section 9.9.12, setting the allocated bit simplifies the coalescing of free blocks.)

The advantage of an implicit free list is simplicity.
A significant disadvantage is that the cost of any operation that requires a search of the free list, such as placing allocated blocks, will be linear in the total number of allocated and free blocks in the heap.
It is important to realize that the system’s alignment requirement and the
allocator’s choice of block format impose a minimum block size on the allocator.
No allocated or free block may be smaller than this minimum. For example, if
we assume a double-word alignment requirement, then the size of each block
must be a multiple of two words (8 bytes). Thus, the block format in Figure 9.35
induces a minimum block size of two words: one word for the header and another
to maintain the alignment requirement. Even if the application were to request a
single byte, the allocator would still create a two-word block.

### 9.9.7 Placing Allocated Blocks
When an application requests a block of k bytes, the allocator searches the free
list for a free block that is large enough to hold the requested block.
The manner in which the allocator performs this search is determined by the placement policy.
Some common policies are first fit, next fit, and best fit.
First fit searches the free list from the beginning and chooses the first free
block that fits. Next fit is similar to first fit, but instead of starting each search at
the beginning of the list, it starts each search where the previous search left off.
Best fit examines every free block and chooses the free block with the smallest size
that fits.
An advantage of first fit is that it tends to retain large free blocks at the end
of the list. A disadvantage is that it tends to leave “splinters” of small free blocks
toward the beginning of the list, which will increase the search time for larger
blocks. Next fit was first proposed by Donald Knuth as an alternative to first fit,
motivated by the idea that if we found a fit in some free block the last time, there
is a good chance that we will find a fit the next time in the remainder of the block.
Next fit can run significantly faster than first fit, especially if the front of the list
becomes littered with many small splinters. However, some studies suggest that
next fit suffers from worse memory utilization than first fit. Studies have found
that best fit generally enjoys better memory utilization than either first fit or next
fit. However, the disadvantage of using best fit with simple free list organizations
such as the implicit free list is that it requires an exhaustive search of the heap.
Later, we will look at more sophisticated segregated free list organizations that
approximate a best-fit policy without an exhaustive search of the heap.

### 9.9.8 Splitting Free Blocks
Once the allocator has located a free block that fits, it must make another policy
decision about how much of the free block to allocate. One option is to use the entire free block. Although simple and fast, the main disadvantage is that it
introduces internal fragmentation. If the placement policy tends to produce good
fits, then some additional internal fragmentation might be acceptable.
However, if the fit is not good, then the allocator will usually opt to split
the free block into two parts. The first part becomes the allocated block, and the
remainder becomes a new free block. Figure 9.37 shows how the allocator might
split the eight-word free block in Figure 9.36 to satisfy an application’s request for
three words of heap memory.

### 9.9.9 Getting Additional Heap Memory
What happens if the allocator is unable to find a fit for the requested block? One
option is to try to create some larger free blocks by merging (coalescing) free
blocks that are physically adjacent in memory (next section). However, if this
does not yield a sufficiently large block, or if the free blocks are already maximally
coalesced, then the allocator asks the kernel for additional heap memory by calling
the sbrk function. The allocator transforms the additional memory into one large
free block, inserts the block into the free list, and then places the requested block
in this new free block.

### 9.9.10 Coalescing Free Blocks
When the allocator frees an allocated block, there might be other free blocks that are adjacent to the newly freed block. Such adjacent free blocks can cause a phenomenon known as false fragmentation, where there is a lot of available free memory chopped up into small, unusable free blocks.

For example, Figure 9.38 shows the result of freeing the block that was allocated in Figure 9.37.
The result is two adjacent free blocks with payloads of three words each. As a result, a subsequent request for a payload of four words would fail, even though the aggregate size of the two free blocks is large enough to satisfy the request.
To combat false fragmentation, any practical allocator must merge adjacent
free blocks in a process known as coalescing. This raises an important policy
decision about when to perform coalescing. The allocator can opt for immediate
coalescing by merging any adjacent blocks each time a block is freed. Or it can opt
for deferred coalescing by waiting to coalesce free blocks at some later time. For
example, the allocator might defer coalescing until some allocation request fails,
and then scan the entire heap, coalescing all free blocks.

Immediate coalescing is straightforward and can be performed in constant
time, but with some request patterns it can introduce a form of thrashing where a
block is repeatedly coalesced and then split soon thereafter. For example, in Figure
9.38, a repeated pattern of allocating and freeing a three-word block would
introduce a lot of unnecessary splitting and coalescing. In our discussion of allocators,
we will assume immediate coalescing, but you should be aware that fast allocators often opt for some form of deferred coalescing.

### 9.9.11 Coalescing with Boundary Tags
How does an allocator implement coalescing? Let us refer to the block we want
to free as the current block. Then coalescing the next free block (in memory) is
straightforward and efficient. The header of the current block points to the header
of the next block, which can be checked to determine if the next block is free. If
so, its size is simply added to the size of the current header and the blocks are
coalesced in constant time.
But how would we coalesce the previous block? Given an implicit free list of
blocks with headers, the only option would be to search the entire list, remembering
the location of the previous block, until we reached the current block. With an
implicit free list, this means that each call to free would require time linear in the
size of the heap. Even with more sophisticated free list organizations, the search
time would not be constant.
Knuth developed a clever and general technique, known as boundary tags,
that allows for constant-time coalescing of the previous block. The idea, which is
shown in Figure 9.39, is to add a footer (the boundary tag) at the end of each block,
where the footer is a replica of the header. If each block includes such a footer,
then the allocator can determine the starting location and status of the previous
block by inspecting its footer, which is always one word away from the start of the
current block.
Consider all the cases that can exist when the allocator frees the current block:
1. The previous and next blocks are both allocated.
2. The previous block is allocated and the next block is free.
3. The previous block is free and the next block is allocated.
4. The previous and next blocks are both free.

Figure 9.40 shows how we would coalesce each of the four cases.
In case 1, both adjacent blocks are allocated and thus no coalescing is possible.
So the status of the current block is simply changed from allocated to free.
In case 2, the current block is merged with the next block. The header of the current block
and the footer of the next block are updated with the combined sizes of the current
and next blocks.
In case 3, the previous block is merged with the current block.
The header of the previous block and the footer of the current block are updated
with the combined sizes of the two blocks.
In case 4, all three blocks are merged to form a single free block, with the header of the previous block and the footer of
the next block updated with the combined sizes of the three blocks. In each case,
the coalescing is performed in constant time.
The idea of boundary tags is a simple and elegant one that generalizes to
many different types of allocators and free list organizations. However, there is
a potential disadvantage. Requiring each block to contain both a header and a footer can introduce significant memory overhead if an application manipulates many small blocks.
For example, if a graph application dynamically creates and
destroys graph nodes by making repeated calls to malloc and free, and each graph
node requires only a couple of words of memory, then the header and the footer
will consume half of each allocated block.

Fortunately, there is a clever optimization of boundary tags that eliminates
the need for a footer in allocated blocks. Recall that when we attempt to coalesce
the current block with the previous and next blocks in memory, the size field in
the footer of the previous block is only needed if the previous block is free. If we
were to store the allocated/free bit of the previous block in one of the excess low order
bits of the current block, then allocated blocks would not need footers, and
we could use that extra space for payload. Note, however, that free blocks would
still need footers.

### 9.9.12 Putting It Together: Implementing a Simple Allocator
Building an allocator is a challenging task. The design space is large, with numerous
alternatives for block format and free list format, as well as placement,
splitting, and coalescing policies. Another challenge is that you are often forced
to program outside the safe, familiar confines of the type system, relying on the
error-prone pointer casting and pointer arithmetic that is typical of low-level systems
programming.
While allocators do not require enormous amounts of code, they are subtle
and unforgiving. Students familiar with higher-level languages such as C++ or Java
often hit a conceptual wall when they first encounter this style of programming. To
help you clear this hurdle, we will work through the implementation of a simple
allocator based on an implicit free list with immediate boundary-tag coalescing.
The maximum block size is 2^32 = 4 GB. The code is 64-bit clean, running without
modification in 32-bit (gcc -m32) or 64-bit (gcc -m64) processes.

#### General Allocator Design
Our allocator uses a model of the memory system provided by the memlib.c package shown in Figure 9.41.
The purpose of the model is to allow us to run our allocator without interfering with the existing system-level malloc package.
The mem_init function models the virtual memory available to the heap as a large double-word aligned array of bytes.
The bytes between mem_heap and mem_brk represent allocated virtual memory.
The bytes following mem_brk represent unallocated virtual memory.
The allocator requests additional heap memory by calling the mem_sbrk function, which has the same interface as the system’s sbrk function, as well as the same semantics, except that it rejects requests to shrink the heap.
The allocator itself is contained in a source file(mm.c) that users can compile
and link into their applications. The allocator exports three functions to application programs:
```c
  extern int mm_init(void);
  extern void *mm_malloc (size_t size);
  extern void mm_free (void *ptr);
```

The mm_init function initializes the allocator, returning 0 if successful and −1 otherwise.
The mm_malloc and mm_free functions have the same interfaces and semantics as their system counterparts.
The allocator uses the block format shown in Figure 9.39. The minimum block size is 16 bytes.
The free list is organized as an implicit free list, with the invariant form shown in Figure 9.42.
The first word is an unused padding word aligned to a double-word boundary.
The padding is followed by a special prologue block, which is an 8-byte allocated
block consisting of only a header and a footer. The prologue block is created
during initialization and is never freed. Following the prologue block are zero
or more regular blocks that are created by calls to malloc or free. The heap
always ends with a special epilogue block, which is a zero-size allocated block
that consists of only a header. The prologue and epilogue blocks are tricks that
eliminate the edge conditions during coalescing. The allocator uses a single private
(static) global variable (heap_listp) that always points to the prologue block.
(As a minor optimization, we could make it point to the next block instead of the
prologue block.)

#### Basic Constants and Macros for Manipulating the Free List
The GET macro (line 12) reads and returns the word referenced by argument p. The casting here is crucial. The argument p is typically a (void *) pointer,
which cannot be dereferenced directly. Similarly, the PUT macro (line 13) stores
val in the word pointed at by argument p.
The GET_SIZE and GET_ALLOC macros (lines 16–17) return the size and
allocated bit, respectively, from a header or footer at address p.
The remaining macros operate on block pointers (denoted bp) that point to the first payload byte. Given a block pointer bp, the HDRP and FTRP macros (lines 20–21) return pointers to the block header and footer, respectively. The NEXT_BLKP and PREV_BLKP macros (lines 24–25) return the block pointers of the next and previous blocks, respectively.
The macros can be composed in various ways to manipulate the free list.
For example, given a pointer bp to the current block, we could use the following line of code to determine the size of the next block in memory:
  sizt_t size = (GET_SIZE(HDRP(NEXT_BLKP(bp))));

#### Creating the Initial Free List
Before calling mm_malloc or mm_free, the application must initialize the heap by calling the mm_init function (Figure 9.44).
The mm_init function gets four words from the memory system and initializes them to create the empty free list (lines 4–10). It then calls the extend_heap function (Figure 9.45), which extends the heap by CHUNKSIZE bytes and creates the initial free block. At this point, the allocator is initialized and ready to accept allocate and free requests from the application.

The extend_heap function is invoked in two different circumstances:
  (1) when the heap is initialized and
  (2) when mm_malloc is unable to find a suitable fit.
To maintain alignment, extend_heap rounds up the requested size to the nearest multiple of 2 words (8 bytes) and then requests the additional heap space from 2the memory system (lines 7–9).
The remainder of the extend_heap function (lines 12–17) is somewhat subtle.
The heap begins on a double-word aligned boundary, and every call to extend_heap returns a block whose size is an integral number of double words.
Thus, every call to mem_sbrk returns a double-word aligned chunk of memory immediately
following the header of the epilogue block. This header becomes the header of
the new free block (line 12), and the last word of the chunk becomes the new
epilogue block header (line 14). Finally, in the likely case that the previous heap
was terminated by a free block, we call the coalesce function to merge the two
free blocks and return the block pointer of the merged blocks (line 17).

#### Freeing and Coalescing Blocks
An application frees a previously allocated block by calling the mm_free function
(Figure 9.46), which frees the requested block (bp) and then merges adjacent free blocks using the boundary-tags coalescing technique described in Section 9.9.11.

The code in the coalesce helper function is a straightforward implementation
of the four cases outlined in Figure 9.40. There is one somewhat subtle aspect. The
free list format we have chosen — with its prologue and epilogue blocks that are
always marked as allocated—allows us to ignore the potentially troublesome edge
conditions where the requested block bp is at the beginning or end of the heap.
Without these special blocks, the code would be messier, more error prone, and
slower because we would have to check for these rare edge conditions on each
and every free request.

#### Allocating Blocks
An application requests a block of size bytes of memory by calling the mm_malloc
function (Figure 9.47). After checking for spurious requests, the allocator must
adjust the requested block size to allow room for the header and the footer, and to
satisfy the double-word alignment requirement. Lines 12–13 enforce the minimum
block size of 16 bytes: 8 bytes to satisfy the alignment requirement and 8 more
bytes for the overhead of the header and footer. For requests over 8 bytes (line 15),
the general rule is to add in the overhead bytes and then round up to the nearest
multiple of 8.
Once the allocator has adjusted the requested size, it searches the free list for a
suitable free block (line 18). If there is a fit, then the allocator places the requested block and optionally splits the excess (line 19) and then returns the address of the newly allocated block.
If the allocator cannot find a fit, it extends the heap with a new free block
(lines 24–26), places the requested block in the new free block, optionally splitting
the block (line 27), and then returns a pointer to the newly allocated block.

### 9.9.13 Explicit Free Lists
The implicit free list provides us with a simple way to introduce some basic
allocator concepts. However, because block allocation time is linear in the total
number of heap blocks, the implicit free list is not appropriate for a general purpose
allocator (although it might be fine for a special-purpose allocator where the number of heap blocks is known beforehand to be small).

A better approach is to organize the free blocks into some form of explicit
data structure. Since by definition the body of a free block is not needed by the
program, the pointers that implement the data structure can be stored within the
bodies of the free blocks. For example, the heap can be organized as a doubly
linked free list by including a pred (predecessor) and succ (successor) pointer in
each free block, as shown in Figure 9.48.

Using a doubly linked list instead of an implicit free list reduces the first-fit
allocation time from linear in the total number of blocks to linear in the number
of free blocks. However, the time to free a block can be either linear or constant,
depending on the policy we choose for ordering the blocks in the free list.
One approach is to maintain the list in last-in first-out (LIFO) order by inserting
newly freed blocks at the beginning of the list. With a LIFO ordering
and a first-fit placement policy, the allocator inspects the most recently used
blocks first. In this case, freeing a block can be performed in constant time.
If boundary tags are used, then coalescing can also be performed in constant time.
Another approach is to maintain the list in address order, where the address
of each block in the list is less than the address of its successor. In this case, freeing a block requires a linear-time search to locate the appropriate predecessor. The
trade-off is that address-ordered first fit enjoys better memory utilization than
LIFO-ordered first fit, approaching the utilization of best fit.
A disadvantage of explicit lists in general is that free blocks must be large
enough to contain all of the necessary pointers, as well as the header and possibly
a footer. This results in a larger minimum block size and increases the potential
for internal fragmentation

### 9.9.14 Segregated Free Lists
As we have seen, an allocator that uses a single linked list of free blocks requires
time linear in the number of free blocks to allocate a block. A popular approach for
reducing the allocation time, known generally as segregated storage, is to maintain
multiple free lists, where each list holds blocks that are roughly the same size. The
general idea is to partition the set of all possible block sizes into equivalence classes called size classes. There are many ways to define the size classes.
For example, we might partition the block sizes by powers of 2:
  {1}, {2}, {3, 4}, {5–8}, . . . , {1,025–2,048}, {2,049–4,096}, {4,097–∞}
Or we might assign small blocks to their own size classes and partition large blocks
by powers of 2:
  {1}, {2}, {3}, . . . , {1,023}, {1,024}, {1,025–2,048}, {2,049–4,096}, {4,097–∞}
The allocator maintains an array of free lists, with one free list per size class,
ordered by increasing size. When the allocator needs a block of size n, it searches
the appropriate free list. If it cannot find a block that fits, it searches the next list, and so on.
The dynamic storage allocation literature describes dozens of variants of segregated
storage that differ in how they define size classes, when they perform
coalescing, when they request additional heap memory from the operating system,
whether they allow splitting, and so forth. To give you a sense of what is
possible, we will describe two of the basic approaches: simple segregated storage
and segregated fits.

#### Simple Segregated Storage
With simple segregated storage, the free list for each size class contains same-size
blocks, each the size of the largest element of the size class. For example, if some
size class is defined as {17–32}, then the free list for that class consists entirely of
blocks of size 32.
To allocate a block of some given size, we check the appropriate free list. If the
list is not empty, we simply allocate the first block in its entirety. Free blocks are
never split to satisfy allocation requests. If the list is empty, the allocator requests
a fixed-size chunk of additional memory from the operating system (typically a
multiple of the page size), divides the chunk into equal-size blocks, and links the
blocks together to form the new free list. To free a block, the allocator simply
inserts the block at the front of the appropriate free list.
There are a number of advantages to this simple scheme. Allocating and
freeing blocks are both fast constant-time operations. Further, the combination
of the same-size blocks in each chunk, no splitting, and no coalescing means that
there is very little per-block memory overhead. Since each chunk has only same-size
blocks, the size of an allocated block can be inferred from its address. Since
there is no coalescing, allocated blocks do not need an allocated/free flag in the
header. Thus, allocated blocks require no headers, and since there is no coalescing,
they do not require any footers either. Since allocate and free operations insert
and delete blocks at the beginning of the free list, the list need only be singly
linked instead of doubly linked. The bottom line is that the only required field in
any block is a one-word succ pointer in each free block, and thus the minimum
block size is only one word.
A significant disadvantage is that simple segregated storage is susceptible to
internal and external fragmentation. Internal fragmentation is possible because
free blocks are never split. Worse, certain reference patterns can cause extreme
external fragmentation because free blocks are never coalesced (Practice Problem
9.10).

#### Segregated Fits
With this approach, the allocator maintains an array of free lists. Each free list is
associated with a size class and is organized as some kind of explicit or implicit list.
Each list contains potentially different-size blocks whose sizes are members of the
size class. There are many variants of segregated fits allocators. Here we describe
a simple version.
To allocate a block, we determine the size class of the request and do a first-fit search of the appropriate free list for a block that fits.
 + If we find one, then we (optionally) split it and insert the fragment in the appropriate free list.
 + If we cannot find a block that fits, then we search the free list for the next larger size class.
We repeat until we find a block that fits. If none of the free lists yields a block that fits, then we request additional heap memory from the operating system, allocate the block out of this new heap memory, and place the remainder in the appropriate size class. To free a block, we coalesce and place the result on the appropriate free list.
The segregated fits approach is a popular choice with production-quality
allocators such as the GNU malloc package provided in the C standard library
because it is both fast and memory efficient. Search times are reduced because
searches are limited to particular parts of the heap instead of the entire heap.
Memory utilization can improve because of the interesting fact that a simple first-fit
search of a segregated free list approximates a best-fit search of the entire heap.

#### Buddy Systems
A buddy system is a special case of segregated fits where each size class is a power
of 2. The basic idea is that, given a heap of 2m words, we maintain a separate free
list for each block size 2k, where 0 ≤ k ≤ m. Requested block sizes are rounded up
to the nearest power of 2. Originally, there is one free block of size 2m words.
To allocate a block of size 2k, we find the first available block of size 2j , such
that k ≤ j ≤ m. If j = k, then we are done. Otherwise, we recursively split the block
in half until j = k. As we perform this splitting, each remaining half (known as a
buddy) is placed on the appropriate free list. To free a block of size 2k, we continue
coalescing with the free buddies. When we encounter an allocated buddy, we stop
the coalescing.
A key fact about buddy systems is that, given the address and size of a block,
it is easy to compute the address of its buddy. For example, a block of size 32 bytes
with address
xxx . . . x00000
has its buddy at address
xxx . . . x10000
In other words, the addresses of a block and its buddy differ in exactly one bit
position.
The major advantage of a buddy system allocator is its fast searching and
coalescing. The major disadvantage is that the power-of-2 requirement on the
block size can cause significant internal fragmentation. For this reason, buddy
system allocators are not appropriate for general-purpose workloads. However,
for certain application-specific workloads, where the block sizes are known in
advance to be powers of 2, buddy system allocators have a certain appeal.


## 9.12 Summary
Virtual memory is an abstraction of main memory. Processors that support virtual
memory reference main memory using a form of indirection known as virtual
addressing. The processor generates a virtual address, which is translated into a
physical address before being sent to the main memory. The translation of addresses
from a virtual address space to a physical address space requires close
cooperation between hardware and software. Dedicated hardware translates virtual
addresses using page tables whose contents are supplied by the operating system.
Virtual memory provides three important capabilities.
  + First, it automatically caches recently used contents of the virtual address space stored on disk in main memory. The block in a virtual memory cache is known as a page. A reference to a page on disk triggers a page fault that transfers control to a fault handler in the operating system. The fault handler copies the page from disk to the main memory cache, writing back the evicted page if necessary.
  + Second, virtual memory simplifies memory management, which in turn simplifies linking, sharing data between processes, the allocation of memory for processes, and program loading.
  + Finally, virtual memory simplifies memory protection by incorporating protection bits into every page table entry.
The process of address translation must be integrated with the operation of
any hardware caches in the system. Most page table entries are located in the L1
cache, but the cost of accessing page table entries from L1 is usually eliminated
by an on-chip cache of page table entries called a TLB.
