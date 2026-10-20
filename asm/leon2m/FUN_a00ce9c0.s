# leon2m FUN_a00ce9c0 0xa00ce9c0-0xa00cea18 (88 bytes)
a00ce9c0:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00ce9c4:  99 33 60 10  srl  %o5, 0x10, %o4
a00ce9c8:  80 a3 20 38  cmp  %o4, 0x38
a00ce9cc:  82 60 20 00  subx  %g0, 0, %g1
a00ce9d0:  90 0a 00 01  and  %o0, %g1, %o0
a00ce9d4:  19 00 00 40  sethi  %hi(0x10000), %o4
a00ce9d8:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00ce9dc:  82 13 20 00  mov  %o4, %g1
a00ce9e0:  94 0a a0 ff  and  %o2, 0xff, %o2
a00ce9e4:  91 33 60 07  srl  %o5, 7, %o0
a00ce9e8:  90 02 00 01  add  %o0, %g1, %o0
a00ce9ec:  95 2a a0 04  sll  %o2, 4, %o2
a00ce9f0:  98 10 20 00  clr  %o4
a00ce9f4:  82 02 00 0c  add  %o0, %o4, %g1
a00ce9f8:  da 08 40 0a  ldub  [ %g1 + %o2 ], %o5
a00ce9fc:  da 2a 40 0c  stb  %o5, [ %o1 + %o4 ]
a00cea00:  98 03 20 01  inc  %o4
a00cea04:  80 a3 20 0f  cmp  %o4, 0xf
a00cea08:  04 bf ff fc  ble  0xa00ce9f8
a00cea0c:  82 02 00 0c  add  %o0, %o4, %g1
a00cea10:  81 c3 e0 08  retl
a00cea14:  01 00 00 00  nop
