# leon2m FUN_a00bdc14 0xa00bdc14-0xa00bdc60 (76 bytes)
a00bdc14:  9d e3 bf 98  save  %sp, -104, %sp
a00bdc18:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00bdc1c:  d4 0a e2 c1  ldub  [ %o3 + 0x2c1 ], %o2	! 0xa802d2c1
a00bdc20:  92 10 20 32  mov  0x32, %o1
a00bdc24:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bdc28:  82 12 20 78  or  %o0, 0x78, %g1	! 0xa802d078
a00bdc2c:  98 10 20 30  mov  0x30, %o4
a00bdc30:  9a 22 40 0a  sub  %o1, %o2, %o5
a00bdc34:  da 28 60 09  stb  %o5, [ %g1 + 9 ]
a00bdc38:  d8 28 60 08  stb  %o4, [ %g1 + 8 ]
a00bdc3c:  d8 28 60 07  stb  %o4, [ %g1 + 7 ]
a00bdc40:  7f ff f3 ff  call  0xa00bac3c
a00bdc44:  90 10 20 38  mov  0x38, %o0
a00bdc48:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bdc4c:  7f ff f3 41  call  0xa00ba950
a00bdc50:  90 10 00 18  mov  %i0, %o0
a00bdc54:  7f ff f3 e4  call  0xa00babe4
a00bdc58:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bdc5c:  01 00 00 00  nop
