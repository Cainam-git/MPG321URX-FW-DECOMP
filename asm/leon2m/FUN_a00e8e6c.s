# leon2m FUN_a00e8e6c 0xa00e8e6c-0xa00e9b34 (3272 bytes)
a00e8e6c:  9d e3 bf 80  save  %sp, -128, %sp
a00e8e70:  c2 07 a0 40  ld  [ %fp + 0x40 ], %g1
a00e8e74:  80 a6 a0 03  cmp  %i2, 3
a00e8e78:  02 80 01 5a  be  0xa00e93e0
a00e8e7c:  c2 27 bf ec  st  %g1, [ %fp + -20 ]
a00e8e80:  90 10 00 18  mov  %i0, %o0
a00e8e84:  92 10 00 19  mov  %i1, %o1
a00e8e88:  7f ff db 72  call  0xa00dfc50
a00e8e8c:  94 10 00 1a  mov  %i2, %o2
a00e8e90:  80 a6 ff ff  cmp  %i3, -1
a00e8e94:  02 80 00 c0  be  0xa00e9194
a00e8e98:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00e8e9c:  9f 2e e0 02  sll  %i3, 2, %o7
a00e8ea0:  92 14 23 08  or  %l0, 0x308, %o1
a00e8ea4:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00e8ea8:  94 14 a0 38  or  %l2, 0x38, %o2	! 0xa8026838
a00e8eac:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00e8eb0:  d6 02 40 0f  ld  [ %o1 + %o7 ], %o3
a00e8eb4:  90 14 60 28  or  %l1, 0x28, %o0
a00e8eb8:  d2 02 80 0f  ld  [ %o2 + %o7 ], %o1
a00e8ebc:  d4 02 00 0f  ld  [ %o0 + %o7 ], %o2
a00e8ec0:  90 10 00 18  mov  %i0, %o0
a00e8ec4:  7f ff de 24  call  0xa00e0754
a00e8ec8:  01 00 00 00  nop
a00e8ecc:  d0 27 bf e0  st  %o0, [ %fp + -32 ]
a00e8ed0:  7f ff dc 70  call  0xa00e0090
a00e8ed4:  90 10 00 18  mov  %i0, %o0
a00e8ed8:  90 10 00 18  mov  %i0, %o0
a00e8edc:  92 10 00 19  mov  %i1, %o1
a00e8ee0:  94 10 00 1a  mov  %i2, %o2
a00e8ee4:  7f ff ec e5  call  0xa00e4278
a00e8ee8:  96 10 00 1c  mov  %i4, %o3
a00e8eec:  80 a2 20 00  cmp  %o0, 0
a00e8ef0:  02 80 00 0c  be  0xa00e8f20
a00e8ef4:  29 2a 00 9a  sethi  %hi(0xa8026800), %l4
a00e8ef8:  80 a6 a0 03  cmp  %i2, 3
a00e8efc:  02 80 00 ae  be  0xa00e91b4
a00e8f00:  01 00 00 00  nop
a00e8f04:  82 10 3f ff  mov  -1, %g1	! 0xffffffff
a00e8f08:  da 07 bf ec  ld  [ %fp + -20 ], %o5
a00e8f0c:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a00e8f10:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a00e8f14:  c2 27 bf f4  st  %g1, [ %fp + -12 ]
a00e8f18:  10 80 03 04  b  0xa00e9b28
a00e8f1c:  c2 23 40 00  st  %g1, [ %o5 ]
a00e8f20:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00e8f24:  a4 15 20 08  or  %l4, 8, %l2
a00e8f28:  2f 2a 00 9a  sethi  %hi(0xa8026800), %l7
a00e8f2c:  a6 17 63 f8  or  %i5, 0x3f8, %l3
a00e8f30:  a3 2e e0 02  sll  %i3, 2, %l1
a00e8f34:  a8 15 e0 18  or  %l7, 0x18, %l4
a00e8f38:  ac 10 00 12  mov  %l2, %l6
a00e8f3c:  aa 10 00 13  mov  %l3, %l5
a00e8f40:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00e8f44:  90 10 00 18  mov  %i0, %o0
a00e8f48:  92 15 e0 18  or  %l7, 0x18, %o1
a00e8f4c:  94 10 60 08  or  %g1, 8, %o2
a00e8f50:  80 a6 ff ff  cmp  %i3, -1
a00e8f54:  02 80 00 06  be  0xa00e8f6c
a00e8f58:  96 17 63 f8  or  %i5, 0x3f8, %o3
a00e8f5c:  d2 05 00 11  ld  [ %l4 + %l1 ], %o1
a00e8f60:  d4 04 80 11  ld  [ %l2 + %l1 ], %o2
a00e8f64:  d6 04 c0 11  ld  [ %l3 + %l1 ], %o3
a00e8f68:  90 10 00 18  mov  %i0, %o0
a00e8f6c:  7f ff dd fa  call  0xa00e0754
a00e8f70:  01 00 00 00  nop
a00e8f74:  da 05 80 11  ld  [ %l6 + %l1 ], %o5
a00e8f78:  de 05 40 11  ld  [ %l5 + %l1 ], %o7
a00e8f7c:  99 33 40 0f  srl  %o5, %o7, %o4
a00e8f80:  80 a3 00 08  cmp  %o4, %o0
a00e8f84:  02 80 00 11  be  0xa00e8fc8
a00e8f88:  a0 10 00 08  mov  %o0, %l0
a00e8f8c:  a0 04 20 01  inc  %l0
a00e8f90:  90 10 00 18  mov  %i0, %o0
a00e8f94:  92 15 e0 18  or  %l7, 0x18, %o1
a00e8f98:  94 10 00 16  mov  %l6, %o2
a00e8f9c:  96 10 00 15  mov  %l5, %o3
a00e8fa0:  80 a6 ff ff  cmp  %i3, -1
a00e8fa4:  02 80 00 07  be  0xa00e8fc0
a00e8fa8:  98 10 00 10  mov  %l0, %o4
a00e8fac:  94 10 00 0d  mov  %o5, %o2
a00e8fb0:  96 10 00 0f  mov  %o7, %o3
a00e8fb4:  d2 05 00 11  ld  [ %l4 + %l1 ], %o1
a00e8fb8:  98 10 00 10  mov  %l0, %o4
a00e8fbc:  90 10 00 18  mov  %i0, %o0
a00e8fc0:  7f ff dd ed  call  0xa00e0774
a00e8fc4:  01 00 00 00  nop
a00e8fc8:  7f ff dc 32  call  0xa00e0090
a00e8fcc:  90 10 00 18  mov  %i0, %o0
a00e8fd0:  90 10 00 18  mov  %i0, %o0
a00e8fd4:  92 10 00 19  mov  %i1, %o1
a00e8fd8:  94 10 00 1a  mov  %i2, %o2
a00e8fdc:  7f ff ec a7  call  0xa00e4278
a00e8fe0:  96 10 00 1c  mov  %i4, %o3
a00e8fe4:  80 a2 20 02  cmp  %o0, 2
a00e8fe8:  02 80 01 04  be  0xa00e93f8
a00e8fec:  80 a2 20 01  cmp  %o0, 1
a00e8ff0:  02 80 01 15  be  0xa00e9444
a00e8ff4:  80 a6 ff ff  cmp  %i3, -1
a00e8ff8:  de 04 80 11  ld  [ %l2 + %l1 ], %o7
a00e8ffc:  da 04 c0 11  ld  [ %l3 + %l1 ], %o5
a00e9000:  97 33 c0 0d  srl  %o7, %o5, %o3
a00e9004:  80 a2 c0 10  cmp  %o3, %l0
a00e9008:  12 bf ff cf  bne  0xa00e8f44
a00e900c:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00e9010:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00e9014:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e9018:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e901c:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00e9020:  ac 14 a0 08  or  %l2, 8, %l6
a00e9024:  aa 12 63 e8  or  %o1, 0x3e8, %l5
a00e9028:  a8 12 a3 d8  or  %o2, 0x3d8, %l4
a00e902c:  10 80 00 21  b  0xa00e90b0
a00e9030:  a6 12 22 f8  or  %o0, 0x2f8, %l3
a00e9034:  d2 05 40 11  ld  [ %l5 + %l1 ], %o1
a00e9038:  d4 05 00 11  ld  [ %l4 + %l1 ], %o2
a00e903c:  7f ff dd c6  call  0xa00e0754
a00e9040:  d6 04 c0 11  ld  [ %l3 + %l1 ], %o3
a00e9044:  a4 10 00 08  mov  %o0, %l2
a00e9048:  d0 05 00 11  ld  [ %l4 + %l1 ], %o0
a00e904c:  da 04 c0 11  ld  [ %l3 + %l1 ], %o5
a00e9050:  9f 32 00 0d  srl  %o0, %o5, %o7
a00e9054:  80 a3 c0 12  cmp  %o7, %l2
a00e9058:  02 80 00 27  be  0xa00e90f4
a00e905c:  80 a6 ff ff  cmp  %i3, -1
a00e9060:  02 80 00 45  be  0xa00e9174
a00e9064:  a4 04 a0 01  inc  %l2
a00e9068:  90 10 00 18  mov  %i0, %o0
a00e906c:  d2 05 40 11  ld  [ %l5 + %l1 ], %o1
a00e9070:  d4 05 00 11  ld  [ %l4 + %l1 ], %o2
a00e9074:  d6 04 c0 11  ld  [ %l3 + %l1 ], %o3
a00e9078:  7f ff dd bf  call  0xa00e0774
a00e907c:  98 10 00 12  mov  %l2, %o4
a00e9080:  7f ff dc 04  call  0xa00e0090
a00e9084:  90 10 00 18  mov  %i0, %o0
a00e9088:  90 10 00 18  mov  %i0, %o0
a00e908c:  92 10 00 19  mov  %i1, %o1
a00e9090:  94 10 00 1a  mov  %i2, %o2
a00e9094:  7f ff ec 79  call  0xa00e4278
a00e9098:  96 10 00 1c  mov  %i4, %o3
a00e909c:  80 a2 20 02  cmp  %o0, 2
a00e90a0:  02 80 01 af  be  0xa00e975c
a00e90a4:  80 a2 20 01  cmp  %o0, 1
a00e90a8:  02 80 00 4c  be  0xa00e91d8
a00e90ac:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00e90b0:  80 a6 ff ff  cmp  %i3, -1
a00e90b4:  12 bf ff e0  bne  0xa00e9034
a00e90b8:  90 10 00 18  mov  %i0, %o0
a00e90bc:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e90c0:  92 12 e3 e8  or  %o3, 0x3e8, %o1	! 0xa80267e8
a00e90c4:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e90c8:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00e90cc:  94 13 23 d8  or  %o4, 0x3d8, %o2
a00e90d0:  7f ff dd a1  call  0xa00e0754
a00e90d4:  96 10 62 f8  or  %g1, 0x2f8, %o3
a00e90d8:  a4 10 00 08  mov  %o0, %l2
a00e90dc:  d0 05 00 11  ld  [ %l4 + %l1 ], %o0
a00e90e0:  da 04 c0 11  ld  [ %l3 + %l1 ], %o5
a00e90e4:  9f 32 00 0d  srl  %o0, %o5, %o7
a00e90e8:  80 a3 c0 12  cmp  %o7, %l2
a00e90ec:  12 bf ff dd  bne  0xa00e9060
a00e90f0:  80 a6 ff ff  cmp  %i3, -1
a00e90f4:  02 80 00 7d  be  0xa00e92e8
a00e90f8:  9e 17 63 f8  or  %i5, 0x3f8, %o7
a00e90fc:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00e9100:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00e9104:  98 12 60 18  or  %o1, 0x18, %o4
a00e9108:  82 12 a0 08  or  %o2, 8, %g1
a00e910c:  d6 03 c0 11  ld  [ %o7 + %l1 ], %o3
a00e9110:  90 10 00 18  mov  %i0, %o0
a00e9114:  d2 03 00 11  ld  [ %o4 + %l1 ], %o1
a00e9118:  d4 00 40 11  ld  [ %g1 + %l1 ], %o2
a00e911c:  7f ff dd 8e  call  0xa00e0754
a00e9120:  01 00 00 00  nop
a00e9124:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e9128:  9a 12 e3 f8  or  %o3, 0x3f8, %o5	! 0xa80267f8
a00e912c:  a0 10 00 08  mov  %o0, %l0
a00e9130:  d4 05 80 11  ld  [ %l6 + %l1 ], %o2
a00e9134:  d6 03 40 11  ld  [ %o5 + %l1 ], %o3
a00e9138:  91 32 80 0b  srl  %o2, %o3, %o0
a00e913c:  80 a2 00 10  cmp  %o0, %l0
a00e9140:  02 80 00 25  be  0xa00e91d4
a00e9144:  80 a6 ff ff  cmp  %i3, -1
a00e9148:  02 80 00 6e  be  0xa00e9300
a00e914c:  a0 04 20 01  inc  %l0
a00e9150:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00e9154:  82 13 20 18  or  %o4, 0x18, %g1	! 0xa8026818
a00e9158:  90 10 00 18  mov  %i0, %o0
a00e915c:  d2 00 40 11  ld  [ %g1 + %l1 ], %o1
a00e9160:  7f ff dd 85  call  0xa00e0774
a00e9164:  98 10 00 10  mov  %l0, %o4
a00e9168:  80 a6 ff ff  cmp  %i3, -1
a00e916c:  12 bf ff bf  bne  0xa00e9068
a00e9170:  a4 10 20 00  clr  %l2
a00e9174:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e9178:  92 12 a3 e8  or  %o2, 0x3e8, %o1	! 0xa80267e8
a00e917c:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e9180:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00e9184:  90 10 00 18  mov  %i0, %o0
a00e9188:  94 13 63 d8  or  %o5, 0x3d8, %o2
a00e918c:  10 bf ff bb  b  0xa00e9078
a00e9190:  96 13 e2 f8  or  %o7, 0x2f8, %o3
a00e9194:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00e9198:  92 12 e0 38  or  %o3, 0x38, %o1	! 0xa8026838
a00e919c:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00e91a0:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00e91a4:  90 10 00 18  mov  %i0, %o0
a00e91a8:  94 13 20 28  or  %o4, 0x28, %o2
a00e91ac:  10 bf ff 46  b  0xa00e8ec4
a00e91b0:  96 13 63 08  or  %o5, 0x308, %o3
a00e91b4:  7f ff d9 96  call  0xa00df80c
a00e91b8:  27 00 06 66  sethi  %hi(0x199800), %l3
a00e91bc:  7f ff de 81  call  0xa00e0bc0
a00e91c0:  01 00 00 00  nop
a00e91c4:  7f ff d7 eb  call  0xa00df170
a00e91c8:  90 14 e3 90  or  %l3, 0x390, %o0
a00e91cc:  10 bf ff 4f  b  0xa00e8f08
a00e91d0:  82 10 3f ff  mov  -1, %g1
a00e91d4:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00e91d8:  92 12 20 08  or  %o0, 8, %o1	! 0xa8026808
a00e91dc:  ac 17 63 f8  or  %i5, 0x3f8, %l6
a00e91e0:  e8 02 40 11  ld  [ %o1 + %l1 ], %l4
a00e91e4:  ea 05 80 11  ld  [ %l6 + %l1 ], %l5
a00e91e8:  a7 35 00 15  srl  %l4, %l5, %l3
a00e91ec:  80 a4 c0 10  cmp  %l3, %l0
a00e91f0:  02 80 00 b2  be  0xa00e94b8
a00e91f4:  27 2a 00 99  sethi  %hi(0xa8026400), %l3
a00e91f8:  e0 27 bf e8  st  %l0, [ %fp + -24 ]
a00e91fc:  80 a6 ff ff  cmp  %i3, -1
a00e9200:  02 80 00 a6  be  0xa00e9498
a00e9204:  e4 27 bf e4  st  %l2, [ %fp + -28 ]
a00e9208:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00e920c:  90 12 e0 28  or  %o3, 0x28, %o0	! 0xa8026828
a00e9210:  13 2a 00 ad  sethi  %hi(0xa802b400), %o1
a00e9214:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00e9218:  ac 12 63 08  or  %o1, 0x308, %l6
a00e921c:  82 13 20 38  or  %o4, 0x38, %g1
a00e9220:  d4 02 00 11  ld  [ %o0 + %l1 ], %o2
a00e9224:  d2 00 40 11  ld  [ %g1 + %l1 ], %o1
a00e9228:  d6 05 80 11  ld  [ %l6 + %l1 ], %o3
a00e922c:  90 10 00 18  mov  %i0, %o0
a00e9230:  7f ff dd 51  call  0xa00e0774
a00e9234:  d8 07 bf e0  ld  [ %fp + -32 ], %o4
a00e9238:  7f ff db 96  call  0xa00e0090
a00e923c:  90 10 00 18  mov  %i0, %o0
a00e9240:  90 10 00 18  mov  %i0, %o0
a00e9244:  92 10 00 19  mov  %i1, %o1
a00e9248:  94 10 00 1a  mov  %i2, %o2
a00e924c:  7f ff ec 0b  call  0xa00e4278
a00e9250:  96 10 00 1c  mov  %i4, %o3
a00e9254:  a0 92 20 00  orcc  %o0, 0, %l0
a00e9258:  02 80 00 30  be  0xa00e9318
a00e925c:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e9260:  80 a6 a0 03  cmp  %i2, 3
a00e9264:  12 bf ff 29  bne  0xa00e8f08
a00e9268:  82 10 3f ff  mov  -1, %g1
a00e926c:  7f ff d9 68  call  0xa00df80c
a00e9270:  2f 00 06 66  sethi  %hi(0x199800), %l7
a00e9274:  7f ff de 53  call  0xa00e0bc0
a00e9278:  01 00 00 00  nop
a00e927c:  92 10 00 10  mov  %l0, %o1
a00e9280:  7f ff d7 bc  call  0xa00df170
a00e9284:  90 15 e3 b8  or  %l7, 0x3b8, %o0
a00e9288:  7f ff d9 61  call  0xa00df80c
a00e928c:  01 00 00 00  nop
a00e9290:  7f ff de 4c  call  0xa00e0bc0
a00e9294:  01 00 00 00  nop
a00e9298:  80 a6 ff ff  cmp  %i3, -1
a00e929c:  02 80 02 0f  be  0xa00e9ad8
a00e92a0:  1b 2a 00 9a  sethi  %hi(0xa8026800), %o5
a00e92a4:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00e92a8:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00e92ac:  b8 13 60 38  or  %o5, 0x38, %i4
a00e92b0:  b6 12 a0 28  or  %o2, 0x28, %i3
a00e92b4:  ba 13 e3 08  or  %o7, 0x308, %i5
a00e92b8:  d6 07 40 11  ld  [ %i5 + %l1 ], %o3
a00e92bc:  90 10 00 18  mov  %i0, %o0
a00e92c0:  d2 07 00 11  ld  [ %i4 + %l1 ], %o1
a00e92c4:  d4 06 c0 11  ld  [ %i3 + %l1 ], %o2
a00e92c8:  7f ff dd 23  call  0xa00e0754
a00e92cc:  23 00 06 66  sethi  %hi(0x199800), %l1
a00e92d0:  94 10 00 08  mov  %o0, %o2
a00e92d4:  90 14 63 f0  or  %l1, 0x3f0, %o0
a00e92d8:  7f ff d7 a6  call  0xa00df170
a00e92dc:  d2 07 bf e0  ld  [ %fp + -32 ], %o1
a00e92e0:  10 bf ff 0a  b  0xa00e8f08
a00e92e4:  82 10 3f ff  mov  -1, %g1
a00e92e8:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00e92ec:  90 10 00 18  mov  %i0, %o0
a00e92f0:  92 15 e0 18  or  %l7, 0x18, %o1
a00e92f4:  94 14 20 08  or  %l0, 8, %o2
a00e92f8:  10 bf ff 89  b  0xa00e911c
a00e92fc:  96 17 63 f8  or  %i5, 0x3f8, %o3
a00e9300:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e9304:  90 10 00 18  mov  %i0, %o0
a00e9308:  92 15 e0 18  or  %l7, 0x18, %o1
a00e930c:  94 10 00 16  mov  %l6, %o2
a00e9310:  10 bf ff 94  b  0xa00e9160
a00e9314:  96 14 a3 f8  or  %l2, 0x3f8, %o3
a00e9318:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00e931c:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e9320:  ac 15 23 d8  or  %l4, 0x3d8, %l6
a00e9324:  a8 14 a0 18  or  %l2, 0x18, %l4
a00e9328:  1f 2a 00 9a  sethi  %hi(0xa8026800), %o7
a00e932c:  a6 15 63 f8  or  %l5, 0x3f8, %l3
a00e9330:  15 2a 00 99  sethi  %hi(0xa8026400), %o2
a00e9334:  a4 13 e0 08  or  %o7, 8, %l2
a00e9338:  80 a6 ff ff  cmp  %i3, -1
a00e933c:  02 80 00 6d  be  0xa00e94f0
a00e9340:  aa 12 a3 e8  or  %o2, 0x3e8, %l5
a00e9344:  d2 05 00 11  ld  [ %l4 + %l1 ], %o1
a00e9348:  d4 04 80 11  ld  [ %l2 + %l1 ], %o2
a00e934c:  d6 04 c0 11  ld  [ %l3 + %l1 ], %o3
a00e9350:  7f ff dd 01  call  0xa00e0754
a00e9354:  90 10 00 18  mov  %i0, %o0
a00e9358:  a0 92 20 00  orcc  %o0, 0, %l0
a00e935c:  02 80 00 11  be  0xa00e93a0
a00e9360:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00e9364:  a0 04 3f ff  add  %l0, -1, %l0
a00e9368:  90 10 00 18  mov  %i0, %o0
a00e936c:  92 15 e0 18  or  %l7, 0x18, %o1
a00e9370:  94 10 60 08  or  %g1, 8, %o2
a00e9374:  96 17 63 f8  or  %i5, 0x3f8, %o3
a00e9378:  80 a6 ff ff  cmp  %i3, -1
a00e937c:  02 80 00 07  be  0xa00e9398
a00e9380:  98 10 00 10  mov  %l0, %o4
a00e9384:  d2 05 00 11  ld  [ %l4 + %l1 ], %o1
a00e9388:  d4 04 80 11  ld  [ %l2 + %l1 ], %o2
a00e938c:  d6 04 c0 11  ld  [ %l3 + %l1 ], %o3
a00e9390:  98 10 00 10  mov  %l0, %o4
a00e9394:  90 10 00 18  mov  %i0, %o0
a00e9398:  7f ff dc f7  call  0xa00e0774
a00e939c:  01 00 00 00  nop
a00e93a0:  7f ff db 3c  call  0xa00e0090
a00e93a4:  90 10 00 18  mov  %i0, %o0
a00e93a8:  90 10 00 18  mov  %i0, %o0
a00e93ac:  92 10 00 19  mov  %i1, %o1
a00e93b0:  94 10 00 1a  mov  %i2, %o2
a00e93b4:  7f ff eb b1  call  0xa00e4278
a00e93b8:  96 10 00 1c  mov  %i4, %o3
a00e93bc:  80 a2 20 02  cmp  %o0, 2
a00e93c0:  02 80 00 fb  be  0xa00e97ac
a00e93c4:  80 a2 20 01  cmp  %o0, 1
a00e93c8:  02 80 01 09  be  0xa00e97ec
a00e93cc:  80 a4 20 00  cmp  %l0, 0
a00e93d0:  32 bf ff de  bne,a   0xa00e9348
a00e93d4:  d2 05 00 11  ld  [ %l4 + %l1 ], %o1
a00e93d8:  10 80 00 67  b  0xa00e9574
a00e93dc:  80 a6 ff ff  cmp  %i3, -1
a00e93e0:  90 10 20 08  mov  8, %o0
a00e93e4:  92 10 00 18  mov  %i0, %o1
a00e93e8:  7f ff da f3  call  0xa00dffb4
a00e93ec:  94 10 00 1b  mov  %i3, %o2
a00e93f0:  10 bf fe a5  b  0xa00e8e84
a00e93f4:  90 10 00 18  mov  %i0, %o0
a00e93f8:  7f ff d9 05  call  0xa00df80c
a00e93fc:  21 00 06 67  sethi  %hi(0x199c00), %l0
a00e9400:  7f ff dd f0  call  0xa00e0bc0
a00e9404:  31 00 06 67  sethi  %hi(0x199c00), %i0
a00e9408:  7f ff d7 5a  call  0xa00df170
a00e940c:  90 14 20 20  or  %l0, 0x20, %o0
a00e9410:  7f ff d8 ff  call  0xa00df80c
a00e9414:  01 00 00 00  nop
a00e9418:  7f ff dd ea  call  0xa00e0bc0
a00e941c:  01 00 00 00  nop
a00e9420:  90 16 20 38  or  %i0, 0x38, %o0
a00e9424:  7f ff d7 53  call  0xa00df170
a00e9428:  b2 10 3f ff  mov  -1, %i1
a00e942c:  d8 07 bf ec  ld  [ %fp + -20 ], %o4
a00e9430:  f2 23 20 04  st  %i1, [ %o4 + 4 ]
a00e9434:  f2 27 bf f0  st  %i1, [ %fp + -16 ]
a00e9438:  f2 27 bf f4  st  %i1, [ %fp + -12 ]
a00e943c:  10 80 01 bb  b  0xa00e9b28
a00e9440:  f2 23 00 00  st  %i1, [ %o4 ]
a00e9444:  02 80 01 93  be  0xa00e9a90
a00e9448:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00e944c:  90 10 00 18  mov  %i0, %o0
a00e9450:  d2 05 00 11  ld  [ %l4 + %l1 ], %o1
a00e9454:  d4 04 80 11  ld  [ %l2 + %l1 ], %o2
a00e9458:  d6 04 c0 11  ld  [ %l3 + %l1 ], %o3
a00e945c:  7f ff dc be  call  0xa00e0754
a00e9460:  01 00 00 00  nop
a00e9464:  80 a6 ff ff  cmp  %i3, -1
a00e9468:  02 80 01 84  be  0xa00e9a78
a00e946c:  a0 02 3f ff  add  %o0, -1, %l0
a00e9470:  d2 05 00 11  ld  [ %l4 + %l1 ], %o1
a00e9474:  d4 04 80 11  ld  [ %l2 + %l1 ], %o2
a00e9478:  d6 04 c0 11  ld  [ %l3 + %l1 ], %o3
a00e947c:  90 10 00 18  mov  %i0, %o0
a00e9480:  7f ff dc bd  call  0xa00e0774
a00e9484:  98 10 00 10  mov  %l0, %o4
a00e9488:  7f ff db 02  call  0xa00e0090
a00e948c:  90 10 00 18  mov  %i0, %o0
a00e9490:  10 bf fe e1  b  0xa00e9014
a00e9494:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00e9498:  2b 2a 00 9a  sethi  %hi(0xa8026800), %l5
a00e949c:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00e94a0:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00e94a4:  90 10 00 18  mov  %i0, %o0
a00e94a8:  92 15 60 38  or  %l5, 0x38, %o1
a00e94ac:  94 14 a0 28  or  %l2, 0x28, %o2
a00e94b0:  10 bf ff 60  b  0xa00e9230
a00e94b4:  96 14 23 08  or  %l0, 0x308, %o3
a00e94b8:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00e94bc:  94 14 e3 d8  or  %l3, 0x3d8, %o2
a00e94c0:  9e 13 62 f8  or  %o5, 0x2f8, %o7
a00e94c4:  c2 02 80 11  ld  [ %o2 + %l1 ], %g1
a00e94c8:  d8 03 c0 11  ld  [ %o7 + %l1 ], %o4
a00e94cc:  97 30 40 0c  srl  %g1, %o4, %o3
a00e94d0:  80 a2 c0 12  cmp  %o3, %l2
a00e94d4:  32 bf ff 4a  bne,a   0xa00e91fc
a00e94d8:  e0 27 bf e8  st  %l0, [ %fp + -24 ]
a00e94dc:  29 00 06 67  sethi  %hi(0x199c00), %l4
a00e94e0:  7f ff d7 24  call  0xa00df170
a00e94e4:  90 15 20 58  or  %l4, 0x58, %o0	! 0x199c58
a00e94e8:  10 bf ff 45  b  0xa00e91fc
a00e94ec:  e0 27 bf e8  st  %l0, [ %fp + -24 ]
a00e94f0:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00e94f4:  94 12 20 08  or  %o0, 8, %o2	! 0xa8026808
a00e94f8:  92 15 e0 18  or  %l7, 0x18, %o1
a00e94fc:  96 17 63 f8  or  %i5, 0x3f8, %o3
a00e9500:  7f ff dc 95  call  0xa00e0754
a00e9504:  90 10 00 18  mov  %i0, %o0
a00e9508:  a0 92 20 00  orcc  %o0, 0, %l0
a00e950c:  02 80 00 0b  be  0xa00e9538
a00e9510:  90 10 00 18  mov  %i0, %o0
a00e9514:  a0 04 3f ff  add  %l0, -1, %l0
a00e9518:  80 a6 ff ff  cmp  %i3, -1
a00e951c:  02 80 00 8a  be  0xa00e9744
a00e9520:  98 10 00 10  mov  %l0, %o4
a00e9524:  d2 05 00 11  ld  [ %l4 + %l1 ], %o1
a00e9528:  d4 04 80 11  ld  [ %l2 + %l1 ], %o2
a00e952c:  d6 04 c0 11  ld  [ %l3 + %l1 ], %o3
a00e9530:  7f ff dc 91  call  0xa00e0774
a00e9534:  01 00 00 00  nop
a00e9538:  7f ff da d6  call  0xa00e0090
a00e953c:  90 10 00 18  mov  %i0, %o0
a00e9540:  90 10 00 18  mov  %i0, %o0
a00e9544:  92 10 00 19  mov  %i1, %o1
a00e9548:  94 10 00 1a  mov  %i2, %o2
a00e954c:  7f ff eb 4b  call  0xa00e4278
a00e9550:  96 10 00 1c  mov  %i4, %o3
a00e9554:  80 a2 20 02  cmp  %o0, 2
a00e9558:  02 80 00 95  be  0xa00e97ac
a00e955c:  80 a2 20 01  cmp  %o0, 1
a00e9560:  02 80 00 a3  be  0xa00e97ec
a00e9564:  80 a4 20 00  cmp  %l0, 0
a00e9568:  12 bf ff e3  bne  0xa00e94f4
a00e956c:  11 2a 00 9a  sethi  %hi(0xa8026800), %o0
a00e9570:  80 a6 ff ff  cmp  %i3, -1
a00e9574:  02 80 01 39  be  0xa00e9a58
a00e9578:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e957c:  13 2a 00 ad  sethi  %hi(0xa802b400), %o1
a00e9580:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e9584:  9e 12 62 f8  or  %o1, 0x2f8, %o7
a00e9588:  82 13 23 e8  or  %o4, 0x3e8, %g1
a00e958c:  9a 14 a3 d8  or  %l2, 0x3d8, %o5
a00e9590:  d2 00 40 11  ld  [ %g1 + %l1 ], %o1
a00e9594:  d4 03 40 11  ld  [ %o5 + %l1 ], %o2
a00e9598:  d6 03 c0 11  ld  [ %o7 + %l1 ], %o3
a00e959c:  90 10 00 18  mov  %i0, %o0
a00e95a0:  7f ff dc 6d  call  0xa00e0754
a00e95a4:  27 2a 00 ad  sethi  %hi(0xa802b400), %l3
a00e95a8:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e95ac:  13 2a 00 99  sethi  %hi(0xa8026400), %o1
a00e95b0:  a4 10 00 08  mov  %o0, %l2
a00e95b4:  a8 13 23 e8  or  %o4, 0x3e8, %l4
a00e95b8:  aa 12 63 d8  or  %o1, 0x3d8, %l5
a00e95bc:  80 a6 ff ff  cmp  %i3, -1
a00e95c0:  02 80 00 47  be  0xa00e96dc
a00e95c4:  a6 14 e2 f8  or  %l3, 0x2f8, %l3
a00e95c8:  80 a4 a0 00  cmp  %l2, 0
a00e95cc:  02 80 00 14  be  0xa00e961c
a00e95d0:  90 10 00 18  mov  %i0, %o0
a00e95d4:  a4 04 bf ff  add  %l2, -1, %l2
a00e95d8:  d2 05 00 11  ld  [ %l4 + %l1 ], %o1
a00e95dc:  d4 05 40 11  ld  [ %l5 + %l1 ], %o2
a00e95e0:  d6 04 c0 11  ld  [ %l3 + %l1 ], %o3
a00e95e4:  7f ff dc 64  call  0xa00e0774
a00e95e8:  98 10 00 12  mov  %l2, %o4
a00e95ec:  7f ff da a9  call  0xa00e0090
a00e95f0:  90 10 00 18  mov  %i0, %o0
a00e95f4:  90 10 00 18  mov  %i0, %o0
a00e95f8:  92 10 00 19  mov  %i1, %o1
a00e95fc:  94 10 00 1a  mov  %i2, %o2
a00e9600:  7f ff eb 1e  call  0xa00e4278
a00e9604:  96 10 00 1c  mov  %i4, %o3
a00e9608:  80 a2 20 02  cmp  %o0, 2
a00e960c:  02 80 01 3b  be  0xa00e9af8
a00e9610:  80 a2 20 00  cmp  %o0, 0
a00e9614:  02 bf ff ee  be  0xa00e95cc
a00e9618:  80 a4 a0 00  cmp  %l2, 0
a00e961c:  e6 07 bf e8  ld  [ %fp + -24 ], %l3
a00e9620:  90 04 c0 10  add  %l3, %l0, %o0
a00e9624:  d6 07 bf e4  ld  [ %fp + -28 ], %o3
a00e9628:  b9 2a 20 03  sll  %o0, 3, %i4
a00e962c:  94 02 c0 12  add  %o3, %l2, %o2
a00e9630:  b4 07 00 0a  add  %i4, %o2, %i2
a00e9634:  b3 36 a0 01  srl  %i2, 1, %i1
a00e9638:  80 a6 ff ff  cmp  %i3, -1
a00e963c:  91 36 a0 04  srl  %i2, 4, %o0
a00e9640:  02 80 00 f6  be  0xa00e9a18
a00e9644:  a6 0e 60 07  and  %i1, 7, %l3
a00e9648:  03 2a 00 9a  sethi  %hi(0xa8026800), %g1
a00e964c:  9a 15 e0 18  or  %l7, 0x18, %o5
a00e9650:  98 10 00 08  mov  %o0, %o4
a00e9654:  9e 10 60 08  or  %g1, 8, %o7
a00e9658:  a8 17 63 f8  or  %i5, 0x3f8, %l4
a00e965c:  d2 03 40 11  ld  [ %o5 + %l1 ], %o1
a00e9660:  d4 03 c0 11  ld  [ %o7 + %l1 ], %o2
a00e9664:  d6 05 00 11  ld  [ %l4 + %l1 ], %o3
a00e9668:  7f ff dc 43  call  0xa00e0774
a00e966c:  90 10 00 18  mov  %i0, %o0
a00e9670:  2b 2a 00 99  sethi  %hi(0xa8026400), %l5
a00e9674:  90 15 63 d8  or  %l5, 0x3d8, %o0	! 0xa80267d8
a00e9678:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e967c:  3b 2a 00 ad  sethi  %hi(0xa802b400), %i5
a00e9680:  ae 15 a3 e8  or  %l6, 0x3e8, %l7
a00e9684:  b6 17 62 f8  or  %i5, 0x2f8, %i3
a00e9688:  d4 02 00 11  ld  [ %o0 + %l1 ], %o2
a00e968c:  d6 06 c0 11  ld  [ %i3 + %l1 ], %o3
a00e9690:  d2 05 c0 11  ld  [ %l7 + %l1 ], %o1
a00e9694:  98 10 00 13  mov  %l3, %o4
a00e9698:  90 10 00 18  mov  %i0, %o0
a00e969c:  7f ff dc 36  call  0xa00e0774
a00e96a0:  01 00 00 00  nop
a00e96a4:  7f ff da 7b  call  0xa00e0090
a00e96a8:  90 10 00 18  mov  %i0, %o0
a00e96ac:  93 2c 20 03  sll  %l0, 3, %o1
a00e96b0:  d8 07 bf e8  ld  [ %fp + -24 ], %o4
a00e96b4:  b3 2b 20 03  sll  %o4, 3, %i1
a00e96b8:  e0 07 bf e4  ld  [ %fp + -28 ], %l0
a00e96bc:  a2 16 40 10  or  %i1, %l0, %l1
a00e96c0:  a6 12 40 12  or  %o1, %l2, %l3
a00e96c4:  f0 07 bf ec  ld  [ %fp + -20 ], %i0
a00e96c8:  e2 26 00 00  st  %l1, [ %i0 ]
a00e96cc:  e6 26 20 04  st  %l3, [ %i0 + 4 ]
a00e96d0:  e2 27 bf f0  st  %l1, [ %fp + -16 ]
a00e96d4:  10 80 01 15  b  0xa00e9b28
a00e96d8:  e6 27 bf f4  st  %l3, [ %fp + -12 ]
a00e96dc:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e96e0:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e96e4:  2d 2a 00 ad  sethi  %hi(0xa802b400), %l6
a00e96e8:  92 10 63 e8  or  %g1, 0x3e8, %o1
a00e96ec:  94 13 63 d8  or  %o5, 0x3d8, %o2
a00e96f0:  96 15 a2 f8  or  %l6, 0x2f8, %o3
a00e96f4:  80 a4 a0 00  cmp  %l2, 0
a00e96f8:  02 bf ff c9  be  0xa00e961c
a00e96fc:  90 10 00 18  mov  %i0, %o0
a00e9700:  a4 04 bf ff  add  %l2, -1, %l2
a00e9704:  7f ff dc 1c  call  0xa00e0774
a00e9708:  98 10 00 12  mov  %l2, %o4
a00e970c:  7f ff da 61  call  0xa00e0090
a00e9710:  90 10 00 18  mov  %i0, %o0
a00e9714:  90 10 00 18  mov  %i0, %o0
a00e9718:  92 10 00 19  mov  %i1, %o1
a00e971c:  94 10 00 1a  mov  %i2, %o2
a00e9720:  7f ff ea d6  call  0xa00e4278
a00e9724:  96 10 00 1c  mov  %i4, %o3
a00e9728:  80 a2 20 02  cmp  %o0, 2
a00e972c:  02 80 00 f3  be  0xa00e9af8
a00e9730:  80 a2 20 00  cmp  %o0, 0
a00e9734:  02 bf ff eb  be  0xa00e96e0
a00e9738:  03 2a 00 99  sethi  %hi(0xa8026400), %g1
a00e973c:  10 bf ff b9  b  0xa00e9620
a00e9740:  e6 07 bf e8  ld  [ %fp + -24 ], %l3
a00e9744:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00e9748:  94 12 e0 08  or  %o3, 8, %o2	! 0xa8026808
a00e974c:  90 10 00 18  mov  %i0, %o0
a00e9750:  92 15 e0 18  or  %l7, 0x18, %o1
a00e9754:  10 bf ff 77  b  0xa00e9530
a00e9758:  96 17 63 f8  or  %i5, 0x3f8, %o3
a00e975c:  7f ff d8 2c  call  0xa00df80c
a00e9760:  2d 00 06 67  sethi  %hi(0x199c00), %l6
a00e9764:  7f ff dd 17  call  0xa00e0bc0
a00e9768:  2b 00 06 67  sethi  %hi(0x199c00), %l5
a00e976c:  7f ff d6 81  call  0xa00df170
a00e9770:  90 15 a0 20  or  %l6, 0x20, %o0
a00e9774:  7f ff d8 26  call  0xa00df80c
a00e9778:  01 00 00 00  nop
a00e977c:  7f ff dd 11  call  0xa00e0bc0
a00e9780:  01 00 00 00  nop
a00e9784:  90 15 60 80  or  %l5, 0x80, %o0
a00e9788:  7f ff d6 7a  call  0xa00df170
a00e978c:  01 00 00 00  nop
a00e9790:  96 10 3f ff  mov  -1, %o3	! 0xffffffff
a00e9794:  d4 07 bf ec  ld  [ %fp + -20 ], %o2
a00e9798:  d6 22 a0 04  st  %o3, [ %o2 + 4 ]
a00e979c:  d6 27 bf f0  st  %o3, [ %fp + -16 ]
a00e97a0:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a00e97a4:  10 80 00 e1  b  0xa00e9b28
a00e97a8:  d6 22 80 00  st  %o3, [ %o2 ]
a00e97ac:  7f ff d8 18  call  0xa00df80c
a00e97b0:  29 00 06 67  sethi  %hi(0x199c00), %l4
a00e97b4:  7f ff dd 03  call  0xa00e0bc0
a00e97b8:  01 00 00 00  nop
a00e97bc:  1f 00 06 67  sethi  %hi(0x199c00), %o7
a00e97c0:  90 13 e0 20  or  %o7, 0x20, %o0	! 0x199c20
a00e97c4:  7f ff d6 6b  call  0xa00df170
a00e97c8:  01 00 00 00  nop
a00e97cc:  7f ff d8 10  call  0xa00df80c
a00e97d0:  01 00 00 00  nop
a00e97d4:  7f ff dc fb  call  0xa00e0bc0
a00e97d8:  01 00 00 00  nop
a00e97dc:  7f ff d6 65  call  0xa00df170
a00e97e0:  90 15 20 a8  or  %l4, 0xa8, %o0
a00e97e4:  10 bf fd c9  b  0xa00e8f08
a00e97e8:  82 10 3f ff  mov  -1, %g1
a00e97ec:  29 2a 00 9a  sethi  %hi(0xa8026800), %l4
a00e97f0:  a6 10 00 15  mov  %l5, %l3
a00e97f4:  a8 15 20 08  or  %l4, 8, %l4
a00e97f8:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e97fc:  aa 14 a3 f8  or  %l2, 0x3f8, %l5	! 0xa80267f8
a00e9800:  80 a6 ff ff  cmp  %i3, -1
a00e9804:  02 80 00 5b  be  0xa00e9970
a00e9808:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00e980c:  9a 10 62 f8  or  %g1, 0x2f8, %o5	! 0xa802b6f8
a00e9810:  90 10 00 18  mov  %i0, %o0
a00e9814:  d2 04 c0 11  ld  [ %l3 + %l1 ], %o1
a00e9818:  d4 05 80 11  ld  [ %l6 + %l1 ], %o2
a00e981c:  d6 03 40 11  ld  [ %o5 + %l1 ], %o3
a00e9820:  7f ff db cd  call  0xa00e0754
a00e9824:  25 2a 00 99  sethi  %hi(0xa8026400), %l2
a00e9828:  15 2a 00 ad  sethi  %hi(0xa802b400), %o2
a00e982c:  98 12 a2 f8  or  %o2, 0x2f8, %o4	! 0xa802b6f8
a00e9830:  9a 14 a3 d8  or  %l2, 0x3d8, %o5
a00e9834:  d4 03 40 11  ld  [ %o5 + %l1 ], %o2
a00e9838:  d6 03 00 11  ld  [ %o4 + %l1 ], %o3
a00e983c:  93 32 80 0b  srl  %o2, %o3, %o1
a00e9840:  80 a2 40 08  cmp  %o1, %o0
a00e9844:  02 80 00 32  be  0xa00e990c
a00e9848:  80 a6 ff ff  cmp  %i3, -1
a00e984c:  02 80 00 51  be  0xa00e9990
a00e9850:  a4 02 20 01  add  %o0, 1, %l2
a00e9854:  90 10 00 18  mov  %i0, %o0
a00e9858:  d2 04 c0 11  ld  [ %l3 + %l1 ], %o1
a00e985c:  98 10 00 12  mov  %l2, %o4
a00e9860:  7f ff db c5  call  0xa00e0774
a00e9864:  01 00 00 00  nop
a00e9868:  7f ff da 0a  call  0xa00e0090
a00e986c:  90 10 00 18  mov  %i0, %o0
a00e9870:  90 10 00 18  mov  %i0, %o0
a00e9874:  92 10 00 19  mov  %i1, %o1
a00e9878:  94 10 00 1a  mov  %i2, %o2
a00e987c:  7f ff ea 7f  call  0xa00e4278
a00e9880:  96 10 00 1c  mov  %i4, %o3
a00e9884:  80 a2 20 02  cmp  %o0, 2
a00e9888:  02 80 00 87  be  0xa00e9aa4
a00e988c:  80 a2 20 00  cmp  %o0, 0
a00e9890:  02 bf ff 63  be  0xa00e961c
a00e9894:  13 2a 00 ad  sethi  %hi(0xa802b400), %o1
a00e9898:  82 12 62 f8  or  %o1, 0x2f8, %g1	! 0xa802b6f8
a00e989c:  de 05 80 11  ld  [ %l6 + %l1 ], %o7
a00e98a0:  da 00 40 11  ld  [ %g1 + %l1 ], %o5
a00e98a4:  91 33 c0 0d  srl  %o7, %o5, %o0
a00e98a8:  80 a2 00 12  cmp  %o0, %l2
a00e98ac:  12 bf ff d6  bne  0xa00e9804
a00e98b0:  80 a6 ff ff  cmp  %i3, -1
a00e98b4:  02 80 00 53  be  0xa00e9a00
a00e98b8:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00e98bc:  a0 13 20 18  or  %o4, 0x18, %l0	! 0xa8026818
a00e98c0:  90 10 00 18  mov  %i0, %o0
a00e98c4:  d2 04 00 11  ld  [ %l0 + %l1 ], %o1
a00e98c8:  d4 05 00 11  ld  [ %l4 + %l1 ], %o2
a00e98cc:  d6 05 40 11  ld  [ %l5 + %l1 ], %o3
a00e98d0:  7f ff db a1  call  0xa00e0754
a00e98d4:  01 00 00 00  nop
a00e98d8:  a0 10 00 08  mov  %o0, %l0
a00e98dc:  d6 05 00 11  ld  [ %l4 + %l1 ], %o3
a00e98e0:  d0 05 40 11  ld  [ %l5 + %l1 ], %o0
a00e98e4:  95 32 c0 08  srl  %o3, %o0, %o2
a00e98e8:  80 a2 80 10  cmp  %o2, %l0
a00e98ec:  12 bf ff c6  bne  0xa00e9804
a00e98f0:  80 a6 ff ff  cmp  %i3, -1
a00e98f4:  7f ff d7 c6  call  0xa00df80c
a00e98f8:  27 00 06 67  sethi  %hi(0x199c00), %l3
a00e98fc:  7f ff dc b1  call  0xa00e0bc0
a00e9900:  01 00 00 00  nop
a00e9904:  10 bf ff a1  b  0xa00e9788
a00e9908:  90 14 e0 d0  or  %l3, 0xd0, %o0
a00e990c:  02 80 00 2e  be  0xa00e99c4
a00e9910:  a4 10 20 00  clr  %l2
a00e9914:  90 10 00 18  mov  %i0, %o0
a00e9918:  d2 04 c0 11  ld  [ %l3 + %l1 ], %o1
a00e991c:  7f ff db 96  call  0xa00e0774
a00e9920:  98 10 20 00  clr  %o4
a00e9924:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00e9928:  82 12 60 18  or  %o1, 0x18, %g1	! 0xa8026818
a00e992c:  90 10 00 18  mov  %i0, %o0
a00e9930:  d2 00 40 11  ld  [ %g1 + %l1 ], %o1
a00e9934:  d4 05 00 11  ld  [ %l4 + %l1 ], %o2
a00e9938:  d6 05 40 11  ld  [ %l5 + %l1 ], %o3
a00e993c:  7f ff db 86  call  0xa00e0754
a00e9940:  01 00 00 00  nop
a00e9944:  80 a6 ff ff  cmp  %i3, -1
a00e9948:  02 80 00 18  be  0xa00e99a8
a00e994c:  a0 02 20 01  add  %o0, 1, %l0
a00e9950:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00e9954:  94 12 e0 18  or  %o3, 0x18, %o2	! 0xa8026818
a00e9958:  d2 02 80 11  ld  [ %o2 + %l1 ], %o1
a00e995c:  90 10 00 18  mov  %i0, %o0
a00e9960:  d4 05 00 11  ld  [ %l4 + %l1 ], %o2
a00e9964:  d6 05 40 11  ld  [ %l5 + %l1 ], %o3
a00e9968:  10 bf ff be  b  0xa00e9860
a00e996c:  98 10 00 10  mov  %l0, %o4
a00e9970:  17 2a 00 99  sethi  %hi(0xa8026400), %o3
a00e9974:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e9978:  94 12 e3 d8  or  %o3, 0x3d8, %o2
a00e997c:  19 2a 00 ad  sethi  %hi(0xa802b400), %o4
a00e9980:  90 10 00 18  mov  %i0, %o0
a00e9984:  92 13 e3 e8  or  %o7, 0x3e8, %o1
a00e9988:  10 bf ff a6  b  0xa00e9820
a00e998c:  96 13 22 f8  or  %o4, 0x2f8, %o3
a00e9990:  96 10 00 0c  mov  %o4, %o3
a00e9994:  19 2a 00 99  sethi  %hi(0xa8026400), %o4
a00e9998:  94 10 00 0d  mov  %o5, %o2
a00e999c:  90 10 00 18  mov  %i0, %o0
a00e99a0:  10 bf ff af  b  0xa00e985c
a00e99a4:  92 13 23 e8  or  %o4, 0x3e8, %o1
a00e99a8:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00e99ac:  94 13 20 08  or  %o4, 8, %o2	! 0xa8026808
a00e99b0:  90 10 00 18  mov  %i0, %o0
a00e99b4:  92 15 e0 18  or  %l7, 0x18, %o1
a00e99b8:  96 17 63 f8  or  %i5, 0x3f8, %o3
a00e99bc:  10 bf ff a9  b  0xa00e9860
a00e99c0:  98 10 00 10  mov  %l0, %o4
a00e99c4:  1b 2a 00 99  sethi  %hi(0xa8026400), %o5
a00e99c8:  1f 2a 00 99  sethi  %hi(0xa8026400), %o7
a00e99cc:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00e99d0:  90 10 00 18  mov  %i0, %o0
a00e99d4:  92 13 63 e8  or  %o5, 0x3e8, %o1
a00e99d8:  94 13 e3 d8  or  %o7, 0x3d8, %o2
a00e99dc:  96 12 e2 f8  or  %o3, 0x2f8, %o3
a00e99e0:  7f ff db 65  call  0xa00e0774
a00e99e4:  98 10 20 00  clr  %o4
a00e99e8:  21 2a 00 9a  sethi  %hi(0xa8026800), %l0
a00e99ec:  90 10 00 18  mov  %i0, %o0
a00e99f0:  92 15 e0 18  or  %l7, 0x18, %o1
a00e99f4:  94 14 20 08  or  %l0, 8, %o2
a00e99f8:  10 bf ff d1  b  0xa00e993c
a00e99fc:  96 17 63 f8  or  %i5, 0x3f8, %o3
a00e9a00:  25 2a 00 9a  sethi  %hi(0xa8026800), %l2
a00e9a04:  90 10 00 18  mov  %i0, %o0
a00e9a08:  92 15 e0 18  or  %l7, 0x18, %o1
a00e9a0c:  94 14 a0 08  or  %l2, 8, %o2
a00e9a10:  10 bf ff b0  b  0xa00e98d0
a00e9a14:  96 17 63 f8  or  %i5, 0x3f8, %o3
a00e9a18:  98 10 00 08  mov  %o0, %o4
a00e9a1c:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00e9a20:  92 15 e0 18  or  %l7, 0x18, %o1
a00e9a24:  96 17 63 f8  or  %i5, 0x3f8, %o3
a00e9a28:  94 14 60 08  or  %l1, 8, %o2
a00e9a2c:  7f ff db 52  call  0xa00e0774
a00e9a30:  90 10 00 18  mov  %i0, %o0
a00e9a34:  3b 2a 00 99  sethi  %hi(0xa8026400), %i5
a00e9a38:  37 2a 00 99  sethi  %hi(0xa8026400), %i3
a00e9a3c:  2f 2a 00 ad  sethi  %hi(0xa802b400), %l7
a00e9a40:  90 10 00 18  mov  %i0, %o0
a00e9a44:  92 17 63 e8  or  %i5, 0x3e8, %o1
a00e9a48:  94 16 e3 d8  or  %i3, 0x3d8, %o2
a00e9a4c:  96 15 e2 f8  or  %l7, 0x2f8, %o3
a00e9a50:  10 bf ff 13  b  0xa00e969c
a00e9a54:  98 10 00 13  mov  %l3, %o4
a00e9a58:  29 2a 00 99  sethi  %hi(0xa8026400), %l4
a00e9a5c:  2d 2a 00 99  sethi  %hi(0xa8026400), %l6
a00e9a60:  2b 2a 00 ad  sethi  %hi(0xa802b400), %l5
a00e9a64:  90 10 00 18  mov  %i0, %o0
a00e9a68:  92 15 23 e8  or  %l4, 0x3e8, %o1
a00e9a6c:  94 15 a3 d8  or  %l6, 0x3d8, %o2
a00e9a70:  10 bf fe cc  b  0xa00e95a0
a00e9a74:  96 15 62 f8  or  %l5, 0x2f8, %o3
a00e9a78:  2d 2a 00 9a  sethi  %hi(0xa8026800), %l6
a00e9a7c:  90 10 00 18  mov  %i0, %o0
a00e9a80:  92 15 e0 18  or  %l7, 0x18, %o1
a00e9a84:  94 15 a0 08  or  %l6, 8, %o2
a00e9a88:  10 bf fe 7e  b  0xa00e9480
a00e9a8c:  96 17 63 f8  or  %i5, 0x3f8, %o3
a00e9a90:  90 10 00 18  mov  %i0, %o0
a00e9a94:  92 15 e0 18  or  %l7, 0x18, %o1
a00e9a98:  94 15 60 08  or  %l5, 8, %o2
a00e9a9c:  10 bf fe 70  b  0xa00e945c
a00e9aa0:  96 17 63 f8  or  %i5, 0x3f8, %o3
a00e9aa4:  7f ff d7 5a  call  0xa00df80c
a00e9aa8:  25 00 06 67  sethi  %hi(0x199c00), %l2
a00e9aac:  7f ff dc 45  call  0xa00e0bc0
a00e9ab0:  01 00 00 00  nop
a00e9ab4:  7f ff d5 af  call  0xa00df170
a00e9ab8:  90 14 a0 20  or  %l2, 0x20, %o0
a00e9abc:  7f ff d7 54  call  0xa00df80c
a00e9ac0:  01 00 00 00  nop
a00e9ac4:  7f ff dc 3f  call  0xa00e0bc0
a00e9ac8:  01 00 00 00  nop
a00e9acc:  13 00 06 67  sethi  %hi(0x199c00), %o1
a00e9ad0:  10 bf fe 55  b  0xa00e9424
a00e9ad4:  90 12 60 f8  or  %o1, 0xf8, %o0	! 0x199cf8
a00e9ad8:  90 10 00 18  mov  %i0, %o0
a00e9adc:  35 2a 00 9a  sethi  %hi(0xa8026800), %i2
a00e9ae0:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00e9ae4:  31 2a 00 ad  sethi  %hi(0xa802b400), %i0
a00e9ae8:  92 16 a0 38  or  %i2, 0x38, %o1
a00e9aec:  94 16 60 28  or  %i1, 0x28, %o2
a00e9af0:  10 bf fd f6  b  0xa00e92c8
a00e9af4:  96 16 23 08  or  %i0, 0x308, %o3
a00e9af8:  7f ff d7 45  call  0xa00df80c
a00e9afc:  39 00 06 67  sethi  %hi(0x199c00), %i4
a00e9b00:  7f ff dc 30  call  0xa00e0bc0
a00e9b04:  35 00 06 67  sethi  %hi(0x199c00), %i2
a00e9b08:  7f ff d5 9a  call  0xa00df170
a00e9b0c:  90 17 20 20  or  %i4, 0x20, %o0
a00e9b10:  7f ff d7 3f  call  0xa00df80c
a00e9b14:  01 00 00 00  nop
a00e9b18:  7f ff dc 2a  call  0xa00e0bc0
a00e9b1c:  01 00 00 00  nop
a00e9b20:  10 bf ff 1a  b  0xa00e9788
a00e9b24:  90 16 a0 f8  or  %i2, 0xf8, %o0
a00e9b28:  f0 07 bf ec  ld  [ %fp + -20 ], %i0
a00e9b2c:  81 c7 e0 0c  jmp  %i7 + 0xc
a00e9b30:  81 e8 00 00  restore
