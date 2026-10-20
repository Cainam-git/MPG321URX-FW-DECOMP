# leon2s FUN_a00c99a4 0xa00c99a4-0xa00c9b58 (436 bytes)
a00c99a4:  9d e3 bf 98  save  %sp, -104, %sp
a00c99a8:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00c99ac:  95 2e a0 04  sll  %i2, 4, %o2
a00c99b0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c99b4:  94 02 80 1a  add  %o2, %i2, %o2
a00c99b8:  94 0a a0 ff  and  %o2, 0xff, %o2
a00c99bc:  90 10 00 18  mov  %i0, %o0
a00c99c0:  40 3b b9 48  call  0xa0fb7ee0
a00c99c4:  92 10 20 04  mov  4, %o1
a00c99c8:  90 10 00 18  mov  %i0, %o0
a00c99cc:  92 10 20 05  mov  5, %o1
a00c99d0:  40 3b b9 44  call  0xa0fb7ee0
a00c99d4:  94 10 20 80  mov  0x80, %o2
a00c99d8:  90 10 00 18  mov  %i0, %o0
a00c99dc:  92 10 20 05  mov  5, %o1
a00c99e0:  40 3b b9 40  call  0xa0fb7ee0
a00c99e4:  94 10 20 00  clr  %o2
a00c99e8:  b6 0e e0 ff  and  %i3, 0xff, %i3
a00c99ec:  80 a6 e0 00  cmp  %i3, 0
a00c99f0:  12 80 00 1b  bne  0xa00c9a5c
a00c99f4:  b4 10 00 1c  mov  %i4, %i2
a00c99f8:  83 2f 20 10  sll  %i4, 0x10, %g1
a00c99fc:  83 30 60 14  srl  %g1, 0x14, %g1
a00c9a00:  80 a6 c0 01  cmp  %i3, %g1
a00c9a04:  1a 80 00 53  bcc  0xa00c9b50
a00c9a08:  b8 10 20 00  clr  %i4
a00c9a0c:  a1 2e a0 10  sll  %i2, 0x10, %l0
a00c9a10:  a1 34 20 14  srl  %l0, 0x14, %l0
a00c9a14:  a2 0f 20 ff  and  %i4, 0xff, %l1
a00c9a18:  a2 24 00 11  sub  %l0, %l1, %l1
a00c9a1c:  a2 04 40 11  add  %l1, %l1, %l1
a00c9a20:  a2 04 40 19  add  %l1, %i1, %l1
a00c9a24:  90 10 00 18  mov  %i0, %o0
a00c9a28:  92 10 20 06  mov  6, %o1
a00c9a2c:  40 3b b9 2d  call  0xa0fb7ee0
a00c9a30:  d4 0c 7f ff  ldub  [ %l1 + -1 ], %o2
a00c9a34:  90 10 00 18  mov  %i0, %o0
a00c9a38:  d4 0c 7f fe  ldub  [ %l1 + -2 ], %o2
a00c9a3c:  40 3b b9 29  call  0xa0fb7ee0
a00c9a40:  92 10 20 07  mov  7, %o1
a00c9a44:  b8 07 20 01  inc  %i4
a00c9a48:  82 0f 20 ff  and  %i4, 0xff, %g1
a00c9a4c:  80 a0 40 10  cmp  %g1, %l0
a00c9a50:  0a bf ff f0  bcs  0xa00c9a10
a00c9a54:  a1 2e a0 10  sll  %i2, 0x10, %l0
a00c9a58:  30 80 00 3e  b,a   0xa00c9b50
a00c9a5c:  80 a6 e0 03  cmp  %i3, 3
a00c9a60:  12 80 00 27  bne  0xa00c9afc
a00c9a64:  80 a6 e0 04  cmp  %i3, 4
a00c9a68:  90 10 00 18  mov  %i0, %o0
a00c9a6c:  92 10 20 06  mov  6, %o1
a00c9a70:  40 3b b9 1c  call  0xa0fb7ee0
a00c9a74:  d4 0e 60 02  ldub  [ %i1 + 2 ], %o2
a00c9a78:  90 10 00 18  mov  %i0, %o0
a00c9a7c:  92 10 20 07  mov  7, %o1
a00c9a80:  40 3b b9 18  call  0xa0fb7ee0
a00c9a84:  d4 0e 60 01  ldub  [ %i1 + 1 ], %o2
a00c9a88:  90 10 00 18  mov  %i0, %o0
a00c9a8c:  d4 0e 40 00  ldub  [ %i1 ], %o2
a00c9a90:  40 3b b9 14  call  0xa0fb7ee0
a00c9a94:  92 10 20 06  mov  6, %o1
a00c9a98:  90 10 00 18  mov  %i0, %o0
a00c9a9c:  92 10 20 07  mov  7, %o1
a00c9aa0:  40 3b b9 10  call  0xa0fb7ee0
a00c9aa4:  94 10 20 00  clr  %o2
a00c9aa8:  83 2f 20 10  sll  %i4, 0x10, %g1
a00c9aac:  83 30 60 14  srl  %g1, 0x14, %g1
a00c9ab0:  80 a0 60 02  cmp  %g1, 2
a00c9ab4:  08 80 00 27  bleu  0xa00c9b50
a00c9ab8:  b8 10 20 02  mov  2, %i4
a00c9abc:  90 10 00 18  mov  %i0, %o0
a00c9ac0:  92 10 20 06  mov  6, %o1
a00c9ac4:  40 3b b9 07  call  0xa0fb7ee0
a00c9ac8:  94 10 20 00  clr  %o2
a00c9acc:  90 10 00 18  mov  %i0, %o0
a00c9ad0:  92 10 20 07  mov  7, %o1
a00c9ad4:  40 3b b9 03  call  0xa0fb7ee0
a00c9ad8:  94 10 20 00  clr  %o2
a00c9adc:  b8 07 20 01  inc  %i4
a00c9ae0:  83 2e a0 10  sll  %i2, 0x10, %g1
a00c9ae4:  83 30 60 14  srl  %g1, 0x14, %g1
a00c9ae8:  9a 0f 20 ff  and  %i4, 0xff, %o5
a00c9aec:  80 a3 40 01  cmp  %o5, %g1
a00c9af0:  0a bf ff f4  bcs  0xa00c9ac0
a00c9af4:  90 10 00 18  mov  %i0, %o0
a00c9af8:  30 80 00 16  b,a   0xa00c9b50
a00c9afc:  12 80 00 15  bne  0xa00c9b50
a00c9b00:  83 2f 20 10  sll  %i4, 0x10, %g1
a00c9b04:  83 30 60 14  srl  %g1, 0x14, %g1
a00c9b08:  80 a0 60 00  cmp  %g1, 0
a00c9b0c:  02 80 00 11  be  0xa00c9b50
a00c9b10:  b8 10 20 00  clr  %i4
a00c9b14:  90 10 00 18  mov  %i0, %o0
a00c9b18:  92 10 20 06  mov  6, %o1
a00c9b1c:  40 3b b8 f1  call  0xa0fb7ee0
a00c9b20:  94 10 20 00  clr  %o2
a00c9b24:  90 10 00 18  mov  %i0, %o0
a00c9b28:  92 10 20 07  mov  7, %o1
a00c9b2c:  40 3b b8 ed  call  0xa0fb7ee0
a00c9b30:  94 10 20 00  clr  %o2
a00c9b34:  b8 07 20 01  inc  %i4
a00c9b38:  83 2e a0 10  sll  %i2, 0x10, %g1
a00c9b3c:  83 30 60 14  srl  %g1, 0x14, %g1
a00c9b40:  9a 0f 20 ff  and  %i4, 0xff, %o5
a00c9b44:  80 a3 40 01  cmp  %o5, %g1
a00c9b48:  0a bf ff f4  bcs  0xa00c9b18
a00c9b4c:  90 10 00 18  mov  %i0, %o0
a00c9b50:  81 c7 e0 08  ret
a00c9b54:  81 e8 00 00  restore
