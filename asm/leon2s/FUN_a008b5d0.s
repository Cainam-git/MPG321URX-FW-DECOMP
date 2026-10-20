# leon2s FUN_a008b5d0 0xa008b5d0-0xa008b694 (196 bytes)  [FUN_a008b68c = unreachable ret/restore tail, merged]
a008b5d0:  9d e3 bf 98  save  %sp, -104, %sp
a008b5d4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a008b5d8:  80 a4 20 03  cmp  %l0, 3
a008b5dc:  18 80 00 2b  bgu  0xa008b688
a008b5e0:  82 10 00 19  mov  %i1, %g1
a008b5e4:  92 10 20 07  mov  7, %o1
a008b5e8:  90 10 00 10  mov  %l0, %o0
a008b5ec:  b0 10 00 10  mov  %l0, %i0
a008b5f0:  b2 10 20 07  mov  7, %i1
a008b5f4:  b4 10 20 10  mov  0x10, %i2
a008b5f8:  80 88 60 ff  btst  0xff, %g1
a008b5fc:  02 80 00 21  be  0xa008b680
a008b600:  b6 10 20 00  clr  %i3
a008b604:  40 00 6e ec  call  0xa00a71b4
a008b608:  01 00 00 00  nop
a008b60c:  80 8a 20 10  btst  0x10, %o0
a008b610:  94 10 20 10  mov  0x10, %o2
a008b614:  96 10 20 10  mov  0x10, %o3
a008b618:  90 10 00 10  mov  %l0, %o0
a008b61c:  12 80 00 04  bne  0xa008b62c
a008b620:  92 10 20 07  mov  7, %o1
a008b624:  40 00 6e f6  call  0xa00a71fc
a008b628:  01 00 00 00  nop
a008b62c:  92 10 20 01  mov  1, %o1	! 0x1
a008b630:  40 00 6e e1  call  0xa00a71b4
a008b634:  90 10 00 10  mov  %l0, %o0
a008b638:  82 0a 20 0e  and  %o0, 0xe, %g1
a008b63c:  92 10 20 0f  mov  0xf, %o1
a008b640:  80 a0 60 02  cmp  %g1, 2
a008b644:  02 80 00 11  be  0xa008b688
a008b648:  90 10 00 10  mov  %l0, %o0
a008b64c:  40 00 6e da  call  0xa00a71b4
a008b650:  b2 10 20 03  mov  3, %i1
a008b654:  82 0a 20 ff  and  %o0, 0xff, %g1
a008b658:  92 10 20 03  mov  3, %o1
a008b65c:  94 10 20 02  mov  2, %o2
a008b660:  96 10 20 00  clr  %o3
a008b664:  90 10 00 10  mov  %l0, %o0
a008b668:  b4 10 20 02  mov  2, %i2
a008b66c:  80 a0 60 f0  cmp  %g1, 0xf0
a008b670:  12 80 00 06  bne  0xa008b688
a008b674:  b6 10 20 02  mov  2, %i3
a008b678:  40 00 6e e1  call  0xa00a71fc
a008b67c:  b0 10 00 10  mov  %l0, %i0
a008b680:  40 00 6e df  call  0xa00a71fc
a008b684:  81 e8 00 00  restore
a008b688:  01 00 00 00  nop
a008b68c:  81 c7 e0 08  ret
a008b690:  81 e8 00 00  restore
