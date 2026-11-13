# leon2m FUN_a0143d14 0xa0143d14-0xa0143d98 (132 bytes)
a0143d14:  9d e3 bf 98  save  %sp, -104, %sp
a0143d18:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0143d1c:  80 a6 20 01  cmp  %i0, 1
a0143d20:  02 80 00 0b  be  0xa0143d4c
a0143d24:  90 10 20 01  mov  1, %o0
a0143d28:  80 a6 20 01  cmp  %i0, 1
a0143d2c:  04 80 00 11  ble  0xa0143d70
a0143d30:  80 a6 20 02  cmp  %i0, 2
a0143d34:  02 80 00 06  be  0xa0143d4c
a0143d38:  90 10 20 02  mov  2, %o0
a0143d3c:  80 a6 20 03  cmp  %i0, 3
a0143d40:  02 80 00 03  be  0xa0143d4c
a0143d44:  90 10 20 03  mov  3, %o0
a0143d48:  90 10 3f ff  mov  -1, %o0
a0143d4c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0143d50:  80 a2 20 03  cmp  %o0, 3
a0143d54:  08 80 00 0c  bleu  0xa0143d84
a0143d58:  01 00 00 00  nop
a0143d5c:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0143d60:  7f fe 6d 04  call  0xa00df170
a0143d64:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0143d68:  10 80 00 07  b  0xa0143d84
a0143d6c:  90 10 20 00  clr  %o0
a0143d70:  80 a6 20 00  cmp  %i0, 0
a0143d74:  02 bf ff f6  be  0xa0143d4c
a0143d78:  90 10 20 00  clr  %o0
a0143d7c:  10 bf ff f4  b  0xa0143d4c
a0143d80:  90 10 3f ff  mov  -1, %o0
a0143d84:  7f ff e4 47  call  0xa013cea0
a0143d88:  01 00 00 00  nop
a0143d8c:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0143d90:  81 c7 e0 08  ret
a0143d94:  81 e8 00 00  restore
