# leon2s FUN_a0096a6c 0xa0096a6c-0xa0096aa4 (56 bytes)
a0096a6c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a0096a70:  96 10 62 50  or  %g1, 0x250, %o3	! 0xa807d650
a0096a74:  98 10 20 00  clr  %o4
a0096a78:  82 0b 20 ff  and  %o4, 0xff, %g1
a0096a7c:  9a 00 40 01  add  %g1, %g1, %o5
a0096a80:  9a 03 40 01  add  %o5, %g1, %o5
a0096a84:  98 03 20 01  inc  %o4
a0096a88:  9b 2b 60 03  sll  %o5, 3, %o5
a0096a8c:  82 0b 20 ff  and  %o4, 0xff, %g1
a0096a90:  80 a0 60 01  cmp  %g1, 1
a0096a94:  08 bf ff fa  bleu  0xa0096a7c
a0096a98:  c0 22 c0 0d  clr  [ %o3 + %o5 ]
a0096a9c:  81 c3 e0 08  retl
a0096aa0:  01 00 00 00  nop
