# leon2s FUN_a008ae18 0xa008ae18-0xa008ae34 (28 bytes)
a008ae18:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008ae1c:  9a 10 20 01  mov  1, %o5
a008ae20:  d8 08 63 31  ldub  [ %g1 + 0x331 ], %o4
a008ae24:  9b 2b 40 08  sll  %o5, %o0, %o5
a008ae28:  9a 13 40 0c  or  %o5, %o4, %o5
a008ae2c:  81 c3 e0 08  retl
a008ae30:  da 28 63 31  stb  %o5, [ %g1 + 0x331 ]
