# leon2s DRV_HDMI21_RXDetect_FSM_LTS_Chk_SCDC_Err 0xa0098e88-0xa0099560 (1752 bytes)
a0098e88:  9d e3 bf 70  save  %sp, -144, %sp
a0098e8c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0098e90:  80 a4 20 00  cmp  %l0, 0
a0098e94:  b8 10 20 00  clr  %i4
a0098e98:  02 80 00 05  be  0xa0098eac
a0098e9c:  ba 10 20 02  mov  2, %i5
a0098ea0:  80 a4 20 01  cmp  %l0, 1
a0098ea4:  12 80 01 ad  bne  0xa0099558
a0098ea8:  ba 10 20 03  mov  3, %i5
a0098eac:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a0098eb0:  9a 15 22 80  or  %l4, 0x280, %o5	! 0xa807d680
a0098eb4:  82 5c 20 b0  smul  %l0, 0xb0, %g1
a0098eb8:  37 2a 01 f5  sethi  %hi(0xa807d400), %i3
a0098ebc:  a4 00 40 0d  add  %g1, %o5, %l2
a0098ec0:  a6 16 e2 48  or  %i3, 0x248, %l3
a0098ec4:  a3 2c 20 02  sll  %l0, 2, %l1
a0098ec8:  da 04 c0 11  ld  [ %l3 + %l1 ], %o5
a0098ecc:  c2 04 a0 30  ld  [ %l2 + 0x30 ], %g1
a0098ed0:  80 a3 40 01  cmp  %o5, %g1
a0098ed4:  02 80 00 0d  be  0xa0098f08
a0098ed8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0098edc:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0098ee0:  80 88 68 00  btst  0x800, %g1
a0098ee4:  22 80 00 08  be,a   0xa0098f04
a0098ee8:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a0098eec:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a0098ef0:  13 28 02 d0  sethi  %hi(0xa00b4000), %o1
a0098ef4:  90 12 20 68  or  %o0, 0x68, %o0
a0098ef8:  7f ff 68 53  call  0xa0073044
a0098efc:  92 12 63 38  or  %o1, 0x338, %o1
a0098f00:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a0098f04:  c2 24 a0 30  st  %g1, [ %l2 + 0x30 ]
a0098f08:  7f ff d2 3e  call  0xa008d800
a0098f0c:  01 00 00 00  nop
a0098f10:  90 0a 20 ff  and  %o0, 0xff, %o0
a0098f14:  80 a2 20 82  cmp  %o0, 0x82
a0098f18:  28 80 00 23  bleu,a   0xa0098fa4
a0098f1c:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0098f20:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0098f24:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a0098f28:  9a 5c 20 34  smul  %l0, 0x34, %o5
a0098f2c:  a2 03 40 01  add  %o5, %g1, %l1
a0098f30:  c2 04 60 18  ld  [ %l1 + 0x18 ], %g1
a0098f34:  c2 00 60 b0  ld  [ %g1 + 0xb0 ], %g1
a0098f38:  83 30 60 08  srl  %g1, 8, %g1
a0098f3c:  82 08 60 ff  and  %g1, 0xff, %g1
a0098f40:  80 a0 60 ff  cmp  %g1, 0xff
a0098f44:  02 80 00 17  be  0xa0098fa0
a0098f48:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0098f4c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0098f50:  80 88 68 00  btst  0x800, %g1
a0098f54:  22 80 00 06  be,a   0xa0098f6c
a0098f58:  d4 04 60 18  ld  [ %l1 + 0x18 ], %o2
a0098f5c:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0098f60:  7f ff 69 59  call  0xa00734c4
a0098f64:  90 12 21 c8  or  %o0, 0x1c8, %o0	! 0xa0069dc8
a0098f68:  d4 04 60 18  ld  [ %l1 + 0x18 ], %o2
a0098f6c:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a0098f70:  da 02 a0 b0  ld  [ %o2 + 0xb0 ], %o5
a0098f74:  82 10 60 ff  or  %g1, 0xff, %g1
a0098f78:  9a 0b 40 01  and  %o5, %g1, %o5
a0098f7c:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0098f80:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a0098f84:  9a 13 40 01  or  %o5, %g1, %o5
a0098f88:  96 16 e2 48  or  %i3, 0x248, %o3
a0098f8c:  99 2c 20 02  sll  %l0, 2, %o4
a0098f90:  82 10 20 03  mov  3, %g1
a0098f94:  c2 22 c0 0c  st  %g1, [ %o3 + %o4 ]
a0098f98:  da 22 a0 b0  st  %o5, [ %o2 + 0xb0 ]
a0098f9c:  30 80 01 6f  b,a   0xa0099558
a0098fa0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a0098fa4:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a0098fa8:  9a 5c 20 34  smul  %l0, 0x34, %o5
a0098fac:  82 10 63 00  or  %g1, 0x300, %g1
a0098fb0:  a2 03 40 01  add  %o5, %g1, %l1
a0098fb4:  c2 04 60 18  ld  [ %l1 + 0x18 ], %g1
a0098fb8:  da 00 60 90  ld  [ %g1 + 0x90 ], %o5
a0098fbc:  96 15 22 80  or  %l4, 0x280, %o3
a0098fc0:  98 5c 20 b0  smul  %l0, 0xb0, %o4
a0098fc4:  9b 33 60 18  srl  %o5, 0x18, %o5
a0098fc8:  82 03 00 0b  add  %o4, %o3, %g1
a0098fcc:  9a 0b 60 0f  and  %o5, 0xf, %o5
a0098fd0:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a0098fd4:  80 a3 40 01  cmp  %o5, %g1
a0098fd8:  02 80 00 1b  be  0xa0099044
a0098fdc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0098fe0:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0098fe4:  80 88 68 00  btst  0x800, %g1
a0098fe8:  02 80 00 06  be  0xa0099000
a0098fec:  98 16 e2 48  or  %i3, 0x248, %o4
a0098ff0:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0098ff4:  7f ff 69 34  call  0xa00734c4
a0098ff8:  90 12 22 08  or  %o0, 0x208, %o0	! 0xa0069e08
a0098ffc:  98 16 e2 48  or  %i3, 0x248, %o4
a0099000:  9b 2c 20 02  sll  %l0, 2, %o5
a0099004:  82 10 20 03  mov  3, %g1
a0099008:  7f ff d1 fe  call  0xa008d800
a009900c:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
a0099010:  90 0a 20 ff  and  %o0, 0xff, %o0
a0099014:  80 a2 20 82  cmp  %o0, 0x82
a0099018:  08 80 01 50  bleu  0xa0099558
a009901c:  03 3f ff c0  sethi  %hi(0xffff0000), %g1
a0099020:  d8 04 60 18  ld  [ %l1 + 0x18 ], %o4
a0099024:  da 03 20 b0  ld  [ %o4 + 0xb0 ], %o5
a0099028:  82 10 60 ff  or  %g1, 0xff, %g1
a009902c:  9a 0b 40 01  and  %o5, %g1, %o5
a0099030:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a0099034:  82 10 63 00  or  %g1, 0x300, %g1	! 0xff00
a0099038:  9a 13 40 01  or  %o5, %g1, %o5
a009903c:  da 23 20 b0  st  %o5, [ %o4 + 0xb0 ]
a0099040:  30 80 01 46  b,a   0xa0099558
a0099044:  c2 0a c0 0c  ldub  [ %o3 + %o4 ], %g1
a0099048:  80 a0 60 00  cmp  %g1, 0
a009904c:  02 80 00 0f  be  0xa0099088
a0099050:  a4 10 20 00  clr  %l2
a0099054:  94 10 00 0b  mov  %o3, %o2
a0099058:  96 5c 20 2c  smul  %l0, 0x2c, %o3
a009905c:  98 10 00 01  mov  %g1, %o4
a0099060:  82 0c a0 ff  and  %l2, 0xff, %g1
a0099064:  82 02 c0 01  add  %o3, %g1, %g1
a0099068:  83 28 60 02  sll  %g1, 2, %g1
a009906c:  a4 04 a0 01  inc  %l2
a0099070:  82 00 40 0a  add  %g1, %o2, %g1
a0099074:  9a 0c a0 ff  and  %l2, 0xff, %o5
a0099078:  c0 30 60 1c  clrh  [ %g1 + 0x1c ]
a009907c:  80 a3 40 0c  cmp  %o5, %o4
a0099080:  0a bf ff f8  bcs  0xa0099060
a0099084:  c0 30 60 1a  clrh  [ %g1 + 0x1a ]
a0099088:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a009908c:  a6 0e 20 ff  and  %i0, 0xff, %l3
a0099090:  a2 15 22 80  or  %l4, 0x280, %l1
a0099094:  a0 5c e0 b0  smul  %l3, 0xb0, %l0
a0099098:  c2 0c 40 10  ldub  [ %l1 + %l0 ], %g1
a009909c:  80 a0 60 03  cmp  %g1, 3
a00990a0:  12 80 00 17  bne  0xa00990fc
a00990a4:  80 a0 60 04  cmp  %g1, 4
a00990a8:  a4 0f 60 ff  and  %i5, 0xff, %l2
a00990ac:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a00990b0:  92 12 62 60  or  %o1, 0x260, %o1	! 0x2e60
a00990b4:  40 00 38 98  call  0xa00a7314
a00990b8:  90 10 00 12  mov  %l2, %o0
a00990bc:  91 32 20 18  srl  %o0, 0x18, %o0
a00990c0:  90 0a 20 0f  and  %o0, 0xf, %o0
a00990c4:  80 a2 20 07  cmp  %o0, 7
a00990c8:  a0 04 00 11  add  %l0, %l1, %l0
a00990cc:  02 80 00 2b  be  0xa0099178
a00990d0:  1b 2a 01 e1  sethi  %hi(0xa8078400), %o5
a00990d4:  c2 0c 20 2b  ldub  [ %l0 + 0x2b ], %g1
a00990d8:  92 00 60 01  add  %g1, 1, %o1
a00990dc:  d2 2c 20 2b  stb  %o1, [ %l0 + 0x2b ]
a00990e0:  c2 03 62 34  ld  [ %o5 + 0x234 ], %g1
a00990e4:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a00990e8:  80 88 68 00  btst  0x800, %g1
a00990ec:  12 80 00 19  bne  0xa0099150
a00990f0:  90 12 22 38  or  %o0, 0x238, %o0
a00990f4:  10 80 00 1a  b  0xa009915c
a00990f8:  c2 0c 20 2b  ldub  [ %l0 + 0x2b ], %g1
a00990fc:  12 80 00 20  bne  0xa009917c
a0099100:  a4 0f 60 ff  and  %i5, 0xff, %l2
a0099104:  13 00 00 0b  sethi  %hi(0x2c00), %o1
a0099108:  92 12 62 60  or  %o1, 0x260, %o1	! 0x2e60
a009910c:  40 00 38 82  call  0xa00a7314
a0099110:  90 10 00 12  mov  %l2, %o0
a0099114:  91 32 20 18  srl  %o0, 0x18, %o0
a0099118:  90 0a 20 0f  and  %o0, 0xf, %o0
a009911c:  80 a2 20 0f  cmp  %o0, 0xf
a0099120:  a0 04 00 11  add  %l0, %l1, %l0
a0099124:  02 80 00 15  be  0xa0099178
a0099128:  1b 2a 01 e1  sethi  %hi(0xa8078400), %o5
a009912c:  c2 0c 20 2b  ldub  [ %l0 + 0x2b ], %g1
a0099130:  92 00 60 01  add  %g1, 1, %o1
a0099134:  d2 2c 20 2b  stb  %o1, [ %l0 + 0x2b ]
a0099138:  c2 03 62 34  ld  [ %o5 + 0x234 ], %g1
a009913c:  80 88 68 00  btst  0x800, %g1
a0099140:  22 80 00 07  be,a   0xa009915c
a0099144:  c2 0c 20 2b  ldub  [ %l0 + 0x2b ], %g1
a0099148:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a009914c:  90 12 22 78  or  %o0, 0x278, %o0	! 0xa0069e78
a0099150:  7f ff 67 bd  call  0xa0073044
a0099154:  92 0a 60 ff  and  %o1, 0xff, %o1
a0099158:  c2 0c 20 2b  ldub  [ %l0 + 0x2b ], %g1
a009915c:  80 a0 60 03  cmp  %g1, 3
a0099160:  12 80 00 07  bne  0xa009917c
a0099164:  01 00 00 00  nop
a0099168:  c0 2c 20 2b  clrb  [ %l0 + 0x2b ]
a009916c:  7f ff 9c 36  call  0xa0080244
a0099170:  90 10 00 12  mov  %l2, %o0
a0099174:  30 80 00 f9  b,a   0xa0099558
a0099178:  c0 2c 20 2b  clrb  [ %l0 + 0x2b ]
a009917c:  7f ff fe 8d  call  0xa0098bb0
a0099180:  90 10 00 13  mov  %l3, %o0
a0099184:  21 2a 01 e1  sethi  %hi(0xa8078400), %l0
a0099188:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1	! 0xa8078634
a009918c:  80 88 68 00  btst  0x800, %g1
a0099190:  02 80 00 06  be  0xa00991a8
a0099194:  ac 10 00 08  mov  %o0, %l6
a0099198:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a009919c:  90 12 22 b8  or  %o0, 0x2b8, %o0	! 0xa0069eb8
a00991a0:  7f ff 67 a9  call  0xa0073044
a00991a4:  92 0d a0 ff  and  %l6, 0xff, %o1
a00991a8:  82 15 22 80  or  %l4, 0x280, %g1
a00991ac:  9a 5c e0 b0  smul  %l3, 0xb0, %o5
a00991b0:  9a 03 40 01  add  %o5, %g1, %o5
a00991b4:  c2 0b 60 02  ldub  [ %o5 + 2 ], %g1
a00991b8:  80 a0 60 06  cmp  %g1, 6
a00991bc:  12 80 00 09  bne  0xa00991e0
a00991c0:  90 0d a0 ff  and  %l6, 0xff, %o0
a00991c4:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a00991c8:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a00991cc:  80 88 68 00  btst  0x800, %g1
a00991d0:  12 80 00 3d  bne  0xa00992c4
a00991d4:  90 12 22 f0  or  %o0, 0x2f0, %o0
a00991d8:  10 80 00 d1  b  0xa009951c
a00991dc:  80 8d a0 ff  btst  0xff, %l6
a00991e0:  80 a2 20 00  cmp  %o0, 0
a00991e4:  02 80 00 d2  be  0xa009952c
a00991e8:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00991ec:  92 10 60 50  or  %g1, 0x50, %o1	! 0xa807cc50
a00991f0:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00991f4:  94 10 60 60  or  %g1, 0x60, %o2	! 0xa807cc60
a00991f8:  b8 10 20 01  mov  1, %i4
a00991fc:  10 80 00 13  b  0xa0099248
a0099200:  a4 10 20 00  clr  %l2
a0099204:  80 8a e0 01  btst  1, %o3
a0099208:  02 80 00 08  be  0xa0099228
a009920c:  c2 0a 40 0c  ldub  [ %o1 + %o4 ], %g1
a0099210:  da 0a 80 0c  ldub  [ %o2 + %o4 ], %o5
a0099214:  82 00 60 01  inc  %g1
a0099218:  9a 03 60 01  inc  %o5
a009921c:  c2 2a 40 0c  stb  %g1, [ %o1 + %o4 ]
a0099220:  da 2a 80 0c  stb  %o5, [ %o2 + %o4 ]
a0099224:  c2 0a 40 0c  ldub  [ %o1 + %o4 ], %g1
a0099228:  80 a0 60 01  cmp  %g1, 1
a009922c:  38 80 00 07  bgu,a   0xa0099248
a0099230:  b8 10 20 00  clr  %i4
a0099234:  c2 0a 80 0c  ldub  [ %o2 + %o4 ], %g1
a0099238:  80 a0 60 01  cmp  %g1, 1
a009923c:  08 80 00 04  bleu  0xa009924c
a0099240:  98 0c a0 ff  and  %l2, 0xff, %o4
a0099244:  b8 10 20 00  clr  %i4
a0099248:  98 0c a0 ff  and  %l2, 0xff, %o4
a009924c:  80 a3 20 04  cmp  %o4, 4
a0099250:  82 60 20 00  subx  %g0, 0, %g1
a0099254:  9a 0f 20 ff  and  %i4, 0xff, %o5
a0099258:  97 3a 00 0c  sra  %o0, %o4, %o3
a009925c:  80 88 40 0d  btst  %g1, %o5
a0099260:  12 bf ff e9  bne  0xa0099204
a0099264:  a4 04 a0 01  inc  %l2
a0099268:  80 a3 60 00  cmp  %o5, 0
a009926c:  22 80 00 0a  be,a   0xa0099294
a0099270:  96 15 22 80  or  %l4, 0x280, %o3
a0099274:  a0 0f 60 ff  and  %i5, 0xff, %l0
a0099278:  7f ff 86 47  call  0xa007ab94
a009927c:  90 10 00 10  mov  %l0, %o0
a0099280:  90 10 00 10  mov  %l0, %o0
a0099284:  7f ff 9b 5e  call  0xa007fffc
a0099288:  92 10 20 01  mov  1, %o1
a009928c:  10 bf ff 80  b  0xa009908c
a0099290:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a0099294:  82 5c e0 b0  smul  %l3, 0xb0, %g1
a0099298:  82 00 40 0b  add  %g1, %o3, %g1
a009929c:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a00992a0:  80 a0 60 01  cmp  %g1, 1
a00992a4:  12 80 00 0c  bne  0xa00992d4
a00992a8:  98 10 20 00  clr  %o4
a00992ac:  c2 04 22 34  ld  [ %l0 + 0x234 ], %g1
a00992b0:  80 88 60 02  btst  2, %g1
a00992b4:  22 80 00 9a  be,a   0xa009951c
a00992b8:  80 8d a0 ff  btst  0xff, %l6
a00992bc:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a00992c0:  90 12 23 18  or  %o0, 0x318, %o0	! 0xa0069f18
a00992c4:  7f ff 68 80  call  0xa00734c4
a00992c8:  01 00 00 00  nop
a00992cc:  10 80 00 94  b  0xa009951c
a00992d0:  80 8d a0 ff  btst  0xff, %l6
a00992d4:  9a 10 20 00  clr  %o5
a00992d8:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a00992dc:  c0 27 bf f0  clr  [ %fp + -16 ]
a00992e0:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a00992e4:  92 10 00 0b  mov  %o3, %o1
a00992e8:  90 5c e0 2c  smul  %l3, 0x2c, %o0
a00992ec:  a4 10 20 00  clr  %l2
a00992f0:  10 80 00 05  b  0xa0099304
a00992f4:  94 07 bf f8  add  %fp, -8, %o2
a00992f8:  c2 12 e0 1a  lduh  [ %o3 + 0x1a ], %g1
a00992fc:  c2 33 7f f0  sth  %g1, [ %o5 + -16 ]
a0099300:  c0 2b 3f f8  clrb  [ %o4 + -8 ]
a0099304:  82 0c a0 ff  and  %l2, 0xff, %g1
a0099308:  9a 02 00 01  add  %o0, %g1, %o5
a009930c:  9b 2b 60 02  sll  %o5, 2, %o5
a0099310:  96 03 40 09  add  %o5, %o1, %o3
a0099314:  9a 00 40 01  add  %g1, %g1, %o5
a0099318:  9a 03 40 0a  add  %o5, %o2, %o5
a009931c:  98 02 80 01  add  %o2, %g1, %o4
a0099320:  80 a0 60 03  cmp  %g1, 3
a0099324:  08 bf ff f5  bleu  0xa00992f8
a0099328:  a4 04 a0 01  inc  %l2
a009932c:  10 80 00 4c  b  0xa009945c
a0099330:  a4 10 20 00  clr  %l2
a0099334:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0099338:  9a 5b 60 2c  smul  %o5, 0x2c, %o5
a009933c:  9a 03 40 10  add  %o5, %l0, %o5
a0099340:  9a 03 40 0d  add  %o5, %o5, %o5
a0099344:  96 0c e0 ff  and  %l3, 0xff, %o3
a0099348:  9a 03 40 0b  add  %o5, %o3, %o5
a009934c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0099350:  9a 03 40 0d  add  %o5, %o5, %o5
a0099354:  82 10 62 80  or  %g1, 0x280, %g1
a0099358:  94 03 40 01  add  %o5, %g1, %o2
a009935c:  2f 2a 01 f3  sethi  %hi(0xa807cc00), %l7
a0099360:  9a 15 e0 50  or  %l7, 0x50, %o5	! 0xa807cc50
a0099364:  da 0b 40 10  ldub  [ %o5 + %l0 ], %o5
a0099368:  a8 07 bf f8  add  %fp, -8, %l4
a009936c:  82 04 00 10  add  %l0, %l0, %g1
a0099370:  80 a3 60 00  cmp  %o5, 0
a0099374:  a2 00 40 14  add  %g1, %l4, %l1
a0099378:  1b 2a 01 e1  sethi  %hi(0xa8078400), %o5
a009937c:  12 80 00 10  bne  0xa00993bc
a0099380:  aa 04 e0 01  add  %l3, 1, %l5
a0099384:  92 06 20 41  add  %i0, 0x41, %o1
a0099388:  93 2a 60 18  sll  %o1, 0x18, %o1
a009938c:  c2 03 62 34  ld  [ %o5 + 0x234 ], %g1
a0099390:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a0099394:  90 12 23 38  or  %o0, 0x338, %o0	! 0xa0069f38
a0099398:  93 3a 60 18  sra  %o1, 0x18, %o1
a009939c:  94 10 00 10  mov  %l0, %o2
a00993a0:  80 88 60 02  btst  2, %g1
a00993a4:  02 80 00 22  be  0xa009942c
a00993a8:  96 10 20 00  clr  %o3
a00993ac:  7f ff 67 26  call  0xa0073044
a00993b0:  01 00 00 00  nop
a00993b4:  10 80 00 1f  b  0xa0099430
a00993b8:  82 0d 60 ff  and  %l5, 0xff, %g1
a00993bc:  d8 03 62 34  ld  [ %o5 + 0x234 ], %o4
a00993c0:  c2 12 a0 1a  lduh  [ %o2 + 0x1a ], %g1
a00993c4:  92 06 20 41  add  %i0, 0x41, %o1
a00993c8:  93 2a 60 18  sll  %o1, 0x18, %o1
a00993cc:  9b 28 60 10  sll  %g1, 0x10, %o5
a00993d0:  80 8b 20 02  btst  2, %o4
a00993d4:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a00993d8:  9e 05 00 10  add  %l4, %l0, %o7
a00993dc:  c2 34 7f e8  sth  %g1, [ %l1 + -24 ]
a00993e0:  90 12 23 78  or  %o0, 0x378, %o0
a00993e4:  93 3a 60 18  sra  %o1, 0x18, %o1
a00993e8:  9b 33 60 10  srl  %o5, 0x10, %o5
a00993ec:  94 10 00 10  mov  %l0, %o2
a00993f0:  02 80 00 09  be  0xa0099414
a00993f4:  98 10 00 10  mov  %l0, %o4
a00993f8:  c2 0b ff f8  ldub  [ %o7 + -8 ], %g1
a00993fc:  de 14 7f f0  lduh  [ %l1 + -16 ], %o7
a0099400:  c2 23 a0 60  st  %g1, [ %sp + 0x60 ]
a0099404:  de 23 a0 68  st  %o7, [ %sp + 0x68 ]
a0099408:  e0 23 a0 5c  st  %l0, [ %sp + 0x5c ]
a009940c:  7f ff 67 0e  call  0xa0073044
a0099410:  e0 23 a0 64  st  %l0, [ %sp + 0x64 ]
a0099414:  c2 14 7f e8  lduh  [ %l1 + -24 ], %g1
a0099418:  da 14 7f f0  lduh  [ %l1 + -16 ], %o5
a009941c:  80 a0 40 0d  cmp  %g1, %o5
a0099420:  1a 80 00 03  bcc  0xa009942c
a0099424:  82 05 00 10  add  %l4, %l0, %g1
a0099428:  e6 28 7f f8  stb  %l3, [ %g1 + -8 ]
a009942c:  82 0d 60 ff  and  %l5, 0xff, %g1
a0099430:  80 a0 60 01  cmp  %g1, 1
a0099434:  08 bf ff c0  bleu  0xa0099334
a0099438:  a6 10 00 15  mov  %l5, %l3
a009943c:  82 07 80 10  add  %fp, %l0, %g1
a0099440:  da 08 7f f0  ldub  [ %g1 + -16 ], %o5
a0099444:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0099448:  98 15 e0 50  or  %l7, 0x50, %o4
a009944c:  82 10 60 60  or  %g1, 0x60, %g1
a0099450:  da 28 40 10  stb  %o5, [ %g1 + %l0 ]
a0099454:  da 2b 00 10  stb  %o5, [ %o4 + %l0 ]
a0099458:  a4 04 a0 01  inc  %l2
a009945c:  a0 0c a0 ff  and  %l2, 0xff, %l0
a0099460:  80 a4 20 03  cmp  %l0, 3
a0099464:  28 bf ff b4  bleu,a   0xa0099334
a0099468:  a6 10 20 01  mov  1, %l3
a009946c:  10 80 00 21  b  0xa00994f0
a0099470:  a4 10 20 00  clr  %l2
a0099474:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0099478:  9a 5b 60 2c  smul  %o5, 0x2c, %o5
a009947c:  9a 03 40 10  add  %o5, %l0, %o5
a0099480:  98 0c e0 ff  and  %l3, 0xff, %o4
a0099484:  9a 03 40 0d  add  %o5, %o5, %o5
a0099488:  9a 03 40 0c  add  %o5, %o4, %o5
a009948c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0099490:  82 10 62 80  or  %g1, 0x280, %g1	! 0xa807d680
a0099494:  9a 03 40 0d  add  %o5, %o5, %o5
a0099498:  9a 03 40 01  add  %o5, %g1, %o5
a009949c:  92 06 20 41  add  %i0, 0x41, %o1
a00994a0:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00994a4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00994a8:  93 2a 60 18  sll  %o1, 0x18, %o1
a00994ac:  11 28 01 a7  sethi  %hi(0xa0069c00), %o0
a00994b0:  a6 04 e0 01  inc  %l3
a00994b4:  80 88 60 02  btst  2, %g1
a00994b8:  90 12 23 f0  or  %o0, 0x3f0, %o0
a00994bc:  93 3a 60 18  sra  %o1, 0x18, %o1
a00994c0:  02 80 00 07  be  0xa00994dc
a00994c4:  94 10 00 10  mov  %l0, %o2
a00994c8:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00994cc:  82 10 60 50  or  %g1, 0x50, %g1	! 0xa807cc50
a00994d0:  d6 08 40 10  ldub  [ %g1 + %l0 ], %o3
a00994d4:  7f ff 66 dc  call  0xa0073044
a00994d8:  da 13 60 1a  lduh  [ %o5 + 0x1a ], %o5
a00994dc:  82 0c e0 ff  and  %l3, 0xff, %g1
a00994e0:  80 a0 60 01  cmp  %g1, 1
a00994e4:  08 bf ff e5  bleu  0xa0099478
a00994e8:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00994ec:  a4 04 a0 01  inc  %l2
a00994f0:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00994f4:  80 a4 20 03  cmp  %l0, 3
a00994f8:  28 bf ff df  bleu,a   0xa0099474
a00994fc:  a6 10 20 00  clr  %l3
a0099500:  a0 0f 60 ff  and  %i5, 0xff, %l0
a0099504:  7f ff 85 a4  call  0xa007ab94
a0099508:  90 10 00 10  mov  %l0, %o0
a009950c:  90 10 00 10  mov  %l0, %o0
a0099510:  7f ff 9a bb  call  0xa007fffc
a0099514:  92 10 20 01  mov  1, %o1
a0099518:  80 8d a0 ff  btst  0xff, %l6
a009951c:  02 80 00 04  be  0xa009952c
a0099520:  80 8f 20 ff  btst  0xff, %i4
a0099524:  12 80 00 0d  bne  0xa0099558
a0099528:  01 00 00 00  nop
a009952c:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0099530:  98 03 40 0d  add  %o5, %o5, %o4
a0099534:  98 03 00 0d  add  %o4, %o5, %o4
a0099538:  82 10 20 09  mov  9, %g1
a009953c:  96 16 e2 48  or  %i3, 0x248, %o3
a0099540:  9b 2b 60 02  sll  %o5, 2, %o5
a0099544:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a0099548:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009954c:  99 2b 20 03  sll  %o4, 3, %o4
a0099550:  82 10 62 50  or  %g1, 0x250, %g1
a0099554:  c0 20 40 0c  clr  [ %g1 + %o4 ]
a0099558:  81 c7 e0 08  ret
a009955c:  91 e8 20 00  restore  %g0, 0, %o0
