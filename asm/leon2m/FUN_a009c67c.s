# leon2m FUN_a009c67c 0xa009c67c-0xa009c75c (224 bytes)
a009c67c:  9d e3 bf 98  save  %sp, -104, %sp
a009c680:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009c684:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a009c688:  90 02 7f 89  add  %o1, -119, %o0
a009c68c:  40 00 33 4c  call  0xa00a93bc
a009c690:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c694:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009c698:  b0 10 61 56  or  %g1, 0x156, %i0	! 0x55555556
a009c69c:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009c6a0:  96 02 3f 8b  add  %o0, -117, %o3
a009c6a4:  95 3a e0 1f  sra  %o3, 0x1f, %o2
a009c6a8:  80 5a c0 18  smul  %o3, %i0, %g0
a009c6ac:  93 40 00 00  rd  %y, %o1
a009c6b0:  82 22 40 0a  sub  %o1, %o2, %g1
a009c6b4:  9e 00 40 01  add  %g1, %g1, %o7
a009c6b8:  98 03 c0 01  add  %o7, %g1, %o4
a009c6bc:  94 22 c0 0c  sub  %o3, %o4, %o2
a009c6c0:  9a 02 a0 77  add  %o2, 0x77, %o5
a009c6c4:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a009c6c8:  40 00 39 9a  call  0xa00aad30
a009c6cc:  90 0a a0 ff  and  %o2, 0xff, %o0
a009c6d0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c6d4:  80 a2 20 01  cmp  %o0, 1
a009c6d8:  32 bf ff f2  bne,a   0xa009c6a0
a009c6dc:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009c6e0:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a009c6e4:  96 16 22 90  or  %i0, 0x290, %o3	! 0xa802d290
a009c6e8:  d4 06 63 ec  ld  [ %i1 + 0x3ec ], %o2
a009c6ec:  d8 02 e0 ac  ld  [ %o3 + 0xac ], %o4
a009c6f0:  b0 02 bf 89  add  %o2, -119, %i0
a009c6f4:  1b 00 03 00  sethi  %hi(0xc0000), %o5
a009c6f8:  92 0e 20 03  and  %i0, 3, %o1
a009c6fc:  9e 2b 00 0d  andn  %o4, %o5, %o7
a009c700:  83 2a 60 12  sll  %o1, 0x12, %g1
a009c704:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a009c708:  d2 0b 20 56  ldub  [ %o4 + 0x56 ], %o1	! 0xa8025c56
a009c70c:  9a 13 c0 01  or  %o7, %g1, %o5
a009c710:  80 a6 00 09  cmp  %i0, %o1
a009c714:  02 80 00 0a  be  0xa009c73c
a009c718:  da 22 e0 ac  st  %o5, [ %o3 + 0xac ]
a009c71c:  90 10 20 01  mov  1, %o0
a009c720:  40 00 2e 87  call  0xa00a813c
a009c724:  94 10 20 01  mov  1, %o2
a009c728:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a009c72c:  b2 02 3f 89  add  %o0, -119, %i1
a009c730:  b0 0e 60 ff  and  %i1, 0xff, %i0
a009c734:  40 00 33 c7  call  0xa00a9650
a009c738:  93 e8 20 01  restore  %g0, 1, %o1
a009c73c:  40 00 2e 80  call  0xa00a813c
a009c740:  94 10 20 00  clr  %o2
a009c744:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a009c748:  b2 02 3f 89  add  %o0, -119, %i1
a009c74c:  b0 0e 60 ff  and  %i1, 0xff, %i0
a009c750:  40 00 33 c0  call  0xa00a9650
a009c754:  93 e8 20 01  restore  %g0, 1, %o1
a009c758:  01 00 00 00  nop
