# leon2m FUN_a0156f34 0xa0156f34-0xa015700c (216 bytes)
a0156f34:  da 02 00 00  ld  [ %o0 ], %o5
a0156f38:  99 33 60 1f  srl  %o5, 0x1f, %o4
a0156f3c:  97 33 60 17  srl  %o5, 0x17, %o3
a0156f40:  03 3f e0 00  sethi  %hi(0xff800000), %g1
a0156f44:  d8 22 60 04  st  %o4, [ %o1 + 4 ]
a0156f48:  96 8a e0 ff  andcc  %o3, 0xff, %o3
a0156f4c:  12 80 00 07  bne  0xa0156f68
a0156f50:  94 2b 40 01  andn  %o5, %g1, %o2
a0156f54:  80 a2 a0 00  cmp  %o2, 0
a0156f58:  12 80 00 0e  bne  0xa0156f90
a0156f5c:  82 10 20 02  mov  2, %g1
a0156f60:  10 80 00 29  b  0xa0157004
a0156f64:  c2 22 40 00  st  %g1, [ %o1 ]
a0156f68:  80 a2 e0 ff  cmp  %o3, 0xff
a0156f6c:  02 80 00 1a  be  0xa0156fd4
a0156f70:  83 2a a0 07  sll  %o2, 7, %g1
a0156f74:  1b 10 00 00  sethi  %hi(0x40000000), %o5
a0156f78:  82 10 40 0d  or  %g1, %o5, %g1
a0156f7c:  98 02 ff 81  add  %o3, -127, %o4
a0156f80:  c2 22 60 0c  st  %g1, [ %o1 + 0xc ]
a0156f84:  d8 22 60 08  st  %o4, [ %o1 + 8 ]
a0156f88:  10 bf ff f6  b  0xa0156f60
a0156f8c:  82 10 20 03  mov  3, %g1
a0156f90:  9a 10 20 03  mov  3, %o5
a0156f94:  03 0f ff ff  sethi  %hi(0x3ffffc00), %g1
a0156f98:  95 2a a0 07  sll  %o2, 7, %o2
a0156f9c:  82 10 63 ff  or  %g1, 0x3ff, %g1
a0156fa0:  da 22 40 00  st  %o5, [ %o1 ]
a0156fa4:  80 a2 80 01  cmp  %o2, %g1
a0156fa8:  9a 10 3f 82  mov  -126, %o5
a0156fac:  18 80 00 07  bgu  0xa0156fc8
a0156fb0:  98 10 3f 82  mov  -126, %o4
a0156fb4:  94 02 80 0a  add  %o2, %o2, %o2
a0156fb8:  9a 03 7f ff  add  %o5, -1, %o5
a0156fbc:  80 a2 80 01  cmp  %o2, %g1
a0156fc0:  08 bf ff fd  bleu  0xa0156fb4
a0156fc4:  98 10 00 0d  mov  %o5, %o4
a0156fc8:  d4 22 60 0c  st  %o2, [ %o1 + 0xc ]
a0156fcc:  10 80 00 0e  b  0xa0157004
a0156fd0:  d8 22 60 08  st  %o4, [ %o1 + 8 ]
a0156fd4:  80 a2 a0 00  cmp  %o2, 0
a0156fd8:  02 bf ff e2  be  0xa0156f60
a0156fdc:  82 10 20 04  mov  4, %g1
a0156fe0:  03 00 04 00  sethi  %hi(0x100000), %g1
a0156fe4:  80 8a 80 01  btst  %o2, %g1
a0156fe8:  22 80 00 06  be,a   0xa0157000
a0156fec:  c0 22 40 00  clr  [ %o1 ]
a0156ff0:  82 10 20 01  mov  1, %g1
a0156ff4:  c2 22 40 00  st  %g1, [ %o1 ]
a0156ff8:  10 80 00 03  b  0xa0157004
a0156ffc:  d4 22 60 0c  st  %o2, [ %o1 + 0xc ]
a0157000:  d4 22 60 0c  st  %o2, [ %o1 + 0xc ]
a0157004:  81 c3 e0 08  retl
a0157008:  01 00 00 00  nop
