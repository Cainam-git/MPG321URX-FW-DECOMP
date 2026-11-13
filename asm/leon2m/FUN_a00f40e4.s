# leon2m FUN_a00f40e4 0xa00f40e4-0xa00f42b8 (468 bytes)
a00f40e4:  9d e3 bf 98  save  %sp, -104, %sp
a00f40e8:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00f40ec:  90 10 00 11  mov  %l1, %o0
a00f40f0:  7f ff f6 68  call  0xa00f1a90
a00f40f4:  92 10 20 54  mov  0x54, %o1
a00f40f8:  80 8a 20 80  btst  0x80, %o0
a00f40fc:  02 80 00 6d  be  0xa00f42b0
a00f4100:  b0 10 20 00  clr  %i0
a00f4104:  31 2a 00 ad  sethi  %hi(0xa802b400), %i0
a00f4108:  90 10 00 11  mov  %l1, %o0
a00f410c:  40 00 b7 4c  call  0xa0121e3c
a00f4110:  c0 2e 23 ac  clrb  [ %i0 + 0x3ac ]
a00f4114:  90 10 00 11  mov  %l1, %o0
a00f4118:  92 10 20 37  mov  0x37, %o1
a00f411c:  7f ff f6 6e  call  0xa00f1ad4
a00f4120:  94 10 20 40  mov  0x40, %o2
a00f4124:  90 10 00 11  mov  %l1, %o0
a00f4128:  92 10 20 36  mov  0x36, %o1
a00f412c:  7f ff f6 6a  call  0xa00f1ad4
a00f4130:  94 10 20 00  clr  %o2
a00f4134:  92 10 20 36  mov  0x36, %o1
a00f4138:  94 10 20 11  mov  0x11, %o2
a00f413c:  7f ff f6 66  call  0xa00f1ad4
a00f4140:  90 10 00 11  mov  %l1, %o0
a00f4144:  67 fe 64 17  call  0x4008d1a0
a00f4148:  90 10 20 14  mov  0x14, %o0
a00f414c:  67 fe 65 0f  call  0x4008d588
a00f4150:  a4 10 20 00  clr  %l2
a00f4154:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00f4158:  40 00 b4 87  call  0xa0121374
a00f415c:  90 10 00 11  mov  %l1, %o0
a00f4160:  82 0a 20 ff  and  %o0, 0xff, %g1
a00f4164:  92 10 20 36  mov  0x36, %o1
a00f4168:  80 a0 60 01  cmp  %g1, 1
a00f416c:  02 80 00 4b  be  0xa00f4298
a00f4170:  90 10 00 11  mov  %l1, %o0
a00f4174:  7f ff f6 47  call  0xa00f1a90
a00f4178:  01 00 00 00  nop
a00f417c:  80 8a 20 01  btst  1, %o0
a00f4180:  02 80 00 48  be  0xa00f42a0
a00f4184:  91 34 20 10  srl  %l0, 0x10, %o0
a00f4188:  67 fe 65 03  call  0x4008d594
a00f418c:  01 00 00 00  nop
a00f4190:  83 2a 20 10  sll  %o0, 0x10, %g1
a00f4194:  91 30 60 10  srl  %g1, 0x10, %o0
a00f4198:  80 a2 20 63  cmp  %o0, 0x63
a00f419c:  08 bf ff ef  bleu  0xa00f4158
a00f41a0:  01 00 00 00  nop
a00f41a4:  80 8c a0 ff  btst  0xff, %l2
a00f41a8:  12 80 00 05  bne  0xa00f41bc
a00f41ac:  d4 0e 23 ac  ldub  [ %i0 + 0x3ac ], %o2
a00f41b0:  92 10 20 01  mov  1, %o1
a00f41b4:  d2 2e 23 ac  stb  %o1, [ %i0 + 0x3ac ]
a00f41b8:  d4 0e 23 ac  ldub  [ %i0 + 0x3ac ], %o2
a00f41bc:  80 a2 a0 01  cmp  %o2, 1
a00f41c0:  02 80 00 3c  be  0xa00f42b0
a00f41c4:  b0 10 20 00  clr  %i0
a00f41c8:  92 10 20 3e  mov  0x3e, %o1
a00f41cc:  7f ff f6 c6  call  0xa00f1ce4
a00f41d0:  90 10 00 11  mov  %l1, %o0
a00f41d4:  94 0a 2f ff  and  %o0, 0xfff, %o2
a00f41d8:  90 10 00 11  mov  %l1, %o0
a00f41dc:  7f ff f6 db  call  0xa00f1d48
a00f41e0:  92 10 20 12  mov  0x12, %o1
a00f41e4:  92 10 20 38  mov  0x38, %o1
a00f41e8:  7f ff f6 bf  call  0xa00f1ce4
a00f41ec:  90 10 00 11  mov  %l1, %o0
a00f41f0:  94 0a 27 ff  and  %o0, 0x7ff, %o2
a00f41f4:  90 10 00 11  mov  %l1, %o0
a00f41f8:  7f ff f6 d4  call  0xa00f1d48
a00f41fc:  92 10 20 0e  mov  0xe, %o1
a00f4200:  92 10 20 38  mov  0x38, %o1
a00f4204:  7f ff f6 b8  call  0xa00f1ce4
a00f4208:  90 10 00 11  mov  %l1, %o0
a00f420c:  94 0a 27 ff  and  %o0, 0x7ff, %o2
a00f4210:  90 10 00 11  mov  %l1, %o0
a00f4214:  7f ff f6 cd  call  0xa00f1d48
a00f4218:  92 10 20 0c  mov  0xc, %o1
a00f421c:  92 10 20 3a  mov  0x3a, %o1
a00f4220:  7f ff f6 b1  call  0xa00f1ce4
a00f4224:  90 10 00 11  mov  %l1, %o0
a00f4228:  a4 10 00 08  mov  %o0, %l2
a00f422c:  90 10 00 11  mov  %l1, %o0
a00f4230:  7f ff f6 ad  call  0xa00f1ce4
a00f4234:  92 10 20 38  mov  0x38, %o1
a00f4238:  a1 2c a0 10  sll  %l2, 0x10, %l0
a00f423c:  97 2a 20 10  sll  %o0, 0x10, %o3
a00f4240:  80 a2 c0 10  cmp  %o3, %l0
a00f4244:  0a 80 00 13  bcs  0xa00f4290
a00f4248:  90 10 00 11  mov  %l1, %o0
a00f424c:  92 10 20 3a  mov  0x3a, %o1
a00f4250:  7f ff f6 a5  call  0xa00f1ce4
a00f4254:  90 10 00 11  mov  %l1, %o0
a00f4258:  b0 10 00 08  mov  %o0, %i0
a00f425c:  90 10 00 11  mov  %l1, %o0
a00f4260:  7f ff f6 a1  call  0xa00f1ce4
a00f4264:  92 10 20 38  mov  0x38, %o1
a00f4268:  99 2e 20 10  sll  %i0, 0x10, %o4
a00f426c:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00f4270:  80 a3 40 0c  cmp  %o5, %o4
a00f4274:  08 80 00 0d  bleu  0xa00f42a8
a00f4278:  90 10 00 11  mov  %l1, %o0
a00f427c:  1f 00 00 3f  sethi  %hi(0xfc00), %o7
a00f4280:  92 13 e3 ff  or  %o7, 0x3ff, %o1	! 0xffff
a00f4284:  40 00 12 ea  call  0xa00f8e2c
a00f4288:  b0 10 20 01  mov  1, %i0
a00f428c:  30 80 00 09  b,a   0xa00f42b0
a00f4290:  10 bf ff fd  b  0xa00f4284
a00f4294:  92 10 20 01  mov  1, %o1
a00f4298:  10 bf ff c3  b  0xa00f41a4
a00f429c:  c2 2e 23 ac  stb  %g1, [ %i0 + 0x3ac ]
a00f42a0:  10 bf ff c1  b  0xa00f41a4
a00f42a4:  a4 10 20 01  mov  1, %l2
a00f42a8:  10 bf ff f7  b  0xa00f4284
a00f42ac:  92 10 20 00  clr  %o1
a00f42b0:  81 c7 e0 08  ret
a00f42b4:  81 e8 00 00  restore
