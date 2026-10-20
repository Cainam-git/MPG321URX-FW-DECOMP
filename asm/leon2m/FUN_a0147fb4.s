# leon2m FUN_a0147fb4 0xa0147fb4-0xa0148120 (364 bytes)
a0147fb4:  9d e3 bf 98  save  %sp, -104, %sp
a0147fb8:  96 10 20 00  clr  %o3
a0147fbc:  98 10 20 00  clr  %o4
a0147fc0:  10 80 00 06  b  0xa0147fd8
a0147fc4:  9a 10 20 00  clr  %o5
a0147fc8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0147fcc:  80 a3 60 2c  cmp  %o5, 0x2c
a0147fd0:  18 80 00 0e  bgu  0xa0148008
a0147fd4:  01 00 00 00  nop
a0147fd8:  c2 0b 40 18  ldub  [ %o5 + %i0 ], %g1
a0147fdc:  80 a0 60 00  cmp  %g1, 0
a0147fe0:  02 80 00 32  be  0xa01480a8
a0147fe4:  80 a3 60 2c  cmp  %o5, 0x2c
a0147fe8:  32 bf ff f8  bne,a   0xa0147fc8
a0147fec:  98 03 20 01  inc  %o4
a0147ff0:  96 10 00 0c  mov  %o4, %o3
a0147ff4:  98 03 20 01  inc  %o4
a0147ff8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0147ffc:  80 a3 60 2c  cmp  %o5, 0x2c
a0148000:  28 bf ff f7  bleu,a   0xa0147fdc
a0148004:  c2 0b 40 18  ldub  [ %o5 + %i0 ], %g1
a0148008:  7f ff 70 58  call  0xa0124168
a014800c:  a2 10 00 0b  mov  %o3, %l1
a0148010:  7f ff 70 59  call  0xa0124174
a0148014:  a4 10 00 08  mov  %o0, %l2
a0148018:  a0 0c a0 ff  and  %l2, 0xff, %l0
a014801c:  15 00 00 3c  sethi  %hi(0xf000), %o2
a0148020:  96 12 a1 90  or  %o2, 0x190, %o3	! 0xf190
a0148024:  a0 04 00 10  add  %l0, %l0, %l0
a0148028:  92 04 00 0b  add  %l0, %o3, %o1
a014802c:  91 2a 60 02  sll  %o1, 2, %o0
a0148030:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a0148034:  98 12 00 0b  or  %o0, %o3, %o4
a0148038:  da 03 00 00  ld  [ %o4 ], %o5
a014803c:  80 a3 60 96  cmp  %o5, 0x96
a0148040:  32 80 00 36  bne,a   0xa0148118
a0148044:  b0 10 20 04  mov  4, %i0
a0148048:  a6 12 a1 91  or  %o2, 0x191, %l3
a014804c:  9e 04 00 13  add  %l0, %l3, %o7
a0148050:  95 2b e0 02  sll  %o7, 2, %o2
a0148054:  a4 12 80 0b  or  %o2, %o3, %l2
a0148058:  a0 0c 60 ff  and  %l1, 0xff, %l0
a014805c:  a2 10 00 0c  mov  %o4, %l1
a0148060:  a6 10 00 12  mov  %l2, %l3
a0148064:  7f ff 6e 21  call  0xa01238e8
a0148068:  01 00 00 00  nop
a014806c:  67 fd 13 9b  call  0x4008ced8
a0148070:  01 00 00 00  nop
a0148074:  90 10 00 18  mov  %i0, %o0
a0148078:  7f ff 6f 02  call  0xa0123c80
a014807c:  92 10 00 10  mov  %l0, %o1
a0148080:  98 0a 20 ff  and  %o0, 0xff, %o4
a0148084:  80 a3 20 01  cmp  %o4, 1
a0148088:  02 80 00 0a  be  0xa01480b0
a014808c:  82 10 20 46  mov  0x46, %g1
a0148090:  d2 04 40 00  ld  [ %l1 ], %o1
a0148094:  80 a2 60 96  cmp  %o1, 0x96
a0148098:  02 bf ff f3  be  0xa0148064
a014809c:  01 00 00 00  nop
a01480a0:  10 80 00 1e  b  0xa0148118
a01480a4:  b0 10 20 04  mov  4, %i0	! 0x4
a01480a8:  10 bf ff d8  b  0xa0148008
a01480ac:  96 10 00 0c  mov  %o4, %o3
a01480b0:  c2 24 80 00  st  %g1, [ %l2 ]
a01480b4:  f0 04 80 00  ld  [ %l2 ], %i0
a01480b8:  80 a6 20 46  cmp  %i0, 0x46
a01480bc:  02 80 00 0a  be  0xa01480e4
a01480c0:  01 00 00 00  nop
a01480c4:  d0 04 40 00  ld  [ %l1 ], %o0
a01480c8:  80 a2 20 9c  cmp  %o0, 0x9c
a01480cc:  02 80 00 13  be  0xa0148118
a01480d0:  b0 10 20 03  mov  3, %i0
a01480d4:  7f ff ff 27  call  0xa0147d70
a01480d8:  01 00 00 00  nop
a01480dc:  10 80 00 0f  b  0xa0148118
a01480e0:  b0 0a 20 ff  and  %o0, 0xff, %i0
a01480e4:  67 fd 13 7d  call  0x4008ced8
a01480e8:  01 00 00 00  nop
a01480ec:  da 04 c0 00  ld  [ %l3 ], %o5
a01480f0:  80 a3 60 46  cmp  %o5, 0x46
a01480f4:  12 bf ff f4  bne  0xa01480c4
a01480f8:  01 00 00 00  nop
a01480fc:  67 fd 13 77  call  0x4008ced8
a0148100:  01 00 00 00  nop
a0148104:  da 04 c0 00  ld  [ %l3 ], %o5
a0148108:  80 a3 60 46  cmp  %o5, 0x46
a014810c:  02 bf ff f6  be  0xa01480e4
a0148110:  01 00 00 00  nop
a0148114:  30 bf ff ec  b,a   0xa01480c4
a0148118:  81 c7 e0 08  ret
a014811c:  81 e8 00 00  restore
