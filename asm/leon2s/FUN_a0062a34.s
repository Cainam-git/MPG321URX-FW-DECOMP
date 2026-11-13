# leon2s FUN_a0062a34 0xa0062a34-0xa0062b64 (304 bytes)
a0062a34:  9d e3 bf 98  save  %sp, -104, %sp
a0062a38:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0062a3c:  b4 10 62 a0  or  %g1, 0x2a0, %i2	! 0xa8078aa0
a0062a40:  c2 16 a0 02  lduh  [ %i2 + 2 ], %g1
a0062a44:  b0 26 00 01  sub  %i0, %g1, %i0
a0062a48:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0062a4c:  c2 00 62 60  ld  [ %g1 + 0x260 ], %g1	! 0xa8078a60
a0062a50:  b0 5e 00 01  smul  %i0, %g1, %i0
a0062a54:  bb 36 20 15  srl  %i0, 0x15, %i5
a0062a58:  c2 0e a0 58  ldub  [ %i2 + 0x58 ], %g1
a0062a5c:  b1 36 20 09  srl  %i0, 9, %i0
a0062a60:  b6 00 60 01  add  %g1, 1, %i3
a0062a64:  b2 0e 2f ff  and  %i0, 0xfff, %i1
a0062a68:  80 a7 60 3f  cmp  %i5, 0x3f
a0062a6c:  08 80 00 21  bleu  0xa0062af0
a0062a70:  98 10 20 00  clr  %o4
a0062a74:  b8 10 20 01  mov  1, %i4
a0062a78:  80 a7 00 1b  cmp  %i4, %i3
a0062a7c:  18 80 00 37  bgu  0xa0062b58
a0062a80:  83 2e e0 06  sll  %i3, 6, %g1
a0062a84:  82 00 40 1b  add  %g1, %i3, %g1
a0062a88:  82 20 40 1d  sub  %g1, %i5, %g1
a0062a8c:  3b 2a 01 f3  sethi  %hi(0xa807cc00), %i5
a0062a90:  fa 07 61 6c  ld  [ %i5 + 0x16c ], %i5	! 0xa807cd6c
a0062a94:  82 00 40 01  add  %g1, %g1, %g1
a0062a98:  82 00 40 1d  add  %g1, %i5, %g1
a0062a9c:  3b 00 00 04  sethi  %hi(0x1000), %i5
a0062aa0:  9e 27 40 19  sub  %i5, %i1, %o7
a0062aa4:  b4 06 a0 5a  add  %i2, 0x5a, %i2
a0062aa8:  b0 00 7f 7e  add  %g1, -130, %i0
a0062aac:  fa 16 21 00  lduh  [ %i0 + 0x100 ], %i5
a0062ab0:  c2 16 20 fe  lduh  [ %i0 + 0xfe ], %g1
a0062ab4:  82 58 40 19  smul  %g1, %i1, %g1
a0062ab8:  ba 5f 40 0f  smul  %i5, %o7, %i5
a0062abc:  ba 07 40 01  add  %i5, %g1, %i5
a0062ac0:  c2 16 80 00  lduh  [ %i2 ], %g1
a0062ac4:  bb 37 60 06  srl  %i5, 6, %i5
a0062ac8:  82 5f 40 01  smul  %i5, %g1, %g1
a0062acc:  83 30 60 04  srl  %g1, 4, %g1
a0062ad0:  b8 07 20 01  inc  %i4
a0062ad4:  98 03 00 01  add  %o4, %g1, %o4
a0062ad8:  b0 06 3f 7e  add  %i0, -130, %i0
a0062adc:  80 a7 00 1b  cmp  %i4, %i3
a0062ae0:  08 bf ff f3  bleu  0xa0062aac
a0062ae4:  b4 06 a0 02  add  %i2, 2, %i2
a0062ae8:  10 80 00 1d  b  0xa0062b5c
a0062aec:  b1 33 20 08  srl  %o4, 8, %i0
a0062af0:  b8 10 20 01  mov  1, %i4
a0062af4:  80 a7 00 1b  cmp  %i4, %i3
a0062af8:  18 80 00 18  bgu  0xa0062b58
a0062afc:  82 07 40 1d  add  %i5, %i5, %g1
a0062b00:  3b 2a 01 f3  sethi  %hi(0xa807cc00), %i5
a0062b04:  de 07 61 6c  ld  [ %i5 + 0x16c ], %o7	! 0xa807cd6c
a0062b08:  3b 00 00 04  sethi  %hi(0x1000), %i5
a0062b0c:  9a 27 40 19  sub  %i5, %i1, %o5
a0062b10:  b4 06 a0 5a  add  %i2, 0x5a, %i2
a0062b14:  b0 00 60 82  add  %g1, 0x82, %i0
a0062b18:  82 06 00 0f  add  %i0, %o7, %g1
a0062b1c:  fa 10 60 02  lduh  [ %g1 + 2 ], %i5
a0062b20:  c2 16 00 0f  lduh  [ %i0 + %o7 ], %g1
a0062b24:  ba 5f 40 19  smul  %i5, %i1, %i5
a0062b28:  82 58 40 0d  smul  %g1, %o5, %g1
a0062b2c:  82 00 40 1d  add  %g1, %i5, %g1
a0062b30:  bb 30 60 06  srl  %g1, 6, %i5
a0062b34:  c2 16 80 00  lduh  [ %i2 ], %g1
a0062b38:  82 5f 40 01  smul  %i5, %g1, %g1
a0062b3c:  83 30 60 04  srl  %g1, 4, %g1
a0062b40:  b8 07 20 01  inc  %i4
a0062b44:  98 03 00 01  add  %o4, %g1, %o4
a0062b48:  b0 06 20 82  add  %i0, 0x82, %i0
a0062b4c:  80 a7 00 1b  cmp  %i4, %i3
a0062b50:  08 bf ff f2  bleu  0xa0062b18
a0062b54:  b4 06 a0 02  add  %i2, 2, %i2
a0062b58:  b1 33 20 08  srl  %o4, 8, %i0
a0062b5c:  81 c7 e0 08  ret
a0062b60:  81 e8 00 00  restore
