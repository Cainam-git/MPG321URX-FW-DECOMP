# leon2m FUN_a0148a24 0xa0148a24-0xa0148aa8 (132 bytes)
a0148a24:  9d e3 bf 98  save  %sp, -104, %sp
a0148a28:  7f fe 57 f4  call  0xa00de9f8
a0148a2c:  90 10 20 00  clr  %o0
a0148a30:  82 0a 20 ff  and  %o0, 0xff, %g1
a0148a34:  90 10 20 01  mov  1, %o0
a0148a38:  80 a0 60 01  cmp  %g1, 1
a0148a3c:  02 80 00 0b  be  0xa0148a68
a0148a40:  b0 10 20 00  clr  %i0
a0148a44:  7f fe 57 ed  call  0xa00de9f8
a0148a48:  90 10 20 00  clr  %o0
a0148a4c:  94 0a 20 ff  and  %o0, 0xff, %o2
a0148a50:  80 a2 a0 02  cmp  %o2, 2
a0148a54:  02 80 00 12  be  0xa0148a9c
a0148a58:  90 10 20 00  clr  %o0
a0148a5c:  7f fe 57 e7  call  0xa00de9f8
a0148a60:  b0 0e 20 01  and  %i0, 1, %i0
a0148a64:  30 80 00 0f  b,a   0xa0148aa0
a0148a68:  7f fe 57 e4  call  0xa00de9f8
a0148a6c:  01 00 00 00  nop
a0148a70:  92 0a 20 ff  and  %o0, 0xff, %o1
a0148a74:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0148a78:  80 a2 60 11  cmp  %o1, 0x11
a0148a7c:  12 80 00 08  bne  0xa0148a9c
a0148a80:  90 12 23 10  or  %o0, 0x310, %o0
a0148a84:  7f fe 59 bb  call  0xa00df170
a0148a88:  b0 10 20 01  mov  1, %i0
a0148a8c:  7f ff 70 2d  call  0xa0124b40
a0148a90:  01 00 00 00  nop
a0148a94:  7f ff 70 07  call  0xa0124ab0
a0148a98:  01 00 00 00  nop
a0148a9c:  b0 0e 20 01  and  %i0, 1, %i0
a0148aa0:  81 c7 e0 08  ret
a0148aa4:  81 e8 00 00  restore
