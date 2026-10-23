# leon2m FUN_a010fda4 0xa010fda4-0xa010fe50 (172 bytes)
a010fda4:  19 34 00 c8  sethi  %hi(0xd0032000), %o4
a010fda8:  94 13 22 70  or  %o4, 0x270, %o2	! 0xd0032270
a010fdac:  90 0a 20 ff  and  %o0, 0xff, %o0
a010fdb0:  80 a2 20 01  cmp  %o0, 1
a010fdb4:  02 80 00 14  be  0xa010fe04
a010fdb8:  96 10 00 0a  mov  %o2, %o3
a010fdbc:  d4 03 00 00  ld  [ %o4 ], %o2
a010fdc0:  82 0a bf fd  and  %o2, -3, %g1
a010fdc4:  c2 23 00 00  st  %g1, [ %o4 ]
a010fdc8:  d8 02 c0 00  ld  [ %o3 ], %o4
a010fdcc:  94 13 20 01  or  %o4, 1, %o2
a010fdd0:  d4 22 c0 00  st  %o2, [ %o3 ]
a010fdd4:  19 34 00 e8  sethi  %hi(0xd003a000), %o4
a010fdd8:  94 13 22 70  or  %o4, 0x270, %o2	! 0xd003a270
a010fddc:  80 a2 20 01  cmp  %o0, 1
a010fde0:  02 80 00 14  be  0xa010fe30
a010fde4:  96 10 00 0a  mov  %o2, %o3
a010fde8:  c2 03 00 00  ld  [ %o4 ], %g1
a010fdec:  90 08 7f fd  and  %g1, -3, %o0
a010fdf0:  d0 23 00 00  st  %o0, [ %o4 ]
a010fdf4:  d4 02 80 00  ld  [ %o2 ], %o2
a010fdf8:  98 12 a0 01  or  %o2, 1, %o4
a010fdfc:  d8 22 c0 00  st  %o4, [ %o3 ]
a010fe00:  30 80 00 12  b,a   0xa010fe48
a010fe04:  da 03 00 00  ld  [ %o4 ], %o5
a010fe08:  96 0b 7f fb  and  %o5, -5, %o3
a010fe0c:  d6 23 00 00  st  %o3, [ %o4 ]
a010fe10:  c2 02 80 00  ld  [ %o2 ], %g1
a010fe14:  9a 10 60 02  or  %g1, 2, %o5
a010fe18:  da 22 80 00  st  %o5, [ %o2 ]
a010fe1c:  19 34 00 e8  sethi  %hi(0xd003a000), %o4
a010fe20:  94 13 22 70  or  %o4, 0x270, %o2	! 0xd003a270
a010fe24:  80 a2 20 01  cmp  %o0, 1
a010fe28:  12 bf ff f0  bne  0xa010fde8
a010fe2c:  96 10 00 0a  mov  %o2, %o3
a010fe30:  c2 03 00 00  ld  [ %o4 ], %g1
a010fe34:  9a 08 7f fb  and  %g1, -5, %o5
a010fe38:  da 23 00 00  st  %o5, [ %o4 ]
a010fe3c:  d6 02 80 00  ld  [ %o2 ], %o3
a010fe40:  90 12 e0 02  or  %o3, 2, %o0
a010fe44:  d0 22 80 00  st  %o0, [ %o2 ]
a010fe48:  81 c3 e0 08  retl
a010fe4c:  01 00 00 00  nop
