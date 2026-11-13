# leon2s FUN_a00a28d8 0xa00a28d8-0xa00a2928 (80 bytes)
a00a28d8:  9d e3 bf 98  save  %sp, -104, %sp
a00a28dc:  7f ff 03 fc  call  0xa00638cc
a00a28e0:  b0 10 20 00  clr  %i0
a00a28e4:  90 10 20 00  clr  %o0
a00a28e8:  92 10 29 c8  mov  0x9c8, %o1
a00a28ec:  40 00 10 44  call  0xa00a69fc
a00a28f0:  94 10 20 01  mov  1, %o2
a00a28f4:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a28f8:  c2 08 63 e1  ldub  [ %g1 + 0x3e1 ], %g1	! 0xa807d7e1
a00a28fc:  90 10 20 00  clr  %o0
a00a2900:  80 a0 60 00  cmp  %g1, 0
a00a2904:  02 80 00 04  be  0xa00a2914
a00a2908:  b2 10 20 00  clr  %i1
a00a290c:  7f ff f8 de  call  0xa00a0c84
a00a2910:  81 e8 00 00  restore
a00a2914:  7f ff f8 ba  call  0xa00a0bfc
a00a2918:  b0 10 20 00  clr  %i0
a00a291c:  7f ff f8 7d  call  0xa00a0b10
a00a2920:  93 e8 20 00  restore  %g0, 0, %o1
a00a2924:  01 00 00 00  nop
