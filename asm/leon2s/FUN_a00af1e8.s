# leon2s FUN_a00af1e8 0xa00af1e8-0xa00af320 (312 bytes)
a00af1e8:  9d e3 bf 98  save  %sp, -104, %sp
a00af1ec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00af1f0:  7f ff f9 65  call  0xa00ad784
a00af1f4:  90 10 00 18  mov  %i0, %o0
a00af1f8:  80 8a 20 ff  btst  0xff, %o0
a00af1fc:  92 10 20 70  mov  0x70, %o1
a00af200:  94 10 20 00  clr  %o2
a00af204:  90 10 00 18  mov  %i0, %o0
a00af208:  02 80 00 44  be  0xa00af318
a00af20c:  82 10 20 00  clr  %g1
a00af210:  7f ff de 7c  call  0xa00a6c00
a00af214:  01 00 00 00  nop
a00af218:  90 10 00 18  mov  %i0, %o0
a00af21c:  94 10 20 0c  mov  0xc, %o2
a00af220:  7f ff de 78  call  0xa00a6c00
a00af224:  92 10 20 73  mov  0x73, %o1
a00af228:  90 10 00 18  mov  %i0, %o0
a00af22c:  7f ff de 63  call  0xa00a6bb8
a00af230:  92 10 20 7a  mov  0x7a, %o1
a00af234:  a2 10 00 08  mov  %o0, %l1
a00af238:  90 10 00 18  mov  %i0, %o0
a00af23c:  92 10 20 70  mov  0x70, %o1
a00af240:  7f ff de 70  call  0xa00a6c00
a00af244:  94 10 20 00  clr  %o2
a00af248:  90 10 00 18  mov  %i0, %o0
a00af24c:  94 10 20 0d  mov  0xd, %o2
a00af250:  7f ff de 6c  call  0xa00a6c00
a00af254:  92 10 20 73  mov  0x73, %o1
a00af258:  90 10 00 18  mov  %i0, %o0
a00af25c:  7f ff de 57  call  0xa00a6bb8
a00af260:  92 10 20 7a  mov  0x7a, %o1
a00af264:  a4 10 00 08  mov  %o0, %l2
a00af268:  90 10 00 18  mov  %i0, %o0
a00af26c:  92 10 20 70  mov  0x70, %o1
a00af270:  7f ff de 64  call  0xa00a6c00
a00af274:  94 10 20 00  clr  %o2
a00af278:  90 10 00 18  mov  %i0, %o0
a00af27c:  94 10 20 10  mov  0x10, %o2
a00af280:  7f ff de 60  call  0xa00a6c00
a00af284:  92 10 20 73  mov  0x73, %o1
a00af288:  90 10 00 18  mov  %i0, %o0
a00af28c:  7f ff de 4b  call  0xa00a6bb8
a00af290:  92 10 20 7a  mov  0x7a, %o1
a00af294:  a0 10 00 08  mov  %o0, %l0
a00af298:  90 10 00 18  mov  %i0, %o0
a00af29c:  92 10 20 70  mov  0x70, %o1
a00af2a0:  7f ff de 58  call  0xa00a6c00
a00af2a4:  94 10 20 00  clr  %o2
a00af2a8:  90 10 00 18  mov  %i0, %o0
a00af2ac:  92 10 20 73  mov  0x73, %o1
a00af2b0:  7f ff de 54  call  0xa00a6c00
a00af2b4:  94 10 20 11  mov  0x11, %o2
a00af2b8:  90 10 00 18  mov  %i0, %o0
a00af2bc:  7f ff de 3f  call  0xa00a6bb8
a00af2c0:  92 10 20 7a  mov  0x7a, %o1
a00af2c4:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00af2c8:  a1 2c 20 08  sll  %l0, 8, %l0
a00af2cc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00af2d0:  a0 04 00 08  add  %l0, %o0, %l0
a00af2d4:  a2 0c 60 ff  and  %l1, 0xff, %l1
a00af2d8:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00af2dc:  a3 2c 60 08  sll  %l1, 8, %l1
a00af2e0:  a4 0c a0 ff  and  %l2, 0xff, %l2
a00af2e4:  a1 34 20 10  srl  %l0, 0x10, %l0
a00af2e8:  a2 04 40 12  add  %l1, %l2, %l1
a00af2ec:  80 a4 20 00  cmp  %l0, 0
a00af2f0:  83 2c 60 10  sll  %l1, 0x10, %g1
a00af2f4:  02 80 00 08  be  0xa00af314
a00af2f8:  b0 10 20 00  clr  %i0
a00af2fc:  83 30 60 10  srl  %g1, 0x10, %g1
a00af300:  81 80 00 00  mov  %g0, %y
a00af304:  01 00 00 00  nop
a00af308:  01 00 00 00  nop
a00af30c:  01 00 00 00  nop
a00af310:  b0 70 40 10  udiv  %g1, %l0, %i0
a00af314:  82 0e 20 ff  and  %i0, 0xff, %g1
a00af318:  81 c7 e0 08  ret
a00af31c:  91 e8 00 01  restore  %g0, %g1, %o0
