# leon2s MODEDET_handler_2 0xa009d87c-0xa009dd40 (1220 bytes)
a009d87c:  9d e3 bf 88  save  %sp, -120, %sp
a009d880:  13 28 02 d1  sethi  %hi(0xa00b4400), %o1
a009d884:  92 12 60 fc  or  %o1, 0xfc, %o1	! 0xa00b44fc
a009d888:  90 07 bf e8  add  %fp, -24, %o0
a009d88c:  40 00 4f 53  call  0xa00b15d8
a009d890:  94 10 20 10  mov  0x10, %o2
a009d894:  a6 10 20 02  mov  2, %l3
a009d898:  a4 0e 20 ff  and  %i0, 0xff, %l2
a009d89c:  80 a4 a0 00  cmp  %l2, 0
a009d8a0:  aa 10 20 00  clr  %l5
a009d8a4:  02 80 00 07  be  0xa009d8c0
a009d8a8:  a0 10 00 13  mov  %l3, %l0
a009d8ac:  80 a4 a0 01  cmp  %l2, 1
a009d8b0:  12 80 01 22  bne  0xa009dd38
a009d8b4:  a6 10 20 03  mov  3, %l3
a009d8b8:  aa 10 20 01  mov  1, %l5
a009d8bc:  a0 10 20 03  mov  3, %l0
a009d8c0:  29 2a 01 f6  sethi  %hi(0xa807d800), %l4
a009d8c4:  9a 15 23 00  or  %l4, 0x300, %o5	! 0xa807db00
a009d8c8:  82 5c a0 34  smul  %l2, 0x34, %g1
a009d8cc:  82 00 40 0d  add  %g1, %o5, %g1
a009d8d0:  c2 00 60 04  ld  [ %g1 + 4 ], %g1
a009d8d4:  c2 00 60 44  ld  [ %g1 + 0x44 ], %g1
a009d8d8:  82 08 60 60  and  %g1, 0x60, %g1
a009d8dc:  80 a0 60 60  cmp  %g1, 0x60
a009d8e0:  12 80 00 10  bne  0xa009d920
a009d8e4:  80 a4 a0 00  cmp  %l2, 0
a009d8e8:  02 80 00 07  be  0xa009d904
a009d8ec:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a009d8f0:  80 a4 a0 01  cmp  %l2, 1
a009d8f4:  02 80 00 08  be  0xa009d914
a009d8f8:  9a 13 62 40  or  %o5, 0x240, %o5
a009d8fc:  10 80 00 19  b  0xa009d960
a009d900:  82 15 23 00  or  %l4, 0x300, %g1
a009d904:  9a 13 62 40  or  %o5, 0x240, %o5
a009d908:  c2 03 40 00  ld  [ %o5 ], %g1
a009d90c:  10 80 00 13  b  0xa009d958
a009d910:  82 10 60 40  or  %g1, 0x40, %g1
a009d914:  c2 03 40 00  ld  [ %o5 ], %g1
a009d918:  10 80 00 10  b  0xa009d958
a009d91c:  82 10 60 80  or  %g1, 0x80, %g1
a009d920:  02 80 00 07  be  0xa009d93c
a009d924:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a009d928:  80 a4 a0 01  cmp  %l2, 1
a009d92c:  02 80 00 08  be  0xa009d94c
a009d930:  82 15 23 00  or  %l4, 0x300, %g1
a009d934:  10 80 00 0c  b  0xa009d964
a009d938:  9a 5c a0 34  smul  %l2, 0x34, %o5
a009d93c:  9a 13 62 40  or  %o5, 0x240, %o5
a009d940:  c2 03 40 00  ld  [ %o5 ], %g1
a009d944:  10 80 00 05  b  0xa009d958
a009d948:  82 08 7f bf  and  %g1, -65, %g1
a009d94c:  9a 13 62 40  or  %o5, 0x240, %o5
a009d950:  c2 03 40 00  ld  [ %o5 ], %g1
a009d954:  82 08 7f 7f  and  %g1, -129, %g1
a009d958:  c2 23 40 00  st  %g1, [ %o5 ]
a009d95c:  82 15 23 00  or  %l4, 0x300, %g1
a009d960:  9a 5c a0 34  smul  %l2, 0x34, %o5
a009d964:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a009d968:  92 02 60 08  add  %o1, 8, %o1
a009d96c:  40 00 26 a7  call  0xa00a7408
a009d970:  90 10 20 0b  mov  0xb, %o0
a009d974:  80 a2 20 00  cmp  %o0, 0
a009d978:  02 80 00 12  be  0xa009d9c0
a009d97c:  92 10 20 80  mov  0x80, %o1
a009d980:  90 0c 20 03  and  %l0, 3, %o0
a009d984:  80 a6 60 06  cmp  %i1, 6
a009d988:  02 80 00 11  be  0xa009d9cc
a009d98c:  94 10 20 60  mov  0x60, %o2
a009d990:  80 a6 60 06  cmp  %i1, 6
a009d994:  18 80 00 09  bgu  0xa009d9b8
a009d998:  80 a6 60 07  cmp  %i1, 7
a009d99c:  90 0c 20 03  and  %l0, 3, %o0
a009d9a0:  92 10 20 80  mov  0x80, %o1
a009d9a4:  80 a6 60 05  cmp  %i1, 5
a009d9a8:  02 80 00 09  be  0xa009d9cc
a009d9ac:  94 10 20 50  mov  0x50, %o2
a009d9b0:  10 80 00 07  b  0xa009d9cc
a009d9b4:  94 10 20 40  mov  0x40, %o2
a009d9b8:  02 80 00 05  be  0xa009d9cc
a009d9bc:  94 10 20 80  mov  0x80, %o2
a009d9c0:  90 0c 20 03  and  %l0, 3, %o0
a009d9c4:  92 10 20 80  mov  0x80, %o1
a009d9c8:  94 10 20 40  mov  0x40, %o2
a009d9cc:  40 00 50 cd  call  0xa00b1d00
a009d9d0:  a2 15 23 00  or  %l4, 0x300, %l1
a009d9d4:  a0 5c a0 34  smul  %l2, 0x34, %l0
a009d9d8:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009d9dc:  92 02 60 84  add  %o1, 0x84, %o1
a009d9e0:  40 00 26 8a  call  0xa00a7408
a009d9e4:  90 10 20 14  mov  0x14, %o0
a009d9e8:  80 a2 20 00  cmp  %o0, 0
a009d9ec:  12 80 00 93  bne  0xa009dc38
a009d9f0:  80 a6 60 06  cmp  %i1, 6
a009d9f4:  22 80 00 56  be,a   0xa009db4c
a009d9f8:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009d9fc:  18 80 00 06  bgu  0xa009da14
a009da00:  80 a6 60 07  cmp  %i1, 7
a009da04:  80 a6 60 05  cmp  %i1, 5
a009da08:  22 80 00 38  be,a   0xa009dae8
a009da0c:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009da10:  30 80 00 03  b,a   0xa009da1c
a009da14:  22 80 00 67  be,a   0xa009dbb0
a009da18:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009da1c:  40 00 0a 6b  call  0xa00a03c8
a009da20:  90 10 00 12  mov  %l2, %o0
a009da24:  90 0a 20 ff  and  %o0, 0xff, %o0
a009da28:  80 a2 20 01  cmp  %o0, 1
a009da2c:  12 80 00 0e  bne  0xa009da64
a009da30:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009da34:  a2 15 23 00  or  %l4, 0x300, %l1
a009da38:  a0 5c a0 34  smul  %l2, 0x34, %l0
a009da3c:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009da40:  92 02 60 b4  add  %o1, 0xb4, %o1
a009da44:  40 00 26 64  call  0xa00a73d4
a009da48:  90 10 20 02  mov  2, %o0
a009da4c:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a009da50:  c2 03 60 44  ld  [ %o5 + 0x44 ], %g1
a009da54:  82 08 70 ff  and  %g1, -3841, %g1
a009da58:  82 10 64 00  or  %g1, 0x400, %g1
a009da5c:  c2 23 60 44  st  %g1, [ %o5 + 0x44 ]
a009da60:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009da64:  9a 5c a0 34  smul  %l2, 0x34, %o5
a009da68:  82 10 63 00  or  %g1, 0x300, %g1
a009da6c:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a009da70:  92 02 60 40  add  %o1, 0x40, %o1
a009da74:  40 00 26 4e  call  0xa00a73ac
a009da78:  90 10 20 0d  mov  0xd, %o0
a009da7c:  7f ff bf 61  call  0xa008d800
a009da80:  01 00 00 00  nop
a009da84:  90 0a 20 ff  and  %o0, 0xff, %o0
a009da88:  80 a2 20 81  cmp  %o0, 0x81
a009da8c:  08 80 00 0a  bleu  0xa009dab4
a009da90:  90 0d 60 01  and  %l5, 1, %o0
a009da94:  90 10 00 12  mov  %l2, %o0
a009da98:  40 00 11 3b  call  0xa00a1f84
a009da9c:  92 10 20 04  mov  4, %o1
a009daa0:  90 10 00 12  mov  %l2, %o0
a009daa4:  40 00 11 5b  call  0xa00a2010
a009daa8:  92 10 20 00  clr  %o1
a009daac:  10 80 00 06  b  0xa009dac4
a009dab0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009dab4:  92 10 20 c0  mov  0xc0, %o1
a009dab8:  40 00 50 92  call  0xa00b1d00
a009dabc:  94 10 20 c0  mov  0xc0, %o2
a009dac0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009dac4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009dac8:  80 88 60 04  btst  4, %g1
a009dacc:  22 80 00 8a  be,a   0xa009dcf4
a009dad0:  82 06 7f fc  add  %i1, -4, %g1
a009dad4:  92 06 20 41  add  %i0, 0x41, %o1
a009dad8:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009dadc:  93 2a 60 18  sll  %o1, 0x18, %o1
a009dae0:  10 80 00 82  b  0xa009dce8
a009dae4:  90 12 22 58  or  %o0, 0x258, %o0
a009dae8:  92 02 60 40  add  %o1, 0x40, %o1
a009daec:  40 00 26 3a  call  0xa00a73d4
a009daf0:  90 10 20 0d  mov  0xd, %o0
a009daf4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009daf8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009dafc:  80 88 60 04  btst  4, %g1
a009db00:  02 80 00 07  be  0xa009db1c
a009db04:  92 06 20 41  add  %i0, 0x41, %o1
a009db08:  93 2a 60 18  sll  %o1, 0x18, %o1
a009db0c:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009db10:  90 12 22 80  or  %o0, 0x280, %o0	! 0xa006aa80
a009db14:  7f ff 55 4c  call  0xa0073044
a009db18:  93 3a 60 18  sra  %o1, 0x18, %o1
a009db1c:  7f ff bf 39  call  0xa008d800
a009db20:  01 00 00 00  nop
a009db24:  90 0a 20 ff  and  %o0, 0xff, %o0
a009db28:  80 a2 20 81  cmp  %o0, 0x81
a009db2c:  28 80 00 05  bleu,a   0xa009db40
a009db30:  90 0d 60 01  and  %l5, 1, %o0
a009db34:  90 10 00 12  mov  %l2, %o0
a009db38:  10 80 00 33  b  0xa009dc04
a009db3c:  92 10 20 05  mov  5, %o1
a009db40:  92 10 20 c0  mov  0xc0, %o1
a009db44:  10 80 00 39  b  0xa009dc28
a009db48:  94 10 20 f0  mov  0xf0, %o2
a009db4c:  92 02 60 40  add  %o1, 0x40, %o1
a009db50:  40 00 26 21  call  0xa00a73d4
a009db54:  90 10 20 0d  mov  0xd, %o0
a009db58:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009db5c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009db60:  80 88 60 04  btst  4, %g1
a009db64:  02 80 00 07  be  0xa009db80
a009db68:  92 06 20 41  add  %i0, 0x41, %o1
a009db6c:  93 2a 60 18  sll  %o1, 0x18, %o1
a009db70:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009db74:  90 12 22 a8  or  %o0, 0x2a8, %o0	! 0xa006aaa8
a009db78:  7f ff 55 33  call  0xa0073044
a009db7c:  93 3a 60 18  sra  %o1, 0x18, %o1
a009db80:  7f ff bf 20  call  0xa008d800
a009db84:  01 00 00 00  nop
a009db88:  90 0a 20 ff  and  %o0, 0xff, %o0
a009db8c:  80 a2 20 81  cmp  %o0, 0x81
a009db90:  28 80 00 05  bleu,a   0xa009dba4
a009db94:  90 0d 60 01  and  %l5, 1, %o0
a009db98:  90 10 00 12  mov  %l2, %o0
a009db9c:  10 80 00 1a  b  0xa009dc04
a009dba0:  92 10 20 06  mov  6, %o1
a009dba4:  92 10 20 c0  mov  0xc0, %o1
a009dba8:  10 80 00 20  b  0xa009dc28
a009dbac:  94 10 21 20  mov  0x120, %o2
a009dbb0:  92 02 60 40  add  %o1, 0x40, %o1
a009dbb4:  40 00 26 08  call  0xa00a73d4
a009dbb8:  90 10 20 0d  mov  0xd, %o0
a009dbbc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009dbc0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009dbc4:  80 88 60 04  btst  4, %g1
a009dbc8:  02 80 00 07  be  0xa009dbe4
a009dbcc:  92 06 20 41  add  %i0, 0x41, %o1
a009dbd0:  93 2a 60 18  sll  %o1, 0x18, %o1
a009dbd4:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009dbd8:  90 12 22 d0  or  %o0, 0x2d0, %o0	! 0xa006aad0
a009dbdc:  7f ff 55 1a  call  0xa0073044
a009dbe0:  93 3a 60 18  sra  %o1, 0x18, %o1
a009dbe4:  7f ff bf 07  call  0xa008d800
a009dbe8:  01 00 00 00  nop
a009dbec:  90 0a 20 ff  and  %o0, 0xff, %o0
a009dbf0:  80 a2 20 81  cmp  %o0, 0x81
a009dbf4:  08 80 00 0b  bleu  0xa009dc20
a009dbf8:  90 0d 60 01  and  %l5, 1, %o0
a009dbfc:  90 10 00 12  mov  %l2, %o0
a009dc00:  92 10 20 07  mov  7, %o1
a009dc04:  40 00 10 e0  call  0xa00a1f84
a009dc08:  01 00 00 00  nop
a009dc0c:  90 10 00 12  mov  %l2, %o0
a009dc10:  40 00 11 00  call  0xa00a2010
a009dc14:  92 10 20 01  mov  1, %o1
a009dc18:  10 80 00 37  b  0xa009dcf4
a009dc1c:  82 06 7f fc  add  %i1, -4, %g1
a009dc20:  92 10 20 c0  mov  0xc0, %o1
a009dc24:  94 10 21 80  mov  0x180, %o2
a009dc28:  40 00 50 36  call  0xa00b1d00
a009dc2c:  01 00 00 00  nop
a009dc30:  10 80 00 31  b  0xa009dcf4
a009dc34:  82 06 7f fc  add  %i1, -4, %g1
a009dc38:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009dc3c:  92 02 60 40  add  %o1, 0x40, %o1
a009dc40:  40 00 25 e5  call  0xa00a73d4
a009dc44:  90 10 20 0d  mov  0xd, %o0
a009dc48:  80 a6 60 06  cmp  %i1, 6
a009dc4c:  02 80 00 13  be  0xa009dc98
a009dc50:  13 00 00 07  sethi  %hi(0x1c00), %o1
a009dc54:  18 80 00 06  bgu  0xa009dc6c
a009dc58:  80 a6 60 07  cmp  %i1, 7
a009dc5c:  80 a6 60 05  cmp  %i1, 5
a009dc60:  02 80 00 0a  be  0xa009dc88
a009dc64:  90 0c e0 03  and  %l3, 3, %o0
a009dc68:  30 80 00 04  b,a   0xa009dc78
a009dc6c:  02 80 00 10  be  0xa009dcac
a009dc70:  13 00 00 07  sethi  %hi(0x1c00), %o1
a009dc74:  90 0c e0 03  and  %l3, 3, %o0
a009dc78:  92 12 63 08  or  %o1, 0x308, %o1
a009dc7c:  94 10 3f f8  mov  -8, %o2
a009dc80:  10 80 00 0f  b  0xa009dcbc
a009dc84:  96 10 20 04  mov  4, %o3
a009dc88:  92 12 63 08  or  %o1, 0x308, %o1
a009dc8c:  94 10 3f f8  mov  -8, %o2
a009dc90:  10 80 00 0b  b  0xa009dcbc
a009dc94:  96 10 20 05  mov  5, %o3
a009dc98:  90 0c e0 03  and  %l3, 3, %o0
a009dc9c:  92 12 63 08  or  %o1, 0x308, %o1
a009dca0:  94 10 3f f8  mov  -8, %o2
a009dca4:  10 80 00 06  b  0xa009dcbc
a009dca8:  96 10 20 06  mov  6, %o3
a009dcac:  90 0c e0 03  and  %l3, 3, %o0
a009dcb0:  92 12 63 08  or  %o1, 0x308, %o1
a009dcb4:  94 10 3f f8  mov  -8, %o2
a009dcb8:  96 10 20 07  mov  7, %o3
a009dcbc:  40 00 25 f3  call  0xa00a7488
a009dcc0:  01 00 00 00  nop
a009dcc4:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009dcc8:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a009dccc:  80 88 60 04  btst  4, %g1
a009dcd0:  22 80 00 09  be,a   0xa009dcf4
a009dcd4:  82 06 7f fc  add  %i1, -4, %g1
a009dcd8:  92 06 20 41  add  %i0, 0x41, %o1
a009dcdc:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009dce0:  93 2a 60 18  sll  %o1, 0x18, %o1
a009dce4:  90 12 22 f8  or  %o0, 0x2f8, %o0
a009dce8:  7f ff 54 d7  call  0xa0073044
a009dcec:  93 3a 60 18  sra  %o1, 0x18, %o1
a009dcf0:  82 06 7f fc  add  %i1, -4, %g1
a009dcf4:  80 a0 60 03  cmp  %g1, 3
a009dcf8:  92 0e 20 ff  and  %i0, 0xff, %o1
a009dcfc:  18 80 00 0a  bgu  0xa009dd24
a009dd00:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009dd04:  98 10 63 e0  or  %g1, 0x3e0, %o4	! 0xa807d7e0
a009dd08:  9b 2e 60 02  sll  %i1, 2, %o5
a009dd0c:  82 5a 61 90  smul  %o1, 0x190, %g1
a009dd10:  9a 07 80 0d  add  %fp, %o5, %o5
a009dd14:  82 00 40 0c  add  %g1, %o4, %g1
a009dd18:  da 03 7f d8  ld  [ %o5 + -40 ], %o5
a009dd1c:  10 80 00 07  b  0xa009dd38
a009dd20:  da 28 60 19  stb  %o5, [ %g1 + 0x19 ]
a009dd24:  82 10 63 e0  or  %g1, 0x3e0, %g1
a009dd28:  9a 5a 61 90  smul  %o1, 0x190, %o5
a009dd2c:  9a 03 40 01  add  %o5, %g1, %o5
a009dd30:  82 10 20 08  mov  8, %g1
a009dd34:  c2 2b 60 19  stb  %g1, [ %o5 + 0x19 ]
a009dd38:  81 c7 e0 08  ret
a009dd3c:  81 e8 00 00  restore
