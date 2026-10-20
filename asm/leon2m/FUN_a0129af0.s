# leon2m FUN_a0129af0 0xa0129af0-0xa0129b38 (72 bytes)
a0129af0:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0129af4:  c2 10 62 00  lduh  [ %g1 + 0x200 ], %g1	! 0xa802ca00
a0129af8:  80 88 60 01  btst  1, %g1
a0129afc:  02 80 00 03  be  0xa0129b08
a0129b00:  90 10 20 00  clr  %o0
a0129b04:  90 10 20 01  mov  1, %o0
a0129b08:  80 88 60 02  btst  2, %g1
a0129b0c:  32 80 00 02  bne,a   0xa0129b14
a0129b10:  90 02 20 01  inc  %o0
a0129b14:  80 88 60 08  btst  8, %g1
a0129b18:  32 80 00 02  bne,a   0xa0129b20
a0129b1c:  90 02 20 01  inc  %o0
a0129b20:  80 88 60 04  btst  4, %g1
a0129b24:  02 80 00 03  be  0xa0129b30
a0129b28:  01 00 00 00  nop
a0129b2c:  90 02 20 01  inc  %o0
a0129b30:  81 c3 e0 08  retl
a0129b34:  90 0a 20 ff  and  %o0, 0xff, %o0
