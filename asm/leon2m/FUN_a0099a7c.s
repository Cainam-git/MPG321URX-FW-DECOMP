# leon2m FUN_a0099a7c 0xa0099a7c-0xa0099ac0 (68 bytes)
a0099a7c:  9d e3 bf 98  save  %sp, -104, %sp
a0099a80:  90 10 20 01  mov  1, %o0
a0099a84:  92 10 20 01  mov  1, %o1
a0099a88:  40 00 39 ad  call  0xa00a813c
a0099a8c:  94 10 20 00  clr  %o2
a0099a90:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0099a94:  d2 04 23 ec  ld  [ %l0 + 0x3ec ], %o1	! 0xa802afec
a0099a98:  90 02 7f d6  add  %o1, -42, %o0
a0099a9c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0099aa0:  40 00 3d 5b  call  0xa00a900c
a0099aa4:  92 10 20 02  mov  2, %o1
a0099aa8:  82 10 20 b7  mov  0xb7, %g1
a0099aac:  c2 24 23 ec  st  %g1, [ %l0 + 0x3ec ]
a0099ab0:  b0 10 20 01  mov  1, %i0
a0099ab4:  40 00 3e e7  call  0xa00a9650
a0099ab8:  93 e8 20 01  restore  %g0, 1, %o1
a0099abc:  01 00 00 00  nop
