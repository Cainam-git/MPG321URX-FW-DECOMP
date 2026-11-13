# leon2m FUN_a00bb414 0xa00bb414-0xa00bb44c (56 bytes)
a00bb414:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00bb418:  c0 28 60 9a  clrb  [ %g1 + 0x9a ]	! 0xa802b09a
a00bb41c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bb420:  9a 13 60 40  or  %o5, 0x40, %o5	! 0xa802d040
a00bb424:  98 10 20 00  clr  %o4
a00bb428:  82 10 20 00  clr  %g1
a00bb42c:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bb430:  98 03 20 01  inc  %o4
a00bb434:  82 0b 20 ff  and  %o4, 0xff, %g1
a00bb438:  80 a0 60 31  cmp  %g1, 0x31
a00bb43c:  28 bf ff fd  bleu,a   0xa00bb430
a00bb440:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bb444:  81 c3 e0 08  retl
a00bb448:  01 00 00 00  nop
