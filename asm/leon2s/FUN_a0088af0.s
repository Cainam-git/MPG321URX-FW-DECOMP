# leon2s FUN_a0088af0 0xa0088af0-0xa0088b60 (112 bytes)
a0088af0:  9d e3 bf 98  save  %sp, -104, %sp
a0088af4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0088af8:  80 a6 20 00  cmp  %i0, 0
a0088afc:  12 80 00 04  bne  0xa0088b0c
a0088b00:  a0 10 20 00  clr  %l0
a0088b04:  10 80 00 0f  b  0xa0088b40
a0088b08:  90 10 20 00  clr  %o0
a0088b0c:  80 a6 20 02  cmp  %i0, 2
a0088b10:  02 80 00 0c  be  0xa0088b40
a0088b14:  90 10 20 02  mov  2, %o0
a0088b18:  80 a6 20 03  cmp  %i0, 3
a0088b1c:  02 80 00 09  be  0xa0088b40
a0088b20:  90 10 20 03  mov  3, %o0
a0088b24:  80 a6 20 04  cmp  %i0, 4
a0088b28:  02 80 00 06  be  0xa0088b40
a0088b2c:  90 10 20 04  mov  4, %o0
a0088b30:  80 a6 20 01  cmp  %i0, 1
a0088b34:  12 80 00 09  bne  0xa0088b58
a0088b38:  b0 0c 20 01  and  %l0, 1, %i0
a0088b3c:  90 10 20 01  mov  1, %o0
a0088b40:  7f ff ea c2  call  0xa0083648
a0088b44:  01 00 00 00  nop
a0088b48:  80 a2 20 00  cmp  %o0, 0
a0088b4c:  22 80 00 02  be,a   0xa0088b54
a0088b50:  a0 10 20 01  mov  1, %l0
a0088b54:  b0 0c 20 01  and  %l0, 1, %i0
a0088b58:  81 c7 e0 08  ret
a0088b5c:  81 e8 00 00  restore
