# leon2s DRV_HDMI21_ReStart_AEQ2 0xa007fde0-0xa007fffc (540 bytes)  [FUN_a007fff4 = unreachable ret/restore tail, merged]
a007fde0:  9d e3 bf 98  save  %sp, -104, %sp
a007fde4:  a0 0e 20 ff  and  %i0, 0xff, %l0
a007fde8:  80 a4 20 02  cmp  %l0, 2
a007fdec:  02 80 00 05  be  0xa007fe00
a007fdf0:  a2 10 20 00  clr  %l1
a007fdf4:  80 a4 20 03  cmp  %l0, 3
a007fdf8:  12 80 00 7e  bne  0xa007fff0
a007fdfc:  a2 10 20 01  mov  1, %l1
a007fe00:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a007fe04:  c2 00 62 34  ld  [ %g1 + 0x234 ], %g1	! 0xa8078634
a007fe08:  80 88 68 00  btst  0x800, %g1
a007fe0c:  02 80 00 08  be  0xa007fe2c
a007fe10:  a4 0c 60 ff  and  %l1, 0xff, %l2
a007fe14:  11 28 01 9e  sethi  %hi(0xa0067800), %o0
a007fe18:  13 28 02 cf  sethi  %hi(0xa00b3c00), %o1
a007fe1c:  90 12 20 68  or  %o0, 0x68, %o0
a007fe20:  7f ff cc 89  call  0xa0073044
a007fe24:  92 12 63 a0  or  %o1, 0x3a0, %o1
a007fe28:  a4 0c 60 ff  and  %l1, 0xff, %l2
a007fe2c:  27 2a 01 f5  sethi  %hi(0xa807d400), %l3
a007fe30:  82 14 e2 80  or  %l3, 0x280, %g1	! 0xa807d680
a007fe34:  9a 5c a0 b0  smul  %l2, 0xb0, %o5
a007fe38:  9a 03 40 01  add  %o5, %g1, %o5
a007fe3c:  c2 0b 60 34  ldub  [ %o5 + 0x34 ], %g1
a007fe40:  80 a0 60 00  cmp  %g1, 0
a007fe44:  02 80 00 04  be  0xa007fe54
a007fe48:  e2 0b 60 01  ldub  [ %o5 + 1 ], %l1
a007fe4c:  7f ff e8 4d  call  0xa0079f80
a007fe50:  90 10 00 10  mov  %l0, %o0
a007fe54:  90 0e 20 ff  and  %i0, 0xff, %o0
a007fe58:  92 10 20 01  mov  1, %o1
a007fe5c:  7f ff e6 47  call  0xa0079778
a007fe60:  94 10 20 01  mov  1, %o2
a007fe64:  82 04 7f fc  add  %l1, -4, %g1
a007fe68:  82 08 60 ff  and  %g1, 0xff, %g1
a007fe6c:  80 a0 60 02  cmp  %g1, 2
a007fe70:  38 80 00 2f  bgu,a   0xa007ff2c
a007fe74:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007fe78:  b2 0e 60 ff  and  %i1, 0xff, %i1
a007fe7c:  80 a6 60 00  cmp  %i1, 0
a007fe80:  22 80 00 2b  be,a   0xa007ff2c
a007fe84:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007fe88:  a0 10 20 00  clr  %l0
a007fe8c:  9a 0c 20 ff  and  %l0, 0xff, %o5
a007fe90:  83 3e 40 0d  sra  %i1, %o5, %g1
a007fe94:  80 88 60 01  btst  1, %g1
a007fe98:  22 80 00 20  be,a   0xa007ff18
a007fe9c:  a0 04 20 01  inc  %l0
a007fea0:  13 00 00 0d  sethi  %hi(0x3400), %o1
a007fea4:  92 12 62 0c  or  %o1, 0x20c, %o1	! 0x360c
a007fea8:  90 0e 20 ff  and  %i0, 0xff, %o0
a007feac:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007feb0:  80 a3 60 00  cmp  %o5, 0
a007feb4:  02 80 00 17  be  0xa007ff10
a007feb8:  96 10 23 d0  mov  0x3d0, %o3
a007febc:  13 00 00 0d  sethi  %hi(0x3400), %o1
a007fec0:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a007fec4:  90 0e 20 ff  and  %i0, 0xff, %o0
a007fec8:  92 12 62 0c  or  %o1, 0x20c, %o1
a007fecc:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007fed0:  17 00 f4 00  sethi  %hi(0x3d00000), %o3
a007fed4:  80 a3 60 01  cmp  %o5, 1
a007fed8:  02 80 00 0e  be  0xa007ff10
a007fedc:  82 10 00 08  mov  %o0, %g1
a007fee0:  13 00 00 0d  sethi  %hi(0x3400), %o1
a007fee4:  92 12 62 10  or  %o1, 0x210, %o1	! 0x3610
a007fee8:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007feec:  80 a3 60 02  cmp  %o5, 2
a007fef0:  02 80 00 08  be  0xa007ff10
a007fef4:  96 10 23 d0  mov  0x3d0, %o3
a007fef8:  13 00 00 0d  sethi  %hi(0x3400), %o1
a007fefc:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a007ff00:  90 10 00 01  mov  %g1, %o0
a007ff04:  92 12 62 10  or  %o1, 0x210, %o1
a007ff08:  94 12 a3 ff  or  %o2, 0x3ff, %o2
a007ff0c:  17 00 f4 00  sethi  %hi(0x3d00000), %o3
a007ff10:  40 00 9d 5e  call  0xa00a7488
a007ff14:  a0 04 20 01  inc  %l0
a007ff18:  82 0c 20 ff  and  %l0, 0xff, %g1
a007ff1c:  80 a0 60 03  cmp  %g1, 3
a007ff20:  08 bf ff dc  bleu  0xa007fe90
a007ff24:  9a 0c 20 ff  and  %l0, 0xff, %o5
a007ff28:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007ff2c:  94 10 20 01  mov  1, %o2
a007ff30:  90 10 00 18  mov  %i0, %o0
a007ff34:  92 10 20 00  clr  %o1
a007ff38:  7f ff e6 10  call  0xa0079778
a007ff3c:  21 2a 01 f6  sethi  %hi(0xa807d800), %l0
a007ff40:  a0 14 23 00  or  %l0, 0x300, %l0	! 0xa807db00
a007ff44:  a2 5c a0 34  smul  %l2, 0x34, %l1
a007ff48:  d2 04 00 11  ld  [ %l0 + %l1 ], %o1
a007ff4c:  92 02 60 04  add  %o1, 4, %o1
a007ff50:  40 00 9d 17  call  0xa00a73ac
a007ff54:  90 10 20 08  mov  8, %o0
a007ff58:  40 00 c6 0f  call  0xa00b1794
a007ff5c:  90 10 20 01  mov  1, %o0
a007ff60:  d2 04 00 11  ld  [ %l0 + %l1 ], %o1
a007ff64:  92 02 60 04  add  %o1, 4, %o1
a007ff68:  40 00 9d 1b  call  0xa00a73d4
a007ff6c:  90 10 20 08  mov  8, %o0
a007ff70:  9a 14 e2 80  or  %l3, 0x280, %o5
a007ff74:  82 5c a0 b0  smul  %l2, 0xb0, %g1
a007ff78:  82 00 40 0d  add  %g1, %o5, %g1
a007ff7c:  c2 08 60 34  ldub  [ %g1 + 0x34 ], %g1
a007ff80:  80 a0 60 00  cmp  %g1, 0
a007ff84:  02 80 00 1b  be  0xa007fff0
a007ff88:  01 00 00 00  nop
a007ff8c:  7f ff e9 a9  call  0xa007a630
a007ff90:  90 10 00 18  mov  %i0, %o0
a007ff94:  7f ff e9 d7  call  0xa007a6f0
a007ff98:  90 10 00 18  mov  %i0, %o0
a007ff9c:  80 8e a0 ff  btst  0xff, %i2
a007ffa0:  02 80 00 12  be  0xa007ffe8
a007ffa4:  01 00 00 00  nop
a007ffa8:  7f ff e5 7e  call  0xa00795a0
a007ffac:  90 10 00 18  mov  %i0, %o0
a007ffb0:  7f ff e6 bf  call  0xa0079aac
a007ffb4:  90 10 00 18  mov  %i0, %o0
a007ffb8:  7f ff fe 04  call  0xa007f7c8
a007ffbc:  90 10 00 18  mov  %i0, %o0
a007ffc0:  7f ff fe 93  call  0xa007fa0c
a007ffc4:  90 10 00 18  mov  %i0, %o0
a007ffc8:  7f ff e6 4d  call  0xa00798fc
a007ffcc:  90 10 00 18  mov  %i0, %o0
a007ffd0:  40 00 c5 f1  call  0xa00b1794
a007ffd4:  90 10 20 01  mov  1, %o0
a007ffd8:  7f ff e6 78  call  0xa00799b8
a007ffdc:  90 10 00 18  mov  %i0, %o0
a007ffe0:  7f ff e5 70  call  0xa00795a0
a007ffe4:  90 10 00 18  mov  %i0, %o0
a007ffe8:  7f ff fd f8  call  0xa007f7c8
a007ffec:  81 e8 00 00  restore
a007fff0:  01 00 00 00  nop
a007fff4:  81 c7 e0 08  ret
a007fff8:  81 e8 00 00  restore
