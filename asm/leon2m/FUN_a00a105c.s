# leon2m FUN_a00a105c 0xa00a105c-0xa00a10c8 (108 bytes)
a00a105c:  9d e3 bf 98  save  %sp, -104, %sp
a00a1060:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a00a1064:  98 14 23 f4  or  %l0, 0x3f4, %o4	! 0xa802cff4
a00a1068:  c2 13 20 36  lduh  [ %o4 + 0x36 ], %g1
a00a106c:  80 a0 6b 3f  cmp  %g1, 0xb3f
a00a1070:  18 80 00 13  bgu  0xa00a10bc
a00a1074:  9a 00 60 08  add  %g1, 8, %o5
a00a1078:  da 33 20 36  sth  %o5, [ %o4 + 0x36 ]
a00a107c:  a0 14 23 f4  or  %l0, 0x3f4, %l0
a00a1080:  d4 14 20 36  lduh  [ %l0 + 0x36 ], %o2
a00a1084:  92 02 a0 04  add  %o2, 4, %o1
a00a1088:  97 2a 60 10  sll  %o1, 0x10, %o3
a00a108c:  97 32 e0 10  srl  %o3, 0x10, %o3
a00a1090:  90 10 20 06  mov  6, %o0
a00a1094:  d2 14 20 36  lduh  [ %l0 + 0x36 ], %o1
a00a1098:  94 10 20 00  clr  %o2
a00a109c:  d8 14 20 38  lduh  [ %l0 + 0x38 ], %o4
a00a10a0:  40 02 95 f4  call  0xa0146870
a00a10a4:  9a 10 20 00  clr  %o5
a00a10a8:  31 00 04 20  sethi  %hi(0x108000), %i0
a00a10ac:  f4 14 20 38  lduh  [ %l0 + 0x38 ], %i2
a00a10b0:  f2 14 20 36  lduh  [ %l0 + 0x36 ], %i1
a00a10b4:  40 00 f8 2f  call  0xa00df170
a00a10b8:  91 ee 21 98  restore  %i0, 0x198, %o0
a00a10bc:  90 10 2b 40  mov  0xb40, %o0
a00a10c0:  10 bf ff ef  b  0xa00a107c
a00a10c4:  d0 33 20 36  sth  %o0, [ %o4 + 0x36 ]
