# leon2m FUN_a00d1ed8 0xa00d1ed8-0xa00d1f20 (72 bytes)
a00d1ed8:  9d e3 bf 98  save  %sp, -104, %sp
a00d1edc:  da 0e 20 07  ldub  [ %i0 + 7 ], %o5
a00d1ee0:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d1ee4:  80 a3 60 64  cmp  %o5, 0x64
a00d1ee8:  08 80 00 05  bleu  0xa00d1efc
a00d1eec:  98 10 62 90  or  %g1, 0x290, %o4
a00d1ef0:  90 10 20 64  mov  0x64, %o0
a00d1ef4:  10 80 00 03  b  0xa00d1f00
a00d1ef8:  d0 2b 20 09  stb  %o0, [ %o4 + 9 ]
a00d1efc:  da 2b 20 09  stb  %o5, [ %o4 + 9 ]
a00d1f00:  40 00 1b 75  call  0xa00d8cd4
a00d1f04:  b0 10 20 e0  mov  0xe0, %i0
a00d1f08:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00d1f0c:  d4 0b 60 8e  ldub  [ %o5 + 0x8e ], %o2	! 0xa802b08e
a00d1f10:  92 12 a0 04  or  %o2, 4, %o1
a00d1f14:  d2 2b 60 8e  stb  %o1, [ %o5 + 0x8e ]
a00d1f18:  81 c7 e0 08  ret
a00d1f1c:  81 e8 00 00  restore
