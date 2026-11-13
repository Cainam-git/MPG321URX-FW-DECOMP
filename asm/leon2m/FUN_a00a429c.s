# leon2m FUN_a00a429c 0xa00a429c-0xa00a42f0 (84 bytes)
a00a429c:  9d e3 bf 98  save  %sp, -104, %sp
a00a42a0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a42a4:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00a42a8:  da 0b 20 09  ldub  [ %o4 + 9 ], %o5
a00a42ac:  9a 03 7f ff  add  %o5, -1, %o5
a00a42b0:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a42b4:  80 a0 60 64  cmp  %g1, 0x64
a00a42b8:  08 80 00 04  bleu  0xa00a42c8
a00a42bc:  90 10 20 01  mov  1, %o0
a00a42c0:  10 80 00 06  b  0xa00a42d8
a00a42c4:  c0 2b 20 09  clrb  [ %o4 + 9 ]
a00a42c8:  40 00 4b 63  call  0xa00b7054
a00a42cc:  da 2b 20 09  stb  %o5, [ %o4 + 9 ]
a00a42d0:  40 00 d2 81  call  0xa00d8cd4
a00a42d4:  01 00 00 00  nop
a00a42d8:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00a42dc:  d6 0a 60 8e  ldub  [ %o1 + 0x8e ], %o3	! 0xa802b08e
a00a42e0:  94 12 e0 02  or  %o3, 2, %o2
a00a42e4:  d4 2a 60 8e  stb  %o2, [ %o1 + 0x8e ]
a00a42e8:  81 c7 e0 08  ret
a00a42ec:  81 e8 00 00  restore
