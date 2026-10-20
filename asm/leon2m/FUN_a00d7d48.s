# leon2m FUN_a00d7d48 0xa00d7d48-0xa00d7de0 (152 bytes)
a00d7d48:  9d e3 bf 98  save  %sp, -104, %sp
a00d7d4c:  40 01 d0 09  call  0xa014bd70
a00d7d50:  90 10 20 00  clr  %o0
a00d7d54:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d7d58:  80 a2 20 01  cmp  %o0, 1
a00d7d5c:  02 80 00 0a  be  0xa00d7d84
a00d7d60:  b0 10 20 05  mov  5, %i0
a00d7d64:  40 01 ae de  call  0xa01438dc
a00d7d68:  90 10 20 00  clr  %o0
a00d7d6c:  82 0a 20 ff  and  %o0, 0xff, %g1
a00d7d70:  80 a0 60 01  cmp  %g1, 1
a00d7d74:  02 80 00 06  be  0xa00d7d8c
a00d7d78:  01 00 00 00  nop
a00d7d7c:  10 80 00 17  b  0xa00d7dd8
a00d7d80:  b0 10 20 00  clr  %i0	! 0x0
a00d7d84:  10 80 00 15  b  0xa00d7dd8
a00d7d88:  b0 10 20 04  mov  4, %i0
a00d7d8c:  40 01 cf 37  call  0xa014ba68
a00d7d90:  01 00 00 00  nop
a00d7d94:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d7d98:  80 a2 20 02  cmp  %o0, 2
a00d7d9c:  22 80 00 0f  be,a   0xa00d7dd8
a00d7da0:  b0 10 20 02  mov  2, %i0
a00d7da4:  14 80 00 07  bg  0xa00d7dc0
a00d7da8:  80 a2 20 03  cmp  %o0, 3
a00d7dac:  80 a2 20 01  cmp  %o0, 1
a00d7db0:  32 80 00 0a  bne,a   0xa00d7dd8
a00d7db4:  b0 10 20 00  clr  %i0
a00d7db8:  10 80 00 08  b  0xa00d7dd8
a00d7dbc:  b0 10 20 01  mov  1, %i0
a00d7dc0:  02 80 00 05  be  0xa00d7dd4
a00d7dc4:  80 a2 20 04  cmp  %o0, 4
a00d7dc8:  32 80 00 04  bne,a   0xa00d7dd8
a00d7dcc:  b0 10 20 00  clr  %i0
a00d7dd0:  30 80 00 02  b,a   0xa00d7dd8
a00d7dd4:  b0 10 20 03  mov  3, %i0
a00d7dd8:  81 c7 e0 08  ret
a00d7ddc:  81 e8 00 00  restore
