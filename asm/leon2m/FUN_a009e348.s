# leon2m FUN_a009e348 0xa009e348-0xa009e3c8 (128 bytes)
a009e348:  9d e3 bf 98  save  %sp, -104, %sp
a009e34c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009e350:  b4 14 22 90  or  %l0, 0x290, %i2	! 0xa802d290
a009e354:  40 00 2c 1a  call  0xa00a93bc
a009e358:  d0 0e a0 ac  ldub  [ %i2 + 0xac ], %o0
a009e35c:  c2 0e a0 ac  ldub  [ %i2 + 0xac ], %g1
a009e360:  80 a0 60 00  cmp  %g1, 0
a009e364:  02 80 00 16  be  0xa009e3bc
a009e368:  9a 00 7f ff  add  %g1, -1, %o5
a009e36c:  da 2e a0 ac  stb  %o5, [ %i2 + 0xac ]
a009e370:  a0 14 22 90  or  %l0, 0x290, %l0
a009e374:  40 00 f0 f8  call  0xa00da754
a009e378:  d0 0c 20 ac  ldub  [ %l0 + 0xac ], %o0
a009e37c:  92 10 20 01  mov  1, %o1
a009e380:  40 00 2c b4  call  0xa00a9650
a009e384:  d0 0c 20 ac  ldub  [ %l0 + 0xac ], %o0
a009e388:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a009e38c:  c2 0a 60 55  ldub  [ %o1 + 0x55 ], %g1	! 0xa8025c55
a009e390:  da 0c 20 ac  ldub  [ %l0 + 0xac ], %o5
a009e394:  b2 10 00 01  mov  %g1, %i1
a009e398:  b0 10 20 01  mov  1, %i0
a009e39c:  80 a3 40 01  cmp  %o5, %g1
a009e3a0:  02 80 00 05  be  0xa009e3b4
a009e3a4:  b4 10 20 00  clr  %i2
a009e3a8:  b2 10 00 01  mov  %g1, %i1
a009e3ac:  b0 10 20 01  mov  1, %i0
a009e3b0:  b4 10 20 01  mov  1, %i2
a009e3b4:  40 00 27 62  call  0xa00a813c
a009e3b8:  81 e8 00 00  restore
a009e3bc:  90 10 20 04  mov  4, %o0
a009e3c0:  10 bf ff ec  b  0xa009e370
a009e3c4:  d0 2e a0 ac  stb  %o0, [ %i2 + 0xac ]
