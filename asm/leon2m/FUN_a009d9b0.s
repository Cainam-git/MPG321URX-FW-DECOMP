# leon2m FUN_a009d9b0 0xa009d9b0-0xa009da6c (188 bytes)
a009d9b0:  9d e3 bf 98  save  %sp, -104, %sp
a009d9b4:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009d9b8:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009d9bc:  90 00 60 4c  add  %g1, 0x4c, %o0
a009d9c0:  40 00 2e 7f  call  0xa00a93bc
a009d9c4:  90 0a 20 ff  and  %o0, 0xff, %o0
a009d9c8:  f2 16 a3 ee  lduh  [ %i2 + 0x3ee ], %i1
a009d9cc:  96 06 7f 4d  add  %i1, -179, %o3
a009d9d0:  b1 32 e0 1f  srl  %o3, 0x1f, %i0
a009d9d4:  9e 02 c0 18  add  %o3, %i0, %o7
a009d9d8:  98 0b ff fe  and  %o7, -2, %o4
a009d9dc:  94 22 c0 0c  sub  %o3, %o4, %o2
a009d9e0:  9a 02 a0 b4  add  %o2, 0xb4, %o5
a009d9e4:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009d9e8:  40 00 34 d2  call  0xa00aad30
a009d9ec:  90 0a a0 ff  and  %o2, 0xff, %o0
a009d9f0:  92 0a 20 ff  and  %o0, 0xff, %o1
a009d9f4:  80 a2 60 01  cmp  %o1, 1
a009d9f8:  12 bf ff f5  bne  0xa009d9cc
a009d9fc:  f2 16 a3 ee  lduh  [ %i2 + 0x3ee ], %i1
a009da00:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1
a009da04:  90 00 60 4c  add  %g1, 0x4c, %o0
a009da08:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a009da0c:  92 13 22 90  or  %o4, 0x290, %o1	! 0xa802d290
a009da10:  90 0a 20 ff  and  %o0, 0xff, %o0
a009da14:  d6 02 60 a8  ld  [ %o1 + 0xa8 ], %o3
a009da18:  b0 0a 20 01  and  %o0, 1, %i0
a009da1c:  33 00 00 20  sethi  %hi(0x8000), %i1
a009da20:  9e 2a c0 19  andn  %o3, %i1, %o7
a009da24:  9b 2e 20 0f  sll  %i0, 0xf, %o5
a009da28:  94 13 c0 0d  or  %o7, %o5, %o2
a009da2c:  d4 22 60 a8  st  %o2, [ %o1 + 0xa8 ]
a009da30:  40 00 2f 08  call  0xa00a9650
a009da34:  92 10 20 01  mov  1, %o1
a009da38:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1
a009da3c:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009da40:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009da44:  90 00 7f 4c  add  %g1, -180, %o0
a009da48:  b0 10 20 01  mov  1, %i0
a009da4c:  80 a2 00 19  cmp  %o0, %i1
a009da50:  02 80 00 04  be  0xa009da60
a009da54:  b4 10 20 00  clr  %i2
a009da58:  b0 10 20 01  mov  1, %i0
a009da5c:  b4 10 20 01  mov  1, %i2
a009da60:  40 00 29 b7  call  0xa00a813c
a009da64:  81 e8 00 00  restore
a009da68:  01 00 00 00  nop
