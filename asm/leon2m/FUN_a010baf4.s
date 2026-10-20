# leon2m FUN_a010baf4 0xa010baf4-0xa010bdcc (728 bytes)
a010baf4:  9d e3 bf 98  save  %sp, -104, %sp
a010baf8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010bafc:  ba 10 00 19  mov  %i1, %i5
a010bb00:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010bb04:  80 a6 20 01  cmp  %i0, 1
a010bb08:  02 80 00 06  be  0xa010bb20
a010bb0c:  b2 10 63 c4  or  %g1, 0x3c4, %i1
a010bb10:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010bb14:  80 a6 20 02  cmp  %i0, 2
a010bb18:  02 80 00 87  be  0xa010bd34
a010bb1c:  b2 10 63 44  or  %g1, 0x344, %i1
a010bb20:  9e 0f 60 ff  and  %i5, 0xff, %o7
a010bb24:  c2 0e 60 24  ldub  [ %i1 + 0x24 ], %g1
a010bb28:  83 30 60 03  srl  %g1, 3, %g1
a010bb2c:  ba 0f 20 1f  and  %i4, 0x1f, %i5
a010bb30:  81 80 00 00  mov  %g0, %y
a010bb34:  01 00 00 00  nop
a010bb38:  01 00 00 00  nop
a010bb3c:  01 00 00 00  nop
a010bb40:  9a 77 40 01  udiv  %i5, %g1, %o5
a010bb44:  80 a3 e0 00  cmp  %o7, 0
a010bb48:  12 80 00 6c  bne  0xa010bcf8
a010bb4c:  83 37 20 05  srl  %i4, 5, %g1
a010bb50:  bb 37 20 05  srl  %i4, 5, %i5
a010bb54:  fa 26 60 04  st  %i5, [ %i1 + 4 ]
a010bb58:  f4 36 60 10  sth  %i2, [ %i1 + 0x10 ]
a010bb5c:  99 2e e0 10  sll  %i3, 0x10, %o4
a010bb60:  97 2e a0 10  sll  %i2, 0x10, %o3
a010bb64:  b9 33 20 10  srl  %o4, 0x10, %i4
a010bb68:  f6 36 60 0e  sth  %i3, [ %i1 + 0xe ]
a010bb6c:  35 00 06 6b  sethi  %hi(0x19ac00), %i2
a010bb70:  b6 12 c0 1c  or  %o3, %i4, %i3
a010bb74:  83 2e 20 02  sll  %i0, 2, %g1
a010bb78:  80 a3 e0 00  cmp  %o7, 0
a010bb7c:  02 80 00 05  be  0xa010bb90
a010bb80:  ba 16 a2 d8  or  %i2, 0x2d8, %i5
a010bb84:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010bb88:  83 2e 20 02  sll  %i0, 2, %g1
a010bb8c:  ba 17 62 cc  or  %i5, 0x2cc, %i5
a010bb90:  f4 07 40 01  ld  [ %i5 + %g1 ], %i2
a010bb94:  f6 26 a0 1c  st  %i3, [ %i2 + 0x1c ]
a010bb98:  f8 0e 60 24  ldub  [ %i1 + 0x24 ], %i4
a010bb9c:  83 37 20 03  srl  %i4, 3, %g1
a010bba0:  b4 10 20 20  mov  0x20, %i2
a010bba4:  95 3e a0 1f  sra  %i2, 0x1f, %o2
a010bba8:  81 82 a0 00  mov  %o2, %y
a010bbac:  01 00 00 00  nop
a010bbb0:  01 00 00 00  nop
a010bbb4:  01 00 00 00  nop
a010bbb8:  ba 7e 80 01  sdiv  %i2, %g1, %i5
a010bbbc:  f6 16 60 0c  lduh  [ %i1 + 0xc ], %i3
a010bbc0:  81 80 00 00  mov  %g0, %y
a010bbc4:  01 00 00 00  nop
a010bbc8:  01 00 00 00  nop
a010bbcc:  01 00 00 00  nop
a010bbd0:  82 76 c0 1d  udiv  %i3, %i5, %g1
a010bbd4:  b4 58 40 1d  smul  %g1, %i5, %i2
a010bbd8:  80 a6 c0 1a  cmp  %i3, %i2
a010bbdc:  02 80 00 04  be  0xa010bbec
a010bbe0:  b9 2b 60 10  sll  %o5, 0x10, %i4
a010bbe4:  b6 00 60 01  add  %g1, 1, %i3
a010bbe8:  b4 5e c0 1d  smul  %i3, %i5, %i2
a010bbec:  80 a3 e0 00  cmp  %o7, 0
a010bbf0:  12 80 00 37  bne  0xa010bccc
a010bbf4:  b6 17 00 1a  or  %i4, %i2, %i3
a010bbf8:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010bbfc:  83 2e 20 02  sll  %i0, 2, %g1
a010bc00:  ba 17 22 d8  or  %i4, 0x2d8, %i5
a010bc04:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a010bc08:  f6 27 20 20  st  %i3, [ %i4 + 0x20 ]
a010bc0c:  f6 06 60 04  ld  [ %i1 + 4 ], %i3
a010bc10:  80 a6 20 01  cmp  %i0, 1
a010bc14:  02 80 00 37  be  0xa010bcf0
a010bc18:  03 01 00 00  sethi  %hi(0x4000000), %g1
a010bc1c:  80 a6 20 02  cmp  %i0, 2
a010bc20:  02 80 00 43  be  0xa010bd2c
a010bc24:  03 02 00 00  sethi  %hi(0x8000000), %g1
a010bc28:  3b 00 06 6b  sethi  %hi(0x19ac00), %i5
a010bc2c:  83 2e 20 02  sll  %i0, 2, %g1
a010bc30:  80 a3 e0 00  cmp  %o7, 0
a010bc34:  02 80 00 05  be  0xa010bc48
a010bc38:  ba 17 62 d8  or  %i5, 0x2d8, %i5
a010bc3c:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010bc40:  83 2e 20 02  sll  %i0, 2, %g1
a010bc44:  ba 17 22 cc  or  %i4, 0x2cc, %i5
a010bc48:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a010bc4c:  f6 27 20 24  st  %i3, [ %i4 + 0x24 ]
a010bc50:  83 33 20 10  srl  %o4, 0x10, %g1
a010bc54:  b6 58 40 1a  smul  %g1, %i2, %i3
a010bc58:  fa 0e 60 24  ldub  [ %i1 + 0x24 ], %i5
a010bc5c:  b4 5e c0 1d  smul  %i3, %i5, %i2
a010bc60:  33 00 06 6b  sethi  %hi(0x19ac00), %i1
a010bc64:  b7 36 a0 07  srl  %i2, 7, %i3
a010bc68:  83 2e 20 02  sll  %i0, 2, %g1
a010bc6c:  80 a3 e0 00  cmp  %o7, 0
a010bc70:  02 80 00 05  be  0xa010bc84
a010bc74:  ba 16 62 d8  or  %i1, 0x2d8, %i5
a010bc78:  33 00 06 6b  sethi  %hi(0x19ac00), %i1
a010bc7c:  83 2e 20 02  sll  %i0, 2, %g1
a010bc80:  ba 16 62 cc  or  %i1, 0x2cc, %i5
a010bc84:  f4 07 40 01  ld  [ %i5 + %g1 ], %i2
a010bc88:  b3 32 e0 10  srl  %o3, 0x10, %i1
a010bc8c:  39 33 33 33  sethi  %hi(0xcccccc00), %i4
a010bc90:  f6 26 a0 28  st  %i3, [ %i2 + 0x28 ]
a010bc94:  82 5e 60 dc  smul  %i1, 0xdc, %g1
a010bc98:  ba 17 20 cd  or  %i4, 0xcd, %i5
a010bc9c:  80 50 40 1d  umul  %g1, %i5, %g0
a010bca0:  b7 40 00 00  rd  %y, %i3
a010bca4:  b5 36 e0 08  srl  %i3, 8, %i2
a010bca8:  80 a6 20 01  cmp  %i0, 1
a010bcac:  02 80 00 16  be  0xa010bd04
a010bcb0:  82 06 a0 01  add  %i2, 1, %g1
a010bcb4:  80 a6 20 01  cmp  %i0, 1
a010bcb8:  04 80 00 31  ble  0xa010bd7c
a010bcbc:  80 a6 20 02  cmp  %i0, 2
a010bcc0:  12 80 00 41  bne  0xa010bdc4
a010bcc4:  80 a0 66 bf  cmp  %g1, 0x6bf
a010bcc8:  30 80 00 1e  b,a   0xa010bd40
a010bccc:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010bcd0:  83 2e 20 02  sll  %i0, 2, %g1
a010bcd4:  ba 17 22 cc  or  %i4, 0x2cc, %i5
a010bcd8:  f8 07 40 01  ld  [ %i5 + %g1 ], %i4
a010bcdc:  f6 27 20 20  st  %i3, [ %i4 + 0x20 ]
a010bce0:  f6 06 60 08  ld  [ %i1 + 8 ], %i3
a010bce4:  80 a6 20 01  cmp  %i0, 1
a010bce8:  12 bf ff cd  bne  0xa010bc1c
a010bcec:  03 01 00 00  sethi  %hi(0x4000000), %g1
a010bcf0:  10 bf ff ce  b  0xa010bc28
a010bcf4:  b6 16 c0 01  or  %i3, %g1, %i3
a010bcf8:  c2 26 60 08  st  %g1, [ %i1 + 8 ]
a010bcfc:  10 bf ff 98  b  0xa010bb5c
a010bd00:  f4 36 60 12  sth  %i2, [ %i1 + 0x12 ]
a010bd04:  80 a0 64 ff  cmp  %g1, 0x4ff
a010bd08:  18 80 00 17  bgu  0xa010bd64
a010bd0c:  80 a3 e0 00  cmp  %o7, 0
a010bd10:  12 80 00 18  bne  0xa010bd70
a010bd14:  bb 28 60 10  sll  %g1, 0x10, %i5
a010bd18:  bb 28 60 10  sll  %g1, 0x10, %i5
a010bd1c:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010bd20:  82 10 60 94  or  %g1, 0x94, %g1	! 0xd0030094
a010bd24:  fa 20 40 00  st  %i5, [ %g1 ]
a010bd28:  30 80 00 27  b,a   0xa010bdc4
a010bd2c:  10 bf ff bf  b  0xa010bc28
a010bd30:  b6 16 c0 01  or  %i3, %g1, %i3
a010bd34:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010bd38:  10 bf ff 7a  b  0xa010bb20
a010bd3c:  b2 10 63 84  or  %g1, 0x384, %i1	! 0xa802d784
a010bd40:  38 80 00 02  bgu,a   0xa010bd48
a010bd44:  82 10 26 bf  mov  0x6bf, %g1
a010bd48:  80 a3 e0 00  cmp  %o7, 0
a010bd4c:  12 80 00 18  bne  0xa010bdac
a010bd50:  bb 28 60 10  sll  %g1, 0x10, %i5
a010bd54:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010bd58:  82 10 60 98  or  %g1, 0x98, %g1	! 0xd0030098
a010bd5c:  fa 20 40 00  st  %i5, [ %g1 ]
a010bd60:  30 80 00 19  b,a   0xa010bdc4
a010bd64:  02 bf ff ed  be  0xa010bd18
a010bd68:  82 10 24 ff  mov  0x4ff, %g1
a010bd6c:  bb 28 60 10  sll  %g1, 0x10, %i5
a010bd70:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010bd74:  10 bf ff ec  b  0xa010bd24
a010bd78:  82 10 60 94  or  %g1, 0x94, %g1	! 0xd0038094
a010bd7c:  80 a6 20 00  cmp  %i0, 0
a010bd80:  12 80 00 11  bne  0xa010bdc4
a010bd84:  80 a0 69 ff  cmp  %g1, 0x9ff
a010bd88:  38 80 00 02  bgu,a   0xa010bd90
a010bd8c:  82 10 29 ff  mov  0x9ff, %g1
a010bd90:  80 a3 e0 00  cmp  %o7, 0
a010bd94:  12 80 00 09  bne  0xa010bdb8
a010bd98:  bb 28 60 10  sll  %g1, 0x10, %i5
a010bd9c:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010bda0:  82 10 60 90  or  %g1, 0x90, %g1	! 0xd0030090
a010bda4:  fa 20 40 00  st  %i5, [ %g1 ]
a010bda8:  30 80 00 07  b,a   0xa010bdc4
a010bdac:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010bdb0:  10 bf ff eb  b  0xa010bd5c
a010bdb4:  82 10 60 98  or  %g1, 0x98, %g1	! 0xd0038098
a010bdb8:  03 34 00 e0  sethi  %hi(0xd0038000), %g1
a010bdbc:  10 bf ff fa  b  0xa010bda4
a010bdc0:  82 10 60 90  or  %g1, 0x90, %g1	! 0xd0038090
a010bdc4:  81 c7 e0 08  ret
a010bdc8:  81 e8 00 00  restore
