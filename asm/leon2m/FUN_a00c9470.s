# leon2m FUN_a00c9470 0xa00c9470-0xa00c9500 (144 bytes)
a00c9470:  9d e3 bf 98  save  %sp, -104, %sp
a00c9474:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c9478:  80 a6 20 02  cmp  %i0, 2
a00c947c:  02 80 00 19  be  0xa00c94e0
a00c9480:  80 a6 20 03  cmp  %i0, 3
a00c9484:  02 80 00 1a  be  0xa00c94ec
a00c9488:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c948c:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c9490:  94 08 60 ff  and  %g1, 0xff, %o2
a00c9494:  80 a2 a0 31  cmp  %o2, 0x31
a00c9498:  12 80 00 18  bne  0xa00c94f8
a00c949c:  82 10 20 ff  mov  0xff, %g1
a00c94a0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c94a4:  da 0a e2 af  ldub  [ %o3 + 0x2af ], %o5	! 0xa802d2af
a00c94a8:  80 a3 60 00  cmp  %o5, 0
a00c94ac:  02 80 00 13  be  0xa00c94f8
a00c94b0:  01 00 00 00  nop
a00c94b4:  40 00 3f c5  call  0xa00d93c8
a00c94b8:  01 00 00 00  nop
a00c94bc:  7f ff c5 6c  call  0xa00baa6c
a00c94c0:  90 10 00 18  mov  %i0, %o0
a00c94c4:  7f ff c5 23  call  0xa00ba950
a00c94c8:  90 10 00 18  mov  %i0, %o0
a00c94cc:  90 10 00 18  mov  %i0, %o0
a00c94d0:  7f ff c5 ac  call  0xa00bab80
a00c94d4:  92 10 20 06  mov  6, %o1
a00c94d8:  10 80 00 08  b  0xa00c94f8
a00c94dc:  82 10 20 00  clr  %g1
a00c94e0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c94e4:  10 bf ff eb  b  0xa00c9490
a00c94e8:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c94ec:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c94f0:  10 bf ff e8  b  0xa00c9490
a00c94f4:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c94f8:  81 c7 e0 08  ret
a00c94fc:  91 e8 00 01  restore  %g0, %g1, %o0
