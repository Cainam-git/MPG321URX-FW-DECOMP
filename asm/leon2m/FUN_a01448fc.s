# leon2m FUN_a01448fc 0xa01448fc-0xa014505c (208 bytes)
a01448fc:  9d e3 bf 98  save  %sp, -104, %sp
a0144900:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0144904:  80 a6 20 01  cmp  %i0, 1
a0144908:  02 80 00 0b  be  0xa0144934
a014490c:  82 10 20 01  mov  1, %g1
a0144910:  80 a6 20 01  cmp  %i0, 1
a0144914:  04 80 00 39  ble  0xa01449f8
a0144918:  80 a6 20 02  cmp  %i0, 2
a014491c:  02 80 00 06  be  0xa0144934
a0144920:  82 10 20 02  mov  2, %g1
a0144924:  80 a6 20 03  cmp  %i0, 3
a0144928:  02 80 00 03  be  0xa0144934
a014492c:  82 10 20 03  mov  3, %g1
a0144930:  82 10 3f ff  mov  -1, %g1
a0144934:  96 08 60 ff  and  %g1, 0xff, %o3
a0144938:  80 a2 e0 03  cmp  %o3, 3
a014493c:  18 80 00 2b  bgu  0xa01449e8
a0144940:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0144944:  95 2a e0 04  sll  %o3, 4, %o2
a0144948:  9a 22 80 0b  sub  %o2, %o3, %o5
a014494c:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0144950:  83 2b 60 03  sll  %o5, 3, %g1
a0144954:  92 12 a3 30  or  %o2, 0x330, %o1
a0144958:  d0 02 40 01  ld  [ %o1 + %g1 ], %o0
a014495c:  b1 32 20 0c  srl  %o0, 0xc, %i0
a0144960:  9e 0e 20 0f  and  %i0, 0xf, %o7
a0144964:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a0144968:  92 5b e0 2a  smul  %o7, 0x2a, %o1
a014496c:  9a 13 22 24  or  %o4, 0x224, %o5
a0144970:  82 02 40 0d  add  %o1, %o5, %g1
a0144974:  c2 08 60 28  ldub  [ %g1 + 0x28 ], %g1
a0144978:  80 a0 60 27  cmp  %g1, 0x27
a014497c:  18 80 01 b5  bgu  0xa0145050
a0144980:  b0 10 20 28  mov  0x28, %i0
a0144984:  11 00 03 8c  sethi  %hi(0xe3000), %o0
a0144988:  9f 28 60 02  sll  %g1, 2, %o7
a014498c:  b0 12 20 a8  or  %o0, 0xa8, %i0
a0144990:  d8 06 00 0f  ld  [ %i0 + %o7 ], %o4
a0144994:  81 c3 00 00  jmp  %o4
a0144998:  01 00 00 00  nop
a014499c:  83 2a e0 04  sll  %o3, 4, %g1
a01449a0:  b0 20 40 0b  sub  %g1, %o3, %i0
a01449a4:  93 2e 20 03  sll  %i0, 3, %o1
a01449a8:  9a 12 a3 30  or  %o2, 0x330, %o5
a01449ac:  d0 03 40 09  ld  [ %o5 + %o1 ], %o0
a01449b0:  9f 32 20 0c  srl  %o0, 0xc, %o7
a01449b4:  90 0b e0 0f  and  %o7, 0xf, %o0
a01449b8:  7f fe e3 9a  call  0xa00fd820
a01449bc:  b0 10 20 00  clr  %i0
a01449c0:  98 0a 20 ff  and  %o0, 0xff, %o4
a01449c4:  80 a3 20 b1  cmp  %o4, 0xb1
a01449c8:  02 80 01 12  be  0xa0144e10
a01449cc:  01 00 00 00  nop
a01449d0:  9e 0e 20 01  and  %i0, 1, %o7
a01449d4:  80 a0 00 0f  cmp  %g0, %o7
a01449d8:  98 40 3f ff  addx  %g0, -1, %o4
a01449dc:  94 0b 3f fe  and  %o4, -2, %o2
a01449e0:  10 80 01 9c  b  0xa0145050
a01449e4:  b0 02 a0 25  add  %o2, 0x25, %i0
a01449e8:  7f fe 69 e2  call  0xa00df170
a01449ec:  90 12 21 d8  or  %o0, 0x1d8, %o0
a01449f0:  10 bf ff d5  b  0xa0144944
a01449f4:  96 10 20 00  clr  %o3
a01449f8:  80 a6 20 00  cmp  %i0, 0
a01449fc:  02 bf ff ce  be  0xa0144934
a0144a00:  82 10 20 00  clr  %g1
a0144a04:  10 bf ff cc  b  0xa0144934
a0144a08:  82 10 3f ff  mov  -1, %g1
a0144a0c:  10 80 01 91  b  0xa0145050
a0144a10:  b0 10 20 27  mov  0x27, %i0
a0144a14:  10 80 01 8f  b  0xa0145050
a0144a18:  b0 10 20 00  clr  %i0
a0144a1c:  10 80 01 8d  b  0xa0145050
a0144a20:  b0 10 20 01  mov  1, %i0
a0144a24:  9f 2a e0 04  sll  %o3, 4, %o7
a0144a28:  98 23 c0 0b  sub  %o7, %o3, %o4
a0144a2c:  9a 12 a3 30  or  %o2, 0x330, %o5
a0144a30:  95 2b 20 03  sll  %o4, 3, %o2
a0144a34:  d2 03 40 0a  ld  [ %o5 + %o2 ], %o1
a0144a38:  83 32 60 0c  srl  %o1, 0xc, %g1
a0144a3c:  7f fe e3 79  call  0xa00fd820
a0144a40:  90 08 60 0f  and  %g1, 0xf, %o0
a0144a44:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144a48:  80 a2 e0 b1  cmp  %o3, 0xb1
a0144a4c:  02 80 01 51  be  0xa0144f90
a0144a50:  b0 10 20 00  clr  %i0
a0144a54:  82 0e 20 01  and  %i0, 1, %g1
a0144a58:  80 a0 00 01  cmp  %g0, %g1
a0144a5c:  b0 40 3f ff  addx  %g0, -1, %i0
a0144a60:  96 0e 3f fe  and  %i0, -2, %o3
a0144a64:  10 80 01 7b  b  0xa0145050
a0144a68:  b0 02 e0 04  add  %o3, 4, %i0
a0144a6c:  b1 2a e0 04  sll  %o3, 4, %i0
a0144a70:  90 26 00 0b  sub  %i0, %o3, %o0
a0144a74:  9a 12 a3 30  or  %o2, 0x330, %o5
a0144a78:  9f 2a 20 03  sll  %o0, 3, %o7
a0144a7c:  d8 03 40 0f  ld  [ %o5 + %o7 ], %o4
a0144a80:  95 33 20 0c  srl  %o4, 0xc, %o2
a0144a84:  7f fe e3 67  call  0xa00fd820
a0144a88:  90 0a a0 0f  and  %o2, 0xf, %o0
a0144a8c:  92 0a 20 ff  and  %o0, 0xff, %o1
a0144a90:  80 a2 60 b1  cmp  %o1, 0xb1
a0144a94:  02 80 01 4b  be  0xa0144fc0
a0144a98:  b0 10 20 00  clr  %i0
a0144a9c:  94 0e 20 01  and  %i0, 1, %o2
a0144aa0:  80 a0 00 0a  cmp  %g0, %o2
a0144aa4:  92 40 3f ff  addx  %g0, -1, %o1
a0144aa8:  82 0a 7f fe  and  %o1, -2, %g1
a0144aac:  10 80 01 69  b  0xa0145050
a0144ab0:  b0 00 60 05  add  %g1, 5, %i0
a0144ab4:  10 80 01 67  b  0xa0145050
a0144ab8:  b0 10 20 05  mov  5, %i0
a0144abc:  10 80 01 65  b  0xa0145050
a0144ac0:  b0 10 20 04  mov  4, %i0
a0144ac4:  10 80 01 63  b  0xa0145050
a0144ac8:  b0 10 20 06  mov  6, %i0
a0144acc:  10 80 01 61  b  0xa0145050
a0144ad0:  b0 10 20 07  mov  7, %i0
a0144ad4:  93 2a e0 04  sll  %o3, 4, %o1
a0144ad8:  82 22 40 0b  sub  %o1, %o3, %g1
a0144adc:  b1 28 60 03  sll  %g1, 3, %i0
a0144ae0:  9a 12 a3 30  or  %o2, 0x330, %o5
a0144ae4:  d0 03 40 18  ld  [ %o5 + %i0 ], %o0
a0144ae8:  9f 32 20 0c  srl  %o0, 0xc, %o7
a0144aec:  90 0b e0 0f  and  %o7, 0xf, %o0
a0144af0:  7f fe e3 4c  call  0xa00fd820
a0144af4:  b0 10 20 00  clr  %i0
a0144af8:  98 0a 20 ff  and  %o0, 0xff, %o4
a0144afc:  80 a3 20 b1  cmp  %o4, 0xb1
a0144b00:  02 80 01 3c  be  0xa0144ff0
a0144b04:  01 00 00 00  nop
a0144b08:  9e 0e 20 01  and  %i0, 1, %o7
a0144b0c:  80 a0 00 0f  cmp  %g0, %o7
a0144b10:  98 40 3f ff  addx  %g0, -1, %o4
a0144b14:  94 0b 3f fe  and  %o4, -2, %o2
a0144b18:  10 80 01 4e  b  0xa0145050
a0144b1c:  b0 02 a0 0a  add  %o2, 0xa, %i0
a0144b20:  9f 2a e0 04  sll  %o3, 4, %o7
a0144b24:  98 23 c0 0b  sub  %o7, %o3, %o4
a0144b28:  9a 12 a3 30  or  %o2, 0x330, %o5
a0144b2c:  83 2b 20 03  sll  %o4, 3, %g1
a0144b30:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0144b34:  b1 32 60 0c  srl  %o1, 0xc, %i0
a0144b38:  7f fe e3 3a  call  0xa00fd820
a0144b3c:  90 0e 20 0f  and  %i0, 0xf, %o0
a0144b40:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144b44:  80 a2 20 b1  cmp  %o0, 0xb1
a0144b48:  02 80 00 ca  be  0xa0144e70
a0144b4c:  b0 10 20 00  clr  %i0
a0144b50:  92 0e 20 01  and  %i0, 1, %o1
a0144b54:  80 a0 00 09  cmp  %g0, %o1
a0144b58:  90 40 3f ff  addx  %g0, -1, %o0
a0144b5c:  94 0a 3f fe  and  %o0, -2, %o2
a0144b60:  10 80 01 3c  b  0xa0145050
a0144b64:  b0 02 a0 0b  add  %o2, 0xb, %i0
a0144b68:  10 80 01 3a  b  0xa0145050
a0144b6c:  b0 10 20 17  mov  0x17, %i0
a0144b70:  83 2a e0 04  sll  %o3, 4, %g1
a0144b74:  b0 20 40 0b  sub  %g1, %o3, %i0
a0144b78:  93 2e 20 03  sll  %i0, 3, %o1
a0144b7c:  9a 12 a3 30  or  %o2, 0x330, %o5
a0144b80:  d0 03 40 09  ld  [ %o5 + %o1 ], %o0
a0144b84:  9f 32 20 0c  srl  %o0, 0xc, %o7
a0144b88:  90 0b e0 0f  and  %o7, 0xf, %o0
a0144b8c:  7f fe e3 25  call  0xa00fd820
a0144b90:  b0 10 20 00  clr  %i0
a0144b94:  98 0a 20 ff  and  %o0, 0xff, %o4
a0144b98:  80 a3 20 b1  cmp  %o4, 0xb1
a0144b9c:  02 80 00 cd  be  0xa0144ed0
a0144ba0:  01 00 00 00  nop
a0144ba4:  9e 0e 20 01  and  %i0, 1, %o7
a0144ba8:  80 a0 00 0f  cmp  %g0, %o7
a0144bac:  98 40 3f ff  addx  %g0, -1, %o4
a0144bb0:  94 0b 3f fe  and  %o4, -2, %o2
a0144bb4:  10 80 01 27  b  0xa0145050
a0144bb8:  b0 02 a0 11  add  %o2, 0x11, %i0
a0144bbc:  10 80 01 25  b  0xa0145050
a0144bc0:  b0 10 20 10  mov  0x10, %i0
a0144bc4:  10 80 01 23  b  0xa0145050
a0144bc8:  b0 10 20 11  mov  0x11, %i0
a0144bcc:  10 80 01 21  b  0xa0145050
a0144bd0:  b0 10 20 12  mov  0x12, %i0
a0144bd4:  10 80 01 1f  b  0xa0145050
a0144bd8:  b0 10 20 13  mov  0x13, %i0
a0144bdc:  9f 2a e0 04  sll  %o3, 4, %o7
a0144be0:  98 23 c0 0b  sub  %o7, %o3, %o4
a0144be4:  9a 12 a3 30  or  %o2, 0x330, %o5
a0144be8:  83 2b 20 03  sll  %o4, 3, %g1
a0144bec:  f0 03 40 01  ld  [ %o5 + %g1 ], %i0
a0144bf0:  93 36 20 0c  srl  %i0, 0xc, %o1
a0144bf4:  7f fe e3 0b  call  0xa00fd820
a0144bf8:  90 0a 60 0f  and  %o1, 0xf, %o0
a0144bfc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144c00:  80 a2 20 b1  cmp  %o0, 0xb1
a0144c04:  02 80 00 cb  be  0xa0144f30
a0144c08:  b0 10 20 00  clr  %i0
a0144c0c:  92 0e 20 01  and  %i0, 1, %o1
a0144c10:  80 a0 00 09  cmp  %g0, %o1
a0144c14:  90 40 3f ff  addx  %g0, -1, %o0
a0144c18:  94 0a 3f fe  and  %o0, -2, %o2
a0144c1c:  10 80 01 0d  b  0xa0145050
a0144c20:  b0 02 a0 16  add  %o2, 0x16, %i0
a0144c24:  93 2a e0 04  sll  %o3, 4, %o1
a0144c28:  90 22 40 0b  sub  %o1, %o3, %o0
a0144c2c:  9f 2a 20 03  sll  %o0, 3, %o7
a0144c30:  9a 12 a3 30  or  %o2, 0x330, %o5
a0144c34:  d8 03 40 0f  ld  [ %o5 + %o7 ], %o4
a0144c38:  83 33 20 0c  srl  %o4, 0xc, %g1
a0144c3c:  7f fe e2 f9  call  0xa00fd820
a0144c40:  90 08 60 0f  and  %g1, 0xf, %o0
a0144c44:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0144c48:  80 a6 20 b1  cmp  %i0, 0xb1
a0144c4c:  02 80 00 c5  be  0xa0144f60
a0144c50:  b0 10 20 00  clr  %i0
a0144c54:  82 0e 20 01  and  %i0, 1, %g1
a0144c58:  80 a0 00 01  cmp  %g0, %g1
a0144c5c:  b0 40 3f ff  addx  %g0, -1, %i0
a0144c60:  94 0e 3f fe  and  %i0, -2, %o2
a0144c64:  10 80 00 fb  b  0xa0145050
a0144c68:  b0 02 a0 17  add  %o2, 0x17, %i0
a0144c6c:  10 80 00 f9  b  0xa0145050
a0144c70:  b0 10 20 16  mov  0x16, %i0
a0144c74:  10 80 00 f7  b  0xa0145050
a0144c78:  b0 10 20 0b  mov  0xb, %i0
a0144c7c:  10 80 00 f5  b  0xa0145050
a0144c80:  b0 10 20 0c  mov  0xc, %i0
a0144c84:  10 80 00 f3  b  0xa0145050
a0144c88:  b0 10 20 0d  mov  0xd, %i0
a0144c8c:  93 2a e0 04  sll  %o3, 4, %o1
a0144c90:  90 22 40 0b  sub  %o1, %o3, %o0
a0144c94:  9f 2a 20 03  sll  %o0, 3, %o7
a0144c98:  9a 12 a3 30  or  %o2, 0x330, %o5
a0144c9c:  d8 03 40 0f  ld  [ %o5 + %o7 ], %o4
a0144ca0:  83 33 20 0c  srl  %o4, 0xc, %g1
a0144ca4:  7f fe e2 df  call  0xa00fd820
a0144ca8:  90 08 60 0f  and  %g1, 0xf, %o0
a0144cac:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0144cb0:  80 a6 20 b1  cmp  %i0, 0xb1
a0144cb4:  02 80 00 db  be  0xa0145020
a0144cb8:  b0 10 20 00  clr  %i0
a0144cbc:  82 0e 20 01  and  %i0, 1, %g1
a0144cc0:  80 a0 00 01  cmp  %g0, %g1
a0144cc4:  b0 40 3f ff  addx  %g0, -1, %i0
a0144cc8:  94 0e 3f fe  and  %i0, -2, %o2
a0144ccc:  10 80 00 e1  b  0xa0145050
a0144cd0:  b0 02 a0 10  add  %o2, 0x10, %i0
a0144cd4:  10 80 00 df  b  0xa0145050
a0144cd8:  b0 10 20 0a  mov  0xa, %i0
a0144cdc:  10 80 00 dd  b  0xa0145050
a0144ce0:  b0 10 20 1f  mov  0x1f, %i0
a0144ce4:  10 80 00 db  b  0xa0145050
a0144ce8:  b0 10 20 20  mov  0x20, %i0
a0144cec:  10 80 00 d9  b  0xa0145050
a0144cf0:  b0 10 20 21  mov  0x21, %i0
a0144cf4:  93 2a e0 04  sll  %o3, 4, %o1
a0144cf8:  90 22 40 0b  sub  %o1, %o3, %o0
a0144cfc:  9f 2a 20 03  sll  %o0, 3, %o7
a0144d00:  9a 12 a3 30  or  %o2, 0x330, %o5
a0144d04:  d8 03 40 0f  ld  [ %o5 + %o7 ], %o4
a0144d08:  83 33 20 0c  srl  %o4, 0xc, %g1
a0144d0c:  7f fe e2 c5  call  0xa00fd820
a0144d10:  90 08 60 0f  and  %g1, 0xf, %o0
a0144d14:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0144d18:  80 a6 20 b1  cmp  %i0, 0xb1
a0144d1c:  02 80 00 79  be  0xa0144f00
a0144d20:  b0 10 20 00  clr  %i0
a0144d24:  82 0e 20 01  and  %i0, 1, %g1
a0144d28:  80 a0 00 01  cmp  %g0, %g1
a0144d2c:  b0 40 3f ff  addx  %g0, -1, %i0
a0144d30:  94 0e 3f fe  and  %i0, -2, %o2
a0144d34:  10 80 00 c7  b  0xa0145050
a0144d38:  b0 02 a0 24  add  %o2, 0x24, %i0
a0144d3c:  10 80 00 c5  b  0xa0145050
a0144d40:  b0 10 20 1b  mov  0x1b, %i0
a0144d44:  10 80 00 c3  b  0xa0145050
a0144d48:  b0 10 20 25  mov  0x25, %i0
a0144d4c:  10 80 00 c1  b  0xa0145050
a0144d50:  b0 10 20 26  mov  0x26, %i0
a0144d54:  10 80 00 bf  b  0xa0145050
a0144d58:  b0 10 20 24  mov  0x24, %i0
a0144d5c:  10 80 00 bd  b  0xa0145050
a0144d60:  b0 10 20 19  mov  0x19, %i0
a0144d64:  10 80 00 bb  b  0xa0145050
a0144d68:  b0 10 20 1a  mov  0x1a, %i0
a0144d6c:  10 80 00 b9  b  0xa0145050
a0144d70:  b0 10 20 18  mov  0x18, %i0
a0144d74:  9f 2a e0 04  sll  %o3, 4, %o7
a0144d78:  98 23 c0 0b  sub  %o7, %o3, %o4
a0144d7c:  9a 12 a3 30  or  %o2, 0x330, %o5
a0144d80:  83 2b 20 03  sll  %o4, 3, %g1
a0144d84:  f0 03 40 01  ld  [ %o5 + %g1 ], %i0
a0144d88:  93 36 20 0c  srl  %i0, 0xc, %o1
a0144d8c:  7f fe e2 a5  call  0xa00fd820
a0144d90:  90 0a 60 0f  and  %o1, 0xf, %o0
a0144d94:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144d98:  80 a2 20 b1  cmp  %o0, 0xb1
a0144d9c:  02 80 00 41  be  0xa0144ea0
a0144da0:  b0 10 20 00  clr  %i0
a0144da4:  92 0e 20 01  and  %i0, 1, %o1
a0144da8:  80 a0 00 09  cmp  %g0, %o1
a0144dac:  90 40 3f ff  addx  %g0, -1, %o0
a0144db0:  94 0a 3f fe  and  %o0, -2, %o2
a0144db4:  10 80 00 a7  b  0xa0145050
a0144db8:  b0 02 a0 1f  add  %o2, 0x1f, %i0
a0144dbc:  10 80 00 a5  b  0xa0145050
a0144dc0:  b0 10 20 1e  mov  0x1e, %i0
a0144dc4:  83 2a e0 04  sll  %o3, 4, %g1
a0144dc8:  b0 20 40 0b  sub  %g1, %o3, %i0
a0144dcc:  93 2e 20 03  sll  %i0, 3, %o1
a0144dd0:  9a 12 a3 30  or  %o2, 0x330, %o5
a0144dd4:  d0 03 40 09  ld  [ %o5 + %o1 ], %o0
a0144dd8:  9f 32 20 0c  srl  %o0, 0xc, %o7
a0144ddc:  90 0b e0 0f  and  %o7, 0xf, %o0
a0144de0:  7f fe e2 90  call  0xa00fd820
a0144de4:  b0 10 20 00  clr  %i0
a0144de8:  98 0a 20 ff  and  %o0, 0xff, %o4
a0144dec:  80 a3 20 b1  cmp  %o4, 0xb1
a0144df0:  02 80 00 14  be  0xa0144e40
a0144df4:  01 00 00 00  nop
a0144df8:  9e 0e 20 01  and  %i0, 1, %o7
a0144dfc:  80 a0 00 0f  cmp  %g0, %o7
a0144e00:  98 40 3f ff  addx  %g0, -1, %o4
a0144e04:  94 0b 3f fe  and  %o4, -2, %o2
a0144e08:  10 80 00 92  b  0xa0145050
a0144e0c:  b0 02 a0 1e  add  %o2, 0x1e, %i0
a0144e10:  7f ff ab 84  call  0xa012fc20
a0144e14:  01 00 00 00  nop
a0144e18:  7f ff f4 d4  call  0xa0142168
a0144e1c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144e20:  7f ff d0 bd  call  0xa0139114
a0144e24:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144e28:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144e2c:  80 a2 e0 01  cmp  %o3, 1
a0144e30:  22 bf fe e8  be,a   0xa01449d0
a0144e34:  b0 10 20 01  mov  1, %i0
a0144e38:  10 bf fe e7  b  0xa01449d4
a0144e3c:  9e 0e 20 01  and  %i0, 1, %o7
a0144e40:  7f ff ab 78  call  0xa012fc20
a0144e44:  01 00 00 00  nop
a0144e48:  7f ff f4 c8  call  0xa0142168
a0144e4c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144e50:  7f ff d0 b1  call  0xa0139114
a0144e54:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144e58:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144e5c:  80 a2 e0 01  cmp  %o3, 1
a0144e60:  22 bf ff e6  be,a   0xa0144df8
a0144e64:  b0 10 20 01  mov  1, %i0
a0144e68:  10 bf ff e5  b  0xa0144dfc
a0144e6c:  9e 0e 20 01  and  %i0, 1, %o7
a0144e70:  7f ff ab 6c  call  0xa012fc20
a0144e74:  01 00 00 00  nop
a0144e78:  7f ff f4 bc  call  0xa0142168
a0144e7c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144e80:  7f ff d0 a5  call  0xa0139114
a0144e84:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144e88:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144e8c:  80 a2 e0 01  cmp  %o3, 1
a0144e90:  22 bf ff 30  be,a   0xa0144b50
a0144e94:  b0 10 20 01  mov  1, %i0
a0144e98:  10 bf ff 2f  b  0xa0144b54
a0144e9c:  92 0e 20 01  and  %i0, 1, %o1
a0144ea0:  7f ff ab 60  call  0xa012fc20
a0144ea4:  01 00 00 00  nop
a0144ea8:  7f ff f4 b0  call  0xa0142168
a0144eac:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144eb0:  7f ff d0 99  call  0xa0139114
a0144eb4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144eb8:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144ebc:  80 a2 e0 01  cmp  %o3, 1
a0144ec0:  22 bf ff b9  be,a   0xa0144da4
a0144ec4:  b0 10 20 01  mov  1, %i0
a0144ec8:  10 bf ff b8  b  0xa0144da8
a0144ecc:  92 0e 20 01  and  %i0, 1, %o1
a0144ed0:  7f ff ab 54  call  0xa012fc20
a0144ed4:  01 00 00 00  nop
a0144ed8:  7f ff f4 a4  call  0xa0142168
a0144edc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144ee0:  7f ff d0 8d  call  0xa0139114
a0144ee4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144ee8:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144eec:  80 a2 e0 01  cmp  %o3, 1
a0144ef0:  22 bf ff 2d  be,a   0xa0144ba4
a0144ef4:  b0 10 20 01  mov  1, %i0
a0144ef8:  10 bf ff 2c  b  0xa0144ba8
a0144efc:  9e 0e 20 01  and  %i0, 1, %o7
a0144f00:  7f ff ab 48  call  0xa012fc20
a0144f04:  01 00 00 00  nop
a0144f08:  7f ff f4 98  call  0xa0142168
a0144f0c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144f10:  7f ff d0 81  call  0xa0139114
a0144f14:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144f18:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144f1c:  80 a2 e0 01  cmp  %o3, 1
a0144f20:  22 bf ff 81  be,a   0xa0144d24
a0144f24:  b0 10 20 01  mov  1, %i0
a0144f28:  10 bf ff 80  b  0xa0144d28
a0144f2c:  82 0e 20 01  and  %i0, 1, %g1
a0144f30:  7f ff ab 3c  call  0xa012fc20
a0144f34:  01 00 00 00  nop
a0144f38:  7f ff f4 8c  call  0xa0142168
a0144f3c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144f40:  7f ff d0 75  call  0xa0139114
a0144f44:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144f48:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144f4c:  80 a2 e0 01  cmp  %o3, 1
a0144f50:  22 bf ff 2f  be,a   0xa0144c0c
a0144f54:  b0 10 20 01  mov  1, %i0
a0144f58:  10 bf ff 2e  b  0xa0144c10
a0144f5c:  92 0e 20 01  and  %i0, 1, %o1
a0144f60:  7f ff ab 30  call  0xa012fc20
a0144f64:  01 00 00 00  nop
a0144f68:  7f ff f4 80  call  0xa0142168
a0144f6c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144f70:  7f ff d0 69  call  0xa0139114
a0144f74:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144f78:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144f7c:  80 a2 e0 01  cmp  %o3, 1
a0144f80:  22 bf ff 35  be,a   0xa0144c54
a0144f84:  b0 10 20 01  mov  1, %i0
a0144f88:  10 bf ff 34  b  0xa0144c58
a0144f8c:  82 0e 20 01  and  %i0, 1, %g1
a0144f90:  7f ff ab 24  call  0xa012fc20
a0144f94:  01 00 00 00  nop
a0144f98:  7f ff f4 74  call  0xa0142168
a0144f9c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144fa0:  7f ff d0 5d  call  0xa0139114
a0144fa4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144fa8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144fac:  80 a2 20 01  cmp  %o0, 1
a0144fb0:  22 bf fe a9  be,a   0xa0144a54
a0144fb4:  b0 10 20 01  mov  1, %i0
a0144fb8:  10 bf fe a8  b  0xa0144a58
a0144fbc:  82 0e 20 01  and  %i0, 1, %g1
a0144fc0:  7f ff ab 18  call  0xa012fc20
a0144fc4:  01 00 00 00  nop
a0144fc8:  7f ff f4 68  call  0xa0142168
a0144fcc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144fd0:  7f ff d0 51  call  0xa0139114
a0144fd4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144fd8:  96 0a 20 ff  and  %o0, 0xff, %o3
a0144fdc:  80 a2 e0 01  cmp  %o3, 1
a0144fe0:  22 bf fe af  be,a   0xa0144a9c
a0144fe4:  b0 10 20 01  mov  1, %i0
a0144fe8:  10 bf fe ae  b  0xa0144aa0
a0144fec:  94 0e 20 01  and  %i0, 1, %o2
a0144ff0:  7f ff ab 0c  call  0xa012fc20
a0144ff4:  01 00 00 00  nop
a0144ff8:  7f ff f4 5c  call  0xa0142168
a0144ffc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0145000:  7f ff d0 45  call  0xa0139114
a0145004:  90 0a 20 ff  and  %o0, 0xff, %o0
a0145008:  96 0a 20 ff  and  %o0, 0xff, %o3
a014500c:  80 a2 e0 01  cmp  %o3, 1
a0145010:  22 bf fe be  be,a   0xa0144b08
a0145014:  b0 10 20 01  mov  1, %i0
a0145018:  10 bf fe bd  b  0xa0144b0c
a014501c:  9e 0e 20 01  and  %i0, 1, %o7
a0145020:  7f ff ab 00  call  0xa012fc20
a0145024:  01 00 00 00  nop
a0145028:  7f ff f4 50  call  0xa0142168
a014502c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0145030:  7f ff d0 39  call  0xa0139114
a0145034:  90 0a 20 ff  and  %o0, 0xff, %o0
a0145038:  96 0a 20 ff  and  %o0, 0xff, %o3
a014503c:  80 a2 e0 01  cmp  %o3, 1
a0145040:  22 bf ff 1f  be,a   0xa0144cbc
a0145044:  b0 10 20 01  mov  1, %i0
a0145048:  10 bf ff 1e  b  0xa0144cc0
a014504c:  82 0e 20 01  and  %i0, 1, %g1
a0145050:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0145054:  81 c7 e0 08  ret
a0145058:  81 e8 00 00  restore
