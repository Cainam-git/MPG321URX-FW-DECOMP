# leon2m FUN_a013a0d4 0xa013a0d4-0xa013a1a4 (208 bytes)
a013a0d4:  9d e3 bf 90  save  %sp, -112, %sp
a013a0d8:  b1 2e 20 10  sll  %i0, 0x10, %i0
a013a0dc:  95 36 20 10  srl  %i0, 0x10, %o2
a013a0e0:  92 0a a0 03  and  %o2, 3, %o1
a013a0e4:  91 2a 60 0e  sll  %o1, 0xe, %o0
a013a0e8:  9a 10 3f ff  mov  -1, %o5
a013a0ec:  b2 16 40 08  or  %i1, %o0, %i1
a013a0f0:  da 27 bf f4  st  %o5, [ %fp + -12 ]
a013a0f4:  90 10 20 02  mov  2, %o0
a013a0f8:  92 10 20 20  mov  0x20, %o1
a013a0fc:  94 07 bf f4  add  %fp, -12, %o2
a013a100:  67 fd 48 f4  call  0x4008c4d0
a013a104:  96 10 20 01  mov  1, %o3
a013a108:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013a10c:  b1 36 20 12  srl  %i0, 0x12, %i0
a013a110:  80 a0 60 00  cmp  %g1, 0
a013a114:  02 80 00 10  be  0xa013a154
a013a118:  a0 10 20 64  mov  0x64, %l0
a013a11c:  67 fd 4c 21  call  0x4008d1a0
a013a120:  90 10 20 01  mov  1, %o0
a013a124:  90 10 20 02  mov  2, %o0
a013a128:  92 10 20 20  mov  0x20, %o1
a013a12c:  94 07 bf f4  add  %fp, -12, %o2
a013a130:  67 fd 48 e8  call  0x4008c4d0
a013a134:  96 10 20 01  mov  1, %o3
a013a138:  a0 04 3f ff  add  %l0, -1, %l0
a013a13c:  80 a4 20 00  cmp  %l0, 0
a013a140:  02 80 00 13  be  0xa013a18c
a013a144:  d6 07 bf f4  ld  [ %fp + -12 ], %o3
a013a148:  80 a2 e0 00  cmp  %o3, 0
a013a14c:  12 bf ff f4  bne  0xa013a11c
a013a150:  01 00 00 00  nop
a013a154:  90 0e 20 ff  and  %i0, 0xff, %o0
a013a158:  83 2a 20 10  sll  %o0, 0x10, %g1
a013a15c:  b1 2e 60 10  sll  %i1, 0x10, %i0
a013a160:  1b 0e 40 00  sethi  %hi(0x39000000), %o5
a013a164:  a0 10 40 0d  or  %g1, %o5, %l0
a013a168:  b3 36 20 10  srl  %i0, 0x10, %i1
a013a16c:  9e 14 00 19  or  %l0, %i1, %o7
a013a170:  de 27 bf f4  st  %o7, [ %fp + -12 ]
a013a174:  90 10 20 02  mov  2, %o0
a013a178:  92 10 20 20  mov  0x20, %o1
a013a17c:  94 07 bf f4  add  %fp, -12, %o2
a013a180:  67 fd 49 1e  call  0x4008c5f8
a013a184:  96 10 20 01  mov  1, %o3
a013a188:  30 80 00 05  b,a   0xa013a19c
a013a18c:  d8 07 bf f4  ld  [ %fp + -12 ], %o4
a013a190:  80 a3 20 00  cmp  %o4, 0
a013a194:  02 bf ff f1  be  0xa013a158
a013a198:  90 0e 20 ff  and  %i0, 0xff, %o0
a013a19c:  81 c7 e0 08  ret
a013a1a0:  81 e8 00 00  restore
