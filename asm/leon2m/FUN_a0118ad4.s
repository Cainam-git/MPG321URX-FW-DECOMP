# leon2m FUN_a0118ad4 0xa0118ad4-0xa0118af0 (28 bytes)
a0118ad4:  1b 33 c0 4b  sethi  %hi(0xcf012c00), %o5
a0118ad8:  9a 13 63 f0  or  %o5, 0x3f0, %o5	! 0xcf012ff0
a0118adc:  c2 03 40 00  ld  [ %o5 ], %g1
a0118ae0:  82 08 7f 7f  and  %g1, -129, %g1
a0118ae4:  c2 23 40 00  st  %g1, [ %o5 ]
a0118ae8:  81 c3 e0 08  retl
a0118aec:  01 00 00 00  nop
