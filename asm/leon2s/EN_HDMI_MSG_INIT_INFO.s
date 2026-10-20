# leon2s EN_HDMI_MSG_INIT_INFO 0xa00a317c-0xa00a3250 (212 bytes)
a00a317c:  9d e3 bf 98  save  %sp, -104, %sp
a00a3180:  da 06 00 00  ld  [ %i0 ], %o5
a00a3184:  80 a3 60 0f  cmp  %o5, 0xf
a00a3188:  08 80 00 05  bleu  0xa00a319c
a00a318c:  01 00 00 00  nop
a00a3190:  31 28 01 ae  sethi  %hi(0xa006b800), %i0
a00a3194:  7f ff 40 cc  call  0xa00734c4
a00a3198:  91 ee 21 40  restore  %i0, 0x140, %o0
a00a319c:  32 80 00 09  bne,a   0xa00a31c0
a00a31a0:  f0 0e 20 04  ldub  [ %i0 + 4 ], %i0
a00a31a4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a31a8:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a31ac:  c0 20 62 34  clr  [ %g1 + 0x234 ]
a00a31b0:  7f ff 40 c5  call  0xa00734c4
a00a31b4:  90 12 21 60  or  %o0, 0x160, %o0
a00a31b8:  10 80 00 0f  b  0xa00a31f4
a00a31bc:  b0 10 20 00  clr  %i0
a00a31c0:  80 a6 20 01  cmp  %i0, 1
a00a31c4:  12 80 00 06  bne  0xa00a31dc
a00a31c8:  19 2a 01 e1  sethi  %hi(0xa8078400), %o4
a00a31cc:  9b 2e 00 0d  sll  %i0, %o5, %o5
a00a31d0:  c2 03 22 34  ld  [ %o4 + 0x234 ], %g1
a00a31d4:  10 80 00 06  b  0xa00a31ec
a00a31d8:  82 10 40 0d  or  %g1, %o5, %g1
a00a31dc:  82 10 20 01  mov  1, %g1
a00a31e0:  83 28 40 0d  sll  %g1, %o5, %g1
a00a31e4:  da 03 22 34  ld  [ %o4 + 0x234 ], %o5
a00a31e8:  82 2b 40 01  andn  %o5, %g1, %g1
a00a31ec:  c2 23 22 34  st  %g1, [ %o4 + 0x234 ]
a00a31f0:  b0 10 20 00  clr  %i0
a00a31f4:  82 10 20 01  mov  1, %g1
a00a31f8:  1b 2a 01 e1  sethi  %hi(0xa8078400), %o5
a00a31fc:  83 28 40 18  sll  %g1, %i0, %g1
a00a3200:  da 03 62 34  ld  [ %o5 + 0x234 ], %o5
a00a3204:  80 8b 40 01  btst  %o5, %g1
a00a3208:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a320c:  03 28 01 ae  sethi  %hi(0xa006b800), %g1
a00a3210:  9b 2e 20 02  sll  %i0, 2, %o5
a00a3214:  90 12 21 80  or  %o0, 0x180, %o0
a00a3218:  94 10 61 90  or  %g1, 0x190, %o2
a00a321c:  12 80 00 04  bne  0xa00a322c
a00a3220:  b0 06 20 01  inc  %i0
a00a3224:  03 28 01 ae  sethi  %hi(0xa006b800), %g1
a00a3228:  94 10 61 98  or  %g1, 0x198, %o2	! 0xa006b998
a00a322c:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a3230:  82 10 60 80  or  %g1, 0x80, %g1	! 0xa00b4c80
a00a3234:  7f ff 3f 84  call  0xa0073044
a00a3238:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a00a323c:  80 a6 20 0e  cmp  %i0, 0xe
a00a3240:  08 bf ff ee  bleu  0xa00a31f8
a00a3244:  82 10 20 01  mov  1, %g1
a00a3248:  81 c7 e0 08  ret
a00a324c:  81 e8 00 00  restore
