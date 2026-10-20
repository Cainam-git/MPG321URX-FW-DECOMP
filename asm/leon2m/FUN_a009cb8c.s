# leon2m FUN_a009cb8c 0xa009cb8c-0xa009cc0c (128 bytes)
a009cb8c:  9d e3 bf 98  save  %sp, -104, %sp
a009cb90:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009cb94:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a009cb98:  90 02 7f 86  add  %o1, -122, %o0
a009cb9c:  40 00 32 08  call  0xa00a93bc
a009cba0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009cba4:  03 19 99 99  sethi  %hi(0x66666400), %g1
a009cba8:  b0 10 62 67  or  %g1, 0x267, %i0	! 0x66666667
a009cbac:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009cbb0:  9e 02 3f 87  add  %o0, -121, %o7
a009cbb4:  80 5b c0 18  smul  %o7, %i0, %g0
a009cbb8:  9b 40 00 00  rd  %y, %o5
a009cbbc:  95 3b 60 01  sra  %o5, 1, %o2
a009cbc0:  97 3b e0 1f  sra  %o7, 0x1f, %o3
a009cbc4:  92 22 80 0b  sub  %o2, %o3, %o1
a009cbc8:  83 2a 60 02  sll  %o1, 2, %g1
a009cbcc:  98 00 40 09  add  %g1, %o1, %o4
a009cbd0:  96 23 c0 0c  sub  %o7, %o4, %o3
a009cbd4:  9a 02 e0 7a  add  %o3, 0x7a, %o5
a009cbd8:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a009cbdc:  40 00 38 55  call  0xa00aad30
a009cbe0:  90 0a e0 ff  and  %o3, 0xff, %o0
a009cbe4:  94 0a 20 ff  and  %o0, 0xff, %o2
a009cbe8:  80 a2 a0 01  cmp  %o2, 1
a009cbec:  12 bf ff f1  bne  0xa009cbb0
a009cbf0:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009cbf4:  de 06 63 ec  ld  [ %i1 + 0x3ec ], %o7
a009cbf8:  b0 03 ff 86  add  %o7, -122, %i0
a009cbfc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009cc00:  40 00 32 94  call  0xa00a9650
a009cc04:  93 e8 20 01  restore  %g0, 1, %o1
a009cc08:  01 00 00 00  nop
