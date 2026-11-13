# leon2s FUN_a0085ea8 0xa0085ea8-0xa0086030 (392 bytes)
a0085ea8:  9d e3 bf 98  save  %sp, -104, %sp
a0085eac:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a0085eb0:  82 10 62 bc  or  %g1, 0x2bc, %g1	! 0xcf0116bc
a0085eb4:  da 00 40 00  ld  [ %g1 ], %o5
a0085eb8:  9a 0b 7f bf  and  %o5, -65, %o5
a0085ebc:  da 20 40 00  st  %o5, [ %g1 ]
a0085ec0:  da 00 40 00  ld  [ %g1 ], %o5
a0085ec4:  9a 0b 7f 7f  and  %o5, -129, %o5
a0085ec8:  da 20 40 00  st  %o5, [ %g1 ]
a0085ecc:  90 10 20 01  mov  1, %o0
a0085ed0:  92 10 20 1e  mov  0x1e, %o1
a0085ed4:  94 10 20 00  clr  %o2
a0085ed8:  40 00 91 c4  call  0xa00aa5e8
a0085edc:  96 10 20 00  clr  %o3
a0085ee0:  90 10 20 00  clr  %o0
a0085ee4:  92 10 20 1e  mov  0x1e, %o1
a0085ee8:  94 10 20 00  clr  %o2
a0085eec:  40 00 91 bf  call  0xa00aa5e8
a0085ef0:  96 10 20 00  clr  %o3
a0085ef4:  90 10 20 00  clr  %o0
a0085ef8:  40 00 92 65  call  0xa00aa88c
a0085efc:  92 10 20 00  clr  %o1
a0085f00:  a4 10 20 01  mov  1, %l2
a0085f04:  90 0c a0 ff  and  %l2, 0xff, %o0
a0085f08:  40 00 92 61  call  0xa00aa88c
a0085f0c:  92 10 20 00  clr  %o1
a0085f10:  a4 04 a0 01  inc  %l2
a0085f14:  82 0c a0 ff  and  %l2, 0xff, %g1
a0085f18:  80 a0 60 04  cmp  %g1, 4
a0085f1c:  08 bf ff fb  bleu  0xa0085f08
a0085f20:  90 0c a0 ff  and  %l2, 0xff, %o0
a0085f24:  40 00 92 26  call  0xa00aa7bc
a0085f28:  01 00 00 00  nop
a0085f2c:  80 8a 20 ff  btst  0xff, %o0
a0085f30:  12 80 00 17  bne  0xa0085f8c
a0085f34:  a4 10 20 01  mov  1, %l2
a0085f38:  90 10 20 00  clr  %o0
a0085f3c:  40 00 91 1a  call  0xa00aa3a4
a0085f40:  21 2a 01 ea  sethi  %hi(0xa807a800), %l0
a0085f44:  a0 14 21 28  or  %l0, 0x128, %l0	! 0xa807a928
a0085f48:  d2 04 20 20  ld  [ %l0 + 0x20 ], %o1
a0085f4c:  93 32 60 0c  srl  %o1, 0xc, %o1
a0085f50:  92 0a 60 01  and  %o1, 1, %o1
a0085f54:  40 00 91 42  call  0xa00aa45c
a0085f58:  90 10 20 00  clr  %o0
a0085f5c:  d2 04 20 20  ld  [ %l0 + 0x20 ], %o1
a0085f60:  93 32 60 0d  srl  %o1, 0xd, %o1
a0085f64:  92 0a 60 03  and  %o1, 3, %o1
a0085f68:  40 00 91 4d  call  0xa00aa49c
a0085f6c:  90 10 20 00  clr  %o0
a0085f70:  7f ff ff 04  call  0xa0085b80
a0085f74:  90 10 20 00  clr  %o0
a0085f78:  7f ff ff 95  call  0xa0085dcc
a0085f7c:  90 10 20 00  clr  %o0
a0085f80:  7f ff fe e5  call  0xa0085b14
a0085f84:  90 10 20 00  clr  %o0
a0085f88:  a4 10 20 01  mov  1, %l2
a0085f8c:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0085f90:  40 00 92 0d  call  0xa00aa7c4
a0085f94:  90 10 00 11  mov  %l1, %o0
a0085f98:  80 8a 20 ff  btst  0xff, %o0
a0085f9c:  a4 04 a0 01  inc  %l2
a0085fa0:  12 80 00 19  bne  0xa0086004
a0085fa4:  90 10 00 11  mov  %l1, %o0
a0085fa8:  40 00 90 ff  call  0xa00aa3a4
a0085fac:  a1 2c 60 02  sll  %l1, 2, %l0
a0085fb0:  a0 04 00 11  add  %l0, %l1, %l0
a0085fb4:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0085fb8:  82 10 61 28  or  %g1, 0x128, %g1	! 0xa807a928
a0085fbc:  a1 2c 20 03  sll  %l0, 3, %l0
a0085fc0:  a0 04 00 01  add  %l0, %g1, %l0
a0085fc4:  d2 04 20 20  ld  [ %l0 + 0x20 ], %o1
a0085fc8:  93 32 60 0c  srl  %o1, 0xc, %o1
a0085fcc:  92 0a 60 01  and  %o1, 1, %o1
a0085fd0:  40 00 91 23  call  0xa00aa45c
a0085fd4:  90 10 00 11  mov  %l1, %o0
a0085fd8:  d2 04 20 20  ld  [ %l0 + 0x20 ], %o1
a0085fdc:  93 32 60 0d  srl  %o1, 0xd, %o1
a0085fe0:  92 0a 60 03  and  %o1, 3, %o1
a0085fe4:  40 00 91 2e  call  0xa00aa49c
a0085fe8:  90 10 00 11  mov  %l1, %o0
a0085fec:  7f ff fe e5  call  0xa0085b80
a0085ff0:  90 10 00 11  mov  %l1, %o0
a0085ff4:  7f ff ff 76  call  0xa0085dcc
a0085ff8:  90 10 00 11  mov  %l1, %o0
a0085ffc:  7f ff fe c6  call  0xa0085b14
a0086000:  90 10 00 11  mov  %l1, %o0
a0086004:  82 0c a0 ff  and  %l2, 0xff, %g1
a0086008:  80 a0 60 04  cmp  %g1, 4
a008600c:  28 bf ff e1  bleu,a   0xa0085f90
a0086010:  a2 0c a0 ff  and  %l2, 0xff, %l1
a0086014:  1b 33 c0 3c  sethi  %hi(0xcf00f000), %o5
a0086018:  9a 13 62 1c  or  %o5, 0x21c, %o5	! 0xcf00f21c
a008601c:  c2 03 40 00  ld  [ %o5 ], %g1
a0086020:  82 08 7f e7  and  %g1, -25, %g1
a0086024:  c2 23 40 00  st  %g1, [ %o5 ]
a0086028:  81 c7 e0 08  ret
a008602c:  81 e8 00 00  restore
