# leon2m FUN_a00d4250 0xa00d4250-0xa00d42e0 (144 bytes)
a00d4250:  9d e3 bf 98  save  %sp, -104, %sp
a00d4254:  40 01 c0 70  call  0xa0144414
a00d4258:  01 00 00 00  nop
a00d425c:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00d4260:  92 10 20 04  mov  4, %o1
a00d4264:  40 01 c4 ff  call  0xa0145660
a00d4268:  90 10 00 11  mov  %l1, %o0
a00d426c:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00d4270:  b1 33 60 10  srl  %o5, 0x10, %i0
a00d4274:  92 10 20 06  mov  6, %o1
a00d4278:  40 01 c4 fa  call  0xa0145660
a00d427c:  90 10 00 11  mov  %l1, %o0
a00d4280:  99 2a 20 10  sll  %o0, 0x10, %o4
a00d4284:  97 33 20 10  srl  %o4, 0x10, %o3
a00d4288:  94 26 00 0b  sub  %i0, %o3, %o2
a00d428c:  b0 5a a0 64  smul  %o2, 0x64, %i0
a00d4290:  92 10 20 05  mov  5, %o1
a00d4294:  40 01 c4 f3  call  0xa0145660
a00d4298:  90 10 00 11  mov  %l1, %o0
a00d429c:  93 2a 20 10  sll  %o0, 0x10, %o1
a00d42a0:  a1 32 60 10  srl  %o1, 0x10, %l0
a00d42a4:  90 10 00 11  mov  %l1, %o0
a00d42a8:  40 01 c4 ee  call  0xa0145660
a00d42ac:  92 10 20 06  mov  6, %o1
a00d42b0:  83 2a 20 10  sll  %o0, 0x10, %g1
a00d42b4:  91 30 60 10  srl  %g1, 0x10, %o0
a00d42b8:  a0 24 00 08  sub  %l0, %o0, %l0
a00d42bc:  83 3e 20 1f  sra  %i0, 0x1f, %g1
a00d42c0:  81 80 60 00  mov  %g1, %y
a00d42c4:  01 00 00 00  nop
a00d42c8:  01 00 00 00  nop
a00d42cc:  01 00 00 00  nop
a00d42d0:  b0 7e 00 10  sdiv  %i0, %l0, %i0
a00d42d4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d42d8:  81 c7 e0 08  ret
a00d42dc:  81 e8 00 00  restore
