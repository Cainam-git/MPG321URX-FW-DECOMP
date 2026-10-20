# leon2s DRV_HDMI_IF_Init 0xa00a1758-0xa00a17c4 (108 bytes)
a00a1758:  9d e3 bf 98  save  %sp, -104, %sp
a00a175c:  31 2a 01 f6  sethi  %hi(0xa807d800), %i0
a00a1760:  11 2a 01 f5  sethi  %hi(0xa807d400), %o0
a00a1764:  c2 0e 23 68  ldub  [ %i0 + 0x368 ], %g1
a00a1768:  90 12 23 e0  or  %o0, 0x3e0, %o0
a00a176c:  92 10 20 00  clr  %o1
a00a1770:  80 a0 60 00  cmp  %g1, 0
a00a1774:  02 80 00 08  be  0xa00a1794
a00a1778:  94 10 23 20  mov  0x320, %o2
a00a177c:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a1780:  13 28 02 d3  sethi  %hi(0xa00b4c00), %o1
a00a1784:  92 12 60 20  or  %o1, 0x20, %o1	! 0xa00b4c20
a00a1788:  7f ff 46 2f  call  0xa0073044
a00a178c:  90 12 20 18  or  %o0, 0x18, %o0
a00a1790:  30 80 00 0b  b,a   0xa00a17bc
a00a1794:  40 00 3f 86  call  0xa00b15ac
a00a1798:  01 00 00 00  nop
a00a179c:  7f ff d4 b4  call  0xa0096a6c
a00a17a0:  01 00 00 00  nop
a00a17a4:  40 00 06 26  call  0xa00a303c
a00a17a8:  01 00 00 00  nop
a00a17ac:  7f ff ea 77  call  0xa009c188
a00a17b0:  90 10 20 15  mov  0x15, %o0	! 0x15
a00a17b4:  82 10 20 01  mov  1, %g1
a00a17b8:  c2 2e 23 68  stb  %g1, [ %i0 + 0x368 ]
a00a17bc:  81 c7 e0 08  ret
a00a17c0:  91 e8 20 00  restore  %g0, 0, %o0
