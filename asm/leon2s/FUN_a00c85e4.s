# leon2s FUN_a00c85e4 0xa00c85e4-0xa00c8688 (164 bytes)
a00c85e4:  9d e3 bf 98  save  %sp, -104, %sp
a00c85e8:  80 8e a0 ff  btst  0xff, %i2
a00c85ec:  12 80 00 18  bne  0xa00c864c
a00c85f0:  a0 10 20 00  clr  %l0
a00c85f4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c85f8:  92 10 20 00  clr  %o1
a00c85fc:  94 10 20 0f  mov  0xf, %o2
a00c8600:  40 3b be 76  call  0xa0fb7fd8
a00c8604:  90 10 00 10  mov  %l0, %o0
a00c8608:  96 12 20 08  or  %o0, 8, %o3
a00c860c:  96 0a e0 ff  and  %o3, 0xff, %o3
a00c8610:  90 10 00 10  mov  %l0, %o0
a00c8614:  92 10 20 00  clr  %o1
a00c8618:  40 3b be 8f  call  0xa0fb8054
a00c861c:  94 10 20 0f  mov  0xf, %o2
a00c8620:  92 10 20 00  clr  %o1
a00c8624:  94 10 20 0f  mov  0xf, %o2
a00c8628:  40 3b be 6c  call  0xa0fb7fd8
a00c862c:  90 10 00 10  mov  %l0, %o0
a00c8630:  96 12 20 08  or  %o0, 8, %o3
a00c8634:  90 10 00 10  mov  %l0, %o0
a00c8638:  96 0a e0 ff  and  %o3, 0xff, %o3
a00c863c:  92 10 20 00  clr  %o1
a00c8640:  40 3b be 85  call  0xa0fb8054
a00c8644:  94 10 20 0f  mov  0xf, %o2
a00c8648:  a0 10 20 00  clr  %l0
a00c864c:  94 0c 20 ff  and  %l0, 0xff, %o2
a00c8650:  94 02 a0 15  add  %o2, 0x15, %o2
a00c8654:  95 2a a0 10  sll  %o2, 0x10, %o2
a00c8658:  95 32 a0 10  srl  %o2, 0x10, %o2
a00c865c:  90 0e 20 ff  and  %i0, 0xff, %o0
a00c8660:  40 3b be 5e  call  0xa0fb7fd8
a00c8664:  92 10 20 00  clr  %o1
a00c8668:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00c866c:  a0 04 20 01  inc  %l0
a00c8670:  82 0c 20 ff  and  %l0, 0xff, %g1
a00c8674:  80 a0 60 07  cmp  %g1, 7
a00c8678:  08 bf ff f5  bleu  0xa00c864c
a00c867c:  d0 2e 40 0d  stb  %o0, [ %i1 + %o5 ]
a00c8680:  81 c7 e0 08  ret
a00c8684:  81 e8 00 00  restore
