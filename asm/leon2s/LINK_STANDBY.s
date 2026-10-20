# leon2s LINK_STANDBY 0xa006d7bc-0xa006e0e4 (2344 bytes)
a006d7bc:  9d e3 bf 80  save  %sp, -128, %sp
a006d7c0:  a2 0e 60 ff  and  %i1, 0xff, %l1
a006d7c4:  40 00 87 43  call  0xa008f4d0
a006d7c8:  90 10 00 11  mov  %l1, %o0
a006d7cc:  c2 0e 20 0d  ldub  [ %i0 + 0xd ], %g1
a006d7d0:  c2 2f bf e7  stb  %g1, [ %fp + -25 ]
a006d7d4:  c2 0e 20 0e  ldub  [ %i0 + 0xe ], %g1
a006d7d8:  a6 10 00 08  mov  %o0, %l3
a006d7dc:  80 a4 60 01  cmp  %l1, 1
a006d7e0:  f4 0e 00 00  ldub  [ %i0 ], %i2
a006d7e4:  18 80 02 3d  bgu  0xa006e0d8
a006d7e8:  c2 2f bf e6  stb  %g1, [ %fp + -26 ]
a006d7ec:  a8 0a 20 ff  and  %o0, 0xff, %l4
a006d7f0:  82 05 00 14  add  %l4, %l4, %g1
a006d7f4:  d8 16 20 12  lduh  [ %i0 + 0x12 ], %o4
a006d7f8:  82 00 40 14  add  %g1, %l4, %g1
a006d7fc:  37 2a 01 f3  sethi  %hi(0xa807cc00), %i3
a006d800:  83 28 60 03  sll  %g1, 3, %g1
a006d804:  99 33 20 07  srl  %o4, 7, %o4
a006d808:  9a 16 e0 64  or  %i3, 0x64, %o5
a006d80c:  82 00 40 0d  add  %g1, %o5, %g1
a006d810:  98 0b 20 01  and  %o4, 1, %o4
a006d814:  d8 28 60 06  stb  %o4, [ %g1 + 6 ]
a006d818:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006d81c:  82 00 7f ff  add  %g1, -1, %g1
a006d820:  80 a0 60 04  cmp  %g1, 4
a006d824:  38 80 02 08  bgu,a   0xa006e044
a006d828:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006d82c:  1b 28 01 b5  sethi  %hi(0xa006d400), %o5
a006d830:  83 28 60 02  sll  %g1, 2, %g1
a006d834:  9a 13 63 a8  or  %o5, 0x3a8, %o5
a006d838:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a006d83c:  81 c0 40 00  jmp  %g1
a006d840:  01 00 00 00  nop
a006d844:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006d848:  a0 10 60 78  or  %g1, 0x78, %l0	! 0xa8078878
a006d84c:  c2 0c 00 11  ldub  [ %l0 + %l1 ], %g1
a006d850:  80 a0 60 01  cmp  %g1, 1
a006d854:  32 80 01 fc  bne,a   0xa006e044
a006d858:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006d85c:  90 10 00 14  mov  %l4, %o0
a006d860:  40 00 1d 26  call  0xa0074cf8
a006d864:  92 10 20 00  clr  %o1
a006d868:  10 80 01 f6  b  0xa006e040
a006d86c:  c0 2c 00 11  clrb  [ %l0 + %l1 ]
a006d870:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006d874:  a0 10 60 78  or  %g1, 0x78, %l0	! 0xa8078878
a006d878:  c2 0c 00 11  ldub  [ %l0 + %l1 ], %g1
a006d87c:  80 a0 60 00  cmp  %g1, 0
a006d880:  32 80 00 07  bne,a   0xa006d89c
a006d884:  90 10 00 18  mov  %i0, %o0
a006d888:  40 00 1c fc  call  0xa0074c78
a006d88c:  90 10 00 14  mov  %l4, %o0
a006d890:  82 10 20 01  mov  1, %g1
a006d894:  c2 2c 00 11  stb  %g1, [ %l0 + %l1 ]
a006d898:  90 10 00 18  mov  %i0, %o0
a006d89c:  10 80 00 30  b  0xa006d95c
a006d8a0:  92 10 20 03  mov  3, %o1
a006d8a4:  40 00 1c e9  call  0xa0074c48
a006d8a8:  90 10 00 14  mov  %l4, %o0
a006d8ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a006d8b0:  80 a2 20 01  cmp  %o0, 1
a006d8b4:  32 80 01 e4  bne,a   0xa006e044
a006d8b8:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006d8bc:  40 00 87 0c  call  0xa008f4ec
a006d8c0:  90 10 00 11  mov  %l1, %o0
a006d8c4:  40 00 8f 17  call  0xa0091520
a006d8c8:  90 10 00 11  mov  %l1, %o0
a006d8cc:  90 10 00 11  mov  %l1, %o0
a006d8d0:  40 00 89 5a  call  0xa008fe38
a006d8d4:  92 10 20 01  mov  1, %o1
a006d8d8:  92 10 20 01  mov  1, %o1
a006d8dc:  40 00 89 64  call  0xa008fe6c
a006d8e0:  90 10 00 11  mov  %l1, %o0
a006d8e4:  40 00 89 ed  call  0xa0090098
a006d8e8:  90 10 00 11  mov  %l1, %o0
a006d8ec:  d0 36 20 02  sth  %o0, [ %i0 + 2 ]
a006d8f0:  40 00 8a 04  call  0xa0090100
a006d8f4:  90 10 00 11  mov  %l1, %o0
a006d8f8:  d0 36 20 04  sth  %o0, [ %i0 + 4 ]
a006d8fc:  40 00 89 c5  call  0xa0090010
a006d900:  90 10 00 11  mov  %l1, %o0
a006d904:  d0 36 20 06  sth  %o0, [ %i0 + 6 ]
a006d908:  40 00 89 dc  call  0xa0090078
a006d90c:  90 10 00 11  mov  %l1, %o0
a006d910:  d0 36 20 08  sth  %o0, [ %i0 + 8 ]
a006d914:  40 00 8d f6  call  0xa00910ec
a006d918:  90 10 00 11  mov  %l1, %o0
a006d91c:  40 01 11 d2  call  0xa00b2064
a006d920:  d0 36 20 0a  sth  %o0, [ %i0 + 0xa ]
a006d924:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a006d928:  83 2c 60 02  sll  %l1, 2, %g1
a006d92c:  9a 13 60 70  or  %o5, 0x70, %o5
a006d930:  d0 23 40 01  st  %o0, [ %o5 + %g1 ]
a006d934:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006d938:  92 10 00 11  mov  %l1, %o1
a006d93c:  40 00 15 c2  call  0xa0073044
a006d940:  90 12 20 18  or  %o0, 0x18, %o0
a006d944:  40 00 88 57  call  0xa008faa0
a006d948:  90 10 00 11  mov  %l1, %o0
a006d94c:  40 00 88 4b  call  0xa008fa78
a006d950:  90 10 00 11  mov  %l1, %o0
a006d954:  90 10 00 18  mov  %i0, %o0
a006d958:  92 10 20 04  mov  4, %o1
a006d95c:  7f ff fe f8  call  0xa006d53c
a006d960:  01 00 00 00  nop
a006d964:  10 80 01 b8  b  0xa006e044
a006d968:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006d96c:  40 00 1c b7  call  0xa0074c48
a006d970:  90 10 00 14  mov  %l4, %o0
a006d974:  80 8a 20 ff  btst  0xff, %o0
a006d978:  12 80 00 0a  bne  0xa006d9a0
a006d97c:  90 10 00 18  mov  %i0, %o0
a006d980:  7f ff fe ef  call  0xa006d53c
a006d984:  92 10 20 03  mov  3, %o1
a006d988:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006d98c:  92 10 00 11  mov  %l1, %o1
a006d990:  40 00 15 ad  call  0xa0073044
a006d994:  90 12 20 38  or  %o0, 0x38, %o0
a006d998:  10 80 00 a0  b  0xa006dc18
a006d99c:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006d9a0:  40 01 11 b1  call  0xa00b2064
a006d9a4:  a1 2c 60 02  sll  %l1, 2, %l0
a006d9a8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006d9ac:  a4 10 60 70  or  %g1, 0x70, %l2	! 0xa8078870
a006d9b0:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a006d9b4:  90 22 00 01  sub  %o0, %g1, %o0
a006d9b8:  80 a2 20 c8  cmp  %o0, 0xc8
a006d9bc:  28 80 00 97  bleu,a   0xa006dc18
a006d9c0:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006d9c4:  40 00 8a 6c  call  0xa0090374
a006d9c8:  90 10 00 11  mov  %l1, %o0
a006d9cc:  40 00 88 6c  call  0xa008fb7c
a006d9d0:  90 10 00 11  mov  %l1, %o0
a006d9d4:  d0 2e 20 12  stb  %o0, [ %i0 + 0x12 ]
a006d9d8:  40 00 88 3d  call  0xa008facc
a006d9dc:  90 10 00 11  mov  %l1, %o0
a006d9e0:  40 00 8e 43  call  0xa00912ec
a006d9e4:  90 10 00 11  mov  %l1, %o0
a006d9e8:  40 00 89 ac  call  0xa0090098
a006d9ec:  90 10 00 11  mov  %l1, %o0
a006d9f0:  d0 36 20 02  sth  %o0, [ %i0 + 2 ]
a006d9f4:  40 00 89 c3  call  0xa0090100
a006d9f8:  90 10 00 11  mov  %l1, %o0
a006d9fc:  d0 36 20 04  sth  %o0, [ %i0 + 4 ]
a006da00:  40 00 89 84  call  0xa0090010
a006da04:  90 10 00 11  mov  %l1, %o0
a006da08:  d0 36 20 06  sth  %o0, [ %i0 + 6 ]
a006da0c:  40 00 89 9b  call  0xa0090078
a006da10:  90 10 00 11  mov  %l1, %o0
a006da14:  d0 36 20 08  sth  %o0, [ %i0 + 8 ]
a006da18:  40 00 8d b5  call  0xa00910ec
a006da1c:  90 10 00 11  mov  %l1, %o0
a006da20:  d0 36 20 0a  sth  %o0, [ %i0 + 0xa ]
a006da24:  40 00 89 df  call  0xa00901a0
a006da28:  90 10 00 11  mov  %l1, %o0
a006da2c:  d0 2e 20 0c  stb  %o0, [ %i0 + 0xc ]
a006da30:  40 00 89 dc  call  0xa00901a0
a006da34:  90 10 00 11  mov  %l1, %o0
a006da38:  90 10 00 18  mov  %i0, %o0
a006da3c:  7f ff fe f8  call  0xa006d61c
a006da40:  92 10 00 11  mov  %l1, %o1
a006da44:  c2 16 20 06  lduh  [ %i0 + 6 ], %g1
a006da48:  80 a0 60 00  cmp  %g1, 0
a006da4c:  02 80 00 0e  be  0xa006da84
a006da50:  90 10 00 18  mov  %i0, %o0
a006da54:  c2 16 20 08  lduh  [ %i0 + 8 ], %g1
a006da58:  80 a0 60 00  cmp  %g1, 0
a006da5c:  02 80 00 0a  be  0xa006da84
a006da60:  01 00 00 00  nop
a006da64:  c2 16 20 02  lduh  [ %i0 + 2 ], %g1
a006da68:  80 a0 60 00  cmp  %g1, 0
a006da6c:  02 80 00 06  be  0xa006da84
a006da70:  01 00 00 00  nop
a006da74:  c2 16 20 04  lduh  [ %i0 + 4 ], %g1
a006da78:  80 a0 60 00  cmp  %g1, 0
a006da7c:  12 80 00 0f  bne  0xa006dab8
a006da80:  01 00 00 00  nop
a006da84:  7f ff fe ae  call  0xa006d53c
a006da88:  92 10 20 03  mov  3, %o1	! 0x3
a006da8c:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006da90:  90 12 20 58  or  %o0, 0x58, %o0	! 0xa0065c58
a006da94:  40 00 15 6c  call  0xa0073044
a006da98:  92 10 00 11  mov  %l1, %o1
a006da9c:  82 05 00 14  add  %l4, %l4, %g1
a006daa0:  82 00 40 14  add  %g1, %l4, %g1
a006daa4:  9a 16 e0 64  or  %i3, 0x64, %o5
a006daa8:  83 28 60 03  sll  %g1, 3, %g1
a006daac:  82 00 40 0d  add  %g1, %o5, %g1
a006dab0:  10 80 00 56  b  0xa006dc08
a006dab4:  c0 28 60 01  clrb  [ %g1 + 1 ]
a006dab8:  40 01 11 6b  call  0xa00b2064
a006dabc:  01 00 00 00  nop
a006dac0:  c2 04 80 10  ld  [ %l2 + %l0 ], %g1
a006dac4:  90 22 00 01  sub  %o0, %g1, %o0
a006dac8:  80 a2 20 f9  cmp  %o0, 0xf9
a006dacc:  18 80 00 08  bgu  0xa006daec
a006dad0:  01 00 00 00  nop
a006dad4:  40 00 88 cf  call  0xa008fe10
a006dad8:  90 10 00 11  mov  %l1, %o0
a006dadc:  90 0a 20 ff  and  %o0, 0xff, %o0
a006dae0:  80 a2 20 01  cmp  %o0, 1
a006dae4:  22 80 01 58  be,a   0xa006e044
a006dae8:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006daec:  40 00 87 c5  call  0xa008fa00
a006daf0:  90 10 00 11  mov  %l1, %o0
a006daf4:  40 00 87 cf  call  0xa008fa30
a006daf8:  90 10 00 11  mov  %l1, %o0
a006dafc:  40 00 87 e9  call  0xa008faa0
a006db00:  90 10 00 11  mov  %l1, %o0
a006db04:  40 00 87 dd  call  0xa008fa78
a006db08:  90 10 00 11  mov  %l1, %o0
a006db0c:  40 00 8d be  call  0xa0091204
a006db10:  90 10 00 11  mov  %l1, %o0
a006db14:  92 10 20 00  clr  %o1
a006db18:  40 00 28 d4  call  0xa0077e68
a006db1c:  90 10 00 14  mov  %l4, %o0
a006db20:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a006db24:  82 10 63 e4  or  %g1, 0x3e4, %g1	! 0xa807d3e4
a006db28:  a0 5c 60 b0  smul  %l1, 0xb0, %l0
a006db2c:  a0 04 00 01  add  %l0, %g1, %l0
a006db30:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006db34:  82 10 60 80  or  %g1, 0x80, %g1	! 0xa8078880
a006db38:  40 01 11 4b  call  0xa00b2064
a006db3c:  c0 28 40 11  clrb  [ %g1 + %l1 ]
a006db40:  d0 24 20 a8  st  %o0, [ %l0 + 0xa8 ]
a006db44:  90 10 00 18  mov  %i0, %o0
a006db48:  7f ff fe 7d  call  0xa006d53c
a006db4c:  92 10 20 05  mov  5, %o1
a006db50:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006db54:  d4 16 20 0a  lduh  [ %i0 + 0xa ], %o2
a006db58:  92 10 00 11  mov  %l1, %o1
a006db5c:  40 00 15 3a  call  0xa0073044
a006db60:  90 12 20 78  or  %o0, 0x78, %o0
a006db64:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006db68:  d2 16 20 02  lduh  [ %i0 + 2 ], %o1
a006db6c:  40 00 15 36  call  0xa0073044
a006db70:  90 12 20 a8  or  %o0, 0xa8, %o0
a006db74:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006db78:  d2 16 20 04  lduh  [ %i0 + 4 ], %o1
a006db7c:  40 00 15 32  call  0xa0073044
a006db80:  90 12 20 c0  or  %o0, 0xc0, %o0
a006db84:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006db88:  d2 16 20 06  lduh  [ %i0 + 6 ], %o1
a006db8c:  40 00 15 2e  call  0xa0073044
a006db90:  90 12 20 d8  or  %o0, 0xd8, %o0
a006db94:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006db98:  d2 16 20 08  lduh  [ %i0 + 8 ], %o1
a006db9c:  40 00 15 2a  call  0xa0073044
a006dba0:  90 12 20 f0  or  %o0, 0xf0, %o0
a006dba4:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006dba8:  d2 16 20 0a  lduh  [ %i0 + 0xa ], %o1
a006dbac:  40 00 15 26  call  0xa0073044
a006dbb0:  90 12 21 08  or  %o0, 0x108, %o0
a006dbb4:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006dbb8:  d2 0e 20 0c  ldub  [ %i0 + 0xc ], %o1
a006dbbc:  40 00 15 22  call  0xa0073044
a006dbc0:  90 12 21 18  or  %o0, 0x118, %o0
a006dbc4:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006dbc8:  d2 0e 20 12  ldub  [ %i0 + 0x12 ], %o1
a006dbcc:  40 00 15 1e  call  0xa0073044
a006dbd0:  90 12 21 30  or  %o0, 0x130, %o0
a006dbd4:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006dbd8:  d2 0e 20 0d  ldub  [ %i0 + 0xd ], %o1
a006dbdc:  40 00 15 1a  call  0xa0073044
a006dbe0:  90 12 21 48  or  %o0, 0x148, %o0
a006dbe4:  82 10 20 01  mov  1, %g1
a006dbe8:  c2 2e 20 0f  stb  %g1, [ %i0 + 0xf ]
a006dbec:  90 10 00 11  mov  %l1, %o0
a006dbf0:  40 00 88 9f  call  0xa008fe6c
a006dbf4:  92 10 20 00  clr  %o1
a006dbf8:  40 00 88 74  call  0xa008fdc8
a006dbfc:  90 10 00 11  mov  %l1, %o0
a006dc00:  40 00 8e 3f  call  0xa00914fc
a006dc04:  90 10 00 11  mov  %l1, %o0
a006dc08:  90 0e 60 ff  and  %i1, 0xff, %o0
a006dc0c:  40 00 2d 12  call  0xa0079054
a006dc10:  92 10 20 00  clr  %o1
a006dc14:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006dc18:  80 a0 60 03  cmp  %g1, 3
a006dc1c:  32 80 01 0a  bne,a   0xa006e044
a006dc20:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006dc24:  a2 0c e0 ff  and  %l3, 0xff, %l1
a006dc28:  40 00 1d 55  call  0xa007517c
a006dc2c:  90 10 00 11  mov  %l1, %o0
a006dc30:  80 8a 20 ff  btst  0xff, %o0
a006dc34:  02 80 00 0b  be  0xa006dc60
a006dc38:  a0 0e 60 ff  and  %i1, 0xff, %l0
a006dc3c:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006dc40:  92 10 00 10  mov  %l0, %o1
a006dc44:  40 00 15 00  call  0xa0073044
a006dc48:  90 12 21 60  or  %o0, 0x160, %o0
a006dc4c:  90 10 00 11  mov  %l1, %o0
a006dc50:  40 00 28 86  call  0xa0077e68
a006dc54:  92 10 20 00  clr  %o1
a006dc58:  10 80 00 fb  b  0xa006e044
a006dc5c:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006dc60:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006dc64:  a4 10 60 80  or  %g1, 0x80, %l2	! 0xa8078880
a006dc68:  c2 0c 80 10  ldub  [ %l2 + %l0 ], %g1
a006dc6c:  82 00 60 01  inc  %g1
a006dc70:  9a 08 60 ff  and  %g1, 0xff, %o5
a006dc74:  80 a3 60 01  cmp  %o5, 1
a006dc78:  08 80 00 f2  bleu  0xa006e040
a006dc7c:  c2 2c 80 10  stb  %g1, [ %l2 + %l0 ]
a006dc80:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006dc84:  92 10 00 10  mov  %l0, %o1
a006dc88:  40 00 14 ef  call  0xa0073044
a006dc8c:  90 12 21 98  or  %o0, 0x198, %o0
a006dc90:  90 10 00 11  mov  %l1, %o0
a006dc94:  40 00 28 75  call  0xa0077e68
a006dc98:  92 10 20 01  mov  1, %o1
a006dc9c:  10 80 00 e9  b  0xa006e040
a006dca0:  c0 2c 80 10  clrb  [ %l2 + %l0 ]
a006dca4:  40 00 8b 0b  call  0xa00908d0
a006dca8:  90 10 00 11  mov  %l1, %o0
a006dcac:  40 00 1b e7  call  0xa0074c48
a006dcb0:  90 10 00 14  mov  %l4, %o0
a006dcb4:  80 8a 20 ff  btst  0xff, %o0
a006dcb8:  12 80 00 07  bne  0xa006dcd4
a006dcbc:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006dcc0:  92 10 20 01  mov  1, %o1
a006dcc4:  40 00 14 e0  call  0xa0073044
a006dcc8:  90 12 21 c0  or  %o0, 0x1c0, %o0
a006dccc:  10 80 00 bf  b  0xa006dfc8
a006dcd0:  90 10 00 18  mov  %i0, %o0
a006dcd4:  40 00 89 33  call  0xa00901a0
a006dcd8:  90 10 00 11  mov  %l1, %o0
a006dcdc:  90 0a 20 ff  and  %o0, 0xff, %o0
a006dce0:  c2 0e 20 0c  ldub  [ %i0 + 0xc ], %g1
a006dce4:  80 a2 00 01  cmp  %o0, %g1
a006dce8:  02 80 00 13  be  0xa006dd34
a006dcec:  92 10 20 03  mov  3, %o1
a006dcf0:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006dcf4:  40 00 14 d4  call  0xa0073044
a006dcf8:  90 12 21 c0  or  %o0, 0x1c0, %o0	! 0xa0065dc0
a006dcfc:  40 00 89 29  call  0xa00901a0
a006dd00:  90 10 00 11  mov  %l1, %o0
a006dd04:  d0 2e 20 0c  stb  %o0, [ %i0 + 0xc ]
a006dd08:  90 10 00 18  mov  %i0, %o0
a006dd0c:  7f ff fe 0c  call  0xa006d53c
a006dd10:  92 10 20 04  mov  4, %o1
a006dd14:  40 01 10 d4  call  0xa00b2064
a006dd18:  01 00 00 00  nop
a006dd1c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a006dd20:  9b 2c 60 02  sll  %l1, 2, %o5
a006dd24:  90 02 3f 38  add  %o0, -200, %o0
a006dd28:  82 10 60 70  or  %g1, 0x70, %g1
a006dd2c:  10 80 00 a9  b  0xa006dfd0
a006dd30:  d0 20 40 0d  st  %o0, [ %g1 + %o5 ]
a006dd34:  c2 16 20 02  lduh  [ %i0 + 2 ], %g1
a006dd38:  da 16 20 04  lduh  [ %i0 + 4 ], %o5
a006dd3c:  d8 16 20 06  lduh  [ %i0 + 6 ], %o4
a006dd40:  d6 16 20 08  lduh  [ %i0 + 8 ], %o3
a006dd44:  c2 37 bf ec  sth  %g1, [ %fp + -20 ]
a006dd48:  da 37 bf ee  sth  %o5, [ %fp + -18 ]
a006dd4c:  d8 37 bf e8  sth  %o4, [ %fp + -24 ]
a006dd50:  d6 37 bf ea  sth  %o3, [ %fp + -22 ]
a006dd54:  40 00 88 af  call  0xa0090010
a006dd58:  90 10 00 11  mov  %l1, %o0
a006dd5c:  ae 10 00 08  mov  %o0, %l7
a006dd60:  40 00 88 c6  call  0xa0090078
a006dd64:  90 10 00 11  mov  %l1, %o0
a006dd68:  ac 10 00 08  mov  %o0, %l6
a006dd6c:  40 00 88 cb  call  0xa0090098
a006dd70:  90 10 00 11  mov  %l1, %o0
a006dd74:  aa 10 00 08  mov  %o0, %l5
a006dd78:  40 00 88 e2  call  0xa0090100
a006dd7c:  90 10 00 11  mov  %l1, %o0
a006dd80:  ba 10 00 08  mov  %o0, %i5
a006dd84:  40 00 8c da  call  0xa00910ec
a006dd88:  90 10 00 11  mov  %l1, %o0
a006dd8c:  83 2d 60 10  sll  %l5, 0x10, %g1
a006dd90:  83 30 60 10  srl  %g1, 0x10, %g1
a006dd94:  da 17 bf ec  lduh  [ %fp + -20 ], %o5
a006dd98:  b8 10 00 08  mov  %o0, %i4
a006dd9c:  80 a0 40 0d  cmp  %g1, %o5
a006dda0:  02 80 00 07  be  0xa006ddbc
a006dda4:  a6 10 20 00  clr  %l3
a006dda8:  40 01 0e 7b  call  0xa00b1794
a006ddac:  90 10 20 01  mov  1, %o0
a006ddb0:  40 00 88 ba  call  0xa0090098
a006ddb4:  90 10 00 11  mov  %l1, %o0
a006ddb8:  aa 10 00 08  mov  %o0, %l5
a006ddbc:  40 00 88 8d  call  0xa008fff0
a006ddc0:  90 10 00 11  mov  %l1, %o0
a006ddc4:  80 8a 20 ff  btst  0xff, %o0
a006ddc8:  12 80 00 3f  bne  0xa006dec4
a006ddcc:  90 10 00 18  mov  %i0, %o0
a006ddd0:  83 2d e0 10  sll  %l7, 0x10, %g1
a006ddd4:  a5 30 60 10  srl  %g1, 0x10, %l2
a006ddd8:  d4 17 bf e8  lduh  [ %fp + -24 ], %o2
a006dddc:  82 24 80 0a  sub  %l2, %o2, %g1
a006dde0:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a006dde4:  82 1b 40 01  xor  %o5, %g1, %g1
a006dde8:  82 20 40 0d  sub  %g1, %o5, %g1
a006ddec:  80 a0 60 02  cmp  %g1, 2
a006ddf0:  04 80 00 08  ble  0xa006de10
a006ddf4:  83 2d a0 10  sll  %l6, 0x10, %g1
a006ddf8:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006ddfc:  90 12 21 e0  or  %o0, 0x1e0, %o0	! 0xa0065de0
a006de00:  40 00 14 91  call  0xa0073044
a006de04:  92 10 00 12  mov  %l2, %o1
a006de08:  a6 10 20 01  mov  1, %l3
a006de0c:  83 2d a0 10  sll  %l6, 0x10, %g1
a006de10:  a1 30 60 10  srl  %g1, 0x10, %l0
a006de14:  d4 17 bf ea  lduh  [ %fp + -22 ], %o2
a006de18:  82 24 00 0a  sub  %l0, %o2, %g1
a006de1c:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a006de20:  82 1b 40 01  xor  %o5, %g1, %g1
a006de24:  82 20 40 0d  sub  %g1, %o5, %g1
a006de28:  80 a0 60 01  cmp  %g1, 1
a006de2c:  04 80 00 08  ble  0xa006de4c
a006de30:  03 00 00 07  sethi  %hi(0x1c00), %g1
a006de34:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006de38:  90 12 21 f0  or  %o0, 0x1f0, %o0	! 0xa0065df0
a006de3c:  40 00 14 82  call  0xa0073044
a006de40:  92 10 00 10  mov  %l0, %o1
a006de44:  a6 10 20 01  mov  1, %l3
a006de48:  03 00 00 07  sethi  %hi(0x1c00), %g1
a006de4c:  82 10 63 ff  or  %g1, 0x3ff, %g1	! 0x1fff
a006de50:  80 a4 80 01  cmp  %l2, %g1
a006de54:  12 80 00 07  bne  0xa006de70
a006de58:  80 a4 20 00  cmp  %l0, 0
a006de5c:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006de60:  40 00 15 99  call  0xa00734c4
a006de64:  90 12 22 00  or  %o0, 0x200, %o0	! 0xa0065e00
a006de68:  a6 10 20 01  mov  1, %l3
a006de6c:  80 a4 20 00  cmp  %l0, 0
a006de70:  12 80 00 07  bne  0xa006de8c
a006de74:  83 2d 60 10  sll  %l5, 0x10, %g1
a006de78:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006de7c:  40 00 15 92  call  0xa00734c4
a006de80:  90 12 22 28  or  %o0, 0x228, %o0	! 0xa0065e28
a006de84:  a6 10 20 01  mov  1, %l3
a006de88:  83 2d 60 10  sll  %l5, 0x10, %g1
a006de8c:  93 30 60 10  srl  %g1, 0x10, %o1
a006de90:  d4 17 bf ec  lduh  [ %fp + -20 ], %o2
a006de94:  82 22 40 0a  sub  %o1, %o2, %g1
a006de98:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a006de9c:  82 1b 40 01  xor  %o5, %g1, %g1
a006dea0:  82 20 40 0d  sub  %g1, %o5, %g1
a006dea4:  80 a0 60 10  cmp  %g1, 0x10
a006dea8:  24 80 00 07  ble,a   0xa006dec4
a006deac:  90 10 00 18  mov  %i0, %o0
a006deb0:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006deb4:  40 00 14 64  call  0xa0073044
a006deb8:  90 12 22 50  or  %o0, 0x250, %o0	! 0xa0065e50
a006debc:  a6 10 20 01  mov  1, %l3
a006dec0:  90 10 00 18  mov  %i0, %o0
a006dec4:  7f ff fd d6  call  0xa006d61c
a006dec8:  92 10 00 11  mov  %l1, %o1
a006decc:  83 2d e0 10  sll  %l7, 0x10, %g1
a006ded0:  83 30 60 10  srl  %g1, 0x10, %g1
a006ded4:  da 16 20 06  lduh  [ %i0 + 6 ], %o5
a006ded8:  80 a3 40 01  cmp  %o5, %g1
a006dedc:  32 80 00 15  bne,a   0xa006df30
a006dee0:  ee 36 20 06  sth  %l7, [ %i0 + 6 ]
a006dee4:  83 2d a0 10  sll  %l6, 0x10, %g1
a006dee8:  83 30 60 10  srl  %g1, 0x10, %g1
a006deec:  da 16 20 08  lduh  [ %i0 + 8 ], %o5
a006def0:  80 a3 40 01  cmp  %o5, %g1
a006def4:  32 80 00 0f  bne,a   0xa006df30
a006def8:  ee 36 20 06  sth  %l7, [ %i0 + 6 ]
a006defc:  83 2d 60 10  sll  %l5, 0x10, %g1
a006df00:  83 30 60 10  srl  %g1, 0x10, %g1
a006df04:  da 16 20 02  lduh  [ %i0 + 2 ], %o5
a006df08:  80 a3 40 01  cmp  %o5, %g1
a006df0c:  32 80 00 09  bne,a   0xa006df30
a006df10:  ee 36 20 06  sth  %l7, [ %i0 + 6 ]
a006df14:  83 2f 60 10  sll  %i5, 0x10, %g1
a006df18:  83 30 60 10  srl  %g1, 0x10, %g1
a006df1c:  da 16 20 04  lduh  [ %i0 + 4 ], %o5
a006df20:  80 a3 40 01  cmp  %o5, %g1
a006df24:  02 80 00 0e  be  0xa006df5c
a006df28:  92 0e 60 ff  and  %i1, 0xff, %o1
a006df2c:  ee 36 20 06  sth  %l7, [ %i0 + 6 ]
a006df30:  ec 36 20 08  sth  %l6, [ %i0 + 8 ]
a006df34:  ea 36 20 02  sth  %l5, [ %i0 + 2 ]
a006df38:  fa 36 20 04  sth  %i5, [ %i0 + 4 ]
a006df3c:  80 8c e0 ff  btst  0xff, %l3
a006df40:  02 80 00 06  be  0xa006df58
a006df44:  f8 36 20 0a  sth  %i4, [ %i0 + 0xa ]
a006df48:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006df4c:  90 12 22 60  or  %o0, 0x260, %o0	! 0xa0065e60
a006df50:  40 00 14 3d  call  0xa0073044
a006df54:  92 10 00 11  mov  %l1, %o1
a006df58:  92 0e 60 ff  and  %i1, 0xff, %o1
a006df5c:  1b 2a 01 f4  sethi  %hi(0xa807d000), %o5
a006df60:  82 5a 60 b0  smul  %o1, 0xb0, %g1
a006df64:  9a 13 63 e4  or  %o5, 0x3e4, %o5
a006df68:  9a 00 40 0d  add  %g1, %o5, %o5
a006df6c:  c2 0b 60 ac  ldub  [ %o5 + 0xac ], %g1
a006df70:  80 a0 60 00  cmp  %g1, 0
a006df74:  02 80 00 08  be  0xa006df94
a006df78:  80 8c e0 ff  btst  0xff, %l3
a006df7c:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006df80:  c0 2b 60 ac  clrb  [ %o5 + 0xac ]
a006df84:  90 12 22 90  or  %o0, 0x290, %o0
a006df88:  40 00 14 2f  call  0xa0073044
a006df8c:  a6 10 20 01  mov  1, %l3
a006df90:  80 8c e0 ff  btst  0xff, %l3
a006df94:  22 80 00 10  be,a   0xa006dfd4
a006df98:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006df9c:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006dfa0:  90 12 21 c0  or  %o0, 0x1c0, %o0	! 0xa0065dc0
a006dfa4:  40 00 14 28  call  0xa0073044
a006dfa8:  92 10 20 04  mov  4, %o1
a006dfac:  82 05 00 14  add  %l4, %l4, %g1
a006dfb0:  82 00 40 14  add  %g1, %l4, %g1
a006dfb4:  9a 16 e0 64  or  %i3, 0x64, %o5
a006dfb8:  83 28 60 03  sll  %g1, 3, %g1
a006dfbc:  82 00 40 0d  add  %g1, %o5, %g1
a006dfc0:  c0 28 60 01  clrb  [ %g1 + 1 ]
a006dfc4:  90 10 00 18  mov  %i0, %o0
a006dfc8:  7f ff fd 5d  call  0xa006d53c
a006dfcc:  92 10 20 03  mov  3, %o1
a006dfd0:  c2 0e 00 00  ldub  [ %i0 ], %g1
a006dfd4:  80 a0 60 05  cmp  %g1, 5
a006dfd8:  02 80 00 0a  be  0xa006e000
a006dfdc:  a0 0e 60 ff  and  %i1, 0xff, %l0
a006dfe0:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006dfe4:  40 00 15 38  call  0xa00734c4
a006dfe8:  90 12 22 c0  or  %o0, 0x2c0, %o0	! 0xa0065ec0
a006dfec:  90 10 00 18  mov  %i0, %o0
a006dff0:  7f ff fd 56  call  0xa006d548
a006dff4:  92 10 00 10  mov  %l0, %o1
a006dff8:  10 80 00 13  b  0xa006e044
a006dffc:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006e000:  90 10 00 18  mov  %i0, %o0
a006e004:  7f ff fd 86  call  0xa006d61c
a006e008:  92 10 00 10  mov  %l0, %o1
a006e00c:  90 10 00 10  mov  %l0, %o0
a006e010:  40 00 e1 5b  call  0xa00a657c
a006e014:  92 10 20 05  mov  5, %o1
a006e018:  80 8a 20 10  btst  0x10, %o0
a006e01c:  02 80 00 07  be  0xa006e038
a006e020:  90 10 00 10  mov  %l0, %o0
a006e024:  92 10 20 05  mov  5, %o1
a006e028:  94 10 20 10  mov  0x10, %o2
a006e02c:  40 00 e1 e3  call  0xa00a67b8
a006e030:  96 10 20 00  clr  %o3
a006e034:  90 10 00 10  mov  %l0, %o0
a006e038:  40 00 2c 07  call  0xa0079054
a006e03c:  92 10 20 00  clr  %o1
a006e040:  d4 0e 00 00  ldub  [ %i0 ], %o2
a006e044:  82 1a a0 05  xor  %o2, 5, %g1
a006e048:  80 a0 00 01  cmp  %g0, %g1
a006e04c:  82 0e a0 ff  and  %i2, 0xff, %g1
a006e050:  9a 40 20 00  addx  %g0, 0, %o5
a006e054:  82 18 60 05  xor  %g1, 5, %g1
a006e058:  80 a0 00 01  cmp  %g0, %g1
a006e05c:  82 60 3f ff  subx  %g0, -1, %g1
a006e060:  80 8b 40 01  btst  %o5, %g1
a006e064:  02 80 00 09  be  0xa006e088
a006e068:  d8 0f bf e7  ldub  [ %fp + -25 ], %o4
a006e06c:  82 10 20 01  mov  1, %g1
a006e070:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e074:  c2 2e 20 10  stb  %g1, [ %i0 + 0x10 ]
a006e078:  90 12 22 d8  or  %o0, 0x2d8, %o0
a006e07c:  40 00 13 f2  call  0xa0073044
a006e080:  92 0e 60 ff  and  %i1, 0xff, %o1
a006e084:  d8 0f bf e7  ldub  [ %fp + -25 ], %o4
a006e088:  d4 0e 20 0d  ldub  [ %i0 + 0xd ], %o2
a006e08c:  80 a2 80 0c  cmp  %o2, %o4
a006e090:  12 80 00 07  bne  0xa006e0ac
a006e094:  9a 0b 20 4c  and  %o4, 0x4c, %o5
a006e098:  da 0f bf e6  ldub  [ %fp + -26 ], %o5
a006e09c:  c2 0e 20 0e  ldub  [ %i0 + 0xe ], %g1
a006e0a0:  80 a0 40 0d  cmp  %g1, %o5
a006e0a4:  02 80 00 0d  be  0xa006e0d8
a006e0a8:  9a 0b 20 4c  and  %o4, 0x4c, %o5
a006e0ac:  98 10 20 01  mov  1, %o4
a006e0b0:  82 0a a0 4c  and  %o2, 0x4c, %g1
a006e0b4:  80 a0 40 0d  cmp  %g1, %o5
a006e0b8:  02 80 00 03  be  0xa006e0c4
a006e0bc:  d8 2e 20 0f  stb  %o4, [ %i0 + 0xf ]
a006e0c0:  d8 2e 20 10  stb  %o4, [ %i0 + 0x10 ]
a006e0c4:  11 28 01 97  sethi  %hi(0xa0065c00), %o0
a006e0c8:  90 12 23 00  or  %o0, 0x300, %o0	! 0xa0065f00
a006e0cc:  92 0e 60 ff  and  %i1, 0xff, %o1
a006e0d0:  40 00 13 dd  call  0xa0073044
a006e0d4:  d6 0e 20 0e  ldub  [ %i0 + 0xe ], %o3
a006e0d8:  01 00 00 00  nop
a006e0dc:  81 c7 e0 08  ret
a006e0e0:  81 e8 00 00  restore
