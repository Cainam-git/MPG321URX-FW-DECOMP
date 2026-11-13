# leon2s FUN_a00865b8 0xa00865b8-0xa008661c (100 bytes)
a00865b8:  9d e3 bf 98  save  %sp, -104, %sp
a00865bc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00865c0:  80 a6 60 01  cmp  %i1, 1
a00865c4:  b2 10 20 00  clr  %i1
a00865c8:  02 80 00 06  be  0xa00865e0
a00865cc:  a0 10 20 01  mov  1, %l0
a00865d0:  10 80 00 04  b  0xa00865e0
a00865d4:  a0 10 20 02  mov  2, %l0
a00865d8:  10 80 00 0f  b  0xa0086614
a00865dc:  b0 10 20 01  mov  1, %i0
a00865e0:  90 0e 20 ff  and  %i0, 0xff, %o0
a00865e4:  92 10 20 80  mov  0x80, %o1
a00865e8:  94 10 26 00  mov  0x600, %o2
a00865ec:  7f ff ff 5d  call  0xa0086360
a00865f0:  96 0c 20 ff  and  %l0, 0xff, %o3
a00865f4:  b2 06 60 01  inc  %i1
a00865f8:  80 8a 20 ff  btst  0xff, %o0
a00865fc:  02 bf ff f7  be  0xa00865d8
a0086600:  82 0e 60 ff  and  %i1, 0xff, %g1
a0086604:  80 a0 60 04  cmp  %g1, 4
a0086608:  08 bf ff f7  bleu  0xa00865e4
a008660c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0086610:  b0 10 20 00  clr  %i0
a0086614:  81 c7 e0 08  ret
a0086618:  81 e8 00 00  restore
