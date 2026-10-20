# leon2m FUN_a00fd074 0xa00fd074-0xa00fd298 (548 bytes)
a00fd074:  9d e3 bf 98  save  %sp, -104, %sp
a00fd078:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fd07c:  90 13 20 84  or  %o4, 0x84, %o0	! 0xcf012084
a00fd080:  92 10 20 44  mov  0x44, %o1
a00fd084:  d2 22 00 00  st  %o1, [ %o0 ]
a00fd088:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a00fd08c:  d0 08 61 7d  ldub  [ %g1 + 0x17d ], %o0	! 0xa802c97d
a00fd090:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00fd094:  9a 13 20 88  or  %o4, 0x88, %o5
a00fd098:  f0 23 40 00  st  %i0, [ %o5 ]
a00fd09c:  80 a2 20 0f  cmp  %o0, 0xf
a00fd0a0:  02 80 00 27  be  0xa00fd13c
a00fd0a4:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a00fd0a8:  d6 04 61 70  ld  [ %l1 + 0x170 ], %o3	! 0xa802c970
a00fd0ac:  9e 13 20 34  or  %o4, 0x34, %o7
a00fd0b0:  a0 10 20 2e  mov  0x2e, %l0
a00fd0b4:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fd0b8:  80 a2 e0 00  cmp  %o3, 0
a00fd0bc:  12 80 00 1d  bne  0xa00fd130
a00fd0c0:  b0 13 20 80  or  %o4, 0x80, %i0
a00fd0c4:  9a 13 20 40  or  %o4, 0x40, %o5
a00fd0c8:  d0 26 00 00  st  %o0, [ %i0 ]
a00fd0cc:  98 10 20 02  mov  2, %o4
a00fd0d0:  d8 23 40 00  st  %o4, [ %o5 ]
a00fd0d4:  67 fe 41 2d  call  0x4008d588
a00fd0d8:  01 00 00 00  nop
a00fd0dc:  03 33 c0 48  sethi  %hi(0xcf012000), %g1
a00fd0e0:  82 10 60 34  or  %g1, 0x34, %g1	! 0xcf012034
a00fd0e4:  d6 00 40 00  ld  [ %g1 ], %o3
a00fd0e8:  80 8a e0 2e  btst  0x2e, %o3
a00fd0ec:  12 80 00 64  bne  0xa00fd27c
a00fd0f0:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00fd0f4:  a0 10 00 01  mov  %g1, %l0
a00fd0f8:  67 fe 3f 78  call  0x4008ced8
a00fd0fc:  01 00 00 00  nop
a00fd100:  67 fe 41 25  call  0x4008d594
a00fd104:  91 36 20 10  srl  %i0, 0x10, %o0
a00fd108:  93 2a 20 10  sll  %o0, 0x10, %o1
a00fd10c:  91 32 60 10  srl  %o1, 0x10, %o0
a00fd110:  80 a2 23 e8  cmp  %o0, 0x3e8
a00fd114:  18 80 00 5b  bgu  0xa00fd280
a00fd118:  23 33 c0 48  sethi  %hi(0xcf012000), %l1
a00fd11c:  d4 04 00 00  ld  [ %l0 ], %o2
a00fd120:  80 8a a0 2e  btst  0x2e, %o2
a00fd124:  02 bf ff f5  be  0xa00fd0f8
a00fd128:  9e 14 60 34  or  %l1, 0x34, %o7
a00fd12c:  30 80 00 56  b,a   0xa00fd284
a00fd130:  9f c2 c0 00  call  %o3
a00fd134:  92 10 20 02  mov  2, %o1
a00fd138:  30 bf ff e7  b,a   0xa00fd0d4
a00fd13c:  94 13 20 34  or  %o4, 0x34, %o2
a00fd140:  d6 04 61 70  ld  [ %l1 + 0x170 ], %o3
a00fd144:  9e 10 20 2e  mov  0x2e, %o7
a00fd148:  de 22 80 00  st  %o7, [ %o2 ]
a00fd14c:  80 a2 e0 00  cmp  %o3, 0
a00fd150:  12 80 00 43  bne  0xa00fd25c
a00fd154:  a0 13 20 80  or  %o4, 0x80, %l0
a00fd158:  9a 10 20 08  mov  8, %o5
a00fd15c:  da 24 00 00  st  %o5, [ %l0 ]
a00fd160:  98 13 20 40  or  %o4, 0x40, %o4
a00fd164:  96 10 20 02  mov  2, %o3
a00fd168:  d6 23 00 00  st  %o3, [ %o4 ]
a00fd16c:  67 fe 41 07  call  0x4008d588
a00fd170:  01 00 00 00  nop
a00fd174:  03 33 c0 48  sethi  %hi(0xcf012000), %g1
a00fd178:  82 10 60 34  or  %g1, 0x34, %g1	! 0xcf012034
a00fd17c:  f0 00 40 00  ld  [ %g1 ], %i0
a00fd180:  80 8e 20 2e  btst  0x2e, %i0
a00fd184:  12 80 00 10  bne  0xa00fd1c4
a00fd188:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fd18c:  b0 10 00 01  mov  %g1, %i0
a00fd190:  67 fe 3f 52  call  0x4008ced8
a00fd194:  01 00 00 00  nop
a00fd198:  67 fe 40 ff  call  0x4008d594
a00fd19c:  91 34 20 10  srl  %l0, 0x10, %o0
a00fd1a0:  93 2a 20 10  sll  %o0, 0x10, %o1
a00fd1a4:  91 32 60 10  srl  %o1, 0x10, %o0
a00fd1a8:  80 a2 23 e8  cmp  %o0, 0x3e8
a00fd1ac:  18 80 00 07  bgu  0xa00fd1c8
a00fd1b0:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fd1b4:  d4 06 00 00  ld  [ %i0 ], %o2
a00fd1b8:  80 8a a0 2e  btst  0x2e, %o2
a00fd1bc:  02 bf ff f5  be  0xa00fd190
a00fd1c0:  01 00 00 00  nop
a00fd1c4:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fd1c8:  9e 12 e0 34  or  %o3, 0x34, %o7	! 0xcf012034
a00fd1cc:  d8 03 c0 00  ld  [ %o7 ], %o4
a00fd1d0:  a0 10 20 2e  mov  0x2e, %l0
a00fd1d4:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fd1d8:  d8 04 61 70  ld  [ %l1 + 0x170 ], %o4
a00fd1dc:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fd1e0:  80 a3 20 00  cmp  %o4, 0
a00fd1e4:  12 80 00 22  bne  0xa00fd26c
a00fd1e8:  9a 12 e0 80  or  %o3, 0x80, %o5
a00fd1ec:  b0 10 20 04  mov  4, %i0
a00fd1f0:  f0 23 40 00  st  %i0, [ %o5 ]
a00fd1f4:  a2 12 e0 40  or  %o3, 0x40, %l1
a00fd1f8:  98 10 20 02  mov  2, %o4
a00fd1fc:  d8 24 40 00  st  %o4, [ %l1 ]
a00fd200:  67 fe 40 e2  call  0x4008d588
a00fd204:  01 00 00 00  nop
a00fd208:  03 33 c0 48  sethi  %hi(0xcf012000), %g1
a00fd20c:  82 10 60 34  or  %g1, 0x34, %g1	! 0xcf012034
a00fd210:  d6 00 40 00  ld  [ %g1 ], %o3
a00fd214:  80 8a e0 2e  btst  0x2e, %o3
a00fd218:  12 80 00 19  bne  0xa00fd27c
a00fd21c:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fd220:  b0 10 00 01  mov  %g1, %i0
a00fd224:  67 fe 3f 2d  call  0x4008ced8
a00fd228:  01 00 00 00  nop
a00fd22c:  67 fe 40 da  call  0x4008d594
a00fd230:  91 34 20 10  srl  %l0, 0x10, %o0
a00fd234:  93 2a 20 10  sll  %o0, 0x10, %o1
a00fd238:  91 32 60 10  srl  %o1, 0x10, %o0
a00fd23c:  80 a2 23 e8  cmp  %o0, 0x3e8
a00fd240:  18 80 00 10  bgu  0xa00fd280
a00fd244:  23 33 c0 48  sethi  %hi(0xcf012000), %l1
a00fd248:  d4 06 00 00  ld  [ %i0 ], %o2
a00fd24c:  80 8a a0 2e  btst  0x2e, %o2
a00fd250:  02 bf ff f5  be  0xa00fd224
a00fd254:  9e 14 60 34  or  %l1, 0x34, %o7
a00fd258:  30 80 00 0b  b,a   0xa00fd284
a00fd25c:  90 10 20 08  mov  8, %o0
a00fd260:  9f c2 c0 00  call  %o3
a00fd264:  92 10 20 02  mov  2, %o1
a00fd268:  30 bf ff c1  b,a   0xa00fd16c
a00fd26c:  90 10 20 04  mov  4, %o0
a00fd270:  9f c3 00 00  call  %o4
a00fd274:  92 10 20 02  mov  2, %o1
a00fd278:  30 bf ff e2  b,a   0xa00fd200
a00fd27c:  23 33 c0 48  sethi  %hi(0xcf012000), %l1
a00fd280:  9e 14 60 34  or  %l1, 0x34, %o7	! 0xcf012034
a00fd284:  d8 03 c0 00  ld  [ %o7 ], %o4
a00fd288:  a0 10 20 2e  mov  0x2e, %l0
a00fd28c:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fd290:  81 c7 e0 08  ret
a00fd294:  81 e8 00 00  restore
