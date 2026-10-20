# leon2s FUN_a00c7bf8 0xa00c7bf8-0xa00c7ccc (212 bytes)
a00c7bf8:  9d e3 bf 98  save  %sp, -104, %sp
a00c7bfc:  a4 10 20 00  clr  %l2
a00c7c00:  a2 10 20 00  clr  %l1
a00c7c04:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c7c08:  7f ff ff d6  call  0xa00c7b60
a00c7c0c:  90 10 00 10  mov  %l0, %o0
a00c7c10:  90 10 00 10  mov  %l0, %o0
a00c7c14:  92 10 20 00  clr  %o1
a00c7c18:  40 3b c0 f0  call  0xa0fb7fd8
a00c7c1c:  94 10 20 f2  mov  0xf2, %o2
a00c7c20:  a2 04 60 01  inc  %l1
a00c7c24:  80 8a 20 10  btst  0x10, %o0
a00c7c28:  02 80 00 05  be  0xa00c7c3c
a00c7c2c:  82 0c 60 ff  and  %l1, 0xff, %g1
a00c7c30:  80 a0 60 04  cmp  %g1, 4
a00c7c34:  28 bf ff f5  bleu,a   0xa00c7c08
a00c7c38:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c7c3c:  a2 10 20 00  clr  %l1
a00c7c40:  7f ff ff d4  call  0xa00c7b90
a00c7c44:  90 10 00 10  mov  %l0, %o0
a00c7c48:  90 10 00 10  mov  %l0, %o0
a00c7c4c:  92 10 20 00  clr  %o1
a00c7c50:  40 3b c0 e2  call  0xa0fb7fd8
a00c7c54:  94 10 20 f5  mov  0xf5, %o2
a00c7c58:  a2 04 60 01  inc  %l1
a00c7c5c:  80 8a 20 1f  btst  0x1f, %o0
a00c7c60:  02 80 00 05  be  0xa00c7c74
a00c7c64:  82 0c 60 ff  and  %l1, 0xff, %g1
a00c7c68:  80 a0 60 04  cmp  %g1, 4
a00c7c6c:  08 bf ff f5  bleu  0xa00c7c40
a00c7c70:  01 00 00 00  nop
a00c7c74:  7f ff ff d4  call  0xa00c7bc4
a00c7c78:  90 10 00 10  mov  %l0, %o0
a00c7c7c:  40 3b e6 c6  call  0xa0fc1794
a00c7c80:  90 10 20 01  mov  1, %o0
a00c7c84:  90 10 00 10  mov  %l0, %o0
a00c7c88:  92 10 20 00  clr  %o1
a00c7c8c:  40 3b c0 d3  call  0xa0fb7fd8
a00c7c90:  94 10 20 f2  mov  0xf2, %o2
a00c7c94:  80 8a 20 10  btst  0x10, %o0
a00c7c98:  02 80 00 04  be  0xa00c7ca8
a00c7c9c:  90 10 00 10  mov  %l0, %o0
a00c7ca0:  10 80 00 08  b  0xa00c7cc0
a00c7ca4:  a4 10 20 0e  mov  0xe, %l2
a00c7ca8:  92 10 20 00  clr  %o1
a00c7cac:  40 3b c0 cb  call  0xa0fb7fd8
a00c7cb0:  94 10 20 f5  mov  0xf5, %o2
a00c7cb4:  80 8a 20 1f  btst  0x1f, %o0
a00c7cb8:  32 80 00 02  bne,a   0xa00c7cc0
a00c7cbc:  a4 10 20 0f  mov  0xf, %l2
a00c7cc0:  b0 0c a0 0f  and  %l2, 0xf, %i0
a00c7cc4:  81 c7 e0 08  ret
a00c7cc8:  81 e8 00 00  restore
