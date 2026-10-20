# leon2m FUN_a0133384 0xa0133384-0xa01334ec (360 bytes)
a0133384:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a0133388:  9a 10 20 00  clr  %o5
a013338c:  82 10 20 00  clr  %g1
a0133390:  98 12 e1 a0  or  %o3, 0x1a0, %o4
a0133394:  c0 2b 00 01  clrb  [ %o4 + %g1 ]
a0133398:  9a 03 60 01  inc  %o5
a013339c:  82 0b 60 ff  and  %o5, 0xff, %g1
a01333a0:  80 a0 60 11  cmp  %g1, 0x11
a01333a4:  28 bf ff fd  bleu,a   0xa0133398
a01333a8:  c0 2b 00 01  clrb  [ %o4 + %g1 ]
a01333ac:  82 10 20 14  mov  0x14, %g1
a01333b0:  c2 2a e1 a0  stb  %g1, [ %o3 + 0x1a0 ]
a01333b4:  96 12 e1 a0  or  %o3, 0x1a0, %o3
a01333b8:  15 2a 00 b6  sethi  %hi(0xa802d800), %o2
a01333bc:  9a 10 20 00  clr  %o5
a01333c0:  82 10 20 00  clr  %g1
a01333c4:  98 10 20 20  mov  0x20, %o4
a01333c8:  83 3b 00 01  sra  %o4, %g1, %g1
a01333cc:  80 a0 60 01  cmp  %g1, 1
a01333d0:  02 80 00 08  be  0xa01333f0
a01333d4:  82 13 60 10  or  %o5, 0x10, %g1
a01333d8:  9a 03 60 01  inc  %o5
a01333dc:  82 0b 60 ff  and  %o5, 0xff, %g1
a01333e0:  80 a0 60 07  cmp  %g1, 7
a01333e4:  08 bf ff fa  bleu  0xa01333cc
a01333e8:  83 3b 00 01  sra  %o4, %g1, %g1
a01333ec:  82 13 60 10  or  %o5, 0x10, %g1
a01333f0:  c2 2a e0 01  stb  %g1, [ %o3 + 1 ]
a01333f4:  98 12 a1 a0  or  %o2, 0x1a0, %o4
a01333f8:  96 10 20 05  mov  5, %o3
a01333fc:  d6 2b 20 02  stb  %o3, [ %o4 + 2 ]
a0133400:  9a 10 20 14  mov  0x14, %o5
a0133404:  da 2b 20 03  stb  %o5, [ %o4 + 3 ]
a0133408:  96 10 00 0c  mov  %o4, %o3
a013340c:  9a 10 20 00  clr  %o5
a0133410:  82 10 20 00  clr  %g1
a0133414:  98 10 20 40  mov  0x40, %o4
a0133418:  83 3b 00 01  sra  %o4, %g1, %g1
a013341c:  80 a0 60 01  cmp  %g1, 1
a0133420:  02 80 00 08  be  0xa0133440
a0133424:  82 13 60 10  or  %o5, 0x10, %g1
a0133428:  9a 03 60 01  inc  %o5
a013342c:  82 0b 60 ff  and  %o5, 0xff, %g1
a0133430:  80 a0 60 07  cmp  %g1, 7
a0133434:  08 bf ff fa  bleu  0xa013341c
a0133438:  83 3b 00 01  sra  %o4, %g1, %g1
a013343c:  82 13 60 10  or  %o5, 0x10, %g1
a0133440:  98 12 a1 a0  or  %o2, 0x1a0, %o4
a0133444:  9a 10 20 05  mov  5, %o5
a0133448:  c2 2a e0 04  stb  %g1, [ %o3 + 4 ]
a013344c:  da 2b 00 0d  stb  %o5, [ %o4 + %o5 ]
a0133450:  94 10 20 14  mov  0x14, %o2
a0133454:  d4 2b 20 09  stb  %o2, [ %o4 + 9 ]
a0133458:  15 2a 00 b6  sethi  %hi(0xa802d800), %o2
a013345c:  9a 10 20 00  clr  %o5
a0133460:  82 10 20 00  clr  %g1
a0133464:  96 10 20 40  mov  0x40, %o3
a0133468:  83 3a c0 01  sra  %o3, %g1, %g1
a013346c:  80 a0 60 01  cmp  %g1, 1
a0133470:  02 80 00 08  be  0xa0133490
a0133474:  82 12 a1 a0  or  %o2, 0x1a0, %g1
a0133478:  9a 03 60 01  inc  %o5
a013347c:  82 0b 60 ff  and  %o5, 0xff, %g1
a0133480:  80 a0 60 07  cmp  %g1, 7
a0133484:  08 bf ff fa  bleu  0xa013346c
a0133488:  83 3a c0 01  sra  %o3, %g1, %g1
a013348c:  82 12 a1 a0  or  %o2, 0x1a0, %g1
a0133490:  da 2b 20 0a  stb  %o5, [ %o4 + 0xa ]
a0133494:  96 10 20 05  mov  5, %o3
a0133498:  d6 28 60 0b  stb  %o3, [ %g1 + 0xb ]
a013349c:  98 10 20 14  mov  0x14, %o4
a01334a0:  d8 28 60 0c  stb  %o4, [ %g1 + 0xc ]
a01334a4:  96 10 00 01  mov  %g1, %o3
a01334a8:  98 10 20 00  clr  %o4
a01334ac:  82 10 20 00  clr  %g1
a01334b0:  9a 10 20 20  mov  0x20, %o5
a01334b4:  83 3b 40 01  sra  %o5, %g1, %g1
a01334b8:  80 a0 60 01  cmp  %g1, 1
a01334bc:  22 80 00 08  be,a   0xa01334dc
a01334c0:  9a 12 a1 a0  or  %o2, 0x1a0, %o5
a01334c4:  98 03 20 01  inc  %o4
a01334c8:  82 0b 20 ff  and  %o4, 0xff, %g1
a01334cc:  80 a0 60 07  cmp  %g1, 7
a01334d0:  28 bf ff fa  bleu,a   0xa01334b8
a01334d4:  83 3b 40 01  sra  %o5, %g1, %g1
a01334d8:  9a 12 a1 a0  or  %o2, 0x1a0, %o5
a01334dc:  d8 2a e0 0d  stb  %o4, [ %o3 + 0xd ]
a01334e0:  94 10 20 02  mov  2, %o2
a01334e4:  81 c3 e0 08  retl
a01334e8:  d4 2b 60 0e  stb  %o2, [ %o5 + 0xe ]
