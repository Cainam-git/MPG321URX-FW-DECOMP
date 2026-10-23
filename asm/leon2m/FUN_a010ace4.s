# leon2m FUN_a010ace4 0xa010ace4-0xa010ad28 (68 bytes)
a010ace4:  17 33 c0 47  sethi  %hi(0xcf011c00), %o3
a010ace8:  82 10 20 01  mov  1, %g1
a010acec:  94 12 e1 c8  or  %o3, 0x1c8, %o2
a010acf0:  99 28 40 08  sll  %g1, %o0, %o4
a010acf4:  96 10 00 0a  mov  %o2, %o3
a010acf8:  80 8a 60 ff  btst  0xff, %o1
a010acfc:  02 80 00 06  be  0xa010ad14
a010ad00:  9a 10 00 0c  mov  %o4, %o5
a010ad04:  d2 02 80 00  ld  [ %o2 ], %o1
a010ad08:  90 12 40 0c  or  %o1, %o4, %o0
a010ad0c:  d0 22 80 00  st  %o0, [ %o2 ]
a010ad10:  30 80 00 04  b,a   0xa010ad20
a010ad14:  d8 02 80 00  ld  [ %o2 ], %o4
a010ad18:  94 2b 00 0d  andn  %o4, %o5, %o2
a010ad1c:  d4 22 c0 00  st  %o2, [ %o3 ]
a010ad20:  81 c3 e0 08  retl
a010ad24:  01 00 00 00  nop
