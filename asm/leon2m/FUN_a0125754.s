# leon2m FUN_a0125754 0xa0125754-0xa01257f0 (156 bytes)
a0125754:  9d e3 bf 80  save  %sp, -128, %sp
a0125758:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a012575c:  da 07 a0 5c  ld  [ %fp + 0x5c ], %o5
a0125760:  a0 10 60 30  or  %g1, 0x30, %l0
a0125764:  99 2b 60 10  sll  %o5, 0x10, %o4
a0125768:  b8 0f 20 ff  and  %i4, 0xff, %i4
a012576c:  82 10 00 18  mov  %i0, %g1
a0125770:  95 2e a0 10  sll  %i2, 0x10, %o2
a0125774:  90 07 bf e8  add  %fp, -24, %o0
a0125778:  92 10 00 19  mov  %i1, %o1
a012577c:  95 32 a0 10  srl  %o2, 0x10, %o2
a0125780:  96 10 00 1d  mov  %i5, %o3
a0125784:  80 a7 20 00  cmp  %i4, 0
a0125788:  99 33 20 10  srl  %o4, 0x10, %o4
a012578c:  da 0f a0 63  ldub  [ %fp + 0x63 ], %o5
a0125790:  12 80 00 14  bne  0xa01257e0
a0125794:  b0 10 20 00  clr  %i0
a0125798:  b4 10 20 01  mov  1, %i2
a012579c:  c2 2c 20 06  stb  %g1, [ %l0 + 6 ]
a01257a0:  f4 2c 20 07  stb  %i2, [ %l0 + 7 ]
a01257a4:  f6 34 20 04  sth  %i3, [ %l0 + 4 ]
a01257a8:  f0 14 20 02  lduh  [ %l0 + 2 ], %i0
a01257ac:  f2 14 00 1c  lduh  [ %l0 + %i4 ], %i1
a01257b0:  e2 14 20 08  lduh  [ %l0 + 8 ], %l1
a01257b4:  e0 14 20 06  lduh  [ %l0 + 6 ], %l0
a01257b8:  9e 10 20 01  mov  1, %o7
a01257bc:  f0 37 bf ea  sth  %i0, [ %fp + -22 ]
a01257c0:  f2 37 bf e8  sth  %i1, [ %fp + -24 ]
a01257c4:  f6 37 bf ec  sth  %i3, [ %fp + -20 ]
a01257c8:  e0 37 bf ee  sth  %l0, [ %fp + -18 ]
a01257cc:  e2 37 bf f0  sth  %l1, [ %fp + -16 ]
a01257d0:  de 23 a0 5c  st  %o7, [ %sp + 0x5c ]
a01257d4:  67 fd 96 21  call  0x4008b058
a01257d8:  01 00 00 00  nop
a01257dc:  b0 10 00 08  mov  %o0, %i0
a01257e0:  91 2e 20 10  sll  %i0, 0x10, %o0
a01257e4:  b1 32 20 10  srl  %o0, 0x10, %i0
a01257e8:  81 c7 e0 08  ret
a01257ec:  81 e8 00 00  restore
