# leon2s FSM_MODE_DETECT_STANDBY 0xa00977e8-0xa0097ed0 (1768 bytes)
a00977e8:  9d e3 bf 90  save  %sp, -112, %sp
a00977ec:  a8 0e 20 ff  and  %i0, 0xff, %l4
a00977f0:  82 1d 20 01  xor  %l4, 1, %g1
a00977f4:  80 a0 00 01  cmp  %g0, %g1
a00977f8:  82 40 20 00  addx  %g0, 0, %g1
a00977fc:  9a 10 20 03  mov  3, %o5
a0097800:  9a 23 40 01  sub  %o5, %g1, %o5
a0097804:  33 2a 01 f6  sethi  %hi(0xa807d800), %i1
a0097808:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009780c:  a2 16 63 00  or  %i1, 0x300, %l1
a0097810:  a0 5d 20 34  smul  %l4, 0x34, %l0
a0097814:  82 10 62 48  or  %g1, 0x248, %g1
a0097818:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a009781c:  c2 08 40 14  ldub  [ %g1 + %l4 ], %g1
a0097820:  92 02 60 04  add  %o1, 4, %o1
a0097824:  c2 2f bf f6  stb  %g1, [ %fp + -10 ]
a0097828:  b8 10 00 0d  mov  %o5, %i4
a009782c:  40 00 3e ea  call  0xa00a73d4
a0097830:  90 10 20 0c  mov  0xc, %o0
a0097834:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a0097838:  d8 03 60 38  ld  [ %o5 + 0x38 ], %o4
a009783c:  ea 03 60 3c  ld  [ %o5 + 0x3c ], %l5
a0097840:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0097844:  e2 03 60 4c  ld  [ %o5 + 0x4c ], %l1
a0097848:  82 10 60 a8  or  %g1, 0xa8, %g1
a009784c:  c2 08 40 14  ldub  [ %g1 + %l4 ], %g1
a0097850:  99 33 20 10  srl  %o4, 0x10, %o4
a0097854:  a3 34 60 10  srl  %l1, 0x10, %l1
a0097858:  ad 2b 00 01  sll  %o4, %g1, %l6
a009785c:  a3 2c 40 01  sll  %l1, %g1, %l1
a0097860:  e4 03 60 50  ld  [ %o5 + 0x50 ], %l2
a0097864:  92 10 20 00  clr  %o1
a0097868:  ae 10 00 18  mov  %i0, %l7
a009786c:  7f ff ff 85  call  0xa0097680
a0097870:  90 10 00 14  mov  %l4, %o0
a0097874:  b0 06 20 41  add  %i0, 0x41, %i0
a0097878:  b6 10 00 08  mov  %o0, %i3
a009787c:  b1 2e 20 18  sll  %i0, 0x18, %i0
a0097880:  a1 2d a0 10  sll  %l6, 0x10, %l0
a0097884:  b1 3e 20 18  sra  %i0, 0x18, %i0
a0097888:  a1 34 20 10  srl  %l0, 0x10, %l0
a009788c:  99 2c 60 10  sll  %l1, 0x10, %o4
a0097890:  9b 2c a0 10  sll  %l2, 0x10, %o5
a0097894:  97 2d 60 10  sll  %l5, 0x10, %o3
a0097898:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a009789c:  92 10 00 18  mov  %i0, %o1
a00978a0:  94 10 00 10  mov  %l0, %o2
a00978a4:  97 32 e0 10  srl  %o3, 0x10, %o3
a00978a8:  99 33 20 10  srl  %o4, 0x10, %o4
a00978ac:  9b 33 60 10  srl  %o5, 0x10, %o5
a00978b0:  7f ff 6d e5  call  0xa0073044
a00978b4:  90 12 21 c8  or  %o0, 0x1c8, %o0
a00978b8:  3b 2a 01 f5  sethi  %hi(0xa807d400), %i5
a00978bc:  82 5d 21 90  smul  %l4, 0x190, %g1
a00978c0:  9a 17 63 e0  or  %i5, 0x3e0, %o5
a00978c4:  a6 00 40 0d  add  %g1, %o5, %l3
a00978c8:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a00978cc:  92 10 00 18  mov  %i0, %o1
a00978d0:  da 14 e0 20  lduh  [ %l3 + 0x20 ], %o5
a00978d4:  90 12 22 08  or  %o0, 0x208, %o0
a00978d8:  d4 14 e0 1a  lduh  [ %l3 + 0x1a ], %o2
a00978dc:  d6 14 e0 1c  lduh  [ %l3 + 0x1c ], %o3
a00978e0:  7f ff 6d d9  call  0xa0073044
a00978e4:  d8 14 e0 1e  lduh  [ %l3 + 0x1e ], %o4
a00978e8:  c2 14 e0 1a  lduh  [ %l3 + 0x1a ], %g1
a00978ec:  82 18 66 b4  xor  %g1, 0x6b4, %g1
a00978f0:  80 a0 00 01  cmp  %g0, %g1
a00978f4:  9a 60 3f ff  subx  %g0, -1, %o5
a00978f8:  a0 1c 23 5a  xor  %l0, 0x35a, %l0
a00978fc:  80 a0 00 10  cmp  %g0, %l0
a0097900:  82 60 3f ff  subx  %g0, -1, %g1
a0097904:  80 8b 40 01  btst  %o5, %g1
a0097908:  c0 2f bf f7  clrb  [ %fp + -9 ]
a009790c:  b4 10 00 16  mov  %l6, %i2
a0097910:  02 80 00 0f  be  0xa009794c
a0097914:  b0 10 00 15  mov  %l5, %i0
a0097918:  82 05 7e fa  add  %l5, -262, %g1
a009791c:  83 28 60 10  sll  %g1, 0x10, %g1
a0097920:  83 30 60 10  srl  %g1, 0x10, %g1
a0097924:  80 a0 60 01  cmp  %g1, 1
a0097928:  18 80 00 09  bgu  0xa009794c
a009792c:  01 00 00 00  nop
a0097930:  c2 14 e0 1c  lduh  [ %l3 + 0x1c ], %g1
a0097934:  82 00 7e fa  add  %g1, -262, %g1
a0097938:  83 28 60 10  sll  %g1, 0x10, %g1
a009793c:  83 30 60 10  srl  %g1, 0x10, %g1
a0097940:  80 a0 60 01  cmp  %g1, 1
a0097944:  28 80 00 02  bleu,a   0xa009794c
a0097948:  ec 34 e0 1a  sth  %l6, [ %l3 + 0x1a ]
a009794c:  7f ff fe e8  call  0xa00974ec
a0097950:  90 10 00 14  mov  %l4, %o0
a0097954:  40 00 22 9d  call  0xa00a03c8
a0097958:  90 10 00 14  mov  %l4, %o0
a009795c:  80 8a 20 ff  btst  0xff, %o0
a0097960:  12 80 00 2c  bne  0xa0097a10
a0097964:  82 17 63 e0  or  %i5, 0x3e0, %g1
a0097968:  9a 5d 21 90  smul  %l4, 0x190, %o5
a009796c:  96 03 40 01  add  %o5, %g1, %o3
a0097970:  c2 0a e0 06  ldub  [ %o3 + 6 ], %g1
a0097974:  80 a0 60 00  cmp  %g1, 0
a0097978:  12 80 00 0a  bne  0xa00979a0
a009797c:  83 2c 60 10  sll  %l1, 0x10, %g1
a0097980:  9b 2e 20 10  sll  %i0, 0x10, %o5
a0097984:  9b 33 60 10  srl  %o5, 0x10, %o5
a0097988:  c2 12 e0 1c  lduh  [ %o3 + 0x1c ], %g1
a009798c:  82 20 40 0d  sub  %g1, %o5, %g1
a0097990:  82 00 60 05  add  %g1, 5, %g1
a0097994:  80 a0 60 0a  cmp  %g1, 0xa
a0097998:  18 80 00 1e  bgu  0xa0097a10
a009799c:  83 2c 60 10  sll  %l1, 0x10, %g1
a00979a0:  95 30 60 10  srl  %g1, 0x10, %o2
a00979a4:  c2 12 e0 1e  lduh  [ %o3 + 0x1e ], %g1
a00979a8:  82 20 40 0a  sub  %g1, %o2, %g1
a00979ac:  82 00 60 01  inc  %g1
a00979b0:  80 a0 60 02  cmp  %g1, 2
a00979b4:  18 80 00 17  bgu  0xa0097a10
a00979b8:  9b 2c a0 10  sll  %l2, 0x10, %o5
a00979bc:  9b 33 60 10  srl  %o5, 0x10, %o5
a00979c0:  c2 12 e0 20  lduh  [ %o3 + 0x20 ], %g1
a00979c4:  82 20 40 0d  sub  %g1, %o5, %g1
a00979c8:  82 00 60 01  inc  %g1
a00979cc:  80 a0 60 03  cmp  %g1, 3
a00979d0:  98 40 20 00  addx  %g0, 0, %o4
a00979d4:  80 a0 00 0d  cmp  %g0, %o5
a00979d8:  82 40 20 00  addx  %g0, 0, %g1
a00979dc:  80 8b 00 01  btst  %o4, %g1
a00979e0:  02 80 00 0c  be  0xa0097a10
a00979e4:  80 a2 a0 00  cmp  %o2, 0
a00979e8:  02 80 00 0a  be  0xa0097a10
a00979ec:  01 00 00 00  nop
a00979f0:  c2 12 e0 1a  lduh  [ %o3 + 0x1a ], %g1
a00979f4:  80 a0 60 00  cmp  %g1, 0
a00979f8:  02 80 00 06  be  0xa0097a10
a00979fc:  01 00 00 00  nop
a0097a00:  c2 12 e0 1c  lduh  [ %o3 + 0x1c ], %g1
a0097a04:  80 a0 60 00  cmp  %g1, 0
a0097a08:  12 80 00 2d  bne  0xa0097abc
a0097a0c:  82 0d e0 ff  and  %l7, 0xff, %g1
a0097a10:  40 00 22 6e  call  0xa00a03c8
a0097a14:  90 10 00 14  mov  %l4, %o0
a0097a18:  90 0a 20 ff  and  %o0, 0xff, %o0
a0097a1c:  80 a2 20 01  cmp  %o0, 1
a0097a20:  12 80 00 3d  bne  0xa0097b14
a0097a24:  82 05 00 14  add  %l4, %l4, %g1
a0097a28:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0097a2c:  82 5d 21 90  smul  %l4, 0x190, %g1
a0097a30:  9a 13 63 e0  or  %o5, 0x3e0, %o5
a0097a34:  96 00 40 0d  add  %g1, %o5, %o3
a0097a38:  c2 0a e0 06  ldub  [ %o3 + 6 ], %g1
a0097a3c:  80 a0 60 00  cmp  %g1, 0
a0097a40:  12 80 00 0b  bne  0xa0097a6c
a0097a44:  9b 2c a0 10  sll  %l2, 0x10, %o5
a0097a48:  9b 2e 20 10  sll  %i0, 0x10, %o5
a0097a4c:  9b 33 60 10  srl  %o5, 0x10, %o5
a0097a50:  c2 12 e0 1c  lduh  [ %o3 + 0x1c ], %g1
a0097a54:  82 20 40 0d  sub  %g1, %o5, %g1
a0097a58:  82 00 60 05  add  %g1, 5, %g1
a0097a5c:  80 a0 60 0a  cmp  %g1, 0xa
a0097a60:  18 80 00 2d  bgu  0xa0097b14
a0097a64:  82 05 00 14  add  %l4, %l4, %g1
a0097a68:  9b 2c a0 10  sll  %l2, 0x10, %o5
a0097a6c:  9b 33 60 10  srl  %o5, 0x10, %o5
a0097a70:  c2 12 e0 20  lduh  [ %o3 + 0x20 ], %g1
a0097a74:  82 20 40 0d  sub  %g1, %o5, %g1
a0097a78:  82 00 60 01  inc  %g1
a0097a7c:  80 a0 60 03  cmp  %g1, 3
a0097a80:  98 40 20 00  addx  %g0, 0, %o4
a0097a84:  80 a0 00 0d  cmp  %g0, %o5
a0097a88:  82 40 20 00  addx  %g0, 0, %g1
a0097a8c:  80 8b 00 01  btst  %o4, %g1
a0097a90:  02 80 00 21  be  0xa0097b14
a0097a94:  82 05 00 14  add  %l4, %l4, %g1
a0097a98:  9b 2c 60 10  sll  %l1, 0x10, %o5
a0097a9c:  c2 12 e0 1e  lduh  [ %o3 + 0x1e ], %g1
a0097aa0:  9b 33 60 10  srl  %o5, 0x10, %o5
a0097aa4:  82 20 40 0d  sub  %g1, %o5, %g1
a0097aa8:  82 00 60 01  inc  %g1
a0097aac:  80 a0 60 02  cmp  %g1, 2
a0097ab0:  18 80 00 19  bgu  0xa0097b14
a0097ab4:  82 05 00 14  add  %l4, %l4, %g1
a0097ab8:  82 0d e0 ff  and  %l7, 0xff, %g1
a0097abc:  9a 00 40 01  add  %g1, %g1, %o5
a0097ac0:  9a 03 40 01  add  %o5, %g1, %o5
a0097ac4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0097ac8:  82 10 62 50  or  %g1, 0x250, %g1	! 0xa807d650
a0097acc:  9b 2b 60 03  sll  %o5, 3, %o5
a0097ad0:  9a 03 40 01  add  %o5, %g1, %o5
a0097ad4:  c2 0b 60 05  ldub  [ %o5 + 5 ], %g1
a0097ad8:  94 00 60 01  add  %g1, 1, %o2
a0097adc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0097ae0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0097ae4:  80 88 60 04  btst  4, %g1
a0097ae8:  02 80 00 5d  be  0xa0097c5c
a0097aec:  d4 2b 60 05  stb  %o2, [ %o5 + 5 ]
a0097af0:  92 05 e0 41  add  %l7, 0x41, %o1
a0097af4:  93 2a 60 18  sll  %o1, 0x18, %o1
a0097af8:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a0097afc:  93 3a 60 18  sra  %o1, 0x18, %o1
a0097b00:  94 0a a0 ff  and  %o2, 0xff, %o2
a0097b04:  7f ff 6d 50  call  0xa0073044
a0097b08:  90 12 22 48  or  %o0, 0x248, %o0
a0097b0c:  10 80 00 55  b  0xa0097c60
a0097b10:  a0 0d e0 ff  and  %l7, 0xff, %l0
a0097b14:  82 00 40 14  add  %g1, %l4, %g1
a0097b18:  a1 28 60 03  sll  %g1, 3, %l0
a0097b1c:  9a 16 63 00  or  %i1, 0x300, %o5
a0097b20:  82 5d 20 34  smul  %l4, 0x34, %g1
a0097b24:  2b 2a 01 f5  sethi  %hi(0xa807d400), %l5
a0097b28:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0097b2c:  a6 15 62 50  or  %l5, 0x250, %l3
a0097b30:  82 04 00 13  add  %l0, %l3, %g1
a0097b34:  c0 28 60 05  clrb  [ %g1 + 5 ]
a0097b38:  92 02 60 08  add  %o1, 8, %o1
a0097b3c:  40 00 3e 33  call  0xa00a7408
a0097b40:  90 10 20 0b  mov  0xb, %o0
a0097b44:  80 a2 20 00  cmp  %o0, 0
a0097b48:  22 80 00 08  be,a   0xa0097b68
a0097b4c:  a0 0f 20 ff  and  %i4, 0xff, %l0
a0097b50:  92 05 e0 41  add  %l7, 0x41, %o1
a0097b54:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a0097b58:  93 2a 60 18  sll  %o1, 0x18, %o1
a0097b5c:  c0 24 c0 10  clr  [ %l3 + %l0 ]
a0097b60:  10 80 00 3d  b  0xa0097c54
a0097b64:  90 12 22 78  or  %o0, 0x278, %o0
a0097b68:  7f ff 75 85  call  0xa007517c
a0097b6c:  90 10 00 10  mov  %l0, %o0
a0097b70:  80 8a 20 ff  btst  0xff, %o0
a0097b74:  02 80 00 12  be  0xa0097bbc
a0097b78:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0097b7c:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0097b80:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0097b84:  80 88 60 04  btst  4, %g1
a0097b88:  22 80 00 09  be,a   0xa0097bac
a0097b8c:  90 10 00 10  mov  %l0, %o0
a0097b90:  92 05 e0 41  add  %l7, 0x41, %o1
a0097b94:  93 2a 60 18  sll  %o1, 0x18, %o1
a0097b98:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a0097b9c:  90 12 22 a0  or  %o0, 0x2a0, %o0	! 0xa0069aa0
a0097ba0:  7f ff 6d 29  call  0xa0073044
a0097ba4:  93 3a 60 18  sra  %o1, 0x18, %o1
a0097ba8:  90 10 00 10  mov  %l0, %o0
a0097bac:  7f ff 80 af  call  0xa0077e68
a0097bb0:  92 10 20 00  clr  %o1
a0097bb4:  10 80 00 19  b  0xa0097c18
a0097bb8:  9a 04 00 10  add  %l0, %l0, %o5
a0097bbc:  a6 10 60 e0  or  %g1, 0xe0, %l3
a0097bc0:  c2 0c c0 14  ldub  [ %l3 + %l4 ], %g1
a0097bc4:  82 00 60 01  inc  %g1
a0097bc8:  9a 08 60 ff  and  %g1, 0xff, %o5
a0097bcc:  80 a3 60 01  cmp  %o5, 1
a0097bd0:  08 80 00 11  bleu  0xa0097c14
a0097bd4:  c2 2c c0 14  stb  %g1, [ %l3 + %l4 ]
a0097bd8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0097bdc:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0097be0:  80 88 60 04  btst  4, %g1
a0097be4:  22 80 00 09  be,a   0xa0097c08
a0097be8:  90 10 00 10  mov  %l0, %o0
a0097bec:  92 05 e0 41  add  %l7, 0x41, %o1
a0097bf0:  93 2a 60 18  sll  %o1, 0x18, %o1
a0097bf4:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a0097bf8:  90 12 22 d8  or  %o0, 0x2d8, %o0	! 0xa0069ad8
a0097bfc:  7f ff 6d 12  call  0xa0073044
a0097c00:  93 3a 60 18  sra  %o1, 0x18, %o1
a0097c04:  90 10 00 10  mov  %l0, %o0
a0097c08:  7f ff 80 98  call  0xa0077e68
a0097c0c:  92 10 20 01  mov  1, %o1
a0097c10:  c0 2c c0 14  clrb  [ %l3 + %l4 ]
a0097c14:  9a 04 00 10  add  %l0, %l0, %o5
a0097c18:  9a 03 40 10  add  %o5, %l0, %o5
a0097c1c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0097c20:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a0097c24:  98 05 00 14  add  %l4, %l4, %o4
a0097c28:  9b 2b 60 03  sll  %o5, 3, %o5
a0097c2c:  9a 03 40 01  add  %o5, %g1, %o5
a0097c30:  98 03 00 14  add  %o4, %l4, %o4
a0097c34:  82 15 62 50  or  %l5, 0x250, %g1
a0097c38:  99 2b 20 03  sll  %o4, 3, %o4
a0097c3c:  92 05 e0 41  add  %l7, 0x41, %o1
a0097c40:  c0 20 40 0c  clr  [ %g1 + %o4 ]
a0097c44:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a0097c48:  93 2a 60 18  sll  %o1, 0x18, %o1
a0097c4c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a0097c50:  90 12 23 08  or  %o0, 0x308, %o0
a0097c54:  7f ff 6c fc  call  0xa0073044
a0097c58:  93 3a 60 18  sra  %o1, 0x18, %o1
a0097c5c:  a0 0d e0 ff  and  %l7, 0xff, %l0
a0097c60:  2b 2a 01 f5  sethi  %hi(0xa807d400), %l5
a0097c64:  9a 15 63 e0  or  %l5, 0x3e0, %o5	! 0xa807d7e0
a0097c68:  82 5c 21 90  smul  %l0, 0x190, %g1
a0097c6c:  82 00 40 0d  add  %g1, %o5, %g1
a0097c70:  e2 30 60 1e  sth  %l1, [ %g1 + 0x1e ]
a0097c74:  e4 30 60 20  sth  %l2, [ %g1 + 0x20 ]
a0097c78:  f4 30 60 1a  sth  %i2, [ %g1 + 0x1a ]
a0097c7c:  f0 30 60 1c  sth  %i0, [ %g1 + 0x1c ]
a0097c80:  40 00 2a b4  call  0xa00a2750
a0097c84:  90 10 00 10  mov  %l0, %o0
a0097c88:  83 2e e0 10  sll  %i3, 0x10, %g1
a0097c8c:  91 2a 20 10  sll  %o0, 0x10, %o0
a0097c90:  93 30 60 10  srl  %g1, 0x10, %o1
a0097c94:  91 32 20 10  srl  %o0, 0x10, %o0
a0097c98:  90 22 00 09  sub  %o0, %o1, %o0
a0097c9c:  83 3a 20 1f  sra  %o0, 0x1f, %g1
a0097ca0:  90 18 40 08  xor  %g1, %o0, %o0
a0097ca4:  90 22 00 01  sub  %o0, %g1, %o0
a0097ca8:  91 2a 20 10  sll  %o0, 0x10, %o0
a0097cac:  a3 32 20 10  srl  %o0, 0x10, %l1
a0097cb0:  80 a4 60 28  cmp  %l1, 0x28
a0097cb4:  18 80 00 04  bgu  0xa0097cc4
a0097cb8:  9a 06 ff 9b  add  %i3, -101, %o5
a0097cbc:  82 10 20 01  mov  1, %g1
a0097cc0:  c2 2f bf f7  stb  %g1, [ %fp + -9 ]
a0097cc4:  9b 2b 60 10  sll  %o5, 0x10, %o5
a0097cc8:  03 00 00 11  sethi  %hi(0x4400), %g1
a0097ccc:  9b 33 60 10  srl  %o5, 0x10, %o5
a0097cd0:  82 10 61 22  or  %g1, 0x122, %g1
a0097cd4:  80 a3 40 01  cmp  %o5, %g1
a0097cd8:  18 80 00 05  bgu  0xa0097cec
a0097cdc:  e4 0f bf f7  ldub  [ %fp + -9 ], %l2
a0097ce0:  7f ff fe bb  call  0xa00977cc
a0097ce4:  90 10 00 10  mov  %l0, %o0
a0097ce8:  e4 0f bf f7  ldub  [ %fp + -9 ], %l2
a0097cec:  80 a4 a0 00  cmp  %l2, 0
a0097cf0:  12 80 00 1c  bne  0xa0097d60
a0097cf4:  82 04 00 10  add  %l0, %l0, %g1
a0097cf8:  40 00 2a 96  call  0xa00a2750
a0097cfc:  90 10 00 10  mov  %l0, %o0
a0097d00:  93 2a 20 10  sll  %o0, 0x10, %o1
a0097d04:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a0097d08:  90 12 23 58  or  %o0, 0x358, %o0	! 0xa0069b58
a0097d0c:  7f ff 6c ce  call  0xa0073044
a0097d10:  93 32 60 10  srl  %o1, 0x10, %o1
a0097d14:  9a 04 00 10  add  %l0, %l0, %o5
a0097d18:  9a 03 40 10  add  %o5, %l0, %o5
a0097d1c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0097d20:  82 10 62 50  or  %g1, 0x250, %g1	! 0xa807d650
a0097d24:  9b 2b 60 03  sll  %o5, 3, %o5
a0097d28:  9a 03 40 01  add  %o5, %g1, %o5
a0097d2c:  c2 0b 60 05  ldub  [ %o5 + 5 ], %g1
a0097d30:  80 a0 60 03  cmp  %g1, 3
a0097d34:  18 80 00 03  bgu  0xa0097d40
a0097d38:  98 10 20 01  mov  1, %o4
a0097d3c:  98 10 20 00  clr  %o4
a0097d40:  80 a4 61 f4  cmp  %l1, 0x1f4
a0097d44:  18 80 00 03  bgu  0xa0097d50
a0097d48:  82 10 20 01  mov  1, %g1
a0097d4c:  82 10 20 00  clr  %g1
a0097d50:  80 8b 00 01  btst  %o4, %g1
a0097d54:  32 80 00 02  bne,a   0xa0097d5c
a0097d58:  c0 2b 60 05  clrb  [ %o5 + 5 ]
a0097d5c:  82 04 00 10  add  %l0, %l0, %g1
a0097d60:  82 00 40 10  add  %g1, %l0, %g1
a0097d64:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a0097d68:  a3 28 60 03  sll  %g1, 3, %l1
a0097d6c:  a6 15 22 50  or  %l4, 0x250, %l3
a0097d70:  82 04 40 13  add  %l1, %l3, %g1
a0097d74:  da 08 60 05  ldub  [ %g1 + 5 ], %o5
a0097d78:  c2 0f bf f6  ldub  [ %fp + -10 ], %g1
a0097d7c:  80 a0 40 0d  cmp  %g1, %o5
a0097d80:  82 40 20 00  addx  %g0, 0, %g1
a0097d84:  80 88 40 12  btst  %g1, %l2
a0097d88:  02 80 00 50  be  0xa0097ec8
a0097d8c:  b0 10 20 00  clr  %i0
a0097d90:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0097d94:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a0097d98:  9a 13 62 80  or  %o5, 0x280, %o5
a0097d9c:  82 00 40 0d  add  %g1, %o5, %g1
a0097da0:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a0097da4:  80 a0 60 00  cmp  %g1, 0
a0097da8:  02 80 00 30  be  0xa0097e68
a0097dac:  92 10 20 00  clr  %o1
a0097db0:  40 00 2a 68  call  0xa00a2750
a0097db4:  90 10 00 10  mov  %l0, %o0
a0097db8:  82 0f 20 ff  and  %i4, 0xff, %g1
a0097dbc:  9a 00 40 01  add  %g1, %g1, %o5
a0097dc0:  9a 03 40 01  add  %o5, %g1, %o5
a0097dc4:  82 15 63 e0  or  %l5, 0x3e0, %g1
a0097dc8:  98 5c 21 90  smul  %l0, 0x190, %o4
a0097dcc:  98 03 00 01  add  %o4, %g1, %o4
a0097dd0:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0097dd4:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a0097dd8:  96 5c 20 34  smul  %l0, 0x34, %o3
a0097ddc:  d6 00 40 0b  ld  [ %g1 + %o3 ], %o3
a0097de0:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0097de4:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a0097de8:  9b 2b 60 03  sll  %o5, 3, %o5
a0097dec:  9a 03 40 01  add  %o5, %g1, %o5
a0097df0:  91 2a 20 10  sll  %o0, 0x10, %o0
a0097df4:  d2 13 60 08  lduh  [ %o5 + 8 ], %o1
a0097df8:  c2 0b 20 19  ldub  [ %o4 + 0x19 ], %g1
a0097dfc:  91 32 20 10  srl  %o0, 0x10, %o0
a0097e00:  90 5a 00 01  smul  %o0, %g1, %o0
a0097e04:  da 02 e0 08  ld  [ %o3 + 8 ], %o5
a0097e08:  9a 0b 60 c0  and  %o5, 0xc0, %o5
a0097e0c:  83 2a 60 02  sll  %o1, 2, %g1
a0097e10:  91 3a 20 03  sra  %o0, 3, %o0
a0097e14:  9b 33 60 06  srl  %o5, 6, %o5
a0097e18:  82 00 40 09  add  %g1, %o1, %g1
a0097e1c:  82 00 40 01  add  %g1, %g1, %g1
a0097e20:  91 2a 00 0d  sll  %o0, %o5, %o0
a0097e24:  90 22 00 01  sub  %o0, %g1, %o0
a0097e28:  83 3a 20 1f  sra  %o0, 0x1f, %g1
a0097e2c:  90 18 40 08  xor  %g1, %o0, %o0
a0097e30:  90 22 00 01  sub  %o0, %g1, %o0
a0097e34:  80 a2 21 f4  cmp  %o0, 0x1f4
a0097e38:  24 80 00 0c  ble,a   0xa0097e68
a0097e3c:  92 10 20 00  clr  %o1
a0097e40:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0097e44:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0097e48:  80 88 60 04  btst  4, %g1
a0097e4c:  22 80 00 1e  be,a   0xa0097ec4
a0097e50:  c0 24 c0 11  clr  [ %l3 + %l1 ]
a0097e54:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a0097e58:  7f ff 6c 7b  call  0xa0073044
a0097e5c:  90 12 23 78  or  %o0, 0x378, %o0	! 0xa0069b78
a0097e60:  10 80 00 19  b  0xa0097ec4
a0097e64:  c0 24 c0 11  clr  [ %l3 + %l1 ]
a0097e68:  7f ff 80 00  call  0xa0077e68
a0097e6c:  90 0f 20 03  and  %i4, 3, %o0
a0097e70:  9a 04 00 10  add  %l0, %l0, %o5
a0097e74:  9a 03 40 10  add  %o5, %l0, %o5
a0097e78:  9b 2b 60 03  sll  %o5, 3, %o5
a0097e7c:  98 15 22 50  or  %l4, 0x250, %o4
a0097e80:  96 03 40 0c  add  %o5, %o4, %o3
a0097e84:  82 10 20 0f  mov  0xf, %g1
a0097e88:  c2 2a e0 09  stb  %g1, [ %o3 + 9 ]
a0097e8c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a0097e90:  82 10 60 e0  or  %g1, 0xe0, %g1	! 0xa80790e0
a0097e94:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a0097e98:  82 10 20 06  mov  6, %g1
a0097e9c:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a0097ea0:  82 10 20 0a  mov  0xa, %g1
a0097ea4:  c2 2a e0 06  stb  %g1, [ %o3 + 6 ]
a0097ea8:  40 00 2a 2a  call  0xa00a2750
a0097eac:  90 10 00 10  mov  %l0, %o0
a0097eb0:  93 2a 20 10  sll  %o0, 0x10, %o1
a0097eb4:  11 28 01 a6  sethi  %hi(0xa0069800), %o0
a0097eb8:  90 12 23 d0  or  %o0, 0x3d0, %o0	! 0xa0069bd0
a0097ebc:  7f ff 6c 62  call  0xa0073044
a0097ec0:  93 32 60 10  srl  %o1, 0x10, %o1
a0097ec4:  b0 10 20 01  mov  1, %i0
a0097ec8:  81 c7 e0 08  ret
a0097ecc:  81 e8 00 00  restore
