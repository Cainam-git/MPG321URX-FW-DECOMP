# leon2m FUN_a009dd9c 0xa009dd9c-0xa009de04 (104 bytes)
a009dd9c:  9d e3 bf 98  save  %sp, -104, %sp
a009dda0:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009dda4:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1	! 0xa802afec
a009dda8:  90 00 60 4a  add  %g1, 0x4a, %o0
a009ddac:  40 00 2d 84  call  0xa00a93bc
a009ddb0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009ddb4:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009ddb8:  96 02 3f 4b  add  %o0, -181, %o3
a009ddbc:  b1 32 e0 1f  srl  %o3, 0x1f, %i0
a009ddc0:  9e 02 c0 18  add  %o3, %i0, %o7
a009ddc4:  98 0b ff fe  and  %o7, -2, %o4
a009ddc8:  94 22 c0 0c  sub  %o3, %o4, %o2
a009ddcc:  9a 02 a0 b6  add  %o2, 0xb6, %o5
a009ddd0:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a009ddd4:  40 00 33 d7  call  0xa00aad30
a009ddd8:  90 0a a0 ff  and  %o2, 0xff, %o0
a009dddc:  92 0a 20 ff  and  %o0, 0xff, %o1
a009dde0:  80 a2 60 01  cmp  %o1, 1
a009dde4:  12 bf ff f5  bne  0xa009ddb8
a009dde8:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009ddec:  c2 06 63 ec  ld  [ %i1 + 0x3ec ], %g1
a009ddf0:  b2 00 60 4a  add  %g1, 0x4a, %i1
a009ddf4:  b0 0e 60 ff  and  %i1, 0xff, %i0
a009ddf8:  40 00 2e 16  call  0xa00a9650
a009ddfc:  93 e8 20 01  restore  %g0, 1, %o1
a009de00:  01 00 00 00  nop
