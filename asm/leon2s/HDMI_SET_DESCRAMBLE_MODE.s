# leon2s HDMI_SET_DESCRAMBLE_MODE 0xa007f7c8-0xa007f8a4 (220 bytes)  [FUN_a007f89c = unreachable ret/restore tail, merged]
a007f7c8:  9d e3 bf 98  save  %sp, -104, %sp
a007f7cc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007f7d0:  7f ff ff f2  call  0xa007f798
a007f7d4:  90 10 00 18  mov  %i0, %o0
a007f7d8:  33 2a 01 e1  sethi  %hi(0xa8078400), %i1
a007f7dc:  13 00 00 08  sethi  %hi(0x2000), %o1
a007f7e0:  c2 06 62 34  ld  [ %i1 + 0x234 ], %g1
a007f7e4:  92 12 61 78  or  %o1, 0x178, %o1
a007f7e8:  80 88 68 00  btst  0x800, %g1
a007f7ec:  02 80 00 2b  be  0xa007f898
a007f7f0:  90 10 00 18  mov  %i0, %o0
a007f7f4:  40 00 9e c8  call  0xa00a7314
a007f7f8:  01 00 00 00  nop
a007f7fc:  92 0a 20 0f  and  %o0, 0xf, %o1
a007f800:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007f804:  7f ff ce 10  call  0xa0073044
a007f808:  90 12 21 20  or  %o0, 0x120, %o0	! 0xa0068520
a007f80c:  13 00 00 09  sethi  %hi(0x2400), %o1
a007f810:  c2 06 62 34  ld  [ %i1 + 0x234 ], %g1
a007f814:  92 12 61 78  or  %o1, 0x178, %o1
a007f818:  80 88 68 00  btst  0x800, %g1
a007f81c:  02 80 00 1f  be  0xa007f898
a007f820:  90 10 00 18  mov  %i0, %o0
a007f824:  40 00 9e bc  call  0xa00a7314
a007f828:  01 00 00 00  nop
a007f82c:  92 0a 20 0f  and  %o0, 0xf, %o1
a007f830:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007f834:  7f ff ce 04  call  0xa0073044
a007f838:  90 12 21 48  or  %o0, 0x148, %o0	! 0xa0068548
a007f83c:  13 00 00 0a  sethi  %hi(0x2800), %o1
a007f840:  c2 06 62 34  ld  [ %i1 + 0x234 ], %g1
a007f844:  92 12 61 78  or  %o1, 0x178, %o1
a007f848:  80 88 68 00  btst  0x800, %g1
a007f84c:  02 80 00 13  be  0xa007f898
a007f850:  90 10 00 18  mov  %i0, %o0
a007f854:  40 00 9e b0  call  0xa00a7314
a007f858:  01 00 00 00  nop
a007f85c:  92 0a 20 0f  and  %o0, 0xf, %o1
a007f860:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a007f864:  7f ff cd f8  call  0xa0073044
a007f868:  90 12 21 70  or  %o0, 0x170, %o0	! 0xa0068570
a007f86c:  13 00 00 0c  sethi  %hi(0x3000), %o1
a007f870:  c2 06 62 34  ld  [ %i1 + 0x234 ], %g1
a007f874:  90 10 00 18  mov  %i0, %o0
a007f878:  80 88 68 00  btst  0x800, %g1
a007f87c:  02 80 00 07  be  0xa007f898
a007f880:  92 12 61 78  or  %o1, 0x178, %o1
a007f884:  40 00 9e a4  call  0xa00a7314
a007f888:  31 28 01 a1  sethi  %hi(0xa0068400), %i0
a007f88c:  b2 0a 20 0f  and  %o0, 0xf, %i1
a007f890:  7f ff cd ed  call  0xa0073044
a007f894:  91 ee 21 98  restore  %i0, 0x198, %o0
a007f898:  01 00 00 00  nop
a007f89c:  81 c7 e0 08  ret
a007f8a0:  81 e8 00 00  restore
