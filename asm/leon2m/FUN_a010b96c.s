# leon2m FUN_a010b96c 0xa010b96c-0xa010baac (320 bytes)
a010b96c:  82 0a 20 ff  and  %o0, 0xff, %g1
a010b970:  80 a0 60 02  cmp  %g1, 2
a010b974:  9a 10 20 00  clr  %o5
a010b978:  08 80 00 05  bleu  0xa010b98c
a010b97c:  98 10 20 00  clr  %o4
a010b980:  82 02 3f fd  add  %o0, -3, %g1
a010b984:  82 08 60 ff  and  %g1, 0xff, %g1
a010b988:  9a 10 20 01  mov  1, %o5
a010b98c:  80 8b 60 ff  btst  0xff, %o5
a010b990:  02 80 00 0a  be  0xa010b9b8
a010b994:  80 a0 60 01  cmp  %g1, 1
a010b998:  02 80 00 3b  be  0xa010ba84
a010b99c:  03 34 00 c8  sethi  %hi(0xd0032000), %g1
a010b9a0:  da 00 40 00  ld  [ %g1 ], %o5
a010b9a4:  80 8b 60 02  btst  2, %o5
a010b9a8:  02 80 00 23  be  0xa010ba34
a010b9ac:  03 34 00 e8  sethi  %hi(0xd003a000), %g1
a010b9b0:  10 80 00 3b  b  0xa010ba9c
a010b9b4:  98 10 20 01  mov  1, %o4
a010b9b8:  02 80 00 25  be  0xa010ba4c
a010b9bc:  80 a0 60 01  cmp  %g1, 1
a010b9c0:  04 80 00 12  ble  0xa010ba08
a010b9c4:  80 a0 60 02  cmp  %g1, 2
a010b9c8:  12 80 00 36  bne  0xa010baa0
a010b9cc:  90 0b 20 ff  and  %o4, 0xff, %o0
a010b9d0:  1b 34 00 c0  sethi  %hi(0xd0030000), %o5
a010b9d4:  82 13 60 04  or  %o5, 4, %g1	! 0xd0030004
a010b9d8:  d0 00 40 00  ld  [ %g1 ], %o0
a010b9dc:  80 8a 20 08  btst  8, %o0
a010b9e0:  32 80 00 2f  bne,a   0xa010ba9c
a010b9e4:  98 10 20 01  mov  1, %o4
a010b9e8:  1b 34 00 e0  sethi  %hi(0xd0038000), %o5
a010b9ec:  82 13 60 04  or  %o5, 4, %g1	! 0xd0038004
a010b9f0:  d0 00 40 00  ld  [ %g1 ], %o0
a010b9f4:  80 8a 20 08  btst  8, %o0
a010b9f8:  22 80 00 2a  be,a   0xa010baa0
a010b9fc:  90 0b 20 ff  and  %o4, 0xff, %o0
a010ba00:  10 80 00 27  b  0xa010ba9c
a010ba04:  98 10 20 01  mov  1, %o4
a010ba08:  80 a0 60 00  cmp  %g1, 0
a010ba0c:  12 80 00 25  bne  0xa010baa0
a010ba10:  90 0b 20 ff  and  %o4, 0xff, %o0
a010ba14:  03 34 00 c0  sethi  %hi(0xd0030000), %g1
a010ba18:  9a 10 60 04  or  %g1, 4, %o5	! 0xd0030004
a010ba1c:  d0 03 40 00  ld  [ %o5 ], %o0
a010ba20:  80 8a 20 02  btst  2, %o0
a010ba24:  32 80 00 1e  bne,a   0xa010ba9c
a010ba28:  98 10 20 01  mov  1, %o4
a010ba2c:  11 34 00 e0  sethi  %hi(0xd0038000), %o0
a010ba30:  82 12 20 04  or  %o0, 4, %g1	! 0xd0038004
a010ba34:  da 00 40 00  ld  [ %g1 ], %o5
a010ba38:  80 8b 60 02  btst  2, %o5
a010ba3c:  22 80 00 19  be,a   0xa010baa0
a010ba40:  90 0b 20 ff  and  %o4, 0xff, %o0
a010ba44:  10 80 00 16  b  0xa010ba9c
a010ba48:  98 10 20 01  mov  1, %o4
a010ba4c:  1b 34 00 c0  sethi  %hi(0xd0030000), %o5
a010ba50:  82 13 60 04  or  %o5, 4, %g1	! 0xd0030004
a010ba54:  d0 00 40 00  ld  [ %g1 ], %o0
a010ba58:  80 8a 20 04  btst  4, %o0
a010ba5c:  32 80 00 10  bne,a   0xa010ba9c
a010ba60:  98 10 20 01  mov  1, %o4
a010ba64:  11 34 00 e0  sethi  %hi(0xd0038000), %o0
a010ba68:  82 12 20 04  or  %o0, 4, %g1	! 0xd0038004
a010ba6c:  da 00 40 00  ld  [ %g1 ], %o5
a010ba70:  80 8b 60 04  btst  4, %o5
a010ba74:  22 80 00 0b  be,a   0xa010baa0
a010ba78:  90 0b 20 ff  and  %o4, 0xff, %o0
a010ba7c:  10 80 00 08  b  0xa010ba9c
a010ba80:  98 10 20 01  mov  1, %o4
a010ba84:  11 34 00 c8  sethi  %hi(0xd0032000), %o0
a010ba88:  da 02 00 00  ld  [ %o0 ], %o5
a010ba8c:  80 8b 60 04  btst  4, %o5
a010ba90:  02 bf ff f7  be  0xa010ba6c
a010ba94:  03 34 00 e8  sethi  %hi(0xd003a000), %g1
a010ba98:  98 10 20 01  mov  1, %o4
a010ba9c:  90 0b 20 ff  and  %o4, 0xff, %o0
a010baa0:  80 a0 00 08  cmp  %g0, %o0
a010baa4:  81 c3 e0 08  retl
a010baa8:  90 40 20 00  addx  %g0, 0, %o0
