Figure 4.2 Y86-64 instruction set

Byte                  0       1       2       3       4       5       6       7       8       9
------------------------------------------------------------------------------------------------
halt                  0   0
nop                   1   0
rrmovq  rA,  rB       2   0   rA  rB
irmovq  V,   rB       3   0   F   rB  V<------------------------------------------------------>V
rmmovq  rA,  D(rB)    4   0   rA  rB  D<------------------------------------------------------>D
mrmovq  D(rB),  rA    5   0   rA  rB  D<------------------------------------------------------>D
OPq     rA,  rB       6   fn  rA  rB
jXX     Dest          7   fn  Dest<---------------------------------------------->Dest
cmovXX  rA,  rB       2   fn  rA  rB
call    Dest          8   0   Dest<---------------------------------------------->Dest
ret                   9   0
pushq   rA            A   0   rA  F
popq    rA            B   0   rA  F
