# leon2s FUN_a00c86bc 0xa00c86bc-0xa00c8760 (164 bytes)
a00c86bc:  9d e3 bf 90  save  %sp, -112, %sp
a00c86c0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c86c4:  7f ff fd 4d  call  0xa00c7bf8
a00c86c8:  90 10 00 18  mov  %i0, %o0
a00c86cc:  80 8a 20 ff  btst  0xff, %o0
a00c86d0:  02 80 00 06  be  0xa00c86e8
a00c86d4:  a2 10 20 00  clr  %l1
a00c86d8:  11 27 c7 07  sethi  %hi(0x9f1c1c00), %o0
a00c86dc:  40 3a ea 5a  call  0xa0f83044
a00c86e0:  90 12 23 a0  or  %o0, 0x3a0, %o0	! 0x9f1c1fa0
a00c86e4:  a2 10 20 00  clr  %l1
a00c86e8:  94 0c 60 ff  and  %l1, 0xff, %o2
a00c86ec:  94 02 a0 1d  add  %o2, 0x1d, %o2
a00c86f0:  82 0c 60 ff  and  %l1, 0xff, %g1
a00c86f4:  95 2a a0 10  sll  %o2, 0x10, %o2
a00c86f8:  a0 07 bf f8  add  %fp, -8, %l0
a00c86fc:  a0 04 00 01  add  %l0, %g1, %l0
a00c8700:  95 32 a0 10  srl  %o2, 0x10, %o2
a00c8704:  90 10 00 18  mov  %i0, %o0
a00c8708:  40 3b be 34  call  0xa0fb7fd8
a00c870c:  92 10 20 00  clr  %o1
a00c8710:  a2 04 60 01  inc  %l1
a00c8714:  82 0c 60 ff  and  %l1, 0xff, %g1
a00c8718:  80 a0 60 04  cmp  %g1, 4
a00c871c:  08 bf ff f3  bleu  0xa00c86e8
a00c8720:  d0 2c 3f f8  stb  %o0, [ %l0 + -8 ]
a00c8724:  92 07 bf f0  add  %fp, -16, %o1
a00c8728:  90 10 00 18  mov  %i0, %o0
a00c872c:  94 10 20 74  mov  0x74, %o2
a00c8730:  96 10 20 10  mov  0x10, %o3
a00c8734:  7f ff fe 6f  call  0xa00c80f0
a00c8738:  98 10 20 05  mov  5, %o4
a00c873c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00c8740:  80 a2 60 00  cmp  %o1, 0
a00c8744:  02 80 00 04  be  0xa00c8754
a00c8748:  11 27 c7 07  sethi  %hi(0x9f1c1c00), %o0
a00c874c:  40 3a ea 3e  call  0xa0f83044
a00c8750:  90 12 23 c0  or  %o0, 0x3c0, %o0	! 0x9f1c1fc0
a00c8754:  01 00 00 00  nop
a00c8758:  81 c7 e0 08  ret
a00c875c:  81 e8 00 00  restore
