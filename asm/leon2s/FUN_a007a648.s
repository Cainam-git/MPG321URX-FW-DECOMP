# leon2s FUN_a007a648 0xa007a648-0xa007a6f0 (168 bytes)
a007a648:  9d e3 bf 98  save  %sp, -104, %sp
a007a64c:  a2 10 20 00  clr  %l1
a007a650:  83 2c 60 10  sll  %l1, 0x10, %g1
a007a654:  9b 30 60 10  srl  %g1, 0x10, %o5
a007a658:  82 0e 60 ff  and  %i1, 0xff, %g1
a007a65c:  83 38 40 0d  sra  %g1, %o5, %g1
a007a660:  80 88 60 01  btst  1, %g1
a007a664:  22 80 00 1c  be,a   0xa007a6d4
a007a668:  9a 04 60 01  add  %l1, 1, %o5
a007a66c:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a007a670:  a0 03 40 0d  add  %o5, %o5, %l0
a007a674:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007a678:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a67c:  80 a3 60 03  cmp  %o5, 3
a007a680:  18 80 00 14  bgu  0xa007a6d0
a007a684:  17 0e 00 00  sethi  %hi(0x38000000), %o3
a007a688:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a68c:  82 10 63 10  or  %g1, 0x310, %g1	! 0xa00b3b10
a007a690:  40 00 b3 7e  call  0xa00a7488
a007a694:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a007a698:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a69c:  82 10 63 20  or  %g1, 0x320, %g1	! 0xa00b3b20
a007a6a0:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a007a6a4:  90 0e 20 ff  and  %i0, 0xff, %o0
a007a6a8:  94 10 3f 00  mov  -256, %o2
a007a6ac:  40 00 b3 77  call  0xa00a7488
a007a6b0:  96 10 20 16  mov  0x16, %o3
a007a6b4:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007a6b8:  82 10 63 18  or  %g1, 0x318, %g1	! 0xa00b3b18
a007a6bc:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a007a6c0:  90 10 20 01  mov  1, %o0
a007a6c4:  92 10 20 07  mov  7, %o1
a007a6c8:  40 00 b3 57  call  0xa00a7424
a007a6cc:  94 0e 20 ff  and  %i0, 0xff, %o2
a007a6d0:  9a 04 60 01  add  %l1, 1, %o5
a007a6d4:  83 2b 60 10  sll  %o5, 0x10, %g1
a007a6d8:  83 30 60 10  srl  %g1, 0x10, %g1
a007a6dc:  80 a0 60 03  cmp  %g1, 3
a007a6e0:  08 bf ff dc  bleu  0xa007a650
a007a6e4:  a2 10 00 0d  mov  %o5, %l1
a007a6e8:  81 c7 e0 08  ret
a007a6ec:  81 e8 00 00  restore
