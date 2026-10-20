# leon2m FUN_a0092bb4 0xa0092bb4-0xa0092c58 (164 bytes)
a0092bb4:  9d e3 bf 98  save  %sp, -104, %sp
a0092bb8:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0092bbc:  d8 04 23 ec  ld  [ %l0 + 0x3ec ], %o4	! 0xa802afec
a0092bc0:  96 03 3f d6  add  %o4, -42, %o3
a0092bc4:  40 00 58 c9  call  0xa00a8ee8
a0092bc8:  90 0a e0 ff  and  %o3, 0xff, %o0
a0092bcc:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2
a0092bd0:  92 02 bf d6  add  %o2, -42, %o1
a0092bd4:  90 0a 60 ff  and  %o1, 0xff, %o0
a0092bd8:  40 00 5d d9  call  0xa00aa33c
a0092bdc:  92 10 20 00  clr  %o1
a0092be0:  d0 04 23 ec  ld  [ %l0 + 0x3ec ], %o0
a0092be4:  82 02 3f d6  add  %o0, -42, %g1
a0092be8:  b0 10 20 07  mov  7, %i0
a0092bec:  b2 10 20 01  mov  1, %i1
a0092bf0:  80 a0 60 06  cmp  %g1, 6
a0092bf4:  18 80 00 0c  bgu  0xa0092c24
a0092bf8:  90 10 20 07  mov  7, %o0
a0092bfc:  90 10 20 2a  mov  0x2a, %o0
a0092c00:  40 00 72 13  call  0xa00af44c
a0092c04:  92 10 20 00  clr  %o1
a0092c08:  90 10 20 00  clr  %o0
a0092c0c:  40 00 59 00  call  0xa00a900c
a0092c10:  92 10 20 00  clr  %o1
a0092c14:  9a 10 20 09  mov  9, %o5
a0092c18:  da 24 23 ec  st  %o5, [ %l0 + 0x3ec ]
a0092c1c:  40 00 85 4a  call  0xa00b4144
a0092c20:  81 e8 00 00  restore
a0092c24:  40 00 75 04  call  0xa00b0034
a0092c28:  01 00 00 00  nop
a0092c2c:  90 10 20 2a  mov  0x2a, %o0	! 0x2a
a0092c30:  40 00 72 07  call  0xa00af44c
a0092c34:  92 10 20 00  clr  %o1
a0092c38:  90 10 20 00  clr  %o0
a0092c3c:  40 00 58 f4  call  0xa00a900c
a0092c40:  92 10 20 00  clr  %o1
a0092c44:  9a 10 20 09  mov  9, %o5
a0092c48:  da 24 23 ec  st  %o5, [ %l0 + 0x3ec ]
a0092c4c:  40 00 85 3e  call  0xa00b4144
a0092c50:  81 e8 00 00  restore
a0092c54:  01 00 00 00  nop
