# leon2s FUN_a00c6760 0xa00c6760-0xa00c68f8 (408 bytes)
a00c6760:  9d e3 bf 98  save  %sp, -104, %sp
a00c6764:  80 8e 60 ff  btst  0xff, %i1
a00c6768:  02 80 00 35  be  0xa00c683c
a00c676c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c6770:  96 10 20 01  mov  1, %o3
a00c6774:  90 10 00 18  mov  %i0, %o0
a00c6778:  92 10 20 30  mov  0x30, %o1
a00c677c:  40 3b c1 47  call  0xa0fb6c98
a00c6780:  94 10 20 80  mov  0x80, %o2
a00c6784:  90 10 00 18  mov  %i0, %o0
a00c6788:  92 10 22 a8  mov  0x2a8, %o1
a00c678c:  40 3b c1 1d  call  0xa0fb6c00
a00c6790:  94 10 20 01  mov  1, %o2
a00c6794:  40 3b 5c 1b  call  0xa0f9d800
a00c6798:  01 00 00 00  nop
a00c679c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c67a0:  80 a2 20 81  cmp  %o0, 0x81
a00c67a4:  38 80 00 07  bgu,a   0xa00c67c0
a00c67a8:  96 10 20 00  clr  %o3
a00c67ac:  90 10 00 18  mov  %i0, %o0
a00c67b0:  92 10 24 5d  mov  0x45d, %o1
a00c67b4:  40 3b c1 13  call  0xa0fb6c00
a00c67b8:  94 10 20 00  clr  %o2
a00c67bc:  96 10 20 00  clr  %o3
a00c67c0:  90 10 00 18  mov  %i0, %o0
a00c67c4:  92 10 20 30  mov  0x30, %o1
a00c67c8:  40 3b c1 34  call  0xa0fb6c98
a00c67cc:  94 10 20 80  mov  0x80, %o2
a00c67d0:  90 10 00 18  mov  %i0, %o0
a00c67d4:  92 10 24 00  mov  0x400, %o1
a00c67d8:  40 3b c1 0a  call  0xa0fb6c00
a00c67dc:  94 10 20 03  mov  3, %o2
a00c67e0:  90 10 00 18  mov  %i0, %o0
a00c67e4:  92 10 24 02  mov  0x402, %o1
a00c67e8:  94 10 20 80  mov  0x80, %o2
a00c67ec:  40 3b c1 2b  call  0xa0fb6c98
a00c67f0:  96 10 20 01  mov  1, %o3
a00c67f4:  90 10 00 18  mov  %i0, %o0
a00c67f8:  92 10 24 03  mov  0x403, %o1
a00c67fc:  40 3b c1 01  call  0xa0fb6c00
a00c6800:  94 10 20 00  clr  %o2
a00c6804:  b4 10 20 00  clr  %i2
a00c6808:  1b 2a 01 e1  sethi  %hi(0xa8078400), %o5
a00c680c:  82 0e a0 ff  and  %i2, 0xff, %g1
a00c6810:  9a 13 62 10  or  %o5, 0x210, %o5
a00c6814:  d4 0b 40 01  ldub  [ %o5 + %g1 ], %o2
a00c6818:  90 10 00 18  mov  %i0, %o0
a00c681c:  40 3b c0 f9  call  0xa0fb6c00
a00c6820:  92 10 24 01  mov  0x401, %o1
a00c6824:  b4 06 a0 01  inc  %i2
a00c6828:  82 0e a0 ff  and  %i2, 0xff, %g1
a00c682c:  80 a0 60 0a  cmp  %g1, 0xa
a00c6830:  08 bf ff f8  bleu  0xa00c6810
a00c6834:  1b 2a 01 e1  sethi  %hi(0xa8078400), %o5
a00c6838:  30 80 00 2e  b,a   0xa00c68f0
a00c683c:  96 10 20 01  mov  1, %o3
a00c6840:  90 10 00 18  mov  %i0, %o0
a00c6844:  92 10 20 30  mov  0x30, %o1
a00c6848:  40 3b c1 14  call  0xa0fb6c98
a00c684c:  94 10 20 80  mov  0x80, %o2
a00c6850:  90 10 00 18  mov  %i0, %o0
a00c6854:  92 10 22 a8  mov  0x2a8, %o1
a00c6858:  40 3b c0 ea  call  0xa0fb6c00
a00c685c:  94 10 20 00  clr  %o2
a00c6860:  40 3b 5b e8  call  0xa0f9d800
a00c6864:  01 00 00 00  nop
a00c6868:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c686c:  80 a2 20 81  cmp  %o0, 0x81
a00c6870:  18 80 00 09  bgu  0xa00c6894
a00c6874:  96 10 20 00  clr  %o3
a00c6878:  80 8e a0 ff  btst  0xff, %i2
a00c687c:  02 80 00 07  be  0xa00c6898
a00c6880:  90 10 00 18  mov  %i0, %o0
a00c6884:  92 10 24 5d  mov  0x45d, %o1
a00c6888:  40 3b c0 de  call  0xa0fb6c00
a00c688c:  94 10 20 bf  mov  0xbf, %o2
a00c6890:  96 10 20 00  clr  %o3
a00c6894:  90 10 00 18  mov  %i0, %o0
a00c6898:  92 10 20 30  mov  0x30, %o1
a00c689c:  40 3b c0 ff  call  0xa0fb6c98
a00c68a0:  94 10 20 80  mov  0x80, %o2
a00c68a4:  90 10 00 18  mov  %i0, %o0
a00c68a8:  92 10 24 00  mov  0x400, %o1
a00c68ac:  40 3b c0 d5  call  0xa0fb6c00
a00c68b0:  94 10 20 03  mov  3, %o2
a00c68b4:  90 10 00 18  mov  %i0, %o0
a00c68b8:  92 10 24 02  mov  0x402, %o1
a00c68bc:  94 10 20 80  mov  0x80, %o2
a00c68c0:  40 3b c0 f6  call  0xa0fb6c98
a00c68c4:  96 10 20 01  mov  1, %o3
a00c68c8:  b4 10 20 00  clr  %i2
a00c68cc:  90 10 00 18  mov  %i0, %o0
a00c68d0:  92 10 24 01  mov  0x401, %o1
a00c68d4:  40 3b c0 cb  call  0xa0fb6c00
a00c68d8:  94 10 20 00  clr  %o2
a00c68dc:  b4 06 a0 01  inc  %i2
a00c68e0:  82 0e a0 ff  and  %i2, 0xff, %g1
a00c68e4:  80 a0 60 0a  cmp  %g1, 0xa
a00c68e8:  08 bf ff fa  bleu  0xa00c68d0
a00c68ec:  90 10 00 18  mov  %i0, %o0
a00c68f0:  81 c7 e0 08  ret
a00c68f4:  81 e8 00 00  restore
