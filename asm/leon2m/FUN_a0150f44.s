# leon2m FUN_a0150f44 0xa0150f44-0xa0151008 (196 bytes)
a0150f44:  90 0a 20 ff  and  %o0, 0xff, %o0
a0150f48:  80 a2 20 01  cmp  %o0, 1
a0150f4c:  02 80 00 17  be  0xa0150fa8
a0150f50:  98 10 3f 80  mov  -128, %o4
a0150f54:  80 a2 20 01  cmp  %o0, 1
a0150f58:  04 80 00 23  ble  0xa0150fe4
a0150f5c:  80 a2 20 02  cmp  %o0, 2
a0150f60:  02 80 00 15  be  0xa0150fb4
a0150f64:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0150f68:  96 0b 20 ff  and  %o4, 0xff, %o3
a0150f6c:  80 a2 e0 80  cmp  %o3, 0x80
a0150f70:  02 80 00 23  be  0xa0150ffc
a0150f74:  80 8b 20 80  btst  0x80, %o4
a0150f78:  12 80 00 11  bne  0xa0150fbc
a0150f7c:  91 2a 60 10  sll  %o1, 0x10, %o0
a0150f80:  98 0b 20 ff  and  %o4, 0xff, %o4
a0150f84:  82 10 20 80  mov  0x80, %g1
a0150f88:  82 20 40 0b  sub  %g1, %o3, %g1
a0150f8c:  98 03 00 09  add  %o4, %o1, %o4
a0150f90:  9b 32 20 10  srl  %o0, 0x10, %o5
a0150f94:  80 a3 40 01  cmp  %o5, %g1
a0150f98:  14 80 00 19  bg  0xa0150ffc
a0150f9c:  92 03 3f 80  add  %o4, -128, %o1
a0150fa0:  10 80 00 17  b  0xa0150ffc
a0150fa4:  92 10 20 00  clr  %o1
a0150fa8:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a0150fac:  10 bf ff ef  b  0xa0150f68
a0150fb0:  d8 0a 23 e6  ldub  [ %o0 + 0x3e6 ], %o4	! 0xa802e3e6
a0150fb4:  10 bf ff ed  b  0xa0150f68
a0150fb8:  d8 0a e3 e7  ldub  [ %o3 + 0x3e7 ], %o4
a0150fbc:  82 0b 20 ff  and  %o4, 0xff, %g1
a0150fc0:  9a 00 40 09  add  %g1, %o1, %o5
a0150fc4:  96 03 7f 80  add  %o5, -128, %o3
a0150fc8:  91 2a e0 10  sll  %o3, 0x10, %o0
a0150fcc:  93 32 20 10  srl  %o0, 0x10, %o1
a0150fd0:  80 a2 60 ff  cmp  %o1, 0xff
a0150fd4:  08 80 00 0a  bleu  0xa0150ffc
a0150fd8:  92 10 00 0b  mov  %o3, %o1
a0150fdc:  10 80 00 08  b  0xa0150ffc
a0150fe0:  92 10 20 ff  mov  0xff, %o1
a0150fe4:  80 a2 20 00  cmp  %o0, 0
a0150fe8:  12 bf ff e1  bne  0xa0150f6c
a0150fec:  96 0b 20 ff  and  %o4, 0xff, %o3
a0150ff0:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0150ff4:  10 bf ff dd  b  0xa0150f68
a0150ff8:  d8 08 63 e5  ldub  [ %g1 + 0x3e5 ], %o4	! 0xa802e3e5
a0150ffc:  99 2a 60 10  sll  %o1, 0x10, %o4
a0151000:  81 c3 e0 08  retl
a0151004:  91 33 20 10  srl  %o4, 0x10, %o0
