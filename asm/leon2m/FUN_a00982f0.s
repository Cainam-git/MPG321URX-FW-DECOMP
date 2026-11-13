# leon2m FUN_a00982f0 0xa00982f0-0xa0098364 (116 bytes)
a00982f0:  9d e3 bf 98  save  %sp, -104, %sp
a00982f4:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00982f8:  98 10 20 05  mov  5, %o4
a00982fc:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a0098300:  9a 10 20 01  mov  1, %o5
a0098304:  a0 16 22 90  or  %i0, 0x290, %l0
a0098308:  d8 2b e0 8f  stb  %o4, [ %o7 + 0x8f ]
a009830c:  40 00 77 c4  call  0xa00b621c
a0098310:  da 2c 21 a3  stb  %o5, [ %l0 + 0x1a3 ]
a0098314:  d4 0c 20 20  ldub  [ %l0 + 0x20 ], %o2
a0098318:  17 2a 00 97  sethi  %hi(0xa8025c00), %o3
a009831c:  d4 2a e0 55  stb  %o2, [ %o3 + 0x55 ]	! 0xa8025c55
a0098320:  40 02 b0 b7  call  0xa01445fc
a0098324:  90 0a a0 ff  and  %o2, 0xff, %o0
a0098328:  92 0a 20 ff  and  %o0, 0xff, %o1
a009832c:  90 02 60 d4  add  %o1, 0xd4, %o0
a0098330:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0098334:  d0 20 63 ec  st  %o0, [ %g1 + 0x3ec ]	! 0xa802afec
a0098338:  40 02 b0 b1  call  0xa01445fc
a009833c:  d0 0c 20 20  ldub  [ %l0 + 0x20 ], %o0
a0098340:  90 0a 20 ff  and  %o0, 0xff, %o0
a0098344:  40 00 44 c3  call  0xa00a9650
a0098348:  92 10 20 00  clr  %o1
a009834c:  40 02 b0 ac  call  0xa01445fc
a0098350:  d0 0c 20 20  ldub  [ %l0 + 0x20 ], %o0
a0098354:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0098358:  40 00 44 be  call  0xa00a9650
a009835c:  93 e8 20 01  restore  %g0, 1, %o1
a0098360:  01 00 00 00  nop
