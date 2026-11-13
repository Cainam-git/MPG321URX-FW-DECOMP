# leon2m FUN_a00c2f08 0xa00c2f08-0xa00c3180 (632 bytes)
a00c2f08:  9d e3 bf 98  save  %sp, -104, %sp
a00c2f0c:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00c2f10:  80 a4 60 02  cmp  %l1, 2
a00c2f14:  02 80 00 5f  be  0xa00c3090
a00c2f18:  80 a4 60 03  cmp  %l1, 3
a00c2f1c:  02 80 00 7a  be  0xa00c3104
a00c2f20:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c2f24:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c2f28:  94 08 60 ff  and  %g1, 0xff, %o2
a00c2f2c:  a4 02 bf d0  add  %o2, -48, %l2
a00c2f30:  92 0c a0 ff  and  %l2, 0xff, %o1
a00c2f34:  80 a2 60 04  cmp  %o1, 4
a00c2f38:  18 80 00 90  bgu  0xa00c3178
a00c2f3c:  b0 10 20 ff  mov  0xff, %i0
a00c2f40:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a00c2f44:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c2f48:  de 12 23 f4  lduh  [ %o0 + 0x3f4 ], %o7
a00c2f4c:  a0 12 e2 90  or  %o3, 0x290, %l0
a00c2f50:  03 00 00 10  sethi  %hi(0x4000), %g1
a00c2f54:  92 02 40 10  add  %o1, %l0, %o1
a00c2f58:  9a 13 c0 01  or  %o7, %g1, %o5
a00c2f5c:  94 12 23 f4  or  %o0, 0x3f4, %o2
a00c2f60:  de 0a 61 9b  ldub  [ %o1 + 0x19b ], %o7
a00c2f64:  f0 12 a0 04  lduh  [ %o2 + 4 ], %i0
a00c2f68:  d6 0a 61 97  ldub  [ %o1 + 0x197 ], %o3
a00c2f6c:  da 32 23 f4  sth  %o5, [ %o0 + 0x3f4 ]
a00c2f70:  19 00 00 18  sethi  %hi(0x6000), %o4
a00c2f74:  80 8b 00 18  btst  %o4, %i0
a00c2f78:  e4 2c 21 a0  stb  %l2, [ %l0 + 0x1a0 ]
a00c2f7c:  d6 2c 21 a1  stb  %o3, [ %l0 + 0x1a1 ]
a00c2f80:  02 80 00 47  be  0xa00c309c
a00c2f84:  de 2c 21 a2  stb  %o7, [ %l0 + 0x1a2 ]
a00c2f88:  80 a4 60 02  cmp  %l1, 2
a00c2f8c:  02 80 00 24  be  0xa00c301c
a00c2f90:  80 a4 60 03  cmp  %l1, 3
a00c2f94:  02 80 00 5f  be  0xa00c3110
a00c2f98:  9e 10 20 30  mov  0x30, %o7
a00c2f9c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c2fa0:  94 16 20 78  or  %i0, 0x78, %o2	! 0xa802d078
a00c2fa4:  98 10 20 35  mov  0x35, %o4
a00c2fa8:  a4 10 20 36  mov  0x36, %l2
a00c2fac:  96 10 20 2b  mov  0x2b, %o3
a00c2fb0:  82 10 20 0d  mov  0xd, %g1
a00c2fb4:  d8 2e 20 78  stb  %o4, [ %i0 + 0x78 ]
a00c2fb8:  e4 2a a0 01  stb  %l2, [ %o2 + 1 ]
a00c2fbc:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c2fc0:  d6 2a a0 04  stb  %o3, [ %o2 + 4 ]
a00c2fc4:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00c2fc8:  80 a4 60 02  cmp  %l1, 2
a00c2fcc:  02 80 00 21  be  0xa00c3050
a00c2fd0:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00c2fd4:  80 a4 60 03  cmp  %l1, 3
a00c2fd8:  02 80 00 5b  be  0xa00c3144
a00c2fdc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c2fe0:  9e 12 e0 d0  or  %o3, 0xd0, %o7	! 0xa802d0d0
a00c2fe4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c2fe8:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]	! 0xa802b09c
a00c2fec:  c0 2a e0 d0  clrb  [ %o3 + 0xd0 ]
a00c2ff0:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c2ff4:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c2ff8:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c2ffc:  80 a4 60 02  cmp  %l1, 2
a00c3000:  02 80 00 1d  be  0xa00c3074
a00c3004:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c3008:  80 a4 60 03  cmp  %l1, 3
a00c300c:  12 80 00 1d  bne  0xa00c3080
a00c3010:  90 10 00 11  mov  %l1, %o0
a00c3014:  10 80 00 56  b  0xa00c316c
a00c3018:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c301c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c3020:  a2 12 e1 28  or  %o3, 0x128, %l1	! 0xa802d128
a00c3024:  92 10 20 30  mov  0x30, %o1
a00c3028:  a4 10 20 35  mov  0x35, %l2
a00c302c:  82 10 20 0d  mov  0xd, %g1
a00c3030:  9e 10 20 36  mov  0x36, %o7
a00c3034:  94 10 20 2b  mov  0x2b, %o2
a00c3038:  e4 2a e1 28  stb  %l2, [ %o3 + 0x128 ]
a00c303c:  c2 2c 60 05  stb  %g1, [ %l1 + 5 ]
a00c3040:  de 2c 60 01  stb  %o7, [ %l1 + 1 ]
a00c3044:  d2 2c 60 03  stb  %o1, [ %l1 + 3 ]
a00c3048:  d4 2c 60 04  stb  %o2, [ %l1 + 4 ]
a00c304c:  d2 2c 60 02  stb  %o1, [ %l1 + 2 ]
a00c3050:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c3054:  94 12 20 40  or  %o0, 0x40, %o2	! 0xa802d040
a00c3058:  21 2a 00 ac  sethi  %hi(0xa802b000), %l0
a00c305c:  c0 2c 20 9a  clrb  [ %l0 + 0x9a ]	! 0xa802b09a
a00c3060:  c0 2a 20 40  clrb  [ %o0 + 0x40 ]
a00c3064:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c3068:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c306c:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c3070:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c3074:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00c3078:  94 14 a1 28  or  %l2, 0x128, %o2	! 0xa802d128
a00c307c:  90 10 20 02  mov  2, %o0
a00c3080:  40 02 15 da  call  0xa01487e8
a00c3084:  92 10 20 06  mov  6, %o1
a00c3088:  10 80 00 3c  b  0xa00c3178
a00c308c:  b0 10 20 00  clr  %i0
a00c3090:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c3094:  10 bf ff a5  b  0xa00c2f28
a00c3098:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c309c:  7f ff 37 cf  call  0xa0090fd8
a00c30a0:  01 00 00 00  nop
a00c30a4:  7f ff 37 c2  call  0xa0090fac
a00c30a8:  01 00 00 00  nop
a00c30ac:  e4 0c 21 90  ldub  [ %l0 + 0x190 ], %l2
a00c30b0:  80 a4 a0 00  cmp  %l2, 0
a00c30b4:  12 bf ff b6  bne  0xa00c2f8c
a00c30b8:  80 a4 60 02  cmp  %l1, 2
a00c30bc:  d8 04 20 a8  ld  [ %l0 + 0xa8 ], %o4
a00c30c0:  31 00 00 04  sethi  %hi(0x1000), %i0
a00c30c4:  80 8b 00 18  btst  %o4, %i0
a00c30c8:  12 bf ff b1  bne  0xa00c2f8c
a00c30cc:  80 a4 60 02  cmp  %l1, 2
a00c30d0:  d0 0c 21 a0  ldub  [ %l0 + 0x1a0 ], %o0
a00c30d4:  80 a2 20 00  cmp  %o0, 0
a00c30d8:  12 bf ff ad  bne  0xa00c2f8c
a00c30dc:  80 a4 60 02  cmp  %l1, 2
a00c30e0:  da 04 20 ac  ld  [ %l0 + 0xac ], %o5
a00c30e4:  21 00 10 00  sethi  %hi(0x400000), %l0
a00c30e8:  80 8b 40 10  btst  %o5, %l0
a00c30ec:  32 bf ff a8  bne,a   0xa00c2f8c
a00c30f0:  80 a4 60 02  cmp  %l1, 2
a00c30f4:  7f ff 37 b9  call  0xa0090fd8
a00c30f8:  01 00 00 00  nop
a00c30fc:  10 bf ff a4  b  0xa00c2f8c
a00c3100:  80 a4 60 02  cmp  %l1, 2
a00c3104:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c3108:  10 bf ff 88  b  0xa00c2f28
a00c310c:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c3110:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c3114:  b0 14 61 08  or  %l1, 0x108, %i0	! 0xa802d108
a00c3118:  98 10 20 30  mov  0x30, %o4
a00c311c:  92 10 20 35  mov  0x35, %o1
a00c3120:  9a 10 20 0d  mov  0xd, %o5
a00c3124:  a0 10 20 36  mov  0x36, %l0
a00c3128:  90 10 20 2b  mov  0x2b, %o0
a00c312c:  d2 2c 61 08  stb  %o1, [ %l1 + 0x108 ]
a00c3130:  da 2e 20 05  stb  %o5, [ %i0 + 5 ]
a00c3134:  e0 2e 20 01  stb  %l0, [ %i0 + 1 ]
a00c3138:  d8 2e 20 03  stb  %o4, [ %i0 + 3 ]
a00c313c:  d0 2e 20 04  stb  %o0, [ %i0 + 4 ]
a00c3140:  d8 2e 20 02  stb  %o4, [ %i0 + 2 ]
a00c3144:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00c3148:  9a 14 60 98  or  %l1, 0x98, %o5	! 0xa802d098
a00c314c:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00c3150:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]	! 0xa802b098
a00c3154:  c0 2c 60 98  clrb  [ %l1 + 0x98 ]
a00c3158:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c315c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c3160:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c3164:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c3168:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c316c:  94 16 21 08  or  %i0, 0x108, %o2	! 0xa802d108
a00c3170:  10 bf ff c4  b  0xa00c3080
a00c3174:  90 10 20 03  mov  3, %o0
a00c3178:  81 c7 e0 08  ret
a00c317c:  81 e8 00 00  restore
