# leon2s FUN_a007ae94 0xa007ae94-0xa007af04 (112 bytes)
a007ae94:  9d e3 bf 98  save  %sp, -104, %sp
a007ae98:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007ae9c:  7f ff e1 a1  call  0xa0073520
a007aea0:  90 10 00 18  mov  %i0, %o0
a007aea4:  80 8a 20 ff  btst  0xff, %o0
a007aea8:  82 1e 20 02  xor  %i0, 2, %g1
a007aeac:  92 10 22 f6  mov  0x2f6, %o1
a007aeb0:  02 80 00 0e  be  0xa007aee8
a007aeb4:  90 10 00 18  mov  %i0, %o0
a007aeb8:  80 a0 00 01  cmp  %g0, %g1
a007aebc:  82 40 20 00  addx  %g0, 0, %g1
a007aec0:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a007aec4:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a007aec8:  82 58 60 34  smul  %g1, 0x34, %g1
a007aecc:  82 00 40 0d  add  %g1, %o5, %g1
a007aed0:  d2 00 60 0c  ld  [ %g1 + 0xc ], %o1
a007aed4:  92 02 60 74  add  %o1, 0x74, %o1
a007aed8:  40 00 b1 4c  call  0xa00a7408
a007aedc:  90 10 20 12  mov  0x12, %o0
a007aee0:  10 80 00 06  b  0xa007aef8
a007aee4:  80 a0 00 08  cmp  %g0, %o0
a007aee8:  40 00 ad a5  call  0xa00a657c
a007aeec:  01 00 00 00  nop
a007aef0:  90 0a 20 04  and  %o0, 4, %o0
a007aef4:  80 a0 00 08  cmp  %g0, %o0
a007aef8:  b0 40 20 00  addx  %g0, 0, %i0
a007aefc:  81 c7 e0 08  ret
a007af00:  81 e8 00 00  restore
