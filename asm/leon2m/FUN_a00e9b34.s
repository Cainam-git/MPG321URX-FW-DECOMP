# leon2m FUN_a00e9b34 0xa00e9b34-0xa00e9c80 (332 bytes)
a00e9b34:  9d e3 bf 90  save  %sp, -112, %sp
a00e9b38:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00e9b3c:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00e9b40:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00e9b44:  92 12 60 38  or  %o1, 0x38, %o1
a00e9b48:  94 12 a0 28  or  %o2, 0x28, %o2
a00e9b4c:  96 12 e3 08  or  %o3, 0x308, %o3
a00e9b50:  a1 2f 20 02  sll  %i4, 2, %l0
a00e9b54:  90 10 00 18  mov  %i0, %o0
a00e9b58:  80 a7 3f ff  cmp  %i4, -1
a00e9b5c:  98 10 00 1d  mov  %i5, %o4
a00e9b60:  02 80 00 24  be  0xa00e9bf0
a00e9b64:  e2 07 a0 40  ld  [ %fp + 0x40 ], %l1
a00e9b68:  13 2a 00 9a  sethi  %hi(0xa8026800), %o1
a00e9b6c:  94 12 60 38  or  %o1, 0x38, %o2	! 0xa8026838
a00e9b70:  3b 2a 00 9a  sethi  %hi(0xa8026800), %i5
a00e9b74:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00e9b78:  9e 17 60 28  or  %i5, 0x28, %o7
a00e9b7c:  d2 02 80 10  ld  [ %o2 + %l0 ], %o1
a00e9b80:  9a 12 e3 08  or  %o3, 0x308, %o5
a00e9b84:  d4 03 c0 10  ld  [ %o7 + %l0 ], %o2
a00e9b88:  7f ff da fb  call  0xa00e0774
a00e9b8c:  d6 03 40 10  ld  [ %o5 + %l0 ], %o3
a00e9b90:  03 2a 00 98  sethi  %hi(0xa8026000), %g1
a00e9b94:  94 10 63 48  or  %g1, 0x348, %o2	! 0xa8026348
a00e9b98:  11 2a 00 98  sethi  %hi(0xa8026000), %o0
a00e9b9c:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00e9ba0:  d2 02 80 10  ld  [ %o2 + %l0 ], %o1
a00e9ba4:  ba 12 23 28  or  %o0, 0x328, %i5
a00e9ba8:  9a 13 e2 58  or  %o7, 0x258, %o5
a00e9bac:  d4 07 40 10  ld  [ %i5 + %l0 ], %o2
a00e9bb0:  d6 03 40 10  ld  [ %o5 + %l0 ], %o3
a00e9bb4:  90 10 00 18  mov  %i0, %o0
a00e9bb8:  7f ff da ef  call  0xa00e0774
a00e9bbc:  98 10 00 1b  mov  %i3, %o4
a00e9bc0:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00e9bc4:  15 2a 00 98  sethi  %hi(0xa8026000), %o2
a00e9bc8:  98 12 e2 48  or  %o3, 0x248, %o4
a00e9bcc:  13 2a 00 98  sethi  %hi(0xa8026000), %o1
a00e9bd0:  90 12 a3 18  or  %o2, 0x318, %o0
a00e9bd4:  d6 03 00 10  ld  [ %o4 + %l0 ], %o3
a00e9bd8:  82 12 63 38  or  %o1, 0x338, %g1
a00e9bdc:  d4 02 00 10  ld  [ %o0 + %l0 ], %o2
a00e9be0:  d2 00 40 10  ld  [ %g1 + %l0 ], %o1
a00e9be4:  98 10 00 1b  mov  %i3, %o4
a00e9be8:  10 80 00 14  b  0xa00e9c38
a00e9bec:  90 10 00 18  mov  %i0, %o0
a00e9bf0:  7f ff da e1  call  0xa00e0774
a00e9bf4:  3b 2a 00 98  sethi  %hi(0xa8026000), %i5
a00e9bf8:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00e9bfc:  21 2a 00 98  sethi  %hi(0xa8026000), %l0
a00e9c00:  90 10 00 18  mov  %i0, %o0
a00e9c04:  92 17 63 48  or  %i5, 0x348, %o1
a00e9c08:  94 14 23 28  or  %l0, 0x328, %o2
a00e9c0c:  96 13 e2 58  or  %o7, 0x258, %o3
a00e9c10:  7f ff da d9  call  0xa00e0774
a00e9c14:  98 10 00 1b  mov  %i3, %o4
a00e9c18:  19 2a 00 98  sethi  %hi(0xa8026000), %o4
a00e9c1c:  1b 2a 00 98  sethi  %hi(0xa8026000), %o5
a00e9c20:  94 13 23 18  or  %o4, 0x318, %o2
a00e9c24:  03 2a 00 ad  sethi  %hi(0xa802b400), %g1
a00e9c28:  90 10 00 18  mov  %i0, %o0
a00e9c2c:  92 13 63 38  or  %o5, 0x338, %o1
a00e9c30:  96 10 62 48  or  %g1, 0x248, %o3
a00e9c34:  98 10 00 1b  mov  %i3, %o4
a00e9c38:  7f ff da cf  call  0xa00e0774
a00e9c3c:  01 00 00 00  nop
a00e9c40:  b6 07 bf f0  add  %fp, -16, %i3
a00e9c44:  90 10 00 18  mov  %i0, %o0
a00e9c48:  92 10 00 19  mov  %i1, %o1
a00e9c4c:  f6 23 a0 40  st  %i3, [ %sp + 0x40 ]
a00e9c50:  94 10 00 1a  mov  %i2, %o2
a00e9c54:  96 10 00 1c  mov  %i4, %o3
a00e9c58:  d8 07 a0 5c  ld  [ %fp + 0x5c ], %o4
a00e9c5c:  7f ff fc 84  call  0xa00e8e6c
a00e9c60:  01 00 00 00  nop
a00e9c64:  00 00 00 08  unimp  0x8
a00e9c68:  f0 07 bf f4  ld  [ %fp + -12 ], %i0
a00e9c6c:  f2 07 bf f0  ld  [ %fp + -16 ], %i1
a00e9c70:  f0 24 60 04  st  %i0, [ %l1 + 4 ]
a00e9c74:  f2 24 40 00  st  %i1, [ %l1 ]
a00e9c78:  81 c7 e0 0c  jmp  %i7 + 0xc
a00e9c7c:  91 e8 00 11  restore  %g0, %l1, %o0
