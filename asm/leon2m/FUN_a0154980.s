# leon2m FUN_a0154980 0xa0154980-0xa0154ae8 (360 bytes)
a0154980:  9d e3 bf 70  save  %sp, -144, %sp
a0154984:  90 10 00 18  mov  %i0, %o0
a0154988:  40 00 00 58  call  0xa0154ae8
a015498c:  92 10 00 19  mov  %i1, %o1
a0154990:  27 00 06 a0  sethi  %hi(0x1a8000), %l3
a0154994:  e4 04 e2 98  ld  [ %l3 + 0x298 ], %l2	! 0x1a8298
a0154998:  a0 10 00 08  mov  %o0, %l0
a015499c:  80 a4 bf ff  cmp  %l2, -1
a01549a0:  02 80 00 08  be  0xa01549c0
a01549a4:  a2 10 00 09  mov  %o1, %l1
a01549a8:  90 10 00 18  mov  %i0, %o0
a01549ac:  40 00 01 b2  call  0xa0155074
a01549b0:  92 10 00 19  mov  %i1, %o1
a01549b4:  80 a2 20 00  cmp  %o0, 0
a01549b8:  02 80 00 05  be  0xa01549cc
a01549bc:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a01549c0:  90 10 00 10  mov  %l0, %o0
a01549c4:  10 80 00 46  b  0xa0154adc
a01549c8:  92 10 00 11  mov  %l1, %o1
a01549cc:  90 10 00 18  mov  %i0, %o0
a01549d0:  92 10 00 19  mov  %i1, %o1
a01549d4:  40 00 07 69  call  0xa0156778
a01549d8:  d4 18 62 08  ldd  [ %g1 + 0x208 ], %o2
a01549dc:  80 a2 20 00  cmp  %o0, 0
a01549e0:  14 bf ff f9  bg  0xa01549c4
a01549e4:  90 10 00 10  mov  %l0, %o0
a01549e8:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a01549ec:  82 10 62 10  or  %g1, 0x210, %g1	! 0x1a8210
a01549f0:  c2 27 bf d4  st  %g1, [ %fp + -44 ]
a01549f4:  80 a4 a0 00  cmp  %l2, 0
a01549f8:  c0 27 bf f0  clr  [ %fp + -16 ]
a01549fc:  f0 3f bf d8  std  %i0, [ %fp + -40 ]
a0154a00:  02 80 00 20  be  0xa0154a80
a0154a04:  f0 3f bf e0  std  %i0, [ %fp + -32 ]
a0154a08:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154a0c:  d8 18 62 90  ldd  [ %g1 + 0x290 ], %o4	! 0x1a8290
a0154a10:  15 20 00 00  sethi  %hi(0x80000000), %o2
a0154a14:  96 10 20 00  clr  %o3
a0154a18:  98 1a 80 0c  xor  %o2, %o4, %o4
a0154a1c:  9a 1a c0 0d  xor  %o3, %o5, %o5
a0154a20:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154a24:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0154a28:  90 10 00 18  mov  %i0, %o0
a0154a2c:  92 10 00 19  mov  %i1, %o1
a0154a30:  40 00 07 20  call  0xa01566b0
a0154a34:  d4 18 62 08  ldd  [ %g1 + 0x208 ], %o2
a0154a38:  80 a2 20 00  cmp  %o0, 0
a0154a3c:  12 80 00 1a  bne  0xa0154aa4
a0154a40:  da 04 e2 98  ld  [ %l3 + 0x298 ], %o5
a0154a44:  82 10 20 02  mov  2, %g1
a0154a48:  80 a3 60 02  cmp  %o5, 2
a0154a4c:  02 80 00 1f  be  0xa0154ac8
a0154a50:  c2 27 bf d0  st  %g1, [ %fp + -48 ]
a0154a54:  40 00 01 93  call  0xa01550a0
a0154a58:  90 07 bf d0  add  %fp, -48, %o0
a0154a5c:  80 a2 20 00  cmp  %o0, 0
a0154a60:  02 80 00 15  be  0xa0154ab4
a0154a64:  01 00 00 00  nop
a0154a68:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a0154a6c:  80 a0 60 00  cmp  %g1, 0
a0154a70:  12 80 00 07  bne  0xa0154a8c
a0154a74:  01 00 00 00  nop
a0154a78:  10 80 00 19  b  0xa0154adc
a0154a7c:  d0 1f bf e8  ldd  [ %fp + -24 ], %o0
a0154a80:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0154a84:  10 bf ff e7  b  0xa0154a20
a0154a88:  d8 18 62 18  ldd  [ %g1 + 0x218 ], %o4	! 0x1a8218
a0154a8c:  40 00 0b 14  call  0xa01576dc
a0154a90:  01 00 00 00  nop
a0154a94:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a0154a98:  c2 22 00 00  st  %g1, [ %o0 ]
a0154a9c:  10 80 00 10  b  0xa0154adc
a0154aa0:  d0 1f bf e8  ldd  [ %fp + -24 ], %o0
a0154aa4:  82 10 20 01  mov  1, %g1
a0154aa8:  80 a3 60 02  cmp  %o5, 2
a0154aac:  12 bf ff ea  bne  0xa0154a54
a0154ab0:  c2 27 bf d0  st  %g1, [ %fp + -48 ]
a0154ab4:  40 00 0b 0a  call  0xa01576dc
a0154ab8:  01 00 00 00  nop
a0154abc:  82 10 20 21  mov  0x21, %g1	! 0x21
a0154ac0:  10 bf ff ea  b  0xa0154a68
a0154ac4:  c2 22 00 00  st  %g1, [ %o0 ]
a0154ac8:  40 00 0b 05  call  0xa01576dc
a0154acc:  01 00 00 00  nop
a0154ad0:  82 10 20 22  mov  0x22, %g1	! 0x22
a0154ad4:  10 bf ff e5  b  0xa0154a68
a0154ad8:  c2 22 00 00  st  %g1, [ %o0 ]
a0154adc:  b0 10 00 08  mov  %o0, %i0
a0154ae0:  81 c7 e0 08  ret
a0154ae4:  93 e8 00 09  restore  %g0, %o1, %o1
