# leon2m FUN_a010adc0 0xa010adc0-0xa010ae38 (120 bytes)
a010adc0:  03 33 c0 3a  sethi  %hi(0xcf00e800), %g1
a010adc4:  98 10 62 c0  or  %g1, 0x2c0, %o4	! 0xcf00eac0
a010adc8:  80 a2 20 00  cmp  %o0, 0
a010adcc:  12 80 00 0e  bne  0xa010ae04
a010add0:  9a 10 00 0c  mov  %o4, %o5
a010add4:  da 03 00 00  ld  [ %o4 ], %o5
a010add8:  90 13 60 80  or  %o5, 0x80, %o0
a010addc:  d0 23 00 00  st  %o0, [ %o4 ]
a010ade0:  11 33 c0 3a  sethi  %hi(0xcf00e800), %o0
a010ade4:  98 12 22 c8  or  %o0, 0x2c8, %o4	! 0xcf00eac8
a010ade8:  80 a2 60 00  cmp  %o1, 0
a010adec:  12 80 00 0e  bne  0xa010ae24
a010adf0:  9a 10 00 0c  mov  %o4, %o5
a010adf4:  da 03 00 00  ld  [ %o4 ], %o5
a010adf8:  92 13 60 40  or  %o5, 0x40, %o1
a010adfc:  d2 23 00 00  st  %o1, [ %o4 ]
a010ae00:  30 80 00 0c  b,a   0xa010ae30
a010ae04:  c2 03 00 00  ld  [ %o4 ], %g1
a010ae08:  98 08 7f 7f  and  %g1, -129, %o4
a010ae0c:  d8 23 40 00  st  %o4, [ %o5 ]
a010ae10:  11 33 c0 3a  sethi  %hi(0xcf00e800), %o0
a010ae14:  98 12 22 c8  or  %o0, 0x2c8, %o4	! 0xcf00eac8
a010ae18:  80 a2 60 00  cmp  %o1, 0
a010ae1c:  02 bf ff f6  be  0xa010adf4
a010ae20:  9a 10 00 0c  mov  %o4, %o5
a010ae24:  c2 03 00 00  ld  [ %o4 ], %g1
a010ae28:  98 08 7f bf  and  %g1, -65, %o4
a010ae2c:  d8 23 40 00  st  %o4, [ %o5 ]
a010ae30:  81 c3 e0 08  retl
a010ae34:  01 00 00 00  nop
