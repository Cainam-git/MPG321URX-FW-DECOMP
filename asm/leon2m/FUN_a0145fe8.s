# leon2m FUN_a0145fe8 0xa0145fe8-0xa0146108 (288 bytes)
a0145fe8:  9d e3 bf 98  save  %sp, -104, %sp
a0145fec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0145ff0:  80 a6 20 01  cmp  %i0, 1
a0145ff4:  02 80 00 0b  be  0xa0146020
a0145ff8:  82 10 20 01  mov  1, %g1
a0145ffc:  80 a6 20 01  cmp  %i0, 1
a0146000:  04 80 00 2b  ble  0xa01460ac
a0146004:  80 a6 20 02  cmp  %i0, 2
a0146008:  02 80 00 06  be  0xa0146020
a014600c:  82 10 20 02  mov  2, %g1
a0146010:  80 a6 20 03  cmp  %i0, 3
a0146014:  02 80 00 03  be  0xa0146020
a0146018:  82 10 20 03  mov  3, %g1
a014601c:  82 10 3f ff  mov  -1, %g1
a0146020:  a0 08 60 ff  and  %g1, 0xff, %l0
a0146024:  80 a4 20 03  cmp  %l0, 3
a0146028:  18 80 00 36  bgu  0xa0146100
a014602c:  01 00 00 00  nop
a0146030:  7f fe f6 0b  call  0xa010385c
a0146034:  90 10 20 00  clr  %o0	! 0x0
a0146038:  80 8f 20 ff  btst  0xff, %i4
a014603c:  12 80 00 21  bne  0xa01460c0
a0146040:  b9 2c 20 04  sll  %l0, 4, %i4
a0146044:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0146048:  b4 0e a0 ff  and  %i2, 0xff, %i2
a014604c:  b6 0e e0 ff  and  %i3, 0xff, %i3
a0146050:  23 2a 00 b7  sethi  %hi(0xa802dc00), %l1
a0146054:  92 27 00 10  sub  %i4, %l0, %o1
a0146058:  a1 2a 60 03  sll  %o1, 3, %l0
a014605c:  a2 14 63 30  or  %l1, 0x330, %l1
a0146060:  d0 04 40 10  ld  [ %l1 + %l0 ], %o0
a0146064:  b9 32 20 0c  srl  %o0, 0xc, %i4
a0146068:  90 0f 20 0f  and  %i4, 0xf, %o0
a014606c:  92 10 00 19  mov  %i1, %o1
a0146070:  94 10 00 1a  mov  %i2, %o2
a0146074:  7f fe f5 e5  call  0xa0103808
a0146078:  96 10 00 1b  mov  %i3, %o3
a014607c:  de 04 40 10  ld  [ %l1 + %l0 ], %o7
a0146080:  99 33 e0 0c  srl  %o7, 0xc, %o4
a0146084:  96 10 00 1b  mov  %i3, %o3
a0146088:  90 0b 20 0f  and  %o4, 0xf, %o0
a014608c:  92 10 00 19  mov  %i1, %o1
a0146090:  7f ff 4a 7c  call  0xa0118a80
a0146094:  94 10 00 1a  mov  %i2, %o2
a0146098:  d6 04 40 10  ld  [ %l1 + %l0 ], %o3
a014609c:  b1 32 e0 0c  srl  %o3, 0xc, %i0
a01460a0:  b0 0e 20 0f  and  %i0, 0xf, %i0
a01460a4:  7f ff 12 91  call  0xa010aae8
a01460a8:  81 e8 00 00  restore
a01460ac:  80 a6 20 00  cmp  %i0, 0
a01460b0:  02 bf ff dc  be  0xa0146020
a01460b4:  82 10 20 00  clr  %g1
a01460b8:  10 bf ff da  b  0xa0146020
a01460bc:  82 10 3f ff  mov  -1, %g1
a01460c0:  94 27 00 10  sub  %i4, %l0, %o2
a01460c4:  23 2a 00 b7  sethi  %hi(0xa802dc00), %l1
a01460c8:  83 2a a0 03  sll  %o2, 3, %g1
a01460cc:  9a 14 63 30  or  %l1, 0x330, %o5
a01460d0:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a01460d4:  91 32 60 0c  srl  %o1, 0xc, %o0
a01460d8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a01460dc:  b4 0e a0 ff  and  %i2, 0xff, %i2
a01460e0:  b6 0e e0 ff  and  %i3, 0xff, %i3
a01460e4:  90 0a 20 0f  and  %o0, 0xf, %o0
a01460e8:  92 10 00 19  mov  %i1, %o1
a01460ec:  94 10 00 1a  mov  %i2, %o2
a01460f0:  7f ff 02 c3  call  0xa0106bfc
a01460f4:  96 10 00 1b  mov  %i3, %o3
a01460f8:  10 bf ff d8  b  0xa0146058
a01460fc:  92 27 00 10  sub  %i4, %l0, %o1
a0146100:  81 c7 e0 08  ret
a0146104:  81 e8 00 00  restore
