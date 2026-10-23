# leon2m FUN_a011b428 0xa011b428-0xa011b4b0 (136 bytes)
a011b428:  80 8a 20 ff  btst  0xff, %o0
a011b42c:  12 80 00 10  bne  0xa011b46c
a011b430:  19 33 c0 45  sethi  %hi(0xcf011400), %o4
a011b434:  96 13 23 84  or  %o4, 0x384, %o3	! 0xcf011784
a011b438:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011b43c:  91 32 60 08  srl  %o1, 8, %o0
a011b440:  da 22 c0 00  st  %o5, [ %o3 ]
a011b444:  82 0a 20 ff  and  %o0, 0xff, %g1
a011b448:  98 13 23 88  or  %o4, 0x388, %o4
a011b44c:  9b 32 60 10  srl  %o1, 0x10, %o5
a011b450:  c2 23 00 00  st  %g1, [ %o4 ]
a011b454:  9a 0b 60 ff  and  %o5, 0xff, %o5
a011b458:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011b45c:  92 10 63 cc  or  %g1, 0x3cc, %o1	! 0xcf00bfcc
a011b460:  da 22 40 00  st  %o5, [ %o1 ]
a011b464:  10 80 00 0d  b  0xa011b498
a011b468:  82 10 20 9f  mov  0x9f, %g1
a011b46c:  96 13 23 98  or  %o4, 0x398, %o3
a011b470:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011b474:  91 32 60 08  srl  %o1, 8, %o0
a011b478:  82 0a 20 ff  and  %o0, 0xff, %g1
a011b47c:  da 22 c0 00  st  %o5, [ %o3 ]
a011b480:  98 13 23 9c  or  %o4, 0x39c, %o4
a011b484:  91 32 60 10  srl  %o1, 0x10, %o0
a011b488:  c2 23 00 00  st  %g1, [ %o4 ]
a011b48c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a011b490:  10 bf ff f3  b  0xa011b45c
a011b494:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011b498:  01 00 00 00  nop
a011b49c:  82 80 7f ff  addcc  %g1, -1, %g1
a011b4a0:  1c bf ff fe  bpos  0xa011b498
a011b4a4:  01 00 00 00  nop
a011b4a8:  81 c3 e0 08  retl
a011b4ac:  01 00 00 00  nop
