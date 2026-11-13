# leon2m FUN_a009bedc 0xa009bedc-0xa009bf48 (108 bytes)
a009bedc:  9d e3 bf 98  save  %sp, -104, %sp
a009bee0:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009bee4:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a009bee8:  90 00 7f c1  add  %g1, -63, %o0
a009beec:  40 00 35 34  call  0xa00a93bc
a009bef0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009bef4:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009bef8:  96 02 3f c4  add  %o0, -60, %o3
a009befc:  83 3a e0 1f  sra  %o3, 0x1f, %g1
a009bf00:  b1 30 60 1e  srl  %g1, 0x1e, %i0
a009bf04:  9e 02 c0 18  add  %o3, %i0, %o7
a009bf08:  98 0b ff fc  and  %o7, -4, %o4
a009bf0c:  94 22 c0 0c  sub  %o3, %o4, %o2
a009bf10:  9a 02 a0 3f  add  %o2, 0x3f, %o5
a009bf14:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a009bf18:  40 00 3b 86  call  0xa00aad30
a009bf1c:  90 0a a0 ff  and  %o2, 0xff, %o0
a009bf20:  92 0a 20 ff  and  %o0, 0xff, %o1
a009bf24:  80 a2 60 01  cmp  %o1, 1
a009bf28:  12 bf ff f4  bne  0xa009bef8
a009bf2c:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009bf30:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a009bf34:  b2 02 7f c1  add  %o1, -63, %i1
a009bf38:  b0 0e 60 ff  and  %i1, 0xff, %i0
a009bf3c:  40 00 35 c5  call  0xa00a9650
a009bf40:  93 e8 20 01  restore  %g0, 1, %o1
a009bf44:  01 00 00 00  nop
