# leon2s FUN_a00ab690 0xa00ab690-0xa00ab6e0 (80 bytes)
a00ab690:  9d e3 bf 98  save  %sp, -104, %sp
a00ab694:  90 0e 20 ff  and  %i0, 0xff, %o0
a00ab698:  7f ff ed 48  call  0xa00a6bb8
a00ab69c:  92 10 22 1c  mov  0x21c, %o1
a00ab6a0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ab6a4:  80 a2 20 06  cmp  %o0, 6
a00ab6a8:  02 80 00 0c  be  0xa00ab6d8
a00ab6ac:  b0 10 20 00  clr  %i0
a00ab6b0:  80 a2 20 0a  cmp  %o0, 0xa
a00ab6b4:  02 80 00 09  be  0xa00ab6d8
a00ab6b8:  b0 10 20 01  mov  1, %i0
a00ab6bc:  82 1a 20 1e  xor  %o0, 0x1e, %g1
a00ab6c0:  80 a2 20 14  cmp  %o0, 0x14
a00ab6c4:  02 80 00 05  be  0xa00ab6d8
a00ab6c8:  b0 10 20 02  mov  2, %i0
a00ab6cc:  80 a0 00 01  cmp  %g0, %g1
a00ab6d0:  82 40 20 00  addx  %g0, 0, %g1
a00ab6d4:  b0 00 60 03  add  %g1, 3, %i0
a00ab6d8:  81 c7 e0 08  ret
a00ab6dc:  81 e8 00 00  restore
