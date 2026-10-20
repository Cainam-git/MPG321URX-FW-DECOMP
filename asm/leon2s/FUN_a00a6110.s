# leon2s FUN_a00a6110 0xa00a6110-0xa00a6190 (128 bytes)
a00a6110:  90 0a 20 ff  and  %o0, 0xff, %o0
a00a6114:  82 02 00 08  add  %o0, %o0, %g1
a00a6118:  82 00 40 08  add  %g1, %o0, %g1
a00a611c:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00a6120:  9a 13 60 04  or  %o5, 4, %o5	! 0xa807dc04
a00a6124:  83 28 60 02  sll  %g1, 2, %g1
a00a6128:  82 00 40 0d  add  %g1, %o5, %g1
a00a612c:  d8 00 60 04  ld  [ %g1 + 4 ], %o4
a00a6130:  c2 03 20 0c  ld  [ %o4 + 0xc ], %g1
a00a6134:  1b 00 00 3f  sethi  %hi(0xfc00), %o5
a00a6138:  96 13 63 ff  or  %o5, 0x3ff, %o3	! 0xffff
a00a613c:  83 30 60 10  srl  %g1, 0x10, %g1
a00a6140:  80 88 40 0b  btst  %g1, %o3
a00a6144:  02 80 00 11  be  0xa00a6188
a00a6148:  90 10 20 01  mov  1, %o0
a00a614c:  da 03 20 08  ld  [ %o4 + 8 ], %o5
a00a6150:  c2 03 20 0c  ld  [ %o4 + 0xc ], %g1
a00a6154:  9b 33 60 10  srl  %o5, 0x10, %o5
a00a6158:  83 30 60 10  srl  %g1, 0x10, %g1
a00a615c:  82 08 40 0b  and  %g1, %o3, %g1
a00a6160:  9a 0b 40 0b  and  %o5, %o3, %o5
a00a6164:  81 80 00 00  mov  %g0, %y
a00a6168:  01 00 00 00  nop
a00a616c:  01 00 00 00  nop
a00a6170:  01 00 00 00  nop
a00a6174:  90 73 40 01  udiv  %o5, %g1, %o0
a00a6178:  80 8a 20 ff  btst  0xff, %o0
a00a617c:  12 80 00 03  bne  0xa00a6188
a00a6180:  01 00 00 00  nop
a00a6184:  90 10 20 01  mov  1, %o0	! 0x1
a00a6188:  81 c3 e0 08  retl
a00a618c:  90 0a 20 ff  and  %o0, 0xff, %o0
