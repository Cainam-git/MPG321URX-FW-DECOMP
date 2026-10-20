# leon2s FUN_a008df7c 0xa008df7c-0xa008e098 (116 bytes)
a008df7c:  9d e3 bf 98  save  %sp, -104, %sp
a008df80:  ba 0e 20 ff  and  %i0, 0xff, %i5
a008df84:  83 2f 60 03  sll  %i5, 3, %g1
a008df88:  80 8e 60 ff  btst  0xff, %i1
a008df8c:  82 20 40 1d  sub  %g1, %i5, %g1
a008df90:  b4 10 20 05  mov  5, %i2
a008df94:  b6 10 20 01  mov  1, %i3
a008df98:  b8 10 20 00  clr  %i4
a008df9c:  b2 10 20 01  mov  1, %i1
a008dfa0:  9f 28 60 02  sll  %g1, 2, %o7
a008dfa4:  02 80 00 0d  be  0xa008dfd8
a008dfa8:  b0 10 00 1d  mov  %i5, %i0
a008dfac:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a008dfb0:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa807d580
a008dfb4:  c2 00 40 0f  ld  [ %g1 + %o7 ], %g1
a008dfb8:  80 88 60 10  btst  0x10, %g1
a008dfbc:  02 80 00 07  be  0xa008dfd8
a008dfc0:  b8 10 20 01  mov  1, %i4
a008dfc4:  b0 10 00 1d  mov  %i5, %i0
a008dfc8:  b2 10 20 01  mov  1, %i1
a008dfcc:  b4 10 20 05  mov  5, %i2
a008dfd0:  40 00 68 21  call  0xa00a8054
a008dfd4:  97 e8 20 0d  restore  %g0, 0xd, %o3
a008dfd8:  40 00 68 3d  call  0xa00a80cc
a008dfdc:  81 e8 00 00  restore
a008dfe0:  01 00 00 00  nop
a008dfe4:  96 0a 60 ff  and  %o1, 0xff, %o3
a008dfe8:  90 0a 20 ff  and  %o0, 0xff, %o0
a008dfec:  92 10 20 01  mov  1, %o1
a008dff0:  94 10 20 0c  mov  0xc, %o2
a008dff4:  82 13 c0 00  mov  %o7, %g1
a008dff8:  40 00 68 17  call  0xa00a8054
a008dffc:  9e 10 40 00  mov  %g1, %o7
a008e000:  01 00 00 00  nop
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
a008e050:  01 00 00 00  nop
a008e054:  80 8a 60 ff  btst  0xff, %o1
a008e058:  82 0a 20 ff  and  %o0, 0xff, %g1
a008e05c:  94 10 20 07  mov  7, %o2
a008e060:  96 10 20 80  mov  0x80, %o3
a008e064:  98 10 20 01  mov  1, %o4
a008e068:  92 10 20 01  mov  1, %o1
a008e06c:  12 80 00 07  bne  0xa008e088
a008e070:  90 10 00 01  mov  %g1, %o0
a008e074:  90 10 00 01  mov  %g1, %o0
a008e078:  92 10 20 01  mov  1, %o1
a008e07c:  94 10 20 07  mov  7, %o2
a008e080:  96 10 20 80  mov  0x80, %o3
a008e084:  98 10 20 00  clr  %o4
a008e088:  82 13 c0 00  mov  %o7, %g1
a008e08c:  40 00 68 10  call  0xa00a80cc
a008e090:  9e 10 40 00  mov  %g1, %o7
a008e094:  01 00 00 00  nop
