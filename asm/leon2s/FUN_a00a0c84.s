# leon2s FUN_a00a0c84 0xa00a0c84-0xa00a1098 (1044 bytes)
a00a0c84:  9d e3 bf 98  save  %sp, -104, %sp
a00a0c88:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00a0c8c:  90 10 00 11  mov  %l1, %o0
a00a0c90:  7f ff fe 3e  call  0xa00a0588
a00a0c94:  92 10 20 08  mov  8, %o1
a00a0c98:  80 8a 20 ff  btst  0xff, %o0
a00a0c9c:  02 80 00 18  be  0xa00a0cfc
a00a0ca0:  a8 10 20 00  clr  %l4
a00a0ca4:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a00a0ca8:  98 13 20 90  or  %o4, 0x90, %o4	! 0xcf03c890
a00a0cac:  9a 10 20 04  mov  4, %o5
a00a0cb0:  c2 03 00 00  ld  [ %o4 ], %g1
a00a0cb4:  9b 2b 40 11  sll  %o5, %l1, %o5
a00a0cb8:  82 10 40 0d  or  %g1, %o5, %g1
a00a0cbc:  c2 23 00 00  st  %g1, [ %o4 ]
a00a0cc0:  40 00 43 22  call  0xa00b1948
a00a0cc4:  01 00 00 00  nop
a00a0cc8:  7f ff b2 ce  call  0xa008d800
a00a0ccc:  01 00 00 00  nop
a00a0cd0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a0cd4:  80 a2 20 82  cmp  %o0, 0x82
a00a0cd8:  18 80 00 05  bgu  0xa00a0cec
a00a0cdc:  90 10 00 11  mov  %l1, %o0
a00a0ce0:  7f ff fe b6  call  0xa00a07b8
a00a0ce4:  92 10 20 08  mov  8, %o1
a00a0ce8:  90 10 00 11  mov  %l1, %o0
a00a0cec:  7f ff ff 89  call  0xa00a0b10
a00a0cf0:  92 10 20 00  clr  %o1
a00a0cf4:  7f ff f7 2c  call  0xa009e9a4
a00a0cf8:  90 10 00 11  mov  %l1, %o0
a00a0cfc:  90 10 00 11  mov  %l1, %o0
a00a0d00:  7f ff fe 22  call  0xa00a0588
a00a0d04:  92 10 20 1c  mov  0x1c, %o1
a00a0d08:  80 8a 20 ff  btst  0xff, %o0
a00a0d0c:  22 80 00 1c  be,a   0xa00a0d7c
a00a0d10:  90 10 00 11  mov  %l1, %o0
a00a0d14:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00a0d18:  82 5c 61 90  smul  %l1, 0x190, %g1
a00a0d1c:  9a 13 63 e0  or  %o5, 0x3e0, %o5
a00a0d20:  82 00 40 0d  add  %g1, %o5, %g1
a00a0d24:  c2 08 60 18  ldub  [ %g1 + 0x18 ], %g1
a00a0d28:  80 a0 60 00  cmp  %g1, 0
a00a0d2c:  22 80 00 11  be,a   0xa00a0d70
a00a0d30:  90 10 00 11  mov  %l1, %o0
a00a0d34:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a00a0d38:  98 13 20 90  or  %o4, 0x90, %o4	! 0xcf03c890
a00a0d3c:  9a 10 20 04  mov  4, %o5
a00a0d40:  c2 03 00 00  ld  [ %o4 ], %g1
a00a0d44:  9b 2b 40 11  sll  %o5, %l1, %o5
a00a0d48:  82 10 40 0d  or  %g1, %o5, %g1
a00a0d4c:  c2 23 00 00  st  %g1, [ %o4 ]
a00a0d50:  40 00 42 fe  call  0xa00b1948
a00a0d54:  01 00 00 00  nop
a00a0d58:  90 10 00 11  mov  %l1, %o0
a00a0d5c:  7f ff ff 6d  call  0xa00a0b10
a00a0d60:  92 10 20 00  clr  %o1
a00a0d64:  7f ff f7 10  call  0xa009e9a4
a00a0d68:  90 10 00 11  mov  %l1, %o0
a00a0d6c:  90 10 00 11  mov  %l1, %o0
a00a0d70:  7f ff fe 92  call  0xa00a07b8
a00a0d74:  92 10 20 1c  mov  0x1c, %o1
a00a0d78:  90 10 00 11  mov  %l1, %o0
a00a0d7c:  7f ff fe 03  call  0xa00a0588
a00a0d80:  92 10 20 0e  mov  0xe, %o1
a00a0d84:  80 8a 20 ff  btst  0xff, %o0
a00a0d88:  02 80 00 7a  be  0xa00a0f70
a00a0d8c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a0d90:  80 a4 60 00  cmp  %l1, 0
a00a0d94:  02 80 00 05  be  0xa00a0da8
a00a0d98:  90 10 20 02  mov  2, %o0
a00a0d9c:  80 a4 60 01  cmp  %l1, 1
a00a0da0:  22 80 00 02  be,a   0xa00a0da8
a00a0da4:  90 10 20 03  mov  3, %o0
a00a0da8:  27 2a 01 f5  sethi  %hi(0xa807d400), %l3
a00a0dac:  82 14 e3 e0  or  %l3, 0x3e0, %g1	! 0xa807d7e0
a00a0db0:  9a 5c 61 90  smul  %l1, 0x190, %o5
a00a0db4:  a4 03 40 01  add  %o5, %g1, %l2
a00a0db8:  c2 0c a0 01  ldub  [ %l2 + 1 ], %g1
a00a0dbc:  80 a0 60 01  cmp  %g1, 1
a00a0dc0:  12 80 00 30  bne  0xa00a0e80
a00a0dc4:  01 00 00 00  nop
a00a0dc8:  7f ff d5 98  call  0xa0096428
a00a0dcc:  90 10 00 11  mov  %l1, %o0
a00a0dd0:  80 8a 20 ff  btst  0xff, %o0
a00a0dd4:  02 80 00 4a  be  0xa00a0efc
a00a0dd8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a0ddc:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a0de0:  9a 5c 60 34  smul  %l1, 0x34, %o5
a00a0de4:  82 10 63 00  or  %g1, 0x300, %g1
a00a0de8:  a0 03 40 01  add  %o5, %g1, %l0
a00a0dec:  d8 04 20 04  ld  [ %l0 + 4 ], %o4
a00a0df0:  da 04 a0 0c  ld  [ %l2 + 0xc ], %o5
a00a0df4:  c2 03 20 40  ld  [ %o4 + 0x40 ], %g1
a00a0df8:  80 a3 40 01  cmp  %o5, %g1
a00a0dfc:  02 80 00 12  be  0xa00a0e44
a00a0e00:  82 14 e3 e0  or  %l3, 0x3e0, %g1
a00a0e04:  da 03 20 44  ld  [ %o4 + 0x44 ], %o5
a00a0e08:  c2 04 a0 10  ld  [ %l2 + 0x10 ], %g1
a00a0e0c:  82 08 60 e0  and  %g1, 0xe0, %g1
a00a0e10:  9a 0b 60 e0  and  %o5, 0xe0, %o5
a00a0e14:  80 a0 40 0d  cmp  %g1, %o5
a00a0e18:  22 80 00 08  be,a   0xa00a0e38
a00a0e1c:  c2 04 20 04  ld  [ %l0 + 4 ], %g1
a00a0e20:  7f ff d5 38  call  0xa0096300
a00a0e24:  90 10 00 11  mov  %l1, %o0
a00a0e28:  c2 04 20 04  ld  [ %l0 + 4 ], %g1
a00a0e2c:  c2 00 60 44  ld  [ %g1 + 0x44 ], %g1
a00a0e30:  c2 24 a0 10  st  %g1, [ %l2 + 0x10 ]
a00a0e34:  c2 04 20 04  ld  [ %l0 + 4 ], %g1
a00a0e38:  c2 00 60 40  ld  [ %g1 + 0x40 ], %g1
a00a0e3c:  c2 24 a0 0c  st  %g1, [ %l2 + 0xc ]
a00a0e40:  82 14 e3 e0  or  %l3, 0x3e0, %g1
a00a0e44:  a0 5c 61 90  smul  %l1, 0x190, %l0
a00a0e48:  a0 04 00 01  add  %l0, %g1, %l0
a00a0e4c:  82 10 20 01  mov  1, %g1
a00a0e50:  c2 2c 20 08  stb  %g1, [ %l0 + 8 ]
a00a0e54:  90 10 00 11  mov  %l1, %o0
a00a0e58:  7f ff fe 58  call  0xa00a07b8
a00a0e5c:  92 10 20 10  mov  0x10, %o1
a00a0e60:  90 10 00 11  mov  %l1, %o0
a00a0e64:  92 10 20 10  mov  0x10, %o1
a00a0e68:  7f ff ff 4c  call  0xa00a0b98
a00a0e6c:  94 10 20 00  clr  %o2
a00a0e70:  40 00 44 7d  call  0xa00b2064
a00a0e74:  01 00 00 00  nop
a00a0e78:  10 80 00 20  b  0xa00a0ef8
a00a0e7c:  d0 24 21 8c  st  %o0, [ %l0 + 0x18c ]
a00a0e80:  7f ff 50 bf  call  0xa007517c
a00a0e84:  90 0a 20 03  and  %o0, 3, %o0
a00a0e88:  80 8a 20 ff  btst  0xff, %o0
a00a0e8c:  02 80 00 1c  be  0xa00a0efc
a00a0e90:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a0e94:  7f ff ba bf  call  0xa008f990
a00a0e98:  d0 04 a1 8c  ld  [ %l2 + 0x18c ], %o0
a00a0e9c:  80 8a 20 ff  btst  0xff, %o0
a00a0ea0:  02 80 00 17  be  0xa00a0efc
a00a0ea4:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a0ea8:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a00a0eac:  82 5c 60 34  smul  %l1, 0x34, %g1
a00a0eb0:  9a 13 63 00  or  %o5, 0x300, %o5
a00a0eb4:  a0 00 40 0d  add  %g1, %o5, %l0
a00a0eb8:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a00a0ebc:  92 02 60 34  add  %o1, 0x34, %o1
a00a0ec0:  40 00 19 52  call  0xa00a7408
a00a0ec4:  90 10 20 00  clr  %o0
a00a0ec8:  80 a2 20 00  cmp  %o0, 0
a00a0ecc:  02 80 00 0c  be  0xa00a0efc
a00a0ed0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a0ed4:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a00a0ed8:  92 02 60 34  add  %o1, 0x34, %o1
a00a0edc:  40 00 19 4b  call  0xa00a7408
a00a0ee0:  90 10 20 01  mov  1, %o0
a00a0ee4:  80 a2 20 00  cmp  %o0, 0
a00a0ee8:  02 80 00 05  be  0xa00a0efc
a00a0eec:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a0ef0:  82 10 20 01  mov  1, %g1
a00a0ef4:  c2 2c a1 8a  stb  %g1, [ %l2 + 0x18a ]
a00a0ef8:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a0efc:  92 10 61 84  or  %g1, 0x184, %o1	! 0xa8079184
a00a0f00:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a0f04:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a0f08:  94 10 61 80  or  %g1, 0x180, %o2	! 0xa8079180
a00a0f0c:  97 2a 20 02  sll  %o0, 2, %o3
a00a0f10:  c2 0a 80 08  ldub  [ %o2 + %o0 ], %g1
a00a0f14:  da 02 40 0b  ld  [ %o1 + %o3 ], %o5
a00a0f18:  80 a3 40 01  cmp  %o5, %g1
a00a0f1c:  12 80 00 0f  bne  0xa00a0f58
a00a0f20:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a0f24:  80 a3 60 00  cmp  %o5, 0
a00a0f28:  02 80 00 0f  be  0xa00a0f64
a00a0f2c:  98 10 61 78  or  %g1, 0x178, %o4
a00a0f30:  c2 0b 00 08  ldub  [ %o4 + %o0 ], %g1
a00a0f34:  82 00 60 01  inc  %g1
a00a0f38:  9a 08 60 ff  and  %g1, 0xff, %o5
a00a0f3c:  80 a3 60 14  cmp  %o5, 0x14
a00a0f40:  08 80 00 09  bleu  0xa00a0f64
a00a0f44:  c2 2b 00 08  stb  %g1, [ %o4 + %o0 ]
a00a0f48:  c0 22 40 0b  clr  [ %o1 + %o3 ]
a00a0f4c:  c0 2b 00 08  clrb  [ %o4 + %o0 ]
a00a0f50:  10 80 00 05  b  0xa00a0f64
a00a0f54:  c0 2a 80 08  clrb  [ %o2 + %o0 ]
a00a0f58:  82 10 61 78  or  %g1, 0x178, %g1
a00a0f5c:  da 2a 80 08  stb  %o5, [ %o2 + %o0 ]
a00a0f60:  c0 28 40 08  clrb  [ %g1 + %o0 ]
a00a0f64:  7f ff fe 15  call  0xa00a07b8
a00a0f68:  92 10 20 0e  mov  0xe, %o1
a00a0f6c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a0f70:  90 10 00 10  mov  %l0, %o0
a00a0f74:  7f ff fd 85  call  0xa00a0588
a00a0f78:  92 10 20 16  mov  0x16, %o1
a00a0f7c:  80 8a 20 ff  btst  0xff, %o0
a00a0f80:  02 80 00 0a  be  0xa00a0fa8
a00a0f84:  90 10 00 10  mov  %l0, %o0
a00a0f88:  92 10 20 16  mov  0x16, %o1
a00a0f8c:  7f ff fe 69  call  0xa00a0930
a00a0f90:  94 10 20 00  clr  %o2
a00a0f94:  90 10 00 10  mov  %l0, %o0
a00a0f98:  a8 10 20 01  mov  1, %l4
a00a0f9c:  7f ff fe 07  call  0xa00a07b8
a00a0fa0:  92 10 20 16  mov  0x16, %o1
a00a0fa4:  90 10 00 10  mov  %l0, %o0
a00a0fa8:  7f ff fd 78  call  0xa00a0588
a00a0fac:  92 10 20 0b  mov  0xb, %o1
a00a0fb0:  80 8a 20 ff  btst  0xff, %o0
a00a0fb4:  02 80 00 17  be  0xa00a1010
a00a0fb8:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a00a0fbc:  98 13 20 90  or  %o4, 0x90, %o4	! 0xcf03c890
a00a0fc0:  9a 10 20 04  mov  4, %o5
a00a0fc4:  c2 03 00 00  ld  [ %o4 ], %g1
a00a0fc8:  9b 2b 40 10  sll  %o5, %l0, %o5
a00a0fcc:  82 10 40 0d  or  %g1, %o5, %g1
a00a0fd0:  c2 23 00 00  st  %g1, [ %o4 ]
a00a0fd4:  40 00 42 5d  call  0xa00b1948
a00a0fd8:  01 00 00 00  nop
a00a0fdc:  7f ff b2 09  call  0xa008d800
a00a0fe0:  01 00 00 00  nop
a00a0fe4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a0fe8:  80 a2 20 82  cmp  %o0, 0x82
a00a0fec:  18 80 00 05  bgu  0xa00a1000
a00a0ff0:  90 10 00 10  mov  %l0, %o0
a00a0ff4:  7f ff fd f1  call  0xa00a07b8
a00a0ff8:  92 10 20 0b  mov  0xb, %o1
a00a0ffc:  90 10 00 10  mov  %l0, %o0
a00a1000:  7f ff fe c4  call  0xa00a0b10
a00a1004:  92 10 20 00  clr  %o1
a00a1008:  7f ff f6 67  call  0xa009e9a4
a00a100c:  90 10 00 10  mov  %l0, %o0
a00a1010:  7f ff b1 fc  call  0xa008d800
a00a1014:  01 00 00 00  nop
a00a1018:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a101c:  80 a2 20 82  cmp  %o0, 0x82
a00a1020:  08 80 00 17  bleu  0xa00a107c
a00a1024:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00a1028:  90 10 00 10  mov  %l0, %o0
a00a102c:  7f ff fd 57  call  0xa00a0588
a00a1030:  92 10 20 0c  mov  0xc, %o1
a00a1034:  80 8a 20 ff  btst  0xff, %o0
a00a1038:  02 80 00 11  be  0xa00a107c
a00a103c:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00a1040:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a00a1044:  98 13 20 90  or  %o4, 0x90, %o4	! 0xcf03c890
a00a1048:  9a 10 20 04  mov  4, %o5
a00a104c:  c2 03 00 00  ld  [ %o4 ], %g1
a00a1050:  9b 2b 40 10  sll  %o5, %l0, %o5
a00a1054:  82 10 40 0d  or  %g1, %o5, %g1
a00a1058:  c2 23 00 00  st  %g1, [ %o4 ]
a00a105c:  40 00 42 3b  call  0xa00b1948
a00a1060:  01 00 00 00  nop
a00a1064:  90 10 00 10  mov  %l0, %o0
a00a1068:  7f ff fe aa  call  0xa00a0b10
a00a106c:  92 10 20 00  clr  %o1
a00a1070:  7f ff f6 4d  call  0xa009e9a4
a00a1074:  90 10 00 10  mov  %l0, %o0
a00a1078:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00a107c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a1080:  9a 5b 61 90  smul  %o5, 0x190, %o5
a00a1084:  82 10 63 e0  or  %g1, 0x3e0, %g1
a00a1088:  9a 03 40 01  add  %o5, %g1, %o5
a00a108c:  e8 2b 60 07  stb  %l4, [ %o5 + 7 ]
a00a1090:  81 c7 e0 08  ret
a00a1094:  91 e8 20 00  restore  %g0, 0, %o0
