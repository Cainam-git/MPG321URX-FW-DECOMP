# leon2m FUN_a00a5420 0xa00a5420-0xa00a550c (236 bytes)
a00a5420:  9d e3 bf 98  save  %sp, -104, %sp
a00a5424:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a5428:  82 06 00 18  add  %i0, %i0, %g1
a00a542c:  80 a6 20 06  cmp  %i0, 6
a00a5430:  18 80 00 04  bgu  0xa00a5440
a00a5434:  82 00 7f f8  add  %g1, -8, %g1
a00a5438:  90 06 00 18  add  %i0, %i0, %o0
a00a543c:  82 02 20 06  add  %o0, 6, %g1
a00a5440:  80 8e 60 ff  btst  0xff, %i1
a00a5444:  b0 08 60 ff  and  %g1, 0xff, %i0
a00a5448:  02 80 00 19  be  0xa00a54ac
a00a544c:  b2 10 20 00  clr  %i1
a00a5450:  92 10 00 18  mov  %i0, %o1
a00a5454:  90 10 20 22  mov  0x22, %o0
a00a5458:  94 10 20 03  mov  3, %o2
a00a545c:  96 10 27 42  mov  0x742, %o3
a00a5460:  40 02 85 88  call  0xa0146a80
a00a5464:  98 10 20 00  clr  %o4
a00a5468:  9a 0e 60 ff  and  %i1, 0xff, %o5
a00a546c:  96 03 60 22  add  %o5, 0x22, %o3
a00a5470:  95 2a e0 10  sll  %o3, 0x10, %o2
a00a5474:  93 32 a0 10  srl  %o2, 0x10, %o1
a00a5478:  98 06 60 37  add  %i1, 0x37, %o4
a00a547c:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a5480:  90 10 20 00  clr  %o0
a00a5484:  94 10 00 18  mov  %i0, %o2
a00a5488:  96 10 20 01  mov  1, %o3
a00a548c:  40 02 85 a5  call  0xa0146b20
a00a5490:  9a 10 20 00  clr  %o5
a00a5494:  b2 06 60 01  inc  %i1
a00a5498:  92 0e 60 ff  and  %i1, 0xff, %o1
a00a549c:  80 a2 60 02  cmp  %o1, 2
a00a54a0:  08 bf ff ed  bleu  0xa00a5454
a00a54a4:  92 10 00 18  mov  %i0, %o1
a00a54a8:  30 80 00 17  b,a   0xa00a5504
a00a54ac:  90 10 20 22  mov  0x22, %o0
a00a54b0:  92 10 00 18  mov  %i0, %o1
a00a54b4:  94 10 20 03  mov  3, %o2
a00a54b8:  96 10 25 42  mov  0x542, %o3
a00a54bc:  40 02 85 71  call  0xa0146a80
a00a54c0:  98 10 20 00  clr  %o4
a00a54c4:  98 0e 60 ff  and  %i1, 0xff, %o4
a00a54c8:  92 03 20 22  add  %o4, 0x22, %o1
a00a54cc:  91 2a 60 10  sll  %o1, 0x10, %o0
a00a54d0:  82 06 60 34  add  %i1, 0x34, %g1
a00a54d4:  93 32 20 10  srl  %o0, 0x10, %o1
a00a54d8:  98 08 60 ff  and  %g1, 0xff, %o4
a00a54dc:  90 10 20 00  clr  %o0
a00a54e0:  94 10 00 18  mov  %i0, %o2
a00a54e4:  96 10 20 01  mov  1, %o3
a00a54e8:  40 02 85 8e  call  0xa0146b20
a00a54ec:  9a 10 20 00  clr  %o5
a00a54f0:  b2 06 60 01  inc  %i1
a00a54f4:  9e 0e 60 ff  and  %i1, 0xff, %o7
a00a54f8:  80 a3 e0 02  cmp  %o7, 2
a00a54fc:  08 bf ff ed  bleu  0xa00a54b0
a00a5500:  90 10 20 22  mov  0x22, %o0
a00a5504:  81 c7 e0 08  ret
a00a5508:  81 e8 00 00  restore
