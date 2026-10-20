# leon2m FUN_a014a11c 0xa014a11c-0xa014a210 (244 bytes)
a014a11c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a014a120:  82 0a 60 ff  and  %o1, 0xff, %g1
a014a124:  90 58 60 c8  smul  %g1, 0xc8, %o0
a014a128:  03 14 7a e1  sethi  %hi(0x51eb8400), %g1
a014a12c:  82 10 61 1f  or  %g1, 0x11f, %g1	! 0x51eb851f
a014a130:  90 02 20 32  add  %o0, 0x32, %o0
a014a134:  80 52 00 01  umul  %o0, %g1, %g0
a014a138:  91 40 00 00  rd  %y, %o0
a014a13c:  91 32 20 05  srl  %o0, 5, %o0
a014a140:  82 02 20 38  add  %o0, 0x38, %g1
a014a144:  91 28 60 10  sll  %g1, 0x10, %o0
a014a148:  80 a3 60 01  cmp  %o5, 1
a014a14c:  02 80 00 09  be  0xa014a170
a014a150:  91 32 20 10  srl  %o0, 0x10, %o0
a014a154:  80 a3 60 01  cmp  %o5, 1
a014a158:  04 80 00 19  ble  0xa014a1bc
a014a15c:  80 a3 60 02  cmp  %o5, 2
a014a160:  12 80 00 29  bne  0xa014a204
a014a164:  9a 0a 60 ff  and  %o1, 0xff, %o5
a014a168:  10 80 00 07  b  0xa014a184
a014a16c:  90 5b 60 c8  smul  %o5, 0xc8, %o0
a014a170:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a014a174:  d2 28 63 dd  stb  %o1, [ %g1 + 0x3dd ]	! 0xa802e3dd
a014a178:  82 13 c0 00  mov  %o7, %g1
a014a17c:  7f ff c4 b4  call  0xa013b44c
a014a180:  9e 10 40 00  mov  %g1, %o7
a014a184:  19 14 7a e1  sethi  %hi(0x51eb8400), %o4
a014a188:  9a 02 20 32  add  %o0, 0x32, %o5
a014a18c:  82 13 21 1f  or  %o4, 0x11f, %g1
a014a190:  80 53 40 01  umul  %o5, %g1, %g0
a014a194:  99 40 00 00  rd  %y, %o4
a014a198:  83 33 20 05  srl  %o4, 5, %g1
a014a19c:  90 00 60 38  add  %g1, 0x38, %o0
a014a1a0:  99 2a 20 10  sll  %o0, 0x10, %o4
a014a1a4:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a014a1a8:  d2 2b 63 de  stb  %o1, [ %o5 + 0x3de ]	! 0xa802e3de
a014a1ac:  91 33 20 10  srl  %o4, 0x10, %o0
a014a1b0:  82 13 c0 00  mov  %o7, %g1
a014a1b4:  7f ff c4 ae  call  0xa013b46c
a014a1b8:  9e 10 40 00  mov  %g1, %o7
a014a1bc:  80 a3 60 00  cmp  %o5, 0
a014a1c0:  12 80 00 11  bne  0xa014a204
a014a1c4:  9a 0a 60 ff  and  %o1, 0xff, %o5
a014a1c8:  90 5b 60 c8  smul  %o5, 0xc8, %o0
a014a1cc:  19 14 7a e1  sethi  %hi(0x51eb8400), %o4
a014a1d0:  9a 02 20 32  add  %o0, 0x32, %o5
a014a1d4:  82 13 21 1f  or  %o4, 0x11f, %g1
a014a1d8:  80 53 40 01  umul  %o5, %g1, %g0
a014a1dc:  99 40 00 00  rd  %y, %o4
a014a1e0:  83 33 20 05  srl  %o4, 5, %g1
a014a1e4:  90 00 60 38  add  %g1, 0x38, %o0
a014a1e8:  99 2a 20 10  sll  %o0, 0x10, %o4
a014a1ec:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a014a1f0:  d2 2b 63 dc  stb  %o1, [ %o5 + 0x3dc ]	! 0xa802e3dc
a014a1f4:  91 33 20 10  srl  %o4, 0x10, %o0
a014a1f8:  82 13 c0 00  mov  %o7, %g1
a014a1fc:  7f ff c4 8c  call  0xa013b42c
a014a200:  9e 10 40 00  mov  %g1, %o7
a014a204:  01 00 00 00  nop
a014a208:  81 c3 e0 08  retl
a014a20c:  01 00 00 00  nop
