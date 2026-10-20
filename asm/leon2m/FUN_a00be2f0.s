# leon2m FUN_a00be2f0 0xa00be2f0-0xa00be340 (80 bytes)
a00be2f0:  9d e3 bf 98  save  %sp, -104, %sp
a00be2f4:  1f 2a 00 b5  sethi  %hi(0xa802d400), %o7
a00be2f8:  d6 03 e0 04  ld  [ %o7 + 4 ], %o3	! 0xa802d404
a00be2fc:  95 32 e0 0f  srl  %o3, 0xf, %o2
a00be300:  90 0a a0 01  and  %o2, 1, %o0
a00be304:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be308:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be30c:  82 02 20 30  add  %o0, 0x30, %g1
a00be310:  98 10 20 30  mov  0x30, %o4
a00be314:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00be318:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00be31c:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00be320:  7f ff f2 47  call  0xa00bac3c
a00be324:  90 10 20 6c  mov  0x6c, %o0
a00be328:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be32c:  7f ff f1 89  call  0xa00ba950
a00be330:  90 10 00 18  mov  %i0, %o0
a00be334:  7f ff f2 2c  call  0xa00babe4
a00be338:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be33c:  01 00 00 00  nop
