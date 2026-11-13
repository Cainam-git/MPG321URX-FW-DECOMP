# leon2s DRV_HDMI_Set_AudStatus 0xa009c7e8-0xa009c87c (148 bytes)
a009c7e8:  9d e3 bf 98  save  %sp, -104, %sp
a009c7ec:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a009c7f0:  92 06 20 41  add  %i0, 0x41, %o1
a009c7f4:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1
a009c7f8:  93 2a 60 18  sll  %o1, 0x18, %o1
a009c7fc:  b2 0e 60 ff  and  %i1, 0xff, %i1
a009c800:  15 28 02 d1  sethi  %hi(0xa00b4400), %o2
a009c804:  11 28 01 a9  sethi  %hi(0xa006a400), %o0
a009c808:  80 88 60 04  btst  4, %g1
a009c80c:  93 3a 60 18  sra  %o1, 0x18, %o1
a009c810:  94 12 a0 c8  or  %o2, 0xc8, %o2
a009c814:  90 12 22 d8  or  %o0, 0x2d8, %o0
a009c818:  02 80 00 04  be  0xa009c828
a009c81c:  96 10 00 19  mov  %i1, %o3
a009c820:  7f ff 5a 09  call  0xa0073044
a009c824:  01 00 00 00  nop
a009c828:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009c82c:  98 0e 20 ff  and  %i0, 0xff, %o4
a009c830:  9a 10 63 e0  or  %g1, 0x3e0, %o5
a009c834:  96 5b 21 90  smul  %o4, 0x190, %o3
a009c838:  92 03 60 38  add  %o5, 0x38, %o1
a009c83c:  80 a6 60 01  cmp  %i1, 1
a009c840:  90 10 00 0c  mov  %o4, %o0
a009c844:  9a 02 c0 0d  add  %o3, %o5, %o5
a009c848:  12 80 00 06  bne  0xa009c860
a009c84c:  92 02 c0 09  add  %o3, %o1, %o1
a009c850:  7f ff ff b2  call  0xa009c718
a009c854:  f2 2b 60 05  stb  %i1, [ %o5 + 5 ]
a009c858:  10 80 00 04  b  0xa009c868
a009c85c:  80 a0 00 19  cmp  %g0, %i1
a009c860:  c0 2b 60 05  clrb  [ %o5 + 5 ]
a009c864:  80 a0 00 19  cmp  %g0, %i1
a009c868:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009c86c:  b2 60 3f ff  subx  %g0, -1, %i1
a009c870:  7f ff ff c9  call  0xa009c794
a009c874:  81 e8 00 00  restore
a009c878:  01 00 00 00  nop
