# leon2s FUN_a0089e24 0xa0089e24-0xa0089e4c (40 bytes)
a0089e24:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089e28:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0089e2c:  82 10 61 04  or  %g1, 0x104, %g1	! 0xa807cd04
a0089e30:  91 2a 20 03  sll  %o0, 3, %o0
a0089e34:  98 02 00 01  add  %o0, %g1, %o4
a0089e38:  9a 10 20 01  mov  1, %o5
a0089e3c:  da 28 40 08  stb  %o5, [ %g1 + %o0 ]
a0089e40:  c0 2b 20 04  clrb  [ %o4 + 4 ]
a0089e44:  81 c3 e0 08  retl
a0089e48:  c0 2b 20 01  clrb  [ %o4 + 1 ]
