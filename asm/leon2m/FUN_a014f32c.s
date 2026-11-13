# leon2m FUN_a014f32c 0xa014f32c-0xa014f374 (72 bytes)
a014f32c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a014f330:  90 0a 20 ff  and  %o0, 0xff, %o0
a014f334:  d6 10 60 80  lduh  [ %g1 + 0x80 ], %o3
a014f338:  98 10 20 00  clr  %o4
a014f33c:  9a 10 20 00  clr  %o5
a014f340:  83 2b 60 02  sll  %o5, 2, %g1
a014f344:  83 3a c0 01  sra  %o3, %g1, %g1
a014f348:  82 08 60 0f  and  %g1, 0xf, %g1
a014f34c:  80 a0 40 08  cmp  %g1, %o0
a014f350:  02 80 00 06  be  0xa014f368
a014f354:  98 03 20 01  inc  %o4
a014f358:  9a 0b 20 ff  and  %o4, 0xff, %o5
a014f35c:  80 a3 60 03  cmp  %o5, 3
a014f360:  08 bf ff f9  bleu  0xa014f344
a014f364:  83 2b 60 02  sll  %o5, 2, %g1
a014f368:  80 a3 60 04  cmp  %o5, 4
a014f36c:  81 c3 e0 08  retl
a014f370:  90 60 3f ff  subx  %g0, -1, %o0
