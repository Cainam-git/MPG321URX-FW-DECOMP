# leon2s FUN_a008e004 0xa008e004-0xa008e050 (76 bytes)
a008e004:  1b 2a 01 f4  sethi  %hi(0xa807d000), %o5
a008e008:  c2 0b 63 c1  ldub  [ %o5 + 0x3c1 ], %g1	! 0xa807d3c1
a008e00c:  80 a0 60 a0  cmp  %g1, 0xa0
a008e010:  82 0a 20 ff  and  %o0, 0xff, %g1
a008e014:  9a 13 63 c1  or  %o5, 0x3c1, %o5
a008e018:  12 80 00 09  bne  0xa008e03c
a008e01c:  92 10 20 0c  mov  0xc, %o1
a008e020:  80 a0 60 00  cmp  %g1, 0
a008e024:  12 80 00 04  bne  0xa008e034
a008e028:  80 a0 60 01  cmp  %g1, 1
a008e02c:  10 80 00 04  b  0xa008e03c
a008e030:  d2 0b 60 03  ldub  [ %o5 + 3 ], %o1
a008e034:  22 80 00 02  be,a   0xa008e03c
a008e038:  d2 0b 60 09  ldub  [ %o5 + 9 ], %o1
a008e03c:  90 0a 20 ff  and  %o0, 0xff, %o0
a008e040:  92 0a 60 ff  and  %o1, 0xff, %o1
a008e044:  82 13 c0 00  mov  %o7, %g1
a008e048:  7f ff ff e7  call  0xa008dfe4
a008e04c:  9e 10 40 00  mov  %g1, %o7
