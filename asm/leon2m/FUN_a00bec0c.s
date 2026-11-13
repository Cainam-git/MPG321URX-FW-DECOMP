# leon2m FUN_a00bec0c 0xa00bec0c-0xa00bed38 (300 bytes)
a00bec0c:  9d e3 bf 98  save  %sp, -104, %sp
a00bec10:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bec14:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bec18:  9a 10 20 30  mov  0x30, %o5
a00bec1c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bec20:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bec24:  da 2c 20 07  stb  %o5, [ %l0 + 7 ]
a00bec28:  40 02 16 75  call  0xa01445fc
a00bec2c:  d0 0a a2 b0  ldub  [ %o2 + 0x2b0 ], %o0
a00bec30:  92 02 20 30  add  %o0, 0x30, %o1
a00bec34:  d2 2c 20 09  stb  %o1, [ %l0 + 9 ]
a00bec38:  92 10 20 00  clr  %o1
a00bec3c:  40 02 56 80  call  0xa015463c
a00bec40:  90 10 20 36  mov  0x36, %o0
a00bec44:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bec48:  90 10 20 62  mov  0x62, %o0
a00bec4c:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bec50:  92 10 20 02  mov  2, %o1
a00bec54:  40 02 56 7a  call  0xa015463c
a00bec58:  90 10 20 36  mov  0x36, %o0
a00bec5c:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bec60:  92 10 20 03  mov  3, %o1
a00bec64:  40 02 56 76  call  0xa015463c
a00bec68:  90 10 20 36  mov  0x36, %o0
a00bec6c:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bec70:  92 10 20 04  mov  4, %o1
a00bec74:  40 02 56 72  call  0xa015463c
a00bec78:  90 10 20 36  mov  0x36, %o0
a00bec7c:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bec80:  92 10 20 05  mov  5, %o1
a00bec84:  40 02 56 6e  call  0xa015463c
a00bec88:  90 10 20 36  mov  0x36, %o0
a00bec8c:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bec90:  92 10 20 06  mov  6, %o1
a00bec94:  40 02 56 6a  call  0xa015463c
a00bec98:  90 10 20 36  mov  0x36, %o0
a00bec9c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00beca0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00beca4:  82 10 20 0d  mov  0xd, %g1
a00beca8:  9a 13 20 40  or  %o4, 0x40, %o5
a00becac:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00becb0:  80 a6 20 02  cmp  %i0, 2
a00becb4:  02 80 00 12  be  0xa00becfc
a00becb8:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00becbc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00becc0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00becc4:  96 12 a0 98  or  %o2, 0x98, %o3
a00becc8:  80 a6 20 03  cmp  %i0, 3
a00beccc:  02 80 00 10  be  0xa00bed0c
a00becd0:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00becd4:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00becd8:  c0 2b e0 9c  clrb  [ %o7 + 0x9c ]	! 0xa802b09c
a00becdc:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bece0:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bece4:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bece8:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00becec:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00becf0:  b4 16 a0 78  or  %i2, 0x78, %i2
a00becf4:  40 02 26 bd  call  0xa01487e8
a00becf8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00becfc:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bed00:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00bed04:  10 bf ff f7  b  0xa00bece0
a00bed08:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bed0c:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00bed10:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00bed14:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bed18:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bed1c:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bed20:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bed24:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bed28:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bed2c:  40 02 26 af  call  0xa01487e8
a00bed30:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bed34:  01 00 00 00  nop
