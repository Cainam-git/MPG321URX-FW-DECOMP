# leon2m FUN_a010db74 0xa010db74-0xa010dbc4 (80 bytes)
a010db74:  9a 0a 20 ff  and  %o0, 0xff, %o5
a010db78:  80 a3 60 02  cmp  %o5, 2
a010db7c:  82 40 20 00  addx  %g0, 0, %g1
a010db80:  82 20 00 01  neg  %g1
a010db84:  90 0b 40 01  and  %o5, %g1, %o0
a010db88:  9b 2a 20 02  sll  %o0, 2, %o5
a010db8c:  80 8a 60 ff  btst  0xff, %o1
a010db90:  12 80 00 06  bne  0xa010dba8
a010db94:  90 10 00 0d  mov  %o5, %o0
a010db98:  11 00 06 6b  sethi  %hi(0x19ac00), %o0
a010db9c:  92 12 22 c4  or  %o0, 0x2c4, %o1	! 0x19aec4
a010dba0:  10 80 00 05  b  0xa010dbb4
a010dba4:  d0 02 40 0d  ld  [ %o1 + %o5 ], %o0
a010dba8:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010dbac:  9a 10 62 bc  or  %g1, 0x2bc, %o5	! 0x19aebc
a010dbb0:  d0 03 40 08  ld  [ %o5 + %o0 ], %o0
a010dbb4:  93 2a a0 02  sll  %o2, 2, %o1
a010dbb8:  d0 02 00 09  ld  [ %o0 + %o1 ], %o0
a010dbbc:  81 c3 e0 08  retl
a010dbc0:  01 00 00 00  nop
