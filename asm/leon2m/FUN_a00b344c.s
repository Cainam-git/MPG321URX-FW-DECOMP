# leon2m FUN_a00b344c 0xa00b344c-0xa00b34d4 (136 bytes)
a00b344c:  9d e3 bf 98  save  %sp, -104, %sp
a00b3450:  90 10 21 e5  mov  0x1e5, %o0
a00b3454:  40 02 4d bf  call  0xa0146b50
a00b3458:  92 10 20 00  clr  %o1
a00b345c:  90 10 20 02  mov  2, %o0
a00b3460:  40 02 4d c3  call  0xa0146b6c
a00b3464:  92 10 20 00  clr  %o1
a00b3468:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b346c:  90 10 20 37  mov  0x37, %o0
a00b3470:  92 10 20 09  mov  9, %o1
a00b3474:  94 10 20 04  mov  4, %o2
a00b3478:  96 10 25 96  mov  0x596, %o3
a00b347c:  40 02 4d 81  call  0xa0146a80
a00b3480:  98 10 20 00  clr  %o4
a00b3484:  b3 2e 20 03  sll  %i0, 3, %i1
a00b3488:  9e 26 40 18  sub  %i1, %i0, %o7
a00b348c:  99 2b e0 02  sll  %o7, 2, %o4
a00b3490:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00b3494:  94 03 00 18  add  %o4, %i0, %o2
a00b3498:  da 0a e2 98  ldub  [ %o3 + 0x298 ], %o5
a00b349c:  82 02 80 0d  add  %o2, %o5, %g1
a00b34a0:  93 28 60 10  sll  %g1, 0x10, %o1
a00b34a4:  11 00 06 4a  sethi  %hi(0x192800), %o0
a00b34a8:  90 12 20 b0  or  %o0, 0xb0, %o0	! 0x1928b0
a00b34ac:  7f ff c0 e6  call  0xa00a3844
a00b34b0:  93 32 60 10  srl  %o1, 0x10, %o1
a00b34b4:  b8 10 00 08  mov  %o0, %i4
a00b34b8:  b0 10 20 00  clr  %i0
a00b34bc:  b2 10 20 37  mov  0x37, %i1
a00b34c0:  b4 10 20 09  mov  9, %i2
a00b34c4:  b6 10 20 04  mov  4, %i3
a00b34c8:  7f ff bf 37  call  0xa00a31a4
a00b34cc:  9b e8 20 00  restore  %g0, 0, %o5
a00b34d0:  01 00 00 00  nop
