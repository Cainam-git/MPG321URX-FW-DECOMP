# leon2m FUN_a00e0888 0xa00e0888-0xa00e09b8 (304 bytes)
a00e0888:  9d e3 bf 98  save  %sp, -104, %sp
a00e088c:  25 2a 00 ad  sethi  %hi(0xa802b400), %l2
a00e0890:  c2 04 a1 50  ld  [ %l2 + 0x150 ], %g1	! 0xa802b550
a00e0894:  80 a0 60 00  cmp  %g1, 0
a00e0898:  12 80 00 23  bne  0xa00e0924
a00e089c:  11 00 06 65  sethi  %hi(0x199400), %o0
a00e08a0:  a2 10 20 00  clr  %l1
a00e08a4:  10 80 00 08  b  0xa00e08c4
a00e08a8:  a6 10 00 12  mov  %l2, %l3
a00e08ac:  80 a4 00 1b  cmp  %l0, %i3
a00e08b0:  02 80 00 18  be  0xa00e0910
a00e08b4:  d6 04 e1 50  ld  [ %l3 + 0x150 ], %o3
a00e08b8:  80 a4 60 09  cmp  %l1, 9
a00e08bc:  14 80 00 21  bg  0xa00e0940
a00e08c0:  da 04 a1 50  ld  [ %l2 + 0x150 ], %o5
a00e08c4:  7f ff fd b8  call  0xa00dffa4
a00e08c8:  90 10 20 02  mov  2, %o0
a00e08cc:  92 10 00 19  mov  %i1, %o1
a00e08d0:  7f ff fe 87  call  0xa00e02ec
a00e08d4:  90 10 00 18  mov  %i0, %o0
a00e08d8:  a0 0a 00 1a  and  %o0, %i2, %l0
a00e08dc:  13 00 06 65  sethi  %hi(0x199400), %o1
a00e08e0:  d4 04 a1 50  ld  [ %l2 + 0x150 ], %o2
a00e08e4:  90 12 61 08  or  %o1, 0x108, %o0
a00e08e8:  a2 04 60 01  inc  %l1
a00e08ec:  80 a2 a0 00  cmp  %o2, 0
a00e08f0:  02 bf ff ef  be  0xa00e08ac
a00e08f4:  92 10 00 10  mov  %l0, %o1
a00e08f8:  7f ff fa 1e  call  0xa00df170
a00e08fc:  01 00 00 00  nop
a00e0900:  80 a4 00 1b  cmp  %l0, %i3
a00e0904:  12 bf ff ee  bne  0xa00e08bc
a00e0908:  80 a4 60 09  cmp  %l1, 9
a00e090c:  d6 04 e1 50  ld  [ %l3 + 0x150 ], %o3
a00e0910:  80 a2 e0 00  cmp  %o3, 0
a00e0914:  12 80 00 1c  bne  0xa00e0984
a00e0918:  19 00 06 65  sethi  %hi(0x199400), %o4
a00e091c:  10 80 00 25  b  0xa00e09b0
a00e0920:  b0 10 20 01  mov  1, %i0
a00e0924:  92 10 00 19  mov  %i1, %o1
a00e0928:  94 10 00 1a  mov  %i2, %o2
a00e092c:  96 10 00 1b  mov  %i3, %o3
a00e0930:  7f ff fa 10  call  0xa00df170
a00e0934:  90 12 20 e0  or  %o0, 0xe0, %o0
a00e0938:  10 bf ff db  b  0xa00e08a4
a00e093c:  a2 10 20 00  clr  %l1
a00e0940:  80 a3 60 00  cmp  %o5, 0
a00e0944:  12 80 00 15  bne  0xa00e0998
a00e0948:  1f 00 06 65  sethi  %hi(0x199400), %o7
a00e094c:  7f ff fb b0  call  0xa00df80c
a00e0950:  21 00 06 65  sethi  %hi(0x199400), %l0
a00e0954:  40 00 00 9b  call  0xa00e0bc0
a00e0958:  01 00 00 00  nop
a00e095c:  92 10 00 19  mov  %i1, %o1
a00e0960:  7f ff fe 63  call  0xa00e02ec
a00e0964:  90 10 00 18  mov  %i0, %o0
a00e0968:  96 10 00 08  mov  %o0, %o3
a00e096c:  90 14 21 28  or  %l0, 0x128, %o0
a00e0970:  92 10 00 19  mov  %i1, %o1
a00e0974:  94 10 00 1b  mov  %i3, %o2
a00e0978:  7f ff f9 fe  call  0xa00df170
a00e097c:  b0 10 20 00  clr  %i0
a00e0980:  30 80 00 0c  b,a   0xa00e09b0
a00e0984:  90 13 21 50  or  %o4, 0x150, %o0
a00e0988:  7f ff f9 fa  call  0xa00df170
a00e098c:  92 10 00 19  mov  %i1, %o1
a00e0990:  10 80 00 08  b  0xa00e09b0
a00e0994:  b0 10 20 01  mov  1, %i0
a00e0998:  90 13 e1 28  or  %o7, 0x128, %o0
a00e099c:  96 10 00 10  mov  %l0, %o3
a00e09a0:  92 10 00 19  mov  %i1, %o1
a00e09a4:  7f ff f9 f3  call  0xa00df170
a00e09a8:  94 10 00 1b  mov  %i3, %o2
a00e09ac:  30 bf ff e8  b,a   0xa00e094c
a00e09b0:  81 c7 e0 08  ret
a00e09b4:  81 e8 00 00  restore
