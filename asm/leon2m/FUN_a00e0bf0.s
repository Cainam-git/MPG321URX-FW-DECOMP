# leon2m FUN_a00e0bf0 0xa00e0bf0-0xa00e0c68 (120 bytes)
a00e0bf0:  9d e3 bf 98  save  %sp, -104, %sp
a00e0bf4:  b3 2e 60 10  sll  %i1, 0x10, %i1
a00e0bf8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00e0bfc:  03 00 06 65  sethi  %hi(0x199400), %g1
a00e0c00:  b3 36 60 10  srl  %i1, 0x10, %i1
a00e0c04:  80 a6 20 00  cmp  %i0, 0
a00e0c08:  b8 10 61 f0  or  %g1, 0x1f0, %i4
a00e0c0c:  02 80 00 08  be  0xa00e0c2c
a00e0c10:  90 10 00 19  mov  %i1, %o0
a00e0c14:  13 00 06 65  sethi  %hi(0x199400), %o1
a00e0c18:  80 a6 20 01  cmp  %i0, 1
a00e0c1c:  02 80 00 04  be  0xa00e0c2c
a00e0c20:  b8 12 61 f8  or  %o1, 0x1f8, %i4
a00e0c24:  15 00 06 65  sethi  %hi(0x199400), %o2
a00e0c28:  b8 12 a2 00  or  %o2, 0x200, %i4	! 0x199600
a00e0c2c:  7f ff fd ab  call  0xa00e02d8
a00e0c30:  01 00 00 00  nop
a00e0c34:  b4 10 00 08  mov  %o0, %i2
a00e0c38:  7f ff fd ab  call  0xa00e02e4
a00e0c3c:  90 10 00 19  mov  %i1, %o0
a00e0c40:  b6 10 00 08  mov  %o0, %i3
a00e0c44:  90 10 00 18  mov  %i0, %o0
a00e0c48:  7f ff fd a9  call  0xa00e02ec
a00e0c4c:  92 10 00 19  mov  %i1, %o1
a00e0c50:  31 00 06 65  sethi  %hi(0x199400), %i0
a00e0c54:  b2 10 00 1c  mov  %i4, %i1
a00e0c58:  b0 16 22 08  or  %i0, 0x208, %i0
a00e0c5c:  7f ff f9 45  call  0xa00df170
a00e0c60:  99 e8 00 08  restore  %g0, %o0, %o4
a00e0c64:  01 00 00 00  nop
