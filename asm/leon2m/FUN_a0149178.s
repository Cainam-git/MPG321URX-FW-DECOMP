# leon2m FUN_a0149178 0xa0149178-0xa0149210 (152 bytes)
a0149178:  9d e3 bf 90  save  %sp, -112, %sp
a014917c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0149180:  90 0e 20 f0  and  %i0, 0xf0, %o0
a0149184:  92 1a 20 10  xor  %o0, 0x10, %o1
a0149188:  80 a0 00 09  cmp  %g0, %o1
a014918c:  82 1a 20 30  xor  %o0, 0x30, %g1
a0149190:  98 60 3f ff  subx  %g0, -1, %o4
a0149194:  80 a0 00 01  cmp  %g0, %g1
a0149198:  9a 60 3f ff  subx  %g0, -1, %o5
a014919c:  80 93 00 0d  orcc  %o4, %o5, %g0
a01491a0:  02 80 00 05  be  0xa01491b4
a01491a4:  82 10 3f ff  mov  -1, %g1
a01491a8:  80 a6 20 30  cmp  %i0, 0x30
a01491ac:  02 80 00 14  be  0xa01491fc
a01491b0:  15 3f ff e0  sethi  %hi(0xffff8000), %o2
a01491b4:  c2 2f bf f0  stb  %g1, [ %fp + -16 ]
a01491b8:  c0 37 bf f2  clrh  [ %fp + -14 ]
a01491bc:  c2 0f bf f0  ldub  [ %fp + -16 ], %g1
a01491c0:  80 a0 60 ff  cmp  %g1, 0xff
a01491c4:  02 80 00 05  be  0xa01491d8
a01491c8:  90 10 20 40  mov  0x40, %o0
a01491cc:  7f ff 8f 43  call  0xa012ced8
a01491d0:  90 10 00 01  mov  %g1, %o0
a01491d4:  30 80 00 0d  b,a   0xa0149208
a01491d8:  7f fe 51 0f  call  0xa00dd614
a01491dc:  01 00 00 00  nop
a01491e0:  80 8a 20 ff  btst  0xff, %o0
a01491e4:  17 00 06 9b  sethi  %hi(0x1a6c00), %o3
a01491e8:  02 80 00 08  be  0xa0149208
a01491ec:  90 12 e3 a8  or  %o3, 0x3a8, %o0	! 0x1a6fa8
a01491f0:  7f fe 57 e0  call  0xa00df170
a01491f4:  01 00 00 00  nop
a01491f8:  30 80 00 04  b,a   0xa0149208
a01491fc:  d4 37 bf f2  sth  %o2, [ %fp + -14 ]
a0149200:  10 bf ff ef  b  0xa01491bc
a0149204:  c0 2f bf f0  clrb  [ %fp + -16 ]
a0149208:  81 c7 e0 08  ret
a014920c:  81 e8 00 00  restore
