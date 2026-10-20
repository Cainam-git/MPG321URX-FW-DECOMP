# leon2m FUN_a0146dfc 0xa0146dfc-0xa0146e24 (40 bytes)
a0146dfc:  9d e3 bf 98  save  %sp, -104, %sp
a0146e00:  7f ff 4a db  call  0xa011996c
a0146e04:  90 0e 20 ff  and  %i0, 0xff, %o0
a0146e08:  80 8a 20 ff  btst  0xff, %o0
a0146e0c:  02 80 00 03  be  0xa0146e18
a0146e10:  b0 10 20 00  clr  %i0
a0146e14:  b0 10 20 01  mov  1, %i0
a0146e18:  b0 0e 20 01  and  %i0, 1, %i0
a0146e1c:  81 c7 e0 08  ret
a0146e20:  81 e8 00 00  restore
