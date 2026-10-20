# leon2s FUN_a007d054 0xa007d054-0xa007d140 (236 bytes)
a007d054:  9d e3 bf 98  save  %sp, -104, %sp
a007d058:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007d05c:  82 06 00 18  add  %i0, %i0, %g1
a007d060:  82 00 40 18  add  %g1, %i0, %g1
a007d064:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a007d068:  83 28 60 03  sll  %g1, 3, %g1
a007d06c:  9a 13 60 64  or  %o5, 0x64, %o5
a007d070:  82 00 40 0d  add  %g1, %o5, %g1
a007d074:  c2 08 60 07  ldub  [ %g1 + 7 ], %g1
a007d078:  80 a0 60 01  cmp  %g1, 1
a007d07c:  90 10 00 18  mov  %i0, %o0
a007d080:  02 80 00 2e  be  0xa007d138
a007d084:  82 10 20 00  clr  %g1
a007d088:  7f ff e0 3d  call  0xa007517c
a007d08c:  01 00 00 00  nop
a007d090:  80 8a 20 ff  btst  0xff, %o0
a007d094:  02 80 00 09  be  0xa007d0b8
a007d098:  82 10 20 01  mov  1, %g1
a007d09c:  80 a6 20 02  cmp  %i0, 2
a007d0a0:  02 80 00 26  be  0xa007d138
a007d0a4:  90 10 00 18  mov  %i0, %o0
a007d0a8:  7f ff ff d1  call  0xa007cfec
a007d0ac:  01 00 00 00  nop
a007d0b0:  10 80 00 22  b  0xa007d138
a007d0b4:  82 0a 20 ff  and  %o0, 0xff, %g1
a007d0b8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a007d0bc:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa8078980
a007d0c0:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a007d0c4:  80 a0 60 01  cmp  %g1, 1
a007d0c8:  12 80 00 06  bne  0xa007d0e0
a007d0cc:  90 10 00 18  mov  %i0, %o0
a007d0d0:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a007d0d4:  82 10 61 98  or  %g1, 0x198, %g1	! 0xa8076198
a007d0d8:  10 80 00 18  b  0xa007d138
a007d0dc:  c2 08 40 18  ldub  [ %g1 + %i0 ], %g1
a007d0e0:  7f ff d9 10  call  0xa0073520
a007d0e4:  01 00 00 00  nop
a007d0e8:  80 8a 20 ff  btst  0xff, %o0
a007d0ec:  82 1e 20 02  xor  %i0, 2, %g1
a007d0f0:  92 10 22 e1  mov  0x2e1, %o1
a007d0f4:  02 80 00 0e  be  0xa007d12c
a007d0f8:  90 10 20 08  mov  8, %o0
a007d0fc:  80 a0 00 01  cmp  %g0, %g1
a007d100:  82 40 20 00  addx  %g0, 0, %g1
a007d104:  1b 2a 01 f6  sethi  %hi(0xa807d800), %o5
a007d108:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xa807db00
a007d10c:  82 58 60 34  smul  %g1, 0x34, %g1
a007d110:  82 00 40 0d  add  %g1, %o5, %g1
a007d114:  d2 00 60 0c  ld  [ %g1 + 0xc ], %o1
a007d118:  40 00 a8 bc  call  0xa00a7408
a007d11c:  92 02 60 60  add  %o1, 0x60, %o1
a007d120:  80 a0 00 08  cmp  %g0, %o0
a007d124:  10 80 00 05  b  0xa007d138
a007d128:  82 40 20 00  addx  %g0, 0, %g1
a007d12c:  40 00 a5 14  call  0xa00a657c
a007d130:  90 10 00 18  mov  %i0, %o0
a007d134:  82 0a 20 01  and  %o0, 1, %g1
a007d138:  81 c7 e0 08  ret
a007d13c:  91 e8 00 01  restore  %g0, %g1, %o0
