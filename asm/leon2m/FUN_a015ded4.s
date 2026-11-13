# leon2m FUN_a015ded4 0xa015ded4-0xa015df0c (56 bytes)
a015ded4:  96 20 00 09  neg  %o1, %o3
a015ded8:  96 12 c0 09  or  %o3, %o1, %o3
a015dedc:  03 20 00 00  sethi  %hi(0x80000000), %g1
a015dee0:  82 2a 00 01  andn  %o0, %g1, %g1
a015dee4:  97 32 e0 1f  srl  %o3, 0x1f, %o3
a015dee8:  82 10 40 0b  or  %g1, %o3, %g1
a015deec:  1b 1f fc 00  sethi  %hi(0x7ff00000), %o5
a015def0:  82 23 40 01  sub  %o5, %g1, %g1
a015def4:  90 20 00 01  neg  %g1, %o0
a015def8:  90 12 00 01  or  %o0, %g1, %o0
a015defc:  91 32 20 1f  srl  %o0, 0x1f, %o0
a015df00:  82 10 20 01  mov  1, %g1
a015df04:  81 c3 e0 08  retl
a015df08:  90 20 40 08  sub  %g1, %o0, %o0
