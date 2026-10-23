# leon2m FUN_a010db2c 0xa010db2c-0xa010db74 (72 bytes)
a010db2c:  82 0a 20 ff  and  %o0, 0xff, %g1
a010db30:  99 2a a0 02  sll  %o2, 2, %o4
a010db34:  9b 28 60 02  sll  %g1, 2, %o5
a010db38:  80 8a 60 ff  btst  0xff, %o1
a010db3c:  94 10 00 0c  mov  %o4, %o2
a010db40:  12 80 00 07  bne  0xa010db5c
a010db44:  90 10 00 0d  mov  %o5, %o0
a010db48:  13 00 06 6b  sethi  %hi(0x19ac00), %o1
a010db4c:  90 12 62 c4  or  %o1, 0x2c4, %o0	! 0x19aec4
a010db50:  da 02 00 0d  ld  [ %o0 + %o5 ], %o5
a010db54:  d6 23 40 0c  st  %o3, [ %o5 + %o4 ]
a010db58:  30 80 00 05  b,a   0xa010db6c
a010db5c:  1b 00 06 6b  sethi  %hi(0x19ac00), %o5
a010db60:  82 13 62 bc  or  %o5, 0x2bc, %g1	! 0x19aebc
a010db64:  d8 00 40 08  ld  [ %g1 + %o0 ], %o4
a010db68:  d6 23 00 0a  st  %o3, [ %o4 + %o2 ]
a010db6c:  81 c3 e0 08  retl
a010db70:  01 00 00 00  nop
