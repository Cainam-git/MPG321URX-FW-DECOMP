# leon2s FUN_a00d00e0 0xa00d00e0-0xa00d01f4 (276 bytes)
a00d00e0:  9d e3 bf 98  save  %sp, -104, %sp
a00d00e4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d00e8:  82 06 00 18  add  %i0, %i0, %g1
a00d00ec:  82 00 40 18  add  %g1, %i0, %g1
a00d00f0:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00d00f4:  a1 28 60 03  sll  %g1, 3, %l0
a00d00f8:  a2 13 63 b0  or  %o5, 0x3b0, %l1
a00d00fc:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00d0100:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00d0104:  82 2b 40 01  andn  %o5, %g1, %g1
a00d0108:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00d010c:  82 10 40 0d  or  %g1, %o5, %g1
a00d0110:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00d0114:  7f ff fe 83  call  0xa00cfb20
a00d0118:  90 06 20 08  add  %i0, 8, %o0
a00d011c:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00d0120:  03 00 10 00  sethi  %hi(0x400000), %g1
a00d0124:  98 2b 40 01  andn  %o5, %g1, %o4
a00d0128:  80 a2 20 00  cmp  %o0, 0
a00d012c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00d0130:  92 10 20 00  clr  %o1
a00d0134:  94 10 20 20  mov  0x20, %o2
a00d0138:  96 10 20 01  mov  1, %o3
a00d013c:  90 10 00 18  mov  %i0, %o0
a00d0140:  02 80 00 04  be  0xa00d0150
a00d0144:  9a 13 40 01  or  %o5, %g1, %o5
a00d0148:  10 80 00 29  b  0xa00d01ec
a00d014c:  da 24 40 10  st  %o5, [ %l1 + %l0 ]
a00d0150:  40 3b 9d fc  call  0xa0fb7940
a00d0154:  d8 24 40 10  st  %o4, [ %l1 + %l0 ]
a00d0158:  96 10 20 00  clr  %o3
a00d015c:  90 10 00 18  mov  %i0, %o0
a00d0160:  94 10 20 20  mov  0x20, %o2
a00d0164:  40 3b 9d f7  call  0xa0fb7940
a00d0168:  92 10 20 00  clr  %o1
a00d016c:  92 10 20 06  mov  6, %o1
a00d0170:  40 3b 9e 57  call  0xa0fb7acc
a00d0174:  90 10 20 00  clr  %o0
a00d0178:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00d017c:  98 10 61 54  or  %g1, 0x154, %o4	! 0xcf018d54
a00d0180:  80 8a 20 01  btst  1, %o0
a00d0184:  02 80 00 0a  be  0xa00d01ac
a00d0188:  96 10 61 dc  or  %g1, 0x1dc, %o3
a00d018c:  c2 03 00 00  ld  [ %o4 ], %g1
a00d0190:  82 10 60 02  or  %g1, 2, %g1
a00d0194:  c2 23 00 00  st  %g1, [ %o4 ]
a00d0198:  c2 02 c0 00  ld  [ %o3 ], %g1
a00d019c:  82 08 7f fe  and  %g1, -2, %g1
a00d01a0:  c2 22 c0 00  st  %g1, [ %o3 ]
a00d01a4:  10 80 00 06  b  0xa00d01bc
a00d01a8:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00d01ac:  c2 03 00 00  ld  [ %o4 ], %g1
a00d01b0:  82 08 7f fd  and  %g1, -3, %g1
a00d01b4:  c2 23 00 00  st  %g1, [ %o4 ]
a00d01b8:  1b 33 c0 63  sethi  %hi(0xcf018c00), %o5
a00d01bc:  98 13 61 54  or  %o5, 0x154, %o4	! 0xcf018d54
a00d01c0:  c2 03 00 00  ld  [ %o4 ], %g1
a00d01c4:  82 08 7f df  and  %g1, -33, %g1
a00d01c8:  c2 23 00 00  st  %g1, [ %o4 ]
a00d01cc:  98 13 61 00  or  %o5, 0x100, %o4
a00d01d0:  c2 03 00 00  ld  [ %o4 ], %g1
a00d01d4:  82 08 7f fc  and  %g1, -4, %g1
a00d01d8:  c2 23 00 00  st  %g1, [ %o4 ]
a00d01dc:  9a 13 62 50  or  %o5, 0x250, %o5
a00d01e0:  c2 03 40 00  ld  [ %o5 ], %g1
a00d01e4:  82 08 7f ee  and  %g1, -18, %g1
a00d01e8:  c2 23 40 00  st  %g1, [ %o5 ]
a00d01ec:  81 c7 e0 08  ret
a00d01f0:  81 e8 00 00  restore
