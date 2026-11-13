# leon2m FUN_a0124ab0 0xa0124ab0-0xa0124af8 (72 bytes)
a0124ab0:  9d e3 bf 98  save  %sp, -104, %sp
a0124ab4:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0124ab8:  da 08 61 f8  ldub  [ %g1 + 0x1f8 ], %o5	! 0xa802c9f8
a0124abc:  b0 10 20 04  mov  4, %i0
a0124ac0:  b2 10 20 80  mov  0x80, %i1
a0124ac4:  80 a3 60 01  cmp  %o5, 1
a0124ac8:  02 80 00 07  be  0xa0124ae4
a0124acc:  b4 10 20 fe  mov  0xfe, %i2
a0124ad0:  40 00 0b 97  call  0xa012792c
a0124ad4:  01 00 00 00  nop
a0124ad8:  80 8a 20 ff  btst  0xff, %o0
a0124adc:  02 80 00 04  be  0xa0124aec
a0124ae0:  01 00 00 00  nop
a0124ae4:  67 fd 9f 62  call  0x4008c86c
a0124ae8:  81 e8 00 00  restore
a0124aec:  01 00 00 00  nop
a0124af0:  81 c7 e0 08  ret
a0124af4:  81 e8 00 00  restore
