# leon2m FUN_a015bb44 0xa015bb44-0xa015bf7c (1080 bytes)
a015bb44:  9d e3 bf 98  save  %sp, -104, %sp
a015bb48:  e0 06 60 08  ld  [ %i1 + 8 ], %l0
a015bb4c:  80 a4 20 00  cmp  %l0, 0
a015bb50:  a6 10 20 00  clr  %l3
a015bb54:  02 80 01 08  be  0xa015bf74
a015bb58:  82 10 20 00  clr  %g1
a015bb5c:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015bb60:  80 88 60 08  btst  8, %g1
a015bb64:  02 80 00 06  be  0xa015bb7c
a015bb68:  9a 10 00 01  mov  %g1, %o5
a015bb6c:  c2 06 20 10  ld  [ %i0 + 0x10 ], %g1
a015bb70:  80 a0 60 00  cmp  %g1, 0
a015bb74:  12 80 00 09  bne  0xa015bb98
a015bb78:  83 2b 60 10  sll  %o5, 0x10, %g1
a015bb7c:  7f ff f8 5d  call  0xa0159cf0
a015bb80:  90 10 00 18  mov  %i0, %o0
a015bb84:  80 a2 20 00  cmp  %o0, 0
a015bb88:  12 80 00 fb  bne  0xa015bf74
a015bb8c:  82 10 3f ff  mov  -1, %g1
a015bb90:  da 16 20 0c  lduh  [ %i0 + 0xc ], %o5
a015bb94:  83 2b 60 10  sll  %o5, 0x10, %g1
a015bb98:  83 30 60 10  srl  %g1, 0x10, %g1
a015bb9c:  80 88 60 02  btst  2, %g1
a015bba0:  e4 06 40 00  ld  [ %i1 ], %l2
a015bba4:  02 80 00 1d  be  0xa015bc18
a015bba8:  a0 10 20 00  clr  %l0
a015bbac:  10 80 00 05  b  0xa015bbc0
a015bbb0:  80 a4 20 00  cmp  %l0, 0
a015bbb4:  e6 04 80 00  ld  [ %l2 ], %l3
a015bbb8:  a4 04 a0 08  add  %l2, 8, %l2
a015bbbc:  80 a4 20 00  cmp  %l0, 0
a015bbc0:  22 bf ff fd  be,a   0xa015bbb4
a015bbc4:  e0 04 a0 04  ld  [ %l2 + 4 ], %l0
a015bbc8:  80 a4 24 00  cmp  %l0, 0x400
a015bbcc:  d0 06 20 1c  ld  [ %i0 + 0x1c ], %o0
a015bbd0:  08 80 00 03  bleu  0xa015bbdc
a015bbd4:  94 10 00 10  mov  %l0, %o2
a015bbd8:  94 10 24 00  mov  0x400, %o2
a015bbdc:  c2 06 20 24  ld  [ %i0 + 0x24 ], %g1
a015bbe0:  9f c0 40 00  call  %g1
a015bbe4:  92 10 00 13  mov  %l3, %o1
a015bbe8:  a2 92 20 00  orcc  %o0, 0, %l1
a015bbec:  24 80 00 a4  ble,a   0xa015be7c
a015bbf0:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015bbf4:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a015bbf8:  82 20 40 11  sub  %g1, %l1, %g1
a015bbfc:  80 a0 60 00  cmp  %g1, 0
a015bc00:  a6 04 c0 11  add  %l3, %l1, %l3
a015bc04:  a0 24 00 11  sub  %l0, %l1, %l0
a015bc08:  12 bf ff ed  bne  0xa015bbbc
a015bc0c:  c2 26 60 08  st  %g1, [ %i1 + 8 ]
a015bc10:  10 80 00 d9  b  0xa015bf74
a015bc14:  82 10 20 00  clr  %g1
a015bc18:  80 88 60 01  btst  1, %g1
a015bc1c:  aa 10 20 00  clr  %l5
a015bc20:  02 80 00 4b  be  0xa015bd4c
a015bc24:  a8 10 20 00  clr  %l4
a015bc28:  80 a4 20 00  cmp  %l0, 0
a015bc2c:  12 80 00 3a  bne  0xa015bd14
a015bc30:  80 a5 60 00  cmp  %l5, 0
a015bc34:  e0 04 a0 04  ld  [ %l2 + 4 ], %l0
a015bc38:  e6 04 80 00  ld  [ %l2 ], %l3
a015bc3c:  80 a4 20 00  cmp  %l0, 0
a015bc40:  02 bf ff fd  be  0xa015bc34
a015bc44:  a4 04 a0 08  add  %l2, 8, %l2
a015bc48:  90 10 00 13  mov  %l3, %o0
a015bc4c:  92 10 20 0a  mov  0xa, %o1
a015bc50:  40 00 03 80  call  0xa015ca50
a015bc54:  94 10 00 10  mov  %l0, %o2
a015bc58:  82 22 00 13  sub  %o0, %l3, %g1
a015bc5c:  80 a2 20 00  cmp  %o0, 0
a015bc60:  02 80 00 70  be  0xa015be20
a015bc64:  a8 00 60 01  add  %g1, 1, %l4
a015bc68:  aa 10 20 01  mov  1, %l5
a015bc6c:  80 a5 00 10  cmp  %l4, %l0
a015bc70:  08 80 00 03  bleu  0xa015bc7c
a015bc74:  98 10 00 14  mov  %l4, %o4
a015bc78:  98 10 00 10  mov  %l0, %o4
a015bc7c:  c2 06 20 10  ld  [ %i0 + 0x10 ], %g1
a015bc80:  d0 06 00 00  ld  [ %i0 ], %o0
a015bc84:  80 a0 40 08  cmp  %g1, %o0
a015bc88:  da 06 20 08  ld  [ %i0 + 8 ], %o5
a015bc8c:  d6 06 20 14  ld  [ %i0 + 0x14 ], %o3
a015bc90:  a2 03 40 0b  add  %o5, %o3, %l1
a015bc94:  82 40 20 00  addx  %g0, 0, %g1
a015bc98:  80 a3 00 11  cmp  %o4, %l1
a015bc9c:  14 80 00 03  bg  0xa015bca8
a015bca0:  9a 10 20 01  mov  1, %o5
a015bca4:  9a 10 20 00  clr  %o5
a015bca8:  80 88 40 0d  btst  %g1, %o5
a015bcac:  12 80 00 a0  bne  0xa015bf2c
a015bcb0:  80 a2 c0 0c  cmp  %o3, %o4
a015bcb4:  14 80 00 8c  bg  0xa015bee4
a015bcb8:  a2 10 00 0c  mov  %o4, %l1
a015bcbc:  94 10 00 0b  mov  %o3, %o2
a015bcc0:  c2 06 20 24  ld  [ %i0 + 0x24 ], %g1
a015bcc4:  d0 06 20 1c  ld  [ %i0 + 0x1c ], %o0
a015bcc8:  9f c0 40 00  call  %g1
a015bccc:  92 10 00 13  mov  %l3, %o1
a015bcd0:  a2 92 20 00  orcc  %o0, 0, %l1
a015bcd4:  24 80 00 6a  ble,a   0xa015be7c
a015bcd8:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015bcdc:  a8 a5 00 11  subcc  %l4, %l1, %l4
a015bce0:  02 80 00 8c  be  0xa015bf10
a015bce4:  01 00 00 00  nop
a015bce8:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a015bcec:  82 20 40 11  sub  %g1, %l1, %g1
a015bcf0:  80 a0 60 00  cmp  %g1, 0
a015bcf4:  a6 04 c0 11  add  %l3, %l1, %l3
a015bcf8:  a0 24 00 11  sub  %l0, %l1, %l0
a015bcfc:  02 bf ff c5  be  0xa015bc10
a015bd00:  c2 26 60 08  st  %g1, [ %i1 + 8 ]
a015bd04:  80 a4 20 00  cmp  %l0, 0
a015bd08:  22 bf ff cc  be,a   0xa015bc38
a015bd0c:  e0 04 a0 04  ld  [ %l2 + 4 ], %l0
a015bd10:  80 a5 60 00  cmp  %l5, 0
a015bd14:  12 bf ff d7  bne  0xa015bc70
a015bd18:  80 a5 00 10  cmp  %l4, %l0
a015bd1c:  90 10 00 13  mov  %l3, %o0
a015bd20:  92 10 20 0a  mov  0xa, %o1
a015bd24:  40 00 03 4b  call  0xa015ca50
a015bd28:  94 10 00 10  mov  %l0, %o2
a015bd2c:  82 22 00 13  sub  %o0, %l3, %g1
a015bd30:  80 a2 20 00  cmp  %o0, 0
a015bd34:  12 bf ff cd  bne  0xa015bc68
a015bd38:  a8 00 60 01  add  %g1, 1, %l4
a015bd3c:  10 bf ff cb  b  0xa015bc68
a015bd40:  a8 04 20 01  add  %l0, 1, %l4
a015bd44:  e6 04 80 00  ld  [ %l2 ], %l3
a015bd48:  a4 04 a0 08  add  %l2, 8, %l2
a015bd4c:  80 a4 20 00  cmp  %l0, 0
a015bd50:  22 bf ff fd  be,a   0xa015bd44
a015bd54:  e0 04 a0 04  ld  [ %l2 + 4 ], %l0
a015bd58:  83 2b 60 10  sll  %o5, 0x10, %g1
a015bd5c:  83 30 60 10  srl  %g1, 0x10, %g1
a015bd60:  80 88 62 00  btst  0x200, %g1
a015bd64:  02 80 00 31  be  0xa015be28
a015bd68:  e2 06 20 08  ld  [ %i0 + 8 ], %l1
a015bd6c:  80 a4 40 10  cmp  %l1, %l0
a015bd70:  3a 80 00 07  bcc,a   0xa015bd8c
a015bd74:  d0 06 00 00  ld  [ %i0 ], %o0
a015bd78:  80 88 60 80  btst  0x80, %g1
a015bd7c:  32 80 00 19  bne,a   0xa015bde0
a015bd80:  c2 06 00 00  ld  [ %i0 ], %g1
a015bd84:  d0 06 00 00  ld  [ %i0 ], %o0
a015bd88:  80 a4 40 10  cmp  %l1, %l0
a015bd8c:  38 80 00 02  bgu,a   0xa015bd94
a015bd90:  a2 10 00 10  mov  %l0, %l1
a015bd94:  94 10 00 11  mov  %l1, %o2
a015bd98:  40 00 03 64  call  0xa015cb28
a015bd9c:  92 10 00 13  mov  %l3, %o1
a015bda0:  c2 06 20 08  ld  [ %i0 + 8 ], %g1
a015bda4:  da 06 00 00  ld  [ %i0 ], %o5
a015bda8:  90 03 40 11  add  %o5, %l1, %o0
a015bdac:  82 20 40 11  sub  %g1, %l1, %g1
a015bdb0:  c2 26 20 08  st  %g1, [ %i0 + 8 ]
a015bdb4:  d0 26 00 00  st  %o0, [ %i0 ]
a015bdb8:  a2 10 00 10  mov  %l0, %l1
a015bdbc:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a015bdc0:  82 20 40 11  sub  %g1, %l1, %g1
a015bdc4:  80 a0 60 00  cmp  %g1, 0
a015bdc8:  a6 04 c0 11  add  %l3, %l1, %l3
a015bdcc:  a0 24 00 11  sub  %l0, %l1, %l0
a015bdd0:  02 bf ff 90  be  0xa015bc10
a015bdd4:  c2 26 60 08  st  %g1, [ %i1 + 8 ]
a015bdd8:  10 bf ff dd  b  0xa015bd4c
a015bddc:  da 16 20 0c  lduh  [ %i0 + 0xc ], %o5
a015bde0:  d2 06 20 10  ld  [ %i0 + 0x10 ], %o1
a015bde4:  a8 20 40 09  sub  %g1, %o1, %l4
a015bde8:  2b 2a 00 aa  sethi  %hi(0xa802a800), %l5
a015bdec:  a2 05 00 10  add  %l4, %l0, %l1
a015bdf0:  d0 05 62 18  ld  [ %l5 + 0x218 ], %o0
a015bdf4:  40 00 06 fc  call  0xa015d9e4
a015bdf8:  94 10 00 11  mov  %l1, %o2
a015bdfc:  82 92 20 00  orcc  %o0, 0, %g1
a015be00:  02 80 00 58  be  0xa015bf60
a015be04:  90 00 40 14  add  %g1, %l4, %o0
a015be08:  e2 26 20 14  st  %l1, [ %i0 + 0x14 ]
a015be0c:  c2 26 20 10  st  %g1, [ %i0 + 0x10 ]
a015be10:  d0 26 00 00  st  %o0, [ %i0 ]
a015be14:  e0 26 20 08  st  %l0, [ %i0 + 8 ]
a015be18:  10 bf ff dc  b  0xa015bd88
a015be1c:  a2 10 00 10  mov  %l0, %l1
a015be20:  10 bf ff 92  b  0xa015bc68
a015be24:  a8 04 20 01  add  %l0, 1, %l4
a015be28:  c2 06 20 10  ld  [ %i0 + 0x10 ], %g1
a015be2c:  d0 06 00 00  ld  [ %i0 ], %o0
a015be30:  80 a0 40 08  cmp  %g1, %o0
a015be34:  9a 40 20 00  addx  %g0, 0, %o5
a015be38:  80 a4 40 10  cmp  %l1, %l0
a015be3c:  82 40 20 00  addx  %g0, 0, %g1
a015be40:  80 8b 40 01  btst  %o5, %g1
a015be44:  12 80 00 1c  bne  0xa015beb4
a015be48:  92 10 00 13  mov  %l3, %o1
a015be4c:  e2 06 20 14  ld  [ %i0 + 0x14 ], %l1
a015be50:  80 a4 40 10  cmp  %l1, %l0
a015be54:  18 80 00 0e  bgu  0xa015be8c
a015be58:  94 10 00 11  mov  %l1, %o2
a015be5c:  c2 06 20 24  ld  [ %i0 + 0x24 ], %g1
a015be60:  d0 06 20 1c  ld  [ %i0 + 0x1c ], %o0
a015be64:  9f c0 40 00  call  %g1
a015be68:  92 10 00 13  mov  %l3, %o1
a015be6c:  a2 92 20 00  orcc  %o0, 0, %l1
a015be70:  34 bf ff d4  bg,a   0xa015bdc0
a015be74:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a015be78:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015be7c:  82 10 60 40  or  %g1, 0x40, %g1
a015be80:  c2 36 20 0c  sth  %g1, [ %i0 + 0xc ]
a015be84:  10 80 00 3c  b  0xa015bf74
a015be88:  82 10 3f ff  mov  -1, %g1
a015be8c:  40 00 03 27  call  0xa015cb28
a015be90:  94 10 00 10  mov  %l0, %o2
a015be94:  c2 06 20 08  ld  [ %i0 + 8 ], %g1
a015be98:  da 06 00 00  ld  [ %i0 ], %o5
a015be9c:  82 20 40 10  sub  %g1, %l0, %g1
a015bea0:  90 03 40 10  add  %o5, %l0, %o0
a015bea4:  a2 10 00 10  mov  %l0, %l1
a015bea8:  c2 26 20 08  st  %g1, [ %i0 + 8 ]
a015beac:  10 bf ff c4  b  0xa015bdbc
a015beb0:  d0 26 00 00  st  %o0, [ %i0 ]
a015beb4:  40 00 03 1d  call  0xa015cb28
a015beb8:  94 10 00 11  mov  %l1, %o2
a015bebc:  c2 06 00 00  ld  [ %i0 ], %g1
a015bec0:  90 00 40 11  add  %g1, %l1, %o0
a015bec4:  d0 26 00 00  st  %o0, [ %i0 ]
a015bec8:  7f ff fd 0e  call  0xa015b300
a015becc:  90 10 00 18  mov  %i0, %o0
a015bed0:  80 a2 20 00  cmp  %o0, 0
a015bed4:  22 bf ff bb  be,a   0xa015bdc0
a015bed8:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a015bedc:  10 bf ff e8  b  0xa015be7c
a015bee0:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015bee4:  92 10 00 13  mov  %l3, %o1
a015bee8:  40 00 03 10  call  0xa015cb28
a015beec:  94 10 00 0c  mov  %o4, %o2
a015bef0:  c2 06 20 08  ld  [ %i0 + 8 ], %g1
a015bef4:  da 06 00 00  ld  [ %i0 ], %o5
a015bef8:  82 20 40 11  sub  %g1, %l1, %g1
a015befc:  9a 03 40 11  add  %o5, %l1, %o5
a015bf00:  c2 26 20 08  st  %g1, [ %i0 + 8 ]
a015bf04:  a8 a5 00 11  subcc  %l4, %l1, %l4
a015bf08:  12 bf ff 78  bne  0xa015bce8
a015bf0c:  da 26 00 00  st  %o5, [ %i0 ]
a015bf10:  7f ff fc fc  call  0xa015b300
a015bf14:  90 10 00 18  mov  %i0, %o0
a015bf18:  80 a2 20 00  cmp  %o0, 0
a015bf1c:  12 bf ff d7  bne  0xa015be78
a015bf20:  aa 10 20 00  clr  %l5
a015bf24:  10 bf ff 72  b  0xa015bcec
a015bf28:  c2 06 60 08  ld  [ %i1 + 8 ], %g1
a015bf2c:  92 10 00 13  mov  %l3, %o1
a015bf30:  40 00 02 fe  call  0xa015cb28
a015bf34:  94 10 00 11  mov  %l1, %o2
a015bf38:  c2 06 00 00  ld  [ %i0 ], %g1
a015bf3c:  90 00 40 11  add  %g1, %l1, %o0
a015bf40:  d0 26 00 00  st  %o0, [ %i0 ]
a015bf44:  7f ff fc ef  call  0xa015b300
a015bf48:  90 10 00 18  mov  %i0, %o0
a015bf4c:  80 a2 20 00  cmp  %o0, 0
a015bf50:  22 bf ff 64  be,a   0xa015bce0
a015bf54:  a8 a5 00 11  subcc  %l4, %l1, %l4
a015bf58:  10 bf ff c9  b  0xa015be7c
a015bf5c:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015bf60:  d0 05 62 18  ld  [ %l5 + 0x218 ], %o0
a015bf64:  7f ff fe 57  call  0xa015b8c0
a015bf68:  d2 06 20 10  ld  [ %i0 + 0x10 ], %o1
a015bf6c:  10 bf ff c4  b  0xa015be7c
a015bf70:  c2 16 20 0c  lduh  [ %i0 + 0xc ], %g1
a015bf74:  81 c7 e0 08  ret
a015bf78:  91 e8 00 01  restore  %g0, %g1, %o0
