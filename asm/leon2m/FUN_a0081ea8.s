# leon2m FUN_a0081ea8 0xa0081ea8-0xa0082acc (56 bytes)
a0081ea8:  9d e3 bf 98  save  %sp, -104, %sp
a0081eac:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0081eb0:  82 14 22 90  or  %l0, 0x290, %g1	! 0xa802d290
a0081eb4:  80 a6 20 05  cmp  %i0, 5
a0081eb8:  18 80 03 03  bgu  0xa0082ac4
a0081ebc:  e2 08 60 1e  ldub  [ %g1 + 0x1e ], %l1
a0081ec0:  13 00 00 80  sethi  %hi(0x20000), %o1
a0081ec4:  91 2e 20 02  sll  %i0, 2, %o0
a0081ec8:  9a 12 61 ec  or  %o1, 0x1ec, %o5
a0081ecc:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a0081ed0:  81 c3 00 00  jmp  %o4
a0081ed4:  01 00 00 00  nop
a0081ed8:  17 00 03 fb  sethi  %hi(0xfec00), %o3
a0081edc:  40 01 74 a5  call  0xa00df170
a0081ee0:  90 12 e1 d8  or  %o3, 0x1d8, %o0	! 0xfedd8
a0081ee4:  b0 14 22 90  or  %l0, 0x290, %i0
a0081ee8:  d4 0e 21 d5  ldub  [ %i0 + 0x1d5 ], %o2
a0081eec:  80 a2 a0 00  cmp  %o2, 0
a0081ef0:  02 80 00 08  be  0xa0081f10
a0081ef4:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a0081ef8:  29 00 00 15  sethi  %hi(0x5400), %l4
a0081efc:  e4 16 21 f6  lduh  [ %i0 + 0x1f6 ], %l2
a0081f00:  9e 15 21 aa  or  %l4, 0x1aa, %o7
a0081f04:  80 a4 80 0f  cmp  %l2, %o7
a0081f08:  02 80 02 ef  be  0xa0082ac4
a0081f0c:  01 00 00 00  nop
a0081f10:  29 2a 00 b3  sethi  %hi(0xa802cc00), %l4
a0081f14:  a4 15 23 f4  or  %l4, 0x3f4, %l2	! 0xa802cff4
a0081f18:  de 14 a0 04  lduh  [ %l2 + 4 ], %o7
a0081f1c:  15 00 00 18  sethi  %hi(0x6000), %o2
a0081f20:  96 0b c0 0a  and  %o7, %o2, %o3
a0081f24:  80 a0 00 0b  cmp  %g0, %o3
a0081f28:  13 00 00 10  sethi  %hi(0x4000), %o1
a0081f2c:  98 60 3f ff  subx  %g0, -1, %o4
a0081f30:  90 1a c0 09  xor  %o3, %o1, %o0
a0081f34:  80 a0 00 08  cmp  %g0, %o0
a0081f38:  82 60 3f ff  subx  %g0, -1, %g1
a0081f3c:  80 93 00 01  orcc  %o4, %g1, %g0
a0081f40:  12 80 01 e8  bne  0xa00826e0
a0081f44:  15 00 00 08  sethi  %hi(0x2000), %o2
a0081f48:  80 a2 c0 0a  cmp  %o3, %o2
a0081f4c:  12 80 02 de  bne  0xa0082ac4
a0081f50:  11 00 03 fb  sethi  %hi(0xfec00), %o0
a0081f54:  40 01 74 87  call  0xa00df170
a0081f58:  90 12 21 f0  or  %o0, 0x1f0, %o0	! 0xfedf0
a0081f5c:  c2 04 e2 90  ld  [ %l3 + 0x290 ], %g1
a0081f60:  25 00 00 10  sethi  %hi(0x4000), %l2
a0081f64:  d6 16 21 f6  lduh  [ %i0 + 0x1f6 ], %o3
a0081f68:  98 28 40 12  andn  %g1, %l2, %o4
a0081f6c:  d8 24 e2 90  st  %o4, [ %l3 + 0x290 ]
a0081f70:  27 00 00 15  sethi  %hi(0x5400), %l3
a0081f74:  9e 14 e1 aa  or  %l3, 0x1aa, %o7	! 0x55aa
a0081f78:  80 a2 c0 0f  cmp  %o3, %o7
a0081f7c:  02 80 00 07  be  0xa0081f98
a0081f80:  15 3f ff ee  sethi  %hi(0xffffb800), %o2
a0081f84:  da 0e 21 d5  ldub  [ %i0 + 0x1d5 ], %o5
a0081f88:  80 a3 60 00  cmp  %o5, 0
a0081f8c:  02 80 00 2b  be  0xa0082038
a0081f90:  96 15 23 f4  or  %l4, 0x3f4, %o3
a0081f94:  15 3f ff ee  sethi  %hi(0xffffb800), %o2
a0081f98:  92 12 a3 99  or  %o2, 0x399, %o1	! 0xffffbb99
a0081f9c:  d2 36 21 f6  sth  %o1, [ %i0 + 0x1f6 ]
a0081fa0:  40 01 69 0f  call  0xa00dc3dc
a0081fa4:  c0 2e 21 d5  clrb  [ %i0 + 0x1d5 ]
a0081fa8:  90 10 20 08  mov  8, %o0
a0081fac:  40 03 0f 2c  call  0xa0145c5c
a0081fb0:  92 10 20 00  clr  %o1
a0081fb4:  90 10 20 09  mov  9, %o0
a0081fb8:  40 03 0f 29  call  0xa0145c5c
a0081fbc:  92 10 20 00  clr  %o1
a0081fc0:  90 10 20 06  mov  6, %o0
a0081fc4:  40 03 0f 26  call  0xa0145c5c
a0081fc8:  92 10 20 00  clr  %o1
a0081fcc:  90 10 20 07  mov  7, %o0
a0081fd0:  40 03 0f 23  call  0xa0145c5c
a0081fd4:  92 10 20 00  clr  %o1
a0081fd8:  90 10 20 0b  mov  0xb, %o0
a0081fdc:  40 03 0f 20  call  0xa0145c5c
a0081fe0:  92 10 20 00  clr  %o1
a0081fe4:  90 10 20 0a  mov  0xa, %o0
a0081fe8:  40 03 0f 1d  call  0xa0145c5c
a0081fec:  92 10 20 00  clr  %o1
a0081ff0:  90 10 20 0d  mov  0xd, %o0
a0081ff4:  40 03 0f 1a  call  0xa0145c5c
a0081ff8:  92 10 20 00  clr  %o1
a0081ffc:  90 10 20 0c  mov  0xc, %o0
a0082000:  40 03 0f 17  call  0xa0145c5c
a0082004:  92 10 20 00  clr  %o1
a0082008:  90 10 20 10  mov  0x10, %o0
a008200c:  40 03 0f 14  call  0xa0145c5c
a0082010:  92 10 20 00  clr  %o1
a0082014:  90 10 20 0e  mov  0xe, %o0
a0082018:  40 03 0f 11  call  0xa0145c5c
a008201c:  92 10 20 00  clr  %o1
a0082020:  90 10 20 0f  mov  0xf, %o0
a0082024:  40 03 0f 0e  call  0xa0145c5c
a0082028:  92 10 20 00  clr  %o1
a008202c:  40 03 0c cd  call  0xa0145360
a0082030:  90 10 20 01  mov  1, %o0
a0082034:  96 15 23 f4  or  %l4, 0x3f4, %o3
a0082038:  d8 12 e0 04  lduh  [ %o3 + 4 ], %o4
a008203c:  25 00 00 04  sethi  %hi(0x1000), %l2
a0082040:  a6 13 00 12  or  %o4, %l2, %l3
a0082044:  e6 32 e0 04  sth  %l3, [ %o3 + 4 ]
a0082048:  a4 14 22 90  or  %l0, 0x290, %l2
a008204c:  40 03 09 6c  call  0xa01445fc
a0082050:  d0 0c a0 1e  ldub  [ %l2 + 0x1e ], %o0
a0082054:  9e 02 20 01  add  %o0, 1, %o7
a0082058:  90 0b e0 ff  and  %o7, 0xff, %o0
a008205c:  40 03 09 50  call  0xa014459c
a0082060:  01 00 00 00  nop
a0082064:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0082068:  80 a6 20 14  cmp  %i0, 0x14
a008206c:  08 80 01 fa  bleu  0xa0082854
a0082070:  01 00 00 00  nop
a0082074:  90 10 20 00  clr  %o0	! 0x0
a0082078:  40 03 09 49  call  0xa014459c
a008207c:  01 00 00 00  nop
a0082080:  40 01 5c 6e  call  0xa00d9238
a0082084:  d0 2c a0 1e  stb  %o0, [ %l2 + 0x1e ]
a0082088:  a4 14 22 90  or  %l0, 0x290, %l2
a008208c:  40 01 5c 6b  call  0xa00d9238
a0082090:  e2 2c a0 1e  stb  %l1, [ %l2 + 0x1e ]
a0082094:  40 02 96 01  call  0xa0127898
a0082098:  23 00 04 00  sethi  %hi(0x100000), %l1
a008209c:  40 01 4f 0f  call  0xa00d5cd8
a00820a0:  01 00 00 00  nop
a00820a4:  40 02 8a a7  call  0xa0124b40
a00820a8:  01 00 00 00  nop
a00820ac:  40 02 8a 6f  call  0xa0124a68
a00820b0:  01 00 00 00  nop
a00820b4:  d0 04 a0 ac  ld  [ %l2 + 0xac ], %o0
a00820b8:  80 8a 00 11  btst  %o0, %l1
a00820bc:  02 80 00 06  be  0xa00820d4
a00820c0:  01 00 00 00  nop
a00820c4:  da 0c a0 1f  ldub  [ %l2 + 0x1f ], %o5
a00820c8:  80 a3 60 00  cmp  %o5, 0
a00820cc:  02 80 02 18  be  0xa008292c
a00820d0:  01 00 00 00  nop
a00820d4:  40 01 5e 29  call  0xa00d9978
a00820d8:  01 00 00 00  nop
a00820dc:  40 02 8e 1d  call  0xa0125950
a00820e0:  01 00 00 00  nop
a00820e4:  40 02 8d ed  call  0xa0125898
a00820e8:  01 00 00 00  nop
a00820ec:  40 01 64 10  call  0xa00db12c
a00820f0:  90 10 20 00  clr  %o0	! 0x0
a00820f4:  40 02 8e 25  call  0xa0125988
a00820f8:  01 00 00 00  nop
a00820fc:  40 03 1a 6b  call  0xa0148aa8
a0082100:  90 10 20 01  mov  1, %o0	! 0x1
a0082104:  92 10 20 01  mov  1, %o1
a0082108:  40 03 18 58  call  0xa0148268
a008210c:  90 10 20 01  mov  1, %o0
a0082110:  f0 04 22 90  ld  [ %l0 + 0x290 ], %i0
a0082114:  1f 00 00 14  sethi  %hi(0x5000), %o7
a0082118:  94 0e 00 0f  and  %i0, %o7, %o2
a008211c:  13 00 00 04  sethi  %hi(0x1000), %o1
a0082120:  80 a2 80 09  cmp  %o2, %o1
a0082124:  02 80 01 df  be  0xa00828a0
a0082128:  82 14 22 90  or  %l0, 0x290, %g1
a008212c:  d4 04 22 90  ld  [ %l0 + 0x290 ], %o2
a0082130:  31 00 00 14  sethi  %hi(0x5000), %i0
a0082134:  92 0a 80 18  and  %o2, %i0, %o1
a0082138:  1b 00 00 04  sethi  %hi(0x1000), %o5
a008213c:  80 a2 40 0d  cmp  %o1, %o5
a0082140:  12 80 01 b8  bne  0xa0082820
a0082144:  82 14 22 90  or  %l0, 0x290, %g1
a0082148:  27 00 00 15  sethi  %hi(0x5400), %l3
a008214c:  d6 10 61 f6  lduh  [ %g1 + 0x1f6 ], %o3
a0082150:  9e 14 e1 aa  or  %l3, 0x1aa, %o7
a0082154:  80 a2 c0 0f  cmp  %o3, %o7
a0082158:  02 80 01 b2  be  0xa0082820
a008215c:  01 00 00 00  nop
a0082160:  e4 04 22 90  ld  [ %l0 + 0x290 ], %l2
a0082164:  19 00 00 10  sethi  %hi(0x4000), %o4
a0082168:  80 8c 80 0c  btst  %l2, %o4
a008216c:  02 80 01 b1  be  0xa0082830
a0082170:  e2 15 23 f4  lduh  [ %l4 + 0x3f4 ], %l1
a0082174:  c2 15 23 f4  lduh  [ %l4 + 0x3f4 ], %g1
a0082178:  82 08 7b ff  and  %g1, -1025, %g1
a008217c:  c2 35 23 f4  sth  %g1, [ %l4 + 0x3f4 ]
a0082180:  94 14 22 90  or  %l0, 0x290, %o2
a0082184:  d8 0a a1 a0  ldub  [ %o2 + 0x1a0 ], %o4
a0082188:  90 15 23 f4  or  %l4, 0x3f4, %o0
a008218c:  9e 03 00 0a  add  %o4, %o2, %o7
a0082190:  c2 15 23 f4  lduh  [ %l4 + 0x3f4 ], %g1
a0082194:  e6 12 20 04  lduh  [ %o0 + 4 ], %l3
a0082198:  d2 0b e1 9b  ldub  [ %o7 + 0x19b ], %o1
a008219c:  25 00 00 10  sethi  %hi(0x4000), %l2
a00821a0:  e0 0b e1 97  ldub  [ %o7 + 0x197 ], %l0
a00821a4:  d2 2a a1 a2  stb  %o1, [ %o2 + 0x1a2 ]
a00821a8:  9a 28 40 12  andn  %g1, %l2, %o5
a00821ac:  17 00 00 18  sethi  %hi(0x6000), %o3
a00821b0:  da 35 23 f4  sth  %o5, [ %l4 + 0x3f4 ]
a00821b4:  b0 2c c0 0b  andn  %l3, %o3, %i0
a00821b8:  f0 32 20 04  sth  %i0, [ %o0 + 4 ]
a00821bc:  10 80 02 42  b  0xa0082ac4
a00821c0:  e0 2a a1 a1  stb  %l0, [ %o2 + 0x1a1 ]
a00821c4:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a00821c8:  9e 14 a3 f4  or  %l2, 0x3f4, %o7	! 0xa802cff4
a00821cc:  d8 13 e0 04  lduh  [ %o7 + 4 ], %o4
a00821d0:  1b 00 00 18  sethi  %hi(0x6000), %o5
a00821d4:  94 0b 40 0c  and  %o5, %o4, %o2
a00821d8:  11 00 00 10  sethi  %hi(0x4000), %o0
a00821dc:  80 a2 80 08  cmp  %o2, %o0
a00821e0:  02 80 01 34  be  0xa00826b0
a00821e4:  f0 04 22 90  ld  [ %l0 + 0x290 ], %i0
a00821e8:  40 02 95 fd  call  0xa01279dc
a00821ec:  01 00 00 00  nop
a00821f0:  a8 0a 20 ff  and  %o0, 0xff, %l4
a00821f4:  80 a5 20 01  cmp  %l4, 1
a00821f8:  02 80 01 69  be  0xa008279c
a00821fc:  01 00 00 00  nop
a0082200:  9a 14 a3 f4  or  %l2, 0x3f4, %o5
a0082204:  c2 13 60 06  lduh  [ %o5 + 6 ], %g1
a0082208:  80 88 60 40  btst  0x40, %g1
a008220c:  02 80 02 2e  be  0xa0082ac4
a0082210:  a6 08 7f bf  and  %g1, -65, %l3
a0082214:  e6 33 60 06  sth  %l3, [ %o5 + 6 ]
a0082218:  a4 14 22 90  or  %l0, 0x290, %l2
a008221c:  40 03 08 f8  call  0xa01445fc
a0082220:  d0 0c a0 1e  ldub  [ %l2 + 0x1e ], %o0
a0082224:  92 02 20 01  add  %o0, 1, %o1
a0082228:  40 03 08 dd  call  0xa014459c
a008222c:  90 0a 60 ff  and  %o1, 0xff, %o0
a0082230:  96 0a 20 ff  and  %o0, 0xff, %o3
a0082234:  80 a2 e0 14  cmp  %o3, 0x14
a0082238:  08 80 01 54  bleu  0xa0082788
a008223c:  01 00 00 00  nop
a0082240:  90 10 20 00  clr  %o0	! 0x0
a0082244:  40 03 08 d6  call  0xa014459c
a0082248:  b0 10 20 03  mov  3, %i0
a008224c:  40 01 5b fb  call  0xa00d9238
a0082250:  d0 2c a0 1e  stb  %o0, [ %l2 + 0x1e ]
a0082254:  a4 14 22 90  or  %l0, 0x290, %l2
a0082258:  40 01 5b f8  call  0xa00d9238
a008225c:  e2 2c a0 1e  stb  %l1, [ %l2 + 0x1e ]
a0082260:  40 02 8a 38  call  0xa0124b40
a0082264:  01 00 00 00  nop
a0082268:  40 02 8a 00  call  0xa0124a68
a008226c:  01 00 00 00  nop
a0082270:  40 03 1a 0e  call  0xa0148aa8
a0082274:  90 10 20 01  mov  1, %o0	! 0x1
a0082278:  40 00 12 1c  call  0xa0086ae8
a008227c:  81 e8 00 00  restore
a0082280:  a0 10 20 01  mov  1, %l0
a0082284:  b0 10 20 00  clr  %i0
a0082288:  90 10 20 00  clr  %o0
a008228c:  40 03 06 62  call  0xa0143c14
a0082290:  01 00 00 00  nop
a0082294:  80 8a 20 ff  btst  0xff, %o0
a0082298:  32 80 00 07  bne,a   0xa00822b4
a008229c:  a0 10 20 00  clr  %l0
a00822a0:  b0 06 20 01  inc  %i0
a00822a4:  90 0e 20 ff  and  %i0, 0xff, %o0
a00822a8:  80 a2 20 03  cmp  %o0, 3
a00822ac:  08 bf ff f8  bleu  0xa008228c
a00822b0:  01 00 00 00  nop
a00822b4:  80 8c 20 ff  btst  0xff, %l0
a00822b8:  12 80 02 03  bne  0xa0082ac4
a00822bc:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00822c0:  e8 0c 23 41  ldub  [ %l0 + 0x341 ], %l4	! 0xa802af41
a00822c4:  80 8d 20 01  btst  1, %l4
a00822c8:  32 80 00 85  bne,a   0xa00824dc
a00822cc:  90 10 20 ff  mov  0xff, %o0
a00822d0:  40 00 3b 42  call  0xa0090fd8
a00822d4:  01 00 00 00  nop
a00822d8:  7f ff f8 6e  call  0xa0080490
a00822dc:  91 e8 20 00  restore  %g0, 0, %o0
a00822e0:  27 00 03 fb  sethi  %hi(0xfec00), %l3
a00822e4:  40 01 73 a3  call  0xa00df170
a00822e8:  90 14 e1 f8  or  %l3, 0x1f8, %o0	! 0xfedf8
a00822ec:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a00822f0:  92 14 a3 f4  or  %l2, 0x3f4, %o1	! 0xa802cff4
a00822f4:  d6 12 60 04  lduh  [ %o1 + 4 ], %o3
a00822f8:  31 00 00 18  sethi  %hi(0x6000), %i0
a00822fc:  9e 2a c0 18  andn  %o3, %i0, %o7
a0082300:  de 32 60 04  sth  %o7, [ %o1 + 4 ]
a0082304:  b0 14 22 90  or  %l0, 0x290, %i0
a0082308:  40 03 08 bd  call  0xa01445fc
a008230c:  d0 0e 20 1e  ldub  [ %i0 + 0x1e ], %o0
a0082310:  9a 02 20 01  add  %o0, 1, %o5
a0082314:  40 03 08 a2  call  0xa014459c
a0082318:  90 0b 60 ff  and  %o5, 0xff, %o0
a008231c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0082320:  80 a2 20 14  cmp  %o0, 0x14
a0082324:  38 80 00 06  bgu,a   0xa008233c
a0082328:  90 10 20 00  clr  %o0
a008232c:  40 03 08 b4  call  0xa01445fc
a0082330:  d0 0e 20 1e  ldub  [ %i0 + 0x1e ], %o0
a0082334:  82 02 20 01  add  %o0, 1, %g1
a0082338:  90 08 60 ff  and  %g1, 0xff, %o0
a008233c:  40 03 08 98  call  0xa014459c
a0082340:  01 00 00 00  nop
a0082344:  40 01 5b bd  call  0xa00d9238
a0082348:  d0 2e 20 1e  stb  %o0, [ %i0 + 0x1e ]
a008234c:  b0 14 22 90  or  %l0, 0x290, %i0
a0082350:  40 01 5b ba  call  0xa00d9238
a0082354:  e2 2e 20 1e  stb  %l1, [ %i0 + 0x1e ]
a0082358:  40 02 95 50  call  0xa0127898
a008235c:  01 00 00 00  nop
a0082360:  40 02 89 f8  call  0xa0124b40
a0082364:  01 00 00 00  nop
a0082368:  40 02 89 c0  call  0xa0124a68
a008236c:  01 00 00 00  nop
a0082370:  40 03 19 ce  call  0xa0148aa8
a0082374:  90 10 20 01  mov  1, %o0	! 0x1
a0082378:  e2 04 22 90  ld  [ %l0 + 0x290 ], %l1
a008237c:  15 00 00 14  sethi  %hi(0x5000), %o2
a0082380:  a8 0c 40 0a  and  %l1, %o2, %l4
a0082384:  19 00 00 04  sethi  %hi(0x1000), %o4
a0082388:  80 a5 00 0c  cmp  %l4, %o4
a008238c:  02 80 00 af  be  0xa0082648
a0082390:  13 00 00 15  sethi  %hi(0x5400), %o1
a0082394:  40 00 11 d5  call  0xa0086ae8
a0082398:  90 10 20 01  mov  1, %o0
a008239c:  d8 04 22 90  ld  [ %l0 + 0x290 ], %o4
a00823a0:  03 00 00 10  sethi  %hi(0x4000), %g1
a00823a4:  80 8b 00 01  btst  %o4, %g1
a00823a8:  02 80 00 a6  be  0xa0082640
a00823ac:  e2 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %l1
a00823b0:  e8 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %l4
a00823b4:  82 0d 3b ff  and  %l4, -1025, %g1
a00823b8:  c2 34 a3 f4  sth  %g1, [ %l2 + 0x3f4 ]
a00823bc:  90 14 22 90  or  %l0, 0x290, %o0
a00823c0:  d6 0a 21 a0  ldub  [ %o0 + 0x1a0 ], %o3
a00823c4:  92 02 c0 08  add  %o3, %o0, %o1
a00823c8:  f0 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %i0
a00823cc:  d4 0a 61 9b  ldub  [ %o1 + 0x19b ], %o2
a00823d0:  1f 00 00 10  sethi  %hi(0x4000), %o7
a00823d4:  e0 0a 61 97  ldub  [ %o1 + 0x197 ], %l0
a00823d8:  9a 2e 00 0f  andn  %i0, %o7, %o5
a00823dc:  d4 2a 21 a2  stb  %o2, [ %o0 + 0x1a2 ]
a00823e0:  da 34 a3 f4  sth  %o5, [ %l2 + 0x3f4 ]
a00823e4:  10 80 01 b8  b  0xa0082ac4
a00823e8:  e0 2a 21 a1  stb  %l0, [ %o0 + 0x1a1 ]
a00823ec:  25 00 03 fb  sethi  %hi(0xfec00), %l2
a00823f0:  90 14 a2 10  or  %l2, 0x210, %o0	! 0xfee10
a00823f4:  40 01 73 5f  call  0xa00df170
a00823f8:  25 2a 00 b3  sethi  %hi(0xa802cc00), %l2
a00823fc:  a2 14 a3 f4  or  %l2, 0x3f4, %l1	! 0xa802cff4
a0082400:  c0 2c 60 3f  clrb  [ %l1 + 0x3f ]
a0082404:  40 02 95 4a  call  0xa012792c
a0082408:  c0 34 60 0c  clrh  [ %l1 + 0xc ]
a008240c:  80 8a 20 ff  btst  0xff, %o0
a0082410:  12 80 00 31  bne  0xa00824d4
a0082414:  27 00 03 fb  sethi  %hi(0xfec00), %l3
a0082418:  40 02 95 4b  call  0xa0127944
a008241c:  01 00 00 00  nop
a0082420:  80 8a 20 ff  btst  0xff, %o0
a0082424:  12 80 00 15  bne  0xa0082478
a0082428:  90 14 e2 28  or  %l3, 0x228, %o0
a008242c:  40 00 3a eb  call  0xa0090fd8
a0082430:  01 00 00 00  nop
a0082434:  40 02 95 2f  call  0xa01278f0
a0082438:  90 10 20 01  mov  1, %o0	! 0x1
a008243c:  40 02 95 36  call  0xa0127914
a0082440:  90 10 20 01  mov  1, %o0
a0082444:  40 02 96 0d  call  0xa0127c78
a0082448:  01 00 00 00  nop
a008244c:  40 02 95 38  call  0xa012792c
a0082450:  01 00 00 00  nop
a0082454:  80 8a 20 ff  btst  0xff, %o0
a0082458:  12 80 00 07  bne  0xa0082474
a008245c:  03 00 03 fb  sethi  %hi(0xfec00), %g1
a0082460:  40 02 95 39  call  0xa0127944
a0082464:  01 00 00 00  nop
a0082468:  80 8a 20 ff  btst  0xff, %o0
a008246c:  02 80 00 23  be  0xa00824f8
a0082470:  03 00 03 fb  sethi  %hi(0xfec00), %g1
a0082474:  90 10 62 38  or  %g1, 0x238, %o0	! 0xfee38
a0082478:  40 01 73 3e  call  0xa00df170
a008247c:  01 00 00 00  nop
a0082480:  e6 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %l3
a0082484:  92 14 e4 00  or  %l3, 0x400, %o1
a0082488:  10 80 01 8f  b  0xa0082ac4
a008248c:  d2 34 a3 f4  sth  %o1, [ %l2 + 0x3f4 ]
a0082490:  40 02 89 88  call  0xa0124ab0
a0082494:  25 00 00 20  sethi  %hi(0x8000), %l2
a0082498:  40 02 89 98  call  0xa0124af8
a008249c:  01 00 00 00  nop
a00824a0:  40 02 8d 8a  call  0xa0125ac8
a00824a4:  01 00 00 00  nop
a00824a8:  40 02 8d dc  call  0xa0125c18
a00824ac:  01 00 00 00  nop
a00824b0:  82 14 22 90  or  %l0, 0x290, %g1
a00824b4:  e8 00 60 a8  ld  [ %g1 + 0xa8 ], %l4
a00824b8:  80 8d 00 12  btst  %l4, %l2
a00824bc:  02 80 00 aa  be  0xa0082764
a00824c0:  01 00 00 00  nop
a00824c4:  40 03 20 d7  call  0xa014a820
a00824c8:  90 10 20 00  clr  %o0	! 0x0
a00824cc:  40 03 04 cc  call  0xa01437fc
a00824d0:  81 e8 00 00  restore
a00824d4:  10 bf ff e9  b  0xa0082478
a00824d8:  90 14 e2 28  or  %l3, 0x228, %o0
a00824dc:  40 00 32 64  call  0xa008ee6c
a00824e0:  92 10 20 00  clr  %o1
a00824e4:  d4 0c 23 41  ldub  [ %l0 + 0x341 ], %o2
a00824e8:  a2 0a bf fe  and  %o2, -2, %l1
a00824ec:  40 03 06 2f  call  0xa0143da8
a00824f0:  e2 2c 23 41  stb  %l1, [ %l0 + 0x341 ]
a00824f4:  30 bf ff 77  b,a   0xa00822d0
a00824f8:  13 00 03 fb  sethi  %hi(0xfec00), %o1
a00824fc:  40 01 73 1d  call  0xa00df170
a0082500:  90 12 62 48  or  %o1, 0x248, %o0	! 0xfee48
a0082504:  da 14 60 3e  lduh  [ %l1 + 0x3e ], %o5
a0082508:  15 3f ff e0  sethi  %hi(0xffff8000), %o2
a008250c:  98 2b 40 0a  andn  %o5, %o2, %o4
a0082510:  40 02 89 3e  call  0xa0124a08
a0082514:  d8 34 60 3e  sth  %o4, [ %l1 + 0x3e ]
a0082518:  98 14 22 90  or  %l0, 0x290, %o4
a008251c:  11 00 00 15  sethi  %hi(0x5400), %o0
a0082520:  e2 13 21 f6  lduh  [ %o4 + 0x1f6 ], %l1
a0082524:  a8 12 21 aa  or  %o0, 0x1aa, %l4
a0082528:  80 a4 40 14  cmp  %l1, %l4
a008252c:  12 80 00 06  bne  0xa0082544
a0082530:  01 00 00 00  nop
a0082534:  de 0b 21 d6  ldub  [ %o4 + 0x1d6 ], %o7
a0082538:  80 a3 e0 55  cmp  %o7, 0x55
a008253c:  02 80 00 07  be  0xa0082558
a0082540:  27 00 00 15  sethi  %hi(0x5400), %l3
a0082544:  40 02 89 5b  call  0xa0124ab0
a0082548:  27 00 00 15  sethi  %hi(0x5400), %l3
a008254c:  40 02 89 6b  call  0xa0124af8
a0082550:  01 00 00 00  nop
a0082554:  98 14 22 90  or  %l0, 0x290, %o4
a0082558:  d6 13 21 f6  lduh  [ %o4 + 0x1f6 ], %o3
a008255c:  b0 14 e1 aa  or  %l3, 0x1aa, %i0
a0082560:  80 a2 c0 18  cmp  %o3, %i0
a0082564:  12 80 00 06  bne  0xa008257c
a0082568:  01 00 00 00  nop
a008256c:  c2 0b 21 d6  ldub  [ %o4 + 0x1d6 ], %g1
a0082570:  80 a0 60 55  cmp  %g1, 0x55
a0082574:  02 80 00 04  be  0xa0082584
a0082578:  01 00 00 00  nop
a008257c:  40 02 8d 53  call  0xa0125ac8
a0082580:  01 00 00 00  nop
a0082584:  40 02 8d a5  call  0xa0125c18
a0082588:  a2 14 22 90  or  %l0, 0x290, %l1
a008258c:  d0 04 60 a8  ld  [ %l1 + 0xa8 ], %o0
a0082590:  29 00 00 20  sethi  %hi(0x8000), %l4
a0082594:  80 8a 00 14  btst  %o0, %l4
a0082598:  02 80 01 00  be  0xa0082998
a008259c:  01 00 00 00  nop
a00825a0:  40 02 95 0f  call  0xa01279dc
a00825a4:  01 00 00 00  nop
a00825a8:  98 0a 20 ff  and  %o0, 0xff, %o4
a00825ac:  80 a3 20 01  cmp  %o4, 1
a00825b0:  02 80 01 29  be  0xa0082a54
a00825b4:  98 14 22 90  or  %l0, 0x290, %o4
a00825b8:  e2 03 20 ac  ld  [ %o4 + 0xac ], %l1
a00825bc:  13 00 04 00  sethi  %hi(0x100000), %o1
a00825c0:  80 8c 40 09  btst  %l1, %o1
a00825c4:  02 80 00 d1  be  0xa0082908
a00825c8:  90 14 22 90  or  %l0, 0x290, %o0
a00825cc:  de 0b 20 1f  ldub  [ %o4 + 0x1f ], %o7
a00825d0:  80 a3 e0 00  cmp  %o7, 0
a00825d4:  32 80 00 ce  bne,a   0xa008290c
a00825d8:  e8 02 20 a8  ld  [ %o0 + 0xa8 ], %l4
a00825dc:  27 2a 00 90  sethi  %hi(0xa8024000), %l3
a00825e0:  96 10 3f ff  mov  -1, %o3
a00825e4:  b0 14 e0 10  or  %l3, 0x10, %i0
a00825e8:  d6 2c e0 10  stb  %o3, [ %l3 + 0x10 ]
a00825ec:  d6 2e 20 01  stb  %o3, [ %i0 + 1 ]
a00825f0:  d6 2e 20 03  stb  %o3, [ %i0 + 3 ]
a00825f4:  d6 2e 20 02  stb  %o3, [ %i0 + 2 ]
a00825f8:  d4 04 22 90  ld  [ %l0 + 0x290 ], %o2
a00825fc:  80 8a a2 00  btst  0x200, %o2
a0082600:  12 80 00 03  bne  0xa008260c
a0082604:  90 10 20 01  mov  1, %o0
a0082608:  90 10 20 00  clr  %o0
a008260c:  40 03 20 85  call  0xa014a820
a0082610:  a2 14 a3 f4  or  %l2, 0x3f4, %l1
a0082614:  da 14 60 06  lduh  [ %l1 + 6 ], %o5
a0082618:  80 8b 60 80  btst  0x80, %o5
a008261c:  02 80 00 c9  be  0xa0082940
a0082620:  92 10 20 01  mov  1, %o1
a0082624:  90 10 20 00  clr  %o0
a0082628:  40 03 0a c1  call  0xa014512c
a008262c:  92 10 20 01  mov  1, %o1
a0082630:  e0 14 60 06  lduh  [ %l1 + 6 ], %l0
a0082634:  98 14 20 40  or  %l0, 0x40, %o4
a0082638:  10 bf ff 92  b  0xa0082480
a008263c:  d8 34 60 06  sth  %o4, [ %l1 + 6 ]
a0082640:  10 bf ff 5e  b  0xa00823b8
a0082644:  82 14 64 00  or  %l1, 0x400, %g1
a0082648:  da 16 21 f6  lduh  [ %i0 + 0x1f6 ], %o5
a008264c:  90 12 61 aa  or  %o1, 0x1aa, %o0
a0082650:  80 a3 40 08  cmp  %o5, %o0
a0082654:  02 bf ff 50  be  0xa0082394
a0082658:  92 10 20 01  mov  1, %o1
a008265c:  27 00 03 fb  sethi  %hi(0xfec00), %l3
a0082660:  40 01 72 c4  call  0xa00df170
a0082664:  90 14 e1 c8  or  %l3, 0x1c8, %o0	! 0xfedc8
a0082668:  40 00 32 38  call  0xa008ef48
a008266c:  01 00 00 00  nop
a0082670:  90 10 20 ff  mov  0xff, %o0	! 0xff
a0082674:  40 00 31 fe  call  0xa008ee6c
a0082678:  92 10 20 01  mov  1, %o1
a008267c:  90 10 20 40  mov  0x40, %o0
a0082680:  40 00 31 fb  call  0xa008ee6c
a0082684:  92 10 20 00  clr  %o1
a0082688:  1f 2a 00 ab  sethi  %hi(0xa802ac00), %o7
a008268c:  d6 0b e3 41  ldub  [ %o7 + 0x341 ], %o3	! 0xa802af41
a0082690:  b0 12 e0 01  or  %o3, 1, %i0
a0082694:  f0 2b e3 41  stb  %i0, [ %o7 + 0x341 ]
a0082698:  40 03 05 c0  call  0xa0143d98
a008269c:  01 00 00 00  nop
a00826a0:  90 10 20 03  mov  3, %o0	! 0x3
a00826a4:  40 00 10 c3  call  0xa00869b0
a00826a8:  92 10 2b b8  mov  0xbb8, %o1
a00826ac:  30 bf ff 3a  b,a   0xa0082394
a00826b0:  80 8e 22 00  btst  0x200, %i0
a00826b4:  12 bf fe cd  bne  0xa00821e8
a00826b8:  01 00 00 00  nop
a00826bc:  7f ff f8 af  call  0xa0080978
a00826c0:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a00826c4:  92 10 3f ff  mov  -1, %o1
a00826c8:  96 14 e3 60  or  %l3, 0x360, %o3
a00826cc:  d2 2a e0 03  stb  %o1, [ %o3 + 3 ]
a00826d0:  d2 2c e3 60  stb  %o1, [ %l3 + 0x360 ]
a00826d4:  d2 2a e0 01  stb  %o1, [ %o3 + 1 ]
a00826d8:  10 bf fe c4  b  0xa00821e8
a00826dc:  d2 2a e0 02  stb  %o1, [ %o3 + 2 ]
a00826e0:  27 00 03 fb  sethi  %hi(0xfec00), %l3
a00826e4:  40 01 72 a3  call  0xa00df170
a00826e8:  90 14 e2 60  or  %l3, 0x260, %o0	! 0xfee60
a00826ec:  e2 14 a0 10  lduh  [ %l2 + 0x10 ], %l1
a00826f0:  80 a4 60 04  cmp  %l1, 4
a00826f4:  08 80 00 3c  bleu  0xa00827e4
a00826f8:  90 15 23 f4  or  %l4, 0x3f4, %o0
a00826fc:  da 12 20 10  lduh  [ %o0 + 0x10 ], %o5
a0082700:  80 a3 60 04  cmp  %o5, 4
a0082704:  18 80 00 0c  bgu  0xa0082734
a0082708:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a008270c:  98 14 22 90  or  %l0, 0x290, %o4
a0082710:  f0 0b 21 e2  ldub  [ %o4 + 0x1e2 ], %i0
a0082714:  80 a6 00 0d  cmp  %i0, %o5
a0082718:  22 80 00 08  be,a   0xa0082738
a008271c:  d0 0c 63 41  ldub  [ %l1 + 0x341 ], %o0
a0082720:  e8 0a 20 19  ldub  [ %o0 + 0x19 ], %l4
a0082724:  80 a5 20 01  cmp  %l4, 1
a0082728:  22 80 00 5c  be,a   0xa0082898
a008272c:  da 2b 21 e2  stb  %o5, [ %o4 + 0x1e2 ]
a0082730:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0082734:  d0 0c 63 41  ldub  [ %l1 + 0x341 ], %o0	! 0xa802af41
a0082738:  80 8a 20 01  btst  1, %o0
a008273c:  32 80 00 3f  bne,a   0xa0082838
a0082740:  90 10 20 ff  mov  0xff, %o0
a0082744:  40 00 3a 25  call  0xa0090fd8
a0082748:  01 00 00 00  nop
a008274c:  92 14 22 90  or  %l0, 0x290, %o1
a0082750:  94 10 20 00  clr  %o2
a0082754:  96 10 21 fc  mov  0x1fc, %o3
a0082758:  40 03 21 de  call  0xa014aed0
a008275c:  90 10 20 30  mov  0x30, %o0
a0082760:  30 bf fe de  b,a   0xa00822d8
a0082764:  40 02 8c 82  call  0xa012596c
a0082768:  01 00 00 00  nop
a008276c:  40 02 8c 8e  call  0xa01259a4
a0082770:  01 00 00 00  nop
a0082774:  40 02 8d 1b  call  0xa0125be0
a0082778:  01 00 00 00  nop
a008277c:  40 02 8c 5c  call  0xa01258ec
a0082780:  01 00 00 00  nop
a0082784:  30 bf ff 50  b,a   0xa00824c4
a0082788:  40 03 07 9d  call  0xa01445fc
a008278c:  d0 0c a0 1e  ldub  [ %l2 + 0x1e ], %o0
a0082790:  a8 02 20 01  add  %o0, 1, %l4
a0082794:  10 bf fe ac  b  0xa0082244
a0082798:  90 0d 20 ff  and  %l4, 0xff, %o0
a008279c:  40 00 3a 0c  call  0xa0090fcc
a00827a0:  01 00 00 00  nop
a00827a4:  91 2a 20 10  sll  %o0, 0x10, %o0
a00827a8:  83 32 20 10  srl  %o0, 0x10, %g1
a00827ac:  80 a0 60 fe  cmp  %g1, 0xfe
a00827b0:  02 bf fe 94  be  0xa0082200
a00827b4:  d4 04 22 90  ld  [ %l0 + 0x290 ], %o2
a00827b8:  80 8a a2 00  btst  0x200, %o2
a00827bc:  02 80 00 2b  be  0xa0082868
a00827c0:  01 00 00 00  nop
a00827c4:  40 01 5c 6d  call  0xa00d9978
a00827c8:  b0 14 22 90  or  %l0, 0x290, %i0
a00827cc:  40 01 5c 77  call  0xa00d99a8
a00827d0:  01 00 00 00  nop
a00827d4:  40 01 5f e0  call  0xa00da754
a00827d8:  d0 0e 20 ac  ldub  [ %i0 + 0xac ], %o0
a00827dc:  10 bf fe 8a  b  0xa0082204
a00827e0:  9a 14 a3 f4  or  %l2, 0x3f4, %o5
a00827e4:  40 00 39 fa  call  0xa0090fcc
a00827e8:  01 00 00 00  nop
a00827ec:  83 2a 20 10  sll  %o0, 0x10, %g1
a00827f0:  97 30 60 10  srl  %g1, 0x10, %o3
a00827f4:  80 a2 e1 0a  cmp  %o3, 0x10a
a00827f8:  12 bf ff c1  bne  0xa00826fc
a00827fc:  90 15 23 f4  or  %l4, 0x3f4, %o0
a0082800:  d8 14 a0 10  lduh  [ %l2 + 0x10 ], %o4
a0082804:  e4 0e 21 e2  ldub  [ %i0 + 0x1e2 ], %l2
a0082808:  80 a4 80 0c  cmp  %l2, %o4
a008280c:  22 bf ff bd  be,a   0xa0082700
a0082810:  da 12 20 10  lduh  [ %o0 + 0x10 ], %o5
a0082814:  d8 2e 21 e2  stb  %o4, [ %i0 + 0x1e2 ]
a0082818:  10 bf ff b9  b  0xa00826fc
a008281c:  c0 2e 21 e6  clrb  [ %i0 + 0x1e6 ]
a0082820:  40 03 05 62  call  0xa0143da8
a0082824:  01 00 00 00  nop
a0082828:  10 bf fe 4f  b  0xa0082164
a008282c:  e4 04 22 90  ld  [ %l0 + 0x290 ], %l2
a0082830:  10 bf fe 53  b  0xa008217c
a0082834:  82 14 64 00  or  %l1, 0x400, %g1
a0082838:  40 00 31 8d  call  0xa008ee6c
a008283c:  92 10 20 00  clr  %o1
a0082840:  d2 0c 63 41  ldub  [ %l1 + 0x341 ], %o1
a0082844:  9a 0a 7f fe  and  %o1, -2, %o5
a0082848:  40 03 05 58  call  0xa0143da8
a008284c:  da 2c 63 41  stb  %o5, [ %l1 + 0x341 ]
a0082850:  30 bf ff bd  b,a   0xa0082744
a0082854:  40 03 07 6a  call  0xa01445fc
a0082858:  d0 0c a0 1e  ldub  [ %l2 + 0x1e ], %o0
a008285c:  82 02 20 01  add  %o0, 1, %g1
a0082860:  10 bf fe 06  b  0xa0082078
a0082864:  90 08 60 ff  and  %g1, 0xff, %o0
a0082868:  40 02 88 b6  call  0xa0124b40
a008286c:  01 00 00 00  nop
a0082870:  40 02 88 7e  call  0xa0124a68
a0082874:  01 00 00 00  nop
a0082878:  1f 2a 00 ab  sethi  %hi(0xa802ac00), %o7
a008287c:  9a 10 3f ff  mov  -1, %o5
a0082880:  98 13 e3 60  or  %o7, 0x360, %o4
a0082884:  da 2b 20 03  stb  %o5, [ %o4 + 3 ]
a0082888:  da 2b e3 60  stb  %o5, [ %o7 + 0x360 ]
a008288c:  da 2b 20 01  stb  %o5, [ %o4 + 1 ]
a0082890:  10 bf ff cd  b  0xa00827c4
a0082894:  da 2b 20 02  stb  %o5, [ %o4 + 2 ]
a0082898:  10 bf ff a6  b  0xa0082730
a008289c:  c0 2b 21 e6  clrb  [ %o4 + 0x1e6 ]
a00828a0:  19 00 00 15  sethi  %hi(0x5400), %o4
a00828a4:  e6 10 61 f6  lduh  [ %g1 + 0x1f6 ], %l3
a00828a8:  96 13 21 aa  or  %o4, 0x1aa, %o3
a00828ac:  80 a4 c0 0b  cmp  %l3, %o3
a00828b0:  02 bf fe 1f  be  0xa008212c
a00828b4:  92 10 20 01  mov  1, %o1
a00828b8:  11 00 03 fb  sethi  %hi(0xfec00), %o0
a00828bc:  40 01 72 2d  call  0xa00df170
a00828c0:  90 12 21 c8  or  %o0, 0x1c8, %o0	! 0xfedc8
a00828c4:  40 00 31 a1  call  0xa008ef48
a00828c8:  25 2a 00 ab  sethi  %hi(0xa802ac00), %l2
a00828cc:  90 10 20 ff  mov  0xff, %o0
a00828d0:  40 00 31 67  call  0xa008ee6c
a00828d4:  92 10 20 01  mov  1, %o1
a00828d8:  90 10 20 40  mov  0x40, %o0
a00828dc:  40 00 31 64  call  0xa008ee6c
a00828e0:  92 10 20 00  clr  %o1
a00828e4:  e2 0c a3 41  ldub  [ %l2 + 0x341 ], %l1
a00828e8:  82 14 60 01  or  %l1, 1, %g1
a00828ec:  40 03 05 2b  call  0xa0143d98
a00828f0:  c2 2c a3 41  stb  %g1, [ %l2 + 0x341 ]
a00828f4:  90 10 20 03  mov  3, %o0
a00828f8:  40 00 10 2e  call  0xa00869b0
a00828fc:  92 10 2b b8  mov  0xbb8, %o1
a0082900:  10 bf fe 0c  b  0xa0082130
a0082904:  d4 04 22 90  ld  [ %l0 + 0x290 ], %o2
a0082908:  e8 02 20 a8  ld  [ %o0 + 0xa8 ], %l4
a008290c:  03 00 00 20  sethi  %hi(0x8000), %g1
a0082910:  80 8d 00 01  btst  %l4, %g1
a0082914:  32 bf ff 3a  bne,a   0xa00825fc
a0082918:  d4 04 22 90  ld  [ %l0 + 0x290 ], %o2
a008291c:  40 03 13 91  call  0xa0147760
a0082920:  01 00 00 00  nop
a0082924:  10 bf ff 36  b  0xa00825fc
a0082928:  d4 04 22 90  ld  [ %l0 + 0x290 ], %o2
a008292c:  40 03 13 c0  call  0xa014782c
a0082930:  90 10 20 02  mov  2, %o0
a0082934:  40 03 13 be  call  0xa014782c
a0082938:  90 10 20 03  mov  3, %o0
a008293c:  30 bf fd e6  b,a   0xa00820d4
a0082940:  40 03 09 fb  call  0xa014512c
a0082944:  90 10 20 00  clr  %o0
a0082948:  40 02 8c 37  call  0xa0125a24
a008294c:  31 00 00 15  sethi  %hi(0x5400), %i0
a0082950:  92 14 22 90  or  %l0, 0x290, %o1
a0082954:  de 12 61 f6  lduh  [ %o1 + 0x1f6 ], %o7
a0082958:  a2 16 21 aa  or  %i0, 0x1aa, %l1
a008295c:  80 a3 c0 11  cmp  %o7, %l1
a0082960:  12 80 00 06  bne  0xa0082978
a0082964:  01 00 00 00  nop
a0082968:  d6 0a 61 d6  ldub  [ %o1 + 0x1d6 ], %o3
a008296c:  80 a2 e0 55  cmp  %o3, 0x55
a0082970:  22 bf fe c5  be,a   0xa0082484
a0082974:  e6 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %l3
a0082978:  40 02 8d 1b  call  0xa0125de4
a008297c:  01 00 00 00  nop
a0082980:  40 00 13 3f  call  0xa008767c
a0082984:  90 10 20 01  mov  1, %o0	! 0x1
a0082988:  40 03 0a 1d  call  0xa01451fc
a008298c:  01 00 00 00  nop
a0082990:  10 bf fe bd  b  0xa0082484
a0082994:  e6 14 a3 f4  lduh  [ %l2 + 0x3f4 ], %l3
a0082998:  40 02 94 11  call  0xa01279dc
a008299c:  01 00 00 00  nop
a00829a0:  80 8a 20 ff  btst  0xff, %o0
a00829a4:  12 bf fe ff  bne  0xa00825a0
a00829a8:  1b 00 00 15  sethi  %hi(0x5400), %o5
a00829ac:  d4 14 61 f6  lduh  [ %l1 + 0x1f6 ], %o2
a00829b0:  98 13 61 aa  or  %o5, 0x1aa, %o4
a00829b4:  80 a2 80 0c  cmp  %o2, %o4
a00829b8:  12 80 00 06  bne  0xa00829d0
a00829bc:  01 00 00 00  nop
a00829c0:  d2 0c 61 d6  ldub  [ %l1 + 0x1d6 ], %o1
a00829c4:  80 a2 60 55  cmp  %o1, 0x55
a00829c8:  02 80 00 0b  be  0xa00829f4
a00829cc:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00829d0:  40 02 8b e7  call  0xa012596c
a00829d4:  01 00 00 00  nop
a00829d8:  40 02 8b f3  call  0xa01259a4
a00829dc:  01 00 00 00  nop
a00829e0:  40 02 8c 80  call  0xa0125be0
a00829e4:  01 00 00 00  nop
a00829e8:  40 02 8b f6  call  0xa01259c0
a00829ec:  90 10 20 00  clr  %o0	! 0x0
a00829f0:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00829f4:  e2 0b e2 88  ldub  [ %o7 + 0x288 ], %l1	! 0xa802d288
a00829f8:  80 a4 60 01  cmp  %l1, 1
a00829fc:  02 80 00 23  be  0xa0082a88
a0082a00:  82 14 22 90  or  %l0, 0x290, %g1
a0082a04:  98 14 22 90  or  %l0, 0x290, %o4
a0082a08:  15 00 00 15  sethi  %hi(0x5400), %o2
a0082a0c:  d0 13 21 f6  lduh  [ %o4 + 0x1f6 ], %o0
a0082a10:  a8 12 a1 aa  or  %o2, 0x1aa, %l4
a0082a14:  80 a2 00 14  cmp  %o0, %l4
a0082a18:  12 80 00 06  bne  0xa0082a30
a0082a1c:  01 00 00 00  nop
a0082a20:  da 0b 21 d6  ldub  [ %o4 + 0x1d6 ], %o5
a0082a24:  80 a3 60 55  cmp  %o5, 0x55
a0082a28:  02 bf fe de  be  0xa00825a0
a0082a2c:  01 00 00 00  nop
a0082a30:  40 02 8b cf  call  0xa012596c
a0082a34:  01 00 00 00  nop
a0082a38:  40 02 8c dd  call  0xa0125dac
a0082a3c:  01 00 00 00  nop
a0082a40:  40 02 8c 5f  call  0xa0125bbc
a0082a44:  90 10 20 00  clr  %o0	! 0x0
a0082a48:  40 02 8c cb  call  0xa0125d74
a0082a4c:  01 00 00 00  nop
a0082a50:  30 bf fe d4  b,a   0xa00825a0
a0082a54:  40 02 fc 11  call  0xa0141a98
a0082a58:  01 00 00 00  nop
a0082a5c:  80 8a 20 ff  btst  0xff, %o0
a0082a60:  32 80 00 05  bne,a   0xa0082a74
a0082a64:  90 10 20 00  clr  %o0
a0082a68:  21 00 03 fb  sethi  %hi(0xfec00), %l0
a0082a6c:  10 bf fe 83  b  0xa0082478
a0082a70:  90 14 22 70  or  %l0, 0x270, %o0	! 0xfee70
a0082a74:  40 03 09 ae  call  0xa014512c
a0082a78:  92 10 20 01  mov  1, %o1
a0082a7c:  21 00 03 fb  sethi  %hi(0xfec00), %l0
a0082a80:  10 bf fe 7e  b  0xa0082478
a0082a84:  90 14 22 70  or  %l0, 0x270, %o0	! 0xfee70
a0082a88:  27 00 00 15  sethi  %hi(0x5400), %l3
a0082a8c:  d6 10 61 f6  lduh  [ %g1 + 0x1f6 ], %o3
a0082a90:  b0 14 e1 aa  or  %l3, 0x1aa, %i0
a0082a94:  80 a2 c0 18  cmp  %o3, %i0
a0082a98:  12 bf ff dc  bne  0xa0082a08
a0082a9c:  98 14 22 90  or  %l0, 0x290, %o4
a0082aa0:  40 02 8b ac  call  0xa0125950
a0082aa4:  01 00 00 00  nop
a0082aa8:  40 02 8c ba  call  0xa0125d90
a0082aac:  01 00 00 00  nop
a0082ab0:  40 02 8b 73  call  0xa012587c
a0082ab4:  01 00 00 00  nop
a0082ab8:  40 02 8c 41  call  0xa0125bbc
a0082abc:  90 10 20 01  mov  1, %o0	! 0x1
a0082ac0:  30 bf fe b8  b,a   0xa00825a0
a0082ac4:  81 c7 e0 08  ret
a0082ac8:  81 e8 00 00  restore
