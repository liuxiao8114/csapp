compiler works -> what linkers work
static linking

## 7.1 Compiler Drivers
precompile(cpp) -> compile(as) -> link(ld)

linker
loader: load program into memory and transfer control to the program.

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

## 7.5 Symbol and Symbol Tables
Each relocatable object module m, has a symbol table that contains information about the symbols that are defined and referenced by m.
In the context of a linker, there are three different kinds of symbols:
1. Global symbols defined by module m and can referenced by other modules.
2. Global symbols referenced by module m but defined by some other module.
3. Local symbols defined and referenced exclusively by module m.

fig7.4
+ name:
+ value: the symbol's address.
    for relocatable modules, the value is an offset from the beginning of the section where the object is defined.
    for executable object files,

Each symbol is assigned to some section of the object file

## 7.7
1. Relocating sections and symbol definitions.
  The linker then assigns run-time memory addresses to the new aggregate sections
2. Relocating symbol references within sections.

### 7.7.1 Relocation Entries
Whenever the assembler encounters a reference to an object whose
ultimate location is unknown, it generates a relocation entry that tells the linker how to modify the reference when it merges the object file into an executable.

ELF to basic relocation types:
R_X86_64_PC32
R_X86_64_32

offset: the section offset of the reference
symbol: the symbol that the modified reference should point to
type: relocation type
addend: A signed constant that is used by some types of relocations to bias
the value of the modified reference.


ADDR(s) = ADDR(.text)
ADDR(r.symbol) = ADDR(sum)

refaddr = ADDR(s) + r.offset
        = 0x4004d0 + 0xf

## 7.8 Executable Object Files
  Read-only  code  segment
1   LOAD    
2

## 7.9 Loading Executable Object Files
