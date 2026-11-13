# leon2s FUN_a00629fc 0xa00629fc-0xa0062a34 (56 bytes)
a00629fc:  d8 0a 20 58  ldub  [ %o0 + 0x58 ], %o4
a0062a00:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0062a04:  80 a3 60 0e  cmp  %o5, 0xe
a0062a08:  18 80 00 09  bgu  0xa0062a2c
a0062a0c:  96 10 23 ff  mov  0x3ff, %o3
a0062a10:  82 03 40 0d  add  %o5, %o5, %g1
a0062a14:  98 03 20 01  inc  %o4
a0062a18:  82 00 40 08  add  %g1, %o0, %g1
a0062a1c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0062a20:  80 a3 60 0e  cmp  %o5, 0xe
a0062a24:  08 bf ff fb  bleu  0xa0062a10
a0062a28:  d6 30 60 5a  sth  %o3, [ %g1 + 0x5a ]
a0062a2c:  81 c3 e0 08  retl
a0062a30:  01 00 00 00  nop
