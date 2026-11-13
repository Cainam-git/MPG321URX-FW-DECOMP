# leon2s FUN_a00ad060 0xa00ad060-0xa00ad09c (60 bytes)
a00ad060:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ad064:  80 a2 20 02  cmp  %o0, 2
a00ad068:  18 80 00 0b  bgu  0xa00ad094
a00ad06c:  19 2a 01 e4  sethi  %hi(0xa8079000), %o4
a00ad070:  82 10 20 01  mov  1, %g1
a00ad074:  80 a2 20 02  cmp  %o0, 2
a00ad078:  12 80 00 04  bne  0xa00ad088
a00ad07c:  9b 28 40 08  sll  %g1, %o0, %o5
a00ad080:  10 80 00 05  b  0xa00ad094
a00ad084:  c0 2b 23 12  clrb  [ %o4 + 0x312 ]
a00ad088:  c2 0b 23 12  ldub  [ %o4 + 0x312 ], %g1
a00ad08c:  82 28 40 0d  andn  %g1, %o5, %g1
a00ad090:  c2 2b 23 12  stb  %g1, [ %o4 + 0x312 ]
a00ad094:  81 c3 e0 08  retl
a00ad098:  01 00 00 00  nop
