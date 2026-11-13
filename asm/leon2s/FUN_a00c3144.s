# leon2s FUN_a00c3144 0xa00c3144-0xa00c32bc (376 bytes)
a00c3144:  9d e3 bf 98  save  %sp, -104, %sp
a00c3148:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c314c:  a1 2e 20 02  sll  %i0, 2, %l0
a00c3150:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00c3154:  9a 04 00 18  add  %l0, %i0, %o5
a00c3158:  98 10 60 24  or  %g1, 0x24, %o4
a00c315c:  9b 2b 60 02  sll  %o5, 2, %o5
a00c3160:  82 03 40 0c  add  %o5, %o4, %g1
a00c3164:  c2 10 60 12  lduh  [ %g1 + 0x12 ], %g1
a00c3168:  80 88 60 80  btst  0x80, %g1
a00c316c:  12 80 00 05  bne  0xa00c3180
a00c3170:  23 2a 01 e3  sethi  %hi(0xa8078c00), %l1
a00c3174:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c3178:  82 10 60 90  or  %g1, 0x90, %g1	! 0xa8078c90
a00c317c:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a00c3180:  82 14 60 90  or  %l1, 0x90, %g1
a00c3184:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a00c3188:  80 a0 60 01  cmp  %g1, 1
a00c318c:  12 80 00 0b  bne  0xa00c31b8
a00c3190:  01 00 00 00  nop
a00c3194:  c2 0b 00 0d  ldub  [ %o4 + %o5 ], %g1
a00c3198:  80 a0 60 03  cmp  %g1, 3
a00c319c:  12 80 00 07  bne  0xa00c31b8
a00c31a0:  01 00 00 00  nop
a00c31a4:  40 3b fb b0  call  0xa0fc2064
a00c31a8:  01 00 00 00  nop
a00c31ac:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c31b0:  82 10 60 98  or  %g1, 0x98, %g1	! 0xa8078c98
a00c31b4:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a00c31b8:  7f ff ff cb  call  0xa00c30e4
a00c31bc:  90 10 00 18  mov  %i0, %o0
a00c31c0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00c31c4:  80 a0 60 01  cmp  %g1, 1
a00c31c8:  32 80 00 09  bne,a   0xa00c31ec
a00c31cc:  82 14 60 90  or  %l1, 0x90, %g1
a00c31d0:  19 2a 01 e3  sethi  %hi(0xa8078c00), %o4
a00c31d4:  da 0b 20 5b  ldub  [ %o4 + 0x5b ], %o5	! 0xa8078c5b
a00c31d8:  83 28 40 18  sll  %g1, %i0, %g1
a00c31dc:  82 2b 40 01  andn  %o5, %g1, %g1
a00c31e0:  9a 14 60 90  or  %l1, 0x90, %o5
a00c31e4:  10 80 00 33  b  0xa00c32b0
a00c31e8:  c2 2b 20 5b  stb  %g1, [ %o4 + 0x5b ]
a00c31ec:  e0 08 40 18  ldub  [ %g1 + %i0 ], %l0
a00c31f0:  80 a4 20 01  cmp  %l0, 1
a00c31f4:  32 80 00 0e  bne,a   0xa00c322c
a00c31f8:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c31fc:  40 3b fb 9a  call  0xa0fc2064
a00c3200:  01 00 00 00  nop
a00c3204:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c3208:  9b 2e 20 02  sll  %i0, 2, %o5
a00c320c:  82 10 60 98  or  %g1, 0x98, %g1
a00c3210:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a00c3214:  90 22 00 01  sub  %o0, %g1, %o0
a00c3218:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c321c:  80 a2 22 bb  cmp  %o0, 0x2bb
a00c3220:  08 80 00 0f  bleu  0xa00c325c
a00c3224:  9b 2c 00 18  sll  %l0, %i0, %o5
a00c3228:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00c322c:  9a 13 61 c8  or  %o5, 0x1c8, %o5	! 0xa807d5c8
a00c3230:  83 2e 20 04  sll  %i0, 4, %g1
a00c3234:  82 00 40 0d  add  %g1, %o5, %g1
a00c3238:  da 08 60 0d  ldub  [ %g1 + 0xd ], %o5
a00c323c:  82 03 7f fe  add  %o5, -2, %g1
a00c3240:  82 08 60 ff  and  %g1, 0xff, %g1
a00c3244:  80 a0 60 0a  cmp  %g1, 0xa
a00c3248:  18 80 00 09  bgu  0xa00c326c
a00c324c:  80 a3 60 0d  cmp  %o5, 0xd
a00c3250:  9a 10 20 01  mov  1, %o5
a00c3254:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c3258:  9b 2b 40 18  sll  %o5, %i0, %o5
a00c325c:  d8 08 60 5b  ldub  [ %g1 + 0x5b ], %o4
a00c3260:  9a 13 40 0c  or  %o5, %o4, %o5
a00c3264:  10 80 00 14  b  0xa00c32b4
a00c3268:  da 28 60 5b  stb  %o5, [ %g1 + 0x5b ]
a00c326c:  12 80 00 0b  bne  0xa00c3298
a00c3270:  17 2a 01 e3  sethi  %hi(0xa8078c00), %o3
a00c3274:  9a 10 20 01  mov  1, %o5
a00c3278:  c2 0a e0 5b  ldub  [ %o3 + 0x5b ], %g1
a00c327c:  9b 2b 40 18  sll  %o5, %i0, %o5
a00c3280:  9a 28 40 0d  andn  %g1, %o5, %o5
a00c3284:  98 14 60 90  or  %l1, 0x90, %o4
a00c3288:  82 10 20 01  mov  1, %g1
a00c328c:  c2 2b 00 18  stb  %g1, [ %o4 + %i0 ]
a00c3290:  10 80 00 09  b  0xa00c32b4
a00c3294:  da 2a e0 5b  stb  %o5, [ %o3 + 0x5b ]
a00c3298:  82 10 20 01  mov  1, %g1
a00c329c:  da 0a e0 5b  ldub  [ %o3 + 0x5b ], %o5
a00c32a0:  83 28 40 18  sll  %g1, %i0, %g1
a00c32a4:  82 2b 40 01  andn  %o5, %g1, %g1
a00c32a8:  9a 14 60 90  or  %l1, 0x90, %o5
a00c32ac:  c2 2a e0 5b  stb  %g1, [ %o3 + 0x5b ]
a00c32b0:  c0 2b 40 18  clrb  [ %o5 + %i0 ]
a00c32b4:  81 c7 e0 08  ret
a00c32b8:  81 e8 00 00  restore
