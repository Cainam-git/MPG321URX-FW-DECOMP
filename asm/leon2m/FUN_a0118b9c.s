# leon2m FUN_a0118b9c 0xa0118b9c-0xa0118be4 (72 bytes)
a0118b9c:  9d e3 bf 98  save  %sp, -104, %sp
a0118ba0:  03 33 c0 4b  sethi  %hi(0xcf012c00), %g1
a0118ba4:  b4 10 20 01  mov  1, %i2
a0118ba8:  b2 10 63 d0  or  %g1, 0x3d0, %i1
a0118bac:  9e 10 63 74  or  %g1, 0x374, %o7
a0118bb0:  80 8e 20 ff  btst  0xff, %i0
a0118bb4:  02 80 00 07  be  0xa0118bd0
a0118bb8:  b6 10 63 6c  or  %g1, 0x36c, %i3
a0118bbc:  f4 26 40 00  st  %i2, [ %i1 ]
a0118bc0:  f4 23 c0 00  st  %i2, [ %o7 ]
a0118bc4:  b0 10 20 04  mov  4, %i0
a0118bc8:  f0 26 c0 00  st  %i0, [ %i3 ]
a0118bcc:  30 80 00 04  b,a   0xa0118bdc
a0118bd0:  c0 23 c0 00  clr  [ %o7 ]
a0118bd4:  c0 26 40 00  clr  [ %i1 ]
a0118bd8:  c0 26 c0 00  clr  [ %i3 ]
a0118bdc:  81 c7 e0 08  ret
a0118be0:  81 e8 00 00  restore
