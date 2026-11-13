# leon2m FUN_a01256d0 0xa01256d0-0xa0125754 (132 bytes)
a01256d0:  9d e3 bf 88  save  %sp, -120, %sp
a01256d4:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a01256d8:  98 10 60 30  or  %g1, 0x30, %o4	! 0xa802a430
a01256dc:  da 07 a0 5c  ld  [ %fp + 0x5c ], %o5
a01256e0:  b8 0f 20 ff  and  %i4, 0xff, %i4
a01256e4:  82 10 00 18  mov  %i0, %g1
a01256e8:  93 2e a0 10  sll  %i2, 0x10, %o1
a01256ec:  95 2b 60 10  sll  %o5, 0x10, %o2
a01256f0:  90 07 bf e8  add  %fp, -24, %o0
a01256f4:  93 32 60 10  srl  %o1, 0x10, %o1
a01256f8:  96 10 00 1d  mov  %i5, %o3
a01256fc:  80 a7 20 00  cmp  %i4, 0
a0125700:  95 32 a0 10  srl  %o2, 0x10, %o2
a0125704:  12 80 00 10  bne  0xa0125744
a0125708:  b0 10 20 00  clr  %i0
a012570c:  c2 2b 20 06  stb  %g1, [ %o4 + 6 ]
a0125710:  f2 2b 20 07  stb  %i1, [ %o4 + 7 ]
a0125714:  f6 33 20 04  sth  %i3, [ %o4 + 4 ]
a0125718:  f0 13 00 1c  lduh  [ %o4 + %i4 ], %i0
a012571c:  e0 13 20 08  lduh  [ %o4 + 8 ], %l0
a0125720:  de 13 20 02  lduh  [ %o4 + 2 ], %o7
a0125724:  d8 13 20 06  lduh  [ %o4 + 6 ], %o4
a0125728:  f0 37 bf e8  sth  %i0, [ %fp + -24 ]
a012572c:  de 37 bf ea  sth  %o7, [ %fp + -22 ]
a0125730:  f6 37 bf ec  sth  %i3, [ %fp + -20 ]
a0125734:  d8 37 bf ee  sth  %o4, [ %fp + -18 ]
a0125738:  67 fd 98 fc  call  0x4008bb28
a012573c:  e0 37 bf f0  sth  %l0, [ %fp + -16 ]
a0125740:  b0 10 00 08  mov  %o0, %i0
a0125744:  91 2e 20 10  sll  %i0, 0x10, %o0
a0125748:  b1 32 20 10  srl  %o0, 0x10, %i0
a012574c:  81 c7 e0 08  ret
a0125750:  81 e8 00 00  restore
