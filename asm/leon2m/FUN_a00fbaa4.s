# leon2m FUN_a00fbaa4 0xa00fbaa4-0xa00fbaf8 (84 bytes)
a00fbaa4:  15 34 01 00  sethi  %hi(0xd0040000), %o2
a00fbaa8:  80 8a 20 ff  btst  0xff, %o0
a00fbaac:  02 80 00 09  be  0xa00fbad0
a00fbab0:  19 20 00 00  sethi  %hi(0x80000000), %o4
a00fbab4:  d0 02 80 00  ld  [ %o2 ], %o0
a00fbab8:  83 32 20 1f  srl  %o0, 0x1f, %g1
a00fbabc:  1b 2a 00 ad  sethi  %hi(0xa802b400), %o5
a00fbac0:  98 2a 00 0c  andn  %o0, %o4, %o4
a00fbac4:  c2 2b 63 e8  stb  %g1, [ %o5 + 0x3e8 ]
a00fbac8:  d8 22 80 00  st  %o4, [ %o2 ]
a00fbacc:  30 80 00 09  b,a   0xa00fbaf0
a00fbad0:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00fbad4:  da 08 63 e8  ldub  [ %g1 + 0x3e8 ], %o5	! 0xa802b7e8
a00fbad8:  97 2b 60 1f  sll  %o5, 0x1f, %o3
a00fbadc:  d0 02 80 00  ld  [ %o2 ], %o0
a00fbae0:  9a 0a c0 0c  and  %o3, %o4, %o5
a00fbae4:  82 2a 00 0c  andn  %o0, %o4, %g1
a00fbae8:  96 10 40 0d  or  %g1, %o5, %o3
a00fbaec:  d6 22 80 00  st  %o3, [ %o2 ]
a00fbaf0:  81 c3 e0 08  retl
a00fbaf4:  90 10 20 01  mov  1, %o0
