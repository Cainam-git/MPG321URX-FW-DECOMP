# leon2m FUN_a00bb1c4 0xa00bb1c4-0xa00bb260 (156 bytes)
a00bb1c4:  9d e3 bf 98  save  %sp, -104, %sp
a00bb1c8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bb1cc:  a6 10 60 d0  or  %g1, 0xd0, %l3	! 0xa802d0d0
a00bb1d0:  a4 10 20 00  clr  %l2
a00bb1d4:  b0 10 20 00  clr  %i0
a00bb1d8:  a2 10 20 02  mov  2, %l1
a00bb1dc:  a0 10 20 02  mov  2, %l0
a00bb1e0:  92 10 00 10  mov  %l0, %o1
a00bb1e4:  40 02 65 16  call  0xa015463c
a00bb1e8:  90 10 00 18  mov  %i0, %o0
a00bb1ec:  94 0a 20 ff  and  %o0, 0xff, %o2
a00bb1f0:  a2 04 60 01  inc  %l1
a00bb1f4:  92 10 00 10  mov  %l0, %o1
a00bb1f8:  80 a2 a0 ff  cmp  %o2, 0xff
a00bb1fc:  02 80 00 09  be  0xa00bb220
a00bb200:  90 10 00 18  mov  %i0, %o0
a00bb204:  40 02 65 0e  call  0xa015463c
a00bb208:  01 00 00 00  nop
a00bb20c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00bb210:  d2 0c c0 10  ldub  [ %l3 + %l0 ], %o1
a00bb214:  80 a2 00 09  cmp  %o0, %o1
a00bb218:  12 80 00 07  bne  0xa00bb234
a00bb21c:  80 a4 20 07  cmp  %l0, 7
a00bb220:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00bb224:  80 a4 20 06  cmp  %l0, 6
a00bb228:  08 bf ff ef  bleu  0xa00bb1e4
a00bb22c:  92 10 00 10  mov  %l0, %o1
a00bb230:  80 a4 20 07  cmp  %l0, 7
a00bb234:  02 80 00 08  be  0xa00bb254
a00bb238:  a4 04 a0 01  inc  %l2
a00bb23c:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00bb240:  80 a6 20 82  cmp  %i0, 0x82
a00bb244:  28 bf ff e6  bleu,a   0xa00bb1dc
a00bb248:  a2 10 20 02  mov  2, %l1
a00bb24c:  10 80 00 03  b  0xa00bb258
a00bb250:  90 10 20 ff  mov  0xff, %o0
a00bb254:  90 10 00 18  mov  %i0, %o0
a00bb258:  81 c7 e0 08  ret
a00bb25c:  91 e8 00 08  restore  %g0, %o0, %o0
