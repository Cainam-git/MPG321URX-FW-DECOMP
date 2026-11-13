# leon2m FUN_a00b8e7c 0xa00b8e7c-0xa00b9750 (2260 bytes)
a00b8e7c:  9d e3 bf 90  save  %sp, -112, %sp
a00b8e80:  90 10 20 00  clr  %o0
a00b8e84:  40 02 37 cf  call  0xa0146dc0
a00b8e88:  92 10 20 00  clr  %o1
a00b8e8c:  94 10 20 00  clr  %o2
a00b8e90:  90 10 20 08  mov  8, %o0
a00b8e94:  40 02 37 6b  call  0xa0146c40
a00b8e98:  92 10 20 00  clr  %o1
a00b8e9c:  94 10 20 24  mov  0x24, %o2
a00b8ea0:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00b8ea4:  d4 2a 60 8f  stb  %o2, [ %o1 + 0x8f ]	! 0xa802b08f
a00b8ea8:  92 10 20 01  mov  1, %o1
a00b8eac:  40 02 37 c5  call  0xa0146dc0
a00b8eb0:  90 10 20 00  clr  %o0
a00b8eb4:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00b8eb8:  a6 12 23 f4  or  %o0, 0x3f4, %l3	! 0xa802cff4
a00b8ebc:  d8 14 e0 3e  lduh  [ %l3 + 0x3e ], %o4
a00b8ec0:  23 3f ff e0  sethi  %hi(0xffff8000), %l1
a00b8ec4:  82 2b 00 11  andn  %o4, %l1, %g1
a00b8ec8:  67 ff 54 f7  call  0x4008e2a4
a00b8ecc:  c2 34 e0 3e  sth  %g1, [ %l3 + 0x3e ]
a00b8ed0:  67 ff 54 f5  call  0x4008e2a4
a00b8ed4:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00b8ed8:  7f ff f0 80  call  0xa00b50d8
a00b8edc:  90 10 20 02  mov  2, %o0
a00b8ee0:  90 10 20 00  clr  %o0
a00b8ee4:  40 02 37 b7  call  0xa0146dc0
a00b8ee8:  92 10 20 00  clr  %o1
a00b8eec:  90 10 20 08  mov  8, %o0
a00b8ef0:  92 10 20 00  clr  %o1
a00b8ef4:  40 02 37 53  call  0xa0146c40
a00b8ef8:  94 10 20 00  clr  %o2
a00b8efc:  98 10 20 00  clr  %o4
a00b8f00:  96 10 20 00  clr  %o3
a00b8f04:  90 10 20 00  clr  %o0
a00b8f08:  92 10 20 00  clr  %o1
a00b8f0c:  40 02 35 cf  call  0xa0146648
a00b8f10:  94 10 20 00  clr  %o2
a00b8f14:  90 10 20 16  mov  0x16, %o0
a00b8f18:  92 10 20 11  mov  0x11, %o1
a00b8f1c:  40 02 34 88  call  0xa014613c
a00b8f20:  94 10 20 00  clr  %o2
a00b8f24:  a2 14 e2 90  or  %l3, 0x290, %l1
a00b8f28:  94 10 20 00  clr  %o2
a00b8f2c:  d0 0c 60 0d  ldub  [ %l1 + 0xd ], %o0
a00b8f30:  40 02 35 7a  call  0xa0146518
a00b8f34:  d2 0c 60 0e  ldub  [ %l1 + 0xe ], %o1
a00b8f38:  92 10 20 00  clr  %o1
a00b8f3c:  40 02 36 dd  call  0xa0146ab0
a00b8f40:  90 10 27 92  mov  0x792, %o0
a00b8f44:  40 02 34 71  call  0xa0146108
a00b8f48:  90 10 20 00  clr  %o0
a00b8f4c:  90 10 26 78  mov  0x678, %o0
a00b8f50:  92 10 25 7c  mov  0x57c, %o1
a00b8f54:  40 02 35 7e  call  0xa014654c
a00b8f58:  94 10 20 00  clr  %o2
a00b8f5c:  94 10 20 02  mov  2, %o2
a00b8f60:  92 10 20 00  clr  %o1
a00b8f64:  90 10 20 00  clr  %o0
a00b8f68:  7f ff b2 68  call  0xa00a5908
a00b8f6c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b8f70:  a0 06 00 11  add  %i0, %l1, %l0
a00b8f74:  7f ff ba 46  call  0xa00a788c
a00b8f78:  d0 0c 21 8a  ldub  [ %l0 + 0x18a ], %o0
a00b8f7c:  90 10 20 02  mov  2, %o0
a00b8f80:  40 02 36 fb  call  0xa0146b6c
a00b8f84:  92 10 20 00  clr  %o1
a00b8f88:  90 10 20 60  mov  0x60, %o0
a00b8f8c:  40 02 36 f1  call  0xa0146b50
a00b8f90:  92 10 20 00  clr  %o1
a00b8f94:  e4 0c 21 8a  ldub  [ %l0 + 0x18a ], %l2
a00b8f98:  9b 2c a0 03  sll  %l2, 3, %o5
a00b8f9c:  a8 23 40 12  sub  %o5, %l2, %l4
a00b8fa0:  a1 2d 20 02  sll  %l4, 2, %l0
a00b8fa4:  96 04 00 12  add  %l0, %l2, %o3
a00b8fa8:  de 0c 60 08  ldub  [ %l1 + 8 ], %o7
a00b8fac:  94 02 c0 0f  add  %o3, %o7, %o2
a00b8fb0:  93 2a a0 10  sll  %o2, 0x10, %o1
a00b8fb4:  11 00 06 4d  sethi  %hi(0x193400), %o0
a00b8fb8:  93 32 60 10  srl  %o1, 0x10, %o1
a00b8fbc:  7f ff aa 22  call  0xa00a3844
a00b8fc0:  90 12 21 bc  or  %o0, 0x1bc, %o0
a00b8fc4:  98 10 00 08  mov  %o0, %o4
a00b8fc8:  96 10 20 10  mov  0x10, %o3
a00b8fcc:  9a 10 20 00  clr  %o5
a00b8fd0:  90 10 20 00  clr  %o0
a00b8fd4:  92 10 20 03  mov  3, %o1
a00b8fd8:  7f ff a8 73  call  0xa00a31a4
a00b8fdc:  94 10 20 01  mov  1, %o2
a00b8fe0:  d6 0c 60 08  ldub  [ %l1 + 8 ], %o3
a00b8fe4:  80 a0 00 0b  cmp  %g0, %o3
a00b8fe8:  98 60 3f ff  subx  %g0, -1, %o4
a00b8fec:  82 1a e0 06  xor  %o3, 6, %g1
a00b8ff0:  80 a0 00 01  cmp  %g0, %g1
a00b8ff4:  9a 60 3f ff  subx  %g0, -1, %o5
a00b8ff8:  80 93 00 0d  orcc  %o4, %o5, %g0
a00b8ffc:  32 80 00 08  bne,a   0xa00b901c
a00b9000:  96 14 e2 90  or  %l3, 0x290, %o3
a00b9004:  80 a2 e0 07  cmp  %o3, 7
a00b9008:  02 80 00 04  be  0xa00b9018
a00b900c:  80 a2 e0 0a  cmp  %o3, 0xa
a00b9010:  12 80 00 04  bne  0xa00b9020
a00b9014:  a2 10 20 01  mov  1, %l1
a00b9018:  96 14 e2 90  or  %l3, 0x290, %o3
a00b901c:  e2 0a e0 08  ldub  [ %o3 + 8 ], %l1
a00b9020:  9a 14 e2 90  or  %l3, 0x290, %o5
a00b9024:  9e 06 00 0d  add  %i0, %o5, %o7
a00b9028:  c2 0b e1 8a  ldub  [ %o7 + 0x18a ], %g1
a00b902c:  80 a0 60 07  cmp  %g1, 7
a00b9030:  02 80 01 19  be  0xa00b9494
a00b9034:  80 a0 60 08  cmp  %g1, 8
a00b9038:  02 80 01 4a  be  0xa00b9560
a00b903c:  80 a0 60 0a  cmp  %g1, 0xa
a00b9040:  02 80 01 4c  be  0xa00b9570
a00b9044:  01 00 00 00  nop
a00b9048:  a0 14 e2 90  or  %l3, 0x290, %l0
a00b904c:  9a 06 00 10  add  %i0, %l0, %o5
a00b9050:  c2 0b 61 8a  ldub  [ %o5 + 0x18a ], %g1
a00b9054:  80 a0 60 01  cmp  %g1, 1
a00b9058:  02 80 01 1a  be  0xa00b94c0
a00b905c:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a00b9060:  80 a0 60 02  cmp  %g1, 2
a00b9064:  02 80 00 58  be  0xa00b91c4
a00b9068:  80 a0 60 07  cmp  %g1, 7
a00b906c:  02 80 01 45  be  0xa00b9580
a00b9070:  80 a0 60 08  cmp  %g1, 8
a00b9074:  02 80 00 e6  be  0xa00b940c
a00b9078:  80 a0 60 0a  cmp  %g1, 0xa
a00b907c:  02 80 01 44  be  0xa00b958c
a00b9080:  80 a0 60 04  cmp  %g1, 4
a00b9084:  02 80 01 46  be  0xa00b959c
a00b9088:  80 a0 60 03  cmp  %g1, 3
a00b908c:  02 80 01 8f  be  0xa00b96c8
a00b9090:  80 a0 60 05  cmp  %g1, 5
a00b9094:  02 80 00 a2  be  0xa00b931c
a00b9098:  80 a0 60 06  cmp  %g1, 6
a00b909c:  02 80 01 47  be  0xa00b95b8
a00b90a0:  80 a0 60 09  cmp  %g1, 9
a00b90a4:  02 80 01 96  be  0xa00b96fc
a00b90a8:  a8 06 00 10  add  %i0, %l0, %l4
a00b90ac:  d6 0d 21 8a  ldub  [ %l4 + 0x18a ], %o3
a00b90b0:  80 a2 e0 0b  cmp  %o3, 0xb
a00b90b4:  32 80 00 58  bne,a   0xa00b9214
a00b90b8:  90 10 20 92  mov  0x92, %o0
a00b90bc:  e4 0c 21 7c  ldub  [ %l0 + 0x17c ], %l2
a00b90c0:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00b90c4:  e4 2c 60 56  stb  %l2, [ %l1 + 0x56 ]	! 0xa8025c56
a00b90c8:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00b90cc:  a4 14 22 90  or  %l0, 0x290, %l2	! 0xa802d290
a00b90d0:  a2 10 20 00  clr  %l1
a00b90d4:  a0 10 20 00  clr  %l0
a00b90d8:  29 00 06 42  sethi  %hi(0x190800), %l4
a00b90dc:  97 2c 20 03  sll  %l0, 3, %o3
a00b90e0:  94 22 c0 10  sub  %o3, %l0, %o2
a00b90e4:  93 2a a0 02  sll  %o2, 2, %o1
a00b90e8:  90 02 40 10  add  %o1, %l0, %o0
a00b90ec:  c2 0c a0 08  ldub  [ %l2 + 8 ], %g1
a00b90f0:  98 02 00 01  add  %o0, %g1, %o4
a00b90f4:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00b90f8:  93 33 60 10  srl  %o5, 0x10, %o1
a00b90fc:  7f ff a9 d2  call  0xa00a3844
a00b9100:  90 15 21 ec  or  %l4, 0x1ec, %o0
a00b9104:  9e 04 00 10  add  %l0, %l0, %o7
a00b9108:  98 10 00 08  mov  %o0, %o4
a00b910c:  94 03 e0 05  add  %o7, 5, %o2
a00b9110:  90 10 20 00  clr  %o0
a00b9114:  92 10 20 06  mov  6, %o1
a00b9118:  96 10 20 0a  mov  0xa, %o3
a00b911c:  9a 10 20 00  clr  %o5
a00b9120:  7f ff a8 21  call  0xa00a31a4
a00b9124:  a2 04 60 01  inc  %l1
a00b9128:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b912c:  80 a4 20 02  cmp  %l0, 2
a00b9130:  08 bf ff ec  bleu  0xa00b90e0
a00b9134:  97 2c 20 03  sll  %l0, 3, %o3
a00b9138:  d0 0c a1 7c  ldub  [ %l2 + 0x17c ], %o0
a00b913c:  7f ff d1 cc  call  0xa00ad86c
a00b9140:  92 10 20 01  mov  1, %o1
a00b9144:  d0 0c a1 7c  ldub  [ %l2 + 0x17c ], %o0
a00b9148:  7f ff d1 c9  call  0xa00ad86c
a00b914c:  92 10 20 00  clr  %o1
a00b9150:  d8 0c a1 7c  ldub  [ %l2 + 0x17c ], %o4
a00b9154:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b9158:  80 a0 60 03  cmp  %g1, 3
a00b915c:  08 80 00 05  bleu  0xa00b9170
a00b9160:  a2 00 40 01  add  %g1, %g1, %l1
a00b9164:  a8 03 3f fc  add  %o4, -4, %l4
a00b9168:  82 0d 20 ff  and  %l4, 0xff, %g1
a00b916c:  a2 00 40 01  add  %g1, %g1, %l1
a00b9170:  a0 04 60 05  add  %l1, 5, %l0
a00b9174:  a3 2c 20 10  sll  %l0, 0x10, %l1
a00b9178:  a0 10 20 00  clr  %l0
a00b917c:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b9180:  98 02 20 04  add  %o0, 4, %o4
a00b9184:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00b9188:  9e 04 20 1c  add  %l0, 0x1c, %o7
a00b918c:  93 33 60 10  srl  %o5, 0x10, %o1
a00b9190:  98 0b e0 ff  and  %o7, 0xff, %o4
a00b9194:  90 10 20 00  clr  %o0
a00b9198:  95 34 60 10  srl  %l1, 0x10, %o2
a00b919c:  96 10 20 01  mov  1, %o3
a00b91a0:  9a 10 20 00  clr  %o5
a00b91a4:  40 02 36 5f  call  0xa0146b20
a00b91a8:  a0 04 20 01  inc  %l0
a00b91ac:  a4 0c 20 ff  and  %l0, 0xff, %l2
a00b91b0:  80 a4 a0 01  cmp  %l2, 1
a00b91b4:  28 bf ff f3  bleu,a   0xa00b9180
a00b91b8:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b91bc:  10 80 00 16  b  0xa00b9214
a00b91c0:  90 10 20 92  mov  0x92, %o0
a00b91c4:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a00b91c8:  83 33 60 0b  srl  %o5, 0xb, %g1
a00b91cc:  96 08 60 01  and  %g1, 1, %o3
a00b91d0:  d0 0c 21 82  ldub  [ %l0 + 0x182 ], %o0
a00b91d4:  29 2a 00 97  sethi  %hi(0xa8025c00), %l4
a00b91d8:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a00b91dc:  9e 0b 77 ff  and  %o5, -2049, %o7
a00b91e0:  d0 2d 20 56  stb  %o0, [ %l4 + 0x56 ]
a00b91e4:  d6 2c a0 55  stb  %o3, [ %l2 + 0x55 ]
a00b91e8:  80 a2 e0 00  cmp  %o3, 0
a00b91ec:  12 80 01 40  bne  0xa00b96ec
a00b91f0:  de 24 20 a8  st  %o7, [ %l0 + 0xa8 ]
a00b91f4:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00b91f8:  7f ff fe ac  call  0xa00b8ca8
a00b91fc:  91 34 60 02  srl  %l1, 2, %o0
a00b9200:  d0 0c 21 82  ldub  [ %l0 + 0x182 ], %o0
a00b9204:  90 0a 20 03  and  %o0, 3, %o0
a00b9208:  7f ff d1 99  call  0xa00ad86c
a00b920c:  92 10 20 01  mov  1, %o1
a00b9210:  90 10 20 92  mov  0x92, %o0
a00b9214:  40 02 36 4f  call  0xa0146b50
a00b9218:  92 10 20 00  clr  %o1
a00b921c:  90 10 20 00  clr  %o0
a00b9220:  40 02 36 53  call  0xa0146b6c
a00b9224:  92 10 20 00  clr  %o1
a00b9228:  90 10 20 06  mov  6, %o0
a00b922c:  92 10 20 0f  mov  0xf, %o1
a00b9230:  94 10 20 06  mov  6, %o2
a00b9234:  96 10 25 92  mov  0x592, %o3
a00b9238:  40 02 36 12  call  0xa0146a80
a00b923c:  98 10 20 00  clr  %o4
a00b9240:  92 10 20 0f  mov  0xf, %o1
a00b9244:  94 10 20 06  mov  6, %o2
a00b9248:  96 10 25 92  mov  0x592, %o3
a00b924c:  98 10 20 00  clr  %o4
a00b9250:  a2 14 e2 90  or  %l3, 0x290, %l1
a00b9254:  40 02 36 0b  call  0xa0146a80
a00b9258:  90 10 20 0f  mov  0xf, %o0
a00b925c:  a8 06 00 11  add  %i0, %l1, %l4
a00b9260:  d8 0d 21 8a  ldub  [ %l4 + 0x18a ], %o4
a00b9264:  96 03 3f f9  add  %o4, -7, %o3
a00b9268:  94 0a e0 ff  and  %o3, 0xff, %o2
a00b926c:  80 a2 a0 02  cmp  %o2, 2
a00b9270:  92 60 20 00  subx  %g0, 0, %o1
a00b9274:  82 1b 20 0a  xor  %o4, 0xa, %g1
a00b9278:  80 a0 00 01  cmp  %g0, %g1
a00b927c:  a6 0a 60 01  and  %o1, 1, %l3
a00b9280:  b0 60 3f ff  subx  %g0, -1, %i0
a00b9284:  80 94 c0 18  orcc  %l3, %i0, %g0
a00b9288:  12 80 00 12  bne  0xa00b92d0
a00b928c:  80 a3 20 01  cmp  %o4, 1
a00b9290:  22 80 00 21  be,a   0xa00b9314
a00b9294:  e4 0c 60 08  ldub  [ %l1 + 8 ], %l2
a00b9298:  21 00 06 4a  sethi  %hi(0x192800), %l0
a00b929c:  d2 0c 60 08  ldub  [ %l1 + 8 ], %o1
a00b92a0:  7f ff a9 69  call  0xa00a3844
a00b92a4:  90 14 20 b0  or  %l0, 0xb0, %o0
a00b92a8:  98 10 00 08  mov  %o0, %o4
a00b92ac:  92 10 20 06  mov  6, %o1
a00b92b0:  94 10 20 0f  mov  0xf, %o2
a00b92b4:  96 10 20 01  mov  1, %o3
a00b92b8:  9a 10 20 00  clr  %o5
a00b92bc:  7f ff a7 ba  call  0xa00a31a4
a00b92c0:  90 10 20 00  clr  %o0
a00b92c4:  d8 0c 60 08  ldub  [ %l1 + 8 ], %o4
a00b92c8:  10 80 01 14  b  0xa00b9718
a00b92cc:  92 03 20 74  add  %o4, 0x74, %o1
a00b92d0:  e0 0c 60 08  ldub  [ %l1 + 8 ], %l0
a00b92d4:  92 04 20 3a  add  %l0, 0x3a, %o1
a00b92d8:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00b92dc:  21 00 06 4a  sethi  %hi(0x192800), %l0
a00b92e0:  93 33 60 10  srl  %o5, 0x10, %o1
a00b92e4:  7f ff a9 58  call  0xa00a3844
a00b92e8:  90 14 20 b0  or  %l0, 0xb0, %o0
a00b92ec:  98 10 00 08  mov  %o0, %o4
a00b92f0:  92 10 20 06  mov  6, %o1
a00b92f4:  94 10 20 0f  mov  0xf, %o2
a00b92f8:  96 10 20 01  mov  1, %o3
a00b92fc:  9a 10 20 00  clr  %o5
a00b9300:  7f ff a7 a9  call  0xa00a31a4
a00b9304:  90 10 20 00  clr  %o0
a00b9308:  de 0c 60 08  ldub  [ %l1 + 8 ], %o7
a00b930c:  10 80 01 03  b  0xa00b9718
a00b9310:  92 03 e0 91  add  %o7, 0x91, %o1
a00b9314:  10 bf ff f1  b  0xa00b92d8
a00b9318:  92 04 a0 57  add  %l2, 0x57, %o1
a00b931c:  a2 10 20 00  clr  %l1
a00b9320:  a0 10 20 00  clr  %l0
a00b9324:  25 00 06 5a  sethi  %hi(0x196800), %l2
a00b9328:  92 10 00 10  mov  %l0, %o1
a00b932c:  7f ff a9 46  call  0xa00a3844
a00b9330:  90 14 a3 24  or  %l2, 0x324, %o0
a00b9334:  98 10 00 08  mov  %o0, %o4
a00b9338:  94 04 00 10  add  %l0, %l0, %o2
a00b933c:  94 02 a0 05  add  %o2, 5, %o2
a00b9340:  90 10 20 00  clr  %o0
a00b9344:  92 10 20 06  mov  6, %o1
a00b9348:  96 10 20 0a  mov  0xa, %o3
a00b934c:  9a 10 20 00  clr  %o5
a00b9350:  7f ff a7 95  call  0xa00a31a4
a00b9354:  a2 04 60 01  inc  %l1
a00b9358:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b935c:  80 a4 20 03  cmp  %l0, 3
a00b9360:  08 bf ff f3  bleu  0xa00b932c
a00b9364:  92 10 00 10  mov  %l0, %o1
a00b9368:  a4 14 e2 90  or  %l3, 0x290, %l2
a00b936c:  40 02 2c a4  call  0xa01445fc
a00b9370:  d0 0c a0 1e  ldub  [ %l2 + 0x1e ], %o0
a00b9374:  96 10 00 08  mov  %o0, %o3
a00b9378:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00b937c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b9380:  d6 2c 20 56  stb  %o3, [ %l0 + 0x56 ]
a00b9384:  7f ff d1 3a  call  0xa00ad86c
a00b9388:  92 10 20 01  mov  1, %o1
a00b938c:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0
a00b9390:  7f ff d1 37  call  0xa00ad86c
a00b9394:  92 10 20 00  clr  %o1
a00b9398:  da 0c 20 56  ldub  [ %l0 + 0x56 ], %o5
a00b939c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00b93a0:  80 a0 60 03  cmp  %g1, 3
a00b93a4:  18 80 00 c5  bgu  0xa00b96b8
a00b93a8:  9e 03 7f fc  add  %o5, -4, %o7
a00b93ac:  9a 00 40 01  add  %g1, %g1, %o5
a00b93b0:  a8 03 60 05  add  %o5, 5, %l4
a00b93b4:  a3 2d 20 10  sll  %l4, 0x10, %l1
a00b93b8:  a0 10 20 00  clr  %l0
a00b93bc:  94 0c 20 ff  and  %l0, 0xff, %o2
a00b93c0:  92 02 a0 04  add  %o2, 4, %o1
a00b93c4:  91 2a 60 10  sll  %o1, 0x10, %o0
a00b93c8:  98 04 20 1c  add  %l0, 0x1c, %o4
a00b93cc:  93 32 20 10  srl  %o0, 0x10, %o1
a00b93d0:  98 0b 20 ff  and  %o4, 0xff, %o4
a00b93d4:  90 10 20 00  clr  %o0
a00b93d8:  95 34 60 10  srl  %l1, 0x10, %o2
a00b93dc:  96 10 20 01  mov  1, %o3
a00b93e0:  40 02 35 d0  call  0xa0146b20
a00b93e4:  9a 10 20 00  clr  %o5
a00b93e8:  a0 04 20 01  inc  %l0
a00b93ec:  82 0c 20 ff  and  %l0, 0xff, %g1
a00b93f0:  80 a0 60 01  cmp  %g1, 1
a00b93f4:  08 bf ff f3  bleu  0xa00b93c0
a00b93f8:  94 0c 20 ff  and  %l0, 0xff, %o2
a00b93fc:  a2 14 e2 90  or  %l3, 0x290, %l1
a00b9400:  e0 0c 60 1e  ldub  [ %l1 + 0x1e ], %l0
a00b9404:  10 bf ff 83  b  0xa00b9210
a00b9408:  e0 2c 61 a3  stb  %l0, [ %l1 + 0x1a3 ]
a00b940c:  d0 04 20 ac  ld  [ %l0 + 0xac ], %o0
a00b9410:  83 32 20 16  srl  %o0, 0x16, %g1
a00b9414:  92 08 60 01  and  %g1, 1, %o1
a00b9418:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00b941c:  d2 2c 20 56  stb  %o1, [ %l0 + 0x56 ]	! 0xa8025c56
a00b9420:  90 10 20 02  mov  2, %o0
a00b9424:  40 02 35 d2  call  0xa0146b6c
a00b9428:  92 10 20 00  clr  %o1
a00b942c:  25 00 06 4c  sethi  %hi(0x193000), %l2
a00b9430:  92 0c 60 ff  and  %l1, 0xff, %o1
a00b9434:  7f ff a9 04  call  0xa00a3844
a00b9438:  90 14 a2 48  or  %l2, 0x248, %o0
a00b943c:  98 10 00 08  mov  %o0, %o4
a00b9440:  94 10 20 08  mov  8, %o2
a00b9444:  96 10 20 03  mov  3, %o3
a00b9448:  9a 10 20 00  clr  %o5
a00b944c:  90 10 20 00  clr  %o0
a00b9450:  7f ff a7 55  call  0xa00a31a4
a00b9454:  92 10 20 03  mov  3, %o1
a00b9458:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00b945c:  a8 03 60 1d  add  %o5, 0x1d, %l4
a00b9460:  9f 2d 20 10  sll  %l4, 0x10, %o7
a00b9464:  93 33 e0 10  srl  %o7, 0x10, %o1
a00b9468:  7f ff a8 f7  call  0xa00a3844
a00b946c:  90 14 a2 48  or  %l2, 0x248, %o0
a00b9470:  98 10 00 08  mov  %o0, %o4
a00b9474:  90 10 20 00  clr  %o0
a00b9478:  92 10 20 10  mov  0x10, %o1
a00b947c:  94 10 20 08  mov  8, %o2
a00b9480:  96 10 20 03  mov  3, %o3
a00b9484:  7f ff a7 48  call  0xa00a31a4
a00b9488:  9a 10 20 00  clr  %o5
a00b948c:  10 bf ff 62  b  0xa00b9214
a00b9490:  90 10 20 92  mov  0x92, %o0
a00b9494:  e4 03 60 a8  ld  [ %o5 + 0xa8 ], %l2
a00b9498:  91 34 a0 0c  srl  %l2, 0xc, %o0
a00b949c:  90 0a 20 01  and  %o0, 1, %o0
a00b94a0:  7f ff ad 64  call  0xa00a4a30
a00b94a4:  a0 14 e2 90  or  %l3, 0x290, %l0
a00b94a8:  9a 06 00 10  add  %i0, %l0, %o5
a00b94ac:  c2 0b 61 8a  ldub  [ %o5 + 0x18a ], %g1
a00b94b0:  80 a0 60 01  cmp  %g1, 1
a00b94b4:  12 bf fe ec  bne  0xa00b9064
a00b94b8:  80 a0 60 02  cmp  %g1, 2
a00b94bc:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a00b94c0:  e2 0c 20 09  ldub  [ %l0 + 9 ], %l1
a00b94c4:  e2 2b 20 56  stb  %l1, [ %o4 + 0x56 ]
a00b94c8:  94 0c 60 ff  and  %l1, 0xff, %o2
a00b94cc:  96 10 20 0c  mov  0xc, %o3
a00b94d0:  90 10 20 05  mov  5, %o0
a00b94d4:  7f ff ac 3b  call  0xa00a45c0
a00b94d8:  92 10 20 08  mov  8, %o1
a00b94dc:  e0 0c 20 09  ldub  [ %l0 + 9 ], %l0
a00b94e0:  90 10 20 6f  mov  0x6f, %o0
a00b94e4:  40 02 35 9b  call  0xa0146b50
a00b94e8:  92 10 20 00  clr  %o1
a00b94ec:  90 10 20 02  mov  2, %o0
a00b94f0:  40 02 35 9f  call  0xa0146b6c
a00b94f4:  92 10 20 00  clr  %o1
a00b94f8:  03 00 06 60  sethi  %hi(0x198000), %g1
a00b94fc:  a2 07 bf f0  add  %fp, -16, %l1
a00b9500:  92 10 61 d0  or  %g1, 0x1d0, %o1
a00b9504:  94 0c 20 ff  and  %l0, 0xff, %o2
a00b9508:  40 02 78 bb  call  0xa01577f4
a00b950c:  90 10 00 11  mov  %l1, %o0
a00b9510:  98 10 20 00  clr  %o4
a00b9514:  82 10 20 00  clr  %g1
a00b9518:  96 07 bf f8  add  %fp, -8, %o3
a00b951c:  92 02 c0 01  add  %o3, %g1, %o1
a00b9520:  d0 0a 7f f8  ldub  [ %o1 + -8 ], %o0
a00b9524:  80 a2 20 00  cmp  %o0, 0
a00b9528:  02 80 00 08  be  0xa00b9548
a00b952c:  94 03 3f ff  add  %o4, -1, %o2
a00b9530:  98 03 20 01  inc  %o4
a00b9534:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b9538:  80 a0 60 03  cmp  %g1, 3
a00b953c:  28 bf ff f9  bleu,a   0xa00b9520
a00b9540:  92 02 c0 01  add  %o3, %g1, %o1
a00b9544:  94 03 3f ff  add  %o4, -1, %o2
a00b9548:  d4 2f bf f0  stb  %o2, [ %fp + -16 ]
a00b954c:  98 10 00 11  mov  %l1, %o4
a00b9550:  90 10 20 00  clr  %o0
a00b9554:  92 10 20 0a  mov  0xa, %o1
a00b9558:  10 bf ff ca  b  0xa00b9480
a00b955c:  94 10 20 06  mov  6, %o2
a00b9560:  e8 03 60 ac  ld  [ %o5 + 0xac ], %l4
a00b9564:  91 35 20 16  srl  %l4, 0x16, %o0
a00b9568:  10 bf ff ce  b  0xa00b94a0
a00b956c:  90 0a 20 01  and  %o0, 1, %o0
a00b9570:  7f ff ad 30  call  0xa00a4a30
a00b9574:  d0 0b 60 4a  ldub  [ %o5 + 0x4a ], %o0
a00b9578:  10 bf ff cc  b  0xa00b94a8
a00b957c:  a0 14 e2 90  or  %l3, 0x290, %l0
a00b9580:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a00b9584:  10 bf ff a4  b  0xa00b9414
a00b9588:  83 33 20 0c  srl  %o4, 0xc, %g1
a00b958c:  d6 0c 20 4a  ldub  [ %l0 + 0x4a ], %o3
a00b9590:  15 2a 00 97  sethi  %hi(0xa8025c00), %o2
a00b9594:  10 bf ff a3  b  0xa00b9420
a00b9598:  d6 2a a0 56  stb  %o3, [ %o2 + 0x56 ]	! 0xa8025c56
a00b959c:  d8 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o4
a00b95a0:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00b95a4:  91 33 20 02  srl  %o4, 2, %o0
a00b95a8:  7f ff fd 07  call  0xa00b89c4
a00b95ac:  d8 28 60 56  stb  %o4, [ %g1 + 0x56 ]
a00b95b0:  10 bf ff 15  b  0xa00b9204
a00b95b4:  d0 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o0
a00b95b8:  d6 0c 20 1f  ldub  [ %l0 + 0x1f ], %o3
a00b95bc:  25 2a 00 97  sethi  %hi(0xa8025c00), %l2
a00b95c0:  d6 2c a0 56  stb  %o3, [ %l2 + 0x56 ]	! 0xa8025c56
a00b95c4:  d6 2c 21 a3  stb  %o3, [ %l0 + 0x1a3 ]
a00b95c8:  a4 10 00 10  mov  %l0, %l2
a00b95cc:  a2 10 20 00  clr  %l1
a00b95d0:  a0 10 20 00  clr  %l0
a00b95d4:  29 00 06 59  sethi  %hi(0x196400), %l4
a00b95d8:  97 2c 20 03  sll  %l0, 3, %o3
a00b95dc:  94 22 c0 10  sub  %o3, %l0, %o2
a00b95e0:  93 2a a0 02  sll  %o2, 2, %o1
a00b95e4:  90 02 40 10  add  %o1, %l0, %o0
a00b95e8:  c2 0c a0 08  ldub  [ %l2 + 8 ], %g1
a00b95ec:  98 02 00 01  add  %o0, %g1, %o4
a00b95f0:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00b95f4:  93 33 60 10  srl  %o5, 0x10, %o1
a00b95f8:  7f ff a8 93  call  0xa00a3844
a00b95fc:  90 15 22 78  or  %l4, 0x278, %o0
a00b9600:  9e 04 00 10  add  %l0, %l0, %o7
a00b9604:  98 10 00 08  mov  %o0, %o4
a00b9608:  94 03 e0 05  add  %o7, 5, %o2
a00b960c:  90 10 20 00  clr  %o0
a00b9610:  92 10 20 06  mov  6, %o1
a00b9614:  96 10 20 0a  mov  0xa, %o3
a00b9618:  9a 10 20 00  clr  %o5
a00b961c:  7f ff a6 e2  call  0xa00a31a4
a00b9620:  a2 04 60 01  inc  %l1
a00b9624:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b9628:  80 a4 20 02  cmp  %l0, 2
a00b962c:  08 bf ff ec  bleu  0xa00b95dc
a00b9630:  97 2c 20 03  sll  %l0, 3, %o3
a00b9634:  d0 0c a0 1f  ldub  [ %l2 + 0x1f ], %o0
a00b9638:  7f ff d0 8d  call  0xa00ad86c
a00b963c:  92 10 20 01  mov  1, %o1
a00b9640:  d0 0c a0 1f  ldub  [ %l2 + 0x1f ], %o0
a00b9644:  7f ff d0 8a  call  0xa00ad86c
a00b9648:  92 10 20 00  clr  %o1
a00b964c:  da 0c a0 1f  ldub  [ %l2 + 0x1f ], %o5
a00b9650:  82 0b 60 ff  and  %o5, 0xff, %g1
a00b9654:  80 a0 60 03  cmp  %g1, 3
a00b9658:  38 80 00 1a  bgu,a   0xa00b96c0
a00b965c:  a8 03 7f fc  add  %o5, -4, %l4
a00b9660:  a2 00 40 01  add  %g1, %g1, %l1
a00b9664:  a0 04 60 05  add  %l1, 5, %l0
a00b9668:  a3 2c 20 10  sll  %l0, 0x10, %l1
a00b966c:  a0 10 20 00  clr  %l0
a00b9670:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b9674:  98 02 20 04  add  %o0, 4, %o4
a00b9678:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00b967c:  9e 04 20 1c  add  %l0, 0x1c, %o7
a00b9680:  93 33 60 10  srl  %o5, 0x10, %o1
a00b9684:  98 0b e0 ff  and  %o7, 0xff, %o4
a00b9688:  90 10 20 00  clr  %o0
a00b968c:  95 34 60 10  srl  %l1, 0x10, %o2
a00b9690:  96 10 20 01  mov  1, %o3
a00b9694:  9a 10 20 00  clr  %o5
a00b9698:  40 02 35 22  call  0xa0146b20
a00b969c:  a0 04 20 01  inc  %l0
a00b96a0:  a4 0c 20 ff  and  %l0, 0xff, %l2
a00b96a4:  80 a4 a0 01  cmp  %l2, 1
a00b96a8:  28 bf ff f3  bleu,a   0xa00b9674
a00b96ac:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b96b0:  10 bf fe d9  b  0xa00b9214
a00b96b4:  90 10 20 92  mov  0x92, %o0
a00b96b8:  10 bf ff 3d  b  0xa00b93ac
a00b96bc:  82 0b e0 ff  and  %o7, 0xff, %g1
a00b96c0:  10 bf ff e8  b  0xa00b9660
a00b96c4:  82 0d 20 ff  and  %l4, 0xff, %g1
a00b96c8:  7f ff 5e 36  call  0xa0090fa0
a00b96cc:  90 10 20 fc  mov  0xfc, %o0
a00b96d0:  d0 0c 21 90  ldub  [ %l0 + 0x190 ], %o0
a00b96d4:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a00b96d8:  d0 2a 60 56  stb  %o0, [ %o1 + 0x56 ]	! 0xa8025c56
a00b96dc:  7f ff d1 06  call  0xa00adaf4
a00b96e0:  d0 2c 21 8f  stb  %o0, [ %l0 + 0x18f ]
a00b96e4:  10 bf fe c8  b  0xa00b9204
a00b96e8:  d0 0c 21 8f  ldub  [ %l0 + 0x18f ], %o0
a00b96ec:  40 00 89 81  call  0xa00dbcf0
a00b96f0:  01 00 00 00  nop
a00b96f4:  10 bf fe c0  b  0xa00b91f4
a00b96f8:  d0 0c 21 82  ldub  [ %l0 + 0x182 ], %o0
a00b96fc:  d4 0c 21 5b  ldub  [ %l0 + 0x15b ], %o2
a00b9700:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a00b9704:  91 32 a0 02  srl  %o2, 2, %o0
a00b9708:  7f ff d0 9a  call  0xa00ad970
a00b970c:  d4 28 60 56  stb  %o2, [ %g1 + 0x56 ]
a00b9710:  10 bf fe bd  b  0xa00b9204
a00b9714:  d0 0c 21 5b  ldub  [ %l0 + 0x15b ], %o0
a00b9718:  a3 2a 60 10  sll  %o1, 0x10, %l1
a00b971c:  93 34 60 10  srl  %l1, 0x10, %o1
a00b9720:  7f ff a8 49  call  0xa00a3844
a00b9724:  90 14 20 b0  or  %l0, 0xb0, %o0
a00b9728:  98 10 00 08  mov  %o0, %o4
a00b972c:  90 10 20 00  clr  %o0
a00b9730:  92 10 20 0f  mov  0xf, %o1
a00b9734:  94 10 20 0f  mov  0xf, %o2
a00b9738:  96 10 20 01  mov  1, %o3
a00b973c:  7f ff a6 9a  call  0xa00a31a4
a00b9740:  9a 10 20 00  clr  %o5
a00b9744:  01 00 00 00  nop
a00b9748:  81 c7 e0 08  ret
a00b974c:  81 e8 00 00  restore
