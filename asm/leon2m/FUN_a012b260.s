# leon2m FUN_a012b260 0xa012b260-0xa012b328 (200 bytes)
a012b260:  9d e3 bf 80  save  %sp, -128, %sp
a012b264:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a012b268:  9e 12 21 a0  or  %o0, 0x1a0, %o7	! 0xa802e1a0
a012b26c:  90 0e 20 ff  and  %i0, 0xff, %o0
a012b270:  c2 0b e0 2c  ldub  [ %o7 + 0x2c ], %g1
a012b274:  ab 2a 20 02  sll  %o0, 2, %l5
a012b278:  13 2a 00 b6  sethi  %hi(0xa802d800), %o1
a012b27c:  95 38 40 15  sra  %g1, %l5, %o2
a012b280:  ac 12 60 ae  or  %o1, 0xae, %l6
a012b284:  98 10 20 01  mov  1, %o4
a012b288:  b0 5a 20 16  smul  %o0, 0x16, %i0
a012b28c:  e0 0b e0 33  ldub  [ %o7 + 0x33 ], %l0
a012b290:  82 06 00 16  add  %i0, %l6, %g1
a012b294:  a4 0a a0 0f  and  %o2, 0xf, %l2
a012b298:  97 2b 00 15  sll  %o4, %l5, %o3
a012b29c:  9a 0e 60 ff  and  %i1, 0xff, %o5
a012b2a0:  f2 28 60 06  stb  %i1, [ %g1 + 6 ]
a012b2a4:  a7 2b 40 15  sll  %o5, %l5, %l3
a012b2a8:  a3 2a c0 12  sll  %o3, %l2, %l1
a012b2ac:  a9 2c c0 12  sll  %l3, %l2, %l4
a012b2b0:  b2 2c 00 11  andn  %l0, %l1, %i1
a012b2b4:  ea 15 80 18  lduh  [ %l6 + %i0 ], %l5
a012b2b8:  98 16 40 14  or  %i1, %l4, %o4
a012b2bc:  d2 10 60 08  lduh  [ %g1 + 8 ], %o1
a012b2c0:  ec 10 60 14  lduh  [ %g1 + 0x14 ], %l6
a012b2c4:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a012b2c8:  d6 10 60 04  lduh  [ %g1 + 4 ], %o3
a012b2cc:  d4 10 60 06  lduh  [ %g1 + 6 ], %o2
a012b2d0:  e0 10 60 0a  lduh  [ %g1 + 0xa ], %l0
a012b2d4:  e2 10 60 0c  lduh  [ %g1 + 0xc ], %l1
a012b2d8:  e4 10 60 0e  lduh  [ %g1 + 0xe ], %l2
a012b2dc:  e6 10 60 10  lduh  [ %g1 + 0x10 ], %l3
a012b2e0:  e8 10 60 12  lduh  [ %g1 + 0x12 ], %l4
a012b2e4:  d8 2b e0 33  stb  %o4, [ %o7 + 0x33 ]
a012b2e8:  d2 37 bf e8  sth  %o1, [ %fp + -24 ]
a012b2ec:  ea 37 bf e0  sth  %l5, [ %fp + -32 ]
a012b2f0:  da 37 bf e2  sth  %o5, [ %fp + -30 ]
a012b2f4:  d6 37 bf e4  sth  %o3, [ %fp + -28 ]
a012b2f8:  d4 37 bf e6  sth  %o2, [ %fp + -26 ]
a012b2fc:  e0 37 bf ea  sth  %l0, [ %fp + -22 ]
a012b300:  e2 37 bf ec  sth  %l1, [ %fp + -20 ]
a012b304:  e4 37 bf ee  sth  %l2, [ %fp + -18 ]
a012b308:  e6 37 bf f0  sth  %l3, [ %fp + -16 ]
a012b30c:  e8 37 bf f2  sth  %l4, [ %fp + -14 ]
a012b310:  ec 37 bf f4  sth  %l6, [ %fp + -12 ]
a012b314:  40 00 31 9a  call  0xa013797c
a012b318:  92 07 bf e0  add  %fp, -32, %o1
a012b31c:  01 00 00 00  nop
a012b320:  81 c7 e0 08  ret
a012b324:  81 e8 00 00  restore
