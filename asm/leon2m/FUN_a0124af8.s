# leon2m FUN_a0124af8 0xa0124af8-0xa0124b40 (72 bytes)
a0124af8:  9d e3 bf 98  save  %sp, -104, %sp
a0124afc:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0124b00:  da 08 61 f8  ldub  [ %g1 + 0x1f8 ], %o5	! 0xa802c9f8
a0124b04:  b0 10 20 04  mov  4, %i0
a0124b08:  b2 10 20 10  mov  0x10, %i1
a0124b0c:  80 a3 60 01  cmp  %o5, 1
a0124b10:  02 80 00 07  be  0xa0124b2c
a0124b14:  b4 10 20 01  mov  1, %i2
a0124b18:  40 00 0b 85  call  0xa012792c
a0124b1c:  01 00 00 00  nop
a0124b20:  80 8a 20 ff  btst  0xff, %o0
a0124b24:  02 80 00 04  be  0xa0124b34
a0124b28:  01 00 00 00  nop
a0124b2c:  67 fd 9f 50  call  0x4008c86c
a0124b30:  81 e8 00 00  restore
a0124b34:  01 00 00 00  nop
a0124b38:  81 c7 e0 08  ret
a0124b3c:  81 e8 00 00  restore
