# leon2m FUN_a0091b94 0xa0091b94-0xa0091cc0 (300 bytes)
a0091b94:  9d e3 bf 98  save  %sp, -104, %sp
a0091b98:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0091b9c:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0	! 0xa802afec
a0091ba0:  82 02 3f f2  add  %o0, -14, %g1
a0091ba4:  40 00 5c d1  call  0xa00a8ee8
a0091ba8:  90 08 60 ff  and  %g1, 0xff, %o0
a0091bac:  da 06 63 ec  ld  [ %i1 + 0x3ec ], %o5
a0091bb0:  b0 03 7f f2  add  %o5, -14, %i0
a0091bb4:  90 0e 20 ff  and  %i0, 0xff, %o0
a0091bb8:  40 00 61 4c  call  0xa00aa0e8
a0091bbc:  92 10 20 00  clr  %o1
a0091bc0:  e0 06 63 ec  ld  [ %i1 + 0x3ec ], %l0
a0091bc4:  1f 09 24 92  sethi  %hi(0x24924800), %o7
a0091bc8:  96 04 3f f2  add  %l0, -14, %o3
a0091bcc:  98 13 e1 25  or  %o7, 0x125, %o4
a0091bd0:  80 52 c0 0c  umul  %o3, %o4, %g0
a0091bd4:  91 40 00 00  rd  %y, %o0
a0091bd8:  94 22 c0 08  sub  %o3, %o0, %o2
a0091bdc:  93 32 a0 01  srl  %o2, 1, %o1
a0091be0:  82 02 00 09  add  %o0, %o1, %g1
a0091be4:  1b 24 92 49  sethi  %hi(0x92492400), %o5
a0091be8:  a1 30 60 02  srl  %g1, 2, %l0
a0091bec:  b0 13 60 93  or  %o5, 0x93, %i0
a0091bf0:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0091bf4:  9e 02 3f f3  add  %o0, -13, %o7
a0091bf8:  80 5b c0 18  smul  %o7, %i0, %g0
a0091bfc:  99 40 00 00  rd  %y, %o4
a0091c00:  96 03 00 0f  add  %o4, %o7, %o3
a0091c04:  93 3a e0 02  sra  %o3, 2, %o1
a0091c08:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a0091c0c:  82 22 40 0a  sub  %o1, %o2, %g1
a0091c10:  9b 28 60 03  sll  %g1, 3, %o5
a0091c14:  98 23 40 01  sub  %o5, %g1, %o4
a0091c18:  94 23 c0 0c  sub  %o7, %o4, %o2
a0091c1c:  96 02 a0 0e  add  %o2, 0xe, %o3
a0091c20:  d6 26 63 ec  st  %o3, [ %i1 + 0x3ec ]
a0091c24:  40 00 62 3f  call  0xa00aa520
a0091c28:  90 0a a0 ff  and  %o2, 0xff, %o0
a0091c2c:  92 0a 20 ff  and  %o0, 0xff, %o1
a0091c30:  80 a2 60 01  cmp  %o1, 1
a0091c34:  12 bf ff f0  bne  0xa0091bf4
a0091c38:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0091c3c:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a0091c40:  17 09 24 92  sethi  %hi(0x24924800), %o3
a0091c44:  94 03 3f f2  add  %o4, -14, %o2
a0091c48:  9a 12 e1 25  or  %o3, 0x125, %o5
a0091c4c:  80 52 80 0d  umul  %o2, %o5, %g0
a0091c50:  9f 40 00 00  rd  %y, %o7
a0091c54:  92 22 80 0f  sub  %o2, %o7, %o1
a0091c58:  83 32 60 01  srl  %o1, 1, %g1
a0091c5c:  b0 03 c0 01  add  %o7, %g1, %i0
a0091c60:  b2 0c 20 ff  and  %l0, 0xff, %i1
a0091c64:  91 36 20 02  srl  %i0, 2, %o0
a0091c68:  80 a6 40 08  cmp  %i1, %o0
a0091c6c:  02 80 00 05  be  0xa0091c80
a0091c70:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0091c74:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091c78:  40 00 6c ed  call  0xa00ad02c
a0091c7c:  92 10 20 01  mov  1, %o1
a0091c80:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0091c84:  82 02 7f f2  add  %o1, -14, %g1
a0091c88:  90 08 60 ff  and  %g1, 0xff, %o0
a0091c8c:  40 00 5c e0  call  0xa00a900c
a0091c90:  92 10 20 01  mov  1, %o1
a0091c94:  de 06 63 ec  ld  [ %i1 + 0x3ec ], %o7
a0091c98:  b0 03 ff f2  add  %o7, -14, %i0
a0091c9c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0091ca0:  40 00 61 12  call  0xa00aa0e8
a0091ca4:  92 10 20 01  mov  1, %o1
a0091ca8:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a0091cac:  a0 02 3f f2  add  %o0, -14, %l0
a0091cb0:  b2 0c 20 ff  and  %l0, 0xff, %i1
a0091cb4:  40 00 75 e6  call  0xa00af44c
a0091cb8:  91 e8 20 0e  restore  %g0, 0xe, %o0
a0091cbc:  01 00 00 00  nop
