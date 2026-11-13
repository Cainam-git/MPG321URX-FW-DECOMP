# leon2m FUN_a00d43b4 0xa00d43b4-0xa00d444c (152 bytes)
a00d43b4:  9d e3 bf 98  save  %sp, -104, %sp
a00d43b8:  40 01 c0 17  call  0xa0144414
a00d43bc:  01 00 00 00  nop
a00d43c0:  a4 0a 20 ff  and  %o0, 0xff, %l2
a00d43c4:  92 10 20 0b  mov  0xb, %o1
a00d43c8:  40 01 c4 a6  call  0xa0145660
a00d43cc:  90 10 00 12  mov  %l2, %o0
a00d43d0:  9f 2a 20 10  sll  %o0, 0x10, %o7
a00d43d4:  a3 33 e0 10  srl  %o7, 0x10, %l1
a00d43d8:  92 10 20 0e  mov  0xe, %o1
a00d43dc:  40 01 c4 a1  call  0xa0145660
a00d43e0:  90 10 00 12  mov  %l2, %o0
a00d43e4:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00d43e8:  99 33 60 10  srl  %o5, 0x10, %o4
a00d43ec:  96 24 40 0c  sub  %l1, %o4, %o3
a00d43f0:  b0 5a e0 64  smul  %o3, 0x64, %i0
a00d43f4:  92 10 20 0d  mov  0xd, %o1
a00d43f8:  40 01 c4 9a  call  0xa0145660
a00d43fc:  90 10 00 12  mov  %l2, %o0
a00d4400:  95 2a 20 10  sll  %o0, 0x10, %o2
a00d4404:  a1 32 a0 10  srl  %o2, 0x10, %l0
a00d4408:  92 10 20 0e  mov  0xe, %o1
a00d440c:  40 01 c4 95  call  0xa0145660
a00d4410:  90 10 00 12  mov  %l2, %o0
a00d4414:  93 2a 20 10  sll  %o0, 0x10, %o1
a00d4418:  91 32 60 10  srl  %o1, 0x10, %o0
a00d441c:  a0 24 00 08  sub  %l0, %o0, %l0
a00d4420:  83 3e 20 1f  sra  %i0, 0x1f, %g1
a00d4424:  81 80 60 00  mov  %g1, %y
a00d4428:  01 00 00 00  nop
a00d442c:  01 00 00 00  nop
a00d4430:  01 00 00 00  nop
a00d4434:  a2 7e 00 10  sdiv  %i0, %l0, %l1
a00d4438:  82 10 20 64  mov  0x64, %g1
a00d443c:  b0 20 40 11  sub  %g1, %l1, %i0
a00d4440:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d4444:  81 c7 e0 08  ret
a00d4448:  81 e8 00 00  restore
