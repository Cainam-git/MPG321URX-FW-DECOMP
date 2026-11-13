# leon2m FUN_a014b900 0xa014b900-0xa014b960 (96 bytes)
a014b900:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b904:  80 a2 20 00  cmp  %o0, 0
a014b908:  12 80 00 09  bne  0xa014b92c
a014b90c:  80 a2 20 01  cmp  %o0, 1
a014b910:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014b914:  da 08 63 fa  ldub  [ %g1 + 0x3fa ], %o5	! 0xa802e3fa
a014b918:  90 10 20 02  mov  2, %o0
a014b91c:  80 a3 60 01  cmp  %o5, 1
a014b920:  12 80 00 0d  bne  0xa014b954
a014b924:  92 10 20 00  clr  %o1
a014b928:  30 80 00 08  b,a   0xa014b948
a014b92c:  12 80 00 0a  bne  0xa014b954
a014b930:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a014b934:  da 0a 23 fc  ldub  [ %o0 + 0x3fc ], %o5	! 0xa802e3fc
a014b938:  90 10 20 03  mov  3, %o0
a014b93c:  80 a3 60 01  cmp  %o5, 1
a014b940:  12 80 00 05  bne  0xa014b954
a014b944:  92 10 20 00  clr  %o1
a014b948:  82 13 c0 00  mov  %o7, %g1
a014b94c:  7f ff 8e 28  call  0xa012f1ec
a014b950:  9e 10 40 00  mov  %g1, %o7
a014b954:  01 00 00 00  nop
a014b958:  81 c3 e0 08  retl
a014b95c:  01 00 00 00  nop
