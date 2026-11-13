# leon2m FUN_a00a900c 0xa00a900c-0xa00a93bc (944 bytes)
a00a900c:  9d e3 bf 80  save  %sp, -128, %sp
a00a9010:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a9014:  82 06 00 18  add  %i0, %i0, %g1
a00a9018:  80 a6 20 06  cmp  %i0, 6
a00a901c:  18 80 00 03  bgu  0xa00a9028
a00a9020:  b4 00 7f f7  add  %g1, -9, %i2
a00a9024:  b4 00 60 05  add  %g1, 5, %i2
a00a9028:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00a902c:  80 a6 60 01  cmp  %i1, 1
a00a9030:  02 80 00 76  be  0xa00a9208
a00a9034:  11 00 00 16  sethi  %hi(0x5800), %o0
a00a9038:  a6 12 23 9a  or  %o0, 0x39a, %l3	! 0x5b9a
a00a903c:  b0 10 2b 92  mov  0xb92, %i0
a00a9040:  a0 10 27 c2  mov  0x7c2, %l0
a00a9044:  67 ff 94 98  call  0x4008e2a4
a00a9048:  01 00 00 00  nop
a00a904c:  80 a6 60 00  cmp  %i1, 0
a00a9050:  12 80 00 20  bne  0xa00a90d0
a00a9054:  90 10 20 06  mov  6, %o0
a00a9058:  92 10 20 00  clr  %o1
a00a905c:  40 02 76 f9  call  0xa0146c40
a00a9060:  94 10 20 00  clr  %o2
a00a9064:  90 10 20 06  mov  6, %o0
a00a9068:  92 10 20 00  clr  %o1
a00a906c:  94 10 20 00  clr  %o2
a00a9070:  96 10 20 00  clr  %o3
a00a9074:  98 10 20 00  clr  %o4
a00a9078:  9a 10 20 0c  mov  0xc, %o5
a00a907c:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00a9080:  c0 23 a0 60  clr  [ %sp + 0x60 ]
a00a9084:  c0 23 a0 64  clr  [ %sp + 0x64 ]
a00a9088:  c0 23 a0 68  clr  [ %sp + 0x68 ]
a00a908c:  40 02 75 7c  call  0xa014667c
a00a9090:  c0 23 a0 6c  clr  [ %sp + 0x6c ]
a00a9094:  98 0e a0 ff  and  %i2, 0xff, %o4
a00a9098:  97 2b 20 03  sll  %o4, 3, %o3
a00a909c:  92 02 c0 0c  add  %o3, %o4, %o1
a00a90a0:  95 2a 60 02  sll  %o1, 2, %o2
a00a90a4:  98 02 a0 55  add  %o2, 0x55, %o4
a00a90a8:  90 10 20 06  mov  6, %o0
a00a90ac:  92 10 21 c8  mov  0x1c8, %o1
a00a90b0:  94 02 a0 16  add  %o2, 0x16, %o2
a00a90b4:  96 10 23 8f  mov  0x38f, %o3
a00a90b8:  40 02 75 ee  call  0xa0146870
a00a90bc:  9a 10 20 00  clr  %o5
a00a90c0:  b0 10 20 06  mov  6, %i0
a00a90c4:  b2 10 20 01  mov  1, %i1
a00a90c8:  40 02 76 de  call  0xa0146c40
a00a90cc:  95 e8 20 00  restore  %g0, 0, %o2
a00a90d0:  7f ff 9f bf  call  0xa0090fcc
a00a90d4:  01 00 00 00  nop
a00a90d8:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00a90dc:  9b 33 e0 10  srl  %o7, 0x10, %o5
a00a90e0:  80 a3 60 1d  cmp  %o5, 0x1d
a00a90e4:  18 80 00 4e  bgu  0xa00a921c
a00a90e8:  01 00 00 00  nop
a00a90ec:  7f ff 9f b8  call  0xa0090fcc
a00a90f0:  01 00 00 00  nop
a00a90f4:  91 2a 20 10  sll  %o0, 0x10, %o0
a00a90f8:  83 32 20 10  srl  %o0, 0x10, %g1
a00a90fc:  80 a0 60 22  cmp  %g1, 0x22
a00a9100:  08 80 00 0a  bleu  0xa00a9128
a00a9104:  90 10 20 06  mov  6, %o0
a00a9108:  7f ff 9f b1  call  0xa0090fcc
a00a910c:  01 00 00 00  nop
a00a9110:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a9114:  95 32 60 10  srl  %o1, 0x10, %o2
a00a9118:  80 a2 a0 25  cmp  %o2, 0x25
a00a911c:  08 80 00 07  bleu  0xa00a9138
a00a9120:  a5 2e 20 10  sll  %i0, 0x10, %l2
a00a9124:  90 10 20 06  mov  6, %o0
a00a9128:  92 10 20 00  clr  %o1
a00a912c:  40 02 76 c5  call  0xa0146c40
a00a9130:  94 10 20 00  clr  %o2
a00a9134:  a5 2e 20 10  sll  %i0, 0x10, %l2
a00a9138:  b0 0e a0 ff  and  %i2, 0xff, %i0
a00a913c:  90 10 20 14  mov  0x14, %o0
a00a9140:  92 10 00 18  mov  %i0, %o1
a00a9144:  94 10 20 11  mov  0x11, %o2
a00a9148:  97 34 a0 10  srl  %l2, 0x10, %o3
a00a914c:  98 10 20 00  clr  %o4
a00a9150:  40 02 76 4c  call  0xa0146a80
a00a9154:  a2 0e a0 ff  and  %i2, 0xff, %l1
a00a9158:  b4 04 60 01  add  %l1, 1, %i2
a00a915c:  97 2e a0 10  sll  %i2, 0x10, %o3
a00a9160:  b5 32 e0 10  srl  %o3, 0x10, %i2
a00a9164:  96 0c 27 c2  and  %l0, 0x7c2, %o3
a00a9168:  90 10 20 14  mov  0x14, %o0
a00a916c:  92 10 00 1a  mov  %i2, %o1
a00a9170:  94 10 20 11  mov  0x11, %o2
a00a9174:  40 02 76 43  call  0xa0146a80
a00a9178:  98 10 20 00  clr  %o4
a00a917c:  80 a6 60 01  cmp  %i1, 1
a00a9180:  02 80 00 5c  be  0xa00a92f0
a00a9184:  90 10 20 22  mov  0x22, %o0
a00a9188:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00a918c:  d6 08 60 8f  ldub  [ %g1 + 0x8f ], %o3	! 0xa802b08f
a00a9190:  9e 1a e0 03  xor  %o3, 3, %o7
a00a9194:  80 a0 00 0f  cmp  %g0, %o7
a00a9198:  98 40 20 00  addx  %g0, 0, %o4
a00a919c:  9a 1a e0 05  xor  %o3, 5, %o5
a00a91a0:  80 a0 00 0d  cmp  %g0, %o5
a00a91a4:  a0 40 20 00  addx  %g0, 0, %l0
a00a91a8:  80 8b 00 10  btst  %o4, %l0
a00a91ac:  02 80 00 0a  be  0xa00a91d4
a00a91b0:  90 04 60 02  add  %l1, 2, %o0
a00a91b4:  80 a2 e0 06  cmp  %o3, 6
a00a91b8:  02 80 00 07  be  0xa00a91d4
a00a91bc:  80 a2 e0 08  cmp  %o3, 8
a00a91c0:  02 80 00 05  be  0xa00a91d4
a00a91c4:  80 a6 60 01  cmp  %i1, 1
a00a91c8:  02 80 00 51  be  0xa00a930c
a00a91cc:  94 10 00 1a  mov  %i2, %o2
a00a91d0:  90 04 60 02  add  %l1, 2, %o0
a00a91d4:  a3 2a 20 10  sll  %o0, 0x10, %l1
a00a91d8:  b5 34 60 10  srl  %l1, 0x10, %i2
a00a91dc:  97 34 a0 10  srl  %l2, 0x10, %o3
a00a91e0:  90 10 20 14  mov  0x14, %o0
a00a91e4:  92 10 00 1a  mov  %i2, %o1
a00a91e8:  94 10 20 11  mov  0x11, %o2
a00a91ec:  40 02 76 25  call  0xa0146a80
a00a91f0:  98 10 20 00  clr  %o4
a00a91f4:  80 a6 60 01  cmp  %i1, 1
a00a91f8:  32 80 00 4d  bne,a   0xa00a932c
a00a91fc:  90 10 20 00  clr  %o0
a00a9200:  10 80 00 0f  b  0xa00a923c
a00a9204:  94 10 00 18  mov  %i0, %o2
a00a9208:  03 00 00 16  sethi  %hi(0x5800), %g1
a00a920c:  a6 10 60 9a  or  %g1, 0x9a, %l3	! 0x589a
a00a9210:  b0 10 23 92  mov  0x392, %i0
a00a9214:  10 bf ff 8c  b  0xa00a9044
a00a9218:  a0 10 27 42  mov  0x742, %l0
a00a921c:  7f ff 9f 6c  call  0xa0090fcc
a00a9220:  01 00 00 00  nop
a00a9224:  a5 2a 20 10  sll  %o0, 0x10, %l2
a00a9228:  a3 34 a0 10  srl  %l2, 0x10, %l1
a00a922c:  80 a4 60 22  cmp  %l1, 0x22
a00a9230:  08 bf ff c2  bleu  0xa00a9138
a00a9234:  a5 2e 20 10  sll  %i0, 0x10, %l2
a00a9238:  30 bf ff ad  b,a   0xa00a90ec
a00a923c:  90 10 20 01  mov  1, %o0
a00a9240:  92 10 20 13  mov  0x13, %o1
a00a9244:  40 00 2b 23  call  0xa00b3ed0
a00a9248:  96 10 20 13  mov  0x13, %o3
a00a924c:  93 2c e0 10  sll  %l3, 0x10, %o1
a00a9250:  94 10 20 a6  mov  0xa6, %o2
a00a9254:  a7 32 60 10  srl  %o1, 0x10, %l3
a00a9258:  d4 23 a0 5c  st  %o2, [ %sp + 0x5c ]
a00a925c:  98 10 00 18  mov  %i0, %o4
a00a9260:  90 10 20 00  clr  %o0
a00a9264:  92 10 20 01  mov  1, %o1
a00a9268:  94 10 00 13  mov  %l3, %o2
a00a926c:  96 10 20 13  mov  0x13, %o3
a00a9270:  40 00 28 1d  call  0xa00b32e4
a00a9274:  9a 10 20 03  mov  3, %o5
a00a9278:  94 10 00 18  mov  %i0, %o2
a00a927c:  90 10 20 00  clr  %o0
a00a9280:  92 10 20 14  mov  0x14, %o1
a00a9284:  96 10 20 11  mov  0x11, %o3
a00a9288:  98 10 20 30  mov  0x30, %o4
a00a928c:  40 02 76 25  call  0xa0146b20
a00a9290:  9a 10 20 00  clr  %o5
a00a9294:  94 10 00 1a  mov  %i2, %o2
a00a9298:  90 10 20 00  clr  %o0
a00a929c:  92 10 20 14  mov  0x14, %o1
a00a92a0:  96 10 20 11  mov  0x11, %o3
a00a92a4:  98 10 20 31  mov  0x31, %o4
a00a92a8:  40 02 76 1e  call  0xa0146b20
a00a92ac:  9a 10 20 00  clr  %o5
a00a92b0:  a4 10 20 a9  mov  0xa9, %l2
a00a92b4:  98 10 00 18  mov  %i0, %o4
a00a92b8:  94 10 00 13  mov  %l3, %o2
a00a92bc:  90 10 20 00  clr  %o0
a00a92c0:  92 10 20 01  mov  1, %o1
a00a92c4:  96 10 20 25  mov  0x25, %o3
a00a92c8:  9a 10 20 03  mov  3, %o5
a00a92cc:  40 00 28 06  call  0xa00b32e4
a00a92d0:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a00a92d4:  90 10 20 01  mov  1, %o0
a00a92d8:  92 10 20 01  mov  1, %o1
a00a92dc:  40 02 76 59  call  0xa0146c40
a00a92e0:  94 10 20 00  clr  %o2
a00a92e4:  b0 10 20 02  mov  2, %i0
a00a92e8:  40 02 76 56  call  0xa0146c40
a00a92ec:  95 e8 20 00  restore  %g0, 0, %o2
a00a92f0:  92 10 00 1a  mov  %i2, %o1
a00a92f4:  94 10 20 03  mov  3, %o2
a00a92f8:  96 10 23 42  mov  0x342, %o3
a00a92fc:  40 02 75 e1  call  0xa0146a80
a00a9300:  98 10 20 00  clr  %o4
a00a9304:  10 bf ff a2  b  0xa00a918c
a00a9308:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00a930c:  90 10 20 00  clr  %o0
a00a9310:  92 10 20 22  mov  0x22, %o1
a00a9314:  96 10 20 03  mov  3, %o3
a00a9318:  98 10 20 00  clr  %o4
a00a931c:  40 02 76 01  call  0xa0146b20
a00a9320:  9a 10 20 00  clr  %o5
a00a9324:  10 bf ff ac  b  0xa00a91d4
a00a9328:  90 04 60 02  add  %l1, 2, %o0
a00a932c:  92 10 20 14  mov  0x14, %o1
a00a9330:  94 10 00 18  mov  %i0, %o2
a00a9334:  96 10 20 11  mov  0x11, %o3
a00a9338:  98 10 20 32  mov  0x32, %o4
a00a933c:  40 02 75 f9  call  0xa0146b20
a00a9340:  9a 10 20 00  clr  %o5
a00a9344:  94 10 00 1a  mov  %i2, %o2
a00a9348:  90 10 20 00  clr  %o0
a00a934c:  92 10 20 14  mov  0x14, %o1
a00a9350:  96 10 20 11  mov  0x11, %o3
a00a9354:  98 10 20 33  mov  0x33, %o4
a00a9358:  9a 10 20 00  clr  %o5
a00a935c:  40 02 75 f1  call  0xa0146b20
a00a9360:  a1 2c e0 10  sll  %l3, 0x10, %l0
a00a9364:  b3 34 20 10  srl  %l0, 0x10, %i1
a00a9368:  b4 10 20 a6  mov  0xa6, %i2
a00a936c:  90 10 20 00  clr  %o0
a00a9370:  92 10 20 01  mov  1, %o1
a00a9374:  94 10 00 19  mov  %i1, %o2
a00a9378:  96 10 20 13  mov  0x13, %o3
a00a937c:  98 10 00 18  mov  %i0, %o4
a00a9380:  9a 10 20 03  mov  3, %o5
a00a9384:  40 00 27 d8  call  0xa00b32e4
a00a9388:  f4 23 a0 5c  st  %i2, [ %sp + 0x5c ]
a00a938c:  96 10 20 a9  mov  0xa9, %o3
a00a9390:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00a9394:  94 10 00 19  mov  %i1, %o2
a00a9398:  98 10 00 18  mov  %i0, %o4
a00a939c:  90 10 20 00  clr  %o0
a00a93a0:  92 10 20 01  mov  1, %o1
a00a93a4:  96 10 20 25  mov  0x25, %o3
a00a93a8:  40 00 27 cf  call  0xa00b32e4
a00a93ac:  9a 10 20 03  mov  3, %o5
a00a93b0:  01 00 00 00  nop
a00a93b4:  81 c7 e0 08  ret
a00a93b8:  81 e8 00 00  restore
