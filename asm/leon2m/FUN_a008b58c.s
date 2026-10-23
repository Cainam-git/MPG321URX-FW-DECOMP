# leon2m FUN_a008b58c 0xa008b58c-0xa008b5e0 (84 bytes)
a008b58c:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a008b590:  d8 0a e3 b9  ldub  [ %o3 + 0x3b9 ], %o4	! 0xa802afb9
a008b594:  94 10 20 04  mov  4, %o2
a008b598:  90 22 80 0c  sub  %o2, %o4, %o0
a008b59c:  9a 10 20 4e  mov  0x4e, %o5
a008b5a0:  96 03 3f fc  add  %o4, -4, %o3
a008b5a4:  82 10 20 4e  mov  0x4e, %g1
a008b5a8:  95 3b 40 08  sra  %o5, %o0, %o2
a008b5ac:  80 a3 20 03  cmp  %o4, 3
a008b5b0:  18 80 00 06  bgu  0xa008b5c8
a008b5b4:  97 28 40 0b  sll  %g1, %o3, %o3
a008b5b8:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008b5bc:  d8 08 63 b8  ldub  [ %g1 + 0x3b8 ], %o4	! 0xa802afb8
a008b5c0:  10 80 00 05  b  0xa008b5d4
a008b5c4:  91 3a 80 0c  sra  %o2, %o4, %o0
a008b5c8:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a008b5cc:  da 0a 23 b8  ldub  [ %o0 + 0x3b8 ], %o5	! 0xa802afb8
a008b5d0:  91 3a c0 0d  sra  %o3, %o5, %o0
a008b5d4:  95 2a 20 10  sll  %o0, 0x10, %o2
a008b5d8:  81 c3 e0 08  retl
a008b5dc:  91 32 a0 10  srl  %o2, 0x10, %o0
