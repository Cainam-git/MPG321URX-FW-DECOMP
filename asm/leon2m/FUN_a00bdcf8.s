# leon2m FUN_a00bdcf8 0xa00bdcf8-0xa00bdd48 (80 bytes)
a00bdcf8:  9d e3 bf 98  save  %sp, -104, %sp
a00bdcfc:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bdd00:  d6 03 e3 38  ld  [ %o7 + 0x338 ], %o3	! 0xa802d338
a00bdd04:  95 32 e0 06  srl  %o3, 6, %o2
a00bdd08:  90 0a a0 01  and  %o2, 1, %o0
a00bdd0c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bdd10:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bdd14:  82 02 20 30  add  %o0, 0x30, %g1
a00bdd18:  98 10 20 30  mov  0x30, %o4
a00bdd1c:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bdd20:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00bdd24:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00bdd28:  7f ff f3 c5  call  0xa00bac3c
a00bdd2c:  90 10 20 3a  mov  0x3a, %o0
a00bdd30:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bdd34:  7f ff f3 07  call  0xa00ba950
a00bdd38:  90 10 00 18  mov  %i0, %o0
a00bdd3c:  7f ff f3 aa  call  0xa00babe4
a00bdd40:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bdd44:  01 00 00 00  nop
