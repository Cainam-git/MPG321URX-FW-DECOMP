# leon2m FUN_a011ca58 0xa011ca58-0xa011cae0 (136 bytes)
a011ca58:  92 0a 60 ff  and  %o1, 0xff, %o1
a011ca5c:  80 a2 60 00  cmp  %o1, 0
a011ca60:  12 80 00 13  bne  0xa011caac
a011ca64:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011ca68:  9a 0a 20 ff  and  %o0, 0xff, %o5
a011ca6c:  82 10 63 8c  or  %g1, 0x38c, %g1
a011ca70:  da 20 40 00  st  %o5, [ %g1 ]
a011ca74:  82 10 20 9f  mov  0x9f, %g1
a011ca78:  01 00 00 00  nop
a011ca7c:  82 80 7f ff  addcc  %g1, -1, %g1
a011ca80:  1c bf ff fe  bpos  0xa011ca78
a011ca84:  9b 2a 20 10  sll  %o0, 0x10, %o5
a011ca88:  80 a2 60 00  cmp  %o1, 0
a011ca8c:  12 80 00 0b  bne  0xa011cab8
a011ca90:  83 33 60 18  srl  %o5, 0x18, %g1
a011ca94:  9a 08 60 ff  and  %g1, 0xff, %o5
a011ca98:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a011ca9c:  82 12 23 8c  or  %o0, 0x38c, %g1	! 0xcf01178c
a011caa0:  da 20 40 00  st  %o5, [ %g1 ]
a011caa4:  10 80 00 09  b  0xa011cac8
a011caa8:  82 10 20 9f  mov  0x9f, %g1
a011caac:  9a 0a 20 ff  and  %o0, 0xff, %o5
a011cab0:  10 bf ff f0  b  0xa011ca70
a011cab4:  82 10 63 a0  or  %g1, 0x3a0, %g1
a011cab8:  9a 08 60 ff  and  %g1, 0xff, %o5
a011cabc:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a011cac0:  10 bf ff f8  b  0xa011caa0
a011cac4:  82 12 63 a0  or  %o1, 0x3a0, %g1	! 0xcf0117a0
a011cac8:  01 00 00 00  nop
a011cacc:  82 80 7f ff  addcc  %g1, -1, %g1
a011cad0:  1c bf ff fe  bpos  0xa011cac8
a011cad4:  01 00 00 00  nop
a011cad8:  81 c3 e0 08  retl
a011cadc:  01 00 00 00  nop
