# leon2m FUN_a01003b4 0xa01003b4-0xa0100434 (128 bytes)  [FUN_a010042c = unreachable ret/restore tail, merged]
a01003b4:  9d e3 bf 98  save  %sp, -104, %sp
a01003b8:  a0 0e 20 ff  and  %i0, 0xff, %l0
a01003bc:  92 10 20 04  mov  4, %o1
a01003c0:  7f ff c5 b4  call  0xa00f1a90
a01003c4:  90 10 00 10  mov  %l0, %o0
a01003c8:  9a 10 00 08  mov  %o0, %o5
a01003cc:  a2 0e 60 ff  and  %i1, 0xff, %l1
a01003d0:  96 0b 7f f3  and  %o5, -13, %o3
a01003d4:  83 2c 60 02  sll  %l1, 2, %g1
a01003d8:  98 0b 60 03  and  %o5, 3, %o4
a01003dc:  94 12 c0 01  or  %o3, %g1, %o2
a01003e0:  90 10 00 10  mov  %l0, %o0
a01003e4:  92 10 20 04  mov  4, %o1
a01003e8:  80 a3 20 03  cmp  %o4, 3
a01003ec:  12 80 00 0f  bne  0xa0100428
a01003f0:  94 0a a0 ff  and  %o2, 0xff, %o2
a01003f4:  7f ff c5 b8  call  0xa00f1ad4
a01003f8:  b0 10 00 10  mov  %l0, %i0
a01003fc:  b2 10 20 16  mov  0x16, %i1
a0100400:  b4 10 20 50  mov  0x50, %i2
a0100404:  80 a4 60 00  cmp  %l1, 0
a0100408:  12 80 00 06  bne  0xa0100420
a010040c:  b6 10 20 01  mov  1, %i3
a0100410:  b0 10 00 10  mov  %l0, %i0
a0100414:  b2 10 20 16  mov  0x16, %i1
a0100418:  b4 10 20 50  mov  0x50, %i2
a010041c:  b6 10 20 00  clr  %i3
a0100420:  7f ff c5 cf  call  0xa00f1b5c
a0100424:  81 e8 00 00  restore
a0100428:  01 00 00 00  nop
a010042c:  81 c7 e0 08  ret
a0100430:  81 e8 00 00  restore
