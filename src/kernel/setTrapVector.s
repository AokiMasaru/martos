    .global setTrapVector
    .type setTrapVector,@function
setTrapVector:
    csrw  mtvec, a0
    ret
    .size setTrapVector,.-setTrapVector
