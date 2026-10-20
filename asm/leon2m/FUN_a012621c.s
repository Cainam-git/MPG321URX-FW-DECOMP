# leon2m FUN_a012621c 0xa012621c-0xa012629c (128 bytes)
a012621c:  9d e3 bf 98  save  %sp, -104, %sp
a0126220:  67 fd 9c da  call  0x4008d588
a0126224:  25 2a 00 b2  sethi  %hi(0xa802c800), %l2
a0126228:  a0 10 00 08  mov  %o0, %l0
a012622c:  b0 10 20 00  clr  %i0
a0126230:  a2 10 00 12  mov  %l2, %l1
a0126234:  7f ff ff 0b  call  0xa0125e60
a0126238:  01 00 00 00  nop
a012623c:  da 0c 61 fc  ldub  [ %l1 + 0x1fc ], %o5
a0126240:  82 0a 20 ff  and  %o0, 0xff, %g1
a0126244:  80 a0 40 0d  cmp  %g1, %o5
a0126248:  22 80 00 07  be,a   0xa0126264
a012624c:  91 2c 20 10  sll  %l0, 0x10, %o0
a0126250:  67 fd 9c ce  call  0x4008d588
a0126254:  d0 2c 61 fc  stb  %o0, [ %l1 + 0x1fc ]
a0126258:  a0 10 00 08  mov  %o0, %l0
a012625c:  b0 10 20 32  mov  0x32, %i0
a0126260:  91 2c 20 10  sll  %l0, 0x10, %o0
a0126264:  80 8e 20 ff  btst  0xff, %i0
a0126268:  02 80 00 0a  be  0xa0126290
a012626c:  91 32 20 10  srl  %o0, 0x10, %o0
a0126270:  67 fd 9c c9  call  0x4008d594
a0126274:  01 00 00 00  nop
a0126278:  97 2a 20 10  sll  %o0, 0x10, %o3
a012627c:  95 32 e0 10  srl  %o3, 0x10, %o2
a0126280:  92 0e 20 32  and  %i0, 0x32, %o1
a0126284:  80 a2 80 09  cmp  %o2, %o1
a0126288:  0a bf ff eb  bcs  0xa0126234
a012628c:  01 00 00 00  nop
a0126290:  f0 0c a1 fc  ldub  [ %l2 + 0x1fc ], %i0
a0126294:  81 c7 e0 08  ret
a0126298:  81 e8 00 00  restore
