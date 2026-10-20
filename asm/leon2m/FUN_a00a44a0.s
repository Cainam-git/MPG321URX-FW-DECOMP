# leon2m FUN_a00a44a0 0xa00a44a0-0xa00a44f4 (84 bytes)
a00a44a0:  9d e3 bf 98  save  %sp, -104, %sp
a00a44a4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a44a8:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00a44ac:  da 0b 20 0f  ldub  [ %o4 + 0xf ], %o5
a00a44b0:  9a 03 7f ff  add  %o5, -1, %o5
a00a44b4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a44b8:  80 a0 60 05  cmp  %g1, 5
a00a44bc:  08 80 00 04  bleu  0xa00a44cc
a00a44c0:  90 10 20 01  mov  1, %o0
a00a44c4:  10 80 00 06  b  0xa00a44dc
a00a44c8:  c0 2b 20 0f  clrb  [ %o4 + 0xf ]
a00a44cc:  40 00 4c 19  call  0xa00b7530
a00a44d0:  da 2b 20 0f  stb  %o5, [ %o4 + 0xf ]
a00a44d4:  40 00 c0 ab  call  0xa00d4780
a00a44d8:  01 00 00 00  nop
a00a44dc:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00a44e0:  d6 0a 60 8e  ldub  [ %o1 + 0x8e ], %o3	! 0xa802b08e
a00a44e4:  94 12 e0 02  or  %o3, 2, %o2
a00a44e8:  d4 2a 60 8e  stb  %o2, [ %o1 + 0x8e ]
a00a44ec:  81 c7 e0 08  ret
a00a44f0:  81 e8 00 00  restore
