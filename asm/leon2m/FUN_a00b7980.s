# leon2m FUN_a00b7980 0xa00b7980-0xa00b79cc (76 bytes)
a00b7980:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00b7984:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00b7988:  da 03 20 ac  ld  [ %o4 + 0xac ], %o5
a00b798c:  03 00 04 00  sethi  %hi(0x100000), %g1
a00b7990:  90 10 20 06  mov  6, %o0
a00b7994:  80 8b 40 01  btst  %o5, %g1
a00b7998:  02 80 00 06  be  0xa00b79b0
a00b799c:  92 10 20 00  clr  %o1
a00b79a0:  c2 0b 20 1f  ldub  [ %o4 + 0x1f ], %g1
a00b79a4:  80 a0 60 00  cmp  %g1, 0
a00b79a8:  02 80 00 05  be  0xa00b79bc
a00b79ac:  01 00 00 00  nop
a00b79b0:  82 13 c0 00  mov  %o7, %g1
a00b79b4:  7f ff c9 5f  call  0xa00a9f30
a00b79b8:  9e 10 40 00  mov  %g1, %o7
a00b79bc:  92 10 20 01  mov  1, %o1
a00b79c0:  82 13 c0 00  mov  %o7, %g1
a00b79c4:  7f ff c9 5b  call  0xa00a9f30
a00b79c8:  9e 10 40 00  mov  %g1, %o7
