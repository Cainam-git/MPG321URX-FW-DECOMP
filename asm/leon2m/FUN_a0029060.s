# leon2m FUN_a0029060 0xa0029060-0xa00290e4 (132 bytes)
a0029060:  9d e3 bf c0  save  %sp, -64, %sp
a0029064:  a1 48 00 00  rd  %psr, %l0
a0029068:  a0 14 2f 00  or  %l0, 0xf00, %l0
a002906c:  81 8c 00 00  mov  %l0, %psr
a0029070:  81 8c 20 20  wr  %l0, 0x20, %psr
a0029074:  01 00 00 00  nop
a0029078:  01 00 00 00  nop
a002907c:  01 00 00 00  nop
a0029080:  a1 48 00 00  rd  %psr, %l0
a0029084:  01 00 00 00  nop
a0029088:  01 00 00 00  nop
a002908c:  29 28 00 aa  sethi  %hi(0xa002a800), %l4
a0029090:  a8 15 20 78  or  %l4, 0x78, %l4	! 0xa002a878
a0029094:  ae 10 00 14  mov  %l4, %l7
a0029098:  a2 10 00 00  mov  %g0, %l1
a002909c:  a4 10 00 01  mov  %g1, %l2
a00290a0:  a6 10 00 02  mov  %g2, %l3
a00290a4:  a8 10 00 03  mov  %g3, %l4
a00290a8:  9f c5 c0 00  call  %l7
a00290ac:  01 00 00 00  nop
a00290b0:  81 e8 00 00  restore
a00290b4:  81 e0 00 00  save
a00290b8:  80 10 00 11  mov  %l1, %g0
a00290bc:  82 10 00 12  mov  %l2, %g1
a00290c0:  84 10 00 13  mov  %l3, %g2
a00290c4:  86 10 00 14  mov  %l4, %g3
a00290c8:  01 00 00 00  nop
a00290cc:  81 8c 20 20  wr  %l0, 0x20, %psr
a00290d0:  a8 2c 2f 00  andn  %l0, 0xf00, %l4
a00290d4:  81 8d 20 20  wr  %l4, 0x20, %psr
a00290d8:  01 00 00 00  nop
a00290dc:  01 00 00 00  nop
a00290e0:  01 00 00 00  nop
