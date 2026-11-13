# leon2s FUN_a00ae850 0xa00ae850-0xa00aea0c (444 bytes)
a00ae850:  9d e3 bf 98  save  %sp, -104, %sp
a00ae854:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00ae858:  c2 08 61 37  ldub  [ %g1 + 0x137 ], %g1	! 0xa807dd37
a00ae85c:  80 a0 60 01  cmp  %g1, 1
a00ae860:  12 80 00 05  bne  0xa00ae874
a00ae864:  03 33 c0 11  sethi  %hi(0xcf004400), %g1
a00ae868:  7f ff ff 5f  call  0xa00ae5e4
a00ae86c:  90 10 20 00  clr  %o0
a00ae870:  03 33 c0 11  sethi  %hi(0xcf004400), %g1
a00ae874:  82 10 62 80  or  %g1, 0x280, %g1	! 0xcf004680
a00ae878:  c2 00 40 00  ld  [ %g1 ], %g1
a00ae87c:  80 88 60 02  btst  2, %g1
a00ae880:  02 80 00 60  be  0xa00aea00
a00ae884:  03 00 00 3a  sethi  %hi(0xe800), %g1
a00ae888:  98 10 62 5f  or  %g1, 0x25f, %o4	! 0xea5f
a00ae88c:  92 10 20 00  clr  %o1
a00ae890:  01 00 00 00  nop
a00ae894:  9a 02 60 01  add  %o1, 1, %o5
a00ae898:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ae89c:  83 30 60 10  srl  %g1, 0x10, %g1
a00ae8a0:  80 a0 40 0c  cmp  %g1, %o4
a00ae8a4:  08 bf ff fb  bleu  0xa00ae890
a00ae8a8:  92 10 00 0d  mov  %o5, %o1
a00ae8ac:  1b 33 c0 0e  sethi  %hi(0xcf003800), %o5
a00ae8b0:  c2 03 40 00  ld  [ %o5 ], %g1
a00ae8b4:  80 a0 60 00  cmp  %g1, 0
a00ae8b8:  02 80 00 23  be  0xa00ae944
a00ae8bc:  82 13 61 80  or  %o5, 0x180, %g1
a00ae8c0:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00ae8c4:  b0 10 62 3d  or  %g1, 0x23d, %i0	! 0xa807963d
a00ae8c8:  92 10 20 00  clr  %o1
a00ae8cc:  11 2a 01 e2  sethi  %hi(0xa8078800), %o0
a00ae8d0:  1f 33 c0 00  sethi  %hi(0xcf000000), %o7
a00ae8d4:  95 2a 60 10  sll  %o1, 0x10, %o2
a00ae8d8:  da 0a 20 30  ldub  [ %o0 + 0x30 ], %o5
a00ae8dc:  95 32 a0 10  srl  %o2, 0x10, %o2
a00ae8e0:  82 03 40 0d  add  %o5, %o5, %g1
a00ae8e4:  96 02 ae 00  add  %o2, 0xe00, %o3
a00ae8e8:  82 00 40 0d  add  %g1, %o5, %g1
a00ae8ec:  97 2a e0 02  sll  %o3, 2, %o3
a00ae8f0:  96 12 c0 0f  or  %o3, %o7, %o3
a00ae8f4:  92 02 60 01  inc  %o1
a00ae8f8:  83 28 60 04  sll  %g1, 4, %g1
a00ae8fc:  da 02 c0 00  ld  [ %o3 ], %o5
a00ae900:  82 00 40 18  add  %g1, %i0, %g1
a00ae904:  99 2a 60 10  sll  %o1, 0x10, %o4
a00ae908:  da 28 40 0a  stb  %o5, [ %g1 + %o2 ]
a00ae90c:  99 33 20 10  srl  %o4, 0x10, %o4
a00ae910:  c0 22 c0 00  clr  [ %o3 ]
a00ae914:  80 a3 20 2f  cmp  %o4, 0x2f
a00ae918:  08 bf ff f0  bleu  0xa00ae8d8
a00ae91c:  95 2a 60 10  sll  %o1, 0x10, %o2
a00ae920:  c2 0a 20 30  ldub  [ %o0 + 0x30 ], %g1
a00ae924:  80 a0 60 0e  cmp  %g1, 0xe
a00ae928:  38 80 00 05  bgu,a   0xa00ae93c
a00ae92c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00ae930:  82 00 60 01  inc  %g1
a00ae934:  10 80 00 20  b  0xa00ae9b4
a00ae938:  c2 2a 20 30  stb  %g1, [ %o0 + 0x30 ]
a00ae93c:  10 80 00 1e  b  0xa00ae9b4
a00ae940:  c0 28 60 30  clrb  [ %g1 + 0x30 ]
a00ae944:  c2 00 40 00  ld  [ %g1 ], %g1
a00ae948:  80 a0 60 00  cmp  %g1, 0
a00ae94c:  02 80 00 1b  be  0xa00ae9b8
a00ae950:  90 10 20 00  clr  %o0
a00ae954:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00ae958:  b0 10 61 dc  or  %g1, 0x1dc, %i0	! 0xa80795dc
a00ae95c:  92 10 20 00  clr  %o1
a00ae960:  1f 2a 01 e2  sethi  %hi(0xa8078800), %o7
a00ae964:  11 33 c0 00  sethi  %hi(0xcf000000), %o0
a00ae968:  95 2a 60 10  sll  %o1, 0x10, %o2
a00ae96c:  da 0b e0 20  ldub  [ %o7 + 0x20 ], %o5
a00ae970:  95 32 a0 10  srl  %o2, 0x10, %o2
a00ae974:  82 03 40 0d  add  %o5, %o5, %g1
a00ae978:  96 02 ae 60  add  %o2, 0xe60, %o3
a00ae97c:  82 00 40 0d  add  %g1, %o5, %g1
a00ae980:  97 2a e0 02  sll  %o3, 2, %o3
a00ae984:  96 12 c0 08  or  %o3, %o0, %o3
a00ae988:  92 02 60 01  inc  %o1
a00ae98c:  83 28 60 04  sll  %g1, 4, %g1
a00ae990:  da 02 c0 00  ld  [ %o3 ], %o5
a00ae994:  82 00 40 18  add  %g1, %i0, %g1
a00ae998:  99 2a 60 10  sll  %o1, 0x10, %o4
a00ae99c:  da 28 40 0a  stb  %o5, [ %g1 + %o2 ]
a00ae9a0:  99 33 20 10  srl  %o4, 0x10, %o4
a00ae9a4:  c0 22 c0 00  clr  [ %o3 ]
a00ae9a8:  80 a3 20 2f  cmp  %o4, 0x2f
a00ae9ac:  08 bf ff f0  bleu  0xa00ae96c
a00ae9b0:  95 2a 60 10  sll  %o1, 0x10, %o2
a00ae9b4:  90 10 20 00  clr  %o0
a00ae9b8:  92 10 20 f7  mov  0xf7, %o1
a00ae9bc:  94 10 20 08  mov  8, %o2
a00ae9c0:  7f ff e0 b6  call  0xa00a6c98
a00ae9c4:  96 10 20 01  mov  1, %o3
a00ae9c8:  90 10 20 00  clr  %o0
a00ae9cc:  92 10 20 30  mov  0x30, %o1
a00ae9d0:  94 10 20 80  mov  0x80, %o2
a00ae9d4:  7f ff e0 b1  call  0xa00a6c98
a00ae9d8:  96 10 20 01  mov  1, %o3
a00ae9dc:  03 33 c0 11  sethi  %hi(0xcf004400), %g1
a00ae9e0:  9a 10 20 22  mov  0x22, %o5
a00ae9e4:  82 10 62 80  or  %g1, 0x280, %g1
a00ae9e8:  da 20 40 00  st  %o5, [ %g1 ]
a00ae9ec:  90 10 20 00  clr  %o0
a00ae9f0:  92 10 20 30  mov  0x30, %o1
a00ae9f4:  94 10 20 80  mov  0x80, %o2
a00ae9f8:  7f ff e0 a8  call  0xa00a6c98
a00ae9fc:  96 10 20 00  clr  %o3
a00aea00:  7f ff 5b 3f  call  0xa00856fc
a00aea04:  91 e8 20 00  restore  %g0, 0, %o0
a00aea08:  01 00 00 00  nop
