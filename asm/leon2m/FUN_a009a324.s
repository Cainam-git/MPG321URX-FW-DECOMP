# leon2m FUN_a009a324 0xa009a324-0xa009a37c (88 bytes)
a009a324:  9d e3 bf 98  save  %sp, -104, %sp
a009a328:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a009a32c:  40 00 3c 24  call  0xa00a93bc
a009a330:  d0 0b 20 70  ldub  [ %o4 + 0x70 ], %o0	! 0xa802d470
a009a334:  90 10 20 34  mov  0x34, %o0
a009a338:  40 00 54 45  call  0xa00af44c
a009a33c:  92 10 20 03  mov  3, %o1
a009a340:  96 10 20 bd  mov  0xbd, %o3
a009a344:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a009a348:  90 10 20 02  mov  2, %o0
a009a34c:  d6 22 a3 ec  st  %o3, [ %o2 + 0x3ec ]
a009a350:  40 00 3c c0  call  0xa00a9650
a009a354:  92 10 20 01  mov  1, %o1
a009a358:  13 2a 00 97  sethi  %hi(0xa8025c00), %o1
a009a35c:  40 01 01 f1  call  0xa00dab20
a009a360:  c0 2a 60 55  clrb  [ %o1 + 0x55 ]	! 0xa8025c55
a009a364:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a009a368:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a009a36c:  82 12 20 02  or  %o0, 2, %g1
a009a370:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a009a374:  81 c7 e0 08  ret
a009a378:  81 e8 00 00  restore
