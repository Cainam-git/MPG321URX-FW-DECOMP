# leon2m FUN_a008ee6c 0xa008ee6c-0xa008ef24 (184 bytes)
a008ee6c:  90 0a 20 ff  and  %o0, 0xff, %o0
a008ee70:  80 a2 20 ff  cmp  %o0, 0xff
a008ee74:  02 80 00 1d  be  0xa008eee8
a008ee78:  82 0a 60 ff  and  %o1, 0xff, %g1
a008ee7c:  19 00 04 01  sethi  %hi(0x100400), %o4
a008ee80:  94 13 21 1f  or  %o4, 0x11f, %o2	! 0x10051f
a008ee84:  96 10 20 00  clr  %o3
a008ee88:  98 10 20 00  clr  %o4
a008ee8c:  9a 03 00 0c  add  %o4, %o4, %o5
a008ee90:  82 03 40 0a  add  %o5, %o2, %g1
a008ee94:  da 08 60 01  ldub  [ %g1 + 1 ], %o5
a008ee98:  80 a3 40 08  cmp  %o5, %o0
a008ee9c:  02 80 00 06  be  0xa008eeb4
a008eea0:  96 02 e0 01  inc  %o3
a008eea4:  98 0a e0 ff  and  %o3, 0xff, %o4
a008eea8:  80 a3 20 0f  cmp  %o4, 0xf
a008eeac:  08 bf ff f9  bleu  0xa008ee90
a008eeb0:  9a 03 00 0c  add  %o4, %o4, %o5
a008eeb4:  98 8b 20 0f  andcc  %o4, 0xf, %o4
a008eeb8:  02 80 00 19  be  0xa008ef1c
a008eebc:  92 0a 60 ff  and  %o1, 0xff, %o1
a008eec0:  80 a2 60 01  cmp  %o1, 1
a008eec4:  22 80 00 0e  be,a   0xa008eefc
a008eec8:  91 2a 40 0c  sll  %o1, %o4, %o0
a008eecc:  9a 10 20 01  mov  1, %o5
a008eed0:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008eed4:  95 2b 40 0c  sll  %o5, %o4, %o2
a008eed8:  d6 10 63 c0  lduh  [ %g1 + 0x3c0 ], %o3
a008eedc:  9a 2a c0 0a  andn  %o3, %o2, %o5
a008eee0:  10 80 00 0f  b  0xa008ef1c
a008eee4:  da 30 63 c0  sth  %o5, [ %g1 + 0x3c0 ]
a008eee8:  80 a0 60 01  cmp  %g1, 1
a008eeec:  02 80 00 08  be  0xa008ef0c
a008eef0:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a008eef4:  10 bf ff e2  b  0xa008ee7c
a008eef8:  c0 32 e3 c0  clrh  [ %o3 + 0x3c0 ]	! 0xa802afc0
a008eefc:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008ef00:  d2 10 63 c0  lduh  [ %g1 + 0x3c0 ], %o1	! 0xa802afc0
a008ef04:  10 bf ff f7  b  0xa008eee0
a008ef08:  9a 12 00 09  or  %o0, %o1, %o5
a008ef0c:  9a 10 3f ff  mov  -1, %o5
a008ef10:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a008ef14:  10 bf ff da  b  0xa008ee7c
a008ef18:  da 32 a3 c0  sth  %o5, [ %o2 + 0x3c0 ]	! 0xa802afc0
a008ef1c:  81 c3 e0 08  retl
a008ef20:  01 00 00 00  nop
