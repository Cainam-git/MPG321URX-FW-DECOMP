# leon2s DRV_HDMI_Init_Timer 0xa009c188-0xa009c284 (252 bytes)  [FUN_a009c27c = unreachable ret/restore tail, merged]
a009c188:  9d e3 bf 98  save  %sp, -104, %sp
a009c18c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009c190:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009c194:  80 88 60 04  btst  4, %g1
a009c198:  02 80 00 09  be  0xa009c1bc
a009c19c:  80 a6 20 14  cmp  %i0, 0x14
a009c1a0:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009c1a4:  13 28 02 d1  sethi  %hi(0xa00b4400), %o1
a009c1a8:  90 12 22 30  or  %o0, 0x230, %o0
a009c1ac:  92 12 60 38  or  %o1, 0x38, %o1
a009c1b0:  7f ff 5b a5  call  0xa0073044
a009c1b4:  94 10 00 18  mov  %i0, %o2
a009c1b8:  80 a6 20 14  cmp  %i0, 0x14
a009c1bc:  02 80 00 12  be  0xa009c204
a009c1c0:  80 a6 20 14  cmp  %i0, 0x14
a009c1c4:  18 80 00 06  bgu  0xa009c1dc
a009c1c8:  80 a6 20 15  cmp  %i0, 0x15
a009c1cc:  80 a6 20 01  cmp  %i0, 1
a009c1d0:  02 80 00 06  be  0xa009c1e8
a009c1d4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009c1d8:  30 80 00 28  b,a   0xa009c278
a009c1dc:  02 80 00 14  be  0xa009c22c
a009c1e0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009c1e4:  30 80 00 25  b,a   0xa009c278
a009c1e8:  d8 08 60 38  ldub  [ %g1 + 0x38 ], %o4	! 0xa8079038
a009c1ec:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a009c1f0:  03 28 02 72  sethi  %hi(0xa009c800), %g1
a009c1f4:  b0 13 60 f4  or  %o5, 0xf4, %i0
a009c1f8:  c0 23 60 f4  clr  [ %o5 + 0xf4 ]
a009c1fc:  10 80 00 09  b  0xa009c220
a009c200:  82 10 61 b4  or  %g1, 0x1b4, %g1
a009c204:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009c208:  d8 08 60 38  ldub  [ %g1 + 0x38 ], %o4	! 0xa8079038
a009c20c:  1b 2a 01 e4  sethi  %hi(0xa8079000), %o5
a009c210:  03 28 02 69  sethi  %hi(0xa009a400), %g1
a009c214:  b0 13 61 00  or  %o5, 0x100, %i0
a009c218:  c0 23 61 00  clr  [ %o5 + 0x100 ]
a009c21c:  82 10 60 1c  or  %g1, 0x1c, %g1
a009c220:  c2 26 20 08  st  %g1, [ %i0 + 8 ]
a009c224:  10 80 00 13  b  0xa009c270
a009c228:  d8 26 20 04  st  %o4, [ %i0 + 4 ]
a009c22c:  90 10 60 f4  or  %g1, 0xf4, %o0
a009c230:  c0 20 60 f4  clr  [ %g1 + 0xf4 ]
a009c234:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a009c238:  03 28 02 72  sethi  %hi(0xa009c800), %g1
a009c23c:  da 0c 20 38  ldub  [ %l0 + 0x38 ], %o5
a009c240:  82 10 61 b4  or  %g1, 0x1b4, %g1
a009c244:  c2 22 20 08  st  %g1, [ %o0 + 8 ]
a009c248:  40 00 57 a5  call  0xa00b20dc
a009c24c:  da 22 20 04  st  %o5, [ %o0 + 4 ]
a009c250:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009c254:  b0 10 61 00  or  %g1, 0x100, %i0	! 0xa8079100
a009c258:  c0 20 61 00  clr  [ %g1 + 0x100 ]
a009c25c:  03 28 02 69  sethi  %hi(0xa009a400), %g1
a009c260:  da 0c 20 38  ldub  [ %l0 + 0x38 ], %o5
a009c264:  82 10 60 1c  or  %g1, 0x1c, %g1
a009c268:  c2 26 20 08  st  %g1, [ %i0 + 8 ]
a009c26c:  da 26 20 04  st  %o5, [ %i0 + 4 ]
a009c270:  40 00 57 9b  call  0xa00b20dc
a009c274:  81 e8 00 00  restore
a009c278:  01 00 00 00  nop
a009c27c:  81 c7 e0 08  ret
a009c280:  81 e8 00 00  restore
