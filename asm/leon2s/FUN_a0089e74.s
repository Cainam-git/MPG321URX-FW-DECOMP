# leon2s FUN_a0089e74 0xa0089e74-0xa0089f00 (140 bytes)
a0089e74:  9d e3 bf 98  save  %sp, -104, %sp
a0089e78:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a0089e7c:  82 10 61 40  or  %g1, 0x140, %g1	! 0xcf03c940
a0089e80:  c2 00 40 00  ld  [ %g1 ], %g1
a0089e84:  80 88 60 02  btst  2, %g1
a0089e88:  02 80 00 0f  be  0xa0089ec4
a0089e8c:  b0 10 20 01  mov  1, %i0
a0089e90:  90 0e 20 ff  and  %i0, 0xff, %o0
a0089e94:  92 10 20 7d  mov  0x7d, %o1
a0089e98:  94 10 20 10  mov  0x10, %o2
a0089e9c:  96 10 20 01  mov  1, %o3
a0089ea0:  40 00 76 a8  call  0xa00a7940
a0089ea4:  b0 06 20 01  inc  %i0
a0089ea8:  b2 0e 20 ff  and  %i0, 0xff, %i1
a0089eac:  80 a6 60 04  cmp  %i1, 4
a0089eb0:  08 bf ff f9  bleu  0xa0089e94
a0089eb4:  90 0e 20 ff  and  %i0, 0xff, %o0
a0089eb8:  31 28 01 a3  sethi  %hi(0xa0068c00), %i0
a0089ebc:  10 80 00 0e  b  0xa0089ef4
a0089ec0:  b0 16 20 60  or  %i0, 0x60, %i0	! 0xa0068c60
a0089ec4:  90 0e 20 ff  and  %i0, 0xff, %o0
a0089ec8:  92 10 20 7d  mov  0x7d, %o1
a0089ecc:  94 10 20 10  mov  0x10, %o2
a0089ed0:  96 10 20 00  clr  %o3
a0089ed4:  40 00 76 9b  call  0xa00a7940
a0089ed8:  b0 06 20 01  inc  %i0
a0089edc:  b2 0e 20 ff  and  %i0, 0xff, %i1
a0089ee0:  80 a6 60 04  cmp  %i1, 4
a0089ee4:  08 bf ff f9  bleu  0xa0089ec8
a0089ee8:  90 0e 20 ff  and  %i0, 0xff, %o0
a0089eec:  31 28 01 a3  sethi  %hi(0xa0068c00), %i0
a0089ef0:  b0 16 20 90  or  %i0, 0x90, %i0	! 0xa0068c90
a0089ef4:  7f ff a4 54  call  0xa0073044
a0089ef8:  81 e8 00 00  restore
a0089efc:  01 00 00 00  nop
