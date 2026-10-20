# leon2m FUN_a00a82c4 0xa00a82c4-0xa00a835c (152 bytes)
a00a82c4:  9d e3 bf 98  save  %sp, -104, %sp
a00a82c8:  90 10 21 11  mov  0x111, %o0
a00a82cc:  40 02 7a 21  call  0xa0146b50
a00a82d0:  92 10 20 00  clr  %o1
a00a82d4:  90 10 20 00  clr  %o0
a00a82d8:  40 02 7a 25  call  0xa0146b6c
a00a82dc:  92 10 20 00  clr  %o1
a00a82e0:  a2 10 20 00  clr  %l1
a00a82e4:  a0 10 20 00  clr  %l0
a00a82e8:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00a82ec:  25 00 06 3e  sethi  %hi(0x18f800), %l2
a00a82f0:  93 2c 20 03  sll  %l0, 3, %o1
a00a82f4:  94 22 40 10  sub  %o1, %l0, %o2
a00a82f8:  9f 2a a0 02  sll  %o2, 2, %o7
a00a82fc:  9a 14 e2 90  or  %l3, 0x290, %o5
a00a8300:  96 03 c0 10  add  %o7, %l0, %o3
a00a8304:  d8 0b 60 08  ldub  [ %o5 + 8 ], %o4
a00a8308:  90 02 c0 0c  add  %o3, %o4, %o0
a00a830c:  82 02 20 1d  add  %o0, 0x1d, %g1
a00a8310:  93 28 60 10  sll  %g1, 0x10, %o1
a00a8314:  93 32 60 10  srl  %o1, 0x10, %o1
a00a8318:  7f ff ed 4b  call  0xa00a3844
a00a831c:  90 14 a1 84  or  %l2, 0x184, %o0
a00a8320:  98 10 00 08  mov  %o0, %o4
a00a8324:  94 04 00 10  add  %l0, %l0, %o2
a00a8328:  94 02 a0 06  add  %o2, 6, %o2
a00a832c:  90 10 20 00  clr  %o0
a00a8330:  92 10 20 2a  mov  0x2a, %o1
a00a8334:  96 10 20 01  mov  1, %o3
a00a8338:  9a 10 20 00  clr  %o5
a00a833c:  7f ff eb 9a  call  0xa00a31a4
a00a8340:  a2 04 60 01  inc  %l1
a00a8344:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a8348:  80 a4 20 03  cmp  %l0, 3
a00a834c:  08 bf ff ea  bleu  0xa00a82f4
a00a8350:  93 2c 20 03  sll  %l0, 3, %o1
a00a8354:  81 c7 e0 08  ret
a00a8358:  81 e8 00 00  restore
