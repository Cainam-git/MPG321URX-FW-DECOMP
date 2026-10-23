# leon2m FUN_a00f6f54 0xa00f6f54-0xa00f6f7c (40 bytes)
a00f6f54:  80 8a 20 80  btst  0x80, %o0
a00f6f58:  02 80 00 03  be  0xa00f6f64
a00f6f5c:  9a 38 00 08  xnor  %g0, %o0, %o5
a00f6f60:  9a 0a 20 7f  and  %o0, 0x7f, %o5
a00f6f64:  11 33 c0 3b  sethi  %hi(0xcf00ec00), %o0
a00f6f68:  9a 0b 60 ff  and  %o5, 0xff, %o5
a00f6f6c:  82 12 23 1c  or  %o0, 0x31c, %g1
a00f6f70:  da 20 40 00  st  %o5, [ %g1 ]
a00f6f74:  81 c3 e0 08  retl
a00f6f78:  01 00 00 00  nop
