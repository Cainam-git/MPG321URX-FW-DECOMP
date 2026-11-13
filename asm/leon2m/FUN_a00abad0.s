# leon2m FUN_a00abad0 0xa00abad0-0xa00abb98 (200 bytes)
a00abad0:  9d e3 bf 98  save  %sp, -104, %sp
a00abad4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00abad8:  a0 12 a2 90  or  %o2, 0x290, %l0	! 0xa802d290
a00abadc:  da 0c 20 14  ldub  [ %l0 + 0x14 ], %o5
a00abae0:  9a 03 7f ff  add  %o5, -1, %o5
a00abae4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00abae8:  90 10 20 2c  mov  0x2c, %o0
a00abaec:  92 10 20 0a  mov  0xa, %o1
a00abaf0:  96 10 20 07  mov  7, %o3
a00abaf4:  98 10 20 01  mov  1, %o4
a00abaf8:  80 a0 60 64  cmp  %g1, 0x64
a00abafc:  08 80 00 04  bleu  0xa00abb0c
a00abb00:  94 10 00 01  mov  %g1, %o2
a00abb04:  10 80 00 1f  b  0xa00abb80
a00abb08:  c0 2c 20 14  clrb  [ %l0 + 0x14 ]
a00abb0c:  7f ff fe b9  call  0xa00ab5f0
a00abb10:  da 2c 20 14  stb  %o5, [ %l0 + 0x14 ]
a00abb14:  90 10 20 28  mov  0x28, %o0
a00abb18:  92 10 20 0a  mov  0xa, %o1
a00abb1c:  94 10 20 03  mov  3, %o2
a00abb20:  96 10 27 42  mov  0x742, %o3
a00abb24:  40 02 6b d7  call  0xa0146a80
a00abb28:  98 10 20 00  clr  %o4
a00abb2c:  90 10 20 2b  mov  0x2b, %o0
a00abb30:  92 10 20 0a  mov  0xa, %o1
a00abb34:  94 10 20 01  mov  1, %o2
a00abb38:  96 10 27 42  mov  0x742, %o3
a00abb3c:  40 02 6b d1  call  0xa0146a80
a00abb40:  98 10 20 00  clr  %o4
a00abb44:  94 10 20 01  mov  1, %o2
a00abb48:  96 10 27 42  mov  0x742, %o3
a00abb4c:  98 10 20 00  clr  %o4
a00abb50:  90 10 20 32  mov  0x32, %o0
a00abb54:  40 02 6b cb  call  0xa0146a80
a00abb58:  92 10 20 0a  mov  0xa, %o1
a00abb5c:  90 10 20 ea  mov  0xea, %o0
a00abb60:  40 02 6b fc  call  0xa0146b50
a00abb64:  92 10 20 00  clr  %o1
a00abb68:  d4 0c 20 14  ldub  [ %l0 + 0x14 ], %o2
a00abb6c:  90 10 20 29  mov  0x29, %o0
a00abb70:  40 00 2c d6  call  0xa00b6ec8
a00abb74:  92 10 20 0a  mov  0xa, %o1
a00abb78:  40 00 b6 ed  call  0xa00d972c
a00abb7c:  01 00 00 00  nop
a00abb80:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00abb84:  d6 0a 20 8e  ldub  [ %o0 + 0x8e ], %o3	! 0xa802b08e
a00abb88:  92 12 e0 02  or  %o3, 2, %o1
a00abb8c:  d2 2a 20 8e  stb  %o1, [ %o0 + 0x8e ]
a00abb90:  81 c7 e0 08  ret
a00abb94:  81 e8 00 00  restore
