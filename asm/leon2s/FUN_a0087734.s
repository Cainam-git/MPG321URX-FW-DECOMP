# leon2s FUN_a0087734 0xa0087734-0xa0087794 (96 bytes)
a0087734:  9d e3 bf 98  save  %sp, -104, %sp
a0087738:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008773c:  90 10 20 00  clr  %o0
a0087740:  96 10 20 01  mov  1, %o3
a0087744:  92 0e 60 ff  and  %i1, 0xff, %o1
a0087748:  80 a6 20 00  cmp  %i0, 0
a008774c:  12 80 00 05  bne  0xa0087760
a0087750:  b4 0e a0 ff  and  %i2, 0xff, %i2
a0087754:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0087758:  d4 08 61 02  ldub  [ %g1 + 0x102 ], %o2	! 0xa807cd02
a008775c:  30 80 00 08  b,a   0xa008777c
a0087760:  80 a6 00 1a  cmp  %i0, %i2
a0087764:  90 10 00 18  mov  %i0, %o0
a0087768:  92 0e 60 ff  and  %i1, 0xff, %o1
a008776c:  12 80 00 06  bne  0xa0087784
a0087770:  96 10 20 01  mov  1, %o3
a0087774:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0087778:  d4 08 61 2c  ldub  [ %g1 + 0x12c ], %o2	! 0xa807cd2c
a008777c:  40 00 8b 9b  call  0xa00aa5e8
a0087780:  01 00 00 00  nop
a0087784:  b4 0e 60 ff  and  %i1, 0xff, %i2
a0087788:  40 00 80 5d  call  0xa00a78fc
a008778c:  93 e8 20 02  restore  %g0, 2, %o1
a0087790:  01 00 00 00  nop
