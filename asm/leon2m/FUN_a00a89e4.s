# leon2m FUN_a00a89e4 0xa00a89e4-0xa00a8a78 (148 bytes)
a00a89e4:  9d e3 bf 98  save  %sp, -104, %sp
a00a89e8:  90 10 21 11  mov  0x111, %o0
a00a89ec:  40 02 78 59  call  0xa0146b50
a00a89f0:  92 10 20 00  clr  %o1
a00a89f4:  90 10 20 00  clr  %o0
a00a89f8:  40 02 78 5d  call  0xa0146b6c
a00a89fc:  92 10 20 00  clr  %o1
a00a8a00:  a2 10 20 00  clr  %l1
a00a8a04:  a0 10 20 00  clr  %l0
a00a8a08:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a00a8a0c:  25 00 06 41  sethi  %hi(0x190400), %l2
a00a8a10:  95 2c 20 03  sll  %l0, 3, %o2
a00a8a14:  9e 22 80 10  sub  %o2, %l0, %o7
a00a8a18:  99 2b e0 02  sll  %o7, 2, %o4
a00a8a1c:  9a 14 e2 90  or  %l3, 0x290, %o5
a00a8a20:  96 03 00 10  add  %o4, %l0, %o3
a00a8a24:  c2 0b 60 08  ldub  [ %o5 + 8 ], %g1
a00a8a28:  90 02 c0 01  add  %o3, %g1, %o0
a00a8a2c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00a8a30:  93 32 60 10  srl  %o1, 0x10, %o1
a00a8a34:  7f ff eb 84  call  0xa00a3844
a00a8a38:  90 14 a3 48  or  %l2, 0x348, %o0
a00a8a3c:  98 10 00 08  mov  %o0, %o4
a00a8a40:  94 04 00 10  add  %l0, %l0, %o2
a00a8a44:  94 02 a0 06  add  %o2, 6, %o2
a00a8a48:  90 10 20 00  clr  %o0
a00a8a4c:  92 10 20 2a  mov  0x2a, %o1
a00a8a50:  96 10 20 01  mov  1, %o3
a00a8a54:  9a 10 20 00  clr  %o5
a00a8a58:  7f ff e9 d3  call  0xa00a31a4
a00a8a5c:  a2 04 60 01  inc  %l1
a00a8a60:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00a8a64:  80 a4 20 01  cmp  %l0, 1
a00a8a68:  08 bf ff eb  bleu  0xa00a8a14
a00a8a6c:  95 2c 20 03  sll  %l0, 3, %o2
a00a8a70:  81 c7 e0 08  ret
a00a8a74:  81 e8 00 00  restore
