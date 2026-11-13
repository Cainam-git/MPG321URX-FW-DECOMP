# leon2m FUN_a00b4144 0xa00b4144-0xa00b5014 (3792 bytes)
a00b4144:  9d e3 bf 98  save  %sp, -104, %sp
a00b4148:  67 ff 68 57  call  0x4008e2a4
a00b414c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00b4150:  80 a6 60 02  cmp  %i1, 2
a00b4154:  02 80 01 e1  be  0xa00b48d8
a00b4158:  90 10 21 e5  mov  0x1e5, %o0
a00b415c:  40 02 4a 7d  call  0xa0146b50
a00b4160:  92 10 20 00  clr  %o1
a00b4164:  90 10 20 02  mov  2, %o0
a00b4168:  40 02 4a 81  call  0xa0146b6c
a00b416c:  92 10 20 00  clr  %o1
a00b4170:  94 10 20 04  mov  4, %o2
a00b4174:  90 10 20 37  mov  0x37, %o0
a00b4178:  92 10 20 09  mov  9, %o1
a00b417c:  96 10 25 96  mov  0x596, %o3
a00b4180:  40 02 4a 40  call  0xa0146a80
a00b4184:  98 10 20 00  clr  %o4
a00b4188:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00b418c:  d0 0a a2 98  ldub  [ %o2 + 0x298 ], %o0	! 0xa802d298
a00b4190:  92 02 20 ae  add  %o0, 0xae, %o1
a00b4194:  99 2a 60 10  sll  %o1, 0x10, %o4
a00b4198:  17 00 06 4a  sethi  %hi(0x192800), %o3
a00b419c:  93 33 20 10  srl  %o4, 0x10, %o1
a00b41a0:  7f ff bd a9  call  0xa00a3844
a00b41a4:  90 12 e0 b0  or  %o3, 0xb0, %o0
a00b41a8:  98 10 00 08  mov  %o0, %o4
a00b41ac:  90 10 20 00  clr  %o0
a00b41b0:  92 10 20 37  mov  0x37, %o1
a00b41b4:  94 10 20 09  mov  9, %o2
a00b41b8:  96 10 20 04  mov  4, %o3
a00b41bc:  7f ff bb fa  call  0xa00a31a4
a00b41c0:  9a 10 20 00  clr  %o5
a00b41c4:  a6 0e 20 ff  and  %i0, 0xff, %l3
a00b41c8:  82 04 c0 13  add  %l3, %l3, %g1
a00b41cc:  80 a4 e0 06  cmp  %l3, 6
a00b41d0:  18 80 00 03  bgu  0xa00b41dc
a00b41d4:  a8 00 7f f7  add  %g1, -9, %l4
a00b41d8:  a8 00 60 05  add  %g1, 5, %l4
a00b41dc:  80 a6 60 01  cmp  %i1, 1
a00b41e0:  02 80 01 ad  be  0xa00b4894
a00b41e4:  2f 00 00 1d  sethi  %hi(0x7400), %l7
a00b41e8:  2d 00 00 1f  sethi  %hi(0x7c00), %l6
a00b41ec:  a0 06 3f fa  add  %i0, -6, %l0
a00b41f0:  ba 0c 20 ff  and  %l0, 0xff, %i5
a00b41f4:  a4 15 e1 ca  or  %l7, 0x1ca, %l2
a00b41f8:  a2 15 a1 9a  or  %l6, 0x19a, %l1
a00b41fc:  80 a7 60 01  cmp  %i5, 1
a00b4200:  ae 10 2b 92  mov  0xb92, %l7
a00b4204:  18 80 01 24  bgu  0xa00b4694
a00b4208:  ac 10 27 c2  mov  0x7c2, %l6
a00b420c:  03 00 00 16  sethi  %hi(0x5800), %g1
a00b4210:  ba 10 63 9a  or  %g1, 0x39a, %i5	! 0x5b9a
a00b4214:  67 ff 68 24  call  0x4008e2a4
a00b4218:  01 00 00 00  nop
a00b421c:  67 ff 68 22  call  0x4008e2a4
a00b4220:  01 00 00 00  nop
a00b4224:  80 a6 60 01  cmp  %i1, 1
a00b4228:  02 80 01 8c  be  0xa00b4858
a00b422c:  b0 0d 20 ff  and  %l4, 0xff, %i0
a00b4230:  7f ff 73 67  call  0xa0090fcc
a00b4234:  01 00 00 00  nop
a00b4238:  95 2a 20 10  sll  %o0, 0x10, %o2
a00b423c:  91 32 a0 10  srl  %o2, 0x10, %o0
a00b4240:  80 a2 20 91  cmp  %o0, 0x91
a00b4244:  08 80 00 0a  bleu  0xa00b426c
a00b4248:  90 10 20 00  clr  %o0
a00b424c:  7f ff 73 60  call  0xa0090fcc
a00b4250:  01 00 00 00  nop
a00b4254:  99 2a 20 10  sll  %o0, 0x10, %o4
a00b4258:  97 33 20 10  srl  %o4, 0x10, %o3
a00b425c:  80 a2 e0 ae  cmp  %o3, 0xae
a00b4260:  08 80 00 09  bleu  0xa00b4284
a00b4264:  aa 0c 20 ff  and  %l0, 0xff, %l5
a00b4268:  90 10 20 00  clr  %o0
a00b426c:  92 10 20 00  clr  %o1
a00b4270:  94 10 20 00  clr  %o2
a00b4274:  7f ff ff 17  call  0xa00b3ed0
a00b4278:  96 10 20 00  clr  %o3
a00b427c:  b0 0d 20 ff  and  %l4, 0xff, %i0
a00b4280:  aa 0c 20 ff  and  %l0, 0xff, %l5
a00b4284:  80 a5 60 02  cmp  %l5, 2
a00b4288:  9e 60 20 00  subx  %g0, 0, %o7
a00b428c:  80 a0 00 13  cmp  %g0, %l3
a00b4290:  9a 0b e0 01  and  %o7, 1, %o5
a00b4294:  a0 60 3f ff  subx  %g0, -1, %l0
a00b4298:  80 93 40 10  orcc  %o5, %l0, %g0
a00b429c:  12 80 01 1e  bne  0xa00b4714
a00b42a0:  96 1c e0 01  xor  %l3, 1, %o3
a00b42a4:  80 a0 00 0b  cmp  %g0, %o3
a00b42a8:  90 40 20 00  addx  %g0, 0, %o0
a00b42ac:  94 1c e0 08  xor  %l3, 8, %o2
a00b42b0:  80 a0 00 0a  cmp  %g0, %o2
a00b42b4:  92 40 20 00  addx  %g0, 0, %o1
a00b42b8:  80 8a 00 09  btst  %o0, %o1
a00b42bc:  02 80 00 f9  be  0xa00b46a0
a00b42c0:  80 a4 e0 08  cmp  %l3, 8
a00b42c4:  80 a6 60 01  cmp  %i1, 1
a00b42c8:  02 80 02 20  be  0xa00b4b48
a00b42cc:  90 0d eb 92  and  %l7, 0xb92, %o0
a00b42d0:  40 02 49 f8  call  0xa0146ab0
a00b42d4:  92 10 20 00  clr  %o1
a00b42d8:  a0 10 20 00  clr  %l0
a00b42dc:  94 0c 20 ff  and  %l0, 0xff, %o2
a00b42e0:  90 02 a0 02  add  %o2, 2, %o0
a00b42e4:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b42e8:  93 32 60 10  srl  %o1, 0x10, %o1
a00b42ec:  90 10 20 01  mov  1, %o0
a00b42f0:  94 10 00 18  mov  %i0, %o2
a00b42f4:  96 10 20 01  mov  1, %o3
a00b42f8:  98 10 20 32  mov  0x32, %o4
a00b42fc:  40 02 4a 09  call  0xa0146b20
a00b4300:  9a 10 20 00  clr  %o5
a00b4304:  a0 04 20 01  inc  %l0
a00b4308:  82 0c 20 ff  and  %l0, 0xff, %g1
a00b430c:  80 a0 60 03  cmp  %g1, 3
a00b4310:  0a bf ff f4  bcs  0xa00b42e0
a00b4314:  94 0c 20 ff  and  %l0, 0xff, %o2
a00b4318:  90 0d 20 ff  and  %l4, 0xff, %o0
a00b431c:  92 02 20 01  add  %o0, 1, %o1
a00b4320:  83 2a 60 10  sll  %o1, 0x10, %g1
a00b4324:  a1 30 60 10  srl  %g1, 0x10, %l0
a00b4328:  ab 2c a0 10  sll  %l2, 0x10, %l5
a00b432c:  97 35 60 10  srl  %l5, 0x10, %o3
a00b4330:  90 10 20 02  mov  2, %o0
a00b4334:  92 10 00 10  mov  %l0, %o1
a00b4338:  94 10 20 03  mov  3, %o2
a00b433c:  40 02 49 d1  call  0xa0146a80
a00b4340:  98 10 20 00  clr  %o4
a00b4344:  92 10 00 10  mov  %l0, %o1
a00b4348:  96 0d a7 c2  and  %l6, 0x7c2, %o3
a00b434c:  90 10 20 05  mov  5, %o0
a00b4350:  94 10 20 0c  mov  0xc, %o2
a00b4354:  40 02 49 cb  call  0xa0146a80
a00b4358:  98 10 20 00  clr  %o4
a00b435c:  80 a4 e0 05  cmp  %l3, 5
a00b4360:  02 80 01 ca  be  0xa00b4a88
a00b4364:  80 a6 60 01  cmp  %i1, 1
a00b4368:  02 80 01 e2  be  0xa00b4af0
a00b436c:  a6 05 20 02  add  %l4, 2, %l3
a00b4370:  90 0d eb 92  and  %l7, 0xb92, %o0
a00b4374:  40 02 49 cf  call  0xa0146ab0
a00b4378:  92 10 20 00  clr  %o1
a00b437c:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b4380:  a2 10 20 00  clr  %l1
a00b4384:  82 0c 60 ff  and  %l1, 0xff, %g1
a00b4388:  aa 00 60 02  add  %g1, 2, %l5
a00b438c:  9f 2d 60 10  sll  %l5, 0x10, %o7
a00b4390:  9a 10 20 00  clr  %o5
a00b4394:  93 33 e0 10  srl  %o7, 0x10, %o1
a00b4398:  90 10 20 01  mov  1, %o0
a00b439c:  94 10 00 10  mov  %l0, %o2
a00b43a0:  96 10 20 01  mov  1, %o3
a00b43a4:  40 02 49 df  call  0xa0146b20
a00b43a8:  98 10 20 33  mov  0x33, %o4
a00b43ac:  a2 04 60 01  inc  %l1
a00b43b0:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00b43b4:  80 a3 60 03  cmp  %o5, 3
a00b43b8:  0a bf ff f4  bcs  0xa00b4388
a00b43bc:  82 0c 60 ff  and  %l1, 0xff, %g1
a00b43c0:  a5 2f 60 10  sll  %i5, 0x10, %l2
a00b43c4:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b43c8:  40 02 49 ba  call  0xa0146ab0
a00b43cc:  92 10 20 00  clr  %o1
a00b43d0:  a0 10 20 00  clr  %l0
a00b43d4:  ac 0c 20 ff  and  %l0, 0xff, %l6
a00b43d8:  90 05 a0 01  add  %l6, 1, %o0
a00b43dc:  bb 2a 20 10  sll  %o0, 0x10, %i5
a00b43e0:  93 37 60 10  srl  %i5, 0x10, %o1
a00b43e4:  90 10 20 01  mov  1, %o0
a00b43e8:  94 10 00 18  mov  %i0, %o2
a00b43ec:  96 10 20 01  mov  1, %o3
a00b43f0:  98 10 20 9a  mov  0x9a, %o4
a00b43f4:  40 02 49 cb  call  0xa0146b20
a00b43f8:  9a 10 20 00  clr  %o5
a00b43fc:  a0 04 20 01  inc  %l0
a00b4400:  80 8c 20 ff  btst  0xff, %l0
a00b4404:  22 bf ff f5  be,a   0xa00b43d8
a00b4408:  ac 0c 20 ff  and  %l0, 0xff, %l6
a00b440c:  80 a6 60 01  cmp  %i1, 1
a00b4410:  02 80 01 89  be  0xa00b4a34
a00b4414:  90 0d eb 92  and  %l7, 0xb92, %o0
a00b4418:  40 02 49 a6  call  0xa0146ab0
a00b441c:  92 10 20 00  clr  %o1
a00b4420:  a0 10 20 00  clr  %l0
a00b4424:  82 0c 20 ff  and  %l0, 0xff, %g1
a00b4428:  aa 00 60 05  add  %g1, 5, %l5
a00b442c:  9f 2d 60 10  sll  %l5, 0x10, %o7
a00b4430:  9a 10 20 00  clr  %o5
a00b4434:  93 33 e0 10  srl  %o7, 0x10, %o1
a00b4438:  90 10 20 01  mov  1, %o0
a00b443c:  94 10 00 18  mov  %i0, %o2
a00b4440:  96 10 20 01  mov  1, %o3
a00b4444:  40 02 49 b7  call  0xa0146b20
a00b4448:  98 10 20 32  mov  0x32, %o4
a00b444c:  a0 04 20 01  inc  %l0
a00b4450:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00b4454:  80 a3 60 0b  cmp  %o5, 0xb
a00b4458:  0a bf ff f4  bcs  0xa00b4428
a00b445c:  82 0c 20 ff  and  %l0, 0xff, %g1
a00b4460:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b4464:  40 02 49 93  call  0xa0146ab0
a00b4468:  92 10 20 00  clr  %o1
a00b446c:  a0 10 20 00  clr  %l0
a00b4470:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b4474:  ba 02 20 10  add  %o0, 0x10, %i5
a00b4478:  93 2f 60 10  sll  %i5, 0x10, %o1
a00b447c:  93 32 60 10  srl  %o1, 0x10, %o1
a00b4480:  90 10 20 01  mov  1, %o0
a00b4484:  94 10 00 18  mov  %i0, %o2
a00b4488:  96 10 20 01  mov  1, %o3
a00b448c:  98 10 20 9c  mov  0x9c, %o4
a00b4490:  40 02 49 a4  call  0xa0146b20
a00b4494:  9a 10 20 00  clr  %o5
a00b4498:  a0 04 20 01  inc  %l0
a00b449c:  80 8c 20 ff  btst  0xff, %l0
a00b44a0:  02 bf ff f5  be  0xa00b4474
a00b44a4:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b44a8:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b44ac:  40 02 49 81  call  0xa0146ab0
a00b44b0:  92 10 20 00  clr  %o1
a00b44b4:  a0 10 20 00  clr  %l0
a00b44b8:  96 0c 20 ff  and  %l0, 0xff, %o3
a00b44bc:  94 02 e0 11  add  %o3, 0x11, %o2
a00b44c0:  ad 2a a0 10  sll  %o2, 0x10, %l6
a00b44c4:  93 35 a0 10  srl  %l6, 0x10, %o1
a00b44c8:  90 10 20 01  mov  1, %o0
a00b44cc:  94 10 00 18  mov  %i0, %o2
a00b44d0:  96 10 20 01  mov  1, %o3
a00b44d4:  98 10 20 9d  mov  0x9d, %o4
a00b44d8:  40 02 49 92  call  0xa0146b20
a00b44dc:  9a 10 20 00  clr  %o5
a00b44e0:  a0 04 20 01  inc  %l0
a00b44e4:  80 8c 20 ff  btst  0xff, %l0
a00b44e8:  02 bf ff f5  be  0xa00b44bc
a00b44ec:  96 0c 20 ff  and  %l0, 0xff, %o3
a00b44f0:  a2 05 20 01  add  %l4, 1, %l1
a00b44f4:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b44f8:  40 02 49 6e  call  0xa0146ab0
a00b44fc:  92 10 20 00  clr  %o1
a00b4500:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b4504:  b0 10 20 00  clr  %i0
a00b4508:  9e 0e 20 ff  and  %i0, 0xff, %o7
a00b450c:  9a 03 e0 01  add  %o7, 1, %o5
a00b4510:  99 2b 60 10  sll  %o5, 0x10, %o4
a00b4514:  93 33 20 10  srl  %o4, 0x10, %o1
a00b4518:  90 10 20 01  mov  1, %o0
a00b451c:  94 10 00 10  mov  %l0, %o2
a00b4520:  96 10 20 01  mov  1, %o3
a00b4524:  98 10 20 9e  mov  0x9e, %o4
a00b4528:  40 02 49 7e  call  0xa0146b20
a00b452c:  9a 10 20 00  clr  %o5
a00b4530:  b0 06 20 01  inc  %i0
a00b4534:  80 8e 20 ff  btst  0xff, %i0
a00b4538:  02 bf ff f5  be  0xa00b450c
a00b453c:  9e 0e 20 ff  and  %i0, 0xff, %o7
a00b4540:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b4544:  40 02 49 5b  call  0xa0146ab0
a00b4548:  92 10 20 00  clr  %o1
a00b454c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b4550:  b0 10 20 00  clr  %i0
a00b4554:  82 0e 20 ff  and  %i0, 0xff, %g1
a00b4558:  aa 00 60 11  add  %g1, 0x11, %l5
a00b455c:  a3 2d 60 10  sll  %l5, 0x10, %l1
a00b4560:  93 34 60 10  srl  %l1, 0x10, %o1
a00b4564:  90 10 20 01  mov  1, %o0
a00b4568:  94 10 00 10  mov  %l0, %o2
a00b456c:  96 10 20 01  mov  1, %o3
a00b4570:  98 10 20 9f  mov  0x9f, %o4
a00b4574:  40 02 49 6b  call  0xa0146b20
a00b4578:  9a 10 20 00  clr  %o5
a00b457c:  b0 06 20 01  inc  %i0
a00b4580:  80 8e 20 ff  btst  0xff, %i0
a00b4584:  02 bf ff f5  be  0xa00b4558
a00b4588:  82 0e 20 ff  and  %i0, 0xff, %g1
a00b458c:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b4590:  40 02 49 48  call  0xa0146ab0
a00b4594:  92 10 20 00  clr  %o1
a00b4598:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b459c:  a2 10 20 00  clr  %l1
a00b45a0:  90 0c 60 ff  and  %l1, 0xff, %o0
a00b45a4:  ba 02 20 01  add  %o0, 1, %i5
a00b45a8:  93 2f 60 10  sll  %i5, 0x10, %o1
a00b45ac:  93 32 60 10  srl  %o1, 0x10, %o1
a00b45b0:  90 10 20 01  mov  1, %o0
a00b45b4:  94 10 00 10  mov  %l0, %o2
a00b45b8:  96 10 20 01  mov  1, %o3
a00b45bc:  98 10 20 a0  mov  0xa0, %o4
a00b45c0:  40 02 49 58  call  0xa0146b20
a00b45c4:  9a 10 20 00  clr  %o5
a00b45c8:  a2 04 60 01  inc  %l1
a00b45cc:  80 8c 60 ff  btst  0xff, %l1
a00b45d0:  02 bf ff f5  be  0xa00b45a4
a00b45d4:  90 0c 60 ff  and  %l1, 0xff, %o0
a00b45d8:  80 a6 60 01  cmp  %i1, 1
a00b45dc:  02 80 01 00  be  0xa00b49dc
a00b45e0:  90 0d eb 92  and  %l7, 0xb92, %o0
a00b45e4:  40 02 49 33  call  0xa0146ab0
a00b45e8:  92 10 20 00  clr  %o1
a00b45ec:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b45f0:  a2 10 20 00  clr  %l1
a00b45f4:  b0 0c 60 ff  and  %l1, 0xff, %i0
a00b45f8:  9e 06 20 05  add  %i0, 5, %o7
a00b45fc:  9b 2b e0 10  sll  %o7, 0x10, %o5
a00b4600:  93 33 60 10  srl  %o5, 0x10, %o1
a00b4604:  98 10 20 33  mov  0x33, %o4
a00b4608:  90 10 20 01  mov  1, %o0
a00b460c:  94 10 00 10  mov  %l0, %o2
a00b4610:  96 10 20 01  mov  1, %o3
a00b4614:  40 02 49 43  call  0xa0146b20
a00b4618:  9a 10 20 00  clr  %o5
a00b461c:  a2 04 60 01  inc  %l1
a00b4620:  98 0c 60 ff  and  %l1, 0xff, %o4
a00b4624:  80 a3 20 0b  cmp  %o4, 0xb
a00b4628:  0a bf ff f4  bcs  0xa00b45f8
a00b462c:  b0 0c 60 ff  and  %l1, 0xff, %i0
a00b4630:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b4634:  40 02 49 1f  call  0xa0146ab0
a00b4638:  92 10 20 00  clr  %o1
a00b463c:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b4640:  a2 10 20 00  clr  %l1
a00b4644:  92 0c 60 ff  and  %l1, 0xff, %o1
a00b4648:  82 02 60 10  add  %o1, 0x10, %g1
a00b464c:  ab 28 60 10  sll  %g1, 0x10, %l5
a00b4650:  93 35 60 10  srl  %l5, 0x10, %o1
a00b4654:  90 10 20 01  mov  1, %o0
a00b4658:  94 10 00 10  mov  %l0, %o2
a00b465c:  96 10 20 01  mov  1, %o3
a00b4660:  98 10 20 a2  mov  0xa2, %o4
a00b4664:  40 02 49 2f  call  0xa0146b20
a00b4668:  9a 10 20 00  clr  %o5
a00b466c:  a2 04 60 01  inc  %l1
a00b4670:  80 8c 60 ff  btst  0xff, %l1
a00b4674:  02 bf ff f5  be  0xa00b4648
a00b4678:  92 0c 60 ff  and  %l1, 0xff, %o1
a00b467c:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b4680:  40 02 49 0c  call  0xa0146ab0
a00b4684:  92 10 20 00  clr  %o1
a00b4688:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b468c:  10 80 02 52  b  0xa00b4fd4
a00b4690:  a2 10 20 00  clr  %l1
a00b4694:  13 00 00 1b  sethi  %hi(0x6c00), %o1
a00b4698:  10 bf fe dd  b  0xa00b420c
a00b469c:  a2 12 61 9a  or  %o1, 0x19a, %l1	! 0x6d9a
a00b46a0:  02 80 01 3e  be  0xa00b4b98
a00b46a4:  80 a4 e0 01  cmp  %l3, 1
a00b46a8:  12 bf ff 1d  bne  0xa00b431c
a00b46ac:  90 0d 20 ff  and  %l4, 0xff, %o0
a00b46b0:  80 a6 60 01  cmp  %i1, 1
a00b46b4:  02 80 01 db  be  0xa00b4e20
a00b46b8:  91 2c 60 10  sll  %l1, 0x10, %o0
a00b46bc:  91 32 20 10  srl  %o0, 0x10, %o0
a00b46c0:  40 02 48 fc  call  0xa0146ab0
a00b46c4:  92 10 20 00  clr  %o1
a00b46c8:  a0 10 20 00  clr  %l0
a00b46cc:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00b46d0:  9a 03 e0 02  add  %o7, 2, %o5
a00b46d4:  99 2b 60 10  sll  %o5, 0x10, %o4
a00b46d8:  96 04 3f 85  add  %l0, -123, %o3
a00b46dc:  93 33 20 10  srl  %o4, 0x10, %o1
a00b46e0:  98 0a e0 ff  and  %o3, 0xff, %o4
a00b46e4:  94 10 00 18  mov  %i0, %o2
a00b46e8:  90 10 20 01  mov  1, %o0
a00b46ec:  96 10 20 01  mov  1, %o3
a00b46f0:  40 02 49 0c  call  0xa0146b20
a00b46f4:  9a 10 20 00  clr  %o5
a00b46f8:  a0 04 20 01  inc  %l0
a00b46fc:  94 0c 20 ff  and  %l0, 0xff, %o2
a00b4700:  80 a2 a0 03  cmp  %o2, 3
a00b4704:  0a bf ff f3  bcs  0xa00b46d0
a00b4708:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00b470c:  10 bf ff 04  b  0xa00b431c
a00b4710:  90 0d 20 ff  and  %l4, 0xff, %o0
a00b4714:  ab 2c 60 10  sll  %l1, 0x10, %l5
a00b4718:  a5 35 60 10  srl  %l5, 0x10, %l2
a00b471c:  90 10 20 02  mov  2, %o0
a00b4720:  92 10 00 18  mov  %i0, %o1
a00b4724:  94 10 20 03  mov  3, %o2
a00b4728:  96 10 00 12  mov  %l2, %o3
a00b472c:  40 02 48 d5  call  0xa0146a80
a00b4730:  98 10 20 00  clr  %o4
a00b4734:  a2 0d 20 ff  and  %l4, 0xff, %l1
a00b4738:  82 04 60 01  add  %l1, 1, %g1
a00b473c:  93 28 60 10  sll  %g1, 0x10, %o1
a00b4740:  a1 32 60 10  srl  %o1, 0x10, %l0
a00b4744:  90 10 20 02  mov  2, %o0
a00b4748:  92 10 00 10  mov  %l0, %o1
a00b474c:  94 10 20 03  mov  3, %o2
a00b4750:  96 10 00 12  mov  %l2, %o3
a00b4754:  40 02 48 cb  call  0xa0146a80
a00b4758:  98 10 20 00  clr  %o4
a00b475c:  96 0d a7 c2  and  %l6, 0x7c2, %o3
a00b4760:  92 10 00 10  mov  %l0, %o1
a00b4764:  90 10 20 05  mov  5, %o0
a00b4768:  94 10 20 0c  mov  0xc, %o2
a00b476c:  98 10 20 00  clr  %o4
a00b4770:  40 02 48 c4  call  0xa0146a80
a00b4774:  ac 04 60 02  add  %l1, 2, %l6
a00b4778:  a3 2d a0 10  sll  %l6, 0x10, %l1
a00b477c:  93 34 60 10  srl  %l1, 0x10, %o1
a00b4780:  90 10 20 02  mov  2, %o0
a00b4784:  94 10 20 03  mov  3, %o2
a00b4788:  96 10 00 12  mov  %l2, %o3
a00b478c:  40 02 48 bd  call  0xa0146a80
a00b4790:  98 10 20 00  clr  %o4
a00b4794:  80 a4 e0 00  cmp  %l3, 0
a00b4798:  12 80 00 5f  bne  0xa00b4914
a00b479c:  80 a4 e0 06  cmp  %l3, 6
a00b47a0:  80 a6 60 01  cmp  %i1, 1
a00b47a4:  02 80 01 5d  be  0xa00b4d18
a00b47a8:  90 10 00 12  mov  %l2, %o0
a00b47ac:  40 02 48 c1  call  0xa0146ab0
a00b47b0:  92 10 20 00  clr  %o1
a00b47b4:  a0 10 20 00  clr  %l0
a00b47b8:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b47bc:  a4 02 20 02  add  %o0, 2, %l2
a00b47c0:  82 04 20 7f  add  %l0, 0x7f, %g1
a00b47c4:  a7 2c a0 10  sll  %l2, 0x10, %l3
a00b47c8:  93 34 e0 10  srl  %l3, 0x10, %o1
a00b47cc:  98 08 60 ff  and  %g1, 0xff, %o4
a00b47d0:  90 10 20 01  mov  1, %o0
a00b47d4:  94 10 00 18  mov  %i0, %o2
a00b47d8:  96 10 20 01  mov  1, %o3
a00b47dc:  9a 10 20 00  clr  %o5
a00b47e0:  40 02 48 d0  call  0xa0146b20
a00b47e4:  a0 04 20 01  inc  %l0
a00b47e8:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00b47ec:  80 a4 60 03  cmp  %l1, 3
a00b47f0:  0a bf ff f3  bcs  0xa00b47bc
a00b47f4:  90 0c 20 ff  and  %l0, 0xff, %o0
a00b47f8:  a6 05 20 02  add  %l4, 2, %l3
a00b47fc:  91 35 60 10  srl  %l5, 0x10, %o0
a00b4800:  40 02 48 ac  call  0xa0146ab0
a00b4804:  92 10 20 00  clr  %o1
a00b4808:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b480c:  a2 10 20 00  clr  %l1
a00b4810:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00b4814:  98 03 60 02  add  %o5, 2, %o4
a00b4818:  96 04 7f 82  add  %l1, -126, %o3
a00b481c:  ab 2b 20 10  sll  %o4, 0x10, %l5
a00b4820:  98 0a e0 ff  and  %o3, 0xff, %o4
a00b4824:  94 10 00 10  mov  %l0, %o2
a00b4828:  93 35 60 10  srl  %l5, 0x10, %o1
a00b482c:  90 10 20 01  mov  1, %o0
a00b4830:  96 10 20 01  mov  1, %o3
a00b4834:  40 02 48 bb  call  0xa0146b20
a00b4838:  9a 10 20 00  clr  %o5
a00b483c:  a2 04 60 01  inc  %l1
a00b4840:  94 0c 60 ff  and  %l1, 0xff, %o2
a00b4844:  80 a2 a0 03  cmp  %o2, 3
a00b4848:  0a bf ff f3  bcs  0xa00b4814
a00b484c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00b4850:  10 bf fe dd  b  0xa00b43c4
a00b4854:  a5 2f 60 10  sll  %i5, 0x10, %l2
a00b4858:  94 10 00 18  mov  %i0, %o2
a00b485c:  96 10 20 11  mov  0x11, %o3
a00b4860:  90 10 20 01  mov  1, %o0
a00b4864:  7f ff fd 9b  call  0xa00b3ed0
a00b4868:  92 10 20 01  mov  1, %o1
a00b486c:  90 10 20 01  mov  1, %o0
a00b4870:  92 10 20 01  mov  1, %o1
a00b4874:  40 02 48 f3  call  0xa0146c40
a00b4878:  94 10 20 00  clr  %o2
a00b487c:  90 10 20 02  mov  2, %o0
a00b4880:  92 10 20 01  mov  1, %o1
a00b4884:  40 02 48 ef  call  0xa0146c40
a00b4888:  94 10 20 00  clr  %o2
a00b488c:  10 bf fe 7e  b  0xa00b4284
a00b4890:  aa 0c 20 ff  and  %l0, 0xff, %l5
a00b4894:  a0 06 3f fa  add  %i0, -6, %l0
a00b4898:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00b489c:  25 2a 00 ac  sethi  %hi(0xa802b000), %l2
a00b48a0:  f0 2c a0 8f  stb  %i0, [ %l2 + 0x8f ]	! 0xa802b08f
a00b48a4:  80 a4 60 01  cmp  %l1, 1
a00b48a8:  1f 00 00 1c  sethi  %hi(0x7000), %o7
a00b48ac:  1b 00 00 1e  sethi  %hi(0x7800), %o5
a00b48b0:  a4 13 e1 4a  or  %o7, 0x14a, %l2
a00b48b4:  a2 13 61 9a  or  %o5, 0x19a, %l1
a00b48b8:  ae 10 23 92  mov  0x392, %l7
a00b48bc:  08 80 00 04  bleu  0xa00b48cc
a00b48c0:  ac 10 27 42  mov  0x742, %l6
a00b48c4:  2b 00 00 1a  sethi  %hi(0x6800), %l5
a00b48c8:  a2 15 61 9a  or  %l5, 0x19a, %l1	! 0x699a
a00b48cc:  31 00 00 16  sethi  %hi(0x5800), %i0
a00b48d0:  10 bf fe 51  b  0xa00b4214
a00b48d4:  ba 16 20 9a  or  %i0, 0x9a, %i5	! 0x589a
a00b48d8:  40 02 48 9e  call  0xa0146b50
a00b48dc:  92 10 20 00  clr  %o1
a00b48e0:  90 10 20 02  mov  2, %o0
a00b48e4:  40 02 48 a2  call  0xa0146b6c
a00b48e8:  92 10 20 00  clr  %o1
a00b48ec:  92 10 20 09  mov  9, %o1
a00b48f0:  94 10 20 04  mov  4, %o2
a00b48f4:  96 10 25 96  mov  0x596, %o3
a00b48f8:  98 10 20 00  clr  %o4
a00b48fc:  40 02 48 61  call  0xa0146a80
a00b4900:  90 10 20 37  mov  0x37, %o0
a00b4904:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00b4908:  d2 08 62 98  ldub  [ %g1 + 0x298 ], %o1	! 0xa802d298
a00b490c:  10 bf fe 22  b  0xa00b4194
a00b4910:  92 02 60 cb  add  %o1, 0xcb, %o1
a00b4914:  02 80 00 d3  be  0xa00b4c60
a00b4918:  80 a4 e0 07  cmp  %l3, 7
a00b491c:  12 bf fe a9  bne  0xa00b43c0
a00b4920:  a6 05 20 02  add  %l4, 2, %l3
a00b4924:  80 a6 60 01  cmp  %i1, 1
a00b4928:  02 80 01 80  be  0xa00b4f28
a00b492c:  90 10 00 12  mov  %l2, %o0
a00b4930:  40 02 48 60  call  0xa0146ab0
a00b4934:  92 10 20 00  clr  %o1
a00b4938:  a0 10 20 00  clr  %l0
a00b493c:  a6 0c 20 ff  and  %l0, 0xff, %l3
a00b4940:  98 04 e0 02  add  %l3, 2, %o4
a00b4944:  96 04 3f 91  add  %l0, -111, %o3
a00b4948:  a3 2b 20 10  sll  %o4, 0x10, %l1
a00b494c:  98 0a e0 ff  and  %o3, 0xff, %o4
a00b4950:  94 10 00 18  mov  %i0, %o2
a00b4954:  93 34 60 10  srl  %l1, 0x10, %o1
a00b4958:  90 10 20 01  mov  1, %o0
a00b495c:  96 10 20 01  mov  1, %o3
a00b4960:  40 02 48 70  call  0xa0146b20
a00b4964:  9a 10 20 00  clr  %o5
a00b4968:  a0 04 20 01  inc  %l0
a00b496c:  94 0c 20 ff  and  %l0, 0xff, %o2
a00b4970:  80 a2 a0 03  cmp  %o2, 3
a00b4974:  0a bf ff f3  bcs  0xa00b4940
a00b4978:  a6 0c 20 ff  and  %l0, 0xff, %l3
a00b497c:  a6 05 20 02  add  %l4, 2, %l3
a00b4980:  91 35 60 10  srl  %l5, 0x10, %o0
a00b4984:  40 02 48 4b  call  0xa0146ab0
a00b4988:  92 10 20 00  clr  %o1
a00b498c:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b4990:  a2 10 20 00  clr  %l1
a00b4994:  82 0c 60 ff  and  %l1, 0xff, %g1
a00b4998:  ac 00 60 02  add  %g1, 2, %l6
a00b499c:  9e 04 7f 94  add  %l1, -108, %o7
a00b49a0:  ab 2d a0 10  sll  %l6, 0x10, %l5
a00b49a4:  9a 10 20 00  clr  %o5
a00b49a8:  93 35 60 10  srl  %l5, 0x10, %o1
a00b49ac:  98 0b e0 ff  and  %o7, 0xff, %o4
a00b49b0:  90 10 20 01  mov  1, %o0
a00b49b4:  94 10 00 10  mov  %l0, %o2
a00b49b8:  40 02 48 5a  call  0xa0146b20
a00b49bc:  96 10 20 01  mov  1, %o3
a00b49c0:  a2 04 60 01  inc  %l1
a00b49c4:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00b49c8:  80 a3 60 03  cmp  %o5, 3
a00b49cc:  0a bf ff f3  bcs  0xa00b4998
a00b49d0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00b49d4:  10 bf fe 7c  b  0xa00b43c4
a00b49d8:  a5 2f 60 10  sll  %i5, 0x10, %l2
a00b49dc:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b49e0:  40 02 48 34  call  0xa0146ab0
a00b49e4:  92 10 20 00  clr  %o1
a00b49e8:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b49ec:  a2 10 20 00  clr  %l1
a00b49f0:  96 0c 60 ff  and  %l1, 0xff, %o3
a00b49f4:  94 02 e0 05  add  %o3, 5, %o2
a00b49f8:  ad 2a a0 10  sll  %o2, 0x10, %l6
a00b49fc:  93 35 a0 10  srl  %l6, 0x10, %o1
a00b4a00:  90 10 20 01  mov  1, %o0
a00b4a04:  94 10 00 10  mov  %l0, %o2
a00b4a08:  96 10 20 01  mov  1, %o3
a00b4a0c:  98 10 20 a1  mov  0xa1, %o4
a00b4a10:  9a 10 20 00  clr  %o5
a00b4a14:  40 02 48 43  call  0xa0146b20
a00b4a18:  a2 04 60 01  inc  %l1
a00b4a1c:  ae 0c 60 ff  and  %l1, 0xff, %l7
a00b4a20:  80 a5 e0 0b  cmp  %l7, 0xb
a00b4a24:  0a bf ff f4  bcs  0xa00b49f4
a00b4a28:  96 0c 60 ff  and  %l1, 0xff, %o3
a00b4a2c:  10 bf ff 02  b  0xa00b4634
a00b4a30:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b4a34:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b4a38:  40 02 48 1e  call  0xa0146ab0
a00b4a3c:  92 10 20 00  clr  %o1
a00b4a40:  a0 10 20 00  clr  %l0
a00b4a44:  98 0c 20 ff  and  %l0, 0xff, %o4
a00b4a48:  a2 03 20 05  add  %o4, 5, %l1
a00b4a4c:  97 2c 60 10  sll  %l1, 0x10, %o3
a00b4a50:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b4a54:  94 10 00 18  mov  %i0, %o2
a00b4a58:  90 10 20 01  mov  1, %o0
a00b4a5c:  96 10 20 01  mov  1, %o3
a00b4a60:  98 10 20 9b  mov  0x9b, %o4
a00b4a64:  40 02 48 2f  call  0xa0146b20
a00b4a68:  9a 10 20 00  clr  %o5
a00b4a6c:  a0 04 20 01  inc  %l0
a00b4a70:  94 0c 20 ff  and  %l0, 0xff, %o2
a00b4a74:  80 a2 a0 0b  cmp  %o2, 0xb
a00b4a78:  0a bf ff f4  bcs  0xa00b4a48
a00b4a7c:  98 0c 20 ff  and  %l0, 0xff, %o4
a00b4a80:  10 bf fe 79  b  0xa00b4464
a00b4a84:  91 34 a0 10  srl  %l2, 0x10, %o0
a00b4a88:  02 80 00 5d  be  0xa00b4bfc
a00b4a8c:  99 2c 60 10  sll  %l1, 0x10, %o4
a00b4a90:  a6 05 20 02  add  %l4, 2, %l3
a00b4a94:  91 33 20 10  srl  %o4, 0x10, %o0
a00b4a98:  40 02 48 06  call  0xa0146ab0
a00b4a9c:  92 10 20 00  clr  %o1
a00b4aa0:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b4aa4:  a2 10 20 00  clr  %l1
a00b4aa8:  92 0c 60 ff  and  %l1, 0xff, %o1
a00b4aac:  82 02 60 02  add  %o1, 2, %g1
a00b4ab0:  9e 04 7f 8e  add  %l1, -114, %o7
a00b4ab4:  ab 28 60 10  sll  %g1, 0x10, %l5
a00b4ab8:  9a 10 20 00  clr  %o5
a00b4abc:  93 35 60 10  srl  %l5, 0x10, %o1
a00b4ac0:  98 0b e0 ff  and  %o7, 0xff, %o4
a00b4ac4:  90 10 20 01  mov  1, %o0
a00b4ac8:  94 10 00 10  mov  %l0, %o2
a00b4acc:  40 02 48 15  call  0xa0146b20
a00b4ad0:  96 10 20 01  mov  1, %o3
a00b4ad4:  a2 04 60 01  inc  %l1
a00b4ad8:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00b4adc:  80 a3 60 03  cmp  %o5, 3
a00b4ae0:  0a bf ff f3  bcs  0xa00b4aac
a00b4ae4:  92 0c 60 ff  and  %l1, 0xff, %o1
a00b4ae8:  10 bf fe 37  b  0xa00b43c4
a00b4aec:  a5 2f 60 10  sll  %i5, 0x10, %l2
a00b4af0:  90 0d eb 92  and  %l7, 0xb92, %o0
a00b4af4:  40 02 47 ef  call  0xa0146ab0
a00b4af8:  92 10 20 00  clr  %o1
a00b4afc:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b4b00:  a2 10 20 00  clr  %l1
a00b4b04:  98 0c 60 ff  and  %l1, 0xff, %o4
a00b4b08:  96 03 20 02  add  %o4, 2, %o3
a00b4b0c:  95 2a e0 10  sll  %o3, 0x10, %o2
a00b4b10:  93 32 a0 10  srl  %o2, 0x10, %o1
a00b4b14:  90 10 20 01  mov  1, %o0
a00b4b18:  94 10 00 10  mov  %l0, %o2
a00b4b1c:  96 10 20 01  mov  1, %o3
a00b4b20:  98 10 20 31  mov  0x31, %o4
a00b4b24:  9a 10 20 00  clr  %o5
a00b4b28:  40 02 47 fe  call  0xa0146b20
a00b4b2c:  a2 04 60 01  inc  %l1
a00b4b30:  ac 0c 60 ff  and  %l1, 0xff, %l6
a00b4b34:  80 a5 a0 03  cmp  %l6, 3
a00b4b38:  0a bf ff f4  bcs  0xa00b4b08
a00b4b3c:  98 0c 60 ff  and  %l1, 0xff, %o4
a00b4b40:  10 bf fe 21  b  0xa00b43c4
a00b4b44:  a5 2f 60 10  sll  %i5, 0x10, %l2
a00b4b48:  40 02 47 da  call  0xa0146ab0
a00b4b4c:  92 10 20 00  clr  %o1
a00b4b50:  a0 10 20 00  clr  %l0
a00b4b54:  aa 0c 20 ff  and  %l0, 0xff, %l5
a00b4b58:  9e 05 60 02  add  %l5, 2, %o7
a00b4b5c:  9b 2b e0 10  sll  %o7, 0x10, %o5
a00b4b60:  93 33 60 10  srl  %o5, 0x10, %o1
a00b4b64:  98 10 20 30  mov  0x30, %o4
a00b4b68:  90 10 20 01  mov  1, %o0
a00b4b6c:  94 10 00 18  mov  %i0, %o2
a00b4b70:  96 10 20 01  mov  1, %o3
a00b4b74:  40 02 47 eb  call  0xa0146b20
a00b4b78:  9a 10 20 00  clr  %o5
a00b4b7c:  a0 04 20 01  inc  %l0
a00b4b80:  98 0c 20 ff  and  %l0, 0xff, %o4
a00b4b84:  80 a3 20 03  cmp  %o4, 3
a00b4b88:  0a bf ff f4  bcs  0xa00b4b58
a00b4b8c:  aa 0c 20 ff  and  %l0, 0xff, %l5
a00b4b90:  10 bf fd e3  b  0xa00b431c
a00b4b94:  90 0d 20 ff  and  %l4, 0xff, %o0
a00b4b98:  80 a6 60 01  cmp  %i1, 1
a00b4b9c:  02 80 00 8a  be  0xa00b4dc4
a00b4ba0:  83 2c 60 10  sll  %l1, 0x10, %g1
a00b4ba4:  91 30 60 10  srl  %g1, 0x10, %o0
a00b4ba8:  40 02 47 c2  call  0xa0146ab0
a00b4bac:  92 10 20 00  clr  %o1
a00b4bb0:  a0 10 20 00  clr  %l0
a00b4bb4:  98 0c 20 ff  and  %l0, 0xff, %o4
a00b4bb8:  96 03 20 02  add  %o4, 2, %o3
a00b4bbc:  95 2a e0 10  sll  %o3, 0x10, %o2
a00b4bc0:  90 04 3f 97  add  %l0, -105, %o0
a00b4bc4:  93 32 a0 10  srl  %o2, 0x10, %o1
a00b4bc8:  98 0a 20 ff  and  %o0, 0xff, %o4
a00b4bcc:  90 10 20 01  mov  1, %o0
a00b4bd0:  94 10 00 18  mov  %i0, %o2
a00b4bd4:  96 10 20 01  mov  1, %o3
a00b4bd8:  40 02 47 d2  call  0xa0146b20
a00b4bdc:  9a 10 20 00  clr  %o5
a00b4be0:  a0 04 20 01  inc  %l0
a00b4be4:  92 0c 20 ff  and  %l0, 0xff, %o1
a00b4be8:  80 a2 60 03  cmp  %o1, 3
a00b4bec:  0a bf ff f3  bcs  0xa00b4bb8
a00b4bf0:  98 0c 20 ff  and  %l0, 0xff, %o4
a00b4bf4:  10 bf fd ca  b  0xa00b431c
a00b4bf8:  90 0d 20 ff  and  %l4, 0xff, %o0
a00b4bfc:  93 2c 60 10  sll  %l1, 0x10, %o1
a00b4c00:  91 32 60 10  srl  %o1, 0x10, %o0
a00b4c04:  a6 05 20 02  add  %l4, 2, %l3
a00b4c08:  40 02 47 aa  call  0xa0146ab0
a00b4c0c:  92 10 20 00  clr  %o1
a00b4c10:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b4c14:  a2 10 20 00  clr  %l1
a00b4c18:  96 0c 60 ff  and  %l1, 0xff, %o3
a00b4c1c:  94 02 e0 02  add  %o3, 2, %o2
a00b4c20:  ad 2a a0 10  sll  %o2, 0x10, %l6
a00b4c24:  a4 04 60 6d  add  %l1, 0x6d, %l2
a00b4c28:  90 10 20 01  mov  1, %o0
a00b4c2c:  93 35 a0 10  srl  %l6, 0x10, %o1
a00b4c30:  98 0c a0 ff  and  %l2, 0xff, %o4
a00b4c34:  94 10 00 10  mov  %l0, %o2
a00b4c38:  96 10 20 01  mov  1, %o3
a00b4c3c:  40 02 47 b9  call  0xa0146b20
a00b4c40:  9a 10 20 00  clr  %o5
a00b4c44:  a2 04 60 01  inc  %l1
a00b4c48:  90 0c 60 ff  and  %l1, 0xff, %o0
a00b4c4c:  80 a2 20 03  cmp  %o0, 3
a00b4c50:  0a bf ff f3  bcs  0xa00b4c1c
a00b4c54:  96 0c 60 ff  and  %l1, 0xff, %o3
a00b4c58:  10 bf fd db  b  0xa00b43c4
a00b4c5c:  a5 2f 60 10  sll  %i5, 0x10, %l2
a00b4c60:  80 a6 60 01  cmp  %i1, 1
a00b4c64:  02 80 00 86  be  0xa00b4e7c
a00b4c68:  90 10 00 12  mov  %l2, %o0
a00b4c6c:  40 02 47 91  call  0xa0146ab0
a00b4c70:  92 10 20 00  clr  %o1
a00b4c74:  a0 10 20 00  clr  %l0
a00b4c78:  92 0c 20 ff  and  %l0, 0xff, %o1
a00b4c7c:  9a 04 3f 88  add  %l0, -120, %o5
a00b4c80:  ac 02 60 02  add  %o1, 2, %l6
a00b4c84:  9f 2d a0 10  sll  %l6, 0x10, %o7
a00b4c88:  98 0b 60 ff  and  %o5, 0xff, %o4
a00b4c8c:  93 33 e0 10  srl  %o7, 0x10, %o1
a00b4c90:  90 10 20 01  mov  1, %o0
a00b4c94:  94 10 00 18  mov  %i0, %o2
a00b4c98:  96 10 20 01  mov  1, %o3
a00b4c9c:  9a 10 20 00  clr  %o5
a00b4ca0:  40 02 47 a0  call  0xa0146b20
a00b4ca4:  a0 04 20 01  inc  %l0
a00b4ca8:  a6 0c 20 ff  and  %l0, 0xff, %l3
a00b4cac:  80 a4 e0 03  cmp  %l3, 3
a00b4cb0:  0a bf ff f3  bcs  0xa00b4c7c
a00b4cb4:  92 0c 20 ff  and  %l0, 0xff, %o1
a00b4cb8:  a6 05 20 02  add  %l4, 2, %l3
a00b4cbc:  91 35 60 10  srl  %l5, 0x10, %o0
a00b4cc0:  40 02 47 7c  call  0xa0146ab0
a00b4cc4:  92 10 20 00  clr  %o1
a00b4cc8:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b4ccc:  a2 10 20 00  clr  %l1
a00b4cd0:  96 0c 60 ff  and  %l1, 0xff, %o3
a00b4cd4:  94 02 e0 02  add  %o3, 2, %o2
a00b4cd8:  91 2a a0 10  sll  %o2, 0x10, %o0
a00b4cdc:  a4 04 7f 8b  add  %l1, -117, %l2
a00b4ce0:  93 32 20 10  srl  %o0, 0x10, %o1
a00b4ce4:  98 0c a0 ff  and  %l2, 0xff, %o4
a00b4ce8:  90 10 20 01  mov  1, %o0
a00b4cec:  94 10 00 10  mov  %l0, %o2
a00b4cf0:  96 10 20 01  mov  1, %o3
a00b4cf4:  40 02 47 8b  call  0xa0146b20
a00b4cf8:  9a 10 20 00  clr  %o5
a00b4cfc:  a2 04 60 01  inc  %l1
a00b4d00:  82 0c 60 ff  and  %l1, 0xff, %g1
a00b4d04:  80 a0 60 03  cmp  %g1, 3
a00b4d08:  0a bf ff f3  bcs  0xa00b4cd4
a00b4d0c:  96 0c 60 ff  and  %l1, 0xff, %o3
a00b4d10:  10 bf fd ad  b  0xa00b43c4
a00b4d14:  a5 2f 60 10  sll  %i5, 0x10, %l2
a00b4d18:  40 02 47 66  call  0xa0146ab0
a00b4d1c:  92 10 20 00  clr  %o1
a00b4d20:  a0 10 20 00  clr  %l0
a00b4d24:  96 0c 20 ff  and  %l0, 0xff, %o3
a00b4d28:  94 02 e0 02  add  %o3, 2, %o2
a00b4d2c:  91 2a a0 10  sll  %o2, 0x10, %o0
a00b4d30:  a4 04 20 49  add  %l0, 0x49, %l2
a00b4d34:  93 32 20 10  srl  %o0, 0x10, %o1
a00b4d38:  98 0c a0 ff  and  %l2, 0xff, %o4
a00b4d3c:  90 10 20 01  mov  1, %o0
a00b4d40:  94 10 00 18  mov  %i0, %o2
a00b4d44:  96 10 20 01  mov  1, %o3
a00b4d48:  9a 10 20 00  clr  %o5
a00b4d4c:  40 02 47 75  call  0xa0146b20
a00b4d50:  a0 04 20 01  inc  %l0
a00b4d54:  a6 0c 20 ff  and  %l0, 0xff, %l3
a00b4d58:  80 a4 e0 03  cmp  %l3, 3
a00b4d5c:  0a bf ff f3  bcs  0xa00b4d28
a00b4d60:  96 0c 20 ff  and  %l0, 0xff, %o3
a00b4d64:  a6 05 20 02  add  %l4, 2, %l3
a00b4d68:  91 35 60 10  srl  %l5, 0x10, %o0
a00b4d6c:  40 02 47 51  call  0xa0146ab0
a00b4d70:  92 10 20 00  clr  %o1
a00b4d74:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b4d78:  a2 10 20 00  clr  %l1
a00b4d7c:  92 0c 60 ff  and  %l1, 0xff, %o1
a00b4d80:  9a 04 60 4f  add  %l1, 0x4f, %o5
a00b4d84:  ac 02 60 02  add  %o1, 2, %l6
a00b4d88:  98 0b 60 ff  and  %o5, 0xff, %o4
a00b4d8c:  9f 2d a0 10  sll  %l6, 0x10, %o7
a00b4d90:  93 33 e0 10  srl  %o7, 0x10, %o1
a00b4d94:  90 10 20 01  mov  1, %o0
a00b4d98:  94 10 00 10  mov  %l0, %o2
a00b4d9c:  96 10 20 01  mov  1, %o3
a00b4da0:  40 02 47 60  call  0xa0146b20
a00b4da4:  9a 10 20 00  clr  %o5
a00b4da8:  a2 04 60 01  inc  %l1
a00b4dac:  98 0c 60 ff  and  %l1, 0xff, %o4
a00b4db0:  80 a3 20 03  cmp  %o4, 3
a00b4db4:  0a bf ff f3  bcs  0xa00b4d80
a00b4db8:  92 0c 60 ff  and  %l1, 0xff, %o1
a00b4dbc:  10 bf fd 82  b  0xa00b43c4
a00b4dc0:  a5 2f 60 10  sll  %i5, 0x10, %l2
a00b4dc4:  a1 2c 60 10  sll  %l1, 0x10, %l0
a00b4dc8:  91 34 20 10  srl  %l0, 0x10, %o0
a00b4dcc:  40 02 47 39  call  0xa0146ab0
a00b4dd0:  92 10 20 00  clr  %o1
a00b4dd4:  a0 10 20 00  clr  %l0
a00b4dd8:  aa 0c 20 ff  and  %l0, 0xff, %l5
a00b4ddc:  9e 05 60 02  add  %l5, 2, %o7
a00b4de0:  9b 2b e0 10  sll  %o7, 0x10, %o5
a00b4de4:  98 04 20 79  add  %l0, 0x79, %o4
a00b4de8:  93 33 60 10  srl  %o5, 0x10, %o1
a00b4dec:  96 10 20 01  mov  1, %o3
a00b4df0:  98 0b 20 ff  and  %o4, 0xff, %o4
a00b4df4:  90 10 20 01  mov  1, %o0
a00b4df8:  94 10 00 18  mov  %i0, %o2
a00b4dfc:  40 02 47 49  call  0xa0146b20
a00b4e00:  9a 10 20 00  clr  %o5
a00b4e04:  a0 04 20 01  inc  %l0
a00b4e08:  96 0c 20 ff  and  %l0, 0xff, %o3
a00b4e0c:  80 a2 e0 03  cmp  %o3, 3
a00b4e10:  0a bf ff f3  bcs  0xa00b4ddc
a00b4e14:  aa 0c 20 ff  and  %l0, 0xff, %l5
a00b4e18:  10 bf fd 41  b  0xa00b431c
a00b4e1c:  90 0d 20 ff  and  %l4, 0xff, %o0
a00b4e20:  a1 2c 60 10  sll  %l1, 0x10, %l0
a00b4e24:  91 34 20 10  srl  %l0, 0x10, %o0
a00b4e28:  40 02 47 22  call  0xa0146ab0
a00b4e2c:  92 10 20 00  clr  %o1
a00b4e30:  a0 10 20 00  clr  %l0
a00b4e34:  92 0c 20 ff  and  %l0, 0xff, %o1
a00b4e38:  82 02 60 02  add  %o1, 2, %g1
a00b4e3c:  9e 04 20 52  add  %l0, 0x52, %o7
a00b4e40:  ab 28 60 10  sll  %g1, 0x10, %l5
a00b4e44:  9a 10 20 00  clr  %o5
a00b4e48:  93 35 60 10  srl  %l5, 0x10, %o1
a00b4e4c:  98 0b e0 ff  and  %o7, 0xff, %o4
a00b4e50:  90 10 20 01  mov  1, %o0
a00b4e54:  94 10 00 18  mov  %i0, %o2
a00b4e58:  40 02 47 32  call  0xa0146b20
a00b4e5c:  96 10 20 01  mov  1, %o3
a00b4e60:  a0 04 20 01  inc  %l0
a00b4e64:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00b4e68:  80 a3 60 03  cmp  %o5, 3
a00b4e6c:  0a bf ff f3  bcs  0xa00b4e38
a00b4e70:  92 0c 20 ff  and  %l0, 0xff, %o1
a00b4e74:  10 bf fd 2a  b  0xa00b431c
a00b4e78:  90 0d 20 ff  and  %l4, 0xff, %o0
a00b4e7c:  40 02 47 0d  call  0xa0146ab0
a00b4e80:  92 10 20 00  clr  %o1
a00b4e84:  a0 10 20 00  clr  %l0
a00b4e88:  82 0c 20 ff  and  %l0, 0xff, %g1
a00b4e8c:  a2 00 60 02  add  %g1, 2, %l1
a00b4e90:  ac 04 20 64  add  %l0, 0x64, %l6
a00b4e94:  93 2c 60 10  sll  %l1, 0x10, %o1
a00b4e98:  93 32 60 10  srl  %o1, 0x10, %o1
a00b4e9c:  98 0d a0 ff  and  %l6, 0xff, %o4
a00b4ea0:  90 10 20 01  mov  1, %o0
a00b4ea4:  94 10 00 18  mov  %i0, %o2
a00b4ea8:  96 10 20 01  mov  1, %o3
a00b4eac:  40 02 47 1d  call  0xa0146b20
a00b4eb0:  9a 10 20 00  clr  %o5
a00b4eb4:  a0 04 20 01  inc  %l0
a00b4eb8:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00b4ebc:  80 a3 e0 03  cmp  %o7, 3
a00b4ec0:  0a bf ff f3  bcs  0xa00b4e8c
a00b4ec4:  82 0c 20 ff  and  %l0, 0xff, %g1
a00b4ec8:  a6 05 20 02  add  %l4, 2, %l3
a00b4ecc:  91 35 60 10  srl  %l5, 0x10, %o0
a00b4ed0:  40 02 46 f8  call  0xa0146ab0
a00b4ed4:  92 10 20 00  clr  %o1
a00b4ed8:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b4edc:  a2 10 20 00  clr  %l1
a00b4ee0:  98 0c 60 ff  and  %l1, 0xff, %o4
a00b4ee4:  aa 03 20 02  add  %o4, 2, %l5
a00b4ee8:  94 04 60 6a  add  %l1, 0x6a, %o2
a00b4eec:  97 2d 60 10  sll  %l5, 0x10, %o3
a00b4ef0:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b4ef4:  98 0a a0 ff  and  %o2, 0xff, %o4
a00b4ef8:  90 10 20 01  mov  1, %o0
a00b4efc:  94 10 00 10  mov  %l0, %o2
a00b4f00:  96 10 20 01  mov  1, %o3
a00b4f04:  40 02 47 07  call  0xa0146b20
a00b4f08:  9a 10 20 00  clr  %o5
a00b4f0c:  a2 04 60 01  inc  %l1
a00b4f10:  90 0c 60 ff  and  %l1, 0xff, %o0
a00b4f14:  80 a2 20 03  cmp  %o0, 3
a00b4f18:  0a bf ff f3  bcs  0xa00b4ee4
a00b4f1c:  98 0c 60 ff  and  %l1, 0xff, %o4
a00b4f20:  10 bf fd 29  b  0xa00b43c4
a00b4f24:  a5 2f 60 10  sll  %i5, 0x10, %l2
a00b4f28:  40 02 46 e2  call  0xa0146ab0
a00b4f2c:  92 10 20 00  clr  %o1
a00b4f30:  a0 10 20 00  clr  %l0
a00b4f34:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00b4f38:  9a 03 e0 02  add  %o7, 2, %o5
a00b4f3c:  a7 2b 60 10  sll  %o5, 0x10, %l3
a00b4f40:  98 04 20 70  add  %l0, 0x70, %o4
a00b4f44:  93 34 e0 10  srl  %l3, 0x10, %o1
a00b4f48:  98 0b 20 ff  and  %o4, 0xff, %o4
a00b4f4c:  90 10 20 01  mov  1, %o0
a00b4f50:  94 10 00 18  mov  %i0, %o2
a00b4f54:  96 10 20 01  mov  1, %o3
a00b4f58:  9a 10 20 00  clr  %o5
a00b4f5c:  40 02 46 f1  call  0xa0146b20
a00b4f60:  a0 04 20 01  inc  %l0
a00b4f64:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00b4f68:  80 a4 60 03  cmp  %l1, 3
a00b4f6c:  0a bf ff f3  bcs  0xa00b4f38
a00b4f70:  9e 0c 20 ff  and  %l0, 0xff, %o7
a00b4f74:  a6 05 20 02  add  %l4, 2, %l3
a00b4f78:  91 35 60 10  srl  %l5, 0x10, %o0
a00b4f7c:  40 02 46 cd  call  0xa0146ab0
a00b4f80:  92 10 20 00  clr  %o1
a00b4f84:  a0 0c e0 ff  and  %l3, 0xff, %l0
a00b4f88:  a2 10 20 00  clr  %l1
a00b4f8c:  90 0c 60 ff  and  %l1, 0xff, %o0
a00b4f90:  a4 02 20 02  add  %o0, 2, %l2
a00b4f94:  82 04 60 76  add  %l1, 0x76, %g1
a00b4f98:  93 2c a0 10  sll  %l2, 0x10, %o1
a00b4f9c:  93 32 60 10  srl  %o1, 0x10, %o1
a00b4fa0:  98 08 60 ff  and  %g1, 0xff, %o4
a00b4fa4:  90 10 20 01  mov  1, %o0
a00b4fa8:  94 10 00 10  mov  %l0, %o2
a00b4fac:  96 10 20 01  mov  1, %o3
a00b4fb0:  9a 10 20 00  clr  %o5
a00b4fb4:  40 02 46 db  call  0xa0146b20
a00b4fb8:  a2 04 60 01  inc  %l1
a00b4fbc:  ac 0c 60 ff  and  %l1, 0xff, %l6
a00b4fc0:  80 a5 a0 03  cmp  %l6, 3
a00b4fc4:  0a bf ff f3  bcs  0xa00b4f90
a00b4fc8:  90 0c 60 ff  and  %l1, 0xff, %o0
a00b4fcc:  10 bf fc fe  b  0xa00b43c4
a00b4fd0:  a5 2f 60 10  sll  %i5, 0x10, %l2
a00b4fd4:  ba 0c 60 ff  and  %l1, 0xff, %i5
a00b4fd8:  a4 07 60 11  add  %i5, 0x11, %l2
a00b4fdc:  a7 2c a0 10  sll  %l2, 0x10, %l3
a00b4fe0:  93 34 e0 10  srl  %l3, 0x10, %o1
a00b4fe4:  90 10 20 01  mov  1, %o0
a00b4fe8:  94 10 00 10  mov  %l0, %o2
a00b4fec:  96 10 20 01  mov  1, %o3
a00b4ff0:  98 10 20 a3  mov  0xa3, %o4
a00b4ff4:  40 02 46 cb  call  0xa0146b20
a00b4ff8:  9a 10 20 00  clr  %o5
a00b4ffc:  a2 04 60 01  inc  %l1
a00b5000:  80 8c 60 ff  btst  0xff, %l1
a00b5004:  02 bf ff f5  be  0xa00b4fd8
a00b5008:  ba 0c 60 ff  and  %l1, 0xff, %i5
a00b500c:  81 c7 e0 08  ret
a00b5010:  81 e8 00 00  restore
