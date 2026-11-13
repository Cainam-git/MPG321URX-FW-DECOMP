# leon2m FUN_a0121c6c 0xa0121c6c-0xa0121cf4 (136 bytes)
a0121c6c:  9d e3 bf 98  save  %sp, -104, %sp
a0121c70:  03 00 00 18  sethi  %hi(0x6000), %g1
a0121c74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0121c78:  a2 10 61 a7  or  %g1, 0x1a7, %l1
a0121c7c:  10 80 00 05  b  0xa0121c90
a0121c80:  a0 10 20 00  clr  %l0
a0121c84:  80 a0 40 11  cmp  %g1, %l1
a0121c88:  18 80 00 0b  bgu  0xa0121cb4
a0121c8c:  11 00 00 18  sethi  %hi(0x6000), %o0
a0121c90:  92 10 20 20  mov  0x20, %o1
a0121c94:  7f ff 40 c2  call  0xa00f1f9c
a0121c98:  90 10 00 18  mov  %i0, %o0
a0121c9c:  93 2c 20 10  sll  %l0, 0x10, %o1
a0121ca0:  83 32 60 10  srl  %o1, 0x10, %g1
a0121ca4:  80 8a 20 80  btst  0x80, %o0
a0121ca8:  02 bf ff f7  be  0xa0121c84
a0121cac:  a0 04 20 01  inc  %l0
a0121cb0:  11 00 00 18  sethi  %hi(0x6000), %o0
a0121cb4:  a2 12 21 a7  or  %o0, 0x1a7, %l1	! 0x61a7
a0121cb8:  10 80 00 05  b  0xa0121ccc
a0121cbc:  a0 10 20 00  clr  %l0
a0121cc0:  80 a0 40 11  cmp  %g1, %l1
a0121cc4:  18 80 00 0a  bgu  0xa0121cec
a0121cc8:  01 00 00 00  nop
a0121ccc:  90 10 00 18  mov  %i0, %o0
a0121cd0:  7f ff 40 b3  call  0xa00f1f9c
a0121cd4:  92 10 20 20  mov  0x20, %o1
a0121cd8:  95 2c 20 10  sll  %l0, 0x10, %o2
a0121cdc:  83 32 a0 10  srl  %o2, 0x10, %g1
a0121ce0:  80 8a 20 80  btst  0x80, %o0
a0121ce4:  12 bf ff f7  bne  0xa0121cc0
a0121ce8:  a0 04 20 01  inc  %l0
a0121cec:  81 c7 e0 08  ret
a0121cf0:  81 e8 00 00  restore
