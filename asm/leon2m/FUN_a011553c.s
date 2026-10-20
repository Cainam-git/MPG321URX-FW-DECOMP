# leon2m FUN_a011553c 0xa011553c-0xa0115584 (72 bytes)
a011553c:  9d e3 bf 98  save  %sp, -104, %sp
a0115540:  21 33 c0 8a  sethi  %hi(0xcf022800), %l0
a0115544:  a2 14 23 f8  or  %l0, 0x3f8, %l1	! 0xcf022bf8
a0115548:  c0 24 40 00  clr  [ %l1 ]
a011554c:  d2 04 00 00  ld  [ %l0 ], %o1
a0115550:  31 00 06 8b  sethi  %hi(0x1a2c00), %i0
a0115554:  90 16 23 20  or  %i0, 0x320, %o0	! 0x1a2f20
a0115558:  7f ff 27 06  call  0xa00df170
a011555c:  92 0a 60 ff  and  %o1, 0xff, %o1
a0115560:  c0 24 40 00  clr  [ %l1 ]
a0115564:  82 10 20 aa  mov  0xaa, %g1
a0115568:  c2 24 00 00  st  %g1, [ %l0 ]
a011556c:  c0 24 40 00  clr  [ %l1 ]
a0115570:  f2 04 00 00  ld  [ %l0 ], %i1
a0115574:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0115578:  7f ff 26 fe  call  0xa00df170
a011557c:  91 ee 23 20  restore  %i0, 0x320, %o0
a0115580:  01 00 00 00  nop
