# leon2m FUN_a015d4c4 0xa015d4c4-0xa015d52c (104 bytes)
a015d4c4:  98 10 00 08  mov  %o0, %o4
a015d4c8:  d0 02 20 10  ld  [ %o0 + 0x10 ], %o0
a015d4cc:  da 02 60 10  ld  [ %o1 + 0x10 ], %o5
a015d4d0:  90 a2 00 0d  subcc  %o0, %o5, %o0
a015d4d4:  12 80 00 14  bne  0xa015d524
a015d4d8:  9b 2b 60 02  sll  %o5, 2, %o5
a015d4dc:  82 02 60 14  add  %o1, 0x14, %g1
a015d4e0:  90 03 20 14  add  %o4, 0x14, %o0
a015d4e4:  82 03 40 01  add  %o5, %g1, %g1
a015d4e8:  9a 03 40 08  add  %o5, %o0, %o5
a015d4ec:  9a 03 7f fc  add  %o5, -4, %o5
a015d4f0:  82 00 7f fc  add  %g1, -4, %g1
a015d4f4:  d6 03 40 00  ld  [ %o5 ], %o3
a015d4f8:  d8 00 40 00  ld  [ %g1 ], %o4
a015d4fc:  80 a2 c0 0c  cmp  %o3, %o4
a015d500:  12 80 00 06  bne  0xa015d518
a015d504:  80 a3 40 08  cmp  %o5, %o0
a015d508:  38 bf ff fa  bgu,a   0xa015d4f0
a015d50c:  9a 03 7f fc  add  %o5, -4, %o5
a015d510:  10 80 00 05  b  0xa015d524
a015d514:  90 10 20 00  clr  %o0
a015d518:  80 a2 c0 0c  cmp  %o3, %o4
a015d51c:  82 60 20 00  subx  %g0, 0, %g1
a015d520:  90 10 60 01  or  %g1, 1, %o0
a015d524:  81 c3 e0 08  retl
a015d528:  01 00 00 00  nop
