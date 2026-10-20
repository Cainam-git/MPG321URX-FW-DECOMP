# leon2m FUN_a00bce7c 0xa00bce7c-0xa00bcecc (80 bytes)
a00bce7c:  9d e3 bf 98  save  %sp, -104, %sp
a00bce80:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bce84:  d6 03 e3 38  ld  [ %o7 + 0x338 ], %o3	! 0xa802d338
a00bce88:  95 32 e0 0d  srl  %o3, 0xd, %o2
a00bce8c:  90 0a a0 01  and  %o2, 1, %o0
a00bce90:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bce94:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bce98:  82 02 20 30  add  %o0, 0x30, %g1
a00bce9c:  98 10 20 30  mov  0x30, %o4
a00bcea0:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bcea4:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00bcea8:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00bceac:  7f ff f7 64  call  0xa00bac3c
a00bceb0:  90 10 20 21  mov  0x21, %o0
a00bceb4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bceb8:  7f ff f6 a6  call  0xa00ba950
a00bcebc:  90 10 00 18  mov  %i0, %o0
a00bcec0:  7f ff f7 49  call  0xa00babe4
a00bcec4:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcec8:  01 00 00 00  nop
