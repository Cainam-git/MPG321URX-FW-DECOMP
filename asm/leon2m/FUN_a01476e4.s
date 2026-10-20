# leon2m FUN_a01476e4 0xa01476e4-0xa014771c (56 bytes)
a01476e4:  9d e3 bf 98  save  %sp, -104, %sp
a01476e8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01476ec:  99 2e 20 04  sll  %i0, 4, %o4
a01476f0:  96 23 00 18  sub  %o4, %i0, %o3
a01476f4:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a01476f8:  9b 2a e0 03  sll  %o3, 3, %o5
a01476fc:  82 12 a3 30  or  %o2, 0x330, %g1
a0147700:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a0147704:  91 32 60 0c  srl  %o1, 0xc, %o0
a0147708:  7f fe c6 0b  call  0xa00f8f34
a014770c:  90 0a 20 0f  and  %o0, 0xf, %o0
a0147710:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0147714:  81 c7 e0 08  ret
a0147718:  81 e8 00 00  restore
