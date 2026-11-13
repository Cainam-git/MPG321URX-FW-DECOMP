# leon2m FUN_a00db054 0xa00db054-0xa00db12c (216 bytes)
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
