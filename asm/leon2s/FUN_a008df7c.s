# leon2s FUN_a008df7c 0xa008df7c-0xa008dfe4 (104 bytes)
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
