# leon2s FUN_a00a69fc 0xa00a69fc-0xa00a6aa0 (164 bytes)
a00a69fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6a00:  80 a2 20 02  cmp  %o0, 2
a00a6a04:  18 80 00 25  bgu  0xa00a6a98
a00a6a08:  01 00 00 00  nop
a00a6a0c:  12 80 00 16  bne  0xa00a6a64
a00a6a10:  80 a2 20 01  cmp  %o0, 1
a00a6a14:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00a6a18:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6a1c:  90 10 61 98  or  %g1, 0x198, %o0	! 0xa00b4d98
a00a6a20:  93 33 60 10  srl  %o5, 0x10, %o1
a00a6a24:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a6a28:  98 10 20 00  clr  %o4
a00a6a2c:  17 33 c0 00  sethi  %hi(0xcf000000), %o3
a00a6a30:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a6a34:  82 00 40 01  add  %g1, %g1, %g1
a00a6a38:  c2 12 00 01  lduh  [ %o0 + %g1 ], %g1
a00a6a3c:  82 00 40 09  add  %g1, %o1, %g1
a00a6a40:  83 28 60 02  sll  %g1, 2, %g1
a00a6a44:  98 03 20 01  inc  %o4
a00a6a48:  82 10 40 0b  or  %g1, %o3, %g1
a00a6a4c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00a6a50:  d4 20 40 00  st  %o2, [ %g1 ]
a00a6a54:  80 a3 60 01  cmp  %o5, 1
a00a6a58:  08 bf ff f7  bleu  0xa00a6a34
a00a6a5c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00a6a60:  30 80 00 0e  b,a   0xa00a6a98
a00a6a64:  18 80 00 0d  bgu  0xa00a6a98
a00a6a68:  03 28 02 d3  sethi  %hi(0xa00b4c00), %g1
a00a6a6c:  98 02 00 08  add  %o0, %o0, %o4
a00a6a70:  9b 2a 60 10  sll  %o1, 0x10, %o5
a00a6a74:  82 10 61 98  or  %g1, 0x198, %g1
a00a6a78:  9b 33 60 10  srl  %o5, 0x10, %o5
a00a6a7c:  c2 10 40 0c  lduh  [ %g1 + %o4 ], %g1
a00a6a80:  82 00 40 0d  add  %g1, %o5, %g1
a00a6a84:  1b 33 c0 00  sethi  %hi(0xcf000000), %o5
a00a6a88:  83 28 60 02  sll  %g1, 2, %g1
a00a6a8c:  82 10 40 0d  or  %g1, %o5, %g1
a00a6a90:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00a6a94:  da 20 40 00  st  %o5, [ %g1 ]
a00a6a98:  81 c3 e0 08  retl
a00a6a9c:  01 00 00 00  nop
