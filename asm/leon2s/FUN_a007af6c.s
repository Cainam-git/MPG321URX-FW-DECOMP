# leon2s FUN_a007af6c 0xa007af6c-0xa007afdc (112 bytes)
a007af6c:  9d e3 bf 98  save  %sp, -104, %sp
a007af70:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007af74:  7f ff e1 6b  call  0xa0073520
a007af78:  90 10 00 18  mov  %i0, %o0
a007af7c:  80 8a 20 ff  btst  0xff, %o0
a007af80:  82 1e 20 02  xor  %i0, 2, %g1
a007af84:  92 10 22 e1  mov  0x2e1, %o1
a007af88:  02 80 00 0e  be  0xa007afc0
a007af8c:  90 10 00 18  mov  %i0, %o0
a007af90:  80 a0 00 01  cmp  %g0, %g1
a007af94:  82 40 20 00  addx  %g0, 0, %g1
a007af98:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a007af9c:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a007afa0:  82 58 60 34  smul  %g1, 0x34, %g1
a007afa4:  82 00 40 0d  add  %g1, %o5, %g1
a007afa8:  d2 00 60 0c  ld  [ %g1 + 0xc ], %o1
a007afac:  92 02 60 60  add  %o1, 0x60, %o1
a007afb0:  40 00 b1 16  call  0xa00a7408
a007afb4:  90 10 20 09  mov  9, %o0
a007afb8:  10 80 00 06  b  0xa007afd0
a007afbc:  80 a0 00 08  cmp  %g0, %o0
a007afc0:  40 00 ad 6f  call  0xa00a657c
a007afc4:  01 00 00 00  nop
a007afc8:  90 0a 20 02  and  %o0, 2, %o0
a007afcc:  80 a0 00 08  cmp  %g0, %o0
a007afd0:  b0 40 20 00  addx  %g0, 0, %i0
a007afd4:  81 c7 e0 08  ret
a007afd8:  81 e8 00 00  restore
