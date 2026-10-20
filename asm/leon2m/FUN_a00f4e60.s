# leon2m FUN_a00f4e60 0xa00f4e60-0xa00f51b4 (852 bytes)
a00f4e60:  9d e3 bf 80  save  %sp, -128, %sp
a00f4e64:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00f4e68:  80 a4 20 07  cmp  %l0, 7
a00f4e6c:  18 80 00 04  bgu  0xa00f4e7c
a00f4e70:  82 10 20 00  clr  %g1
a00f4e74:  83 2e 20 04  sll  %i0, 4, %g1
a00f4e78:  82 10 40 18  or  %g1, %i0, %g1
a00f4e7c:  15 33 c0 80  sethi  %hi(0xcf020000), %o2
a00f4e80:  92 08 60 ff  and  %g1, 0xff, %o1
a00f4e84:  9a 12 a1 0c  or  %o2, 0x10c, %o5
a00f4e88:  d2 23 40 00  st  %o1, [ %o5 ]
a00f4e8c:  7f ff fa b5  call  0xa00f3960
a00f4e90:  a4 10 20 0a  mov  0xa, %l2
a00f4e94:  7f ff fa b8  call  0xa00f3974
a00f4e98:  d0 2f bf e0  stb  %o0, [ %fp + -32 ]
a00f4e9c:  7f ff fa bb  call  0xa00f3988
a00f4ea0:  d0 2f bf e1  stb  %o0, [ %fp + -31 ]
a00f4ea4:  d0 2f bf e2  stb  %o0, [ %fp + -30 ]
a00f4ea8:  7f ff f8 c5  call  0xa00f31bc
a00f4eac:  90 10 20 02  mov  2, %o0
a00f4eb0:  90 10 00 10  mov  %l0, %o0
a00f4eb4:  92 10 20 5e  mov  0x5e, %o1
a00f4eb8:  7f ff f3 07  call  0xa00f1ad4
a00f4ebc:  94 10 20 71  mov  0x71, %o2
a00f4ec0:  90 10 00 10  mov  %l0, %o0
a00f4ec4:  92 10 20 5f  mov  0x5f, %o1
a00f4ec8:  7f ff f3 03  call  0xa00f1ad4
a00f4ecc:  94 10 20 ff  mov  0xff, %o2
a00f4ed0:  92 10 20 60  mov  0x60, %o1
a00f4ed4:  94 10 20 00  clr  %o2
a00f4ed8:  7f ff f2 ff  call  0xa00f1ad4
a00f4edc:  90 10 00 10  mov  %l0, %o0
a00f4ee0:  90 10 20 ff  mov  0xff, %o0
a00f4ee4:  c0 2f bf e8  clrb  [ %fp + -24 ]
a00f4ee8:  c0 2f bf e9  clrb  [ %fp + -23 ]
a00f4eec:  7f ff fa 7a  call  0xa00f38d4
a00f4ef0:  c0 2f bf ea  clrb  [ %fp + -22 ]
a00f4ef4:  7f ff fa 7e  call  0xa00f38ec
a00f4ef8:  90 10 20 ff  mov  0xff, %o0
a00f4efc:  7f ff fa 82  call  0xa00f3904
a00f4f00:  90 10 20 ff  mov  0xff, %o0
a00f4f04:  90 10 00 10  mov  %l0, %o0
a00f4f08:  92 10 20 65  mov  0x65, %o1
a00f4f0c:  7f ff f2 f2  call  0xa00f1ad4
a00f4f10:  94 10 20 f4  mov  0xf4, %o2
a00f4f14:  90 10 00 10  mov  %l0, %o0
a00f4f18:  92 10 20 66  mov  0x66, %o1
a00f4f1c:  7f ff f2 ee  call  0xa00f1ad4
a00f4f20:  94 10 20 f1  mov  0xf1, %o2
a00f4f24:  90 10 00 10  mov  %l0, %o0
a00f4f28:  92 10 20 67  mov  0x67, %o1
a00f4f2c:  7f ff f2 ea  call  0xa00f1ad4
a00f4f30:  94 10 20 ec  mov  0xec, %o2
a00f4f34:  90 10 00 10  mov  %l0, %o0
a00f4f38:  92 10 20 63  mov  0x63, %o1
a00f4f3c:  7f ff f2 e6  call  0xa00f1ad4
a00f4f40:  94 10 20 80  mov  0x80, %o2
a00f4f44:  90 10 00 10  mov  %l0, %o0
a00f4f48:  92 10 20 64  mov  0x64, %o1
a00f4f4c:  7f ff f2 e2  call  0xa00f1ad4
a00f4f50:  94 10 20 03  mov  3, %o2
a00f4f54:  c0 37 bf f0  clrh  [ %fp + -16 ]
a00f4f58:  c0 37 bf f2  clrh  [ %fp + -14 ]
a00f4f5c:  67 fe 61 8b  call  0x4008d588
a00f4f60:  c0 37 bf f4  clrh  [ %fp + -12 ]
a00f4f64:  a2 10 00 08  mov  %o0, %l1
a00f4f68:  11 33 33 33  sethi  %hi(0xcccccc00), %o0
a00f4f6c:  10 80 00 1a  b  0xa00f4fd4
a00f4f70:  a6 12 20 cd  or  %o0, 0xcd, %l3	! 0xcccccccd
a00f4f74:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00f4f78:  d6 0f bf e9  ldub  [ %fp + -23 ], %o3
a00f4f7c:  b0 03 00 01  add  %o4, %g1, %i0
a00f4f80:  da 17 bf f2  lduh  [ %fp + -14 ], %o5
a00f4f84:  9e 03 40 0b  add  %o5, %o3, %o7
a00f4f88:  d0 17 bf f4  lduh  [ %fp + -12 ], %o0
a00f4f8c:  94 0a 60 ff  and  %o1, 0xff, %o2
a00f4f90:  f0 37 bf f0  sth  %i0, [ %fp + -16 ]
a00f4f94:  a4 04 bf ff  add  %l2, -1, %l2
a00f4f98:  96 02 00 0a  add  %o0, %o2, %o3
a00f4f9c:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00f4fa0:  de 37 bf f2  sth  %o7, [ %fp + -14 ]
a00f4fa4:  80 a6 20 00  cmp  %i0, 0
a00f4fa8:  02 80 00 43  be  0xa00f50b4
a00f4fac:  d6 37 bf f4  sth  %o3, [ %fp + -12 ]
a00f4fb0:  9f 2c 60 10  sll  %l1, 0x10, %o7
a00f4fb4:  91 33 e0 10  srl  %o7, 0x10, %o0
a00f4fb8:  67 fe 61 77  call  0x4008d594
a00f4fbc:  d2 2f bf ea  stb  %o1, [ %fp + -22 ]
a00f4fc0:  83 2a 20 10  sll  %o0, 0x10, %g1
a00f4fc4:  99 30 60 10  srl  %g1, 0x10, %o4
a00f4fc8:  80 a3 21 2b  cmp  %o4, 0x12b
a00f4fcc:  18 80 00 4a  bgu  0xa00f50f4
a00f4fd0:  90 10 00 10  mov  %l0, %o0
a00f4fd4:  67 fe 60 73  call  0x4008d1a0
a00f4fd8:  90 10 20 02  mov  2, %o0
a00f4fdc:  40 00 b0 e6  call  0xa0121374
a00f4fe0:  90 10 00 10  mov  %l0, %o0
a00f4fe4:  96 0a 20 ff  and  %o0, 0xff, %o3
a00f4fe8:  80 a2 e0 01  cmp  %o3, 1
a00f4fec:  02 80 00 41  be  0xa00f50f0
a00f4ff0:  b0 10 20 0a  mov  0xa, %i0
a00f4ff4:  7f ff fa 5b  call  0xa00f3960
a00f4ff8:  01 00 00 00  nop
a00f4ffc:  d2 0f bf e8  ldub  [ %fp + -24 ], %o1
a00f5000:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00f5004:  82 22 40 0d  sub  %o1, %o5, %g1
a00f5008:  99 38 60 1f  sra  %g1, 0x1f, %o4
a00f500c:  b0 1b 00 01  xor  %o4, %g1, %i0
a00f5010:  9e 26 00 0c  sub  %i0, %o4, %o7
a00f5014:  80 a3 e0 03  cmp  %o7, 3
a00f5018:  34 80 00 02  bg,a   0xa00f5020
a00f501c:  a4 10 20 0a  mov  0xa, %l2
a00f5020:  7f ff fa 55  call  0xa00f3974
a00f5024:  d0 2f bf e8  stb  %o0, [ %fp + -24 ]
a00f5028:  d8 0f bf e9  ldub  [ %fp + -23 ], %o4
a00f502c:  82 0a 20 ff  and  %o0, 0xff, %g1
a00f5030:  b0 23 00 01  sub  %o4, %g1, %i0
a00f5034:  9f 3e 20 1f  sra  %i0, 0x1f, %o7
a00f5038:  96 1b c0 18  xor  %o7, %i0, %o3
a00f503c:  94 22 c0 0f  sub  %o3, %o7, %o2
a00f5040:  80 a2 a0 03  cmp  %o2, 3
a00f5044:  34 80 00 02  bg,a   0xa00f504c
a00f5048:  a4 10 20 0a  mov  0xa, %l2
a00f504c:  7f ff fa 4f  call  0xa00f3988
a00f5050:  d0 2f bf e9  stb  %o0, [ %fp + -23 ]
a00f5054:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00f5058:  de 0f bf ea  ldub  [ %fp + -22 ], %o7
a00f505c:  96 23 c0 18  sub  %o7, %i0, %o3
a00f5060:  95 3a e0 1f  sra  %o3, 0x1f, %o2
a00f5064:  92 10 00 08  mov  %o0, %o1
a00f5068:  9a 1a 80 0b  xor  %o2, %o3, %o5
a00f506c:  90 23 40 0a  sub  %o5, %o2, %o0
a00f5070:  80 a2 20 03  cmp  %o0, 3
a00f5074:  34 80 00 02  bg,a   0xa00f507c
a00f5078:  a4 10 20 0a  mov  0xa, %l2
a00f507c:  98 0c a0 ff  and  %l2, 0xff, %o4
a00f5080:  80 a3 20 0a  cmp  %o4, 0xa
a00f5084:  12 bf ff bc  bne  0xa00f4f74
a00f5088:  d8 17 bf f0  lduh  [ %fp + -16 ], %o4
a00f508c:  a4 04 bf ff  add  %l2, -1, %l2
a00f5090:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00f5094:  da 0f bf e9  ldub  [ %fp + -23 ], %o5
a00f5098:  90 0a 60 ff  and  %o1, 0xff, %o0
a00f509c:  b0 0c a0 ff  and  %l2, 0xff, %i0
a00f50a0:  c2 37 bf f0  sth  %g1, [ %fp + -16 ]
a00f50a4:  da 37 bf f2  sth  %o5, [ %fp + -14 ]
a00f50a8:  80 a6 20 00  cmp  %i0, 0
a00f50ac:  12 bf ff c1  bne  0xa00f4fb0
a00f50b0:  d0 37 bf f4  sth  %o0, [ %fp + -12 ]
a00f50b4:  da 17 bf f0  lduh  [ %fp + -16 ], %o5
a00f50b8:  d4 17 bf f2  lduh  [ %fp + -14 ], %o2
a00f50bc:  d6 17 bf f4  lduh  [ %fp + -12 ], %o3
a00f50c0:  80 52 c0 13  umul  %o3, %l3, %g0
a00f50c4:  93 40 00 00  rd  %y, %o1
a00f50c8:  80 52 80 13  umul  %o2, %l3, %g0
a00f50cc:  9f 40 00 00  rd  %y, %o7
a00f50d0:  80 53 40 13  umul  %o5, %l3, %g0
a00f50d4:  91 40 00 00  rd  %y, %o0
a00f50d8:  a7 32 20 03  srl  %o0, 3, %l3
a00f50dc:  a5 33 e0 03  srl  %o7, 3, %l2
a00f50e0:  a3 32 60 03  srl  %o1, 3, %l1
a00f50e4:  e6 2f bf e8  stb  %l3, [ %fp + -24 ]
a00f50e8:  e4 2f bf e9  stb  %l2, [ %fp + -23 ]
a00f50ec:  e2 2f bf ea  stb  %l1, [ %fp + -22 ]
a00f50f0:  90 10 00 10  mov  %l0, %o0
a00f50f4:  92 10 20 63  mov  0x63, %o1
a00f50f8:  7f ff f2 77  call  0xa00f1ad4
a00f50fc:  94 10 20 00  clr  %o2
a00f5100:  90 10 00 10  mov  %l0, %o0
a00f5104:  92 10 20 64  mov  0x64, %o1
a00f5108:  7f ff f2 73  call  0xa00f1ad4
a00f510c:  94 10 20 00  clr  %o2
a00f5110:  90 10 00 10  mov  %l0, %o0
a00f5114:  92 10 20 65  mov  0x65, %o1
a00f5118:  7f ff f2 6f  call  0xa00f1ad4
a00f511c:  94 10 20 00  clr  %o2
a00f5120:  90 10 00 10  mov  %l0, %o0
a00f5124:  92 10 20 66  mov  0x66, %o1
a00f5128:  7f ff f2 6b  call  0xa00f1ad4
a00f512c:  94 10 20 00  clr  %o2
a00f5130:  90 10 00 10  mov  %l0, %o0
a00f5134:  92 10 20 67  mov  0x67, %o1
a00f5138:  7f ff f2 67  call  0xa00f1ad4
a00f513c:  94 10 20 00  clr  %o2
a00f5140:  90 10 00 10  mov  %l0, %o0
a00f5144:  92 10 20 5e  mov  0x5e, %o1
a00f5148:  7f ff f2 63  call  0xa00f1ad4
a00f514c:  94 10 20 00  clr  %o2
a00f5150:  7f ff f8 1b  call  0xa00f31bc
a00f5154:  90 10 20 03  mov  3, %o0
a00f5158:  80 a6 20 00  cmp  %i0, 0
a00f515c:  02 80 00 0a  be  0xa00f5184
a00f5160:  01 00 00 00  nop
a00f5164:  7f ff f9 dc  call  0xa00f38d4
a00f5168:  d0 0f bf e0  ldub  [ %fp + -32 ], %o0
a00f516c:  7f ff f9 e0  call  0xa00f38ec
a00f5170:  d0 0f bf e1  ldub  [ %fp + -31 ], %o0
a00f5174:  7f ff f9 e4  call  0xa00f3904
a00f5178:  d0 0f bf e2  ldub  [ %fp + -30 ], %o0
a00f517c:  10 80 00 0c  b  0xa00f51ac
a00f5180:  b0 10 20 00  clr  %i0
a00f5184:  7f ff f9 d4  call  0xa00f38d4
a00f5188:  d0 0f bf e8  ldub  [ %fp + -24 ], %o0
a00f518c:  7f ff f9 d8  call  0xa00f38ec
a00f5190:  d0 0f bf e9  ldub  [ %fp + -23 ], %o0
a00f5194:  d0 0f bf ea  ldub  [ %fp + -22 ], %o0
a00f5198:  7f ff f9 db  call  0xa00f3904
a00f519c:  b0 10 20 01  mov  1, %i0
a00f51a0:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00f51a4:  f0 2c 23 98  stb  %i0, [ %l0 + 0x398 ]	! 0xa802b798
a00f51a8:  b0 10 20 01  mov  1, %i0
a00f51ac:  81 c7 e0 08  ret
a00f51b0:  81 e8 00 00  restore
