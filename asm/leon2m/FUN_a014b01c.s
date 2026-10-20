# leon2m FUN_a014b01c 0xa014b01c-0xa014b0c4 (168 bytes)
a014b01c:  9d e3 bf 98  save  %sp, -104, %sp
a014b020:  7f ff 68 5e  call  0xa0125198
a014b024:  90 0e 20 ff  and  %i0, 0xff, %o0
a014b028:  7f ff dc 7c  call  0xa0142218
a014b02c:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b030:  7f ff dc 65  call  0xa01421c4
a014b034:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b038:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b03c:  80 a2 20 61  cmp  %o0, 0x61
a014b040:  02 80 00 1d  be  0xa014b0b4
a014b044:  9a 10 20 00  clr  %o5
a014b048:  80 a2 20 61  cmp  %o0, 0x61
a014b04c:  04 80 00 08  ble  0xa014b06c
a014b050:  9e 0b 60 03  and  %o5, 3, %o7
a014b054:  80 a2 20 71  cmp  %o0, 0x71
a014b058:  02 80 00 19  be  0xa014b0bc
a014b05c:  80 a2 20 81  cmp  %o0, 0x81
a014b060:  22 80 00 02  be,a   0xa014b068
a014b064:  9a 10 20 03  mov  3, %o5
a014b068:  9e 0b 60 03  and  %o5, 3, %o7
a014b06c:  99 2b e0 03  sll  %o7, 3, %o4
a014b070:  96 03 00 0f  add  %o4, %o7, %o3
a014b074:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014b078:  90 02 c0 0b  add  %o3, %o3, %o0
a014b07c:  9a 12 a1 16  or  %o2, 0x116, %o5
a014b080:  92 02 00 0d  add  %o0, %o5, %o1
a014b084:  7f ff 68 28  call  0xa0125124
a014b088:  d0 0a 60 10  ldub  [ %o1 + 0x10 ], %o0
a014b08c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a014b090:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014b094:  90 10 00 10  mov  %l0, %o0
a014b098:  7f ff 69 51  call  0xa01255dc
a014b09c:  92 10 00 19  mov  %i1, %o1
a014b0a0:  82 10 20 01  mov  1, %g1
a014b0a4:  b1 28 40 10  sll  %g1, %l0, %i0
a014b0a8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a014b0ac:  7f ff a3 74  call  0xa0133e7c
a014b0b0:  81 e8 00 00  restore
a014b0b4:  10 bf ff ed  b  0xa014b068
a014b0b8:  9a 10 20 01  mov  1, %o5
a014b0bc:  10 bf ff eb  b  0xa014b068
a014b0c0:  9a 10 20 02  mov  2, %o5
