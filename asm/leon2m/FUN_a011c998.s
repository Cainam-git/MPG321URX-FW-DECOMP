# leon2m FUN_a011c998 0xa011c998-0xa011ca58 (192 bytes)
a011c998:  94 0a a0 ff  and  %o2, 0xff, %o2
a011c99c:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011c9a0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a011c9a4:  80 a2 a0 00  cmp  %o2, 0
a011c9a8:  02 80 00 05  be  0xa011c9bc
a011c9ac:  82 10 63 8c  or  %g1, 0x38c, %g1
a011c9b0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a011c9b4:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a011c9b8:  82 12 23 a0  or  %o0, 0x3a0, %g1	! 0xcf0117a0
a011c9bc:  da 20 40 00  st  %o5, [ %g1 ]
a011c9c0:  82 10 20 9f  mov  0x9f, %g1
a011c9c4:  01 00 00 00  nop
a011c9c8:  82 80 7f ff  addcc  %g1, -1, %g1
a011c9cc:  1c bf ff fe  bpos  0xa011c9c4
a011c9d0:  80 a2 a0 00  cmp  %o2, 0
a011c9d4:  12 80 00 14  bne  0xa011ca24
a011c9d8:  11 33 c0 45  sethi  %hi(0xcf011400), %o0
a011c9dc:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a011c9e0:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011c9e4:  82 10 63 8c  or  %g1, 0x38c, %g1
a011c9e8:  da 20 40 00  st  %o5, [ %g1 ]
a011c9ec:  82 10 20 9f  mov  0x9f, %g1
a011c9f0:  01 00 00 00  nop
a011c9f4:  82 80 7f ff  addcc  %g1, -1, %g1
a011c9f8:  1c bf ff fe  bpos  0xa011c9f0
a011c9fc:  9b 2a 60 10  sll  %o1, 0x10, %o5
a011ca00:  80 a2 a0 00  cmp  %o2, 0
a011ca04:  12 80 00 0b  bne  0xa011ca30
a011ca08:  83 33 60 18  srl  %o5, 0x18, %g1
a011ca0c:  9a 08 60 ff  and  %g1, 0xff, %o5
a011ca10:  13 33 c0 45  sethi  %hi(0xcf011400), %o1
a011ca14:  82 12 63 8c  or  %o1, 0x38c, %g1	! 0xcf01178c
a011ca18:  da 20 40 00  st  %o5, [ %g1 ]
a011ca1c:  10 80 00 09  b  0xa011ca40
a011ca20:  82 10 20 9f  mov  0x9f, %g1
a011ca24:  9a 0a 60 ff  and  %o1, 0xff, %o5
a011ca28:  10 bf ff f0  b  0xa011c9e8
a011ca2c:  82 12 23 a0  or  %o0, 0x3a0, %g1
a011ca30:  9a 08 60 ff  and  %g1, 0xff, %o5
a011ca34:  15 33 c0 45  sethi  %hi(0xcf011400), %o2
a011ca38:  10 bf ff f8  b  0xa011ca18
a011ca3c:  82 12 a3 a0  or  %o2, 0x3a0, %g1	! 0xcf0117a0
a011ca40:  01 00 00 00  nop
a011ca44:  82 80 7f ff  addcc  %g1, -1, %g1
a011ca48:  1c bf ff fe  bpos  0xa011ca40
a011ca4c:  01 00 00 00  nop
a011ca50:  81 c3 e0 08  retl
a011ca54:  01 00 00 00  nop
