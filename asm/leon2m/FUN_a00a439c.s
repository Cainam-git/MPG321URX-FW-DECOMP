# leon2m FUN_a00a439c 0xa00a439c-0xa00a43f4 (88 bytes)
a00a439c:  9d e3 bf 98  save  %sp, -104, %sp
a00a43a0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a43a4:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00a43a8:  da 0b 20 49  ldub  [ %o4 + 0x49 ], %o5
a00a43ac:  9a 03 60 01  inc  %o5
a00a43b0:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a43b4:  80 a0 60 05  cmp  %g1, 5
a00a43b8:  08 80 00 05  bleu  0xa00a43cc
a00a43bc:  90 10 20 01  mov  1, %o0
a00a43c0:  92 10 20 05  mov  5, %o1
a00a43c4:  10 80 00 06  b  0xa00a43dc
a00a43c8:  d2 2b 20 49  stb  %o1, [ %o4 + 0x49 ]
a00a43cc:  40 00 4b 6f  call  0xa00b7188
a00a43d0:  da 2b 20 49  stb  %o5, [ %o4 + 0x49 ]
a00a43d4:  40 00 bf 2c  call  0xa00d4084
a00a43d8:  01 00 00 00  nop
a00a43dc:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a43e0:  d8 0a a0 8e  ldub  [ %o2 + 0x8e ], %o4	! 0xa802b08e
a00a43e4:  96 13 20 02  or  %o4, 2, %o3
a00a43e8:  d6 2a a0 8e  stb  %o3, [ %o2 + 0x8e ]
a00a43ec:  81 c7 e0 08  ret
a00a43f0:  81 e8 00 00  restore
