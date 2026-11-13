# leon2m FUN_a00ea25c 0xa00ea25c-0xa00ea308 (172 bytes)
a00ea25c:  9d e3 bf 98  save  %sp, -104, %sp
a00ea260:  80 a6 60 03  cmp  %i1, 3
a00ea264:  18 80 00 15  bgu  0xa00ea2b8
a00ea268:  92 06 40 19  add  %i1, %i1, %o1
a00ea26c:  9a 02 40 19  add  %o1, %i1, %o5
a00ea270:  82 10 20 01  mov  1, %g1
a00ea274:  83 28 40 1a  sll  %g1, %i2, %g1
a00ea278:  80 a6 a0 07  cmp  %i2, 7
a00ea27c:  18 80 00 19  bgu  0xa00ea2e0
a00ea280:  9a 03 61 b5  add  %o5, 0x1b5, %o5
a00ea284:  94 10 00 01  mov  %g1, %o2
a00ea288:  90 10 00 18  mov  %i0, %o0
a00ea28c:  92 10 00 0d  mov  %o5, %o1
a00ea290:  80 a6 e0 01  cmp  %i3, 1
a00ea294:  02 80 00 06  be  0xa00ea2ac
a00ea298:  96 10 00 01  mov  %g1, %o3
a00ea29c:  90 10 00 18  mov  %i0, %o0
a00ea2a0:  92 10 00 0d  mov  %o5, %o1
a00ea2a4:  94 10 00 01  mov  %g1, %o2
a00ea2a8:  96 10 20 00  clr  %o3
a00ea2ac:  7f ff d8 cb  call  0xa00e05d8
a00ea2b0:  b0 10 20 00  clr  %i0
a00ea2b4:  30 80 00 13  b,a   0xa00ea300
a00ea2b8:  7f ff d5 55  call  0xa00df80c
a00ea2bc:  01 00 00 00  nop
a00ea2c0:  7f ff da 40  call  0xa00e0bc0
a00ea2c4:  01 00 00 00  nop
a00ea2c8:  11 00 06 66  sethi  %hi(0x199800), %o0
a00ea2cc:  90 12 22 a8  or  %o0, 0x2a8, %o0	! 0x199aa8
a00ea2d0:  92 10 00 19  mov  %i1, %o1
a00ea2d4:  7f ff d3 a7  call  0xa00df170
a00ea2d8:  b0 10 3f ff  mov  -1, %i0
a00ea2dc:  30 80 00 09  b,a   0xa00ea300
a00ea2e0:  7f ff d5 4b  call  0xa00df80c
a00ea2e4:  01 00 00 00  nop
a00ea2e8:  7f ff da 36  call  0xa00e0bc0
a00ea2ec:  01 00 00 00  nop
a00ea2f0:  15 00 06 66  sethi  %hi(0x199800), %o2
a00ea2f4:  90 12 a2 d0  or  %o2, 0x2d0, %o0	! 0x199ad0
a00ea2f8:  10 bf ff f7  b  0xa00ea2d4
a00ea2fc:  92 10 00 1a  mov  %i2, %o1
a00ea300:  81 c7 e0 08  ret
a00ea304:  81 e8 00 00  restore
