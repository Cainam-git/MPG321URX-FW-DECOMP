# leon2m FUN_a0097190 0xa0097190-0xa00972cc (316 bytes)
a0097190:  9d e3 bf 98  save  %sp, -104, %sp
a0097194:  92 10 20 00  clr  %o1
a0097198:  90 10 20 04  mov  4, %o0
a009719c:  7f ff a5 c4  call  0xa00808ac
a00971a0:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00971a4:  a2 14 a2 90  or  %l2, 0x290, %l1	! 0xa802d290
a00971a8:  40 02 b5 15  call  0xa01445fc
a00971ac:  d0 0c 60 1e  ldub  [ %l1 + 0x1e ], %o0
a00971b0:  a0 10 00 08  mov  %o0, %l0
a00971b4:  40 02 b5 12  call  0xa01445fc
a00971b8:  d0 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %o0
a00971bc:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00971c0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00971c4:  80 a4 00 08  cmp  %l0, %o0
a00971c8:  02 80 00 11  be  0xa009720c
a00971cc:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a00971d0:  98 12 63 f4  or  %o1, 0x3f4, %o4	! 0xa802cff4
a00971d4:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a00971d8:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00971dc:  a0 0b 40 01  and  %o5, %g1, %l0
a00971e0:  91 2c 20 10  sll  %l0, 0x10, %o0
a00971e4:  80 a2 20 00  cmp  %o0, 0
a00971e8:  12 80 00 24  bne  0xa0097278
a00971ec:  1f 2a 00 ab  sethi  %hi(0xa802ac00), %o7
a00971f0:  c0 23 e3 ec  clr  [ %o7 + 0x3ec ]	! 0xa802afec
a00971f4:  40 00 77 a3  call  0xa00b5080
a00971f8:  01 00 00 00  nop
a00971fc:  d6 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %o3
a0097200:  d6 2c 60 1e  stb  %o3, [ %l1 + 0x1e ]
a0097204:  40 00 85 80  call  0xa00b8804
a0097208:  81 e8 00 00  restore
a009720c:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a0097210:  98 12 e3 f4  or  %o3, 0x3f4, %o4	! 0xa802cff4
a0097214:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a0097218:  15 3f ff e0  sethi  %hi(0xffff8000), %o2
a009721c:  92 0b 40 0a  and  %o5, %o2, %o1
a0097220:  83 2a 60 10  sll  %o1, 0x10, %g1
a0097224:  80 a0 60 00  cmp  %g1, 0
a0097228:  12 80 00 21  bne  0xa00972ac
a009722c:  9e 13 64 00  or  %o5, 0x400, %o7
a0097230:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0097234:  40 00 77 93  call  0xa00b5080
a0097238:  c0 24 23 ec  clr  [ %l0 + 0x3ec ]	! 0xa802afec
a009723c:  40 02 b2 76  call  0xa0143c14
a0097240:  90 10 20 00  clr  %o0
a0097244:  98 0a 20 ff  and  %o0, 0xff, %o4
a0097248:  80 a3 20 0a  cmp  %o4, 0xa
a009724c:  02 80 00 1e  be  0xa00972c4
a0097250:  da 04 a2 90  ld  [ %l2 + 0x290 ], %o5
a0097254:  80 8b 62 00  btst  0x200, %o5
a0097258:  12 80 00 1b  bne  0xa00972c4
a009725c:  01 00 00 00  nop
a0097260:  e4 0c 60 1f  ldub  [ %l1 + 0x1f ], %l2
a0097264:  80 a4 a0 00  cmp  %l2, 0
a0097268:  12 80 00 17  bne  0xa00972c4
a009726c:  a2 10 20 fe  mov  0xfe, %l1
a0097270:  10 80 00 15  b  0xa00972c4
a0097274:  e2 24 23 ec  st  %l1, [ %l0 + 0x3ec ]
a0097278:  94 13 64 00  or  %o5, 0x400, %o2
a009727c:  d4 33 20 04  sth  %o2, [ %o4 + 4 ]
a0097280:  90 10 20 04  mov  4, %o0
a0097284:  7f ff a5 8a  call  0xa00808ac
a0097288:  92 10 20 00  clr  %o1
a009728c:  1f 2a 00 ab  sethi  %hi(0xa802ac00), %o7
a0097290:  c0 23 e3 ec  clr  [ %o7 + 0x3ec ]	! 0xa802afec
a0097294:  40 00 77 7b  call  0xa00b5080
a0097298:  01 00 00 00  nop
a009729c:  d6 0c 61 a3  ldub  [ %l1 + 0x1a3 ], %o3
a00972a0:  d6 2c 60 1e  stb  %o3, [ %l1 + 0x1e ]
a00972a4:  40 00 85 58  call  0xa00b8804
a00972a8:  81 e8 00 00  restore
a00972ac:  de 33 20 04  sth  %o7, [ %o4 + 4 ]
a00972b0:  90 10 20 04  mov  4, %o0
a00972b4:  7f ff a5 7e  call  0xa00808ac
a00972b8:  92 10 20 00  clr  %o1
a00972bc:  10 bf ff de  b  0xa0097234
a00972c0:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a00972c4:  81 c7 e0 08  ret
a00972c8:  81 e8 00 00  restore
