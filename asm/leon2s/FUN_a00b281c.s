# leon2s FUN_a00b281c 0xa00b281c-0xa00b288c (112 bytes)
a00b281c:  9d e3 bf 98  save  %sp, -104, %sp
a00b2820:  9e 96 20 00  orcc  %i0, 0, %o7
a00b2824:  02 80 00 18  be  0xa00b2884
a00b2828:  b0 10 20 01  mov  1, %i0
a00b282c:  c0 2b c0 00  clrb  [ %o7 ]
a00b2830:  b6 10 20 00  clr  %i3
a00b2834:  b4 10 20 1c  mov  0x1c, %i2
a00b2838:  83 36 40 1a  srl  %i1, %i2, %g1
a00b283c:  b8 08 60 0f  and  %g1, 0xf, %i4
a00b2840:  82 07 3f f6  add  %i4, -10, %g1
a00b2844:  b4 06 bf fc  add  %i2, -4, %i2
a00b2848:  82 08 60 ff  and  %g1, 0xff, %g1
a00b284c:  80 a7 20 09  cmp  %i4, 9
a00b2850:  08 80 00 06  bleu  0xa00b2868
a00b2854:  ba 07 20 30  add  %i4, 0x30, %i5
a00b2858:  80 a0 60 05  cmp  %g1, 5
a00b285c:  08 80 00 03  bleu  0xa00b2868
a00b2860:  ba 07 20 37  add  %i4, 0x37, %i5
a00b2864:  ba 10 20 30  mov  0x30, %i5
a00b2868:  fa 2b c0 1b  stb  %i5, [ %o7 + %i3 ]
a00b286c:  b6 06 e0 01  inc  %i3
a00b2870:  80 a6 e0 07  cmp  %i3, 7
a00b2874:  04 bf ff f2  ble  0xa00b283c
a00b2878:  83 36 40 1a  srl  %i1, %i2, %g1
a00b287c:  c0 2b e0 08  clrb  [ %o7 + 8 ]
a00b2880:  b0 10 20 00  clr  %i0
a00b2884:  81 c7 e0 08  ret
a00b2888:  81 e8 00 00  restore
