compiler works -> what linkers work
static linking

## 7.1 Compiler Drivers
precompile(cpp) -> compile(as) -> link(ld)

linker
loader: load program into memory and transfer control to the program.

main.c sum.c
----------------------
cpp main.c /tmp/main.i
cc1 -o /tmp/main.s /tmp/main.i
as -o /tmp/main.o /tmp/main.s
ld -o prog /tmp/main.o /tmp/sum.o

## 7.2 Static Linking
static linker take *a collection of relocatable object* files and command-line arguments as input and generate *a fully linked executable object* as output.

## 7.3 Object Files
three forms:
  Relocatable object file
  Executable object file
  Shared object file

Compliers and assemblers generate relocatable object files.
Linkers generate executable object files.

object file formats:
Linux   ELF
Windows PE

## 7.4 Relocatable Object Files
Fig 7.3
Setctions --- ELF header
            | .text      :
            | .rodata    :   
            | .data      : Initialized global and static C variables.
            | .bss       : Information about functions and global variables that defined and referenced in the program. Not contain entries for local variables.
            | .symtab    :  
            | .rel.text  :     
            | .rel.data  :     
            | .debug     :   
            | .line      :
            | .strtab    :   
          ---
            | Section header table
          ---

<Details about ELF format>
+ ELF header: contains information that allows a linker to parse and interpret the object file. Includes
              the size of the ELF header, the object file type(relocatable, executable or shared), the machine type(x86-64 e.g.)

## 7.5 Symbol and Symbol Tables
### <Symbol>
Each relocatable object module m, has a symbol table that contains information about the symbols that are defined and referenced by m.
In the context of a linker, there are three different kinds of symbols:
1. Global symbols defined by module m and can referenced by other modules.
2. Global symbols referenced by module m but defined by some other module.
3. Local symbols defined and referenced exclusively by module m.

Local linker symbols are not the same as local program variables. These are managed at run time on the stack and are not of interest to the linker.
Local procedure variables that are defined with the C static attribute are not managed on the stack.

### <Symbol tables>
Symbol tables are built by assemblers, using symbols exported by the complier into the assembly-language .s file. An ELF symbol table is contained in the .symtab section. It contains an array of entries showed in Fig7.4:

Fig7.4 ELF symbol table entry.
----------------------------------------------------------
typedef struct {

} symbol
----------------------------------------------------------

+ name: String table offset
+ value: the symbol's address.
  + for relocatable modules, the value is an offset from the beginning of the section where the object is defined.
  + for executable object files, the value is an absolute run-time address.
+ size: Object size in bytes

Each symbol is assigned to some section of the object file, denoted by the *section* field, which is an index into the section header table. There are three special pseudosections that don't have entries in the section header table.
  + ABS
  + UND
  + COMMON

## 7.6 Symbol Resolution
Symbol resolution is a straightforward for references to local symbols that are defined in the same module as the reference.
Symbol resolution for global symbols is tricker because:
1. When the compiler encounters a symbol that is not defined in the current module, it assumes that it is defined in some other module, generates a linker symbol table entry, and leaves it for the linker to handle.
2. multiple object modules might define global symbols with the same name.

### 7.6.1 How Linkers Resolve Duplicate Symbol Names
In some cases the linker allows multiple modules to define global symbols with the same name.
when the complier is translating some module and encounter a weak global symbol, say, x, it does not know if other modules also define x, and if so, it cannot predict which of the multiple instances of the x

+ Mulitple strong symbols with the same name are not allowed.

```c
/* foo3.c */
#include <stdio.h>
void f(void);

int x = 15213;

int main() {
  f();
  printf("%x\n", x);
  return 0;
}

/* bar3.c */
int x;
void f() {
  x = 15212;
}

```

When the compiler is translating some module and encounters a weak global symbol, say, x, it does not know if other modules also define x, and if so, it cannot predict which of the multiple instances of x the linker might choose. So the compiler defers the decision to the linker by assigning x to COMMON.
On the other hand, if x is initialized to zero, then it is a strong symbol(and thus must be unique by rule 2), so the compiler can confidently assign it to .bss.

### 7.6.2 Linking with Static Libraries
+ have the compiler recognize calls to the standard functions and to generate the appropriate code directly.
+ put all of the standard C functions in a single relocatable object module, that application programmers could link into their executables

Related functions can be compiled into separate object modules and then packaged in a single static library file.

The -static argument tells the complier driver that the linker should build a fully linked executable object file that can be loaded into memory and run without any further linking at load time.

### 7.6.3 How Linkers Use Static Libraries to Resolve References
During the symbol resolution phase, the linker scans the relocatable object files and archives left to right in the same sequential order that they appear on the compiler driver’s command line. (The driver automatically translates any .c files on the command line into .o files.)

a set E of relocatable object files that will be merged to form the executable
a set U of unresolved symbols
a set D pf symbols that have been defined in previous input files

## 7.7 Relocation
1. Relocating sections and symbol definitions.
   The linker then assigns run-time memory addresses to the new aggregate sections
2. Relocating symbol references within sections.

### 7.7.1 Relocation Entries
Whenever the assembler encounters a reference to an object whose ultimate location is unknown, it generates a relocation entry that tells the linker how to modify the reference when it merges the object file into an executable.
Relocation entries for code are placed in .rel.text.
Relocation entries for data are placed in .rel.data.

```c
typedef struct {
  long offset; // the section offset of the reference
  long type: 32;   // relocation type
       symbol: 32; // the symbol that the modified reference should point to
  long addend; // a signed constant that is used by some types of relocations to bias the value of the modified reference.
} Elf_Rela;
```

