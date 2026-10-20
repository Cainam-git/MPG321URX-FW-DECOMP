# leon2m FUN_a009ab58 0xa009ab58-0xa009ac7c (292 bytes)
a009ab58:  9d e3 bf 98  save  %sp, -104, %sp
a009ab5c:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009ab60:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009ab64:  90 02 7f aa  add  %o1, -86, %o0
a009ab68:  40 00 3a 15  call  0xa00a93bc
a009ab6c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009ab70:  03 0a aa aa  sethi  %hi(0x2aaaa800), %g1
a009ab74:  b2 10 62 ab  or  %g1, 0x2ab, %i1	! 0x2aaaaaab
a009ab78:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009ab7c:  9e 02 3f ab  add  %o0, -85, %o7
a009ab80:  80 5b c0 19  smul  %o7, %i1, %g0
a009ab84:  95 40 00 00  rd  %y, %o2
a009ab88:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a009ab8c:  92 22 80 0b  sub  %o2, %o3, %o1
a009ab90:  82 02 40 09  add  %o1, %o1, %g1
a009ab94:  b0 00 40 09  add  %g1, %o1, %i0
a009ab98:  98 06 00 18  add  %i0, %i0, %o4
a009ab9c:  96 23 c0 0c  sub  %o7, %o4, %o3
a009aba0:  9a 02 e0 56  add  %o3, 0x56, %o5
a009aba4:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009aba8:  40 00 40 62  call  0xa00aad30
a009abac:  90 0a e0 ff  and  %o3, 0xff, %o0
a009abb0:  94 0a 20 ff  and  %o0, 0xff, %o2
a009abb4:  80 a2 a0 01  cmp  %o2, 1
a009abb8:  12 bf ff f1  bne  0xa009ab7c
a009abbc:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009abc0:  da 06 a3 ec  ld  [ %i2 + 0x3ec ], %o5
a009abc4:  80 a3 60 56  cmp  %o5, 0x56
a009abc8:  08 80 00 17  bleu  0xa009ac24
a009abcc:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009abd0:  9a 03 7f a9  add  %o5, -87, %o5
a009abd4:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a009abd8:  94 02 ff aa  add  %o3, -86, %o2
a009abdc:  da 2e 60 30  stb  %o5, [ %i1 + 0x30 ]
a009abe0:  92 10 20 01  mov  1, %o1
a009abe4:  40 00 3a 9b  call  0xa00a9650
a009abe8:  90 0a a0 ff  and  %o2, 0xff, %o0
a009abec:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a009abf0:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1	! 0xa8025c56
a009abf4:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009abf8:  82 0e 60 ff  and  %i1, 0xff, %g1
a009abfc:  b0 02 7f aa  add  %o1, -86, %i0
a009ac00:  b4 00 60 01  add  %g1, 1, %i2
a009ac04:  80 a6 00 1a  cmp  %i0, %i2
a009ac08:  02 80 00 18  be  0xa009ac68
a009ac0c:  90 06 60 01  add  %i1, 1, %o0
a009ac10:  b2 06 60 01  inc  %i1
a009ac14:  b2 0e 60 ff  and  %i1, 0xff, %i1
a009ac18:  b0 10 20 01  mov  1, %i0
a009ac1c:  40 00 35 48  call  0xa00a813c
a009ac20:  95 e8 20 01  restore  %g0, 1, %o2
a009ac24:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a009ac28:  d8 0e 60 56  ldub  [ %i1 + 0x56 ], %o4	! 0xa8025c56
a009ac2c:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a009ac30:  94 02 ff aa  add  %o3, -86, %o2
a009ac34:  92 10 20 01  mov  1, %o1
a009ac38:  d8 2b e0 30  stb  %o4, [ %o7 + 0x30 ]
a009ac3c:  40 00 3a 85  call  0xa00a9650
a009ac40:  90 0a a0 ff  and  %o2, 0xff, %o0
a009ac44:  f2 0e 60 56  ldub  [ %i1 + 0x56 ], %i1
a009ac48:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1
a009ac4c:  82 0e 60 ff  and  %i1, 0xff, %g1
a009ac50:  b0 02 7f aa  add  %o1, -86, %i0
a009ac54:  b4 00 60 01  add  %g1, 1, %i2
a009ac58:  80 a6 00 1a  cmp  %i0, %i2
a009ac5c:  32 bf ff ee  bne,a   0xa009ac14
a009ac60:  b2 06 60 01  inc  %i1
a009ac64:  90 06 60 01  add  %i1, 1, %o0
a009ac68:  b2 0a 20 ff  and  %o0, 0xff, %i1
a009ac6c:  b0 10 20 01  mov  1, %i0
a009ac70:  40 00 35 33  call  0xa00a813c
a009ac74:  95 e8 20 00  restore  %g0, 0, %o2
a009ac78:  01 00 00 00  nop
