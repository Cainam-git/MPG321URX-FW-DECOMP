# leon2s FUN_a00cf6bc 0xa00cf6bc-0xa00cf7b4 (248 bytes)
a00cf6bc:  9d e3 bf 88  save  %sp, -120, %sp
a00cf6c0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cf6c4:  98 06 00 18  add  %i0, %i0, %o4
a00cf6c8:  98 03 00 18  add  %o4, %i0, %o4
a00cf6cc:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00cf6d0:  99 2b 20 03  sll  %o4, 3, %o4
a00cf6d4:  96 14 e3 b0  or  %l3, 0x3b0, %o3
a00cf6d8:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cf6dc:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cf6e0:  82 2b 40 01  andn  %o5, %g1, %g1
a00cf6e4:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cf6e8:  82 10 40 0d  or  %g1, %o5, %g1
a00cf6ec:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cf6f0:  a4 07 bf e8  add  %fp, -24, %l2
a00cf6f4:  15 00 01 a5  sethi  %hi(0x69400), %o2
a00cf6f8:  94 12 a0 93  or  %o2, 0x93, %o2	! 0x69493
a00cf6fc:  92 10 20 90  mov  0x90, %o1
a00cf700:  96 10 20 00  clr  %o3
a00cf704:  98 10 00 12  mov  %l2, %o4
a00cf708:  40 3b 1b 3e  call  0xa0f96400
a00cf70c:  90 10 20 00  clr  %o0
a00cf710:  90 10 00 18  mov  %i0, %o0
a00cf714:  92 10 20 0c  mov  0xc, %o1
a00cf718:  7f ff e4 34  call  0xa00c87e8
a00cf71c:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cf720:  a2 10 20 00  clr  %l1
a00cf724:  83 2c 60 10  sll  %l1, 0x10, %g1
a00cf728:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf72c:  a0 07 bf f8  add  %fp, -8, %l0
a00cf730:  a0 04 00 01  add  %l0, %g1, %l0
a00cf734:  90 10 00 18  mov  %i0, %o0
a00cf738:  7f ff e0 0e  call  0xa00c7770
a00cf73c:  92 10 20 01  mov  1, %o1
a00cf740:  9a 04 60 01  add  %l1, 1, %o5
a00cf744:  83 2b 60 10  sll  %o5, 0x10, %g1
a00cf748:  83 30 60 10  srl  %g1, 0x10, %g1
a00cf74c:  d0 2c 3f f0  stb  %o0, [ %l0 + -16 ]
a00cf750:  80 a0 60 0f  cmp  %g1, 0xf
a00cf754:  08 bf ff f4  bleu  0xa00cf724
a00cf758:  a2 10 00 0d  mov  %o5, %l1
a00cf75c:  15 00 01 a4  sethi  %hi(0x69000), %o2
a00cf760:  96 10 20 0f  mov  0xf, %o3
a00cf764:  94 12 a3 e0  or  %o2, 0x3e0, %o2
a00cf768:  98 10 00 12  mov  %l2, %o4
a00cf76c:  90 10 20 00  clr  %o0
a00cf770:  40 3b 1b 19  call  0xa0f963d4
a00cf774:  92 10 20 80  mov  0x80, %o1
a00cf778:  82 06 00 18  add  %i0, %i0, %g1
a00cf77c:  82 00 40 18  add  %g1, %i0, %g1
a00cf780:  91 28 60 03  sll  %g1, 3, %o0
a00cf784:  96 14 e3 b0  or  %l3, 0x3b0, %o3
a00cf788:  da 02 c0 08  ld  [ %o3 + %o0 ], %o5
a00cf78c:  83 33 60 15  srl  %o5, 0x15, %g1
a00cf790:  80 88 60 01  btst  1, %g1
a00cf794:  02 80 00 06  be  0xa00cf7ac
a00cf798:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cf79c:  82 2b 40 01  andn  %o5, %g1, %g1
a00cf7a0:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cf7a4:  82 10 40 0d  or  %g1, %o5, %g1
a00cf7a8:  c2 22 c0 08  st  %g1, [ %o3 + %o0 ]
a00cf7ac:  81 c7 e0 08  ret
a00cf7b0:  81 e8 00 00  restore
