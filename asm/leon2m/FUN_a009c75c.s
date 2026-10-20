# leon2m FUN_a009c75c 0xa009c75c-0xa009c83c (224 bytes)
a009c75c:  9d e3 bf 98  save  %sp, -104, %sp
a009c760:  33 2a 00 ab  sethi  %hi(0xa802ac00), %i1
a009c764:  d2 06 63 ec  ld  [ %i1 + 0x3ec ], %o1	! 0xa802afec
a009c768:  90 02 7f 89  add  %o1, -119, %o0
a009c76c:  40 00 33 14  call  0xa00a93bc
a009c770:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c774:  03 15 55 55  sethi  %hi(0x55555400), %g1
a009c778:  b0 10 61 56  or  %g1, 0x156, %i0	! 0x55555556
a009c77c:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009c780:  96 02 3f 8a  add  %o0, -118, %o3
a009c784:  95 3a e0 1f  sra  %o3, 0x1f, %o2
a009c788:  80 5a c0 18  smul  %o3, %i0, %g0
a009c78c:  93 40 00 00  rd  %y, %o1
a009c790:  82 22 40 0a  sub  %o1, %o2, %g1
a009c794:  9e 00 40 01  add  %g1, %g1, %o7
a009c798:  98 03 c0 01  add  %o7, %g1, %o4
a009c79c:  94 22 c0 0c  sub  %o3, %o4, %o2
a009c7a0:  9a 02 a0 77  add  %o2, 0x77, %o5
a009c7a4:  da 26 63 ec  st  %o5, [ %i1 + 0x3ec ]
a009c7a8:  40 00 39 62  call  0xa00aad30
a009c7ac:  90 0a a0 ff  and  %o2, 0xff, %o0
a009c7b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c7b4:  80 a2 20 01  cmp  %o0, 1
a009c7b8:  32 bf ff f2  bne,a   0xa009c780
a009c7bc:  d0 16 63 ee  lduh  [ %i1 + 0x3ee ], %o0
a009c7c0:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a009c7c4:  96 16 22 90  or  %i0, 0x290, %o3	! 0xa802d290
a009c7c8:  d4 06 63 ec  ld  [ %i1 + 0x3ec ], %o2
a009c7cc:  d8 02 e0 ac  ld  [ %o3 + 0xac ], %o4
a009c7d0:  b0 02 bf 89  add  %o2, -119, %i0
a009c7d4:  1b 00 03 00  sethi  %hi(0xc0000), %o5
a009c7d8:  92 0e 20 03  and  %i0, 3, %o1
a009c7dc:  9e 2b 00 0d  andn  %o4, %o5, %o7
a009c7e0:  83 2a 60 12  sll  %o1, 0x12, %g1
a009c7e4:  19 2a 00 97  sethi  %hi(0xa8025c00), %o4
a009c7e8:  d2 0b 20 56  ldub  [ %o4 + 0x56 ], %o1	! 0xa8025c56
a009c7ec:  9a 13 c0 01  or  %o7, %g1, %o5
a009c7f0:  80 a6 00 09  cmp  %i0, %o1
a009c7f4:  02 80 00 0a  be  0xa009c81c
a009c7f8:  da 22 e0 ac  st  %o5, [ %o3 + 0xac ]
a009c7fc:  90 10 20 01  mov  1, %o0
a009c800:  40 00 2e 4f  call  0xa00a813c
a009c804:  94 10 20 01  mov  1, %o2
a009c808:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a009c80c:  b2 02 3f 89  add  %o0, -119, %i1
a009c810:  b0 0e 60 ff  and  %i1, 0xff, %i0
a009c814:  40 00 33 8f  call  0xa00a9650
a009c818:  93 e8 20 01  restore  %g0, 1, %o1
a009c81c:  40 00 2e 48  call  0xa00a813c
a009c820:  94 10 20 00  clr  %o2
a009c824:  d0 06 63 ec  ld  [ %i1 + 0x3ec ], %o0
a009c828:  b2 02 3f 89  add  %o0, -119, %i1
a009c82c:  b0 0e 60 ff  and  %i1, 0xff, %i0
a009c830:  40 00 33 88  call  0xa00a9650
a009c834:  93 e8 20 01  restore  %g0, 1, %o1
a009c838:  01 00 00 00  nop
