# leon2m FUN_a0149fb8 0xa0149fb8-0xa014a060 (168 bytes)
a0149fb8:  9d e3 bf 98  save  %sp, -104, %sp
a0149fbc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0149fc0:  80 a6 20 01  cmp  %i0, 1
a0149fc4:  02 80 00 0b  be  0xa0149ff0
a0149fc8:  90 10 20 01  mov  1, %o0
a0149fcc:  80 a6 20 01  cmp  %i0, 1
a0149fd0:  04 80 00 1f  ble  0xa014a04c
a0149fd4:  80 a6 20 02  cmp  %i0, 2
a0149fd8:  02 80 00 06  be  0xa0149ff0
a0149fdc:  90 10 20 02  mov  2, %o0
a0149fe0:  80 a6 20 03  cmp  %i0, 3
a0149fe4:  02 80 00 03  be  0xa0149ff0
a0149fe8:  90 10 20 03  mov  3, %o0
a0149fec:  90 10 3f ff  mov  -1, %o0
a0149ff0:  b2 0a 20 ff  and  %o0, 0xff, %i1
a0149ff4:  80 a6 60 03  cmp  %i1, 3
a0149ff8:  38 80 00 0a  bgu,a   0xa014a020
a0149ffc:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014a000:  90 10 00 19  mov  %i1, %o0
a014a004:  7f ff 94 7a  call  0xa012f1ec
a014a008:  92 10 20 02  mov  2, %o1
a014a00c:  7f ff cb 67  call  0xa013cda8
a014a010:  90 10 00 19  mov  %i1, %o0
a014a014:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014a018:  7f fe fd 17  call  0xa0109474
a014a01c:  93 e8 20 00  restore  %g0, 0, %o1
a014a020:  7f fe 54 54  call  0xa00df170
a014a024:  90 12 21 d8  or  %o0, 0x1d8, %o0
a014a028:  b2 10 20 00  clr  %i1
a014a02c:  90 10 00 19  mov  %i1, %o0
a014a030:  7f ff 94 6f  call  0xa012f1ec
a014a034:  92 10 20 02  mov  2, %o1
a014a038:  7f ff cb 5c  call  0xa013cda8
a014a03c:  90 10 00 19  mov  %i1, %o0
a014a040:  b0 0a 20 ff  and  %o0, 0xff, %i0
a014a044:  7f fe fd 0c  call  0xa0109474
a014a048:  93 e8 20 00  restore  %g0, 0, %o1
a014a04c:  80 a6 20 00  cmp  %i0, 0
a014a050:  02 bf ff e8  be  0xa0149ff0
a014a054:  90 10 20 00  clr  %o0
a014a058:  10 bf ff e6  b  0xa0149ff0
a014a05c:  90 10 3f ff  mov  -1, %o0
