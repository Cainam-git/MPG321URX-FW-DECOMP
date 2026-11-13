# leon2s FUN_a0079a20 0xa0079a20-0xa0079aac (140 bytes)
a0079a20:  9d e3 bf 98  save  %sp, -104, %sp
a0079a24:  a2 10 20 00  clr  %l1
a0079a28:  83 2c 60 10  sll  %l1, 0x10, %g1
a0079a2c:  9b 30 60 10  srl  %g1, 0x10, %o5
a0079a30:  82 0e 60 ff  and  %i1, 0xff, %g1
a0079a34:  83 38 40 0d  sra  %g1, %o5, %g1
a0079a38:  80 88 60 01  btst  1, %g1
a0079a3c:  22 80 00 15  be,a   0xa0079a90
a0079a40:  9a 04 60 01  add  %l1, 1, %o5
a0079a44:  a0 03 40 0d  add  %o5, %o5, %l0
a0079a48:  90 10 20 00  clr  %o0
a0079a4c:  92 10 20 07  mov  7, %o1
a0079a50:  80 a3 60 03  cmp  %o5, 3
a0079a54:  18 80 00 0e  bgu  0xa0079a8c
a0079a58:  94 0e 20 ff  and  %i0, 0xff, %o2
a0079a5c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079a60:  82 10 63 18  or  %g1, 0x318, %g1	! 0xa00b3b18
a0079a64:  40 00 b6 70  call  0xa00a7424
a0079a68:  d6 10 40 10  lduh  [ %g1 + %l0 ], %o3
a0079a6c:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a0079a70:  82 10 63 10  or  %g1, 0x310, %g1	! 0xa00b3b10
a0079a74:  15 00 3f ff  sethi  %hi(0xfffc00), %o2
a0079a78:  d2 10 40 10  lduh  [ %g1 + %l0 ], %o1
a0079a7c:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a0079a80:  90 0e 20 ff  and  %i0, 0xff, %o0
a0079a84:  40 00 b6 81  call  0xa00a7488
a0079a88:  17 0e 00 00  sethi  %hi(0x38000000), %o3
a0079a8c:  9a 04 60 01  add  %l1, 1, %o5
a0079a90:  83 2b 60 10  sll  %o5, 0x10, %g1
a0079a94:  83 30 60 10  srl  %g1, 0x10, %g1
a0079a98:  80 a0 60 03  cmp  %g1, 3
a0079a9c:  08 bf ff e3  bleu  0xa0079a28
a0079aa0:  a2 10 00 0d  mov  %o5, %l1
a0079aa4:  81 c7 e0 08  ret
a0079aa8:  81 e8 00 00  restore
