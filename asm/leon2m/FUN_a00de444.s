# leon2m FUN_a00de444 0xa00de444-0xa00de4fc (52 bytes)
a00de444:  82 0a 20 ff  and  %o0, 0xff, %g1
a00de448:  80 a0 60 11  cmp  %g1, 0x11
a00de44c:  18 80 00 29  bgu  0xa00de4f0
a00de450:  90 10 20 00  clr  %o0
a00de454:  19 00 01 f7  sethi  %hi(0x7dc00), %o4
a00de458:  83 28 60 02  sll  %g1, 2, %g1
a00de45c:  9a 13 21 70  or  %o4, 0x170, %o5
a00de460:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00de464:  81 c3 00 00  jmp  %o4
a00de468:  01 00 00 00  nop
a00de46c:  10 80 00 21  b  0xa00de4f0
a00de470:  90 10 33 02  mov  -3326, %o0	! 0xfffff302
a00de474:  10 80 00 1f  b  0xa00de4f0
a00de478:  90 10 33 03  mov  -3325, %o0
a00de47c:  10 80 00 1d  b  0xa00de4f0
a00de480:  90 10 33 01  mov  -3327, %o0
a00de484:  10 80 00 1b  b  0xa00de4f0
a00de488:  90 10 33 00  mov  -3328, %o0
a00de48c:  10 80 00 19  b  0xa00de4f0
a00de490:  90 10 31 1e  mov  -3810, %o0
a00de494:  10 80 00 17  b  0xa00de4f0
a00de498:  90 10 31 1c  mov  -3812, %o0
a00de49c:  10 80 00 15  b  0xa00de4f0
a00de4a0:  90 10 31 1a  mov  -3814, %o0
a00de4a4:  10 80 00 13  b  0xa00de4f0
a00de4a8:  90 10 31 18  mov  -3816, %o0
a00de4ac:  10 80 00 11  b  0xa00de4f0
a00de4b0:  90 10 31 16  mov  -3818, %o0
a00de4b4:  10 80 00 0f  b  0xa00de4f0
a00de4b8:  90 10 31 14  mov  -3820, %o0
a00de4bc:  10 80 00 0d  b  0xa00de4f0
a00de4c0:  90 10 30 12  mov  -4078, %o0
a00de4c4:  10 80 00 0b  b  0xa00de4f0
a00de4c8:  90 10 30 10  mov  -4080, %o0
a00de4cc:  10 80 00 09  b  0xa00de4f0
a00de4d0:  90 10 30 04  mov  -4092, %o0
a00de4d4:  10 80 00 07  b  0xa00de4f0
a00de4d8:  90 10 30 03  mov  -4093, %o0
a00de4dc:  10 80 00 05  b  0xa00de4f0
a00de4e0:  90 10 30 02  mov  -4094, %o0
a00de4e4:  10 80 00 03  b  0xa00de4f0
a00de4e8:  90 10 30 01  mov  -4095, %o0
a00de4ec:  90 10 30 00  mov  -4096, %o0
a00de4f0:  91 2a 20 10  sll  %o0, 0x10, %o0
a00de4f4:  81 c3 e0 08  retl
a00de4f8:  91 32 20 10  srl  %o0, 0x10, %o0
