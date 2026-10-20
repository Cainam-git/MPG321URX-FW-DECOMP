# leon2s DRV_HDMI21_RXDetect_FSM_LTS_P 0xa009ae98-0xa009b5f4 (1884 bytes)
a009ae98:  9d e3 bf 98  save  %sp, -104, %sp
a009ae9c:  a6 0e 20 ff  and  %i0, 0xff, %l3
a009aea0:  80 a4 e0 00  cmp  %l3, 0
a009aea4:  b2 10 20 02  mov  2, %i1
a009aea8:  02 80 00 05  be  0xa009aebc
a009aeac:  b8 10 20 00  clr  %i4
a009aeb0:  80 a4 e0 01  cmp  %l3, 1
a009aeb4:  12 80 01 ce  bne  0xa009b5ec
a009aeb8:  b2 10 20 03  mov  3, %i1
a009aebc:  35 2a 01 f5  sethi  %hi(0xa807d400), %i2
a009aec0:  3b 2a 01 f5  sethi  %hi(0xa807d400), %i5
a009aec4:  ae 16 a2 80  or  %i2, 0x280, %l7
a009aec8:  aa 5c e0 b0  smul  %l3, 0xb0, %l5
a009aecc:  ac 17 62 48  or  %i5, 0x248, %l6
a009aed0:  a9 2c e0 02  sll  %l3, 2, %l4
a009aed4:  a4 05 40 17  add  %l5, %l7, %l2
a009aed8:  da 05 80 14  ld  [ %l6 + %l4 ], %o5
a009aedc:  c2 04 a0 30  ld  [ %l2 + 0x30 ], %g1
a009aee0:  80 a3 40 01  cmp  %o5, %g1
a009aee4:  02 80 00 45  be  0xa009aff8
a009aee8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009aeec:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009aef0:  80 88 68 00  btst  0x800, %g1
a009aef4:  02 80 00 08  be  0xa009af14
a009aef8:  37 2a 01 f6  sethi  %hi(0xa807d800), %i3
a009aefc:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a009af00:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a009af04:  90 12 20 68  or  %o0, 0x68, %o0
a009af08:  7f ff 60 4f  call  0xa0073044
a009af0c:  92 12 63 b0  or  %o1, 0x3b0, %o1
a009af10:  37 2a 01 f6  sethi  %hi(0xa807d800), %i3
a009af14:  a2 16 e3 00  or  %i3, 0x300, %l1	! 0xa807db00
a009af18:  a0 5c e0 34  smul  %l3, 0x34, %l0
a009af1c:  c2 05 80 14  ld  [ %l6 + %l4 ], %g1
a009af20:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009af24:  c2 24 a0 30  st  %g1, [ %l2 + 0x30 ]
a009af28:  92 02 60 08  add  %o1, 8, %o1
a009af2c:  90 10 20 0b  mov  0xb, %o0
a009af30:  c0 2c a0 39  clrb  [ %l2 + 0x39 ]
a009af34:  40 00 31 1e  call  0xa00a73ac
a009af38:  c0 2c a0 38  clrb  [ %l2 + 0x38 ]
a009af3c:  a0 04 00 11  add  %l0, %l1, %l0
a009af40:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a009af44:  40 00 31 1a  call  0xa00a73ac
a009af48:  90 10 20 0d  mov  0xd, %o0
a009af4c:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a009af50:  82 10 20 01  mov  1, %g1
a009af54:  c2 22 60 60  st  %g1, [ %o1 + 0x60 ]
a009af58:  c2 0d c0 15  ldub  [ %l7 + %l5 ], %g1
a009af5c:  80 a0 60 03  cmp  %g1, 3
a009af60:  12 80 00 0a  bne  0xa009af88
a009af64:  a0 0e 60 ff  and  %i1, 0xff, %l0
a009af68:  40 00 31 1b  call  0xa00a73d4
a009af6c:  90 10 20 08  mov  8, %o0
a009af70:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009af74:  90 10 00 10  mov  %l0, %o0
a009af78:  92 12 62 70  or  %o1, 0x270, %o1
a009af7c:  94 10 3f ff  mov  -1, %o2
a009af80:  10 80 00 0a  b  0xa009afa8
a009af84:  17 00 00 30  sethi  %hi(0xc000), %o3
a009af88:  40 00 31 09  call  0xa00a73ac
a009af8c:  90 10 20 08  mov  8, %o0
a009af90:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009af94:  15 3f ff cf  sethi  %hi(0xffff3c00), %o2
a009af98:  90 10 00 10  mov  %l0, %o0
a009af9c:  92 12 62 70  or  %o1, 0x270, %o1
a009afa0:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a009afa4:  96 10 20 00  clr  %o3
a009afa8:  40 00 31 38  call  0xa00a7488
a009afac:  a2 16 e3 00  or  %i3, 0x300, %l1
a009afb0:  a0 5c e0 34  smul  %l3, 0x34, %l0
a009afb4:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009afb8:  92 02 60 04  add  %o1, 4, %o1
a009afbc:  40 00 30 fc  call  0xa00a73ac
a009afc0:  90 10 20 08  mov  8, %o0
a009afc4:  40 00 59 f4  call  0xa00b1794
a009afc8:  90 10 20 01  mov  1, %o0
a009afcc:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009afd0:  92 02 60 04  add  %o1, 4, %o1
a009afd4:  40 00 31 00  call  0xa00a73d4
a009afd8:  90 10 20 08  mov  8, %o0
a009afdc:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009afe0:  82 10 60 82  or  %g1, 0x82, %g1	! 0xa8079082
a009afe4:  9a 04 c0 13  add  %l3, %l3, %o5
a009afe8:  c0 30 40 0d  clrh  [ %g1 + %o5 ]
a009afec:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009aff0:  82 10 60 80  or  %g1, 0x80, %g1	! 0xa8079080
a009aff4:  c0 28 40 13  clrb  [ %g1 + %l3 ]
a009aff8:  7f ff ca 02  call  0xa008d800
a009affc:  01 00 00 00  nop
a009b000:  90 0a 20 ff  and  %o0, 0xff, %o0
a009b004:  80 a2 20 82  cmp  %o0, 0x82
a009b008:  08 80 00 22  bleu  0xa009b090
a009b00c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a009b010:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009b014:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009b018:  9a 5c 60 34  smul  %l1, 0x34, %o5
a009b01c:  a0 03 40 01  add  %o5, %g1, %l0
a009b020:  c2 04 20 18  ld  [ %l0 + 0x18 ], %g1
a009b024:  c2 00 60 b0  ld  [ %g1 + 0xb0 ], %g1
a009b028:  83 30 60 08  srl  %g1, 8, %g1
a009b02c:  82 08 60 ff  and  %g1, 0xff, %g1
a009b030:  80 a0 60 ff  cmp  %g1, 0xff
a009b034:  02 80 00 17  be  0xa009b090
a009b038:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009b03c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009b040:  80 88 68 00  btst  0x800, %g1
a009b044:  22 80 00 06  be,a   0xa009b05c
a009b048:  d4 04 20 18  ld  [ %l0 + 0x18 ], %o2
a009b04c:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009b050:  7f ff 61 1d  call  0xa00734c4
a009b054:  90 12 23 68  or  %o0, 0x368, %o0	! 0xa006a368
a009b058:  d4 04 20 18  ld  [ %l0 + 0x18 ], %o2
a009b05c:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a009b060:  da 02 a0 b0  ld  [ %o2 + 0xb0 ], %o5
a009b064:  82 10 60 ff  or  %g1, 0xff, %g1
a009b068:  9a 0b 40 01  and  %o5, %g1, %o5
a009b06c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a009b070:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a009b074:  9a 13 40 01  or  %o5, %g1, %o5
a009b078:  96 17 62 48  or  %i5, 0x248, %o3
a009b07c:  99 2c 60 02  sll  %l1, 2, %o4
a009b080:  82 10 20 03  mov  3, %g1
a009b084:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a009b088:  da 22 a0 b0  st  %o5, [ %o2 + 0xb0 ]
a009b08c:  30 80 01 58  b,a   0xa009b5ec
a009b090:  27 2a 01 f6  sethi  %hi(0xa807d800), %l3
a009b094:  9a 14 e3 00  or  %l3, 0x300, %o5	! 0xa807db00
a009b098:  82 5c 60 34  smul  %l1, 0x34, %g1
a009b09c:  a0 00 40 0d  add  %g1, %o5, %l0
a009b0a0:  d2 04 20 18  ld  [ %l0 + 0x18 ], %o1
a009b0a4:  da 02 60 90  ld  [ %o1 + 0x90 ], %o5
a009b0a8:  98 16 a2 80  or  %i2, 0x280, %o4
a009b0ac:  82 5c 60 b0  smul  %l1, 0xb0, %g1
a009b0b0:  82 00 40 0c  add  %g1, %o4, %g1
a009b0b4:  9b 33 60 18  srl  %o5, 0x18, %o5
a009b0b8:  9a 0b 60 0f  and  %o5, 0xf, %o5
a009b0bc:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a009b0c0:  80 a3 40 01  cmp  %o5, %g1
a009b0c4:  02 80 00 1b  be  0xa009b130
a009b0c8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009b0cc:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009b0d0:  80 88 68 00  btst  0x800, %g1
a009b0d4:  02 80 00 06  be  0xa009b0ec
a009b0d8:  98 17 62 48  or  %i5, 0x248, %o4
a009b0dc:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009b0e0:  7f ff 60 f9  call  0xa00734c4
a009b0e4:  90 12 23 a0  or  %o0, 0x3a0, %o0	! 0xa006a3a0
a009b0e8:  98 17 62 48  or  %i5, 0x248, %o4
a009b0ec:  9b 2c 60 02  sll  %l1, 2, %o5
a009b0f0:  82 10 20 03  mov  3, %g1
a009b0f4:  7f ff c9 c3  call  0xa008d800
a009b0f8:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a009b0fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a009b100:  80 a2 20 82  cmp  %o0, 0x82
a009b104:  08 80 01 3a  bleu  0xa009b5ec
a009b108:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a009b10c:  d8 04 20 18  ld  [ %l0 + 0x18 ], %o4
a009b110:  da 03 20 b0  ld  [ %o4 + 0xb0 ], %o5
a009b114:  82 10 60 ff  or  %g1, 0xff, %g1
a009b118:  9a 0b 40 01  and  %o5, %g1, %o5
a009b11c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a009b120:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a009b124:  9a 13 40 01  or  %o5, %g1, %o5
a009b128:  da 23 20 b0  st  %o5, [ %o4 + 0xb0 ]
a009b12c:  30 80 01 30  b,a   0xa009b5ec
a009b130:  92 02 60 80  add  %o1, 0x80, %o1
a009b134:  40 00 30 b5  call  0xa00a7408
a009b138:  90 10 20 05  mov  5, %o0
a009b13c:  80 a2 20 00  cmp  %o0, 0
a009b140:  12 80 00 0c  bne  0xa009b170
a009b144:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a009b148:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a009b14c:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1	! 0xa8078634
a009b150:  80 88 68 00  btst  0x800, %g1
a009b154:  22 80 00 38  be,a   0xa009b234
a009b158:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009b15c:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009b160:  7f ff 60 d9  call  0xa00734c4
a009b164:  90 12 23 c8  or  %o0, 0x3c8, %o0	! 0xa006a3c8
a009b168:  10 80 00 33  b  0xa009b234
a009b16c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009b170:  82 14 20 82  or  %l0, 0x82, %g1
a009b174:  9a 04 40 11  add  %l1, %l1, %o5
a009b178:  c2 10 40 0d  lduh  [ %g1 + %o5 ], %g1
a009b17c:  80 a0 60 00  cmp  %g1, 0
a009b180:  12 80 00 0b  bne  0xa009b1ac
a009b184:  a4 14 20 82  or  %l0, 0x82, %l2
a009b188:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009b18c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009b190:  80 88 68 00  btst  0x800, %g1
a009b194:  22 80 00 07  be,a   0xa009b1b0
a009b198:  a0 04 40 11  add  %l1, %l1, %l0
a009b19c:  11 28 01 a8  sethi  %hi(0xa006a000), %o0
a009b1a0:  7f ff 60 c9  call  0xa00734c4
a009b1a4:  90 12 23 f0  or  %o0, 0x3f0, %o0	! 0xa006a3f0
a009b1a8:  a4 14 20 82  or  %l0, 0x82, %l2
a009b1ac:  a0 04 40 11  add  %l1, %l1, %l0
a009b1b0:  da 14 80 10  lduh  [ %l2 + %l0 ], %o5
a009b1b4:  9a 03 60 01  inc  %o5
a009b1b8:  83 2b 60 10  sll  %o5, 0x10, %g1
a009b1bc:  83 30 60 10  srl  %g1, 0x10, %g1
a009b1c0:  80 a0 61 2b  cmp  %g1, 0x12b
a009b1c4:  08 80 01 0a  bleu  0xa009b5ec
a009b1c8:  da 34 80 10  sth  %o5, [ %l2 + %l0 ]
a009b1cc:  82 14 e3 00  or  %l3, 0x300, %g1
a009b1d0:  9a 5c 60 34  smul  %l1, 0x34, %o5
a009b1d4:  9a 03 40 01  add  %o5, %g1, %o5
a009b1d8:  d2 03 60 18  ld  [ %o5 + 0x18 ], %o1
a009b1dc:  c0 34 80 10  clrh  [ %l2 + %l0 ]
a009b1e0:  92 02 60 90  add  %o1, 0x90, %o1
a009b1e4:  40 00 30 89  call  0xa00a7408
a009b1e8:  90 10 20 11  mov  0x11, %o0
a009b1ec:  80 a2 20 00  cmp  %o0, 0
a009b1f0:  02 80 00 08  be  0xa009b210
a009b1f4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009b1f8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009b1fc:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b200:  80 88 68 00  btst  0x800, %g1
a009b204:  12 80 00 f8  bne  0xa009b5e4
a009b208:  90 12 20 08  or  %o0, 8, %o0
a009b20c:  30 80 00 f8  b,a   0xa009b5ec
a009b210:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a009b214:  80 88 68 00  btst  0x800, %g1
a009b218:  02 80 00 f5  be  0xa009b5ec
a009b21c:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b220:  d4 14 80 10  lduh  [ %l2 + %l0 ], %o2
a009b224:  92 10 00 11  mov  %l1, %o1
a009b228:  7f ff 5f 87  call  0xa0073044
a009b22c:  90 12 20 20  or  %o0, 0x20, %o0
a009b230:  30 80 00 ef  b,a   0xa009b5ec
a009b234:  c2 08 60 52  ldub  [ %g1 + 0x52 ], %g1
a009b238:  80 a0 60 00  cmp  %g1, 0
a009b23c:  12 80 00 d9  bne  0xa009b5a0
a009b240:  9a 16 a2 80  or  %i2, 0x280, %o5
a009b244:  82 5c 60 b0  smul  %l1, 0xb0, %g1
a009b248:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a009b24c:  80 a0 60 03  cmp  %g1, 3
a009b250:  12 80 00 17  bne  0xa009b2ac
a009b254:  80 a0 60 04  cmp  %g1, 4
a009b258:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009b25c:  92 12 62 60  or  %o1, 0x260, %o1	! 0x2e60
a009b260:  40 00 30 2d  call  0xa00a7314
a009b264:  90 0e 60 03  and  %i1, 3, %o0
a009b268:  91 32 20 18  srl  %o0, 0x18, %o0
a009b26c:  90 0a 20 0f  and  %o0, 0xf, %o0
a009b270:  80 a2 20 07  cmp  %o0, 7
a009b274:  12 80 00 08  bne  0xa009b294
a009b278:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a009b27c:  80 88 68 00  btst  0x800, %g1
a009b280:  02 80 00 23  be  0xa009b30c
a009b284:  b8 10 20 01  mov  1, %i4
a009b288:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b28c:  10 80 00 1e  b  0xa009b304
a009b290:  90 12 20 40  or  %o0, 0x40, %o0	! 0xa006a440
a009b294:  80 88 68 00  btst  0x800, %g1
a009b298:  02 80 00 1d  be  0xa009b30c
a009b29c:  b8 10 20 00  clr  %i4
a009b2a0:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b2a4:  10 80 00 18  b  0xa009b304
a009b2a8:  90 12 20 60  or  %o0, 0x60, %o0	! 0xa006a460
a009b2ac:  12 80 00 19  bne  0xa009b310
a009b2b0:  80 8f 20 ff  btst  0xff, %i4
a009b2b4:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a009b2b8:  92 12 62 60  or  %o1, 0x260, %o1	! 0x2e60
a009b2bc:  40 00 30 16  call  0xa00a7314
a009b2c0:  90 0e 60 03  and  %i1, 3, %o0
a009b2c4:  91 32 20 18  srl  %o0, 0x18, %o0
a009b2c8:  90 0a 20 0f  and  %o0, 0xf, %o0
a009b2cc:  80 a2 20 0f  cmp  %o0, 0xf
a009b2d0:  12 80 00 08  bne  0xa009b2f0
a009b2d4:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a009b2d8:  80 88 68 00  btst  0x800, %g1
a009b2dc:  02 80 00 0c  be  0xa009b30c
a009b2e0:  b8 10 20 01  mov  1, %i4
a009b2e4:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b2e8:  10 80 00 07  b  0xa009b304
a009b2ec:  90 12 20 80  or  %o0, 0x80, %o0	! 0xa006a480
a009b2f0:  80 88 68 00  btst  0x800, %g1
a009b2f4:  02 80 00 06  be  0xa009b30c
a009b2f8:  b8 10 20 00  clr  %i4
a009b2fc:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b300:  90 12 20 a0  or  %o0, 0xa0, %o0	! 0xa006a4a0
a009b304:  7f ff 60 70  call  0xa00734c4
a009b308:  01 00 00 00  nop
a009b30c:  80 8f 20 ff  btst  0xff, %i4
a009b310:  02 80 00 8b  be  0xa009b53c
a009b314:  82 5c 60 b0  smul  %l1, 0xb0, %g1
a009b318:  2b 2a 01 e1  sethi  %hi(0xa8078400), %l5
a009b31c:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1	! 0xa8078634
a009b320:  80 88 68 00  btst  0x800, %g1
a009b324:  02 80 00 1c  be  0xa009b394
a009b328:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009b32c:  9a 14 e3 00  or  %l3, 0x300, %o5
a009b330:  82 5c 60 34  smul  %l1, 0x34, %g1
a009b334:  82 00 40 0d  add  %g1, %o5, %g1
a009b338:  da 00 60 18  ld  [ %g1 + 0x18 ], %o5
a009b33c:  d0 03 60 38  ld  [ %o5 + 0x38 ], %o0
a009b340:  d6 00 60 20  ld  [ %g1 + 0x20 ], %o3
a009b344:  d4 02 c0 00  ld  [ %o3 ], %o2
a009b348:  19 00 00 1f  sethi  %hi(0x7c00), %o4
a009b34c:  98 13 23 ff  or  %o4, 0x3ff, %o4	! 0x7fff
a009b350:  c2 02 e0 04  ld  [ %o3 + 4 ], %g1
a009b354:  82 08 40 0c  and  %g1, %o4, %g1
a009b358:  94 0a 80 0c  and  %o2, %o4, %o2
a009b35c:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a009b360:  da 02 e0 08  ld  [ %o3 + 8 ], %o5
a009b364:  94 02 80 01  add  %o2, %g1, %o2
a009b368:  92 12 63 ff  or  %o1, 0x3ff, %o1
a009b36c:  9a 0b 40 0c  and  %o5, %o4, %o5
a009b370:  c2 02 e0 0c  ld  [ %o3 + 0xc ], %g1
a009b374:  92 0a 00 09  and  %o0, %o1, %o1
a009b378:  94 02 80 0d  add  %o2, %o5, %o2
a009b37c:  82 08 40 0c  and  %g1, %o4, %g1
a009b380:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b384:  94 02 80 01  add  %o2, %g1, %o2
a009b388:  7f ff 5f 2f  call  0xa0073044
a009b38c:  90 12 20 c0  or  %o0, 0xc0, %o0
a009b390:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009b394:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009b398:  a8 10 63 00  or  %g1, 0x300, %l4
a009b39c:  a4 5e 20 34  smul  %i0, 0x34, %l2
a009b3a0:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a009b3a4:  a6 04 80 14  add  %l2, %l4, %l3
a009b3a8:  a0 10 63 ff  or  %g1, 0x3ff, %l0
a009b3ac:  d2 04 e0 18  ld  [ %l3 + 0x18 ], %o1
a009b3b0:  c2 02 60 38  ld  [ %o1 + 0x38 ], %g1
a009b3b4:  82 08 40 10  and  %g1, %l0, %g1
a009b3b8:  1b 00 00 20  sethi  %hi(0x8000), %o5
a009b3bc:  80 a0 40 0d  cmp  %g1, %o5
a009b3c0:  02 80 00 07  be  0xa009b3dc
a009b3c4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009b3c8:  a2 10 60 80  or  %g1, 0x80, %l1	! 0xa8079080
a009b3cc:  c2 0c 40 18  ldub  [ %l1 + %i0 ], %g1
a009b3d0:  80 a0 60 05  cmp  %g1, 5
a009b3d4:  08 80 00 12  bleu  0xa009b41c
a009b3d8:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1
a009b3dc:  92 02 60 80  add  %o1, 0x80, %o1
a009b3e0:  40 00 2f f3  call  0xa00a73ac
a009b3e4:  90 10 20 04  mov  4, %o0
a009b3e8:  d2 05 00 12  ld  [ %l4 + %l2 ], %o1
a009b3ec:  92 02 60 04  add  %o1, 4, %o1
a009b3f0:  40 00 2f f9  call  0xa00a73d4
a009b3f4:  90 10 20 15  mov  0x15, %o0
a009b3f8:  c2 05 62 34  ld  [ %l5 + 0x234 ], %g1
a009b3fc:  80 88 68 00  btst  0x800, %g1
a009b400:  22 80 00 1c  be,a   0xa009b470
a009b404:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009b408:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b40c:  7f ff 60 2e  call  0xa00734c4
a009b410:  90 12 21 08  or  %o0, 0x108, %o0	! 0xa006a508
a009b414:  10 80 00 17  b  0xa009b470
a009b418:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009b41c:  80 88 68 00  btst  0x800, %g1
a009b420:  22 80 00 06  be,a   0xa009b438
a009b424:  da 04 e0 18  ld  [ %l3 + 0x18 ], %o5
a009b428:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b42c:  7f ff 60 26  call  0xa00734c4
a009b430:  90 12 21 28  or  %o0, 0x128, %o0	! 0xa006a528
a009b434:  da 04 e0 18  ld  [ %l3 + 0x18 ], %o5
a009b438:  c2 03 60 34  ld  [ %o5 + 0x34 ], %g1
a009b43c:  82 10 40 10  or  %g1, %l0, %g1
a009b440:  c2 23 60 34  st  %g1, [ %o5 + 0x34 ]
a009b444:  c2 03 60 38  ld  [ %o5 + 0x38 ], %g1
a009b448:  82 10 40 10  or  %g1, %l0, %g1
a009b44c:  c2 23 60 38  st  %g1, [ %o5 + 0x38 ]
a009b450:  da 0c 40 18  ldub  [ %l1 + %i0 ], %o5
a009b454:  96 17 62 48  or  %i5, 0x248, %o3
a009b458:  99 2e 20 02  sll  %i0, 2, %o4
a009b45c:  82 10 20 06  mov  6, %g1
a009b460:  9a 03 60 01  inc  %o5
a009b464:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a009b468:  10 80 00 61  b  0xa009b5ec
a009b46c:  da 2c 40 18  stb  %o5, [ %l1 + %i0 ]
a009b470:  82 10 60 80  or  %g1, 0x80, %g1
a009b474:  40 00 5a fc  call  0xa00b2064
a009b478:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a009b47c:  9a 16 a2 80  or  %i2, 0x280, %o5
a009b480:  82 5e 20 b0  smul  %i0, 0xb0, %g1
a009b484:  a2 00 40 0d  add  %g1, %o5, %l1
a009b488:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009b48c:  b1 2e 20 02  sll  %i0, 2, %i0
a009b490:  82 10 60 74  or  %g1, 0x74, %g1
a009b494:  d2 00 40 18  ld  [ %g1 + %i0 ], %o1
a009b498:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009b49c:  82 10 60 6c  or  %g1, 0x6c, %g1	! 0xa807906c
a009b4a0:  d0 20 40 18  st  %o0, [ %g1 + %i0 ]
a009b4a4:  98 10 00 08  mov  %o0, %o4
a009b4a8:  96 10 00 08  mov  %o0, %o3
a009b4ac:  94 10 00 09  mov  %o1, %o2
a009b4b0:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b4b4:  92 23 00 09  sub  %o4, %o1, %o1
a009b4b8:  c0 2c 60 37  clrb  [ %l1 + 0x37 ]
a009b4bc:  7f ff 5e e2  call  0xa0073044
a009b4c0:  90 12 21 48  or  %o0, 0x148, %o0
a009b4c4:  a0 0e 60 ff  and  %i1, 0xff, %l0
a009b4c8:  7f ff 7d b3  call  0xa007ab94
a009b4cc:  90 10 00 10  mov  %l0, %o0
a009b4d0:  c2 0c 60 02  ldub  [ %l1 + 2 ], %g1
a009b4d4:  82 00 7f fb  add  %g1, -5, %g1
a009b4d8:  82 08 60 ff  and  %g1, 0xff, %g1
a009b4dc:  80 a0 60 01  cmp  %g1, 1
a009b4e0:  18 80 00 0f  bgu  0xa009b51c
a009b4e4:  90 10 00 10  mov  %l0, %o0
a009b4e8:  7f ff 91 49  call  0xa007fa0c
a009b4ec:  90 10 00 10  mov  %l0, %o0
a009b4f0:  7f ff 79 03  call  0xa00798fc
a009b4f4:  90 10 00 10  mov  %l0, %o0
a009b4f8:  40 00 58 a7  call  0xa00b1794
a009b4fc:  90 10 20 01  mov  1, %o0
a009b500:  7f ff 79 2e  call  0xa00799b8
a009b504:  90 10 00 10  mov  %l0, %o0
a009b508:  9a 17 62 48  or  %i5, 0x248, %o5
a009b50c:  82 10 20 09  mov  9, %g1
a009b510:  c2 23 40 18  st  %g1, [ %o5 + %i0 ]
a009b514:  10 80 00 36  b  0xa009b5ec
a009b518:  c0 2c 60 2c  clrb  [ %l1 + 0x2c ]
a009b51c:  92 10 20 00  clr  %o1
a009b520:  94 10 20 01  mov  1, %o2
a009b524:  7f ff 92 2f  call  0xa007fde0
a009b528:  96 10 20 00  clr  %o3
a009b52c:  9a 17 62 48  or  %i5, 0x248, %o5
a009b530:  82 10 20 08  mov  8, %g1
a009b534:  10 80 00 2e  b  0xa009b5ec
a009b538:  c2 23 40 18  st  %g1, [ %o5 + %i0 ]
a009b53c:  9a 16 a2 80  or  %i2, 0x280, %o5
a009b540:  98 00 40 0d  add  %g1, %o5, %o4
a009b544:  c2 0b 20 2b  ldub  [ %o4 + 0x2b ], %g1
a009b548:  82 00 60 01  inc  %g1
a009b54c:  a0 08 60 ff  and  %g1, 0xff, %l0
a009b550:  80 a4 20 03  cmp  %l0, 3
a009b554:  12 80 00 26  bne  0xa009b5ec
a009b558:  c2 2b 20 2b  stb  %g1, [ %o4 + 0x2b ]
a009b55c:  c0 2b 20 2b  clrb  [ %o4 + 0x2b ]
a009b560:  7f ff 93 39  call  0xa0080244
a009b564:  90 0e 60 03  and  %i1, 3, %o0
a009b568:  7f ff c8 a6  call  0xa008d800
a009b56c:  01 00 00 00  nop
a009b570:  90 0a 20 ff  and  %o0, 0xff, %o0
a009b574:  80 a2 20 82  cmp  %o0, 0x82
a009b578:  18 80 00 1d  bgu  0xa009b5ec
a009b57c:  01 00 00 00  nop
a009b580:  7f ff fc 46  call  0xa009a698
a009b584:  90 10 00 11  mov  %l1, %o0
a009b588:  80 8a 20 ff  btst  0xff, %o0
a009b58c:  02 80 00 18  be  0xa009b5ec
a009b590:  9a 17 62 48  or  %i5, 0x248, %o5
a009b594:  83 2c 60 02  sll  %l1, 2, %g1
a009b598:  10 80 00 15  b  0xa009b5ec
a009b59c:  e0 23 40 01  st  %l0, [ %o5 + %g1 ]
a009b5a0:  9a 14 e3 00  or  %l3, 0x300, %o5
a009b5a4:  82 5c 60 34  smul  %l1, 0x34, %g1
a009b5a8:  82 00 40 0d  add  %g1, %o5, %g1
a009b5ac:  d2 00 60 18  ld  [ %g1 + 0x18 ], %o1
a009b5b0:  90 10 20 04  mov  4, %o0
a009b5b4:  40 00 2f 7e  call  0xa00a73ac
a009b5b8:  92 02 60 80  add  %o1, 0x80, %o1
a009b5bc:  82 16 a2 80  or  %i2, 0x280, %g1
a009b5c0:  9a 5c 60 b0  smul  %l1, 0xb0, %o5
a009b5c4:  9a 03 40 01  add  %o5, %g1, %o5
a009b5c8:  96 17 62 48  or  %i5, 0x248, %o3
a009b5cc:  99 2c 60 02  sll  %l1, 2, %o4
a009b5d0:  82 10 20 09  mov  9, %g1
a009b5d4:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a009b5d8:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009b5dc:  c0 2b 60 2c  clrb  [ %o5 + 0x2c ]
a009b5e0:  90 12 21 78  or  %o0, 0x178, %o0
a009b5e4:  7f ff 5f b8  call  0xa00734c4
a009b5e8:  01 00 00 00  nop
a009b5ec:  81 c7 e0 08  ret
a009b5f0:  91 e8 20 00  restore  %g0, 0, %o0
