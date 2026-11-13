# leon2m FUN_a00edc70 0xa00edc70-0xa00ee188 (708 bytes)
a00edc70:  9d e3 bf 90  save  %sp, -112, %sp
a00edc74:  a2 10 00 18  mov  %i0, %l1
a00edc78:  a0 10 00 1b  mov  %i3, %l0
a00edc7c:  80 a7 20 49  cmp  %i4, 0x49
a00edc80:  f0 07 a0 40  ld  [ %fp + 0x40 ], %i0
a00edc84:  18 80 00 0b  bgu  0xa00edcb0
a00edc88:  ec 07 a0 5c  ld  [ %fp + 0x5c ], %l6
a00edc8c:  92 07 00 1c  add  %i4, %i4, %o1
a00edc90:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00edc94:  82 02 40 1c  add  %o1, %i4, %g1
a00edc98:  9a 12 21 98  or  %o0, 0x198, %o5
a00edc9c:  f6 0b 40 01  ldub  [ %o5 + %g1 ], %i3
a00edca0:  98 0e e0 3f  and  %i3, 0x3f, %o4
a00edca4:  80 a3 20 32  cmp  %o4, 0x32
a00edca8:  08 80 00 08  bleu  0xa00edcc8
a00edcac:  a5 2c 20 0a  sll  %l0, 0xa, %l2
a00edcb0:  94 10 3f ff  mov  -1, %o2
a00edcb4:  d4 26 20 04  st  %o2, [ %i0 + 4 ]
a00edcb8:  d4 27 bf f4  st  %o2, [ %fp + -12 ]
a00edcbc:  d4 27 bf f0  st  %o2, [ %fp + -16 ]
a00edcc0:  10 80 01 30  b  0xa00ee180
a00edcc4:  d4 26 00 00  st  %o2, [ %i0 ]
a00edcc8:  92 10 20 06  mov  6, %o1
a00edccc:  94 10 20 06  mov  6, %o2
a00edcd0:  96 14 a0 80  or  %l2, 0x80, %o3
a00edcd4:  7f ff d8 e6  call  0xa00e406c
a00edcd8:  90 10 00 11  mov  %l1, %o0
a00edcdc:  7f ff c8 b2  call  0xa00dffa4
a00edce0:  90 10 20 01  mov  1, %o0
a00edce4:  a0 14 80 1b  or  %l2, %i3, %l0
a00edce8:  96 14 20 80  or  %l0, 0x80, %o3
a00edcec:  90 10 00 11  mov  %l1, %o0
a00edcf0:  92 10 20 06  mov  6, %o1
a00edcf4:  7f ff d8 de  call  0xa00e406c
a00edcf8:  94 10 20 06  mov  6, %o2
a00edcfc:  80 a7 7f ff  cmp  %i5, -1
a00edd00:  02 80 00 b1  be  0xa00edfc4
a00edd04:  b9 2f 60 02  sll  %i5, 2, %i4
a00edd08:  37 2a 00 9a  sethi  %hi(0xa8026800), %i3
a00edd0c:  2f 2a 00 9a  sethi  %hi(0xa8026800), %l7
a00edd10:  27 2a 00 9a  sethi  %hi(0xa8026800), %l3
a00edd14:  82 16 e0 e8  or  %i3, 0xe8, %g1
a00edd18:  a0 15 e0 d8  or  %l7, 0xd8, %l0
a00edd1c:  aa 14 e0 c8  or  %l3, 0xc8, %l5
a00edd20:  d2 00 40 1c  ld  [ %g1 + %i4 ], %o1
a00edd24:  d4 04 00 1c  ld  [ %l0 + %i4 ], %o2
a00edd28:  d6 05 40 1c  ld  [ %l5 + %i4 ], %o3
a00edd2c:  7f ff ca 8a  call  0xa00e0754
a00edd30:  90 10 00 11  mov  %l1, %o0
a00edd34:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00edd38:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00edd3c:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00edd40:  9e 13 60 a8  or  %o5, 0xa8, %o7
a00edd44:  a8 13 20 98  or  %o4, 0x98, %l4
a00edd48:  a4 12 60 b8  or  %o1, 0xb8, %l2
a00edd4c:  aa 10 00 08  mov  %o0, %l5
a00edd50:  d4 03 c0 1c  ld  [ %o7 + %i4 ], %o2
a00edd54:  d2 04 80 1c  ld  [ %l2 + %i4 ], %o1
a00edd58:  d6 05 00 1c  ld  [ %l4 + %i4 ], %o3
a00edd5c:  7f ff ca 7e  call  0xa00e0754
a00edd60:  90 10 00 11  mov  %l1, %o0
a00edd64:  a8 10 00 08  mov  %o0, %l4
a00edd68:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00edd6c:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00edd70:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00edd74:  b6 12 23 98  or  %o0, 0x398, %i3
a00edd78:  ae 12 e3 88  or  %o3, 0x388, %l7
a00edd7c:  a6 12 a3 78  or  %o2, 0x378, %l3
a00edd80:  d2 06 c0 1c  ld  [ %i3 + %i4 ], %o1
a00edd84:  d4 05 c0 1c  ld  [ %l7 + %i4 ], %o2
a00edd88:  d6 04 c0 1c  ld  [ %l3 + %i4 ], %o3
a00edd8c:  7f ff ca 72  call  0xa00e0754
a00edd90:  90 10 00 11  mov  %l1, %o0
a00edd94:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00edd98:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00edd9c:  13 2a 00 ad  sethi  %hi(0xa802b400), %o1
a00edda0:  9a 14 23 68  or  %l0, 0x368, %o5
a00edda4:  98 10 63 58  or  %g1, 0x358, %o4
a00edda8:  a4 12 62 e8  or  %o1, 0x2e8, %l2
a00eddac:  a6 10 00 08  mov  %o0, %l3
a00eddb0:  d2 03 40 1c  ld  [ %o5 + %i4 ], %o1
a00eddb4:  d4 03 00 1c  ld  [ %o4 + %i4 ], %o2
a00eddb8:  d6 04 80 1c  ld  [ %l2 + %i4 ], %o3
a00eddbc:  7f ff ca 66  call  0xa00e0754
a00eddc0:  90 10 00 11  mov  %l1, %o0
a00eddc4:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00eddc8:  a4 10 00 08  mov  %o0, %l2
a00eddcc:  94 13 e3 48  or  %o7, 0x348, %o2
a00eddd0:  11 2a 00 99  sethi  %hi(0xa8026400), %o0
a00eddd4:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00eddd8:  b6 12 23 38  or  %o0, 0x338, %i3
a00edddc:  d2 02 80 1c  ld  [ %o2 + %i4 ], %o1
a00edde0:  ae 12 e3 28  or  %o3, 0x328, %l7
a00edde4:  d4 06 c0 1c  ld  [ %i3 + %i4 ], %o2
a00edde8:  d6 05 c0 1c  ld  [ %l7 + %i4 ], %o3
a00eddec:  7f ff ca 5a  call  0xa00e0754
a00eddf0:  90 10 00 11  mov  %l1, %o0
a00eddf4:  2f 2a 00 ad  sethi  %hi(0xa802b400), %l7
a00eddf8:  92 15 e2 d8  or  %l7, 0x2d8, %o1	! 0xa802b6d8
a00eddfc:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ede00:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ede04:  b6 10 00 08  mov  %o0, %i3
a00ede08:  9a 14 23 18  or  %l0, 0x318, %o5
a00ede0c:  98 10 63 08  or  %g1, 0x308, %o4
a00ede10:  d6 02 40 1c  ld  [ %o1 + %i4 ], %o3
a00ede14:  d2 03 40 1c  ld  [ %o5 + %i4 ], %o1
a00ede18:  d4 03 00 1c  ld  [ %o4 + %i4 ], %o2
a00ede1c:  90 10 00 11  mov  %l1, %o0
a00ede20:  7f ff ca 4d  call  0xa00e0754
a00ede24:  01 00 00 00  nop
a00ede28:  94 07 bf f0  add  %fp, -16, %o2
a00ede2c:  d4 23 a0 40  st  %o2, [ %sp + 0x40 ]
a00ede30:  b8 10 00 08  mov  %o0, %i4
a00ede34:  92 10 00 19  mov  %i1, %o1
a00ede38:  94 10 00 1a  mov  %i2, %o2
a00ede3c:  d8 07 a0 64  ld  [ %fp + 0x64 ], %o4
a00ede40:  da 07 a0 60  ld  [ %fp + 0x60 ], %o5
a00ede44:  90 10 00 11  mov  %l1, %o0
a00ede48:  96 10 00 1d  mov  %i5, %o3
a00ede4c:  7f ff fa 1b  call  0xa00ec6b8
a00ede50:  01 00 00 00  nop
a00ede54:  00 00 00 08  unimp  0x8
a00ede58:  80 a7 7f ff  cmp  %i5, -1
a00ede5c:  02 80 00 95  be  0xa00ee0b0
a00ede60:  a1 2f 60 02  sll  %i5, 2, %l0
a00ede64:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00ede68:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ede6c:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00ede70:  9a 13 20 e8  or  %o4, 0xe8, %o5
a00ede74:  9e 12 e0 d8  or  %o3, 0xd8, %o7
a00ede78:  ba 12 60 c8  or  %o1, 0xc8, %i5
a00ede7c:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00ede80:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00ede84:  d6 07 40 10  ld  [ %i5 + %l0 ], %o3
a00ede88:  98 10 00 15  mov  %l5, %o4
a00ede8c:  7f ff ca 3a  call  0xa00e0774
a00ede90:  90 10 00 11  mov  %l1, %o0
a00ede94:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00ede98:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ede9c:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00edea0:  82 16 a0 b8  or  %i2, 0xb8, %g1
a00edea4:  aa 12 20 98  or  %o0, 0x98, %l5
a00edea8:  b2 12 a0 a8  or  %o2, 0xa8, %i1
a00edeac:  d2 00 40 10  ld  [ %g1 + %l0 ], %o1
a00edeb0:  d4 06 40 10  ld  [ %i1 + %l0 ], %o2
a00edeb4:  d6 05 40 10  ld  [ %l5 + %l0 ], %o3
a00edeb8:  98 10 00 14  mov  %l4, %o4
a00edebc:  7f ff ca 2e  call  0xa00e0774
a00edec0:  90 10 00 11  mov  %l1, %o0
a00edec4:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00edec8:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00edecc:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00eded0:  9a 13 23 98  or  %o4, 0x398, %o5
a00eded4:  9e 12 e3 88  or  %o3, 0x388, %o7
a00eded8:  a8 12 63 78  or  %o1, 0x378, %l4
a00ededc:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00edee0:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00edee4:  d6 05 00 10  ld  [ %l4 + %l0 ], %o3
a00edee8:  98 10 00 13  mov  %l3, %o4
a00edeec:  7f ff ca 22  call  0xa00e0774
a00edef0:  90 10 00 11  mov  %l1, %o0
a00edef4:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00edef8:  94 14 e3 68  or  %l3, 0x368, %o2	! 0xa8026768
a00edefc:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00edf00:  d2 02 80 10  ld  [ %o2 + %l0 ], %o1
a00edf04:  90 17 63 58  or  %i5, 0x358, %o0
a00edf08:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00edf0c:  d4 02 00 10  ld  [ %o0 + %l0 ], %o2
a00edf10:  b2 16 a2 e8  or  %i2, 0x2e8, %i1
a00edf14:  98 10 00 12  mov  %l2, %o4
a00edf18:  d6 06 40 10  ld  [ %i1 + %l0 ], %o3
a00edf1c:  7f ff ca 16  call  0xa00e0774
a00edf20:  90 10 00 11  mov  %l1, %o0
a00edf24:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00edf28:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00edf2c:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00edf30:  9a 10 63 48  or  %g1, 0x348, %o5
a00edf34:  9e 15 63 38  or  %l5, 0x338, %o7
a00edf38:  a8 13 23 28  or  %o4, 0x328, %l4
a00edf3c:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00edf40:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00edf44:  d6 05 00 10  ld  [ %l4 + %l0 ], %o3
a00edf48:  98 10 00 1b  mov  %i3, %o4
a00edf4c:  7f ff ca 0a  call  0xa00e0774
a00edf50:  90 10 00 11  mov  %l1, %o0
a00edf54:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00edf58:  a6 12 e3 18  or  %o3, 0x318, %l3	! 0xa8026718
a00edf5c:  92 15 e2 d8  or  %l7, 0x2d8, %o1
a00edf60:  37 2a 00 99  sethi  %hi(0xa8026400), %i3
a00edf64:  a4 16 e3 08  or  %i3, 0x308, %l2	! 0xa8026708
a00edf68:  d6 02 40 10  ld  [ %o1 + %l0 ], %o3
a00edf6c:  90 10 00 11  mov  %l1, %o0
a00edf70:  d2 04 c0 10  ld  [ %l3 + %l0 ], %o1
a00edf74:  d4 04 80 10  ld  [ %l2 + %l0 ], %o2
a00edf78:  7f ff c9 ff  call  0xa00e0774
a00edf7c:  98 10 00 1c  mov  %i4, %o4
a00edf80:  d6 07 bf f4  ld  [ %fp + -12 ], %o3
a00edf84:  80 a2 ff ff  cmp  %o3, -1
a00edf88:  02 80 00 44  be  0xa00ee098
a00edf8c:  d8 07 bf f0  ld  [ %fp + -16 ], %o4
a00edf90:  b7 3b 20 08  sra  %o4, 8, %i3
a00edf94:  a7 3a e0 08  sra  %o3, 8, %l3
a00edf98:  a0 5e c0 16  smul  %i3, %l6, %l0
a00edf9c:  ae 5c c0 16  smul  %l3, %l6, %l7
a00edfa0:  a4 0b 20 ff  and  %o4, 0xff, %l2
a00edfa4:  a2 0a e0 ff  and  %o3, 0xff, %l1
a00edfa8:  b8 04 00 12  add  %l0, %l2, %i4
a00edfac:  ac 05 c0 11  add  %l7, %l1, %l6
a00edfb0:  f8 26 00 00  st  %i4, [ %i0 ]
a00edfb4:  ec 26 20 04  st  %l6, [ %i0 + 4 ]
a00edfb8:  f8 27 bf f0  st  %i4, [ %fp + -16 ]
a00edfbc:  10 80 00 71  b  0xa00ee180
a00edfc0:  ec 27 bf f4  st  %l6, [ %fp + -12 ]
a00edfc4:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00edfc8:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00edfcc:  94 12 20 d8  or  %o0, 0xd8, %o2
a00edfd0:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00edfd4:  92 13 e0 e8  or  %o7, 0xe8, %o1
a00edfd8:  96 15 60 c8  or  %l5, 0xc8, %o3
a00edfdc:  7f ff c9 de  call  0xa00e0754
a00edfe0:  90 10 00 11  mov  %l1, %o0
a00edfe4:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00edfe8:  92 12 e0 b8  or  %o3, 0xb8, %o1	! 0xa80268b8
a00edfec:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00edff0:  29 2a 00 9a  sethi  %hi(0xa8026800), %l4
a00edff4:  aa 10 00 08  mov  %o0, %l5
a00edff8:  94 14 a0 a8  or  %l2, 0xa8, %o2
a00edffc:  96 15 20 98  or  %l4, 0x98, %o3
a00ee000:  7f ff c9 d5  call  0xa00e0754
a00ee004:  90 10 00 11  mov  %l1, %o0
a00ee008:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00ee00c:  92 12 a3 98  or  %o2, 0x398, %o1	! 0xa8026798
a00ee010:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00ee014:  a8 10 00 08  mov  %o0, %l4
a00ee018:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ee01c:  96 14 e3 78  or  %l3, 0x378, %o3
a00ee020:  94 14 23 88  or  %l0, 0x388, %o2
a00ee024:  7f ff c9 cc  call  0xa00e0754
a00ee028:  90 10 00 11  mov  %l1, %o0
a00ee02c:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ee030:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00ee034:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00ee038:  a6 10 00 08  mov  %o0, %l3
a00ee03c:  92 13 63 68  or  %o5, 0x368, %o1
a00ee040:  94 10 63 58  or  %g1, 0x358, %o2
a00ee044:  96 13 22 e8  or  %o4, 0x2e8, %o3
a00ee048:  7f ff c9 c3  call  0xa00e0754
a00ee04c:  90 10 00 11  mov  %l1, %o0
a00ee050:  37 2a 00 99  sethi  %hi(0xa8026400), %i3
a00ee054:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00ee058:  a4 10 00 08  mov  %o0, %l2
a00ee05c:  39 2a 00 99  sethi  %hi(0xa8026400), %i4
a00ee060:  94 16 e3 38  or  %i3, 0x338, %o2
a00ee064:  96 15 e3 28  or  %l7, 0x328, %o3
a00ee068:  92 17 23 48  or  %i4, 0x348, %o1
a00ee06c:  7f ff c9 ba  call  0xa00e0754
a00ee070:  90 10 00 11  mov  %l1, %o0
a00ee074:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ee078:  b6 10 00 08  mov  %o0, %i3
a00ee07c:  2f 2a 00 ad  sethi  %hi(0xa802b400), %l7
a00ee080:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ee084:  94 12 e3 08  or  %o3, 0x308, %o2
a00ee088:  90 10 00 11  mov  %l1, %o0
a00ee08c:  92 13 e3 18  or  %o7, 0x318, %o1
a00ee090:  10 bf ff 64  b  0xa00ede20
a00ee094:  96 15 e2 d8  or  %l7, 0x2d8, %o3
a00ee098:  80 a3 3f ff  cmp  %o4, -1
a00ee09c:  12 bf ff be  bne  0xa00edf94
a00ee0a0:  b7 3b 20 08  sra  %o4, 8, %i3
a00ee0a4:  d6 26 20 04  st  %o3, [ %i0 + 4 ]
a00ee0a8:  10 80 00 36  b  0xa00ee180
a00ee0ac:  d6 26 00 00  st  %o3, [ %i0 ]
a00ee0b0:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00ee0b4:  96 12 20 c8  or  %o0, 0xc8, %o3	! 0xa80268c8
a00ee0b8:  3b 2a 00 9a  sethi  %hi(0xa8026800), %i5
a00ee0bc:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00ee0c0:  92 17 60 e8  or  %i5, 0xe8, %o1
a00ee0c4:  94 16 a0 d8  or  %i2, 0xd8, %o2
a00ee0c8:  98 10 00 15  mov  %l5, %o4
a00ee0cc:  7f ff c9 aa  call  0xa00e0774
a00ee0d0:  90 10 00 11  mov  %l1, %o0
a00ee0d4:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ee0d8:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00ee0dc:  92 12 a0 b8  or  %o2, 0xb8, %o1
a00ee0e0:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00ee0e4:  96 10 60 98  or  %g1, 0x98, %o3
a00ee0e8:  90 10 00 11  mov  %l1, %o0
a00ee0ec:  94 16 60 a8  or  %i1, 0xa8, %o2
a00ee0f0:  7f ff c9 a1  call  0xa00e0774
a00ee0f4:  98 10 00 14  mov  %l4, %o4
a00ee0f8:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00ee0fc:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00ee100:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00ee104:  96 13 63 78  or  %o5, 0x378, %o3
a00ee108:  90 10 00 11  mov  %l1, %o0
a00ee10c:  92 14 23 98  or  %l0, 0x398, %o1
a00ee110:  94 15 63 88  or  %l5, 0x388, %o2
a00ee114:  7f ff c9 98  call  0xa00e0774
a00ee118:  98 10 00 13  mov  %l3, %o4
a00ee11c:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00ee120:  92 13 23 68  or  %o4, 0x368, %o1	! 0xa8026768
a00ee124:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00ee128:  29 2a 00 ad  sethi  %hi(0xa802b400), %l4
a00ee12c:  90 10 00 11  mov  %l1, %o0
a00ee130:  94 13 e3 58  or  %o7, 0x358, %o2
a00ee134:  96 15 22 e8  or  %l4, 0x2e8, %o3
a00ee138:  7f ff c9 8f  call  0xa00e0774
a00ee13c:  98 10 00 12  mov  %l2, %o4
a00ee140:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00ee144:  92 12 e3 48  or  %o3, 0x348, %o1	! 0xa8026748
a00ee148:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00ee14c:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00ee150:  90 10 00 11  mov  %l1, %o0
a00ee154:  94 17 63 38  or  %i5, 0x338, %o2
a00ee158:  96 16 a3 28  or  %i2, 0x328, %o3
a00ee15c:  7f ff c9 86  call  0xa00e0774
a00ee160:  98 10 00 1b  mov  %i3, %o4
a00ee164:  90 10 00 11  mov  %l1, %o0
a00ee168:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00ee16c:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00ee170:  92 16 63 18  or  %i1, 0x318, %o1
a00ee174:  94 14 63 08  or  %l1, 0x308, %o2
a00ee178:  10 bf ff 80  b  0xa00edf78
a00ee17c:  96 15 e2 d8  or  %l7, 0x2d8, %o3
a00ee180:  81 c7 e0 0c  jmp  %i7 + 0xc
a00ee184:  81 e8 00 00  restore
