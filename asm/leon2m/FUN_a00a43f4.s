# leon2m FUN_a00a43f4 0xa00a43f4-0xa00a4448 (84 bytes)
a00a43f4:  9d e3 bf 98  save  %sp, -104, %sp
a00a43f8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00a43fc:  98 12 22 90  or  %o0, 0x290, %o4	! 0xa802d290
a00a4400:  da 0b 20 49  ldub  [ %o4 + 0x49 ], %o5
a00a4404:  9a 03 7f ff  add  %o5, -1, %o5
a00a4408:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a440c:  80 a0 60 05  cmp  %g1, 5
a00a4410:  08 80 00 04  bleu  0xa00a4420
a00a4414:  90 10 20 01  mov  1, %o0
a00a4418:  10 80 00 06  b  0xa00a4430
a00a441c:  c0 2b 20 49  clrb  [ %o4 + 0x49 ]
a00a4420:  40 00 4b 5a  call  0xa00b7188
a00a4424:  da 2b 20 49  stb  %o5, [ %o4 + 0x49 ]
a00a4428:  40 00 bf 17  call  0xa00d4084
a00a442c:  01 00 00 00  nop
a00a4430:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00a4434:  d6 0a 60 8e  ldub  [ %o1 + 0x8e ], %o3	! 0xa802b08e
a00a4438:  94 12 e0 02  or  %o3, 2, %o2
a00a443c:  d4 2a 60 8e  stb  %o2, [ %o1 + 0x8e ]
a00a4440:  81 c7 e0 08  ret
a00a4444:  81 e8 00 00  restore
