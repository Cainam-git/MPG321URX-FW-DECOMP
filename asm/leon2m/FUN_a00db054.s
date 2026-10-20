# leon2m FUN_a00db054 0xa00db054-0xa00db1ac (224 bytes)
a00db054:  9d e3 bf 98  save  %sp, -104, %sp
a00db058:  40 01 26 6c  call  0xa0124a08
a00db05c:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a00db060:  40 01 26 13  call  0xa01248ac
a00db064:  01 00 00 00  nop
a00db068:  90 10 20 00  clr  %o0	! 0x0
a00db06c:  40 01 a8 30  call  0xa014512c
a00db070:  92 10 20 00  clr  %o1
a00db074:  90 10 20 02  mov  2, %o0
a00db078:  7f ff fa 60  call  0xa00d99f8
a00db07c:  92 10 20 00  clr  %o1
a00db080:  90 10 20 00  clr  %o0
a00db084:  40 01 b4 79  call  0xa0148268
a00db088:  92 10 20 01  mov  1, %o1
a00db08c:  90 10 20 01  mov  1, %o0
a00db090:  40 01 b4 76  call  0xa0148268
a00db094:  92 10 20 01  mov  1, %o1
a00db098:  92 10 20 01  mov  1, %o1
a00db09c:  90 10 20 04  mov  4, %o0
a00db0a0:  40 01 be 0d  call  0xa014a8d4
a00db0a4:  94 10 23 e8  mov  0x3e8, %o2
a00db0a8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00db0ac:  11 00 03 00  sethi  %hi(0xc0000), %o0
a00db0b0:  da 02 63 3c  ld  [ %o1 + 0x33c ], %o5
a00db0b4:  9a 0b 40 08  and  %o5, %o0, %o5
a00db0b8:  03 00 01 00  sethi  %hi(0x40000), %g1
a00db0bc:  98 16 21 f0  or  %i0, 0x1f0, %o4
a00db0c0:  80 a3 40 01  cmp  %o5, %g1
a00db0c4:  02 80 00 12  be  0xa00db10c
a00db0c8:  90 10 20 00  clr  %o0
a00db0cc:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a00db0d0:  15 00 02 00  sethi  %hi(0x80000), %o2
a00db0d4:  98 16 21 f0  or  %i0, 0x1f0, %o4
a00db0d8:  80 a3 40 0a  cmp  %o5, %o2
a00db0dc:  02 80 00 0c  be  0xa00db10c
a00db0e0:  90 10 20 01  mov  1, %o0
a00db0e4:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a00db0e8:  98 16 21 f0  or  %i0, 0x1f0, %o4	! 0xa802e1f0
a00db0ec:  9e 10 21 c2  mov  0x1c2, %o7
a00db0f0:  de 33 20 24  sth  %o7, [ %o4 + 0x24 ]
a00db0f4:  40 01 cb d7  call  0xa014e050
a00db0f8:  90 10 20 00  clr  %o0
a00db0fc:  82 16 21 f0  or  %i0, 0x1f0, %g1
a00db100:  f0 10 60 24  lduh  [ %g1 + 0x24 ], %i0
a00db104:  40 01 cb c8  call  0xa014e024
a00db108:  81 e8 00 00  restore
a00db10c:  96 10 23 f7  mov  0x3f7, %o3
a00db110:  40 01 cb d0  call  0xa014e050
a00db114:  d6 33 20 24  sth  %o3, [ %o4 + 0x24 ]
a00db118:  82 16 21 f0  or  %i0, 0x1f0, %g1
a00db11c:  f0 10 60 24  lduh  [ %g1 + 0x24 ], %i0
a00db120:  40 01 cb c1  call  0xa014e024
a00db124:  81 e8 00 00  restore
a00db128:  01 00 00 00  nop
a00db12c:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a00db130:  c2 03 60 7c  ld  [ %o5 + 0x7c ], %g1	! 0xa802d47c
a00db134:  90 0a 20 ff  and  %o0, 0xff, %o0
a00db138:  9b 30 60 07  srl  %g1, 7, %o5
a00db13c:  80 a0 00 08  cmp  %g0, %o0
a00db140:  90 1b 60 01  xor  %o5, 1, %o0
a00db144:  82 0a 20 01  and  %o0, 1, %g1
a00db148:  9a 40 20 00  addx  %g0, 0, %o5
a00db14c:  80 90 40 0d  orcc  %g1, %o5, %g0
a00db150:  02 80 00 05  be  0xa00db164
a00db154:  01 00 00 00  nop
a00db158:  82 13 c0 00  mov  %o7, %g1
a00db15c:  40 01 29 e4  call  0xa01258ec
a00db160:  9e 10 40 00  mov  %g1, %o7
a00db164:  82 13 c0 00  mov  %o7, %g1
a00db168:  40 01 29 da  call  0xa01258d0
a00db16c:  9e 10 40 00  mov  %g1, %o7
a00db170:  01 00 00 00  nop
a00db174:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00db178:  da 02 20 84  ld  [ %o0 + 0x84 ], %o5	! 0xa802d484
a00db17c:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00db180:  80 8b 40 01  btst  %o5, %g1
a00db184:  02 80 00 05  be  0xa00db198
a00db188:  90 10 20 01  mov  1, %o0
a00db18c:  82 13 c0 00  mov  %o7, %g1
a00db190:  40 01 24 8b  call  0xa01243bc
a00db194:  9e 10 40 00  mov  %g1, %o7
a00db198:  90 10 20 00  clr  %o0
a00db19c:  82 13 c0 00  mov  %o7, %g1
a00db1a0:  40 01 24 87  call  0xa01243bc
a00db1a4:  9e 10 40 00  mov  %g1, %o7
a00db1a8:  01 00 00 00  nop
