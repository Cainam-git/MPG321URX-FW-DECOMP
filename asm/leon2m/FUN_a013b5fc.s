# leon2m FUN_a013b5fc 0xa013b5fc-0xa013b658 (92 bytes)
a013b5fc:  9d e3 bf 80  save  %sp, -128, %sp
a013b600:  1f 2a 00 a9  sethi  %hi(0xa802a400), %o7
a013b604:  13 2a 00 b2  sethi  %hi(0xa802c800), %o1
a013b608:  9a 13 e0 68  or  %o7, 0x68, %o5
a013b60c:  d0 0a 63 bc  ldub  [ %o1 + 0x3bc ], %o0
a013b610:  e0 0b 60 01  ldub  [ %o5 + 1 ], %l0
a013b614:  c2 0b 60 02  ldub  [ %o5 + 2 ], %g1
a013b618:  93 32 20 01  srl  %o0, 1, %o1
a013b61c:  98 0e 20 ff  and  %i0, 0xff, %o4
a013b620:  f0 2b e0 68  stb  %i0, [ %o7 + 0x68 ]
a013b624:  c2 2b 60 02  stb  %g1, [ %o5 + 2 ]
a013b628:  d8 37 bf e6  sth  %o4, [ %fp + -26 ]
a013b62c:  e0 37 bf ee  sth  %l0, [ %fp + -18 ]
a013b630:  c2 37 bf f6  sth  %g1, [ %fp + -10 ]
a013b634:  e0 2b 60 01  stb  %l0, [ %o5 + 1 ]
a013b638:  90 0a 20 01  and  %o0, 1, %o0
a013b63c:  92 0a 60 01  and  %o1, 1, %o1
a013b640:  94 07 bf e0  add  %fp, -32, %o2
a013b644:  7f fe ee 68  call  0xa00f6fe4
a013b648:  96 10 20 70  mov  0x70, %o3
a013b64c:  01 00 00 00  nop
a013b650:  81 c7 e0 08  ret
a013b654:  81 e8 00 00  restore
