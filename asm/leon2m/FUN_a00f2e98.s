# leon2m FUN_a00f2e98 0xa00f2e98-0xa00f2f88 (240 bytes)
a00f2e98:  9d e3 bf 98  save  %sp, -104, %sp
a00f2e9c:  9e 10 00 1b  mov  %i3, %o7
a00f2ea0:  b8 10 20 00  clr  %i4
a00f2ea4:  01 00 00 00  nop
a00f2ea8:  b8 07 20 01  inc  %i4
a00f2eac:  82 0f 20 ff  and  %i4, 0xff, %g1
a00f2eb0:  80 a0 60 1f  cmp  %g1, 0x1f
a00f2eb4:  08 bf ff fc  bleu  0xa00f2ea4
a00f2eb8:  ba 0e 20 ff  and  %i0, 0xff, %i5
a00f2ebc:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a00f2ec0:  b0 16 e3 80  or  %i3, 0x380, %i0	! 0xcf011780
a00f2ec4:  fa 26 00 00  st  %i5, [ %i0 ]
a00f2ec8:  ba 10 20 00  clr  %i5
a00f2ecc:  01 00 00 00  nop
a00f2ed0:  ba 07 60 01  inc  %i5
a00f2ed4:  b8 0f 60 ff  and  %i5, 0xff, %i4
a00f2ed8:  80 a7 20 1f  cmp  %i4, 0x1f
a00f2edc:  08 bf ff fc  bleu  0xa00f2ecc
a00f2ee0:  82 0e 60 ff  and  %i1, 0xff, %g1
a00f2ee4:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a00f2ee8:  b0 17 63 84  or  %i5, 0x384, %i0	! 0xcf011784
a00f2eec:  c2 26 00 00  st  %g1, [ %i0 ]
a00f2ef0:  b9 2e 60 10  sll  %i1, 0x10, %i4
a00f2ef4:  b0 17 63 88  or  %i5, 0x388, %i0
a00f2ef8:  b7 37 20 18  srl  %i4, 0x18, %i3
a00f2efc:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a00f2f00:  f6 26 00 00  st  %i3, [ %i0 ]
a00f2f04:  b2 10 63 cc  or  %g1, 0x3cc, %i1
a00f2f08:  c0 26 40 00  clr  [ %i1 ]
a00f2f0c:  ba 10 20 00  clr  %i5
a00f2f10:  01 00 00 00  nop
a00f2f14:  ba 07 60 01  inc  %i5
a00f2f18:  b2 0f 60 ff  and  %i5, 0xff, %i1
a00f2f1c:  80 a6 60 1f  cmp  %i1, 0x1f
a00f2f20:  08 bf ff fc  bleu  0xa00f2f10
a00f2f24:  01 00 00 00  nop
a00f2f28:  b5 2e a0 10  sll  %i2, 0x10, %i2
a00f2f2c:  80 a6 a0 00  cmp  %i2, 0
a00f2f30:  02 80 00 14  be  0xa00f2f80
a00f2f34:  b8 10 20 00  clr  %i4
a00f2f38:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a00f2f3c:  b6 17 63 8c  or  %i5, 0x38c, %i3	! 0xcf01178c
a00f2f40:  b3 2f 20 10  sll  %i4, 0x10, %i1
a00f2f44:  83 36 60 10  srl  %i1, 0x10, %g1
a00f2f48:  f0 08 40 0f  ldub  [ %g1 + %o7 ], %i0
a00f2f4c:  f0 26 c0 00  st  %i0, [ %i3 ]
a00f2f50:  ba 10 20 00  clr  %i5
a00f2f54:  01 00 00 00  nop
a00f2f58:  ba 07 60 01  inc  %i5
a00f2f5c:  b0 0f 60 ff  and  %i5, 0xff, %i0
a00f2f60:  80 a6 20 1f  cmp  %i0, 0x1f
a00f2f64:  08 bf ff fc  bleu  0xa00f2f54
a00f2f68:  01 00 00 00  nop
a00f2f6c:  ba 07 20 01  add  %i4, 1, %i5
a00f2f70:  b9 2f 60 10  sll  %i5, 0x10, %i4
a00f2f74:  80 a6 80 1c  cmp  %i2, %i4
a00f2f78:  18 bf ff f2  bgu  0xa00f2f40
a00f2f7c:  b8 10 00 1d  mov  %i5, %i4
a00f2f80:  81 c7 e0 08  ret
a00f2f84:  81 e8 00 00  restore
