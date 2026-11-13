# leon2m FUN_a00da754 0xa00da754-0xa00da840 (236 bytes)
a00da754:  9d e3 bf 98  save  %sp, -104, %sp
a00da758:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00da75c:  93 2c 20 02  sll  %l0, 2, %o1
a00da760:  9e 02 40 10  add  %o1, %l0, %o7
a00da764:  95 2b e0 02  sll  %o7, 2, %o2
a00da768:  a0 02 a0 14  add  %o2, 0x14, %l0
a00da76c:  b0 0c 20 fc  and  %l0, 0xfc, %i0
a00da770:  1b 00 06 62  sethi  %hi(0x198800), %o5
a00da774:  92 10 00 18  mov  %i0, %o1
a00da778:  40 00 12 7e  call  0xa00df170
a00da77c:  90 13 61 28  or  %o5, 0x128, %o0
a00da780:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a00da784:  98 12 21 1f  or  %o0, 0x11f, %o4	! 0x51eb851f
a00da788:  80 56 00 0c  umul  %i0, %o4, %g0
a00da78c:  a3 40 00 00  rd  %y, %l1
a00da790:  a3 34 60 05  srl  %l1, 5, %l1
a00da794:  82 0c 60 ff  and  %l1, 0xff, %g1
a00da798:  96 58 60 64  smul  %g1, 0x64, %o3
a00da79c:  a0 24 00 0b  sub  %l0, %o3, %l0
a00da7a0:  13 33 33 33  sethi  %hi(0xcccccc00), %o1
a00da7a4:  9e 0c 20 fc  and  %l0, 0xfc, %o7
a00da7a8:  b0 12 60 cd  or  %o1, 0xcd, %i0
a00da7ac:  80 53 c0 18  umul  %o7, %i0, %g0
a00da7b0:  95 40 00 00  rd  %y, %o2
a00da7b4:  97 32 a0 03  srl  %o2, 3, %o3
a00da7b8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00da7bc:  91 2b 60 02  sll  %o5, 2, %o0
a00da7c0:  98 02 00 0d  add  %o0, %o5, %o4
a00da7c4:  82 03 00 0c  add  %o4, %o4, %g1
a00da7c8:  92 24 00 01  sub  %l0, %g1, %o1
a00da7cc:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00da7d0:  a0 02 60 30  add  %o1, 0x30, %l0
a00da7d4:  82 13 e2 68  or  %o7, 0x268, %g1
a00da7d8:  92 10 20 30  mov  0x30, %o1
a00da7dc:  94 10 20 62  mov  0x62, %o2
a00da7e0:  90 10 20 37  mov  0x37, %o0
a00da7e4:  96 02 e0 30  add  %o3, 0x30, %o3
a00da7e8:  d4 28 60 01  stb  %o2, [ %g1 + 1 ]
a00da7ec:  d0 28 60 04  stb  %o0, [ %g1 + 4 ]
a00da7f0:  98 10 20 34  mov  0x34, %o4
a00da7f4:  d2 28 60 06  stb  %o1, [ %g1 + 6 ]
a00da7f8:  9a 10 20 0d  mov  0xd, %o5
a00da7fc:  d2 28 60 02  stb  %o1, [ %g1 + 2 ]
a00da800:  d2 28 60 03  stb  %o1, [ %g1 + 3 ]
a00da804:  a2 04 60 30  add  %l1, 0x30, %l1
a00da808:  b0 10 20 35  mov  0x35, %i0
a00da80c:  f0 2b e2 68  stb  %i0, [ %o7 + 0x268 ]
a00da810:  d8 28 60 05  stb  %o4, [ %g1 + 5 ]
a00da814:  e2 28 60 07  stb  %l1, [ %g1 + 7 ]
a00da818:  d6 28 60 08  stb  %o3, [ %g1 + 8 ]
a00da81c:  e0 28 60 09  stb  %l0, [ %g1 + 9 ]
a00da820:  da 28 60 0a  stb  %o5, [ %g1 + 0xa ]
a00da824:  94 10 00 01  mov  %g1, %o2
a00da828:  90 10 20 02  mov  2, %o0
a00da82c:  40 01 b7 ef  call  0xa01487e8
a00da830:  92 10 20 0b  mov  0xb, %o1
a00da834:  40 01 6a 2a  call  0xa01350dc
a00da838:  81 e8 00 00  restore
a00da83c:  01 00 00 00  nop
