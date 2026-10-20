# leon2s FUN_a00d264c 0xa00d264c-0xa00d2678 (44 bytes)
a00d264c:  03 2a 01 de  sethi  %hi(0xa8077800), %g1
a00d2650:  96 10 62 08  or  %g1, 0x208, %o3	! 0xa8077a08
a00d2654:  9a 10 20 00  clr  %o5
a00d2658:  98 10 24 00  mov  0x400, %o4
a00d265c:  82 03 40 0d  add  %o5, %o5, %g1
a00d2660:  9a 03 60 01  inc  %o5
a00d2664:  80 a3 61 00  cmp  %o5, 0x100
a00d2668:  04 bf ff fd  ble  0xa00d265c
a00d266c:  d8 32 c0 01  sth  %o4, [ %o3 + %g1 ]
a00d2670:  81 c3 e0 08  retl
a00d2674:  01 00 00 00  nop
