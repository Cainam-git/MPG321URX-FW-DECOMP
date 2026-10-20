# leon2s EQ_handler_2 0xa0075ffc-0xa0076180 (388 bytes)
a0075ffc:  9d e3 bf 98  save  %sp, -104, %sp
a0076000:  a0 10 20 00  clr  %l0
a0076004:  10 80 00 12  b  0xa007604c
a0076008:  a2 0e 20 ff  and  %i0, 0xff, %l1
a007600c:  da 0b 28 90  ldub  [ %o4 + 0x890 ], %o5
a0076010:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0076014:  d8 00 62 34  ld  [ %g1 + 0x234 ], %o4	! 0xa8078634
a0076018:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007601c:  82 10 62 c8  or  %g1, 0x2c8, %g1	! 0xa00b3ac8
a0076020:  d6 08 40 0d  ldub  [ %g1 + %o5 ], %o3
a0076024:  80 8b 20 02  btst  2, %o4
a0076028:  da 13 e8 86  lduh  [ %o7 + 0x886 ], %o5
a007602c:  9b 2b 60 10  sll  %o5, 0x10, %o5
a0076030:  d8 0b e8 84  ldub  [ %o7 + 0x884 ], %o4
a0076034:  96 0a e0 ff  and  %o3, 0xff, %o3
a0076038:  9b 33 60 10  srl  %o5, 0x10, %o5
a007603c:  02 80 00 04  be  0xa007604c
a0076040:  98 0b 20 ff  and  %o4, 0xff, %o4
a0076044:  7f ff f4 00  call  0xa0073044
a0076048:  01 00 00 00  nop
a007604c:  82 0c 20 ff  and  %l0, 0xff, %g1
a0076050:  17 2a 01 ea  sethi  %hi(0xa807a800), %o3
a0076054:  9a 5c 62 26  smul  %l1, 0x226, %o5
a0076058:  96 12 e1 f0  or  %o3, 0x1f0, %o3
a007605c:  98 5c 68 98  smul  %l1, 0x898, %o4
a0076060:  92 06 20 41  add  %i0, 0x41, %o1
a0076064:  9a 03 40 01  add  %o5, %g1, %o5
a0076068:  98 03 00 0b  add  %o4, %o3, %o4
a007606c:  93 2a 60 18  sll  %o1, 0x18, %o1
a0076070:  11 28 01 9b  sethi  %hi(0xa0066c00), %o0
a0076074:  9b 2b 60 02  sll  %o5, 2, %o5
a0076078:  90 12 21 b8  or  %o0, 0x1b8, %o0
a007607c:  93 3a 60 18  sra  %o1, 0x18, %o1
a0076080:  98 03 00 01  add  %o4, %g1, %o4
a0076084:  9e 03 40 0b  add  %o5, %o3, %o7
a0076088:  94 10 00 01  mov  %g1, %o2
a007608c:  80 a0 60 02  cmp  %g1, 2
a0076090:  08 bf ff df  bleu  0xa007600c
a0076094:  a0 04 20 01  inc  %l0
a0076098:  82 0e 20 ff  and  %i0, 0xff, %g1
a007609c:  9a 00 40 01  add  %g1, %g1, %o5
a00760a0:  9a 03 40 01  add  %o5, %g1, %o5
a00760a4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00760a8:  9b 2b 60 02  sll  %o5, 2, %o5
a00760ac:  82 10 60 c4  or  %g1, 0xc4, %g1
a00760b0:  9a 03 40 01  add  %o5, %g1, %o5
a00760b4:  da 0b 60 08  ldub  [ %o5 + 8 ], %o5
a00760b8:  98 10 20 00  clr  %o4
a00760bc:  82 0b 20 ff  and  %o4, 0xff, %g1
a00760c0:  80 a3 60 00  cmp  %o5, 0
a00760c4:  02 80 00 07  be  0xa00760e0
a00760c8:  98 03 20 01  inc  %o4
a00760cc:  80 a0 60 02  cmp  %g1, 2
a00760d0:  28 bf ff fc  bleu,a   0xa00760c0
a00760d4:  82 0b 20 ff  and  %o4, 0xff, %g1
a00760d8:  10 80 00 06  b  0xa00760f0
a00760dc:  82 0e 20 ff  and  %i0, 0xff, %g1
a00760e0:  80 a0 60 00  cmp  %g1, 0
a00760e4:  22 bf ff f7  be,a   0xa00760c0
a00760e8:  82 0b 20 ff  and  %o4, 0xff, %g1
a00760ec:  82 0e 20 ff  and  %i0, 0xff, %g1
a00760f0:  9a 00 40 01  add  %g1, %g1, %o5
a00760f4:  9a 03 40 01  add  %o5, %g1, %o5
a00760f8:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00760fc:  82 10 60 c4  or  %g1, 0xc4, %g1	! 0xa807ccc4
a0076100:  9b 2b 60 02  sll  %o5, 2, %o5
a0076104:  9a 03 40 01  add  %o5, %g1, %o5
a0076108:  92 10 00 0d  mov  %o5, %o1
a007610c:  94 10 20 00  clr  %o2
a0076110:  10 80 00 10  b  0xa0076150
a0076114:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a0076118:  d6 0a 60 08  ldub  [ %o1 + 8 ], %o3
a007611c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0076120:  80 a2 e0 00  cmp  %o3, 0
a0076124:  02 80 00 07  be  0xa0076140
a0076128:  98 03 20 01  inc  %o4
a007612c:  80 a3 60 02  cmp  %o5, 2
a0076130:  08 bf ff fc  bleu  0xa0076120
a0076134:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0076138:  10 80 00 06  b  0xa0076150
a007613c:  94 02 a0 01  inc  %o2
a0076140:  80 a3 60 00  cmp  %o5, 0
a0076144:  02 bf ff f7  be  0xa0076120
a0076148:  9a 0b 20 ff  and  %o4, 0xff, %o5
a007614c:  94 02 a0 01  inc  %o2
a0076150:  80 a0 60 00  cmp  %g1, 0
a0076154:  02 80 00 06  be  0xa007616c
a0076158:  9a 0a a0 ff  and  %o2, 0xff, %o5
a007615c:  80 a3 60 09  cmp  %o5, 9
a0076160:  28 bf ff ee  bleu,a   0xa0076118
a0076164:  98 10 20 00  clr  %o4
a0076168:  30 80 00 04  b,a   0xa0076178
a007616c:  80 a3 60 0d  cmp  %o5, 0xd
a0076170:  08 bf ff ea  bleu  0xa0076118
a0076174:  98 10 20 00  clr  %o4
a0076178:  81 c7 e0 08  ret
a007617c:  81 e8 00 00  restore
