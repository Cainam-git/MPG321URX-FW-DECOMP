# leon2m FUN_a015cf78 0xa015cf78-0xa015d048 (208 bytes)
a015cf78:  da 02 00 00  ld  [ %o0 ], %o5
a015cf7c:  80 8b 60 07  btst  7, %o5
a015cf80:  02 80 00 0b  be  0xa015cfac
a015cf84:  98 10 00 08  mov  %o0, %o4
a015cf88:  80 8b 60 01  btst  1, %o5
a015cf8c:  12 80 00 2d  bne  0xa015d040
a015cf90:  90 10 20 00  clr  %o0
a015cf94:  80 8b 60 02  btst  2, %o5
a015cf98:  02 80 00 27  be  0xa015d034
a015cf9c:  83 33 60 01  srl  %o5, 1, %g1
a015cfa0:  c2 23 00 00  st  %g1, [ %o4 ]
a015cfa4:  10 80 00 27  b  0xa015d040
a015cfa8:  90 10 20 01  mov  1, %o0
a015cfac:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a015cfb0:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0xffff
a015cfb4:  80 8b 40 01  btst  %o5, %g1
a015cfb8:  02 80 00 1c  be  0xa015d028
a015cfbc:  82 10 20 00  clr  %g1
a015cfc0:  80 8b 60 ff  btst  0xff, %o5
a015cfc4:  12 80 00 05  bne  0xa015cfd8
a015cfc8:  80 8b 60 0f  btst  0xf, %o5
a015cfcc:  82 00 60 08  add  %g1, 8, %g1
a015cfd0:  9b 33 60 08  srl  %o5, 8, %o5
a015cfd4:  80 8b 60 0f  btst  0xf, %o5
a015cfd8:  12 80 00 05  bne  0xa015cfec
a015cfdc:  80 8b 60 03  btst  3, %o5
a015cfe0:  82 00 60 04  add  %g1, 4, %g1
a015cfe4:  9b 33 60 04  srl  %o5, 4, %o5
a015cfe8:  80 8b 60 03  btst  3, %o5
a015cfec:  12 80 00 05  bne  0xa015d000
a015cff0:  80 8b 60 01  btst  1, %o5
a015cff4:  82 00 60 02  add  %g1, 2, %g1
a015cff8:  9b 33 60 02  srl  %o5, 2, %o5
a015cffc:  80 8b 60 01  btst  1, %o5
a015d000:  32 80 00 08  bne,a   0xa015d020
a015d004:  da 23 00 00  st  %o5, [ %o4 ]
a015d008:  9b 33 60 01  srl  %o5, 1, %o5
a015d00c:  82 00 60 01  inc  %g1
a015d010:  80 a3 60 00  cmp  %o5, 0
a015d014:  02 80 00 0b  be  0xa015d040
a015d018:  90 10 20 20  mov  0x20, %o0
a015d01c:  da 23 00 00  st  %o5, [ %o4 ]
a015d020:  10 80 00 08  b  0xa015d040
a015d024:  90 10 00 01  mov  %g1, %o0
a015d028:  9b 33 60 10  srl  %o5, 0x10, %o5
a015d02c:  10 bf ff e5  b  0xa015cfc0
a015d030:  82 10 20 10  mov  0x10, %g1
a015d034:  83 33 60 02  srl  %o5, 2, %g1
a015d038:  c2 23 00 00  st  %g1, [ %o4 ]
a015d03c:  90 10 20 02  mov  2, %o0
a015d040:  81 c3 e0 08  retl
a015d044:  01 00 00 00  nop
