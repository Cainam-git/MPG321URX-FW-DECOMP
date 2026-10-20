# leon2m FUN_a014e050 0xa014e050-0xa014e144 (244 bytes)
a014e050:  9d e3 bf 98  save  %sp, -104, %sp
a014e054:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014e058:  15 00 00 08  sethi  %hi(0x2000), %o2
a014e05c:  94 12 a0 40  or  %o2, 0x40, %o2	! 0x2040
a014e060:  90 10 20 2a  mov  0x2a, %o0
a014e064:  80 a6 20 01  cmp  %i0, 1
a014e068:  02 80 00 08  be  0xa014e088
a014e06c:  92 10 20 00  clr  %o1
a014e070:  7f ff ae c8  call  0xa0139b90
a014e074:  01 00 00 00  nop
a014e078:  7f ff b2 45  call  0xa013a98c
a014e07c:  90 10 00 18  mov  %i0, %o0
a014e080:  7f ff ab 97  call  0xa0138edc
a014e084:  81 e8 00 00  restore
a014e088:  7f ff ac da  call  0xa01393f0
a014e08c:  01 00 00 00  nop
a014e090:  7f ff b2 3f  call  0xa013a98c
a014e094:  90 10 00 18  mov  %i0, %o0
a014e098:  7f ff ab 91  call  0xa0138edc
a014e09c:  81 e8 00 00  restore
a014e0a0:  01 00 00 00  nop
a014e0a4:  82 0a 20 ff  and  %o0, 0xff, %g1
a014e0a8:  80 a0 60 02  cmp  %g1, 2
a014e0ac:  02 80 00 06  be  0xa014e0c4
a014e0b0:  90 10 20 02  mov  2, %o0
a014e0b4:  80 a0 60 01  cmp  %g1, 1
a014e0b8:  02 80 00 03  be  0xa014e0c4
a014e0bc:  90 10 20 01  mov  1, %o0
a014e0c0:  90 10 20 00  clr  %o0
a014e0c4:  82 13 c0 00  mov  %o7, %g1
a014e0c8:  7f fe df 0f  call  0xa0105d04
a014e0cc:  9e 10 40 00  mov  %g1, %o7
a014e0d0:  01 00 00 00  nop
a014e0d4:  90 0a 20 ff  and  %o0, 0xff, %o0
a014e0d8:  80 a2 20 01  cmp  %o0, 1
a014e0dc:  22 80 00 0a  be,a   0xa014e104
a014e0e0:  90 10 20 00  clr  %o0
a014e0e4:  04 80 00 11  ble  0xa014e128
a014e0e8:  80 a2 20 02  cmp  %o0, 2
a014e0ec:  02 80 00 0a  be  0xa014e114
a014e0f0:  80 a2 20 03  cmp  %o0, 3
a014e0f4:  12 80 00 12  bne  0xa014e13c
a014e0f8:  90 10 20 01  mov  1, %o0
a014e0fc:  10 80 00 03  b  0xa014e108
a014e100:  92 10 20 01  mov  1, %o1
a014e104:  92 10 20 01  mov  1, %o1
a014e108:  82 13 c0 00  mov  %o7, %g1
a014e10c:  7f fe f3 2d  call  0xa010adc0
a014e110:  9e 10 40 00  mov  %g1, %o7
a014e114:  90 10 20 01  mov  1, %o0
a014e118:  92 10 20 00  clr  %o1
a014e11c:  82 13 c0 00  mov  %o7, %g1
a014e120:  7f fe f3 28  call  0xa010adc0
a014e124:  9e 10 40 00  mov  %g1, %o7
a014e128:  80 a2 20 00  cmp  %o0, 0
a014e12c:  12 80 00 04  bne  0xa014e13c
a014e130:  90 10 20 00  clr  %o0
a014e134:  10 bf ff fa  b  0xa014e11c
a014e138:  92 10 20 00  clr  %o1
a014e13c:  81 c3 e0 08  retl
a014e140:  01 00 00 00  nop
