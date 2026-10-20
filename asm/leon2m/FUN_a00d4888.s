# leon2m FUN_a00d4888 0xa00d4888-0xa00d48cc (68 bytes)
a00d4888:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d488c:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00d4890:  da 03 20 ac  ld  [ %o4 + 0xac ], %o5
a00d4894:  03 00 04 00  sethi  %hi(0x100000), %g1
a00d4898:  80 8b 40 01  btst  %o5, %g1
a00d489c:  02 80 00 09  be  0xa00d48c0
a00d48a0:  01 00 00 00  nop
a00d48a4:  c2 0b 20 1f  ldub  [ %o4 + 0x1f ], %g1
a00d48a8:  80 a0 60 00  cmp  %g1, 0
a00d48ac:  12 80 00 05  bne  0xa00d48c0
a00d48b0:  90 10 20 04  mov  4, %o0
a00d48b4:  82 13 c0 00  mov  %o7, %g1
a00d48b8:  40 01 cb dd  call  0xa014782c
a00d48bc:  9e 10 40 00  mov  %g1, %o7
a00d48c0:  01 00 00 00  nop
a00d48c4:  81 c3 e0 08  retl
a00d48c8:  01 00 00 00  nop
