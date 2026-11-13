# leon2m FUN_a00fcb1c 0xa00fcb1c-0xa00fcbec (208 bytes)
a00fcb1c:  9d e3 bf 98  save  %sp, -104, %sp
a00fcb20:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fcb24:  90 12 e0 84  or  %o3, 0x84, %o0	! 0xcf012084
a00fcb28:  92 10 20 82  mov  0x82, %o1
a00fcb2c:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a00fcb30:  d2 22 00 00  st  %o1, [ %o0 ]
a00fcb34:  da 03 61 70  ld  [ %o5 + 0x170 ], %o5
a00fcb38:  98 12 e0 34  or  %o3, 0x34, %o4
a00fcb3c:  82 10 20 2e  mov  0x2e, %g1
a00fcb40:  c2 23 00 00  st  %g1, [ %o4 ]
a00fcb44:  80 a3 60 00  cmp  %o5, 0
a00fcb48:  12 80 00 1e  bne  0xa00fcbc0
a00fcb4c:  9e 12 e0 80  or  %o3, 0x80, %o7
a00fcb50:  94 12 e0 40  or  %o3, 0x40, %o2
a00fcb54:  a0 10 20 0f  mov  0xf, %l0
a00fcb58:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fcb5c:  96 10 20 01  mov  1, %o3
a00fcb60:  d6 22 80 00  st  %o3, [ %o2 ]
a00fcb64:  67 fe 42 89  call  0x4008d588
a00fcb68:  01 00 00 00  nop
a00fcb6c:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fcb70:  82 13 20 34  or  %o4, 0x34, %g1	! 0xcf012034
a00fcb74:  e2 00 40 00  ld  [ %g1 ], %l1
a00fcb78:  80 8c 60 2e  btst  0x2e, %l1
a00fcb7c:  12 80 00 15  bne  0xa00fcbd0
a00fcb80:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fcb84:  a2 10 00 01  mov  %g1, %l1
a00fcb88:  67 fe 40 d4  call  0x4008ced8
a00fcb8c:  01 00 00 00  nop
a00fcb90:  67 fe 42 81  call  0x4008d594
a00fcb94:  91 34 20 10  srl  %l0, 0x10, %o0
a00fcb98:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00fcb9c:  83 33 60 10  srl  %o5, 0x10, %g1
a00fcba0:  80 a0 63 e8  cmp  %g1, 0x3e8
a00fcba4:  18 80 00 0c  bgu  0xa00fcbd4
a00fcba8:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fcbac:  d0 04 40 00  ld  [ %l1 ], %o0
a00fcbb0:  80 8a 20 2e  btst  0x2e, %o0
a00fcbb4:  02 bf ff f5  be  0xa00fcb88
a00fcbb8:  92 12 e0 34  or  %o3, 0x34, %o1
a00fcbbc:  30 80 00 07  b,a   0xa00fcbd8
a00fcbc0:  90 10 20 0f  mov  0xf, %o0
a00fcbc4:  9f c3 40 00  call  %o5
a00fcbc8:  92 10 20 01  mov  1, %o1
a00fcbcc:  30 bf ff e6  b,a   0xa00fcb64
a00fcbd0:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fcbd4:  92 12 e0 34  or  %o3, 0x34, %o1	! 0xcf012034
a00fcbd8:  d8 02 40 00  ld  [ %o1 ], %o4
a00fcbdc:  94 10 20 2e  mov  0x2e, %o2
a00fcbe0:  d4 22 40 00  st  %o2, [ %o1 ]
a00fcbe4:  81 c7 e0 08  ret
a00fcbe8:  81 e8 00 00  restore
