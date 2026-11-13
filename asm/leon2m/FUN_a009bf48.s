# leon2m FUN_a009bf48 0xa009bf48-0xa009bfb4 (108 bytes)
a009bf48:  9d e3 bf 98  save  %sp, -104, %sp
a009bf4c:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009bf50:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a009bf54:  90 00 7f c1  add  %g1, -63, %o0
a009bf58:  40 00 35 19  call  0xa00a93bc
a009bf5c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009bf60:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009bf64:  96 02 3f c2  add  %o0, -62, %o3
a009bf68:  83 3a e0 1f  sra  %o3, 0x1f, %g1
a009bf6c:  b1 30 60 1e  srl  %g1, 0x1e, %i0
a009bf70:  9e 02 c0 18  add  %o3, %i0, %o7
a009bf74:  98 0b ff fc  and  %o7, -4, %o4
a009bf78:  94 22 c0 0c  sub  %o3, %o4, %o2
a009bf7c:  9a 02 a0 3f  add  %o2, 0x3f, %o5
a009bf80:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a009bf84:  40 00 3b 6b  call  0xa00aad30
a009bf88:  90 0a a0 ff  and  %o2, 0xff, %o0
a009bf8c:  92 0a 20 ff  and  %o0, 0xff, %o1
a009bf90:  80 a2 60 01  cmp  %o1, 1
a009bf94:  12 bf ff f4  bne  0xa009bf64
a009bf98:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009bf9c:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1
a009bfa0:  b2 02 7f c1  add  %o1, -63, %i1
a009bfa4:  b0 0e 60 ff  and  %i1, 0xff, %i0
a009bfa8:  40 00 35 aa  call  0xa00a9650
a009bfac:  93 e8 20 01  restore  %g0, 1, %o1
a009bfb0:  01 00 00 00  nop
