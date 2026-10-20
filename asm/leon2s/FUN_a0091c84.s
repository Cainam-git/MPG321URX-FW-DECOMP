# leon2s FUN_a0091c84 0xa0091c84-0xa0091cf4 (112 bytes)
a0091c84:  9d e3 bf 98  save  %sp, -104, %sp
a0091c88:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0091c8c:  92 10 20 00  clr  %o1
a0091c90:  94 10 20 f7  mov  0xf7, %o2
a0091c94:  40 00 58 d1  call  0xa00a7fd8
a0091c98:  90 10 00 18  mov  %i0, %o0
a0091c9c:  83 2e 60 10  sll  %i1, 0x10, %g1
a0091ca0:  83 30 60 10  srl  %g1, 0x10, %g1
a0091ca4:  80 a0 63 ff  cmp  %g1, 0x3ff
a0091ca8:  9a 10 00 19  mov  %i1, %o5
a0091cac:  82 0a 3f f3  and  %o0, -13, %g1
a0091cb0:  92 10 20 00  clr  %o1
a0091cb4:  94 10 20 f6  mov  0xf6, %o2
a0091cb8:  b2 10 20 00  clr  %i1
a0091cbc:  b4 10 20 f7  mov  0xf7, %i2
a0091cc0:  90 10 00 18  mov  %i0, %o0
a0091cc4:  08 80 00 03  bleu  0xa0091cd0
a0091cc8:  96 10 00 0d  mov  %o5, %o3
a0091ccc:  96 10 23 ff  mov  0x3ff, %o3
a0091cd0:  b7 2a e0 10  sll  %o3, 0x10, %i3
a0091cd4:  b7 36 e0 18  srl  %i3, 0x18, %i3
a0091cd8:  b6 10 40 1b  or  %g1, %i3, %i3
a0091cdc:  40 00 58 de  call  0xa00a8054
a0091ce0:  96 0a e0 ff  and  %o3, 0xff, %o3
a0091ce4:  b6 0e e0 ff  and  %i3, 0xff, %i3
a0091ce8:  40 00 58 db  call  0xa00a8054
a0091cec:  81 e8 00 00  restore
a0091cf0:  01 00 00 00  nop
