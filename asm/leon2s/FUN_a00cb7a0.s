# leon2s FUN_a00cb7a0 0xa00cb7a0-0xa00cbb50 (944 bytes)
a00cb7a0:  9d e3 bf 98  save  %sp, -104, %sp
a00cb7a4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cb7a8:  98 06 00 18  add  %i0, %i0, %o4
a00cb7ac:  98 03 00 18  add  %o4, %i0, %o4
a00cb7b0:  29 2a 01 e2  sethi  %hi(0xa8078800), %l4
a00cb7b4:  99 2b 20 03  sll  %o4, 3, %o4
a00cb7b8:  96 15 23 b0  or  %l4, 0x3b0, %o3
a00cb7bc:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cb7c0:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cb7c4:  82 2b 40 01  andn  %o5, %g1, %g1
a00cb7c8:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cb7cc:  82 10 40 0d  or  %g1, %o5, %g1
a00cb7d0:  27 2a 01 f3  sethi  %hi(0xa807cc00), %l3
a00cb7d4:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cb7d8:  a2 10 20 01  mov  1, %l1
a00cb7dc:  94 14 e2 50  or  %l3, 0x250, %o2
a00cb7e0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb7e4:  e2 2a 80 01  stb  %l1, [ %o2 + %g1 ]
a00cb7e8:  96 04 60 08  add  %l1, 8, %o3
a00cb7ec:  98 04 60 20  add  %l1, 0x20, %o4
a00cb7f0:  a2 04 60 01  inc  %l1
a00cb7f4:  82 00 40 0a  add  %g1, %o2, %g1
a00cb7f8:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00cb7fc:  d8 28 60 10  stb  %o4, [ %g1 + 0x10 ]
a00cb800:  80 a3 60 08  cmp  %o5, 8
a00cb804:  08 bf ff f7  bleu  0xa00cb7e0
a00cb808:  d6 28 60 08  stb  %o3, [ %g1 + 8 ]
a00cb80c:  90 10 00 18  mov  %i0, %o0
a00cb810:  92 10 20 15  mov  0x15, %o1
a00cb814:  7f ff f3 f5  call  0xa00c87e8
a00cb818:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cb81c:  a2 10 20 00  clr  %l1
a00cb820:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb824:  9a 14 e2 50  or  %l3, 0x250, %o5
a00cb828:  82 00 40 0d  add  %g1, %o5, %g1
a00cb82c:  d4 08 60 01  ldub  [ %g1 + 1 ], %o2
a00cb830:  90 10 00 18  mov  %i0, %o0
a00cb834:  7f ff ef 88  call  0xa00c7654
a00cb838:  92 10 20 12  mov  0x12, %o1
a00cb83c:  a2 04 60 01  inc  %l1
a00cb840:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb844:  80 a0 60 0f  cmp  %g1, 0xf
a00cb848:  08 bf ff f8  bleu  0xa00cb828
a00cb84c:  9a 14 e2 50  or  %l3, 0x250, %o5
a00cb850:  90 10 00 18  mov  %i0, %o0
a00cb854:  92 10 20 11  mov  0x11, %o1
a00cb858:  7f ff f3 e4  call  0xa00c87e8
a00cb85c:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cb860:  a2 10 20 00  clr  %l1
a00cb864:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb868:  9a 14 e2 50  or  %l3, 0x250, %o5
a00cb86c:  82 00 40 0d  add  %g1, %o5, %g1
a00cb870:  d4 08 60 11  ldub  [ %g1 + 0x11 ], %o2
a00cb874:  90 10 00 18  mov  %i0, %o0
a00cb878:  7f ff ef 77  call  0xa00c7654
a00cb87c:  92 10 20 01  mov  1, %o1
a00cb880:  a2 04 60 01  inc  %l1
a00cb884:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb888:  80 a0 60 07  cmp  %g1, 7
a00cb88c:  08 bf ff f8  bleu  0xa00cb86c
a00cb890:  9a 14 e2 50  or  %l3, 0x250, %o5
a00cb894:  90 10 00 18  mov  %i0, %o0
a00cb898:  92 10 20 06  mov  6, %o1
a00cb89c:  7f ff ef 6e  call  0xa00c7654
a00cb8a0:  94 10 20 0a  mov  0xa, %o2
a00cb8a4:  10 80 00 05  b  0xa00cb8b8
a00cb8a8:  a2 10 3f ff  mov  -1, %l1
a00cb8ac:  80 8c 60 ff  btst  0xff, %l1
a00cb8b0:  02 80 00 9a  be  0xa00cbb18
a00cb8b4:  9a 06 00 18  add  %i0, %i0, %o5
a00cb8b8:  90 10 00 18  mov  %i0, %o0
a00cb8bc:  7f ff ef ad  call  0xa00c7770
a00cb8c0:  92 10 20 06  mov  6, %o1
a00cb8c4:  80 8a 20 08  btst  8, %o0
a00cb8c8:  12 bf ff f9  bne  0xa00cb8ac
a00cb8cc:  a2 04 7f ff  add  %l1, -1, %l1
a00cb8d0:  83 2e 20 03  sll  %i0, 3, %g1
a00cb8d4:  82 20 40 18  sub  %g1, %i0, %g1
a00cb8d8:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00cb8dc:  83 28 60 02  sll  %g1, 2, %g1
a00cb8e0:  9a 13 61 80  or  %o5, 0x180, %o5
a00cb8e4:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00cb8e8:  90 10 00 18  mov  %i0, %o0
a00cb8ec:  92 10 20 0d  mov  0xd, %o1
a00cb8f0:  80 88 60 04  btst  4, %g1
a00cb8f4:  12 80 00 05  bne  0xa00cb908
a00cb8f8:  94 10 20 3a  mov  0x3a, %o2
a00cb8fc:  90 10 00 18  mov  %i0, %o0
a00cb900:  92 10 20 0d  mov  0xd, %o1
a00cb904:  94 10 20 76  mov  0x76, %o2
a00cb908:  7f ff ef 53  call  0xa00c7654
a00cb90c:  a2 10 20 00  clr  %l1
a00cb910:  90 10 00 18  mov  %i0, %o0
a00cb914:  92 10 20 0e  mov  0xe, %o1
a00cb918:  7f ff ef 4f  call  0xa00c7654
a00cb91c:  94 10 20 00  clr  %o2
a00cb920:  82 10 20 0b  mov  0xb, %g1
a00cb924:  c2 2c e2 50  stb  %g1, [ %l3 + 0x250 ]
a00cb928:  90 10 00 18  mov  %i0, %o0
a00cb92c:  92 10 20 0a  mov  0xa, %o1
a00cb930:  7f ff f3 ae  call  0xa00c87e8
a00cb934:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cb938:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00cb93c:  90 10 00 18  mov  %i0, %o0
a00cb940:  7f ff ef 8c  call  0xa00c7770
a00cb944:  92 10 20 01  mov  1, %o1
a00cb948:  a4 14 e2 50  or  %l3, 0x250, %l2
a00cb94c:  a2 04 60 01  inc  %l1
a00cb950:  a0 04 00 12  add  %l0, %l2, %l0
a00cb954:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cb958:  80 a0 60 0f  cmp  %g1, 0xf
a00cb95c:  08 bf ff f7  bleu  0xa00cb938
a00cb960:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a00cb964:  96 10 20 60  mov  0x60, %o3
a00cb968:  98 10 20 19  mov  0x19, %o4
a00cb96c:  92 10 00 12  mov  %l2, %o1
a00cb970:  90 10 00 18  mov  %i0, %o0
a00cb974:  7f ff f1 df  call  0xa00c80f0
a00cb978:  94 10 20 74  mov  0x74, %o2
a00cb97c:  82 06 00 18  add  %i0, %i0, %g1
a00cb980:  82 00 40 18  add  %g1, %i0, %g1
a00cb984:  99 28 60 03  sll  %g1, 3, %o4
a00cb988:  96 15 23 b0  or  %l4, 0x3b0, %o3
a00cb98c:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cb990:  83 33 60 1c  srl  %o5, 0x1c, %g1
a00cb994:  80 88 60 01  btst  1, %g1
a00cb998:  12 80 00 68  bne  0xa00cbb38
a00cb99c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cb9a0:  03 00 20 00  sethi  %hi(0x800000), %g1
a00cb9a4:  82 2b 40 01  andn  %o5, %g1, %g1
a00cb9a8:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cb9ac:  90 10 00 18  mov  %i0, %o0
a00cb9b0:  92 10 20 05  mov  5, %o1
a00cb9b4:  94 10 20 04  mov  4, %o2
a00cb9b8:  7f ff ef 42  call  0xa00c76c0
a00cb9bc:  96 10 20 01  mov  1, %o3
a00cb9c0:  96 10 20 00  clr  %o3
a00cb9c4:  90 10 00 18  mov  %i0, %o0
a00cb9c8:  92 10 20 05  mov  5, %o1
a00cb9cc:  7f ff ef 3d  call  0xa00c76c0
a00cb9d0:  94 10 20 04  mov  4, %o2
a00cb9d4:  90 10 00 18  mov  %i0, %o0
a00cb9d8:  92 10 20 0b  mov  0xb, %o1
a00cb9dc:  7f ff f3 83  call  0xa00c87e8
a00cb9e0:  15 00 00 20  sethi  %hi(0x8000), %o2
a00cb9e4:  90 10 00 18  mov  %i0, %o0
a00cb9e8:  92 10 20 01  mov  1, %o1
a00cb9ec:  7f ff ef 1a  call  0xa00c7654
a00cb9f0:  94 10 20 02  mov  2, %o2
a00cb9f4:  90 10 00 18  mov  %i0, %o0
a00cb9f8:  92 10 20 01  mov  1, %o1
a00cb9fc:  7f ff ef 16  call  0xa00c7654
a00cba00:  94 10 20 10  mov  0x10, %o2
a00cba04:  90 10 00 18  mov  %i0, %o0
a00cba08:  92 10 20 01  mov  1, %o1
a00cba0c:  7f ff ef 12  call  0xa00c7654
a00cba10:  94 10 20 00  clr  %o2
a00cba14:  90 10 00 18  mov  %i0, %o0
a00cba18:  92 10 20 01  mov  1, %o1
a00cba1c:  7f ff ef 0e  call  0xa00c7654
a00cba20:  94 10 20 00  clr  %o2
a00cba24:  90 10 00 18  mov  %i0, %o0
a00cba28:  92 10 20 01  mov  1, %o1
a00cba2c:  7f ff ef 0a  call  0xa00c7654
a00cba30:  94 10 20 00  clr  %o2
a00cba34:  a2 10 20 00  clr  %l1
a00cba38:  9b 2e 20 02  sll  %i0, 2, %o5
a00cba3c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00cba40:  82 10 62 38  or  %g1, 0x238, %g1	! 0xa807ce38
a00cba44:  9a 03 40 18  add  %o5, %i0, %o5
a00cba48:  9a 03 40 01  add  %o5, %g1, %o5
a00cba4c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cba50:  d4 0b 40 01  ldub  [ %o5 + %g1 ], %o2
a00cba54:  90 10 00 18  mov  %i0, %o0
a00cba58:  7f ff ee ff  call  0xa00c7654
a00cba5c:  92 10 20 01  mov  1, %o1
a00cba60:  a2 04 60 01  inc  %l1
a00cba64:  82 0c 60 ff  and  %l1, 0xff, %g1
a00cba68:  80 a0 60 04  cmp  %g1, 4
a00cba6c:  28 bf ff f4  bleu,a   0xa00cba3c
a00cba70:  9b 2e 20 02  sll  %i0, 2, %o5
a00cba74:  90 10 00 18  mov  %i0, %o0
a00cba78:  92 10 20 01  mov  1, %o1
a00cba7c:  7f ff ee f6  call  0xa00c7654
a00cba80:  94 10 20 02  mov  2, %o2
a00cba84:  90 10 00 18  mov  %i0, %o0
a00cba88:  92 10 20 01  mov  1, %o1
a00cba8c:  7f ff ee f2  call  0xa00c7654
a00cba90:  94 10 20 10  mov  0x10, %o2
a00cba94:  90 10 00 18  mov  %i0, %o0
a00cba98:  92 10 20 01  mov  1, %o1
a00cba9c:  7f ff ee ee  call  0xa00c7654
a00cbaa0:  94 10 20 00  clr  %o2
a00cbaa4:  90 10 00 18  mov  %i0, %o0
a00cbaa8:  92 10 20 01  mov  1, %o1
a00cbaac:  7f ff ee ea  call  0xa00c7654
a00cbab0:  94 10 20 00  clr  %o2
a00cbab4:  90 10 00 18  mov  %i0, %o0
a00cbab8:  92 10 20 01  mov  1, %o1
a00cbabc:  7f ff ee e6  call  0xa00c7654
a00cbac0:  94 10 20 00  clr  %o2
a00cbac4:  90 10 00 18  mov  %i0, %o0
a00cbac8:  92 10 20 01  mov  1, %o1
a00cbacc:  7f ff ee e2  call  0xa00c7654
a00cbad0:  94 10 20 80  mov  0x80, %o2
a00cbad4:  98 06 00 18  add  %i0, %i0, %o4
a00cbad8:  98 03 00 18  add  %o4, %i0, %o4
a00cbadc:  96 15 23 b0  or  %l4, 0x3b0, %o3
a00cbae0:  99 2b 20 03  sll  %o4, 3, %o4
a00cbae4:  82 03 00 0b  add  %o4, %o3, %g1
a00cbae8:  9a 10 20 01  mov  1, %o5
a00cbaec:  da 28 60 04  stb  %o5, [ %g1 + 4 ]
a00cbaf0:  c0 28 60 08  clrb  [ %g1 + 8 ]
a00cbaf4:  da 28 60 03  stb  %o5, [ %g1 + 3 ]
a00cbaf8:  c0 28 60 05  clrb  [ %g1 + 5 ]
a00cbafc:  c0 28 60 06  clrb  [ %g1 + 6 ]
a00cbb00:  c0 28 60 07  clrb  [ %g1 + 7 ]
a00cbb04:  da 02 c0 0c  ld  [ %o3 + %o4 ], %o5
a00cbb08:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cbb0c:  82 2b 40 01  andn  %o5, %g1, %g1
a00cbb10:  10 80 00 0c  b  0xa00cbb40
a00cbb14:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cbb18:  9a 03 40 18  add  %o5, %i0, %o5
a00cbb1c:  96 15 23 b0  or  %l4, 0x3b0, %o3
a00cbb20:  9b 2b 60 03  sll  %o5, 3, %o5
a00cbb24:  c2 02 c0 0d  ld  [ %o3 + %o5 ], %g1
a00cbb28:  19 00 00 c0  sethi  %hi(0x30000), %o4
a00cbb2c:  82 10 40 0c  or  %g1, %o4, %g1
a00cbb30:  10 80 00 06  b  0xa00cbb48
a00cbb34:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cbb38:  82 2b 40 01  andn  %o5, %g1, %g1
a00cbb3c:  1b 00 00 80  sethi  %hi(0x20000), %o5
a00cbb40:  82 10 40 0d  or  %g1, %o5, %g1
a00cbb44:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a00cbb48:  81 c7 e0 08  ret
a00cbb4c:  81 e8 00 00  restore
