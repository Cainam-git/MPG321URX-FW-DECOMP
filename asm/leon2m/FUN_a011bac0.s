# leon2m FUN_a011bac0 0xa011bac0-0xa011bd60 (672 bytes)
a011bac0:  9d e3 bf 98  save  %sp, -104, %sp
a011bac4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a011bac8:  80 a6 60 00  cmp  %i1, 0
a011bacc:  12 80 00 48  bne  0xa011bbec
a011bad0:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011bad4:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011bad8:  82 16 a3 80  or  %i2, 0x380, %g1	! 0xcf011780
a011badc:  ba 10 20 a0  mov  0xa0, %i5
a011bae0:  fa 20 40 00  st  %i5, [ %g1 ]
a011bae4:  82 10 20 9f  mov  0x9f, %g1
a011bae8:  01 00 00 00  nop
a011baec:  82 80 7f ff  addcc  %g1, -1, %g1
a011baf0:  1c bf ff fe  bpos  0xa011bae8
a011baf4:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a011baf8:  f8 13 21 a2  lduh  [ %o4 + 0x1a2 ], %i4	! 0xa802c9a2
a011bafc:  b5 2f 20 10  sll  %i4, 0x10, %i2
a011bb00:  bb 36 a0 10  srl  %i2, 0x10, %i5
a011bb04:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011bb08:  82 0f 60 ff  and  %i5, 0xff, %g1
a011bb0c:  ba 16 e3 84  or  %i3, 0x384, %i5
a011bb10:  c2 27 40 00  st  %g1, [ %i5 ]
a011bb14:  82 16 e3 88  or  %i3, 0x388, %g1
a011bb18:  bb 36 a0 18  srl  %i2, 0x18, %i5
a011bb1c:  39 33 c0 2f  sethi  %hi(0xcf00bc00), %i4
a011bb20:  fa 20 40 00  st  %i5, [ %g1 ]
a011bb24:  b6 17 23 cc  or  %i4, 0x3cc, %i3
a011bb28:  c0 26 c0 00  clr  [ %i3 ]
a011bb2c:  82 10 20 9f  mov  0x9f, %g1
a011bb30:  01 00 00 00  nop
a011bb34:  82 80 7f ff  addcc  %g1, -1, %g1
a011bb38:  1c bf ff fe  bpos  0xa011bb30
a011bb3c:  01 00 00 00  nop
a011bb40:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a011bb44:  f6 08 61 b8  ldub  [ %g1 + 0x1b8 ], %i3	! 0xa802c9b8
a011bb48:  b5 2e e0 02  sll  %i3, 2, %i2
a011bb4c:  9e 0e a0 ff  and  %i2, 0xff, %o7
a011bb50:  80 a3 e0 00  cmp  %o7, 0
a011bb54:  02 80 00 77  be  0xa011bd30
a011bb58:  b4 10 20 00  clr  %i2
a011bb5c:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011bb60:  9a 17 63 8c  or  %i5, 0x38c, %o5	! 0xcf01178c
a011bb64:  b6 10 20 00  clr  %i3
a011bb68:  82 06 c0 18  add  %i3, %i0, %g1
a011bb6c:  f8 08 60 02  ldub  [ %g1 + 2 ], %i4
a011bb70:  f8 23 40 00  st  %i4, [ %o5 ]
a011bb74:  82 10 20 9f  mov  0x9f, %g1
a011bb78:  01 00 00 00  nop
a011bb7c:  82 80 7f ff  addcc  %g1, -1, %g1
a011bb80:  1c bf ff fe  bpos  0xa011bb78
a011bb84:  ba 06 c0 18  add  %i3, %i0, %i5
a011bb88:  f8 0f 60 01  ldub  [ %i5 + 1 ], %i4
a011bb8c:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011bb90:  ba 10 63 8c  or  %g1, 0x38c, %i5	! 0xcf01178c
a011bb94:  f8 27 40 00  st  %i4, [ %i5 ]
a011bb98:  82 10 20 9f  mov  0x9f, %g1
a011bb9c:  01 00 00 00  nop
a011bba0:  82 80 7f ff  addcc  %g1, -1, %g1
a011bba4:  1c bf ff fe  bpos  0xa011bb9c
a011bba8:  01 00 00 00  nop
a011bbac:  f8 0e c0 18  ldub  [ %i3 + %i0 ], %i4
a011bbb0:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011bbb4:  b6 10 63 8c  or  %g1, 0x38c, %i3	! 0xcf01178c
a011bbb8:  f8 26 c0 00  st  %i4, [ %i3 ]
a011bbbc:  82 10 20 9f  mov  0x9f, %g1
a011bbc0:  01 00 00 00  nop
a011bbc4:  82 80 7f ff  addcc  %g1, -1, %g1
a011bbc8:  1c bf ff fe  bpos  0xa011bbc0
a011bbcc:  01 00 00 00  nop
a011bbd0:  b4 06 a0 04  add  %i2, 4, %i2
a011bbd4:  b6 0e a0 ff  and  %i2, 0xff, %i3
a011bbd8:  80 a6 c0 0f  cmp  %i3, %o7
a011bbdc:  0a bf ff e4  bcs  0xa011bb6c
a011bbe0:  82 06 c0 18  add  %i3, %i0, %g1
a011bbe4:  10 80 00 54  b  0xa011bd34
a011bbe8:  39 2a 00 b2  sethi  %hi(0xa802c800), %i4
a011bbec:  ba 10 20 a0  mov  0xa0, %i5
a011bbf0:  b4 16 e3 94  or  %i3, 0x394, %i2
a011bbf4:  fa 26 80 00  st  %i5, [ %i2 ]
a011bbf8:  82 10 20 9f  mov  0x9f, %g1
a011bbfc:  01 00 00 00  nop
a011bc00:  82 80 7f ff  addcc  %g1, -1, %g1
a011bc04:  1c bf ff fe  bpos  0xa011bbfc
a011bc08:  19 2a 00 b2  sethi  %hi(0xa802c800), %o4
a011bc0c:  82 13 21 a2  or  %o4, 0x1a2, %g1	! 0xa802c9a2
a011bc10:  b4 06 40 19  add  %i1, %i1, %i2
a011bc14:  f8 10 40 1a  lduh  [ %g1 + %i2 ], %i4
a011bc18:  b7 2f 20 10  sll  %i4, 0x10, %i3
a011bc1c:  80 a6 60 00  cmp  %i1, 0
a011bc20:  12 80 00 3b  bne  0xa011bd0c
a011bc24:  bb 36 e0 10  srl  %i3, 0x10, %i5
a011bc28:  35 33 c0 45  sethi  %hi(0xcf011400), %i2
a011bc2c:  b8 0f 60 ff  and  %i5, 0xff, %i4
a011bc30:  82 16 a3 84  or  %i2, 0x384, %g1
a011bc34:  f8 20 40 00  st  %i4, [ %g1 ]
a011bc38:  b8 16 a3 88  or  %i2, 0x388, %i4
a011bc3c:  bb 36 e0 18  srl  %i3, 0x18, %i5
a011bc40:  fa 27 00 00  st  %i5, [ %i4 ]
a011bc44:  03 33 c0 2f  sethi  %hi(0xcf00bc00), %g1
a011bc48:  b6 10 63 cc  or  %g1, 0x3cc, %i3	! 0xcf00bfcc
a011bc4c:  c0 26 c0 00  clr  [ %i3 ]
a011bc50:  82 10 20 9f  mov  0x9f, %g1
a011bc54:  01 00 00 00  nop
a011bc58:  82 80 7f ff  addcc  %g1, -1, %g1
a011bc5c:  1c bf ff fe  bpos  0xa011bc54
a011bc60:  35 2a 00 b2  sethi  %hi(0xa802c800), %i2
a011bc64:  82 16 a1 b8  or  %i2, 0x1b8, %g1	! 0xa802c9b8
a011bc68:  f8 08 40 19  ldub  [ %g1 + %i1 ], %i4
a011bc6c:  bb 2f 20 02  sll  %i4, 2, %i5
a011bc70:  9e 0f 60 ff  and  %i5, 0xff, %o7
a011bc74:  80 a3 e0 00  cmp  %o7, 0
a011bc78:  02 80 00 2e  be  0xa011bd30
a011bc7c:  b4 10 20 00  clr  %i2
a011bc80:  37 33 c0 45  sethi  %hi(0xcf011400), %i3
a011bc84:  9a 16 e3 a0  or  %i3, 0x3a0, %o5	! 0xcf0117a0
a011bc88:  b6 10 20 00  clr  %i3
a011bc8c:  b8 06 c0 18  add  %i3, %i0, %i4
a011bc90:  fa 0f 20 02  ldub  [ %i4 + 2 ], %i5
a011bc94:  fa 23 40 00  st  %i5, [ %o5 ]
a011bc98:  82 10 20 9f  mov  0x9f, %g1
a011bc9c:  01 00 00 00  nop
a011bca0:  82 80 7f ff  addcc  %g1, -1, %g1
a011bca4:  1c bf ff fe  bpos  0xa011bc9c
a011bca8:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011bcac:  82 06 c0 18  add  %i3, %i0, %g1
a011bcb0:  f8 08 60 01  ldub  [ %g1 + 1 ], %i4
a011bcb4:  82 17 63 a0  or  %i5, 0x3a0, %g1
a011bcb8:  f8 20 40 00  st  %i4, [ %g1 ]
a011bcbc:  82 10 20 9f  mov  0x9f, %g1
a011bcc0:  01 00 00 00  nop
a011bcc4:  82 80 7f ff  addcc  %g1, -1, %g1
a011bcc8:  1c bf ff fe  bpos  0xa011bcc0
a011bccc:  3b 33 c0 45  sethi  %hi(0xcf011400), %i5
a011bcd0:  f8 0e c0 18  ldub  [ %i3 + %i0 ], %i4
a011bcd4:  b6 17 63 a0  or  %i5, 0x3a0, %i3
a011bcd8:  f8 26 c0 00  st  %i4, [ %i3 ]
a011bcdc:  82 10 20 9f  mov  0x9f, %g1
a011bce0:  01 00 00 00  nop
a011bce4:  82 80 7f ff  addcc  %g1, -1, %g1
a011bce8:  1c bf ff fe  bpos  0xa011bce0
a011bcec:  01 00 00 00  nop
a011bcf0:  b4 06 a0 04  add  %i2, 4, %i2
a011bcf4:  b6 0e a0 ff  and  %i2, 0xff, %i3
a011bcf8:  80 a6 c0 0f  cmp  %i3, %o7
a011bcfc:  2a bf ff e5  bcs,a   0xa011bc90
a011bd00:  b8 06 c0 18  add  %i3, %i0, %i4
a011bd04:  10 80 00 0c  b  0xa011bd34
a011bd08:  39 2a 00 b2  sethi  %hi(0xa802c800), %i4
a011bd0c:  39 33 c0 45  sethi  %hi(0xcf011400), %i4
a011bd10:  b4 0f 60 ff  and  %i5, 0xff, %i2
a011bd14:  82 17 23 98  or  %i4, 0x398, %g1
a011bd18:  f4 20 40 00  st  %i2, [ %g1 ]
a011bd1c:  b4 17 23 9c  or  %i4, 0x39c, %i2
a011bd20:  bb 36 e0 18  srl  %i3, 0x18, %i5
a011bd24:  fa 26 80 00  st  %i5, [ %i2 ]
a011bd28:  10 bf ff c8  b  0xa011bc48
a011bd2c:  03 33 c0 30  sethi  %hi(0xcf00c000), %g1
a011bd30:  39 2a 00 b2  sethi  %hi(0xa802c800), %i4
a011bd34:  b4 13 21 a2  or  %o4, 0x1a2, %i2
a011bd38:  b0 17 21 a0  or  %i4, 0x1a0, %i0
a011bd3c:  b6 06 40 19  add  %i1, %i1, %i3
a011bd40:  c2 16 80 1b  lduh  [ %i2 + %i3 ], %g1
a011bd44:  fa 0e 00 19  ldub  [ %i0 + %i1 ], %i5
a011bd48:  82 00 60 01  inc  %g1
a011bd4c:  ba 07 60 01  inc  %i5
a011bd50:  c2 36 80 1b  sth  %g1, [ %i2 + %i3 ]
a011bd54:  fa 2e 00 19  stb  %i5, [ %i0 + %i1 ]
a011bd58:  81 c7 e0 08  ret
a011bd5c:  81 e8 00 00  restore
