# leon2m FUN_a008ed00 0xa008ed00-0xa008edb8 (184 bytes)
a008ed00:  90 0a 20 ff  and  %o0, 0xff, %o0
a008ed04:  80 a2 20 ff  cmp  %o0, 0xff
a008ed08:  02 80 00 1d  be  0xa008ed7c
a008ed0c:  82 0a 60 ff  and  %o1, 0xff, %g1
a008ed10:  19 00 04 01  sethi  %hi(0x100400), %o4
a008ed14:  94 13 21 1f  or  %o4, 0x11f, %o2	! 0x10051f
a008ed18:  96 10 20 00  clr  %o3
a008ed1c:  98 10 20 00  clr  %o4
a008ed20:  9a 03 00 0c  add  %o4, %o4, %o5
a008ed24:  82 03 40 0a  add  %o5, %o2, %g1
a008ed28:  da 08 60 01  ldub  [ %g1 + 1 ], %o5
a008ed2c:  80 a3 40 08  cmp  %o5, %o0
a008ed30:  02 80 00 06  be  0xa008ed48
a008ed34:  96 02 e0 01  inc  %o3
a008ed38:  98 0a e0 ff  and  %o3, 0xff, %o4
a008ed3c:  80 a3 20 0f  cmp  %o4, 0xf
a008ed40:  08 bf ff f9  bleu  0xa008ed24
a008ed44:  9a 03 00 0c  add  %o4, %o4, %o5
a008ed48:  98 8b 20 0f  andcc  %o4, 0xf, %o4
a008ed4c:  02 80 00 19  be  0xa008edb0
a008ed50:  92 0a 60 ff  and  %o1, 0xff, %o1
a008ed54:  80 a2 60 01  cmp  %o1, 1
a008ed58:  22 80 00 0e  be,a   0xa008ed90
a008ed5c:  91 2a 40 0c  sll  %o1, %o4, %o0
a008ed60:  9a 10 20 01  mov  1, %o5
a008ed64:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008ed68:  95 2b 40 0c  sll  %o5, %o4, %o2
a008ed6c:  d6 10 63 da  lduh  [ %g1 + 0x3da ], %o3
a008ed70:  9a 2a c0 0a  andn  %o3, %o2, %o5
a008ed74:  10 80 00 0f  b  0xa008edb0
a008ed78:  da 30 63 da  sth  %o5, [ %g1 + 0x3da ]
a008ed7c:  80 a0 60 01  cmp  %g1, 1
a008ed80:  02 80 00 08  be  0xa008eda0
a008ed84:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a008ed88:  10 bf ff e2  b  0xa008ed10
a008ed8c:  c0 32 e3 da  clrh  [ %o3 + 0x3da ]	! 0xa802afda
a008ed90:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008ed94:  d2 10 63 da  lduh  [ %g1 + 0x3da ], %o1	! 0xa802afda
a008ed98:  10 bf ff f7  b  0xa008ed74
a008ed9c:  9a 12 00 09  or  %o0, %o1, %o5
a008eda0:  9a 10 3f ff  mov  -1, %o5
a008eda4:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a008eda8:  10 bf ff da  b  0xa008ed10
a008edac:  da 32 a3 da  sth  %o5, [ %o2 + 0x3da ]	! 0xa802afda
a008edb0:  81 c3 e0 08  retl
a008edb4:  01 00 00 00  nop
