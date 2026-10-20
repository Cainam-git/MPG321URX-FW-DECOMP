# leon2m FUN_a00934dc 0xa00934dc-0xa0093534 (88 bytes)
a00934dc:  9d e3 bf 98  save  %sp, -104, %sp
a00934e0:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a00934e4:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2	! 0xa802afec
a00934e8:  92 02 bf ad  add  %o2, -83, %o1
a00934ec:  40 00 57 b4  call  0xa00a93bc
a00934f0:  90 0a 60 ff  and  %o1, 0xff, %o0
a00934f4:  40 00 7f 05  call  0xa00b3108
a00934f8:  b2 10 20 01  mov  1, %i1
a00934fc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0093500:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a0093504:  d8 0c 21 3e  ldub  [ %l0 + 0x13e ], %o4
a0093508:  82 03 20 dd  add  %o4, 0xdd, %g1
a009350c:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a0093510:  90 10 00 0c  mov  %o4, %o0
a0093514:  c2 24 63 ec  st  %g1, [ %l1 + 0x3ec ]
a0093518:  d8 2b 60 55  stb  %o4, [ %o5 + 0x55 ]
a009351c:  40 00 58 4d  call  0xa00a9650
a0093520:  92 10 20 00  clr  %o1
a0093524:  f0 0c 21 3e  ldub  [ %l0 + 0x13e ], %i0
a0093528:  40 00 58 4a  call  0xa00a9650
a009352c:  81 e8 00 00  restore
a0093530:  01 00 00 00  nop
