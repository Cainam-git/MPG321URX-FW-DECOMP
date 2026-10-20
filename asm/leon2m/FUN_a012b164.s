# leon2m FUN_a012b164 0xa012b164-0xa012b22c (200 bytes)
a012b164:  9d e3 bf 80  save  %sp, -128, %sp
a012b168:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a012b16c:  9e 12 21 a0  or  %o0, 0x1a0, %o7	! 0xa802e1a0
a012b170:  90 0e 20 ff  and  %i0, 0xff, %o0
a012b174:  c2 0b e0 2c  ldub  [ %o7 + 0x2c ], %g1
a012b178:  ab 2a 20 02  sll  %o0, 2, %l5
a012b17c:  13 2a 00 b6  sethi  %hi(0xa802d800), %o1
a012b180:  95 38 40 15  sra  %g1, %l5, %o2
a012b184:  ac 12 60 ae  or  %o1, 0xae, %l6
a012b188:  98 10 20 01  mov  1, %o4
a012b18c:  b0 5a 20 16  smul  %o0, 0x16, %i0
a012b190:  e0 0b e0 32  ldub  [ %o7 + 0x32 ], %l0
a012b194:  82 06 00 16  add  %i0, %l6, %g1
a012b198:  a4 0a a0 0f  and  %o2, 0xf, %l2
a012b19c:  97 2b 00 15  sll  %o4, %l5, %o3
a012b1a0:  9a 0e 60 ff  and  %i1, 0xff, %o5
a012b1a4:  f2 28 60 07  stb  %i1, [ %g1 + 7 ]
a012b1a8:  a7 2b 40 15  sll  %o5, %l5, %l3
a012b1ac:  a3 2a c0 12  sll  %o3, %l2, %l1
a012b1b0:  a9 2c c0 12  sll  %l3, %l2, %l4
a012b1b4:  b2 2c 00 11  andn  %l0, %l1, %i1
a012b1b8:  ea 15 80 18  lduh  [ %l6 + %i0 ], %l5
a012b1bc:  98 16 40 14  or  %i1, %l4, %o4
a012b1c0:  d2 10 60 08  lduh  [ %g1 + 8 ], %o1
a012b1c4:  ec 10 60 14  lduh  [ %g1 + 0x14 ], %l6
a012b1c8:  da 10 60 02  lduh  [ %g1 + 2 ], %o5
a012b1cc:  d6 10 60 04  lduh  [ %g1 + 4 ], %o3
a012b1d0:  d4 10 60 06  lduh  [ %g1 + 6 ], %o2
a012b1d4:  e0 10 60 0a  lduh  [ %g1 + 0xa ], %l0
a012b1d8:  e2 10 60 0c  lduh  [ %g1 + 0xc ], %l1
a012b1dc:  e4 10 60 0e  lduh  [ %g1 + 0xe ], %l2
a012b1e0:  e6 10 60 10  lduh  [ %g1 + 0x10 ], %l3
a012b1e4:  e8 10 60 12  lduh  [ %g1 + 0x12 ], %l4
a012b1e8:  d8 2b e0 32  stb  %o4, [ %o7 + 0x32 ]
a012b1ec:  d2 37 bf e8  sth  %o1, [ %fp + -24 ]
a012b1f0:  ea 37 bf e0  sth  %l5, [ %fp + -32 ]
a012b1f4:  da 37 bf e2  sth  %o5, [ %fp + -30 ]
a012b1f8:  d6 37 bf e4  sth  %o3, [ %fp + -28 ]
a012b1fc:  d4 37 bf e6  sth  %o2, [ %fp + -26 ]
a012b200:  e0 37 bf ea  sth  %l0, [ %fp + -22 ]
a012b204:  e2 37 bf ec  sth  %l1, [ %fp + -20 ]
a012b208:  e4 37 bf ee  sth  %l2, [ %fp + -18 ]
a012b20c:  e6 37 bf f0  sth  %l3, [ %fp + -16 ]
a012b210:  e8 37 bf f2  sth  %l4, [ %fp + -14 ]
a012b214:  ec 37 bf f4  sth  %l6, [ %fp + -12 ]
a012b218:  40 00 32 14  call  0xa0137a68
a012b21c:  92 07 bf e0  add  %fp, -32, %o1
a012b220:  01 00 00 00  nop
a012b224:  81 c7 e0 08  ret
a012b228:  81 e8 00 00  restore
