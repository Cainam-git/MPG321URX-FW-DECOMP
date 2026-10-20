# leon2s FUN_a008a1f8 0xa008a1f8-0xa008a224 (44 bytes)
a008a1f8:  90 0a 20 ff  and  %o0, 0xff, %o0
a008a1fc:  80 a2 20 00  cmp  %o0, 0
a008a200:  02 80 00 07  be  0xa008a21c
a008a204:  80 a2 20 01  cmp  %o0, 1
a008a208:  12 80 00 05  bne  0xa008a21c
a008a20c:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008a210:  9a 10 20 40  mov  0x40, %o5
a008a214:  82 10 60 24  or  %g1, 0x24, %g1
a008a218:  da 20 40 00  st  %o5, [ %g1 ]
a008a21c:  81 c3 e0 08  retl
a008a220:  01 00 00 00  nop
