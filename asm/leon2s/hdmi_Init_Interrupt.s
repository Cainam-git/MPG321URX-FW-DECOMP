# leon2s hdmi_Init_Interrupt 0xa00a2fd4-0xa00a303c (104 bytes)
a00a2fd4:  9d e3 bf 98  save  %sp, -104, %sp
a00a2fd8:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a2fdc:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a00a2fe0:  80 88 60 01  btst  1, %g1
a00a2fe4:  02 80 00 06  be  0xa00a2ffc
a00a2fe8:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a2fec:  13 28 02 d3  sethi  %hi(0xa00b4c00), %o1
a00a2ff0:  90 12 20 80  or  %o0, 0x80, %o0
a00a2ff4:  7f ff 40 14  call  0xa0073044
a00a2ff8:  92 12 60 50  or  %o1, 0x50, %o1
a00a2ffc:  7f ff f5 46  call  0xa00a0514
a00a3000:  b0 10 20 00  clr  %i0
a00a3004:  7f ff ff 91  call  0xa00a2e48
a00a3008:  90 0e 20 ff  and  %i0, 0xff, %o0
a00a300c:  b0 06 20 01  inc  %i0
a00a3010:  82 0e 20 ff  and  %i0, 0xff, %g1
a00a3014:  80 a0 60 01  cmp  %g1, 1
a00a3018:  08 bf ff fb  bleu  0xa00a3004
a00a301c:  01 00 00 00  nop
a00a3020:  40 00 3a 58  call  0xa00b1980
a00a3024:  b0 10 20 00  clr  %i0	! 0x0
a00a3028:  40 00 3a 89  call  0xa00b1a4c
a00a302c:  01 00 00 00  nop
a00a3030:  01 00 00 00  nop
a00a3034:  81 c7 e0 08  ret
a00a3038:  81 e8 00 00  restore
