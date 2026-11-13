# leon2m FUN_a00b50d8 0xa00b50d8-0xa00b52f8 (544 bytes)  [FUN_a00b52f0 = unreachable ret/restore tail, merged]
a00b50d8:  9d e3 bf 98  save  %sp, -104, %sp
a00b50dc:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00b50e0:  d0 08 60 8e  ldub  [ %g1 + 0x8e ], %o0	! 0xa802b08e
a00b50e4:  9a 12 3f 80  or  %o0, -128, %o5
a00b50e8:  da 28 60 8e  stb  %o5, [ %g1 + 0x8e ]
a00b50ec:  90 10 20 04  mov  4, %o0
a00b50f0:  40 02 44 6a  call  0xa0146298
a00b50f4:  92 10 20 00  clr  %o1
a00b50f8:  90 10 20 01  mov  1, %o0
a00b50fc:  92 10 20 01  mov  1, %o1
a00b5100:  40 02 44 95  call  0xa0146354
a00b5104:  94 10 20 00  clr  %o2
a00b5108:  7f ff b6 b5  call  0xa00a2bdc
a00b510c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b5110:  80 a6 20 00  cmp  %i0, 0
a00b5114:  02 80 00 0b  be  0xa00b5140
a00b5118:  80 a6 20 02  cmp  %i0, 2
a00b511c:  02 80 00 1d  be  0xa00b5190
a00b5120:  80 a6 20 03  cmp  %i0, 3
a00b5124:  02 80 00 38  be  0xa00b5204
a00b5128:  80 a6 20 05  cmp  %i0, 5
a00b512c:  02 80 00 5d  be  0xa00b52a0
a00b5130:  80 a6 20 04  cmp  %i0, 4
a00b5134:  12 80 00 6e  bne  0xa00b52ec
a00b5138:  92 10 20 03  mov  3, %o1
a00b513c:  30 80 00 29  b,a   0xa00b51e0
a00b5140:  92 10 20 17  mov  0x17, %o1
a00b5144:  40 02 44 14  call  0xa0146194
a00b5148:  90 10 20 3c  mov  0x3c, %o0
a00b514c:  97 2a 20 10  sll  %o0, 0x10, %o3
a00b5150:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b5154:  90 10 20 00  clr  %o0
a00b5158:  40 02 44 86  call  0xa0146370
a00b515c:  94 10 20 00  clr  %o2
a00b5160:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a00b5164:  92 12 a2 c0  or  %o2, 0x2c0, %o1	! 0xfec0
a00b5168:  90 10 20 01  mov  1, %o0
a00b516c:  40 02 44 81  call  0xa0146370
a00b5170:  94 10 20 00  clr  %o2
a00b5174:  13 00 00 4b  sethi  %hi(0x12c00), %o1
a00b5178:  92 12 63 b0  or  %o1, 0x3b0, %o1	! 0x12fb0
a00b517c:  90 10 20 03  mov  3, %o0
a00b5180:  40 02 44 7c  call  0xa0146370
a00b5184:  94 10 20 00  clr  %o2
a00b5188:  7f ff b5 cd  call  0xa00a28bc
a00b518c:  81 e8 00 00  restore
a00b5190:  92 10 20 11  mov  0x11, %o1
a00b5194:  40 02 44 00  call  0xa0146194
a00b5198:  90 10 20 16  mov  0x16, %o0
a00b519c:  b1 2a 20 10  sll  %o0, 0x10, %i0
a00b51a0:  93 36 20 10  srl  %i0, 0x10, %o1
a00b51a4:  90 10 20 00  clr  %o0
a00b51a8:  40 02 44 72  call  0xa0146370
a00b51ac:  94 10 20 00  clr  %o2
a00b51b0:  1f 00 00 3c  sethi  %hi(0xf000), %o7
a00b51b4:  92 13 e2 60  or  %o7, 0x260, %o1	! 0xf260
a00b51b8:  90 10 20 01  mov  1, %o0
a00b51bc:  40 02 44 6d  call  0xa0146370
a00b51c0:  94 10 20 00  clr  %o2
a00b51c4:  19 00 00 47  sethi  %hi(0x11c00), %o4
a00b51c8:  92 13 20 90  or  %o4, 0x90, %o1	! 0x11c90
a00b51cc:  90 10 20 03  mov  3, %o0
a00b51d0:  40 02 44 68  call  0xa0146370
a00b51d4:  94 10 20 00  clr  %o2
a00b51d8:  7f ff b5 d4  call  0xa00a2928
a00b51dc:  81 e8 00 00  restore
a00b51e0:  40 02 43 ed  call  0xa0146194
a00b51e4:  90 10 20 08  mov  8, %o0
a00b51e8:  97 2a 20 10  sll  %o0, 0x10, %o3
a00b51ec:  93 32 e0 10  srl  %o3, 0x10, %o1
a00b51f0:  90 10 20 01  mov  1, %o0
a00b51f4:  40 02 44 5f  call  0xa0146370
a00b51f8:  94 10 20 00  clr  %o2
a00b51fc:  7f ff b6 38  call  0xa00a2adc
a00b5200:  81 e8 00 00  restore
a00b5204:  40 02 4c 5e  call  0xa014837c
a00b5208:  90 10 20 00  clr  %o0
a00b520c:  1b 2a aa aa  sethi  %hi(0xaaaaa800), %o5
a00b5210:  91 2a 20 10  sll  %o0, 0x10, %o0
a00b5214:  82 13 62 ab  or  %o5, 0x2ab, %g1
a00b5218:  b1 32 20 10  srl  %o0, 0x10, %i0
a00b521c:  80 56 00 01  umul  %i0, %g1, %g0
a00b5220:  9f 40 00 00  rd  %y, %o7
a00b5224:  99 33 e0 04  srl  %o7, 4, %o4
a00b5228:  96 03 20 01  add  %o4, 1, %o3
a00b522c:  95 2a e0 10  sll  %o3, 0x10, %o2
a00b5230:  91 32 a0 10  srl  %o2, 0x10, %o0
a00b5234:  40 02 43 d8  call  0xa0146194
a00b5238:  92 10 20 3d  mov  0x3d, %o1
a00b523c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b5240:  93 32 60 10  srl  %o1, 0x10, %o1
a00b5244:  90 10 20 00  clr  %o0
a00b5248:  40 02 44 4a  call  0xa0146370
a00b524c:  94 10 20 00  clr  %o2
a00b5250:  11 00 00 3c  sethi  %hi(0xf000), %o0
a00b5254:  92 12 22 60  or  %o0, 0x260, %o1	! 0xf260
a00b5258:  90 10 20 01  mov  1, %o0
a00b525c:  40 02 44 45  call  0xa0146370
a00b5260:  94 10 20 00  clr  %o2
a00b5264:  1b 00 00 47  sethi  %hi(0x11c00), %o5
a00b5268:  92 13 60 90  or  %o5, 0x90, %o1	! 0x11c90
a00b526c:  94 10 20 00  clr  %o2
a00b5270:  40 02 44 40  call  0xa0146370
a00b5274:  90 10 20 03  mov  3, %o0
a00b5278:  92 10 20 0a  mov  0xa, %o1
a00b527c:  40 02 43 c6  call  0xa0146194
a00b5280:  90 10 20 0a  mov  0xa, %o0
a00b5284:  83 2a 20 10  sll  %o0, 0x10, %g1
a00b5288:  93 30 60 10  srl  %g1, 0x10, %o1
a00b528c:  90 10 20 00  clr  %o0
a00b5290:  40 02 44 38  call  0xa0146370
a00b5294:  94 10 20 01  mov  1, %o2
a00b5298:  7f ff b5 c4  call  0xa00a29a8
a00b529c:  81 e8 00 00  restore
a00b52a0:  92 10 20 1b  mov  0x1b, %o1
a00b52a4:  40 02 43 bc  call  0xa0146194
a00b52a8:  90 10 20 38  mov  0x38, %o0
a00b52ac:  95 2a 20 10  sll  %o0, 0x10, %o2
a00b52b0:  93 32 a0 10  srl  %o2, 0x10, %o1
a00b52b4:  90 10 20 00  clr  %o0
a00b52b8:  40 02 44 2e  call  0xa0146370
a00b52bc:  94 10 20 00  clr  %o2
a00b52c0:  90 10 20 01  mov  1, %o0
a00b52c4:  13 00 00 35  sethi  %hi(0xd400), %o1
a00b52c8:  40 02 44 2a  call  0xa0146370
a00b52cc:  94 10 20 00  clr  %o2
a00b52d0:  13 00 00 3f  sethi  %hi(0xfc00), %o1
a00b52d4:  92 12 62 30  or  %o1, 0x230, %o1	! 0xfe30
a00b52d8:  90 10 20 03  mov  3, %o0
a00b52dc:  40 02 44 25  call  0xa0146370
a00b52e0:  94 10 20 00  clr  %o2
a00b52e4:  7f ff b5 d5  call  0xa00a2a38
a00b52e8:  81 e8 00 00  restore
a00b52ec:  01 00 00 00  nop
a00b52f0:  81 c7 e0 08  ret
a00b52f4:  81 e8 00 00  restore
