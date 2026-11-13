# leon2s FUN_a0095f20 0xa0095f20-0xa00961e8 (712 bytes)
a0095f20:  9d e3 bf 98  save  %sp, -104, %sp
a0095f24:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0095f28:  80 a6 60 00  cmp  %i1, 0
a0095f2c:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a0095f30:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0095f34:  96 0e e0 ff  and  %i3, 0xff, %o3
a0095f38:  92 0e a0 ff  and  %i2, 0xff, %o1
a0095f3c:  98 0f 60 ff  and  %i5, 0xff, %o4
a0095f40:  12 80 00 38  bne  0xa0096020
a0095f44:  94 0f 20 ff  and  %i4, 0xff, %o2
a0095f48:  83 2c 60 03  sll  %l1, 3, %g1
a0095f4c:  82 20 40 11  sub  %g1, %l1, %g1
a0095f50:  9a 13 61 80  or  %o5, 0x180, %o5
a0095f54:  83 28 60 02  sll  %g1, 2, %g1
a0095f58:  82 00 40 0d  add  %g1, %o5, %g1
a0095f5c:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a0095f60:  99 32 e0 01  srl  %o3, 1, %o4
a0095f64:  82 10 20 04  mov  4, %g1
a0095f68:  9a 5b 40 0c  smul  %o5, %o4, %o5
a0095f6c:  83 38 40 09  sra  %g1, %o1, %g1
a0095f70:  99 3b 60 1f  sra  %o5, 0x1f, %o4
a0095f74:  81 83 20 00  mov  %o4, %y
a0095f78:  01 00 00 00  nop
a0095f7c:  01 00 00 00  nop
a0095f80:  01 00 00 00  nop
a0095f84:  a0 7b 40 01  sdiv  %o5, %g1, %l0
a0095f88:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095f8c:  92 10 00 10  mov  %l0, %o1
a0095f90:  7f ff 74 2d  call  0xa0073044
a0095f94:  90 12 22 40  or  %o0, 0x240, %o0
a0095f98:  90 10 00 11  mov  %l1, %o0
a0095f9c:  92 10 20 01  mov  1, %o1
a0095fa0:  94 10 20 00  clr  %o2
a0095fa4:  96 10 20 10  mov  0x10, %o3
a0095fa8:  40 00 48 49  call  0xa00a80cc
a0095fac:  98 10 20 00  clr  %o4
a0095fb0:  90 10 00 11  mov  %l1, %o0
a0095fb4:  92 10 20 01  mov  1, %o1
a0095fb8:  94 10 20 05  mov  5, %o2
a0095fbc:  96 10 20 c0  mov  0xc0, %o3
a0095fc0:  40 00 48 43  call  0xa00a80cc
a0095fc4:  98 10 20 01  mov  1, %o4
a0095fc8:  80 a4 20 0c  cmp  %l0, 0xc
a0095fcc:  b4 10 20 02  mov  2, %i2
a0095fd0:  04 80 00 4e  ble  0xa0096108
a0095fd4:  b6 10 20 08  mov  8, %i3
a0095fd8:  80 a4 20 18  cmp  %l0, 0x18
a0095fdc:  04 80 00 4b  ble  0xa0096108
a0095fe0:  b4 10 20 01  mov  1, %i2
a0095fe4:  80 a4 20 31  cmp  %l0, 0x31
a0095fe8:  14 80 00 07  bg  0xa0096004
a0095fec:  80 a4 20 4f  cmp  %l0, 0x4f
a0095ff0:  90 10 00 11  mov  %l1, %o0
a0095ff4:  92 10 20 01  mov  1, %o1
a0095ff8:  94 10 20 00  clr  %o2
a0095ffc:  10 80 00 37  b  0xa00960d8
a0096000:  96 10 20 10  mov  0x10, %o3
a0096004:  b4 10 20 00  clr  %i2
a0096008:  04 80 00 40  ble  0xa0096108
a009600c:  b6 10 20 08  mov  8, %i3
a0096010:  90 10 00 11  mov  %l1, %o0
a0096014:  92 10 20 01  mov  1, %o1
a0096018:  10 80 00 38  b  0xa00960f8
a009601c:  94 10 20 05  mov  5, %o2
a0096020:  83 2c 60 03  sll  %l1, 3, %g1
a0096024:  82 20 40 11  sub  %g1, %l1, %g1
a0096028:  9a 13 61 80  or  %o5, 0x180, %o5
a009602c:  83 28 60 02  sll  %g1, 2, %g1
a0096030:  82 00 40 0d  add  %g1, %o5, %g1
a0096034:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a0096038:  99 33 20 01  srl  %o4, 1, %o4
a009603c:  82 10 20 04  mov  4, %g1
a0096040:  9a 5b 40 0c  smul  %o5, %o4, %o5
a0096044:  83 38 40 0a  sra  %g1, %o2, %g1
a0096048:  99 3b 60 1f  sra  %o5, 0x1f, %o4
a009604c:  81 83 20 00  mov  %o4, %y
a0096050:  01 00 00 00  nop
a0096054:  01 00 00 00  nop
a0096058:  01 00 00 00  nop
a009605c:  a0 7b 40 01  sdiv  %o5, %g1, %l0
a0096060:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0096064:  92 10 00 10  mov  %l0, %o1
a0096068:  7f ff 73 f7  call  0xa0073044
a009606c:  90 12 22 68  or  %o0, 0x268, %o0
a0096070:  90 10 00 11  mov  %l1, %o0
a0096074:  92 10 20 01  mov  1, %o1
a0096078:  94 10 20 80  mov  0x80, %o2
a009607c:  96 10 20 01  mov  1, %o3
a0096080:  40 00 48 13  call  0xa00a80cc
a0096084:  98 10 20 00  clr  %o4
a0096088:  90 10 00 11  mov  %l1, %o0
a009608c:  92 10 20 01  mov  1, %o1
a0096090:  94 10 20 7f  mov  0x7f, %o2
a0096094:  96 10 20 c0  mov  0xc0, %o3
a0096098:  40 00 48 0d  call  0xa00a80cc
a009609c:  98 10 20 01  mov  1, %o4
a00960a0:  80 a4 20 0c  cmp  %l0, 0xc
a00960a4:  b8 10 20 02  mov  2, %i4
a00960a8:  04 80 00 18  ble  0xa0096108
a00960ac:  ba 10 20 08  mov  8, %i5
a00960b0:  80 a4 20 18  cmp  %l0, 0x18
a00960b4:  04 80 00 15  ble  0xa0096108
a00960b8:  b8 10 20 01  mov  1, %i4
a00960bc:  80 a4 20 31  cmp  %l0, 0x31
a00960c0:  14 80 00 08  bg  0xa00960e0
a00960c4:  80 a4 20 4f  cmp  %l0, 0x4f
a00960c8:  90 10 00 11  mov  %l1, %o0
a00960cc:  92 10 20 01  mov  1, %o1
a00960d0:  94 10 20 80  mov  0x80, %o2
a00960d4:  96 10 20 01  mov  1, %o3
a00960d8:  10 80 00 0a  b  0xa0096100
a00960dc:  98 10 20 01  mov  1, %o4
a00960e0:  b8 10 20 00  clr  %i4
a00960e4:  04 80 00 09  ble  0xa0096108
a00960e8:  ba 10 20 08  mov  8, %i5
a00960ec:  90 10 00 11  mov  %l1, %o0
a00960f0:  92 10 20 01  mov  1, %o1
a00960f4:  94 10 20 7f  mov  0x7f, %o2
a00960f8:  96 10 20 c0  mov  0xc0, %o3
a00960fc:  98 10 20 00  clr  %o4
a0096100:  40 00 47 f3  call  0xa00a80cc
a0096104:  01 00 00 00  nop
a0096108:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009610c:  92 0e a0 ff  and  %i2, 0xff, %o1
a0096110:  7f ff de 1c  call  0xa008d980
a0096114:  90 10 00 18  mov  %i0, %o0
a0096118:  90 10 00 18  mov  %i0, %o0
a009611c:  7f ff de 01  call  0xa008d920
a0096120:  92 0e e0 ff  and  %i3, 0xff, %o1
a0096124:  90 10 00 18  mov  %i0, %o0
a0096128:  7f ff de 43  call  0xa008da34
a009612c:  92 0f 20 ff  and  %i4, 0xff, %o1
a0096130:  90 10 00 18  mov  %i0, %o0
a0096134:  7f ff de 28  call  0xa008d9d4
a0096138:  92 0f 60 ff  and  %i5, 0xff, %o1
a009613c:  80 a6 60 00  cmp  %i1, 0
a0096140:  12 80 00 18  bne  0xa00961a0
a0096144:  94 10 20 00  clr  %o2
a0096148:  92 10 20 01  mov  1, %o1
a009614c:  40 00 47 a3  call  0xa00a7fd8
a0096150:  90 10 00 18  mov  %i0, %o0
a0096154:  92 0a 20 ff  and  %o0, 0xff, %o1
a0096158:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a009615c:  7f ff 73 ba  call  0xa0073044
a0096160:  90 12 22 90  or  %o0, 0x290, %o0	! 0xa0069690
a0096164:  94 10 20 05  mov  5, %o2
a0096168:  90 10 00 18  mov  %i0, %o0
a009616c:  40 00 47 9b  call  0xa00a7fd8
a0096170:  92 10 20 01  mov  1, %o1
a0096174:  92 0a 20 ff  and  %o0, 0xff, %o1
a0096178:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a009617c:  7f ff 73 b2  call  0xa0073044
a0096180:  90 12 22 b0  or  %o0, 0x2b0, %o0	! 0xa00696b0
a0096184:  90 10 00 18  mov  %i0, %o0
a0096188:  92 10 20 01  mov  1, %o1
a009618c:  94 10 20 06  mov  6, %o2
a0096190:  40 00 47 92  call  0xa00a7fd8
a0096194:  31 28 01 a5  sethi  %hi(0xa0069400), %i0
a0096198:  10 80 00 10  b  0xa00961d8
a009619c:  b0 16 22 d0  or  %i0, 0x2d0, %i0	! 0xa00696d0
a00961a0:  94 10 20 80  mov  0x80, %o2
a00961a4:  92 10 20 01  mov  1, %o1
a00961a8:  40 00 47 8c  call  0xa00a7fd8
a00961ac:  90 10 00 18  mov  %i0, %o0
a00961b0:  92 0a 20 ff  and  %o0, 0xff, %o1
a00961b4:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a00961b8:  7f ff 73 a3  call  0xa0073044
a00961bc:  90 12 22 f0  or  %o0, 0x2f0, %o0	! 0xa00696f0
a00961c0:  90 10 00 18  mov  %i0, %o0
a00961c4:  92 10 20 01  mov  1, %o1
a00961c8:  94 10 20 7f  mov  0x7f, %o2
a00961cc:  40 00 47 83  call  0xa00a7fd8
a00961d0:  31 28 01 a5  sethi  %hi(0xa0069400), %i0
a00961d4:  b0 16 23 10  or  %i0, 0x310, %i0	! 0xa0069710
a00961d8:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00961dc:  7f ff 73 9a  call  0xa0073044
a00961e0:  81 e8 00 00  restore
a00961e4:  01 00 00 00  nop
