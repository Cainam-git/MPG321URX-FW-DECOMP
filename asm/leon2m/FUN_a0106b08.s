# leon2m FUN_a0106b08 0xa0106b08-0xa0106ba8 (160 bytes)
a0106b08:  9d e3 bf 98  save  %sp, -104, %sp
a0106b0c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0106b10:  94 10 20 00  clr  %o2
a0106b14:  92 10 20 54  mov  0x54, %o1
a0106b18:  80 a6 20 03  cmp  %i0, 3
a0106b1c:  18 80 00 21  bgu  0xa0106ba0
a0106b20:  90 10 00 18  mov  %i0, %o0
a0106b24:  7f ff ad dd  call  0xa00f2298
a0106b28:  01 00 00 00  nop
a0106b2c:  90 10 00 18  mov  %i0, %o0
a0106b30:  7f ff ff 7c  call  0xa0106920
a0106b34:  92 10 20 01  mov  1, %o1
a0106b38:  67 fe 1d db  call  0x4008e2a4
a0106b3c:  01 00 00 00  nop
a0106b40:  67 fe 1d d9  call  0x4008e2a4
a0106b44:  01 00 00 00  nop
a0106b48:  67 fe 1d d7  call  0x4008e2a4
a0106b4c:  01 00 00 00  nop
a0106b50:  80 a6 20 00  cmp  %i0, 0
a0106b54:  02 80 00 0f  be  0xa0106b90
a0106b58:  01 00 00 00  nop
a0106b5c:  15 33 c0 3a  sethi  %hi(0xcf00e800), %o2
a0106b60:  98 12 a2 c8  or  %o2, 0x2c8, %o4	! 0xcf00eac8
a0106b64:  d0 03 00 00  ld  [ %o4 ], %o0
a0106b68:  f0 03 00 00  ld  [ %o4 ], %i0
a0106b6c:  9e 0e 3f ef  and  %i0, -17, %o7
a0106b70:  de 23 00 00  st  %o7, [ %o4 ]
a0106b74:  9a 12 a1 c4  or  %o2, 0x1c4, %o5
a0106b78:  d2 03 40 00  ld  [ %o5 ], %o1
a0106b7c:  82 0a 7f 7f  and  %o1, -129, %g1
a0106b80:  c2 23 40 00  st  %g1, [ %o5 ]
a0106b84:  96 0a 20 ff  and  %o0, 0xff, %o3
a0106b88:  d6 23 00 00  st  %o3, [ %o4 ]
a0106b8c:  30 80 00 05  b,a   0xa0106ba0
a0106b90:  40 00 12 d5  call  0xa010b6e4
a0106b94:  01 00 00 00  nop
a0106b98:  10 bf ff f2  b  0xa0106b60
a0106b9c:  15 33 c0 3a  sethi  %hi(0xcf00e800), %o2
a0106ba0:  81 c7 e0 08  ret
a0106ba4:  81 e8 00 00  restore
