# leon2m FUN_a00f6e30 0xa00f6e30-0xa00f6e88 (88 bytes)
a00f6e30:  9d e3 bf 98  save  %sp, -104, %sp
a00f6e34:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00f6e38:  d8 00 63 b8  ld  [ %g1 + 0x3b8 ], %o4	! 0xa802b7b8
a00f6e3c:  90 10 20 02  mov  2, %o0
a00f6e40:  80 8e 20 80  btst  0x80, %i0
a00f6e44:  12 80 00 0d  bne  0xa00f6e78
a00f6e48:  82 16 3f 80  or  %i0, -128, %g1
a00f6e4c:  92 08 60 ff  and  %g1, 0xff, %o1
a00f6e50:  80 a3 20 00  cmp  %o4, 0
a00f6e54:  12 80 00 06  bne  0xa00f6e6c
a00f6e58:  9a 10 00 09  mov  %o1, %o5
a00f6e5c:  13 33 c0 3b  sethi  %hi(0xcf00ec00), %o1
a00f6e60:  90 12 63 0c  or  %o1, 0x30c, %o0	! 0xcf00ef0c
a00f6e64:  da 22 00 00  st  %o5, [ %o0 ]
a00f6e68:  30 80 00 06  b,a   0xa00f6e80
a00f6e6c:  9f c3 00 00  call  %o4
a00f6e70:  01 00 00 00  nop
a00f6e74:  30 80 00 03  b,a   0xa00f6e80
a00f6e78:  10 bf ff f5  b  0xa00f6e4c
a00f6e7c:  82 0e 20 7f  and  %i0, 0x7f, %g1
a00f6e80:  81 c7 e0 08  ret
a00f6e84:  81 e8 00 00  restore
