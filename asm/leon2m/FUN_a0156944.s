# leon2m FUN_a0156944 0xa0156944-0xa01569e0 (156 bytes)
a0156944:  9d e3 bf 78  save  %sp, -136, %sp
a0156948:  92 07 bf e0  add  %fp, -32, %o1
a015694c:  f0 3f bf d8  std  %i0, [ %fp + -40 ]
a0156950:  40 00 02 7f  call  0xa015734c
a0156954:  90 07 bf d8  add  %fp, -40, %o0
a0156958:  da 07 bf e0  ld  [ %fp + -32 ], %o5
a015695c:  80 a3 60 02  cmp  %o5, 2
a0156960:  02 80 00 1e  be  0xa01569d8
a0156964:  92 10 20 00  clr  %o1
a0156968:  80 a3 60 01  cmp  %o5, 1
a015696c:  08 80 00 1b  bleu  0xa01569d8
a0156970:  80 a3 60 04  cmp  %o5, 4
a0156974:  12 80 00 0a  bne  0xa015699c
a0156978:  c2 07 bf e8  ld  [ %fp + -24 ], %g1
a015697c:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a0156980:  80 a0 60 00  cmp  %g1, 0
a0156984:  12 80 00 04  bne  0xa0156994
a0156988:  31 20 00 00  sethi  %hi(0x80000000), %i0
a015698c:  03 1f ff ff  sethi  %hi(0x7ffffc00), %g1
a0156990:  b0 10 63 ff  or  %g1, 0x3ff, %i0	! 0x7fffffff
a0156994:  10 80 00 11  b  0xa01569d8
a0156998:  92 10 00 18  mov  %i0, %o1
a015699c:  80 a0 60 00  cmp  %g1, 0
a01569a0:  06 80 00 0e  bl  0xa01569d8
a01569a4:  92 10 20 00  clr  %o1
a01569a8:  80 a0 60 1e  cmp  %g1, 0x1e
a01569ac:  34 bf ff f5  bg,a   0xa0156980
a01569b0:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a01569b4:  94 10 20 3c  mov  0x3c, %o2
a01569b8:  94 22 80 01  sub  %o2, %g1, %o2
a01569bc:  7f ff f9 bb  call  0xa01550a8
a01569c0:  d0 1f bf f0  ldd  [ %fp + -16 ], %o0
a01569c4:  c2 07 bf e4  ld  [ %fp + -28 ], %g1
a01569c8:  80 a0 60 00  cmp  %g1, 0
a01569cc:  02 80 00 03  be  0xa01569d8
a01569d0:  01 00 00 00  nop
a01569d4:  92 20 00 09  neg  %o1
a01569d8:  81 c7 e0 08  ret
a01569dc:  91 e8 00 09  restore  %g0, %o1, %o0
