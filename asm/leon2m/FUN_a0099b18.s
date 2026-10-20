# leon2m FUN_a0099b18 0xa0099b18-0xa0099b60 (72 bytes)
a0099b18:  9d e3 bf 98  save  %sp, -104, %sp
a0099b1c:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0099b20:  d4 04 23 ec  ld  [ %l0 + 0x3ec ], %o2	! 0xa802afec
a0099b24:  92 02 a0 4f  add  %o2, 0x4f, %o1
a0099b28:  40 00 3e 25  call  0xa00a93bc
a0099b2c:  90 0a 60 ff  and  %o1, 0xff, %o0
a0099b30:  40 00 49 65  call  0xa00ac0c4
a0099b34:  b2 10 20 01  mov  1, %i1
a0099b38:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0099b3c:  f0 0a 23 3c  ldub  [ %o0 + 0x33c ], %i0	! 0xa802d33c
a0099b40:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a0099b44:  9a 10 20 f0  mov  0xf0, %o5
a0099b48:  f0 28 60 55  stb  %i0, [ %g1 + 0x55 ]
a0099b4c:  da 24 23 ec  st  %o5, [ %l0 + 0x3ec ]
a0099b50:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0099b54:  40 00 3e bf  call  0xa00a9650
a0099b58:  81 e8 00 00  restore
a0099b5c:  01 00 00 00  nop
