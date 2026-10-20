# leon2m FUN_a00b9f30 0xa00b9f30-0xa00ba068 (312 bytes)
a00b9f30:  9d e3 bf 98  save  %sp, -104, %sp
a00b9f34:  e0 0f a0 5f  ldub  [ %fp + 0x5f ], %l0
a00b9f38:  40 02 42 c4  call  0xa014aa48
a00b9f3c:  90 10 20 00  clr  %o0
a00b9f40:  a4 10 00 08  mov  %o0, %l2
a00b9f44:  40 02 42 c1  call  0xa014aa48
a00b9f48:  90 10 20 01  mov  1, %o0
a00b9f4c:  a2 10 00 08  mov  %o0, %l1
a00b9f50:  40 02 42 be  call  0xa014aa48
a00b9f54:  90 10 20 02  mov  2, %o0
a00b9f58:  82 0f 60 ff  and  %i5, 0xff, %g1
a00b9f5c:  96 0e e0 ff  and  %i3, 0xff, %o3
a00b9f60:  98 0f 20 ff  and  %i4, 0xff, %o4
a00b9f64:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00b9f68:  94 20 40 0b  sub  %g1, %o3, %o2
a00b9f6c:  92 23 c0 0c  sub  %o7, %o4, %o1
a00b9f70:  9a 02 a0 01  add  %o2, 1, %o5
a00b9f74:  82 02 60 01  add  %o1, 1, %g1
a00b9f78:  b6 10 00 0b  mov  %o3, %i3
a00b9f7c:  92 5b 40 01  smul  %o5, %g1, %o1
a00b9f80:  b8 10 00 0c  mov  %o4, %i4
a00b9f84:  ba 0f 60 ff  and  %i5, 0xff, %i5
a00b9f88:  96 10 20 00  clr  %o3
a00b9f8c:  9e 02 e0 01  add  %o3, 1, %o7
a00b9f90:  9b 2b e0 10  sll  %o7, 0x10, %o5
a00b9f94:  99 2a e0 10  sll  %o3, 0x10, %o4
a00b9f98:  95 33 60 10  srl  %o5, 0x10, %o2
a00b9f9c:  9b 33 20 14  srl  %o4, 0x14, %o5
a00b9fa0:  96 10 00 0f  mov  %o7, %o3
a00b9fa4:  80 a7 00 0d  cmp  %i4, %o5
a00b9fa8:  18 80 00 17  bgu  0xa00ba004
a00b9fac:  99 33 20 10  srl  %o4, 0x10, %o4
a00b9fb0:  80 a4 00 0d  cmp  %l0, %o5
a00b9fb4:  0a 80 00 14  bcs  0xa00ba004
a00b9fb8:  82 0b 20 0f  and  %o4, 0xf, %g1
a00b9fbc:  80 a6 c0 01  cmp  %i3, %g1
a00b9fc0:  18 80 00 12  bgu  0xa00ba008
a00b9fc4:  80 a2 a0 ff  cmp  %o2, 0xff
a00b9fc8:  80 a7 40 01  cmp  %i5, %g1
a00b9fcc:  0a 80 00 0f  bcs  0xa00ba008
a00b9fd0:  80 a2 a0 ff  cmp  %o2, 0xff
a00b9fd4:  da 0b 00 12  ldub  [ %o4 + %l2 ], %o5
a00b9fd8:  de 06 00 00  ld  [ %i0 ], %o7
a00b9fdc:  82 03 c0 0d  add  %o7, %o5, %g1
a00b9fe0:  c2 26 00 00  st  %g1, [ %i0 ]
a00b9fe4:  da 0b 00 11  ldub  [ %o4 + %l1 ], %o5
a00b9fe8:  de 06 40 00  ld  [ %i1 ], %o7
a00b9fec:  82 03 c0 0d  add  %o7, %o5, %g1
a00b9ff0:  c2 26 40 00  st  %g1, [ %i1 ]
a00b9ff4:  de 0b 00 08  ldub  [ %o4 + %o0 ], %o7
a00b9ff8:  d8 06 80 00  ld  [ %i2 ], %o4
a00b9ffc:  82 03 00 0f  add  %o4, %o7, %g1
a00ba000:  c2 26 80 00  st  %g1, [ %i2 ]
a00ba004:  80 a2 a0 ff  cmp  %o2, 0xff
a00ba008:  08 bf ff e2  bleu  0xa00b9f90
a00ba00c:  9e 02 e0 01  add  %o3, 1, %o7
a00ba010:  b9 2a 60 10  sll  %o1, 0x10, %i4
a00ba014:  a3 37 20 10  srl  %i4, 0x10, %l1
a00ba018:  81 80 00 00  mov  %g0, %y
a00ba01c:  f6 06 00 00  ld  [ %i0 ], %i3
a00ba020:  01 00 00 00  nop
a00ba024:  01 00 00 00  nop
a00ba028:  b6 76 c0 11  udiv  %i3, %l1, %i3
a00ba02c:  f6 26 00 00  st  %i3, [ %i0 ]
a00ba030:  81 80 00 00  mov  %g0, %y
a00ba034:  e4 06 40 00  ld  [ %i1 ], %l2
a00ba038:  01 00 00 00  nop
a00ba03c:  01 00 00 00  nop
a00ba040:  a4 74 80 11  udiv  %l2, %l1, %l2
a00ba044:  e4 26 40 00  st  %l2, [ %i1 ]
a00ba048:  81 80 00 00  mov  %g0, %y
a00ba04c:  e0 06 80 00  ld  [ %i2 ], %l0
a00ba050:  01 00 00 00  nop
a00ba054:  01 00 00 00  nop
a00ba058:  a0 74 00 11  udiv  %l0, %l1, %l0
a00ba05c:  e0 26 80 00  st  %l0, [ %i2 ]
a00ba060:  81 c7 e0 08  ret
a00ba064:  81 e8 00 00  restore
