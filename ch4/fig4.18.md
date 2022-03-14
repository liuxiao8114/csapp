Stage     OPq rA, rB                  rrmovq rA, rB                   irmovq V, rB
---------------------------------------------------------------------------------------------
Fetch     icode:ifun <- M1[PC]        icode:ifun <- M1[PC]            icode:ifun <- M1[PC]
          rA:rB      <- M1[PC + 1]    rA:rB      <- M1[PC + 1]        rA:rB      <- M1[PC + 1]
                                                                      valC       <- M8[PC + 2]
          valP       <- PC + 2        valP       <- PC + 2            valP       <- PC + 10

Decode    valA <- R[rA]               valA <- R[rA]                   
          valB <- R[rB]               

Execute   valE <- valB OP valA        valE <- 0 + valA // WHY?        valE <- 0 + valC // WHY?
          Set CC

Memory    

WriteBack R[rB] <- valE               R[rB]  <- valE                 R[rB]  <- valE

Update    PC <- valP                  PC <- valP                     PC <- valP
