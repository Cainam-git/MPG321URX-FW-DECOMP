# leon2m FUN_a0138110 0xa0138110-0xa0138148 (56 bytes)
a0138110:  9d e3 bf 90  save  %sp, -112, %sp
a0138114:  90 10 20 5f  mov  0x5f, %o0
a0138118:  92 10 20 04  mov  4, %o1
a013811c:  94 07 bf f0  add  %fp, -16, %o2
a0138120:  96 10 20 00  clr  %o3
a0138124:  80 8e 20 ff  btst  0xff, %i0
a0138128:  12 80 00 05  bne  0xa013813c
a013812c:  c0 27 bf f0  clr  [ %fp + -16 ]
a0138130:  f0 2f bf f0  stb  %i0, [ %fp + -16 ]
a0138134:  7f ff fb ea  call  0xa01370dc
a0138138:  f2 2f bf f1  stb  %i1, [ %fp + -15 ]
a013813c:  01 00 00 00  nop
a0138140:  81 c7 e0 08  ret
a0138144:  81 e8 00 00  restore
