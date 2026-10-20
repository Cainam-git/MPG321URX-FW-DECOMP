# leon2m FUN_a0129a5c 0xa0129a5c-0xa0129aa4 (72 bytes)
a0129a5c:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0129a60:  c2 10 61 fe  lduh  [ %g1 + 0x1fe ], %g1	! 0xa802c9fe
a0129a64:  80 88 60 01  btst  1, %g1
a0129a68:  02 80 00 03  be  0xa0129a74
a0129a6c:  90 10 20 00  clr  %o0
a0129a70:  90 10 20 01  mov  1, %o0
a0129a74:  80 88 60 02  btst  2, %g1
a0129a78:  32 80 00 02  bne,a   0xa0129a80
a0129a7c:  90 02 20 01  inc  %o0
a0129a80:  80 88 60 08  btst  8, %g1
a0129a84:  32 80 00 02  bne,a   0xa0129a8c
a0129a88:  90 02 20 01  inc  %o0
a0129a8c:  80 88 60 04  btst  4, %g1
a0129a90:  02 80 00 03  be  0xa0129a9c
a0129a94:  01 00 00 00  nop
a0129a98:  90 02 20 01  inc  %o0
a0129a9c:  81 c3 e0 08  retl
a0129aa0:  90 0a 20 ff  and  %o0, 0xff, %o0
