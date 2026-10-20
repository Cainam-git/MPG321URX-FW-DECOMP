# leon2m FUN_a012629c 0xa012629c-0xa0126310 (116 bytes)
a012629c:  9d e3 bf 98  save  %sp, -104, %sp
a01262a0:  82 10 20 01  mov  1, %g1
a01262a4:  98 10 20 00  clr  %o4
a01262a8:  82 08 60 ff  and  %g1, 0xff, %g1
a01262ac:  80 88 60 01  btst  1, %g1
a01262b0:  12 80 00 09  bne  0xa01262d4
a01262b4:  83 30 60 01  srl  %g1, 1, %g1
a01262b8:  98 03 20 01  inc  %o4
a01262bc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01262c0:  80 a3 60 07  cmp  %o5, 7
a01262c4:  08 bf ff fa  bleu  0xa01262ac
a01262c8:  82 08 60 ff  and  %g1, 0xff, %g1
a01262cc:  10 80 00 04  b  0xa01262dc
a01262d0:  94 03 40 0d  add  %o5, %o5, %o2
a01262d4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01262d8:  94 03 40 0d  add  %o5, %o5, %o2
a01262dc:  11 00 06 90  sethi  %hi(0x1a4000), %o0
a01262e0:  a0 02 80 0d  add  %o2, %o5, %l0
a01262e4:  a2 12 23 71  or  %o0, 0x371, %l1
a01262e8:  7f fe e0 57  call  0xa00de444
a01262ec:  d0 0c 40 10  ldub  [ %l1 + %l0 ], %o0
a01262f0:  a0 04 00 11  add  %l0, %l1, %l0
a01262f4:  d2 0c 20 02  ldub  [ %l0 + 2 ], %o1
a01262f8:  da 0c 20 01  ldub  [ %l0 + 1 ], %o5
a01262fc:  d2 2e 20 02  stb  %o1, [ %i0 + 2 ]
a0126300:  d0 36 00 00  sth  %o0, [ %i0 ]
a0126304:  da 2e 20 03  stb  %o5, [ %i0 + 3 ]
a0126308:  81 c7 e0 08  ret
a012630c:  81 e8 00 00  restore
