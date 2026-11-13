# leon2s FUN_a00abff0 0xa00abff0-0xa00ac41c (1068 bytes)
a00abff0:  9d e3 bf 98  save  %sp, -104, %sp
a00abff4:  33 2a 01 f7  sethi  %hi(0xa807dc00), %i1
a00abff8:  b6 0e 20 ff  and  %i0, 0xff, %i3
a00abffc:  82 16 60 18  or  %i1, 0x18, %g1
a00ac000:  9a 5e e1 2c  smul  %i3, 0x12c, %o5
a00ac004:  b4 03 40 01  add  %o5, %g1, %i2
a00ac008:  c2 0e a1 17  ldub  [ %i2 + 0x117 ], %g1
a00ac00c:  80 a0 60 00  cmp  %g1, 0
a00ac010:  22 80 00 02  be,a   0xa00ac018
a00ac014:  c0 2e a1 12  clrb  [ %i2 + 0x112 ]
a00ac018:  7f ff ff 82  call  0xa00abe20
a00ac01c:  90 10 00 1b  mov  %i3, %o0
a00ac020:  96 10 20 01  mov  1, %o3
a00ac024:  90 10 00 1b  mov  %i3, %o0
a00ac028:  92 10 20 30  mov  0x30, %o1
a00ac02c:  7f ff eb 1b  call  0xa00a6c98
a00ac030:  94 10 20 80  mov  0x80, %o2
a00ac034:  90 10 00 1b  mov  %i3, %o0
a00ac038:  92 10 22 04  mov  0x204, %o1
a00ac03c:  7f ff ea f1  call  0xa00a6c00
a00ac040:  94 10 20 01  mov  1, %o2
a00ac044:  90 10 00 1b  mov  %i3, %o0
a00ac048:  92 10 22 06  mov  0x206, %o1
a00ac04c:  7f ff ea ed  call  0xa00a6c00
a00ac050:  94 10 20 01  mov  1, %o2
a00ac054:  c2 0e a1 1e  ldub  [ %i2 + 0x11e ], %g1
a00ac058:  90 10 00 1b  mov  %i3, %o0
a00ac05c:  92 10 22 1c  mov  0x21c, %o1
a00ac060:  80 a0 60 00  cmp  %g1, 0
a00ac064:  02 80 00 05  be  0xa00ac078
a00ac068:  94 10 20 14  mov  0x14, %o2
a00ac06c:  90 10 00 1b  mov  %i3, %o0
a00ac070:  92 10 22 1c  mov  0x21c, %o1
a00ac074:  94 10 20 06  mov  6, %o2
a00ac078:  7f ff ea e2  call  0xa00a6c00
a00ac07c:  01 00 00 00  nop
a00ac080:  90 10 00 1b  mov  %i3, %o0
a00ac084:  92 10 22 1d  mov  0x21d, %o1
a00ac088:  7f ff ea de  call  0xa00a6c00
a00ac08c:  94 10 20 84  mov  0x84, %o2
a00ac090:  90 10 00 1b  mov  %i3, %o0
a00ac094:  92 10 22 25  mov  0x225, %o1
a00ac098:  7f ff ea da  call  0xa00a6c00
a00ac09c:  94 10 20 41  mov  0x41, %o2
a00ac0a0:  90 10 00 1b  mov  %i3, %o0
a00ac0a4:  92 10 22 26  mov  0x226, %o1
a00ac0a8:  7f ff ea d6  call  0xa00a6c00
a00ac0ac:  94 10 20 00  clr  %o2
a00ac0b0:  96 10 20 01  mov  1, %o3
a00ac0b4:  90 10 00 1b  mov  %i3, %o0
a00ac0b8:  92 10 22 0a  mov  0x20a, %o1
a00ac0bc:  7f ff ea f7  call  0xa00a6c98
a00ac0c0:  94 10 20 04  mov  4, %o2
a00ac0c4:  90 10 00 1b  mov  %i3, %o0
a00ac0c8:  92 10 22 61  mov  0x261, %o1
a00ac0cc:  7f ff ea cd  call  0xa00a6c00
a00ac0d0:  94 10 20 00  clr  %o2
a00ac0d4:  90 10 00 1b  mov  %i3, %o0
a00ac0d8:  92 10 23 32  mov  0x332, %o1
a00ac0dc:  7f ff ea c9  call  0xa00a6c00
a00ac0e0:  94 10 20 41  mov  0x41, %o2
a00ac0e4:  80 a6 e0 00  cmp  %i3, 0
a00ac0e8:  12 80 00 18  bne  0xa00ac148
a00ac0ec:  82 16 60 18  or  %i1, 0x18, %g1
a00ac0f0:  c2 08 61 12  ldub  [ %g1 + 0x112 ], %g1
a00ac0f4:  80 a0 60 00  cmp  %g1, 0
a00ac0f8:  22 80 00 15  be,a   0xa00ac14c
a00ac0fc:  90 10 00 1b  mov  %i3, %o0
a00ac100:  90 10 20 00  clr  %o0
a00ac104:  92 10 22 05  mov  0x205, %o1
a00ac108:  7f ff ea be  call  0xa00a6c00
a00ac10c:  94 10 20 01  mov  1, %o2
a00ac110:  90 10 20 00  clr  %o0
a00ac114:  92 10 22 07  mov  0x207, %o1
a00ac118:  7f ff ea ba  call  0xa00a6c00
a00ac11c:  94 10 20 81  mov  0x81, %o2
a00ac120:  90 10 20 00  clr  %o0
a00ac124:  92 10 23 01  mov  0x301, %o1
a00ac128:  7f ff ea b6  call  0xa00a6c00
a00ac12c:  94 10 20 01  mov  1, %o2
a00ac130:  90 10 20 00  clr  %o0
a00ac134:  92 10 23 0e  mov  0x30e, %o1
a00ac138:  7f ff ea b2  call  0xa00a6c00
a00ac13c:  94 10 20 00  clr  %o2
a00ac140:  10 80 00 13  b  0xa00ac18c
a00ac144:  90 10 20 00  clr  %o0
a00ac148:  90 10 00 1b  mov  %i3, %o0
a00ac14c:  92 10 22 05  mov  0x205, %o1
a00ac150:  7f ff ea ac  call  0xa00a6c00
a00ac154:  94 10 20 00  clr  %o2
a00ac158:  90 10 00 1b  mov  %i3, %o0
a00ac15c:  92 10 22 07  mov  0x207, %o1
a00ac160:  7f ff ea a8  call  0xa00a6c00
a00ac164:  94 10 20 00  clr  %o2
a00ac168:  90 10 00 1b  mov  %i3, %o0
a00ac16c:  92 10 23 01  mov  0x301, %o1
a00ac170:  7f ff ea a4  call  0xa00a6c00
a00ac174:  94 10 20 00  clr  %o2
a00ac178:  90 10 00 1b  mov  %i3, %o0
a00ac17c:  92 10 23 0e  mov  0x30e, %o1
a00ac180:  7f ff ea a0  call  0xa00a6c00
a00ac184:  94 10 20 00  clr  %o2
a00ac188:  90 10 00 1b  mov  %i3, %o0
a00ac18c:  92 10 23 33  mov  0x333, %o1
a00ac190:  7f ff ea 9c  call  0xa00a6c00
a00ac194:  94 10 20 00  clr  %o2
a00ac198:  b6 0e 20 ff  and  %i0, 0xff, %i3
a00ac19c:  35 2a 01 f7  sethi  %hi(0xa807dc00), %i2
a00ac1a0:  82 16 a0 18  or  %i2, 0x18, %g1	! 0xa807dc18
a00ac1a4:  9a 5e e1 2c  smul  %i3, 0x12c, %o5
a00ac1a8:  9a 03 40 01  add  %o5, %g1, %o5
a00ac1ac:  c2 0b 61 13  ldub  [ %o5 + 0x113 ], %g1
a00ac1b0:  90 10 00 1b  mov  %i3, %o0
a00ac1b4:  80 a0 60 00  cmp  %g1, 0
a00ac1b8:  02 80 00 0c  be  0xa00ac1e8
a00ac1bc:  92 10 22 a8  mov  0x2a8, %o1
a00ac1c0:  90 10 00 1b  mov  %i3, %o0
a00ac1c4:  92 10 22 a8  mov  0x2a8, %o1
a00ac1c8:  7f ff ea 8e  call  0xa00a6c00
a00ac1cc:  94 10 20 03  mov  3, %o2
a00ac1d0:  90 10 00 1b  mov  %i3, %o0
a00ac1d4:  92 10 22 aa  mov  0x2aa, %o1
a00ac1d8:  7f ff ea 8a  call  0xa00a6c00
a00ac1dc:  94 10 20 01  mov  1, %o2
a00ac1e0:  90 10 00 1b  mov  %i3, %o0
a00ac1e4:  92 10 22 ab  mov  0x2ab, %o1
a00ac1e8:  7f ff ea 86  call  0xa00a6c00
a00ac1ec:  94 10 20 01  mov  1, %o2
a00ac1f0:  82 16 a0 18  or  %i2, 0x18, %g1
a00ac1f4:  9a 5e e1 2c  smul  %i3, 0x12c, %o5
a00ac1f8:  9a 03 40 01  add  %o5, %g1, %o5
a00ac1fc:  c2 0b 61 15  ldub  [ %o5 + 0x115 ], %g1
a00ac200:  80 a0 60 00  cmp  %g1, 0
a00ac204:  02 80 00 06  be  0xa00ac21c
a00ac208:  90 10 00 1b  mov  %i3, %o0
a00ac20c:  92 10 22 07  mov  0x207, %o1
a00ac210:  94 10 20 40  mov  0x40, %o2
a00ac214:  10 80 00 05  b  0xa00ac228
a00ac218:  96 10 20 01  mov  1, %o3
a00ac21c:  92 10 22 07  mov  0x207, %o1
a00ac220:  94 10 20 40  mov  0x40, %o2
a00ac224:  96 10 20 00  clr  %o3
a00ac228:  7f ff ea 9c  call  0xa00a6c98
a00ac22c:  01 00 00 00  nop
a00ac230:  82 16 a0 18  or  %i2, 0x18, %g1
a00ac234:  9a 5e e1 2c  smul  %i3, 0x12c, %o5
a00ac238:  9a 03 40 01  add  %o5, %g1, %o5
a00ac23c:  c2 0b 61 16  ldub  [ %o5 + 0x116 ], %g1
a00ac240:  80 a0 60 00  cmp  %g1, 0
a00ac244:  02 80 00 51  be  0xa00ac388
a00ac248:  90 10 00 1b  mov  %i3, %o0
a00ac24c:  c2 0b 61 12  ldub  [ %o5 + 0x112 ], %g1
a00ac250:  82 18 60 01  xor  %g1, 1, %g1
a00ac254:  80 a0 00 01  cmp  %g0, %g1
a00ac258:  9a 60 3f ff  subx  %g0, -1, %o5
a00ac25c:  80 a0 00 1b  cmp  %g0, %i3
a00ac260:  82 60 3f ff  subx  %g0, -1, %g1
a00ac264:  80 8b 40 01  btst  %o5, %g1
a00ac268:  12 80 00 49  bne  0xa00ac38c
a00ac26c:  92 10 24 50  mov  0x450, %o1
a00ac270:  90 10 00 1b  mov  %i3, %o0
a00ac274:  7f ff ea 63  call  0xa00a6c00
a00ac278:  94 10 20 01  mov  1, %o2
a00ac27c:  90 10 00 1b  mov  %i3, %o0
a00ac280:  92 10 24 51  mov  0x451, %o1
a00ac284:  7f ff ea 5f  call  0xa00a6c00
a00ac288:  94 10 20 21  mov  0x21, %o2
a00ac28c:  90 10 00 1b  mov  %i3, %o0
a00ac290:  92 10 24 52  mov  0x452, %o1
a00ac294:  7f ff ea 5b  call  0xa00a6c00
a00ac298:  94 10 20 00  clr  %o2
a00ac29c:  90 10 00 1b  mov  %i3, %o0
a00ac2a0:  92 10 24 53  mov  0x453, %o1
a00ac2a4:  7f ff ea 57  call  0xa00a6c00
a00ac2a8:  94 10 20 76  mov  0x76, %o2
a00ac2ac:  35 2a 01 e4  sethi  %hi(0xa8079000), %i2
a00ac2b0:  c2 0e a3 08  ldub  [ %i2 + 0x308 ], %g1	! 0xa8079308
a00ac2b4:  90 10 00 1b  mov  %i3, %o0
a00ac2b8:  92 10 24 54  mov  0x454, %o1
a00ac2bc:  80 a0 60 01  cmp  %g1, 1
a00ac2c0:  02 80 00 05  be  0xa00ac2d4
a00ac2c4:  94 10 20 0b  mov  0xb, %o2
a00ac2c8:  90 10 00 1b  mov  %i3, %o0
a00ac2cc:  92 10 24 54  mov  0x454, %o1
a00ac2d0:  94 10 20 2b  mov  0x2b, %o2
a00ac2d4:  7f ff ea 4b  call  0xa00a6c00
a00ac2d8:  01 00 00 00  nop
a00ac2dc:  90 10 00 1b  mov  %i3, %o0
a00ac2e0:  92 10 24 55  mov  0x455, %o1
a00ac2e4:  7f ff ea 47  call  0xa00a6c00
a00ac2e8:  94 10 20 01  mov  1, %o2
a00ac2ec:  90 10 00 1b  mov  %i3, %o0
a00ac2f0:  92 10 24 56  mov  0x456, %o1
a00ac2f4:  7f ff ea 43  call  0xa00a6c00
a00ac2f8:  94 10 20 01  mov  1, %o2
a00ac2fc:  90 10 00 1b  mov  %i3, %o0
a00ac300:  92 10 24 57  mov  0x457, %o1
a00ac304:  7f ff ea 3f  call  0xa00a6c00
a00ac308:  94 10 20 07  mov  7, %o2
a00ac30c:  90 10 00 1b  mov  %i3, %o0
a00ac310:  92 10 24 58  mov  0x458, %o1
a00ac314:  7f ff ea 3b  call  0xa00a6c00
a00ac318:  94 10 20 0e  mov  0xe, %o2
a00ac31c:  c2 0e a3 08  ldub  [ %i2 + 0x308 ], %g1
a00ac320:  90 10 00 1b  mov  %i3, %o0
a00ac324:  92 10 24 59  mov  0x459, %o1
a00ac328:  80 a0 60 01  cmp  %g1, 1
a00ac32c:  02 80 00 05  be  0xa00ac340
a00ac330:  94 10 20 02  mov  2, %o2
a00ac334:  90 10 00 1b  mov  %i3, %o0
a00ac338:  92 10 24 59  mov  0x459, %o1
a00ac33c:  94 10 20 01  mov  1, %o2
a00ac340:  7f ff ea 30  call  0xa00a6c00
a00ac344:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ac348:  90 10 00 1b  mov  %i3, %o0
a00ac34c:  92 10 24 5a  mov  0x45a, %o1
a00ac350:  7f ff ea 2c  call  0xa00a6c00
a00ac354:  94 10 20 08  mov  8, %o2
a00ac358:  90 10 00 1b  mov  %i3, %o0
a00ac35c:  92 10 24 5b  mov  0x45b, %o1
a00ac360:  7f ff ea 28  call  0xa00a6c00
a00ac364:  94 10 20 00  clr  %o2
a00ac368:  90 10 00 1b  mov  %i3, %o0
a00ac36c:  92 10 24 5c  mov  0x45c, %o1
a00ac370:  7f ff ea 24  call  0xa00a6c00
a00ac374:  94 10 20 04  mov  4, %o2
a00ac378:  90 10 00 1b  mov  %i3, %o0
a00ac37c:  92 10 24 5d  mov  0x45d, %o1
a00ac380:  10 80 00 09  b  0xa00ac3a4
a00ac384:  94 10 20 bf  mov  0xbf, %o2
a00ac388:  92 10 24 50  mov  0x450, %o1
a00ac38c:  7f ff ea 1d  call  0xa00a6c00
a00ac390:  94 10 20 00  clr  %o2
a00ac394:  90 10 00 1b  mov  %i3, %o0
a00ac398:  92 10 24 5d  mov  0x45d, %o1
a00ac39c:  94 10 20 00  clr  %o2
a00ac3a0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ac3a4:  7f ff ea 17  call  0xa00a6c00
a00ac3a8:  b2 10 20 30  mov  0x30, %i1
a00ac3ac:  90 10 00 18  mov  %i0, %o0
a00ac3b0:  92 10 23 e0  mov  0x3e0, %o1
a00ac3b4:  7f ff ea 13  call  0xa00a6c00
a00ac3b8:  94 10 20 38  mov  0x38, %o2
a00ac3bc:  90 10 00 18  mov  %i0, %o0
a00ac3c0:  92 10 23 e1  mov  0x3e1, %o1
a00ac3c4:  7f ff ea 0f  call  0xa00a6c00
a00ac3c8:  94 10 20 ec  mov  0xec, %o2
a00ac3cc:  90 10 00 18  mov  %i0, %o0
a00ac3d0:  92 10 23 e2  mov  0x3e2, %o1
a00ac3d4:  7f ff ea 0b  call  0xa00a6c00
a00ac3d8:  94 10 20 11  mov  0x11, %o2
a00ac3dc:  90 10 00 18  mov  %i0, %o0
a00ac3e0:  92 10 23 e3  mov  0x3e3, %o1
a00ac3e4:  7f ff ea 07  call  0xa00a6c00
a00ac3e8:  94 10 20 00  clr  %o2
a00ac3ec:  90 10 00 18  mov  %i0, %o0
a00ac3f0:  92 10 23 e4  mov  0x3e4, %o1
a00ac3f4:  7f ff ea 03  call  0xa00a6c00
a00ac3f8:  94 10 20 00  clr  %o2
a00ac3fc:  90 10 00 18  mov  %i0, %o0
a00ac400:  92 10 23 e5  mov  0x3e5, %o1
a00ac404:  7f ff e9 ff  call  0xa00a6c00
a00ac408:  94 10 20 00  clr  %o2
a00ac40c:  b4 10 20 80  mov  0x80, %i2
a00ac410:  7f ff ea 22  call  0xa00a6c98
a00ac414:  97 e8 20 00  restore  %g0, 0, %o3
a00ac418:  01 00 00 00  nop
