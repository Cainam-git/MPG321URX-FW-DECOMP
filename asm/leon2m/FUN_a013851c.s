# leon2m FUN_a013851c 0xa013851c-0xa0138554 (56 bytes)
a013851c:  9d e3 bf 90  save  %sp, -112, %sp
a0138520:  c0 27 bf f0  clr  [ %fp + -16 ]
a0138524:  f0 2f bf f0  stb  %i0, [ %fp + -16 ]
a0138528:  90 10 20 fd  mov  0xfd, %o0
a013852c:  92 10 20 04  mov  4, %o1
a0138530:  94 07 bf f0  add  %fp, -16, %o2
a0138534:  7f ff fa ea  call  0xa01370dc
a0138538:  96 10 20 00  clr  %o3
a013853c:  7f ff fb 82  call  0xa0137344
a0138540:  90 10 20 01  mov  1, %o0
a0138544:  03 2a 00 b2  sethi  %hi(0xa802c800), %g1
a0138548:  f0 08 63 a3  ldub  [ %g1 + 0x3a3 ], %i0	! 0xa802cba3
a013854c:  81 c7 e0 08  ret
a0138550:  81 e8 00 00  restore
