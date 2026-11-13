# leon2m FUN_a015cd54 0xa015cd54-0xa015ce30 (220 bytes)
a015cd54:  9d e3 bf 98  save  %sp, -104, %sp
a015cd58:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a015cd5c:  aa 10 63 ff  or  %g1, 0x3ff, %l5	! 0xffff
a015cd60:  e8 06 60 10  ld  [ %i1 + 0x10 ], %l4
a015cd64:  a4 06 60 14  add  %i1, 0x14, %l2
a015cd68:  a6 10 20 00  clr  %l3
a015cd6c:  e2 04 80 00  ld  [ %l2 ], %l1
a015cd70:  92 10 00 1a  mov  %i2, %o1
a015cd74:  7f ff ea 20  call  0xa01575f4
a015cd78:  90 0c 40 15  and  %l1, %l5, %o0
a015cd7c:  a0 02 00 1b  add  %o0, %i3, %l0
a015cd80:  91 34 60 10  srl  %l1, 0x10, %o0
a015cd84:  7f ff ea 1c  call  0xa01575f4
a015cd88:  92 10 00 1a  mov  %i2, %o1
a015cd8c:  9b 34 20 10  srl  %l0, 0x10, %o5
a015cd90:  90 02 00 0d  add  %o0, %o5, %o0
a015cd94:  83 2a 20 10  sll  %o0, 0x10, %g1
a015cd98:  a0 0c 00 15  and  %l0, %l5, %l0
a015cd9c:  82 00 40 10  add  %g1, %l0, %g1
a015cda0:  c2 24 80 00  st  %g1, [ %l2 ]
a015cda4:  a6 04 e0 01  inc  %l3
a015cda8:  a4 04 a0 04  add  %l2, 4, %l2
a015cdac:  80 a4 c0 14  cmp  %l3, %l4
a015cdb0:  06 bf ff ef  bl  0xa015cd6c
a015cdb4:  b7 32 20 10  srl  %o0, 0x10, %i3
a015cdb8:  80 a6 e0 00  cmp  %i3, 0
a015cdbc:  02 80 00 1b  be  0xa015ce28
a015cdc0:  01 00 00 00  nop
a015cdc4:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a015cdc8:  80 a0 40 14  cmp  %g1, %l4
a015cdcc:  24 80 00 08  ble,a   0xa015cdec
a015cdd0:  d2 06 60 04  ld  [ %i1 + 4 ], %o1
a015cdd4:  83 2d 20 02  sll  %l4, 2, %g1
a015cdd8:  82 00 40 19  add  %g1, %i1, %g1
a015cddc:  a8 05 20 01  inc  %l4
a015cde0:  f6 20 60 14  st  %i3, [ %g1 + 0x14 ]
a015cde4:  10 80 00 11  b  0xa015ce28
a015cde8:  e8 26 60 10  st  %l4, [ %i1 + 0x10 ]
a015cdec:  92 02 60 01  inc  %o1
a015cdf0:  7f ff ff a5  call  0xa015cc84
a015cdf4:  90 10 00 18  mov  %i0, %o0
a015cdf8:  d4 06 60 10  ld  [ %i1 + 0x10 ], %o2
a015cdfc:  a0 10 00 08  mov  %o0, %l0
a015ce00:  95 2a a0 02  sll  %o2, 2, %o2
a015ce04:  92 06 60 0c  add  %i1, 0xc, %o1
a015ce08:  94 02 a0 08  add  %o2, 8, %o2
a015ce0c:  7f ff 7e c1  call  0xa013c910
a015ce10:  90 02 20 0c  add  %o0, 0xc, %o0
a015ce14:  92 10 00 19  mov  %i1, %o1
a015ce18:  7f ff ff c4  call  0xa015cd28
a015ce1c:  90 10 00 18  mov  %i0, %o0
a015ce20:  10 bf ff ed  b  0xa015cdd4
a015ce24:  b2 10 00 10  mov  %l0, %i1
a015ce28:  81 c7 e0 08  ret
a015ce2c:  91 e8 00 19  restore  %g0, %i1, %o0
