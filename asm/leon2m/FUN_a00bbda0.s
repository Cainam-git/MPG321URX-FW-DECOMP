# leon2m FUN_a00bbda0 0xa00bbda0-0xa00bbf1c (380 bytes)
a00bbda0:  9d e3 bf 98  save  %sp, -104, %sp
a00bbda4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bbda8:  d4 0b 62 99  ldub  [ %o5 + 0x299 ], %o2	! 0xa802d299
a00bbdac:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a00bbdb0:  b2 0a a0 ff  and  %o2, 0xff, %i1
a00bbdb4:  82 12 21 1f  or  %o0, 0x11f, %g1
a00bbdb8:  80 56 40 01  umul  %i1, %g1, %g0
a00bbdbc:  97 40 00 00  rd  %y, %o3
a00bbdc0:  b3 32 e0 05  srl  %o3, 5, %i1
a00bbdc4:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00bbdc8:  a0 5e a0 64  smul  %i2, 0x64, %l0
a00bbdcc:  b4 22 80 10  sub  %o2, %l0, %i2
a00bbdd0:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00bbdd4:  92 0e a0 ff  and  %i2, 0xff, %o1
a00bbdd8:  9e 13 20 cd  or  %o4, 0xcd, %o7
a00bbddc:  80 52 40 0f  umul  %o1, %o7, %g0
a00bbde0:  9b 40 00 00  rd  %y, %o5
a00bbde4:  9f 33 60 03  srl  %o5, 3, %o7
a00bbde8:  90 0b e0 ff  and  %o7, 0xff, %o0
a00bbdec:  83 2a 20 02  sll  %o0, 2, %g1
a00bbdf0:  a0 00 40 08  add  %g1, %o0, %l0
a00bbdf4:  98 04 00 10  add  %l0, %l0, %o4
a00bbdf8:  92 26 80 0c  sub  %i2, %o4, %o1
a00bbdfc:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bbe00:  a0 16 a0 78  or  %i2, 0x78, %l0	! 0xa802d078
a00bbe04:  9a 03 e0 30  add  %o7, 0x30, %o5
a00bbe08:  94 02 60 30  add  %o1, 0x30, %o2
a00bbe0c:  96 06 60 30  add  %i1, 0x30, %o3
a00bbe10:  da 2c 20 08  stb  %o5, [ %l0 + 8 ]
a00bbe14:  d6 2c 20 07  stb  %o3, [ %l0 + 7 ]
a00bbe18:  d4 2c 20 09  stb  %o2, [ %l0 + 9 ]
a00bbe1c:  92 10 20 00  clr  %o1
a00bbe20:  40 02 62 07  call  0xa015463c
a00bbe24:  90 10 20 03  mov  3, %o0
a00bbe28:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bbe2c:  90 10 20 62  mov  0x62, %o0
a00bbe30:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00bbe34:  92 10 20 02  mov  2, %o1
a00bbe38:  40 02 62 01  call  0xa015463c
a00bbe3c:  90 10 20 03  mov  3, %o0
a00bbe40:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bbe44:  92 10 20 03  mov  3, %o1
a00bbe48:  40 02 61 fd  call  0xa015463c
a00bbe4c:  90 10 20 03  mov  3, %o0
a00bbe50:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bbe54:  92 10 20 04  mov  4, %o1
a00bbe58:  40 02 61 f9  call  0xa015463c
a00bbe5c:  90 10 20 03  mov  3, %o0
a00bbe60:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bbe64:  92 10 20 05  mov  5, %o1
a00bbe68:  40 02 61 f5  call  0xa015463c
a00bbe6c:  90 10 20 03  mov  3, %o0
a00bbe70:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bbe74:  92 10 20 06  mov  6, %o1
a00bbe78:  40 02 61 f1  call  0xa015463c
a00bbe7c:  90 10 20 03  mov  3, %o0
a00bbe80:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bbe84:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bbe88:  82 10 20 0d  mov  0xd, %g1
a00bbe8c:  9a 13 20 40  or  %o4, 0x40, %o5
a00bbe90:  c2 2c 20 0a  stb  %g1, [ %l0 + 0xa ]
a00bbe94:  80 a6 20 02  cmp  %i0, 2
a00bbe98:  02 80 00 12  be  0xa00bbee0
a00bbe9c:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bbea0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bbea4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bbea8:  96 12 a0 98  or  %o2, 0x98, %o3
a00bbeac:  80 a6 20 03  cmp  %i0, 3
a00bbeb0:  02 80 00 10  be  0xa00bbef0
a00bbeb4:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00bbeb8:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00bbebc:  c0 2a a0 9c  clrb  [ %o2 + 0x9c ]	! 0xa802b09c
a00bbec0:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00bbec4:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bbec8:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bbecc:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bbed0:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bbed4:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bbed8:  40 02 32 44  call  0xa01487e8
a00bbedc:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bbee0:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00bbee4:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]	! 0xa802b09a
a00bbee8:  10 bf ff f7  b  0xa00bbec4
a00bbeec:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00bbef0:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bbef4:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]	! 0xa802b098
a00bbef8:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00bbefc:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00bbf00:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00bbf04:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00bbf08:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00bbf0c:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bbf10:  40 02 32 36  call  0xa01487e8
a00bbf14:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bbf18:  01 00 00 00  nop
