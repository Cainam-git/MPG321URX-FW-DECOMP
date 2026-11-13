# leon2m FUN_a00de65c 0xa00de65c-0xa00de6a8 (76 bytes)
a00de65c:  9d e3 bf 98  save  %sp, -104, %sp
a00de660:  03 27 c0 80  sethi  %hi(0x9f020000), %g1
a00de664:  90 10 60 e0  or  %g1, 0xe0, %o0	! 0x9f0200e0
a00de668:  67 fe b6 fd  call  0x4008c25c
a00de66c:  92 10 20 60  mov  0x60, %o1
a00de670:  01 00 00 00  nop
a00de674:  01 00 00 00  nop
a00de678:  01 00 00 00  nop
a00de67c:  11 27 c0 00  sethi  %hi(0x9f000000), %o0
a00de680:  90 12 20 14  or  %o0, 0x14, %o0	! 0x9f000014
a00de684:  67 fe b6 f6  call  0x4008c25c
a00de688:  92 10 20 00  clr  %o1
a00de68c:  82 10 23 ff  mov  0x3ff, %g1
a00de690:  01 00 00 00  nop
a00de694:  82 80 7f ff  addcc  %g1, -1, %g1
a00de698:  1c bf ff fe  bpos  0xa00de690
a00de69c:  01 00 00 00  nop
a00de6a0:  81 c7 e0 08  ret
a00de6a4:  81 e8 00 00  restore
