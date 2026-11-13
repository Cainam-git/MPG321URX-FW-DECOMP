# leon2m FUN_a00b3ba0 0xa00b3ba0-0xa00b3c80 (224 bytes)
a00b3ba0:  9d e3 bf 98  save  %sp, -104, %sp
a00b3ba4:  90 10 20 92  mov  0x92, %o0
a00b3ba8:  40 02 4b ea  call  0xa0146b50
a00b3bac:  92 10 20 00  clr  %o1
a00b3bb0:  90 10 20 00  clr  %o0
a00b3bb4:  40 02 4b ee  call  0xa0146b6c
a00b3bb8:  92 10 20 00  clr  %o1
a00b3bbc:  b0 10 20 00  clr  %i0
a00b3bc0:  b2 10 20 00  clr  %i1
a00b3bc4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00b3bc8:  10 80 00 11  b  0xa00b3c0c
a00b3bcc:  21 00 06 5a  sethi  %hi(0x196800), %l0
a00b3bd0:  7f ff bf 1d  call  0xa00a3844
a00b3bd4:  90 14 23 24  or  %l0, 0x324, %o0	! 0x196b24
a00b3bd8:  82 06 40 19  add  %i1, %i1, %g1
a00b3bdc:  98 10 00 08  mov  %o0, %o4
a00b3be0:  94 00 60 06  add  %g1, 6, %o2
a00b3be4:  90 10 20 00  clr  %o0
a00b3be8:  92 10 20 14  mov  0x14, %o1
a00b3bec:  96 10 20 01  mov  1, %o3
a00b3bf0:  9a 10 20 00  clr  %o5
a00b3bf4:  7f ff bd 6c  call  0xa00a31a4
a00b3bf8:  b0 06 20 01  inc  %i0
a00b3bfc:  b2 0e 20 ff  and  %i0, 0xff, %i1
a00b3c00:  80 a6 60 04  cmp  %i1, 4
a00b3c04:  18 80 00 1a  bgu  0xa00b3c6c
a00b3c08:  d0 04 62 90  ld  [ %l1 + 0x290 ], %o0
a00b3c0c:  9a 14 62 90  or  %l1, 0x290, %o5
a00b3c10:  82 0e 20 ff  and  %i0, 0xff, %g1
a00b3c14:  90 14 23 24  or  %l0, 0x324, %o0
a00b3c18:  80 a6 60 04  cmp  %i1, 4
a00b3c1c:  12 bf ff ed  bne  0xa00b3bd0
a00b3c20:  92 10 00 19  mov  %i1, %o1
a00b3c24:  d6 0b 60 08  ldub  [ %o5 + 8 ], %o3
a00b3c28:  94 00 40 0b  add  %g1, %o3, %o2
a00b3c2c:  93 2a a0 10  sll  %o2, 0x10, %o1
a00b3c30:  7f ff bf 05  call  0xa00a3844
a00b3c34:  93 32 60 10  srl  %o1, 0x10, %o1
a00b3c38:  98 10 00 08  mov  %o0, %o4
a00b3c3c:  90 10 20 00  clr  %o0
a00b3c40:  92 10 20 14  mov  0x14, %o1
a00b3c44:  94 10 20 0e  mov  0xe, %o2
a00b3c48:  96 10 20 01  mov  1, %o3
a00b3c4c:  9a 10 20 00  clr  %o5
a00b3c50:  7f ff bd 55  call  0xa00a31a4
a00b3c54:  b0 06 20 01  inc  %i0
a00b3c58:  b2 0e 20 ff  and  %i0, 0xff, %i1
a00b3c5c:  80 a6 60 04  cmp  %i1, 4
a00b3c60:  08 bf ff ec  bleu  0xa00b3c10
a00b3c64:  9a 14 62 90  or  %l1, 0x290, %o5
a00b3c68:  d0 04 62 90  ld  [ %l1 + 0x290 ], %o0
a00b3c6c:  b3 32 20 09  srl  %o0, 9, %i1
a00b3c70:  b2 0e 60 01  and  %i1, 1, %i1
a00b3c74:  7f ff d8 af  call  0xa00a9f30
a00b3c78:  91 e8 20 04  restore  %g0, 4, %o0
a00b3c7c:  01 00 00 00  nop
