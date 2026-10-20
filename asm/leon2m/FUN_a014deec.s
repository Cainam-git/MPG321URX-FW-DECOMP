# leon2m FUN_a014deec 0xa014deec-0xa014df68 (124 bytes)
a014deec:  9d e3 bf 98  save  %sp, -104, %sp
a014def0:  7f ff 5c aa  call  0xa0125198
a014def4:  90 0e 20 ff  and  %i0, 0xff, %o0
a014def8:  7f ff d0 c8  call  0xa0142218
a014defc:  90 0a 20 ff  and  %o0, 0xff, %o0
a014df00:  7f ff d0 b1  call  0xa01421c4
a014df04:  90 0a 20 ff  and  %o0, 0xff, %o0
a014df08:  82 0a 20 ff  and  %o0, 0xff, %g1
a014df0c:  b0 10 20 00  clr  %i0
a014df10:  90 10 20 10  mov  0x10, %o0
a014df14:  80 a0 60 71  cmp  %g1, 0x71
a014df18:  02 80 00 0e  be  0xa014df50
a014df1c:  92 10 20 01  mov  1, %o1
a014df20:  80 a0 60 81  cmp  %g1, 0x81
a014df24:  02 80 00 08  be  0xa014df44
a014df28:  b0 10 3f ff  mov  -1, %i0
a014df2c:  82 0e 20 ff  and  %i0, 0xff, %g1
a014df30:  80 a0 60 ff  cmp  %g1, 0xff
a014df34:  02 80 00 0b  be  0xa014df60
a014df38:  b0 10 00 01  mov  %g1, %i0
a014df3c:  7f ff 76 52  call  0xa012b884
a014df40:  81 e8 00 00  restore
a014df44:  b0 10 20 01  mov  1, %i0
a014df48:  90 10 20 20  mov  0x20, %o0
a014df4c:  92 10 20 01  mov  1, %o1
a014df50:  40 00 0e d5  call  0xa0151aa4
a014df54:  01 00 00 00  nop
a014df58:  10 bf ff f6  b  0xa014df30
a014df5c:  82 0e 20 ff  and  %i0, 0xff, %g1
a014df60:  81 c7 e0 08  ret
a014df64:  81 e8 00 00  restore
