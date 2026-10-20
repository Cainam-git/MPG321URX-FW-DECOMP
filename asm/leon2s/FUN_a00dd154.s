# leon2s FUN_a00dd154 0xa00dd154-0xa00dd37c (552 bytes)
a00dd154:  9d e3 bf 98  save  %sp, -104, %sp
a00dd158:  27 2a 01 e5  sethi  %hi(0xa8079400), %l3
a00dd15c:  82 14 e1 38  or  %l3, 0x138, %g1	! 0xa8079538
a00dd160:  11 27 c7 3b  sethi  %hi(0x9f1cec00), %o0
a00dd164:  e0 08 60 07  ldub  [ %g1 + 7 ], %l0
a00dd168:  d2 08 60 04  ldub  [ %g1 + 4 ], %o1
a00dd16c:  40 3a 97 b6  call  0xa0f83044
a00dd170:  90 12 20 a0  or  %o0, 0xa0, %o0
a00dd174:  80 a0 00 10  cmp  %g0, %l0
a00dd178:  98 60 3f ff  subx  %g0, -1, %o4
a00dd17c:  82 1c 20 03  xor  %l0, 3, %g1
a00dd180:  80 a0 00 01  cmp  %g0, %g1
a00dd184:  03 30 04 40  sethi  %hi(0xc0110000), %g1
a00dd188:  82 10 60 04  or  %g1, 4, %g1	! 0xc0110004
a00dd18c:  da 00 40 00  ld  [ %g1 ], %o5
a00dd190:  82 60 3f ff  subx  %g0, -1, %g1
a00dd194:  9b 33 60 10  srl  %o5, 0x10, %o5
a00dd198:  80 93 00 01  orcc  %o4, %g1, %g0
a00dd19c:  82 0b 63 ff  and  %o5, 0x3ff, %g1
a00dd1a0:  a4 10 20 00  clr  %l2
a00dd1a4:  12 80 00 05  bne  0xa00dd1b8
a00dd1a8:  a8 10 20 01  mov  1, %l4
a00dd1ac:  80 a4 20 04  cmp  %l0, 4
a00dd1b0:  12 80 00 0c  bne  0xa00dd1e0
a00dd1b4:  80 a4 20 01  cmp  %l0, 1
a00dd1b8:  9b 30 60 04  srl  %g1, 4, %o5
a00dd1bc:  82 10 20 18  mov  0x18, %g1
a00dd1c0:  97 38 60 1f  sra  %g1, 0x1f, %o3
a00dd1c4:  81 82 e0 00  mov  %o3, %y
a00dd1c8:  01 00 00 00  nop
a00dd1cc:  01 00 00 00  nop
a00dd1d0:  01 00 00 00  nop
a00dd1d4:  a2 78 40 0d  sdiv  %g1, %o5, %l1
a00dd1d8:  10 80 00 15  b  0xa00dd22c
a00dd1dc:  82 0e 20 ff  and  %i0, 0xff, %g1
a00dd1e0:  12 80 00 05  bne  0xa00dd1f4
a00dd1e4:  83 28 60 10  sll  %g1, 0x10, %g1
a00dd1e8:  83 30 60 15  srl  %g1, 0x15, %g1
a00dd1ec:  10 80 00 04  b  0xa00dd1fc
a00dd1f0:  9a 10 20 10  mov  0x10, %o5
a00dd1f4:  83 30 60 15  srl  %g1, 0x15, %g1
a00dd1f8:  9a 10 20 0c  mov  0xc, %o5
a00dd1fc:  97 3b 60 1f  sra  %o5, 0x1f, %o3
a00dd200:  81 82 e0 00  mov  %o3, %y
a00dd204:  01 00 00 00  nop
a00dd208:  01 00 00 00  nop
a00dd20c:  01 00 00 00  nop
a00dd210:  98 7b 40 01  sdiv  %o5, %g1, %o4
a00dd214:  82 5b 00 01  smul  %o4, %g1, %g1
a00dd218:  80 a3 40 01  cmp  %o5, %g1
a00dd21c:  02 80 00 03  be  0xa00dd228
a00dd220:  a2 10 00 0c  mov  %o4, %l1
a00dd224:  a2 03 20 01  add  %o4, 1, %l1
a00dd228:  82 0e 20 ff  and  %i0, 0xff, %g1
a00dd22c:  80 a0 60 01  cmp  %g1, 1
a00dd230:  28 80 00 12  bleu,a   0xa00dd278
a00dd234:  a4 10 20 02  mov  2, %l2
a00dd238:  92 10 20 03  mov  3, %o1
a00dd23c:  40 3b 69 9e  call  0xa0fb78b4
a00dd240:  90 10 20 00  clr  %o0
a00dd244:  a0 0a 20 0f  and  %o0, 0xf, %l0
a00dd248:  40 3a f3 01  call  0xa0f99e4c
a00dd24c:  90 10 20 00  clr  %o0
a00dd250:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dd254:  80 a2 20 01  cmp  %o0, 1
a00dd258:  32 80 00 04  bne,a   0xa00dd268
a00dd25c:  90 0c 20 ff  and  %l0, 0xff, %o0
a00dd260:  10 80 00 06  b  0xa00dd278
a00dd264:  a4 10 20 04  mov  4, %l2
a00dd268:  80 a2 20 04  cmp  %o0, 4
a00dd26c:  12 80 00 05  bne  0xa00dd280
a00dd270:  80 a2 20 02  cmp  %o0, 2
a00dd274:  a4 10 20 02  mov  2, %l2
a00dd278:  10 80 00 0a  b  0xa00dd2a0
a00dd27c:  a8 10 20 01  mov  1, %l4
a00dd280:  12 80 00 04  bne  0xa00dd290
a00dd284:  80 a2 20 01  cmp  %o0, 1
a00dd288:  10 80 00 05  b  0xa00dd29c
a00dd28c:  a4 10 20 04  mov  4, %l2
a00dd290:  12 80 00 05  bne  0xa00dd2a4
a00dd294:  82 14 e1 38  or  %l3, 0x138, %g1
a00dd298:  a4 10 20 02  mov  2, %l2
a00dd29c:  a8 10 20 03  mov  3, %l4
a00dd2a0:  82 14 e1 38  or  %l3, 0x138, %g1
a00dd2a4:  d8 00 60 20  ld  [ %g1 + 0x20 ], %o4
a00dd2a8:  82 0b 20 03  and  %o4, 3, %g1
a00dd2ac:  80 8b 20 80  btst  0x80, %o4
a00dd2b0:  02 80 00 03  be  0xa00dd2bc
a00dd2b4:  96 10 00 01  mov  %g1, %o3
a00dd2b8:  96 00 60 01  add  %g1, 1, %o3
a00dd2bc:  83 33 20 10  srl  %o4, 0x10, %g1
a00dd2c0:  9b 33 20 08  srl  %o4, 8, %o5
a00dd2c4:  82 08 60 ff  and  %g1, 0xff, %g1
a00dd2c8:  83 28 60 08  sll  %g1, 8, %g1
a00dd2cc:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00dd2d0:  99 33 20 18  srl  %o4, 0x18, %o4
a00dd2d4:  9a 03 40 01  add  %o5, %g1, %o5
a00dd2d8:  99 2b 20 10  sll  %o4, 0x10, %o4
a00dd2dc:  94 03 40 0c  add  %o5, %o4, %o2
a00dd2e0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00dd2e4:  9b 2a 80 0d  sll  %o2, %o5, %o5
a00dd2e8:  94 0c 60 ff  and  %l1, 0xff, %o2
a00dd2ec:  98 0d 20 ff  and  %l4, 0xff, %o4
a00dd2f0:  82 0c a0 ff  and  %l2, 0xff, %g1
a00dd2f4:  17 33 c0 50  sethi  %hi(0xcf014000), %o3
a00dd2f8:  82 58 40 0c  smul  %g1, %o4, %g1
a00dd2fc:  81 80 00 00  mov  %g0, %y
a00dd300:  01 00 00 00  nop
a00dd304:  01 00 00 00  nop
a00dd308:  01 00 00 00  nop
a00dd30c:  9a 73 40 0a  udiv  %o5, %o2, %o5
a00dd310:  98 12 e1 00  or  %o3, 0x100, %o4
a00dd314:  81 80 00 00  mov  %g0, %y
a00dd318:  01 00 00 00  nop
a00dd31c:  01 00 00 00  nop
a00dd320:  01 00 00 00  nop
a00dd324:  9a 73 40 01  udiv  %o5, %g1, %o5
a00dd328:  c2 03 00 00  ld  [ %o4 ], %g1
a00dd32c:  82 08 7f 7f  and  %g1, -129, %g1
a00dd330:  c2 23 00 00  st  %g1, [ %o4 ]
a00dd334:  95 33 60 01  srl  %o5, 1, %o2
a00dd338:  82 12 e1 04  or  %o3, 0x104, %g1
a00dd33c:  94 0a a0 ff  and  %o2, 0xff, %o2
a00dd340:  d4 20 40 00  st  %o2, [ %g1 ]
a00dd344:  99 33 60 09  srl  %o5, 9, %o4
a00dd348:  82 12 e1 08  or  %o3, 0x108, %g1
a00dd34c:  98 0b 20 ff  and  %o4, 0xff, %o4
a00dd350:  d8 20 40 00  st  %o4, [ %g1 ]
a00dd354:  9b 33 60 11  srl  %o5, 0x11, %o5
a00dd358:  82 12 e1 0c  or  %o3, 0x10c, %g1
a00dd35c:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00dd360:  da 20 40 00  st  %o5, [ %g1 ]
a00dd364:  96 12 e1 14  or  %o3, 0x114, %o3
a00dd368:  c2 02 c0 00  ld  [ %o3 ], %g1
a00dd36c:  82 10 60 80  or  %g1, 0x80, %g1
a00dd370:  c2 22 c0 00  st  %g1, [ %o3 ]
a00dd374:  81 c7 e0 08  ret
a00dd378:  81 e8 00 00  restore
