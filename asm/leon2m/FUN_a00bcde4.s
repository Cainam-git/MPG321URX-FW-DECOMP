# leon2m FUN_a00bcde4 0xa00bcde4-0xa00bce2c (72 bytes)
a00bcde4:  9d e3 bf 98  save  %sp, -104, %sp
a00bcde8:  15 2a 00 b5  sethi  %hi(0xa802d400), %o2
a00bcdec:  d0 0a a0 0b  ldub  [ %o2 + 0xb ], %o0	! 0xa802d40b
a00bcdf0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bcdf4:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bcdf8:  98 02 20 30  add  %o0, 0x30, %o4
a00bcdfc:  82 10 20 30  mov  0x30, %g1
a00bce00:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bce04:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bce08:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bce0c:  7f ff f7 8c  call  0xa00bac3c
a00bce10:  90 10 20 1f  mov  0x1f, %o0
a00bce14:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bce18:  7f ff f6 ce  call  0xa00ba950
a00bce1c:  90 10 00 18  mov  %i0, %o0
a00bce20:  7f ff f7 71  call  0xa00babe4
a00bce24:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bce28:  01 00 00 00  nop
