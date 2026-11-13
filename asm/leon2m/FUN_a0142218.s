# leon2m FUN_a0142218 0xa0142218-0xa014226c (84 bytes)
a0142218:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014221c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0142220:  96 10 61 16  or  %g1, 0x116, %o3
a0142224:  94 10 3f ff  mov  -1, %o2
a0142228:  98 10 20 00  clr  %o4
a014222c:  9a 10 20 00  clr  %o5
a0142230:  83 2b 60 03  sll  %o5, 3, %g1
a0142234:  82 00 40 0d  add  %g1, %o5, %g1
a0142238:  9a 00 40 01  add  %g1, %g1, %o5
a014223c:  82 03 40 0b  add  %o5, %o3, %g1
a0142240:  da 08 60 10  ldub  [ %g1 + 0x10 ], %o5
a0142244:  80 a3 40 08  cmp  %o5, %o0
a0142248:  22 80 00 07  be,a   0xa0142264
a014224c:  94 10 00 0c  mov  %o4, %o2
a0142250:  98 03 20 01  inc  %o4
a0142254:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0142258:  80 a3 60 06  cmp  %o5, 6
a014225c:  08 bf ff f6  bleu  0xa0142234
a0142260:  83 2b 60 03  sll  %o5, 3, %g1
a0142264:  81 c3 e0 08  retl
a0142268:  90 0a a0 ff  and  %o2, 0xff, %o0
