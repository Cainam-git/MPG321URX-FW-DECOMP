# leon2s FUN_a00adf84 0xa00adf84-0xa00ae0dc (344 bytes)
a00adf84:  9d e3 bf 98  save  %sp, -104, %sp
a00adf88:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00adf8c:  7f c4 61 a6  call  0x9f1c6624
a00adf90:  90 10 00 18  mov  %i0, %o0
a00adf94:  92 0a 20 ff  and  %o0, 0xff, %o1
a00adf98:  7f ff ff 6c  call  0xa00add48
a00adf9c:  90 10 00 18  mov  %i0, %o0
a00adfa0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00adfa4:  80 a0 60 03  cmp  %g1, 3
a00adfa8:  18 80 00 1b  bgu  0xa00ae014
a00adfac:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00adfb0:  80 a6 60 01  cmp  %i1, 1
a00adfb4:  12 80 00 06  bne  0xa00adfcc
a00adfb8:  17 33 c0 51  sethi  %hi(0xcf014400), %o3
a00adfbc:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a00adfc0:  98 13 23 98  or  %o4, 0x398, %o4	! 0xcf014798
a00adfc4:  10 80 00 1a  b  0xa00ae02c
a00adfc8:  82 00 40 01  add  %g1, %g1, %g1
a00adfcc:  96 12 e3 98  or  %o3, 0x398, %o3
a00adfd0:  80 a6 60 02  cmp  %i1, 2
a00adfd4:  02 80 00 22  be  0xa00ae05c
a00adfd8:  98 00 40 01  add  %g1, %g1, %o4
a00adfdc:  80 a6 60 04  cmp  %i1, 4
a00adfe0:  12 80 00 05  bne  0xa00adff4
a00adfe4:  96 00 40 01  add  %g1, %g1, %o3
a00adfe8:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a00adfec:  10 80 00 29  b  0xa00ae090
a00adff0:  98 13 23 98  or  %o4, 0x398, %o4	! 0xcf014798
a00adff4:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a00adff8:  82 10 63 98  or  %g1, 0x398, %g1	! 0xcf014798
a00adffc:  9a 10 20 03  mov  3, %o5
a00ae000:  d8 00 40 00  ld  [ %g1 ], %o4
a00ae004:  9b 2b 40 0b  sll  %o5, %o3, %o5
a00ae008:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00ae00c:  da 20 40 00  st  %o5, [ %g1 ]
a00ae010:  30 80 00 31  b,a   0xa00ae0d4
a00ae014:  80 a6 60 01  cmp  %i1, 1
a00ae018:  12 80 00 0a  bne  0xa00ae040
a00ae01c:  90 02 3f fc  add  %o0, -4, %o0
a00ae020:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a00ae024:  98 13 23 9c  or  %o4, 0x39c, %o4	! 0xcf01479c
a00ae028:  82 02 00 08  add  %o0, %o0, %g1
a00ae02c:  9a 10 20 03  mov  3, %o5
a00ae030:  9b 2b 40 01  sll  %o5, %g1, %o5
a00ae034:  c2 03 00 00  ld  [ %o4 ], %g1
a00ae038:  10 80 00 26  b  0xa00ae0d0
a00ae03c:  82 10 40 0d  or  %g1, %o5, %g1
a00ae040:  80 a6 60 02  cmp  %i1, 2
a00ae044:  12 80 00 0e  bne  0xa00ae07c
a00ae048:  80 a6 60 04  cmp  %i1, 4
a00ae04c:  98 0a 20 ff  and  %o0, 0xff, %o4
a00ae050:  17 33 c0 51  sethi  %hi(0xcf014400), %o3
a00ae054:  96 12 e3 9c  or  %o3, 0x39c, %o3	! 0xcf01479c
a00ae058:  98 03 00 0c  add  %o4, %o4, %o4
a00ae05c:  82 10 20 03  mov  3, %g1
a00ae060:  83 28 40 0c  sll  %g1, %o4, %g1
a00ae064:  da 02 c0 00  ld  [ %o3 ], %o5
a00ae068:  82 2b 40 01  andn  %o5, %g1, %g1
a00ae06c:  99 2e 40 0c  sll  %i1, %o4, %o4
a00ae070:  82 10 40 0c  or  %g1, %o4, %g1
a00ae074:  c2 22 c0 00  st  %g1, [ %o3 ]
a00ae078:  30 80 00 17  b,a   0xa00ae0d4
a00ae07c:  12 80 00 0e  bne  0xa00ae0b4
a00ae080:  82 0a 20 ff  and  %o0, 0xff, %g1
a00ae084:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a00ae088:  98 13 23 9c  or  %o4, 0x39c, %o4	! 0xcf01479c
a00ae08c:  96 00 40 01  add  %g1, %g1, %o3
a00ae090:  9a 10 20 03  mov  3, %o5
a00ae094:  c2 03 00 00  ld  [ %o4 ], %g1
a00ae098:  9b 2b 40 0b  sll  %o5, %o3, %o5
a00ae09c:  9a 28 40 0d  andn  %g1, %o5, %o5
a00ae0a0:  82 10 20 01  mov  1, %g1
a00ae0a4:  83 28 40 0b  sll  %g1, %o3, %g1
a00ae0a8:  9a 13 40 01  or  %o5, %g1, %o5
a00ae0ac:  da 23 00 00  st  %o5, [ %o4 ]
a00ae0b0:  30 80 00 09  b,a   0xa00ae0d4
a00ae0b4:  9a 00 40 01  add  %g1, %g1, %o5
a00ae0b8:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a00ae0bc:  82 10 20 03  mov  3, %g1
a00ae0c0:  83 28 40 0d  sll  %g1, %o5, %g1
a00ae0c4:  98 13 23 9c  or  %o4, 0x39c, %o4
a00ae0c8:  da 03 00 00  ld  [ %o4 ], %o5
a00ae0cc:  82 2b 40 01  andn  %o5, %g1, %g1
a00ae0d0:  c2 23 00 00  st  %g1, [ %o4 ]
a00ae0d4:  81 c7 e0 08  ret
a00ae0d8:  81 e8 00 00  restore
