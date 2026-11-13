# leon2s FUN_a0093084 0xa0093084-0xa0093138 (180 bytes)
a0093084:  9d e3 bf 98  save  %sp, -104, %sp
a0093088:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009308c:  90 10 00 10  mov  %l0, %o0
a0093090:  92 10 20 00  clr  %o1
a0093094:  94 10 21 80  mov  0x180, %o2
a0093098:  40 00 53 ef  call  0xa00a8054
a009309c:  d6 0e 40 00  ldub  [ %i1 ], %o3
a00930a0:  90 10 00 10  mov  %l0, %o0
a00930a4:  92 10 20 00  clr  %o1
a00930a8:  94 10 21 81  mov  0x181, %o2
a00930ac:  40 00 53 ea  call  0xa00a8054
a00930b0:  d6 0e 60 01  ldub  [ %i1 + 1 ], %o3
a00930b4:  d6 0e 60 02  ldub  [ %i1 + 2 ], %o3
a00930b8:  90 10 00 10  mov  %l0, %o0
a00930bc:  92 10 20 00  clr  %o1
a00930c0:  40 00 53 e5  call  0xa00a8054
a00930c4:  94 10 21 82  mov  0x182, %o2
a00930c8:  d6 0e 60 02  ldub  [ %i1 + 2 ], %o3
a00930cc:  80 a2 e0 00  cmp  %o3, 0
a00930d0:  b6 10 20 00  clr  %i3
a00930d4:  02 80 00 12  be  0xa009311c
a00930d8:  b4 10 20 00  clr  %i2
a00930dc:  94 0e a0 ff  and  %i2, 0xff, %o2
a00930e0:  94 02 a1 84  add  %o2, 0x184, %o2
a00930e4:  95 2a a0 10  sll  %o2, 0x10, %o2
a00930e8:  95 32 a0 10  srl  %o2, 0x10, %o2
a00930ec:  90 10 00 10  mov  %l0, %o0
a00930f0:  40 00 53 d9  call  0xa00a8054
a00930f4:  92 10 20 00  clr  %o1
a00930f8:  82 0e a0 ff  and  %i2, 0xff, %g1
a00930fc:  82 06 40 01  add  %i1, %g1, %g1
a0093100:  da 08 60 04  ldub  [ %g1 + 4 ], %o5
a0093104:  b4 06 a0 01  inc  %i2
a0093108:  82 0e a0 ff  and  %i2, 0xff, %g1
a009310c:  d6 0e 60 02  ldub  [ %i1 + 2 ], %o3
a0093110:  80 a0 40 0b  cmp  %g1, %o3
a0093114:  0a bf ff f2  bcs  0xa00930dc
a0093118:  b6 06 c0 0d  add  %i3, %o5, %i3
a009311c:  b6 20 00 1b  neg  %i3
a0093120:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0093124:  b6 0e e0 ff  and  %i3, 0xff, %i3
a0093128:  b2 10 20 00  clr  %i1
a009312c:  40 00 53 ca  call  0xa00a8054
a0093130:  95 e8 21 83  restore  %g0, 0x183, %o2
a0093134:  01 00 00 00  nop
