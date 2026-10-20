# leon2m FUN_a009ba34 0xa009ba34-0xa009bb0c (216 bytes)
a009ba34:  9d e3 bf 98  save  %sp, -104, %sp
a009ba38:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009ba3c:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009ba40:  90 02 60 19  add  %o1, 0x19, %o0
a009ba44:  40 00 36 5e  call  0xa00a93bc
a009ba48:  90 0a 20 ff  and  %o0, 0xff, %o0
a009ba4c:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009ba50:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009ba54:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009ba58:  9e 02 3f 1a  add  %o0, -230, %o7
a009ba5c:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009ba60:  80 5b c0 19  smul  %o7, %i1, %g0
a009ba64:  93 40 00 00  rd  %y, %o1
a009ba68:  82 22 40 0a  sub  %o1, %o2, %g1
a009ba6c:  b0 00 40 01  add  %g1, %g1, %i0
a009ba70:  98 06 00 01  add  %i0, %g1, %o4
a009ba74:  96 23 c0 0c  sub  %o7, %o4, %o3
a009ba78:  9a 02 e0 e7  add  %o3, 0xe7, %o5
a009ba7c:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009ba80:  40 00 3c ac  call  0xa00aad30
a009ba84:  90 0a e0 ff  and  %o3, 0xff, %o0
a009ba88:  94 0a 20 ff  and  %o0, 0xff, %o2
a009ba8c:  80 a2 a0 01  cmp  %o2, 1
a009ba90:  32 bf ff f2  bne,a   0xa009ba58
a009ba94:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009ba98:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009ba9c:  9a 03 20 19  add  %o4, 0x19, %o5
a009baa0:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a009baa4:  90 0b 60 ff  and  %o5, 0xff, %o0
a009baa8:  da 2b e2 db  stb  %o5, [ %o7 + 0x2db ]
a009baac:  40 00 36 e9  call  0xa00a9650
a009bab0:  92 10 20 01  mov  1, %o1
a009bab4:  40 00 e8 fe  call  0xa00d5eac
a009bab8:  90 10 20 01  mov  1, %o0
a009babc:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009bac0:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009bac4:  b2 02 ff 19  add  %o3, -231, %i1
a009bac8:  d2 0e a0 55  ldub  [ %i2 + 0x55 ], %o1
a009bacc:  90 10 20 01  mov  1, %o0
a009bad0:  80 a6 40 09  cmp  %i1, %o1
a009bad4:  02 80 00 04  be  0xa009bae4
a009bad8:  94 10 20 00  clr  %o2
a009badc:  90 10 20 01  mov  1, %o0
a009bae0:  94 10 20 01  mov  1, %o2
a009bae4:  40 00 31 96  call  0xa00a813c
a009bae8:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a009baec:  d2 0e 20 8e  ldub  [ %i0 + 0x8e ], %o1	! 0xa802b08e
a009baf0:  82 12 60 02  or  %o1, 2, %g1
a009baf4:  c2 2e 20 8e  stb  %g1, [ %i0 + 0x8e ]
a009baf8:  b0 10 20 01  mov  1, %i0
a009bafc:  b2 10 20 00  clr  %i1
a009bb00:  40 02 bb 75  call  0xa014a8d4
a009bb04:  95 e8 20 00  restore  %g0, 0, %o2
a009bb08:  01 00 00 00  nop
