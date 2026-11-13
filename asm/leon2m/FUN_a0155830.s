# leon2m FUN_a0155830 0xa0155830-0xa0155a18 (488 bytes)
a0155830:  9d e3 bf 60  save  %sp, -160, %sp
a0155834:  a0 07 bf e8  add  %fp, -24, %l0
a0155838:  f0 27 bf c4  st  %i0, [ %fp + -60 ]
a015583c:  f2 27 bf c0  st  %i1, [ %fp + -64 ]
a0155840:  90 07 bf c4  add  %fp, -60, %o0
a0155844:  40 00 05 bc  call  0xa0156f34
a0155848:  92 10 00 10  mov  %l0, %o1
a015584c:  b2 07 bf d8  add  %fp, -40, %i1
a0155850:  90 07 bf c0  add  %fp, -64, %o0
a0155854:  40 00 05 b8  call  0xa0156f34
a0155858:  92 10 00 19  mov  %i1, %o1
a015585c:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a0155860:  80 a0 60 01  cmp  %g1, 1
a0155864:  08 80 00 1a  bleu  0xa01558cc
a0155868:  b0 07 bf c8  add  %fp, -56, %i0
a015586c:  da 07 bf d8  ld  [ %fp + -40 ], %o5
a0155870:  80 a3 60 01  cmp  %o5, 1
a0155874:  28 80 00 0c  bleu,a   0xa01558a4
a0155878:  da 07 bf dc  ld  [ %fp + -36 ], %o5
a015587c:  80 a0 60 04  cmp  %g1, 4
a0155880:  22 80 00 10  be,a   0xa01558c0
a0155884:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0155888:  80 a3 60 04  cmp  %o5, 4
a015588c:  12 80 00 18  bne  0xa01558ec
a0155890:  80 a0 60 02  cmp  %g1, 2
a0155894:  03 00 06 a0  sethi  %hi(0x1a8000), %g1
a0155898:  02 80 00 5c  be  0xa0155a08
a015589c:  90 10 62 b0  or  %g1, 0x2b0, %o0	! 0x1a82b0
a01558a0:  da 07 bf dc  ld  [ %fp + -36 ], %o5
a01558a4:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a01558a8:  82 18 40 0d  xor  %g1, %o5, %g1
a01558ac:  80 a0 00 01  cmp  %g0, %g1
a01558b0:  9a 40 20 00  addx  %g0, 0, %o5
a01558b4:  da 27 bf dc  st  %o5, [ %fp + -36 ]
a01558b8:  10 80 00 54  b  0xa0155a08
a01558bc:  90 10 00 19  mov  %i1, %o0
a01558c0:  80 a3 60 02  cmp  %o5, 2
a01558c4:  02 80 00 51  be  0xa0155a08
a01558c8:  90 10 62 b0  or  %g1, 0x2b0, %o0
a01558cc:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a01558d0:  da 07 bf dc  ld  [ %fp + -36 ], %o5
a01558d4:  82 18 40 0d  xor  %g1, %o5, %g1
a01558d8:  80 a0 00 01  cmp  %g0, %g1
a01558dc:  9a 40 20 00  addx  %g0, 0, %o5
a01558e0:  da 27 bf ec  st  %o5, [ %fp + -20 ]
a01558e4:  10 80 00 49  b  0xa0155a08
a01558e8:  90 10 00 10  mov  %l0, %o0
a01558ec:  02 bf ff f9  be  0xa01558d0
a01558f0:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a01558f4:  80 a3 60 02  cmp  %o5, 2
a01558f8:  02 bf ff ec  be  0xa01558a8
a01558fc:  da 07 bf dc  ld  [ %fp + -36 ], %o5
a0155900:  d0 07 bf f4  ld  [ %fp + -12 ], %o0
a0155904:  d4 07 bf e4  ld  [ %fp + -28 ], %o2
a0155908:  96 10 00 0a  mov  %o2, %o3
a015590c:  92 10 00 08  mov  %o0, %o1
a0155910:  94 10 20 00  clr  %o2
a0155914:  40 00 05 02  call  0xa0156d1c
a0155918:  90 10 20 00  clr  %o0
a015591c:  d6 07 bf dc  ld  [ %fp + -36 ], %o3
a0155920:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a0155924:  82 18 40 0b  xor  %g1, %o3, %g1
a0155928:  80 a0 00 01  cmp  %g0, %g1
a015592c:  d6 07 bf f0  ld  [ %fp + -16 ], %o3
a0155930:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a0155934:  96 02 c0 01  add  %o3, %g1, %o3
a0155938:  9a 10 00 08  mov  %o0, %o5
a015593c:  94 40 20 00  addx  %g0, 0, %o2
a0155940:  96 02 e0 02  add  %o3, 2, %o3
a0155944:  98 10 00 0d  mov  %o5, %o4
a0155948:  d4 27 bf cc  st  %o2, [ %fp + -52 ]
a015594c:  90 10 00 09  mov  %o1, %o0
a0155950:  80 a3 60 00  cmp  %o5, 0
a0155954:  06 80 00 1d  bl  0xa01559c8
a0155958:  d6 27 bf d0  st  %o3, [ %fp + -48 ]
a015595c:  03 0f ff ff  sethi  %hi(0x3ffffc00), %g1
a0155960:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0x3fffffff
a0155964:  80 a3 00 01  cmp  %o4, %g1
a0155968:  38 80 00 10  bgu,a   0xa01559a8
a015596c:  82 0b 20 7f  and  %o4, 0x7f, %g1
a0155970:  10 80 00 05  b  0xa0155984
a0155974:  d6 06 20 08  ld  [ %i0 + 8 ], %o3
a0155978:  80 a3 00 01  cmp  %o4, %g1
a015597c:  38 80 00 0a  bgu,a   0xa01559a4
a0155980:  da 26 20 08  st  %o5, [ %i0 + 8 ]
a0155984:  9a 02 ff ff  add  %o3, -1, %o5
a0155988:  80 a2 20 00  cmp  %o0, 0
a015598c:  98 03 00 0c  add  %o4, %o4, %o4
a0155990:  90 02 00 08  add  %o0, %o0, %o0
a0155994:  16 bf ff f9  bge  0xa0155978
a0155998:  96 10 00 0d  mov  %o5, %o3
a015599c:  10 bf ff f7  b  0xa0155978
a01559a0:  98 13 20 01  or  %o4, 1, %o4
a01559a4:  82 0b 20 7f  and  %o4, 0x7f, %g1
a01559a8:  80 a0 60 40  cmp  %g1, 0x40
a01559ac:  02 80 00 10  be  0xa01559ec
a01559b0:  80 8b 20 80  btst  0x80, %o4
a01559b4:  82 10 20 03  mov  3, %g1
a01559b8:  d8 26 20 0c  st  %o4, [ %i0 + 0xc ]
a01559bc:  c2 26 00 00  st  %g1, [ %i0 ]
a01559c0:  10 80 00 12  b  0xa0155a08
a01559c4:  90 10 00 18  mov  %i0, %o0
a01559c8:  80 8b 60 01  btst  1, %o5
a01559cc:  02 80 00 05  be  0xa01559e0
a01559d0:  96 02 e0 01  inc  %o3
a01559d4:  91 32 60 01  srl  %o1, 1, %o0
a01559d8:  03 20 00 00  sethi  %hi(0x80000000), %g1
a01559dc:  90 12 00 01  or  %o0, %g1, %o0
a01559e0:  99 33 20 01  srl  %o4, 1, %o4
a01559e4:  10 bf ff de  b  0xa015595c
a01559e8:  d6 26 20 08  st  %o3, [ %i0 + 8 ]
a01559ec:  32 bf ff f2  bne,a   0xa01559b4
a01559f0:  98 03 20 40  add  %o4, 0x40, %o4
a01559f4:  80 a2 20 00  cmp  %o0, 0
a01559f8:  02 bf ff f0  be  0xa01559b8
a01559fc:  82 10 20 03  mov  3, %g1
a0155a00:  10 bf ff ee  b  0xa01559b8
a0155a04:  98 03 20 40  add  %o4, 0x40, %o4
a0155a08:  40 00 04 f9  call  0xa0156dec
a0155a0c:  01 00 00 00  nop
a0155a10:  81 c7 e0 08  ret
a0155a14:  91 e8 00 08  restore  %g0, %o0, %o0
