# leon2m FUN_a009e2cc 0xa009e2cc-0xa009e348 (124 bytes)
a009e2cc:  9d e3 bf 98  save  %sp, -104, %sp
a009e2d0:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a009e2d4:  b4 14 22 90  or  %l0, 0x290, %i2	! 0xa802d290
a009e2d8:  40 00 2c 39  call  0xa00a93bc
a009e2dc:  d0 0e a0 ac  ldub  [ %i2 + 0xac ], %o0
a009e2e0:  c2 0e a0 ac  ldub  [ %i2 + 0xac ], %g1
a009e2e4:  80 a0 60 03  cmp  %g1, 3
a009e2e8:  18 80 00 16  bgu  0xa009e340
a009e2ec:  9a 00 60 01  add  %g1, 1, %o5
a009e2f0:  da 2e a0 ac  stb  %o5, [ %i2 + 0xac ]
a009e2f4:  a0 14 22 90  or  %l0, 0x290, %l0
a009e2f8:  40 00 f1 17  call  0xa00da754
a009e2fc:  d0 0c 20 ac  ldub  [ %l0 + 0xac ], %o0
a009e300:  d0 0c 20 ac  ldub  [ %l0 + 0xac ], %o0
a009e304:  40 00 2c d3  call  0xa00a9650
a009e308:  92 10 20 01  mov  1, %o1
a009e30c:  11 2a 00 97  sethi  %hi(0xa8025c00), %o0
a009e310:  c2 0a 20 55  ldub  [ %o0 + 0x55 ], %g1	! 0xa8025c55
a009e314:  da 0c 20 ac  ldub  [ %l0 + 0xac ], %o5
a009e318:  b2 10 00 01  mov  %g1, %i1
a009e31c:  b0 10 20 01  mov  1, %i0
a009e320:  80 a3 40 01  cmp  %o5, %g1
a009e324:  02 80 00 05  be  0xa009e338
a009e328:  b4 10 20 00  clr  %i2
a009e32c:  b2 10 00 01  mov  %g1, %i1
a009e330:  b0 10 20 01  mov  1, %i0
a009e334:  b4 10 20 01  mov  1, %i2
a009e338:  40 00 27 81  call  0xa00a813c
a009e33c:  81 e8 00 00  restore
a009e340:  10 bf ff ed  b  0xa009e2f4
a009e344:  c0 2e a0 ac  clrb  [ %i2 + 0xac ]
