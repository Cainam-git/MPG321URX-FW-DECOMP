# leon2m FUN_a00d5938 0xa00d5938-0xa00d59d4 (156 bytes)  [FUN_a00d59cc = unreachable ret/restore tail, merged]
a00d5938:  9d e3 bf 98  save  %sp, -104, %sp
a00d593c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00d5940:  b2 12 22 90  or  %o0, 0x290, %i1	! 0xa802d290
a00d5944:  da 06 60 a8  ld  [ %i1 + 0xa8 ], %o5
a00d5948:  03 00 00 10  sethi  %hi(0x4000), %g1
a00d594c:  80 8b 40 01  btst  %o5, %g1
a00d5950:  12 80 00 13  bne  0xa00d599c
a00d5954:  01 00 00 00  nop
a00d5958:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d595c:  80 a6 20 02  cmp  %i0, 2
a00d5960:  22 80 00 16  be,a   0xa00d59b8
a00d5964:  f2 0e 60 21  ldub  [ %i1 + 0x21 ], %i1
a00d5968:  80 a6 20 02  cmp  %i0, 2
a00d596c:  04 80 00 07  ble  0xa00d5988
a00d5970:  80 a6 20 01  cmp  %i0, 1
a00d5974:  80 a6 20 03  cmp  %i0, 3
a00d5978:  12 80 00 14  bne  0xa00d59c8
a00d597c:  01 00 00 00  nop
a00d5980:  10 80 00 10  b  0xa00d59c0
a00d5984:  f2 0e 60 22  ldub  [ %i1 + 0x22 ], %i1
a00d5988:  12 80 00 10  bne  0xa00d59c8
a00d598c:  01 00 00 00  nop
a00d5990:  f2 0e 60 20  ldub  [ %i1 + 0x20 ], %i1
a00d5994:  40 01 cf f9  call  0xa0149978
a00d5998:  91 e8 20 01  restore  %g0, 1, %o0
a00d599c:  40 01 c8 14  call  0xa01479ec
a00d59a0:  90 10 20 01  mov  1, %o0
a00d59a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d59a8:  80 a6 20 02  cmp  %i0, 2
a00d59ac:  12 bf ff f0  bne  0xa00d596c
a00d59b0:  01 00 00 00  nop
a00d59b4:  f2 0e 60 21  ldub  [ %i1 + 0x21 ], %i1
a00d59b8:  40 01 cf f0  call  0xa0149978
a00d59bc:  91 e8 20 02  restore  %g0, 2, %o0
a00d59c0:  40 01 cf ee  call  0xa0149978
a00d59c4:  91 e8 20 03  restore  %g0, 3, %o0
a00d59c8:  01 00 00 00  nop
a00d59cc:  81 c7 e0 08  ret
a00d59d0:  81 e8 00 00  restore
