# leon2s FUN_a0075360 0xa0075360-0xa0075508 (424 bytes)
a0075360:  9d e3 bf 98  save  %sp, -104, %sp
a0075364:  b4 0e 20 ff  and  %i0, 0xff, %i2
a0075368:  82 1e a0 02  xor  %i2, 2, %g1
a007536c:  80 a0 00 01  cmp  %g0, %g1
a0075370:  9a 40 20 00  addx  %g0, 0, %o5
a0075374:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0075378:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa807d680
a007537c:  9a 5b 60 b0  smul  %o5, 0xb0, %o5
a0075380:  9a 03 40 01  add  %o5, %g1, %o5
a0075384:  37 00 00 0d  sethi  %hi(0x3400), %i3
a0075388:  e2 0b 60 02  ldub  [ %o5 + 2 ], %l1
a007538c:  90 10 00 1a  mov  %i2, %o0
a0075390:  92 16 e2 30  or  %i3, 0x230, %o1
a0075394:  94 10 3f f0  mov  -16, %o2
a0075398:  40 00 c8 3c  call  0xa00a7488
a007539c:  96 10 20 02  mov  2, %o3
a00753a0:  90 10 00 1a  mov  %i2, %o0
a00753a4:  92 16 e2 30  or  %i3, 0x230, %o1
a00753a8:  94 10 3f 8f  mov  -113, %o2
a00753ac:  40 00 c8 37  call  0xa00a7488
a00753b0:  96 10 20 10  mov  0x10, %o3
a00753b4:  90 10 00 1a  mov  %i2, %o0
a00753b8:  92 16 e2 30  or  %i3, 0x230, %o1
a00753bc:  94 10 38 ff  mov  -1793, %o2
a00753c0:  40 00 c8 32  call  0xa00a7488
a00753c4:  96 10 20 00  clr  %o3
a00753c8:  15 3f ff f1  sethi  %hi(0xffffc400), %o2
a00753cc:  90 10 00 1a  mov  %i2, %o0
a00753d0:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a00753d4:  92 16 e2 30  or  %i3, 0x230, %o1
a00753d8:  40 00 c8 2c  call  0xa00a7488
a00753dc:  96 10 20 00  clr  %o3
a00753e0:  21 3f c7 ff  sethi  %hi(0xff1ffc00), %l0
a00753e4:  90 10 00 1a  mov  %i2, %o0
a00753e8:  92 16 e2 30  or  %i3, 0x230, %o1
a00753ec:  94 14 23 ff  or  %l0, 0x3ff, %o2
a00753f0:  40 00 c8 26  call  0xa00a7488
a00753f4:  96 10 20 00  clr  %o3
a00753f8:  90 10 00 1a  mov  %i2, %o0
a00753fc:  94 14 23 ff  or  %l0, 0x3ff, %o2
a0075400:  92 16 e2 30  or  %i3, 0x230, %o1
a0075404:  40 00 c8 21  call  0xa00a7488
a0075408:  96 10 20 00  clr  %o3
a007540c:  80 a4 60 05  cmp  %l1, 5
a0075410:  08 80 00 13  bleu  0xa007545c
a0075414:  15 3f ff cf  sethi  %hi(0xffff3c00), %o2
a0075418:  94 12 a3 ff  or  %o2, 0x3ff, %o2	! 0xffff3fff
a007541c:  90 10 00 1a  mov  %i2, %o0
a0075420:  92 16 e2 30  or  %i3, 0x230, %o1
a0075424:  40 00 c8 19  call  0xa00a7488
a0075428:  17 00 00 10  sethi  %hi(0x4000), %o3
a007542c:  15 3f ff 3f  sethi  %hi(0xfffcfc00), %o2
a0075430:  90 10 00 1a  mov  %i2, %o0
a0075434:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0075438:  92 16 e2 30  or  %i3, 0x230, %o1
a007543c:  40 00 c8 13  call  0xa00a7488
a0075440:  17 00 00 40  sethi  %hi(0x10000), %o3
a0075444:  15 3f f8 ff  sethi  %hi(0xffe3fc00), %o2
a0075448:  90 10 00 1a  mov  %i2, %o0
a007544c:  92 16 e2 30  or  %i3, 0x230, %o1
a0075450:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0075454:  10 80 00 12  b  0xa007549c
a0075458:  17 00 01 00  sethi  %hi(0x40000), %o3
a007545c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0075460:  90 10 00 1a  mov  %i2, %o0
a0075464:  92 16 e2 30  or  %i3, 0x230, %o1
a0075468:  40 00 c8 08  call  0xa00a7488
a007546c:  96 10 20 00  clr  %o3
a0075470:  15 3f ff 3f  sethi  %hi(0xfffcfc00), %o2
a0075474:  90 10 00 1a  mov  %i2, %o0
a0075478:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007547c:  92 16 e2 30  or  %i3, 0x230, %o1
a0075480:  40 00 c8 02  call  0xa00a7488
a0075484:  96 10 20 00  clr  %o3
a0075488:  15 3f f8 ff  sethi  %hi(0xffe3fc00), %o2
a007548c:  90 10 00 1a  mov  %i2, %o0
a0075490:  92 16 e2 30  or  %i3, 0x230, %o1
a0075494:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0075498:  96 10 20 00  clr  %o3
a007549c:  40 00 c7 fb  call  0xa00a7488
a00754a0:  37 00 00 0d  sethi  %hi(0x3400), %i3
a00754a4:  96 16 e2 30  or  %i3, 0x230, %o3	! 0x3630
a00754a8:  90 10 20 00  clr  %o0
a00754ac:  92 10 20 1a  mov  0x1a, %o1
a00754b0:  40 00 c7 dd  call  0xa00a7424
a00754b4:  94 10 00 1a  mov  %i2, %o2
a00754b8:  96 16 e2 30  or  %i3, 0x230, %o3
a00754bc:  90 10 20 00  clr  %o0
a00754c0:  92 10 20 1b  mov  0x1b, %o1
a00754c4:  40 00 c7 d8  call  0xa00a7424
a00754c8:  94 10 00 1a  mov  %i2, %o2
a00754cc:  96 16 e2 30  or  %i3, 0x230, %o3
a00754d0:  90 10 20 00  clr  %o0
a00754d4:  92 10 20 1c  mov  0x1c, %o1
a00754d8:  40 00 c7 d3  call  0xa00a7424
a00754dc:  94 10 00 1a  mov  %i2, %o2
a00754e0:  96 16 e2 30  or  %i3, 0x230, %o3
a00754e4:  90 10 20 00  clr  %o0
a00754e8:  92 10 20 1d  mov  0x1d, %o1
a00754ec:  40 00 c7 ce  call  0xa00a7424
a00754f0:  94 10 00 1a  mov  %i2, %o2
a00754f4:  b6 16 e2 30  or  %i3, 0x230, %i3
a00754f8:  b0 10 20 00  clr  %i0
a00754fc:  40 00 c7 ca  call  0xa00a7424
a0075500:  93 e8 20 1e  restore  %g0, 0x1e, %o1
a0075504:  01 00 00 00  nop
