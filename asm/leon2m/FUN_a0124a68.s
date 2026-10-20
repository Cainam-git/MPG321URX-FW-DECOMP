# leon2m FUN_a0124a68 0xa0124a68-0xa0124ab0 (72 bytes)
a0124a68:  9d e3 bf 98  save  %sp, -104, %sp
a0124a6c:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0124a70:  da 08 61 f8  ldub  [ %g1 + 0x1f8 ], %o5	! 0xa802c9f8
a0124a74:  b0 10 20 04  mov  4, %i0
a0124a78:  b2 10 20 80  mov  0x80, %i1
a0124a7c:  80 a3 60 01  cmp  %o5, 1
a0124a80:  02 80 00 07  be  0xa0124a9c
a0124a84:  b4 10 20 01  mov  1, %i2
a0124a88:  40 00 0b a9  call  0xa012792c
a0124a8c:  01 00 00 00  nop
a0124a90:  80 8a 20 ff  btst  0xff, %o0
a0124a94:  02 80 00 04  be  0xa0124aa4
a0124a98:  01 00 00 00  nop
a0124a9c:  67 fd 9f 74  call  0x4008c86c
a0124aa0:  81 e8 00 00  restore
a0124aa4:  01 00 00 00  nop
a0124aa8:  81 c7 e0 08  ret
a0124aac:  81 e8 00 00  restore
