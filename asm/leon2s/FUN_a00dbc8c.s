# leon2s FUN_a00dbc8c 0xa00dbc8c-0xa00dbe74 (488 bytes)
a00dbc8c:  9d e3 bf 98  save  %sp, -104, %sp
a00dbc90:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbc94:  c2 08 60 40  ldub  [ %g1 + 0x40 ], %g1	! 0xa8078840
a00dbc98:  80 a0 60 00  cmp  %g1, 0
a00dbc9c:  a2 10 20 00  clr  %l1
a00dbca0:  12 80 00 0e  bne  0xa00dbcd8
a00dbca4:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00dbca8:  c2 08 60 99  ldub  [ %g1 + 0x99 ], %g1	! 0xa8076099
a00dbcac:  80 a0 60 00  cmp  %g1, 0
a00dbcb0:  12 80 00 06  bne  0xa00dbcc8
a00dbcb4:  80 a0 60 01  cmp  %g1, 1
a00dbcb8:  9a 10 20 01  mov  1, %o5
a00dbcbc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbcc0:  10 80 00 6b  b  0xa00dbe6c
a00dbcc4:  da 28 60 3f  stb  %o5, [ %g1 + 0x3f ]	! 0xa807883f
a00dbcc8:  12 80 00 69  bne  0xa00dbe6c
a00dbccc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbcd0:  10 80 00 67  b  0xa00dbe6c
a00dbcd4:  c0 28 60 3f  clrb  [ %g1 + 0x3f ]	! 0xa807883f
a00dbcd8:  a0 10 00 01  mov  %g1, %l0
a00dbcdc:  c2 08 60 99  ldub  [ %g1 + 0x99 ], %g1
a00dbce0:  80 a0 60 02  cmp  %g1, 2
a00dbce4:  02 80 00 3f  be  0xa00dbde0
a00dbce8:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00dbcec:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00dbcf0:  90 12 23 d8  or  %o0, 0x3d8, %o0
a00dbcf4:  40 3a 9c d4  call  0xa0f83044
a00dbcf8:  d2 0c 60 3f  ldub  [ %l1 + 0x3f ], %o1
a00dbcfc:  c2 0c 20 99  ldub  [ %l0 + 0x99 ], %g1
a00dbd00:  80 a0 60 00  cmp  %g1, 0
a00dbd04:  12 80 00 18  bne  0xa00dbd64
a00dbd08:  80 a0 60 01  cmp  %g1, 1
a00dbd0c:  c2 0c 60 3f  ldub  [ %l1 + 0x3f ], %g1
a00dbd10:  80 a0 60 00  cmp  %g1, 0
a00dbd14:  32 80 00 13  bne,a   0xa00dbd60
a00dbd18:  c2 0c 20 99  ldub  [ %l0 + 0x99 ], %g1
a00dbd1c:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00dbd20:  92 10 20 00  clr  %o1
a00dbd24:  40 3a 9c c8  call  0xa0f83044
a00dbd28:  90 12 23 f8  or  %o0, 0x3f8, %o0
a00dbd2c:  7f ff ff 2a  call  0xa00db9d4
a00dbd30:  01 00 00 00  nop
a00dbd34:  7f ff ff 4f  call  0xa00dba70
a00dbd38:  90 10 20 01  mov  1, %o0	! 0x1
a00dbd3c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00dbd40:  9a 10 20 01  mov  1, %o5
a00dbd44:  c0 28 60 98  clrb  [ %g1 + 0x98 ]
a00dbd48:  da 2c 60 3f  stb  %o5, [ %l1 + 0x3f ]
a00dbd4c:  80 8a 20 ff  btst  0xff, %o0
a00dbd50:  12 80 00 1f  bne  0xa00dbdcc
a00dbd54:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbd58:  10 80 00 18  b  0xa00dbdb8
a00dbd5c:  da 28 60 3d  stb  %o5, [ %g1 + 0x3d ]	! 0xa807883d
a00dbd60:  80 a0 60 01  cmp  %g1, 1
a00dbd64:  12 80 00 1c  bne  0xa00dbdd4
a00dbd68:  9a 10 20 02  mov  2, %o5
a00dbd6c:  e0 0c 60 3f  ldub  [ %l1 + 0x3f ], %l0
a00dbd70:  80 a4 20 01  cmp  %l0, 1
a00dbd74:  32 80 00 19  bne,a   0xa00dbdd8
a00dbd78:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00dbd7c:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00dbd80:  92 10 20 01  mov  1, %o1
a00dbd84:  40 3a 9c b0  call  0xa0f83044
a00dbd88:  90 12 23 f8  or  %o0, 0x3f8, %o0
a00dbd8c:  7f ff ff 12  call  0xa00db9d4
a00dbd90:  01 00 00 00  nop
a00dbd94:  7f ff ff 37  call  0xa00dba70
a00dbd98:  90 10 20 00  clr  %o0	! 0x0
a00dbd9c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00dbda0:  e0 28 60 98  stb  %l0, [ %g1 + 0x98 ]	! 0xa8076098
a00dbda4:  c0 2c 60 3f  clrb  [ %l1 + 0x3f ]
a00dbda8:  80 8a 20 ff  btst  0xff, %o0
a00dbdac:  12 80 00 08  bne  0xa00dbdcc
a00dbdb0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbdb4:  e0 28 60 3d  stb  %l0, [ %g1 + 0x3d ]	! 0xa807883d
a00dbdb8:  40 3b 98 ab  call  0xa0fc2064
a00dbdbc:  01 00 00 00  nop
a00dbdc0:  03 2a 01 e9  sethi  %hi(0xa807a400), %g1
a00dbdc4:  10 80 00 03  b  0xa00dbdd0
a00dbdc8:  d0 20 61 18  st  %o0, [ %g1 + 0x118 ]	! 0xa807a518
a00dbdcc:  c0 28 60 3d  clrb  [ %g1 + 0x3d ]
a00dbdd0:  9a 10 20 02  mov  2, %o5
a00dbdd4:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00dbdd8:  10 80 00 25  b  0xa00dbe6c
a00dbddc:  da 28 60 99  stb  %o5, [ %g1 + 0x99 ]	! 0xa8076099
a00dbde0:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a00dbde4:  c2 0c 20 3d  ldub  [ %l0 + 0x3d ], %g1	! 0xa807883d
a00dbde8:  80 a0 60 00  cmp  %g1, 0
a00dbdec:  02 80 00 20  be  0xa00dbe6c
a00dbdf0:  01 00 00 00  nop
a00dbdf4:  40 3b 98 9c  call  0xa0fc2064
a00dbdf8:  25 2a 01 e9  sethi  %hi(0xa807a400), %l2
a00dbdfc:  c2 04 a1 18  ld  [ %l2 + 0x118 ], %g1	! 0xa807a518
a00dbe00:  90 22 00 01  sub  %o0, %g1, %o0
a00dbe04:  80 a2 21 f4  cmp  %o0, 0x1f4
a00dbe08:  08 80 00 19  bleu  0xa00dbe6c
a00dbe0c:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00dbe10:  c2 08 60 98  ldub  [ %g1 + 0x98 ], %g1	! 0xa8076098
a00dbe14:  80 a0 60 00  cmp  %g1, 0
a00dbe18:  12 80 00 06  bne  0xa00dbe30
a00dbe1c:  80 a0 60 01  cmp  %g1, 1
a00dbe20:  7f ff fe ed  call  0xa00db9d4
a00dbe24:  01 00 00 00  nop
a00dbe28:  10 80 00 07  b  0xa00dbe44
a00dbe2c:  90 10 20 01  mov  1, %o0	! 0x1
a00dbe30:  12 80 00 09  bne  0xa00dbe54
a00dbe34:  80 8c 60 ff  btst  0xff, %l1
a00dbe38:  7f ff fe e7  call  0xa00db9d4
a00dbe3c:  01 00 00 00  nop
a00dbe40:  90 10 20 00  clr  %o0	! 0x0
a00dbe44:  7f ff ff 0b  call  0xa00dba70
a00dbe48:  01 00 00 00  nop
a00dbe4c:  a2 10 00 08  mov  %o0, %l1
a00dbe50:  80 8c 60 ff  btst  0xff, %l1
a00dbe54:  32 80 00 06  bne,a   0xa00dbe6c
a00dbe58:  c0 2c 20 3d  clrb  [ %l0 + 0x3d ]
a00dbe5c:  82 10 20 01  mov  1, %g1
a00dbe60:  40 3b 98 81  call  0xa0fc2064
a00dbe64:  c2 2c 20 3d  stb  %g1, [ %l0 + 0x3d ]
a00dbe68:  d0 24 a1 18  st  %o0, [ %l2 + 0x118 ]
a00dbe6c:  81 c7 e0 08  ret
a00dbe70:  81 e8 00 00  restore
