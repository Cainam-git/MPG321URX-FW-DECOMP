# leon2m FUN_a008ec48 0xa008ec48-0xa008ed00 (184 bytes)
a008ec48:  90 0a 20 ff  and  %o0, 0xff, %o0
a008ec4c:  80 a2 20 ff  cmp  %o0, 0xff
a008ec50:  02 80 00 1d  be  0xa008ecc4
a008ec54:  82 0a 60 ff  and  %o1, 0xff, %g1
a008ec58:  19 00 04 01  sethi  %hi(0x100400), %o4
a008ec5c:  94 13 21 1f  or  %o4, 0x11f, %o2	! 0x10051f
a008ec60:  96 10 20 00  clr  %o3
a008ec64:  98 10 20 00  clr  %o4
a008ec68:  9a 03 00 0c  add  %o4, %o4, %o5
a008ec6c:  82 03 40 0a  add  %o5, %o2, %g1
a008ec70:  da 08 60 01  ldub  [ %g1 + 1 ], %o5
a008ec74:  80 a3 40 08  cmp  %o5, %o0
a008ec78:  02 80 00 06  be  0xa008ec90
a008ec7c:  96 02 e0 01  inc  %o3
a008ec80:  98 0a e0 ff  and  %o3, 0xff, %o4
a008ec84:  80 a3 20 0f  cmp  %o4, 0xf
a008ec88:  08 bf ff f9  bleu  0xa008ec6c
a008ec8c:  9a 03 00 0c  add  %o4, %o4, %o5
a008ec90:  98 8b 20 0f  andcc  %o4, 0xf, %o4
a008ec94:  02 80 00 19  be  0xa008ecf8
a008ec98:  92 0a 60 ff  and  %o1, 0xff, %o1
a008ec9c:  80 a2 60 01  cmp  %o1, 1
a008eca0:  22 80 00 0e  be,a   0xa008ecd8
a008eca4:  91 2a 40 0c  sll  %o1, %o4, %o0
a008eca8:  9a 10 20 01  mov  1, %o5
a008ecac:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008ecb0:  95 2b 40 0c  sll  %o5, %o4, %o2
a008ecb4:  d6 10 63 dc  lduh  [ %g1 + 0x3dc ], %o3
a008ecb8:  9a 2a c0 0a  andn  %o3, %o2, %o5
a008ecbc:  10 80 00 0f  b  0xa008ecf8
a008ecc0:  da 30 63 dc  sth  %o5, [ %g1 + 0x3dc ]
a008ecc4:  80 a0 60 01  cmp  %g1, 1
a008ecc8:  02 80 00 08  be  0xa008ece8
a008eccc:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a008ecd0:  10 bf ff e2  b  0xa008ec58
a008ecd4:  c0 32 e3 dc  clrh  [ %o3 + 0x3dc ]	! 0xa802afdc
a008ecd8:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008ecdc:  d2 10 63 dc  lduh  [ %g1 + 0x3dc ], %o1	! 0xa802afdc
a008ece0:  10 bf ff f7  b  0xa008ecbc
a008ece4:  9a 12 00 09  or  %o0, %o1, %o5
a008ece8:  9a 10 3f ff  mov  -1, %o5
a008ecec:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a008ecf0:  10 bf ff da  b  0xa008ec58
a008ecf4:  da 32 a3 dc  sth  %o5, [ %o2 + 0x3dc ]	! 0xa802afdc
a008ecf8:  81 c3 e0 08  retl
a008ecfc:  01 00 00 00  nop
