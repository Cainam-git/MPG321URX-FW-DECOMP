# leon2m FUN_a012c188 0xa012c188-0xa012c320 (408 bytes)
a012c188:  9d e3 bf 98  save  %sp, -104, %sp
a012c18c:  a2 10 20 00  clr  %l1
a012c190:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a012c194:  a6 10 20 0f  mov  0xf, %l3
a012c198:  aa 0c 60 ff  and  %l1, 0xff, %l5
a012c19c:  7f ff e5 01  call  0xa01255a0
a012c1a0:  90 10 00 15  mov  %l5, %o0
a012c1a4:  98 04 60 01  add  %l1, 1, %o4
a012c1a8:  a1 2d 60 02  sll  %l5, 2, %l0
a012c1ac:  a9 2a 20 10  sll  %o0, 0x10, %l4
a012c1b0:  e2 04 a3 08  ld  [ %l2 + 0x308 ], %l1
a012c1b4:  97 35 20 17  srl  %l4, 0x17, %o3
a012c1b8:  9f 2c c0 10  sll  %l3, %l0, %o7
a012c1bc:  82 2c 40 0f  andn  %l1, %o7, %g1
a012c1c0:  95 2a c0 10  sll  %o3, %l0, %o2
a012c1c4:  93 2b 20 10  sll  %o4, 0x10, %o1
a012c1c8:  90 12 80 01  or  %o2, %g1, %o0
a012c1cc:  9b 32 60 10  srl  %o1, 0x10, %o5
a012c1d0:  d0 24 a3 08  st  %o0, [ %l2 + 0x308 ]
a012c1d4:  80 a3 60 06  cmp  %o5, 6
a012c1d8:  08 bf ff f0  bleu  0xa012c198
a012c1dc:  a2 10 00 0c  mov  %o4, %l1
a012c1e0:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a012c1e4:  c2 04 a0 48  ld  [ %l2 + 0x48 ], %g1	! 0xa802cc48
a012c1e8:  80 a0 60 00  cmp  %g1, 0
a012c1ec:  12 80 00 3b  bne  0xa012c2d8
a012c1f0:  2f 2a 00 b3  sethi  %hi(0xa802cc00), %l7
a012c1f4:  2d 2a 00 b8  sethi  %hi(0xa802e000), %l6
a012c1f8:  27 00 06 9a  sethi  %hi(0x1a6800), %l3
a012c1fc:  ba 15 e0 10  or  %l7, 0x10, %i5
a012c200:  b8 15 a1 a0  or  %l6, 0x1a0, %i4
a012c204:  b6 14 e2 d8  or  %l3, 0x2d8, %i3
a012c208:  10 80 00 0a  b  0xa012c230
a012c20c:  a4 10 20 00  clr  %l2
a012c210:  40 00 1f 5d  call  0xa0133f84
a012c214:  90 08 60 ff  and  %g1, 0xff, %o0
a012c218:  a8 04 a0 01  add  %l2, 1, %l4
a012c21c:  a5 2d 20 10  sll  %l4, 0x10, %l2
a012c220:  ab 34 a0 10  srl  %l2, 0x10, %l5
a012c224:  80 a5 60 06  cmp  %l5, 6
a012c228:  18 80 00 3c  bgu  0xa012c318
a012c22c:  a4 10 00 14  mov  %l4, %l2
a012c230:  a2 0c a0 ff  and  %l2, 0xff, %l1
a012c234:  7f ff e4 4e  call  0xa012536c
a012c238:  90 10 00 11  mov  %l1, %o0
a012c23c:  a6 0a 20 ff  and  %o0, 0xff, %l3
a012c240:  98 10 20 01  mov  1, %o4
a012c244:  90 10 00 11  mov  %l1, %o0
a012c248:  80 a4 e0 01  cmp  %l3, 1
a012c24c:  12 bf ff f1  bne  0xa012c210
a012c250:  83 2b 00 12  sll  %o4, %l2, %g1
a012c254:  7f ff e4 4b  call  0xa0125380
a012c258:  01 00 00 00  nop
a012c25c:  97 2c a0 10  sll  %l2, 0x10, %o3
a012c260:  a9 32 e0 10  srl  %o3, 0x10, %l4
a012c264:  ac 05 00 1c  add  %l4, %i4, %l6
a012c268:  c2 0d a0 1b  ldub  [ %l6 + 0x1b ], %g1
a012c26c:  af 2a 20 10  sll  %o0, 0x10, %l7
a012c270:  90 00 40 01  add  %g1, %g1, %o0
a012c274:  e0 16 c0 08  lduh  [ %i3 + %o0 ], %l0
a012c278:  95 28 60 02  sll  %g1, 2, %o2
a012c27c:  ea 07 40 0a  ld  [ %i5 + %o2 ], %l5
a012c280:  7f ff e4 c8  call  0xa01255a0
a012c284:  90 10 00 11  mov  %l1, %o0
a012c288:  93 2a 20 10  sll  %o0, 0x10, %o1
a012c28c:  9b 2c 20 10  sll  %l0, 0x10, %o5
a012c290:  80 a3 40 09  cmp  %o5, %o1
a012c294:  a1 33 60 10  srl  %o5, 0x10, %l0
a012c298:  90 10 20 01  mov  1, %o0
a012c29c:  18 80 00 12  bgu  0xa012c2e4
a012c2a0:  92 10 00 10  mov  %l0, %o1
a012c2a4:  40 00 25 16  call  0xa01356fc
a012c2a8:  a3 2c c0 14  sll  %l3, %l4, %l1
a012c2ac:  94 10 00 15  mov  %l5, %o2
a012c2b0:  91 35 e0 10  srl  %l7, 0x10, %o0
a012c2b4:  40 00 29 d7  call  0xa0136a10
a012c2b8:  92 10 00 10  mov  %l0, %o1
a012c2bc:  9f 35 e0 17  srl  %l7, 0x17, %o7
a012c2c0:  90 0c 60 ff  and  %l1, 0xff, %o0
a012c2c4:  94 0b e0 ff  and  %o7, 0xff, %o2
a012c2c8:  40 00 1f 3d  call  0xa0133fbc
a012c2cc:  92 10 00 10  mov  %l0, %o1
a012c2d0:  10 bf ff d3  b  0xa012c21c
a012c2d4:  a8 04 a0 01  add  %l2, 1, %l4
a012c2d8:  9f c0 40 00  call  %g1
a012c2dc:  01 00 00 00  nop
a012c2e0:  30 80 00 0e  b,a   0xa012c318
a012c2e4:  7f ff e4 af  call  0xa01255a0
a012c2e8:  90 10 00 11  mov  %l1, %o0
a012c2ec:  b7 2a 20 10  sll  %o0, 0x10, %i3
a012c2f0:  39 00 06 93  sethi  %hi(0x1a4c00), %i4
a012c2f4:  90 17 23 08  or  %i4, 0x308, %o0	! 0x1a4f08
a012c2f8:  92 10 00 14  mov  %l4, %o1
a012c2fc:  95 36 e0 10  srl  %i3, 0x10, %o2
a012c300:  d6 0d a0 1b  ldub  [ %l6 + 0x1b ], %o3
a012c304:  7f fe cb 9b  call  0xa00df170
a012c308:  98 10 00 10  mov  %l0, %o4
a012c30c:  01 00 00 00  nop
a012c310:  01 00 00 00  nop
a012c314:  30 bf ff fe  b,a   0xa012c30c
a012c318:  81 c7 e0 08  ret
a012c31c:  81 e8 00 00  restore
