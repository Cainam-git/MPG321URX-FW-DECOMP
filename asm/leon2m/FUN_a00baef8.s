# leon2m FUN_a00baef8 0xa00baef8-0xa00bb1c4 (716 bytes)
a00baef8:  9d e3 bf 90  save  %sp, -112, %sp
a00baefc:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00baf00:  d0 0c 60 9c  ldub  [ %l1 + 0x9c ], %o0	! 0xa802b09c
a00baf04:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00baf08:  98 10 20 30  mov  0x30, %o4
a00baf0c:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00baf10:  96 23 00 0d  sub  %o4, %o5, %o3
a00baf14:  94 14 20 d0  or  %l0, 0xd0, %o2
a00baf18:  93 2a e0 10  sll  %o3, 0x10, %o1
a00baf1c:  94 02 00 0a  add  %o0, %o2, %o2
a00baf20:  96 07 bf f6  add  %fp, -10, %o3
a00baf24:  c0 37 bf f6  clrh  [ %fp + -10 ]
a00baf28:  90 0e 20 ff  and  %i0, 0xff, %o0
a00baf2c:  40 02 36 28  call  0xa01487cc
a00baf30:  93 32 60 10  srl  %o1, 0x10, %o1
a00baf34:  c2 17 bf f6  lduh  [ %fp + -10 ], %g1
a00baf38:  80 a0 60 00  cmp  %g1, 0
a00baf3c:  a4 10 20 00  clr  %l2
a00baf40:  02 80 00 3b  be  0xa00bb02c
a00baf44:  96 10 00 01  mov  %g1, %o3
a00baf48:  d8 0c 20 d0  ldub  [ %l0 + 0xd0 ], %o4
a00baf4c:  9a 1b 20 35  xor  %o4, 0x35, %o5
a00baf50:  80 a0 00 0d  cmp  %g0, %o5
a00baf54:  94 40 20 00  addx  %g0, 0, %o2
a00baf58:  80 a0 00 0c  cmp  %g0, %o4
a00baf5c:  d0 0c 60 9c  ldub  [ %l1 + 0x9c ], %o0
a00baf60:  82 02 00 0b  add  %o0, %o3, %g1
a00baf64:  92 40 20 00  addx  %g0, 0, %o1
a00baf68:  80 8a 80 09  btst  %o2, %o1
a00baf6c:  12 80 00 46  bne  0xa00bb084
a00baf70:  c2 2c 60 9c  stb  %g1, [ %l1 + 0x9c ]
a00baf74:  c2 0c 20 d0  ldub  [ %l0 + 0xd0 ], %g1
a00baf78:  80 a0 60 35  cmp  %g1, 0x35
a00baf7c:  12 80 00 06  bne  0xa00baf94
a00baf80:  b0 14 20 d0  or  %l0, 0xd0, %i0
a00baf84:  d2 0c 60 9c  ldub  [ %l1 + 0x9c ], %o1
a00baf88:  80 a2 60 05  cmp  %o1, 5
a00baf8c:  18 80 00 04  bgu  0xa00baf9c
a00baf90:  01 00 00 00  nop
a00baf94:  10 80 00 8a  b  0xa00bb1bc
a00baf98:  b0 10 20 08  mov  8, %i0	! 0x8
a00baf9c:  7f ff 2e a8  call  0xa0086a3c
a00bafa0:  90 10 20 0f  mov  0xf, %o0
a00bafa4:  95 2a 20 10  sll  %o0, 0x10, %o2
a00bafa8:  80 a2 a0 00  cmp  %o2, 0
a00bafac:  02 80 00 44  be  0xa00bb0bc
a00bafb0:  98 10 20 01  mov  1, %o4
a00bafb4:  c2 0e 20 01  ldub  [ %i0 + 1 ], %g1
a00bafb8:  80 a0 60 38  cmp  %g1, 0x38
a00bafbc:  d4 0e 20 04  ldub  [ %i0 + 4 ], %o2
a00bafc0:  02 80 00 46  be  0xa00bb0d8
a00bafc4:  d2 0e 20 05  ldub  [ %i0 + 5 ], %o1
a00bafc8:  80 a0 60 62  cmp  %g1, 0x62
a00bafcc:  02 80 00 45  be  0xa00bb0e0
a00bafd0:  96 0a 60 ff  and  %o1, 0xff, %o3
a00bafd4:  d6 0c 60 9c  ldub  [ %l1 + 0x9c ], %o3
a00bafd8:  98 0c a0 3f  and  %l2, 0x3f, %o4
a00bafdc:  80 a2 c0 0c  cmp  %o3, %o4
a00bafe0:  08 80 00 77  bleu  0xa00bb1bc
a00bafe4:  b0 10 20 08  mov  8, %i0
a00bafe8:  94 14 20 d0  or  %l0, 0xd0, %o2
a00bafec:  e0 0a 80 0c  ldub  [ %o2 + %o4 ], %l0
a00baff0:  80 a4 20 0d  cmp  %l0, 0xd
a00baff4:  12 80 00 72  bne  0xa00bb1bc
a00baff8:  b0 10 20 10  mov  0x10, %i0
a00baffc:  d4 0a a0 01  ldub  [ %o2 + 1 ], %o2
a00bb000:  23 2a 00 ac  sethi  %hi(0xa802b000), %l1
a00bb004:  c0 2c 60 96  clrb  [ %l1 + 0x96 ]	! 0xa802b096
a00bb008:  80 a2 a0 38  cmp  %o2, 0x38
a00bb00c:  02 80 00 6c  be  0xa00bb1bc
a00bb010:  b0 10 20 02  mov  2, %i0
a00bb014:  9a 1a a0 62  xor  %o2, 0x62, %o5
a00bb018:  80 a0 00 0d  cmp  %g0, %o5
a00bb01c:  a4 60 20 00  subx  %g0, 0, %l2
a00bb020:  98 0c a0 0c  and  %l2, 0xc, %o4
a00bb024:  10 80 00 66  b  0xa00bb1bc
a00bb028:  b0 03 20 04  add  %o4, 4, %i0
a00bb02c:  7f ff 2e 84  call  0xa0086a3c
a00bb030:  90 10 20 0f  mov  0xf, %o0
a00bb034:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00bb038:  80 a3 e0 00  cmp  %o7, 0
a00bb03c:  12 80 00 07  bne  0xa00bb058
a00bb040:  d8 0c 20 d0  ldub  [ %l0 + 0xd0 ], %o4
a00bb044:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00bb048:  f0 0b 60 96  ldub  [ %o5 + 0x96 ], %i0	! 0xa802b096
a00bb04c:  80 a6 20 01  cmp  %i0, 1
a00bb050:  22 80 00 55  be,a   0xa00bb1a4
a00bb054:  c0 2b 60 96  clrb  [ %o5 + 0x96 ]
a00bb058:  9a 1b 20 35  xor  %o4, 0x35, %o5
a00bb05c:  80 a0 00 0d  cmp  %g0, %o5
a00bb060:  94 40 20 00  addx  %g0, 0, %o2
a00bb064:  d6 17 bf f6  lduh  [ %fp + -10 ], %o3
a00bb068:  80 a0 00 0c  cmp  %g0, %o4
a00bb06c:  d0 0c 60 9c  ldub  [ %l1 + 0x9c ], %o0
a00bb070:  82 02 00 0b  add  %o0, %o3, %g1
a00bb074:  92 40 20 00  addx  %g0, 0, %o1
a00bb078:  80 8a 80 09  btst  %o2, %o1
a00bb07c:  02 bf ff be  be  0xa00baf74
a00bb080:  c2 2c 60 9c  stb  %g1, [ %l1 + 0x9c ]
a00bb084:  7f ff 2e 6e  call  0xa0086a3c
a00bb088:  90 10 20 0f  mov  0xf, %o0
a00bb08c:  97 2a 20 10  sll  %o0, 0x10, %o3
a00bb090:  80 a2 e0 00  cmp  %o3, 0
a00bb094:  32 bf ff b9  bne,a   0xa00baf78
a00bb098:  c2 0c 20 d0  ldub  [ %l0 + 0xd0 ], %g1
a00bb09c:  b0 10 20 01  mov  1, %i0
a00bb0a0:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bb0a4:  f0 2b e0 96  stb  %i0, [ %o7 + 0x96 ]	! 0xa802b096
a00bb0a8:  90 10 20 0f  mov  0xf, %o0
a00bb0ac:  7f ff 2e 41  call  0xa00869b0
a00bb0b0:  92 10 20 32  mov  0x32, %o1
a00bb0b4:  10 bf ff b1  b  0xa00baf78
a00bb0b8:  c2 0c 20 d0  ldub  [ %l0 + 0xd0 ], %g1
a00bb0bc:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00bb0c0:  d8 2a 20 96  stb  %o4, [ %o0 + 0x96 ]	! 0xa802b096
a00bb0c4:  90 10 20 0f  mov  0xf, %o0
a00bb0c8:  7f ff 2e 3a  call  0xa00869b0
a00bb0cc:  92 10 20 fa  mov  0xfa, %o1
a00bb0d0:  10 bf ff ba  b  0xa00bafb8
a00bb0d4:  c2 0e 20 01  ldub  [ %i0 + 1 ], %g1
a00bb0d8:  10 bf ff bf  b  0xa00bafd4
a00bb0dc:  a4 10 20 07  mov  7, %l2
a00bb0e0:  80 a2 e0 a6  cmp  %o3, 0xa6
a00bb0e4:  02 bf ff bc  be  0xa00bafd4
a00bb0e8:  a4 10 20 29  mov  0x29, %l2
a00bb0ec:  b0 1a e0 a5  xor  %o3, 0xa5, %i0
a00bb0f0:  80 a0 00 18  cmp  %g0, %i0
a00bb0f4:  9a 60 3f ff  subx  %g0, -1, %o5
a00bb0f8:  9e 1a e0 a7  xor  %o3, 0xa7, %o7
a00bb0fc:  80 a0 00 0f  cmp  %g0, %o7
a00bb100:  a4 60 3f ff  subx  %g0, -1, %l2
a00bb104:  80 93 40 12  orcc  %o5, %l2, %g0
a00bb108:  32 bf ff b3  bne,a   0xa00bafd4
a00bb10c:  a4 10 20 0a  mov  0xa, %l2
a00bb110:  80 a2 e0 a8  cmp  %o3, 0xa8
a00bb114:  02 80 00 22  be  0xa00bb19c
a00bb118:  98 1a e0 3c  xor  %o3, 0x3c, %o4
a00bb11c:  80 a0 00 0c  cmp  %g0, %o4
a00bb120:  94 0a a0 ff  and  %o2, 0xff, %o2
a00bb124:  98 60 3f ff  subx  %g0, -1, %o4
a00bb128:  90 1a a0 36  xor  %o2, 0x36, %o0
a00bb12c:  80 a0 00 08  cmp  %g0, %o0
a00bb130:  82 60 3f ff  subx  %g0, -1, %g1
a00bb134:  80 8b 00 01  btst  %o4, %g1
a00bb138:  12 bf ff a7  bne  0xa00bafd4
a00bb13c:  a4 10 20 19  mov  0x19, %l2
a00bb140:  9a 1a e0 3e  xor  %o3, 0x3e, %o5
a00bb144:  80 a0 00 0d  cmp  %g0, %o5
a00bb148:  a4 60 3f ff  subx  %g0, -1, %l2
a00bb14c:  80 93 00 12  orcc  %o4, %l2, %g0
a00bb150:  12 80 00 17  bne  0xa00bb1ac
a00bb154:  80 a2 a0 32  cmp  %o2, 0x32
a00bb158:  80 a2 e0 3f  cmp  %o3, 0x3f
a00bb15c:  02 80 00 14  be  0xa00bb1ac
a00bb160:  80 a2 a0 32  cmp  %o2, 0x32
a00bb164:  90 02 7f 9b  add  %o1, -101, %o0
a00bb168:  82 0a 20 ff  and  %o0, 0xff, %g1
a00bb16c:  80 a0 60 03  cmp  %g1, 3
a00bb170:  9e 60 20 00  subx  %g0, 0, %o7
a00bb174:  b0 1a a0 31  xor  %o2, 0x31, %i0
a00bb178:  80 a0 00 18  cmp  %g0, %i0
a00bb17c:  92 60 3f ff  subx  %g0, -1, %o1
a00bb180:  80 8b c0 09  btst  %o7, %o1
a00bb184:  12 bf ff 94  bne  0xa00bafd4
a00bb188:  a4 10 20 19  mov  0x19, %l2
a00bb18c:  94 0a e0 f0  and  %o3, 0xf0, %o2
a00bb190:  80 a2 a0 5f  cmp  %o2, 0x5f
a00bb194:  14 bf ff 91  bg  0xa00bafd8
a00bb198:  d6 0c 60 9c  ldub  [ %l1 + 0x9c ], %o3
a00bb19c:  10 bf ff 8e  b  0xa00bafd4
a00bb1a0:  a4 10 20 0a  mov  0xa, %l2
a00bb1a4:  10 80 00 06  b  0xa00bb1bc
a00bb1a8:  b0 10 20 40  mov  0x40, %i0
a00bb1ac:  12 bf ff ee  bne  0xa00bb164
a00bb1b0:  a4 10 20 19  mov  0x19, %l2
a00bb1b4:  10 bf ff 89  b  0xa00bafd8
a00bb1b8:  d6 0c 60 9c  ldub  [ %l1 + 0x9c ], %o3
a00bb1bc:  81 c7 e0 08  ret
a00bb1c0:  81 e8 00 00  restore
