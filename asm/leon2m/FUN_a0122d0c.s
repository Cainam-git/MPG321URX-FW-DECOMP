# leon2m FUN_a0122d0c 0xa0122d0c-0xa0122d40 (52 bytes)
a0122d0c:  9d e3 bf 98  save  %sp, -104, %sp
a0122d10:  13 00 06 8c  sethi  %hi(0x1a3000), %o1
a0122d14:  7f fe f1 17  call  0xa00df170
a0122d18:  90 12 60 48  or  %o1, 0x48, %o0	! 0x1a3048
a0122d1c:  11 33 c0 3a  sethi  %hi(0xcf00e800), %o0
a0122d20:  a0 12 23 44  or  %o0, 0x344, %l0	! 0xcf00eb44
a0122d24:  82 10 20 01  mov  1, %g1
a0122d28:  c2 24 00 00  st  %g1, [ %l0 ]
a0122d2c:  67 fd a9 1d  call  0x4008d1a0
a0122d30:  90 10 20 01  mov  1, %o0
a0122d34:  c0 24 00 00  clr  [ %l0 ]
a0122d38:  81 c7 e0 08  ret
a0122d3c:  81 e8 00 00  restore
