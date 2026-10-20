# leon2m FUN_a008767c 0xa008767c-0xa008796c (752 bytes)
a008767c:  9d e3 bf 88  save  %sp, -120, %sp
a0087680:  92 10 20 01  mov  1, %o1
a0087684:  40 02 f7 f7  call  0xa0145660
a0087688:  90 10 20 00  clr  %o0
a008768c:  99 2a 20 10  sll  %o0, 0x10, %o4
a0087690:  17 33 33 33  sethi  %hi(0xcccccc00), %o3
a0087694:  82 12 e0 cd  or  %o3, 0xcd, %g1	! 0xcccccccd
a0087698:  95 33 20 10  srl  %o4, 0x10, %o2
a008769c:  80 52 80 01  umul  %o2, %g1, %g0
a00876a0:  93 40 00 00  rd  %y, %o1
a00876a4:  a1 32 60 03  srl  %o1, 3, %l0
a00876a8:  40 02 f1 5b  call  0xa0143c14
a00876ac:  90 10 20 00  clr  %o0
a00876b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00876b4:  80 a2 20 08  cmp  %o0, 8
a00876b8:  a4 10 00 10  mov  %l0, %l2
a00876bc:  a2 10 20 00  clr  %l1
a00876c0:  82 10 20 00  clr  %g1
a00876c4:  08 80 00 13  bleu  0xa0087710
a00876c8:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00876cc:  a6 04 3f ac  add  %l0, -84, %l3
a00876d0:  9f 2c e0 10  sll  %l3, 0x10, %o7
a00876d4:  9b 33 e0 10  srl  %o7, 0x10, %o5
a00876d8:  80 a3 60 c3  cmp  %o5, 0xc3
a00876dc:  28 80 00 02  bleu,a   0xa00876e4
a00876e0:  a2 10 20 02  mov  2, %l1
a00876e4:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00876e8:  90 14 e2 90  or  %l3, 0x290, %o0	! 0xa802d290
a00876ec:  e0 02 20 a8  ld  [ %o0 + 0xa8 ], %l0
a00876f0:  80 8c 20 80  btst  0x80, %l0
a00876f4:  32 80 00 02  bne,a   0xa00876fc
a00876f8:  a2 10 20 03  mov  3, %l1
a00876fc:  40 01 41 93  call  0xa00d7d48
a0087700:  01 00 00 00  nop
a0087704:  80 a0 00 08  cmp  %g0, %o0
a0087708:  92 40 3f ff  addx  %g0, -1, %o1
a008770c:  82 0c 40 09  and  %l1, %o1, %g1
a0087710:  40 02 74 cc  call  0xa0124a40
a0087714:  a0 10 00 01  mov  %g1, %l0
a0087718:  98 14 e2 90  or  %l3, 0x290, %o4
a008771c:  e2 03 20 b0  ld  [ %o4 + 0xb0 ], %l1
a0087720:  80 a4 60 03  cmp  %l1, 3
a0087724:  08 80 00 04  bleu  0xa0087734
a0087728:  80 8e 20 ff  btst  0xff, %i0
a008772c:  c0 23 20 b0  clr  [ %o4 + 0xb0 ]
a0087730:  a0 10 20 00  clr  %l0
a0087734:  02 80 00 3a  be  0xa008781c
a0087738:  80 a4 20 00  cmp  %l0, 0
a008773c:  a0 10 20 00  clr  %l0
a0087740:  90 10 20 0c  mov  0xc, %o0
a0087744:  40 03 10 e0  call  0xa014bac4
a0087748:  92 10 21 34  mov  0x134, %o1
a008774c:  19 00 00 18  sethi  %hi(0x6000), %o4
a0087750:  92 13 21 a8  or  %o4, 0x1a8, %o1	! 0x61a8
a0087754:  40 03 10 dc  call  0xa014bac4
a0087758:  90 10 20 11  mov  0x11, %o0
a008775c:  90 10 20 10  mov  0x10, %o0
a0087760:  40 03 10 d9  call  0xa014bac4
a0087764:  92 10 20 e1  mov  0xe1, %o1
a0087768:  90 10 20 0e  mov  0xe, %o0
a008776c:  40 03 10 d6  call  0xa014bac4
a0087770:  92 10 20 55  mov  0x55, %o1
a0087774:  90 10 20 00  clr  %o0
a0087778:  40 03 10 d3  call  0xa014bac4
a008777c:  92 10 20 10  mov  0x10, %o1
a0087780:  90 10 20 01  mov  1, %o0
a0087784:  40 03 10 d0  call  0xa014bac4
a0087788:  92 10 20 10  mov  0x10, %o1
a008778c:  90 10 20 12  mov  0x12, %o0
a0087790:  40 03 10 cd  call  0xa014bac4
a0087794:  92 10 20 19  mov  0x19, %o1
a0087798:  90 10 20 0f  mov  0xf, %o0
a008779c:  40 03 10 ca  call  0xa014bac4
a00877a0:  92 10 20 00  clr  %o1
a00877a4:  80 a4 20 02  cmp  %l0, 2
a00877a8:  02 80 00 4b  be  0xa00878d4
a00877ac:  80 a4 20 03  cmp  %l0, 3
a00877b0:  02 80 00 27  be  0xa008784c
a00877b4:  9e 10 20 14  mov  0x14, %o7
a00877b8:  40 02 79 99  call  0xa0125e1c
a00877bc:  a4 14 e2 90  or  %l3, 0x290, %l2
a00877c0:  40 03 11 49  call  0xa014bce4
a00877c4:  90 10 20 00  clr  %o0
a00877c8:  40 01 45 43  call  0xa00d8cd4
a00877cc:  01 00 00 00  nop
a00877d0:  68 00 16 74  call  0x4008d1a0
a00877d4:  90 10 20 32  mov  0x32, %o0	! 0x32
a00877d8:  40 02 f0 3c  call  0xa01438c8
a00877dc:  90 10 20 00  clr  %o0
a00877e0:  90 10 20 01  mov  1, %o0
a00877e4:  40 03 23 e1  call  0xa0150768
a00877e8:  92 10 20 ff  mov  0xff, %o1
a00877ec:  92 10 23 ff  mov  0x3ff, %o1
a00877f0:  40 03 10 b5  call  0xa014bac4
a00877f4:  90 10 20 02  mov  2, %o0
a00877f8:  40 01 34 51  call  0xa00d493c
a00877fc:  d0 0c a0 19  ldub  [ %l2 + 0x19 ], %o0
a0087800:  40 03 06 4f  call  0xa014913c
a0087804:  90 0a 20 ff  and  %o0, 0xff, %o0
a0087808:  40 03 11 14  call  0xa014bc58
a008780c:  90 10 20 00  clr  %o0
a0087810:  40 03 18 f9  call  0xa014dbf4
a0087814:  90 10 20 00  clr  %o0
a0087818:  30 80 00 50  b,a   0xa0087958
a008781c:  02 bf ff ca  be  0xa0087744
a0087820:  90 10 20 0c  mov  0xc, %o0
a0087824:  f0 03 20 b0  ld  [ %o4 + 0xb0 ], %i0
a0087828:  80 a6 20 01  cmp  %i0, 1
a008782c:  12 bf ff c6  bne  0xa0087744
a0087830:  a0 10 00 18  mov  %i0, %l0
a0087834:  d6 03 20 a8  ld  [ %o4 + 0xa8 ], %o3
a0087838:  82 0a e0 80  and  %o3, 0x80, %g1
a008783c:  80 a0 00 01  cmp  %g0, %g1
a0087840:  94 10 20 03  mov  3, %o2
a0087844:  10 bf ff c0  b  0xa0087744
a0087848:  a0 42 bf ff  addx  %o2, -1, %l0
a008784c:  98 10 20 2d  mov  0x2d, %o4
a0087850:  96 10 20 19  mov  0x19, %o3
a0087854:  82 10 20 fa  mov  0xfa, %g1
a0087858:  94 10 20 0a  mov  0xa, %o2
a008785c:  a2 10 20 10  mov  0x10, %l1
a0087860:  b0 10 3f 80  mov  -128, %i0
a0087864:  90 07 bf e8  add  %fp, -24, %o0
a0087868:  de 2f bf e9  stb  %o7, [ %fp + -23 ]
a008786c:  d8 2f bf ea  stb  %o4, [ %fp + -22 ]
a0087870:  d6 2f bf ec  stb  %o3, [ %fp + -20 ]
a0087874:  c2 37 bf ee  sth  %g1, [ %fp + -18 ]
a0087878:  d4 2f bf f0  stb  %o2, [ %fp + -16 ]
a008787c:  e2 2f bf eb  stb  %l1, [ %fp + -21 ]
a0087880:  e4 37 bf f2  sth  %l2, [ %fp + -14 ]
a0087884:  f0 2f bf f4  stb  %i0, [ %fp + -12 ]
a0087888:  40 03 22 8f  call  0xa01502c4
a008788c:  e2 2f bf e8  stb  %l1, [ %fp + -24 ]
a0087890:  40 02 79 5c  call  0xa0125e00
a0087894:  01 00 00 00  nop
a0087898:  90 10 20 02  mov  2, %o0	! 0x2
a008789c:  40 03 10 ef  call  0xa014bc58
a00878a0:  01 00 00 00  nop
a00878a4:  40 01 34 26  call  0xa00d493c
a00878a8:  90 10 20 05  mov  5, %o0	! 0x5
a00878ac:  40 03 06 24  call  0xa014913c
a00878b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00878b4:  92 10 20 ff  mov  0xff, %o1
a00878b8:  40 03 23 ac  call  0xa0150768
a00878bc:  90 10 20 01  mov  1, %o0
a00878c0:  40 03 18 cd  call  0xa014dbf4
a00878c4:  90 10 20 01  mov  1, %o0
a00878c8:  40 02 f0 00  call  0xa01438c8
a00878cc:  90 10 20 01  mov  1, %o0
a00878d0:  30 80 00 22  b,a   0xa0087958
a00878d4:  90 10 20 01  mov  1, %o0
a00878d8:  40 03 10 7b  call  0xa014bac4
a00878dc:  92 10 20 00  clr  %o1
a00878e0:  40 03 17 09  call  0xa014d504
a00878e4:  01 00 00 00  nop
a00878e8:  80 8a 20 ff  btst  0xff, %o0
a00878ec:  22 80 00 0a  be,a   0xa0087914
a00878f0:  92 04 bf fe  add  %l2, -2, %o1
a00878f4:  21 2a 00 b8  sethi  %hi(0xa802e000), %l0
a00878f8:  27 33 33 33  sethi  %hi(0xcccccc00), %l3
a00878fc:  e4 14 23 ca  lduh  [ %l0 + 0x3ca ], %l2
a0087900:  9a 14 e0 cd  or  %l3, 0xcd, %o5
a0087904:  80 54 80 0d  umul  %l2, %o5, %g0
a0087908:  9f 40 00 00  rd  %y, %o7
a008790c:  a5 33 e0 03  srl  %o7, 3, %l2
a0087910:  92 04 bf fe  add  %l2, -2, %o1
a0087914:  91 2a 60 10  sll  %o1, 0x10, %o0
a0087918:  93 32 20 10  srl  %o0, 0x10, %o1
a008791c:  40 03 10 6a  call  0xa014bac4
a0087920:  90 10 20 03  mov  3, %o0
a0087924:  90 10 20 0c  mov  0xc, %o0
a0087928:  40 03 10 67  call  0xa014bac4
a008792c:  92 10 23 ff  mov  0x3ff, %o1
a0087930:  90 10 20 02  mov  2, %o0
a0087934:  40 03 10 64  call  0xa014bac4
a0087938:  92 10 20 b2  mov  0xb2, %o1
a008793c:  90 10 20 10  mov  0x10, %o0
a0087940:  7f ff fe e2  call  0xa00874c8
a0087944:  92 10 20 10  mov  0x10, %o1
a0087948:  40 02 79 2e  call  0xa0125e00
a008794c:  01 00 00 00  nop
a0087950:  10 bf ff d3  b  0xa008789c
a0087954:  90 10 20 01  mov  1, %o0	! 0x1
a0087958:  40 01 44 df  call  0xa00d8cd4
a008795c:  01 00 00 00  nop
a0087960:  01 00 00 00  nop
a0087964:  81 c7 e0 08  ret
a0087968:  81 e8 00 00  restore
