# leon2m FUN_a013832c 0xa013832c-0xa013844c (288 bytes)
a013832c:  9d e3 bf 80  save  %sp, -128, %sp
a0138330:  f6 06 40 00  ld  [ %i1 ], %i3
a0138334:  93 36 e0 14  srl  %i3, 0x14, %o1
a0138338:  99 36 e0 17  srl  %i3, 0x17, %o4
a013833c:  90 0a 60 20  and  %o1, 0x20, %o0
a0138340:  94 0b 20 10  and  %o4, 0x10, %o2
a0138344:  9f 36 e0 19  srl  %i3, 0x19, %o7
a0138348:  a2 12 00 0a  or  %o0, %o2, %l1
a013834c:  a0 0b e0 08  and  %o7, 8, %l0
a0138350:  a9 36 e0 1b  srl  %i3, 0x1b, %l4
a0138354:  ac 14 40 10  or  %l1, %l0, %l6
a0138358:  aa 0d 20 04  and  %l4, 4, %l5
a013835c:  af 36 e0 1d  srl  %i3, 0x1d, %l7
a0138360:  b8 15 80 15  or  %l6, %l5, %i4
a0138364:  ba 0d e0 02  and  %l7, 2, %i5
a0138368:  a6 17 00 1d  or  %i4, %i5, %l3
a013836c:  a5 36 e0 1f  srl  %i3, 0x1f, %l2
a0138370:  ea 16 60 04  lduh  [ %i1 + 4 ], %l5
a0138374:  96 14 c0 12  or  %l3, %l2, %o3
a0138378:  e8 06 60 14  ld  [ %i1 + 0x14 ], %l4
a013837c:  ec 16 60 06  lduh  [ %i1 + 6 ], %l6
a0138380:  ee 16 60 08  lduh  [ %i1 + 8 ], %l7
a0138384:  fa 16 60 0a  lduh  [ %i1 + 0xa ], %i5
a0138388:  f8 16 60 0c  lduh  [ %i1 + 0xc ], %i4
a013838c:  f6 16 60 0e  lduh  [ %i1 + 0xe ], %i3
a0138390:  91 35 60 08  srl  %l5, 8, %o0
a0138394:  c2 0e 60 01  ldub  [ %i1 + 1 ], %g1
a0138398:  da 0e 60 02  ldub  [ %i1 + 2 ], %o5
a013839c:  d8 0e 60 18  ldub  [ %i1 + 0x18 ], %o4
a01383a0:  d4 0e 60 19  ldub  [ %i1 + 0x19 ], %o2
a01383a4:  93 3d 20 08  sra  %l4, 8, %o1
a01383a8:  d0 2f bf e9  stb  %o0, [ %fp + -23 ]
a01383ac:  9f 35 a0 08  srl  %l6, 8, %o7
a01383b0:  a1 35 e0 08  srl  %l7, 8, %l0
a01383b4:  a3 37 60 08  srl  %i5, 8, %l1
a01383b8:  a5 37 20 08  srl  %i4, 8, %l2
a01383bc:  a7 36 e0 08  srl  %i3, 8, %l3
a01383c0:  d0 16 60 10  lduh  [ %i1 + 0x10 ], %o0
a01383c4:  d6 2f bf e1  stb  %o3, [ %fp + -31 ]
a01383c8:  c2 2f bf e2  stb  %g1, [ %fp + -30 ]
a01383cc:  da 2f bf e3  stb  %o5, [ %fp + -29 ]
a01383d0:  d2 2f bf e5  stb  %o1, [ %fp + -27 ]
a01383d4:  d8 2f bf e6  stb  %o4, [ %fp + -26 ]
a01383d8:  d4 2f bf e7  stb  %o2, [ %fp + -25 ]
a01383dc:  f0 2f bf e0  stb  %i0, [ %fp + -32 ]
a01383e0:  de 2f bf eb  stb  %o7, [ %fp + -21 ]
a01383e4:  e0 2f bf ed  stb  %l0, [ %fp + -19 ]
a01383e8:  e2 2f bf ef  stb  %l1, [ %fp + -17 ]
a01383ec:  e4 2f bf f1  stb  %l2, [ %fp + -15 ]
a01383f0:  e6 2f bf f3  stb  %l3, [ %fp + -13 ]
a01383f4:  e8 2f bf e4  stb  %l4, [ %fp + -28 ]
a01383f8:  ea 2f bf e8  stb  %l5, [ %fp + -24 ]
a01383fc:  ec 2f bf ea  stb  %l6, [ %fp + -22 ]
a0138400:  ee 2f bf ec  stb  %l7, [ %fp + -20 ]
a0138404:  fa 2f bf ee  stb  %i5, [ %fp + -18 ]
a0138408:  f8 2f bf f0  stb  %i4, [ %fp + -16 ]
a013840c:  f6 2f bf f2  stb  %i3, [ %fp + -14 ]
a0138410:  d0 2f bf f4  stb  %o0, [ %fp + -12 ]
a0138414:  d8 16 60 12  lduh  [ %i1 + 0x12 ], %o4
a0138418:  83 32 20 08  srl  %o0, 8, %g1
a013841c:  9b 33 20 08  srl  %o4, 8, %o5
a0138420:  c2 2f bf f5  stb  %g1, [ %fp + -11 ]
a0138424:  da 2f bf f7  stb  %o5, [ %fp + -9 ]
a0138428:  d8 2f bf f6  stb  %o4, [ %fp + -10 ]
a013842c:  90 10 20 50  mov  0x50, %o0
a0138430:  92 10 20 18  mov  0x18, %o1
a0138434:  94 07 bf e0  add  %fp, -32, %o2
a0138438:  7f ff fb 29  call  0xa01370dc
a013843c:  96 10 20 00  clr  %o3
a0138440:  01 00 00 00  nop
a0138444:  81 c7 e0 08  ret
a0138448:  81 e8 00 00  restore
