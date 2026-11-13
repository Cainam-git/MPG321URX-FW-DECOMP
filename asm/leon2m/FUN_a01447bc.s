# leon2m FUN_a01447bc 0xa01447bc-0xa014489c (224 bytes)
a01447bc:  9d e3 bf 98  save  %sp, -104, %sp
a01447c0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01447c4:  80 a6 20 01  cmp  %i0, 1
a01447c8:  02 80 00 0b  be  0xa01447f4
a01447cc:  98 10 20 01  mov  1, %o4
a01447d0:  80 a6 20 01  cmp  %i0, 1
a01447d4:  04 80 00 11  ble  0xa0144818
a01447d8:  80 a6 20 02  cmp  %i0, 2
a01447dc:  02 80 00 06  be  0xa01447f4
a01447e0:  98 10 20 02  mov  2, %o4
a01447e4:  80 a6 20 03  cmp  %i0, 3
a01447e8:  02 80 00 03  be  0xa01447f4
a01447ec:  98 10 20 03  mov  3, %o4
a01447f0:  98 10 3f ff  mov  -1, %o4
a01447f4:  82 0b 20 ff  and  %o4, 0xff, %g1
a01447f8:  80 a0 60 03  cmp  %g1, 3
a01447fc:  08 80 00 0d  bleu  0xa0144830
a0144800:  95 28 60 04  sll  %g1, 4, %o2
a0144804:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0144808:  7f fe 6a 5a  call  0xa00df170
a014480c:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0144810:  10 80 00 07  b  0xa014482c
a0144814:  82 10 20 00  clr  %g1
a0144818:  80 a6 20 00  cmp  %i0, 0
a014481c:  02 bf ff f6  be  0xa01447f4
a0144820:  98 10 20 00  clr  %o4
a0144824:  10 bf ff f4  b  0xa01447f4
a0144828:  98 10 3f ff  mov  -1, %o4
a014482c:  95 28 60 04  sll  %g1, 4, %o2
a0144830:  90 22 80 01  sub  %o2, %g1, %o0
a0144834:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a0144838:  93 2a 20 03  sll  %o0, 3, %o1
a014483c:  9a 10 63 30  or  %g1, 0x330, %o5
a0144840:  f0 03 40 09  ld  [ %o5 + %o1 ], %i0
a0144844:  9f 36 20 0c  srl  %i0, 0xc, %o7
a0144848:  98 0b e0 0f  and  %o7, 0xf, %o4
a014484c:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0144850:  90 5b 20 2a  smul  %o4, 0x2a, %o0
a0144854:  94 12 e2 24  or  %o3, 0x224, %o2
a0144858:  82 02 00 0a  add  %o0, %o2, %g1
a014485c:  7f ff f6 43  call  0xa0142168
a0144860:  d0 08 60 0a  ldub  [ %g1 + 0xa ], %o0
a0144864:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0144868:  80 a6 20 07  cmp  %i0, 7
a014486c:  92 40 20 00  addx  %g0, 0, %o1
a0144870:  9a 20 00 09  neg  %o1, %o5
a0144874:  9e 0e 00 0d  and  %i0, %o5, %o7
a0144878:  99 2b e0 03  sll  %o7, 3, %o4
a014487c:  96 03 00 0f  add  %o4, %o7, %o3
a0144880:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0144884:  92 02 c0 0b  add  %o3, %o3, %o1
a0144888:  82 12 a1 16  or  %o2, 0x116, %g1
a014488c:  9a 02 40 01  add  %o1, %g1, %o5
a0144890:  f0 0b 60 05  ldub  [ %o5 + 5 ], %i0
a0144894:  81 c7 e0 08  ret
a0144898:  81 e8 00 00  restore
