# leon2m FUN_a015ca50 0xa015ca50-0xa015cb28 (216 bytes)
a015ca50:  9d e3 bf 98  save  %sp, -104, %sp
a015ca54:  80 a6 a0 03  cmp  %i2, 3
a015ca58:  08 80 00 05  bleu  0xa015ca6c
a015ca5c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a015ca60:  80 8e 20 03  btst  3, %i0
a015ca64:  02 80 00 0d  be  0xa015ca98
a015ca68:  b8 10 00 18  mov  %i0, %i4
a015ca6c:  10 80 00 06  b  0xa015ca84
a015ca70:  b4 06 bf ff  add  %i2, -1, %i2
a015ca74:  80 a0 40 19  cmp  %g1, %i1
a015ca78:  02 80 00 2a  be  0xa015cb20
a015ca7c:  b4 06 bf ff  add  %i2, -1, %i2
a015ca80:  b0 06 20 01  inc  %i0
a015ca84:  80 a6 bf ff  cmp  %i2, -1
a015ca88:  32 bf ff fb  bne,a   0xa015ca74
a015ca8c:  c2 0e 00 00  ldub  [ %i0 ], %g1
a015ca90:  10 80 00 24  b  0xa015cb20
a015ca94:  b0 10 20 00  clr  %i0
a015ca98:  b6 10 20 00  clr  %i3
a015ca9c:  ba 10 20 03  mov  3, %i5
a015caa0:  83 2e e0 08  sll  %i3, 8, %g1
a015caa4:  ba 87 7f ff  addcc  %i5, -1, %i5
a015caa8:  1c bf ff fe  bpos  0xa015caa0
a015caac:  b6 00 40 19  add  %g1, %i1, %i3
a015cab0:  80 a6 a0 03  cmp  %i2, 3
a015cab4:  08 80 00 19  bleu  0xa015cb18
a015cab8:  03 3f bf bf  sethi  %hi(0xfefefc00), %g1
a015cabc:  3b 20 20 20  sethi  %hi(0x80808000), %i5
a015cac0:  9a 10 62 ff  or  %g1, 0x2ff, %o5
a015cac4:  9e 17 60 80  or  %i5, 0x80, %o7
a015cac8:  c2 07 00 00  ld  [ %i4 ], %g1
a015cacc:  82 18 40 1b  xor  %g1, %i3, %g1
a015cad0:  ba 00 40 0d  add  %g1, %o5, %i5
a015cad4:  82 2f 40 01  andn  %i5, %g1, %g1
a015cad8:  80 88 40 0f  btst  %g1, %o7
a015cadc:  22 80 00 0c  be,a   0xa015cb0c
a015cae0:  b4 06 bf fc  add  %i2, -4, %i2
a015cae4:  b0 10 00 1c  mov  %i4, %i0
a015cae8:  ba 10 20 00  clr  %i5
a015caec:  c2 0e 00 00  ldub  [ %i0 ], %g1
a015caf0:  80 a0 40 19  cmp  %g1, %i1
a015caf4:  02 80 00 0b  be  0xa015cb20
a015caf8:  ba 07 60 01  inc  %i5
a015cafc:  80 a7 60 03  cmp  %i5, 3
a015cb00:  08 bf ff fb  bleu  0xa015caec
a015cb04:  b0 06 20 01  inc  %i0
a015cb08:  b4 06 bf fc  add  %i2, -4, %i2
a015cb0c:  80 a6 a0 03  cmp  %i2, 3
a015cb10:  18 bf ff ee  bgu  0xa015cac8
a015cb14:  b8 07 20 04  add  %i4, 4, %i4
a015cb18:  10 bf ff d5  b  0xa015ca6c
a015cb1c:  b0 10 00 1c  mov  %i4, %i0
a015cb20:  81 c7 e0 08  ret
a015cb24:  81 e8 00 00  restore
