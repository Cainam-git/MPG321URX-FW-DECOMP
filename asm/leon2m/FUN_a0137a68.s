# leon2m FUN_a0137a68 0xa0137a68-0xa0137aec (132 bytes)
a0137a68:  9d e3 bf 88  save  %sp, -120, %sp
a0137a6c:  de 0e 60 04  ldub  [ %i1 + 4 ], %o7
a0137a70:  92 03 c0 0f  add  %o7, %o7, %o1
a0137a74:  d4 0e 60 03  ldub  [ %i1 + 3 ], %o2
a0137a78:  d0 0e 60 05  ldub  [ %i1 + 5 ], %o0
a0137a7c:  96 12 40 0a  or  %o1, %o2, %o3
a0137a80:  83 2a 20 02  sll  %o0, 2, %g1
a0137a84:  da 0e 60 06  ldub  [ %i1 + 6 ], %o5
a0137a88:  9e 12 c0 01  or  %o3, %g1, %o7
a0137a8c:  99 2b 60 03  sll  %o5, 3, %o4
a0137a90:  90 13 c0 0c  or  %o7, %o4, %o0
a0137a94:  d4 0e 60 07  ldub  [ %i1 + 7 ], %o2
a0137a98:  93 2a a0 04  sll  %o2, 4, %o1
a0137a9c:  98 10 20 00  clr  %o4
a0137aa0:  9a 10 20 00  clr  %o5
a0137aa4:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0137aa8:  96 12 00 09  or  %o0, %o1, %o3
a0137aac:  d8 0e 60 02  ldub  [ %i1 + 2 ], %o4
a0137ab0:  c2 0e 40 00  ldub  [ %i1 ], %g1
a0137ab4:  da 0e 60 01  ldub  [ %i1 + 1 ], %o5
a0137ab8:  d6 2f bf eb  stb  %o3, [ %fp + -21 ]
a0137abc:  f0 2f bf e8  stb  %i0, [ %fp + -24 ]
a0137ac0:  c2 2f bf e9  stb  %g1, [ %fp + -23 ]
a0137ac4:  da 2f bf ea  stb  %o5, [ %fp + -22 ]
a0137ac8:  d8 2f bf f0  stb  %o4, [ %fp + -16 ]
a0137acc:  90 10 20 21  mov  0x21, %o0
a0137ad0:  92 10 20 09  mov  9, %o1
a0137ad4:  94 07 bf e8  add  %fp, -24, %o2
a0137ad8:  7f ff fd 81  call  0xa01370dc
a0137adc:  96 10 20 01  mov  1, %o3
a0137ae0:  01 00 00 00  nop
a0137ae4:  81 c7 e0 08  ret
a0137ae8:  81 e8 00 00  restore
