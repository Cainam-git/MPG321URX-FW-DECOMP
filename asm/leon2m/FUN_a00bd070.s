# leon2m FUN_a00bd070 0xa00bd070-0xa00bd1d4 (356 bytes)
a00bd070:  9d e3 bf 98  save  %sp, -104, %sp
a00bd074:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bd078:  11 2a 00 b5  sethi  %hi(0xa802d400), %o0
a00bd07c:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bd080:  82 10 20 30  mov  0x30, %g1
a00bd084:  d8 0a 20 11  ldub  [ %o0 + 0x11 ], %o4
a00bd088:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bd08c:  80 a3 20 07  cmp  %o4, 7
a00bd090:  18 80 00 0b  bgu  0xa00bd0bc
a00bd094:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bd098:  17 00 01 68  sethi  %hi(0x5a000), %o3
a00bd09c:  93 2b 20 02  sll  %o4, 2, %o1
a00bd0a0:  94 12 e3 e8  or  %o3, 0x3e8, %o2
a00bd0a4:  d8 02 80 09  ld  [ %o2 + %o1 ], %o4
a00bd0a8:  81 c3 00 00  jmp  %o4
a00bd0ac:  01 00 00 00  nop
a00bd0b0:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bd0b4:  82 10 20 37  mov  0x37, %g1
a00bd0b8:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bd0bc:  92 10 20 00  clr  %o1
a00bd0c0:  40 02 5d 5f  call  0xa015463c
a00bd0c4:  90 10 20 23  mov  0x23, %o0
a00bd0c8:  a0 16 a0 78  or  %i2, 0x78, %l0
a00bd0cc:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bd0d0:  b2 10 20 62  mov  0x62, %i1
a00bd0d4:  92 10 20 02  mov  2, %o1
a00bd0d8:  f2 2c 20 01  stb  %i1, [ %l0 + 1 ]
a00bd0dc:  40 02 5d 58  call  0xa015463c
a00bd0e0:  90 10 20 23  mov  0x23, %o0
a00bd0e4:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00bd0e8:  92 10 20 03  mov  3, %o1
a00bd0ec:  40 02 5d 54  call  0xa015463c
a00bd0f0:  90 10 20 23  mov  0x23, %o0
a00bd0f4:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00bd0f8:  92 10 20 04  mov  4, %o1
a00bd0fc:  40 02 5d 50  call  0xa015463c
a00bd100:  90 10 20 23  mov  0x23, %o0
a00bd104:  d0 2c 20 04  stb  %o0, [ %l0 + 4 ]
a00bd108:  92 10 20 05  mov  5, %o1
a00bd10c:  40 02 5d 4c  call  0xa015463c
a00bd110:  90 10 20 23  mov  0x23, %o0
a00bd114:  d0 2c 20 05  stb  %o0, [ %l0 + 5 ]
a00bd118:  90 10 20 23  mov  0x23, %o0
a00bd11c:  40 02 5d 48  call  0xa015463c
a00bd120:  92 10 20 06  mov  6, %o1
a00bd124:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bd128:  9e 10 20 0d  mov  0xd, %o7
a00bd12c:  de 2c 20 0a  stb  %o7, [ %l0 + 0xa ]
a00bd130:  80 a6 20 02  cmp  %i0, 2
a00bd134:  02 80 00 10  be  0xa00bd174
a00bd138:  d0 2c 20 06  stb  %o0, [ %l0 + 6 ]
a00bd13c:  80 a6 20 03  cmp  %i0, 3
a00bd140:  02 80 00 19  be  0xa00bd1a4
a00bd144:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bd148:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bd14c:  9a 12 a0 d0  or  %o2, 0xd0, %o5
a00bd150:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]
a00bd154:  c0 2a a0 d0  clrb  [ %o2 + 0xd0 ]
a00bd158:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bd15c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bd160:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bd164:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bd168:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd16c:  40 02 2d 9f  call  0xa01487e8
a00bd170:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd174:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bd178:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00bd17c:  9a 12 20 40  or  %o0, 0x40, %o5
a00bd180:  c0 28 60 9a  clrb  [ %g1 + 0x9a ]
a00bd184:  c0 2a 20 40  clrb  [ %o0 + 0x40 ]
a00bd188:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bd18c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bd190:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bd194:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bd198:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd19c:  40 02 2d 93  call  0xa01487e8
a00bd1a0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bd1a4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bd1a8:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00bd1ac:  9a 13 20 98  or  %o4, 0x98, %o5
a00bd1b0:  c0 2a 60 98  clrb  [ %o1 + 0x98 ]
a00bd1b4:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]
a00bd1b8:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bd1bc:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bd1c0:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bd1c4:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bd1c8:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bd1cc:  40 02 2d 87  call  0xa01487e8
a00bd1d0:  93 e8 20 0b  restore  %g0, 0xb, %o1
