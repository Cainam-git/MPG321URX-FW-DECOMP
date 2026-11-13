# leon2m FUN_a0092a80 0xa0092a80-0xa0092b18 (152 bytes)
a0092a80:  9d e3 bf 98  save  %sp, -104, %sp
a0092a84:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a0092a88:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a0092a8c:  90 00 7f da  add  %g1, -38, %o0
a0092a90:  40 00 59 16  call  0xa00a8ee8
a0092a94:  90 0a 20 ff  and  %o0, 0xff, %o0
a0092a98:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0092a9c:  96 02 3f db  add  %o0, -37, %o3
a0092aa0:  83 3a e0 1f  sra  %o3, 0x1f, %g1
a0092aa4:  b1 30 60 1e  srl  %g1, 0x1e, %i0
a0092aa8:  9e 02 c0 18  add  %o3, %i0, %o7
a0092aac:  98 0b ff fc  and  %o7, -4, %o4
a0092ab0:  94 22 c0 0c  sub  %o3, %o4, %o2
a0092ab4:  9a 02 a0 26  add  %o2, 0x26, %o5
a0092ab8:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a0092abc:  40 00 5e 99  call  0xa00aa520
a0092ac0:  90 0a a0 ff  and  %o2, 0xff, %o0
a0092ac4:  92 0a 20 ff  and  %o0, 0xff, %o1
a0092ac8:  80 a2 60 01  cmp  %o1, 1
a0092acc:  12 bf ff f4  bne  0xa0092a9c
a0092ad0:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a0092ad4:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0092ad8:  9a 10 62 90  or  %g1, 0x290, %o5	! 0xa802d290
a0092adc:  f0 0b 61 a3  ldub  [ %o5 + 0x1a3 ], %i0
a0092ae0:  9e 06 20 01  add  %i0, 1, %o7
a0092ae4:  d8 06 63 ec  ld  [ %i1 + 0x3ec ], %o4
a0092ae8:  96 0b e0 03  and  %o7, 3, %o3
a0092aec:  94 03 3f da  add  %o4, -38, %o2
a0092af0:  92 10 20 01  mov  1, %o1
a0092af4:  d6 2b 61 a3  stb  %o3, [ %o5 + 0x1a3 ]
a0092af8:  40 00 59 45  call  0xa00a900c
a0092afc:  90 0a a0 ff  and  %o2, 0xff, %o0
a0092b00:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a0092b04:  b2 02 7f da  add  %o1, -38, %i1
a0092b08:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0092b0c:  40 00 72 50  call  0xa00af44c
a0092b10:  91 e8 20 26  restore  %g0, 0x26, %o0
a0092b14:  01 00 00 00  nop
