# leon2m FUN_a00fcbec 0xa00fcbec-0xa00fccbc (208 bytes)
a00fcbec:  9d e3 bf 98  save  %sp, -104, %sp
a00fcbf0:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fcbf4:  90 12 e0 84  or  %o3, 0x84, %o0	! 0xcf012084
a00fcbf8:  92 10 20 86  mov  0x86, %o1
a00fcbfc:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a00fcc00:  d2 22 00 00  st  %o1, [ %o0 ]
a00fcc04:  da 03 61 70  ld  [ %o5 + 0x170 ], %o5
a00fcc08:  98 12 e0 34  or  %o3, 0x34, %o4
a00fcc0c:  82 10 20 2e  mov  0x2e, %g1
a00fcc10:  c2 23 00 00  st  %g1, [ %o4 ]
a00fcc14:  80 a3 60 00  cmp  %o5, 0
a00fcc18:  12 80 00 1e  bne  0xa00fcc90
a00fcc1c:  9e 12 e0 80  or  %o3, 0x80, %o7
a00fcc20:  94 12 e0 40  or  %o3, 0x40, %o2
a00fcc24:  a0 10 20 0f  mov  0xf, %l0
a00fcc28:  e0 23 c0 00  st  %l0, [ %o7 ]
a00fcc2c:  96 10 20 01  mov  1, %o3
a00fcc30:  d6 22 80 00  st  %o3, [ %o2 ]
a00fcc34:  67 fe 42 55  call  0x4008d588
a00fcc38:  01 00 00 00  nop
a00fcc3c:  19 33 c0 48  sethi  %hi(0xcf012000), %o4
a00fcc40:  82 13 20 34  or  %o4, 0x34, %g1	! 0xcf012034
a00fcc44:  e2 00 40 00  ld  [ %g1 ], %l1
a00fcc48:  80 8c 60 2e  btst  0x2e, %l1
a00fcc4c:  12 80 00 15  bne  0xa00fcca0
a00fcc50:  a1 2a 20 10  sll  %o0, 0x10, %l0
a00fcc54:  a2 10 00 01  mov  %g1, %l1
a00fcc58:  67 fe 40 a0  call  0x4008ced8
a00fcc5c:  01 00 00 00  nop
a00fcc60:  67 fe 42 4d  call  0x4008d594
a00fcc64:  91 34 20 10  srl  %l0, 0x10, %o0
a00fcc68:  9b 2a 20 10  sll  %o0, 0x10, %o5
a00fcc6c:  83 33 60 10  srl  %o5, 0x10, %g1
a00fcc70:  80 a0 63 e8  cmp  %g1, 0x3e8
a00fcc74:  18 80 00 0c  bgu  0xa00fcca4
a00fcc78:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fcc7c:  d0 04 40 00  ld  [ %l1 ], %o0
a00fcc80:  80 8a 20 2e  btst  0x2e, %o0
a00fcc84:  02 bf ff f5  be  0xa00fcc58
a00fcc88:  92 12 e0 34  or  %o3, 0x34, %o1
a00fcc8c:  30 80 00 07  b,a   0xa00fcca8
a00fcc90:  90 10 20 0f  mov  0xf, %o0
a00fcc94:  9f c3 40 00  call  %o5
a00fcc98:  92 10 20 01  mov  1, %o1
a00fcc9c:  30 bf ff e6  b,a   0xa00fcc34
a00fcca0:  17 33 c0 48  sethi  %hi(0xcf012000), %o3
a00fcca4:  92 12 e0 34  or  %o3, 0x34, %o1	! 0xcf012034
a00fcca8:  d8 02 40 00  ld  [ %o1 ], %o4
a00fccac:  94 10 20 2e  mov  0x2e, %o2
a00fccb0:  d4 22 40 00  st  %o2, [ %o1 ]
a00fccb4:  81 c7 e0 08  ret
a00fccb8:  81 e8 00 00  restore
