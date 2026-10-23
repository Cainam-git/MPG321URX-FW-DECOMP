# leon2m FUN_a011cae0 0xa011cae0-0xa011cc44 (356 bytes)
a011cae0:  80 a2 60 01  cmp  %o1, 1
a011cae4:  02 80 00 34  be  0xa011cbb4
a011cae8:  98 0a 20 ff  and  %o0, 0xff, %o4
a011caec:  1a 80 00 1e  bcc  0xa011cb64
a011caf0:  80 a2 60 02  cmp  %o1, 2
a011caf4:  98 0a 20 ff  and  %o0, 0xff, %o4
a011caf8:  80 a3 20 02  cmp  %o4, 2
a011cafc:  82 60 20 00  subx  %g0, 0, %g1
a011cb00:  94 0a 00 01  and  %o0, %g1, %o2
a011cb04:  92 0a a0 ff  and  %o2, 0xff, %o1
a011cb08:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a011cb0c:  9a 02 40 09  add  %o1, %o1, %o5
a011cb10:  94 12 e2 a8  or  %o3, 0x2a8, %o2
a011cb14:  c2 12 80 0d  lduh  [ %o2 + %o5 ], %g1
a011cb18:  96 00 60 80  add  %g1, 0x80, %o3
a011cb1c:  93 2a e0 02  sll  %o3, 2, %o1
a011cb20:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a011cb24:  82 12 40 0b  or  %o1, %o3, %g1
a011cb28:  da 00 40 00  ld  [ %g1 ], %o5
a011cb2c:  80 a3 20 01  cmp  %o4, 1
a011cb30:  98 0b 60 1f  and  %o5, 0x1f, %o4
a011cb34:  08 80 00 03  bleu  0xa011cb40
a011cb38:  82 10 00 08  mov  %o0, %g1
a011cb3c:  82 10 20 00  clr  %g1
a011cb40:  92 08 60 ff  and  %g1, 0xff, %o1
a011cb44:  82 02 40 09  add  %o1, %o1, %g1
a011cb48:  d0 12 80 01  lduh  [ %o2 + %g1 ], %o0
a011cb4c:  94 02 20 80  add  %o0, 0x80, %o2
a011cb50:  9b 2a a0 02  sll  %o2, 2, %o5
a011cb54:  90 13 40 0b  or  %o5, %o3, %o0
a011cb58:  92 0b 20 ff  and  %o4, 0xff, %o1
a011cb5c:  d2 22 00 00  st  %o1, [ %o0 ]
a011cb60:  30 80 00 37  b,a   0xa011cc3c
a011cb64:  02 80 00 25  be  0xa011cbf8
a011cb68:  98 0a 20 ff  and  %o0, 0xff, %o4
a011cb6c:  80 a2 60 03  cmp  %o1, 3
a011cb70:  12 80 00 33  bne  0xa011cc3c
a011cb74:  80 a3 20 02  cmp  %o4, 2
a011cb78:  82 60 20 00  subx  %g0, 0, %g1
a011cb7c:  94 0a 00 01  and  %o0, %g1, %o2
a011cb80:  92 0a a0 ff  and  %o2, 0xff, %o1
a011cb84:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a011cb88:  9a 02 40 09  add  %o1, %o1, %o5
a011cb8c:  94 12 e2 a8  or  %o3, 0x2a8, %o2
a011cb90:  c2 12 80 0d  lduh  [ %o2 + %o5 ], %g1
a011cb94:  96 00 60 80  add  %g1, 0x80, %o3
a011cb98:  93 2a e0 02  sll  %o3, 2, %o1
a011cb9c:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a011cba0:  82 12 40 0b  or  %o1, %o3, %g1
a011cba4:  da 00 40 00  ld  [ %g1 ], %o5
a011cba8:  80 a3 20 01  cmp  %o4, 1
a011cbac:  10 bf ff e2  b  0xa011cb34
a011cbb0:  98 13 7f e0  or  %o5, -32, %o4
a011cbb4:  80 a3 20 02  cmp  %o4, 2
a011cbb8:  92 60 20 00  subx  %g0, 0, %o1
a011cbbc:  94 0a 00 09  and  %o0, %o1, %o2
a011cbc0:  9a 0a a0 ff  and  %o2, 0xff, %o5
a011cbc4:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a011cbc8:  82 03 40 0d  add  %o5, %o5, %g1
a011cbcc:  94 12 e2 a8  or  %o3, 0x2a8, %o2
a011cbd0:  d2 12 80 01  lduh  [ %o2 + %g1 ], %o1
a011cbd4:  96 02 60 80  add  %o1, 0x80, %o3
a011cbd8:  9b 2a e0 02  sll  %o3, 2, %o5
a011cbdc:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a011cbe0:  82 13 40 0b  or  %o5, %o3, %g1
a011cbe4:  d2 00 40 00  ld  [ %g1 ], %o1
a011cbe8:  9a 0a 60 1f  and  %o1, 0x1f, %o5
a011cbec:  80 a3 20 01  cmp  %o4, 1
a011cbf0:  10 bf ff d1  b  0xa011cb34
a011cbf4:  98 13 7f 80  or  %o5, -128, %o4
a011cbf8:  80 a3 20 02  cmp  %o4, 2
a011cbfc:  92 60 20 00  subx  %g0, 0, %o1
a011cc00:  94 0a 00 09  and  %o0, %o1, %o2
a011cc04:  96 0a a0 ff  and  %o2, 0xff, %o3
a011cc08:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a011cc0c:  9a 02 c0 0b  add  %o3, %o3, %o5
a011cc10:  94 10 62 a8  or  %g1, 0x2a8, %o2
a011cc14:  d2 12 80 0d  lduh  [ %o2 + %o5 ], %o1
a011cc18:  96 02 60 80  add  %o1, 0x80, %o3
a011cc1c:  83 2a e0 02  sll  %o3, 2, %g1
a011cc20:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a011cc24:  92 10 40 0b  or  %g1, %o3, %o1
a011cc28:  da 02 40 00  ld  [ %o1 ], %o5
a011cc2c:  82 0b 60 1f  and  %o5, 0x1f, %g1
a011cc30:  80 a3 20 01  cmp  %o4, 1
a011cc34:  10 bf ff c0  b  0xa011cb34
a011cc38:  98 10 60 60  or  %g1, 0x60, %o4
a011cc3c:  81 c3 e0 08  retl
a011cc40:  01 00 00 00  nop
