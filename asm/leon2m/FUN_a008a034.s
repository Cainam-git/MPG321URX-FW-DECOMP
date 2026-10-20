# leon2m FUN_a008a034 0xa008a034-0xa008a09c (104 bytes)
a008a034:  82 0a 20 c0  and  %o0, 0xc0, %g1
a008a038:  80 a0 60 40  cmp  %g1, 0x40
a008a03c:  02 80 00 05  be  0xa008a050
a008a040:  9a 10 20 04  mov  4, %o5
a008a044:  80 a0 60 80  cmp  %g1, 0x80
a008a048:  02 80 00 09  be  0xa008a06c
a008a04c:  90 0a 20 3f  and  %o0, 0x3f, %o0
a008a050:  90 0b 60 ff  and  %o5, 0xff, %o0
a008a054:  80 a2 20 03  cmp  %o0, 3
a008a058:  18 80 00 0f  bgu  0xa008a094
a008a05c:  01 00 00 00  nop
a008a060:  82 13 c0 00  mov  %o7, %g1
a008a064:  7f ff f9 ac  call  0xa0088714
a008a068:  9e 10 40 00  mov  %g1, %o7
a008a06c:  03 00 04 00  sethi  %hi(0x100000), %g1
a008a070:  82 10 60 68  or  %g1, 0x68, %g1	! 0x100068
a008a074:  d0 08 40 08  ldub  [ %g1 + %o0 ], %o0
a008a078:  80 a2 20 04  cmp  %o0, 4
a008a07c:  22 bf ff f6  be,a   0xa008a054
a008a080:  90 0b 60 ff  and  %o5, 0xff, %o0
a008a084:  1b 00 04 00  sethi  %hi(0x100000), %o5
a008a088:  82 13 60 60  or  %o5, 0x60, %g1	! 0x100060
a008a08c:  10 bf ff f1  b  0xa008a050
a008a090:  da 08 40 08  ldub  [ %g1 + %o0 ], %o5
a008a094:  81 c3 e0 08  retl
a008a098:  01 00 00 00  nop
