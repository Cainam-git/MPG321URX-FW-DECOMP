# leon2m FUN_a0129a24 0xa0129a24-0xa0129a5c (56 bytes)
a0129a24:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0129a28:  c2 10 61 fe  lduh  [ %g1 + 0x1fe ], %g1	! 0xa802c9fe
a0129a2c:  80 88 60 01  btst  1, %g1
a0129a30:  12 80 00 09  bne  0xa0129a54
a0129a34:  90 10 20 01  mov  1, %o0
a0129a38:  80 88 60 02  btst  2, %g1
a0129a3c:  12 80 00 06  bne  0xa0129a54
a0129a40:  80 88 60 08  btst  8, %g1
a0129a44:  12 80 00 04  bne  0xa0129a54
a0129a48:  9a 08 60 04  and  %g1, 4, %o5
a0129a4c:  80 a0 00 0d  cmp  %g0, %o5
a0129a50:  90 40 20 00  addx  %g0, 0, %o0
a0129a54:  81 c3 e0 08  retl
a0129a58:  01 00 00 00  nop
