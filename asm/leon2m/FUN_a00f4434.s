# leon2m FUN_a00f4434 0xa00f4434-0xa00f446c (56 bytes)
a00f4434:  9d e3 bf 98  save  %sp, -104, %sp
a00f4438:  40 00 b1 78  call  0xa0120a18
a00f443c:  90 0e 20 ff  and  %i0, 0xff, %o0
a00f4440:  99 2a 20 10  sll  %o0, 0x10, %o4
a00f4444:  97 2e 60 10  sll  %i1, 0x10, %o3
a00f4448:  95 33 20 10  srl  %o4, 0x10, %o2
a00f444c:  b3 32 e0 10  srl  %o3, 0x10, %i1
a00f4450:  13 00 07 d1  sethi  %hi(0x1f4400), %o1
a00f4454:  90 5a 80 19  smul  %o2, %i1, %o0
a00f4458:  82 12 63 d0  or  %o1, 0x3d0, %g1
a00f445c:  80 a0 40 08  cmp  %g1, %o0
a00f4460:  b0 40 20 00  addx  %g0, 0, %i0
a00f4464:  81 c7 e0 08  ret
a00f4468:  81 e8 00 00  restore
