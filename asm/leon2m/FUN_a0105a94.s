# leon2m FUN_a0105a94 0xa0105a94-0xa0105af0 (92 bytes)
a0105a94:  9d e3 bf 98  save  %sp, -104, %sp
a0105a98:  80 8e 20 ff  btst  0xff, %i0
a0105a9c:  02 80 00 0a  be  0xa0105ac4
a0105aa0:  80 8e 60 ff  btst  0xff, %i1
a0105aa4:  13 33 c0 46  sethi  %hi(0xcf011800), %o1
a0105aa8:  82 12 62 00  or  %o1, 0x200, %g1	! 0xcf011a00
a0105aac:  da 00 40 00  ld  [ %g1 ], %o5
a0105ab0:  80 8b 60 01  btst  1, %o5
a0105ab4:  12 80 00 07  bne  0xa0105ad0
a0105ab8:  90 10 20 04  mov  4, %o0
a0105abc:  10 80 00 05  b  0xa0105ad0
a0105ac0:  90 10 20 00  clr  %o0
a0105ac4:  12 80 00 03  bne  0xa0105ad0
a0105ac8:  90 10 20 02  mov  2, %o0
a0105acc:  90 10 20 03  mov  3, %o0
a0105ad0:  7f ff f5 40  call  0xa0102fd0
a0105ad4:  01 00 00 00  nop
a0105ad8:  91 2a 20 10  sll  %o0, 0x10, %o0
a0105adc:  95 32 20 10  srl  %o0, 0x10, %o2
a0105ae0:  b1 2a a0 10  sll  %o2, 0x10, %i0
a0105ae4:  b1 36 20 10  srl  %i0, 0x10, %i0
a0105ae8:  81 c7 e0 08  ret
a0105aec:  81 e8 00 00  restore
