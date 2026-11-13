# leon2m FUN_a00bd244 0xa00bd244-0xa00bd294 (80 bytes)
a00bd244:  9d e3 bf 98  save  %sp, -104, %sp
a00bd248:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bd24c:  d6 03 e3 ac  ld  [ %o7 + 0x3ac ], %o3	! 0xa802d3ac
a00bd250:  95 32 e0 04  srl  %o3, 4, %o2
a00bd254:  90 0a a0 01  and  %o2, 1, %o0
a00bd258:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bd25c:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bd260:  82 02 20 30  add  %o0, 0x30, %g1
a00bd264:  98 10 20 30  mov  0x30, %o4
a00bd268:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bd26c:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00bd270:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00bd274:  7f ff f6 72  call  0xa00bac3c
a00bd278:  90 10 20 24  mov  0x24, %o0
a00bd27c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd280:  7f ff f5 b4  call  0xa00ba950
a00bd284:  90 10 00 18  mov  %i0, %o0
a00bd288:  7f ff f6 57  call  0xa00babe4
a00bd28c:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd290:  01 00 00 00  nop
