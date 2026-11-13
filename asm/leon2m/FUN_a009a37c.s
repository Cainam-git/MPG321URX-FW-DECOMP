# leon2m FUN_a009a37c 0xa009a37c-0xa009a3cc (80 bytes)
a009a37c:  9d e3 bf 98  save  %sp, -104, %sp
a009a380:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a009a384:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a009a388:  40 00 3c 0d  call  0xa00a93bc
a009a38c:  d0 0c 21 e0  ldub  [ %l0 + 0x1e0 ], %o0
a009a390:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a009a394:  d0 0c 60 55  ldub  [ %l1 + 0x55 ], %o0	! 0xa8025c55
a009a398:  d0 2c 21 e0  stb  %o0, [ %l0 + 0x1e0 ]
a009a39c:  90 10 20 34  mov  0x34, %o0
a009a3a0:  40 00 54 2b  call  0xa00af44c
a009a3a4:  92 10 20 03  mov  3, %o1
a009a3a8:  9a 10 20 bd  mov  0xbd, %o5
a009a3ac:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a009a3b0:  da 20 63 ec  st  %o5, [ %g1 + 0x3ec ]	! 0xa802afec
a009a3b4:  90 10 20 02  mov  2, %o0
a009a3b8:  40 00 3c a6  call  0xa00a9650
a009a3bc:  92 10 20 01  mov  1, %o1
a009a3c0:  c0 2c 60 55  clrb  [ %l1 + 0x55 ]
a009a3c4:  81 c7 e0 08  ret
a009a3c8:  81 e8 00 00  restore
