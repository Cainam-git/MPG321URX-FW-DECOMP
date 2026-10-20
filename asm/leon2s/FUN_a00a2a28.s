# leon2s FUN_a00a2a28 0xa00a2a28-0xa00a2a80 (88 bytes)
a00a2a28:  9d e3 bf 98  save  %sp, -104, %sp
a00a2a2c:  b0 10 20 00  clr  %i0
a00a2a30:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a2a34:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a2a38:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a00a2a3c:  a0 5c 20 34  smul  %l0, 0x34, %l0
a00a2a40:  a0 04 00 01  add  %l0, %g1, %l0
a00a2a44:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a00a2a48:  92 02 60 34  add  %o1, 0x34, %o1
a00a2a4c:  40 00 12 58  call  0xa00a73ac
a00a2a50:  90 10 20 14  mov  0x14, %o0
a00a2a54:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a00a2a58:  92 02 60 34  add  %o1, 0x34, %o1
a00a2a5c:  40 00 12 54  call  0xa00a73ac
a00a2a60:  90 10 20 15  mov  0x15, %o0
a00a2a64:  b0 06 20 01  inc  %i0
a00a2a68:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a2a6c:  80 a0 60 01  cmp  %g1, 1
a00a2a70:  08 bf ff f1  bleu  0xa00a2a34
a00a2a74:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00a2a78:  81 c7 e0 08  ret
a00a2a7c:  91 e8 20 00  restore  %g0, 0, %o0
