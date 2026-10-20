# leon2m FUN_a0150248 0xa0150248-0xa01502c4 (124 bytes)
a0150248:  9d e3 bf 98  save  %sp, -104, %sp
a015024c:  03 2a 00 b3  sethi  %hi(0xa802cc00), %g1
a0150250:  da 08 60 86  ldub  [ %g1 + 0x86 ], %o5	! 0xa802cc86
a0150254:  b1 2e 20 10  sll  %i0, 0x10, %i0
a0150258:  80 a3 60 00  cmp  %o5, 0
a015025c:  02 80 00 18  be  0xa01502bc
a0150260:  b1 36 20 10  srl  %i0, 0x10, %i0
a0150264:  17 2a 00 a9  sethi  %hi(0xa802a400), %o3
a0150268:  d4 12 e0 a2  lduh  [ %o3 + 0xa2 ], %o2	! 0xa802a4a2
a015026c:  90 10 20 18  mov  0x18, %o0
a0150270:  92 10 20 00  clr  %o1
a0150274:  80 a6 00 0a  cmp  %i0, %o2
a0150278:  08 80 00 0d  bleu  0xa01502ac
a015027c:  19 2a 00 b3  sethi  %hi(0xa802cc00), %o4
a0150280:  d2 13 20 88  lduh  [ %o4 + 0x88 ], %o1	! 0xa802cc88
a0150284:  b0 10 20 18  mov  0x18, %i0
a0150288:  80 a2 60 00  cmp  %o1, 0
a015028c:  02 80 00 04  be  0xa015029c
a0150290:  82 02 7f ff  add  %o1, -1, %g1
a0150294:  10 80 00 0a  b  0xa01502bc
a0150298:  c2 33 20 88  sth  %g1, [ %o4 + 0x88 ]
a015029c:  19 2a 00 a9  sethi  %hi(0xa802a400), %o4
a01502a0:  f2 13 20 b0  lduh  [ %o4 + 0xb0 ], %i1	! 0xa802a4b0
a01502a4:  7f ff 36 be  call  0xa011dd9c
a01502a8:  81 e8 00 00  restore
a01502ac:  7f ff 36 bc  call  0xa011dd9c
a01502b0:  b2 10 23 e8  mov  0x3e8, %i1
a01502b4:  1f 2a 00 b3  sethi  %hi(0xa802cc00), %o7
a01502b8:  f2 33 e0 88  sth  %i1, [ %o7 + 0x88 ]	! 0xa802cc88
a01502bc:  81 c7 e0 08  ret
a01502c0:  81 e8 00 00  restore
