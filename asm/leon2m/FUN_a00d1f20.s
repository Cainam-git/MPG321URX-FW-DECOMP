# leon2m FUN_a00d1f20 0xa00d1f20-0xa00d1f58 (56 bytes)
a00d1f20:  9d e3 bf 98  save  %sp, -104, %sp
a00d1f24:  da 0e 20 07  ldub  [ %i0 + 7 ], %o5
a00d1f28:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d1f2c:  80 a3 60 64  cmp  %o5, 0x64
a00d1f30:  08 80 00 05  bleu  0xa00d1f44
a00d1f34:  98 10 62 90  or  %g1, 0x290, %o4
a00d1f38:  90 10 20 64  mov  0x64, %o0
a00d1f3c:  10 80 00 03  b  0xa00d1f48
a00d1f40:  d0 2b 20 0a  stb  %o0, [ %o4 + 0xa ]
a00d1f44:  da 2b 20 0a  stb  %o5, [ %o4 + 0xa ]
a00d1f48:  40 00 17 a6  call  0xa00d7de0
a00d1f4c:  b0 10 20 e0  mov  0xe0, %i0
a00d1f50:  81 c7 e0 08  ret
a00d1f54:  81 e8 00 00  restore
