# leon2m FUN_a0091f58 0xa0091f58-0xa0092044 (236 bytes)
a0091f58:  9d e3 bf 98  save  %sp, -104, %sp
a0091f5c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0091f60:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a0091f64:  90 00 7f fe  add  %g1, -2, %o0
a0091f68:  90 0a 20 ff  and  %o0, 0xff, %o0
a0091f6c:  40 00 88 76  call  0xa00b4144
a0091f70:  92 10 20 02  mov  2, %o1
a0091f74:  40 01 17 75  call  0xa00d7d48
a0091f78:  01 00 00 00  nop
a0091f7c:  80 a2 20 00  cmp  %o0, 0
a0091f80:  12 80 00 0c  bne  0xa0091fb0
a0091f84:  82 10 20 1a  mov  0x1a, %g1
a0091f88:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a0091f8c:  82 12 62 90  or  %o1, 0x290, %g1	! 0xa802d290
a0091f90:  da 00 61 1c  ld  [ %g1 + 0x11c ], %o5
a0091f94:  80 a3 60 00  cmp  %o5, 0
a0091f98:  26 80 00 06  bl,a   0xa0091fb0
a0091f9c:  82 10 20 19  mov  0x19, %g1
a0091fa0:  d4 00 60 b0  ld  [ %g1 + 0xb0 ], %o2
a0091fa4:  80 a2 a0 00  cmp  %o2, 0
a0091fa8:  12 80 00 20  bne  0xa0092028
a0091fac:  82 10 20 18  mov  0x18, %g1
a0091fb0:  17 0a aa aa  sethi  %hi(0x2aaaa800), %o3
a0091fb4:  c2 26 63 ec  st  %g1, [ %i1 + 0x3ec ]
a0091fb8:  10 80 00 0d  b  0xa0091fec
a0091fbc:  b0 12 e2 ab  or  %o3, 0x2ab, %i0
a0091fc0:  92 03 7f e9  add  %o5, -23, %o1
a0091fc4:  83 3a 60 1f  sra  %o1, 0x1f, %g1
a0091fc8:  80 5a 40 18  smul  %o1, %i0, %g0
a0091fcc:  91 40 00 00  rd  %y, %o0
a0091fd0:  98 22 00 01  sub  %o0, %g1, %o4
a0091fd4:  9e 03 00 0c  add  %o4, %o4, %o7
a0091fd8:  96 03 c0 0c  add  %o7, %o4, %o3
a0091fdc:  94 02 c0 0b  add  %o3, %o3, %o2
a0091fe0:  9a 22 40 0a  sub  %o1, %o2, %o5
a0091fe4:  82 03 60 18  add  %o5, 0x18, %g1
a0091fe8:  c2 26 63 ec  st  %g1, [ %i1 + 0x3ec ]
a0091fec:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a0091ff0:  9e 02 3f e8  add  %o0, -24, %o7
a0091ff4:  90 0b e0 ff  and  %o7, 0xff, %o0
a0091ff8:  40 00 61 4a  call  0xa00aa520
a0091ffc:  01 00 00 00  nop
a0092000:  98 0a 20 ff  and  %o0, 0xff, %o4
a0092004:  80 a3 20 01  cmp  %o4, 1
a0092008:  12 bf ff ee  bne  0xa0091fc0
a009200c:  da 16 63 ee  lduh  [ %i1 + 0x3ee ], %o5
a0092010:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a0092014:  f2 02 63 ec  ld  [ %o1 + 0x3ec ], %i1	! 0xa802afec
a0092018:  b0 06 7f e8  add  %i1, -24, %i0
a009201c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0092020:  40 00 5b fb  call  0xa00a900c
a0092024:  93 e8 20 01  restore  %g0, 1, %o1
a0092028:  40 01 1a ec  call  0xa00d8bd8
a009202c:  01 00 00 00  nop
a0092030:  80 8a 20 ff  btst  0xff, %o0
a0092034:  22 bf ff df  be,a   0xa0091fb0
a0092038:  82 10 20 18  mov  0x18, %g1
a009203c:  10 bf ff dd  b  0xa0091fb0
a0092040:  82 10 20 19  mov  0x19, %g1
