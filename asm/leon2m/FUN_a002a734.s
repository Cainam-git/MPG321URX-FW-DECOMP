# leon2m FUN_a002a734 0xa002a734-0xa002a84c (280 bytes)
a002a734:  9d e3 bf 98  save  %sp, -104, %sp
a002a738:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a002a73c:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a002a740:  92 10 20 00  clr  %o1
a002a744:  40 00 06 c9  call  0xa002c268
a002a748:  15 00 00 10  sethi  %hi(0x4000), %o2
a002a74c:  13 00 00 10  sethi  %hi(0x4000), %o1
a002a750:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a754:  94 10 00 09  mov  %o1, %o2
a002a758:  40 00 06 c4  call  0xa002c268
a002a75c:  90 14 60 28  or  %l1, 0x28, %o0
a002a760:  40 00 06 bc  call  0xa002c250
a002a764:  90 14 60 a4  or  %l1, 0xa4, %o0
a002a768:  a4 10 00 08  mov  %o0, %l2
a002a76c:  40 00 06 b9  call  0xa002c250
a002a770:  90 14 60 6c  or  %l1, 0x6c, %o0
a002a774:  a0 2c 80 08  andn  %l2, %o0, %l0
a002a778:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a002a77c:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a002a780:  91 32 20 10  srl  %o0, 0x10, %o0
a002a784:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a002a788:  a4 0a 00 09  and  %o0, %o1, %l2
a002a78c:  a0 0c 00 09  and  %l0, %o1, %l0
a002a790:  b0 10 61 70  or  %g1, 0x170, %i0
a002a794:  b2 10 20 00  clr  %i1
a002a798:  98 10 20 01  mov  1, %o4
a002a79c:  b5 2b 00 19  sll  %o4, %i1, %i2
a002a7a0:  80 8e 80 10  btst  %i2, %l0
a002a7a4:  22 80 00 0f  be,a   0xa002a7e0
a002a7a8:  b2 06 60 01  inc  %i1
a002a7ac:  c2 06 23 80  ld  [ %i0 + 0x380 ], %g1
a002a7b0:  80 a0 60 00  cmp  %g1, 0
a002a7b4:  22 80 00 0b  be,a   0xa002a7e0
a002a7b8:  b2 06 60 01  inc  %i1
a002a7bc:  92 10 00 1a  mov  %i2, %o1
a002a7c0:  80 8e 80 12  btst  %i2, %l2
a002a7c4:  02 80 00 1b  be  0xa002a830
a002a7c8:  90 14 60 a4  or  %l1, 0xa4, %o0
a002a7cc:  9f c0 40 00  call  %g1
a002a7d0:  b2 06 60 01  inc  %i1
a002a7d4:  92 10 00 1a  mov  %i2, %o1
a002a7d8:  40 00 06 a1  call  0xa002c25c
a002a7dc:  90 14 60 a4  or  %l1, 0xa4, %o0
a002a7e0:  b0 06 20 04  add  %i0, 4, %i0
a002a7e4:  80 a6 60 06  cmp  %i1, 6
a002a7e8:  08 bf ff ed  bleu  0xa002a79c
a002a7ec:  98 10 20 01  mov  1, %o4
a002a7f0:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a002a7f4:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a002a7f8:  40 00 06 99  call  0xa002c25c
a002a7fc:  13 00 00 10  sethi  %hi(0x4000), %o1
a002a800:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a002a804:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a002a808:  40 00 06 95  call  0xa002c25c
a002a80c:  13 00 00 10  sethi  %hi(0x4000), %o1
a002a810:  15 00 00 10  sethi  %hi(0x4000), %o2
a002a814:  b2 10 00 0a  mov  %o2, %i1
a002a818:  90 14 60 28  or  %l1, 0x28, %o0
a002a81c:  40 00 06 93  call  0xa002c268
a002a820:  92 10 20 00  clr  %o1
a002a824:  b0 16 20 90  or  %i0, 0x90, %i0
a002a828:  40 00 06 90  call  0xa002c268
a002a82c:  95 e8 00 19  restore  %g0, %i1, %o2
a002a830:  40 00 06 8b  call  0xa002c25c
a002a834:  b2 06 60 01  inc  %i1
a002a838:  da 06 23 80  ld  [ %i0 + 0x380 ], %o5
a002a83c:  9f c3 40 00  call  %o5
a002a840:  b0 06 20 04  add  %i0, 4, %i0
a002a844:  10 bf ff e9  b  0xa002a7e8
a002a848:  80 a6 60 06  cmp  %i1, 6
