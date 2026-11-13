# leon2m FUN_a00ab4bc 0xa00ab4bc-0xa00ab5f0 (308 bytes)
a00ab4bc:  9d e3 bf 98  save  %sp, -104, %sp
a00ab4c0:  a8 10 20 00  clr  %l4
a00ab4c4:  9a 10 20 00  clr  %o5
a00ab4c8:  91 2b 60 02  sll  %o5, 2, %o0
a00ab4cc:  82 02 00 0d  add  %o0, %o5, %g1
a00ab4d0:  a6 08 60 ff  and  %g1, 0xff, %l3
a00ab4d4:  a4 10 20 00  clr  %l2
a00ab4d8:  a2 10 20 00  clr  %l1
a00ab4dc:  90 0c a0 ff  and  %l2, 0xff, %o0
a00ab4e0:  82 02 00 13  add  %o0, %l3, %g1
a00ab4e4:  9e 00 60 06  add  %g1, 6, %o7
a00ab4e8:  9b 2b e0 10  sll  %o7, 0x10, %o5
a00ab4ec:  a1 33 60 10  srl  %o5, 0x10, %l0
a00ab4f0:  90 10 20 37  mov  0x37, %o0
a00ab4f4:  92 10 00 10  mov  %l0, %o1
a00ab4f8:  94 10 20 01  mov  1, %o2
a00ab4fc:  96 10 29 92  mov  0x992, %o3
a00ab500:  40 02 6d 60  call  0xa0146a80
a00ab504:  98 10 20 00  clr  %o4
a00ab508:  17 00 00 0d  sethi  %hi(0x3400), %o3
a00ab50c:  96 12 e0 9e  or  %o3, 0x9e, %o3	! 0x349e
a00ab510:  90 10 20 38  mov  0x38, %o0
a00ab514:  92 10 00 10  mov  %l0, %o1
a00ab518:  94 10 20 02  mov  2, %o2
a00ab51c:  40 02 6d 59  call  0xa0146a80
a00ab520:  98 10 20 00  clr  %o4
a00ab524:  90 10 20 3a  mov  0x3a, %o0
a00ab528:  92 10 00 10  mov  %l0, %o1
a00ab52c:  94 10 20 01  mov  1, %o2
a00ab530:  96 10 29 92  mov  0x992, %o3
a00ab534:  40 02 6d 53  call  0xa0146a80
a00ab538:  98 10 20 00  clr  %o4
a00ab53c:  a2 04 40 11  add  %l1, %l1, %l1
a00ab540:  94 04 60 2a  add  %l1, 0x2a, %o2
a00ab544:  98 0a a0 fe  and  %o2, 0xfe, %o4
a00ab548:  90 10 20 00  clr  %o0
a00ab54c:  92 10 20 37  mov  0x37, %o1
a00ab550:  94 10 00 10  mov  %l0, %o2
a00ab554:  96 10 20 01  mov  1, %o3
a00ab558:  40 02 6d 72  call  0xa0146b20
a00ab55c:  9a 10 20 00  clr  %o5
a00ab560:  92 04 60 17  add  %l1, 0x17, %o1
a00ab564:  98 0a 60 ff  and  %o1, 0xff, %o4
a00ab568:  90 10 20 00  clr  %o0
a00ab56c:  92 10 20 38  mov  0x38, %o1
a00ab570:  94 10 00 10  mov  %l0, %o2
a00ab574:  96 10 20 01  mov  1, %o3
a00ab578:  40 02 6d 6a  call  0xa0146b20
a00ab57c:  9a 10 20 00  clr  %o5
a00ab580:  98 04 60 18  add  %l1, 0x18, %o4
a00ab584:  98 0b 20 fe  and  %o4, 0xfe, %o4
a00ab588:  90 10 20 00  clr  %o0
a00ab58c:  92 10 20 39  mov  0x39, %o1
a00ab590:  94 10 00 10  mov  %l0, %o2
a00ab594:  96 10 20 01  mov  1, %o3
a00ab598:  40 02 6d 62  call  0xa0146b20
a00ab59c:  9a 10 20 00  clr  %o5
a00ab5a0:  a2 04 60 2b  add  %l1, 0x2b, %l1
a00ab5a4:  98 0c 60 ff  and  %l1, 0xff, %o4
a00ab5a8:  94 10 00 10  mov  %l0, %o2
a00ab5ac:  90 10 20 00  clr  %o0
a00ab5b0:  92 10 20 3a  mov  0x3a, %o1
a00ab5b4:  96 10 20 01  mov  1, %o3
a00ab5b8:  9a 10 20 00  clr  %o5
a00ab5bc:  40 02 6d 59  call  0xa0146b20
a00ab5c0:  a4 04 a0 01  inc  %l2
a00ab5c4:  a2 0c a0 ff  and  %l2, 0xff, %l1
a00ab5c8:  80 a4 60 02  cmp  %l1, 2
a00ab5cc:  08 bf ff c5  bleu  0xa00ab4e0
a00ab5d0:  90 0c a0 ff  and  %l2, 0xff, %o0
a00ab5d4:  a8 05 20 01  inc  %l4
a00ab5d8:  9a 0d 20 ff  and  %l4, 0xff, %o5
a00ab5dc:  80 a3 60 02  cmp  %o5, 2
a00ab5e0:  08 bf ff bb  bleu  0xa00ab4cc
a00ab5e4:  91 2b 60 02  sll  %o5, 2, %o0
a00ab5e8:  81 c7 e0 08  ret
a00ab5ec:  81 e8 00 00  restore
