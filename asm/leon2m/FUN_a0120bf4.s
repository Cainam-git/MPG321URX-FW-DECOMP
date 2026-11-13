# leon2m FUN_a0120bf4 0xa0120bf4-0xa0120c58 (100 bytes)
a0120bf4:  9d e3 bf 98  save  %sp, -104, %sp
a0120bf8:  90 0e 20 ff  and  %i0, 0xff, %o0
a0120bfc:  7f ff 44 e8  call  0xa00f1f9c
a0120c00:  92 10 20 11  mov  0x11, %o1
a0120c04:  90 0a 20 03  and  %o0, 3, %o0
a0120c08:  80 a2 20 01  cmp  %o0, 1
a0120c0c:  02 80 00 10  be  0xa0120c4c
a0120c10:  b0 10 20 04  mov  4, %i0
a0120c14:  80 a2 20 01  cmp  %o0, 1
a0120c18:  04 80 00 0a  ble  0xa0120c40
a0120c1c:  b0 10 20 02  mov  2, %i0
a0120c20:  80 a2 20 02  cmp  %o0, 2
a0120c24:  02 80 00 0a  be  0xa0120c4c
a0120c28:  80 a2 20 03  cmp  %o0, 3
a0120c2c:  b0 10 20 08  mov  8, %i0
a0120c30:  32 80 00 07  bne,a   0xa0120c4c
a0120c34:  b0 10 20 08  mov  8, %i0
a0120c38:  10 80 00 06  b  0xa0120c50
a0120c3c:  b0 0e 20 0f  and  %i0, 0xf, %i0
a0120c40:  80 a2 20 00  cmp  %o0, 0
a0120c44:  10 bf ff fb  b  0xa0120c30
a0120c48:  b0 10 20 01  mov  1, %i0
a0120c4c:  b0 0e 20 0f  and  %i0, 0xf, %i0
a0120c50:  81 c7 e0 08  ret
a0120c54:  81 e8 00 00  restore
