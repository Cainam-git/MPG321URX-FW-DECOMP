# leon2m FUN_a009934c 0xa009934c-0xa00993a8 (92 bytes)
a009934c:  9d e3 bf 98  save  %sp, -104, %sp
a0099350:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a0099354:  98 13 22 90  or  %o4, 0x290, %o4	! 0xa802d290
a0099358:  da 03 21 ec  ld  [ %o4 + 0x1ec ], %o5
a009935c:  93 33 60 07  srl  %o5, 7, %o1
a0099360:  90 38 00 09  xnor  %g0, %o1, %o0
a0099364:  82 0a 20 01  and  %o0, 1, %g1
a0099368:  9f 28 60 07  sll  %g1, 7, %o7
a009936c:  96 0b 7f 7f  and  %o5, -129, %o3
a0099370:  94 12 c0 0f  or  %o3, %o7, %o2
a0099374:  93 32 a0 07  srl  %o2, 7, %o1
a0099378:  d4 23 21 ec  st  %o2, [ %o4 + 0x1ec ]
a009937c:  92 0a 60 01  and  %o1, 1, %o1
a0099380:  40 00 30 28  call  0xa00a5420
a0099384:  90 10 20 00  clr  %o0
a0099388:  40 01 07 69  call  0xa00db12c
a009938c:  90 10 20 00  clr  %o0
a0099390:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0099394:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0099398:  82 12 20 02  or  %o0, 2, %g1
a009939c:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a00993a0:  81 c7 e0 08  ret
a00993a4:  81 e8 00 00  restore
