# leon2m FUN_a00d9120 0xa00d9120-0xa00d91fc (220 bytes)
a00d9120:  9d e3 bf 98  save  %sp, -104, %sp
a00d9124:  40 01 cb 13  call  0xa014bd70
a00d9128:  90 10 20 00  clr  %o0
a00d912c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d9130:  80 a2 20 01  cmp  %o0, 1
a00d9134:  02 80 00 24  be  0xa00d91c4
a00d9138:  01 00 00 00  nop
a00d913c:  40 01 a9 e8  call  0xa01438dc
a00d9140:  90 10 20 00  clr  %o0	! 0x0
a00d9144:  82 0a 20 ff  and  %o0, 0xff, %g1
a00d9148:  80 a0 60 01  cmp  %g1, 1
a00d914c:  02 80 00 11  be  0xa00d9190
a00d9150:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d9154:  b0 12 62 90  or  %o1, 0x290, %i0	! 0xa802d290
a00d9158:  da 0e 21 5b  ldub  [ %i0 + 0x15b ], %o5
a00d915c:  80 a3 60 04  cmp  %o5, 4
a00d9160:  02 80 00 06  be  0xa00d9178
a00d9164:  15 00 00 20  sethi  %hi(0x8000), %o2
a00d9168:  d6 06 21 74  ld  [ %i0 + 0x174 ], %o3
a00d916c:  80 8a c0 0a  btst  %o3, %o2
a00d9170:  02 80 00 19  be  0xa00d91d4
a00d9174:  01 00 00 00  nop
a00d9178:  40 01 ca e5  call  0xa014bd0c
a00d917c:  90 10 20 02  mov  2, %o0	! 0x2
a00d9180:  67 fe d4 49  call  0x4008e2a4
a00d9184:  b0 10 20 00  clr  %i0
a00d9188:  7f fe ba f5  call  0xa0087d5c
a00d918c:  81 e8 00 00  restore
a00d9190:  40 01 ca 36  call  0xa014ba68
a00d9194:  01 00 00 00  nop
a00d9198:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d919c:  80 a2 20 02  cmp  %o0, 2
a00d91a0:  02 80 00 09  be  0xa00d91c4
a00d91a4:  01 00 00 00  nop
a00d91a8:  04 80 00 12  ble  0xa00d91f0
a00d91ac:  80 a2 20 01  cmp  %o0, 1
a00d91b0:  80 a2 20 03  cmp  %o0, 3
a00d91b4:  02 80 00 04  be  0xa00d91c4
a00d91b8:  80 a2 20 04  cmp  %o0, 4
a00d91bc:  12 bf ff e6  bne  0xa00d9154
a00d91c0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d91c4:  40 01 ca d2  call  0xa014bd0c
a00d91c8:  90 10 20 00  clr  %o0
a00d91cc:  10 bf ff ef  b  0xa00d9188
a00d91d0:  b0 10 20 00  clr  %i0
a00d91d4:  40 01 ca ce  call  0xa014bd0c
a00d91d8:  90 10 20 00  clr  %o0
a00d91dc:  67 fe d4 32  call  0x4008e2a4
a00d91e0:  01 00 00 00  nop
a00d91e4:  f0 0e 21 5b  ldub  [ %i0 + 0x15b ], %i0
a00d91e8:  7f fe ba dd  call  0xa0087d5c
a00d91ec:  81 e8 00 00  restore
a00d91f0:  12 bf ff d9  bne  0xa00d9154
a00d91f4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00d91f8:  30 bf ff f3  b,a   0xa00d91c4
