# leon2m FUN_a0145808 0xa0145808-0xa0145920 (280 bytes)
a0145808:  9d e3 bf 98  save  %sp, -104, %sp
a014580c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0145810:  80 a6 20 01  cmp  %i0, 1
a0145814:  02 80 00 0b  be  0xa0145840
a0145818:  82 10 20 01  mov  1, %g1
a014581c:  80 a6 20 01  cmp  %i0, 1
a0145820:  04 80 00 2d  ble  0xa01458d4
a0145824:  80 a6 20 02  cmp  %i0, 2
a0145828:  02 80 00 06  be  0xa0145840
a014582c:  82 10 20 02  mov  2, %g1
a0145830:  80 a6 20 03  cmp  %i0, 3
a0145834:  02 80 00 03  be  0xa0145840
a0145838:  82 10 20 03  mov  3, %g1
a014583c:  82 10 3f ff  mov  -1, %g1
a0145840:  b0 08 60 ff  and  %g1, 0xff, %i0
a0145844:  91 2e 20 04  sll  %i0, 4, %o0
a0145848:  82 22 00 18  sub  %o0, %i0, %g1
a014584c:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a0145850:  83 28 60 03  sll  %g1, 3, %g1
a0145854:  9a 13 63 30  or  %o5, 0x330, %o5
a0145858:  80 a6 60 0a  cmp  %i1, 0xa
a014585c:  02 80 00 1b  be  0xa01458c8
a0145860:  96 00 40 0d  add  %g1, %o5, %o3
a0145864:  80 a6 60 0a  cmp  %i1, 0xa
a0145868:  18 80 00 0a  bgu  0xa0145890
a014586c:  80 a6 60 0c  cmp  %i1, 0xc
a0145870:  80 a6 60 09  cmp  %i1, 9
a0145874:  02 80 00 27  be  0xa0145910
a0145878:  98 0e e0 ff  and  %i3, 0xff, %o4
a014587c:  80 a3 20 00  cmp  %o4, 0
a0145880:  02 80 00 26  be  0xa0145918
a0145884:  01 00 00 00  nop
a0145888:  7f ff a6 59  call  0xa012f1ec
a014588c:  93 e8 20 02  restore  %g0, 2, %o1
a0145890:  02 80 00 16  be  0xa01458e8
a0145894:  80 a6 60 10  cmp  %i1, 0x10
a0145898:  12 bf ff f9  bne  0xa014587c
a014589c:  98 0e e0 ff  and  %i3, 0xff, %o4
a01458a0:  80 8e e0 ff  btst  0xff, %i3
a01458a4:  12 bf ff f9  bne  0xa0145888
a01458a8:  f4 32 e0 20  sth  %i2, [ %o3 + 0x20 ]
a01458ac:  f0 00 40 0d  ld  [ %g1 + %o5 ], %i0
a01458b0:  9f 36 20 0c  srl  %i0, 0xc, %o7
a01458b4:  99 2e a0 10  sll  %i2, 0x10, %o4
a01458b8:  90 0b e0 0f  and  %o7, 0xf, %o0
a01458bc:  7f fe cd 62  call  0xa00f8e44
a01458c0:  93 33 20 10  srl  %o4, 0x10, %o1
a01458c4:  30 80 00 15  b,a   0xa0145918
a01458c8:  f4 32 e0 18  sth  %i2, [ %o3 + 0x18 ]
a01458cc:  10 bf ff ec  b  0xa014587c
a01458d0:  98 0e e0 ff  and  %i3, 0xff, %o4
a01458d4:  80 a6 20 00  cmp  %i0, 0
a01458d8:  02 bf ff da  be  0xa0145840
a01458dc:  82 10 20 00  clr  %g1
a01458e0:  10 bf ff d8  b  0xa0145840
a01458e4:  82 10 3f ff  mov  -1, %g1
a01458e8:  80 8e e0 ff  btst  0xff, %i3
a01458ec:  12 bf ff e7  bne  0xa0145888
a01458f0:  f4 32 e0 1e  sth  %i2, [ %o3 + 0x1e ]
a01458f4:  d6 00 40 0d  ld  [ %g1 + %o5 ], %o3
a01458f8:  95 32 e0 0c  srl  %o3, 0xc, %o2
a01458fc:  93 2e a0 10  sll  %i2, 0x10, %o1
a0145900:  90 0a a0 0f  and  %o2, 0xf, %o0
a0145904:  7f fe cd 42  call  0xa00f8e0c
a0145908:  93 32 60 10  srl  %o1, 0x10, %o1
a014590c:  30 80 00 03  b,a   0xa0145918
a0145910:  10 bf ff db  b  0xa014587c
a0145914:  f4 32 e0 16  sth  %i2, [ %o3 + 0x16 ]
a0145918:  81 c7 e0 08  ret
a014591c:  81 e8 00 00  restore
