# leon2s FUN_a0089f00 0xa0089f00-0xa0089f84 (132 bytes)
a0089f00:  9d e3 bf 98  save  %sp, -104, %sp
a0089f04:  03 33 c0 f2  sethi  %hi(0xcf03c800), %g1
a0089f08:  82 10 61 40  or  %g1, 0x140, %g1	! 0xcf03c940
a0089f0c:  c2 00 40 00  ld  [ %g1 ], %g1
a0089f10:  80 88 60 04  btst  4, %g1
a0089f14:  02 80 00 0e  be  0xa0089f4c
a0089f18:  b0 10 20 01  mov  1, %i0
a0089f1c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0089f20:  92 10 20 11  mov  0x11, %o1
a0089f24:  94 10 20 1b  mov  0x1b, %o2
a0089f28:  40 00 76 75  call  0xa00a78fc
a0089f2c:  b0 06 20 01  inc  %i0
a0089f30:  b2 0e 20 ff  and  %i0, 0xff, %i1
a0089f34:  80 a6 60 04  cmp  %i1, 4
a0089f38:  08 bf ff fa  bleu  0xa0089f20
a0089f3c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0089f40:  31 28 01 a3  sethi  %hi(0xa0068c00), %i0
a0089f44:  10 80 00 0d  b  0xa0089f78
a0089f48:  b0 16 20 c0  or  %i0, 0xc0, %i0	! 0xa0068cc0
a0089f4c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0089f50:  92 10 20 11  mov  0x11, %o1
a0089f54:  94 10 20 00  clr  %o2
a0089f58:  40 00 76 69  call  0xa00a78fc
a0089f5c:  b0 06 20 01  inc  %i0
a0089f60:  b2 0e 20 ff  and  %i0, 0xff, %i1
a0089f64:  80 a6 60 04  cmp  %i1, 4
a0089f68:  08 bf ff fa  bleu  0xa0089f50
a0089f6c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0089f70:  31 28 01 a3  sethi  %hi(0xa0068c00), %i0
a0089f74:  b0 16 20 f0  or  %i0, 0xf0, %i0	! 0xa0068cf0
a0089f78:  7f ff a4 33  call  0xa0073044
a0089f7c:  81 e8 00 00  restore
a0089f80:  01 00 00 00  nop
