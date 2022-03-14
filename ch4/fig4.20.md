Stage     pushq rA                    popq rA
------------------------------------------------------------------
Fetch     icode:ifun <- M1[PC]        icode:ifun <- M1[PC]
          rA:rB      <- M1[PC + 1]    rA:rB      <- M1[PC + 1]

          valP       <- PC + 2        valP       <- PC + 2

Decode    valA <- R[rA]               valA <- R[%rsp]
          valB <- R[%rsp]             valB <- R[%rsp]

Execute   valE <- valB + (-8)         valE <- valB + 8

Memory    M8[valE] <- valA            valM <- M8[valA]

WriteBack R[%rsp]  <- valE            R[%rsp]<- valE
                                      R[rA]  <- valM

Update    PC <- valP                  PC <- valP
