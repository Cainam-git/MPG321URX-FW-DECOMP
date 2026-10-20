# leon2m FUN_a014b1c8 0xa014b1c8-0xa014b280 (184 bytes)
a014b1c8:  9d e3 bf 90  save  %sp, -112, %sp
a014b1cc:  f6 37 bf f6  sth  %i3, [ %fp + -10 ]
a014b1d0:  7f ff 67 f2  call  0xa0125198
a014b1d4:  90 0e 20 ff  and  %i0, 0xff, %o0
a014b1d8:  7f ff dc 10  call  0xa0142218
a014b1dc:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b1e0:  7f ff db f9  call  0xa01421c4
a014b1e4:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b1e8:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b1ec:  80 a2 20 61  cmp  %o0, 0x61
a014b1f0:  02 80 00 0c  be  0xa014b220
a014b1f4:  9a 10 20 00  clr  %o5
a014b1f8:  80 a2 20 61  cmp  %o0, 0x61
a014b1fc:  04 80 00 0f  ble  0xa014b238
a014b200:  9e 0b 60 03  and  %o5, 3, %o7
a014b204:  80 a2 20 71  cmp  %o0, 0x71
a014b208:  02 80 00 0a  be  0xa014b230
a014b20c:  80 a2 20 81  cmp  %o0, 0x81
a014b210:  32 80 00 0b  bne,a   0xa014b23c
a014b214:  99 2b e0 03  sll  %o7, 3, %o4
a014b218:  10 80 00 04  b  0xa014b228
a014b21c:  9a 10 20 03  mov  3, %o5
a014b220:  10 80 00 05  b  0xa014b234
a014b224:  9a 10 20 01  mov  1, %o5
a014b228:  10 80 00 04  b  0xa014b238
a014b22c:  9e 0b 60 03  and  %o5, 3, %o7
a014b230:  9a 10 20 02  mov  2, %o5
a014b234:  9e 0b 60 03  and  %o5, 3, %o7
a014b238:  99 2b e0 03  sll  %o7, 3, %o4
a014b23c:  96 03 00 0f  add  %o4, %o7, %o3
a014b240:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a014b244:  90 02 c0 0b  add  %o3, %o3, %o0
a014b248:  9a 12 a1 16  or  %o2, 0x116, %o5
a014b24c:  82 02 00 0d  add  %o0, %o5, %g1
a014b250:  7f ff 67 b5  call  0xa0125124
a014b254:  d0 08 60 10  ldub  [ %g1 + 0x10 ], %o0
a014b258:  93 2e 60 10  sll  %i1, 0x10, %o1
a014b25c:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b260:  93 32 60 10  srl  %o1, 0x10, %o1
a014b264:  94 10 00 1a  mov  %i2, %o2
a014b268:  96 07 bf f6  add  %fp, -10, %o3
a014b26c:  7f ff 84 2d  call  0xa012c320
a014b270:  98 10 20 01  mov  1, %o4
a014b274:  01 00 00 00  nop
a014b278:  81 c7 e0 08  ret
a014b27c:  81 e8 00 00  restore
