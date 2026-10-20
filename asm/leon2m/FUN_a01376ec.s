# leon2m FUN_a01376ec 0xa01376ec-0xa0137724 (56 bytes)
a01376ec:  9d e3 bf 90  save  %sp, -112, %sp
a01376f0:  90 10 20 01  mov  1, %o0
a01376f4:  c0 27 bf f4  clr  [ %fp + -12 ]
a01376f8:  92 10 20 0c  mov  0xc, %o1
a01376fc:  94 07 bf f4  add  %fp, -12, %o2
a0137700:  67 fd 53 74  call  0x4008c4d0
a0137704:  96 10 20 01  mov  1, %o3
a0137708:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013770c:  90 0e 00 01  and  %i0, %g1, %o0
a0137710:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0137714:  80 a0 00 18  cmp  %g0, %i0
a0137718:  b0 40 20 00  addx  %g0, 0, %i0
a013771c:  81 c7 e0 08  ret
a0137720:  81 e8 00 00  restore
