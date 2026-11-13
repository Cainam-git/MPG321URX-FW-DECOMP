# leon2m FUN_a0127724 0xa0127724-0xa0127898 (372 bytes)
a0127724:  9d e3 bf 90  save  %sp, -112, %sp
a0127728:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a012772c:  a2 15 60 90  or  %l5, 0x90, %l1	! 0xa802d890
a0127730:  f0 2c 60 01  stb  %i0, [ %l1 + 1 ]
a0127734:  7f ff f4 65  call  0xa01248c8
a0127738:  c0 2d 60 90  clrb  [ %l5 + 0x90 ]
a012773c:  80 8a 20 ff  btst  0xff, %o0
a0127740:  02 80 00 54  be  0xa0127890
a0127744:  15 00 06 92  sethi  %hi(0x1a4800), %o2
a0127748:  92 0e 20 ff  and  %i0, 0xff, %o1
a012774c:  7f fe de 89  call  0xa00df170
a0127750:  90 12 a2 20  or  %o2, 0x220, %o0
a0127754:  82 10 20 01  mov  1, %g1
a0127758:  a4 10 20 02  mov  2, %l2
a012775c:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a0127760:  9a 10 00 11  mov  %l1, %o5
a0127764:  92 10 20 02  mov  2, %o1
a0127768:  94 10 21 c8  mov  0x1c8, %o2
a012776c:  96 10 20 05  mov  5, %o3
a0127770:  98 10 20 00  clr  %o4
a0127774:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0127778:  40 00 80 ca  call  0xa0147aa0
a012777c:  90 10 20 60  mov  0x60, %o0
a0127780:  67 fd 96 88  call  0x4008d1a0
a0127784:  90 10 20 32  mov  0x32, %o0
a0127788:  2d 2a 00 b6  sethi  %hi(0xa802d800), %l6
a012778c:  96 10 20 05  mov  5, %o3
a0127790:  98 10 20 00  clr  %o4
a0127794:  9a 15 a0 88  or  %l6, 0x88, %o5
a0127798:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a012779c:  92 10 20 02  mov  2, %o1
a01277a0:  94 10 21 c8  mov  0x1c8, %o2
a01277a4:  40 00 80 d1  call  0xa0147ae8
a01277a8:  90 10 20 60  mov  0x60, %o0
a01277ac:  a0 15 a0 88  or  %l6, 0x88, %l0
a01277b0:  11 00 06 92  sethi  %hi(0x1a4800), %o0
a01277b4:  d4 0c 20 01  ldub  [ %l0 + 1 ], %o2
a01277b8:  d2 0d a0 88  ldub  [ %l6 + 0x88 ], %o1
a01277bc:  7f fe de 6d  call  0xa00df170
a01277c0:  90 12 22 50  or  %o0, 0x250, %o0
a01277c4:  a4 10 00 11  mov  %l1, %l2
a01277c8:  90 10 20 32  mov  0x32, %o0
a01277cc:  67 fd 96 75  call  0x4008d1a0
a01277d0:  a2 10 00 10  mov  %l0, %l1
a01277d4:  a8 10 00 15  mov  %l5, %l4
a01277d8:  a6 10 00 16  mov  %l6, %l3
a01277dc:  10 80 00 1f  b  0xa0127858
a01277e0:  a0 10 20 02  mov  2, %l0
a01277e4:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a01277e8:  80 a2 e0 09  cmp  %o3, 9
a01277ec:  18 80 00 29  bgu  0xa0127890
a01277f0:  d2 0d 20 90  ldub  [ %l4 + 0x90 ], %o1
a01277f4:  7f fe de 5f  call  0xa00df170
a01277f8:  d6 0c e0 88  ldub  [ %l3 + 0x88 ], %o3
a01277fc:  98 10 20 01  mov  1, %o4
a0127800:  d8 23 a0 60  st  %o4, [ %sp + 0x60 ]
a0127804:  92 10 20 02  mov  2, %o1
a0127808:  94 10 21 c8  mov  0x1c8, %o2
a012780c:  96 10 20 05  mov  5, %o3
a0127810:  98 10 20 00  clr  %o4
a0127814:  9a 10 00 12  mov  %l2, %o5
a0127818:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a012781c:  40 00 80 a1  call  0xa0147aa0
a0127820:  90 10 20 60  mov  0x60, %o0
a0127824:  67 fd 96 5f  call  0x4008d1a0
a0127828:  90 10 20 05  mov  5, %o0
a012782c:  92 10 20 02  mov  2, %o1
a0127830:  96 10 20 05  mov  5, %o3
a0127834:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a0127838:  90 10 20 60  mov  0x60, %o0
a012783c:  94 10 21 c8  mov  0x1c8, %o2
a0127840:  98 10 20 00  clr  %o4
a0127844:  40 00 80 a9  call  0xa0147ae8
a0127848:  9a 10 00 11  mov  %l1, %o5
a012784c:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0127850:  92 02 e0 01  add  %o3, 1, %o1
a0127854:  d2 2e 21 fd  stb  %o1, [ %i0 + 0x1fd ]
a0127858:  31 00 06 92  sethi  %hi(0x1a4800), %i0
a012785c:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a0127860:  de 0c 60 01  ldub  [ %l1 + 1 ], %o7
a0127864:  90 16 22 80  or  %i0, 0x280, %o0
a0127868:  31 2a 00 b2  sethi  %hi(0xa802c800), %i0
a012786c:  94 10 00 0d  mov  %o5, %o2
a0127870:  80 a3 40 0f  cmp  %o5, %o7
a0127874:  12 bf ff dc  bne  0xa01277e4
a0127878:  98 10 00 0f  mov  %o7, %o4
a012787c:  d2 0d 60 90  ldub  [ %l5 + 0x90 ], %o1
a0127880:  c2 0d a0 88  ldub  [ %l6 + 0x88 ], %g1
a0127884:  80 a2 40 01  cmp  %o1, %g1
a0127888:  12 bf ff d8  bne  0xa01277e8
a012788c:  d6 0e 21 fd  ldub  [ %i0 + 0x1fd ], %o3
a0127890:  81 c7 e0 08  ret
a0127894:  81 e8 00 00  restore
