# leon2m FUN_a00b3238 0xa00b3238-0xa00b32ac (116 bytes)
a00b3238:  9d e3 bf 98  save  %sp, -104, %sp
a00b323c:  7f ff d6 93  call  0xa00a8c88
a00b3240:  a2 10 20 00  clr  %l1
a00b3244:  90 10 21 11  mov  0x111, %o0
a00b3248:  40 02 4e 42  call  0xa0146b50
a00b324c:  92 10 20 00  clr  %o1
a00b3250:  90 10 20 00  clr  %o0
a00b3254:  40 02 4e 46  call  0xa0146b6c
a00b3258:  92 10 20 00  clr  %o1
a00b325c:  a0 10 20 00  clr  %l0
a00b3260:  25 00 06 3d  sethi  %hi(0x18f400), %l2
a00b3264:  92 10 00 10  mov  %l0, %o1
a00b3268:  7f ff c1 77  call  0xa00a3844
a00b326c:  90 14 a1 2c  or  %l2, 0x12c, %o0
a00b3270:  98 10 00 08  mov  %o0, %o4
a00b3274:  94 04 00 10  add  %l0, %l0, %o2
a00b3278:  94 02 a0 06  add  %o2, 6, %o2
a00b327c:  90 10 20 00  clr  %o0
a00b3280:  92 10 20 2a  mov  0x2a, %o1
a00b3284:  96 10 20 01  mov  1, %o3
a00b3288:  9a 10 20 00  clr  %o5
a00b328c:  7f ff bf c6  call  0xa00a31a4
a00b3290:  a2 04 60 01  inc  %l1
a00b3294:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00b3298:  80 a4 20 02  cmp  %l0, 2
a00b329c:  08 bf ff f3  bleu  0xa00b3268
a00b32a0:  92 10 00 10  mov  %l0, %o1
a00b32a4:  81 c7 e0 08  ret
a00b32a8:  81 e8 00 00  restore
