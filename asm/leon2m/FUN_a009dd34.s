# leon2m FUN_a009dd34 0xa009dd34-0xa009dd9c (104 bytes)
a009dd34:  9d e3 bf 98  save  %sp, -104, %sp
a009dd38:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009dd3c:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a009dd40:  90 00 60 4a  add  %g1, 0x4a, %o0
a009dd44:  40 00 2d 9e  call  0xa00a93bc
a009dd48:  90 0a 20 ff  and  %o0, 0xff, %o0
a009dd4c:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009dd50:  96 02 3f 4b  add  %o0, -181, %o3
a009dd54:  b1 32 e0 1f  srl  %o3, 0x1f, %i0
a009dd58:  9e 02 c0 18  add  %o3, %i0, %o7
a009dd5c:  98 0b ff fe  and  %o7, -2, %o4
a009dd60:  94 22 c0 0c  sub  %o3, %o4, %o2
a009dd64:  9a 02 a0 b6  add  %o2, 0xb6, %o5
a009dd68:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a009dd6c:  40 00 33 f1  call  0xa00aad30
a009dd70:  90 0a a0 ff  and  %o2, 0xff, %o0
a009dd74:  92 0a 20 ff  and  %o0, 0xff, %o1
a009dd78:  80 a2 60 01  cmp  %o1, 1
a009dd7c:  12 bf ff f5  bne  0xa009dd50
a009dd80:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009dd84:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a009dd88:  b2 00 60 4a  add  %g1, 0x4a, %i1
a009dd8c:  b0 0e 60 ff  and  %i1, 0xff, %i0
a009dd90:  40 00 2e 30  call  0xa00a9650
a009dd94:  93 e8 20 01  restore  %g0, 1, %o1
a009dd98:  01 00 00 00  nop
