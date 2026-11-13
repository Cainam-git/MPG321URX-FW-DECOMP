# leon2s FUN_a008ffa4 0xa008ffa4-0xa008fff0 (76 bytes)
a008ffa4:  9d e3 bf 98  save  %sp, -104, %sp
a008ffa8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a008ffac:  92 10 20 01  mov  1, %o1
a008ffb0:  80 a4 20 00  cmp  %l0, 0
a008ffb4:  02 80 00 05  be  0xa008ffc8
a008ffb8:  b0 10 20 00  clr  %i0
a008ffbc:  80 a4 20 01  cmp  %l0, 1
a008ffc0:  12 80 00 09  bne  0xa008ffe4
a008ffc4:  b0 10 20 01  mov  1, %i0
a008ffc8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008ffcc:  7f ff cd 93  call  0xa0083618
a008ffd0:  90 10 00 18  mov  %i0, %o0
a008ffd4:  7f ff ff e1  call  0xa008ff58
a008ffd8:  90 10 00 10  mov  %l0, %o0
a008ffdc:  7f ff be 32  call  0xa007f8a4
a008ffe0:  81 e8 00 00  restore
a008ffe4:  01 00 00 00  nop
a008ffe8:  81 c7 e0 08  ret
a008ffec:  81 e8 00 00  restore
