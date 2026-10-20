# leon2s DRV_HDMI_IF_Enable_RxPort 0xa00a16cc-0xa00a1710 (68 bytes)
a00a16cc:  9d e3 bf 98  save  %sp, -104, %sp
a00a16d0:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a16d4:  13 28 02 d3  sethi  %hi(0xa00b4c00), %o1
a00a16d8:  90 12 20 00  mov  %o0, %o0
a00a16dc:  92 12 60 00  mov  %o1, %o1
a00a16e0:  80 a6 20 02  cmp  %i0, 2
a00a16e4:  12 80 00 05  bne  0xa00a16f8
a00a16e8:  94 10 20 43  mov  0x43, %o2
a00a16ec:  7f ff 46 56  call  0xa0073044
a00a16f0:  b0 10 20 16  mov  0x16, %i0
a00a16f4:  30 80 00 05  b,a   0xa00a1708
a00a16f8:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a16fc:  40 00 05 66  call  0xa00a2c94
a00a1700:  92 0e 60 ff  and  %i1, 0xff, %o1
a00a1704:  b0 10 20 00  clr  %i0
a00a1708:  81 c7 e0 08  ret
a00a170c:  81 e8 00 00  restore
