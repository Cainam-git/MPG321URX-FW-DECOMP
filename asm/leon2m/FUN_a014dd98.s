# leon2m FUN_a014dd98 0xa014dd98-0xa014de48 (176 bytes)
a014dd98:  90 0a 20 ff  and  %o0, 0xff, %o0
a014dd9c:  80 a2 20 01  cmp  %o0, 1
a014dda0:  02 80 00 0b  be  0xa014ddcc
a014dda4:  98 10 20 01  mov  1, %o4
a014dda8:  80 a2 20 01  cmp  %o0, 1
a014ddac:  04 80 00 20  ble  0xa014de2c
a014ddb0:  80 a2 20 02  cmp  %o0, 2
a014ddb4:  02 80 00 06  be  0xa014ddcc
a014ddb8:  98 10 20 02  mov  2, %o4
a014ddbc:  80 a2 20 03  cmp  %o0, 3
a014ddc0:  02 80 00 03  be  0xa014ddcc
a014ddc4:  98 10 20 03  mov  3, %o4
a014ddc8:  98 10 3f ff  mov  -1, %o4
a014ddcc:  90 0b 20 ff  and  %o4, 0xff, %o0
a014ddd0:  80 a2 20 04  cmp  %o0, 4
a014ddd4:  18 80 00 1b  bgu  0xa014de40
a014ddd8:  97 2a 20 04  sll  %o0, 4, %o3
a014dddc:  98 22 c0 08  sub  %o3, %o0, %o4
a014dde0:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a014dde4:  97 2b 20 03  sll  %o4, 3, %o3
a014dde8:  82 13 63 30  or  %o5, 0x330, %g1
a014ddec:  da 00 40 0b  ld  [ %g1 + %o3 ], %o5
a014ddf0:  99 33 60 0c  srl  %o5, 0xc, %o4
a014ddf4:  9a 0b 20 0f  and  %o4, 0xf, %o5
a014ddf8:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014ddfc:  96 12 e2 24  or  %o3, 0x224, %o3	! 0xa802e224
a014de00:  9a 5b 60 2a  smul  %o5, 0x2a, %o5
a014de04:  d8 12 c0 0d  lduh  [ %o3 + %o5 ], %o4
a014de08:  82 0a 60 01  and  %o1, 1, %g1
a014de0c:  83 28 60 04  sll  %g1, 4, %g1
a014de10:  98 0b 3f ef  and  %o4, -17, %o4
a014de14:  98 13 00 01  or  %o4, %g1, %o4
a014de18:  d8 32 c0 0d  sth  %o4, [ %o3 + %o5 ]
a014de1c:  92 0a 60 ff  and  %o1, 0xff, %o1
a014de20:  82 13 c0 00  mov  %o7, %g1
a014de24:  7f ff 8d 2c  call  0xa01312d4
a014de28:  9e 10 40 00  mov  %g1, %o7
a014de2c:  80 a2 20 00  cmp  %o0, 0
a014de30:  02 bf ff e7  be  0xa014ddcc
a014de34:  98 10 20 00  clr  %o4
a014de38:  10 bf ff e5  b  0xa014ddcc
a014de3c:  98 10 3f ff  mov  -1, %o4
a014de40:  81 c3 e0 08  retl
a014de44:  01 00 00 00  nop
