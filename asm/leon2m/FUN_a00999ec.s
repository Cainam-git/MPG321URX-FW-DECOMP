# leon2m FUN_a00999ec 0xa00999ec-0xa0099a34 (72 bytes)
a00999ec:  9d e3 bf 98  save  %sp, -104, %sp
a00999f0:  40 00 65 ec  call  0xa00b31a0
a00999f4:  b2 10 20 01  mov  1, %i1
a00999f8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00999fc:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a0099a00:  d6 0c 20 4b  ldub  [ %l0 + 0x4b ], %o3
a0099a04:  98 02 e0 e7  add  %o3, 0xe7, %o4
a0099a08:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0099a0c:  1b 2a 00 97  sethi  %hi(0xa8025c00), %o5
a0099a10:  90 10 00 0b  mov  %o3, %o0
a0099a14:  d8 20 63 ec  st  %o4, [ %g1 + 0x3ec ]
a0099a18:  d6 2b 60 55  stb  %o3, [ %o5 + 0x55 ]
a0099a1c:  40 00 3f 0d  call  0xa00a9650
a0099a20:  92 10 20 00  clr  %o1
a0099a24:  f0 0c 20 4b  ldub  [ %l0 + 0x4b ], %i0
a0099a28:  40 00 3f 0a  call  0xa00a9650
a0099a2c:  81 e8 00 00  restore
a0099a30:  01 00 00 00  nop
