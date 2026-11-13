# leon2m FUN_a01541ec 0xa01541ec-0xa01542c4 (216 bytes)
a01541ec:  9d e3 bf 88  save  %sp, -120, %sp
a01541f0:  98 10 20 00  clr  %o4
a01541f4:  9a 10 20 00  clr  %o5
a01541f8:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a01541fc:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0154200:  a4 10 20 00  clr  %l2
a0154204:  a0 10 20 00  clr  %l0
a0154208:  a2 07 bf e8  add  %fp, -24, %l1
a015420c:  96 0c 20 ff  and  %l0, 0xff, %o3
a0154210:  95 2a e0 04  sll  %o3, 4, %o2
a0154214:  90 02 a3 00  add  %o2, 0x300, %o0
a0154218:  93 2a 20 10  sll  %o0, 0x10, %o1
a015421c:  93 32 60 10  srl  %o1, 0x10, %o1
a0154220:  90 10 20 00  clr  %o0
a0154224:  94 10 20 10  mov  0x10, %o2
a0154228:  7f ff b0 4e  call  0xa0140360
a015422c:  96 10 00 11  mov  %l1, %o3
a0154230:  a0 04 20 01  inc  %l0
a0154234:  da 16 20 36  lduh  [ %i0 + 0x36 ], %o5
a0154238:  c2 17 bf f6  lduh  [ %fp + -10 ], %g1
a015423c:  80 a3 40 01  cmp  %o5, %g1
a0154240:  02 80 00 0a  be  0xa0154268
a0154244:  98 0c 20 ff  and  %l0, 0xff, %o4
a0154248:  80 a3 20 13  cmp  %o4, 0x13
a015424c:  28 bf ff f1  bleu,a   0xa0154210
a0154250:  96 0c 20 ff  and  %l0, 0xff, %o3
a0154254:  80 8c a0 ff  btst  0xff, %l2
a0154258:  02 80 00 19  be  0xa01542bc
a015425c:  82 10 20 00  clr  %g1
a0154260:  10 80 00 07  b  0xa015427c
a0154264:  c2 0f bf f5  ldub  [ %fp + -11 ], %g1
a0154268:  a4 10 20 01  mov  1, %l2
a015426c:  80 8c a0 ff  btst  0xff, %l2
a0154270:  02 80 00 13  be  0xa01542bc
a0154274:  82 10 20 00  clr  %g1
a0154278:  c2 0f bf f5  ldub  [ %fp + -11 ], %g1
a015427c:  da 17 bf e8  lduh  [ %fp + -24 ], %o5
a0154280:  d8 17 bf ea  lduh  [ %fp + -22 ], %o4
a0154284:  d2 17 bf ec  lduh  [ %fp + -20 ], %o1
a0154288:  e4 17 bf ee  lduh  [ %fp + -18 ], %l2
a015428c:  e2 17 bf f0  lduh  [ %fp + -16 ], %l1
a0154290:  e0 17 bf f2  lduh  [ %fp + -14 ], %l0
a0154294:  de 0f bf f4  ldub  [ %fp + -12 ], %o7
a0154298:  c2 2e 20 34  stb  %g1, [ %i0 + 0x34 ]
a015429c:  da 36 20 08  sth  %o5, [ %i0 + 8 ]
a01542a0:  d8 36 20 18  sth  %o4, [ %i0 + 0x18 ]
a01542a4:  d2 36 20 1a  sth  %o1, [ %i0 + 0x1a ]
a01542a8:  e4 36 20 22  sth  %l2, [ %i0 + 0x22 ]
a01542ac:  e2 36 20 24  sth  %l1, [ %i0 + 0x24 ]
a01542b0:  e0 36 20 26  sth  %l0, [ %i0 + 0x26 ]
a01542b4:  de 2e 20 20  stb  %o7, [ %i0 + 0x20 ]
a01542b8:  82 10 20 01  mov  1, %g1
a01542bc:  81 c7 e0 08  ret
a01542c0:  91 e8 00 01  restore  %g0, %g1, %o0
