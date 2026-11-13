# leon2s FUN_a00cc1d4 0xa00cc1d4-0xa00cc2f8 (292 bytes)
a00cc1d4:  9d e3 bf 98  save  %sp, -104, %sp
a00cc1d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cc1dc:  82 06 00 18  add  %i0, %i0, %g1
a00cc1e0:  82 00 40 18  add  %g1, %i0, %g1
a00cc1e4:  a1 28 60 03  sll  %g1, 3, %l0
a00cc1e8:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00cc1ec:  29 2a 01 e2  sethi  %hi(0xa8078800), %l4
a00cc1f0:  a2 15 23 b0  or  %l4, 0x3b0, %l1	! 0xa8078bb0
a00cc1f4:  a4 10 63 ff  or  %g1, 0x3ff, %l2
a00cc1f8:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cc1fc:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cc200:  82 08 40 12  and  %g1, %l2, %g1
a00cc204:  82 10 40 0d  or  %g1, %o5, %g1
a00cc208:  27 2a 01 f4  sethi  %hi(0xa807d000), %l3
a00cc20c:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cc210:  90 10 00 18  mov  %i0, %o0
a00cc214:  7f ff f5 61  call  0xa00c9798
a00cc218:  92 14 e2 50  or  %l3, 0x250, %o1
a00cc21c:  80 8a 20 ff  btst  0xff, %o0
a00cc220:  32 80 00 08  bne,a   0xa00cc240
a00cc224:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cc228:  82 14 e2 50  or  %l3, 0x250, %g1
a00cc22c:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a00cc230:  80 88 60 08  btst  8, %g1
a00cc234:  02 80 00 06  be  0xa00cc24c
a00cc238:  90 10 00 18  mov  %i0, %o0
a00cc23c:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cc240:  82 08 40 12  and  %g1, %l2, %g1
a00cc244:  10 80 00 2b  b  0xa00cc2f0
a00cc248:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00cc24c:  92 10 20 0c  mov  0xc, %o1
a00cc250:  7f ff f1 66  call  0xa00c87e8
a00cc254:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cc258:  a2 10 20 00  clr  %l1
a00cc25c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cc260:  27 2a 01 f4  sethi  %hi(0xa807d000), %l3
a00cc264:  90 10 00 18  mov  %i0, %o0
a00cc268:  7f ff ed 42  call  0xa00c7770
a00cc26c:  92 10 20 12  mov  0x12, %o1
a00cc270:  a4 14 e0 88  or  %l3, 0x88, %l2
a00cc274:  a2 04 60 01  inc  %l1
a00cc278:  a0 04 00 12  add  %l0, %l2, %l0
a00cc27c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cc280:  80 a0 60 0f  cmp  %g1, 0xf
a00cc284:  08 bf ff f6  bleu  0xa00cc25c
a00cc288:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00cc28c:  82 10 20 0f  mov  0xf, %g1
a00cc290:  c2 2c e0 88  stb  %g1, [ %l3 + 0x88 ]
a00cc294:  98 10 20 11  mov  0x11, %o4
a00cc298:  92 10 00 12  mov  %l2, %o1
a00cc29c:  90 10 00 18  mov  %i0, %o0
a00cc2a0:  94 10 20 74  mov  0x74, %o2
a00cc2a4:  7f ff ef 93  call  0xa00c80f0
a00cc2a8:  96 10 20 60  mov  0x60, %o3
a00cc2ac:  82 06 00 18  add  %i0, %i0, %g1
a00cc2b0:  82 00 40 18  add  %g1, %i0, %g1
a00cc2b4:  91 28 60 03  sll  %g1, 3, %o0
a00cc2b8:  98 15 23 b0  or  %l4, 0x3b0, %o4
a00cc2bc:  9a 02 00 0c  add  %o0, %o4, %o5
a00cc2c0:  c2 03 60 10  ld  [ %o5 + 0x10 ], %g1
a00cc2c4:  82 00 60 01  inc  %g1
a00cc2c8:  c2 23 60 10  st  %g1, [ %o5 + 0x10 ]
a00cc2cc:  da 03 00 08  ld  [ %o4 + %o0 ], %o5
a00cc2d0:  83 33 60 15  srl  %o5, 0x15, %g1
a00cc2d4:  80 88 60 01  btst  1, %g1
a00cc2d8:  02 80 00 06  be  0xa00cc2f0
a00cc2dc:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cc2e0:  82 2b 40 01  andn  %o5, %g1, %g1
a00cc2e4:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cc2e8:  82 10 40 0d  or  %g1, %o5, %g1
a00cc2ec:  c2 23 00 08  st  %g1, [ %o4 + %o0 ]
a00cc2f0:  81 c7 e0 08  ret
a00cc2f4:  81 e8 00 00  restore
