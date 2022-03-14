Stage     jXX Dest                    call Dest                       ret
----------------------------------------------------------------------------------------
Fetch     icode:ifun <- M1[PC]        icode:ifun <- M1[PC]            icode:ifun <- M1[PC]

          valC   <- M8[PC + 1]        valC   <- M8[PC + 1]
          valP       <- PC + 9        valP       <- PC + 9            valP       <- PC + 1

Decode                                                                valA <- R[%rsp]
                                      valB <- R[%rsp]                 valB <- R[%rsp]

Execute                               valE <- valB + (-8)             valE <- valB + 8
          Cnd <- Cond(CC, ifun)
Memory                                M8[valE] <- valP                valM <- M8[valA]

WriteBack                             R[%rsp]  <- valE                R[%rsp] <- valE

Update    PC <- Cnd ? valC : valP     PC <- valC                      PC <- valM
