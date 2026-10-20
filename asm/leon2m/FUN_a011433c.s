# leon2m FUN_a011433c 0xa011433c-0xa0114360 (36 bytes)
a011433c:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a0114340:  82 10 62 6c  or  %g1, 0x26c, %g1	! 0xcf01166c
a0114344:  da 00 40 00  ld  [ %g1 ], %o5
a0114348:  9a 0b 60 fc  and  %o5, 0xfc, %o5
a011434c:  90 0a 20 03  and  %o0, 3, %o0
a0114350:  9a 13 40 08  or  %o5, %o0, %o5
a0114354:  da 20 40 00  st  %o5, [ %g1 ]
a0114358:  81 c3 e0 08  retl
a011435c:  01 00 00 00  nop
