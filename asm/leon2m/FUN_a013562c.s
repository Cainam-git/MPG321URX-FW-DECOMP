# leon2m FUN_a013562c 0xa013562c-0xa01356fc (208 bytes)
a013562c:  9d e3 bf 98  save  %sp, -104, %sp
a0135630:  93 2e 20 10  sll  %i0, 0x10, %o1
a0135634:  91 32 60 10  srl  %o1, 0x10, %o0
a0135638:  83 3a 20 1f  sra  %o0, 0x1f, %g1
a013563c:  81 80 60 00  mov  %g1, %y
a0135640:  01 00 00 00  nop
a0135644:  01 00 00 00  nop
a0135648:  01 00 00 00  nop
a013564c:  94 7a 20 10  sdiv  %o0, 0x10, %o2
a0135650:  96 0e 60 ff  and  %i1, 0xff, %o3
a0135654:  94 0a a0 ff  and  %o2, 0xff, %o2
a0135658:  90 10 20 0d  mov  0xd, %o0
a013565c:  92 10 20 00  clr  %o1
a0135660:  67 fd 67 65  call  0x4008f3f4
a0135664:  98 10 20 00  clr  %o4
a0135668:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a013566c:  a0 10 62 40  or  %g1, 0x240, %l0	! 0xa802de40
a0135670:  33 2a 00 b2  sethi  %hi(0xa802c800), %i1
a0135674:  10 80 00 09  b  0xa0135698
a0135678:  b0 10 20 00  clr  %i0
a013567c:  80 88 60 ff  btst  0xff, %g1
a0135680:  12 80 00 1d  bne  0xa01356f4
a0135684:  01 00 00 00  nop
a0135688:  7f ff fe 95  call  0xa01350dc
a013568c:  01 00 00 00  nop
a0135690:  7f ff fd d4  call  0xa0134de0
a0135694:  01 00 00 00  nop
a0135698:  d6 0e 63 8f  ldub  [ %i1 + 0x38f ], %o3
a013569c:  80 a2 e0 01  cmp  %o3, 1
a01356a0:  12 bf ff f7  bne  0xa013567c
a01356a4:  82 10 20 00  clr  %g1
a01356a8:  15 2a 00 b2  sethi  %hi(0xa802c800), %o2
a01356ac:  d8 0a a3 8e  ldub  [ %o2 + 0x38e ], %o4	! 0xa802cb8e
a01356b0:  80 a6 00 0c  cmp  %i0, %o4
a01356b4:  1a 80 00 0c  bcc  0xa01356e4
a01356b8:  98 10 20 00  clr  %o4
a01356bc:  9a 10 20 00  clr  %o5
a01356c0:  96 10 00 10  mov  %l0, %o3
a01356c4:  c2 0a c0 0d  ldub  [ %o3 + %o5 ], %g1
a01356c8:  c2 2b 40 1a  stb  %g1, [ %o5 + %i2 ]
a01356cc:  98 03 20 01  inc  %o4
a01356d0:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01356d4:  de 0a a3 8e  ldub  [ %o2 + 0x38e ], %o7
a01356d8:  80 a3 40 0f  cmp  %o5, %o7
a01356dc:  2a bf ff fb  bcs,a   0xa01356c8
a01356e0:  c2 0a c0 0d  ldub  [ %o3 + %o5 ], %g1
a01356e4:  82 10 20 01  mov  1, %g1
a01356e8:  80 88 60 ff  btst  0xff, %g1
a01356ec:  02 bf ff e7  be  0xa0135688
a01356f0:  c0 2e 63 8f  clrb  [ %i1 + 0x38f ]
a01356f4:  81 c7 e0 08  ret
a01356f8:  81 e8 00 00  restore
