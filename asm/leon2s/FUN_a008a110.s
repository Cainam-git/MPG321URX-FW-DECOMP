# leon2s FUN_a008a110 0xa008a110-0xa008a1b4 (164 bytes)
a008a110:  9d e3 bf 98  save  %sp, -104, %sp
a008a114:  97 2e a0 06  sll  %i2, 6, %o3
a008a118:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008a11c:  a0 0e 60 ff  and  %i1, 0xff, %l0
a008a120:  92 10 20 03  mov  3, %o1
a008a124:  94 10 20 40  mov  0x40, %o2
a008a128:  96 0a e0 c0  and  %o3, 0xc0, %o3
a008a12c:  80 a6 20 0c  cmp  %i0, 0xc
a008a130:  02 80 00 07  be  0xa008a14c
a008a134:  90 10 00 10  mov  %l0, %o0
a008a138:  97 2e a0 06  sll  %i2, 6, %o3
a008a13c:  80 a6 20 0e  cmp  %i0, 0xe
a008a140:  02 80 00 0f  be  0xa008a17c
a008a144:  96 0a e0 c0  and  %o3, 0xc0, %o3
a008a148:  30 80 00 19  b,a   0xa008a1ac
a008a14c:  40 00 74 2c  call  0xa00a71fc
a008a150:  01 00 00 00  nop
a008a154:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008a158:  98 10 63 70  or  %g1, 0x370, %o4	! 0xcf014770
a008a15c:  9a 04 20 04  add  %l0, 4, %o5
a008a160:  82 10 20 01  mov  1, %g1
a008a164:  80 8e a0 ff  btst  0xff, %i2
a008a168:  02 80 00 11  be  0xa008a1ac
a008a16c:  91 28 40 0d  sll  %g1, %o5, %o0
a008a170:  c2 03 00 00  ld  [ %o4 ], %g1
a008a174:  10 80 00 0d  b  0xa008a1a8
a008a178:  82 28 40 08  andn  %g1, %o0, %g1
a008a17c:  40 00 74 20  call  0xa00a71fc
a008a180:  01 00 00 00  nop
a008a184:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008a188:  98 10 63 70  or  %g1, 0x370, %o4	! 0xcf014770
a008a18c:  9a 04 20 04  add  %l0, 4, %o5
a008a190:  82 10 20 01  mov  1, %g1
a008a194:  80 8e a0 ff  btst  0xff, %i2
a008a198:  02 80 00 05  be  0xa008a1ac
a008a19c:  91 28 40 0d  sll  %g1, %o5, %o0
a008a1a0:  c2 03 00 00  ld  [ %o4 ], %g1
a008a1a4:  82 10 40 08  or  %g1, %o0, %g1
a008a1a8:  c2 23 00 00  st  %g1, [ %o4 ]
a008a1ac:  81 c7 e0 08  ret
a008a1b0:  81 e8 00 00  restore
