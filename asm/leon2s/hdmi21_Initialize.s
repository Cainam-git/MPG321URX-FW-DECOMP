# leon2s hdmi21_Initialize 0xa00a303c-0xa00a317c (320 bytes)
a00a303c:  9d e3 bf 98  save  %sp, -104, %sp
a00a3040:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a3044:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00a3048:  80 88 60 01  btst  1, %g1
a00a304c:  02 80 00 07  be  0xa00a3068
a00a3050:  b0 10 20 00  clr  %i0
a00a3054:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a3058:  13 28 02 d3  sethi  %hi(0xa00b4c00), %o1
a00a305c:  90 12 20 80  or  %o0, 0x80, %o0
a00a3060:  7f ff 3f f9  call  0xa0073044
a00a3064:  92 12 60 68  or  %o1, 0x68, %o1
a00a3068:  21 00 00 07  sethi  %hi(0x1c00), %l0
a00a306c:  90 10 20 08  mov  8, %o0
a00a3070:  92 10 20 00  clr  %o1
a00a3074:  40 00 10 fd  call  0xa00a7468
a00a3078:  94 14 23 0c  or  %l0, 0x30c, %o2
a00a307c:  80 a2 20 00  cmp  %o0, 0
a00a3080:  12 80 00 04  bne  0xa00a3090
a00a3084:  01 00 00 00  nop
a00a3088:  7f ff fe 7e  call  0xa00a2a80
a00a308c:  90 10 20 01  mov  1, %o0	! 0x1
a00a3090:  7f ff fe c2  call  0xa00a2b98
a00a3094:  01 00 00 00  nop
a00a3098:  7f ff fe 9c  call  0xa00a2b08
a00a309c:  90 10 20 01  mov  1, %o0	! 0x1
a00a30a0:  7f ff ff 8b  call  0xa00a2ecc
a00a30a4:  01 00 00 00  nop
a00a30a8:  94 14 23 0c  or  %l0, 0x30c, %o2
a00a30ac:  90 10 20 08  mov  8, %o0
a00a30b0:  40 00 10 ee  call  0xa00a7468
a00a30b4:  92 10 20 00  clr  %o1
a00a30b8:  80 a2 20 00  cmp  %o0, 0
a00a30bc:  12 80 00 04  bne  0xa00a30cc
a00a30c0:  01 00 00 00  nop
a00a30c4:  7f ff fe 6f  call  0xa00a2a80
a00a30c8:  01 00 00 00  nop
a00a30cc:  7f ff fe d3  call  0xa00a2c18
a00a30d0:  90 10 20 01  mov  1, %o0	! 0x1
a00a30d4:  7f ff fe 55  call  0xa00a2a28
a00a30d8:  a6 0e 20 ff  and  %i0, 0xff, %l3
a00a30dc:  7f ff ff be  call  0xa00a2fd4
a00a30e0:  01 00 00 00  nop
a00a30e4:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a00a30e8:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xa807db00
a00a30ec:  a2 5c e0 34  smul  %l3, 0x34, %l1
a00a30f0:  d2 04 00 11  ld  [ %l0 + %l1 ], %o1
a00a30f4:  92 02 60 08  add  %o1, 8, %o1
a00a30f8:  40 00 10 b7  call  0xa00a73d4
a00a30fc:  90 10 20 01  mov  1, %o0
a00a3100:  a4 04 40 10  add  %l1, %l0, %l2
a00a3104:  da 04 a0 0c  ld  [ %l2 + 0xc ], %o5
a00a3108:  c2 03 60 50  ld  [ %o5 + 0x50 ], %g1
a00a310c:  82 08 7f 00  and  %g1, -256, %g1
a00a3110:  82 10 60 01  or  %g1, 1, %g1
a00a3114:  d2 04 00 11  ld  [ %l0 + %l1 ], %o1
a00a3118:  c2 23 60 50  st  %g1, [ %o5 + 0x50 ]
a00a311c:  92 02 60 04  add  %o1, 4, %o1
a00a3120:  40 00 10 a3  call  0xa00a73ac
a00a3124:  90 10 20 0c  mov  0xc, %o0
a00a3128:  7f ff f9 a7  call  0xa00a17c4
a00a312c:  90 10 00 13  mov  %l3, %o0
a00a3130:  b0 06 20 01  inc  %i0
a00a3134:  da 04 a0 20  ld  [ %l2 + 0x20 ], %o5
a00a3138:  98 0e 20 ff  and  %i0, 0xff, %o4
a00a313c:  03 00 00 40  sethi  %hi(0x10000), %g1
a00a3140:  c2 23 60 3c  st  %g1, [ %o5 + 0x3c ]
a00a3144:  80 a3 20 01  cmp  %o4, 1
a00a3148:  28 bf ff e7  bleu,a   0xa00a30e4
a00a314c:  a6 0e 20 ff  and  %i0, 0xff, %l3
a00a3150:  7f ff a9 ac  call  0xa008d800
a00a3154:  01 00 00 00  nop
a00a3158:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a315c:  80 a2 20 82  cmp  %o0, 0x82
a00a3160:  18 80 00 05  bgu  0xa00a3174
a00a3164:  13 28 02 7d  sethi  %hi(0xa009f400), %o1
a00a3168:  92 12 62 54  or  %o1, 0x254, %o1	! 0xa009f654
a00a316c:  40 00 3b c1  call  0xa00b2070
a00a3170:  90 10 20 00  clr  %o0
a00a3174:  81 c7 e0 08  ret
a00a3178:  91 e8 20 00  restore  %g0, 0, %o0
