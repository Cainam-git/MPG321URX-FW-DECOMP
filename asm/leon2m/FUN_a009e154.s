# leon2m FUN_a009e154 0xa009e154-0xa009e1ec (152 bytes)
a009e154:  9d e3 bf 98  save  %sp, -104, %sp
a009e158:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a009e15c:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1	! 0xa802afec
a009e160:  90 00 60 3d  add  %g1, 0x3d, %o0
a009e164:  40 00 2c 96  call  0xa00a93bc
a009e168:  90 0a 20 ff  and  %o0, 0xff, %o0
a009e16c:  f2 16 a3 ee  lduh  [ %i2 + 0x3ee ], %i1
a009e170:  96 06 7f 3e  add  %i1, -194, %o3
a009e174:  b1 32 e0 1f  srl  %o3, 0x1f, %i0
a009e178:  9e 02 c0 18  add  %o3, %i0, %o7
a009e17c:  98 0b ff fe  and  %o7, -2, %o4
a009e180:  94 22 c0 0c  sub  %o3, %o4, %o2
a009e184:  9a 02 a0 c3  add  %o2, 0xc3, %o5
a009e188:  da 26 a3 ec  st  %o5, [ %i2 + 0x3ec ]
a009e18c:  40 00 32 e9  call  0xa00aad30
a009e190:  90 0a a0 ff  and  %o2, 0xff, %o0
a009e194:  92 0a 20 ff  and  %o0, 0xff, %o1
a009e198:  80 a2 60 01  cmp  %o1, 1
a009e19c:  12 bf ff f5  bne  0xa009e170
a009e1a0:  f2 16 a3 ee  lduh  [ %i2 + 0x3ee ], %i1
a009e1a4:  d4 06 a3 ec  ld  [ %i2 + 0x3ec ], %o2
a009e1a8:  92 02 a0 3d  add  %o2, 0x3d, %o1
a009e1ac:  90 0a 60 ff  and  %o1, 0xff, %o0
a009e1b0:  40 00 2d 28  call  0xa00a9650
a009e1b4:  92 10 20 01  mov  1, %o1
a009e1b8:  c2 06 a3 ec  ld  [ %i2 + 0x3ec ], %g1
a009e1bc:  35 2a 00 97  sethi  %hi(0xa8025c00), %i2
a009e1c0:  f2 0e a0 56  ldub  [ %i2 + 0x56 ], %i1	! 0xa8025c56
a009e1c4:  90 00 7f 3d  add  %g1, -195, %o0
a009e1c8:  b0 10 20 01  mov  1, %i0
a009e1cc:  80 a2 00 19  cmp  %o0, %i1
a009e1d0:  02 80 00 04  be  0xa009e1e0
a009e1d4:  b4 10 20 00  clr  %i2
a009e1d8:  b0 10 20 01  mov  1, %i0
a009e1dc:  b4 10 20 01  mov  1, %i2
a009e1e0:  40 00 27 d7  call  0xa00a813c
a009e1e4:  81 e8 00 00  restore
a009e1e8:  01 00 00 00  nop
