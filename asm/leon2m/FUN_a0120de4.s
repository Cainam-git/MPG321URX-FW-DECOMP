# leon2m FUN_a0120de4 0xa0120de4-0xa01211ac (968 bytes)
a0120de4:  9d e3 bf 98  save  %sp, -104, %sp
a0120de8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0120dec:  80 a6 20 71  cmp  %i0, 0x71
a0120df0:  02 80 00 21  be  0xa0120e74
a0120df4:  a0 10 20 01  mov  1, %l0
a0120df8:  80 a6 20 71  cmp  %i0, 0x71
a0120dfc:  14 80 00 11  bg  0xa0120e40
a0120e00:  80 a6 20 b1  cmp  %i0, 0xb1
a0120e04:  80 a6 20 21  cmp  %i0, 0x21
a0120e08:  22 80 00 52  be,a   0xa0120f50
a0120e0c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0120e10:  14 80 00 21  bg  0xa0120e94
a0120e14:  80 a6 20 41  cmp  %i0, 0x41
a0120e18:  80 a6 20 12  cmp  %i0, 0x12
a0120e1c:  02 80 00 87  be  0xa0121038
a0120e20:  92 10 20 11  mov  0x11, %o1
a0120e24:  14 80 00 48  bg  0xa0120f44
a0120e28:  80 a6 20 13  cmp  %i0, 0x13
a0120e2c:  80 a6 20 11  cmp  %i0, 0x11
a0120e30:  22 80 00 68  be,a   0xa0120fd0
a0120e34:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0120e38:  10 80 00 db  b  0xa01211a4
a0120e3c:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0120e40:  02 80 00 38  be  0xa0120f20
a0120e44:  90 0e 60 ff  and  %i1, 0xff, %o0
a0120e48:  80 a6 20 b1  cmp  %i0, 0xb1
a0120e4c:  14 80 00 2b  bg  0xa0120ef8
a0120e50:  80 a6 20 e2  cmp  %i0, 0xe2
a0120e54:  80 a6 20 91  cmp  %i0, 0x91
a0120e58:  22 80 00 d2  be,a   0xa01211a0
a0120e5c:  a0 10 20 05  mov  5, %l0
a0120e60:  14 80 00 58  bg  0xa0120fc0
a0120e64:  80 a6 20 a1  cmp  %i0, 0xa1
a0120e68:  80 a6 20 81  cmp  %i0, 0x81
a0120e6c:  32 80 00 cd  bne,a   0xa01211a0
a0120e70:  a0 10 20 01  mov  1, %l0
a0120e74:  90 0e 60 ff  and  %i1, 0xff, %o0
a0120e78:  7f ff 44 49  call  0xa00f1f9c
a0120e7c:  92 10 20 11  mov  0x11, %o1
a0120e80:  80 8a 20 c0  btst  0xc0, %o0
a0120e84:  12 80 00 c8  bne  0xa01211a4
a0120e88:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0120e8c:  10 80 00 c5  b  0xa01211a0
a0120e90:  a0 10 20 05  mov  5, %l0
a0120e94:  02 80 00 07  be  0xa0120eb0
a0120e98:  80 a6 20 41  cmp  %i0, 0x41
a0120e9c:  14 80 00 43  bg  0xa0120fa8
a0120ea0:  80 a6 20 51  cmp  %i0, 0x51
a0120ea4:  80 a6 20 31  cmp  %i0, 0x31
a0120ea8:  32 80 00 be  bne,a   0xa01211a0
a0120eac:  a0 10 20 01  mov  1, %l0
a0120eb0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0120eb4:  a2 06 40 19  add  %i1, %i1, %l1
a0120eb8:  94 04 40 19  add  %l1, %i1, %o2
a0120ebc:  17 2a 00 9e  sethi  %hi(0xa8027800), %o3
a0120ec0:  a2 12 e2 ac  or  %o3, 0x2ac, %l1	! 0xa8027aac
a0120ec4:  b1 2a a0 02  sll  %o2, 2, %i0
a0120ec8:  d2 04 40 18  ld  [ %l1 + %i0 ], %o1
a0120ecc:  80 a2 60 01  cmp  %o1, 1
a0120ed0:  02 80 00 4f  be  0xa012100c
a0120ed4:  90 10 00 19  mov  %i1, %o0
a0120ed8:  7f ff 44 31  call  0xa00f1f9c
a0120edc:  92 10 20 11  mov  0x11, %o1
a0120ee0:  90 0a 20 18  and  %o0, 0x18, %o0
a0120ee4:  80 a2 20 18  cmp  %o0, 0x18
a0120ee8:  12 80 00 af  bne  0xa01211a4
a0120eec:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0120ef0:  10 80 00 ac  b  0xa01211a0
a0120ef4:  a0 10 20 05  mov  5, %l0
a0120ef8:  14 80 00 0f  bg  0xa0120f34
a0120efc:  80 a6 20 e8  cmp  %i0, 0xe8
a0120f00:  80 a6 20 e1  cmp  %i0, 0xe1
a0120f04:  16 80 00 07  bge  0xa0120f20
a0120f08:  90 0e 60 ff  and  %i1, 0xff, %o0
a0120f0c:  80 a6 20 c1  cmp  %i0, 0xc1
a0120f10:  32 80 00 a4  bne,a   0xa01211a0
a0120f14:  a0 10 20 01  mov  1, %l0
a0120f18:  10 80 00 a3  b  0xa01211a4
a0120f1c:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0120f20:  7f ff 44 1f  call  0xa00f1f9c
a0120f24:  92 10 20 11  mov  0x11, %o1
a0120f28:  90 0a 20 d8  and  %o0, 0xd8, %o0
a0120f2c:  10 bf ff ef  b  0xa0120ee8
a0120f30:  80 a2 20 18  cmp  %o0, 0x18
a0120f34:  32 80 00 9b  bne,a   0xa01211a0
a0120f38:  a0 10 20 01  mov  1, %l0
a0120f3c:  10 80 00 99  b  0xa01211a0
a0120f40:  a0 10 20 02  mov  2, %l0
a0120f44:  32 80 00 97  bne,a   0xa01211a0
a0120f48:  a0 10 20 01  mov  1, %l0
a0120f4c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0120f50:  90 10 00 19  mov  %i1, %o0
a0120f54:  7f ff 44 12  call  0xa00f1f9c
a0120f58:  92 10 20 11  mov  0x11, %o1
a0120f5c:  94 0a 20 e0  and  %o0, 0xe0, %o2
a0120f60:  80 a2 a0 20  cmp  %o2, 0x20
a0120f64:  12 80 00 90  bne  0xa01211a4
a0120f68:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0120f6c:  90 10 00 19  mov  %i1, %o0
a0120f70:  7f ff 44 0b  call  0xa00f1f9c
a0120f74:  92 10 20 23  mov  0x23, %o1
a0120f78:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0120f7c:  9a 03 ff ff  add  %o7, -1, %o5
a0120f80:  99 2b 60 10  sll  %o5, 0x10, %o4
a0120f84:  97 33 20 10  srl  %o4, 0x10, %o3
a0120f88:  80 a2 e0 0e  cmp  %o3, 0xe
a0120f8c:  08 80 00 30  bleu  0xa012104c
a0120f90:  82 10 20 00  clr  %g1
a0120f94:  80 a0 00 01  cmp  %g0, %g1
a0120f98:  b0 40 3f ff  addx  %g0, -1, %i0
a0120f9c:  90 0e 3f fd  and  %i0, -3, %o0
a0120fa0:  10 80 00 80  b  0xa01211a0
a0120fa4:  a0 02 20 04  add  %o0, 4, %l0
a0120fa8:  02 bf ff c2  be  0xa0120eb0
a0120fac:  80 a6 20 61  cmp  %i0, 0x61
a0120fb0:  32 80 00 7c  bne,a   0xa01211a0
a0120fb4:  a0 10 20 01  mov  1, %l0
a0120fb8:  10 bf ff bf  b  0xa0120eb4
a0120fbc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0120fc0:  32 80 00 78  bne,a   0xa01211a0
a0120fc4:  a0 10 20 01  mov  1, %l0
a0120fc8:  10 80 00 76  b  0xa01211a0
a0120fcc:  a0 10 20 05  mov  5, %l0
a0120fd0:  90 10 00 19  mov  %i1, %o0
a0120fd4:  7f ff 43 f2  call  0xa00f1f9c
a0120fd8:  92 10 20 11  mov  0x11, %o1
a0120fdc:  90 0a 20 f8  and  %o0, 0xf8, %o0
a0120fe0:  80 a2 20 18  cmp  %o0, 0x18
a0120fe4:  02 bf ff d6  be  0xa0120f3c
a0120fe8:  90 10 00 19  mov  %i1, %o0
a0120fec:  7f ff 43 ec  call  0xa00f1f9c
a0120ff0:  92 10 20 11  mov  0x11, %o1
a0120ff4:  82 0a 20 f8  and  %o0, 0xf8, %g1
a0120ff8:  80 a0 60 38  cmp  %g1, 0x38
a0120ffc:  22 80 00 69  be,a   0xa01211a0
a0121000:  a0 10 20 03  mov  3, %l0
a0121004:  10 80 00 68  b  0xa01211a4
a0121008:  b0 0c 20 ff  and  %l0, 0xff, %i0
a012100c:  7f ff 43 e4  call  0xa00f1f9c
a0121010:  92 10 20 11  mov  0x11, %o1
a0121014:  80 8a 20 c0  btst  0xc0, %o0
a0121018:  22 80 00 62  be,a   0xa01211a0
a012101c:  a0 10 20 05  mov  5, %l0
a0121020:  c2 04 40 18  ld  [ %l1 + %i0 ], %g1
a0121024:  80 a0 60 01  cmp  %g1, 1
a0121028:  12 bf ff ac  bne  0xa0120ed8
a012102c:  90 10 00 19  mov  %i1, %o0
a0121030:  10 80 00 5d  b  0xa01211a4
a0121034:  b0 0c 20 ff  and  %l0, 0xff, %i0
a0121038:  7f ff 43 d9  call  0xa00f1f9c
a012103c:  90 0e 60 ff  and  %i1, 0xff, %o0
a0121040:  92 0a 20 f8  and  %o0, 0xf8, %o1
a0121044:  10 bf ff ee  b  0xa0120ffc
a0121048:  80 a2 60 28  cmp  %o1, 0x28
a012104c:  92 10 20 22  mov  0x22, %o1
a0121050:  7f ff 43 d3  call  0xa00f1f9c
a0121054:  90 10 00 19  mov  %i1, %o0
a0121058:  b0 0a 20 ff  and  %o0, 0xff, %i0
a012105c:  92 10 20 12  mov  0x12, %o1
a0121060:  7f ff 44 64  call  0xa00f21f0
a0121064:  90 10 00 19  mov  %i1, %o0
a0121068:  19 00 00 07  sethi  %hi(0x1c00), %o4
a012106c:  a2 13 23 ff  or  %o4, 0x3ff, %l1	! 0x1fff
a0121070:  17 2a aa aa  sethi  %hi(0xaaaaa800), %o3
a0121074:  94 0a 00 11  and  %o0, %l1, %o2
a0121078:  82 12 e2 ab  or  %o3, 0x2ab, %g1
a012107c:  80 52 80 01  umul  %o2, %g1, %g0
a0121080:  93 40 00 00  rd  %y, %o1
a0121084:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0121088:  91 2a 60 0b  sll  %o1, 0xb, %o0
a012108c:  b1 32 20 10  srl  %o0, 0x10, %i0
a0121090:  80 a4 00 18  cmp  %l0, %i0
a0121094:  18 bf ff c0  bgu  0xa0120f94
a0121098:  82 10 20 00  clr  %g1
a012109c:  90 10 00 19  mov  %i1, %o0
a01210a0:  7f ff 44 54  call  0xa00f21f0
a01210a4:  92 10 20 12  mov  0x12, %o1
a01210a8:  b0 0c 40 08  and  %l1, %o0, %i0
a01210ac:  80 a6 22 80  cmp  %i0, 0x280
a01210b0:  a0 60 20 00  subx  %g0, 0, %l0
a01210b4:  90 1e 00 11  xor  %i0, %l1, %o0
a01210b8:  80 a0 00 08  cmp  %g0, %o0
a01210bc:  9a 0c 20 01  and  %l0, 1, %o5
a01210c0:  9e 60 3f ff  subx  %g0, -1, %o7
a01210c4:  80 93 40 0f  orcc  %o5, %o7, %g0
a01210c8:  12 bf ff b3  bne  0xa0120f94
a01210cc:  82 10 20 00  clr  %g1
a01210d0:  92 10 20 14  mov  0x14, %o1
a01210d4:  7f ff 44 47  call  0xa00f21f0
a01210d8:  90 10 00 19  mov  %i1, %o0
a01210dc:  96 0c 40 08  and  %l1, %o0, %o3
a01210e0:  80 a2 e2 00  cmp  %o3, 0x200
a01210e4:  82 1a c0 11  xor  %o3, %l1, %g1
a01210e8:  94 60 20 00  subx  %g0, 0, %o2
a01210ec:  80 a0 00 01  cmp  %g0, %g1
a01210f0:  92 0a a0 01  and  %o2, 1, %o1
a01210f4:  a2 60 3f ff  subx  %g0, -1, %l1
a01210f8:  80 92 40 11  orcc  %o1, %l1, %g0
a01210fc:  12 bf ff a6  bne  0xa0120f94
a0121100:  82 10 20 00  clr  %g1
a0121104:  92 10 20 22  mov  0x22, %o1
a0121108:  7f ff 43 a5  call  0xa00f1f9c
a012110c:  90 10 00 19  mov  %i1, %o0
a0121110:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0121114:  90 10 00 19  mov  %i1, %o0
a0121118:  7f ff 44 36  call  0xa00f21f0
a012111c:  92 10 20 26  mov  0x26, %o1
a0121120:  98 02 20 01  add  %o0, 1, %o4
a0121124:  b3 2b 20 10  sll  %o4, 0x10, %i1
a0121128:  91 36 60 10  srl  %i1, 0x10, %o0
a012112c:  80 a2 20 c7  cmp  %o0, 0xc7
a0121130:  08 bf ff 99  bleu  0xa0120f94
a0121134:  82 10 20 00  clr  %g1
a0121138:  80 a2 21 7b  cmp  %o0, 0x17b
a012113c:  18 80 00 0d  bgu  0xa0121170
a0121140:  80 a2 22 d9  cmp  %o0, 0x2d9
a0121144:  40 00 d5 bf  call  0xa0156840
a0121148:  90 0c 20 ff  and  %l0, 0xff, %o0
a012114c:  1f 00 06 8b  sethi  %hi(0x1a2c00), %o7
a0121150:  d4 1b e3 e0  ldd  [ %o7 + 0x3e0 ], %o2	! 0x1a2fe0
a0121154:  40 00 d5 89  call  0xa0156778
a0121158:  01 00 00 00  nop
a012115c:  80 a2 20 00  cmp  %o0, 0
a0121160:  14 bf ff 8d  bg  0xa0120f94
a0121164:  82 10 20 00  clr  %g1
a0121168:  10 bf ff 8b  b  0xa0120f94
a012116c:  82 10 20 01  mov  1, %g1
a0121170:  18 80 00 07  bgu  0xa012118c
a0121174:  01 00 00 00  nop
a0121178:  40 00 d5 b2  call  0xa0156840
a012117c:  90 0c 20 ff  and  %l0, 0xff, %o0
a0121180:  1b 00 06 8b  sethi  %hi(0x1a2c00), %o5
a0121184:  10 bf ff f4  b  0xa0121154
a0121188:  d4 1b 63 e8  ldd  [ %o5 + 0x3e8 ], %o2	! 0x1a2fe8
a012118c:  40 00 d5 ad  call  0xa0156840
a0121190:  90 0c 20 ff  and  %l0, 0xff, %o0
a0121194:  21 00 06 8b  sethi  %hi(0x1a2c00), %l0
a0121198:  10 bf ff ef  b  0xa0121154
a012119c:  d4 1c 23 f0  ldd  [ %l0 + 0x3f0 ], %o2	! 0x1a2ff0
a01211a0:  b0 0c 20 ff  and  %l0, 0xff, %i0
a01211a4:  81 c7 e0 08  ret
a01211a8:  81 e8 00 00  restore
