# leon2m FUN_a00a8230 0xa00a8230-0xa00a82c4 (148 bytes)
a00a8230:  9d e3 bf 98  save  %sp, -104, %sp
a00a8234:  90 10 20 92  mov  0x92, %o0
a00a8238:  40 02 7a 46  call  0xa0146b50
a00a823c:  92 10 20 00  clr  %o1
a00a8240:  90 10 20 00  clr  %o0
a00a8244:  40 02 7a 4a  call  0xa0146b6c
a00a8248:  92 10 20 00  clr  %o1
a00a824c:  a2 10 20 00  clr  %l1
a00a8250:  a0 10 20 00  clr  %l0
a00a8254:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00a8258:  25 00 06 45  sethi  %hi(0x191400), %l2
a00a825c:  95 2c 20 03  sll  %l0, 3, %o2
a00a8260:  9e 22 80 10  sub  %o2, %l0, %o7
a00a8264:  99 2b e0 02  sll  %o7, 2, %o4
a00a8268:  9a 14 e2 90  or  %l3, 0x290, %o5
a00a826c:  96 03 00 10  add  %o4, %l0, %o3
a00a8270:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00a8274:  90 02 c0 01  add  %o3, %g1, %o0
a00a8278:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a827c:  93 32 60 10  srl  %o1, 0x10, %o1
a00a8280:  7f ff ed 71  call  0xa00a3844
a00a8284:  90 14 a1 8c  or  %l2, 0x18c, %o0
a00a8288:  98 10 00 08  mov  %o0, %o4
a00a828c:  94 04 00 10  add  %l0, %l0, %o2
a00a8290:  94 02 a0 06  add  %o2, 6, %o2
a00a8294:  90 10 20 00  clr  %o0
a00a8298:  92 10 20 14  mov  0x14, %o1
a00a829c:  96 10 20 01  mov  1, %o3
a00a82a0:  9a 10 20 00  clr  %o5
a00a82a4:  7f ff eb c0  call  0xa00a31a4
a00a82a8:  a2 04 60 01  inc  %l1
a00a82ac:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a82b0:  80 a4 20 04  cmp  %l0, 4
a00a82b4:  0a bf ff eb  bcs  0xa00a8260
a00a82b8:  95 2c 20 03  sll  %l0, 3, %o2
a00a82bc:  81 c7 e0 08  ret
a00a82c0:  81 e8 00 00  restore
