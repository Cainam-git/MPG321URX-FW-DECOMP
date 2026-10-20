# leon2s FUN_a00aa3a4 0xa00aa3a4-0xa00aa49c (188 bytes)
a00aa3a4:  9d e3 bf 98  save  %sp, -104, %sp
a00aa3a8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00aa3ac:  92 10 20 09  mov  9, %o1
a00aa3b0:  90 10 20 00  clr  %o0
a00aa3b4:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a00aa3b8:  b2 10 20 0d  mov  0xd, %i1
a00aa3bc:  80 a6 20 00  cmp  %i0, 0
a00aa3c0:  12 80 00 10  bne  0xa00aa400
a00aa3c4:  b4 10 20 08  mov  8, %i2
a00aa3c8:  7f ff f5 c1  call  0xa00a7acc
a00aa3cc:  01 00 00 00  nop
a00aa3d0:  94 0a 20 08  and  %o0, 8, %o2
a00aa3d4:  94 12 bf 91  or  %o2, -111, %o2
a00aa3d8:  94 0a a0 99  and  %o2, 0x99, %o2
a00aa3dc:  90 10 20 00  clr  %o0
a00aa3e0:  7f ff f5 e1  call  0xa00a7b64
a00aa3e4:  92 10 20 09  mov  9, %o1
a00aa3e8:  90 10 20 00  clr  %o0
a00aa3ec:  92 10 20 0a  mov  0xa, %o1
a00aa3f0:  7f ff f5 dd  call  0xa00a7b64
a00aa3f4:  94 10 20 11  mov  0x11, %o2
a00aa3f8:  7f ff ff b6  call  0xa00aa2d0
a00aa3fc:  81 e8 00 00  restore
a00aa400:  c2 0c 23 04  ldub  [ %l0 + 0x304 ], %g1
a00aa404:  90 10 20 01  mov  1, %o0
a00aa408:  92 10 20 64  mov  0x64, %o1
a00aa40c:  80 a0 60 00  cmp  %g1, 0
a00aa410:  12 80 00 0c  bne  0xa00aa440
a00aa414:  94 10 20 07  mov  7, %o2
a00aa418:  7f ff f5 d3  call  0xa00a7b64
a00aa41c:  01 00 00 00  nop
a00aa420:  90 10 20 01  mov  1, %o0	! 0x1
a00aa424:  92 10 20 63  mov  0x63, %o1
a00aa428:  7f ff f5 cf  call  0xa00a7b64
a00aa42c:  94 10 20 94  mov  0x94, %o2
a00aa430:  7f ff ff b6  call  0xa00aa308
a00aa434:  01 00 00 00  nop
a00aa438:  82 10 20 01  mov  1, %g1	! 0x1
a00aa43c:  c2 2c 23 04  stb  %g1, [ %l0 + 0x304 ]
a00aa440:  90 10 00 18  mov  %i0, %o0
a00aa444:  92 10 20 0c  mov  0xc, %o1
a00aa448:  7f ff f5 c7  call  0xa00a7b64
a00aa44c:  94 10 20 10  mov  0x10, %o2
a00aa450:  7f ff f5 c5  call  0xa00a7b64
a00aa454:  81 e8 00 00  restore
a00aa458:  01 00 00 00  nop
a00aa45c:  82 0a 60 ff  and  %o1, 0xff, %g1
a00aa460:  80 a0 60 01  cmp  %g1, 1
a00aa464:  82 0a 20 ff  and  %o0, 0xff, %g1
a00aa468:  92 10 20 09  mov  9, %o1
a00aa46c:  94 10 20 08  mov  8, %o2
a00aa470:  96 10 20 01  mov  1, %o3
a00aa474:  02 80 00 06  be  0xa00aa48c
a00aa478:  90 10 00 01  mov  %g1, %o0
a00aa47c:  90 10 00 01  mov  %g1, %o0
a00aa480:  92 10 20 09  mov  9, %o1
a00aa484:  94 10 20 08  mov  8, %o2
a00aa488:  96 10 20 00  clr  %o3
a00aa48c:  82 13 c0 00  mov  %o7, %g1
a00aa490:  7f ff f5 da  call  0xa00a7bf8
a00aa494:  9e 10 40 00  mov  %g1, %o7
a00aa498:  01 00 00 00  nop
