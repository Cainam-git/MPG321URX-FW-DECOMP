# leon2m FUN_a0106bfc 0xa0106bfc-0xa0106d3c (320 bytes)
a0106bfc:  9d e3 bf 98  save  %sp, -104, %sp
a0106c00:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0106c04:  92 10 20 54  mov  0x54, %o1
a0106c08:  7f ff ad 93  call  0xa00f2254
a0106c0c:  90 10 00 18  mov  %i0, %o0
a0106c10:  82 0a 20 03  and  %o0, 3, %g1
a0106c14:  92 10 20 54  mov  0x54, %o1
a0106c18:  80 a0 60 02  cmp  %g1, 2
a0106c1c:  02 80 00 42  be  0xa0106d24
a0106c20:  90 10 00 18  mov  %i0, %o0
a0106c24:  7f ff ad 8c  call  0xa00f2254
a0106c28:  01 00 00 00  nop
a0106c2c:  90 0a 20 03  and  %o0, 3, %o0
a0106c30:  80 a2 20 03  cmp  %o0, 3
a0106c34:  02 80 00 3c  be  0xa0106d24
a0106c38:  94 0e 60 ff  and  %i1, 0xff, %o2
a0106c3c:  90 10 00 18  mov  %i0, %o0
a0106c40:  80 a6 20 03  cmp  %i0, 3
a0106c44:  08 80 00 06  bleu  0xa0106c5c
a0106c48:  92 10 20 6b  mov  0x6b, %o1
a0106c4c:  80 a6 20 00  cmp  %i0, 0
a0106c50:  12 80 00 35  bne  0xa0106d24
a0106c54:  90 10 20 00  clr  %o0
a0106c58:  30 80 00 1b  b,a   0xa0106cc4
a0106c5c:  7f ff ad 8f  call  0xa00f2298
a0106c60:  01 00 00 00  nop
a0106c64:  90 10 00 18  mov  %i0, %o0
a0106c68:  94 0e a0 ff  and  %i2, 0xff, %o2
a0106c6c:  7f ff ad 8b  call  0xa00f2298
a0106c70:  92 10 20 6c  mov  0x6c, %o1
a0106c74:  94 0e e0 ff  and  %i3, 0xff, %o2
a0106c78:  90 10 00 18  mov  %i0, %o0
a0106c7c:  7f ff ad 87  call  0xa00f2298
a0106c80:  92 10 20 6d  mov  0x6d, %o1
a0106c84:  90 10 00 18  mov  %i0, %o0
a0106c88:  67 fe 1d cf  call  0x4008e3c4
a0106c8c:  92 10 20 01  mov  1, %o1
a0106c90:  90 10 00 18  mov  %i0, %o0
a0106c94:  40 00 47 65  call  0xa0118a28
a0106c98:  92 10 20 01  mov  1, %o1
a0106c9c:  90 10 00 18  mov  %i0, %o0
a0106ca0:  94 10 20 02  mov  2, %o2
a0106ca4:  7f ff ad 7d  call  0xa00f2298
a0106ca8:  92 10 20 54  mov  0x54, %o1
a0106cac:  90 10 00 18  mov  %i0, %o0
a0106cb0:  7f ff ff 1c  call  0xa0106920
a0106cb4:  92 10 20 00  clr  %o1
a0106cb8:  80 a6 20 00  cmp  %i0, 0
a0106cbc:  12 80 00 1a  bne  0xa0106d24
a0106cc0:  90 10 20 00  clr  %o0
a0106cc4:  7f ff ed cc  call  0xa01023f4
a0106cc8:  33 2a 00 b5  sethi  %hi(0xa802d400), %i1
a0106ccc:  da 06 62 a4  ld  [ %i1 + 0x2a4 ], %o5	! 0xa802d6a4
a0106cd0:  31 33 33 33  sethi  %hi(0xcccccc00), %i0
a0106cd4:  d8 03 60 34  ld  [ %o5 + 0x34 ], %o4
a0106cd8:  9e 16 20 cd  or  %i0, 0xcd, %o7
a0106cdc:  80 53 00 0f  umul  %o4, %o7, %g0
a0106ce0:  97 40 00 00  rd  %y, %o3
a0106ce4:  93 32 e0 03  srl  %o3, 3, %o1
a0106ce8:  d4 13 60 22  lduh  [ %o5 + 0x22 ], %o2
a0106cec:  a0 5a 40 0a  smul  %o1, %o2, %l0
a0106cf0:  90 10 20 00  clr  %o0
a0106cf4:  7f ff ee 7d  call  0xa01026e8
a0106cf8:  92 10 00 10  mov  %l0, %o1
a0106cfc:  a3 34 20 01  srl  %l0, 1, %l1
a0106d00:  90 10 20 01  mov  1, %o0
a0106d04:  7f ff ee 79  call  0xa01026e8
a0106d08:  92 10 00 11  mov  %l1, %o1
a0106d0c:  92 10 00 11  mov  %l1, %o1
a0106d10:  7f ff ee 76  call  0xa01026e8
a0106d14:  90 10 20 02  mov  2, %o0
a0106d18:  93 34 20 02  srl  %l0, 2, %o1
a0106d1c:  7f ff ee 73  call  0xa01026e8
a0106d20:  90 10 20 03  mov  3, %o0
a0106d24:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a0106d28:  b6 10 20 40  mov  0x40, %i3
a0106d2c:  b4 10 62 58  or  %g1, 0x258, %i2
a0106d30:  f6 26 80 00  st  %i3, [ %i2 ]
a0106d34:  81 c7 e0 08  ret
a0106d38:  81 e8 00 00  restore
