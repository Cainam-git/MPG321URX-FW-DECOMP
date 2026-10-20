# leon2m FUN_a0156840 0xa0156840-0xa0156944 (260 bytes)
a0156840:  9d e3 bf 80  save  %sp, -128, %sp
a0156844:  9b 36 20 1f  srl  %i0, 0x1f, %o5
a0156848:  80 a6 20 00  cmp  %i0, 0
a015684c:  12 80 00 08  bne  0xa015686c
a0156850:  da 27 bf e4  st  %o5, [ %fp + -28 ]
a0156854:  82 10 20 02  mov  2, %g1
a0156858:  c2 27 bf e0  st  %g1, [ %fp + -32 ]
a015685c:  40 00 02 3c  call  0xa015714c
a0156860:  90 07 bf e0  add  %fp, -32, %o0
a0156864:  10 80 00 36  b  0xa015693c
a0156868:  b0 10 00 08  mov  %o0, %i0
a015686c:  82 10 20 03  mov  3, %g1
a0156870:  c2 27 bf e0  st  %g1, [ %fp + -32 ]
a0156874:  80 a3 60 00  cmp  %o5, 0
a0156878:  94 10 20 3c  mov  0x3c, %o2
a015687c:  02 80 00 22  be  0xa0156904
a0156880:  96 10 20 3c  mov  0x3c, %o3
a0156884:  03 20 00 00  sethi  %hi(0x80000000), %g1
a0156888:  80 a6 00 01  cmp  %i0, %g1
a015688c:  02 80 00 28  be  0xa015692c
a0156890:  82 20 00 18  neg  %i0, %g1
a0156894:  9a 10 00 01  mov  %g1, %o5
a0156898:  99 38 60 1f  sra  %g1, 0x1f, %o4
a015689c:  92 10 00 0d  mov  %o5, %o1
a01568a0:  90 10 00 0c  mov  %o4, %o0
a01568a4:  d0 3f bf f0  std  %o0, [ %fp + -16 ]
a01568a8:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a01568ac:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a01568b0:  82 10 63 ff  or  %g1, 0x3ff, %g1
a01568b4:  80 a3 40 01  cmp  %o5, %g1
a01568b8:  38 bf ff e9  bgu,a   0xa015685c
a01568bc:  d6 27 bf e8  st  %o3, [ %fp + -24 ]
a01568c0:  97 32 60 1f  srl  %o1, 0x1f, %o3
a01568c4:  82 02 00 08  add  %o0, %o0, %g1
a01568c8:  98 12 c0 01  or  %o3, %g1, %o4
a01568cc:  9a 02 40 09  add  %o1, %o1, %o5
a01568d0:  82 02 bf ff  add  %o2, -1, %g1
a01568d4:  92 10 00 0d  mov  %o5, %o1
a01568d8:  94 10 00 01  mov  %g1, %o2
a01568dc:  90 10 00 0c  mov  %o4, %o0
a01568e0:  d0 3f bf f0  std  %o0, [ %fp + -16 ]
a01568e4:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a01568e8:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a01568ec:  82 10 63 ff  or  %g1, 0x3ff, %g1
a01568f0:  80 a3 40 01  cmp  %o5, %g1
a01568f4:  08 bf ff f3  bleu  0xa01568c0
a01568f8:  96 10 00 0a  mov  %o2, %o3
a01568fc:  10 bf ff d8  b  0xa015685c
a0156900:  d6 27 bf e8  st  %o3, [ %fp + -24 ]
a0156904:  9a 10 00 18  mov  %i0, %o5
a0156908:  99 3e 20 1f  sra  %i0, 0x1f, %o4
a015690c:  92 10 00 0d  mov  %o5, %o1
a0156910:  90 10 00 0c  mov  %o4, %o0
a0156914:  d0 3f bf f0  std  %o0, [ %fp + -16 ]
a0156918:  03 03 ff ff  sethi  %hi(0xffffc00), %g1
a015691c:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a0156920:  82 10 63 ff  or  %g1, 0x3ff, %g1
a0156924:  10 bf ff e5  b  0xa01568b8
a0156928:  80 a3 40 01  cmp  %o5, %g1
a015692c:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0156930:  d6 27 bf e8  st  %o3, [ %fp + -24 ]
a0156934:  d0 18 62 a8  ldd  [ %g1 + 0x2a8 ], %o0
a0156938:  b0 10 00 08  mov  %o0, %i0
a015693c:  81 c7 e0 08  ret
a0156940:  93 e8 00 09  restore  %g0, %o1, %o1
