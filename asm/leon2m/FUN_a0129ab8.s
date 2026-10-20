# leon2m FUN_a0129ab8 0xa0129ab8-0xa0129af0 (56 bytes)
a0129ab8:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0129abc:  c2 10 62 00  lduh  [ %g1 + 0x200 ], %g1	! 0xa802ca00
a0129ac0:  80 88 60 01  btst  1, %g1
a0129ac4:  12 80 00 09  bne  0xa0129ae8
a0129ac8:  90 10 20 01  mov  1, %o0
a0129acc:  80 88 60 02  btst  2, %g1
a0129ad0:  12 80 00 06  bne  0xa0129ae8
a0129ad4:  80 88 60 08  btst  8, %g1
a0129ad8:  12 80 00 04  bne  0xa0129ae8
a0129adc:  9a 08 60 04  and  %g1, 4, %o5
a0129ae0:  80 a0 00 0d  cmp  %g0, %o5
a0129ae4:  90 40 20 00  addx  %g0, 0, %o0
a0129ae8:  81 c3 e0 08  retl
a0129aec:  01 00 00 00  nop
