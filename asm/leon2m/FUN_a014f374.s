# leon2m FUN_a014f374 0xa014f374-0xa014f3d8 (100 bytes)
a014f374:  96 0a 20 ff  and  %o0, 0xff, %o3
a014f378:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a014f37c:  d8 10 60 80  lduh  [ %g1 + 0x80 ], %o4	! 0xa802cc80
a014f380:  9a 10 20 00  clr  %o5
a014f384:  90 10 20 00  clr  %o0
a014f388:  83 2a 20 02  sll  %o0, 2, %g1
a014f38c:  83 3b 00 01  sra  %o4, %g1, %g1
a014f390:  82 08 60 0f  and  %g1, 0xf, %g1
a014f394:  80 a0 40 0b  cmp  %g1, %o3
a014f398:  02 80 00 06  be  0xa014f3b0
a014f39c:  9a 03 60 01  inc  %o5
a014f3a0:  90 0b 60 ff  and  %o5, 0xff, %o0
a014f3a4:  80 a2 20 03  cmp  %o0, 3
a014f3a8:  08 bf ff f9  bleu  0xa014f38c
a014f3ac:  83 2a 20 02  sll  %o0, 2, %g1
a014f3b0:  80 a2 20 03  cmp  %o0, 3
a014f3b4:  18 80 00 06  bgu  0xa014f3cc
a014f3b8:  93 2a 60 10  sll  %o1, 0x10, %o1
a014f3bc:  93 32 60 10  srl  %o1, 0x10, %o1
a014f3c0:  82 13 c0 00  mov  %o7, %g1
a014f3c4:  7f ff a4 ac  call  0xa0138674
a014f3c8:  9e 10 40 00  mov  %g1, %o7
a014f3cc:  01 00 00 00  nop
a014f3d0:  81 c3 e0 08  retl
a014f3d4:  01 00 00 00  nop
