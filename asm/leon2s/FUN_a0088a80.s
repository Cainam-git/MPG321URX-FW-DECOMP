# leon2s FUN_a0088a80 0xa0088a80-0xa0088af0 (112 bytes)
a0088a80:  9d e3 bf 98  save  %sp, -104, %sp
a0088a84:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0088a88:  80 a6 20 00  cmp  %i0, 0
a0088a8c:  12 80 00 04  bne  0xa0088a9c
a0088a90:  a0 10 20 00  clr  %l0
a0088a94:  10 80 00 0f  b  0xa0088ad0
a0088a98:  90 10 20 00  clr  %o0
a0088a9c:  80 a6 20 02  cmp  %i0, 2
a0088aa0:  02 80 00 0c  be  0xa0088ad0
a0088aa4:  90 10 20 02  mov  2, %o0
a0088aa8:  80 a6 20 03  cmp  %i0, 3
a0088aac:  02 80 00 09  be  0xa0088ad0
a0088ab0:  90 10 20 03  mov  3, %o0
a0088ab4:  80 a6 20 04  cmp  %i0, 4
a0088ab8:  02 80 00 06  be  0xa0088ad0
a0088abc:  90 10 20 04  mov  4, %o0
a0088ac0:  80 a6 20 01  cmp  %i0, 1
a0088ac4:  12 80 00 09  bne  0xa0088ae8
a0088ac8:  b0 0c 20 01  and  %l0, 1, %i0
a0088acc:  90 10 20 01  mov  1, %o0
a0088ad0:  7f ff eb 10  call  0xa0083710
a0088ad4:  01 00 00 00  nop
a0088ad8:  80 8a 20 04  btst  4, %o0
a0088adc:  32 80 00 02  bne,a   0xa0088ae4
a0088ae0:  a0 10 20 01  mov  1, %l0
a0088ae4:  b0 0c 20 01  and  %l0, 1, %i0
a0088ae8:  81 c7 e0 08  ret
a0088aec:  81 e8 00 00  restore
