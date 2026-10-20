# leon2m FUN_a00d9fdc 0xa00d9fdc-0xa00da184 (424 bytes)
a00d9fdc:  9d e3 bf 98  save  %sp, -104, %sp
a00d9fe0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d9fe4:  80 a6 20 00  cmp  %i0, 0
a00d9fe8:  02 80 00 38  be  0xa00da0c8
a00d9fec:  80 a6 20 01  cmp  %i0, 1
a00d9ff0:  02 80 00 20  be  0xa00da070
a00d9ff4:  90 10 20 02  mov  2, %o0
a00d9ff8:  7f ff fe 80  call  0xa00d99f8
a00d9ffc:  92 10 20 01  mov  1, %o1
a00da000:  94 10 23 e8  mov  0x3e8, %o2
a00da004:  90 10 20 04  mov  4, %o0
a00da008:  40 01 c2 33  call  0xa014a8d4
a00da00c:  92 10 20 01  mov  1, %o1
a00da010:  90 10 20 00  clr  %o0
a00da014:  40 01 b8 95  call  0xa0148268
a00da018:  92 10 20 01  mov  1, %o1
a00da01c:  90 10 20 01  mov  1, %o0
a00da020:  40 01 b8 92  call  0xa0148268
a00da024:  92 10 20 01  mov  1, %o1
a00da028:  90 10 20 0f  mov  0xf, %o0
a00da02c:  40 01 de 9e  call  0xa0151aa4
a00da030:  92 10 20 01  mov  1, %o1
a00da034:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00da038:  d4 02 e0 84  ld  [ %o3 + 0x84 ], %o2	! 0xa802d484
a00da03c:  80 a2 a0 00  cmp  %o2, 0
a00da040:  16 80 00 32  bge  0xa00da108
a00da044:  01 00 00 00  nop
a00da048:  40 01 c1 a6  call  0xa014a6e0
a00da04c:  90 10 20 0c  mov  0xc, %o0	! 0xc
a00da050:  80 8a 20 ff  btst  0xff, %o0
a00da054:  12 80 00 45  bne  0xa00da168
a00da058:  90 10 20 0c  mov  0xc, %o0
a00da05c:  40 01 c1 7e  call  0xa014a654
a00da060:  92 10 20 01  mov  1, %o1
a00da064:  b0 10 20 0d  mov  0xd, %i0
a00da068:  40 01 c1 7b  call  0xa014a654
a00da06c:  93 e8 20 01  restore  %g0, 1, %o1
a00da070:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a00da074:  da 00 60 84  ld  [ %g1 + 0x84 ], %o5	! 0xa802d484
a00da078:  80 a3 60 00  cmp  %o5, 0
a00da07c:  06 80 00 30  bl  0xa00da13c
a00da080:  01 00 00 00  nop
a00da084:  40 01 c1 97  call  0xa014a6e0
a00da088:  90 10 20 0c  mov  0xc, %o0	! 0xc
a00da08c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00da090:  80 a2 20 01  cmp  %o0, 1
a00da094:  02 80 00 08  be  0xa00da0b4
a00da098:  90 10 20 0c  mov  0xc, %o0
a00da09c:  40 01 c1 91  call  0xa014a6e0
a00da0a0:  90 10 20 0d  mov  0xd, %o0
a00da0a4:  92 0a 20 ff  and  %o0, 0xff, %o1
a00da0a8:  80 a2 60 01  cmp  %o1, 1
a00da0ac:  12 80 00 34  bne  0xa00da17c
a00da0b0:  90 10 20 0c  mov  0xc, %o0
a00da0b4:  40 01 c1 68  call  0xa014a654
a00da0b8:  92 10 20 00  clr  %o1
a00da0bc:  b0 10 20 0d  mov  0xd, %i0
a00da0c0:  40 01 c1 65  call  0xa014a654
a00da0c4:  93 e8 20 00  restore  %g0, 0, %o1
a00da0c8:  90 10 20 00  clr  %o0
a00da0cc:  7f ff fe 4b  call  0xa00d99f8
a00da0d0:  92 10 20 01  mov  1, %o1
a00da0d4:  94 10 23 e8  mov  0x3e8, %o2
a00da0d8:  90 10 20 04  mov  4, %o0
a00da0dc:  40 01 c1 fe  call  0xa014a8d4
a00da0e0:  92 10 20 01  mov  1, %o1
a00da0e4:  90 10 20 00  clr  %o0
a00da0e8:  40 01 b8 60  call  0xa0148268
a00da0ec:  92 10 20 01  mov  1, %o1
a00da0f0:  90 10 20 01  mov  1, %o0
a00da0f4:  40 01 b8 5d  call  0xa0148268
a00da0f8:  92 10 20 01  mov  1, %o1
a00da0fc:  b0 10 20 0f  mov  0xf, %i0
a00da100:  40 01 de 69  call  0xa0151aa4
a00da104:  93 e8 20 01  restore  %g0, 1, %o1
a00da108:  40 01 c1 76  call  0xa014a6e0
a00da10c:  90 10 20 0c  mov  0xc, %o0
a00da110:  98 0a 20 ff  and  %o0, 0xff, %o4
a00da114:  80 a3 20 01  cmp  %o4, 1
a00da118:  02 bf ff e7  be  0xa00da0b4
a00da11c:  90 10 20 0c  mov  0xc, %o0
a00da120:  40 01 c1 70  call  0xa014a6e0
a00da124:  90 10 20 0d  mov  0xd, %o0
a00da128:  9e 0a 20 ff  and  %o0, 0xff, %o7
a00da12c:  80 a3 e0 01  cmp  %o7, 1
a00da130:  12 80 00 13  bne  0xa00da17c
a00da134:  90 10 20 0c  mov  0xc, %o0
a00da138:  30 bf ff df  b,a   0xa00da0b4
a00da13c:  40 01 c1 69  call  0xa014a6e0
a00da140:  90 10 20 0c  mov  0xc, %o0
a00da144:  80 8a 20 ff  btst  0xff, %o0
a00da148:  02 bf ff c5  be  0xa00da05c
a00da14c:  90 10 20 0c  mov  0xc, %o0
a00da150:  40 01 c1 64  call  0xa014a6e0
a00da154:  90 10 20 0d  mov  0xd, %o0
a00da158:  80 8a 20 ff  btst  0xff, %o0
a00da15c:  02 bf ff c0  be  0xa00da05c
a00da160:  90 10 20 0c  mov  0xc, %o0
a00da164:  30 80 00 06  b,a   0xa00da17c
a00da168:  40 01 c1 5e  call  0xa014a6e0
a00da16c:  90 10 20 0d  mov  0xd, %o0
a00da170:  80 8a 20 ff  btst  0xff, %o0
a00da174:  02 bf ff ba  be  0xa00da05c
a00da178:  90 10 20 0c  mov  0xc, %o0
a00da17c:  81 c7 e0 08  ret
a00da180:  81 e8 00 00  restore
