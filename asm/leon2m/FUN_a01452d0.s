# leon2m FUN_a01452d0 0xa01452d0-0xa0145348 (120 bytes)
a01452d0:  9d e3 bf 98  save  %sp, -104, %sp
a01452d4:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a01452d8:  a2 14 21 a0  or  %l0, 0x1a0, %l1	! 0xa802e1a0
a01452dc:  19 00 3f ff  sethi  %hi(0xfffc00), %o4
a01452e0:  d4 04 60 04  ld  [ %l1 + 4 ], %o2
a01452e4:  90 13 23 ff  or  %o4, 0x3ff, %o0
a01452e8:  9b 2e 20 18  sll  %i0, 0x18, %o5
a01452ec:  f4 04 21 a0  ld  [ %l0 + 0x1a0 ], %i2
a01452f0:  92 0a 80 08  and  %o2, %o0, %o1
a01452f4:  b1 2e 60 10  sll  %i1, 0x10, %i0
a01452f8:  82 12 40 0d  or  %o1, %o5, %g1
a01452fc:  96 0e bf 00  and  %i2, -256, %o3
a0145300:  9f 36 20 18  srl  %i0, 0x18, %o7
a0145304:  94 08 40 08  and  %g1, %o0, %o2
a0145308:  99 2e 20 08  sll  %i0, 8, %o4
a014530c:  9a 12 c0 0f  or  %o3, %o7, %o5
a0145310:  92 12 80 0c  or  %o2, %o4, %o1
a0145314:  da 24 21 a0  st  %o5, [ %l0 + 0x1a0 ]
a0145318:  d2 24 60 04  st  %o1, [ %l1 + 4 ]
a014531c:  90 10 00 11  mov  %l1, %o0
a0145320:  40 00 39 94  call  0xa0153970
a0145324:  92 10 20 00  clr  %o1
a0145328:  d0 0c 21 a3  ldub  [ %l0 + 0x1a3 ], %o0
a014532c:  83 2a 20 08  sll  %o0, 8, %g1
a0145330:  f2 0c 60 04  ldub  [ %l1 + 4 ], %i1
a0145334:  b2 16 40 01  or  %i1, %g1, %i1
a0145338:  b0 10 20 01  mov  1, %i0
a014533c:  7f fe ff 03  call  0xa0104f48
a0145340:  95 e8 00 19  restore  %g0, %i1, %o2
a0145344:  01 00 00 00  nop
