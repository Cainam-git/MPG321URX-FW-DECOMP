# leon2m FUN_a01478b0 0xa01478b0-0xa01479ec (280 bytes)
a01478b0:  9d e3 bf 98  save  %sp, -104, %sp
a01478b4:  03 00 06 9b  sethi  %hi(0x1a6c00), %g1
a01478b8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01478bc:  94 10 61 a3  or  %g1, 0x1a3, %o2
a01478c0:  96 10 20 00  clr  %o3
a01478c4:  9a 10 20 00  clr  %o5
a01478c8:  92 03 40 0d  add  %o5, %o5, %o1
a01478cc:  98 02 40 0d  add  %o1, %o5, %o4
a01478d0:  9a 03 00 0a  add  %o4, %o2, %o5
a01478d4:  d0 0b 60 01  ldub  [ %o5 + 1 ], %o0
a01478d8:  80 a2 00 18  cmp  %o0, %i0
a01478dc:  02 80 00 29  be  0xa0147980
a01478e0:  96 02 e0 01  inc  %o3
a01478e4:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01478e8:  80 a3 60 04  cmp  %o5, 4
a01478ec:  08 bf ff f8  bleu  0xa01478cc
a01478f0:  92 03 40 0d  add  %o5, %o5, %o1
a01478f4:  b0 10 20 00  clr  %i0
a01478f8:  82 0e 60 ff  and  %i1, 0xff, %g1
a01478fc:  80 a0 60 07  cmp  %g1, 7
a0147900:  18 80 00 09  bgu  0xa0147924
a0147904:  b2 10 20 09  mov  9, %i1
a0147908:  33 00 03 8d  sethi  %hi(0xe3400), %i1
a014790c:  97 28 60 02  sll  %g1, 2, %o3
a0147910:  9e 16 60 18  or  %i1, 0x18, %o7
a0147914:  d8 03 c0 0b  ld  [ %o7 + %o3 ], %o4
a0147918:  81 c3 00 00  jmp  %o4
a014791c:  01 00 00 00  nop
a0147920:  b2 10 20 09  mov  9, %i1	! 0x9
a0147924:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0147928:  80 a6 60 09  cmp  %i1, 9
a014792c:  02 80 00 04  be  0xa014793c
a0147930:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0147934:  40 00 1e a9  call  0xa014f3d8
a0147938:  81 e8 00 00  restore
a014793c:  90 10 00 18  mov  %i0, %o0
a0147940:  40 00 1e a6  call  0xa014f3d8
a0147944:  92 10 20 00  clr  %o1
a0147948:  90 10 00 18  mov  %i0, %o0
a014794c:  40 00 1e a3  call  0xa014f3d8
a0147950:  92 10 20 06  mov  6, %o1
a0147954:  90 10 00 18  mov  %i0, %o0
a0147958:  40 00 1e a0  call  0xa014f3d8
a014795c:  92 10 20 07  mov  7, %o1
a0147960:  90 10 00 18  mov  %i0, %o0
a0147964:  40 00 1e 9d  call  0xa014f3d8
a0147968:  92 10 20 04  mov  4, %o1
a014796c:  90 10 00 18  mov  %i0, %o0
a0147970:  40 00 1e 9a  call  0xa014f3d8
a0147974:  92 10 20 05  mov  5, %o1
a0147978:  40 00 1e 98  call  0xa014f3d8
a014797c:  93 e8 20 08  restore  %g0, 8, %o1
a0147980:  7f ff 8c fb  call  0xa012ad6c
a0147984:  f0 0a 80 0c  ldub  [ %o2 + %o4 ], %i0
a0147988:  94 0a 20 ff  and  %o0, 0xff, %o2
a014798c:  80 a2 a0 01  cmp  %o2, 1
a0147990:  02 80 00 04  be  0xa01479a0
a0147994:  82 0e 20 ff  and  %i0, 0xff, %g1
a0147998:  10 bf ff d8  b  0xa01478f8
a014799c:  b0 10 00 01  mov  %g1, %i0
a01479a0:  80 a0 60 04  cmp  %g1, 4
a01479a4:  02 80 00 0f  be  0xa01479e0
a01479a8:  80 a0 60 06  cmp  %g1, 6
a01479ac:  32 bf ff d3  bne,a   0xa01478f8
a01479b0:  b0 10 00 01  mov  %g1, %i0
a01479b4:  82 10 20 04  mov  4, %g1
a01479b8:  10 bf ff d0  b  0xa01478f8
a01479bc:  b0 10 00 01  mov  %g1, %i0
a01479c0:  10 bf ff d9  b  0xa0147924
a01479c4:  b2 10 20 08  mov  8, %i1
a01479c8:  10 bf ff d7  b  0xa0147924
a01479cc:  b2 10 20 07  mov  7, %i1
a01479d0:  10 bf ff d5  b  0xa0147924
a01479d4:  b2 10 20 06  mov  6, %i1
a01479d8:  10 bf ff d3  b  0xa0147924
a01479dc:  b2 10 20 00  clr  %i1
a01479e0:  82 10 20 06  mov  6, %g1
a01479e4:  10 bf ff c5  b  0xa01478f8
a01479e8:  b0 10 00 01  mov  %g1, %i0
