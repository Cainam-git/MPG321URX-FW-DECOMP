# leon2m FUN_a00bcbcc 0xa00bcbcc-0xa00bcc1c (80 bytes)
a00bcbcc:  9d e3 bf 98  save  %sp, -104, %sp
a00bcbd0:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bcbd4:  d6 03 e3 38  ld  [ %o7 + 0x338 ], %o3	! 0xa802d338
a00bcbd8:  95 32 e0 0c  srl  %o3, 0xc, %o2
a00bcbdc:  90 0a a0 01  and  %o2, 1, %o0
a00bcbe0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bcbe4:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bcbe8:  82 02 20 30  add  %o0, 0x30, %g1
a00bcbec:  98 10 20 30  mov  0x30, %o4
a00bcbf0:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bcbf4:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00bcbf8:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00bcbfc:  7f ff f8 10  call  0xa00bac3c
a00bcc00:  90 10 20 18  mov  0x18, %o0
a00bcc04:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bcc08:  7f ff f7 52  call  0xa00ba950
a00bcc0c:  90 10 00 18  mov  %i0, %o0
a00bcc10:  7f ff f7 f5  call  0xa00babe4
a00bcc14:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bcc18:  01 00 00 00  nop
