# leon2m FUN_a0147064 0xa0147064-0xa01470fc (152 bytes)
a0147064:  9d e3 bf 98  save  %sp, -104, %sp
a0147068:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014706c:  80 a6 20 01  cmp  %i0, 1
a0147070:  02 80 00 0b  be  0xa014709c
a0147074:  82 10 20 01  mov  1, %g1
a0147078:  80 a6 20 01  cmp  %i0, 1
a014707c:  04 80 00 11  ble  0xa01470c0
a0147080:  80 a6 20 02  cmp  %i0, 2
a0147084:  02 80 00 06  be  0xa014709c
a0147088:  82 10 20 02  mov  2, %g1
a014708c:  80 a6 20 03  cmp  %i0, 3
a0147090:  02 80 00 03  be  0xa014709c
a0147094:  82 10 20 03  mov  3, %g1
a0147098:  82 10 3f ff  mov  -1, %g1
a014709c:  9a 08 60 ff  and  %g1, 0xff, %o5
a01470a0:  80 a3 60 03  cmp  %o5, 3
a01470a4:  08 80 00 0d  bleu  0xa01470d8
a01470a8:  99 2b 60 04  sll  %o5, 4, %o4
a01470ac:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a01470b0:  7f fe 60 30  call  0xa00df170
a01470b4:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a01470b8:  10 80 00 07  b  0xa01470d4
a01470bc:  9a 10 20 00  clr  %o5
a01470c0:  80 a6 20 00  cmp  %i0, 0
a01470c4:  02 bf ff f6  be  0xa014709c
a01470c8:  82 10 20 00  clr  %g1
a01470cc:  10 bf ff f4  b  0xa014709c
a01470d0:  82 10 3f ff  mov  -1, %g1
a01470d4:  99 2b 60 04  sll  %o5, 4, %o4
a01470d8:  96 23 00 0d  sub  %o4, %o5, %o3
a01470dc:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a01470e0:  83 2a e0 03  sll  %o3, 3, %g1
a01470e4:  9a 12 a3 30  or  %o2, 0x330, %o5
a01470e8:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a01470ec:  b1 32 60 04  srl  %o1, 4, %i0
a01470f0:  b0 0e 20 0f  and  %i0, 0xf, %i0
a01470f4:  81 c7 e0 08  ret
a01470f8:  81 e8 00 00  restore
