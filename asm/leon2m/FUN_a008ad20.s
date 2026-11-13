# leon2m FUN_a008ad20 0xa008ad20-0xa008b2bc (800 bytes)
a008ad20:  9d e3 bf 88  save  %sp, -120, %sp
a008ad24:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a008ad28:  82 14 62 74  or  %l1, 0x274, %g1	! 0xa802d274
a008ad2c:  da 08 60 10  ldub  [ %g1 + 0x10 ], %o5
a008ad30:  80 a3 60 3f  cmp  %o5, 0x3f
a008ad34:  02 80 00 13  be  0xa008ad80
a008ad38:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a008ad3c:  90 14 23 f4  or  %l0, 0x3f4, %o0	! 0xa802cff4
a008ad40:  c2 0a 20 06  ldub  [ %o0 + 6 ], %g1
a008ad44:  80 a0 60 02  cmp  %g1, 2
a008ad48:  02 80 00 4f  be  0xa008ae84
a008ad4c:  80 a0 60 04  cmp  %g1, 4
a008ad50:  02 80 00 62  be  0xa008aed8
a008ad54:  80 a0 60 08  cmp  %g1, 8
a008ad58:  02 80 00 36  be  0xa008ae30
a008ad5c:  80 a0 60 10  cmp  %g1, 0x10
a008ad60:  02 80 00 73  be  0xa008af2c
a008ad64:  80 a0 60 20  cmp  %g1, 0x20
a008ad68:  02 80 00 86  be  0xa008af80
a008ad6c:  80 a0 60 01  cmp  %g1, 1
a008ad70:  12 80 01 4c  bne  0xa008b2a0
a008ad74:  92 14 62 74  or  %l1, 0x274, %o1
a008ad78:  10 80 01 15  b  0xa008b1cc
a008ad7c:  19 00 04 01  sethi  %hi(0x100400), %o4
a008ad80:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a008ad84:  c2 0c 23 fa  ldub  [ %l0 + 0x3fa ], %g1	! 0xa802cffa
a008ad88:  80 a0 60 20  cmp  %g1, 0x20
a008ad8c:  18 80 00 15  bgu  0xa008ade0
a008ad90:  90 10 20 c8  mov  0xc8, %o0
a008ad94:  1f 00 00 a8  sethi  %hi(0x2a000), %o7
a008ad98:  95 28 60 02  sll  %g1, 2, %o2
a008ad9c:  96 13 e2 d8  or  %o7, 0x2d8, %o3
a008ada0:  d2 02 c0 0a  ld  [ %o3 + %o2 ], %o1
a008ada4:  81 c2 40 00  jmp  %o1
a008ada8:  01 00 00 00  nop
a008adac:  9a 10 20 00  clr  %o5	! 0x0
a008adb0:  90 10 20 00  clr  %o0
a008adb4:  94 10 20 09  mov  9, %o2
a008adb8:  96 10 20 01  mov  1, %o3
a008adbc:  40 02 ef 4e  call  0xa0146af4
a008adc0:  92 10 20 04  mov  4, %o1
a008adc4:  90 14 23 f4  or  %l0, 0x3f4, %o0
a008adc8:  a0 14 62 74  or  %l1, 0x274, %l0
a008adcc:  c2 0c 20 10  ldub  [ %l0 + 0x10 ], %g1
a008add0:  d8 0a 20 06  ldub  [ %o0 + 6 ], %o4
a008add4:  9a 10 40 0c  or  %g1, %o4, %o5
a008add8:  da 2c 20 10  stb  %o5, [ %l0 + 0x10 ]
a008addc:  90 10 20 c8  mov  0xc8, %o0
a008ade0:  40 02 ef 5c  call  0xa0146b50
a008ade4:  92 10 20 00  clr  %o1
a008ade8:  21 00 04 00  sethi  %hi(0x100000), %l0
a008adec:  98 14 23 18  or  %l0, 0x318, %o4	! 0x100318
a008adf0:  90 10 20 00  clr  %o0
a008adf4:  92 10 20 01  mov  1, %o1
a008adf8:  94 10 20 09  mov  9, %o2
a008adfc:  96 10 20 03  mov  3, %o3
a008ae00:  40 00 60 e9  call  0xa00a31a4
a008ae04:  9a 10 20 00  clr  %o5
a008ae08:  19 00 04 00  sethi  %hi(0x100000), %o4
a008ae0c:  98 13 23 28  or  %o4, 0x328, %o4	! 0x100328
a008ae10:  90 10 20 00  clr  %o0
a008ae14:  92 10 20 06  mov  6, %o1
a008ae18:  94 10 20 09  mov  9, %o2
a008ae1c:  96 10 20 07  mov  7, %o3
a008ae20:  40 00 60 e1  call  0xa00a31a4
a008ae24:  9a 10 20 00  clr  %o5
a008ae28:  10 80 01 1e  b  0xa008b2a0
a008ae2c:  92 14 62 74  or  %l1, 0x274, %o1
a008ae30:  13 00 04 01  sethi  %hi(0x100400), %o1
a008ae34:  92 12 60 78  or  %o1, 0x78, %o1	! 0x100478
a008ae38:  90 07 bf f5  add  %fp, -11, %o0
a008ae3c:  40 03 32 6e  call  0xa01577f4
a008ae40:  94 10 20 03  mov  3, %o2
a008ae44:  98 10 20 00  clr  %o4
a008ae48:  9a 10 20 00  clr  %o5
a008ae4c:  10 80 00 08  b  0xa008ae6c
a008ae50:  96 07 bf f5  add  %fp, -11, %o3
a008ae54:  d4 2b 40 0b  stb  %o2, [ %o5 + %o3 ]
a008ae58:  98 03 20 01  inc  %o4
a008ae5c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008ae60:  80 a3 60 00  cmp  %o5, 0
a008ae64:  32 bf ff d2  bne,a   0xa008adac
a008ae68:  98 07 bf f5  add  %fp, -11, %o4
a008ae6c:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008ae70:  80 a0 60 20  cmp  %g1, 0x20
a008ae74:  12 bf ff f8  bne  0xa008ae54
a008ae78:  94 00 7f d1  add  %g1, -47, %o2
a008ae7c:  10 bf ff f7  b  0xa008ae58
a008ae80:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008ae84:  13 00 04 01  sethi  %hi(0x100400), %o1
a008ae88:  92 12 60 78  or  %o1, 0x78, %o1	! 0x100478
a008ae8c:  90 07 bf f7  add  %fp, -9, %o0
a008ae90:  40 03 32 59  call  0xa01577f4
a008ae94:  94 10 20 01  mov  1, %o2
a008ae98:  98 10 20 00  clr  %o4
a008ae9c:  9a 10 20 00  clr  %o5
a008aea0:  10 80 00 08  b  0xa008aec0
a008aea4:  96 07 bf f7  add  %fp, -9, %o3
a008aea8:  d4 2b 40 0b  stb  %o2, [ %o5 + %o3 ]
a008aeac:  98 03 20 01  inc  %o4
a008aeb0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008aeb4:  80 a3 60 00  cmp  %o5, 0
a008aeb8:  32 bf ff bd  bne,a   0xa008adac
a008aebc:  98 07 bf f7  add  %fp, -9, %o4
a008aec0:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008aec4:  80 a0 60 20  cmp  %g1, 0x20
a008aec8:  12 bf ff f8  bne  0xa008aea8
a008aecc:  94 00 7f d1  add  %g1, -47, %o2
a008aed0:  10 bf ff f7  b  0xa008aeac
a008aed4:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008aed8:  17 00 04 01  sethi  %hi(0x100400), %o3
a008aedc:  92 12 e0 78  or  %o3, 0x78, %o1	! 0x100478
a008aee0:  90 07 bf f6  add  %fp, -10, %o0
a008aee4:  40 03 32 44  call  0xa01577f4
a008aee8:  94 10 20 02  mov  2, %o2
a008aeec:  98 10 20 00  clr  %o4
a008aef0:  9a 10 20 00  clr  %o5
a008aef4:  10 80 00 08  b  0xa008af14
a008aef8:  96 07 bf f6  add  %fp, -10, %o3
a008aefc:  de 2b 40 0b  stb  %o7, [ %o5 + %o3 ]
a008af00:  98 03 20 01  inc  %o4
a008af04:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008af08:  80 a3 60 00  cmp  %o5, 0
a008af0c:  32 bf ff a8  bne,a   0xa008adac
a008af10:  98 07 bf f6  add  %fp, -10, %o4
a008af14:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008af18:  80 a0 60 20  cmp  %g1, 0x20
a008af1c:  12 bf ff f8  bne  0xa008aefc
a008af20:  9e 00 7f d1  add  %g1, -47, %o7
a008af24:  10 bf ff f7  b  0xa008af00
a008af28:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008af2c:  17 00 04 01  sethi  %hi(0x100400), %o3
a008af30:  92 12 e0 78  or  %o3, 0x78, %o1	! 0x100478
a008af34:  90 07 bf f4  add  %fp, -12, %o0
a008af38:  40 03 32 2f  call  0xa01577f4
a008af3c:  94 10 20 04  mov  4, %o2
a008af40:  98 10 20 00  clr  %o4
a008af44:  9a 10 20 00  clr  %o5
a008af48:  10 80 00 08  b  0xa008af68
a008af4c:  96 07 bf f4  add  %fp, -12, %o3
a008af50:  de 2b 40 0b  stb  %o7, [ %o5 + %o3 ]
a008af54:  98 03 20 01  inc  %o4
a008af58:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008af5c:  80 a3 60 00  cmp  %o5, 0
a008af60:  32 bf ff 93  bne,a   0xa008adac
a008af64:  98 07 bf f4  add  %fp, -12, %o4
a008af68:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008af6c:  80 a0 60 20  cmp  %g1, 0x20
a008af70:  12 bf ff f8  bne  0xa008af50
a008af74:  9e 00 7f d1  add  %g1, -47, %o7
a008af78:  10 bf ff f7  b  0xa008af54
a008af7c:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008af80:  1b 00 04 01  sethi  %hi(0x100400), %o5
a008af84:  92 13 60 78  or  %o5, 0x78, %o1	! 0x100478
a008af88:  90 07 bf f3  add  %fp, -13, %o0
a008af8c:  40 03 32 1a  call  0xa01577f4
a008af90:  94 10 20 05  mov  5, %o2
a008af94:  98 10 20 00  clr  %o4
a008af98:  9a 10 20 00  clr  %o5
a008af9c:  10 80 00 08  b  0xa008afbc
a008afa0:  96 07 bf f3  add  %fp, -13, %o3
a008afa4:  c2 2b 40 0b  stb  %g1, [ %o5 + %o3 ]
a008afa8:  98 03 20 01  inc  %o4
a008afac:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008afb0:  80 a3 60 00  cmp  %o5, 0
a008afb4:  32 bf ff 7e  bne,a   0xa008adac
a008afb8:  98 07 bf f3  add  %fp, -13, %o4
a008afbc:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008afc0:  80 a0 60 20  cmp  %g1, 0x20
a008afc4:  12 bf ff f8  bne  0xa008afa4
a008afc8:  82 00 7f d1  add  %g1, -47, %g1
a008afcc:  10 bf ff f7  b  0xa008afa8
a008afd0:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008afd4:  17 00 04 01  sethi  %hi(0x100400), %o3
a008afd8:  92 12 e0 78  or  %o3, 0x78, %o1	! 0x100478
a008afdc:  90 07 bf ed  add  %fp, -19, %o0
a008afe0:  40 03 32 05  call  0xa01577f4
a008afe4:  94 10 20 05  mov  5, %o2
a008afe8:  98 10 20 00  clr  %o4
a008afec:  9a 10 20 00  clr  %o5
a008aff0:  10 80 00 08  b  0xa008b010
a008aff4:  96 07 bf ed  add  %fp, -19, %o3
a008aff8:  c2 2b 40 0b  stb  %g1, [ %o5 + %o3 ]
a008affc:  98 03 20 01  inc  %o4
a008b000:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008b004:  80 a3 60 00  cmp  %o5, 0
a008b008:  12 80 00 8d  bne  0xa008b23c
a008b00c:  90 10 20 00  clr  %o0
a008b010:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008b014:  80 a0 60 20  cmp  %g1, 0x20
a008b018:  12 bf ff f8  bne  0xa008aff8
a008b01c:  82 00 7f d1  add  %g1, -47, %g1
a008b020:  10 bf ff f7  b  0xa008affc
a008b024:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008b028:  15 00 04 01  sethi  %hi(0x100400), %o2
a008b02c:  92 12 a0 78  or  %o2, 0x78, %o1	! 0x100478
a008b030:  90 07 bf ee  add  %fp, -18, %o0
a008b034:  40 03 31 f0  call  0xa01577f4
a008b038:  94 10 20 04  mov  4, %o2
a008b03c:  98 10 20 00  clr  %o4
a008b040:  9a 10 20 00  clr  %o5
a008b044:  10 80 00 08  b  0xa008b064
a008b048:  96 07 bf ee  add  %fp, -18, %o3
a008b04c:  de 2b 40 0b  stb  %o7, [ %o5 + %o3 ]
a008b050:  98 03 20 01  inc  %o4
a008b054:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008b058:  80 a3 60 00  cmp  %o5, 0
a008b05c:  12 80 00 70  bne  0xa008b21c
a008b060:  90 10 20 00  clr  %o0
a008b064:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008b068:  80 a0 60 20  cmp  %g1, 0x20
a008b06c:  12 bf ff f8  bne  0xa008b04c
a008b070:  9e 00 7f d1  add  %g1, -47, %o7
a008b074:  10 bf ff f7  b  0xa008b050
a008b078:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008b07c:  21 00 04 01  sethi  %hi(0x100400), %l0
a008b080:  92 14 20 78  or  %l0, 0x78, %o1	! 0x100478
a008b084:  90 07 bf ef  add  %fp, -17, %o0
a008b088:  40 03 31 db  call  0xa01577f4
a008b08c:  94 10 20 03  mov  3, %o2
a008b090:  98 10 20 00  clr  %o4
a008b094:  9a 10 20 00  clr  %o5
a008b098:  10 80 00 08  b  0xa008b0b8
a008b09c:  96 07 bf ef  add  %fp, -17, %o3
a008b0a0:  d2 2b 40 0b  stb  %o1, [ %o5 + %o3 ]
a008b0a4:  98 03 20 01  inc  %o4
a008b0a8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008b0ac:  80 a3 60 00  cmp  %o5, 0
a008b0b0:  12 80 00 77  bne  0xa008b28c
a008b0b4:  90 10 20 00  clr  %o0
a008b0b8:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008b0bc:  80 a0 60 20  cmp  %g1, 0x20
a008b0c0:  12 bf ff f8  bne  0xa008b0a0
a008b0c4:  92 00 7f d1  add  %g1, -47, %o1
a008b0c8:  10 bf ff f7  b  0xa008b0a4
a008b0cc:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008b0d0:  19 00 04 01  sethi  %hi(0x100400), %o4
a008b0d4:  92 13 20 78  or  %o4, 0x78, %o1	! 0x100478
a008b0d8:  90 07 bf f0  add  %fp, -16, %o0
a008b0dc:  40 03 31 c6  call  0xa01577f4
a008b0e0:  94 10 20 02  mov  2, %o2
a008b0e4:  98 10 20 00  clr  %o4
a008b0e8:  9a 10 20 00  clr  %o5
a008b0ec:  10 80 00 08  b  0xa008b10c
a008b0f0:  96 07 bf f0  add  %fp, -16, %o3
a008b0f4:  d0 2b 40 0b  stb  %o0, [ %o5 + %o3 ]
a008b0f8:  98 03 20 01  inc  %o4
a008b0fc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008b100:  80 a3 60 00  cmp  %o5, 0
a008b104:  12 80 00 5d  bne  0xa008b278
a008b108:  90 10 20 00  clr  %o0
a008b10c:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008b110:  80 a0 60 20  cmp  %g1, 0x20
a008b114:  12 bf ff f8  bne  0xa008b0f4
a008b118:  90 00 7f d1  add  %g1, -47, %o0
a008b11c:  10 bf ff f7  b  0xa008b0f8
a008b120:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008b124:  1b 00 04 01  sethi  %hi(0x100400), %o5
a008b128:  92 13 60 78  or  %o5, 0x78, %o1	! 0x100478
a008b12c:  90 07 bf f1  add  %fp, -15, %o0
a008b130:  40 03 31 b1  call  0xa01577f4
a008b134:  94 10 20 01  mov  1, %o2
a008b138:  98 10 20 00  clr  %o4
a008b13c:  9a 10 20 00  clr  %o5
a008b140:  10 80 00 08  b  0xa008b160
a008b144:  96 07 bf f1  add  %fp, -15, %o3
a008b148:  c2 2b 40 0b  stb  %g1, [ %o5 + %o3 ]
a008b14c:  98 03 20 01  inc  %o4
a008b150:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008b154:  80 a3 60 00  cmp  %o5, 0
a008b158:  12 80 00 43  bne  0xa008b264
a008b15c:  90 10 20 00  clr  %o0
a008b160:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008b164:  80 a0 60 20  cmp  %g1, 0x20
a008b168:  12 bf ff f8  bne  0xa008b148
a008b16c:  82 00 7f d1  add  %g1, -47, %g1
a008b170:  10 bf ff f7  b  0xa008b14c
a008b174:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008b178:  1b 00 04 01  sethi  %hi(0x100400), %o5
a008b17c:  92 13 60 78  or  %o5, 0x78, %o1	! 0x100478
a008b180:  90 07 bf ec  add  %fp, -20, %o0
a008b184:  40 03 31 9c  call  0xa01577f4
a008b188:  94 10 20 06  mov  6, %o2
a008b18c:  98 10 20 00  clr  %o4
a008b190:  9a 10 20 00  clr  %o5
a008b194:  10 80 00 08  b  0xa008b1b4
a008b198:  96 07 bf ec  add  %fp, -20, %o3
a008b19c:  d0 2b 40 0b  stb  %o0, [ %o5 + %o3 ]
a008b1a0:  98 03 20 01  inc  %o4
a008b1a4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008b1a8:  80 a3 60 00  cmp  %o5, 0
a008b1ac:  12 80 00 29  bne  0xa008b250
a008b1b0:  90 10 20 00  clr  %o0
a008b1b4:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008b1b8:  80 a0 60 20  cmp  %g1, 0x20
a008b1bc:  12 bf ff f8  bne  0xa008b19c
a008b1c0:  90 00 7f d1  add  %g1, -47, %o0
a008b1c4:  10 bf ff f7  b  0xa008b1a0
a008b1c8:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008b1cc:  92 13 20 78  or  %o4, 0x78, %o1
a008b1d0:  90 07 bf f2  add  %fp, -14, %o0
a008b1d4:  40 03 31 88  call  0xa01577f4
a008b1d8:  94 10 20 06  mov  6, %o2
a008b1dc:  98 10 20 00  clr  %o4
a008b1e0:  9a 10 20 00  clr  %o5
a008b1e4:  10 80 00 08  b  0xa008b204
a008b1e8:  96 07 bf f2  add  %fp, -14, %o3
a008b1ec:  d0 2b 40 0b  stb  %o0, [ %o5 + %o3 ]
a008b1f0:  98 03 20 01  inc  %o4
a008b1f4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a008b1f8:  80 a3 60 00  cmp  %o5, 0
a008b1fc:  32 bf fe ec  bne,a   0xa008adac
a008b200:  98 07 bf f2  add  %fp, -14, %o4
a008b204:  c2 0b 40 0b  ldub  [ %o5 + %o3 ], %g1
a008b208:  80 a0 60 20  cmp  %g1, 0x20
a008b20c:  12 bf ff f8  bne  0xa008b1ec
a008b210:  90 00 7f d1  add  %g1, -47, %o0
a008b214:  10 bf ff f7  b  0xa008b1f0
a008b218:  c0 2b 40 0b  clrb  [ %o5 + %o3 ]
a008b21c:  92 10 20 04  mov  4, %o1
a008b220:  94 10 20 09  mov  9, %o2
a008b224:  96 10 20 01  mov  1, %o3
a008b228:  98 07 bf ee  add  %fp, -18, %o4
a008b22c:  40 02 ee 32  call  0xa0146af4
a008b230:  9a 10 20 00  clr  %o5
a008b234:  10 bf fe eb  b  0xa008ade0
a008b238:  90 10 20 c8  mov  0xc8, %o0
a008b23c:  92 10 20 04  mov  4, %o1
a008b240:  94 10 20 09  mov  9, %o2
a008b244:  96 10 20 01  mov  1, %o3
a008b248:  10 bf ff f9  b  0xa008b22c
a008b24c:  98 07 bf ed  add  %fp, -19, %o4
a008b250:  92 10 20 04  mov  4, %o1
a008b254:  94 10 20 09  mov  9, %o2
a008b258:  96 10 20 01  mov  1, %o3
a008b25c:  10 bf ff f4  b  0xa008b22c
a008b260:  98 07 bf ec  add  %fp, -20, %o4
a008b264:  92 10 20 04  mov  4, %o1
a008b268:  94 10 20 09  mov  9, %o2
a008b26c:  96 10 20 01  mov  1, %o3
a008b270:  10 bf ff ef  b  0xa008b22c
a008b274:  98 07 bf f1  add  %fp, -15, %o4
a008b278:  92 10 20 04  mov  4, %o1
a008b27c:  94 10 20 09  mov  9, %o2
a008b280:  96 10 20 01  mov  1, %o3
a008b284:  10 bf ff ea  b  0xa008b22c
a008b288:  98 07 bf f0  add  %fp, -16, %o4
a008b28c:  92 10 20 04  mov  4, %o1
a008b290:  94 10 20 09  mov  9, %o2
a008b294:  96 10 20 01  mov  1, %o3
a008b298:  10 bf ff e5  b  0xa008b22c
a008b29c:  98 07 bf ef  add  %fp, -17, %o4
a008b2a0:  90 10 20 30  mov  0x30, %o0
a008b2a4:  94 10 22 e0  mov  0x2e0, %o2
a008b2a8:  40 02 ff 0a  call  0xa014aed0
a008b2ac:  96 10 20 1c  mov  0x1c, %o3
a008b2b0:  01 00 00 00  nop
a008b2b4:  81 c7 e0 08  ret
a008b2b8:  81 e8 00 00  restore
