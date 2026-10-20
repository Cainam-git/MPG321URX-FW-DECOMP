# leon2s FUN_a008b9ec 0xa008b9ec-0xa008bc44 (600 bytes)
a008b9ec:  9d e3 bf 98  save  %sp, -104, %sp
a008b9f0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a008b9f4:  80 a4 20 01  cmp  %l0, 1
a008b9f8:  02 80 00 08  be  0xa008ba18
a008b9fc:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a008ba00:  82 10 60 24  or  %g1, 0x24, %g1	! 0xa807a824
a008ba04:  c2 08 60 50  ldub  [ %g1 + 0x50 ], %g1
a008ba08:  80 a0 60 05  cmp  %g1, 5
a008ba0c:  02 80 00 08  be  0xa008ba2c
a008ba10:  a2 10 20 04  mov  4, %l1
a008ba14:  30 80 00 8a  b,a   0xa008bc3c
a008ba18:  82 10 60 24  or  %g1, 0x24, %g1
a008ba1c:  c2 08 60 64  ldub  [ %g1 + 0x64 ], %g1
a008ba20:  80 a0 60 05  cmp  %g1, 5
a008ba24:  12 80 00 86  bne  0xa008bc3c
a008ba28:  a2 10 20 06  mov  6, %l1
a008ba2c:  7f ff ff 83  call  0xa008b838
a008ba30:  90 10 00 10  mov  %l0, %o0
a008ba34:  82 10 20 01  mov  1, %g1
a008ba38:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a008ba3c:  a5 28 40 10  sll  %g1, %l0, %l2
a008ba40:  d8 0c e3 54  ldub  [ %l3 + 0x354 ], %o4
a008ba44:  82 0b 00 12  and  %o4, %l2, %g1
a008ba48:  80 a0 40 12  cmp  %g1, %l2
a008ba4c:  02 80 00 0d  be  0xa008ba80
a008ba50:  a8 10 00 08  mov  %o0, %l4
a008ba54:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008ba58:  9b 2c 20 02  sll  %l0, 2, %o5
a008ba5c:  82 10 63 3c  or  %g1, 0x33c, %g1
a008ba60:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a008ba64:  82 22 00 01  sub  %o0, %g1, %g1
a008ba68:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a008ba6c:  82 1b 40 01  xor  %o5, %g1, %g1
a008ba70:  82 20 40 0d  sub  %g1, %o5, %g1
a008ba74:  80 a0 60 14  cmp  %g1, 0x14
a008ba78:  04 80 00 57  ble  0xa008bbd4
a008ba7c:  83 3b 00 10  sra  %o4, %l0, %g1
a008ba80:  7f ff ff 95  call  0xa008b8d4
a008ba84:  90 10 00 10  mov  %l0, %o0
a008ba88:  90 0a 20 ff  and  %o0, 0xff, %o0
a008ba8c:  80 a2 20 01  cmp  %o0, 1
a008ba90:  12 80 00 60  bne  0xa008bc10
a008ba94:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008ba98:  7f ff ff 97  call  0xa008b8f4
a008ba9c:  90 10 00 10  mov  %l0, %o0
a008baa0:  90 0a 20 ff  and  %o0, 0xff, %o0
a008baa4:  80 a2 20 01  cmp  %o0, 1
a008baa8:  12 80 00 5a  bne  0xa008bc10
a008baac:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008bab0:  a2 0c 60 ff  and  %l1, 0xff, %l1
a008bab4:  7f ff f9 39  call  0xa0089f98
a008bab8:  90 10 00 11  mov  %l1, %o0
a008babc:  91 2a 20 10  sll  %o0, 0x10, %o0
a008bac0:  80 a2 20 00  cmp  %o0, 0
a008bac4:  02 80 00 41  be  0xa008bbc8
a008bac8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008bacc:  83 2c 20 02  sll  %l0, 2, %g1
a008bad0:  82 00 40 10  add  %g1, %l0, %g1
a008bad4:  1b 2a 01 ea  sethi  %hi(0xa807a800), %o5
a008bad8:  83 28 60 02  sll  %g1, 2, %g1
a008badc:  9a 13 60 24  or  %o5, 0x24, %o5
a008bae0:  82 00 40 0d  add  %g1, %o5, %g1
a008bae4:  c2 10 60 62  lduh  [ %g1 + 0x62 ], %g1
a008bae8:  80 88 60 40  btst  0x40, %g1
a008baec:  02 80 00 37  be  0xa008bbc8
a008baf0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008baf4:  98 10 63 38  or  %g1, 0x338, %o4	! 0xa8078b38
a008baf8:  c2 0b 00 10  ldub  [ %o4 + %l0 ], %g1
a008bafc:  82 00 60 01  inc  %g1
a008bb00:  9a 08 60 ff  and  %g1, 0xff, %o5
a008bb04:  80 a3 60 03  cmp  %o5, 3
a008bb08:  08 80 00 41  bleu  0xa008bc0c
a008bb0c:  c2 2b 00 10  stb  %g1, [ %o4 + %l0 ]
a008bb10:  c0 2b 00 10  clrb  [ %o4 + %l0 ]
a008bb14:  7f ff f9 4b  call  0xa008a040
a008bb18:  90 10 00 11  mov  %l1, %o0
a008bb1c:  90 0a 20 ff  and  %o0, 0xff, %o0
a008bb20:  7f ff ff 0f  call  0xa008b75c
a008bb24:  92 10 20 01  mov  1, %o1
a008bb28:  90 10 00 10  mov  %l0, %o0
a008bb2c:  7f ff ff a1  call  0xa008b9b0
a008bb30:  92 10 20 01  mov  1, %o1
a008bb34:  11 28 01 a3  sethi  %hi(0xa0068c00), %o0
a008bb38:  90 12 21 20  or  %o0, 0x120, %o0	! 0xa0068d20
a008bb3c:  7f ff 9d 42  call  0xa0073044
a008bb40:  92 10 00 10  mov  %l0, %o1
a008bb44:  80 a4 20 00  cmp  %l0, 0
a008bb48:  12 80 00 0c  bne  0xa008bb78
a008bb4c:  01 00 00 00  nop
a008bb50:  7f c4 ea d1  call  0x9f1c6694
a008bb54:  90 10 20 00  clr  %o0	! 0x0
a008bb58:  90 0a 20 ff  and  %o0, 0xff, %o0
a008bb5c:  80 a2 20 01  cmp  %o0, 1
a008bb60:  12 80 00 06  bne  0xa008bb78
a008bb64:  92 10 20 50  mov  0x50, %o1
a008bb68:  90 10 20 00  clr  %o0
a008bb6c:  94 10 20 10  mov  0x10, %o2
a008bb70:  40 00 6c 4a  call  0xa00a6c98
a008bb74:  96 10 20 01  mov  1, %o3
a008bb78:  7f ff ec 18  call  0xa0086bd8
a008bb7c:  01 00 00 00  nop
a008bb80:  7f ff ff 4b  call  0xa008b8ac
a008bb84:  90 10 00 10  mov  %l0, %o0
a008bb88:  96 10 20 01  mov  1, %o3
a008bb8c:  c2 0c e3 54  ldub  [ %l3 + 0x354 ], %g1
a008bb90:  9b 2a c0 10  sll  %o3, %l0, %o5
a008bb94:  9a 28 40 0d  andn  %g1, %o5, %o5
a008bb98:  82 10 20 10  mov  0x10, %g1
a008bb9c:  83 28 40 10  sll  %g1, %l0, %g1
a008bba0:  9a 13 40 01  or  %o5, %g1, %o5
a008bba4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008bba8:  82 10 63 3c  or  %g1, 0x33c, %g1	! 0xa8078b3c
a008bbac:  99 2c 20 02  sll  %l0, 2, %o4
a008bbb0:  e8 20 40 0c  st  %l4, [ %g1 + %o4 ]
a008bbb4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008bbb8:  82 10 63 48  or  %g1, 0x348, %g1	! 0xa8078b48
a008bbbc:  d6 28 40 10  stb  %o3, [ %g1 + %l0 ]
a008bbc0:  10 80 00 13  b  0xa008bc0c
a008bbc4:  da 2c e3 54  stb  %o5, [ %l3 + 0x354 ]
a008bbc8:  82 10 63 38  or  %g1, 0x338, %g1
a008bbcc:  10 80 00 10  b  0xa008bc0c
a008bbd0:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a008bbd4:  80 88 60 01  btst  1, %g1
a008bbd8:  12 80 00 0e  bne  0xa008bc10
a008bbdc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008bbe0:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a008bbe4:  c2 0c 63 31  ldub  [ %l1 + 0x331 ], %g1	! 0xa8078b31
a008bbe8:  83 38 40 10  sra  %g1, %l0, %g1
a008bbec:  80 88 60 01  btst  1, %g1
a008bbf0:  02 80 00 08  be  0xa008bc10
a008bbf4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008bbf8:  7f ff ff 4f  call  0xa008b934
a008bbfc:  90 10 00 10  mov  %l0, %o0
a008bc00:  c2 0c 63 31  ldub  [ %l1 + 0x331 ], %g1
a008bc04:  82 28 40 12  andn  %g1, %l2, %g1
a008bc08:  c2 2c 63 31  stb  %g1, [ %l1 + 0x331 ]
a008bc0c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008bc10:  c2 08 63 54  ldub  [ %g1 + 0x354 ], %g1	! 0xa8078b54
a008bc14:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008bc18:  83 38 40 18  sra  %g1, %i0, %g1
a008bc1c:  80 88 60 01  btst  1, %g1
a008bc20:  12 80 00 07  bne  0xa008bc3c
a008bc24:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008bc28:  9a 10 63 48  or  %g1, 0x348, %o5	! 0xa8078b48
a008bc2c:  c2 0b 40 18  ldub  [ %o5 + %i0 ], %g1
a008bc30:  80 a0 60 01  cmp  %g1, 1
a008bc34:  22 80 00 02  be,a   0xa008bc3c
a008bc38:  c0 2b 40 18  clrb  [ %o5 + %i0 ]
a008bc3c:  81 c7 e0 08  ret
a008bc40:  81 e8 00 00  restore
