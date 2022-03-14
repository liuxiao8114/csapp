Figure 4.24

Stage          Computation               OP rA rB                  mrmovq D(rB) rA
-----------------------------------------------------------------------------------------
Fetch          icode:ifun              icode:ifun <- M1[PC]       icode:ifun <- M1[PC]
               rA, rB                  rA:rB <- M1[PC+1]          rA:rB <- M1[PC+1]
               valC                                               valC <- M8[PC+2]
               valP                    valP <- PC+2               valP <- PC+10

Decode         valA, srcA              valA <- R[rA]
               valB, srcB              valB <- R[rB]              valB <- R[rB]

Execute        valE                    valE <- valB OP valA       valE <- valB + valC
               Cond.codes              set CC

Memory         Read/Write                                         valM <- M8[valE]

Writeback      E port, dstE            R[rB] <- valE
               M port, dstM                                       R[rA] <- valM

PC update      PC
