Stage     rmmovq rA, D(rB)            mrmovq D(rB), rA
------------------------------------------------------------------
Fetch     icode:ifun <- M1[PC]        icode:ifun <- M1[PC]
          rA:rB      <- M1[PC + 1]    rA:rB      <- M1[PC + 1]
          valC       <- M8[PC + 2]    valC       <- M8[PC + 2]
          valP       <- PC + 10       valP       <- PC + 10

Decode    valA <- R[rA]               
          valB <- R[rB]               valB <- R[rB]

Execute   valE <- valB + valC         valE <- valB + valC

Memory    M8[valE] <- valA            valM <- M8[valE]

WriteBack                             R[rA]  <- valM

Update    PC <- valP                  PC <- valP
