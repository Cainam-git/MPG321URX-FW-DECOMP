# leon2m FUN_a00b7944 0xa00b7944-0xa00b797c (56 bytes)
a00b7944:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00b7948:  da 02 23 3c  ld  [ %o0 + 0x33c ], %o5	! 0xa802d33c
a00b794c:  03 00 10 00  sethi  %hi(0x400000), %g1
a00b7950:  90 10 20 05  mov  5, %o0
a00b7954:  80 8b 40 01  btst  %o5, %g1
a00b7958:  02 80 00 05  be  0xa00b796c
a00b795c:  92 10 20 01  mov  1, %o1
a00b7960:  82 13 c0 00  mov  %o7, %g1
a00b7964:  7f ff c9 73  call  0xa00a9f30
a00b7968:  9e 10 40 00  mov  %g1, %o7
a00b796c:  92 10 20 00  clr  %o1
a00b7970:  82 13 c0 00  mov  %o7, %g1
a00b7974:  7f ff c9 6f  call  0xa00a9f30
a00b7978:  9e 10 40 00  mov  %g1, %o7
