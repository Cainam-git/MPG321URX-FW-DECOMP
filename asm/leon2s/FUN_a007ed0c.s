# leon2s FUN_a007ed0c 0xa007ed0c-0xa007ed88 (124 bytes)
a007ed0c:  9d e3 bf 98  save  %sp, -104, %sp
a007ed10:  a0 0e 20 ff  and  %i0, 0xff, %l0
a007ed14:  7f ff d2 03  call  0xa0073520
a007ed18:  90 10 00 10  mov  %l0, %o0
a007ed1c:  b0 10 00 10  mov  %l0, %i0
a007ed20:  9a 10 00 19  mov  %i1, %o5
a007ed24:  b6 0e 60 ff  and  %i1, 0xff, %i3
a007ed28:  a0 1c 20 02  xor  %l0, 2, %l0
a007ed2c:  b4 10 20 02  mov  2, %i2
a007ed30:  80 8a 20 ff  btst  0xff, %o0
a007ed34:  b2 10 22 f6  mov  0x2f6, %i1
a007ed38:  02 80 00 11  be  0xa007ed7c
a007ed3c:  17 2a 01 f6  sethi  %hi(0xa807d800), %o3
a007ed40:  80 a0 00 10  cmp  %g0, %l0
a007ed44:  82 40 20 00  addx  %g0, 0, %g1
a007ed48:  80 8b 60 ff  btst  0xff, %o5
a007ed4c:  98 12 e3 00  or  %o3, 0x300, %o4
a007ed50:  9a 58 60 34  smul  %g1, 0x34, %o5
a007ed54:  b0 10 20 11  mov  0x11, %i0
a007ed58:  02 80 00 05  be  0xa007ed6c
a007ed5c:  9a 03 40 0c  add  %o5, %o4, %o5
a007ed60:  f2 03 60 0c  ld  [ %o5 + 0xc ], %i1
a007ed64:  40 00 a1 92  call  0xa00a73ac
a007ed68:  93 ee 60 74  restore  %i1, 0x74, %o1
a007ed6c:  f2 03 60 0c  ld  [ %o5 + 0xc ], %i1
a007ed70:  b2 06 60 74  add  %i1, 0x74, %i1
a007ed74:  40 00 a1 98  call  0xa00a73d4
a007ed78:  91 e8 20 11  restore  %g0, 0x11, %o0
a007ed7c:  40 00 9e 8f  call  0xa00a67b8
a007ed80:  81 e8 00 00  restore
a007ed84:  01 00 00 00  nop
