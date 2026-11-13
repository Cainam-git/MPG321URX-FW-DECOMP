# leon2m FUN_a002e238 0xa002e238-0xa002e2a4 (108 bytes)
a002e238:  9d e3 bf 98  save  %sp, -104, %sp
a002e23c:  21 30 02 c0  sethi  %hi(0xc00b0000), %l0
a002e240:  7f ff f8 04  call  0xa002c250
a002e244:  90 14 20 14  or  %l0, 0x14, %o0	! 0xc00b0014
a002e248:  80 8a 20 01  btst  1, %o0
a002e24c:  02 80 00 14  be  0xa002e29c
a002e250:  90 10 00 10  mov  %l0, %o0
a002e254:  7f ff f7 ff  call  0xa002c250
a002e258:  01 00 00 00  nop
a002e25c:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a002e260:  94 13 60 ec  or  %o5, 0xec, %o2	! 0xa802b0ec
a002e264:  d8 0a a0 80  ldub  [ %o2 + 0x80 ], %o4
a002e268:  9e 03 20 01  add  %o4, 1, %o7
a002e26c:  83 2b e0 18  sll  %o7, 0x18, %g1
a002e270:  a1 38 60 18  sra  %g1, 0x18, %l0
a002e274:  96 38 00 10  xnor  %g0, %l0, %o3
a002e278:  93 3a e0 1f  sra  %o3, 0x1f, %o1
a002e27c:  96 0b c0 09  and  %o7, %o1, %o3
a002e280:  da 0a a0 81  ldub  [ %o2 + 0x81 ], %o5
a002e284:  82 0a e0 ff  and  %o3, 0xff, %g1
a002e288:  80 a3 40 01  cmp  %o5, %g1
a002e28c:  02 80 00 04  be  0xa002e29c
a002e290:  98 0b 20 ff  and  %o4, 0xff, %o4
a002e294:  d0 2a 80 0c  stb  %o0, [ %o2 + %o4 ]
a002e298:  d6 2a a0 80  stb  %o3, [ %o2 + 0x80 ]
a002e29c:  81 c7 e0 08  ret
a002e2a0:  81 e8 00 00  restore
