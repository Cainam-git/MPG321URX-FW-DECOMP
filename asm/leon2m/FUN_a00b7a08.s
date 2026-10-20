# leon2m FUN_a00b7a08 0xa00b7a08-0xa00b7a40 (56 bytes)
a00b7a08:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00b7a0c:  da 02 20 84  ld  [ %o0 + 0x84 ], %o5	! 0xa802d484
a00b7a10:  03 10 00 00  sethi  %hi(0x40000000), %g1
a00b7a14:  90 10 20 01  mov  1, %o0
a00b7a18:  80 8b 40 01  btst  %o5, %g1
a00b7a1c:  02 80 00 05  be  0xa00b7a30
a00b7a20:  92 10 20 01  mov  1, %o1
a00b7a24:  82 13 c0 00  mov  %o7, %g1
a00b7a28:  7f ff c9 42  call  0xa00a9f30
a00b7a2c:  9e 10 40 00  mov  %g1, %o7
a00b7a30:  92 10 20 00  clr  %o1
a00b7a34:  82 13 c0 00  mov  %o7, %g1
a00b7a38:  7f ff c9 3e  call  0xa00a9f30
a00b7a3c:  9e 10 40 00  mov  %g1, %o7
