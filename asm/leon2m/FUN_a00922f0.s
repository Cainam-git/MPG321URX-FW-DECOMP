# leon2m FUN_a00922f0 0xa00922f0-0xa0092364 (116 bytes)
a00922f0:  9d e3 bf 98  save  %sp, -104, %sp
a00922f4:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00922f8:  d8 04 23 ec  ld  [ %l0 + 0x3ec ], %o4	! 0xa802afec
a00922fc:  96 03 3f e2  add  %o4, -30, %o3
a0092300:  40 00 5a fa  call  0xa00a8ee8
a0092304:  90 0a e0 ff  and  %o3, 0xff, %o0
a0092308:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2
a009230c:  90 02 bf e2  add  %o2, -30, %o0
a0092310:  90 0a 20 ff  and  %o0, 0xff, %o0
a0092314:  40 00 5f 42  call  0xa00aa01c
a0092318:  92 10 20 00  clr  %o1
a009231c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a0092320:  40 02 c8 b7  call  0xa01445fc
a0092324:  d0 0a 62 ae  ldub  [ %o1 + 0x2ae ], %o0	! 0xa802d2ae
a0092328:  90 0a 20 ff  and  %o0, 0xff, %o0
a009232c:  40 00 5b 38  call  0xa00a900c
a0092330:  92 10 20 00  clr  %o1
a0092334:  82 10 20 06  mov  6, %g1
a0092338:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a009233c:  90 10 20 04  mov  4, %o0
a0092340:  40 00 87 81  call  0xa00b4144
a0092344:  92 10 20 01  mov  1, %o1
a0092348:  90 10 20 01  mov  1, %o0
a009234c:  40 00 5c 47  call  0xa00a9468
a0092350:  92 10 20 02  mov  2, %o1
a0092354:  b0 10 20 00  clr  %i0
a0092358:  40 00 84 5f  call  0xa00b34d4
a009235c:  93 e8 20 01  restore  %g0, 1, %o1
a0092360:  01 00 00 00  nop
