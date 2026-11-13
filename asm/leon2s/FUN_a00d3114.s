# leon2s FUN_a00d3114 0xa00d3114-0xa00d31f8 (228 bytes)
a00d3114:  9d e3 bf 90  save  %sp, -112, %sp
a00d3118:  21 34 00 4f  sethi  %hi(0xd0013c00), %l0
a00d311c:  90 14 23 60  or  %l0, 0x360, %o0	! 0xd0013f60
a00d3120:  40 3a 79 02  call  0xa0f71528
a00d3124:  c0 27 bf f4  clr  [ %fp + -12 ]
a00d3128:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d312c:  90 07 bf f4  add  %fp, -12, %o0
a00d3130:  92 10 20 00  clr  %o1
a00d3134:  94 10 20 00  clr  %o2
a00d3138:  40 3a 78 e0  call  0xa0f714b8
a00d313c:  96 10 20 01  mov  1, %o3
a00d3140:  90 07 bf f4  add  %fp, -12, %o0
a00d3144:  92 10 20 10  mov  0x10, %o1
a00d3148:  94 10 20 08  mov  8, %o2
a00d314c:  40 3a 78 db  call  0xa0f714b8
a00d3150:  96 10 20 00  clr  %o3
a00d3154:  90 14 23 60  or  %l0, 0x360, %o0
a00d3158:  40 3a 78 f7  call  0xa0f71534
a00d315c:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d3160:  a0 10 20 00  clr  %l0
a00d3164:  96 10 00 10  mov  %l0, %o3
a00d3168:  94 10 20 08  mov  8, %o2
a00d316c:  90 07 bf f4  add  %fp, -12, %o0
a00d3170:  40 3a 78 d2  call  0xa0f714b8
a00d3174:  92 10 20 10  mov  0x10, %o1
a00d3178:  31 34 00 4f  sethi  %hi(0xd0013c00), %i0
a00d317c:  90 16 23 60  or  %i0, 0x360, %o0	! 0xd0013f60
a00d3180:  40 3a 78 ed  call  0xa0f71534
a00d3184:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d3188:  82 04 00 10  add  %l0, %l0, %g1
a00d318c:  80 a4 21 00  cmp  %l0, 0x100
a00d3190:  23 2a 01 de  sethi  %hi(0xa8077800), %l1
a00d3194:  90 16 23 6c  or  %i0, 0x36c, %o0
a00d3198:  9a 14 62 08  or  %l1, 0x208, %o5
a00d319c:  02 80 00 05  be  0xa00d31b0
a00d31a0:  a0 04 20 01  inc  %l0
a00d31a4:  d2 13 40 01  lduh  [ %o5 + %g1 ], %o1
a00d31a8:  10 80 00 0d  b  0xa00d31dc
a00d31ac:  90 16 23 68  or  %i0, 0x368, %o0
a00d31b0:  40 3a 78 de  call  0xa0f71528
a00d31b4:  01 00 00 00  nop
a00d31b8:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a00d31bc:  82 14 62 08  or  %l1, 0x208, %g1
a00d31c0:  90 07 bf f4  add  %fp, -12, %o0
a00d31c4:  92 10 20 0f  mov  0xf, %o1
a00d31c8:  d6 10 62 00  lduh  [ %g1 + 0x200 ], %o3
a00d31cc:  40 3a 78 bb  call  0xa0f714b8
a00d31d0:  94 10 20 00  clr  %o2
a00d31d4:  90 16 23 6c  or  %i0, 0x36c, %o0
a00d31d8:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a00d31dc:  40 3a 78 d6  call  0xa0f71534
a00d31e0:  01 00 00 00  nop
a00d31e4:  80 a4 21 00  cmp  %l0, 0x100
a00d31e8:  08 bf ff e0  bleu  0xa00d3168
a00d31ec:  96 10 00 10  mov  %l0, %o3
a00d31f0:  81 c7 e0 08  ret
a00d31f4:  91 e8 20 01  restore  %g0, 1, %o0
