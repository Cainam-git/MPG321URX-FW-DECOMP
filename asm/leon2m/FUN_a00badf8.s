# leon2m FUN_a00badf8 0xa00badf8-0xa00bae38 (64 bytes)
a00badf8:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a00badfc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bae00:  d6 0b 23 fd  ldub  [ %o4 + 0x3fd ], %o3
a00bae04:  82 12 a2 90  or  %o2, 0x290, %g1
a00bae08:  9a 02 c0 01  add  %o3, %g1, %o5
a00bae0c:  c2 0b 61 9b  ldub  [ %o5 + 0x19b ], %g1
a00bae10:  d4 0b 61 97  ldub  [ %o5 + 0x197 ], %o2
a00bae14:  96 00 60 30  add  %g1, 0x30, %o3
a00bae18:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bae1c:  9a 13 20 78  or  %o4, 0x78, %o5	! 0xa802d078
a00bae20:  94 02 a0 30  add  %o2, 0x30, %o2
a00bae24:  82 10 20 30  mov  0x30, %g1
a00bae28:  d6 2b 60 09  stb  %o3, [ %o5 + 9 ]
a00bae2c:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bae30:  81 c3 e0 08  retl
a00bae34:  d4 2b 60 08  stb  %o2, [ %o5 + 8 ]
