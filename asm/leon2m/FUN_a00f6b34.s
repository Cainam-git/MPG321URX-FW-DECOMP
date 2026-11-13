# leon2m FUN_a00f6b34 0xa00f6b34-0xa00f6c38 (260 bytes)
a00f6b34:  80 8a 20 01  btst  1, %o0
a00f6b38:  02 80 00 08  be  0xa00f6b58
a00f6b3c:  80 8a 20 02  btst  2, %o0
a00f6b40:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6b44:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xcf00ef00
a00f6b48:  c2 03 40 00  ld  [ %o5 ], %g1
a00f6b4c:  82 10 60 40  or  %g1, 0x40, %g1
a00f6b50:  c2 23 40 00  st  %g1, [ %o5 ]
a00f6b54:  80 8a 20 02  btst  2, %o0
a00f6b58:  02 80 00 08  be  0xa00f6b78
a00f6b5c:  80 8a 20 04  btst  4, %o0
a00f6b60:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6b64:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xcf00ef00
a00f6b68:  c2 03 40 00  ld  [ %o5 ], %g1
a00f6b6c:  82 10 60 20  or  %g1, 0x20, %g1
a00f6b70:  c2 23 40 00  st  %g1, [ %o5 ]
a00f6b74:  80 8a 20 04  btst  4, %o0
a00f6b78:  02 80 00 08  be  0xa00f6b98
a00f6b7c:  80 8a 20 08  btst  8, %o0
a00f6b80:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6b84:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xcf00ef00
a00f6b88:  c2 03 40 00  ld  [ %o5 ], %g1
a00f6b8c:  82 10 60 10  or  %g1, 0x10, %g1
a00f6b90:  c2 23 40 00  st  %g1, [ %o5 ]
a00f6b94:  80 8a 20 08  btst  8, %o0
a00f6b98:  02 80 00 08  be  0xa00f6bb8
a00f6b9c:  80 8a 20 10  btst  0x10, %o0
a00f6ba0:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6ba4:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xcf00ef00
a00f6ba8:  c2 03 40 00  ld  [ %o5 ], %g1
a00f6bac:  82 10 60 08  or  %g1, 8, %g1
a00f6bb0:  c2 23 40 00  st  %g1, [ %o5 ]
a00f6bb4:  80 8a 20 10  btst  0x10, %o0
a00f6bb8:  02 80 00 08  be  0xa00f6bd8
a00f6bbc:  80 8a 20 20  btst  0x20, %o0
a00f6bc0:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6bc4:  9a 13 63 00  or  %o5, 0x300, %o5	! 0xcf00ef00
a00f6bc8:  c2 03 40 00  ld  [ %o5 ], %g1
a00f6bcc:  82 10 60 04  or  %g1, 4, %g1
a00f6bd0:  c2 23 40 00  st  %g1, [ %o5 ]
a00f6bd4:  80 8a 20 20  btst  0x20, %o0
a00f6bd8:  02 80 00 08  be  0xa00f6bf8
a00f6bdc:  80 8a 20 40  btst  0x40, %o0
a00f6be0:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6be4:  9a 13 63 30  or  %o5, 0x330, %o5	! 0xcf00ef30
a00f6be8:  c2 03 40 00  ld  [ %o5 ], %g1
a00f6bec:  82 10 60 81  or  %g1, 0x81, %g1
a00f6bf0:  c2 23 40 00  st  %g1, [ %o5 ]
a00f6bf4:  80 8a 20 40  btst  0x40, %o0
a00f6bf8:  02 80 00 08  be  0xa00f6c18
a00f6bfc:  80 8a 20 80  btst  0x80, %o0
a00f6c00:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6c04:  9a 13 63 30  or  %o5, 0x330, %o5	! 0xcf00ef30
a00f6c08:  c2 03 40 00  ld  [ %o5 ], %g1
a00f6c0c:  82 10 60 41  or  %g1, 0x41, %g1
a00f6c10:  c2 23 40 00  st  %g1, [ %o5 ]
a00f6c14:  80 8a 20 80  btst  0x80, %o0
a00f6c18:  02 80 00 06  be  0xa00f6c30
a00f6c1c:  1b 33 c0 3b  sethi  %hi(0xcf00ec00), %o5
a00f6c20:  90 13 63 30  or  %o5, 0x330, %o0	! 0xcf00ef30
a00f6c24:  c2 02 00 00  ld  [ %o0 ], %g1
a00f6c28:  82 10 60 11  or  %g1, 0x11, %g1
a00f6c2c:  c2 22 00 00  st  %g1, [ %o0 ]
a00f6c30:  81 c3 e0 08  retl
a00f6c34:  01 00 00 00  nop
