# leon2m FUN_a0133a10 0xa0133a10-0xa0133ad8 (200 bytes)
a0133a10:  9d e3 bf 98  save  %sp, -104, %sp
a0133a14:  ba 0e 20 ff  and  %i0, 0xff, %i5
a0133a18:  80 a7 60 00  cmp  %i5, 0
a0133a1c:  02 80 00 10  be  0xa0133a5c
a0133a20:  9e 10 20 00  clr  %o7
a0133a24:  b7 2f 60 03  sll  %i5, 3, %i3
a0133a28:  b4 06 c0 1d  add  %i3, %i5, %i2
a0133a2c:  b9 2e a0 02  sll  %i2, 2, %i4
a0133a30:  82 27 00 1d  sub  %i4, %i5, %g1
a0133a34:  33 2a 00 b7  sethi  %hi(0xa802dc00), %i1
a0133a38:  ba 16 61 90  or  %i1, 0x190, %i5	! 0xa802dd90
a0133a3c:  b6 00 40 1d  add  %g1, %i5, %i3
a0133a40:  f4 0f 40 01  ldub  [ %i5 + %g1 ], %i2
a0133a44:  f8 0e e0 01  ldub  [ %i3 + 1 ], %i4
a0133a48:  80 a6 80 1c  cmp  %i2, %i4
a0133a4c:  32 80 00 20  bne,a   0xa0133acc
a0133a50:  9e 10 00 18  mov  %i0, %o7
a0133a54:  10 80 00 1f  b  0xa0133ad0
a0133a58:  b0 0b e0 ff  and  %o7, 0xff, %i0
a0133a5c:  31 2a 00 b7  sethi  %hi(0xa802dc00), %i0
a0133a60:  b2 16 21 90  or  %i0, 0x190, %i1	! 0xa802dd90
a0133a64:  ba 10 20 01  mov  1, %i5
a0133a68:  b9 2f 60 03  sll  %i5, 3, %i4
a0133a6c:  82 07 00 1d  add  %i4, %i5, %g1
a0133a70:  b1 28 60 02  sll  %g1, 2, %i0
a0133a74:  b6 26 00 1d  sub  %i0, %i5, %i3
a0133a78:  b8 06 c0 19  add  %i3, %i1, %i4
a0133a7c:  fa 0e 40 1b  ldub  [ %i1 + %i3 ], %i5
a0133a80:  c2 0f 20 01  ldub  [ %i4 + 1 ], %g1
a0133a84:  80 a7 40 01  cmp  %i5, %g1
a0133a88:  12 80 00 10  bne  0xa0133ac8
a0133a8c:  b4 10 20 01  mov  1, %i2
a0133a90:  b4 06 a0 01  inc  %i2
a0133a94:  ba 0e a0 ff  and  %i2, 0xff, %i5
a0133a98:  80 a7 60 04  cmp  %i5, 4
a0133a9c:  18 80 00 0c  bgu  0xa0133acc
a0133aa0:  b9 2f 60 03  sll  %i5, 3, %i4
a0133aa4:  82 07 00 1d  add  %i4, %i5, %g1
a0133aa8:  b1 28 60 02  sll  %g1, 2, %i0
a0133aac:  b6 26 00 1d  sub  %i0, %i5, %i3
a0133ab0:  b8 06 c0 19  add  %i3, %i1, %i4
a0133ab4:  fa 0e 40 1b  ldub  [ %i1 + %i3 ], %i5
a0133ab8:  c2 0f 20 01  ldub  [ %i4 + 1 ], %g1
a0133abc:  80 a7 40 01  cmp  %i5, %g1
a0133ac0:  22 bf ff f5  be,a   0xa0133a94
a0133ac4:  b4 06 a0 01  inc  %i2
a0133ac8:  9e 10 00 1a  mov  %i2, %o7
a0133acc:  b0 0b e0 ff  and  %o7, 0xff, %i0
a0133ad0:  81 c7 e0 08  ret
a0133ad4:  81 e8 00 00  restore
