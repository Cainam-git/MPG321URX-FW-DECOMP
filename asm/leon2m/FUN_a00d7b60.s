# leon2m FUN_a00d7b60 0xa00d7b60-0xa00d7bc0 (96 bytes)
a00d7b60:  9d e3 bf 98  save  %sp, -104, %sp
a00d7b64:  40 01 cf c1  call  0xa014ba68
a00d7b68:  b0 10 20 00  clr  %i0
a00d7b6c:  82 0a 20 ff  and  %o0, 0xff, %g1
a00d7b70:  80 a0 60 02  cmp  %g1, 2
a00d7b74:  02 80 00 0a  be  0xa00d7b9c
a00d7b78:  90 10 20 00  clr  %o0
a00d7b7c:  40 01 d0 7d  call  0xa014bd70
a00d7b80:  01 00 00 00  nop
a00d7b84:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d7b88:  80 a2 20 01  cmp  %o0, 1
a00d7b8c:  32 80 00 0b  bne,a   0xa00d7bb8
a00d7b90:  b0 0e 20 01  and  %i0, 1, %i0
a00d7b94:  10 80 00 08  b  0xa00d7bb4
a00d7b98:  b0 10 20 01  mov  1, %i0
a00d7b9c:  40 01 d0 75  call  0xa014bd70
a00d7ba0:  b0 10 20 01  mov  1, %i0
a00d7ba4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d7ba8:  80 a2 20 01  cmp  %o0, 1
a00d7bac:  22 80 00 02  be,a   0xa00d7bb4
a00d7bb0:  b0 10 20 01  mov  1, %i0
a00d7bb4:  b0 0e 20 01  and  %i0, 1, %i0
a00d7bb8:  81 c7 e0 08  ret
a00d7bbc:  81 e8 00 00  restore
