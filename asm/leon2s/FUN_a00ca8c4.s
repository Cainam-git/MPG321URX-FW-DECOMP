# leon2s FUN_a00ca8c4 0xa00ca8c4-0xa00cab10 (588 bytes)  [FUN_a00cab08 = unreachable ret/restore tail, merged]
a00ca8c4:  9d e3 bf 98  save  %sp, -104, %sp
a00ca8c8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ca8cc:  82 06 00 18  add  %i0, %i0, %g1
a00ca8d0:  82 00 40 18  add  %g1, %i0, %g1
a00ca8d4:  a3 28 60 03  sll  %g1, 3, %l1
a00ca8d8:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00ca8dc:  2b 2a 01 e2  sethi  %hi(0xa8078800), %l5
a00ca8e0:  a6 15 63 b0  or  %l5, 0x3b0, %l3	! 0xa8078bb0
a00ca8e4:  a8 10 63 ff  or  %g1, 0x3ff, %l4
a00ca8e8:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a00ca8ec:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00ca8f0:  82 08 40 14  and  %g1, %l4, %g1
a00ca8f4:  82 10 40 0d  or  %g1, %o5, %g1
a00ca8f8:  21 2a 01 f4  sethi  %hi(0xa807d000), %l0
a00ca8fc:  c2 24 c0 11  st  %g1, [ %l3 + %l1 ]
a00ca900:  90 10 00 18  mov  %i0, %o0
a00ca904:  7f ff fb a5  call  0xa00c9798
a00ca908:  92 14 22 50  or  %l0, 0x250, %o1
a00ca90c:  80 8a 20 ff  btst  0xff, %o0
a00ca910:  32 80 00 24  bne,a   0xa00ca9a0
a00ca914:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a00ca918:  82 14 22 50  or  %l0, 0x250, %g1
a00ca91c:  d8 08 60 01  ldub  [ %g1 + 1 ], %o4
a00ca920:  82 0b 20 03  and  %o4, 3, %g1
a00ca924:  83 28 60 08  sll  %g1, 8, %g1
a00ca928:  da 0c 22 50  ldub  [ %l0 + 0x250 ], %o5
a00ca92c:  80 8b 20 0c  btst  0xc, %o4
a00ca930:  12 80 00 1b  bne  0xa00ca99c
a00ca934:  82 00 40 0d  add  %g1, %o5, %g1
a00ca938:  83 28 60 10  sll  %g1, 0x10, %g1
a00ca93c:  a5 30 60 10  srl  %g1, 0x10, %l2
a00ca940:  80 a4 a0 00  cmp  %l2, 0
a00ca944:  12 80 00 05  bne  0xa00ca958
a00ca948:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00ca94c:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a00ca950:  10 80 00 15  b  0xa00ca9a4
a00ca954:  82 10 40 0d  or  %g1, %o5, %g1
a00ca958:  90 10 00 18  mov  %i0, %o0
a00ca95c:  92 10 20 74  mov  0x74, %o1
a00ca960:  94 10 20 80  mov  0x80, %o2
a00ca964:  7f ff f5 b9  call  0xa00c8048
a00ca968:  96 10 00 12  mov  %l2, %o3
a00ca96c:  80 8a 20 ff  btst  0xff, %o0
a00ca970:  32 80 00 0c  bne,a   0xa00ca9a0
a00ca974:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a00ca978:  21 2a 01 f3  sethi  %hi(0xa807cc00), %l0
a00ca97c:  94 10 00 12  mov  %l2, %o2
a00ca980:  90 10 00 18  mov  %i0, %o0
a00ca984:  7f ff fb a3  call  0xa00c9810
a00ca988:  92 14 22 50  or  %l0, 0x250, %o1
a00ca98c:  c2 0c 22 50  ldub  [ %l0 + 0x250 ], %g1
a00ca990:  80 a0 60 03  cmp  %g1, 3
a00ca994:  02 80 00 06  be  0xa00ca9ac
a00ca998:  96 10 20 00  clr  %o3
a00ca99c:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a00ca9a0:  82 08 40 14  and  %g1, %l4, %g1
a00ca9a4:  10 80 00 58  b  0xa00cab04
a00ca9a8:  c2 24 c0 11  st  %g1, [ %l3 + %l1 ]
a00ca9ac:  9a 02 e0 01  add  %o3, 1, %o5
a00ca9b0:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ca9b4:  83 30 60 10  srl  %g1, 0x10, %g1
a00ca9b8:  80 a0 60 89  cmp  %g1, 0x89
a00ca9bc:  08 bf ff fc  bleu  0xa00ca9ac
a00ca9c0:  96 10 00 0d  mov  %o5, %o3
a00ca9c4:  96 10 20 00  clr  %o3
a00ca9c8:  9a 02 e0 01  add  %o3, 1, %o5
a00ca9cc:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ca9d0:  83 30 60 10  srl  %g1, 0x10, %g1
a00ca9d4:  80 a0 61 7f  cmp  %g1, 0x17f
a00ca9d8:  08 bf ff fc  bleu  0xa00ca9c8
a00ca9dc:  96 10 00 0d  mov  %o5, %o3
a00ca9e0:  96 10 20 00  clr  %o3
a00ca9e4:  9a 02 e0 01  add  %o3, 1, %o5
a00ca9e8:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ca9ec:  83 30 60 10  srl  %g1, 0x10, %g1
a00ca9f0:  80 a0 60 0a  cmp  %g1, 0xa
a00ca9f4:  08 bf ff fc  bleu  0xa00ca9e4
a00ca9f8:  96 10 00 0d  mov  %o5, %o3
a00ca9fc:  83 2e 20 02  sll  %i0, 2, %g1
a00caa00:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a00caa04:  82 00 40 18  add  %g1, %i0, %g1
a00caa08:  9a 13 62 38  or  %o5, 0x238, %o5
a00caa0c:  94 00 40 0d  add  %g1, %o5, %o2
a00caa10:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00caa14:  92 10 62 50  or  %g1, 0x250, %o1	! 0xa807ce50
a00caa18:  96 10 20 00  clr  %o3
a00caa1c:  99 2a e0 10  sll  %o3, 0x10, %o4
a00caa20:  99 33 20 10  srl  %o4, 0x10, %o4
a00caa24:  96 02 e0 01  inc  %o3
a00caa28:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00caa2c:  82 03 00 09  add  %o4, %o1, %g1
a00caa30:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a00caa34:  9b 33 60 10  srl  %o5, 0x10, %o5
a00caa38:  80 a3 60 04  cmp  %o5, 4
a00caa3c:  08 bf ff f8  bleu  0xa00caa1c
a00caa40:  c2 2a 80 0c  stb  %g1, [ %o2 + %o4 ]
a00caa44:  96 10 20 00  clr  %o3
a00caa48:  9a 02 e0 01  add  %o3, 1, %o5
a00caa4c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00caa50:  83 30 60 10  srl  %g1, 0x10, %g1
a00caa54:  80 a0 60 7f  cmp  %g1, 0x7f
a00caa58:  08 bf ff fc  bleu  0xa00caa48
a00caa5c:  96 10 00 0d  mov  %o5, %o3
a00caa60:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00caa64:  92 10 62 48  or  %g1, 0x248, %o1	! 0xa807ce48
a00caa68:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00caa6c:  94 10 62 50  or  %g1, 0x250, %o2	! 0xa807ce50
a00caa70:  96 10 20 00  clr  %o3
a00caa74:  99 2a e0 10  sll  %o3, 0x10, %o4
a00caa78:  99 33 20 10  srl  %o4, 0x10, %o4
a00caa7c:  96 02 e0 01  inc  %o3
a00caa80:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00caa84:  82 03 00 0a  add  %o4, %o2, %g1
a00caa88:  c2 08 60 86  ldub  [ %g1 + 0x86 ], %g1
a00caa8c:  9b 33 60 10  srl  %o5, 0x10, %o5
a00caa90:  80 a3 60 02  cmp  %o5, 2
a00caa94:  08 bf ff f8  bleu  0xa00caa74
a00caa98:  c2 2a 40 0c  stb  %g1, [ %o1 + %o4 ]
a00caa9c:  96 10 20 00  clr  %o3
a00caaa0:  9a 02 e0 01  add  %o3, 1, %o5
a00caaa4:  83 2b 60 10  sll  %o5, 0x10, %g1
a00caaa8:  83 30 60 10  srl  %g1, 0x10, %g1
a00caaac:  80 a0 60 01  cmp  %g1, 1
a00caab0:  08 bf ff fc  bleu  0xa00caaa0
a00caab4:  96 10 00 0d  mov  %o5, %o3
a00caab8:  82 06 00 18  add  %i0, %i0, %g1
a00caabc:  82 00 40 18  add  %g1, %i0, %g1
a00caac0:  b0 15 63 b0  or  %l5, 0x3b0, %i0
a00caac4:  91 28 60 03  sll  %g1, 3, %o0
a00caac8:  c2 06 00 08  ld  [ %i0 + %o0 ], %g1
a00caacc:  83 30 60 13  srl  %g1, 0x13, %g1
a00caad0:  80 88 60 01  btst  1, %g1
a00caad4:  12 80 00 0c  bne  0xa00cab04
a00caad8:  82 02 00 18  add  %o0, %i0, %g1
a00caadc:  13 2a 01 f3  sethi  %hi(0xa807cc00), %o1
a00caae0:  d0 08 60 09  ldub  [ %g1 + 9 ], %o0
a00caae4:  92 12 63 08  or  %o1, 0x308, %o1
a00caae8:  94 10 20 00  clr  %o2
a00caaec:  96 10 20 00  clr  %o3
a00caaf0:  98 10 2c 00  mov  0xc00, %o4
a00caaf4:  7f ff fb ac  call  0xa00c99a4
a00caaf8:  31 2a 01 f3  sethi  %hi(0xa807cc00), %i0
a00caafc:  7f ff fe 7b  call  0xa00ca4e8
a00cab00:  91 ee 22 51  restore  %i0, 0x251, %o0
a00cab04:  01 00 00 00  nop
a00cab08:  81 c7 e0 08  ret
a00cab0c:  81 e8 00 00  restore
