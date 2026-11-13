# leon2s DRV_HDMI21_PHY_PICDR_Reset 0xa0080244-0xa00802cc (136 bytes)  [FUN_a00802c4 = its unreachable ret/restore tail, merged]
a0080244:  9d e3 bf 98  save  %sp, -104, %sp
a0080248:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a008024c:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a0080250:  13 28 02 cf  sethi  %hi(0xa00b3c00), %o1
a0080254:  11 28 01 a1  sethi  %hi(0xa0068400), %o0
a0080258:  80 88 68 00  btst  0x800, %g1
a008025c:  92 12 63 d8  or  %o1, 0x3d8, %o1
a0080260:  02 80 00 04  be  0xa0080270
a0080264:  90 12 22 e0  or  %o0, 0x2e0, %o0
a0080268:  7f ff cb 77  call  0xa0073044
a008026c:  01 00 00 00  nop
a0080270:  98 0e 20 ff  and  %i0, 0xff, %o4
a0080274:  80 a3 20 02  cmp  %o4, 2
a0080278:  02 80 00 05  be  0xa008028c
a008027c:  82 10 20 00  clr  %g1
a0080280:  80 a3 20 03  cmp  %o4, 3
a0080284:  12 80 00 0f  bne  0xa00802c0
a0080288:  82 10 20 01  mov  1, %g1
a008028c:  82 08 60 ff  and  %g1, 0xff, %g1
a0080290:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0080294:  82 58 60 b0  smul  %g1, 0xb0, %g1
a0080298:  9a 13 62 80  or  %o5, 0x280, %o5
a008029c:  82 00 40 0d  add  %g1, %o5, %g1
a00802a0:  c2 08 60 02  ldub  [ %g1 + 2 ], %g1
a00802a4:  80 a0 60 03  cmp  %g1, 3
a00802a8:  08 80 00 04  bleu  0xa00802b8
a00802ac:  b0 10 00 0c  mov  %o4, %i0
a00802b0:  7f ff fd c8  call  0xa007f9d0
a00802b4:  81 e8 00 00  restore
a00802b8:  7f ff ea 7a  call  0xa007aca0
a00802bc:  91 e8 00 0c  restore  %g0, %o4, %o0
a00802c0:  01 00 00 00  nop
a00802c4:  81 c7 e0 08  ret
a00802c8:  81 e8 00 00  restore
