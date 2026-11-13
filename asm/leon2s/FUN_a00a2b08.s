# leon2s FUN_a00a2b08 0xa00a2b08-0xa00a2b98 (144 bytes)
a00a2b08:  9d e3 bf 98  save  %sp, -104, %sp
a00a2b0c:  a4 10 20 00  clr  %l2
a00a2b10:  82 0c a0 ff  and  %l2, 0xff, %g1
a00a2b14:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a00a2b18:  a0 58 60 34  smul  %g1, 0x34, %l0
a00a2b1c:  a2 13 63 00  or  %o5, 0x300, %l1
a00a2b20:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a00a2b24:  90 10 20 0e  mov  0xe, %o0
a00a2b28:  40 00 12 21  call  0xa00a73ac
a00a2b2c:  92 02 60 b4  add  %o1, 0xb4, %o1
a00a2b30:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a2b34:  80 a0 60 01  cmp  %g1, 1
a00a2b38:  12 80 00 07  bne  0xa00a2b54
a00a2b3c:  90 10 20 0a  mov  0xa, %o0
a00a2b40:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a00a2b44:  40 00 12 1a  call  0xa00a73ac
a00a2b48:  92 02 60 b4  add  %o1, 0xb4, %o1
a00a2b4c:  10 80 00 0d  b  0xa00a2b80
a00a2b50:  a4 04 a0 01  inc  %l2
a00a2b54:  80 a0 60 00  cmp  %g1, 0
a00a2b58:  12 80 00 09  bne  0xa00a2b7c
a00a2b5c:  90 10 20 08  mov  8, %o0
a00a2b60:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a00a2b64:  40 00 12 1c  call  0xa00a73d4
a00a2b68:  92 02 60 b4  add  %o1, 0xb4, %o1
a00a2b6c:  d2 04 40 10  ld  [ %l1 + %l0 ], %o1
a00a2b70:  92 02 60 b4  add  %o1, 0xb4, %o1
a00a2b74:  40 00 12 18  call  0xa00a73d4
a00a2b78:  90 10 20 0a  mov  0xa, %o0
a00a2b7c:  a4 04 a0 01  inc  %l2
a00a2b80:  82 0c a0 ff  and  %l2, 0xff, %g1
a00a2b84:  80 a0 60 01  cmp  %g1, 1
a00a2b88:  08 bf ff e4  bleu  0xa00a2b18
a00a2b8c:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a00a2b90:  81 c7 e0 08  ret
a00a2b94:  91 e8 20 00  restore  %g0, 0, %o0
