# leon2m FUN_a00a9f30 0xa00a9f30-0xa00aa01c (236 bytes)
a00a9f30:  9d e3 bf 98  save  %sp, -104, %sp
a00a9f34:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a9f38:  82 06 00 18  add  %i0, %i0, %g1
a00a9f3c:  80 a6 20 06  cmp  %i0, 6
a00a9f40:  18 80 00 04  bgu  0xa00a9f50
a00a9f44:  82 00 7f f8  add  %g1, -8, %g1
a00a9f48:  90 06 00 18  add  %i0, %i0, %o0
a00a9f4c:  82 02 20 06  add  %o0, 6, %g1
a00a9f50:  80 8e 60 ff  btst  0xff, %i1
a00a9f54:  b0 08 60 ff  and  %g1, 0xff, %i0
a00a9f58:  02 80 00 19  be  0xa00a9fbc
a00a9f5c:  b2 10 20 00  clr  %i1
a00a9f60:  92 10 00 18  mov  %i0, %o1
a00a9f64:  90 10 20 22  mov  0x22, %o0
a00a9f68:  94 10 20 03  mov  3, %o2
a00a9f6c:  96 10 27 92  mov  0x792, %o3
a00a9f70:  40 02 72 c4  call  0xa0146a80
a00a9f74:  98 10 20 00  clr  %o4
a00a9f78:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00a9f7c:  96 03 60 22  add  %o5, 0x22, %o3
a00a9f80:  95 2a e0 10  sll  %o3, 0x10, %o2
a00a9f84:  93 32 a0 10  srl  %o2, 0x10, %o1
a00a9f88:  98 06 60 37  add  %i1, 0x37, %o4
a00a9f8c:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a9f90:  90 10 20 00  clr  %o0
a00a9f94:  94 10 00 18  mov  %i0, %o2
a00a9f98:  96 10 20 01  mov  1, %o3
a00a9f9c:  40 02 72 e1  call  0xa0146b20
a00a9fa0:  9a 10 20 00  clr  %o5
a00a9fa4:  b2 06 60 01  inc  %i1
a00a9fa8:  92 0e 60 ff  and  %i1, 0xff, %o1
a00a9fac:  80 a2 60 02  cmp  %o1, 2
a00a9fb0:  08 bf ff ed  bleu  0xa00a9f64
a00a9fb4:  92 10 00 18  mov  %i0, %o1
a00a9fb8:  30 80 00 17  b,a   0xa00aa014
a00a9fbc:  90 10 20 22  mov  0x22, %o0
a00a9fc0:  92 10 00 18  mov  %i0, %o1
a00a9fc4:  94 10 20 03  mov  3, %o2
a00a9fc8:  96 10 25 92  mov  0x592, %o3
a00a9fcc:  40 02 72 ad  call  0xa0146a80
a00a9fd0:  98 10 20 00  clr  %o4
a00a9fd4:  98 0e 60 ff  and  %i1, 0xff, %o4
a00a9fd8:  92 03 20 22  add  %o4, 0x22, %o1
a00a9fdc:  91 2a 60 10  sll  %o1, 0x10, %o0
a00a9fe0:  82 06 60 34  add  %i1, 0x34, %g1
a00a9fe4:  93 32 20 10  srl  %o0, 0x10, %o1
a00a9fe8:  98 08 60 ff  and  %g1, 0xff, %o4
a00a9fec:  90 10 20 00  clr  %o0
a00a9ff0:  94 10 00 18  mov  %i0, %o2
a00a9ff4:  96 10 20 01  mov  1, %o3
a00a9ff8:  40 02 72 ca  call  0xa0146b20
a00a9ffc:  9a 10 20 00  clr  %o5
a00aa000:  b2 06 60 01  inc  %i1
a00aa004:  9e 0e 60 ff  and  %i1, 0xff, %o7
a00aa008:  80 a3 e0 02  cmp  %o7, 2
a00aa00c:  08 bf ff ed  bleu  0xa00a9fc0
a00aa010:  90 10 20 22  mov  0x22, %o0
a00aa014:  81 c7 e0 08  ret
a00aa018:  81 e8 00 00  restore
