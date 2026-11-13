# leon2m FUN_a0125644 0xa0125644-0xa01256d0 (140 bytes)
a0125644:  9d e3 bf 88  save  %sp, -120, %sp
a0125648:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a012564c:  d8 07 a0 5c  ld  [ %fp + 0x5c ], %o4
a0125650:  a0 10 60 30  or  %g1, 0x30, %l0
a0125654:  95 2b 20 10  sll  %o4, 0x10, %o2
a0125658:  b8 0f 20 ff  and  %i4, 0xff, %i4
a012565c:  82 10 00 18  mov  %i0, %g1
a0125660:  93 2e a0 10  sll  %i2, 0x10, %o1
a0125664:  90 07 bf e8  add  %fp, -24, %o0
a0125668:  9a 10 20 01  mov  1, %o5
a012566c:  93 32 60 10  srl  %o1, 0x10, %o1
a0125670:  96 10 00 1d  mov  %i5, %o3
a0125674:  80 a7 20 00  cmp  %i4, 0
a0125678:  95 32 a0 10  srl  %o2, 0x10, %o2
a012567c:  d8 0f a0 63  ldub  [ %fp + 0x63 ], %o4
a0125680:  12 80 00 10  bne  0xa01256c0
a0125684:  b0 10 20 00  clr  %i0
a0125688:  c2 2c 20 06  stb  %g1, [ %l0 + 6 ]
a012568c:  f2 2c 20 07  stb  %i1, [ %l0 + 7 ]
a0125690:  f6 34 20 04  sth  %i3, [ %l0 + 4 ]
a0125694:  f0 14 20 02  lduh  [ %l0 + 2 ], %i0
a0125698:  de 14 00 1c  lduh  [ %l0 + %i4 ], %o7
a012569c:  e2 14 20 08  lduh  [ %l0 + 8 ], %l1
a01256a0:  e0 14 20 06  lduh  [ %l0 + 6 ], %l0
a01256a4:  f0 37 bf ea  sth  %i0, [ %fp + -22 ]
a01256a8:  de 37 bf e8  sth  %o7, [ %fp + -24 ]
a01256ac:  f6 37 bf ec  sth  %i3, [ %fp + -20 ]
a01256b0:  e0 37 bf ee  sth  %l0, [ %fp + -18 ]
a01256b4:  67 fd 97 4c  call  0x4008b3e4
a01256b8:  e2 37 bf f0  sth  %l1, [ %fp + -16 ]
a01256bc:  b0 10 00 08  mov  %o0, %i0
a01256c0:  91 2e 20 10  sll  %i0, 0x10, %o0
a01256c4:  b1 32 20 10  srl  %o0, 0x10, %i0
a01256c8:  81 c7 e0 08  ret
a01256cc:  81 e8 00 00  restore
