# leon2m FUN_a009e0bc 0xa009e0bc-0xa009e154 (152 bytes)
a009e0bc:  9d e3 bf 98  save  %sp, -104, %sp
a009e0c0:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009e0c4:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009e0c8:  90 00 60 3d  add  %g1, 0x3d, %o0
a009e0cc:  40 00 2c bc  call  0xa00a93bc
a009e0d0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009e0d4:  f2 16 a3 ee  lduh  [ %i2 + 0x3ee ], %i1
a009e0d8:  96 06 7f 3e  add  %i1, -194, %o3
a009e0dc:  b1 32 e0 1f  srl  %o3, 0x1f, %i0
a009e0e0:  9e 02 c0 18  add  %o3, %i0, %o7
a009e0e4:  98 0b ff fe  and  %o7, -2, %o4
a009e0e8:  94 22 c0 0c  sub  %o3, %o4, %o2
a009e0ec:  9a 02 a0 c3  add  %o2, 0xc3, %o5
a009e0f0:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009e0f4:  40 00 33 0f  call  0xa00aad30
a009e0f8:  90 0a a0 ff  and  %o2, 0xff, %o0
a009e0fc:  92 0a 20 ff  and  %o0, 0xff, %o1
a009e100:  80 a2 60 01  cmp  %o1, 1
a009e104:  12 bf ff f5  bne  0xa009e0d8
a009e108:  f2 16 a3 ee  lduh  [ %i2 + 0x3ee ], %i1
a009e10c:  d4 06 a3 ec  ld  [ %i2 + 0x3ec ], %o2
a009e110:  92 02 a0 3d  add  %o2, 0x3d, %o1
a009e114:  90 0a 60 ff  and  %o1, 0xff, %o0
a009e118:  40 00 2d 4e  call  0xa00a9650
a009e11c:  92 10 20 01  mov  1, %o1
a009e120:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1
a009e124:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009e128:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009e12c:  90 00 7f 3d  add  %g1, -195, %o0
a009e130:  b0 10 20 01  mov  1, %i0
a009e134:  80 a2 00 19  cmp  %o0, %i1
a009e138:  02 80 00 04  be  0xa009e148
a009e13c:  b4 10 20 00  clr  %i2
a009e140:  b0 10 20 01  mov  1, %i0
a009e144:  b4 10 20 01  mov  1, %i2
a009e148:  40 00 27 fd  call  0xa00a813c
a009e14c:  81 e8 00 00  restore
a009e150:  01 00 00 00  nop
