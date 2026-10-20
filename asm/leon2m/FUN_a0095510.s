# leon2m FUN_a0095510 0xa0095510-0xa00955a0 (144 bytes)
a0095510:  9d e3 bf 98  save  %sp, -104, %sp
a0095514:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0095518:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a009551c:  96 12 22 90  or  %o0, 0x290, %o3
a0095520:  da 0b 60 55  ldub  [ %o5 + 0x55 ], %o5
a0095524:  d8 0a e0 4b  ldub  [ %o3 + 0x4b ], %o4
a0095528:  82 0b 60 ff  and  %o5, 0xff, %g1
a009552c:  33 2a 00 97  sethi  %hi(0xa8025c00), %i1
a0095530:  b0 10 20 01  mov  1, %i0
a0095534:  b4 10 20 01  mov  1, %i2
a0095538:  80 a3 00 01  cmp  %o4, %g1
a009553c:  02 80 00 04  be  0xa009554c
a0095540:  90 10 20 01  mov  1, %o0
a0095544:  40 01 02 5a  call  0xa00d5eac
a0095548:  da 2a e0 4b  stb  %o5, [ %o3 + 0x4b ]
a009554c:  40 00 4d cf  call  0xa00a8c88
a0095550:  01 00 00 00  nop
a0095554:  40 00 89 64  call  0xa00b7ae4
a0095558:  01 00 00 00  nop
a009555c:  82 10 20 44  mov  0x44, %g1	! 0x44
a0095560:  1f 2a 00 ab  sethi  %hi(0xa802ac00), %o7
a0095564:  c2 23 e3 ec  st  %g1, [ %o7 + 0x3ec ]	! 0xa802afec
a0095568:  90 10 20 00  clr  %o0
a009556c:  40 00 50 39  call  0xa00a9650
a0095570:  92 10 20 01  mov  1, %o1
a0095574:  d6 0e 60 56  ldub  [ %i1 + 0x56 ], %o3
a0095578:  94 02 e0 02  add  %o3, 2, %o2
a009557c:  92 10 20 02  mov  2, %o1
a0095580:  40 00 50 34  call  0xa00a9650
a0095584:  90 0a a0 ff  and  %o2, 0xff, %o0
a0095588:  d2 0e 60 56  ldub  [ %i1 + 0x56 ], %o1
a009558c:  b2 02 60 02  add  %o1, 2, %i1
a0095590:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0095594:  40 00 4a ea  call  0xa00a813c
a0095598:  81 e8 00 00  restore
a009559c:  01 00 00 00  nop
