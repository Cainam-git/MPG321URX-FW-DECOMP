# leon2m FUN_a00b3108 0xa00b3108-0xa00b31a0 (152 bytes)
a00b3108:  9d e3 bf 98  save  %sp, -104, %sp
a00b310c:  7f ff d6 df  call  0xa00a8c88
a00b3110:  a2 10 20 00  clr  %l1
a00b3114:  90 10 21 11  mov  0x111, %o0
a00b3118:  40 02 4e 8e  call  0xa0146b50
a00b311c:  92 10 20 00  clr  %o1
a00b3120:  90 10 20 00  clr  %o0
a00b3124:  40 02 4e 92  call  0xa0146b6c
a00b3128:  92 10 20 00  clr  %o1
a00b312c:  a0 10 20 00  clr  %l0
a00b3130:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00b3134:  25 00 06 3a  sethi  %hi(0x18e800), %l2
a00b3138:  95 2c 20 03  sll  %l0, 3, %o2
a00b313c:  9e 22 80 10  sub  %o2, %l0, %o7
a00b3140:  99 2b e0 02  sll  %o7, 2, %o4
a00b3144:  9a 14 e2 90  or  %l3, 0x290, %o5
a00b3148:  96 03 00 10  add  %o4, %l0, %o3
a00b314c:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00b3150:  90 02 c0 01  add  %o3, %g1, %o0
a00b3154:  93 2a 20 10  sll  %o0, 0x10, %o1
a00b3158:  93 32 60 10  srl  %o1, 0x10, %o1
a00b315c:  7f ff c1 ba  call  0xa00a3844
a00b3160:  90 14 a1 f8  or  %l2, 0x1f8, %o0
a00b3164:  98 10 00 08  mov  %o0, %o4
a00b3168:  94 04 00 10  add  %l0, %l0, %o2
a00b316c:  94 02 a0 06  add  %o2, 6, %o2
a00b3170:  90 10 20 00  clr  %o0
a00b3174:  92 10 20 2a  mov  0x2a, %o1
a00b3178:  96 10 20 01  mov  1, %o3
a00b317c:  9a 10 20 00  clr  %o5
a00b3180:  7f ff c0 09  call  0xa00a31a4
a00b3184:  a2 04 60 01  inc  %l1
a00b3188:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b318c:  80 a4 20 04  cmp  %l0, 4
a00b3190:  08 bf ff eb  bleu  0xa00b313c
a00b3194:  95 2c 20 03  sll  %l0, 3, %o2
a00b3198:  81 c7 e0 08  ret
a00b319c:  81 e8 00 00  restore
