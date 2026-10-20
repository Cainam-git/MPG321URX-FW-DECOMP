# leon2m FUN_a0124b40 0xa0124b40-0xa0124b88 (72 bytes)
a0124b40:  9d e3 bf 98  save  %sp, -104, %sp
a0124b44:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0124b48:  da 08 61 f8  ldub  [ %g1 + 0x1f8 ], %o5	! 0xa802c9f8
a0124b4c:  b0 10 20 04  mov  4, %i0
a0124b50:  b2 10 20 10  mov  0x10, %i1
a0124b54:  80 a3 60 01  cmp  %o5, 1
a0124b58:  02 80 00 07  be  0xa0124b74
a0124b5c:  b4 10 20 fe  mov  0xfe, %i2
a0124b60:  40 00 0b 73  call  0xa012792c
a0124b64:  01 00 00 00  nop
a0124b68:  80 8a 20 ff  btst  0xff, %o0
a0124b6c:  02 80 00 04  be  0xa0124b7c
a0124b70:  01 00 00 00  nop
a0124b74:  67 fd 9f 3e  call  0x4008c86c
a0124b78:  81 e8 00 00  restore
a0124b7c:  01 00 00 00  nop
a0124b80:  81 c7 e0 08  ret
a0124b84:  81 e8 00 00  restore
