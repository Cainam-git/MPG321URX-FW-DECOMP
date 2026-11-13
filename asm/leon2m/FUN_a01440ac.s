# leon2m FUN_a01440ac 0xa01440ac-0xa0144114 (104 bytes)
a01440ac:  9d e3 bf 98  save  %sp, -104, %sp
a01440b0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01440b4:  80 a6 20 61  cmp  %i0, 0x61
a01440b8:  02 80 00 0f  be  0xa01440f4
a01440bc:  90 10 3f ff  mov  -1, %o0
a01440c0:  80 a6 20 61  cmp  %i0, 0x61
a01440c4:  14 80 00 07  bg  0xa01440e0
a01440c8:  80 a6 20 71  cmp  %i0, 0x71
a01440cc:  80 a6 20 51  cmp  %i0, 0x51
a01440d0:  12 80 00 0c  bne  0xa0144100
a01440d4:  01 00 00 00  nop
a01440d8:  10 80 00 0a  b  0xa0144100
a01440dc:  90 10 20 00  clr  %o0	! 0x0
a01440e0:  02 80 00 07  be  0xa01440fc
a01440e4:  80 a6 20 81  cmp  %i0, 0x81
a01440e8:  22 80 00 06  be,a   0xa0144100
a01440ec:  90 10 20 03  mov  3, %o0
a01440f0:  30 80 00 04  b,a   0xa0144100
a01440f4:  10 80 00 03  b  0xa0144100
a01440f8:  90 10 20 01  mov  1, %o0
a01440fc:  90 10 20 02  mov  2, %o0
a0144100:  7f ff 96 44  call  0xa0129a10
a0144104:  90 0a 20 ff  and  %o0, 0xff, %o0
a0144108:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014410c:  81 c7 e0 08  ret
a0144110:  81 e8 00 00  restore
