# leon2m FUN_a0104b2c 0xa0104b2c-0xa0104c34 (80 bytes)
a0104b2c:  9d e3 bf 98  save  %sp, -104, %sp
a0104b30:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0104b34:  90 10 00 18  mov  %i0, %o0
a0104b38:  92 10 20 54  mov  0x54, %o1
a0104b3c:  7f ff b5 d7  call  0xa00f2298
a0104b40:  94 10 20 01  mov  1, %o2
a0104b44:  80 a6 20 08  cmp  %i0, 8
a0104b48:  18 80 00 09  bgu  0xa0104b6c
a0104b4c:  9a 0e 60 ff  and  %i1, 0xff, %o5
a0104b50:  11 00 02 87  sethi  %hi(0xa1c00), %o0
a0104b54:  83 2e 20 02  sll  %i0, 2, %g1
a0104b58:  9a 12 21 5c  or  %o0, 0x15c, %o5
a0104b5c:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0104b60:  81 c3 00 00  jmp  %o4
a0104b64:  01 00 00 00  nop
a0104b68:  9a 0e 60 ff  and  %i1, 0xff, %o5
a0104b6c:  03 33 c0 4e  sethi  %hi(0xcf013800), %g1
a0104b70:  da 20 40 00  st  %o5, [ %g1 ]
a0104b74:  30 80 00 2e  b,a   0xa0104c2c
a0104b78:  96 0e 60 ff  and  %i1, 0xff, %o3
a0104b7c:  1f 33 c0 4e  sethi  %hi(0xcf013800), %o7
a0104b80:  d6 23 c0 00  st  %o3, [ %o7 ]
a0104b84:  b2 13 e1 00  or  %o7, 0x100, %i1
a0104b88:  d6 26 40 00  st  %o3, [ %i1 ]
a0104b8c:  b0 13 e2 00  or  %o7, 0x200, %i0
a0104b90:  d6 26 00 00  st  %o3, [ %i0 ]
a0104b94:  9a 13 e3 00  or  %o7, 0x300, %o5
a0104b98:  d6 23 40 00  st  %o3, [ %o5 ]
a0104b9c:  1b 33 c0 6c  sethi  %hi(0xcf01b000), %o5
a0104ba0:  d6 23 40 00  st  %o3, [ %o5 ]
a0104ba4:  94 13 61 00  or  %o5, 0x100, %o2
a0104ba8:  d6 22 80 00  st  %o3, [ %o2 ]
a0104bac:  90 13 60 7c  or  %o5, 0x7c, %o0
a0104bb0:  d2 02 00 00  ld  [ %o0 ], %o1
a0104bb4:  82 12 60 80  or  %o1, 0x80, %g1
a0104bb8:  c2 22 00 00  st  %g1, [ %o0 ]
a0104bbc:  9a 13 61 7c  or  %o5, 0x17c, %o5
a0104bc0:  d0 03 40 00  ld  [ %o5 ], %o0
a0104bc4:  98 12 20 80  or  %o0, 0x80, %o4
a0104bc8:  d8 23 40 00  st  %o4, [ %o5 ]
a0104bcc:  30 80 00 18  b,a   0xa0104c2c
a0104bd0:  13 33 c0 4e  sethi  %hi(0xcf013800), %o1
a0104bd4:  9a 0e 60 ff  and  %i1, 0xff, %o5
a0104bd8:  10 bf ff e6  b  0xa0104b70
a0104bdc:  82 12 61 00  or  %o1, 0x100, %g1
a0104be0:  15 33 c0 4e  sethi  %hi(0xcf013800), %o2
a0104be4:  9a 0e 60 ff  and  %i1, 0xff, %o5
a0104be8:  10 bf ff e2  b  0xa0104b70
a0104bec:  82 12 a2 00  or  %o2, 0x200, %g1
a0104bf0:  17 33 c0 4e  sethi  %hi(0xcf013800), %o3
a0104bf4:  9a 0e 60 ff  and  %i1, 0xff, %o5
a0104bf8:  10 bf ff de  b  0xa0104b70
a0104bfc:  82 12 e3 00  or  %o3, 0x300, %g1
a0104c00:  1f 33 c0 6c  sethi  %hi(0xcf01b000), %o7
a0104c04:  b0 0e 60 ff  and  %i1, 0xff, %i0
a0104c08:  f0 23 c0 00  st  %i0, [ %o7 ]
a0104c0c:  10 bf ff ed  b  0xa0104bc0
a0104c10:  9a 13 e0 7c  or  %o7, 0x7c, %o5
a0104c14:  98 0e 60 ff  and  %i1, 0xff, %o4
a0104c18:  1b 33 c0 6c  sethi  %hi(0xcf01b000), %o5
a0104c1c:  b2 13 61 00  or  %o5, 0x100, %i1	! 0xcf01b100
a0104c20:  d8 26 40 00  st  %o4, [ %i1 ]
a0104c24:  10 bf ff e7  b  0xa0104bc0
a0104c28:  9a 13 61 7c  or  %o5, 0x17c, %o5
a0104c2c:  81 c7 e0 08  ret
a0104c30:  81 e8 00 00  restore
