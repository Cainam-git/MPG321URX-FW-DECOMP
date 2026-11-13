# leon2m FUN_a009bb0c 0xa009bb0c-0xa009bbe4 (216 bytes)
a009bb0c:  9d e3 bf 98  save  %sp, -104, %sp
a009bb10:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009bb14:  d2 06 a3 ec  ld  [ %i2 + 0x3ec ], %o1	! 0xa802afec
a009bb18:  90 02 60 16  add  %o1, 0x16, %o0
a009bb1c:  40 00 36 28  call  0xa00a93bc
a009bb20:  90 0a 20 ff  and  %o0, 0xff, %o0
a009bb24:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009bb28:  b2 10 61 56  or  %g1, 0x156, %i1	! 0x55555556
a009bb2c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009bb30:  9e 02 3f 18  add  %o0, -232, %o7
a009bb34:  95 3b e0 1f  sra  %o7, 0x1f, %o2
a009bb38:  80 5b c0 19  smul  %o7, %i1, %g0
a009bb3c:  93 40 00 00  rd  %y, %o1
a009bb40:  82 22 40 0a  sub  %o1, %o2, %g1
a009bb44:  b0 00 40 01  add  %g1, %g1, %i0
a009bb48:  98 06 00 01  add  %i0, %g1, %o4
a009bb4c:  96 23 c0 0c  sub  %o7, %o4, %o3
a009bb50:  9a 02 e0 ea  add  %o3, 0xea, %o5
a009bb54:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009bb58:  40 00 3c 76  call  0xa00aad30
a009bb5c:  90 0a e0 ff  and  %o3, 0xff, %o0
a009bb60:  94 0a 20 ff  and  %o0, 0xff, %o2
a009bb64:  80 a2 a0 01  cmp  %o2, 1
a009bb68:  32 bf ff f2  bne,a   0xa009bb30
a009bb6c:  d0 16 a3 ee  lduh  [ %i2 + 0x3ee ], %o0
a009bb70:  d8 06 a3 ec  ld  [ %i2 + 0x3ec ], %o4
a009bb74:  9a 03 20 16  add  %o4, 0x16, %o5
a009bb78:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a009bb7c:  90 0b 60 ff  and  %o5, 0xff, %o0
a009bb80:  da 2b e2 dc  stb  %o5, [ %o7 + 0x2dc ]
a009bb84:  40 00 36 b3  call  0xa00a9650
a009bb88:  92 10 20 01  mov  1, %o1
a009bb8c:  40 00 e8 c8  call  0xa00d5eac
a009bb90:  90 10 20 01  mov  1, %o0
a009bb94:  d6 06 a3 ec  ld  [ %i2 + 0x3ec ], %o3
a009bb98:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009bb9c:  b2 02 ff 16  add  %o3, -234, %i1
a009bba0:  d2 0e a0 55  ldub  [ %i2 + 0x55 ], %o1
a009bba4:  90 10 20 01  mov  1, %o0
a009bba8:  80 a6 40 09  cmp  %i1, %o1
a009bbac:  02 80 00 04  be  0xa009bbbc
a009bbb0:  94 10 20 00  clr  %o2
a009bbb4:  90 10 20 01  mov  1, %o0
a009bbb8:  94 10 20 01  mov  1, %o2
a009bbbc:  40 00 31 60  call  0xa00a813c
a009bbc0:  31 2a 00 ac  sethi  %hi(0xa802b000), %i0
a009bbc4:  d2 0e 20 8e  ldub  [ %i0 + 0x8e ], %o1	! 0xa802b08e
a009bbc8:  82 12 60 02  or  %o1, 2, %g1
a009bbcc:  c2 2e 20 8e  stb  %g1, [ %i0 + 0x8e ]
a009bbd0:  b0 10 20 01  mov  1, %i0
a009bbd4:  b2 10 20 00  clr  %i1
a009bbd8:  40 02 bb 3f  call  0xa014a8d4
a009bbdc:  95 e8 20 00  restore  %g0, 0, %o2
a009bbe0:  01 00 00 00  nop
