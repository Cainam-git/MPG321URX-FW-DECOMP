# leon2s FUN_a00afbbc 0xa00afbbc-0xa00afd04 (328 bytes)
a00afbbc:  9d e3 bf 98  save  %sp, -104, %sp
a00afbc0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00afbc4:  90 10 00 18  mov  %i0, %o0
a00afbc8:  92 10 20 2f  mov  0x2f, %o1
a00afbcc:  7f ff dc 0d  call  0xa00a6c00
a00afbd0:  94 10 20 30  mov  0x30, %o2
a00afbd4:  90 10 00 18  mov  %i0, %o0
a00afbd8:  92 10 20 f7  mov  0xf7, %o1
a00afbdc:  7f ff dc 09  call  0xa00a6c00
a00afbe0:  94 10 20 00  clr  %o2
a00afbe4:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00afbe8:  9a 5e 21 2c  smul  %i0, 0x12c, %o5
a00afbec:  82 10 60 18  or  %g1, 0x18, %g1
a00afbf0:  a0 03 40 01  add  %o5, %g1, %l0
a00afbf4:  90 10 00 18  mov  %i0, %o0
a00afbf8:  d2 14 21 20  lduh  [ %l0 + 0x120 ], %o1
a00afbfc:  7f ff ee b9  call  0xa00ab6e0
a00afc00:  94 10 20 01  mov  1, %o2
a00afc04:  90 10 00 18  mov  %i0, %o0
a00afc08:  92 10 20 c2  mov  0xc2, %o1
a00afc0c:  94 10 20 04  mov  4, %o2
a00afc10:  7f ff dc 22  call  0xa00a6c98
a00afc14:  96 10 20 01  mov  1, %o3
a00afc18:  90 10 00 18  mov  %i0, %o0
a00afc1c:  96 10 20 01  mov  1, %o3
a00afc20:  94 10 20 08  mov  8, %o2
a00afc24:  7f ff dc 1d  call  0xa00a6c98
a00afc28:  92 10 20 c2  mov  0xc2, %o1
a00afc2c:  7f ff 76 f5  call  0xa008d800
a00afc30:  b2 10 20 23  mov  0x23, %i1
a00afc34:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00afc38:  9a 10 63 58  or  %g1, 0x358, %o5	! 0xcf011758
a00afc3c:  82 0a 20 ff  and  %o0, 0xff, %g1
a00afc40:  90 10 00 18  mov  %i0, %o0
a00afc44:  80 a0 60 81  cmp  %g1, 0x81
a00afc48:  08 80 00 05  bleu  0xa00afc5c
a00afc4c:  b4 10 20 40  mov  0x40, %i2
a00afc50:  c2 03 40 00  ld  [ %o5 ], %g1
a00afc54:  82 10 60 10  or  %g1, 0x10, %g1
a00afc58:  c2 23 40 00  st  %g1, [ %o5 ]
a00afc5c:  7f ff f0 e5  call  0xa00abff0
a00afc60:  01 00 00 00  nop
a00afc64:  7f ff f2 82  call  0xa00ac66c
a00afc68:  90 10 00 18  mov  %i0, %o0
a00afc6c:  7f ff ff 48  call  0xa00af98c
a00afc70:  90 10 00 18  mov  %i0, %o0
a00afc74:  c2 0c 21 1f  ldub  [ %l0 + 0x11f ], %g1
a00afc78:  80 a0 60 01  cmp  %g1, 1
a00afc7c:  96 10 20 00  clr  %o3
a00afc80:  94 10 20 01  mov  1, %o2
a00afc84:  90 10 00 18  mov  %i0, %o0
a00afc88:  12 80 00 05  bne  0xa00afc9c
a00afc8c:  92 10 20 01  mov  1, %o1
a00afc90:  7f ff ef 73  call  0xa00aba5c
a00afc94:  01 00 00 00  nop
a00afc98:  90 10 00 18  mov  %i0, %o0
a00afc9c:  7f ff ee fa  call  0xa00ab884
a00afca0:  92 10 20 00  clr  %o1
a00afca4:  90 10 00 18  mov  %i0, %o0
a00afca8:  92 10 20 c5  mov  0xc5, %o1
a00afcac:  7f ff db d5  call  0xa00a6c00
a00afcb0:  94 10 20 04  mov  4, %o2
a00afcb4:  90 10 00 18  mov  %i0, %o0
a00afcb8:  92 10 20 c4  mov  0xc4, %o1
a00afcbc:  7f ff db d1  call  0xa00a6c00
a00afcc0:  94 10 20 55  mov  0x55, %o2
a00afcc4:  19 2a 01 e4  sethi  %hi(0xa8079000), %o4
a00afcc8:  9a 10 20 01  mov  1, %o5
a00afccc:  c2 0b 23 72  ldub  [ %o4 + 0x372 ], %g1
a00afcd0:  9b 2b 40 18  sll  %o5, %i0, %o5
a00afcd4:  9a 28 40 0d  andn  %g1, %o5, %o5
a00afcd8:  82 10 20 10  mov  0x10, %g1
a00afcdc:  83 28 40 18  sll  %g1, %i0, %g1
a00afce0:  82 2b 40 01  andn  %o5, %g1, %g1
a00afce4:  c2 2b 23 72  stb  %g1, [ %o4 + 0x372 ]
a00afce8:  90 10 00 18  mov  %i0, %o0
a00afcec:  92 10 20 51  mov  0x51, %o1
a00afcf0:  7f ff db c4  call  0xa00a6c00
a00afcf4:  94 10 20 a0  mov  0xa0, %o2
a00afcf8:  7f ff db c2  call  0xa00a6c00
a00afcfc:  81 e8 00 00  restore
a00afd00:  01 00 00 00  nop
