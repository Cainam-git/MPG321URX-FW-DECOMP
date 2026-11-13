# leon2m FUN_a002cf78 0xa002cf78-0xa002cfac (52 bytes)
a002cf78:  9d e3 bf 98  save  %sp, -104, %sp
a002cf7c:  58 02 40 03  call  0xbcf88
a002cf80:  01 00 00 00  nop
a002cf84:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a002cf88:  9a 10 60 48  or  %g1, 0x48, %o5	! 0xcf03c848
a002cf8c:  90 0a 20 ff  and  %o0, 0xff, %o0
a002cf90:  80 a2 20 e0  cmp  %o0, 0xe0
a002cf94:  12 80 00 04  bne  0xa002cfa4
a002cf98:  82 10 60 44  or  %g1, 0x44, %g1
a002cf9c:  c0 23 40 00  clr  [ %o5 ]
a002cfa0:  c0 20 40 00  clr  [ %g1 ]
a002cfa4:  81 c7 e0 08  ret
a002cfa8:  81 e8 00 00  restore
