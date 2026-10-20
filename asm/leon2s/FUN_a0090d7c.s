# leon2s FUN_a0090d7c 0xa0090d7c-0xa0090dcc (80 bytes)
a0090d7c:  9d e3 bf 98  save  %sp, -104, %sp
a0090d80:  90 0e 20 ff  and  %i0, 0xff, %o0
a0090d84:  40 00 55 fe  call  0xa00a657c
a0090d88:  92 10 21 48  mov  0x148, %o1
a0090d8c:  90 0a 20 0f  and  %o0, 0xf, %o0
a0090d90:  80 a2 20 01  cmp  %o0, 1
a0090d94:  02 80 00 0b  be  0xa0090dc0
a0090d98:  b0 10 20 02  mov  2, %i0
a0090d9c:  80 a2 20 01  cmp  %o0, 1
a0090da0:  14 80 00 05  bg  0xa0090db4
a0090da4:  b0 10 20 04  mov  4, %i0
a0090da8:  80 a2 20 00  cmp  %o0, 0
a0090dac:  10 80 00 03  b  0xa0090db8
a0090db0:  b0 10 20 01  mov  1, %i0
a0090db4:  80 a2 20 03  cmp  %o0, 3
a0090db8:  32 80 00 02  bne,a   0xa0090dc0
a0090dbc:  b0 10 20 01  mov  1, %i0
a0090dc0:  b0 0e 20 07  and  %i0, 7, %i0
a0090dc4:  81 c7 e0 08  ret
a0090dc8:  81 e8 00 00  restore
