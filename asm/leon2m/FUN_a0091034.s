# leon2m FUN_a0091034 0xa0091034-0xa009108c (88 bytes)
a0091034:  9d e3 bf 98  save  %sp, -104, %sp
a0091038:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a009103c:  c2 04 23 ec  ld  [ %l0 + 0x3ec ], %g1	! 0xa802afec
a0091040:  80 a0 61 0d  cmp  %g1, 0x10d
a0091044:  12 80 00 0f  bne  0xa0091080
a0091048:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a009104c:  11 00 04 20  sethi  %hi(0x108000), %o0
a0091050:  da 0a 62 af  ldub  [ %o1 + 0x2af ], %o5
a0091054:  90 12 21 08  or  %o0, 0x108, %o0
a0091058:  b0 10 20 00  clr  %i0
a009105c:  80 a3 60 00  cmp  %o5, 0
a0091060:  12 80 00 08  bne  0xa0091080
a0091064:  b2 10 20 01  mov  1, %i1
a0091068:  40 01 38 42  call  0xa00df170
a009106c:  01 00 00 00  nop
a0091070:  40 00 90 04  call  0xa00b5080
a0091074:  c0 24 23 ec  clr  [ %l0 + 0x3ec ]
a0091078:  40 02 d0 2d  call  0xa014512c
a009107c:  81 e8 00 00  restore
a0091080:  01 00 00 00  nop
a0091084:  81 c7 e0 08  ret
a0091088:  81 e8 00 00  restore
