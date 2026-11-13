# leon2s FUN_a00c81f8 0xa00c81f8-0xa00c82dc (228 bytes)
a00c81f8:  9d e3 bf 98  save  %sp, -104, %sp
a00c81fc:  40 3b e5 66  call  0xa0fc1794
a00c8200:  90 10 20 02  mov  2, %o0
a00c8204:  90 0e 20 ff  and  %i0, 0xff, %o0
a00c8208:  92 10 20 00  clr  %o1
a00c820c:  40 3b bf 73  call  0xa0fb7fd8
a00c8210:  94 10 20 f4  mov  0xf4, %o2
a00c8214:  83 2e a0 10  sll  %i2, 0x10, %g1
a00c8218:  d0 2e 40 00  stb  %o0, [ %i1 ]
a00c821c:  80 a0 60 00  cmp  %g1, 0
a00c8220:  a6 10 20 64  mov  0x64, %l3
a00c8224:  10 80 00 2a  b  0xa00c82cc
a00c8228:  a4 10 20 00  clr  %l2
a00c822c:  80 8c e0 ff  btst  0xff, %l3
a00c8230:  02 80 00 13  be  0xa00c827c
a00c8234:  93 2c a0 10  sll  %l2, 0x10, %o1
a00c8238:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00c823c:  92 10 20 00  clr  %o1
a00c8240:  94 10 20 f5  mov  0xf5, %o2
a00c8244:  40 3b bf 65  call  0xa0fb7fd8
a00c8248:  90 10 00 11  mov  %l1, %o0
a00c824c:  a1 2e a0 10  sll  %i2, 0x10, %l0
a00c8250:  83 34 20 10  srl  %l0, 0x10, %g1
a00c8254:  9a 00 7f ff  add  %g1, -1, %o5
a00c8258:  80 a0 60 10  cmp  %g1, 0x10
a00c825c:  18 80 00 04  bgu  0xa00c826c
a00c8260:  90 0a 20 1f  and  %o0, 0x1f, %o0
a00c8264:  10 80 00 03  b  0xa00c8270
a00c8268:  80 a2 00 0d  cmp  %o0, %o5
a00c826c:  80 a2 20 10  cmp  %o0, 0x10
a00c8270:  32 bf ff ef  bne,a   0xa00c822c
a00c8274:  a6 04 ff ff  add  %l3, -1, %l3
a00c8278:  93 2c a0 10  sll  %l2, 0x10, %o1
a00c827c:  93 32 60 0c  srl  %o1, 0xc, %o1
a00c8280:  83 34 20 10  srl  %l0, 0x10, %g1
a00c8284:  90 10 00 11  mov  %l1, %o0
a00c8288:  96 10 20 f4  mov  0xf4, %o3
a00c828c:  a4 04 a0 01  inc  %l2
a00c8290:  80 a0 60 10  cmp  %g1, 0x10
a00c8294:  92 06 40 09  add  %i1, %o1, %o1
a00c8298:  08 80 00 03  bleu  0xa00c82a4
a00c829c:  94 0e a0 ff  and  %i2, 0xff, %o2
a00c82a0:  94 10 20 10  mov  0x10, %o2
a00c82a4:  7f ff ff 52  call  0xa00c7fec
a00c82a8:  01 00 00 00  nop
a00c82ac:  83 34 20 10  srl  %l0, 0x10, %g1
a00c82b0:  80 a0 60 10  cmp  %g1, 0x10
a00c82b4:  18 80 00 03  bgu  0xa00c82c0
a00c82b8:  82 06 bf f0  add  %i2, -16, %g1
a00c82bc:  82 10 20 00  clr  %g1
a00c82c0:  b4 10 00 01  mov  %g1, %i2
a00c82c4:  83 2e a0 10  sll  %i2, 0x10, %g1
a00c82c8:  80 a0 60 00  cmp  %g1, 0
a00c82cc:  12 bf ff dc  bne  0xa00c823c
a00c82d0:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00c82d4:  81 c7 e0 08  ret
a00c82d8:  91 e8 20 00  restore  %g0, 0, %o0
