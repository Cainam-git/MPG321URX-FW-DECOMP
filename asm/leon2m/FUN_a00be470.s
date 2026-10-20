# leon2m FUN_a00be470 0xa00be470-0xa00be4c0 (80 bytes)
a00be470:  9d e3 bf 98  save  %sp, -104, %sp
a00be474:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00be478:  d6 03 e0 6c  ld  [ %o7 + 0x6c ], %o3	! 0xa802d46c
a00be47c:  95 32 e0 1e  srl  %o3, 0x1e, %o2
a00be480:  90 0a a0 01  and  %o2, 1, %o0
a00be484:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be488:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be48c:  82 02 20 30  add  %o0, 0x30, %g1
a00be490:  98 10 20 30  mov  0x30, %o4
a00be494:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00be498:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00be49c:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00be4a0:  7f ff f1 e7  call  0xa00bac3c
a00be4a4:  90 10 20 72  mov  0x72, %o0
a00be4a8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be4ac:  7f ff f1 29  call  0xa00ba950
a00be4b0:  90 10 00 18  mov  %i0, %o0
a00be4b4:  7f ff f1 cc  call  0xa00babe4
a00be4b8:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be4bc:  01 00 00 00  nop
