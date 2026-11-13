# leon2m FUN_a00b3708 0xa00b3708-0xa00b37a4 (156 bytes)
a00b3708:  9d e3 bf 90  save  %sp, -112, %sp
a00b370c:  90 10 20 6f  mov  0x6f, %o0
a00b3710:  40 02 4d 10  call  0xa0146b50
a00b3714:  92 10 20 00  clr  %o1
a00b3718:  90 10 20 02  mov  2, %o0
a00b371c:  40 02 4d 14  call  0xa0146b6c
a00b3720:  92 10 20 00  clr  %o1
a00b3724:  94 10 00 1a  mov  %i2, %o2
a00b3728:  b4 07 bf f0  add  %fp, -16, %i2
a00b372c:  13 00 06 60  sethi  %hi(0x198000), %o1
a00b3730:  92 12 61 d0  or  %o1, 0x1d0, %o1	! 0x1981d0
a00b3734:  94 0a a0 ff  and  %o2, 0xff, %o2
a00b3738:  40 02 90 2f  call  0xa01577f4
a00b373c:  90 10 00 1a  mov  %i2, %o0
a00b3740:  98 10 20 00  clr  %o4
a00b3744:  82 10 20 00  clr  %g1
a00b3748:  96 07 bf f8  add  %fp, -8, %o3
a00b374c:  82 02 c0 01  add  %o3, %g1, %g1
a00b3750:  da 08 7f f8  ldub  [ %g1 + -8 ], %o5
a00b3754:  80 a3 60 00  cmp  %o5, 0
a00b3758:  22 80 00 08  be,a   0xa00b3778
a00b375c:  90 03 3f ff  add  %o4, -1, %o0
a00b3760:  98 03 20 01  inc  %o4
a00b3764:  82 0b 20 ff  and  %o4, 0xff, %g1
a00b3768:  80 a0 60 03  cmp  %g1, 3
a00b376c:  08 bf ff f9  bleu  0xa00b3750
a00b3770:  82 02 c0 01  add  %o3, %g1, %g1
a00b3774:  90 03 3f ff  add  %o4, -1, %o0
a00b3778:  d0 2f bf f0  stb  %o0, [ %fp + -16 ]
a00b377c:  92 0e 20 ff  and  %i0, 0xff, %o1
a00b3780:  94 0e 60 ff  and  %i1, 0xff, %o2
a00b3784:  98 10 00 1a  mov  %i2, %o4
a00b3788:  90 10 20 00  clr  %o0
a00b378c:  96 10 20 03  mov  3, %o3
a00b3790:  7f ff be 85  call  0xa00a31a4
a00b3794:  9a 10 20 00  clr  %o5
a00b3798:  01 00 00 00  nop
a00b379c:  81 c7 e0 08  ret
a00b37a0:  81 e8 00 00  restore
