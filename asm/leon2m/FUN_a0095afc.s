# leon2m FUN_a0095afc 0xa0095afc-0xa0095b58 (92 bytes)
a0095afc:  9d e3 bf 98  save  %sp, -104, %sp
a0095b00:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0095b04:  a0 12 e2 90  or  %o3, 0x290, %l0	! 0xa802d290
a0095b08:  94 10 20 00  clr  %o2
a0095b0c:  90 10 20 01  mov  1, %o0
a0095b10:  40 00 49 8b  call  0xa00a813c
a0095b14:  d2 0c 21 5b  ldub  [ %l0 + 0x15b ], %o1
a0095b18:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0095b1c:  d4 04 63 ec  ld  [ %l1 + 0x3ec ], %o2	! 0xa802afec
a0095b20:  90 02 bf f2  add  %o2, -14, %o0
a0095b24:  90 0a 20 ff  and  %o0, 0xff, %o0
a0095b28:  40 00 4d 39  call  0xa00a900c
a0095b2c:  92 10 20 02  mov  2, %o1
a0095b30:  d0 0c 21 5b  ldub  [ %l0 + 0x15b ], %o0
a0095b34:  92 02 20 4e  add  %o0, 0x4e, %o1
a0095b38:  d2 24 63 ec  st  %o1, [ %l1 + 0x3ec ]
a0095b3c:  40 00 4e c5  call  0xa00a9650
a0095b40:  92 10 20 01  mov  1, %o1
a0095b44:  da 0c 21 5b  ldub  [ %l0 + 0x15b ], %o5
a0095b48:  03 2a 00 97  sethi  %hi(0xa8025c00), %g1
a0095b4c:  da 28 60 56  stb  %o5, [ %g1 + 0x56 ]	! 0xa8025c56
a0095b50:  81 c7 e0 08  ret
a0095b54:  81 e8 00 00  restore
