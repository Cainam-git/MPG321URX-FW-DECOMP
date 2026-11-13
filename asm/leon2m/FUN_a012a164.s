# leon2m FUN_a012a164 0xa012a164-0xa012a1a0 (60 bytes)
a012a164:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a012a168:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a012a16c:  92 10 62 9c  or  %g1, 0x29c, %o1
a012a170:  94 13 62 5c  or  %o5, 0x25c, %o2
a012a174:  96 10 20 00  clr  %o3
a012a178:  98 10 20 00  clr  %o4
a012a17c:  9b 2b 20 02  sll  %o4, 2, %o5
a012a180:  96 02 e0 01  inc  %o3
a012a184:  c2 02 80 0d  ld  [ %o2 + %o5 ], %g1
a012a188:  98 0a e0 ff  and  %o3, 0xff, %o4
a012a18c:  80 a3 20 0f  cmp  %o4, 0xf
a012a190:  08 bf ff fb  bleu  0xa012a17c
a012a194:  c2 22 40 0d  st  %g1, [ %o1 + %o5 ]
a012a198:  81 c3 e0 08  retl
a012a19c:  01 00 00 00  nop
