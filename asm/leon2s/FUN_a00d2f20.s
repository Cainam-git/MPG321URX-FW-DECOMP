# leon2s FUN_a00d2f20 0xa00d2f20-0xa00d3114 (400 bytes)
a00d2f20:  9d e3 bf 90  save  %sp, -112, %sp
a00d2f24:  82 06 3f ff  add  %i0, -1, %g1
a00d2f28:  c0 27 bf f4  clr  [ %fp + -12 ]
a00d2f2c:  80 a0 60 07  cmp  %g1, 7
a00d2f30:  18 80 00 21  bgu  0xa00d2fb4
a00d2f34:  c0 27 bf f0  clr  [ %fp + -16 ]
a00d2f38:  1b 27 c7 0b  sethi  %hi(0x9f1c2c00), %o5
a00d2f3c:  9a 13 63 00  or  %o5, 0x300, %o5	! 0x9f1c2f00
a00d2f40:  83 28 60 02  sll  %g1, 2, %g1
a00d2f44:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a00d2f48:  81 c0 40 00  jmp  %g1
a00d2f4c:  1b 2a 01 e3  sethi  %hi(0xa8078c00), %o5
a00d2f50:  82 10 21 0e  mov  0x10e, %g1
a00d2f54:  c2 33 60 44  sth  %g1, [ %o5 + 0x44 ]
a00d2f58:  03 27 c7 10  sethi  %hi(0x9f1c4000), %g1
a00d2f5c:  10 80 00 1b  b  0xa00d2fc8
a00d2f60:  a4 10 63 a8  or  %g1, 0x3a8, %l2	! 0x9f1c43a8
a00d2f64:  10 80 00 16  b  0xa00d2fbc
a00d2f68:  82 10 21 0e  mov  0x10e, %g1
a00d2f6c:  82 10 21 3b  mov  0x13b, %g1
a00d2f70:  c2 33 60 44  sth  %g1, [ %o5 + 0x44 ]
a00d2f74:  03 27 c7 15  sethi  %hi(0x9f1c5400), %g1
a00d2f78:  10 80 00 14  b  0xa00d2fc8
a00d2f7c:  a4 10 62 00  or  %g1, 0x200, %l2	! 0x9f1c5600
a00d2f80:  82 10 21 5b  mov  0x15b, %g1
a00d2f84:  c2 33 60 44  sth  %g1, [ %o5 + 0x44 ]
a00d2f88:  03 27 c7 14  sethi  %hi(0x9f1c5000), %g1
a00d2f8c:  10 80 00 0f  b  0xa00d2fc8
a00d2f90:  a4 10 61 a8  or  %g1, 0x1a8, %l2	! 0x9f1c51a8
a00d2f94:  82 10 21 a9  mov  0x1a9, %g1
a00d2f98:  c2 33 60 44  sth  %g1, [ %o5 + 0x44 ]
a00d2f9c:  03 27 c7 13  sethi  %hi(0x9f1c4c00), %g1
a00d2fa0:  10 80 00 0a  b  0xa00d2fc8
a00d2fa4:  a4 10 61 08  or  %g1, 0x108, %l2	! 0x9f1c4d08
a00d2fa8:  82 10 21 0e  mov  0x10e, %g1
a00d2fac:  10 80 00 58  b  0xa00d310c
a00d2fb0:  c2 33 60 44  sth  %g1, [ %o5 + 0x44 ]
a00d2fb4:  82 10 21 0e  mov  0x10e, %g1
a00d2fb8:  1b 2a 01 e3  sethi  %hi(0xa8078c00), %o5
a00d2fbc:  c2 33 60 44  sth  %g1, [ %o5 + 0x44 ]	! 0xa8078c44
a00d2fc0:  03 27 c7 16  sethi  %hi(0x9f1c5800), %g1
a00d2fc4:  a4 10 62 38  or  %g1, 0x238, %l2	! 0x9f1c5a38
a00d2fc8:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d2fcc:  40 3a 79 57  call  0xa0f71528
a00d2fd0:  90 14 23 d0  or  %l0, 0x3d0, %o0	! 0xd0013fd0
a00d2fd4:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d2fd8:  90 07 bf f4  add  %fp, -12, %o0
a00d2fdc:  92 10 20 02  mov  2, %o1
a00d2fe0:  94 10 20 00  clr  %o2
a00d2fe4:  40 3a 79 35  call  0xa0f714b8
a00d2fe8:  96 10 20 07  mov  7, %o3
a00d2fec:  90 07 bf f4  add  %fp, -12, %o0
a00d2ff0:  92 10 20 05  mov  5, %o1
a00d2ff4:  94 10 20 04  mov  4, %o2
a00d2ff8:  40 3a 79 30  call  0xa0f714b8
a00d2ffc:  96 10 20 00  clr  %o3
a00d3000:  90 14 23 d0  or  %l0, 0x3d0, %o0
a00d3004:  40 3a 79 4c  call  0xa0f71534
a00d3008:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d300c:  a2 10 20 00  clr  %l1
a00d3010:  a6 10 20 00  clr  %l3
a00d3014:  b0 10 20 00  clr  %i0
a00d3018:  90 07 bf f4  add  %fp, -12, %o0
a00d301c:  92 10 20 13  mov  0x13, %o1
a00d3020:  94 10 20 08  mov  8, %o2
a00d3024:  40 3a 79 25  call  0xa0f714b8
a00d3028:  96 10 00 18  mov  %i0, %o3
a00d302c:  11 34 00 4f  sethi  %hi(0xd0013c00), %o0
a00d3030:  90 12 23 d0  or  %o0, 0x3d0, %o0	! 0xd0013fd0
a00d3034:  40 3a 79 40  call  0xa0f71534
a00d3038:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d303c:  03 00 00 ff  sethi  %hi(0x3fc00), %g1
a00d3040:  82 10 63 fe  or  %g1, 0x3fe, %g1	! 0x3fffe
a00d3044:  80 a4 40 01  cmp  %l1, %g1
a00d3048:  18 80 00 0e  bgu  0xa00d3080
a00d304c:  11 34 00 4f  sethi  %hi(0xd0013c00), %o0
a00d3050:  c2 0c 80 13  ldub  [ %l2 + %l3 ], %g1
a00d3054:  80 a0 60 ef  cmp  %g1, 0xef
a00d3058:  28 80 00 08  bleu,a   0xa00d3078
a00d305c:  a2 04 40 01  add  %l1, %g1, %l1
a00d3060:  82 08 60 0f  and  %g1, 0xf, %g1
a00d3064:  a6 04 e0 01  inc  %l3
a00d3068:  83 28 60 08  sll  %g1, 8, %g1
a00d306c:  da 0c 80 13  ldub  [ %l2 + %l3 ], %o5
a00d3070:  82 00 40 0d  add  %g1, %o5, %g1
a00d3074:  a2 04 40 01  add  %l1, %g1, %l1
a00d3078:  a6 04 e0 01  inc  %l3
a00d307c:  11 34 00 4f  sethi  %hi(0xd0013c00), %o0
a00d3080:  90 12 23 d8  or  %o0, 0x3d8, %o0	! 0xd0013fd8
a00d3084:  80 a6 24 00  cmp  %i0, 0x400
a00d3088:  12 80 00 0d  bne  0xa00d30bc
a00d308c:  92 10 00 11  mov  %l1, %o1
a00d3090:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d3094:  40 3a 79 25  call  0xa0f71528
a00d3098:  90 14 23 dc  or  %l0, 0x3dc, %o0	! 0xd0013fdc
a00d309c:  d0 27 bf f0  st  %o0, [ %fp + -16 ]
a00d30a0:  90 07 bf f0  add  %fp, -16, %o0
a00d30a4:  92 10 20 11  mov  0x11, %o1
a00d30a8:  94 10 20 00  clr  %o2
a00d30ac:  40 3a 79 03  call  0xa0f714b8
a00d30b0:  96 10 00 11  mov  %l1, %o3
a00d30b4:  90 14 23 dc  or  %l0, 0x3dc, %o0
a00d30b8:  d2 07 bf f0  ld  [ %fp + -16 ], %o1
a00d30bc:  40 3a 79 1e  call  0xa0f71534
a00d30c0:  01 00 00 00  nop
a00d30c4:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d30c8:  da 10 60 44  lduh  [ %g1 + 0x44 ], %o5	! 0xa8078c44
a00d30cc:  80 a3 40 18  cmp  %o5, %i0
a00d30d0:  3a 80 00 0c  bcc,a   0xa00d3100
a00d30d4:  b0 06 20 01  inc  %i0
a00d30d8:  82 03 61 f4  add  %o5, 0x1f4, %g1
a00d30dc:  80 a6 00 01  cmp  %i0, %g1
a00d30e0:  3a 80 00 08  bcc,a   0xa00d3100
a00d30e4:  b0 06 20 01  inc  %i0
a00d30e8:  9a 26 00 0d  sub  %i0, %o5, %o5
a00d30ec:  03 2a 01 df  sethi  %hi(0xa8077c00), %g1
a00d30f0:  9b 2b 60 02  sll  %o5, 2, %o5
a00d30f4:  82 10 60 0c  or  %g1, 0xc, %g1
a00d30f8:  e2 20 40 0d  st  %l1, [ %g1 + %o5 ]
a00d30fc:  b0 06 20 01  inc  %i0
a00d3100:  80 a6 24 00  cmp  %i0, 0x400
a00d3104:  08 bf ff c6  bleu  0xa00d301c
a00d3108:  90 07 bf f4  add  %fp, -12, %o0
a00d310c:  81 c7 e0 08  ret
a00d3110:  91 e8 20 01  restore  %g0, 1, %o0
