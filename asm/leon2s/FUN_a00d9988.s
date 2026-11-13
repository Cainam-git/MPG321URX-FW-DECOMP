# leon2s FUN_a00d9988 0xa00d9988-0xa00d9a78 (240 bytes)
a00d9988:  9d e3 bf 98  save  %sp, -104, %sp
a00d998c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00d9990:  80 a6 60 00  cmp  %i1, 0
a00d9994:  98 10 00 1a  mov  %i2, %o4
a00d9998:  96 10 00 18  mov  %i0, %o3
a00d999c:  b4 10 3f 80  mov  -128, %i2
a00d99a0:  9e 10 20 07  mov  7, %o7
a00d99a4:  b3 2e 60 03  sll  %i1, 3, %i1
a00d99a8:  02 80 00 25  be  0xa00d9a3c
a00d99ac:  b8 10 20 00  clr  %i4
a00d99b0:  83 2e e0 10  sll  %i3, 0x10, %g1
a00d99b4:  9b 30 60 10  srl  %g1, 0x10, %o5
a00d99b8:  83 2b 20 10  sll  %o4, 0x10, %g1
a00d99bc:  83 30 60 10  srl  %g1, 0x10, %g1
a00d99c0:  fa 0a c0 01  ldub  [ %o3 + %g1 ], %i5
a00d99c4:  ba 0f 40 1a  and  %i5, %i2, %i5
a00d99c8:  b6 00 60 01  add  %g1, 1, %i3
a00d99cc:  82 07 00 1c  add  %i4, %i4, %g1
a00d99d0:  bb 3f 40 0f  sra  %i5, %o7, %i5
a00d99d4:  b0 10 40 1d  or  %g1, %i5, %i0
a00d99d8:  b8 0e a0 ff  and  %i2, 0xff, %i4
a00d99dc:  82 06 7f ff  add  %i1, -1, %g1
a00d99e0:  b5 37 20 01  srl  %i4, 1, %i2
a00d99e4:  bb 28 60 10  sll  %g1, 0x10, %i5
a00d99e8:  80 a6 a0 00  cmp  %i2, 0
a00d99ec:  b8 10 00 18  mov  %i0, %i4
a00d99f0:  9e 03 ff ff  add  %o7, -1, %o7
a00d99f4:  12 80 00 0c  bne  0xa00d9a24
a00d99f8:  b2 10 00 01  mov  %g1, %i1
a00d99fc:  99 3e e0 1f  sra  %i3, 0x1f, %o4
a00d9a00:  81 83 20 00  mov  %o4, %y
a00d9a04:  01 00 00 00  nop
a00d9a08:  01 00 00 00  nop
a00d9a0c:  01 00 00 00  nop
a00d9a10:  82 7e c0 0d  sdiv  %i3, %o5, %g1
a00d9a14:  82 58 40 0d  smul  %g1, %o5, %g1
a00d9a18:  98 26 c0 01  sub  %i3, %g1, %o4
a00d9a1c:  b4 10 3f 80  mov  -128, %i2
a00d9a20:  9e 10 20 07  mov  7, %o7
a00d9a24:  80 8e 21 00  btst  0x100, %i0
a00d9a28:  32 80 00 02  bne,a   0xa00d9a30
a00d9a2c:  b8 1e 20 d5  xor  %i0, 0xd5, %i4
a00d9a30:  80 a7 60 00  cmp  %i5, 0
a00d9a34:  12 bf ff e2  bne  0xa00d99bc
a00d9a38:  83 2b 20 10  sll  %o4, 0x10, %g1
a00d9a3c:  b2 10 20 08  mov  8, %i1
a00d9a40:  ba 07 00 1c  add  %i4, %i4, %i5
a00d9a44:  82 06 7f ff  add  %i1, -1, %g1
a00d9a48:  b7 28 60 10  sll  %g1, 0x10, %i3
a00d9a4c:  80 8f 61 00  btst  0x100, %i5
a00d9a50:  b8 10 00 1d  mov  %i5, %i4
a00d9a54:  02 80 00 03  be  0xa00d9a60
a00d9a58:  b2 10 00 01  mov  %g1, %i1
a00d9a5c:  b8 1f 60 d5  xor  %i5, 0xd5, %i4
a00d9a60:  80 a6 e0 00  cmp  %i3, 0
a00d9a64:  12 bf ff f8  bne  0xa00d9a44
a00d9a68:  ba 07 00 1c  add  %i4, %i4, %i5
a00d9a6c:  b0 0f 20 ff  and  %i4, 0xff, %i0
a00d9a70:  81 c7 e0 08  ret
a00d9a74:  81 e8 00 00  restore
