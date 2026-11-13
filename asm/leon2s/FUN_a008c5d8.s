# leon2s FUN_a008c5d8 0xa008c5d8-0xa008c6f8 (288 bytes)  [FUN_a008c6f0 = unreachable ret/restore tail, merged]
a008c5d8:  9d e3 bf 98  save  %sp, -104, %sp
a008c5dc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008c5e0:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a008c5e4:  80 a6 20 04  cmp  %i0, 4
a008c5e8:  b4 10 20 00  clr  %i2
a008c5ec:  02 80 00 05  be  0xa008c600
a008c5f0:  90 10 20 00  clr  %o0
a008c5f4:  80 a6 20 06  cmp  %i0, 6
a008c5f8:  12 80 00 3d  bne  0xa008c6ec
a008c5fc:  90 10 20 01  mov  1, %o0
a008c600:  b6 0a 20 ff  and  %o0, 0xff, %i3
a008c604:  7f ff ff cd  call  0xa008c538
a008c608:  90 10 00 1b  mov  %i3, %o0
a008c60c:  c2 0c 63 30  ldub  [ %l1 + 0x330 ], %g1
a008c610:  82 18 60 01  xor  %g1, 1, %g1
a008c614:  80 a0 00 01  cmp  %g0, %g1
a008c618:  1b 3f ff e4  sethi  %hi(0xffff9000), %o5
a008c61c:  a0 10 00 08  mov  %o0, %l0
a008c620:  9a 13 62 9f  or  %o5, 0x29f, %o5
a008c624:  03 00 00 07  sethi  %hi(0x1c00), %g1
a008c628:  98 60 3f ff  subx  %g0, -1, %o4
a008c62c:  82 10 63 3e  or  %g1, 0x33e, %g1
a008c630:  9a 04 00 0d  add  %l0, %o5, %o5
a008c634:  80 a0 40 0d  cmp  %g1, %o5
a008c638:  82 60 3f ff  subx  %g0, -1, %g1
a008c63c:  90 10 00 1b  mov  %i3, %o0
a008c640:  80 a3 00 01  cmp  %o4, %g1
a008c644:  02 80 00 03  be  0xa008c650
a008c648:  b0 0e 60 ff  and  %i1, 0xff, %i0
a008c64c:  b4 10 20 01  mov  1, %i2
a008c650:  80 8e a0 ff  btst  0xff, %i2
a008c654:  02 80 00 26  be  0xa008c6ec
a008c658:  01 00 00 00  nop
a008c65c:  7f ff f9 ef  call  0xa008ae18
a008c660:  b2 10 20 01  mov  1, %i1	! 0x1
a008c664:  9b 2e e0 02  sll  %i3, 2, %o5
a008c668:  9a 03 40 1b  add  %o5, %i3, %o5
a008c66c:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a008c670:  82 10 60 24  or  %g1, 0x24, %g1	! 0xa807a824
a008c674:  9b 2b 60 02  sll  %o5, 2, %o5
a008c678:  9a 03 40 01  add  %o5, %g1, %o5
a008c67c:  d8 13 60 62  lduh  [ %o5 + 0x62 ], %o4
a008c680:  03 00 00 23  sethi  %hi(0x8c00), %g1
a008c684:  98 0b 3f bf  and  %o4, -65, %o4
a008c688:  82 10 60 9f  or  %g1, 0x9f, %g1
a008c68c:  90 10 00 18  mov  %i0, %o0
a008c690:  92 10 20 02  mov  2, %o1
a008c694:  94 10 20 08  mov  8, %o2
a008c698:  96 10 20 00  clr  %o3
a008c69c:  b4 10 20 40  mov  0x40, %i2
a008c6a0:  b6 10 20 00  clr  %i3
a008c6a4:  80 a4 00 01  cmp  %l0, %g1
a008c6a8:  18 80 00 06  bgu  0xa008c6c0
a008c6ac:  d8 33 60 62  sth  %o4, [ %o5 + 0x62 ]
a008c6b0:  82 10 20 01  mov  1, %g1
a008c6b4:  40 00 6a d2  call  0xa00a71fc
a008c6b8:  c2 2c 63 30  stb  %g1, [ %l1 + 0x330 ]
a008c6bc:  30 80 00 0a  b,a   0xa008c6e4
a008c6c0:  c0 2c 63 30  clrb  [ %l1 + 0x330 ]
a008c6c4:  90 10 00 18  mov  %i0, %o0
a008c6c8:  92 10 20 02  mov  2, %o1
a008c6cc:  94 10 20 08  mov  8, %o2
a008c6d0:  40 00 6a cb  call  0xa00a71fc
a008c6d4:  96 10 20 08  mov  8, %o3
a008c6d8:  b2 10 20 01  mov  1, %i1
a008c6dc:  b4 10 20 40  mov  0x40, %i2
a008c6e0:  b6 10 20 40  mov  0x40, %i3
a008c6e4:  40 00 6a c6  call  0xa00a71fc
a008c6e8:  81 e8 00 00  restore
a008c6ec:  01 00 00 00  nop
a008c6f0:  81 c7 e0 08  ret
a008c6f4:  81 e8 00 00  restore
