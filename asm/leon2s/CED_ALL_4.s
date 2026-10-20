# leon2s CED_ALL_4 0xa00b258c-0xa00b25f8 (108 bytes)
a00b258c:  9d e3 bf 98  save  %sp, -104, %sp
a00b2590:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b2594:  a0 96 20 00  orcc  %i0, 0, %l0
a00b2598:  02 80 00 15  be  0xa00b25ec
a00b259c:  90 12 22 98  or  %o0, 0x298, %o0
a00b25a0:  7f fe bb 38  call  0xa0061280
a00b25a4:  31 28 01 b1  sethi  %hi(0xa006c400), %i0
a00b25a8:  7f fe bb 68  call  0xa0061348
a00b25ac:  90 10 00 10  mov  %l0, %o0
a00b25b0:  11 28 01 b1  sethi  %hi(0xa006c400), %o0
a00b25b4:  7f fe bb 33  call  0xa0061280
a00b25b8:  90 12 22 b0  or  %o0, 0x2b0, %o0	! 0xa006c6b0
a00b25bc:  90 10 00 10  mov  %l0, %o0
a00b25c0:  92 10 00 19  mov  %i1, %o1
a00b25c4:  80 8c 20 03  btst  3, %l0
a00b25c8:  12 80 00 07  bne  0xa00b25e4
a00b25cc:  b0 16 22 a0  or  %i0, 0x2a0, %i0
a00b25d0:  7f ff ff 4d  call  0xa00b2304
a00b25d4:  31 28 01 a7  sethi  %hi(0xa0069c00), %i0
a00b25d8:  7f fe bb 5c  call  0xa0061348
a00b25dc:  90 10 00 19  mov  %i1, %o0
a00b25e0:  b0 16 22 e8  or  %i0, 0x2e8, %i0
a00b25e4:  7f fe bb 27  call  0xa0061280
a00b25e8:  81 e8 00 00  restore
a00b25ec:  01 00 00 00  nop
a00b25f0:  81 c7 e0 08  ret
a00b25f4:  81 e8 00 00  restore
