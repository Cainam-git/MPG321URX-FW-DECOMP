# leon2m FUN_a013797c 0xa013797c-0xa0137a68 (236 bytes)
a013797c:  9d e3 bf 88  save  %sp, -120, %sp
a0137980:  d4 0e 60 0b  ldub  [ %i1 + 0xb ], %o2
a0137984:  97 2a a0 02  sll  %o2, 2, %o3
a0137988:  da 0e 60 09  ldub  [ %i1 + 9 ], %o5
a013798c:  d2 0e 60 0c  ldub  [ %i1 + 0xc ], %o1
a0137990:  98 12 c0 0d  or  %o3, %o5, %o4
a0137994:  83 2a 60 03  sll  %o1, 3, %g1
a0137998:  96 13 00 01  or  %o4, %g1, %o3
a013799c:  de 0e 60 04  ldub  [ %i1 + 4 ], %o7
a01379a0:  92 03 c0 0f  add  %o7, %o7, %o1
a01379a4:  d0 0e 60 0d  ldub  [ %i1 + 0xd ], %o0
a01379a8:  d8 0e 60 05  ldub  [ %i1 + 5 ], %o4
a01379ac:  9b 2a 20 04  sll  %o0, 4, %o5
a01379b0:  83 2b 20 02  sll  %o4, 2, %g1
a01379b4:  d4 0e 60 03  ldub  [ %i1 + 3 ], %o2
a01379b8:  de 0e 60 0e  ldub  [ %i1 + 0xe ], %o7
a01379bc:  90 12 40 0a  or  %o1, %o2, %o0
a01379c0:  99 2b e0 05  sll  %o7, 5, %o4
a01379c4:  96 12 c0 0d  or  %o3, %o5, %o3
a01379c8:  92 12 00 01  or  %o0, %g1, %o1
a01379cc:  de 0e 60 06  ldub  [ %i1 + 6 ], %o7
a01379d0:  d4 0e 60 0f  ldub  [ %i1 + 0xf ], %o2
a01379d4:  82 12 c0 0c  or  %o3, %o4, %g1
a01379d8:  9b 2b e0 03  sll  %o7, 3, %o5
a01379dc:  91 2a a0 06  sll  %o2, 6, %o0
a01379e0:  96 10 40 08  or  %g1, %o0, %o3
a01379e4:  d8 0e 60 07  ldub  [ %i1 + 7 ], %o4
a01379e8:  de 0e 60 10  ldub  [ %i1 + 0x10 ], %o7
a01379ec:  95 2b 20 04  sll  %o4, 4, %o2
a01379f0:  91 2b e0 07  sll  %o7, 7, %o0
a01379f4:  92 12 40 0d  or  %o1, %o5, %o1
a01379f8:  92 12 40 0a  or  %o1, %o2, %o1
a01379fc:  96 12 c0 08  or  %o3, %o0, %o3
a0137a00:  de 16 60 12  lduh  [ %i1 + 0x12 ], %o7
a0137a04:  98 10 20 00  clr  %o4
a0137a08:  9a 10 20 00  clr  %o5
a0137a0c:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0137a10:  95 33 e0 08  srl  %o7, 8, %o2
a0137a14:  d0 0e 60 02  ldub  [ %i1 + 2 ], %o0
a0137a18:  c2 0e 40 00  ldub  [ %i1 ], %g1
a0137a1c:  da 0e 60 01  ldub  [ %i1 + 1 ], %o5
a0137a20:  d8 0e 60 08  ldub  [ %i1 + 8 ], %o4
a0137a24:  d2 2f bf eb  stb  %o1, [ %fp + -21 ]
a0137a28:  d6 2f bf ed  stb  %o3, [ %fp + -19 ]
a0137a2c:  d4 2f bf ef  stb  %o2, [ %fp + -17 ]
a0137a30:  d0 2f bf f0  stb  %o0, [ %fp + -16 ]
a0137a34:  f0 2f bf e8  stb  %i0, [ %fp + -24 ]
a0137a38:  c2 2f bf e9  stb  %g1, [ %fp + -23 ]
a0137a3c:  da 2f bf ea  stb  %o5, [ %fp + -22 ]
a0137a40:  d8 2f bf ec  stb  %o4, [ %fp + -20 ]
a0137a44:  de 2f bf ee  stb  %o7, [ %fp + -18 ]
a0137a48:  90 10 20 20  mov  0x20, %o0
a0137a4c:  92 10 20 09  mov  9, %o1
a0137a50:  94 07 bf e8  add  %fp, -24, %o2
a0137a54:  7f ff fd a2  call  0xa01370dc
a0137a58:  96 10 20 01  mov  1, %o3
a0137a5c:  01 00 00 00  nop
a0137a60:  81 c7 e0 08  ret
a0137a64:  81 e8 00 00  restore
