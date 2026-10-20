# leon2s FUN_a00c972c 0xa00c972c-0xa00c9750 (36 bytes)
a00c972c:  03 33 c0 63  sethi  %hi(0xcf018c00), %g1
a00c9730:  82 10 61 00  or  %g1, 0x100, %g1	! 0xcf018d00
a00c9734:  c2 00 40 00  ld  [ %g1 ], %g1
a00c9738:  80 88 60 02  btst  2, %g1
a00c973c:  02 80 00 03  be  0xa00c9748
a00c9740:  90 10 20 00  clr  %o0
a00c9744:  90 10 20 01  mov  1, %o0
a00c9748:  81 c3 e0 08  retl
a00c974c:  90 0a 20 01  and  %o0, 1, %o0
