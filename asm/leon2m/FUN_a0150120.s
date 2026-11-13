# leon2m FUN_a0150120 0xa0150120-0xa0150230 (272 bytes)
a0150120:  9d e3 bf 98  save  %sp, -104, %sp
a0150124:  11 00 06 9c  sethi  %hi(0x1a7000), %o0
a0150128:  b0 0e 20 ff  and  %i0, 0xff, %i0
a015012c:  90 12 23 80  or  %o0, 0x380, %o0
a0150130:  80 a6 20 01  cmp  %i0, 1
a0150134:  02 80 00 13  be  0xa0150180
a0150138:  b2 0e 60 ff  and  %i1, 0xff, %i1
a015013c:  7f fe 3c 0d  call  0xa00df170
a0150140:  b0 10 20 1f  mov  0x1f, %i0
a0150144:  1b 2a 00 a9  sethi  %hi(0xa802a400), %o5
a0150148:  7f ff 38 00  call  0xa011e148
a015014c:  d0 0b 60 9a  ldub  [ %o5 + 0x9a ], %o0	! 0xa802a49a
a0150150:  7f ff ff 4a  call  0xa014fe78
a0150154:  90 10 20 00  clr  %o0
a0150158:  7f ff fe 54  call  0xa014faa8
a015015c:  b2 10 20 01  mov  1, %i1
a0150160:  90 10 20 1f  mov  0x1f, %o0
a0150164:  7f ff 38 2f  call  0xa011e220
a0150168:  92 10 20 01  mov  1, %o1
a015016c:  90 10 20 1f  mov  0x1f, %o0
a0150170:  7f ff 38 86  call  0xa011e388
a0150174:  92 10 20 01  mov  1, %o1
a0150178:  7f ff 37 ac  call  0xa011e028
a015017c:  81 e8 00 00  restore
a0150180:  03 00 06 9c  sethi  %hi(0x1a7000), %g1
a0150184:  90 10 63 98  or  %g1, 0x398, %o0	! 0x1a7398
a0150188:  80 a6 60 01  cmp  %i1, 1
a015018c:  02 80 00 15  be  0xa01501e0
a0150190:  31 2a 00 a9  sethi  %hi(0xa802a400), %i0
a0150194:  19 00 06 9c  sethi  %hi(0x1a7000), %o4
a0150198:  7f fe 3b f6  call  0xa00df170
a015019c:  90 13 23 b0  or  %o4, 0x3b0, %o0	! 0x1a73b0
a01501a0:  17 2a 00 a9  sethi  %hi(0xa802a400), %o3
a01501a4:  7f ff 37 e9  call  0xa011e148
a01501a8:  d0 0a e0 9a  ldub  [ %o3 + 0x9a ], %o0	! 0xa802a49a
a01501ac:  90 10 20 01  mov  1, %o0
a01501b0:  7f ff ff 32  call  0xa014fe78
a01501b4:  b0 10 20 1f  mov  0x1f, %i0
a01501b8:  7f ff fe 3c  call  0xa014faa8
a01501bc:  b2 10 20 01  mov  1, %i1
a01501c0:  90 10 20 1f  mov  0x1f, %o0
a01501c4:  7f ff 38 17  call  0xa011e220
a01501c8:  92 10 20 01  mov  1, %o1
a01501cc:  90 10 20 1f  mov  0x1f, %o0
a01501d0:  7f ff 38 6e  call  0xa011e388
a01501d4:  92 10 20 01  mov  1, %o1
a01501d8:  7f ff 37 94  call  0xa011e028
a01501dc:  81 e8 00 00  restore
a01501e0:  7f fe 3b e4  call  0xa00df170
a01501e4:  01 00 00 00  nop
a01501e8:  d0 0e 20 9a  ldub  [ %i0 + 0x9a ], %o0
a01501ec:  7f ff 37 8f  call  0xa011e028
a01501f0:  92 10 20 01  mov  1, %o1
a01501f4:  d0 0e 20 9a  ldub  [ %i0 + 0x9a ], %o0
a01501f8:  7f ff 38 0a  call  0xa011e220
a01501fc:  92 10 20 01  mov  1, %o1
a0150200:  15 2a 00 a9  sethi  %hi(0xa802a400), %o2
a0150204:  d2 12 a0 9e  lduh  [ %o2 + 0x9e ], %o1	! 0xa802a49e
a0150208:  7f ff 36 e5  call  0xa011dd9c
a015020c:  d0 0e 20 9a  ldub  [ %i0 + 0x9a ], %o0
a0150210:  13 2a 00 a9  sethi  %hi(0xa802a400), %o1
a0150214:  d4 12 60 a0  lduh  [ %o1 + 0xa0 ], %o2	! 0xa802a4a0
a0150218:  d0 0e 20 9a  ldub  [ %i0 + 0x9a ], %o0
a015021c:  92 10 20 ff  mov  0xff, %o1
a0150220:  7f ff 35 4a  call  0xa011d748
a0150224:  96 10 20 00  clr  %o3
a0150228:  10 bf ff e2  b  0xa01501b0
a015022c:  90 10 20 01  mov  1, %o0
