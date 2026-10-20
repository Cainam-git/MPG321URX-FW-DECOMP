# leon2m FUN_a0125e60 0xa0125e60-0xa012621c (956 bytes)
a0125e60:  9d e3 bf 98  save  %sp, -104, %sp
a0125e64:  7f fe df 20  call  0xa00ddae4
a0125e68:  90 10 20 06  mov  6, %o0
a0125e6c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0125e70:  80 a3 60 50  cmp  %o5, 0x50
a0125e74:  18 80 00 c1  bgu  0xa0126178
a0125e78:  a0 10 20 00  clr  %l0
a0125e7c:  a0 10 20 04  mov  4, %l0
a0125e80:  80 8c 20 ff  btst  0xff, %l0
a0125e84:  02 80 00 c6  be  0xa012619c
a0125e88:  01 00 00 00  nop
a0125e8c:  82 10 20 01  mov  1, %g1	! 0x1
a0125e90:  98 10 20 00  clr  %o4
a0125e94:  9e 08 60 ff  and  %g1, 0xff, %o7
a0125e98:  80 8b e0 01  btst  1, %o7
a0125e9c:  12 80 00 cd  bne  0xa01261d0
a0125ea0:  83 33 e0 01  srl  %o7, 1, %g1
a0125ea4:  98 03 20 01  inc  %o4
a0125ea8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0125eac:  80 a3 60 07  cmp  %o5, 7
a0125eb0:  28 bf ff fa  bleu,a   0xa0125e98
a0125eb4:  9e 08 60 ff  and  %g1, 0xff, %o7
a0125eb8:  82 03 40 0d  add  %o5, %o5, %g1
a0125ebc:  b0 00 40 0d  add  %g1, %o5, %i0
a0125ec0:  23 00 06 90  sethi  %hi(0x1a4000), %l1
a0125ec4:  9a 14 63 71  or  %l1, 0x371, %o5	! 0x1a4371
a0125ec8:  d0 0b 40 18  ldub  [ %o5 + %i0 ], %o0
a0125ecc:  98 06 00 0d  add  %i0, %o5, %o4
a0125ed0:  f0 0b 20 02  ldub  [ %o4 + 2 ], %i0
a0125ed4:  80 a2 20 ff  cmp  %o0, 0xff
a0125ed8:  02 80 00 09  be  0xa0125efc
a0125edc:  c2 0b 20 01  ldub  [ %o4 + 1 ], %g1
a0125ee0:  67 fd 9b 96  call  0x4008cd38
a0125ee4:  92 08 60 ff  and  %g1, 0xff, %o1
a0125ee8:  94 0a 20 ff  and  %o0, 0xff, %o2
a0125eec:  92 0e 20 ff  and  %i0, 0xff, %o1
a0125ef0:  80 a2 80 09  cmp  %o2, %o1
a0125ef4:  02 80 00 03  be  0xa0125f00
a0125ef8:  82 10 20 01  mov  1, %g1
a0125efc:  82 10 20 00  clr  %g1
a0125f00:  a0 10 40 10  or  %g1, %l0, %l0
a0125f04:  82 10 20 02  mov  2, %g1
a0125f08:  98 10 20 00  clr  %o4
a0125f0c:  90 08 60 ff  and  %g1, 0xff, %o0
a0125f10:  80 8a 20 01  btst  1, %o0
a0125f14:  12 80 00 b1  bne  0xa01261d8
a0125f18:  83 32 20 01  srl  %o0, 1, %g1
a0125f1c:  98 03 20 01  inc  %o4
a0125f20:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0125f24:  80 a3 60 07  cmp  %o5, 7
a0125f28:  08 bf ff fa  bleu  0xa0125f10
a0125f2c:  90 08 60 ff  and  %g1, 0xff, %o0
a0125f30:  b0 03 40 0d  add  %o5, %o5, %i0
a0125f34:  9e 06 00 0d  add  %i0, %o5, %o7
a0125f38:  98 14 63 71  or  %l1, 0x371, %o4
a0125f3c:  96 03 c0 0c  add  %o7, %o4, %o3
a0125f40:  d0 0b 00 0f  ldub  [ %o4 + %o7 ], %o0
a0125f44:  f0 0a e0 02  ldub  [ %o3 + 2 ], %i0
a0125f48:  80 a2 20 ff  cmp  %o0, 0xff
a0125f4c:  02 80 00 09  be  0xa0125f70
a0125f50:  c2 0a e0 01  ldub  [ %o3 + 1 ], %g1
a0125f54:  67 fd 9b 79  call  0x4008cd38
a0125f58:  92 08 60 ff  and  %g1, 0xff, %o1
a0125f5c:  82 0a 20 ff  and  %o0, 0xff, %g1
a0125f60:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0125f64:  80 a0 40 0d  cmp  %g1, %o5
a0125f68:  02 80 00 03  be  0xa0125f74
a0125f6c:  82 10 20 02  mov  2, %g1
a0125f70:  82 10 20 00  clr  %g1
a0125f74:  b0 10 40 10  or  %g1, %l0, %i0
a0125f78:  82 10 20 00  clr  %g1
a0125f7c:  98 10 20 00  clr  %o4
a0125f80:  a0 08 60 ff  and  %g1, 0xff, %l0
a0125f84:  80 8c 20 01  btst  1, %l0
a0125f88:  12 80 00 96  bne  0xa01261e0
a0125f8c:  83 34 20 01  srl  %l0, 1, %g1
a0125f90:  98 03 20 01  inc  %o4
a0125f94:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0125f98:  80 a3 60 07  cmp  %o5, 7
a0125f9c:  28 bf ff fa  bleu,a   0xa0125f84
a0125fa0:  a0 08 60 ff  and  %g1, 0xff, %l0
a0125fa4:  90 03 40 0d  add  %o5, %o5, %o0
a0125fa8:  94 02 00 0d  add  %o0, %o5, %o2
a0125fac:  96 14 63 71  or  %l1, 0x371, %o3
a0125fb0:  d0 0a c0 0a  ldub  [ %o3 + %o2 ], %o0
a0125fb4:  92 02 80 0b  add  %o2, %o3, %o1
a0125fb8:  80 a2 20 ff  cmp  %o0, 0xff
a0125fbc:  02 80 00 04  be  0xa0125fcc
a0125fc0:  c2 0a 60 01  ldub  [ %o1 + 1 ], %g1
a0125fc4:  67 fd 9b 5d  call  0x4008cd38
a0125fc8:  92 08 60 ff  and  %g1, 0xff, %o1
a0125fcc:  82 10 20 00  clr  %g1
a0125fd0:  98 10 20 00  clr  %o4
a0125fd4:  9e 08 60 ff  and  %g1, 0xff, %o7
a0125fd8:  80 8b e0 01  btst  1, %o7
a0125fdc:  12 80 00 8b  bne  0xa0126208
a0125fe0:  83 33 e0 01  srl  %o7, 1, %g1
a0125fe4:  98 03 20 01  inc  %o4
a0125fe8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0125fec:  80 a3 60 07  cmp  %o5, 7
a0125ff0:  28 bf ff fa  bleu,a   0xa0125fd8
a0125ff4:  9e 08 60 ff  and  %g1, 0xff, %o7
a0125ff8:  a0 03 40 0d  add  %o5, %o5, %l0
a0125ffc:  82 04 00 0d  add  %l0, %o5, %g1
a0126000:  9a 14 63 71  or  %l1, 0x371, %o5
a0126004:  d0 0b 40 01  ldub  [ %o5 + %g1 ], %o0
a0126008:  98 00 40 0d  add  %g1, %o5, %o4
a012600c:  80 a2 20 ff  cmp  %o0, 0xff
a0126010:  02 80 00 04  be  0xa0126020
a0126014:  c2 0b 20 01  ldub  [ %o4 + 1 ], %g1
a0126018:  67 fd 9b 48  call  0x4008cd38
a012601c:  92 08 60 ff  and  %g1, 0xff, %o1
a0126020:  82 10 20 00  clr  %g1
a0126024:  98 10 20 00  clr  %o4
a0126028:  92 08 60 ff  and  %g1, 0xff, %o1
a012602c:  80 8a 60 01  btst  1, %o1
a0126030:  12 80 00 74  bne  0xa0126200
a0126034:  83 32 60 01  srl  %o1, 1, %g1
a0126038:  98 03 20 01  inc  %o4
a012603c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0126040:  80 a3 60 07  cmp  %o5, 7
a0126044:  28 bf ff fa  bleu,a   0xa012602c
a0126048:  92 08 60 ff  and  %g1, 0xff, %o1
a012604c:  90 03 40 0d  add  %o5, %o5, %o0
a0126050:  96 02 00 0d  add  %o0, %o5, %o3
a0126054:  9e 14 63 71  or  %l1, 0x371, %o7
a0126058:  d0 0b c0 0b  ldub  [ %o7 + %o3 ], %o0
a012605c:  94 02 c0 0f  add  %o3, %o7, %o2
a0126060:  80 a2 20 ff  cmp  %o0, 0xff
a0126064:  02 80 00 04  be  0xa0126074
a0126068:  c2 0a a0 01  ldub  [ %o2 + 1 ], %g1
a012606c:  67 fd 9b 33  call  0x4008cd38
a0126070:  92 08 60 ff  and  %g1, 0xff, %o1
a0126074:  82 10 20 00  clr  %g1
a0126078:  98 10 20 00  clr  %o4
a012607c:  82 08 60 ff  and  %g1, 0xff, %g1
a0126080:  80 88 60 01  btst  1, %g1
a0126084:  12 80 00 5d  bne  0xa01261f8
a0126088:  83 30 60 01  srl  %g1, 1, %g1
a012608c:  98 03 20 01  inc  %o4
a0126090:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0126094:  80 a3 60 07  cmp  %o5, 7
a0126098:  28 bf ff fa  bleu,a   0xa0126080
a012609c:  82 08 60 ff  and  %g1, 0xff, %g1
a01260a0:  92 03 40 0d  add  %o5, %o5, %o1
a01260a4:  a0 02 40 0d  add  %o1, %o5, %l0
a01260a8:  9a 14 63 71  or  %l1, 0x371, %o5
a01260ac:  d0 0b 40 10  ldub  [ %o5 + %l0 ], %o0
a01260b0:  98 04 00 0d  add  %l0, %o5, %o4
a01260b4:  80 a2 20 ff  cmp  %o0, 0xff
a01260b8:  02 80 00 04  be  0xa01260c8
a01260bc:  c2 0b 20 01  ldub  [ %o4 + 1 ], %g1
a01260c0:  67 fd 9b 1e  call  0x4008cd38
a01260c4:  92 08 60 ff  and  %g1, 0xff, %o1
a01260c8:  82 10 20 00  clr  %g1
a01260cc:  98 10 20 00  clr  %o4
a01260d0:  94 08 60 ff  and  %g1, 0xff, %o2
a01260d4:  80 8a a0 01  btst  1, %o2
a01260d8:  12 80 00 46  bne  0xa01261f0
a01260dc:  83 32 a0 01  srl  %o2, 1, %g1
a01260e0:  98 03 20 01  inc  %o4
a01260e4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01260e8:  80 a3 60 07  cmp  %o5, 7
a01260ec:  28 bf ff fa  bleu,a   0xa01260d4
a01260f0:  94 08 60 ff  and  %g1, 0xff, %o2
a01260f4:  90 03 40 0d  add  %o5, %o5, %o0
a01260f8:  9e 02 00 0d  add  %o0, %o5, %o7
a01260fc:  98 14 63 71  or  %l1, 0x371, %o4
a0126100:  d0 0b 00 0f  ldub  [ %o4 + %o7 ], %o0
a0126104:  96 03 c0 0c  add  %o7, %o4, %o3
a0126108:  80 a2 20 ff  cmp  %o0, 0xff
a012610c:  02 80 00 04  be  0xa012611c
a0126110:  c2 0a e0 01  ldub  [ %o3 + 1 ], %g1
a0126114:  67 fd 9b 09  call  0x4008cd38
a0126118:  92 08 60 ff  and  %g1, 0xff, %o1
a012611c:  82 10 20 00  clr  %g1
a0126120:  98 10 20 00  clr  %o4
a0126124:  82 08 60 ff  and  %g1, 0xff, %g1
a0126128:  80 88 60 01  btst  1, %g1
a012612c:  12 80 00 2f  bne  0xa01261e8
a0126130:  83 30 60 01  srl  %g1, 1, %g1
a0126134:  98 03 20 01  inc  %o4
a0126138:  9a 0b 20 ff  and  %o4, 0xff, %o5
a012613c:  80 a3 60 07  cmp  %o5, 7
a0126140:  08 bf ff fa  bleu  0xa0126128
a0126144:  82 08 60 ff  and  %g1, 0xff, %g1
a0126148:  92 03 40 0d  add  %o5, %o5, %o1
a012614c:  a0 02 40 0d  add  %o1, %o5, %l0
a0126150:  9a 14 63 71  or  %l1, 0x371, %o5
a0126154:  d0 0b 40 10  ldub  [ %o5 + %l0 ], %o0
a0126158:  a2 04 00 0d  add  %l0, %o5, %l1
a012615c:  80 a2 20 ff  cmp  %o0, 0xff
a0126160:  02 80 00 2c  be  0xa0126210
a0126164:  c2 0c 60 01  ldub  [ %l1 + 1 ], %g1
a0126168:  67 fd 9a f4  call  0x4008cd38
a012616c:  92 08 60 ff  and  %g1, 0xff, %o1
a0126170:  10 80 00 29  b  0xa0126214
a0126174:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0126178:  92 02 3f a0  add  %o0, -96, %o1
a012617c:  82 0a 60 ff  and  %o1, 0xff, %g1
a0126180:  80 a0 60 40  cmp  %g1, 0x40
a0126184:  18 bf ff 40  bgu  0xa0125e84
a0126188:  80 8c 20 ff  btst  0xff, %l0
a012618c:  a0 10 20 08  mov  8, %l0
a0126190:  80 8c 20 ff  btst  0xff, %l0
a0126194:  12 bf ff 3f  bne  0xa0125e90
a0126198:  82 10 20 01  mov  1, %g1
a012619c:  7f fe de 52  call  0xa00ddae4
a01261a0:  90 10 20 05  mov  5, %o0
a01261a4:  94 0a 20 ff  and  %o0, 0xff, %o2
a01261a8:  80 a2 a0 50  cmp  %o2, 0x50
a01261ac:  28 bf ff 38  bleu,a   0xa0125e8c
a01261b0:  a0 14 20 10  or  %l0, 0x10, %l0
a01261b4:  96 02 3f a0  add  %o0, -96, %o3
a01261b8:  90 0a e0 ff  and  %o3, 0xff, %o0
a01261bc:  80 a2 20 40  cmp  %o0, 0x40
a01261c0:  28 bf ff 33  bleu,a   0xa0125e8c
a01261c4:  a0 14 20 20  or  %l0, 0x20, %l0
a01261c8:  10 bf ff 32  b  0xa0125e90
a01261cc:  82 10 20 01  mov  1, %g1
a01261d0:  10 bf ff 3a  b  0xa0125eb8
a01261d4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01261d8:  10 bf ff 56  b  0xa0125f30
a01261dc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01261e0:  10 bf ff 71  b  0xa0125fa4
a01261e4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01261e8:  10 bf ff d8  b  0xa0126148
a01261ec:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01261f0:  10 bf ff c1  b  0xa01260f4
a01261f4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a01261f8:  10 bf ff aa  b  0xa01260a0
a01261fc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0126200:  10 bf ff 93  b  0xa012604c
a0126204:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0126208:  10 bf ff 7c  b  0xa0125ff8
a012620c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0126210:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0126214:  81 c7 e0 08  ret
a0126218:  81 e8 00 00  restore
