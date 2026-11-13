# leon2s FUN_a00a5050 0xa00a5050-0xa00a507c (44 bytes)
a00a5050:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00a5054:  98 10 60 10  or  %g1, 0x10, %o4	! 0xa807dc10
a00a5058:  9a 10 20 00  clr  %o5
a00a505c:  82 0b 60 ff  and  %o5, 0xff, %g1
a00a5060:  83 28 60 03  sll  %g1, 3, %g1
a00a5064:  9a 03 60 01  inc  %o5
a00a5068:  80 8b 60 ff  btst  0xff, %o5
a00a506c:  02 bf ff fc  be  0xa00a505c
a00a5070:  c0 23 00 01  clr  [ %o4 + %g1 ]
a00a5074:  81 c3 e0 08  retl
a00a5078:  01 00 00 00  nop
