# leon2m FUN_a00abb98 0xa00abb98-0xa00abc64 (204 bytes)
a00abb98:  9d e3 bf 98  save  %sp, -104, %sp
a00abb9c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00abba0:  a0 12 a2 90  or  %o2, 0x290, %l0	! 0xa802d290
a00abba4:  da 0c 20 14  ldub  [ %l0 + 0x14 ], %o5
a00abba8:  9a 03 60 01  inc  %o5
a00abbac:  82 0b 60 ff  and  %o5, 0xff, %g1
a00abbb0:  90 10 20 2c  mov  0x2c, %o0
a00abbb4:  92 10 20 0a  mov  0xa, %o1
a00abbb8:  96 10 20 07  mov  7, %o3
a00abbbc:  98 10 20 01  mov  1, %o4
a00abbc0:  80 a0 60 64  cmp  %g1, 0x64
a00abbc4:  08 80 00 05  bleu  0xa00abbd8
a00abbc8:  94 10 00 01  mov  %g1, %o2
a00abbcc:  90 10 20 64  mov  0x64, %o0
a00abbd0:  10 80 00 1f  b  0xa00abc4c
a00abbd4:  d0 2c 20 14  stb  %o0, [ %l0 + 0x14 ]
a00abbd8:  7f ff fe 86  call  0xa00ab5f0
a00abbdc:  da 2c 20 14  stb  %o5, [ %l0 + 0x14 ]
a00abbe0:  90 10 20 28  mov  0x28, %o0
a00abbe4:  92 10 20 0a  mov  0xa, %o1
a00abbe8:  94 10 20 03  mov  3, %o2
a00abbec:  96 10 27 42  mov  0x742, %o3
a00abbf0:  40 02 6b a4  call  0xa0146a80
a00abbf4:  98 10 20 00  clr  %o4
a00abbf8:  90 10 20 2b  mov  0x2b, %o0
a00abbfc:  92 10 20 0a  mov  0xa, %o1
a00abc00:  94 10 20 01  mov  1, %o2
a00abc04:  96 10 27 42  mov  0x742, %o3
a00abc08:  40 02 6b 9e  call  0xa0146a80
a00abc0c:  98 10 20 00  clr  %o4
a00abc10:  94 10 20 01  mov  1, %o2
a00abc14:  96 10 27 42  mov  0x742, %o3
a00abc18:  98 10 20 00  clr  %o4
a00abc1c:  90 10 20 32  mov  0x32, %o0
a00abc20:  40 02 6b 98  call  0xa0146a80
a00abc24:  92 10 20 0a  mov  0xa, %o1
a00abc28:  90 10 20 ea  mov  0xea, %o0
a00abc2c:  40 02 6b c9  call  0xa0146b50
a00abc30:  92 10 20 00  clr  %o1
a00abc34:  d4 0c 20 14  ldub  [ %l0 + 0x14 ], %o2
a00abc38:  90 10 20 29  mov  0x29, %o0
a00abc3c:  40 00 2c a3  call  0xa00b6ec8
a00abc40:  92 10 20 0a  mov  0xa, %o1
a00abc44:  40 00 b6 ba  call  0xa00d972c
a00abc48:  01 00 00 00  nop
a00abc4c:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00abc50:  d8 0a 60 8e  ldub  [ %o1 + 0x8e ], %o4	! 0xa802b08e
a00abc54:  96 13 20 02  or  %o4, 2, %o3
a00abc58:  d6 2a 60 8e  stb  %o3, [ %o1 + 0x8e ]
a00abc5c:  81 c7 e0 08  ret
a00abc60:  81 e8 00 00  restore
