# leon2s FUN_a00ad27c 0xa00ad27c-0xa00ad320 (164 bytes)
a00ad27c:  9d e3 bf 98  save  %sp, -104, %sp
a00ad280:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ad284:  7f ff 61 13  call  0xa00856d0
a00ad288:  90 10 00 18  mov  %i0, %o0
a00ad28c:  82 0a 20 ff  and  %o0, 0xff, %g1
a00ad290:  90 10 00 18  mov  %i0, %o0
a00ad294:  80 a0 60 01  cmp  %g1, 1
a00ad298:  a0 10 20 00  clr  %l0
a00ad29c:  02 80 00 1f  be  0xa00ad318
a00ad2a0:  b0 10 20 00  clr  %i0
a00ad2a4:  7f ff 60 f8  call  0xa0085684
a00ad2a8:  01 00 00 00  nop
a00ad2ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ad2b0:  82 0a 20 22  and  %o0, 0x22, %g1
a00ad2b4:  98 18 60 22  xor  %g1, 0x22, %o4
a00ad2b8:  82 0a 20 44  and  %o0, 0x44, %g1
a00ad2bc:  96 18 60 44  xor  %g1, 0x44, %o3
a00ad2c0:  82 0a 20 88  and  %o0, 0x88, %g1
a00ad2c4:  90 0a 20 11  and  %o0, 0x11, %o0
a00ad2c8:  94 18 60 88  xor  %g1, 0x88, %o2
a00ad2cc:  80 a2 20 11  cmp  %o0, 0x11
a00ad2d0:  12 80 00 03  bne  0xa00ad2dc
a00ad2d4:  9a 10 20 00  clr  %o5
a00ad2d8:  9a 10 20 01  mov  1, %o5
a00ad2dc:  80 a0 00 0c  cmp  %g0, %o4
a00ad2e0:  82 60 3f ff  subx  %g0, -1, %g1
a00ad2e4:  82 00 40 0d  add  %g1, %o5, %g1
a00ad2e8:  9a 10 00 01  mov  %g1, %o5
a00ad2ec:  80 a0 00 0b  cmp  %g0, %o3
a00ad2f0:  82 60 3f ff  subx  %g0, -1, %g1
a00ad2f4:  82 00 40 0d  add  %g1, %o5, %g1
a00ad2f8:  80 a0 00 0a  cmp  %g0, %o2
a00ad2fc:  9a 10 00 01  mov  %g1, %o5
a00ad300:  82 60 3f ff  subx  %g0, -1, %g1
a00ad304:  82 00 40 0d  add  %g1, %o5, %g1
a00ad308:  80 88 60 ff  btst  0xff, %g1
a00ad30c:  32 80 00 02  bne,a   0xa00ad314
a00ad310:  a0 10 20 01  mov  1, %l0
a00ad314:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00ad318:  81 c7 e0 08  ret
a00ad31c:  81 e8 00 00  restore
