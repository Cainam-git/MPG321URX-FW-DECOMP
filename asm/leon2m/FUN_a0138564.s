# leon2m FUN_a0138564 0xa0138564-0xa0138610 (172 bytes)
a0138564:  9d e3 bf 90  save  %sp, -112, %sp
a0138568:  d2 0e 00 00  ldub  [ %i0 ], %o1
a013856c:  94 0a 60 ff  and  %o1, 0xff, %o2
a0138570:  9b 32 a0 05  srl  %o2, 5, %o5
a0138574:  90 0b 60 02  and  %o5, 2, %o0
a0138578:  83 32 a0 07  srl  %o2, 7, %g1
a013857c:  9f 32 a0 03  srl  %o2, 3, %o7
a0138580:  96 10 40 08  or  %g1, %o0, %o3
a0138584:  98 0b e0 04  and  %o7, 4, %o4
a0138588:  9b 32 a0 01  srl  %o2, 1, %o5
a013858c:  82 12 c0 0c  or  %o3, %o4, %g1
a0138590:  90 0b 60 08  and  %o5, 8, %o0
a0138594:  9e 02 80 0a  add  %o2, %o2, %o7
a0138598:  96 10 40 08  or  %g1, %o0, %o3
a013859c:  98 0b e0 10  and  %o7, 0x10, %o4
a01385a0:  9b 2a a0 03  sll  %o2, 3, %o5
a01385a4:  82 12 c0 0c  or  %o3, %o4, %g1
a01385a8:  90 0b 60 20  and  %o5, 0x20, %o0
a01385ac:  9f 2a a0 05  sll  %o2, 5, %o7
a01385b0:  98 10 40 08  or  %g1, %o0, %o4
a01385b4:  96 0b e0 40  and  %o7, 0x40, %o3
a01385b8:  d0 0e 20 01  ldub  [ %i0 + 1 ], %o0
a01385bc:  9a 0a 60 01  and  %o1, 1, %o5
a01385c0:  9e 13 00 0b  or  %o4, %o3, %o7
a01385c4:  c0 27 bf f0  clr  [ %fp + -16 ]
a01385c8:  95 2b 60 07  sll  %o5, 7, %o2
a01385cc:  93 32 20 04  srl  %o0, 4, %o1
a01385d0:  d6 0e 20 02  ldub  [ %i0 + 2 ], %o3
a01385d4:  82 13 c0 0a  or  %o7, %o2, %g1
a01385d8:  9a 0a 60 03  and  %o1, 3, %o5
a01385dc:  99 32 20 06  srl  %o0, 6, %o4
a01385e0:  d6 2f bf f1  stb  %o3, [ %fp + -15 ]
a01385e4:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a01385e8:  d8 2f bf f2  stb  %o4, [ %fp + -14 ]
a01385ec:  da 2f bf f3  stb  %o5, [ %fp + -13 ]
a01385f0:  90 10 20 90  mov  0x90, %o0
a01385f4:  92 10 20 04  mov  4, %o1
a01385f8:  94 07 bf f0  add  %fp, -16, %o2
a01385fc:  7f ff fa b8  call  0xa01370dc
a0138600:  96 10 20 00  clr  %o3
a0138604:  01 00 00 00  nop
a0138608:  81 c7 e0 08  ret
a013860c:  81 e8 00 00  restore
