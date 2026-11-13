# leon2m FUN_a0115a44 0xa0115a44-0xa0115bd4 (400 bytes)
a0115a44:  83 2a 60 10  sll  %o1, 0x10, %g1
a0115a48:  83 30 60 10  srl  %g1, 0x10, %g1
a0115a4c:  80 a0 60 01  cmp  %g1, 1
a0115a50:  04 80 00 10  ble  0xa0115a90
a0115a54:  96 10 20 00  clr  %o3
a0115a58:  80 a0 60 03  cmp  %g1, 3
a0115a5c:  24 80 00 02  ble,a   0xa0115a64
a0115a60:  96 10 20 c9  mov  0xc9, %o3
a0115a64:  90 0a 20 ff  and  %o0, 0xff, %o0
a0115a68:  80 a2 20 01  cmp  %o0, 1
a0115a6c:  22 80 00 0e  be,a   0xa0115aa4
a0115a70:  91 2a 60 10  sll  %o1, 0x10, %o0
a0115a74:  80 a2 20 01  cmp  %o0, 1
a0115a78:  04 80 00 3c  ble  0xa0115b68
a0115a7c:  80 a2 20 02  cmp  %o0, 2
a0115a80:  12 80 00 53  bne  0xa0115bcc
a0115a84:  9b 2a 60 10  sll  %o1, 0x10, %o5
a0115a88:  10 80 00 2a  b  0xa0115b30
a0115a8c:  93 33 60 10  srl  %o5, 0x10, %o1
a0115a90:  90 0a 20 ff  and  %o0, 0xff, %o0
a0115a94:  80 a2 20 01  cmp  %o0, 1
a0115a98:  12 bf ff f8  bne  0xa0115a78
a0115a9c:  96 10 20 c8  mov  0xc8, %o3
a0115aa0:  91 2a 60 10  sll  %o1, 0x10, %o0
a0115aa4:  9b 32 20 10  srl  %o0, 0x10, %o5
a0115aa8:  80 a0 00 0d  cmp  %g0, %o5
a0115aac:  90 60 3f ff  subx  %g0, -1, %o0
a0115ab0:  92 1b 60 02  xor  %o5, 2, %o1
a0115ab4:  80 a0 00 09  cmp  %g0, %o1
a0115ab8:  19 33 c0 8c  sethi  %hi(0xcf023000), %o4
a0115abc:  9a 60 3f ff  subx  %g0, -1, %o5
a0115ac0:  82 13 23 f8  or  %o4, 0x3f8, %g1
a0115ac4:  c0 20 40 00  clr  [ %g1 ]
a0115ac8:  80 92 00 0d  orcc  %o0, %o5, %g0
a0115acc:  02 80 00 0d  be  0xa0115b00
a0115ad0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0115ad4:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0115ad8:  92 03 40 01  add  %o5, %g1, %o1
a0115adc:  91 2a 60 02  sll  %o1, 2, %o0
a0115ae0:  19 33 c0 00  sethi  %hi(0xcf000000), %o4
a0115ae4:  9a 12 00 0c  or  %o0, %o4, %o5
a0115ae8:  c2 03 40 00  ld  [ %o5 ], %g1
a0115aec:  82 08 60 f0  and  %g1, 0xf0, %g1
a0115af0:  98 0a a0 0f  and  %o2, 0xf, %o4
a0115af4:  90 10 40 0c  or  %g1, %o4, %o0
a0115af8:  d0 23 40 00  st  %o0, [ %o5 ]
a0115afc:  30 80 00 34  b,a   0xa0115bcc
a0115b00:  03 00 00 23  sethi  %hi(0x8c00), %g1
a0115b04:  92 03 40 01  add  %o5, %g1, %o1
a0115b08:  99 2a 60 02  sll  %o1, 2, %o4
a0115b0c:  03 33 c0 00  sethi  %hi(0xcf000000), %g1
a0115b10:  9a 13 00 01  or  %o4, %g1, %o5
a0115b14:  96 0a a0 ff  and  %o2, 0xff, %o3
a0115b18:  d4 03 40 00  ld  [ %o5 ], %o2
a0115b1c:  82 0a a0 0f  and  %o2, 0xf, %g1
a0115b20:  99 2a e0 04  sll  %o3, 4, %o4
a0115b24:  90 10 40 0c  or  %g1, %o4, %o0
a0115b28:  d0 23 40 00  st  %o0, [ %o5 ]
a0115b2c:  30 80 00 28  b,a   0xa0115bcc
a0115b30:  80 a0 00 09  cmp  %g0, %o1
a0115b34:  9a 60 3f ff  subx  %g0, -1, %o5
a0115b38:  90 1a 60 02  xor  %o1, 2, %o0
a0115b3c:  80 a0 00 08  cmp  %g0, %o0
a0115b40:  19 33 c0 8b  sethi  %hi(0xcf022c00), %o4
a0115b44:  92 60 3f ff  subx  %g0, -1, %o1
a0115b48:  82 13 23 f8  or  %o4, 0x3f8, %g1
a0115b4c:  c0 20 40 00  clr  [ %g1 ]
a0115b50:  80 93 40 09  orcc  %o5, %o1, %g0
a0115b54:  02 80 00 18  be  0xa0115bb4
a0115b58:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0115b5c:  17 00 00 22  sethi  %hi(0x8800), %o3
a0115b60:  10 bf ff de  b  0xa0115ad8
a0115b64:  82 12 e3 00  or  %o3, 0x300, %g1	! 0x8b00
a0115b68:  80 a2 20 00  cmp  %o0, 0
a0115b6c:  12 80 00 18  bne  0xa0115bcc
a0115b70:  99 2a 60 10  sll  %o1, 0x10, %o4
a0115b74:  9b 33 20 10  srl  %o4, 0x10, %o5
a0115b78:  80 a0 00 0d  cmp  %g0, %o5
a0115b7c:  98 60 3f ff  subx  %g0, -1, %o4
a0115b80:  82 1b 60 02  xor  %o5, 2, %g1
a0115b84:  80 a0 00 01  cmp  %g0, %g1
a0115b88:  13 33 c0 8a  sethi  %hi(0xcf022800), %o1
a0115b8c:  9a 60 3f ff  subx  %g0, -1, %o5
a0115b90:  90 12 63 f8  or  %o1, 0x3f8, %o0
a0115b94:  c0 22 00 00  clr  [ %o0 ]
a0115b98:  80 93 00 0d  orcc  %o4, %o5, %g0
a0115b9c:  02 80 00 09  be  0xa0115bc0
a0115ba0:  11 00 00 22  sethi  %hi(0x8800), %o0
a0115ba4:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0115ba8:  17 00 00 22  sethi  %hi(0x8800), %o3
a0115bac:  10 bf ff cb  b  0xa0115ad8
a0115bb0:  82 12 e2 00  or  %o3, 0x200, %g1	! 0x8a00
a0115bb4:  17 00 00 22  sethi  %hi(0x8800), %o3
a0115bb8:  10 bf ff d3  b  0xa0115b04
a0115bbc:  82 12 e3 00  or  %o3, 0x300, %g1	! 0x8b00
a0115bc0:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0115bc4:  10 bf ff d0  b  0xa0115b04
a0115bc8:  82 12 22 00  or  %o0, 0x200, %g1
a0115bcc:  81 c3 e0 08  retl
a0115bd0:  01 00 00 00  nop
