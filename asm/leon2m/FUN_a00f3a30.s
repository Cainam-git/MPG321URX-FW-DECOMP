# leon2m FUN_a00f3a30 0xa00f3a30-0xa00f3c18 (488 bytes)
a00f3a30:  9d e3 bf 98  save  %sp, -104, %sp
a00f3a34:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f3a38:  40 00 14 ee  call  0xa00f8df0
a00f3a3c:  90 10 00 18  mov  %i0, %o0
a00f3a40:  ae 10 00 08  mov  %o0, %l7
a00f3a44:  40 00 14 e4  call  0xa00f8dd4
a00f3a48:  90 10 00 18  mov  %i0, %o0
a00f3a4c:  b8 10 00 08  mov  %o0, %i4
a00f3a50:  92 10 20 0c  mov  0xc, %o1
a00f3a54:  7f ff f8 a4  call  0xa00f1ce4
a00f3a58:  90 10 00 18  mov  %i0, %o0
a00f3a5c:  a4 0a 27 ff  and  %o0, 0x7ff, %l2
a00f3a60:  92 10 20 12  mov  0x12, %o1
a00f3a64:  7f ff f8 a0  call  0xa00f1ce4
a00f3a68:  90 10 00 18  mov  %i0, %o0
a00f3a6c:  a6 0a 2f ff  and  %o0, 0xfff, %l3
a00f3a70:  92 10 20 3c  mov  0x3c, %o1
a00f3a74:  7f ff f8 9c  call  0xa00f1ce4
a00f3a78:  90 10 00 18  mov  %i0, %o0
a00f3a7c:  a8 0a 27 ff  and  %o0, 0x7ff, %l4
a00f3a80:  92 10 20 40  mov  0x40, %o1
a00f3a84:  7f ff f8 98  call  0xa00f1ce4
a00f3a88:  90 10 00 18  mov  %i0, %o0
a00f3a8c:  ba 0a 2f ff  and  %o0, 0xfff, %i5
a00f3a90:  92 10 20 38  mov  0x38, %o1
a00f3a94:  7f ff f8 94  call  0xa00f1ce4
a00f3a98:  90 10 00 18  mov  %i0, %o0
a00f3a9c:  a0 0a 27 ff  and  %o0, 0x7ff, %l0
a00f3aa0:  90 10 00 18  mov  %i0, %o0
a00f3aa4:  7f ff f8 90  call  0xa00f1ce4
a00f3aa8:  92 10 20 3e  mov  0x3e, %o1
a00f3aac:  83 2d e0 10  sll  %l7, 0x10, %g1
a00f3ab0:  a3 30 60 10  srl  %g1, 0x10, %l1
a00f3ab4:  aa 0a 2f ff  and  %o0, 0xfff, %l5
a00f3ab8:  80 a5 00 11  cmp  %l4, %l1
a00f3abc:  0a 80 00 31  bcs  0xa00f3b80
a00f3ac0:  ac 10 00 12  mov  %l2, %l6
a00f3ac4:  a3 2f 20 10  sll  %i4, 0x10, %l1
a00f3ac8:  9e 0f 6f ff  and  %i5, 0xfff, %o7
a00f3acc:  a1 34 60 10  srl  %l1, 0x10, %l0
a00f3ad0:  80 a3 c0 10  cmp  %o7, %l0
a00f3ad4:  0a 80 00 14  bcs  0xa00f3b24
a00f3ad8:  91 2c e0 10  sll  %l3, 0x10, %o0
a00f3adc:  c2 16 60 2c  lduh  [ %i1 + 0x2c ], %g1
a00f3ae0:  97 32 20 10  srl  %o0, 0x10, %o3
a00f3ae4:  80 a0 40 0b  cmp  %g1, %o3
a00f3ae8:  28 80 00 04  bleu,a   0xa00f3af8
a00f3aec:  d8 16 60 2e  lduh  [ %i1 + 0x2e ], %o4
a00f3af0:  10 80 00 38  b  0xa00f3bd0
a00f3af4:  91 28 60 10  sll  %g1, 0x10, %o0
a00f3af8:  95 2b 20 10  sll  %o4, 0x10, %o2
a00f3afc:  9b 34 60 10  srl  %l1, 0x10, %o5
a00f3b00:  b9 32 a0 10  srl  %o2, 0x10, %i4
a00f3b04:  d2 16 60 0c  lduh  [ %i1 + 0xc ], %o1
a00f3b08:  a6 02 c0 0d  add  %o3, %o5, %l3
a00f3b0c:  a2 07 00 09  add  %i4, %o1, %l1
a00f3b10:  80 a4 c0 11  cmp  %l3, %l1
a00f3b14:  34 80 00 2f  bg,a   0xa00f3bd0
a00f3b18:  90 10 00 0a  mov  %o2, %o0
a00f3b1c:  10 80 00 2e  b  0xa00f3bd4
a00f3b20:  93 32 20 10  srl  %o0, 0x10, %o1
a00f3b24:  7f ff fe 81  call  0xa00f3528
a00f3b28:  01 00 00 00  nop
a00f3b2c:  a9 2a 20 10  sll  %o0, 0x10, %l4
a00f3b30:  a5 35 20 10  srl  %l4, 0x10, %l2
a00f3b34:  9a 0d 6f ff  and  %l5, 0xfff, %o5
a00f3b38:  80 a4 80 0d  cmp  %l2, %o5
a00f3b3c:  08 bf ff e8  bleu  0xa00f3adc
a00f3b40:  91 2c e0 10  sll  %l3, 0x10, %o0
a00f3b44:  af 32 20 10  srl  %o0, 0x10, %l7
a00f3b48:  80 a3 40 17  cmp  %o5, %l7
a00f3b4c:  28 bf ff e4  bleu,a   0xa00f3adc
a00f3b50:  91 2d 60 10  sll  %l5, 0x10, %o0
a00f3b54:  82 07 40 15  add  %i5, %l5, %g1
a00f3b58:  9a 20 40 13  sub  %g1, %l3, %o5
a00f3b5c:  bb 2b 60 10  sll  %o5, 0x10, %i5
a00f3b60:  ab 37 60 10  srl  %i5, 0x10, %l5
a00f3b64:  80 a5 40 10  cmp  %l5, %l0
a00f3b68:  28 bf ff de  bleu,a   0xa00f3ae0
a00f3b6c:  c2 16 60 2c  lduh  [ %i1 + 0x2c ], %g1
a00f3b70:  90 23 40 1c  sub  %o5, %i4, %o0
a00f3b74:  a0 02 00 13  add  %o0, %l3, %l0
a00f3b78:  10 bf ff d9  b  0xa00f3adc
a00f3b7c:  91 2c 20 10  sll  %l0, 0x10, %o0
a00f3b80:  40 00 b4 44  call  0xa0120c90
a00f3b84:  90 10 00 18  mov  %i0, %o0
a00f3b88:  93 2a 20 10  sll  %o0, 0x10, %o1
a00f3b8c:  91 32 60 10  srl  %o1, 0x10, %o0
a00f3b90:  80 a2 00 10  cmp  %o0, %l0
a00f3b94:  28 bf ff cd  bleu,a   0xa00f3ac8
a00f3b98:  a3 2f 20 10  sll  %i4, 0x10, %l1
a00f3b9c:  80 a4 00 12  cmp  %l0, %l2
a00f3ba0:  28 bf ff c9  bleu,a   0xa00f3ac4
a00f3ba4:  ac 10 00 10  mov  %l0, %l6
a00f3ba8:  9a 05 00 10  add  %l4, %l0, %o5
a00f3bac:  90 23 40 12  sub  %o5, %l2, %o0
a00f3bb0:  97 2a 20 10  sll  %o0, 0x10, %o3
a00f3bb4:  95 32 e0 10  srl  %o3, 0x10, %o2
a00f3bb8:  80 a2 80 11  cmp  %o2, %l1
a00f3bbc:  08 bf ff c3  bleu  0xa00f3ac8
a00f3bc0:  a3 2f 20 10  sll  %i4, 0x10, %l1
a00f3bc4:  98 22 00 17  sub  %o0, %l7, %o4
a00f3bc8:  10 bf ff c0  b  0xa00f3ac8
a00f3bcc:  ac 04 80 0c  add  %l2, %o4, %l6
a00f3bd0:  93 32 20 10  srl  %o0, 0x10, %o1
a00f3bd4:  40 00 14 8e  call  0xa00f8e0c
a00f3bd8:  90 10 00 18  mov  %i0, %o0
a00f3bdc:  95 2d a0 10  sll  %l6, 0x10, %o2
a00f3be0:  93 32 a0 10  srl  %o2, 0x10, %o1
a00f3be4:  40 00 14 98  call  0xa00f8e44
a00f3be8:  90 10 00 18  mov  %i0, %o0
a00f3bec:  40 00 13 30  call  0xa00f88ac
a00f3bf0:  90 10 00 18  mov  %i0, %o0
a00f3bf4:  d0 36 60 14  sth  %o0, [ %i1 + 0x14 ]
a00f3bf8:  40 00 13 35  call  0xa00f88cc
a00f3bfc:  90 10 00 18  mov  %i0, %o0
a00f3c00:  ec 16 60 14  lduh  [ %i1 + 0x14 ], %l6
a00f3c04:  d0 36 60 1a  sth  %o0, [ %i1 + 0x1a ]
a00f3c08:  ec 36 60 18  sth  %l6, [ %i1 + 0x18 ]
a00f3c0c:  d0 36 60 16  sth  %o0, [ %i1 + 0x16 ]
a00f3c10:  81 c7 e0 08  ret
a00f3c14:  81 e8 00 00  restore
