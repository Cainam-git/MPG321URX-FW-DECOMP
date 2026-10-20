# leon2m FUN_a010a884 0xa010a884-0xa010a8f0 (108 bytes)
a010a884:  9d e3 bf 98  save  %sp, -104, %sp
a010a888:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a010a88c:  82 16 22 80  or  %i0, 0x280, %g1	! 0xcf011a80
a010a890:  da 00 40 00  ld  [ %g1 ], %o5
a010a894:  80 8b 60 80  btst  0x80, %o5
a010a898:  02 80 00 0f  be  0xa010a8d4
a010a89c:  90 16 22 c0  or  %i0, 0x2c0, %o0
a010a8a0:  7f ff a1 f6  call  0xa00f3078
a010a8a4:  01 00 00 00  nop
a010a8a8:  a0 10 00 08  mov  %o0, %l0
a010a8ac:  7f ff a1 f3  call  0xa00f3078
a010a8b0:  90 16 22 c8  or  %i0, 0x2c8, %o0
a010a8b4:  a0 04 00 08  add  %l0, %o0, %l0
a010a8b8:  7f ff a1 f0  call  0xa00f3078
a010a8bc:  90 16 22 d0  or  %i0, 0x2d0, %o0
a010a8c0:  a0 04 00 08  add  %l0, %o0, %l0
a010a8c4:  7f ff a1 ed  call  0xa00f3078
a010a8c8:  90 16 22 d8  or  %i0, 0x2d8, %o0
a010a8cc:  10 80 00 05  b  0xa010a8e0
a010a8d0:  90 04 00 08  add  %l0, %o0, %o0
a010a8d4:  11 33 c0 47  sethi  %hi(0xcf011c00), %o0
a010a8d8:  7f ff a1 e8  call  0xa00f3078
a010a8dc:  90 12 20 20  or  %o0, 0x20, %o0	! 0xcf011c20
a010a8e0:  b1 2a 20 10  sll  %o0, 0x10, %i0
a010a8e4:  b1 36 20 10  srl  %i0, 0x10, %i0
a010a8e8:  81 c7 e0 08  ret
a010a8ec:  81 e8 00 00  restore
