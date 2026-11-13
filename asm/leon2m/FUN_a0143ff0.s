# leon2m FUN_a0143ff0 0xa0143ff0-0xa01440ac (188 bytes)
a0143ff0:  9d e3 bf 98  save  %sp, -104, %sp
a0143ff4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0143ff8:  80 a6 20 01  cmp  %i0, 1
a0143ffc:  02 80 00 0b  be  0xa0144028
a0144000:  98 10 20 01  mov  1, %o4
a0144004:  80 a6 20 01  cmp  %i0, 1
a0144008:  04 80 00 11  ble  0xa014404c
a014400c:  80 a6 20 02  cmp  %i0, 2
a0144010:  02 80 00 06  be  0xa0144028
a0144014:  98 10 20 02  mov  2, %o4
a0144018:  80 a6 20 03  cmp  %i0, 3
a014401c:  02 80 00 03  be  0xa0144028
a0144020:  98 10 20 03  mov  3, %o4
a0144024:  98 10 3f ff  mov  -1, %o4
a0144028:  82 0b 20 ff  and  %o4, 0xff, %g1
a014402c:  80 a0 60 03  cmp  %g1, 3
a0144030:  08 80 00 0d  bleu  0xa0144064
a0144034:  9b 28 60 04  sll  %g1, 4, %o5
a0144038:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a014403c:  7f fe 6c 4d  call  0xa00df170
a0144040:  90 12 21 d8  or  %o0, 0x1d8, %o0	! 0x1a6dd8
a0144044:  10 80 00 07  b  0xa0144060
a0144048:  82 10 20 00  clr  %g1
a014404c:  80 a6 20 00  cmp  %i0, 0
a0144050:  02 bf ff f6  be  0xa0144028
a0144054:  98 10 20 00  clr  %o4
a0144058:  10 bf ff f4  b  0xa0144028
a014405c:  98 10 3f ff  mov  -1, %o4
a0144060:  9b 28 60 04  sll  %g1, 4, %o5
a0144064:  92 23 40 01  sub  %o5, %g1, %o1
a0144068:  03 2a 00 b7  sethi  %hi(0xa802dc00), %g1
a014406c:  b1 2a 60 03  sll  %o1, 3, %i0
a0144070:  90 10 63 30  or  %g1, 0x330, %o0
a0144074:  de 02 00 18  ld  [ %o0 + %i0 ], %o7
a0144078:  99 33 e0 0c  srl  %o7, 0xc, %o4
a014407c:  96 0b 20 0f  and  %o4, 0xf, %o3
a0144080:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0144084:  92 5a e0 2a  smul  %o3, 0x2a, %o1
a0144088:  9a 12 a2 24  or  %o2, 0x224, %o5
a014408c:  82 02 40 0d  add  %o1, %o5, %g1
a0144090:  7f ff f8 36  call  0xa0142168
a0144094:  d0 08 60 0a  ldub  [ %g1 + 0xa ], %o0
a0144098:  7f ff 96 5e  call  0xa0129a10
a014409c:  90 0a 20 ff  and  %o0, 0xff, %o0
a01440a0:  b0 0a 20 ff  and  %o0, 0xff, %i0
a01440a4:  81 c7 e0 08  ret
a01440a8:  81 e8 00 00  restore
