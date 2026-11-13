# leon2m FUN_a00c95a4 0xa00c95a4-0xa00c9788 (484 bytes)
a00c95a4:  9d e3 bf 98  save  %sp, -104, %sp
a00c95a8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c95ac:  80 a4 20 02  cmp  %l0, 2
a00c95b0:  02 80 00 54  be  0xa00c9700
a00c95b4:  80 a4 20 03  cmp  %l0, 3
a00c95b8:  02 80 00 55  be  0xa00c970c
a00c95bc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c95c0:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c95c4:  94 08 60 ff  and  %g1, 0xff, %o2
a00c95c8:  98 02 bf d0  add  %o2, -48, %o4
a00c95cc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c95d0:  80 a3 60 04  cmp  %o5, 4
a00c95d4:  18 80 00 6b  bgu  0xa00c9780
a00c95d8:  b0 10 20 ff  mov  0xff, %i0
a00c95dc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c95e0:  40 00 2c ee  call  0xa00d4998
a00c95e4:  d8 2a e3 eb  stb  %o4, [ %o3 + 0x3eb ]	! 0xa802d3eb
a00c95e8:  40 00 3e ce  call  0xa00d9120
a00c95ec:  01 00 00 00  nop
a00c95f0:  7f ff bc b7  call  0xa00b88cc
a00c95f4:  01 00 00 00  nop
a00c95f8:  80 a4 20 02  cmp  %l0, 2
a00c95fc:  02 80 00 24  be  0xa00c968c
a00c9600:  80 a4 20 03  cmp  %l0, 3
a00c9604:  02 80 00 45  be  0xa00c9718
a00c9608:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c960c:  94 13 60 78  or  %o5, 0x78, %o2	! 0xa802d078
a00c9610:  90 10 20 30  mov  0x30, %o0
a00c9614:  96 10 20 35  mov  0x35, %o3
a00c9618:  98 10 20 36  mov  0x36, %o4
a00c961c:  92 10 20 2b  mov  0x2b, %o1
a00c9620:  82 10 20 0d  mov  0xd, %g1
a00c9624:  d6 2b 60 78  stb  %o3, [ %o5 + 0x78 ]
a00c9628:  d8 2a a0 01  stb  %o4, [ %o2 + 1 ]
a00c962c:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c9630:  d2 2a a0 04  stb  %o1, [ %o2 + 4 ]
a00c9634:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c9638:  80 a4 20 02  cmp  %l0, 2
a00c963c:  02 80 00 21  be  0xa00c96c0
a00c9640:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c9644:  80 a4 20 03  cmp  %l0, 3
a00c9648:  02 80 00 41  be  0xa00c974c
a00c964c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c9650:  92 13 20 d0  or  %o4, 0xd0, %o1	! 0xa802d0d0
a00c9654:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00c9658:  c0 2b 60 9c  clrb  [ %o5 + 0x9c ]	! 0xa802b09c
a00c965c:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c9660:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c9664:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c9668:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c966c:  80 a4 20 02  cmp  %l0, 2
a00c9670:  02 80 00 1d  be  0xa00c96e4
a00c9674:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c9678:  80 a4 20 03  cmp  %l0, 3
a00c967c:  12 80 00 1d  bne  0xa00c96f0
a00c9680:  90 10 00 10  mov  %l0, %o0
a00c9684:  10 80 00 3c  b  0xa00c9774
a00c9688:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c968c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9690:  98 12 21 28  or  %o0, 0x128, %o4	! 0xa802d128
a00c9694:  9e 10 20 30  mov  0x30, %o7
a00c9698:  92 10 20 35  mov  0x35, %o1
a00c969c:  82 10 20 0d  mov  0xd, %g1
a00c96a0:  b0 10 20 36  mov  0x36, %i0
a00c96a4:  a0 10 20 2b  mov  0x2b, %l0
a00c96a8:  d2 2a 21 28  stb  %o1, [ %o0 + 0x128 ]
a00c96ac:  c2 2b 20 05  stb  %g1, [ %o4 + 5 ]
a00c96b0:  f0 2b 20 01  stb  %i0, [ %o4 + 1 ]
a00c96b4:  de 2b 20 03  stb  %o7, [ %o4 + 3 ]
a00c96b8:  e0 2b 20 04  stb  %l0, [ %o4 + 4 ]
a00c96bc:  de 2b 20 02  stb  %o7, [ %o4 + 2 ]
a00c96c0:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c96c4:  94 13 e0 40  or  %o7, 0x40, %o2	! 0xa802d040
a00c96c8:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c96cc:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00c96d0:  c0 2b e0 40  clrb  [ %o7 + 0x40 ]
a00c96d4:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c96d8:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c96dc:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c96e0:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c96e4:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c96e8:  94 12 e1 28  or  %o3, 0x128, %o2	! 0xa802d128
a00c96ec:  90 10 20 02  mov  2, %o0
a00c96f0:  40 01 fc 3e  call  0xa01487e8
a00c96f4:  92 10 20 06  mov  6, %o1
a00c96f8:  10 80 00 22  b  0xa00c9780
a00c96fc:  b0 10 20 00  clr  %i0
a00c9700:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c9704:  10 bf ff b0  b  0xa00c95c4
a00c9708:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c970c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9710:  10 bf ff ad  b  0xa00c95c4
a00c9714:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c9718:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c971c:  98 14 21 08  or  %l0, 0x108, %o4	! 0xa802d108
a00c9720:  94 10 20 30  mov  0x30, %o2
a00c9724:  b0 10 20 35  mov  0x35, %i0
a00c9728:  9e 10 20 0d  mov  0xd, %o7
a00c972c:  96 10 20 36  mov  0x36, %o3
a00c9730:  9a 10 20 2b  mov  0x2b, %o5
a00c9734:  f0 2c 21 08  stb  %i0, [ %l0 + 0x108 ]
a00c9738:  de 2b 20 05  stb  %o7, [ %o4 + 5 ]
a00c973c:  d6 2b 20 01  stb  %o3, [ %o4 + 1 ]
a00c9740:  d4 2b 20 03  stb  %o2, [ %o4 + 3 ]
a00c9744:  da 2b 20 04  stb  %o5, [ %o4 + 4 ]
a00c9748:  d4 2b 20 02  stb  %o2, [ %o4 + 2 ]
a00c974c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c9750:  b0 12 20 98  or  %o0, 0x98, %i0	! 0xa802d098
a00c9754:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c9758:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c975c:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00c9760:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c9764:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c9768:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c976c:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c9770:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c9774:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c9778:  10 bf ff de  b  0xa00c96f0
a00c977c:  90 10 20 03  mov  3, %o0
a00c9780:  81 c7 e0 08  ret
a00c9784:  81 e8 00 00  restore
