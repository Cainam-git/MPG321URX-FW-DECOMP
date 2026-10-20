# leon2m FUN_a00e7eb0 0xa00e7eb0-0xa00e8e6c (4028 bytes)
a00e7eb0:  9d e3 bf 90  save  %sp, -112, %sp
a00e7eb4:  90 10 20 07  mov  7, %o0
a00e7eb8:  92 10 00 18  mov  %i0, %o1
a00e7ebc:  7f ff e0 3e  call  0xa00dffb4
a00e7ec0:  94 10 00 1b  mov  %i3, %o2
a00e7ec4:  92 10 00 19  mov  %i1, %o1
a00e7ec8:  94 10 00 1a  mov  %i2, %o2
a00e7ecc:  7f ff df 61  call  0xa00dfc50
a00e7ed0:  90 10 00 18  mov  %i0, %o0
a00e7ed4:  90 10 00 18  mov  %i0, %o0
a00e7ed8:  92 10 21 b4  mov  0x1b4, %o1
a00e7edc:  7f ff e2 19  call  0xa00e0740
a00e7ee0:  94 10 20 f0  mov  0xf0, %o2
a00e7ee4:  90 10 00 18  mov  %i0, %o0
a00e7ee8:  92 10 21 5d  mov  0x15d, %o1
a00e7eec:  7f ff e2 15  call  0xa00e0740
a00e7ef0:  94 10 20 f0  mov  0xf0, %o2
a00e7ef4:  90 10 00 18  mov  %i0, %o0
a00e7ef8:  92 10 21 65  mov  0x165, %o1
a00e7efc:  7f ff e2 11  call  0xa00e0740
a00e7f00:  94 10 20 0f  mov  0xf, %o2
a00e7f04:  80 a6 ff ff  cmp  %i3, -1
a00e7f08:  02 80 01 4b  be  0xa00e8434
a00e7f0c:  13 2a 00 ad  sethi  %hi(0xa802b400), %o1
a00e7f10:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00e7f14:  a5 2e e0 02  sll  %i3, 2, %l2
a00e7f18:  90 12 63 08  or  %o1, 0x308, %o0
a00e7f1c:  94 14 20 38  or  %l0, 0x38, %o2
a00e7f20:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00e7f24:  9a 13 e0 28  or  %o7, 0x28, %o5	! 0xa8026828
a00e7f28:  d2 02 80 12  ld  [ %o2 + %l2 ], %o1
a00e7f2c:  d6 02 00 12  ld  [ %o0 + %l2 ], %o3
a00e7f30:  d4 03 40 12  ld  [ %o5 + %l2 ], %o2
a00e7f34:  7f ff e2 08  call  0xa00e0754
a00e7f38:  90 10 00 18  mov  %i0, %o0
a00e7f3c:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00e7f40:  7f ff e0 54  call  0xa00e0090
a00e7f44:  90 10 00 18  mov  %i0, %o0
a00e7f48:  90 10 00 18  mov  %i0, %o0
a00e7f4c:  92 10 20 02  mov  2, %o1
a00e7f50:  94 10 20 00  clr  %o2
a00e7f54:  7f ff f0 46  call  0xa00e406c
a00e7f58:  96 10 24 00  mov  0x400, %o3
a00e7f5c:  80 a6 a0 04  cmp  %i2, 4
a00e7f60:  02 80 00 8b  be  0xa00e818c
a00e7f64:  80 a6 a0 03  cmp  %i2, 3
a00e7f68:  02 80 02 3b  be  0xa00e8854
a00e7f6c:  80 a6 a0 04  cmp  %i2, 4
a00e7f70:  02 80 00 8f  be  0xa00e81ac
a00e7f74:  90 10 00 18  mov  %i0, %o0
a00e7f78:  92 10 20 05  mov  5, %o1
a00e7f7c:  94 10 20 00  clr  %o2
a00e7f80:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e7f84:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e7f88:  7f ff f0 39  call  0xa00e406c
a00e7f8c:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e7f90:  b4 15 a0 18  or  %l6, 0x18, %i2	! 0xa8026418
a00e7f94:  a0 10 20 00  clr  %l0
a00e7f98:  a6 15 20 28  or  %l4, 0x28, %l3
a00e7f9c:  a2 10 20 07  mov  7, %l1
a00e7fa0:  d0 04 c0 12  ld  [ %l3 + %l2 ], %o0
a00e7fa4:  92 02 00 10  add  %o0, %l0, %o1
a00e7fa8:  90 10 00 18  mov  %i0, %o0
a00e7fac:  7f ff e1 5a  call  0xa00e0514
a00e7fb0:  d4 06 80 12  ld  [ %i2 + %l2 ], %o2
a00e7fb4:  82 24 40 10  sub  %l1, %l0, %g1
a00e7fb8:  96 10 20 55  mov  0x55, %o3
a00e7fbc:  99 3a c0 01  sra  %o3, %g1, %o4
a00e7fc0:  ba 0b 20 01  and  %o4, 1, %i5
a00e7fc4:  80 a0 00 1d  cmp  %g0, %i5
a00e7fc8:  b8 40 3f ff  addx  %g0, -1, %i4
a00e7fcc:  b2 0f 3f 01  and  %i4, -255, %i1
a00e7fd0:  ae 06 60 ff  add  %i1, 0xff, %l7
a00e7fd4:  80 a2 00 17  cmp  %o0, %l7
a00e7fd8:  12 80 00 7b  bne  0xa00e81c4
a00e7fdc:  a0 04 20 01  inc  %l0
a00e7fe0:  80 a4 20 07  cmp  %l0, 7
a00e7fe4:  24 bf ff f0  ble,a   0xa00e7fa4
a00e7fe8:  d0 04 c0 12  ld  [ %l3 + %l2 ], %o0
a00e7fec:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e7ff0:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00e7ff4:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00e7ff8:  35 2a 00 99  sethi  %hi(0xa8026400), %i2
a00e7ffc:  b8 12 60 18  or  %o1, 0x18, %i4
a00e8000:  ac 12 a0 18  or  %o2, 0x18, %l6
a00e8004:  ae 13 60 08  or  %o5, 8, %l7
a00e8008:  80 a6 ff ff  cmp  %i3, -1
a00e800c:  02 80 00 48  be  0xa00e812c
a00e8010:  ba 16 a3 f8  or  %i2, 0x3f8, %i5
a00e8014:  d2 05 80 12  ld  [ %l6 + %l2 ], %o1
a00e8018:  d4 05 c0 12  ld  [ %l7 + %l2 ], %o2
a00e801c:  d6 07 40 12  ld  [ %i5 + %l2 ], %o3
a00e8020:  7f ff e1 cd  call  0xa00e0754
a00e8024:  90 10 00 18  mov  %i0, %o0
a00e8028:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e802c:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e8030:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00e8034:  94 13 e3 e8  or  %o7, 0x3e8, %o2
a00e8038:  90 13 62 f8  or  %o5, 0x2f8, %o0
a00e803c:  b4 12 63 d8  or  %o1, 0x3d8, %i2
a00e8040:  d2 02 80 12  ld  [ %o2 + %l2 ], %o1
a00e8044:  d6 02 00 12  ld  [ %o0 + %l2 ], %o3
a00e8048:  d4 06 80 12  ld  [ %i2 + %l2 ], %o2
a00e804c:  7f ff e1 c2  call  0xa00e0754
a00e8050:  90 10 00 18  mov  %i0, %o0
a00e8054:  90 10 00 18  mov  %i0, %o0
a00e8058:  d2 05 80 12  ld  [ %l6 + %l2 ], %o1
a00e805c:  d4 05 c0 12  ld  [ %l7 + %l2 ], %o2
a00e8060:  d6 07 40 12  ld  [ %i5 + %l2 ], %o3
a00e8064:  7f ff e1 bc  call  0xa00e0754
a00e8068:  01 00 00 00  nop
a00e806c:  80 a2 20 00  cmp  %o0, 0
a00e8070:  02 80 02 27  be  0xa00e890c
a00e8074:  80 a6 ff ff  cmp  %i3, -1
a00e8078:  02 80 00 fa  be  0xa00e8460
a00e807c:  98 02 3f ff  add  %o0, -1, %o4
a00e8080:  90 10 00 18  mov  %i0, %o0
a00e8084:  d2 05 80 12  ld  [ %l6 + %l2 ], %o1
a00e8088:  d4 05 c0 12  ld  [ %l7 + %l2 ], %o2
a00e808c:  d6 07 40 12  ld  [ %i5 + %l2 ], %o3
a00e8090:  7f ff e1 b9  call  0xa00e0774
a00e8094:  b4 10 20 00  clr  %i2
a00e8098:  7f ff df fe  call  0xa00e0090
a00e809c:  90 10 00 18  mov  %i0, %o0
a00e80a0:  90 10 00 18  mov  %i0, %o0
a00e80a4:  92 10 20 05  mov  5, %o1
a00e80a8:  94 10 20 00  clr  %o2
a00e80ac:  7f ff ef f0  call  0xa00e406c
a00e80b0:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e80b4:  a6 10 00 1c  mov  %i4, %l3
a00e80b8:  aa 10 20 01  mov  1, %l5
a00e80bc:  a0 10 20 00  clr  %l0
a00e80c0:  a3 2d 40 1a  sll  %l5, %i2, %l1
a00e80c4:  d0 04 c0 12  ld  [ %l3 + %l2 ], %o0
a00e80c8:  9e 15 20 28  or  %l4, 0x28, %o7
a00e80cc:  94 0a 00 11  and  %o0, %l1, %o2
a00e80d0:  d2 03 c0 12  ld  [ %o7 + %l2 ], %o1
a00e80d4:  92 02 40 10  add  %o1, %l0, %o1
a00e80d8:  7f ff e1 0f  call  0xa00e0514
a00e80dc:  90 10 00 18  mov  %i0, %o0
a00e80e0:  9a 10 20 07  mov  7, %o5
a00e80e4:  82 23 40 10  sub  %o5, %l0, %g1
a00e80e8:  94 10 20 55  mov  0x55, %o2
a00e80ec:  97 3a 80 01  sra  %o2, %g1, %o3
a00e80f0:  99 32 00 1a  srl  %o0, %i2, %o4
a00e80f4:  b2 0a e0 01  and  %o3, 1, %i1
a00e80f8:  80 a3 00 19  cmp  %o4, %i1
a00e80fc:  12 80 00 e1  bne  0xa00e8480
a00e8100:  a0 04 20 01  inc  %l0
a00e8104:  80 a4 20 07  cmp  %l0, 7
a00e8108:  24 bf ff f0  ble,a   0xa00e80c8
a00e810c:  d0 04 c0 12  ld  [ %l3 + %l2 ], %o0
a00e8110:  b4 06 a0 01  inc  %i2
a00e8114:  80 a6 a0 07  cmp  %i2, 7
a00e8118:  24 bf ff ea  ble,a   0xa00e80c0
a00e811c:  a0 10 20 00  clr  %l0
a00e8120:  80 a6 ff ff  cmp  %i3, -1
a00e8124:  32 bf ff bd  bne,a   0xa00e8018
a00e8128:  d2 05 80 12  ld  [ %l6 + %l2 ], %o1
a00e812c:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00e8130:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00e8134:  94 12 e0 08  or  %o3, 8, %o2
a00e8138:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e813c:  92 10 60 18  or  %g1, 0x18, %o1
a00e8140:  96 13 23 f8  or  %o4, 0x3f8, %o3
a00e8144:  7f ff e1 84  call  0xa00e0754
a00e8148:  90 10 00 18  mov  %i0, %o0
a00e814c:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00e8150:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e8154:  27 2a 00 ad  sethi  %hi(0xa802b400), %l3
a00e8158:  92 16 63 e8  or  %i1, 0x3e8, %o1
a00e815c:  94 15 63 d8  or  %l5, 0x3d8, %o2
a00e8160:  96 14 e2 f8  or  %l3, 0x2f8, %o3
a00e8164:  7f ff e1 7c  call  0xa00e0754
a00e8168:  90 10 00 18  mov  %i0, %o0
a00e816c:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00e8170:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00e8174:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e8178:  90 10 00 18  mov  %i0, %o0
a00e817c:  92 14 60 18  or  %l1, 0x18, %o1
a00e8180:  94 14 20 08  or  %l0, 8, %o2
a00e8184:  10 bf ff b8  b  0xa00e8064
a00e8188:  96 13 e3 f8  or  %o7, 0x3f8, %o3
a00e818c:  7f ff ef a9  call  0xa00e4030
a00e8190:  90 10 00 18  mov  %i0, %o0
a00e8194:  96 12 20 04  or  %o0, 4, %o3
a00e8198:  90 10 00 18  mov  %i0, %o0
a00e819c:  92 10 20 06  mov  6, %o1
a00e81a0:  7f ff ef b3  call  0xa00e406c
a00e81a4:  94 10 20 03  mov  3, %o2
a00e81a8:  90 10 00 18  mov  %i0, %o0
a00e81ac:  92 10 20 0b  mov  0xb, %o1
a00e81b0:  94 10 20 00  clr  %o2
a00e81b4:  7f ff ef ae  call  0xa00e406c
a00e81b8:  96 10 20 55  mov  0x55, %o3
a00e81bc:  10 bf ff 6f  b  0xa00e7f78
a00e81c0:  90 10 00 18  mov  %i0, %o0
a00e81c4:  7f ff dd 92  call  0xa00df80c
a00e81c8:  23 00 06 66  sethi  %hi(0x199800), %l1
a00e81cc:  7f ff e2 7d  call  0xa00e0bc0
a00e81d0:  01 00 00 00  nop
a00e81d4:  7f ff db e7  call  0xa00df170
a00e81d8:  90 14 62 f8  or  %l1, 0x2f8, %o0
a00e81dc:  82 10 3f ff  mov  -1, %g1
a00e81e0:  ac 90 60 00  orcc  %g1, 0, %l6
a00e81e4:  02 80 00 21  be  0xa00e8268
a00e81e8:  90 10 00 18  mov  %i0, %o0
a00e81ec:  90 10 00 18  mov  %i0, %o0
a00e81f0:  7f ff ef 90  call  0xa00e4030
a00e81f4:  2f 00 03 ff  sethi  %hi(0xffc00), %l7
a00e81f8:  a8 15 e3 fb  or  %l7, 0x3fb, %l4	! 0xffffb
a00e81fc:  96 0a 00 14  and  %o0, %l4, %o3
a00e8200:  90 10 00 18  mov  %i0, %o0
a00e8204:  92 10 20 06  mov  6, %o1
a00e8208:  7f ff ef 99  call  0xa00e406c
a00e820c:  94 10 20 03  mov  3, %o2
a00e8210:  80 a6 ff ff  cmp  %i3, -1
a00e8214:  02 80 00 81  be  0xa00e8418
a00e8218:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00e821c:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00e8220:  13 2a 00 ad  sethi  %hi(0xa802b400), %o1
a00e8224:  ba 12 a0 38  or  %o2, 0x38, %i5
a00e8228:  a2 12 63 08  or  %o1, 0x308, %l1
a00e822c:  b8 13 e0 28  or  %o7, 0x28, %i4
a00e8230:  d6 04 40 12  ld  [ %l1 + %l2 ], %o3
a00e8234:  d2 07 40 12  ld  [ %i5 + %l2 ], %o1
a00e8238:  d4 07 00 12  ld  [ %i4 + %l2 ], %o2
a00e823c:  d8 07 bf f4  ld  [ %fp + -12 ], %o4
a00e8240:  7f ff e1 4d  call  0xa00e0774
a00e8244:  90 10 00 18  mov  %i0, %o0
a00e8248:  7f ff df 92  call  0xa00e0090
a00e824c:  90 10 00 18  mov  %i0, %o0
a00e8250:  90 95 a0 00  orcc  %l6, 0, %o0
a00e8254:  12 80 03 04  bne  0xa00e8e64
a00e8258:  80 a6 e0 03  cmp  %i3, 3
a00e825c:  08 80 03 02  bleu  0xa00e8e64
a00e8260:  01 00 00 00  nop
a00e8264:  30 80 02 b8  b,a   0xa00e8d44
a00e8268:  94 10 20 00  clr  %o2	! 0x0
a00e826c:  92 10 20 05  mov  5, %o1
a00e8270:  7f ff ef 7f  call  0xa00e406c
a00e8274:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e8278:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e827c:  1f 2a 00 98  sethi  %hi(0xa8026000), %o7
a00e8280:  11 2a 00 98  sethi  %hi(0xa8026000), %o0
a00e8284:  b2 12 a0 18  or  %o2, 0x18, %i1
a00e8288:  ac 13 e2 88  or  %o7, 0x288, %l6
a00e828c:  ae 12 22 78  or  %o0, 0x278, %l7
a00e8290:  ba 10 20 01  mov  1, %i5
a00e8294:  a2 10 20 00  clr  %l1
a00e8298:  b4 10 20 00  clr  %i2
a00e829c:  a1 2f 40 11  sll  %i5, %l1, %l0
a00e82a0:  90 15 20 28  or  %l4, 0x28, %o0
a00e82a4:  e6 02 00 12  ld  [ %o0 + %l2 ], %l3
a00e82a8:  f8 06 40 12  ld  [ %i1 + %l2 ], %i4
a00e82ac:  92 04 c0 1a  add  %l3, %i2, %o1
a00e82b0:  94 0f 00 10  and  %i4, %l0, %o2
a00e82b4:  7f ff e0 98  call  0xa00e0514
a00e82b8:  90 10 00 18  mov  %i0, %o0
a00e82bc:  aa 10 20 07  mov  7, %l5
a00e82c0:  92 25 40 1a  sub  %l5, %i2, %o1
a00e82c4:  96 10 20 55  mov  0x55, %o3
a00e82c8:  9b 3a c0 09  sra  %o3, %o1, %o5
a00e82cc:  83 32 00 11  srl  %o0, %l1, %g1
a00e82d0:  98 0b 60 01  and  %o5, 1, %o4
a00e82d4:  80 a0 40 0c  cmp  %g1, %o4
a00e82d8:  12 80 00 2c  bne  0xa00e8388
a00e82dc:  b4 06 a0 01  inc  %i2
a00e82e0:  80 a6 a0 07  cmp  %i2, 7
a00e82e4:  24 bf ff f0  ble,a   0xa00e82a4
a00e82e8:  90 15 20 28  or  %l4, 0x28, %o0
a00e82ec:  f4 05 80 12  ld  [ %l6 + %l2 ], %i2
a00e82f0:  92 06 80 11  add  %i2, %l1, %o1
a00e82f4:  90 10 00 18  mov  %i0, %o0
a00e82f8:  7f ff e0 87  call  0xa00e0514
a00e82fc:  d4 05 c0 12  ld  [ %l7 + %l2 ], %o2
a00e8300:  97 32 20 03  srl  %o0, 3, %o3
a00e8304:  80 a2 e0 0f  cmp  %o3, 0xf
a00e8308:  02 80 01 e9  be  0xa00e8aac
a00e830c:  90 0a 20 07  and  %o0, 7, %o0
a00e8310:  94 02 e0 01  add  %o3, 1, %o2
a00e8314:  9f 2a a0 03  sll  %o2, 3, %o7
a00e8318:  96 03 c0 08  add  %o7, %o0, %o3
a00e831c:  e0 05 80 12  ld  [ %l6 + %l2 ], %l0
a00e8320:  92 04 00 11  add  %l0, %l1, %o1
a00e8324:  90 10 00 18  mov  %i0, %o0
a00e8328:  7f ff e0 ac  call  0xa00e05d8
a00e832c:  d4 05 c0 12  ld  [ %l7 + %l2 ], %o2
a00e8330:  90 10 00 18  mov  %i0, %o0
a00e8334:  92 10 00 1b  mov  %i3, %o1
a00e8338:  94 10 00 11  mov  %l1, %o2
a00e833c:  7f ff fe a3  call  0xa00e7dc8
a00e8340:  96 10 20 00  clr  %o3
a00e8344:  80 a2 20 00  cmp  %o0, 0
a00e8348:  12 80 01 e0  bne  0xa00e8ac8
a00e834c:  92 10 00 1b  mov  %i3, %o1
a00e8350:  90 10 00 18  mov  %i0, %o0
a00e8354:  94 10 00 11  mov  %l1, %o2
a00e8358:  7f ff fe 9c  call  0xa00e7dc8
a00e835c:  96 10 20 01  mov  1, %o3
a00e8360:  80 a2 20 00  cmp  %o0, 0
a00e8364:  12 80 01 d9  bne  0xa00e8ac8
a00e8368:  92 10 00 1b  mov  %i3, %o1
a00e836c:  90 10 00 18  mov  %i0, %o0
a00e8370:  94 10 00 11  mov  %l1, %o2
a00e8374:  7f ff fe 95  call  0xa00e7dc8
a00e8378:  96 10 20 00  clr  %o3
a00e837c:  80 a2 20 00  cmp  %o0, 0
a00e8380:  32 80 01 d3  bne,a   0xa00e8acc
a00e8384:  ac 92 20 00  orcc  %o0, 0, %l6
a00e8388:  a2 04 60 01  inc  %l1
a00e838c:  80 a4 60 07  cmp  %l1, 7
a00e8390:  04 bf ff c3  ble  0xa00e829c
a00e8394:  b4 10 20 00  clr  %i2
a00e8398:  90 10 00 18  mov  %i0, %o0
a00e839c:  92 10 20 05  mov  5, %o1
a00e83a0:  94 10 20 00  clr  %o2
a00e83a4:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e83a8:  7f ff ef 31  call  0xa00e406c
a00e83ac:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e83b0:  a6 10 20 00  clr  %l3
a00e83b4:  aa 14 60 18  or  %l1, 0x18, %l5
a00e83b8:  b8 10 20 01  mov  1, %i4
a00e83bc:  a0 10 20 00  clr  %l0
a00e83c0:  a3 2f 00 13  sll  %i4, %l3, %l1
a00e83c4:  94 15 20 28  or  %l4, 0x28, %o2
a00e83c8:  de 02 80 12  ld  [ %o2 + %l2 ], %o7
a00e83cc:  d0 05 40 12  ld  [ %l5 + %l2 ], %o0
a00e83d0:  94 0a 00 11  and  %o0, %l1, %o2
a00e83d4:  92 03 c0 10  add  %o7, %l0, %o1
a00e83d8:  7f ff e0 4f  call  0xa00e0514
a00e83dc:  90 10 00 18  mov  %i0, %o0
a00e83e0:  b4 10 20 07  mov  7, %i2
a00e83e4:  92 26 80 10  sub  %i2, %l0, %o1
a00e83e8:  96 10 20 55  mov  0x55, %o3
a00e83ec:  9b 3a c0 09  sra  %o3, %o1, %o5
a00e83f0:  83 32 00 13  srl  %o0, %l3, %g1
a00e83f4:  98 0b 60 01  and  %o5, 1, %o4
a00e83f8:  80 a0 40 0c  cmp  %g1, %o4
a00e83fc:  12 80 02 0f  bne  0xa00e8c38
a00e8400:  a0 04 20 01  inc  %l0
a00e8404:  80 a4 20 07  cmp  %l0, 7
a00e8408:  04 bf ff f0  ble  0xa00e83c8
a00e840c:  94 15 20 28  or  %l4, 0x28, %o2
a00e8410:  10 bf ff a2  b  0xa00e8298
a00e8414:  a2 10 20 00  clr  %l1
a00e8418:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00e841c:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00e8420:  25 2a 00 ad  sethi  %hi(0xa802b400), %l2
a00e8424:  92 15 60 38  or  %l5, 0x38, %o1
a00e8428:  94 16 60 28  or  %i1, 0x28, %o2
a00e842c:  10 bf ff 84  b  0xa00e823c
a00e8430:  96 14 a3 08  or  %l2, 0x308, %o3
a00e8434:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00e8438:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00e843c:  94 12 e0 28  or  %o3, 0x28, %o2
a00e8440:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00e8444:  90 10 00 18  mov  %i0, %o0
a00e8448:  92 10 60 38  or  %g1, 0x38, %o1
a00e844c:  7f ff e0 c2  call  0xa00e0754
a00e8450:  96 13 23 08  or  %o4, 0x308, %o3
a00e8454:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00e8458:  10 bf fe ba  b  0xa00e7f40
a00e845c:  a4 10 3f fc  mov  -4, %l2
a00e8460:  27 2a 00 9a  sethi  %hi(0xa8026800), %l3
a00e8464:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00e8468:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00e846c:  90 10 00 18  mov  %i0, %o0
a00e8470:  92 14 e0 18  or  %l3, 0x18, %o1
a00e8474:  94 14 60 08  or  %l1, 8, %o2
a00e8478:  10 bf ff 06  b  0xa00e8090
a00e847c:  96 14 23 f8  or  %l0, 0x3f8, %o3
a00e8480:  39 2a 00 9a  sethi  %hi(0xa8026800), %i4
a00e8484:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00e8488:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00e848c:  ba 17 20 18  or  %i4, 0x18, %i5
a00e8490:  b8 15 60 08  or  %l5, 8, %i4
a00e8494:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e8498:  ac 15 e3 d8  or  %l7, 0x3d8, %l6
a00e849c:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00e84a0:  aa 14 e3 e8  or  %l3, 0x3e8, %l5
a00e84a4:  ae 14 22 f8  or  %l0, 0x2f8, %l7
a00e84a8:  80 a6 ff ff  cmp  %i3, -1
a00e84ac:  02 80 00 9c  be  0xa00e871c
a00e84b0:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00e84b4:  b4 14 23 f8  or  %l0, 0x3f8, %i2	! 0xa80267f8
a00e84b8:  d2 07 40 12  ld  [ %i5 + %l2 ], %o1
a00e84bc:  d4 07 00 12  ld  [ %i4 + %l2 ], %o2
a00e84c0:  d6 06 80 12  ld  [ %i2 + %l2 ], %o3
a00e84c4:  7f ff e0 a4  call  0xa00e0754
a00e84c8:  90 10 00 18  mov  %i0, %o0
a00e84cc:  d2 05 40 12  ld  [ %l5 + %l2 ], %o1
a00e84d0:  d4 05 80 12  ld  [ %l6 + %l2 ], %o2
a00e84d4:  d6 05 c0 12  ld  [ %l7 + %l2 ], %o3
a00e84d8:  7f ff e0 9f  call  0xa00e0754
a00e84dc:  90 10 00 18  mov  %i0, %o0
a00e84e0:  90 10 00 18  mov  %i0, %o0
a00e84e4:  d2 05 40 12  ld  [ %l5 + %l2 ], %o1
a00e84e8:  d4 05 80 12  ld  [ %l6 + %l2 ], %o2
a00e84ec:  d6 05 c0 12  ld  [ %l7 + %l2 ], %o3
a00e84f0:  7f ff e0 99  call  0xa00e0754
a00e84f4:  01 00 00 00  nop
a00e84f8:  80 a2 20 07  cmp  %o0, 7
a00e84fc:  02 80 00 6e  be  0xa00e86b4
a00e8500:  80 a6 ff ff  cmp  %i3, -1
a00e8504:  02 80 00 9e  be  0xa00e877c
a00e8508:  98 02 20 01  add  %o0, 1, %o4
a00e850c:  90 10 00 18  mov  %i0, %o0
a00e8510:  d2 05 40 12  ld  [ %l5 + %l2 ], %o1
a00e8514:  d4 05 80 12  ld  [ %l6 + %l2 ], %o2
a00e8518:  d6 05 c0 12  ld  [ %l7 + %l2 ], %o3
a00e851c:  7f ff e0 96  call  0xa00e0774
a00e8520:  a0 10 20 00  clr  %l0
a00e8524:  7f ff de db  call  0xa00e0090
a00e8528:  90 10 00 18  mov  %i0, %o0
a00e852c:  92 10 20 05  mov  5, %o1
a00e8530:  90 10 00 18  mov  %i0, %o0
a00e8534:  94 10 20 00  clr  %o2
a00e8538:  7f ff ee cd  call  0xa00e406c
a00e853c:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e8540:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e8544:  a2 12 60 18  or  %o1, 0x18, %l1	! 0xa8026418
a00e8548:  a6 10 20 01  mov  1, %l3
a00e854c:  b4 10 20 00  clr  %i2
a00e8550:  b3 2c c0 10  sll  %l3, %l0, %i1
a00e8554:  98 15 20 28  or  %l4, 0x28, %o4
a00e8558:  d2 03 00 12  ld  [ %o4 + %l2 ], %o1
a00e855c:  d6 04 40 12  ld  [ %l1 + %l2 ], %o3
a00e8560:  92 02 40 1a  add  %o1, %i2, %o1
a00e8564:  94 0a c0 19  and  %o3, %i1, %o2
a00e8568:  7f ff df eb  call  0xa00e0514
a00e856c:  90 10 00 18  mov  %i0, %o0
a00e8570:  82 10 20 07  mov  7, %g1
a00e8574:  9a 20 40 1a  sub  %g1, %i2, %o5
a00e8578:  94 10 20 55  mov  0x55, %o2
a00e857c:  9f 3a 80 0d  sra  %o2, %o5, %o7
a00e8580:  91 32 00 10  srl  %o0, %l0, %o0
a00e8584:  98 0b e0 01  and  %o7, 1, %o4
a00e8588:  80 a2 00 0c  cmp  %o0, %o4
a00e858c:  12 80 01 46  bne  0xa00e8aa4
a00e8590:  b4 06 a0 01  inc  %i2
a00e8594:  80 a6 a0 07  cmp  %i2, 7
a00e8598:  24 bf ff f0  ble,a   0xa00e8558
a00e859c:  98 15 20 28  or  %l4, 0x28, %o4
a00e85a0:  a0 04 20 01  inc  %l0
a00e85a4:  80 a4 20 07  cmp  %l0, 7
a00e85a8:  24 bf ff ea  ble,a   0xa00e8550
a00e85ac:  b4 10 20 00  clr  %i2
a00e85b0:  82 10 20 00  clr  %g1
a00e85b4:  80 a0 60 00  cmp  %g1, 0
a00e85b8:  12 bf ff bd  bne  0xa00e84ac
a00e85bc:  80 a6 ff ff  cmp  %i3, -1
a00e85c0:  02 80 00 9d  be  0xa00e8834
a00e85c4:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e85c8:  21 2a 00 99  sethi  %hi(0xa8026400), %l0
a00e85cc:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00e85d0:  b2 14 e3 e8  or  %l3, 0x3e8, %i1
a00e85d4:  b8 14 23 d8  or  %l0, 0x3d8, %i4
a00e85d8:  aa 16 a2 f8  or  %i2, 0x2f8, %l5
a00e85dc:  d2 06 40 12  ld  [ %i1 + %l2 ], %o1
a00e85e0:  d4 07 00 12  ld  [ %i4 + %l2 ], %o2
a00e85e4:  d6 05 40 12  ld  [ %l5 + %l2 ], %o3
a00e85e8:  90 10 00 18  mov  %i0, %o0
a00e85ec:  7f ff e0 5a  call  0xa00e0754
a00e85f0:  01 00 00 00  nop
a00e85f4:  80 a2 20 00  cmp  %o0, 0
a00e85f8:  12 80 00 81  bne  0xa00e87fc
a00e85fc:  80 a6 ff ff  cmp  %i3, -1
a00e8600:  02 80 00 bb  be  0xa00e88ec
a00e8604:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00e8608:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e860c:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00e8610:  90 12 e3 f8  or  %o3, 0x3f8, %o0
a00e8614:  9a 12 60 08  or  %o1, 8, %o5
a00e8618:  82 13 20 18  or  %o4, 0x18, %g1
a00e861c:  d6 02 00 12  ld  [ %o0 + %l2 ], %o3
a00e8620:  d2 00 40 12  ld  [ %g1 + %l2 ], %o1
a00e8624:  d4 03 40 12  ld  [ %o5 + %l2 ], %o2
a00e8628:  90 10 00 18  mov  %i0, %o0
a00e862c:  7f ff e0 4a  call  0xa00e0754
a00e8630:  01 00 00 00  nop
a00e8634:  80 a6 ff ff  cmp  %i3, -1
a00e8638:  02 80 00 93  be  0xa00e8884
a00e863c:  90 02 3f ff  add  %o0, -1, %o0
a00e8640:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e8644:  98 12 e3 f8  or  %o3, 0x3f8, %o4	! 0xa80267f8
a00e8648:  d6 03 00 12  ld  [ %o4 + %l2 ], %o3
a00e864c:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00e8650:  3b 2a 00 9a  sethi  %hi(0xa8026800), %i5
a00e8654:  9a 12 60 08  or  %o1, 8, %o5
a00e8658:  82 17 60 18  or  %i5, 0x18, %g1
a00e865c:  98 10 00 08  mov  %o0, %o4
a00e8660:  d2 00 40 12  ld  [ %g1 + %l2 ], %o1
a00e8664:  d4 03 40 12  ld  [ %o5 + %l2 ], %o2
a00e8668:  7f ff e0 43  call  0xa00e0774
a00e866c:  90 10 00 18  mov  %i0, %o0
a00e8670:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e8674:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e8678:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00e867c:  a6 12 a3 e8  or  %o2, 0x3e8, %l3
a00e8680:  a0 13 e3 d8  or  %o7, 0x3d8, %l0
a00e8684:  b4 14 62 f8  or  %l1, 0x2f8, %i2
a00e8688:  d2 04 c0 12  ld  [ %l3 + %l2 ], %o1
a00e868c:  d4 04 00 12  ld  [ %l0 + %l2 ], %o2
a00e8690:  d6 06 80 12  ld  [ %i2 + %l2 ], %o3
a00e8694:  90 10 00 18  mov  %i0, %o0
a00e8698:  98 10 20 07  mov  7, %o4
a00e869c:  7f ff e0 36  call  0xa00e0774
a00e86a0:  01 00 00 00  nop
a00e86a4:  7f ff de 7b  call  0xa00e0090
a00e86a8:  90 10 00 18  mov  %i0, %o0
a00e86ac:  10 bf fe cd  b  0xa00e81e0
a00e86b0:  82 10 20 00  clr  %g1
a00e86b4:  02 80 00 4b  be  0xa00e87e0
a00e86b8:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00e86bc:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e86c0:  82 12 e3 f8  or  %o3, 0x3f8, %g1	! 0xa80267f8
a00e86c4:  90 10 00 18  mov  %i0, %o0
a00e86c8:  d2 07 40 12  ld  [ %i5 + %l2 ], %o1
a00e86cc:  d4 07 00 12  ld  [ %i4 + %l2 ], %o2
a00e86d0:  d6 00 40 12  ld  [ %g1 + %l2 ], %o3
a00e86d4:  7f ff e0 20  call  0xa00e0754
a00e86d8:  01 00 00 00  nop
a00e86dc:  80 a6 ff ff  cmp  %i3, -1
a00e86e0:  02 80 00 2f  be  0xa00e879c
a00e86e4:  98 02 20 01  add  %o0, 1, %o4
a00e86e8:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e86ec:  a6 13 63 f8  or  %o5, 0x3f8, %l3	! 0xa80267f8
a00e86f0:  90 10 00 18  mov  %i0, %o0
a00e86f4:  d2 07 40 12  ld  [ %i5 + %l2 ], %o1
a00e86f8:  d4 07 00 12  ld  [ %i4 + %l2 ], %o2
a00e86fc:  7f ff e0 1e  call  0xa00e0774
a00e8700:  d6 04 c0 12  ld  [ %l3 + %l2 ], %o3
a00e8704:  90 10 00 18  mov  %i0, %o0
a00e8708:  d2 05 40 12  ld  [ %l5 + %l2 ], %o1
a00e870c:  d4 05 80 12  ld  [ %l6 + %l2 ], %o2
a00e8710:  d6 05 c0 12  ld  [ %l7 + %l2 ], %o3
a00e8714:  10 bf ff 82  b  0xa00e851c
a00e8718:  98 10 20 00  clr  %o4
a00e871c:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00e8720:  94 12 20 08  or  %o0, 8, %o2	! 0xa8026808
a00e8724:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e8728:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00e872c:  96 13 e3 f8  or  %o7, 0x3f8, %o3
a00e8730:  92 16 60 18  or  %i1, 0x18, %o1
a00e8734:  7f ff e0 08  call  0xa00e0754
a00e8738:  90 10 00 18  mov  %i0, %o0
a00e873c:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e8740:  92 12 a3 e8  or  %o2, 0x3e8, %o1	! 0xa80267e8
a00e8744:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00e8748:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e874c:  94 14 63 d8  or  %l1, 0x3d8, %o2	! 0xa80267d8
a00e8750:  96 10 62 f8  or  %g1, 0x2f8, %o3
a00e8754:  7f ff e0 00  call  0xa00e0754
a00e8758:  90 10 00 18  mov  %i0, %o0
a00e875c:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e8760:  92 12 e3 e8  or  %o3, 0x3e8, %o1	! 0xa80267e8
a00e8764:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e8768:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00e876c:  90 10 00 18  mov  %i0, %o0
a00e8770:  94 13 63 d8  or  %o5, 0x3d8, %o2
a00e8774:  10 bf ff 5f  b  0xa00e84f0
a00e8778:  96 13 22 f8  or  %o4, 0x2f8, %o3
a00e877c:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e8780:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e8784:  94 12 e3 d8  or  %o3, 0x3d8, %o2
a00e8788:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00e878c:  90 10 00 18  mov  %i0, %o0
a00e8790:  92 14 63 e8  or  %l1, 0x3e8, %o1
a00e8794:  10 bf ff 62  b  0xa00e851c
a00e8798:  96 10 62 f8  or  %g1, 0x2f8, %o3
a00e879c:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00e87a0:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00e87a4:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00e87a8:  90 10 00 18  mov  %i0, %o0
a00e87ac:  92 14 20 18  or  %l0, 0x18, %o1
a00e87b0:  94 16 a0 08  or  %i2, 8, %o2
a00e87b4:  7f ff df f0  call  0xa00e0774
a00e87b8:  96 16 63 f8  or  %i1, 0x3f8, %o3
a00e87bc:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e87c0:  92 12 a3 e8  or  %o2, 0x3e8, %o1	! 0xa80267e8
a00e87c4:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e87c8:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00e87cc:  90 10 00 18  mov  %i0, %o0
a00e87d0:  94 13 e3 d8  or  %o7, 0x3d8, %o2
a00e87d4:  96 14 62 f8  or  %l1, 0x2f8, %o3
a00e87d8:  10 bf ff 51  b  0xa00e851c
a00e87dc:  98 10 20 00  clr  %o4
a00e87e0:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00e87e4:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e87e8:  90 10 00 18  mov  %i0, %o0
a00e87ec:  92 13 60 18  or  %o5, 0x18, %o1
a00e87f0:  94 13 20 08  or  %o4, 8, %o2
a00e87f4:  10 bf ff b8  b  0xa00e86d4
a00e87f8:  96 14 e3 f8  or  %l3, 0x3f8, %o3
a00e87fc:  02 80 00 33  be  0xa00e88c8
a00e8800:  90 02 3f ff  add  %o0, -1, %o0
a00e8804:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e8808:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e880c:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00e8810:  b4 14 63 e8  or  %l1, 0x3e8, %i2
a00e8814:  b2 14 e3 d8  or  %l3, 0x3d8, %i1
a00e8818:  b8 14 22 f8  or  %l0, 0x2f8, %i4
a00e881c:  98 10 00 08  mov  %o0, %o4
a00e8820:  d2 06 80 12  ld  [ %i2 + %l2 ], %o1
a00e8824:  d4 06 40 12  ld  [ %i1 + %l2 ], %o2
a00e8828:  d6 07 00 12  ld  [ %i4 + %l2 ], %o3
a00e882c:  10 bf ff 9c  b  0xa00e869c
a00e8830:  90 10 00 18  mov  %i0, %o0
a00e8834:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00e8838:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e883c:  3b 2a 00 ad  sethi  %hi(0xa802b400), %i5
a00e8840:  90 10 00 18  mov  %i0, %o0
a00e8844:  92 15 e3 e8  or  %l7, 0x3e8, %o1
a00e8848:  94 15 a3 d8  or  %l6, 0x3d8, %o2
a00e884c:  10 bf ff 68  b  0xa00e85ec
a00e8850:  96 17 62 f8  or  %i5, 0x2f8, %o3
a00e8854:  7f ff ed f7  call  0xa00e4030
a00e8858:  90 10 00 18  mov  %i0, %o0
a00e885c:  2b 00 03 c0  sethi  %hi(0xf0000), %l5
a00e8860:  a8 12 20 04  or  %o0, 4, %l4
a00e8864:  a6 15 60 fc  or  %l5, 0xfc, %l3
a00e8868:  96 0d 00 13  and  %l4, %l3, %o3
a00e886c:  90 10 00 18  mov  %i0, %o0
a00e8870:  92 10 20 06  mov  6, %o1
a00e8874:  7f ff ed fe  call  0xa00e406c
a00e8878:  94 10 20 03  mov  3, %o2
a00e887c:  10 bf fd bf  b  0xa00e7f78
a00e8880:  90 10 00 18  mov  %i0, %o0
a00e8884:  98 10 00 08  mov  %o0, %o4
a00e8888:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00e888c:  39 2a 00 9a  sethi  %hi(0xa8026800), %i4
a00e8890:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e8894:  92 16 60 18  or  %i1, 0x18, %o1
a00e8898:  94 17 20 08  or  %i4, 8, %o2
a00e889c:  96 15 63 f8  or  %l5, 0x3f8, %o3
a00e88a0:  7f ff df b5  call  0xa00e0774
a00e88a4:  90 10 00 18  mov  %i0, %o0
a00e88a8:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00e88ac:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e88b0:  3b 2a 00 ad  sethi  %hi(0xa802b400), %i5
a00e88b4:  90 10 00 18  mov  %i0, %o0
a00e88b8:  92 15 e3 e8  or  %l7, 0x3e8, %o1
a00e88bc:  94 15 a3 d8  or  %l6, 0x3d8, %o2
a00e88c0:  10 bf ff 76  b  0xa00e8698
a00e88c4:  96 17 62 f8  or  %i5, 0x2f8, %o3
a00e88c8:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e88cc:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00e88d0:  2d 2a 00 ad  sethi  %hi(0xa802b400), %l6
a00e88d4:  98 10 00 08  mov  %o0, %o4
a00e88d8:  92 15 63 e8  or  %l5, 0x3e8, %o1
a00e88dc:  94 15 e3 d8  or  %l7, 0x3d8, %o2
a00e88e0:  96 15 a2 f8  or  %l6, 0x2f8, %o3
a00e88e4:  10 bf ff 6e  b  0xa00e869c
a00e88e8:  90 10 00 18  mov  %i0, %o0
a00e88ec:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00e88f0:  92 12 a0 18  or  %o2, 0x18, %o1	! 0xa8026818
a00e88f4:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00e88f8:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e88fc:  90 10 00 18  mov  %i0, %o0
a00e8900:  94 13 e0 08  or  %o7, 8, %o2
a00e8904:  10 bf ff 4a  b  0xa00e862c
a00e8908:  96 14 63 f8  or  %l1, 0x3f8, %o3
a00e890c:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00e8910:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00e8914:  ac 15 e3 e8  or  %l7, 0x3e8, %l6
a00e8918:  ae 17 63 d8  or  %i5, 0x3d8, %l7
a00e891c:  2b 2a 00 ad  sethi  %hi(0xa802b400), %l5
a00e8920:  39 2a 00 99  sethi  %hi(0xa8026400), %i4
a00e8924:  ba 15 62 f8  or  %l5, 0x2f8, %i5
a00e8928:  b4 17 20 18  or  %i4, 0x18, %i2
a00e892c:  02 80 00 46  be  0xa00e8a44
a00e8930:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00e8934:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e8938:  90 12 63 f8  or  %o1, 0x3f8, %o0	! 0xa80267f8
a00e893c:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00e8940:  9e 15 60 08  or  %l5, 8, %o7	! 0xa8026808
a00e8944:  d6 02 00 12  ld  [ %o0 + %l2 ], %o3
a00e8948:  b8 14 20 18  or  %l0, 0x18, %i4
a00e894c:  d4 03 c0 12  ld  [ %o7 + %l2 ], %o2
a00e8950:  d2 07 00 12  ld  [ %i4 + %l2 ], %o1
a00e8954:  7f ff df 80  call  0xa00e0754
a00e8958:  90 10 00 18  mov  %i0, %o0
a00e895c:  d2 05 80 12  ld  [ %l6 + %l2 ], %o1
a00e8960:  d4 05 c0 12  ld  [ %l7 + %l2 ], %o2
a00e8964:  d6 07 40 12  ld  [ %i5 + %l2 ], %o3
a00e8968:  7f ff df 7b  call  0xa00e0754
a00e896c:  90 10 00 18  mov  %i0, %o0
a00e8970:  90 10 00 18  mov  %i0, %o0
a00e8974:  d2 05 80 12  ld  [ %l6 + %l2 ], %o1
a00e8978:  d4 05 c0 12  ld  [ %l7 + %l2 ], %o2
a00e897c:  d6 07 40 12  ld  [ %i5 + %l2 ], %o3
a00e8980:  7f ff df 75  call  0xa00e0754
a00e8984:  01 00 00 00  nop
a00e8988:  80 a2 20 00  cmp  %o0, 0
a00e898c:  02 80 00 f7  be  0xa00e8d68
a00e8990:  80 a6 ff ff  cmp  %i3, -1
a00e8994:  02 80 00 e4  be  0xa00e8d24
a00e8998:  98 02 3f ff  add  %o0, -1, %o4
a00e899c:  90 10 00 18  mov  %i0, %o0
a00e89a0:  d2 05 80 12  ld  [ %l6 + %l2 ], %o1
a00e89a4:  d4 05 c0 12  ld  [ %l7 + %l2 ], %o2
a00e89a8:  d6 07 40 12  ld  [ %i5 + %l2 ], %o3
a00e89ac:  7f ff df 72  call  0xa00e0774
a00e89b0:  a2 10 20 00  clr  %l1
a00e89b4:  7f ff dd b7  call  0xa00e0090
a00e89b8:  90 10 00 18  mov  %i0, %o0
a00e89bc:  90 10 00 18  mov  %i0, %o0
a00e89c0:  92 10 20 05  mov  5, %o1
a00e89c4:  94 10 20 00  clr  %o2
a00e89c8:  7f ff ed a9  call  0xa00e406c
a00e89cc:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e89d0:  aa 10 00 1a  mov  %i2, %l5
a00e89d4:  b8 10 20 01  mov  1, %i4
a00e89d8:  a0 10 20 00  clr  %l0
a00e89dc:  a7 2f 00 11  sll  %i4, %l1, %l3
a00e89e0:  d0 05 40 12  ld  [ %l5 + %l2 ], %o0
a00e89e4:  b2 15 20 28  or  %l4, 0x28, %i1
a00e89e8:  94 0a 00 13  and  %o0, %l3, %o2
a00e89ec:  d2 06 40 12  ld  [ %i1 + %l2 ], %o1
a00e89f0:  92 02 40 10  add  %o1, %l0, %o1
a00e89f4:  7f ff de c8  call  0xa00e0514
a00e89f8:  90 10 00 18  mov  %i0, %o0
a00e89fc:  9e 10 20 07  mov  7, %o7
a00e8a00:  82 23 c0 10  sub  %o7, %l0, %g1
a00e8a04:  94 10 20 55  mov  0x55, %o2
a00e8a08:  9b 3a 80 01  sra  %o2, %g1, %o5
a00e8a0c:  97 32 00 11  srl  %o0, %l1, %o3
a00e8a10:  98 0b 60 01  and  %o5, 1, %o4
a00e8a14:  80 a2 c0 0c  cmp  %o3, %o4
a00e8a18:  12 bf fe 9a  bne  0xa00e8480
a00e8a1c:  a0 04 20 01  inc  %l0
a00e8a20:  80 a4 20 07  cmp  %l0, 7
a00e8a24:  24 bf ff f0  ble,a   0xa00e89e4
a00e8a28:  d0 05 40 12  ld  [ %l5 + %l2 ], %o0
a00e8a2c:  a2 04 60 01  inc  %l1
a00e8a30:  80 a4 60 07  cmp  %l1, 7
a00e8a34:  04 bf ff ea  ble  0xa00e89dc
a00e8a38:  a0 10 20 00  clr  %l0
a00e8a3c:  10 bf ff bc  b  0xa00e892c
a00e8a40:  80 a6 ff ff  cmp  %i3, -1
a00e8a44:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00e8a48:  92 12 a0 18  or  %o2, 0x18, %o1	! 0xa8026818
a00e8a4c:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00e8a50:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e8a54:  94 13 60 08  or  %o5, 8, %o2
a00e8a58:  96 10 63 f8  or  %g1, 0x3f8, %o3
a00e8a5c:  7f ff df 3e  call  0xa00e0754
a00e8a60:  90 10 00 18  mov  %i0, %o0
a00e8a64:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e8a68:  92 12 e3 e8  or  %o3, 0x3e8, %o1	! 0xa80267e8
a00e8a6c:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e8a70:  33 2a 00 ad  sethi  %hi(0xa802b400), %i1
a00e8a74:  94 13 23 d8  or  %o4, 0x3d8, %o2
a00e8a78:  96 16 62 f8  or  %i1, 0x2f8, %o3
a00e8a7c:  7f ff df 36  call  0xa00e0754
a00e8a80:  90 10 00 18  mov  %i0, %o0
a00e8a84:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e8a88:  23 2a 00 99  sethi  %hi(0xa8026400), %l1
a00e8a8c:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00e8a90:  90 10 00 18  mov  %i0, %o0
a00e8a94:  92 14 e3 e8  or  %l3, 0x3e8, %o1
a00e8a98:  94 14 63 d8  or  %l1, 0x3d8, %o2
a00e8a9c:  10 bf ff b9  b  0xa00e8980
a00e8aa0:  96 14 22 f8  or  %l0, 0x2f8, %o3
a00e8aa4:  10 bf fe c4  b  0xa00e85b4
a00e8aa8:  82 10 20 01  mov  1, %g1
a00e8aac:  7f ff db 58  call  0xa00df80c
a00e8ab0:  3b 00 06 66  sethi  %hi(0x199800), %i5
a00e8ab4:  7f ff e0 43  call  0xa00e0bc0
a00e8ab8:  01 00 00 00  nop
a00e8abc:  7f ff d9 ad  call  0xa00df170
a00e8ac0:  90 17 63 18  or  %i5, 0x318, %o0
a00e8ac4:  90 10 3f ff  mov  -1, %o0
a00e8ac8:  ac 92 20 00  orcc  %o0, 0, %l6
a00e8acc:  12 bf fd c9  bne  0xa00e81f0
a00e8ad0:  90 10 00 18  mov  %i0, %o0
a00e8ad4:  92 10 20 05  mov  5, %o1
a00e8ad8:  94 10 20 00  clr  %o2
a00e8adc:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e8ae0:  23 2a 00 98  sethi  %hi(0xa8026000), %l1
a00e8ae4:  21 2a 00 98  sethi  %hi(0xa8026000), %l0
a00e8ae8:  7f ff ed 61  call  0xa00e406c
a00e8aec:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e8af0:  ba 14 62 88  or  %l1, 0x288, %i5
a00e8af4:  b8 14 22 78  or  %l0, 0x278, %i4
a00e8af8:  b2 14 e0 18  or  %l3, 0x18, %i1
a00e8afc:  aa 10 20 00  clr  %l5
a00e8b00:  ae 10 20 01  mov  1, %l7
a00e8b04:  a2 10 20 00  clr  %l1
a00e8b08:  83 2d c0 11  sll  %l7, %l1, %g1
a00e8b0c:  80 88 40 15  btst  %g1, %l5
a00e8b10:  32 80 00 48  bne,a   0xa00e8c30
a00e8b14:  a1 2d c0 11  sll  %l7, %l1, %l0
a00e8b18:  a6 10 00 01  mov  %g1, %l3
a00e8b1c:  a0 10 20 00  clr  %l0
a00e8b20:  b4 10 00 19  mov  %i1, %i2
a00e8b24:  96 15 20 28  or  %l4, 0x28, %o3
a00e8b28:  d0 06 80 12  ld  [ %i2 + %l2 ], %o0
a00e8b2c:  da 02 c0 12  ld  [ %o3 + %l2 ], %o5
a00e8b30:  94 0a 00 13  and  %o0, %l3, %o2
a00e8b34:  92 03 40 10  add  %o5, %l0, %o1
a00e8b38:  7f ff de 77  call  0xa00e0514
a00e8b3c:  90 10 00 18  mov  %i0, %o0
a00e8b40:  82 10 20 07  mov  7, %g1
a00e8b44:  98 20 40 10  sub  %g1, %l0, %o4
a00e8b48:  94 10 20 55  mov  0x55, %o2
a00e8b4c:  9f 3a 80 0c  sra  %o2, %o4, %o7
a00e8b50:  93 32 00 11  srl  %o0, %l1, %o1
a00e8b54:  96 0b e0 01  and  %o7, 1, %o3
a00e8b58:  80 a2 40 0b  cmp  %o1, %o3
a00e8b5c:  12 80 00 34  bne  0xa00e8c2c
a00e8b60:  a0 04 20 01  inc  %l0
a00e8b64:  80 a4 20 07  cmp  %l0, 7
a00e8b68:  24 bf ff f0  ble,a   0xa00e8b28
a00e8b6c:  96 15 20 28  or  %l4, 0x28, %o3
a00e8b70:  e6 07 40 12  ld  [ %i5 + %l2 ], %l3
a00e8b74:  92 04 c0 11  add  %l3, %l1, %o1
a00e8b78:  d4 07 00 12  ld  [ %i4 + %l2 ], %o2
a00e8b7c:  7f ff de 66  call  0xa00e0514
a00e8b80:  90 10 00 18  mov  %i0, %o0
a00e8b84:  96 02 20 01  add  %o0, 1, %o3
a00e8b88:  f4 07 40 12  ld  [ %i5 + %l2 ], %i2
a00e8b8c:  92 06 80 11  add  %i2, %l1, %o1
a00e8b90:  90 10 00 18  mov  %i0, %o0
a00e8b94:  7f ff de 91  call  0xa00e05d8
a00e8b98:  d4 07 00 12  ld  [ %i4 + %l2 ], %o2
a00e8b9c:  90 10 00 18  mov  %i0, %o0
a00e8ba0:  92 10 00 1b  mov  %i3, %o1
a00e8ba4:  94 10 00 11  mov  %l1, %o2
a00e8ba8:  7f ff fc 88  call  0xa00e7dc8
a00e8bac:  96 10 20 00  clr  %o3
a00e8bb0:  80 a2 20 00  cmp  %o0, 0
a00e8bb4:  12 bf fd 8e  bne  0xa00e81ec
a00e8bb8:  90 10 00 18  mov  %i0, %o0
a00e8bbc:  92 10 00 1b  mov  %i3, %o1
a00e8bc0:  94 10 00 11  mov  %l1, %o2
a00e8bc4:  7f ff fc 81  call  0xa00e7dc8
a00e8bc8:  96 10 20 01  mov  1, %o3
a00e8bcc:  80 a2 20 00  cmp  %o0, 0
a00e8bd0:  12 bf fd 87  bne  0xa00e81ec
a00e8bd4:  90 10 00 18  mov  %i0, %o0
a00e8bd8:  92 10 00 1b  mov  %i3, %o1
a00e8bdc:  94 10 00 11  mov  %l1, %o2
a00e8be0:  7f ff fc 7a  call  0xa00e7dc8
a00e8be4:  96 10 20 00  clr  %o3
a00e8be8:  80 a2 20 00  cmp  %o0, 0
a00e8bec:  12 bf fd 81  bne  0xa00e81f0
a00e8bf0:  90 10 00 18  mov  %i0, %o0
a00e8bf4:  a2 04 60 01  inc  %l1
a00e8bf8:  80 a4 60 07  cmp  %l1, 7
a00e8bfc:  04 bf ff c4  ble  0xa00e8b0c
a00e8c00:  83 2d c0 11  sll  %l7, %l1, %g1
a00e8c04:  90 10 00 18  mov  %i0, %o0
a00e8c08:  92 10 20 05  mov  5, %o1
a00e8c0c:  94 10 20 00  clr  %o2
a00e8c10:  7f ff ed 17  call  0xa00e406c
a00e8c14:  17 00 00 04  sethi  %hi(0x1000), %o3
a00e8c18:  80 a5 60 ff  cmp  %l5, 0xff
a00e8c1c:  32 bf ff bb  bne,a   0xa00e8b08
a00e8c20:  a2 10 20 00  clr  %l1
a00e8c24:  10 bf fd 73  b  0xa00e81f0
a00e8c28:  90 10 00 18  mov  %i0, %o0
a00e8c2c:  a1 2d c0 11  sll  %l7, %l1, %l0
a00e8c30:  10 bf ff f1  b  0xa00e8bf4
a00e8c34:  aa 15 40 10  or  %l5, %l0, %l5
a00e8c38:  a6 04 e0 01  inc  %l3
a00e8c3c:  80 a4 e0 07  cmp  %l3, 7
a00e8c40:  04 bf fd e0  ble  0xa00e83c0
a00e8c44:  a0 10 20 00  clr  %l0
a00e8c48:  2f 2a 00 98  sethi  %hi(0xa8026000), %l7
a00e8c4c:  2d 2a 00 98  sethi  %hi(0xa8026000), %l6
a00e8c50:  a2 15 e2 88  or  %l7, 0x288, %l1
a00e8c54:  10 80 00 06  b  0xa00e8c6c
a00e8c58:  a6 15 a2 78  or  %l6, 0x278, %l3
a00e8c5c:  a0 04 20 01  inc  %l0
a00e8c60:  80 a4 20 07  cmp  %l0, 7
a00e8c64:  14 bf ff 99  bg  0xa00e8ac8
a00e8c68:  90 10 20 00  clr  %o0
a00e8c6c:  c2 04 40 12  ld  [ %l1 + %l2 ], %g1
a00e8c70:  92 00 40 10  add  %g1, %l0, %o1
a00e8c74:  d4 04 c0 12  ld  [ %l3 + %l2 ], %o2
a00e8c78:  7f ff de 27  call  0xa00e0514
a00e8c7c:  90 10 00 18  mov  %i0, %o0
a00e8c80:  b8 10 00 08  mov  %o0, %i4
a00e8c84:  bb 37 20 03  srl  %i4, 3, %i5
a00e8c88:  98 07 7f ff  add  %i5, -1, %o4
a00e8c8c:  b3 2b 20 03  sll  %o4, 3, %i1
a00e8c90:  aa 0f 20 07  and  %i4, 7, %l5
a00e8c94:  90 10 00 18  mov  %i0, %o0
a00e8c98:  80 a7 60 00  cmp  %i5, 0
a00e8c9c:  02 bf ff f0  be  0xa00e8c5c
a00e8ca0:  96 06 40 15  add  %i1, %l5, %o3
a00e8ca4:  da 04 40 12  ld  [ %l1 + %l2 ], %o5
a00e8ca8:  92 03 40 10  add  %o5, %l0, %o1
a00e8cac:  7f ff de 4b  call  0xa00e05d8
a00e8cb0:  d4 04 c0 12  ld  [ %l3 + %l2 ], %o2
a00e8cb4:  92 10 00 1b  mov  %i3, %o1
a00e8cb8:  94 10 00 10  mov  %l0, %o2
a00e8cbc:  96 10 20 00  clr  %o3
a00e8cc0:  7f ff fc 42  call  0xa00e7dc8
a00e8cc4:  90 10 00 18  mov  %i0, %o0
a00e8cc8:  82 10 00 08  mov  %o0, %g1
a00e8ccc:  94 10 00 10  mov  %l0, %o2
a00e8cd0:  92 10 00 1b  mov  %i3, %o1
a00e8cd4:  96 10 20 01  mov  1, %o3
a00e8cd8:  80 a0 60 00  cmp  %g1, 0
a00e8cdc:  12 80 00 4f  bne  0xa00e8e18
a00e8ce0:  90 10 00 18  mov  %i0, %o0
a00e8ce4:  7f ff fc 39  call  0xa00e7dc8
a00e8ce8:  01 00 00 00  nop
a00e8cec:  82 10 00 08  mov  %o0, %g1
a00e8cf0:  94 10 00 10  mov  %l0, %o2
a00e8cf4:  90 10 00 18  mov  %i0, %o0
a00e8cf8:  92 10 00 1b  mov  %i3, %o1
a00e8cfc:  80 a0 60 00  cmp  %g1, 0
a00e8d00:  12 80 00 46  bne  0xa00e8e18
a00e8d04:  96 10 20 00  clr  %o3
a00e8d08:  7f ff fc 30  call  0xa00e7dc8
a00e8d0c:  01 00 00 00  nop
a00e8d10:  80 a2 20 00  cmp  %o0, 0
a00e8d14:  22 bf ff d3  be,a   0xa00e8c60
a00e8d18:  a0 04 20 01  inc  %l0
a00e8d1c:  10 bf ff 6c  b  0xa00e8acc
a00e8d20:  ac 92 20 00  orcc  %o0, 0, %l6
a00e8d24:  33 2a 00 99  sethi  %hi(0xa8026400), %i1
a00e8d28:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e8d2c:  23 2a 00 ad  sethi  %hi(0xa802b400), %l1
a00e8d30:  90 10 00 18  mov  %i0, %o0
a00e8d34:  92 16 63 e8  or  %i1, 0x3e8, %o1
a00e8d38:  94 14 e3 d8  or  %l3, 0x3d8, %o2
a00e8d3c:  10 bf ff 1c  b  0xa00e89ac
a00e8d40:  96 14 62 f8  or  %l1, 0x2f8, %o3
a00e8d44:  7f ff da b2  call  0xa00df80c
a00e8d48:  31 00 06 66  sethi  %hi(0x199800), %i0
a00e8d4c:  7f ff df 9d  call  0xa00e0bc0
a00e8d50:  01 00 00 00  nop
a00e8d54:  90 16 23 28  or  %i0, 0x328, %o0
a00e8d58:  7f ff d9 06  call  0xa00df170
a00e8d5c:  92 10 00 1b  mov  %i3, %o1
a00e8d60:  10 80 00 41  b  0xa00e8e64
a00e8d64:  90 10 3f ff  mov  -1, %o0
a00e8d68:  ac 10 20 01  mov  1, %l6
a00e8d6c:  80 a5 a0 00  cmp  %l6, 0
a00e8d70:  02 bf fd c5  be  0xa00e8484
a00e8d74:  39 2a 00 9a  sethi  %hi(0xa8026800), %i4
a00e8d78:  80 a6 ff ff  cmp  %i3, -1
a00e8d7c:  02 80 00 29  be  0xa00e8e20
a00e8d80:  2d 2a 00 9a  sethi  %hi(0xa8026800), %l6
a00e8d84:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e8d88:  a2 12 63 f8  or  %o1, 0x3f8, %l1	! 0xa80267f8
a00e8d8c:  90 15 a0 18  or  %l6, 0x18, %o0
a00e8d90:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00e8d94:  d2 02 00 12  ld  [ %o0 + %l2 ], %o1
a00e8d98:  9e 16 60 08  or  %i1, 8, %o7
a00e8d9c:  d6 04 40 12  ld  [ %l1 + %l2 ], %o3
a00e8da0:  d4 03 c0 12  ld  [ %o7 + %l2 ], %o2
a00e8da4:  7f ff de 6c  call  0xa00e0754
a00e8da8:  90 10 00 18  mov  %i0, %o0
a00e8dac:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e8db0:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00e8db4:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e8db8:  a2 10 00 08  mov  %o0, %l1
a00e8dbc:  9a 10 63 e8  or  %g1, 0x3e8, %o5
a00e8dc0:  98 12 a3 d8  or  %o2, 0x3d8, %o4
a00e8dc4:  a6 12 e2 f8  or  %o3, 0x2f8, %l3
a00e8dc8:  d2 03 40 12  ld  [ %o5 + %l2 ], %o1
a00e8dcc:  d4 03 00 12  ld  [ %o4 + %l2 ], %o2
a00e8dd0:  d6 04 c0 12  ld  [ %l3 + %l2 ], %o3
a00e8dd4:  90 10 00 18  mov  %i0, %o0
a00e8dd8:  7f ff de 5f  call  0xa00e0754
a00e8ddc:  01 00 00 00  nop
a00e8de0:  a0 10 00 08  mov  %o0, %l0
a00e8de4:  80 94 40 08  orcc  %l1, %o0, %g0
a00e8de8:  02 bf fc fe  be  0xa00e81e0
a00e8dec:  82 10 20 00  clr  %g1
a00e8df0:  7f ff da 87  call  0xa00df80c
a00e8df4:  35 00 06 66  sethi  %hi(0x199800), %i2
a00e8df8:  7f ff df 72  call  0xa00e0bc0
a00e8dfc:  01 00 00 00  nop
a00e8e00:  90 16 a3 50  or  %i2, 0x350, %o0
a00e8e04:  92 10 00 11  mov  %l1, %o1
a00e8e08:  7f ff d8 da  call  0xa00df170
a00e8e0c:  94 10 00 10  mov  %l0, %o2
a00e8e10:  10 bf fc f4  b  0xa00e81e0
a00e8e14:  82 10 3f ff  mov  -1, %g1
a00e8e18:  10 bf ff 2c  b  0xa00e8ac8
a00e8e1c:  90 10 00 01  mov  %g1, %o0
a00e8e20:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00e8e24:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00e8e28:  39 2a 00 99  sethi  %hi(0xa8026400), %i4
a00e8e2c:  92 14 20 18  or  %l0, 0x18, %o1
a00e8e30:  94 15 60 08  or  %l5, 8, %o2
a00e8e34:  96 17 23 f8  or  %i4, 0x3f8, %o3
a00e8e38:  7f ff de 47  call  0xa00e0754
a00e8e3c:  90 10 00 18  mov  %i0, %o0
a00e8e40:  a2 10 00 08  mov  %o0, %l1
a00e8e44:  2f 2a 00 99  sethi  %hi(0xa8026400), %l7
a00e8e48:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00e8e4c:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00e8e50:  90 10 00 18  mov  %i0, %o0
a00e8e54:  92 15 e3 e8  or  %l7, 0x3e8, %o1
a00e8e58:  94 17 63 d8  or  %i5, 0x3d8, %o2
a00e8e5c:  10 bf ff df  b  0xa00e8dd8
a00e8e60:  96 16 a2 f8  or  %i2, 0x2f8, %o3
a00e8e64:  81 c7 e0 08  ret
a00e8e68:  91 e8 00 08  restore  %g0, %o0, %o0
