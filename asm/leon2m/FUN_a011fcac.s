# leon2m FUN_a011fcac 0xa011fcac-0xa011fd84 (216 bytes)
a011fcac:  9d e3 bf 98  save  %sp, -104, %sp
a011fcb0:  80 a6 20 02  cmp  %i0, 2
a011fcb4:  82 60 20 00  subx  %g0, 0, %g1
a011fcb8:  b4 0e 00 01  and  %i0, %g1, %i2
a011fcbc:  37 00 06 8b  sethi  %hi(0x1a2c00), %i3
a011fcc0:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011fcc4:  b8 17 20 28  or  %i4, 0x28, %i4	! 0xcf011428
a011fcc8:  ba 06 80 1a  add  %i2, %i2, %i5
a011fccc:  9e 16 e3 b0  or  %i3, 0x3b0, %o7
a011fcd0:  f6 07 00 00  ld  [ %i4 ], %i3
a011fcd4:  c2 13 c0 1d  lduh  [ %o7 + %i5 ], %g1
a011fcd8:  b4 00 60 48  add  %g1, 0x48, %i2
a011fcdc:  ba 16 e0 03  or  %i3, 3, %i5
a011fce0:  b7 2e a0 02  sll  %i2, 2, %i3
a011fce4:  35 33 c0 00  sethi  %hi(0xcf000000), %i2
a011fce8:  fa 27 00 00  st  %i5, [ %i4 ]
a011fcec:  82 16 c0 1a  or  %i3, %i2, %g1
a011fcf0:  fa 00 40 00  ld  [ %g1 ], %i5
a011fcf4:  f6 07 00 00  ld  [ %i4 ], %i3
a011fcf8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011fcfc:  82 16 e0 03  or  %i3, 3, %g1
a011fd00:  ba 0f 60 df  and  %i5, 0xdf, %i5
a011fd04:  b3 2e 60 05  sll  %i1, 5, %i1
a011fd08:  c2 27 00 00  st  %g1, [ %i4 ]
a011fd0c:  80 a6 20 02  cmp  %i0, 2
a011fd10:  02 80 00 0c  be  0xa011fd40
a011fd14:  b8 17 40 19  or  %i5, %i1, %i4
a011fd18:  80 a6 20 01  cmp  %i0, 1
a011fd1c:  18 80 00 18  bgu  0xa011fd7c
a011fd20:  ba 06 00 18  add  %i0, %i0, %i5
a011fd24:  f0 13 c0 1d  lduh  [ %o7 + %i5 ], %i0
a011fd28:  82 06 20 48  add  %i0, 0x48, %g1
a011fd2c:  b7 28 60 02  sll  %g1, 2, %i3
a011fd30:  b2 16 c0 1a  or  %i3, %i2, %i1
a011fd34:  b4 0f 20 ff  and  %i4, 0xff, %i2
a011fd38:  f4 26 40 00  st  %i2, [ %i1 ]
a011fd3c:  30 80 00 10  b,a   0xa011fd7c
a011fd40:  b6 0f 20 ff  and  %i4, 0xff, %i3
a011fd44:  b2 10 00 0f  mov  %o7, %i1
a011fd48:  b8 10 20 00  clr  %i4
a011fd4c:  ba 10 20 00  clr  %i5
a011fd50:  ba 07 40 1d  add  %i5, %i5, %i5
a011fd54:  f0 16 40 1d  lduh  [ %i1 + %i5 ], %i0
a011fd58:  82 06 20 48  add  %i0, 0x48, %g1
a011fd5c:  bb 28 60 02  sll  %g1, 2, %i5
a011fd60:  b0 17 40 1a  or  %i5, %i2, %i0
a011fd64:  b8 07 20 01  inc  %i4
a011fd68:  ba 0f 20 ff  and  %i4, 0xff, %i5
a011fd6c:  f6 26 00 00  st  %i3, [ %i0 ]
a011fd70:  80 a7 60 01  cmp  %i5, 1
a011fd74:  08 bf ff f8  bleu  0xa011fd54
a011fd78:  ba 07 40 1d  add  %i5, %i5, %i5
a011fd7c:  81 c7 e0 08  ret
a011fd80:  81 e8 00 00  restore
