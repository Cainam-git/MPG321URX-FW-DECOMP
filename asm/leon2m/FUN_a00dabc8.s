# leon2m FUN_a00dabc8 0xa00dabc8-0xa00dabfc (52 bytes)
a00dabc8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00dabcc:  82 10 62 90  or  %g1, 0x290, %g1	! 0xa802d290
a00dabd0:  da 08 61 ea  ldub  [ %g1 + 0x1ea ], %o5
a00dabd4:  80 a3 60 00  cmp  %o5, 0
a00dabd8:  12 80 00 05  bne  0xa00dabec
a00dabdc:  90 10 20 00  clr  %o0
a00dabe0:  82 13 c0 00  mov  %o7, %g1
a00dabe4:  40 01 31 b9  call  0xa01272c8
a00dabe8:  9e 10 40 00  mov  %g1, %o7
a00dabec:  d0 08 61 eb  ldub  [ %g1 + 0x1eb ], %o0
a00dabf0:  82 13 c0 00  mov  %o7, %g1
a00dabf4:  40 01 31 b5  call  0xa01272c8
a00dabf8:  9e 10 40 00  mov  %g1, %o7