ELF to basic relocation types:
+ R_X86_64_PC32:
+ R_X86_64_32:

### 7.7.2 Relocating Symbol References

Fig 7.9 psedocode for relocate entry
----------------------------------------------------------
foreach section s {
  foreach relocation entry r {
    refptr = s + r.offset;

    if(r.type == R_X86_64_PC32) {
      refaddr = ADDR(s) + r.offset;
      *refptr = (ADDR(r.symbol))
    }
    if(r.type == R_X86_64_32) {
      refaddr = ADDR(s) + r.offset;
      *refptr
    }
  }
}
----------------------------------------------------------

Fig 7.11 Code and relocation entries from main.o. (Original C code in Fig 7.1)
----------------------------------------------------------
subq  $0x8, %rsp
movq  $0x2, %esi
movq  $0x0, %edi
   a: R_X86_64_32   array
callq 13
   f: R_X86_64_PC32 sum-0x4
addq  $0x8, %rsp
retq
----------------------------------------------------------

Suppose:
ADDR(s) = ADDR(.text) = 0x4004d0
ADDR(r.symbol) = ADDR(sum) = 0x4004e8

refaddr = ADDR(s) + r.offset
        = 0x4004d0 + 0xf
        = 0x4004df

refptr  = s + r.offset
*refptr = (ADDR(r.symbol) + r.addend - refaddr)
        = 0x4004e8 +

## 7.8 Executable Object Files
### <Segment/program header table>
p.732
ELF executables are designed to be easy to load into memory, with contiguous chunks of the executable file mapped to contiguous memory segments. This mapping is described by the program header table.

Fig 7.13 Typical ELF executable object file
----------------------------------------------------------
ELF header
Segment header table
.init
.text
.rodata
.data
.bss
.symtab
.debug
.line
.strtab
Section header table
----------------------------------------------------------

Fig 7.14 Program header table for the example executable prog.
----------------------------------------------------------
  Read-only code segment
1   LOAD    
2

  Read/write data segment
1
2
----------------------------------------------------------

For any segment s, the linker must choose a starting address, vaddr
  vaddr mod align = off mod align

## 7.9 Loading Executable Object Files
The loader copies the code and data in the executable object file from disk into memory and then runs the program by jumping to its first instruction, or entry point. This process of copying the program into memory and then running it is known as loading.

Fig 7.15 Linux x86-64 run-time memory image
----------------------------------------------------------
+ code segment
+ data segment
+ run-time heap and grows upward via calls to the malloc library
+ shared modules
+ user stack
+ kernel
----------------------------------------------------------

When the loader runs, it creates a memory image similar to the one shown in Fig 7.15. Guided by the program header table, it copies chunks of the executable object file into the code and data segments. Next, the loader jumps to the program's entry point, which is always the address of the _start function. This function is defined in the system object file crt1.o and is the same for all C programs. The _start function calls the system startup function, __libc_start_main, which is defined in libc.so. It initializes the execution environment, calls the user-level main function, handles its return value, and if necessary returns control to the kernel.

## 7.10 Dynamic Linking with Shared Libraries
+ Static libraries, like all software, need to be maintained and updated periodically.
+ Almost every C program uses standard IO functions such as printf and scanf. At run time, the code for these functions is duplicated in the text segment of each running process.

Shared libraries are "shared" in two different ways.
+ in any given file system, there is exactly one .so file for a particular library. The code and data in this .so file are shared by all of the executable object files that reference the library, as opposed to the contents of static libraries, which are copied and embedded in the executables that reference them.
+ a single copy of the .text section of a shared library in memory can be shared by different running processes. <Chapter 9>

Fig 7.16 Dynamic linking with share libraries

gcc -fgic -shared -o libvector.so addvec.c multvec.c
gcc -o progl main2.c ./libvector.so

The basic idea

...
.interp section, which contains the path name of the dynamic linker, which is itself a shared object. Instead of passing control to the application, as it would normally do, the loader loads and runs the dynamic linker.

## 7.11 Loading and Linking Shared Libraries from Applications
it is possible for an application to request the dynamic linker to load and link arbitrary shared libraries while the application is running, without having to link in the applications against those libraries at compile time.

void *dlopen(const char *filename, int flag);

The dlopen function loads and links the shared library filename. The external symbols in filename are resolved using libraries previously opened with RTLD_GLOABAL flag.


## 7.12 Position-Independent Code(PIC)

Modern systems compile the code segments of shared modules so that they can be loaded anywhere in memory without having to be modified by the linker.
Code that can be loaded without needing any relocations is known as PIC.

#### PIC Data References
Compilers generate PIC References to global variables by exploiting the fact that:
no matter where we load an object module(including the share object modules) in memory,
the data segment is always the same distance from the code segment. Thus, the distance between any instruction in the code segment

GOT: Global offset table
+ GOT is created at the beginning of the data segment
+ GOT contains an 8-byte entry for each global data object
+ The compiler also generates a relocation record for each GOT for the dynamic linker relocates each GOT entry so that contains the absolute address of the object at load time
+ Each object module that references global objects has its own GOT

#### PIC Function Calls
lazy binding is implemented with an interaction between two data structures:
GOT(global object table) and PLT(procedure linkage table)

+ PLT is an array of 16-byte code entries
+ Each shared library function called by the executable has it own PLT entry
+ PLT[0] is a special entry that jumps into the dynamic linker
+ PLT[1] invokes the system startup function
+ Entries starting at PLT[2] invoke functions called by the user code
