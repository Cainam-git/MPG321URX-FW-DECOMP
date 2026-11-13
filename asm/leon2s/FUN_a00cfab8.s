# leon2s FUN_a00cfab8 0xa00cfab8-0xa00cfb20 (104 bytes)
a00cfab8:  9d e3 bf 98  save  %sp, -104, %sp
a00cfabc:  40 3b c9 6a  call  0xa0fc2064
a00cfac0:  01 00 00 00  nop
a00cfac4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00cfac8:  da 00 63 f8  ld  [ %g1 + 0x3f8 ], %o5	! 0xa8078bf8
a00cfacc:  d0 20 63 f8  st  %o0, [ %g1 + 0x3f8 ]
a00cfad0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00cfad4:  90 22 00 0d  sub  %o0, %o5, %o0
a00cfad8:  96 10 63 60  or  %g1, 0x360, %o3
a00cfadc:  98 10 20 00  clr  %o4
a00cfae0:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cfae4:  9b 28 60 02  sll  %g1, 2, %o5
a00cfae8:  c2 02 c0 0d  ld  [ %o3 + %o5 ], %g1
a00cfaec:  80 a2 00 01  cmp  %o0, %g1
a00cfaf0:  08 80 00 04  bleu  0xa00cfb00
a00cfaf4:  82 20 40 08  sub  %g1, %o0, %g1
a00cfaf8:  10 80 00 03  b  0xa00cfb04
a00cfafc:  c0 22 c0 0d  clr  [ %o3 + %o5 ]
a00cfb00:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cfb04:  98 03 20 01  inc  %o4
a00cfb08:  82 0b 20 ff  and  %o4, 0xff, %g1
a00cfb0c:  80 a0 60 0e  cmp  %g1, 0xe
a00cfb10:  08 bf ff f6  bleu  0xa00cfae8
a00cfb14:  9b 28 60 02  sll  %g1, 2, %o5
a00cfb18:  81 c7 e0 08  ret
a00cfb1c:  81 e8 00 00  restore
