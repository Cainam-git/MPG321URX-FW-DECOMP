# leon2m FUN_a01243dc 0xa01243dc-0xa0124448 (108 bytes)
a01243dc:  9d e3 bf 98  save  %sp, -104, %sp
a01243e0:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a01243e4:  a6 10 60 28  or  %g1, 0x28, %l3	! 0xa802a428
a01243e8:  a0 10 20 00  clr  %l0
a01243ec:  9a 10 20 00  clr  %o5
a01243f0:  a2 10 20 01  mov  1, %l1
a01243f4:  10 80 00 06  b  0xa012440c
a01243f8:  a4 10 20 55  mov  0x55, %l2
a01243fc:  40 00 3e a0  call  0xa0133e7c
a0124400:  d2 0c c0 0d  ldub  [ %l3 + %o5 ], %o1
a0124404:  10 80 00 0b  b  0xa0124430
a0124408:  a0 04 20 01  inc  %l0
a012440c:  91 2c 40 0d  sll  %l1, %o5, %o0
a0124410:  98 10 00 08  mov  %o0, %o4
a0124414:  93 3c 80 0d  sra  %l2, %o5, %o1
a0124418:  80 8a 60 01  btst  1, %o1
a012441c:  12 bf ff f8  bne  0xa01243fc
a0124420:  90 0a 20 ff  and  %o0, 0xff, %o0
a0124424:  40 00 3e 8d  call  0xa0133e58
a0124428:  90 0b 20 ff  and  %o4, 0xff, %o0
a012442c:  a0 04 20 01  inc  %l0
a0124430:  9a 0c 20 ff  and  %l0, 0xff, %o5
a0124434:  80 a3 60 07  cmp  %o5, 7
a0124438:  08 bf ff f6  bleu  0xa0124410
a012443c:  91 2c 40 0d  sll  %l1, %o5, %o0
a0124440:  81 c7 e0 08  ret
a0124444:  81 e8 00 00  restore
