# leon2m FUN_a0127c78 0xa0127c78-0xa0129598 (52 bytes)
a0127c78:  9d e3 bf 90  save  %sp, -112, %sp
a0127c7c:  35 2a 00 b6  sethi  %hi(0xa802d800), %i2
a0127c80:  c2 0e a0 96  ldub  [ %i2 + 0x96 ], %g1	! 0xa802d896
a0127c84:  80 a0 60 04  cmp  %g1, 4
a0127c88:  18 80 06 42  bgu  0xa0129590
a0127c8c:  11 00 03 18  sethi  %hi(0xc6000), %o0
a0127c90:  83 28 60 02  sll  %g1, 2, %g1
a0127c94:  9a 12 23 4c  or  %o0, 0x34c, %o5
a0127c98:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0127c9c:  81 c3 00 00  jmp  %o4
a0127ca0:  01 00 00 00  nop
a0127ca4:  7f fe dd 33  call  0xa00df170
a0127ca8:  90 13 22 c0  or  %o4, 0x2c0, %o0
a0127cac:  90 10 20 0c  mov  0xc, %o0
a0127cb0:  40 00 77 eb  call  0xa0145c5c
a0127cb4:  92 10 20 00  clr  %o1
a0127cb8:  90 10 20 0a  mov  0xa, %o0
a0127cbc:  40 00 77 e8  call  0xa0145c5c
a0127cc0:  92 10 20 00  clr  %o1
a0127cc4:  90 10 20 0d  mov  0xd, %o0
a0127cc8:  40 00 77 e5  call  0xa0145c5c
a0127ccc:  92 10 20 00  clr  %o1
a0127cd0:  92 10 20 00  clr  %o1
a0127cd4:  40 00 77 e2  call  0xa0145c5c
a0127cd8:  90 10 20 0b  mov  0xb, %o0
a0127cdc:  40 00 77 87  call  0xa0145af8
a0127ce0:  90 10 20 0e  mov  0xe, %o0
a0127ce4:  b2 02 20 01  add  %o0, 1, %i1
a0127ce8:  ab 2e 60 10  sll  %i1, 0x10, %l5
a0127cec:  93 35 60 10  srl  %l5, 0x10, %o1
a0127cf0:  40 00 77 db  call  0xa0145c5c
a0127cf4:  90 10 20 0e  mov  0xe, %o0
a0127cf8:  40 00 75 9a  call  0xa0145360
a0127cfc:  90 10 20 01  mov  1, %o0
a0127d00:  7f ff f3 90  call  0xa0124b40
a0127d04:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a0127d08:  7f ff f3 58  call  0xa0124a68
a0127d0c:  01 00 00 00  nop
a0127d10:  90 10 20 00  clr  %o0	! 0x0
a0127d14:  40 00 75 06  call  0xa014512c
a0127d18:  92 10 20 01  mov  1, %o1
a0127d1c:  92 14 e2 90  or  %l3, 0x290, %o1
a0127d20:  d0 0a 61 e5  ldub  [ %o1 + 0x1e5 ], %o0
a0127d24:  80 a2 20 01  cmp  %o0, 1
a0127d28:  c0 2a 61 e7  clrb  [ %o1 + 0x1e7 ]
a0127d2c:  02 80 04 ec  be  0xa01290dc
a0127d30:  c0 2a 61 e3  clrb  [ %o1 + 0x1e3 ]
a0127d34:  94 10 20 00  clr  %o2
a0127d38:  96 10 21 fc  mov  0x1fc, %o3
a0127d3c:  40 00 8c 65  call  0xa014aed0
a0127d40:  90 10 20 30  mov  0x30, %o0
a0127d44:  40 00 6f b4  call  0xa0143c14
a0127d48:  90 10 20 00  clr  %o0
a0127d4c:  a4 0a 20 ff  and  %o0, 0xff, %l2
a0127d50:  80 a4 a0 0a  cmp  %l2, 0xa
a0127d54:  02 80 04 d6  be  0xa01290ac
a0127d58:  90 10 20 01  mov  1, %o0
a0127d5c:  40 00 74 f4  call  0xa014512c
a0127d60:  92 10 20 01  mov  1, %o1
a0127d64:  a0 16 a0 96  or  %i2, 0x96, %l0
a0127d68:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a0127d6c:  10 80 06 09  b  0xa0129590
a0127d70:  c0 2e a0 96  clrb  [ %i2 + 0x96 ]
a0127d74:  a0 16 a0 96  or  %i2, 0x96, %l0
a0127d78:  c2 0c 20 01  ldub  [ %l0 + 1 ], %g1
a0127d7c:  80 a0 60 01  cmp  %g1, 1
a0127d80:  02 80 03 39  be  0xa0128a64
a0127d84:  2b 00 06 92  sethi  %hi(0x1a4800), %l5
a0127d88:  04 80 03 2f  ble  0xa0128a44
a0127d8c:  80 a0 60 02  cmp  %g1, 2
a0127d90:  12 80 06 00  bne  0xa0129590
a0127d94:  01 00 00 00  nop
a0127d98:  67 fd 95 ff  call  0x4008d594
a0127d9c:  d0 14 20 04  lduh  [ %l0 + 4 ], %o0
a0127da0:  99 2a 20 10  sll  %o0, 0x10, %o4
a0127da4:  b3 33 20 10  srl  %o4, 0x10, %i1
a0127da8:  80 a6 60 0a  cmp  %i1, 0xa
a0127dac:  08 80 05 f9  bleu  0xa0129590
a0127db0:  01 00 00 00  nop
a0127db4:  67 fd 95 f5  call  0x4008d588
a0127db8:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a0127dbc:  e6 0c 20 0f  ldub  [ %l0 + 0xf ], %l3
a0127dc0:  31 2a 00 b6  sethi  %hi(0xa802d800), %i0
a0127dc4:  94 10 20 01  mov  1, %o2
a0127dc8:  d0 34 20 04  sth  %o0, [ %l0 + 4 ]
a0127dcc:  c0 2e 20 96  clrb  [ %i0 + 0x96 ]
a0127dd0:  80 a4 e0 01  cmp  %l3, 1
a0127dd4:  02 80 05 00  be  0xa01291d4
a0127dd8:  d4 2c 20 0c  stb  %o2, [ %l0 + 0xc ]
a0127ddc:  a0 16 a0 96  or  %i2, 0x96, %l0
a0127de0:  f4 0c 20 0f  ldub  [ %l0 + 0xf ], %i2
a0127de4:  80 a6 a0 02  cmp  %i2, 2
a0127de8:  12 80 05 ea  bne  0xa0129590
a0127dec:  13 00 06 92  sethi  %hi(0x1a4800), %o1
a0127df0:  90 12 63 20  or  %o1, 0x320, %o0	! 0x1a4b20
a0127df4:  7f fe dc df  call  0xa00df170
a0127df8:  b0 10 20 01  mov  1, %i0
a0127dfc:  7f fd 68 2b  call  0xa0081ea8
a0127e00:  81 e8 00 00  restore
a0127e04:  94 16 a0 96  or  %i2, 0x96, %o2
a0127e08:  d2 0a a0 0a  ldub  [ %o2 + 0xa ], %o1
a0127e0c:  80 a2 60 01  cmp  %o1, 1
a0127e10:  02 80 00 27  be  0xa0127eac
a0127e14:  82 10 20 02  mov  2, %g1
a0127e18:  40 00 77 38  call  0xa0145af8
a0127e1c:  90 10 20 10  mov  0x10, %o0
a0127e20:  97 2a 20 10  sll  %o0, 0x10, %o3
a0127e24:  80 a2 e0 00  cmp  %o3, 0
a0127e28:  02 80 00 72  be  0xa0127ff0
a0127e2c:  01 00 00 00  nop
a0127e30:  40 00 77 32  call  0xa0145af8
a0127e34:  90 10 20 0d  mov  0xd, %o0	! 0xd
a0127e38:  83 2a 20 10  sll  %o0, 0x10, %g1
a0127e3c:  99 30 60 10  srl  %g1, 0x10, %o4
a0127e40:  b3 2b 20 04  sll  %o4, 4, %i1
a0127e44:  b0 26 40 0c  sub  %i1, %o4, %i0
a0127e48:  40 00 77 2c  call  0xa0145af8
a0127e4c:  90 10 20 0b  mov  0xb, %o0
a0127e50:  ab 2a 20 10  sll  %o0, 0x10, %l5
a0127e54:  a7 2e 20 02  sll  %i0, 2, %l3
a0127e58:  a9 35 60 10  srl  %l5, 0x10, %l4
a0127e5c:  a4 04 c0 14  add  %l3, %l4, %l2
a0127e60:  80 a4 a0 13  cmp  %l2, 0x13
a0127e64:  14 80 00 03  bg  0xa0127e70
a0127e68:  82 10 20 01  mov  1, %g1
a0127e6c:  82 10 20 00  clr  %g1
a0127e70:  80 88 60 ff  btst  0xff, %g1
a0127e74:  12 80 00 0e  bne  0xa0127eac
a0127e78:  82 10 20 02  mov  2, %g1
a0127e7c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a0127e80:  98 12 a2 90  or  %o2, 0x290, %o4	! 0xa802d290
a0127e84:  13 00 00 15  sethi  %hi(0x5400), %o1
a0127e88:  da 13 21 f6  lduh  [ %o4 + 0x1f6 ], %o5
a0127e8c:  90 12 61 aa  or  %o1, 0x1aa, %o0
a0127e90:  80 a3 40 08  cmp  %o5, %o0
a0127e94:  22 80 00 5e  be,a   0xa012800c
a0127e98:  d6 0b 21 d5  ldub  [ %o4 + 0x1d5 ], %o3
a0127e9c:  82 10 20 00  clr  %g1
a0127ea0:  80 88 60 ff  btst  0xff, %g1
a0127ea4:  12 80 02 55  bne  0xa01287f8
a0127ea8:  82 10 20 00  clr  %g1
a0127eac:  82 08 60 ff  and  %g1, 0xff, %g1
a0127eb0:  a0 08 60 ff  and  %g1, 0xff, %l0
a0127eb4:  80 a4 20 02  cmp  %l0, 2
a0127eb8:  02 80 02 92  be  0xa0128900
a0127ebc:  b2 16 a0 96  or  %i2, 0x96, %i1
a0127ec0:  a0 16 a0 96  or  %i2, 0x96, %l0
a0127ec4:  ea 14 20 0c  lduh  [ %l0 + 0xc ], %l5
a0127ec8:  80 a5 60 01  cmp  %l5, 1
a0127ecc:  12 80 05 b1  bne  0xa0129590
a0127ed0:  33 00 06 92  sethi  %hi(0x1a4800), %i1
a0127ed4:  7f fe dc a7  call  0xa00df170
a0127ed8:  90 16 63 38  or  %i1, 0x338, %o0	! 0x1a4b38
a0127edc:  b0 10 20 04  mov  4, %i0
a0127ee0:  f0 2e a0 96  stb  %i0, [ %i2 + 0x96 ]
a0127ee4:  10 80 05 ab  b  0xa0129590
a0127ee8:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a0127eec:  a0 16 a0 96  or  %i2, 0x96, %l0
a0127ef0:  67 fd 95 a9  call  0x4008d594
a0127ef4:  d0 14 20 02  lduh  [ %l0 + 2 ], %o0
a0127ef8:  83 2a 20 10  sll  %o0, 0x10, %g1
a0127efc:  99 30 60 10  srl  %g1, 0x10, %o4
a0127f00:  80 a3 23 e8  cmp  %o4, 0x3e8
a0127f04:  18 80 02 59  bgu  0xa0128868
a0127f08:  9e 16 a0 96  or  %i2, 0x96, %o7
a0127f0c:  c2 0b e0 01  ldub  [ %o7 + 1 ], %g1
a0127f10:  80 a0 60 07  cmp  %g1, 7
a0127f14:  18 80 05 9f  bgu  0xa0129590
a0127f18:  2b 00 03 18  sethi  %hi(0xc6000), %l5
a0127f1c:  a7 28 60 02  sll  %g1, 2, %l3
a0127f20:  a8 15 63 2c  or  %l5, 0x32c, %l4
a0127f24:  e4 05 00 13  ld  [ %l4 + %l3 ], %l2
a0127f28:  81 c4 80 00  jmp  %l2
a0127f2c:  01 00 00 00  nop
a0127f30:  a0 16 a0 96  or  %i2, 0x96, %l0
a0127f34:  67 fd 95 98  call  0x4008d594
a0127f38:  d0 14 20 02  lduh  [ %l0 + 2 ], %o0
a0127f3c:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0127f40:  97 33 e0 10  srl  %o7, 0x10, %o3
a0127f44:  80 a2 e3 e8  cmp  %o3, 0x3e8
a0127f48:  18 80 02 5b  bgu  0xa01288b4
a0127f4c:  01 00 00 00  nop
a0127f50:  a0 16 a0 96  or  %i2, 0x96, %l0
a0127f54:  c2 0c 20 01  ldub  [ %l0 + 1 ], %g1
a0127f58:  80 a0 60 04  cmp  %g1, 4
a0127f5c:  18 80 05 8d  bgu  0xa0129590
a0127f60:  1b 00 03 18  sethi  %hi(0xc6000), %o5
a0127f64:  b1 28 60 02  sll  %g1, 2, %i0
a0127f68:  92 13 63 18  or  %o5, 0x318, %o1
a0127f6c:  d8 02 40 18  ld  [ %o1 + %i0 ], %o4
a0127f70:  81 c3 00 00  jmp  %o4
a0127f74:  01 00 00 00  nop
a0127f78:  a0 16 a0 96  or  %i2, 0x96, %l0
a0127f7c:  f4 0c 20 01  ldub  [ %l0 + 1 ], %i2
a0127f80:  80 a6 a0 01  cmp  %i2, 1
a0127f84:  02 80 02 bf  be  0xa0128a80
a0127f88:  01 00 00 00  nop
a0127f8c:  04 80 02 99  ble  0xa01289f0
a0127f90:  80 a6 a0 02  cmp  %i2, 2
a0127f94:  02 80 02 d1  be  0xa0128ad8
a0127f98:  80 a6 a0 03  cmp  %i2, 3
a0127f9c:  12 80 05 7d  bne  0xa0129590
a0127fa0:  01 00 00 00  nop
a0127fa4:  67 fd 95 7c  call  0x4008d594
a0127fa8:  d0 14 20 04  lduh  [ %l0 + 4 ], %o0
a0127fac:  b1 2a 20 10  sll  %o0, 0x10, %i0
a0127fb0:  95 36 20 10  srl  %i0, 0x10, %o2
a0127fb4:  80 a2 a0 0f  cmp  %o2, 0xf
a0127fb8:  08 80 05 76  bleu  0xa0129590
a0127fbc:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a0127fc0:  de 0c 20 0f  ldub  [ %l0 + 0xf ], %o7
a0127fc4:  82 03 ff ff  add  %o7, -1, %g1
a0127fc8:  92 08 60 ff  and  %g1, 0xff, %o1
a0127fcc:  b4 10 20 01  mov  1, %i2
a0127fd0:  1b 00 06 92  sethi  %hi(0x1a4800), %o5
a0127fd4:  c0 2a e0 96  clrb  [ %o3 + 0x96 ]
a0127fd8:  f4 2c 20 10  stb  %i2, [ %l0 + 0x10 ]
a0127fdc:  90 13 63 58  or  %o5, 0x358, %o0
a0127fe0:  80 a2 60 01  cmp  %o1, 1
a0127fe4:  18 80 05 6b  bgu  0xa0129590
a0127fe8:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a0127fec:  30 bf ff 82  b,a   0xa0127df4
a0127ff0:  40 00 76 c2  call  0xa0145af8
a0127ff4:  90 10 20 0d  mov  0xd, %o0
a0127ff8:  a1 2a 20 10  sll  %o0, 0x10, %l0
a0127ffc:  9f 34 20 10  srl  %l0, 0x10, %o7
a0128000:  80 a3 e0 04  cmp  %o7, 4
a0128004:  10 bf ff 9b  b  0xa0127e70
a0128008:  82 60 3f ff  subx  %g0, -1, %g1
a012800c:  80 a2 e0 00  cmp  %o3, 0
a0128010:  02 bf ff a4  be  0xa0127ea0
a0128014:  82 10 20 00  clr  %g1
a0128018:  40 00 76 b8  call  0xa0145af8
a012801c:  90 10 20 11  mov  0x11, %o0
a0128020:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0128024:  91 33 e0 10  srl  %o7, 0x10, %o0
a0128028:  80 a2 20 01  cmp  %o0, 1
a012802c:  32 bf ff 9d  bne,a   0xa0127ea0
a0128030:  82 10 20 00  clr  %g1
a0128034:  a0 16 a0 96  or  %i2, 0x96, %l0
a0128038:  d0 2c 20 09  stb  %o0, [ %l0 + 9 ]
a012803c:  c0 2c 20 0f  clrb  [ %l0 + 0xf ]
a0128040:  10 bf ff 98  b  0xa0127ea0
a0128044:  82 10 20 01  mov  1, %g1
a0128048:  a0 16 a0 96  or  %i2, 0x96, %l0
a012804c:  67 fd 95 52  call  0x4008d594
a0128050:  d0 14 20 02  lduh  [ %l0 + 2 ], %o0
a0128054:  a5 2a 20 10  sll  %o0, 0x10, %l2
a0128058:  9b 34 a0 10  srl  %l2, 0x10, %o5
a012805c:  80 a3 61 f4  cmp  %o5, 0x1f4
a0128060:  08 80 05 4c  bleu  0xa0129590
a0128064:  01 00 00 00  nop
a0128068:  c2 0c 20 0f  ldub  [ %l0 + 0xf ], %g1
a012806c:  80 a0 60 00  cmp  %g1, 0
a0128070:  02 80 02 ef  be  0xa0128c2c
a0128074:  c0 2c 20 13  clrb  [ %l0 + 0x13 ]
a0128078:  80 a0 60 01  cmp  %g1, 1
a012807c:  02 80 04 1a  be  0xa01290e4
a0128080:  80 a0 60 02  cmp  %g1, 2
a0128084:  12 80 05 43  bne  0xa0129590
a0128088:  21 00 06 92  sethi  %hi(0x1a4800), %l0
a012808c:  7f fe dc 39  call  0xa00df170
a0128090:  90 14 23 70  or  %l0, 0x370, %o0	! 0x1a4b70
a0128094:  90 10 20 0d  mov  0xd, %o0
a0128098:  40 00 76 f1  call  0xa0145c5c
a012809c:  92 10 20 00  clr  %o1
a01280a0:  90 10 20 0b  mov  0xb, %o0
a01280a4:  40 00 76 ee  call  0xa0145c5c
a01280a8:  92 10 20 00  clr  %o1
a01280ac:  40 00 76 93  call  0xa0145af8
a01280b0:  90 10 20 11  mov  0x11, %o0
a01280b4:  a5 2a 20 10  sll  %o0, 0x10, %l2
a01280b8:  b1 34 a0 10  srl  %l2, 0x10, %i0
a01280bc:  80 a6 20 01  cmp  %i0, 1
a01280c0:  02 80 05 19  be  0xa0129524
a01280c4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a01280c8:  40 00 76 8c  call  0xa0145af8
a01280cc:  90 10 20 0f  mov  0xf, %o0
a01280d0:  a6 02 20 01  add  %o0, 1, %l3
a01280d4:  99 2c e0 10  sll  %l3, 0x10, %o4
a01280d8:  93 33 20 10  srl  %o4, 0x10, %o1
a01280dc:  40 00 76 e0  call  0xa0145c5c
a01280e0:  90 10 20 0f  mov  0xf, %o0
a01280e4:  92 10 20 00  clr  %o1
a01280e8:  40 00 76 dd  call  0xa0145c5c
a01280ec:  90 10 20 11  mov  0x11, %o0
a01280f0:  40 00 74 9c  call  0xa0145360
a01280f4:  90 10 20 01  mov  1, %o0
a01280f8:  92 14 22 90  or  %l0, 0x290, %o1
a01280fc:  d4 0a 61 e4  ldub  [ %o1 + 0x1e4 ], %o2
a0128100:  80 a2 a0 01  cmp  %o2, 1
a0128104:  c0 2a 61 e6  clrb  [ %o1 + 0x1e6 ]
a0128108:  02 80 05 05  be  0xa012951c
a012810c:  c0 2a 61 e2  clrb  [ %o1 + 0x1e2 ]
a0128110:  94 10 20 00  clr  %o2
a0128114:  96 10 21 fc  mov  0x1fc, %o3
a0128118:  40 00 8b 6e  call  0xa014aed0
a012811c:  90 10 20 30  mov  0x30, %o0
a0128120:  b0 16 a0 96  or  %i2, 0x96, %i0
a0128124:  92 10 20 01  mov  1, %o1
a0128128:  d2 2e 20 0c  stb  %o1, [ %i0 + 0xc ]
a012812c:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a0128130:  67 fd 95 16  call  0x4008d588
a0128134:  c0 2e a0 96  clrb  [ %i2 + 0x96 ]
a0128138:  d0 36 20 04  sth  %o0, [ %i0 + 4 ]
a012813c:  10 bf ff 30  b  0xa0127dfc
a0128140:  b0 10 20 01  mov  1, %i0
a0128144:  7f ff f1 fe  call  0xa012493c
a0128148:  01 00 00 00  nop
a012814c:  a4 0a 20 ff  and  %o0, 0xff, %l2
a0128150:  80 a4 a0 01  cmp  %l2, 1
a0128154:  02 80 00 06  be  0xa012816c
a0128158:  82 16 a0 96  or  %i2, 0x96, %g1
a012815c:  d4 10 60 06  lduh  [ %g1 + 6 ], %o2
a0128160:  80 a2 a1 72  cmp  %o2, 0x172
a0128164:  08 80 05 0b  bleu  0xa0129590
a0128168:  01 00 00 00  nop
a012816c:  b2 16 a0 96  or  %i2, 0x96, %i1
a0128170:  96 10 20 02  mov  2, %o3
a0128174:  67 fd 95 05  call  0x4008d588
a0128178:  d6 2e 60 01  stb  %o3, [ %i1 + 1 ]
a012817c:  10 80 05 05  b  0xa0129590
a0128180:  d0 36 60 02  sth  %o0, [ %i1 + 2 ]
a0128184:  a0 16 a0 96  or  %i2, 0x96, %l0
a0128188:  67 fd 95 03  call  0x4008d594
a012818c:  d0 14 20 02  lduh  [ %l0 + 2 ], %o0
a0128190:  a9 2a 20 10  sll  %o0, 0x10, %l4
a0128194:  b1 35 20 10  srl  %l4, 0x10, %i0
a0128198:  80 a6 21 f4  cmp  %i0, 0x1f4
a012819c:  08 80 04 fd  bleu  0xa0129590
a01281a0:  01 00 00 00  nop
a01281a4:  67 fd 94 f9  call  0x4008d588
a01281a8:  01 00 00 00  nop
a01281ac:  ea 0c 20 16  ldub  [ %l0 + 0x16 ], %l5
a01281b0:  82 05 60 01  add  %l5, 1, %g1
a01281b4:  9a 08 60 ff  and  %g1, 0xff, %o5
a01281b8:  80 a3 60 07  cmp  %o5, 7
a01281bc:  18 80 02 70  bgu  0xa0128b7c
a01281c0:  d0 34 20 02  sth  %o0, [ %l0 + 2 ]
a01281c4:  c2 2c 20 16  stb  %g1, [ %l0 + 0x16 ]
a01281c8:  b0 10 20 ff  mov  0xff, %i0
a01281cc:  80 8b 60 01  btst  1, %o5
a01281d0:  12 80 00 c1  bne  0xa01284d4
a01281d4:  b2 10 20 10  mov  0x10, %i1
a01281d8:  b4 10 20 00  clr  %i2
a01281dc:  7f fe c9 a1  call  0xa00da860
a01281e0:  81 e8 00 00  restore
a01281e4:  7f ff f1 d6  call  0xa012493c
a01281e8:  01 00 00 00  nop
a01281ec:  80 8a 20 ff  btst  0xff, %o0
a01281f0:  02 80 00 0a  be  0xa0128218
a01281f4:  90 10 20 00  clr  %o0
a01281f8:  a0 16 a0 96  or  %i2, 0x96, %l0
a01281fc:  67 fd 94 e6  call  0x4008d594
a0128200:  d0 14 20 02  lduh  [ %l0 + 2 ], %o0
a0128204:  91 2a 20 10  sll  %o0, 0x10, %o0
a0128208:  9f 32 20 10  srl  %o0, 0x10, %o7
a012820c:  80 a3 e3 e8  cmp  %o7, 0x3e8
a0128210:  08 80 04 e0  bleu  0xa0129590
a0128214:  90 10 20 00  clr  %o0
a0128218:  40 00 73 c5  call  0xa014512c
a012821c:  92 10 20 01  mov  1, %o1
a0128220:  7f ff f6 a3  call  0xa0125cac
a0128224:  01 00 00 00  nop
a0128228:  67 fd 94 d8  call  0x4008d588
a012822c:  01 00 00 00  nop
a0128230:  98 16 a0 96  or  %i2, 0x96, %o4
a0128234:  b4 10 20 03  mov  3, %i2
a0128238:  f4 2b 20 01  stb  %i2, [ %o4 + 1 ]
a012823c:  10 80 04 d5  b  0xa0129590
a0128240:  d0 33 20 02  sth  %o0, [ %o4 + 2 ]
a0128244:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a0128248:  98 13 e2 90  or  %o7, 0x290, %o4	! 0xa802d290
a012824c:  17 00 00 15  sethi  %hi(0x5400), %o3
a0128250:  d4 13 21 f6  lduh  [ %o4 + 0x1f6 ], %o2
a0128254:  82 12 e1 aa  or  %o3, 0x1aa, %g1
a0128258:  80 a2 80 01  cmp  %o2, %g1
a012825c:  22 80 01 77  be,a   0xa0128838
a0128260:  e8 0b 21 d5  ldub  [ %o4 + 0x1d5 ], %l4
a0128264:  9a 10 20 b4  mov  0xb4, %o5
a0128268:  b4 16 a0 96  or  %i2, 0x96, %i2
a012826c:  b2 0b 60 b5  and  %o5, 0xb5, %i1
a0128270:  d0 16 a0 06  lduh  [ %i2 + 6 ], %o0
a0128274:  80 a2 00 19  cmp  %o0, %i1
a0128278:  08 80 04 c6  bleu  0xa0129590
a012827c:  90 10 20 01  mov  1, %o0
a0128280:  40 00 73 ab  call  0xa014512c
a0128284:  92 10 20 01  mov  1, %o1
a0128288:  7f ff f1 90  call  0xa01248c8
a012828c:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a0128290:  80 8a 20 ff  btst  0xff, %o0
a0128294:  12 80 03 34  bne  0xa0128f64
a0128298:  a4 10 20 02  mov  2, %l2
a012829c:  c2 0c 20 88  ldub  [ %l0 + 0x88 ], %g1
a01282a0:  b2 14 20 88  or  %l0, 0x88, %i1
a01282a4:  9b 28 60 08  sll  %g1, 8, %o5
a01282a8:  d2 0e 60 01  ldub  [ %i1 + 1 ], %o1
a01282ac:  a6 12 40 0d  or  %o1, %o5, %l3
a01282b0:  29 00 06 91  sethi  %hi(0x1a4400), %l4
a01282b4:  92 10 00 13  mov  %l3, %o1
a01282b8:  7f fe db ae  call  0xa00df170
a01282bc:  90 15 21 90  or  %l4, 0x190, %o0
a01282c0:  40 00 b9 60  call  0xa0156840
a01282c4:  90 10 00 13  mov  %l3, %o0
a01282c8:  31 00 06 93  sethi  %hi(0x1a4c00), %i0
a01282cc:  e4 1e 22 a0  ldd  [ %i0 + 0x2a0 ], %l2	! 0x1a4ea0
a01282d0:  94 10 00 12  mov  %l2, %o2
a01282d4:  40 00 b7 a1  call  0xa0156158
a01282d8:  96 10 00 13  mov  %l3, %o3
a01282dc:  40 00 b3 a1  call  0xa0155160
a01282e0:  2b 00 06 91  sethi  %hi(0x1a4400), %l5
a01282e4:  99 2a 20 10  sll  %o0, 0x10, %o4
a01282e8:  a1 33 20 10  srl  %o4, 0x10, %l0
a01282ec:  90 15 61 b0  or  %l5, 0x1b0, %o0
a01282f0:  7f fe db a0  call  0xa00df170
a01282f4:  92 10 00 10  mov  %l0, %o1
a01282f8:  80 a4 20 2d  cmp  %l0, 0x2d
a01282fc:  08 80 02 29  bleu  0xa0128ba0
a0128300:  96 10 20 04  mov  4, %o3
a0128304:  94 10 20 02  mov  2, %o2
a0128308:  d6 2e a0 01  stb  %o3, [ %i2 + 1 ]
a012830c:  7f ff f1 6f  call  0xa01248c8
a0128310:  d4 2e a0 0f  stb  %o2, [ %i2 + 0xf ]
a0128314:  80 8a 20 ff  btst  0xff, %o0
a0128318:  32 80 03 e6  bne,a   0xa01292b0
a012831c:  b4 10 20 02  mov  2, %i2
a0128320:  31 2a 00 b6  sethi  %hi(0xa802d800), %i0
a0128324:  d8 0e 20 88  ldub  [ %i0 + 0x88 ], %o4	! 0xa802d888
a0128328:  a1 2b 20 08  sll  %o4, 8, %l0
a012832c:  d0 0e 60 01  ldub  [ %i1 + 1 ], %o0
a0128330:  b2 12 00 10  or  %o0, %l0, %i1
a0128334:  92 10 00 19  mov  %i1, %o1
a0128338:  7f fe db 8e  call  0xa00df170
a012833c:  90 15 21 90  or  %l4, 0x190, %o0
a0128340:  40 00 b9 40  call  0xa0156840
a0128344:  90 10 00 19  mov  %i1, %o0
a0128348:  94 10 00 12  mov  %l2, %o2
a012834c:  40 00 b7 83  call  0xa0156158
a0128350:  96 10 00 13  mov  %l3, %o3
a0128354:  40 00 b3 83  call  0xa0155160
a0128358:  01 00 00 00  nop
a012835c:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0128360:  b3 33 e0 10  srl  %o7, 0x10, %i1
a0128364:  90 15 61 b0  or  %l5, 0x1b0, %o0
a0128368:  92 10 00 19  mov  %i1, %o1
a012836c:  7f fe db 81  call  0xa00df170
a0128370:  29 00 06 92  sethi  %hi(0x1a4800), %l4
a0128374:  7f fe db 7f  call  0xa00df170
a0128378:  91 ed 23 98  restore  %l4, 0x398, %o0
a012837c:  a0 16 a0 96  or  %i2, 0x96, %l0
a0128380:  c2 0c 20 0f  ldub  [ %l0 + 0xf ], %g1
a0128384:  80 a0 60 00  cmp  %g1, 0
a0128388:  02 bf fe 47  be  0xa0127ca4
a012838c:  19 00 06 92  sethi  %hi(0x1a4800), %o4
a0128390:  92 00 7f ff  add  %g1, -1, %o1
a0128394:  b0 0a 60 ff  and  %o1, 0xff, %i0
a0128398:  80 a6 20 01  cmp  %i0, 1
a012839c:  18 80 04 7d  bgu  0xa0129590
a01283a0:  11 00 06 92  sethi  %hi(0x1a4800), %o0
a01283a4:  7f fe db 73  call  0xa00df170
a01283a8:  90 12 23 b8  or  %o0, 0x3b8, %o0	! 0x1a4bb8
a01283ac:  90 10 20 0c  mov  0xc, %o0
a01283b0:  40 00 76 2b  call  0xa0145c5c
a01283b4:  92 10 20 00  clr  %o1
a01283b8:  90 10 20 0a  mov  0xa, %o0
a01283bc:  40 00 76 28  call  0xa0145c5c
a01283c0:  92 10 20 00  clr  %o1
a01283c4:  90 10 20 0d  mov  0xd, %o0
a01283c8:  40 00 76 25  call  0xa0145c5c
a01283cc:  92 10 20 00  clr  %o1
a01283d0:  92 10 20 00  clr  %o1
a01283d4:  40 00 76 22  call  0xa0145c5c
a01283d8:  90 10 20 0b  mov  0xb, %o0
a01283dc:  40 00 75 c7  call  0xa0145af8
a01283e0:  90 10 20 0e  mov  0xe, %o0
a01283e4:  a6 02 20 01  add  %o0, 1, %l3
a01283e8:  a9 2c e0 10  sll  %l3, 0x10, %l4
a01283ec:  93 35 20 10  srl  %l4, 0x10, %o1
a01283f0:  40 00 76 1b  call  0xa0145c5c
a01283f4:  90 10 20 0e  mov  0xe, %o0
a01283f8:  40 00 73 da  call  0xa0145360
a01283fc:  90 10 20 01  mov  1, %o0
a0128400:  9e 10 20 01  mov  1, %o7
a0128404:  17 2a 00 b6  sethi  %hi(0xa802d800), %o3
a0128408:  de 2c 20 0c  stb  %o7, [ %l0 + 0xc ]
a012840c:  c0 2a e0 96  clrb  [ %o3 + 0x96 ]
a0128410:  67 fd 94 5e  call  0x4008d588
a0128414:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a0128418:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a012841c:  92 12 a2 90  or  %o2, 0x290, %o1	! 0xa802d290
a0128420:  da 0a 61 e5  ldub  [ %o1 + 0x1e5 ], %o5
a0128424:  82 10 20 02  mov  2, %g1
a0128428:  d0 34 20 04  sth  %o0, [ %l0 + 4 ]
a012842c:  c2 2c 20 11  stb  %g1, [ %l0 + 0x11 ]
a0128430:  80 a3 60 01  cmp  %o5, 1
a0128434:  c0 2a 61 e7  clrb  [ %o1 + 0x1e7 ]
a0128438:  02 80 03 9c  be  0xa01292a8
a012843c:  c0 2a 61 e3  clrb  [ %o1 + 0x1e3 ]
a0128440:  90 10 20 30  mov  0x30, %o0
a0128444:  94 10 20 00  clr  %o2
a0128448:  40 00 8a a2  call  0xa014aed0
a012844c:  96 10 21 fc  mov  0x1fc, %o3
a0128450:  ea 0c 20 0f  ldub  [ %l0 + 0xf ], %l5
a0128454:  80 a5 60 01  cmp  %l5, 1
a0128458:  02 80 03 85  be  0xa012926c
a012845c:  94 16 a0 96  or  %i2, 0x96, %o2
a0128460:  f4 0a a0 0f  ldub  [ %o2 + 0xf ], %i2
a0128464:  80 a6 a0 02  cmp  %i2, 2
a0128468:  12 80 04 4a  bne  0xa0129590
a012846c:  b0 10 20 01  mov  1, %i0
a0128470:  30 bf fe 63  b,a   0xa0127dfc
a0128474:  a0 16 a0 96  or  %i2, 0x96, %l0
a0128478:  67 fd 94 47  call  0x4008d594
a012847c:  d0 14 20 02  lduh  [ %l0 + 2 ], %o0
a0128480:  95 2a 20 10  sll  %o0, 0x10, %o2
a0128484:  83 32 a0 10  srl  %o2, 0x10, %g1
a0128488:  80 a0 61 f4  cmp  %g1, 0x1f4
a012848c:  08 80 04 41  bleu  0xa0129590
a0128490:  01 00 00 00  nop
a0128494:  7f ff f0 f8  call  0xa0124874
a0128498:  01 00 00 00  nop
a012849c:  67 fd 94 3b  call  0x4008d588
a01284a0:  01 00 00 00  nop
a01284a4:  d6 0c 20 16  ldub  [ %l0 + 0x16 ], %o3
a01284a8:  82 02 e0 01  add  %o3, 1, %g1
a01284ac:  9a 08 60 ff  and  %g1, 0xff, %o5
a01284b0:  80 a3 60 07  cmp  %o5, 7
a01284b4:  18 80 02 7d  bgu  0xa0128ea8
a01284b8:  d0 34 20 02  sth  %o0, [ %l0 + 2 ]
a01284bc:  c2 2c 20 16  stb  %g1, [ %l0 + 0x16 ]
a01284c0:  b0 10 20 ff  mov  0xff, %i0
a01284c4:  b2 10 20 ff  mov  0xff, %i1
a01284c8:  80 8b 60 01  btst  1, %o5
a01284cc:  02 bf ff 44  be  0xa01281dc
a01284d0:  b4 10 20 ff  mov  0xff, %i2
a01284d4:  b0 10 20 00  clr  %i0
a01284d8:  b2 10 20 00  clr  %i1
a01284dc:  10 bf ff 40  b  0xa01281dc
a01284e0:  b4 10 20 00  clr  %i2
a01284e4:  b4 16 a0 96  or  %i2, 0x96, %i2
a01284e8:  e6 16 a0 06  lduh  [ %i2 + 6 ], %l3
a01284ec:  80 a4 e0 01  cmp  %l3, 1
a01284f0:  08 80 04 28  bleu  0xa0129590
a01284f4:  01 00 00 00  nop
a01284f8:  7f ff f0 e6  call  0xa0124890
a01284fc:  c0 36 a0 06  clrh  [ %i2 + 6 ]
a0128500:  7f ff f0 f2  call  0xa01248c8
a0128504:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a0128508:  80 8a 20 ff  btst  0xff, %o0
a012850c:  12 80 02 db  bne  0xa0129078
a0128510:  aa 10 20 02  mov  2, %l5
a0128514:  d6 0c 20 88  ldub  [ %l0 + 0x88 ], %o3
a0128518:  94 14 20 88  or  %l0, 0x88, %o2
a012851c:  83 2a e0 08  sll  %o3, 8, %g1
a0128520:  d2 0a a0 01  ldub  [ %o2 + 1 ], %o1
a0128524:  b0 12 40 01  or  %o1, %g1, %i0
a0128528:  1b 00 06 91  sethi  %hi(0x1a4400), %o5
a012852c:  90 13 61 90  or  %o5, 0x190, %o0	! 0x1a4590
a0128530:  7f fe db 10  call  0xa00df170
a0128534:  92 10 00 18  mov  %i0, %o1
a0128538:  40 00 b8 c2  call  0xa0156840
a012853c:  90 10 00 18  mov  %i0, %o0
a0128540:  21 00 06 93  sethi  %hi(0x1a4c00), %l0
a0128544:  40 00 b7 05  call  0xa0156158
a0128548:  d4 1c 22 a0  ldd  [ %l0 + 0x2a0 ], %o2	! 0x1a4ea0
a012854c:  40 00 b3 05  call  0xa0155160
a0128550:  01 00 00 00  nop
a0128554:  a5 2a 20 10  sll  %o0, 0x10, %l2
a0128558:  b3 34 a0 10  srl  %l2, 0x10, %i1
a012855c:  19 00 06 91  sethi  %hi(0x1a4400), %o4
a0128560:  90 13 21 b0  or  %o4, 0x1b0, %o0	! 0x1a45b0
a0128564:  7f fe db 03  call  0xa00df170
a0128568:  92 10 00 19  mov  %i1, %o1
a012856c:  80 a6 60 2d  cmp  %i1, 0x2d
a0128570:  08 80 02 a2  bleu  0xa0128ff8
a0128574:  9e 10 20 06  mov  6, %o7
a0128578:  de 2e a0 01  stb  %o7, [ %i2 + 1 ]
a012857c:  7f ff f1 4d  call  0xa0124ab0
a0128580:  01 00 00 00  nop
a0128584:  7f ff f1 6f  call  0xa0124b40
a0128588:  81 e8 00 00  restore
a012858c:  a0 16 a0 96  or  %i2, 0x96, %l0
a0128590:  de 14 20 06  lduh  [ %l0 + 6 ], %o7
a0128594:  80 a3 e8 34  cmp  %o7, 0x834
a0128598:  08 80 03 fe  bleu  0xa0129590
a012859c:  01 00 00 00  nop
a01285a0:  7f ff f0 ac  call  0xa0124850
a01285a4:  29 00 06 92  sethi  %hi(0x1a4800), %l4
a01285a8:  90 10 20 04  mov  4, %o0
a01285ac:  d0 2c 20 01  stb  %o0, [ %l0 + 1 ]
a01285b0:  c0 34 20 06  clrh  [ %l0 + 6 ]
a01285b4:  7f fe da ef  call  0xa00df170
a01285b8:  91 ed 23 e8  restore  %l4, 0x3e8, %o0
a01285bc:  7f ff f0 e0  call  0xa012493c
a01285c0:  01 00 00 00  nop
a01285c4:  80 8a 20 ff  btst  0xff, %o0
a01285c8:  12 80 00 07  bne  0xa01285e4
a01285cc:  9a 16 a0 96  or  %i2, 0x96, %o5
a01285d0:  a0 16 a0 96  or  %i2, 0x96, %l0
a01285d4:  e4 14 20 06  lduh  [ %l0 + 6 ], %l2
a01285d8:  80 a4 a1 72  cmp  %l2, 0x172
a01285dc:  08 80 03 ed  bleu  0xa0129590
a01285e0:  01 00 00 00  nop
a01285e4:  82 10 20 03  mov  3, %g1	! 0x3
a01285e8:  40 00 7c 4f  call  0xa0147724
a01285ec:  c2 2b 60 01  stb  %g1, [ %o5 + 1 ]
a01285f0:  10 80 00 04  b  0xa0128600
a01285f4:  a1 2a 20 10  sll  %o0, 0x10, %l0
a01285f8:  40 00 95 c6  call  0xa014dd10
a01285fc:  01 00 00 00  nop
a0128600:  40 00 7c 50  call  0xa0147740
a0128604:  91 34 20 10  srl  %l0, 0x10, %o0
a0128608:  95 2a 20 10  sll  %o0, 0x10, %o2
a012860c:  93 32 a0 10  srl  %o2, 0x10, %o1
a0128610:  80 a2 61 f3  cmp  %o1, 0x1f3
a0128614:  08 bf ff f9  bleu  0xa01285f8
a0128618:  01 00 00 00  nop
a012861c:  7f ff f0 96  call  0xa0124874
a0128620:  31 00 06 92  sethi  %hi(0x1a4800), %i0
a0128624:  96 16 a0 96  or  %i2, 0x96, %o3
a0128628:  7f ff f1 10  call  0xa0124a68
a012862c:  c0 32 e0 06  clrh  [ %o3 + 6 ]
a0128630:  7f ff f1 44  call  0xa0124b40
a0128634:  b0 16 23 f8  or  %i0, 0x3f8, %i0
a0128638:  7f fe da ce  call  0xa00df170
a012863c:  81 e8 00 00  restore
a0128640:  7f ff f0 bf  call  0xa012493c
a0128644:  01 00 00 00  nop
a0128648:  80 8a 20 ff  btst  0xff, %o0
a012864c:  12 80 00 06  bne  0xa0128664
a0128650:  a0 16 a0 96  or  %i2, 0x96, %l0
a0128654:  e4 14 20 06  lduh  [ %l0 + 6 ], %l2
a0128658:  80 a4 a0 5f  cmp  %l2, 0x5f
a012865c:  08 80 03 cd  bleu  0xa0129590
a0128660:  01 00 00 00  nop
a0128664:  67 fd 93 c9  call  0x4008d588
a0128668:  31 00 06 93  sethi  %hi(0x1a4c00), %i0
a012866c:  92 16 a0 96  or  %i2, 0x96, %o1
a0128670:  9a 10 20 06  mov  6, %o5
a0128674:  d0 32 60 02  sth  %o0, [ %o1 + 2 ]
a0128678:  da 2a 60 01  stb  %o5, [ %o1 + 1 ]
a012867c:  c0 32 60 06  clrh  [ %o1 + 6 ]
a0128680:  7f fe da bc  call  0xa00df170
a0128684:  91 ee 20 08  restore  %i0, 8, %o0
a0128688:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a012868c:  92 16 62 90  or  %i1, 0x290, %o1	! 0xa802d290
a0128690:  f0 0a 61 e5  ldub  [ %o1 + 0x1e5 ], %i0
a0128694:  80 a6 20 00  cmp  %i0, 0
a0128698:  12 80 00 04  bne  0xa01286a8
a012869c:  90 10 20 30  mov  0x30, %o0
a01286a0:  98 10 20 01  mov  1, %o4
a01286a4:  d8 2a 61 e7  stb  %o4, [ %o1 + 0x1e7 ]
a01286a8:  94 10 20 00  clr  %o2
a01286ac:  40 00 8a 09  call  0xa014aed0
a01286b0:  96 10 21 fc  mov  0x1fc, %o3
a01286b4:  a0 16 a0 96  or  %i2, 0x96, %l0
a01286b8:  f4 14 20 06  lduh  [ %l0 + 6 ], %i2
a01286bc:  80 a6 a3 84  cmp  %i2, 0x384
a01286c0:  08 80 03 b4  bleu  0xa0129590
a01286c4:  01 00 00 00  nop
a01286c8:  7f ff f0 62  call  0xa0124850
a01286cc:  01 00 00 00  nop
a01286d0:  9a 10 20 01  mov  1, %o5	! 0x1
a01286d4:  03 00 06 93  sethi  %hi(0x1a4c00), %g1
a01286d8:  da 2c 20 01  stb  %o5, [ %l0 + 1 ]
a01286dc:  c0 34 20 06  clrh  [ %l0 + 6 ]
a01286e0:  7f fe da a4  call  0xa00df170
a01286e4:  91 e8 60 18  restore  %g1, 0x18, %o0
a01286e8:  b2 16 a0 96  or  %i2, 0x96, %i1
a01286ec:  d2 16 60 06  lduh  [ %i1 + 6 ], %o1
a01286f0:  80 a2 60 01  cmp  %o1, 1
a01286f4:  08 80 03 a7  bleu  0xa0129590
a01286f8:  01 00 00 00  nop
a01286fc:  7f ff f0 65  call  0xa0124890
a0128700:  c0 36 60 06  clrh  [ %i1 + 6 ]
a0128704:  7f ff f0 71  call  0xa01248c8
a0128708:  21 2a 00 b6  sethi  %hi(0xa802d800), %l0
a012870c:  80 8a 20 ff  btst  0xff, %o0
a0128710:  12 80 02 1f  bne  0xa0128f8c
a0128714:  94 10 20 02  mov  2, %o2
a0128718:  ea 0c 20 88  ldub  [ %l0 + 0x88 ], %l5
a012871c:  a4 14 20 88  or  %l0, 0x88, %l2
a0128720:  a7 2d 60 08  sll  %l5, 8, %l3
a0128724:  d0 0c a0 01  ldub  [ %l2 + 1 ], %o0
a0128728:  a8 12 00 13  or  %o0, %l3, %l4
a012872c:  27 00 06 91  sethi  %hi(0x1a4400), %l3
a0128730:  92 10 00 14  mov  %l4, %o1
a0128734:  7f fe da 8f  call  0xa00df170
a0128738:  90 14 e1 90  or  %l3, 0x190, %o0
a012873c:  40 00 b8 41  call  0xa0156840
a0128740:  90 10 00 14  mov  %l4, %o0
a0128744:  1f 00 06 93  sethi  %hi(0x1a4c00), %o7
a0128748:  e8 1b e2 a0  ldd  [ %o7 + 0x2a0 ], %l4	! 0x1a4ea0
a012874c:  94 10 00 14  mov  %l4, %o2
a0128750:  40 00 b6 82  call  0xa0156158
a0128754:  96 10 00 15  mov  %l5, %o3
a0128758:  40 00 b2 82  call  0xa0155160
a012875c:  31 00 06 91  sethi  %hi(0x1a4400), %i0
a0128760:  97 2a 20 10  sll  %o0, 0x10, %o3
a0128764:  a1 32 e0 10  srl  %o3, 0x10, %l0
a0128768:  90 16 21 b0  or  %i0, 0x1b0, %o0
a012876c:  7f fe da 81  call  0xa00df170
a0128770:  92 10 00 10  mov  %l0, %o1
a0128774:  80 a4 20 2d  cmp  %l0, 0x2d
a0128778:  08 80 01 db  bleu  0xa0128ee4
a012877c:  98 10 20 06  mov  6, %o4
a0128780:  b4 10 20 02  mov  2, %i2
a0128784:  d8 2e 60 01  stb  %o4, [ %i1 + 1 ]
a0128788:  7f ff f0 ca  call  0xa0124ab0
a012878c:  f4 2e 60 0f  stb  %i2, [ %i1 + 0xf ]
a0128790:  7f ff f0 ec  call  0xa0124b40
a0128794:  01 00 00 00  nop
a0128798:  7f ff f0 4c  call  0xa01248c8
a012879c:  01 00 00 00  nop
a01287a0:  80 8a 20 ff  btst  0xff, %o0
a01287a4:  32 80 02 e0  bne,a   0xa0129324
a01287a8:  b2 10 20 02  mov  2, %i1
a01287ac:  15 2a 00 b6  sethi  %hi(0xa802d800), %o2
a01287b0:  d2 0a a0 88  ldub  [ %o2 + 0x88 ], %o1	! 0xa802d888
a01287b4:  83 2a 60 08  sll  %o1, 8, %g1
a01287b8:  da 0c a0 01  ldub  [ %l2 + 1 ], %o5
a01287bc:  a0 13 40 01  or  %o5, %g1, %l0
a01287c0:  92 10 00 10  mov  %l0, %o1
a01287c4:  7f fe da 6b  call  0xa00df170
a01287c8:  90 14 e1 90  or  %l3, 0x190, %o0
a01287cc:  40 00 b8 1d  call  0xa0156840
a01287d0:  90 10 00 10  mov  %l0, %o0
a01287d4:  94 10 00 14  mov  %l4, %o2
a01287d8:  40 00 b6 60  call  0xa0156158
a01287dc:  96 10 00 15  mov  %l5, %o3
a01287e0:  40 00 b2 60  call  0xa0155160
a01287e4:  01 00 00 00  nop
a01287e8:  a5 2a 20 10  sll  %o0, 0x10, %l2
a01287ec:  b3 34 a0 10  srl  %l2, 0x10, %i1
a01287f0:  10 bf fe de  b  0xa0128368
a01287f4:  90 16 21 b0  or  %i0, 0x1b0, %o0
a01287f8:  40 00 74 c0  call  0xa0145af8
a01287fc:  90 10 20 0d  mov  0xd, %o0
a0128800:  99 2a 20 10  sll  %o0, 0x10, %o4
a0128804:  b3 33 20 10  srl  %o4, 0x10, %i1
a0128808:  40 00 74 bc  call  0xa0145af8
a012880c:  90 10 20 0b  mov  0xb, %o0
a0128810:  b1 2e 60 04  sll  %i1, 4, %i0
a0128814:  aa 26 00 19  sub  %i0, %i1, %l5
a0128818:  a9 2a 20 10  sll  %o0, 0x10, %l4
a012881c:  a7 2d 60 02  sll  %l5, 2, %l3
a0128820:  a5 35 20 10  srl  %l4, 0x10, %l2
a0128824:  80 84 c0 12  addcc  %l3, %l2, %g0
a0128828:  1c bf fd a1  bpos  0xa0127eac
a012882c:  82 10 20 02  mov  2, %g1
a0128830:  10 bf fd 9f  b  0xa0127eac
a0128834:  82 10 20 00  clr  %g1
a0128838:  80 a5 20 00  cmp  %l4, 0
a012883c:  02 bf fe 8b  be  0xa0128268
a0128840:  9a 10 20 b4  mov  0xb4, %o5
a0128844:  40 00 74 ad  call  0xa0145af8
a0128848:  90 10 20 11  mov  0x11, %o0
a012884c:  ab 2a 20 10  sll  %o0, 0x10, %l5
a0128850:  a7 35 60 10  srl  %l5, 0x10, %l3
a0128854:  80 a4 e0 01  cmp  %l3, 1
a0128858:  12 bf fe 83  bne  0xa0128264
a012885c:  9a 10 20 05  mov  5, %o5
a0128860:  10 bf fe 83  b  0xa012826c
a0128864:  b4 16 a0 96  or  %i2, 0x96, %i2
a0128868:  67 fd 93 48  call  0x4008d588
a012886c:  01 00 00 00  nop
a0128870:  d6 14 20 06  lduh  [ %l0 + 6 ], %o3
a0128874:  d4 14 20 14  lduh  [ %l0 + 0x14 ], %o2
a0128878:  92 02 e0 01  add  %o3, 1, %o1
a012887c:  9a 02 a0 01  add  %o2, 1, %o5
a0128880:  f2 0c 20 13  ldub  [ %l0 + 0x13 ], %i1
a0128884:  d0 34 20 02  sth  %o0, [ %l0 + 2 ]
a0128888:  d2 34 20 06  sth  %o1, [ %l0 + 6 ]
a012888c:  80 a6 60 01  cmp  %i1, 1
a0128890:  02 80 00 ab  be  0xa0128b3c
a0128894:  da 34 20 14  sth  %o5, [ %l0 + 0x14 ]
a0128898:  a0 16 a0 96  or  %i2, 0x96, %l0
a012889c:  d2 14 20 14  lduh  [ %l0 + 0x14 ], %o1
a01288a0:  90 10 2d 89  mov  0xd89, %o0
a01288a4:  7f fe c7 f1  call  0xa00da868
a01288a8:  d4 0e a0 96  ldub  [ %i2 + 0x96 ], %o2
a01288ac:  10 bf fd 98  b  0xa0127f0c
a01288b0:  9e 16 a0 96  or  %i2, 0x96, %o7
a01288b4:  67 fd 93 35  call  0x4008d588
a01288b8:  01 00 00 00  nop
a01288bc:  f2 14 20 06  lduh  [ %l0 + 6 ], %i1
a01288c0:  ea 14 20 14  lduh  [ %l0 + 0x14 ], %l5
a01288c4:  a6 06 60 01  add  %i1, 1, %l3
a01288c8:  a8 05 60 01  add  %l5, 1, %l4
a01288cc:  f2 0c 20 13  ldub  [ %l0 + 0x13 ], %i1
a01288d0:  d0 34 20 02  sth  %o0, [ %l0 + 2 ]
a01288d4:  e6 34 20 06  sth  %l3, [ %l0 + 6 ]
a01288d8:  80 a6 60 01  cmp  %i1, 1
a01288dc:  02 80 00 90  be  0xa0128b1c
a01288e0:  e8 34 20 14  sth  %l4, [ %l0 + 0x14 ]
a01288e4:  a4 16 a0 96  or  %i2, 0x96, %l2
a01288e8:  d2 14 a0 14  lduh  [ %l2 + 0x14 ], %o1
a01288ec:  90 10 22 26  mov  0x226, %o0
a01288f0:  7f fe c7 de  call  0xa00da868
a01288f4:  d4 0e a0 96  ldub  [ %i2 + 0x96 ], %o2
a01288f8:  10 bf fd 97  b  0xa0127f54
a01288fc:  a0 16 a0 96  or  %i2, 0x96, %l0
a0128900:  d0 0e 60 09  ldub  [ %i1 + 9 ], %o0
a0128904:  80 a2 20 01  cmp  %o0, 1
a0128908:  32 bf fd 6f  bne,a   0xa0127ec4
a012890c:  a0 16 a0 96  or  %i2, 0x96, %l0
a0128910:  da 0e 60 10  ldub  [ %i1 + 0x10 ], %o5
a0128914:  80 a3 60 00  cmp  %o5, 0
a0128918:  32 bf fd 6b  bne,a   0xa0127ec4
a012891c:  a0 16 a0 96  or  %i2, 0x96, %l0
a0128920:  f0 0e 60 01  ldub  [ %i1 + 1 ], %i0
a0128924:  80 a6 20 00  cmp  %i0, 0
a0128928:  02 80 00 d9  be  0xa0128c8c
a012892c:  80 a6 20 01  cmp  %i0, 1
a0128930:  12 80 03 18  bne  0xa0129590
a0128934:  25 00 06 93  sethi  %hi(0x1a4c00), %l2
a0128938:  7f fe da 0e  call  0xa00df170
a012893c:  90 14 a0 28  or  %l2, 0x28, %o0	! 0x1a4c28
a0128940:  67 fd 93 15  call  0x4008d594
a0128944:  d0 16 60 04  lduh  [ %i1 + 4 ], %o0
a0128948:  9f 2a 20 10  sll  %o0, 0x10, %o7
a012894c:  97 33 e0 10  srl  %o7, 0x10, %o3
a0128950:  80 a2 e0 0a  cmp  %o3, 0xa
a0128954:  08 80 03 0f  bleu  0xa0129590
a0128958:  01 00 00 00  nop
a012895c:  7f ff f0 55  call  0xa0124ab0
a0128960:  29 00 06 93  sethi  %hi(0x1a4c00), %l4
a0128964:  7f ff f0 77  call  0xa0124b40
a0128968:  27 2a 00 b6  sethi  %hi(0xa802d800), %l3
a012896c:  7f fe da 01  call  0xa00df170
a0128970:  90 15 20 48  or  %l4, 0x48, %o0
a0128974:  92 10 20 00  clr  %o1
a0128978:  40 00 71 ed  call  0xa014512c
a012897c:  90 10 20 00  clr  %o0
a0128980:  f0 2e 60 08  stb  %i0, [ %i1 + 8 ]
a0128984:  c0 2e 60 0a  clrb  [ %i1 + 0xa ]
a0128988:  c0 2e 60 01  clrb  [ %i1 + 1 ]
a012898c:  67 fd 92 ff  call  0x4008d588
a0128990:  e0 2c e0 96  stb  %l0, [ %l3 + 0x96 ]
a0128994:  67 fd 92 fd  call  0x4008d588
a0128998:  d0 36 60 02  sth  %o0, [ %i1 + 2 ]
a012899c:  d0 36 60 04  sth  %o0, [ %i1 + 4 ]
a01289a0:  f0 2e 60 13  stb  %i0, [ %i1 + 0x13 ]
a01289a4:  c0 36 60 06  clrh  [ %i1 + 6 ]
a01289a8:  c0 36 60 14  clrh  [ %i1 + 0x14 ]
a01289ac:  7f ff f3 f7  call  0xa0125988
a01289b0:  c0 2e 60 16  clrb  [ %i1 + 0x16 ]
a01289b4:  7f fe c3 f1  call  0xa00d9978
a01289b8:  b0 10 20 40  mov  0x40, %i0
a01289bc:  92 10 20 00  clr  %o1
a01289c0:  94 10 20 00  clr  %o2
a01289c4:  7f fe c7 a3  call  0xa00da850
a01289c8:  90 10 20 00  clr  %o0
a01289cc:  67 fd 91 f5  call  0x4008d1a0
a01289d0:  90 10 20 05  mov  5, %o0
a01289d4:  7f ff f4 98  call  0xa0125c34
a01289d8:  b2 10 20 00  clr  %i1
a01289dc:  90 10 20 ff  mov  0xff, %o0
a01289e0:  7f fd 99 23  call  0xa008ee6c
a01289e4:  92 10 20 01  mov  1, %o1
a01289e8:  7f fd 99 21  call  0xa008ee6c
a01289ec:  81 e8 00 00  restore
a01289f0:  80 a6 a0 00  cmp  %i2, 0
a01289f4:  12 80 02 e7  bne  0xa0129590
a01289f8:  01 00 00 00  nop
a01289fc:  67 fd 92 e6  call  0x4008d594
a0128a00:  d0 14 20 04  lduh  [ %l0 + 4 ], %o0
a0128a04:  b5 2a 20 10  sll  %o0, 0x10, %i2
a0128a08:  9b 36 a0 10  srl  %i2, 0x10, %o5
a0128a0c:  80 a3 60 0a  cmp  %o5, 0xa
a0128a10:  08 80 02 e0  bleu  0xa0129590
a0128a14:  17 00 06 93  sethi  %hi(0x1a4c00), %o3
a0128a18:  7f fe d9 d6  call  0xa00df170
a0128a1c:  90 12 e0 60  or  %o3, 0x60, %o0	! 0x1a4c60
a0128a20:  90 10 20 01  mov  1, %o0
a0128a24:  40 00 71 c2  call  0xa014512c
a0128a28:  92 10 20 01  mov  1, %o1
a0128a2c:  67 fd 92 d7  call  0x4008d588
a0128a30:  01 00 00 00  nop
a0128a34:  82 10 20 01  mov  1, %g1	! 0x1
a0128a38:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a0128a3c:  10 80 02 d5  b  0xa0129590
a0128a40:  d0 34 20 04  sth  %o0, [ %l0 + 4 ]
a0128a44:  80 a0 60 00  cmp  %g1, 0
a0128a48:  12 80 02 d2  bne  0xa0129590
a0128a4c:  11 00 06 93  sethi  %hi(0x1a4c00), %o0
a0128a50:  7f fe d9 c8  call  0xa00df170
a0128a54:  90 12 20 70  or  %o0, 0x70, %o0	! 0x1a4c70
a0128a58:  a4 10 20 01  mov  1, %l2
a0128a5c:  10 80 02 cd  b  0xa0129590
a0128a60:  e4 2c 20 01  stb  %l2, [ %l0 + 1 ]
a0128a64:  7f fe d9 c3  call  0xa00df170
a0128a68:  90 15 62 e0  or  %l5, 0x2e0, %o0
a0128a6c:  a8 10 20 02  mov  2, %l4
a0128a70:  67 fd 92 c6  call  0x4008d588
a0128a74:  e8 2c 20 01  stb  %l4, [ %l0 + 1 ]
a0128a78:  10 80 02 c6  b  0xa0129590
a0128a7c:  d0 34 20 04  sth  %o0, [ %l0 + 4 ]
a0128a80:  67 fd 92 c5  call  0x4008d594
a0128a84:  d0 14 20 04  lduh  [ %l0 + 4 ], %o0
a0128a88:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0128a8c:  83 33 e0 10  srl  %o7, 0x10, %g1
a0128a90:  80 a0 63 e8  cmp  %g1, 0x3e8
a0128a94:  08 80 02 bf  bleu  0xa0129590
a0128a98:  11 00 06 93  sethi  %hi(0x1a4c00), %o0
a0128a9c:  25 2a 00 b6  sethi  %hi(0xa802d800), %l2
a0128aa0:  7f fe d9 b4  call  0xa00df170
a0128aa4:  90 12 20 b0  or  %o0, 0xb0, %o0
a0128aa8:  b2 14 a0 90  or  %l2, 0x90, %i1
a0128aac:  c0 2c a0 90  clrb  [ %l2 + 0x90 ]
a0128ab0:  7f ff ef 86  call  0xa01248c8
a0128ab4:  c0 2e 60 01  clrb  [ %i1 + 1 ]
a0128ab8:  80 8a 20 ff  btst  0xff, %o0
a0128abc:  12 80 00 a5  bne  0xa0128d50
a0128ac0:  2b 00 06 91  sethi  %hi(0x1a4400), %l5
a0128ac4:  67 fd 92 b1  call  0x4008d588
a0128ac8:  01 00 00 00  nop
a0128acc:  82 10 20 02  mov  2, %g1	! 0x2
a0128ad0:  10 bf ff db  b  0xa0128a3c
a0128ad4:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a0128ad8:  67 fd 92 af  call  0x4008d594
a0128adc:  d0 14 20 04  lduh  [ %l0 + 4 ], %o0
a0128ae0:  99 2a 20 10  sll  %o0, 0x10, %o4
a0128ae4:  b3 33 20 10  srl  %o4, 0x10, %i1
a0128ae8:  80 a6 60 0a  cmp  %i1, 0xa
a0128aec:  08 80 02 a9  bleu  0xa0129590
a0128af0:  27 00 06 93  sethi  %hi(0x1a4c00), %l3
a0128af4:  7f fe d9 9f  call  0xa00df170
a0128af8:  90 14 e0 d0  or  %l3, 0xd0, %o0	! 0x1a4cd0
a0128afc:  90 10 20 00  clr  %o0
a0128b00:  40 00 71 8b  call  0xa014512c
a0128b04:  92 10 20 01  mov  1, %o1
a0128b08:  67 fd 92 a0  call  0x4008d588
a0128b0c:  01 00 00 00  nop
a0128b10:  82 10 20 03  mov  3, %g1	! 0x3
a0128b14:  10 bf ff ca  b  0xa0128a3c
a0128b18:  c2 2c 20 01  stb  %g1, [ %l0 + 1 ]
a0128b1c:  d0 0c 20 08  ldub  [ %l0 + 8 ], %o0
a0128b20:  80 a2 20 01  cmp  %o0, 1
a0128b24:  02 80 00 0e  be  0xa0128b5c
a0128b28:  01 00 00 00  nop
a0128b2c:  7f ff ef f3  call  0xa0124af8
a0128b30:  a4 16 a0 96  or  %i2, 0x96, %l2
a0128b34:  10 bf ff 6d  b  0xa01288e8
a0128b38:  f2 2c 20 08  stb  %i1, [ %l0 + 8 ]
a0128b3c:  d0 0c 20 08  ldub  [ %l0 + 8 ], %o0
a0128b40:  80 a2 20 01  cmp  %o0, 1
a0128b44:  02 80 00 0a  be  0xa0128b6c
a0128b48:  01 00 00 00  nop
a0128b4c:  7f ff ef c7  call  0xa0124a68
a0128b50:  01 00 00 00  nop
a0128b54:  10 bf ff 51  b  0xa0128898
a0128b58:  f2 2c 20 08  stb  %i1, [ %l0 + 8 ]
a0128b5c:  7f ff ef f9  call  0xa0124b40
a0128b60:  a4 16 a0 96  or  %i2, 0x96, %l2
a0128b64:  10 bf ff 61  b  0xa01288e8
a0128b68:  c0 2c 20 08  clrb  [ %l0 + 8 ]
a0128b6c:  7f ff ef d1  call  0xa0124ab0
a0128b70:  01 00 00 00  nop
a0128b74:  10 bf ff 49  b  0xa0128898
a0128b78:  c0 2c 20 08  clrb  [ %l0 + 8 ]
a0128b7c:  e6 0c 20 0f  ldub  [ %l0 + 0xf ], %l3
a0128b80:  92 10 20 04  mov  4, %o1
a0128b84:  d2 2c 20 01  stb  %o1, [ %l0 + 1 ]
a0128b88:  80 a4 e0 00  cmp  %l3, 0
a0128b8c:  c0 34 20 14  clrh  [ %l0 + 0x14 ]
a0128b90:  12 80 02 80  bne  0xa0129590
a0128b94:  c0 2c 20 16  clrb  [ %l0 + 0x16 ]
a0128b98:  7f fe c3 84  call  0xa00d99a8
a0128b9c:  81 e8 00 00  restore
a0128ba0:  7f ff f6 d9  call  0xa0126704
a0128ba4:  90 10 20 00  clr  %o0
a0128ba8:  40 00 7e 56  call  0xa0148500
a0128bac:  2b 2a 00 b6  sethi  %hi(0xa802d800), %l5
a0128bb0:  67 fd 91 7c  call  0x4008d1a0
a0128bb4:  90 10 21 f4  mov  0x1f4, %o0
a0128bb8:  7f ff f4 3b  call  0xa0125ca4
a0128bbc:  a4 15 60 90  or  %l5, 0x90, %l2
a0128bc0:  a0 10 20 01  mov  1, %l0
a0128bc4:  c0 2d 60 90  clrb  [ %l5 + 0x90 ]
a0128bc8:  7f ff ef 40  call  0xa01248c8
a0128bcc:  e0 2c a0 01  stb  %l0, [ %l2 + 1 ]
a0128bd0:  80 8a 20 ff  btst  0xff, %o0
a0128bd4:  12 80 00 05  bne  0xa0128be8
a0128bd8:  1b 00 06 91  sethi  %hi(0x1a4400), %o5
a0128bdc:  e0 2e a0 01  stb  %l0, [ %i2 + 1 ]
a0128be0:  10 80 02 6c  b  0xa0129590
a0128be4:  c0 36 a0 06  clrh  [ %i2 + 6 ]
a0128be8:  90 13 61 40  or  %o5, 0x140, %o0
a0128bec:  7f fe d9 61  call  0xa00df170
a0128bf0:  92 10 20 01  mov  1, %o1
a0128bf4:  92 10 20 02  mov  2, %o1
a0128bf8:  d2 23 a0 5c  st  %o1, [ %sp + 0x5c ]
a0128bfc:  a6 10 20 01  mov  1, %l3
a0128c00:  e6 23 a0 60  st  %l3, [ %sp + 0x60 ]
a0128c04:  9a 10 00 12  mov  %l2, %o5
a0128c08:  90 10 20 60  mov  0x60, %o0
a0128c0c:  92 10 20 02  mov  2, %o1
a0128c10:  94 10 20 c0  mov  0xc0, %o2
a0128c14:  96 10 20 05  mov  5, %o3
a0128c18:  40 00 7b a2  call  0xa0147aa0
a0128c1c:  98 10 20 00  clr  %o4
a0128c20:  e0 2e a0 01  stb  %l0, [ %i2 + 1 ]
a0128c24:  10 80 02 5b  b  0xa0129590
a0128c28:  c0 36 a0 06  clrh  [ %i2 + 6 ]
a0128c2c:  15 00 06 93  sethi  %hi(0x1a4c00), %o2
a0128c30:  7f fe d9 50  call  0xa00df170
a0128c34:  90 12 a0 e8  or  %o2, 0xe8, %o0	! 0x1a4ce8
a0128c38:  40 00 6c 60  call  0xa0143db8
a0128c3c:  90 10 20 00  clr  %o0
a0128c40:  80 8a 20 ff  btst  0xff, %o0
a0128c44:  12 80 00 51  bne  0xa0128d88
a0128c48:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0128c4c:  82 14 a2 90  or  %l2, 0x290, %g1	! 0xa802d290
a0128c50:  f2 08 61 d5  ldub  [ %g1 + 0x1d5 ], %i1
a0128c54:  80 a6 60 00  cmp  %i1, 0
a0128c58:  12 80 00 4d  bne  0xa0128d8c
a0128c5c:  90 10 20 00  clr  %o0
a0128c60:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a0128c64:  9e 13 23 f4  or  %o4, 0x3f4, %o7	! 0xa802cff4
a0128c68:  ea 13 e0 04  lduh  [ %o7 + 4 ], %l5
a0128c6c:  29 00 00 18  sethi  %hi(0x6000), %l4
a0128c70:  b4 2d 40 14  andn  %l5, %l4, %i2
a0128c74:  31 00 00 10  sethi  %hi(0x4000), %i0
a0128c78:  90 16 80 18  or  %i2, %i0, %o0
a0128c7c:  d0 33 e0 04  sth  %o0, [ %o7 + 4 ]
a0128c80:  96 10 20 01  mov  1, %o3
a0128c84:  10 80 02 43  b  0xa0129590
a0128c88:  d6 2c 20 0f  stb  %o3, [ %l0 + 0xf ]
a0128c8c:  15 00 06 93  sethi  %hi(0x1a4c00), %o2
a0128c90:  7f fe d9 38  call  0xa00df170
a0128c94:  90 12 a1 08  or  %o2, 0x108, %o0	! 0x1a4d08
a0128c98:  40 00 73 98  call  0xa0145af8
a0128c9c:  90 10 20 10  mov  0x10, %o0
a0128ca0:  93 2a 20 10  sll  %o0, 0x10, %o1
a0128ca4:  80 a2 60 00  cmp  %o1, 0
a0128ca8:  12 80 00 c3  bne  0xa0128fb4
a0128cac:  01 00 00 00  nop
a0128cb0:  40 00 73 92  call  0xa0145af8
a0128cb4:  90 10 20 0d  mov  0xd, %o0	! 0xd
a0128cb8:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0128cbc:  97 33 e0 10  srl  %o7, 0x10, %o3
a0128cc0:  80 a2 e0 04  cmp  %o3, 4
a0128cc4:  82 60 3f ff  subx  %g0, -1, %g1
a0128cc8:  a0 16 a0 96  or  %i2, 0x96, %l0
a0128ccc:  11 00 06 93  sethi  %hi(0x1a4c00), %o0
a0128cd0:  92 08 60 01  and  %g1, 1, %o1
a0128cd4:  90 12 21 28  or  %o0, 0x128, %o0
a0128cd8:  d4 0c 20 09  ldub  [ %l0 + 9 ], %o2
a0128cdc:  d6 0c 20 0a  ldub  [ %l0 + 0xa ], %o3
a0128ce0:  7f fe d9 24  call  0xa00df170
a0128ce4:  d8 0c 20 10  ldub  [ %l0 + 0x10 ], %o4
a0128ce8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0128cec:  92 10 62 90  or  %g1, 0x290, %o1	! 0xa802d290
a0128cf0:  f4 0a 61 e4  ldub  [ %o1 + 0x1e4 ], %i2
a0128cf4:  80 a6 a0 00  cmp  %i2, 0
a0128cf8:  12 80 00 04  bne  0xa0128d08
a0128cfc:  96 10 21 fc  mov  0x1fc, %o3
a0128d00:  9a 10 20 01  mov  1, %o5
a0128d04:  da 2a 61 e6  stb  %o5, [ %o1 + 0x1e6 ]
a0128d08:  94 10 20 00  clr  %o2
a0128d0c:  40 00 88 71  call  0xa014aed0
a0128d10:  90 10 20 30  mov  0x30, %o0
a0128d14:  7f ff 55 da  call  0xa00fe47c
a0128d18:  01 00 00 00  nop
a0128d1c:  94 12 21 20  or  %o0, 0x120, %o2
a0128d20:  93 2a a0 10  sll  %o2, 0x10, %o1
a0128d24:  7f ff 55 ca  call  0xa00fe44c
a0128d28:  91 32 60 10  srl  %o1, 0x10, %o0
a0128d2c:  7f ff 77 9f  call  0xa0106ba8
a0128d30:  90 10 20 00  clr  %o0
a0128d34:  7f ff 77 9d  call  0xa0106ba8
a0128d38:  90 10 20 01  mov  1, %o0
a0128d3c:  7f ff 77 9b  call  0xa0106ba8
a0128d40:  90 10 20 02  mov  2, %o0
a0128d44:  7f ff 77 99  call  0xa0106ba8
a0128d48:  90 10 20 03  mov  3, %o0
a0128d4c:  30 bf ff 38  b,a   0xa0128a2c
a0128d50:  90 15 61 40  or  %l5, 0x140, %o0
a0128d54:  7f fe d9 07  call  0xa00df170
a0128d58:  92 10 20 00  clr  %o1
a0128d5c:  a8 10 20 02  mov  2, %l4
a0128d60:  e8 23 a0 5c  st  %l4, [ %sp + 0x5c ]
a0128d64:  f4 23 a0 60  st  %i2, [ %sp + 0x60 ]
a0128d68:  9a 10 00 19  mov  %i1, %o5
a0128d6c:  92 10 20 02  mov  2, %o1
a0128d70:  94 10 20 c0  mov  0xc0, %o2
a0128d74:  96 10 20 05  mov  5, %o3
a0128d78:  98 10 20 00  clr  %o4
a0128d7c:  40 00 7b 49  call  0xa0147aa0
a0128d80:  90 10 20 60  mov  0x60, %o0
a0128d84:  30 bf ff 50  b,a   0xa0128ac4
a0128d88:  90 10 20 00  clr  %o0
a0128d8c:  40 00 7d 37  call  0xa0148268
a0128d90:  92 10 20 00  clr  %o1
a0128d94:  90 10 20 01  mov  1, %o0
a0128d98:  40 00 7d 34  call  0xa0148268
a0128d9c:  92 10 20 00  clr  %o1
a0128da0:  40 00 6c 02  call  0xa0143da8
a0128da4:  01 00 00 00  nop
a0128da8:  90 10 20 0d  mov  0xd, %o0	! 0xd
a0128dac:  40 00 73 ac  call  0xa0145c5c
a0128db0:  92 10 20 00  clr  %o1
a0128db4:  90 10 20 0b  mov  0xb, %o0
a0128db8:  40 00 73 a9  call  0xa0145c5c
a0128dbc:  92 10 20 00  clr  %o1
a0128dc0:  40 00 73 4e  call  0xa0145af8
a0128dc4:  90 10 20 11  mov  0x11, %o0
a0128dc8:  a1 2a 20 10  sll  %o0, 0x10, %l0
a0128dcc:  80 a4 20 00  cmp  %l0, 0
a0128dd0:  02 80 01 44  be  0xa01292e0
a0128dd4:  01 00 00 00  nop
a0128dd8:  90 10 20 11  mov  0x11, %o0	! 0x11
a0128ddc:  40 00 73 a0  call  0xa0145c5c
a0128de0:  92 10 20 00  clr  %o1
a0128de4:  40 00 71 5f  call  0xa0145360
a0128de8:  90 10 20 01  mov  1, %o0
a0128dec:  a0 14 a2 90  or  %l2, 0x290, %l0
a0128df0:  da 0c 21 e4  ldub  [ %l0 + 0x1e4 ], %o5
a0128df4:  80 a3 60 01  cmp  %o5, 1
a0128df8:  c0 2c 21 e6  clrb  [ %l0 + 0x1e6 ]
a0128dfc:  02 80 01 37  be  0xa01292d8
a0128e00:  c0 2c 21 e2  clrb  [ %l0 + 0x1e2 ]
a0128e04:  94 10 20 00  clr  %o2
a0128e08:  90 10 20 30  mov  0x30, %o0
a0128e0c:  92 10 00 10  mov  %l0, %o1
a0128e10:  40 00 88 30  call  0xa014aed0
a0128e14:  96 10 21 fc  mov  0x1fc, %o3
a0128e18:  f2 04 21 f4  ld  [ %l0 + 0x1f4 ], %i1
a0128e1c:  15 10 00 00  sethi  %hi(0x40000000), %o2
a0128e20:  80 8e 40 0a  btst  %i1, %o2
a0128e24:  02 80 00 9f  be  0xa01290a0
a0128e28:  01 00 00 00  nop
a0128e2c:  7f ff ef 0f  call  0xa0124a68
a0128e30:  01 00 00 00  nop
a0128e34:  7f ff ef 43  call  0xa0124b40
a0128e38:  01 00 00 00  nop
a0128e3c:  90 10 20 00  clr  %o0	! 0x0
a0128e40:  40 00 70 bb  call  0xa014512c
a0128e44:  92 10 20 01  mov  1, %o1
a0128e48:  90 10 20 00  clr  %o0
a0128e4c:  92 10 20 01  mov  1, %o1
a0128e50:  7f fe c7 7a  call  0xa00dac38
a0128e54:  94 10 20 00  clr  %o2
a0128e58:  98 14 a2 90  or  %l2, 0x290, %o4
a0128e5c:  03 00 00 15  sethi  %hi(0x5400), %g1
a0128e60:  d6 13 21 f6  lduh  [ %o4 + 0x1f6 ], %o3
a0128e64:  a4 10 61 aa  or  %g1, 0x1aa, %l2
a0128e68:  80 a2 c0 12  cmp  %o3, %l2
a0128e6c:  22 80 01 26  be,a   0xa0129304
a0128e70:  de 0b 21 d5  ldub  [ %o4 + 0x1d5 ], %o7
a0128e74:  90 16 a0 96  or  %i2, 0x96, %o0
a0128e78:  c0 2a 20 09  clrb  [ %o0 + 9 ]
a0128e7c:  c0 2a 20 01  clrb  [ %o0 + 1 ]
a0128e80:  c0 2e a0 96  clrb  [ %i2 + 0x96 ]
a0128e84:  90 10 20 ff  mov  0xff, %o0
a0128e88:  92 10 20 00  clr  %o1
a0128e8c:  7f fd 97 f8  call  0xa008ee6c
a0128e90:  31 00 00 3f  sethi  %hi(0xfc00), %i0
a0128e94:  7f ff 55 7a  call  0xa00fe47c
a0128e98:  b4 16 22 df  or  %i0, 0x2df, %i2	! 0xfedf
a0128e9c:  b0 0a 00 1a  and  %o0, %i2, %i0
a0128ea0:  7f ff 55 6b  call  0xa00fe44c
a0128ea4:  81 e8 00 00  restore
a0128ea8:  de 0c 20 0f  ldub  [ %l0 + 0xf ], %o7
a0128eac:  b4 10 20 07  mov  7, %i2
a0128eb0:  f4 2c 20 01  stb  %i2, [ %l0 + 1 ]
a0128eb4:  80 a3 e0 00  cmp  %o7, 0
a0128eb8:  c0 34 20 14  clrh  [ %l0 + 0x14 ]
a0128ebc:  02 80 00 06  be  0xa0128ed4
a0128ec0:  c0 2c 20 16  clrb  [ %l0 + 0x16 ]
a0128ec4:  29 00 06 93  sethi  %hi(0x1a4c00), %l4
a0128ec8:  b0 15 21 48  or  %l4, 0x148, %i0	! 0x1a4d48
a0128ecc:  7f fe d8 a9  call  0xa00df170
a0128ed0:  81 e8 00 00  restore
a0128ed4:  7f fe c2 b5  call  0xa00d99a8
a0128ed8:  29 00 06 93  sethi  %hi(0x1a4c00), %l4
a0128edc:  10 bf ff fc  b  0xa0128ecc
a0128ee0:  b0 15 21 48  or  %l4, 0x148, %i0	! 0x1a4d48
a0128ee4:  7f ff f6 08  call  0xa0126704
a0128ee8:  90 10 20 00  clr  %o0
a0128eec:  40 00 7d 85  call  0xa0148500
a0128ef0:  01 00 00 00  nop
a0128ef4:  40 00 7a 0c  call  0xa0147724
a0128ef8:  01 00 00 00  nop
a0128efc:  10 80 00 04  b  0xa0128f0c
a0128f00:  a1 2a 20 10  sll  %o0, 0x10, %l0
a0128f04:  40 00 93 83  call  0xa014dd10
a0128f08:  01 00 00 00  nop
a0128f0c:  40 00 7a 0d  call  0xa0147740
a0128f10:  91 34 20 10  srl  %l0, 0x10, %o0
a0128f14:  97 2a 20 10  sll  %o0, 0x10, %o3
a0128f18:  b1 32 e0 10  srl  %o3, 0x10, %i0
a0128f1c:  80 a6 21 f3  cmp  %i0, 0x1f3
a0128f20:  08 bf ff f9  bleu  0xa0128f04
a0128f24:  29 2a 00 b6  sethi  %hi(0xa802d800), %l4
a0128f28:  9e 10 20 01  mov  1, %o7
a0128f2c:  a0 15 20 90  or  %l4, 0x90, %l0
a0128f30:  c0 2d 20 90  clrb  [ %l4 + 0x90 ]
a0128f34:  de 2c 20 01  stb  %o7, [ %l0 + 1 ]
a0128f38:  7f ff ee 64  call  0xa01248c8
a0128f3c:  01 00 00 00  nop
a0128f40:  80 8a 20 ff  btst  0xff, %o0
a0128f44:  12 80 01 13  bne  0xa0129390
a0128f48:  2b 00 06 91  sethi  %hi(0x1a4400), %l5
a0128f4c:  b2 16 a0 96  or  %i2, 0x96, %i1
a0128f50:  b4 10 20 02  mov  2, %i2
a0128f54:  19 00 06 93  sethi  %hi(0x1a4c00), %o4
a0128f58:  f4 2e 60 01  stb  %i2, [ %i1 + 1 ]
a0128f5c:  7f fe d8 85  call  0xa00df170
a0128f60:  91 eb 21 58  restore  %o4, 0x158, %o0
a0128f64:  e4 23 a0 5c  st  %l2, [ %sp + 0x5c ]
a0128f68:  92 10 20 02  mov  2, %o1
a0128f6c:  94 10 20 08  mov  8, %o2
a0128f70:  96 10 20 05  mov  5, %o3
a0128f74:  98 10 20 00  clr  %o4
a0128f78:  9a 14 20 88  or  %l0, 0x88, %o5
a0128f7c:  40 00 7a db  call  0xa0147ae8
a0128f80:  90 10 20 60  mov  0x60, %o0
a0128f84:  10 bf fc c7  b  0xa01282a0
a0128f88:  c2 0c 20 88  ldub  [ %l0 + 0x88 ], %g1
a0128f8c:  d4 23 a0 5c  st  %o2, [ %sp + 0x5c ]
a0128f90:  92 10 20 02  mov  2, %o1
a0128f94:  94 10 20 08  mov  8, %o2
a0128f98:  96 10 20 05  mov  5, %o3
a0128f9c:  98 10 20 00  clr  %o4
a0128fa0:  9a 14 20 88  or  %l0, 0x88, %o5
a0128fa4:  40 00 7a d1  call  0xa0147ae8
a0128fa8:  90 10 20 60  mov  0x60, %o0
a0128fac:  10 bf fd dc  b  0xa012871c
a0128fb0:  ea 0c 20 88  ldub  [ %l0 + 0x88 ], %l5
a0128fb4:  40 00 72 d1  call  0xa0145af8
a0128fb8:  90 10 20 0d  mov  0xd, %o0
a0128fbc:  99 2a 20 10  sll  %o0, 0x10, %o4
a0128fc0:  b3 33 20 10  srl  %o4, 0x10, %i1
a0128fc4:  40 00 72 cd  call  0xa0145af8
a0128fc8:  90 10 20 0b  mov  0xb, %o0
a0128fcc:  b1 2e 60 04  sll  %i1, 4, %i0
a0128fd0:  aa 26 00 19  sub  %i0, %i1, %l5
a0128fd4:  a9 2a 20 10  sll  %o0, 0x10, %l4
a0128fd8:  a5 2d 60 02  sll  %l5, 2, %l2
a0128fdc:  a7 35 20 10  srl  %l4, 0x10, %l3
a0128fe0:  a0 04 80 13  add  %l2, %l3, %l0
a0128fe4:  80 a4 20 13  cmp  %l0, 0x13
a0128fe8:  14 bf ff 38  bg  0xa0128cc8
a0128fec:  82 10 20 01  mov  1, %g1
a0128ff0:  10 bf ff 36  b  0xa0128cc8
a0128ff4:  82 10 20 00  clr  %g1
a0128ff8:  90 10 20 05  mov  5, %o0
a0128ffc:  29 2a 00 b6  sethi  %hi(0xa802d800), %l4
a0129000:  d0 2e a0 01  stb  %o0, [ %i2 + 1 ]
a0129004:  a0 15 20 90  or  %l4, 0x90, %l0
a0129008:  b4 10 20 01  mov  1, %i2
a012900c:  c0 2d 20 90  clrb  [ %l4 + 0x90 ]
a0129010:  7f ff ee 2e  call  0xa01248c8
a0129014:  f4 2c 20 01  stb  %i2, [ %l0 + 1 ]
a0129018:  80 8a 20 ff  btst  0xff, %o0
a012901c:  12 80 00 05  bne  0xa0129030
a0129020:  19 00 06 93  sethi  %hi(0x1a4c00), %o4
a0129024:  b0 13 21 68  or  %o4, 0x168, %i0	! 0x1a4d68
a0129028:  7f fe d8 52  call  0xa00df170
a012902c:  81 e8 00 00  restore
a0129030:  33 00 06 91  sethi  %hi(0x1a4400), %i1
a0129034:  92 10 20 01  mov  1, %o1
a0129038:  7f fe d8 4e  call  0xa00df170
a012903c:  90 16 61 68  or  %i1, 0x168, %o0
a0129040:  aa 10 20 02  mov  2, %l5
a0129044:  a6 10 20 01  mov  1, %l3
a0129048:  98 10 20 00  clr  %o4
a012904c:  ea 23 a0 5c  st  %l5, [ %sp + 0x5c ]
a0129050:  e6 23 a0 60  st  %l3, [ %sp + 0x60 ]
a0129054:  9a 10 00 10  mov  %l0, %o5
a0129058:  90 10 20 60  mov  0x60, %o0
a012905c:  92 10 20 02  mov  2, %o1
a0129060:  94 10 20 c2  mov  0xc2, %o2
a0129064:  40 00 7a 8f  call  0xa0147aa0
a0129068:  96 10 20 05  mov  5, %o3
a012906c:  19 00 06 93  sethi  %hi(0x1a4c00), %o4
a0129070:  10 bf ff ee  b  0xa0129028
a0129074:  b0 13 21 68  or  %o4, 0x168, %i0	! 0x1a4d68
a0129078:  ea 23 a0 5c  st  %l5, [ %sp + 0x5c ]
a012907c:  92 10 20 02  mov  2, %o1
a0129080:  94 10 20 08  mov  8, %o2
a0129084:  96 10 20 05  mov  5, %o3
a0129088:  98 10 20 00  clr  %o4
a012908c:  9a 14 20 88  or  %l0, 0x88, %o5
a0129090:  40 00 7a 96  call  0xa0147ae8
a0129094:  90 10 20 60  mov  0x60, %o0
a0129098:  10 bf fd 20  b  0xa0128518
a012909c:  d6 0c 20 88  ldub  [ %l0 + 0x88 ], %o3
a01290a0:  7f ff ee 84  call  0xa0124ab0
a01290a4:  01 00 00 00  nop
a01290a8:  30 bf ff 63  b,a   0xa0128e34
a01290ac:  94 10 20 00  clr  %o2	! 0x0
a01290b0:  90 10 20 00  clr  %o0
a01290b4:  7f fe c6 e1  call  0xa00dac38
a01290b8:  92 10 20 01  mov  1, %o1
a01290bc:  90 10 20 00  clr  %o0
a01290c0:  40 00 7c 6a  call  0xa0148268
a01290c4:  92 10 20 03  mov  3, %o1
a01290c8:  90 10 20 01  mov  1, %o0
a01290cc:  40 00 7c 67  call  0xa0148268
a01290d0:  92 10 20 03  mov  3, %o1
a01290d4:  10 bf fb 25  b  0xa0127d68
a01290d8:  a0 16 a0 96  or  %i2, 0x96, %l0
a01290dc:  10 bf fb 16  b  0xa0127d34
a01290e0:  c0 2a 61 e5  clrb  [ %o1 + 0x1e5 ]
a01290e4:  2b 00 06 93  sethi  %hi(0x1a4c00), %l5
a01290e8:  7f fe d8 22  call  0xa00df170
a01290ec:  90 15 61 78  or  %l5, 0x178, %o0	! 0x1a4d78
a01290f0:  90 10 20 0d  mov  0xd, %o0
a01290f4:  40 00 72 da  call  0xa0145c5c
a01290f8:  92 10 20 00  clr  %o1
a01290fc:  90 10 20 0b  mov  0xb, %o0
a0129100:  40 00 72 d7  call  0xa0145c5c
a0129104:  92 10 20 00  clr  %o1
a0129108:  40 00 72 7c  call  0xa0145af8
a012910c:  90 10 20 11  mov  0x11, %o0
a0129110:  a9 2a 20 10  sll  %o0, 0x10, %l4
a0129114:  80 a5 20 00  cmp  %l4, 0
a0129118:  12 80 00 0a  bne  0xa0129140
a012911c:  92 10 20 00  clr  %o1
a0129120:  40 00 72 76  call  0xa0145af8
a0129124:  90 10 20 0f  mov  0xf, %o0
a0129128:  a6 02 20 01  add  %o0, 1, %l3
a012912c:  99 2c e0 10  sll  %l3, 0x10, %o4
a0129130:  93 33 20 10  srl  %o4, 0x10, %o1
a0129134:  40 00 72 ca  call  0xa0145c5c
a0129138:  90 10 20 0f  mov  0xf, %o0
a012913c:  92 10 20 00  clr  %o1
a0129140:  40 00 72 c7  call  0xa0145c5c
a0129144:  90 10 20 11  mov  0x11, %o0
a0129148:  40 00 70 86  call  0xa0145360
a012914c:  90 10 20 01  mov  1, %o0
a0129150:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0129154:  b2 13 62 90  or  %o5, 0x290, %i1	! 0xa802d290
a0129158:  d2 0e 61 e4  ldub  [ %i1 + 0x1e4 ], %o1
a012915c:  80 a2 60 01  cmp  %o1, 1
a0129160:  c0 2e 61 e6  clrb  [ %i1 + 0x1e6 ]
a0129164:  12 80 00 03  bne  0xa0129170
a0129168:  c0 2e 61 e2  clrb  [ %i1 + 0x1e2 ]
a012916c:  c0 2e 61 e4  clrb  [ %i1 + 0x1e4 ]
a0129170:  94 10 20 00  clr  %o2
a0129174:  96 10 21 fc  mov  0x1fc, %o3
a0129178:  92 10 00 19  mov  %i1, %o1
a012917c:  40 00 87 55  call  0xa014aed0
a0129180:  90 10 20 30  mov  0x30, %o0
a0129184:  67 fd 91 01  call  0x4008d588
a0129188:  c0 2c 20 09  clrb  [ %l0 + 9 ]
a012918c:  a4 10 20 02  mov  2, %l2
a0129190:  e4 2c 20 11  stb  %l2, [ %l0 + 0x11 ]
a0129194:  d0 34 20 04  sth  %o0, [ %l0 + 4 ]
a0129198:  40 00 6b 04  call  0xa0143da8
a012919c:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a01291a0:  b0 14 a3 f4  or  %l2, 0x3f4, %i0	! 0xa802cff4
a01291a4:  de 16 20 04  lduh  [ %i0 + 4 ], %o7
a01291a8:  03 00 00 18  sethi  %hi(0x6000), %g1
a01291ac:  96 08 40 0f  and  %g1, %o7, %o3
a01291b0:  15 00 00 10  sethi  %hi(0x4000), %o2
a01291b4:  80 a2 c0 0a  cmp  %o3, %o2
a01291b8:  02 80 00 b0  be  0xa0129478
a01291bc:  1f 2a 00 b6  sethi  %hi(0xa802d800), %o7
a01291c0:  c0 2c 20 01  clrb  [ %l0 + 1 ]
a01291c4:  c0 2b e0 96  clrb  [ %o7 + 0x96 ]
a01291c8:  b0 10 20 03  mov  3, %i0
a01291cc:  7f fd 63 37  call  0xa0081ea8
a01291d0:  81 e8 00 00  restore
a01291d4:  40 00 72 49  call  0xa0145af8
a01291d8:  90 10 20 0d  mov  0xd, %o0
a01291dc:  1b 00 06 93  sethi  %hi(0x1a4c00), %o5
a01291e0:  93 2a 20 10  sll  %o0, 0x10, %o1
a01291e4:  93 32 60 10  srl  %o1, 0x10, %o1
a01291e8:  7f fe d7 e2  call  0xa00df170
a01291ec:  90 13 61 a0  or  %o5, 0x1a0, %o0
a01291f0:  40 00 72 42  call  0xa0145af8
a01291f4:  90 10 20 10  mov  0x10, %o0
a01291f8:  a1 2a 20 10  sll  %o0, 0x10, %l0
a01291fc:  80 a4 20 00  cmp  %l0, 0
a0129200:  12 80 00 53  bne  0xa012934c
a0129204:  01 00 00 00  nop
a0129208:  40 00 72 3c  call  0xa0145af8
a012920c:  90 10 20 0d  mov  0xd, %o0	! 0xd
a0129210:  83 2a 20 10  sll  %o0, 0x10, %g1
a0129214:  97 30 60 10  srl  %g1, 0x10, %o3
a0129218:  80 a2 e0 04  cmp  %o3, 4
a012921c:  82 60 3f ff  subx  %g0, -1, %g1
a0129220:  b0 08 60 ff  and  %g1, 0xff, %i0
a0129224:  94 0e 20 ff  and  %i0, 0xff, %o2
a0129228:  80 a2 a0 01  cmp  %o2, 1
a012922c:  02 80 00 85  be  0xa0129440
a0129230:  27 2a 00 b3  sethi  %hi(0xa802cc00), %l3
a0129234:  d8 14 e3 f8  lduh  [ %l3 + 0x3f8 ], %o4	! 0xa802cff8
a0129238:  33 00 00 18  sethi  %hi(0x6000), %i1
a012923c:  aa 0e 40 0c  and  %i1, %o4, %l5
a0129240:  29 00 00 10  sethi  %hi(0x4000), %l4
a0129244:  80 a5 40 14  cmp  %l5, %l4
a0129248:  02 80 00 7a  be  0xa0129430
a012924c:  31 00 06 93  sethi  %hi(0x1a4c00), %i0
a0129250:  7f fd 63 16  call  0xa0081ea8
a0129254:  90 10 20 03  mov  3, %o0
a0129258:  15 00 06 93  sethi  %hi(0x1a4c00), %o2
a012925c:  7f fe d7 c5  call  0xa00df170
a0129260:  90 12 a1 e0  or  %o2, 0x1e0, %o0	! 0x1a4de0
a0129264:  10 bf fa df  b  0xa0127de0
a0129268:  a0 16 a0 96  or  %i2, 0x96, %l0
a012926c:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a0129270:  d8 16 23 f8  lduh  [ %i0 + 0x3f8 ], %o4	! 0xa802cff8
a0129274:  21 00 00 18  sethi  %hi(0x6000), %l0
a0129278:  a4 0c 00 0c  and  %l0, %o4, %l2
a012927c:  33 00 00 10  sethi  %hi(0x4000), %i1
a0129280:  80 a4 80 19  cmp  %l2, %i1
a0129284:  02 80 00 53  be  0xa01293d0
a0129288:  03 00 06 93  sethi  %hi(0x1a4c00), %g1
a012928c:  7f fd 63 07  call  0xa0081ea8
a0129290:  90 10 20 03  mov  3, %o0
a0129294:  90 10 20 00  clr  %o0
a0129298:  40 00 6f a5  call  0xa014512c
a012929c:  92 10 20 01  mov  1, %o1
a01292a0:  10 bf fc 70  b  0xa0128460
a01292a4:  94 16 a0 96  or  %i2, 0x96, %o2
a01292a8:  10 bf fc 66  b  0xa0128440
a01292ac:  c0 2a 61 e5  clrb  [ %o1 + 0x1e5 ]
a01292b0:  f4 23 a0 5c  st  %i2, [ %sp + 0x5c ]
a01292b4:  92 10 20 02  mov  2, %o1
a01292b8:  94 10 20 08  mov  8, %o2
a01292bc:  96 10 20 05  mov  5, %o3
a01292c0:  98 10 20 00  clr  %o4
a01292c4:  9a 10 00 19  mov  %i1, %o5
a01292c8:  40 00 7a 08  call  0xa0147ae8
a01292cc:  90 10 20 60  mov  0x60, %o0
a01292d0:  10 bf fc 15  b  0xa0128324
a01292d4:  31 2a 00 b6  sethi  %hi(0xa802d800), %i0
a01292d8:  10 bf fe cb  b  0xa0128e04
a01292dc:  c0 2c 21 e4  clrb  [ %l0 + 0x1e4 ]
a01292e0:  40 00 72 06  call  0xa0145af8
a01292e4:  90 10 20 0f  mov  0xf, %o0
a01292e8:  92 02 20 01  add  %o0, 1, %o1
a01292ec:  a7 2a 60 10  sll  %o1, 0x10, %l3
a01292f0:  93 34 e0 10  srl  %l3, 0x10, %o1
a01292f4:  40 00 72 5a  call  0xa0145c5c
a01292f8:  90 10 20 0f  mov  0xf, %o0
a01292fc:  10 bf fe b8  b  0xa0128ddc
a0129300:  90 10 20 11  mov  0x11, %o0
a0129304:  80 a3 e0 00  cmp  %o7, 0
a0129308:  22 bf fe dc  be,a   0xa0128e78
a012930c:  90 16 a0 96  or  %i2, 0x96, %o0
a0129310:  90 10 20 01  mov  1, %o0
a0129314:  40 00 6f 86  call  0xa014512c
a0129318:  92 10 20 00  clr  %o1
a012931c:  10 bf fe d7  b  0xa0128e78
a0129320:  90 16 a0 96  or  %i2, 0x96, %o0
a0129324:  f2 23 a0 5c  st  %i1, [ %sp + 0x5c ]
a0129328:  92 10 20 02  mov  2, %o1
a012932c:  94 10 20 08  mov  8, %o2
a0129330:  96 10 20 05  mov  5, %o3
a0129334:  98 10 20 00  clr  %o4
a0129338:  9a 10 00 12  mov  %l2, %o5
a012933c:  40 00 79 eb  call  0xa0147ae8
a0129340:  90 10 20 60  mov  0x60, %o0
a0129344:  10 bf fd 1b  b  0xa01287b0
a0129348:  15 2a 00 b6  sethi  %hi(0xa802d800), %o2
a012934c:  40 00 71 eb  call  0xa0145af8
a0129350:  90 10 20 0d  mov  0xd, %o0
a0129354:  a7 2a 20 10  sll  %o0, 0x10, %l3
a0129358:  99 34 e0 10  srl  %l3, 0x10, %o4
a012935c:  b3 2b 20 04  sll  %o4, 4, %i1
a0129360:  aa 26 40 0c  sub  %i1, %o4, %l5
a0129364:  40 00 71 e5  call  0xa0145af8
a0129368:  90 10 20 0b  mov  0xb, %o0
a012936c:  a9 2a 20 10  sll  %o0, 0x10, %l4
a0129370:  a5 2d 60 02  sll  %l5, 2, %l2
a0129374:  91 35 20 10  srl  %l4, 0x10, %o0
a0129378:  9e 04 80 08  add  %l2, %o0, %o7
a012937c:  80 a3 e0 13  cmp  %o7, 0x13
a0129380:  14 bf ff a8  bg  0xa0129220
a0129384:  82 10 20 01  mov  1, %g1
a0129388:  10 bf ff a6  b  0xa0129220
a012938c:  82 10 20 00  clr  %g1
a0129390:  90 15 61 40  or  %l5, 0x140, %o0
a0129394:  7f fe d7 77  call  0xa00df170
a0129398:  92 10 20 01  mov  1, %o1
a012939c:  90 10 20 01  mov  1, %o0
a01293a0:  a6 10 20 02  mov  2, %l3
a01293a4:  d0 23 a0 60  st  %o0, [ %sp + 0x60 ]
a01293a8:  e6 23 a0 5c  st  %l3, [ %sp + 0x5c ]
a01293ac:  9a 10 00 10  mov  %l0, %o5
a01293b0:  92 10 20 02  mov  2, %o1
a01293b4:  94 10 20 c0  mov  0xc0, %o2
a01293b8:  96 10 20 05  mov  5, %o3
a01293bc:  98 10 20 00  clr  %o4
a01293c0:  40 00 79 b8  call  0xa0147aa0
a01293c4:  90 10 20 60  mov  0x60, %o0
a01293c8:  10 bf fe e2  b  0xa0128f50
a01293cc:  b2 16 a0 96  or  %i2, 0x96, %i1
a01293d0:  7f fe d7 68  call  0xa00df170
a01293d4:  90 10 61 f8  or  %g1, 0x1f8, %o0
a01293d8:  7f ff ed b6  call  0xa0124ab0
a01293dc:  01 00 00 00  nop
a01293e0:  7f ff ed c6  call  0xa0124af8
a01293e4:  01 00 00 00  nop
a01293e8:  7f ff f1 b8  call  0xa0125ac8
a01293ec:  01 00 00 00  nop
a01293f0:  7f fd 9e fa  call  0xa0090fd8
a01293f4:  01 00 00 00  nop
a01293f8:  90 10 20 00  clr  %o0	! 0x0
a01293fc:  40 00 6f 4c  call  0xa014512c
a0129400:  92 10 20 01  mov  1, %o1
a0129404:  92 10 20 00  clr  %o1
a0129408:  7f fd 96 99  call  0xa008ee6c
a012940c:  90 10 20 ff  mov  0xff, %o0
a0129410:  7f ff 54 1b  call  0xa00fe47c
a0129414:  01 00 00 00  nop
a0129418:  1b 00 00 3f  sethi  %hi(0xfc00), %o5
a012941c:  92 13 62 df  or  %o5, 0x2df, %o1	! 0xfedf
a0129420:  7f ff 54 0b  call  0xa00fe44c
a0129424:  90 0a 00 09  and  %o0, %o1, %o0
a0129428:  10 bf fc 0e  b  0xa0128460
a012942c:  94 16 a0 96  or  %i2, 0x96, %o2
a0129430:  7f fe d7 50  call  0xa00df170
a0129434:  90 16 21 c0  or  %i0, 0x1c0, %o0
a0129438:  10 bf ff 89  b  0xa012925c
a012943c:  15 00 06 93  sethi  %hi(0x1a4c00), %o2
a0129440:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a0129444:  a0 12 e3 f4  or  %o3, 0x3f4, %l0	! 0xa802cff4
a0129448:  d0 14 20 04  lduh  [ %l0 + 4 ], %o0
a012944c:  25 00 00 18  sethi  %hi(0x6000), %l2
a0129450:  9a 16 a0 96  or  %i2, 0x96, %o5
a0129454:  82 2a 00 12  andn  %o0, %l2, %g1
a0129458:  d4 2b 60 12  stb  %o2, [ %o5 + 0x12 ]
a012945c:  1f 00 00 10  sethi  %hi(0x4000), %o7
a0129460:  92 10 40 0f  or  %g1, %o7, %o1
a0129464:  15 00 06 93  sethi  %hi(0x1a4c00), %o2
a0129468:  d2 34 20 04  sth  %o1, [ %l0 + 4 ]
a012946c:  7f fe d7 41  call  0xa00df170
a0129470:  90 12 a2 08  or  %o2, 0x208, %o0
a0129474:  30 bf ff 77  b,a   0xa0129250
a0129478:  11 00 06 93  sethi  %hi(0x1a4c00), %o0
a012947c:  7f fe d7 3d  call  0xa00df170
a0129480:  90 12 21 f8  or  %o0, 0x1f8, %o0	! 0x1a4df8
a0129484:  40 00 69 e4  call  0xa0143c14
a0129488:  90 10 20 00  clr  %o0
a012948c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0129490:  80 a4 20 04  cmp  %l0, 4
a0129494:  28 80 00 2f  bleu,a   0xa0129550
a0129498:  da 06 61 f4  ld  [ %i1 + 0x1f4 ], %o5
a012949c:  e8 06 61 f4  ld  [ %i1 + 0x1f4 ], %l4
a01294a0:  33 10 00 00  sethi  %hi(0x40000000), %i1
a01294a4:  80 8d 00 19  btst  %l4, %i1
a01294a8:  02 80 00 27  be  0xa0129544
a01294ac:  01 00 00 00  nop
a01294b0:  7f ff ed 6e  call  0xa0124a68
a01294b4:  01 00 00 00  nop
a01294b8:  7f ff ed a2  call  0xa0124b40
a01294bc:  aa 14 a3 f4  or  %l2, 0x3f4, %l5
a01294c0:  7f ff f1 7b  call  0xa0125aac
a01294c4:  27 00 00 18  sethi  %hi(0x6000), %l3
a01294c8:  d2 15 60 04  lduh  [ %l5 + 4 ], %o1
a01294cc:  98 2a 40 13  andn  %o1, %l3, %o4
a01294d0:  d8 35 60 04  sth  %o4, [ %l5 + 4 ]
a01294d4:  7f fd 9e c1  call  0xa0090fd8
a01294d8:  b0 10 20 03  mov  3, %i0
a01294dc:  90 10 20 00  clr  %o0
a01294e0:  40 00 6f 13  call  0xa014512c
a01294e4:  92 10 20 01  mov  1, %o1
a01294e8:  82 16 a0 96  or  %i2, 0x96, %g1
a01294ec:  c0 28 60 01  clrb  [ %g1 + 1 ]
a01294f0:  92 10 20 00  clr  %o1
a01294f4:  c0 2e a0 96  clrb  [ %i2 + 0x96 ]
a01294f8:  7f fd 96 5d  call  0xa008ee6c
a01294fc:  90 10 20 ff  mov  0xff, %o0
a0129500:  7f ff 53 df  call  0xa00fe47c
a0129504:  01 00 00 00  nop
a0129508:  17 00 00 3f  sethi  %hi(0xfc00), %o3
a012950c:  b4 12 e2 df  or  %o3, 0x2df, %i2	! 0xfedf
a0129510:  7f ff 53 cf  call  0xa00fe44c
a0129514:  90 0a 00 1a  and  %o0, %i2, %o0
a0129518:  30 bf ff 2d  b,a   0xa01291cc
a012951c:  10 bf fa fd  b  0xa0128110
a0129520:  c0 2a 61 e4  clrb  [ %o1 + 0x1e4 ]
a0129524:  aa 14 22 90  or  %l0, 0x290, %l5
a0129528:  29 00 00 15  sethi  %hi(0x5400), %l4
a012952c:  f2 15 61 f6  lduh  [ %l5 + 0x1f6 ], %i1
a0129530:  90 15 21 aa  or  %l4, 0x1aa, %o0
a0129534:  80 a6 40 08  cmp  %i1, %o0
a0129538:  12 bf fa e4  bne  0xa01280c8
a012953c:  92 10 20 00  clr  %o1
a0129540:  30 bf fa ea  b,a   0xa01280e8
a0129544:  7f ff ed 5b  call  0xa0124ab0
a0129548:  01 00 00 00  nop
a012954c:  30 bf ff db  b,a   0xa01294b8
a0129550:  15 10 00 00  sethi  %hi(0x40000000), %o2
a0129554:  80 8b 40 0a  btst  %o5, %o2
a0129558:  02 80 00 09  be  0xa012957c
a012955c:  01 00 00 00  nop
a0129560:  7f ff ed 54  call  0xa0124ab0
a0129564:  01 00 00 00  nop
a0129568:  7f ff ed 64  call  0xa0124af8
a012956c:  01 00 00 00  nop
a0129570:  7f ff f1 56  call  0xa0125ac8
a0129574:  01 00 00 00  nop
a0129578:  30 bf ff d7  b,a   0xa01294d4
a012957c:  7f ff ed 4d  call  0xa0124ab0
a0129580:  01 00 00 00  nop
a0129584:  7f ff ed 6f  call  0xa0124b40
a0129588:  01 00 00 00  nop
a012958c:  30 bf ff f9  b,a   0xa0129570
a0129590:  81 c7 e0 08  ret
a0129594:  81 e8 00 00  restore
