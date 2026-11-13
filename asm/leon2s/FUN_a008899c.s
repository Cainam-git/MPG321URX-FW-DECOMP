# leon2s FUN_a008899c 0xa008899c-0xa0088a80 (228 bytes)
a008899c:  9d e3 bf 98  save  %sp, -104, %sp
a00889a0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00889a4:  80 a6 20 00  cmp  %i0, 0
a00889a8:  12 80 00 09  bne  0xa00889cc
a00889ac:  a0 10 20 00  clr  %l0
a00889b0:  7f ff eb 58  call  0xa0083710
a00889b4:  90 10 20 00  clr  %o0
a00889b8:  80 8a 20 01  btst  1, %o0
a00889bc:  32 80 00 2e  bne,a   0xa0088a74
a00889c0:  a0 10 20 01  mov  1, %l0
a00889c4:  10 80 00 27  b  0xa0088a60
a00889c8:  90 10 20 00  clr  %o0
a00889cc:  80 a6 20 02  cmp  %i0, 2
a00889d0:  12 80 00 09  bne  0xa00889f4
a00889d4:  80 a6 20 03  cmp  %i0, 3
a00889d8:  7f ff eb 4e  call  0xa0083710
a00889dc:  90 10 20 02  mov  2, %o0
a00889e0:  80 8a 20 01  btst  1, %o0
a00889e4:  32 80 00 24  bne,a   0xa0088a74
a00889e8:  a0 10 20 01  mov  1, %l0
a00889ec:  10 80 00 1d  b  0xa0088a60
a00889f0:  90 10 20 02  mov  2, %o0
a00889f4:  12 80 00 09  bne  0xa0088a18
a00889f8:  80 a6 20 04  cmp  %i0, 4
a00889fc:  7f ff eb 45  call  0xa0083710
a0088a00:  90 10 20 03  mov  3, %o0
a0088a04:  80 8a 20 01  btst  1, %o0
a0088a08:  32 80 00 1b  bne,a   0xa0088a74
a0088a0c:  a0 10 20 01  mov  1, %l0
a0088a10:  10 80 00 14  b  0xa0088a60
a0088a14:  90 10 20 03  mov  3, %o0
a0088a18:  12 80 00 09  bne  0xa0088a3c
a0088a1c:  80 a6 20 01  cmp  %i0, 1
a0088a20:  7f ff eb 3c  call  0xa0083710
a0088a24:  90 10 20 04  mov  4, %o0
a0088a28:  80 8a 20 01  btst  1, %o0
a0088a2c:  32 80 00 12  bne,a   0xa0088a74
a0088a30:  a0 10 20 01  mov  1, %l0
a0088a34:  10 80 00 0b  b  0xa0088a60
a0088a38:  90 10 20 04  mov  4, %o0
a0088a3c:  32 80 00 0f  bne,a   0xa0088a78
a0088a40:  b0 0c 20 03  and  %l0, 3, %i0
a0088a44:  7f ff eb 33  call  0xa0083710
a0088a48:  90 10 20 01  mov  1, %o0
a0088a4c:  80 8a 20 01  btst  1, %o0
a0088a50:  02 80 00 04  be  0xa0088a60
a0088a54:  90 10 20 01  mov  1, %o0
a0088a58:  10 80 00 07  b  0xa0088a74
a0088a5c:  a0 10 20 01  mov  1, %l0
a0088a60:  7f ff eb 2c  call  0xa0083710
a0088a64:  01 00 00 00  nop
a0088a68:  80 8a 20 02  btst  2, %o0
a0088a6c:  32 80 00 02  bne,a   0xa0088a74
a0088a70:  a0 10 20 02  mov  2, %l0
a0088a74:  b0 0c 20 03  and  %l0, 3, %i0
a0088a78:  81 c7 e0 08  ret
a0088a7c:  81 e8 00 00  restore
