# leon2s FUN_a00a6aa0 0xa00a6aa0-0xa00a6bb8 (280 bytes)
a00a6aa0:  9d e3 bf 98  save  %sp, -104, %sp
a00a6aa4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a6aa8:  80 a6 20 02  cmp  %i0, 2
a00a6aac:  9a 10 00 19  mov  %i1, %o5
a00a6ab0:  18 80 00 40  bgu  0xa00a6bb0
a00a6ab4:  98 10 00 1a  mov  %i2, %o4
a00a6ab8:  80 a6 20 02  cmp  %i0, 2
a00a6abc:  12 80 00 21  bne  0xa00a6b40
a00a6ac0:  80 a6 20 01  cmp  %i0, 1
a00a6ac4:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a6ac8:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6acc:  96 10 61 98  or  %g1, 0x198, %o3	! 0xa00b4d98
a00a6ad0:  b3 37 60 10  srl  %i5, 0x10, %i1
a00a6ad4:  9e 0e e0 ff  and  %i3, 0xff, %o7
a00a6ad8:  b4 38 00 1a  xnor  %g0, %i2, %i2
a00a6adc:  b8 10 20 00  clr  %i4
a00a6ae0:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a6ae4:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a6ae8:  ba 00 40 01  add  %g1, %g1, %i5
a00a6aec:  c2 12 c0 1d  lduh  [ %o3 + %i5 ], %g1
a00a6af0:  82 00 40 19  add  %g1, %i1, %g1
a00a6af4:  83 28 60 02  sll  %g1, 2, %g1
a00a6af8:  82 10 40 0d  or  %g1, %o5, %g1
a00a6afc:  b8 07 20 01  inc  %i4
a00a6b00:  c2 00 40 00  ld  [ %g1 ], %g1
a00a6b04:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00a6b08:  80 a3 e0 01  cmp  %o7, 1
a00a6b0c:  02 80 00 03  be  0xa00a6b18
a00a6b10:  b6 10 40 0c  or  %g1, %o4, %i3
a00a6b14:  b6 08 40 1a  and  %g1, %i2, %i3
a00a6b18:  c2 12 c0 1d  lduh  [ %o3 + %i5 ], %g1
a00a6b1c:  82 00 40 19  add  %g1, %i1, %g1
a00a6b20:  83 28 60 02  sll  %g1, 2, %g1
a00a6b24:  82 10 40 0d  or  %g1, %o5, %g1
a00a6b28:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a6b2c:  fa 20 40 00  st  %i5, [ %g1 ]
a00a6b30:  80 a6 20 01  cmp  %i0, 1
a00a6b34:  08 bf ff ed  bleu  0xa00a6ae8
a00a6b38:  82 0f 20 ff  and  %i4, 0xff, %g1
a00a6b3c:  30 80 00 1d  b,a   0xa00a6bb0
a00a6b40:  18 80 00 1c  bgu  0xa00a6bb0
a00a6b44:  1f 28 02 d3  sethi  %hi(0xa00b4c00), %o7
a00a6b48:  bb 2e 60 10  sll  %i1, 0x10, %i5
a00a6b4c:  b8 13 e1 98  or  %o7, 0x198, %i4
a00a6b50:  82 06 00 18  add  %i0, %i0, %g1
a00a6b54:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a6b58:  c2 17 00 01  lduh  [ %i4 + %g1 ], %g1
a00a6b5c:  82 00 40 1d  add  %g1, %i5, %g1
a00a6b60:  83 28 60 02  sll  %g1, 2, %g1
a00a6b64:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a6b68:  82 10 40 1d  or  %g1, %i5, %g1
a00a6b6c:  f2 00 40 00  ld  [ %g1 ], %i1
a00a6b70:  82 0e e0 ff  and  %i3, 0xff, %g1
a00a6b74:  80 a0 60 01  cmp  %g1, 1
a00a6b78:  02 80 00 04  be  0xa00a6b88
a00a6b7c:  b6 16 40 1a  or  %i1, %i2, %i3
a00a6b80:  b6 2e 40 1a  andn  %i1, %i2, %i3
a00a6b84:  b8 13 e1 98  or  %o7, 0x198, %i4
a00a6b88:  82 06 00 18  add  %i0, %i0, %g1
a00a6b8c:  bb 2b 60 10  sll  %o5, 0x10, %i5
a00a6b90:  bb 37 60 10  srl  %i5, 0x10, %i5
a00a6b94:  c2 17 00 01  lduh  [ %i4 + %g1 ], %g1
a00a6b98:  82 00 40 1d  add  %g1, %i5, %g1
a00a6b9c:  3b 33 c0 00  sethi  %hi(0xcf000000), %i5
a00a6ba0:  83 28 60 02  sll  %g1, 2, %g1
a00a6ba4:  82 10 40 1d  or  %g1, %i5, %g1
a00a6ba8:  ba 0e e0 ff  and  %i3, 0xff, %i5
a00a6bac:  fa 20 40 00  st  %i5, [ %g1 ]
a00a6bb0:  81 c7 e0 08  ret
a00a6bb4:  81 e8 00 00  restore
