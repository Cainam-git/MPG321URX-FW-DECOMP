# leon2s FUN_a00a8694 0xa00a8694-0xa00a8708 (116 bytes)
a00a8694:  9d e3 bf 80  save  %sp, -128, %sp
a00a8698:  c0 27 bf f0  clr  [ %fp + -16 ]
a00a869c:  82 10 20 10  mov  0x10, %g1
a00a86a0:  c2 2f bf f1  stb  %g1, [ %fp + -15 ]
a00a86a4:  82 10 20 40  mov  0x40, %g1
a00a86a8:  c0 27 bf e8  clr  [ %fp + -24 ]
a00a86ac:  a0 07 bf e0  add  %fp, -32, %l0
a00a86b0:  13 28 02 d3  sethi  %hi(0xa00b4c00), %o1
a00a86b4:  c2 2f bf e8  stb  %g1, [ %fp + -24 ]
a00a86b8:  92 12 61 c8  or  %o1, 0x1c8, %o1
a00a86bc:  94 10 20 04  mov  4, %o2
a00a86c0:  40 00 23 c6  call  0xa00b15d8
a00a86c4:  90 10 00 10  mov  %l0, %o0
a00a86c8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a86cc:  90 10 00 18  mov  %i0, %o0
a00a86d0:  92 10 20 00  clr  %o1
a00a86d4:  7f ff ff 8d  call  0xa00a8508
a00a86d8:  94 07 bf f0  add  %fp, -16, %o2
a00a86dc:  90 10 00 18  mov  %i0, %o0
a00a86e0:  94 10 00 10  mov  %l0, %o2
a00a86e4:  7f ff ff 89  call  0xa00a8508
a00a86e8:  92 10 20 01  mov  1, %o1
a00a86ec:  90 10 00 18  mov  %i0, %o0
a00a86f0:  92 10 20 02  mov  2, %o1
a00a86f4:  7f ff ff 85  call  0xa00a8508
a00a86f8:  94 07 bf e8  add  %fp, -24, %o2
a00a86fc:  01 00 00 00  nop
a00a8700:  81 c7 e0 08  ret
a00a8704:  81 e8 00 00  restore
