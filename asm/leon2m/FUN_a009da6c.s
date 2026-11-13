# leon2m FUN_a009da6c 0xa009da6c-0xa009db20 (180 bytes)
a009da6c:  9d e3 bf 98  save  %sp, -104, %sp
a009da70:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009da74:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009da78:  90 02 7f c4  add  %o1, -60, %o0
a009da7c:  40 00 2e 50  call  0xa00a93bc
a009da80:  90 0a 20 ff  and  %o0, 0xff, %o0
a009da84:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009da88:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009da8c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009da90:  9e 02 3f c6  add  %o0, -58, %o7
a009da94:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009da98:  80 5b c0 19  smul  %o7, %i1, %g0
a009da9c:  93 40 00 00  rd  %y, %o1
a009daa0:  82 22 40 0a  sub  %o1, %o2, %g1
a009daa4:  b0 00 40 01  add  %g1, %g1, %i0
a009daa8:  98 06 00 01  add  %i0, %g1, %o4
a009daac:  96 23 c0 0c  sub  %o7, %o4, %o3
a009dab0:  9a 02 e0 3c  add  %o3, 0x3c, %o5
a009dab4:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009dab8:  40 00 34 9e  call  0xa00aad30
a009dabc:  90 0a e0 ff  and  %o3, 0xff, %o0
a009dac0:  94 0a 20 ff  and  %o0, 0xff, %o2
a009dac4:  80 a2 a0 01  cmp  %o2, 1
a009dac8:  12 bf ff f2  bne  0xa009da90
a009dacc:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009dad0:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009dad4:  9a 03 3f c4  add  %o4, -60, %o5
a009dad8:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a009dadc:  da 2b e0 0c  stb  %o5, [ %o7 + 0xc ]	! 0xa802d40c
a009dae0:  90 0b 60 ff  and  %o5, 0xff, %o0
a009dae4:  40 00 2e db  call  0xa00a9650
a009dae8:  92 10 20 01  mov  1, %o1
a009daec:  f2 06 a3 ec  ld  [ %i2 + 0x3ec ], %i1
a009daf0:  96 06 7f c4  add  %i1, -60, %o3
a009daf4:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009daf8:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009dafc:  b0 10 20 01  mov  1, %i0
a009db00:  80 a2 c0 19  cmp  %o3, %i1
a009db04:  02 80 00 04  be  0xa009db14
a009db08:  b4 10 20 00  clr  %i2
a009db0c:  b0 10 20 01  mov  1, %i0
a009db10:  b4 10 20 01  mov  1, %i2
a009db14:  40 00 29 8a  call  0xa00a813c
a009db18:  81 e8 00 00  restore
a009db1c:  01 00 00 00  nop
