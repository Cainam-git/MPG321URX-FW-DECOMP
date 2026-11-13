# leon2m FUN_a013d0ec 0xa013d0ec-0xa013d178 (140 bytes)
a013d0ec:  9d e3 bf 98  save  %sp, -104, %sp
a013d0f0:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a013d0f4:  80 8e 20 ff  btst  0xff, %i0
a013d0f8:  12 80 00 1d  bne  0xa013d16c
a013d0fc:  82 14 20 1c  or  %l0, 0x1c, %g1
a013d100:  c2 00 60 28  ld  [ %g1 + 0x28 ], %g1
a013d104:  80 a0 60 00  cmp  %g1, 0
a013d108:  12 80 00 10  bne  0xa013d148
a013d10c:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a013d110:  da 03 23 d0  ld  [ %o4 + 0x3d0 ], %o5	! 0xa802e3d0
a013d114:  11 01 00 00  sethi  %hi(0x4000000), %o0
a013d118:  82 2b 40 08  andn  %o5, %o0, %g1
a013d11c:  c2 23 23 d0  st  %g1, [ %o4 + 0x3d0 ]
a013d120:  92 14 20 1c  or  %l0, 0x1c, %o1
a013d124:  c2 02 60 24  ld  [ %o1 + 0x24 ], %g1
a013d128:  80 a0 60 00  cmp  %g1, 0
a013d12c:  12 80 00 0e  bne  0xa013d164
a013d130:  01 00 00 00  nop
a013d134:  de 03 23 d0  ld  [ %o4 + 0x3d0 ], %o7
a013d138:  17 02 00 00  sethi  %hi(0x8000000), %o3
a013d13c:  94 2b c0 0b  andn  %o7, %o3, %o2
a013d140:  10 80 00 0b  b  0xa013d16c
a013d144:  d4 23 23 d0  st  %o2, [ %o4 + 0x3d0 ]
a013d148:  9f c0 40 00  call  %g1
a013d14c:  01 00 00 00  nop
a013d150:  92 14 20 1c  or  %l0, 0x1c, %o1
a013d154:  c2 02 60 24  ld  [ %o1 + 0x24 ], %g1
a013d158:  80 a0 60 00  cmp  %g1, 0
a013d15c:  02 bf ff f6  be  0xa013d134
a013d160:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a013d164:  9f c0 40 00  call  %g1
a013d168:  01 00 00 00  nop
a013d16c:  01 00 00 00  nop
a013d170:  81 c7 e0 08  ret
a013d174:  81 e8 00 00  restore
