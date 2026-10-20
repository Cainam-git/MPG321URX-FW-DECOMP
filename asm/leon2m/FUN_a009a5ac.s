# leon2m FUN_a009a5ac 0xa009a5ac-0xa009a5fc (80 bytes)
a009a5ac:  9d e3 bf 98  save  %sp, -104, %sp
a009a5b0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a009a5b4:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a009a5b8:  40 00 3b 81  call  0xa00a93bc
a009a5bc:  d0 0c 21 e1  ldub  [ %l0 + 0x1e1 ], %o0
a009a5c0:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a009a5c4:  d0 0c 60 55  ldub  [ %l1 + 0x55 ], %o0	! 0xa8025c55
a009a5c8:  d0 2c 21 e1  stb  %o0, [ %l0 + 0x1e1 ]
a009a5cc:  90 10 20 34  mov  0x34, %o0
a009a5d0:  40 00 53 9f  call  0xa00af44c
a009a5d4:  92 10 20 03  mov  3, %o1
a009a5d8:  9a 10 20 be  mov  0xbe, %o5
a009a5dc:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a009a5e0:  da 20 63 ec  st  %o5, [ %g1 + 0x3ec ]	! 0xa802afec
a009a5e4:  90 10 20 03  mov  3, %o0
a009a5e8:  40 00 3c 1a  call  0xa00a9650
a009a5ec:  92 10 20 01  mov  1, %o1
a009a5f0:  c0 2c 60 55  clrb  [ %l1 + 0x55 ]
a009a5f4:  81 c7 e0 08  ret
a009a5f8:  81 e8 00 00  restore
