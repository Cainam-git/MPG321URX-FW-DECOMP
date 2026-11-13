# leon2m FUN_a008f354 0xa008f354-0xa008f3e8 (148 bytes)
a008f354:  9d e3 bf 98  save  %sp, -104, %sp
a008f358:  40 00 07 20  call  0xa0090fd8
a008f35c:  01 00 00 00  nop
a008f360:  90 10 20 00  clr  %o0	! 0x0
a008f364:  40 02 d7 72  call  0xa014512c
a008f368:  92 10 20 01  mov  1, %o1
a008f36c:  90 10 20 00  clr  %o0
a008f370:  92 10 20 00  clr  %o1
a008f374:  94 10 20 00  clr  %o2
a008f378:  96 10 20 00  clr  %o3
a008f37c:  40 02 db 1b  call  0xa0145fe8
a008f380:  98 10 20 00  clr  %o4
a008f384:  40 01 26 54  call  0xa00d8cd4
a008f388:  01 00 00 00  nop
a008f38c:  40 01 22 95  call  0xa00d7de0
a008f390:  01 00 00 00  nop
a008f394:  40 01 28 f4  call  0xa00d9764
a008f398:  01 00 00 00  nop
a008f39c:  40 01 22 09  call  0xa00d7bc0
a008f3a0:  01 00 00 00  nop
a008f3a4:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a008f3a8:  a0 12 23 f4  or  %o0, 0x3f4, %l0	! 0xa802cff4
a008f3ac:  da 14 20 04  lduh  [ %l0 + 4 ], %o5
a008f3b0:  03 00 00 04  sethi  %hi(0x1000), %g1
a008f3b4:  80 88 40 0d  btst  %g1, %o5
a008f3b8:  12 80 00 04  bne  0xa008f3c8
a008f3bc:  01 00 00 00  nop
a008f3c0:  40 01 2b a5  call  0xa00da254
a008f3c4:  01 00 00 00  nop
a008f3c8:  40 00 97 44  call  0xa00b50d8
a008f3cc:  90 10 20 01  mov  1, %o0	! 0x1
a008f3d0:  d6 14 20 04  lduh  [ %l0 + 4 ], %o3
a008f3d4:  15 00 00 04  sethi  %hi(0x1000), %o2
a008f3d8:  92 2a c0 0a  andn  %o3, %o2, %o1
a008f3dc:  d2 34 20 04  sth  %o1, [ %l0 + 4 ]
a008f3e0:  81 c7 e0 08  ret
a008f3e4:  81 e8 00 00  restore
