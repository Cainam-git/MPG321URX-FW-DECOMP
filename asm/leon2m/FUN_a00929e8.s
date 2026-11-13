# leon2m FUN_a00929e8 0xa00929e8-0xa0092a80 (152 bytes)
a00929e8:  9d e3 bf 98  save  %sp, -104, %sp
a00929ec:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a00929f0:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a00929f4:  90 00 7f da  add  %g1, -38, %o0
a00929f8:  40 00 59 3c  call  0xa00a8ee8
a00929fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0092a00:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0092a04:  96 02 3f dd  add  %o0, -35, %o3
a0092a08:  83 3a e0 1f  sra  %o3, 0x1f, %g1
a0092a0c:  b1 30 60 1e  srl  %g1, 0x1e, %i0
a0092a10:  9e 02 c0 18  add  %o3, %i0, %o7
a0092a14:  98 0b ff fc  and  %o7, -4, %o4
a0092a18:  94 22 c0 0c  sub  %o3, %o4, %o2
a0092a1c:  9a 02 a0 26  add  %o2, 0x26, %o5
a0092a20:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a0092a24:  40 00 5e bf  call  0xa00aa520
a0092a28:  90 0a a0 ff  and  %o2, 0xff, %o0
a0092a2c:  92 0a 20 ff  and  %o0, 0xff, %o1
a0092a30:  80 a2 60 01  cmp  %o1, 1
a0092a34:  12 bf ff f4  bne  0xa0092a04
a0092a38:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0092a3c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0092a40:  9a 10 62 90  or  %g1, 0x290, %o5	! 0xa802d290
a0092a44:  f0 0b 61 a3  ldub  [ %o5 + 0x1a3 ], %i0
a0092a48:  9e 06 20 03  add  %i0, 3, %o7
a0092a4c:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a0092a50:  96 0b e0 03  and  %o7, 3, %o3
a0092a54:  94 03 3f da  add  %o4, -38, %o2
a0092a58:  92 10 20 01  mov  1, %o1
a0092a5c:  d6 2b 61 a3  stb  %o3, [ %o5 + 0x1a3 ]
a0092a60:  40 00 59 6b  call  0xa00a900c
a0092a64:  90 0a a0 ff  and  %o2, 0xff, %o0
a0092a68:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0092a6c:  b2 02 7f da  add  %o1, -38, %i1
a0092a70:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0092a74:  40 00 72 76  call  0xa00af44c
a0092a78:  91 e8 20 26  restore  %g0, 0x26, %o0
a0092a7c:  01 00 00 00  nop
