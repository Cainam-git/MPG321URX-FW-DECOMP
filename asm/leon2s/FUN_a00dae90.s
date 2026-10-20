# leon2s FUN_a00dae90 0xa00dae90-0xa00db53c (1708 bytes)
a00dae90:  9d e3 bf 50  save  %sp, -176, %sp
a00dae94:  a6 07 bf b8  add  %fp, -72, %l3
a00dae98:  90 10 00 13  mov  %l3, %o0
a00dae9c:  92 10 20 00  clr  %o1
a00daea0:  40 3b 99 c3  call  0xa0fc15ac
a00daea4:  94 10 20 40  mov  0x40, %o2
a00daea8:  b4 0e a0 ff  and  %i2, 0xff, %i2
a00daeac:  80 a6 a0 00  cmp  %i2, 0
a00daeb0:  12 80 01 3a  bne  0xa00db398
a00daeb4:  21 2a 01 d8  sethi  %hi(0xa8076000), %l0
a00daeb8:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00daebc:  c2 0c a0 32  ldub  [ %l2 + 0x32 ], %g1	! 0xa8078832
a00daec0:  83 28 60 02  sll  %g1, 2, %g1
a00daec4:  9a 14 20 9c  or  %l0, 0x9c, %o5
a00daec8:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00daecc:  c2 00 62 58  ld  [ %g1 + 0x258 ], %g1
a00daed0:  80 88 60 04  btst  4, %g1
a00daed4:  12 80 00 0f  bne  0xa00daf10
a00daed8:  a2 10 20 13  mov  0x13, %l1
a00daedc:  40 3b 9a 2e  call  0xa0fc1794
a00daee0:  90 10 20 05  mov  5, %o0
a00daee4:  c2 0c a0 32  ldub  [ %l2 + 0x32 ], %g1
a00daee8:  83 28 60 02  sll  %g1, 2, %g1
a00daeec:  9a 14 20 9c  or  %l0, 0x9c, %o5
a00daef0:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00daef4:  c2 00 62 58  ld  [ %g1 + 0x258 ], %g1
a00daef8:  80 88 60 04  btst  4, %g1
a00daefc:  12 80 00 05  bne  0xa00daf10
a00daf00:  a2 04 7f ff  add  %l1, -1, %l1
a00daf04:  80 8c 60 ff  btst  0xff, %l1
a00daf08:  12 bf ff f5  bne  0xa00daedc
a00daf0c:  01 00 00 00  nop
a00daf10:  29 2a 01 e2  sethi  %hi(0xa8078800), %l4
a00daf14:  c2 0d 20 32  ldub  [ %l4 + 0x32 ], %g1	! 0xa8078832
a00daf18:  21 2a 01 d8  sethi  %hi(0xa8076000), %l0
a00daf1c:  a0 14 20 a4  or  %l0, 0xa4, %l0	! 0xa80760a4
a00daf20:  83 28 60 02  sll  %g1, 2, %g1
a00daf24:  da 04 00 01  ld  [ %l0 + %g1 ], %o5
a00daf28:  c2 03 60 c0  ld  [ %o5 + 0xc0 ], %g1
a00daf2c:  82 10 60 80  or  %g1, 0x80, %g1
a00daf30:  c2 23 60 c0  st  %g1, [ %o5 + 0xc0 ]
a00daf34:  92 10 00 13  mov  %l3, %o1
a00daf38:  40 3b 99 17  call  0xa0fc1394
a00daf3c:  90 10 20 00  clr  %o0
a00daf40:  c2 0d 20 32  ldub  [ %l4 + 0x32 ], %g1
a00daf44:  83 28 60 02  sll  %g1, 2, %g1
a00daf48:  da 04 00 01  ld  [ %l0 + %g1 ], %o5
a00daf4c:  c2 03 60 c0  ld  [ %o5 + 0xc0 ], %g1
a00daf50:  82 08 7f 7f  and  %g1, -129, %g1
a00daf54:  c2 23 60 c0  st  %g1, [ %o5 + 0xc0 ]
a00daf58:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00daf5c:  94 10 61 d8  or  %g1, 0x1d8, %o2	! 0xa80795d8
a00daf60:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00daf64:  96 10 60 20  or  %g1, 0x20, %o3	! 0xa807a820
a00daf68:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00daf6c:  98 10 61 d0  or  %g1, 0x1d0, %o4	! 0xa80795d0
a00daf70:  a2 10 20 00  clr  %l1
a00daf74:  82 0c 60 ff  and  %l1, 0xff, %g1
a00daf78:  a2 04 60 01  inc  %l1
a00daf7c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00daf80:  c0 2b 00 01  clrb  [ %o4 + %g1 ]
a00daf84:  80 a3 60 03  cmp  %o5, 3
a00daf88:  c0 2a 80 01  clrb  [ %o2 + %g1 ]
a00daf8c:  08 bf ff fa  bleu  0xa00daf74
a00daf90:  c0 2a c0 01  clrb  [ %o3 + %g1 ]
a00daf94:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00daf98:  13 27 c7 32  sethi  %hi(0x9f1cc800), %o1
a00daf9c:  90 12 22 08  or  %o0, 0x208, %o0
a00dafa0:  40 3a a0 29  call  0xa0f83044
a00dafa4:  92 12 62 20  or  %o1, 0x220, %o1
a00dafa8:  a2 10 20 00  clr  %l1
a00dafac:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00dafb0:  40 3a a0 25  call  0xa0f83044
a00dafb4:  90 12 22 28  or  %o0, 0x228, %o0	! 0x9f1cca28
a00dafb8:  a4 10 20 00  clr  %l2
a00dafbc:  82 0c 60 ff  and  %l1, 0xff, %g1
a00dafc0:  83 28 60 03  sll  %g1, 3, %g1
a00dafc4:  a6 07 bf f8  add  %fp, -8, %l3
a00dafc8:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00dafcc:  82 00 40 13  add  %g1, %l3, %g1
a00dafd0:  82 00 40 0d  add  %g1, %o5, %g1
a00dafd4:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00dafd8:  d2 08 7f c0  ldub  [ %g1 + -64 ], %o1
a00dafdc:  40 3a a0 1a  call  0xa0f83044
a00dafe0:  90 12 22 30  or  %o0, 0x230, %o0
a00dafe4:  a4 04 a0 01  inc  %l2
a00dafe8:  82 0c a0 ff  and  %l2, 0xff, %g1
a00dafec:  80 a0 60 07  cmp  %g1, 7
a00daff0:  08 bf ff f4  bleu  0xa00dafc0
a00daff4:  82 0c 60 ff  and  %l1, 0xff, %g1
a00daff8:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00daffc:  13 27 c7 32  sethi  %hi(0x9f1cc800), %o1
a00db000:  90 12 22 38  or  %o0, 0x238, %o0
a00db004:  40 3a a0 10  call  0xa0f83044
a00db008:  92 12 62 40  or  %o1, 0x240, %o1
a00db00c:  a2 04 60 01  inc  %l1
a00db010:  82 0c 60 ff  and  %l1, 0xff, %g1
a00db014:  80 a0 60 07  cmp  %g1, 7
a00db018:  08 bf ff e6  bleu  0xa00dafb0
a00db01c:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db020:  a4 10 20 00  clr  %l2
a00db024:  a2 10 20 00  clr  %l1
a00db028:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00db02c:  82 04 c0 0d  add  %l3, %o5, %g1
a00db030:  d6 08 7f c0  ldub  [ %g1 + -64 ], %o3
a00db034:  98 0a e0 ff  and  %o3, 0xff, %o4
a00db038:  80 a3 20 00  cmp  %o4, 0
a00db03c:  22 80 00 3b  be,a   0xa00db128
a00db040:  a2 04 60 01  inc  %l1
a00db044:  80 a3 60 00  cmp  %o5, 0
a00db048:  1b 2a 01 e5  sethi  %hi(0xa8079400), %o5
a00db04c:  12 80 00 15  bne  0xa00db0a0
a00db050:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00db054:  c2 0f bf b8  ldub  [ %fp + -72 ], %g1
a00db058:  9a 13 61 d8  or  %o5, 0x1d8, %o5
a00db05c:  80 a0 60 00  cmp  %g1, 0
a00db060:  02 80 00 31  be  0xa00db124
a00db064:  c2 2b 40 10  stb  %g1, [ %o5 + %l0 ]
a00db068:  40 3a fb 79  call  0xa0f99e4c
a00db06c:  90 10 20 00  clr  %o0
a00db070:  90 0a 20 ff  and  %o0, 0xff, %o0
a00db074:  80 a2 20 01  cmp  %o0, 1
a00db078:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00db07c:  12 80 00 05  bne  0xa00db090
a00db080:  17 2a 01 e5  sethi  %hi(0xa8079400), %o3
a00db084:  82 10 60 20  or  %g1, 0x20, %g1
a00db088:  10 80 00 24  b  0xa00db118
a00db08c:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a00db090:  9a 10 60 20  or  %g1, 0x20, %o5
a00db094:  82 10 20 01  mov  1, %g1
a00db098:  10 80 00 20  b  0xa00db118
a00db09c:  c2 2b 40 10  stb  %g1, [ %o5 + %l0 ]
a00db0a0:  9a 13 61 d8  or  %o5, 0x1d8, %o5
a00db0a4:  c2 0b 40 10  ldub  [ %o5 + %l0 ], %g1
a00db0a8:  80 a3 00 01  cmp  %o4, %g1
a00db0ac:  32 80 00 07  bne,a   0xa00db0c8
a00db0b0:  82 04 20 01  add  %l0, 1, %g1
a00db0b4:  1b 2a 01 e5  sethi  %hi(0xa8079400), %o5
a00db0b8:  9a 13 61 d0  or  %o5, 0x1d0, %o5	! 0xa80795d0
a00db0bc:  c2 0b 40 10  ldub  [ %o5 + %l0 ], %g1
a00db0c0:  10 80 00 18  b  0xa00db120
a00db0c4:  82 00 60 01  inc  %g1
a00db0c8:  80 a0 60 03  cmp  %g1, 3
a00db0cc:  14 80 00 1b  bg  0xa00db138
a00db0d0:  80 a3 20 00  cmp  %o4, 0
a00db0d4:  a4 04 a0 01  inc  %l2
a00db0d8:  a0 0c a0 ff  and  %l2, 0xff, %l0
a00db0dc:  02 80 00 12  be  0xa00db124
a00db0e0:  d6 2b 40 10  stb  %o3, [ %o5 + %l0 ]
a00db0e4:  40 3a fb 5a  call  0xa0f99e4c
a00db0e8:  90 10 20 00  clr  %o0
a00db0ec:  90 0a 20 ff  and  %o0, 0xff, %o0
a00db0f0:  80 a2 20 01  cmp  %o0, 1
a00db0f4:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00db0f8:  17 2a 01 e5  sethi  %hi(0xa8079400), %o3
a00db0fc:  12 80 00 05  bne  0xa00db110
a00db100:  98 04 60 01  add  %l1, 1, %o4
a00db104:  82 10 60 20  or  %g1, 0x20, %g1
a00db108:  10 80 00 04  b  0xa00db118
a00db10c:  e2 28 40 10  stb  %l1, [ %g1 + %l0 ]
a00db110:  82 10 60 20  or  %g1, 0x20, %g1
a00db114:  d8 28 40 10  stb  %o4, [ %g1 + %l0 ]
a00db118:  9a 12 e1 d0  or  %o3, 0x1d0, %o5
a00db11c:  82 10 20 01  mov  1, %g1
a00db120:  c2 2b 40 10  stb  %g1, [ %o5 + %l0 ]
a00db124:  a2 04 60 01  inc  %l1
a00db128:  82 0c 60 ff  and  %l1, 0xff, %g1
a00db12c:  80 a0 60 3e  cmp  %g1, 0x3e
a00db130:  08 bf ff bf  bleu  0xa00db02c
a00db134:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00db138:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db13c:  40 3a a0 e2  call  0xa0f834c4
a00db140:  90 12 22 48  or  %o0, 0x248, %o0	! 0x9f1cca48
a00db144:  a2 10 20 00  clr  %l1
a00db148:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db14c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00db150:  82 10 61 d0  or  %g1, 0x1d0, %g1
a00db154:  d6 08 40 0d  ldub  [ %g1 + %o5 ], %o3
a00db158:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db15c:  82 10 61 d8  or  %g1, 0x1d8, %g1	! 0xa80795d8
a00db160:  d2 08 40 0d  ldub  [ %g1 + %o5 ], %o1
a00db164:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00db168:  82 10 60 20  or  %g1, 0x20, %g1	! 0xa807a820
a00db16c:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db170:  d4 08 40 0d  ldub  [ %g1 + %o5 ], %o2
a00db174:  40 3a 9f b4  call  0xa0f83044
a00db178:  90 12 22 58  or  %o0, 0x258, %o0
a00db17c:  a2 04 60 01  inc  %l1
a00db180:  82 0c 60 ff  and  %l1, 0xff, %g1
a00db184:  80 a0 60 03  cmp  %g1, 3
a00db188:  08 bf ff f1  bleu  0xa00db14c
a00db18c:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db190:  40 3a fb 2f  call  0xa0f99e4c
a00db194:  90 10 20 00  clr  %o0
a00db198:  90 0a 20 ff  and  %o0, 0xff, %o0
a00db19c:  80 a2 20 00  cmp  %o0, 0
a00db1a0:  12 80 00 7e  bne  0xa00db398
a00db1a4:  27 2a 01 d8  sethi  %hi(0xa8076000), %l3
a00db1a8:  c2 0c e0 ac  ldub  [ %l3 + 0xac ], %g1	! 0xa80760ac
a00db1ac:  80 a2 00 01  cmp  %o0, %g1
a00db1b0:  a4 10 20 00  clr  %l2
a00db1b4:  1a 80 00 43  bcc  0xa00db2c0
a00db1b8:  c2 0d 20 32  ldub  [ %l4 + 0x32 ], %g1
a00db1bc:  19 2a 01 d8  sethi  %hi(0xa8076000), %o4
a00db1c0:  98 13 20 9c  or  %o4, 0x9c, %o4	! 0xa807609c
a00db1c4:  83 28 60 02  sll  %g1, 2, %g1
a00db1c8:  d6 03 00 01  ld  [ %o4 + %g1 ], %o3
a00db1cc:  da 02 e2 ac  ld  [ %o3 + 0x2ac ], %o5
a00db1d0:  82 0c a0 ff  and  %l2, 0xff, %g1
a00db1d4:  83 28 60 06  sll  %g1, 6, %g1
a00db1d8:  9a 0b 60 3f  and  %o5, 0x3f, %o5
a00db1dc:  9a 13 40 01  or  %o5, %g1, %o5
a00db1e0:  da 22 e2 ac  st  %o5, [ %o3 + 0x2ac ]
a00db1e4:  c2 0d 20 32  ldub  [ %l4 + 0x32 ], %g1
a00db1e8:  83 28 60 02  sll  %g1, 2, %g1
a00db1ec:  c2 03 00 01  ld  [ %o4 + %g1 ], %g1
a00db1f0:  c2 00 62 84  ld  [ %g1 + 0x284 ], %g1
a00db1f4:  a0 08 60 ff  and  %g1, 0xff, %l0
a00db1f8:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db1fc:  92 10 00 10  mov  %l0, %o1
a00db200:  40 3a 9f 91  call  0xa0f83044
a00db204:  90 12 22 80  or  %o0, 0x280, %o0
a00db208:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db20c:  94 10 61 d8  or  %g1, 0x1d8, %o2	! 0xa80795d8
a00db210:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db214:  96 10 61 d0  or  %g1, 0x1d0, %o3	! 0xa80795d0
a00db218:  92 10 20 00  clr  %o1
a00db21c:  a2 10 20 00  clr  %l1
a00db220:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00db224:  a2 04 60 01  inc  %l1
a00db228:  c2 0a 80 0d  ldub  [ %o2 + %o5 ], %g1
a00db22c:  80 a0 40 10  cmp  %g1, %l0
a00db230:  12 80 00 05  bne  0xa00db244
a00db234:  98 0c 60 ff  and  %l1, 0xff, %o4
a00db238:  d2 0a c0 0d  ldub  [ %o3 + %o5 ], %o1
a00db23c:  10 80 00 05  b  0xa00db250
a00db240:  c0 2a c0 0d  clrb  [ %o3 + %o5 ]
a00db244:  80 a3 20 03  cmp  %o4, 3
a00db248:  08 bf ff f7  bleu  0xa00db224
a00db24c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00db250:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db254:  90 10 61 d8  or  %g1, 0x1d8, %o0	! 0xa80795d8
a00db258:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db25c:  94 10 61 d0  or  %g1, 0x1d0, %o2	! 0xa80795d0
a00db260:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00db264:  96 10 60 20  or  %g1, 0x20, %o3	! 0xa807a820
a00db268:  a2 10 20 00  clr  %l1
a00db26c:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00db270:  a2 04 60 01  inc  %l1
a00db274:  c2 0a 00 0d  ldub  [ %o0 + %o5 ], %g1
a00db278:  80 a0 60 00  cmp  %g1, 0
a00db27c:  02 80 00 09  be  0xa00db2a0
a00db280:  98 0c 60 ff  and  %l1, 0xff, %o4
a00db284:  c2 0a 80 0d  ldub  [ %o2 + %o5 ], %g1
a00db288:  80 a0 60 00  cmp  %g1, 0
a00db28c:  02 80 00 06  be  0xa00db2a4
a00db290:  80 a3 20 03  cmp  %o4, 3
a00db294:  c2 0a c0 0d  ldub  [ %o3 + %o5 ], %g1
a00db298:  82 20 40 09  sub  %g1, %o1, %g1
a00db29c:  c2 2a c0 0d  stb  %g1, [ %o3 + %o5 ]
a00db2a0:  80 a3 20 03  cmp  %o4, 3
a00db2a4:  08 bf ff f3  bleu  0xa00db270
a00db2a8:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00db2ac:  a4 04 a0 01  inc  %l2
a00db2b0:  9a 0c a0 ff  and  %l2, 0xff, %o5
a00db2b4:  c2 0c e0 ac  ldub  [ %l3 + 0xac ], %g1
a00db2b8:  10 bf ff bf  b  0xa00db1b4
a00db2bc:  80 a3 40 01  cmp  %o5, %g1
a00db2c0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00db2c4:  da 08 60 32  ldub  [ %g1 + 0x32 ], %o5	! 0xa8078832
a00db2c8:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00db2cc:  82 10 60 9c  or  %g1, 0x9c, %g1	! 0xa807609c
a00db2d0:  9b 2b 60 02  sll  %o5, 2, %o5
a00db2d4:  da 00 40 0d  ld  [ %g1 + %o5 ], %o5
a00db2d8:  c2 03 62 ac  ld  [ %o5 + 0x2ac ], %g1
a00db2dc:  82 08 60 3f  and  %g1, 0x3f, %g1
a00db2e0:  c2 23 62 ac  st  %g1, [ %o5 + 0x2ac ]
a00db2e4:  80 8e 60 ff  btst  0xff, %i1
a00db2e8:  02 80 00 2c  be  0xa00db398
a00db2ec:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db2f0:  aa 10 61 d8  or  %g1, 0x1d8, %l5	! 0xa80795d8
a00db2f4:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db2f8:  9e 10 61 d0  or  %g1, 0x1d0, %o7	! 0xa80795d0
a00db2fc:  2f 2a 01 e5  sethi  %hi(0xa8079400), %l7
a00db300:  2d 2a 01 e7  sethi  %hi(0xa8079c00), %l6
a00db304:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00db308:  90 10 60 20  or  %g1, 0x20, %o0	! 0xa807a820
a00db30c:  92 10 20 00  clr  %o1
a00db310:  a4 10 20 00  clr  %l2
a00db314:  a2 10 20 00  clr  %l1
a00db318:  e6 0d e2 3c  ldub  [ %l7 + 0x23c ], %l3
a00db31c:  a8 0e 20 ff  and  %i0, 0xff, %l4
a00db320:  e0 0d a0 61  ldub  [ %l6 + 0x61 ], %l0
a00db324:  96 0c 60 ff  and  %l1, 0xff, %o3
a00db328:  d4 0d 40 0b  ldub  [ %l5 + %o3 ], %o2
a00db32c:  82 0a a0 ff  and  %o2, 0xff, %g1
a00db330:  80 a0 60 00  cmp  %g1, 0
a00db334:  02 80 00 17  be  0xa00db390
a00db338:  80 a0 40 14  cmp  %g1, %l4
a00db33c:  12 80 00 07  bne  0xa00db358
a00db340:  98 0c a0 ff  and  %l2, 0xff, %o4
a00db344:  c2 0b c0 0b  ldub  [ %o7 + %o3 ], %g1
a00db348:  92 02 40 01  add  %o1, %g1, %o1
a00db34c:  a0 10 00 0a  mov  %o2, %l0
a00db350:  10 80 00 0b  b  0xa00db37c
a00db354:  e6 0a 00 0b  ldub  [ %o0 + %o3 ], %l3
a00db358:  80 8a 60 ff  btst  0xff, %o1
a00db35c:  02 80 00 08  be  0xa00db37c
a00db360:  a4 04 a0 01  inc  %l2
a00db364:  da 0a 00 0b  ldub  [ %o0 + %o3 ], %o5
a00db368:  9a 23 40 09  sub  %o5, %o1, %o5
a00db36c:  c2 0b c0 0b  ldub  [ %o7 + %o3 ], %g1
a00db370:  c2 2b c0 0c  stb  %g1, [ %o7 + %o4 ]
a00db374:  d4 2d 40 0c  stb  %o2, [ %l5 + %o4 ]
a00db378:  da 2a 00 0c  stb  %o5, [ %o0 + %o4 ]
a00db37c:  a2 04 60 01  inc  %l1
a00db380:  82 0c 60 ff  and  %l1, 0xff, %g1
a00db384:  80 a0 60 03  cmp  %g1, 3
a00db388:  08 bf ff e8  bleu  0xa00db328
a00db38c:  96 0c 60 ff  and  %l1, 0xff, %o3
a00db390:  e0 2d a0 61  stb  %l0, [ %l6 + 0x61 ]
a00db394:  e6 2d e2 3c  stb  %l3, [ %l7 + 0x23c ]
a00db398:  40 3a fa ad  call  0xa0f99e4c
a00db39c:  90 10 20 00  clr  %o0
a00db3a0:  80 8a 20 ff  btst  0xff, %o0
a00db3a4:  32 80 00 1a  bne,a   0xa00db40c
a00db3a8:  90 10 20 00  clr  %o0
a00db3ac:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db3b0:  90 12 22 98  or  %o0, 0x298, %o0	! 0x9f1cca98
a00db3b4:  40 3a 9f 24  call  0xa0f83044
a00db3b8:  92 10 20 01  mov  1, %o1
a00db3bc:  a2 10 20 00  clr  %l1
a00db3c0:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db3c4:  9a 0c 60 ff  and  %l1, 0xff, %o5
a00db3c8:  82 10 61 d0  or  %g1, 0x1d0, %g1
a00db3cc:  d6 08 40 0d  ldub  [ %g1 + %o5 ], %o3
a00db3d0:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db3d4:  82 10 61 d8  or  %g1, 0x1d8, %g1	! 0xa80795d8
a00db3d8:  d2 08 40 0d  ldub  [ %g1 + %o5 ], %o1
a00db3dc:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00db3e0:  82 10 60 20  or  %g1, 0x20, %g1	! 0xa807a820
a00db3e4:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db3e8:  d4 08 40 0d  ldub  [ %g1 + %o5 ], %o2
a00db3ec:  40 3a 9f 16  call  0xa0f83044
a00db3f0:  90 12 22 58  or  %o0, 0x258, %o0
a00db3f4:  a2 04 60 01  inc  %l1
a00db3f8:  82 0c 60 ff  and  %l1, 0xff, %g1
a00db3fc:  80 a0 60 03  cmp  %g1, 3
a00db400:  08 bf ff f1  bleu  0xa00db3c4
a00db404:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db408:  90 10 20 00  clr  %o0
a00db40c:  92 10 20 80  mov  0x80, %o1
a00db410:  94 10 22 c0  mov  0x2c0, %o2
a00db414:  40 3a eb d3  call  0xa0f96360
a00db418:  96 10 20 01  mov  1, %o3
a00db41c:  80 8a 20 ff  btst  0xff, %o0
a00db420:  02 80 00 05  be  0xa00db434
a00db424:  80 a6 a0 00  cmp  %i2, 0
a00db428:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db42c:  10 80 00 1d  b  0xa00db4a0
a00db430:  90 12 22 a8  or  %o0, 0x2a8, %o0	! 0x9f1ccaa8
a00db434:  02 80 00 07  be  0xa00db450
a00db438:  80 8e 60 ff  btst  0xff, %i1
a00db43c:  82 10 20 3f  mov  0x3f, %g1
a00db440:  c2 2f bf b2  stb  %g1, [ %fp + -78 ]
a00db444:  c0 2f bf b0  clrb  [ %fp + -80 ]
a00db448:  10 80 00 0b  b  0xa00db474
a00db44c:  c0 2f bf b1  clrb  [ %fp + -79 ]
a00db450:  02 80 00 17  be  0xa00db4ac
a00db454:  a2 10 20 00  clr  %l1
a00db458:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00db45c:  da 08 60 61  ldub  [ %g1 + 0x61 ], %o5	! 0xa8079c61
a00db460:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db464:  c2 08 62 3c  ldub  [ %g1 + 0x23c ], %g1	! 0xa807963c
a00db468:  da 2f bf b0  stb  %o5, [ %fp + -80 ]
a00db46c:  c2 2f bf b1  stb  %g1, [ %fp + -79 ]
a00db470:  c0 2f bf b2  clrb  [ %fp + -78 ]
a00db474:  90 10 20 00  clr  %o0
a00db478:  92 10 20 80  mov  0x80, %o1
a00db47c:  94 10 21 c0  mov  0x1c0, %o2
a00db480:  96 10 20 02  mov  2, %o3
a00db484:  40 3a eb d4  call  0xa0f963d4
a00db488:  98 07 bf b0  add  %fp, -80, %o4
a00db48c:  80 8a 20 ff  btst  0xff, %o0
a00db490:  32 80 00 29  bne,a   0xa00db534
a00db494:  b0 10 20 01  mov  1, %i0
a00db498:  11 27 c7 32  sethi  %hi(0x9f1cc800), %o0
a00db49c:  90 12 22 c8  or  %o0, 0x2c8, %o0	! 0x9f1ccac8
a00db4a0:  40 3a a0 09  call  0xa0f834c4
a00db4a4:  b0 10 20 00  clr  %i0
a00db4a8:  30 80 00 23  b,a   0xa00db534
a00db4ac:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db4b0:  9e 0c 60 ff  and  %l1, 0xff, %o7
a00db4b4:  82 10 61 d8  or  %g1, 0x1d8, %g1
a00db4b8:  e0 08 40 0f  ldub  [ %g1 + %o7 ], %l0
a00db4bc:  82 0c 20 ff  and  %l0, 0xff, %g1
a00db4c0:  a2 04 60 01  inc  %l1
a00db4c4:  90 10 20 00  clr  %o0
a00db4c8:  92 10 20 80  mov  0x80, %o1
a00db4cc:  94 10 21 c0  mov  0x1c0, %o2
a00db4d0:  96 10 20 02  mov  2, %o3
a00db4d4:  98 07 bf b0  add  %fp, -80, %o4
a00db4d8:  80 a0 60 00  cmp  %g1, 0
a00db4dc:  02 80 00 15  be  0xa00db530
a00db4e0:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00db4e4:  80 a0 40 0d  cmp  %g1, %o5
a00db4e8:  12 80 00 0f  bne  0xa00db524
a00db4ec:  82 0c 60 ff  and  %l1, 0xff, %g1
a00db4f0:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db4f4:  82 10 61 d0  or  %g1, 0x1d0, %g1	! 0xa80795d0
a00db4f8:  da 08 40 0f  ldub  [ %g1 + %o7 ], %o5
a00db4fc:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00db500:  82 10 60 20  or  %g1, 0x20, %g1	! 0xa807a820
a00db504:  c2 08 40 0f  ldub  [ %g1 + %o7 ], %g1
a00db508:  e0 2f bf b0  stb  %l0, [ %fp + -80 ]
a00db50c:  c2 2f bf b1  stb  %g1, [ %fp + -79 ]
a00db510:  40 3a eb b1  call  0xa0f963d4
a00db514:  da 2f bf b2  stb  %o5, [ %fp + -78 ]
a00db518:  80 8a 20 ff  btst  0xff, %o0
a00db51c:  02 bf ff df  be  0xa00db498
a00db520:  82 0c 60 ff  and  %l1, 0xff, %g1
a00db524:  80 a0 60 03  cmp  %g1, 3
a00db528:  08 bf ff e2  bleu  0xa00db4b0
a00db52c:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a00db530:  b0 10 20 01  mov  1, %i0
a00db534:  81 c7 e0 08  ret
a00db538:  81 e8 00 00  restore
