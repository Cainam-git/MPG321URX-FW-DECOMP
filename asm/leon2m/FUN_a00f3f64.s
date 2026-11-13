# leon2m FUN_a00f3f64 0xa00f3f64-0xa00f40e4 (384 bytes)
a00f3f64:  9d e3 bf 98  save  %sp, -104, %sp
a00f3f68:  7f ff fe 1a  call  0xa00f37d0
a00f3f6c:  90 10 20 00  clr  %o0
a00f3f70:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00f3f74:  90 10 00 18  mov  %i0, %o0
a00f3f78:  92 10 20 36  mov  0x36, %o1
a00f3f7c:  7f ff f6 d6  call  0xa00f1ad4
a00f3f80:  94 10 20 42  mov  0x42, %o2
a00f3f84:  a8 10 20 00  clr  %l4
a00f3f88:  a6 10 3f ff  mov  -1, %l3
a00f3f8c:  a2 10 20 04  mov  4, %l1
a00f3f90:  2b 2a 00 ad  sethi  %hi(0xa802b400), %l5
a00f3f94:  2d 2a 00 ad  sethi  %hi(0xa802b400), %l6
a00f3f98:  da 0d 63 b1  ldub  [ %l5 + 0x3b1 ], %o5
a00f3f9c:  90 0b 60 ff  and  %o5, 0xff, %o0
a00f3fa0:  80 a2 20 63  cmp  %o0, 0x63
a00f3fa4:  18 80 00 06  bgu  0xa00f3fbc
a00f3fa8:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f3fac:  d8 00 63 9c  ld  [ %g1 + 0x39c ], %o4	! 0xa802b79c
a00f3fb0:  80 a3 20 00  cmp  %o4, 0
a00f3fb4:  12 80 00 47  bne  0xa00f40d0
a00f3fb8:  92 03 60 01  add  %o5, 1, %o1
a00f3fbc:  67 fe 65 73  call  0x4008d588
a00f3fc0:  a4 10 20 00  clr  %l2
a00f3fc4:  a0 10 00 08  mov  %o0, %l0
a00f3fc8:  40 00 b4 eb  call  0xa0121374
a00f3fcc:  90 10 00 18  mov  %i0, %o0
a00f3fd0:  82 0a 20 ff  and  %o0, 0xff, %g1
a00f3fd4:  92 10 20 36  mov  0x36, %o1
a00f3fd8:  80 a0 60 01  cmp  %g1, 1
a00f3fdc:  02 80 00 38  be  0xa00f40bc
a00f3fe0:  90 10 00 18  mov  %i0, %o0
a00f3fe4:  7f ff f6 ab  call  0xa00f1a90
a00f3fe8:  01 00 00 00  nop
a00f3fec:  95 2c 20 10  sll  %l0, 0x10, %o2
a00f3ff0:  80 8a 20 02  btst  2, %o0
a00f3ff4:  02 80 00 35  be  0xa00f40c8
a00f3ff8:  91 32 a0 10  srl  %o2, 0x10, %o0
a00f3ffc:  67 fe 65 66  call  0x4008d594
a00f4000:  01 00 00 00  nop
a00f4004:  97 2a 20 10  sll  %o0, 0x10, %o3
a00f4008:  91 32 e0 10  srl  %o3, 0x10, %o0
a00f400c:  80 a2 20 63  cmp  %o0, 0x63
a00f4010:  08 bf ff ee  bleu  0xa00f3fc8
a00f4014:  01 00 00 00  nop
a00f4018:  80 8c a0 ff  btst  0xff, %l2
a00f401c:  02 80 00 28  be  0xa00f40bc
a00f4020:  82 10 20 01  mov  1, %g1
a00f4024:  7f ff fd eb  call  0xa00f37d0
a00f4028:  90 0c 60 ff  and  %l1, 0xff, %o0
a00f402c:  94 10 20 42  mov  0x42, %o2
a00f4030:  90 10 00 18  mov  %i0, %o0
a00f4034:  7f ff f6 a8  call  0xa00f1ad4
a00f4038:  92 10 20 36  mov  0x36, %o1
a00f403c:  92 10 20 45  mov  0x45, %o1
a00f4040:  7f ff f7 29  call  0xa00f1ce4
a00f4044:  90 10 00 18  mov  %i0, %o0
a00f4048:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00f404c:  90 10 00 18  mov  %i0, %o0
a00f4050:  7f ff f7 25  call  0xa00f1ce4
a00f4054:  92 10 20 43  mov  0x43, %o1
a00f4058:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00f405c:  99 33 60 10  srl  %o5, 0x10, %o4
a00f4060:  a0 04 00 0c  add  %l0, %o4, %l0
a00f4064:  80 a4 00 13  cmp  %l0, %l3
a00f4068:  1a 80 00 07  bcc  0xa00f4084
a00f406c:  80 a4 00 14  cmp  %l0, %l4
a00f4070:  a6 04 7f fc  add  %l1, -4, %l3
a00f4074:  a4 0c e0 3f  and  %l3, 0x3f, %l2
a00f4078:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00f407c:  e4 2b e3 af  stb  %l2, [ %o7 + 0x3af ]	! 0xa802b7af
a00f4080:  a6 10 00 10  mov  %l0, %l3
a00f4084:  28 80 00 08  bleu,a   0xa00f40a4
a00f4088:  a2 04 60 04  add  %l1, 4, %l1
a00f408c:  92 04 7f fc  add  %l1, -4, %o1
a00f4090:  29 2a 00 ad  sethi  %hi(0xa802b400), %l4
a00f4094:  82 0a 60 3f  and  %o1, 0x3f, %g1
a00f4098:  c2 2d 23 b0  stb  %g1, [ %l4 + 0x3b0 ]
a00f409c:  a8 10 00 10  mov  %l0, %l4
a00f40a0:  a2 04 60 04  add  %l1, 4, %l1
a00f40a4:  94 0c 60 ff  and  %l1, 0xff, %o2
a00f40a8:  80 a2 a0 41  cmp  %o2, 0x41
a00f40ac:  08 bf ff bc  bleu  0xa00f3f9c
a00f40b0:  da 0d 63 b1  ldub  [ %l5 + 0x3b1 ], %o5
a00f40b4:  10 80 00 0a  b  0xa00f40dc
a00f40b8:  b0 25 00 13  sub  %l4, %l3, %i0
a00f40bc:  c2 2d a3 ac  stb  %g1, [ %l6 + 0x3ac ]
a00f40c0:  10 80 00 07  b  0xa00f40dc
a00f40c4:  b0 10 20 00  clr  %i0
a00f40c8:  10 bf ff d4  b  0xa00f4018
a00f40cc:  a4 10 20 01  mov  1, %l2
a00f40d0:  9f c3 00 00  call  %o4
a00f40d4:  d2 2d 63 b1  stb  %o1, [ %l5 + 0x3b1 ]
a00f40d8:  30 bf ff b9  b,a   0xa00f3fbc
a00f40dc:  81 c7 e0 08  ret
a00f40e0:  81 e8 00 00  restore
