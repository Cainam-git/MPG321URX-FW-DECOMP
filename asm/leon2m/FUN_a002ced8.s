# leon2m FUN_a002ced8 0xa002ced8-0xa002cf04 (44 bytes)
a002ced8:  19 33 c0 f2  sethi  %hi(0xcf03c800), %o4
a002cedc:  82 13 20 10  or  %o4, 0x10, %g1	! 0xcf03c810
a002cee0:  d6 00 40 00  ld  [ %g1 ], %o3
a002cee4:  9a 13 20 20  or  %o4, 0x20, %o5
a002cee8:  d6 23 40 00  st  %o3, [ %o5 ]
a002ceec:  82 13 21 00  or  %o4, 0x100, %g1
a002cef0:  da 00 40 00  ld  [ %g1 ], %o5
a002cef4:  98 13 21 10  or  %o4, 0x110, %o4
a002cef8:  da 23 00 00  st  %o5, [ %o4 ]
a002cefc:  81 c3 e0 08  retl
a002cf00:  01 00 00 00  nop
