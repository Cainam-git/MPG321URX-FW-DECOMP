# leon2m FUN_a0122250 0xa0122250-0xa01222c8 (120 bytes)
a0122250:  15 33 c0 72  sethi  %hi(0xcf01c800), %o2
a0122254:  92 12 a3 b8  or  %o2, 0x3b8, %o1	! 0xcf01cbb8
a0122258:  98 10 20 ff  mov  0xff, %o4
a012225c:  d8 22 40 00  st  %o4, [ %o1 ]
a0122260:  96 12 a3 bc  or  %o2, 0x3bc, %o3
a0122264:  c0 22 c0 00  clr  [ %o3 ]
a0122268:  9a 12 a1 9c  or  %o2, 0x19c, %o5
a012226c:  82 10 20 fd  mov  0xfd, %g1
a0122270:  c2 23 40 00  st  %g1, [ %o5 ]
a0122274:  98 10 20 04  mov  4, %o4
a0122278:  96 12 a0 30  or  %o2, 0x30, %o3
a012227c:  d8 22 c0 00  st  %o4, [ %o3 ]
a0122280:  9a 12 a0 04  or  %o2, 4, %o5
a0122284:  c0 23 40 00  clr  [ %o5 ]
a0122288:  82 10 20 01  mov  1, %g1
a012228c:  c2 22 40 00  st  %g1, [ %o1 ]
a0122290:  9a 10 20 00  clr  %o5
a0122294:  82 10 20 00  clr  %g1
a0122298:  98 10 20 80  mov  0x80, %o4
a012229c:  97 3b 00 01  sra  %o4, %g1, %o3
a01222a0:  82 0a e0 ff  and  %o3, 0xff, %g1
a01222a4:  c2 22 40 00  st  %g1, [ %o1 ]
a01222a8:  9a 03 60 01  inc  %o5
a01222ac:  82 0b 60 ff  and  %o5, 0xff, %g1
a01222b0:  c0 22 80 00  clr  [ %o2 ]
a01222b4:  80 a0 60 07  cmp  %g1, 7
a01222b8:  08 bf ff fa  bleu  0xa01222a0
a01222bc:  97 3b 00 01  sra  %o4, %g1, %o3
a01222c0:  81 c3 e0 08  retl
a01222c4:  01 00 00 00  nop
