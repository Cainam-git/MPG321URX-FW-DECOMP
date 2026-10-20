# leon2s FUN_a0093164 0xa0093164-0xa00931fc (152 bytes)
a0093164:  9d e3 bf 98  save  %sp, -104, %sp
a0093168:  a0 10 20 00  clr  %l0
a009316c:  94 0c 20 ff  and  %l0, 0xff, %o2
a0093170:  94 02 a1 1e  add  %o2, 0x11e, %o2
a0093174:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a0093178:  9a 0c 20 ff  and  %l0, 0xff, %o5
a009317c:  82 10 62 00  or  %g1, 0x200, %g1
a0093180:  95 2a a0 10  sll  %o2, 0x10, %o2
a0093184:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0093188:  d6 08 40 0d  ldub  [ %g1 + %o5 ], %o3
a009318c:  95 32 a0 10  srl  %o2, 0x10, %o2
a0093190:  90 10 00 11  mov  %l1, %o0
a0093194:  40 00 53 b0  call  0xa00a8054
a0093198:  92 10 20 00  clr  %o1
a009319c:  a0 04 20 01  inc  %l0
a00931a0:  82 0c 20 ff  and  %l0, 0xff, %g1
a00931a4:  80 a0 60 04  cmp  %g1, 4
a00931a8:  08 bf ff f2  bleu  0xa0093170
a00931ac:  94 0c 20 ff  and  %l0, 0xff, %o2
a00931b0:  a0 10 20 00  clr  %l0
a00931b4:  94 0c 20 ff  and  %l0, 0xff, %o2
a00931b8:  94 02 a1 80  add  %o2, 0x180, %o2
a00931bc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00931c0:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00931c4:  82 10 61 f0  or  %g1, 0x1f0, %g1
a00931c8:  95 2a a0 10  sll  %o2, 0x10, %o2
a00931cc:  d6 08 40 0d  ldub  [ %g1 + %o5 ], %o3
a00931d0:  95 32 a0 10  srl  %o2, 0x10, %o2
a00931d4:  90 10 00 11  mov  %l1, %o0
a00931d8:  40 00 53 9f  call  0xa00a8054
a00931dc:  92 10 20 00  clr  %o1
a00931e0:  a0 04 20 01  inc  %l0
a00931e4:  82 0c 20 ff  and  %l0, 0xff, %g1
a00931e8:  80 a0 60 08  cmp  %g1, 8
a00931ec:  08 bf ff f3  bleu  0xa00931b8
a00931f0:  94 0c 20 ff  and  %l0, 0xff, %o2
a00931f4:  81 c7 e0 08  ret
a00931f8:  81 e8 00 00  restore
