# leon2s FUN_a006fd78 0xa006fd78-0xa006fedc (356 bytes)
a006fd78:  9d e3 bf 78  save  %sp, -136, %sp
a006fd7c:  a2 07 bf d8  add  %fp, -40, %l1
a006fd80:  90 10 00 11  mov  %l1, %o0
a006fd84:  92 10 20 00  clr  %o1
a006fd88:  40 01 06 09  call  0xa00b15ac
a006fd8c:  94 10 20 20  mov  0x20, %o2
a006fd90:  a0 10 20 00  clr  %l0
a006fd94:  90 10 20 0a  mov  0xa, %o0
a006fd98:  92 10 20 00  clr  %o1
a006fd9c:  94 10 00 11  mov  %l1, %o2
a006fda0:  7f ff ff 42  call  0xa006faa8
a006fda4:  96 10 20 01  mov  1, %o3
a006fda8:  da 07 bf d8  ld  [ %fp + -40 ], %o5
a006fdac:  80 a3 60 00  cmp  %o5, 0
a006fdb0:  12 bf ff fa  bne  0xa006fd98
a006fdb4:  90 10 20 0a  mov  0xa, %o0
a006fdb8:  82 0e 60 ff  and  %i1, 0xff, %g1
a006fdbc:  80 a0 60 1c  cmp  %g1, 0x1c
a006fdc0:  38 80 00 02  bgu,a   0xa006fdc8
a006fdc4:  b2 10 20 1c  mov  0x1c, %i1
a006fdc8:  90 0e 60 ff  and  %i1, 0xff, %o0
a006fdcc:  95 32 20 02  srl  %o0, 2, %o2
a006fdd0:  80 a3 40 0a  cmp  %o5, %o2
a006fdd4:  9e 0a 20 03  and  %o0, 3, %o7
a006fdd8:  1a 80 00 18  bcc  0xa006fe38
a006fddc:  92 10 20 00  clr  %o1
a006fde0:  a4 07 bf f8  add  %fp, -8, %l2
a006fde4:  9a 0c 20 ff  and  %l0, 0xff, %o5
a006fde8:  96 06 80 0d  add  %i2, %o5, %o3
a006fdec:  c2 0a e0 01  ldub  [ %o3 + 1 ], %g1
a006fdf0:  83 28 60 08  sll  %g1, 8, %g1
a006fdf4:  da 0e 80 0d  ldub  [ %i2 + %o5 ], %o5
a006fdf8:  d8 0a e0 02  ldub  [ %o3 + 2 ], %o4
a006fdfc:  9a 13 40 01  or  %o5, %g1, %o5
a006fe00:  99 2b 20 10  sll  %o4, 0x10, %o4
a006fe04:  d6 0a e0 03  ldub  [ %o3 + 3 ], %o3
a006fe08:  82 0a 60 ff  and  %o1, 0xff, %g1
a006fe0c:  9a 13 40 0c  or  %o5, %o4, %o5
a006fe10:  83 28 60 02  sll  %g1, 2, %g1
a006fe14:  97 2a e0 18  sll  %o3, 0x18, %o3
a006fe18:  92 02 60 01  inc  %o1
a006fe1c:  9a 13 40 0b  or  %o5, %o3, %o5
a006fe20:  82 00 40 12  add  %g1, %l2, %g1
a006fe24:  98 0a 60 ff  and  %o1, 0xff, %o4
a006fe28:  da 20 7f e4  st  %o5, [ %g1 + -28 ]
a006fe2c:  80 a3 00 0a  cmp  %o4, %o2
a006fe30:  0a bf ff ed  bcs  0xa006fde4
a006fe34:  a0 04 20 04  add  %l0, 4, %l0
a006fe38:  94 0b e0 ff  and  %o7, 0xff, %o2
a006fe3c:  80 a2 a0 00  cmp  %o2, 0
a006fe40:  22 80 00 16  be,a   0xa006fe98
a006fe44:  b2 06 60 04  add  %i1, 4, %i1
a006fe48:  80 a2 a0 00  cmp  %o2, 0
a006fe4c:  02 80 00 12  be  0xa006fe94
a006fe50:  92 10 20 00  clr  %o1
a006fe54:  82 0a 20 fc  and  %o0, 0xfc, %g1
a006fe58:  98 0c 20 ff  and  %l0, 0xff, %o4
a006fe5c:  9a 07 bf f8  add  %fp, -8, %o5
a006fe60:  90 00 40 0d  add  %g1, %o5, %o0
a006fe64:  96 03 00 1a  add  %o4, %i2, %o3
a006fe68:  82 0a 60 ff  and  %o1, 0xff, %g1
a006fe6c:  9b 28 60 03  sll  %g1, 3, %o5
a006fe70:  c2 0a c0 01  ldub  [ %o3 + %g1 ], %g1
a006fe74:  83 28 40 0d  sll  %g1, %o5, %g1
a006fe78:  da 02 3f e4  ld  [ %o0 + -28 ], %o5
a006fe7c:  9a 13 40 01  or  %o5, %g1, %o5
a006fe80:  92 02 60 01  inc  %o1
a006fe84:  82 0a 60 ff  and  %o1, 0xff, %g1
a006fe88:  80 a0 40 0a  cmp  %g1, %o2
a006fe8c:  0a bf ff f8  bcs  0xa006fe6c
a006fe90:  da 22 3f e4  st  %o5, [ %o0 + -28 ]
a006fe94:  b2 06 60 04  add  %i1, 4, %i1
a006fe98:  9a 0e 60 ff  and  %i1, 0xff, %o5
a006fe9c:  9b 2b 60 10  sll  %o5, 0x10, %o5
a006fea0:  83 2e 20 08  sll  %i0, 8, %g1
a006fea4:  82 10 40 0d  or  %g1, %o5, %g1
a006fea8:  82 10 60 55  or  %g1, 0x55, %g1
a006feac:  90 10 00 11  mov  %l1, %o0
a006feb0:  92 10 20 08  mov  8, %o1
a006feb4:  7f ff ff 22  call  0xa006fb3c
a006feb8:  c2 27 bf d8  st  %g1, [ %fp + -40 ]
a006febc:  94 10 00 11  mov  %l1, %o2
a006fec0:  90 10 20 0a  mov  0xa, %o0
a006fec4:  92 10 20 00  clr  %o1
a006fec8:  7f ff ff 03  call  0xa006fad4
a006fecc:  96 10 20 08  mov  8, %o3
a006fed0:  01 00 00 00  nop
a006fed4:  81 c7 e0 08  ret
a006fed8:  81 e8 00 00  restore
