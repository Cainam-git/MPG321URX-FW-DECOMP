# leon2m FUN_a008edb8 0xa008edb8-0xa008ee6c (180 bytes)
a008edb8:  90 0a 20 ff  and  %o0, 0xff, %o0
a008edbc:  80 a2 20 ff  cmp  %o0, 0xff
a008edc0:  02 80 00 1e  be  0xa008ee38
a008edc4:  80 8a 60 ff  btst  0xff, %o1
a008edc8:  17 00 04 01  sethi  %hi(0x100400), %o3
a008edcc:  94 12 e1 1f  or  %o3, 0x11f, %o2	! 0x10051f
a008edd0:  96 10 20 00  clr  %o3
a008edd4:  98 10 20 00  clr  %o4
a008edd8:  9a 03 00 0c  add  %o4, %o4, %o5
a008eddc:  82 03 40 0a  add  %o5, %o2, %g1
a008ede0:  da 08 60 01  ldub  [ %g1 + 1 ], %o5
a008ede4:  80 a3 40 08  cmp  %o5, %o0
a008ede8:  02 80 00 06  be  0xa008ee00
a008edec:  96 02 e0 01  inc  %o3
a008edf0:  98 0a e0 ff  and  %o3, 0xff, %o4
a008edf4:  80 a3 20 0f  cmp  %o4, 0xf
a008edf8:  08 bf ff f9  bleu  0xa008eddc
a008edfc:  9a 03 00 0c  add  %o4, %o4, %o5
a008ee00:  98 8b 20 0f  andcc  %o4, 0xf, %o4
a008ee04:  02 80 00 18  be  0xa008ee64
a008ee08:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a008ee0c:  90 12 a3 c8  or  %o2, 0x3c8, %o0	! 0xa802afc8
a008ee10:  80 8a 60 ff  btst  0xff, %o1
a008ee14:  02 80 00 0e  be  0xa008ee4c
a008ee18:  d2 2a 00 0c  stb  %o1, [ %o0 + %o4 ]
a008ee1c:  96 10 20 01  mov  1, %o3
a008ee20:  93 2a c0 0c  sll  %o3, %o4, %o1
a008ee24:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008ee28:  d8 10 63 d8  lduh  [ %g1 + 0x3d8 ], %o4	! 0xa802afd8
a008ee2c:  9a 12 40 0c  or  %o1, %o4, %o5
a008ee30:  10 80 00 0d  b  0xa008ee64
a008ee34:  da 30 63 d8  sth  %o5, [ %g1 + 0x3d8 ]
a008ee38:  32 bf ff e5  bne,a   0xa008edcc
a008ee3c:  17 00 04 01  sethi  %hi(0x100400), %o3
a008ee40:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008ee44:  10 bf ff e1  b  0xa008edc8
a008ee48:  c0 30 63 d8  clrh  [ %g1 + 0x3d8 ]	! 0xa802afd8
a008ee4c:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a008ee50:  94 10 20 01  mov  1, %o2
a008ee54:  9b 2a 80 0c  sll  %o2, %o4, %o5
a008ee58:  d0 10 63 d8  lduh  [ %g1 + 0x3d8 ], %o0
a008ee5c:  10 bf ff f5  b  0xa008ee30
a008ee60:  9a 2a 00 0d  andn  %o0, %o5, %o5
a008ee64:  81 c3 e0 08  retl
a008ee68:  01 00 00 00  nop
