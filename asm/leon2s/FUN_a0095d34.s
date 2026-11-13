# leon2s FUN_a0095d34 0xa0095d34-0xa0095d78 (68 bytes)
a0095d34:  9d e3 bf 98  save  %sp, -104, %sp
a0095d38:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0095d3c:  90 10 20 05  mov  5, %o0
a0095d40:  80 a6 20 00  cmp  %i0, 0
a0095d44:  02 80 00 05  be  0xa0095d58
a0095d48:  a0 10 20 00  clr  %l0
a0095d4c:  80 a6 20 01  cmp  %i0, 1
a0095d50:  12 80 00 07  bne  0xa0095d6c
a0095d54:  90 10 20 06  mov  6, %o0
a0095d58:  7f ff b6 3c  call  0xa0083648
a0095d5c:  01 00 00 00  nop
a0095d60:  80 a2 20 00  cmp  %o0, 0
a0095d64:  22 80 00 02  be,a   0xa0095d6c
a0095d68:  a0 10 20 01  mov  1, %l0
a0095d6c:  b0 0c 20 01  and  %l0, 1, %i0
a0095d70:  81 c7 e0 08  ret
a0095d74:  81 e8 00 00  restore
