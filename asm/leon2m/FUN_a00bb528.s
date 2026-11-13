# leon2m FUN_a00bb528 0xa00bb528-0xa00bb560 (56 bytes)
a00bb528:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00bb52c:  c0 28 60 9a  clrb  [ %g1 + 0x9a ]	! 0xa802b09a
a00bb530:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bb534:  9a 13 60 40  or  %o5, 0x40, %o5	! 0xa802d040
a00bb538:  98 10 20 00  clr  %o4
a00bb53c:  82 10 20 00  clr  %g1
a00bb540:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bb544:  98 03 20 01  inc  %o4
a00bb548:  82 0b 20 ff  and  %o4, 0xff, %g1
a00bb54c:  80 a0 60 31  cmp  %g1, 0x31
a00bb550:  28 bf ff fd  bleu,a   0xa00bb544
a00bb554:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bb558:  81 c3 e0 08  retl
a00bb55c:  90 10 20 00  clr  %o0
