# leon2m FUN_a00c1adc 0xa00c1adc-0xa00c1d54 (632 bytes)
a00c1adc:  9d e3 bf 98  save  %sp, -104, %sp
a00c1ae0:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c1ae4:  80 a4 20 02  cmp  %l0, 2
a00c1ae8:  02 80 00 5f  be  0xa00c1c64
a00c1aec:  80 a4 20 03  cmp  %l0, 3
a00c1af0:  02 80 00 7d  be  0xa00c1ce4
a00c1af4:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c1af8:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c1afc:  96 08 60 ff  and  %g1, 0xff, %o3
a00c1b00:  94 02 ff d0  add  %o3, -48, %o2
a00c1b04:  98 0a a0 ff  and  %o2, 0xff, %o4
a00c1b08:  80 a3 20 01  cmp  %o4, 1
a00c1b0c:  18 80 00 90  bgu  0xa00c1d4c
a00c1b10:  b0 10 20 ff  mov  0xff, %i0
a00c1b14:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c1b18:  96 16 22 90  or  %i0, 0x290, %o3	! 0xa802d290
a00c1b1c:  c2 02 e1 1c  ld  [ %o3 + 0x11c ], %g1
a00c1b20:  11 20 00 00  sethi  %hi(0x80000000), %o0
a00c1b24:  9e 28 40 08  andn  %g1, %o0, %o7
a00c1b28:  99 2b 20 1f  sll  %o4, 0x1f, %o4
a00c1b2c:  9a 13 c0 0c  or  %o7, %o4, %o5
a00c1b30:  80 a3 60 00  cmp  %o5, 0
a00c1b34:  06 80 00 37  bl  0xa00c1c10
a00c1b38:  da 22 e1 1c  st  %o5, [ %o3 + 0x11c ]
a00c1b3c:  40 00 5d 30  call  0xa00d8ffc
a00c1b40:  01 00 00 00  nop
a00c1b44:  94 16 22 90  or  %i0, 0x290, %o2
a00c1b48:  f0 02 a1 1c  ld  [ %o2 + 0x11c ], %i0
a00c1b4c:  80 a6 20 00  cmp  %i0, 0
a00c1b50:  16 80 00 3d  bge  0xa00c1c44
a00c1b54:  01 00 00 00  nop
a00c1b58:  40 00 4b 90  call  0xa00d4998
a00c1b5c:  01 00 00 00  nop
a00c1b60:  7f ff db 5b  call  0xa00b88cc
a00c1b64:  01 00 00 00  nop
a00c1b68:  80 a4 20 02  cmp  %l0, 2
a00c1b6c:  02 80 00 41  be  0xa00c1c70
a00c1b70:  80 a4 20 03  cmp  %l0, 3
a00c1b74:  02 80 00 5f  be  0xa00c1cf0
a00c1b78:  90 10 20 30  mov  0x30, %o0
a00c1b7c:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c1b80:  94 16 20 78  or  %i0, 0x78, %o2	! 0xa802d078
a00c1b84:  9e 10 20 35  mov  0x35, %o7
a00c1b88:  92 10 20 36  mov  0x36, %o1
a00c1b8c:  82 10 20 2b  mov  0x2b, %g1
a00c1b90:  98 10 20 0d  mov  0xd, %o4
a00c1b94:  de 2e 20 78  stb  %o7, [ %i0 + 0x78 ]
a00c1b98:  d2 2a a0 01  stb  %o1, [ %o2 + 1 ]
a00c1b9c:  d0 2a a0 03  stb  %o0, [ %o2 + 3 ]
a00c1ba0:  c2 2a a0 04  stb  %g1, [ %o2 + 4 ]
a00c1ba4:  d8 2a a0 05  stb  %o4, [ %o2 + 5 ]
a00c1ba8:  80 a4 20 02  cmp  %l0, 2
a00c1bac:  02 80 00 3e  be  0xa00c1ca4
a00c1bb0:  d0 2a a0 02  stb  %o0, [ %o2 + 2 ]
a00c1bb4:  80 a4 20 03  cmp  %l0, 3
a00c1bb8:  02 80 00 5b  be  0xa00c1d24
a00c1bbc:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c1bc0:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00c1bc4:  92 16 20 d0  or  %i0, 0xd0, %o1	! 0xa802d0d0
a00c1bc8:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]
a00c1bcc:  c0 2e 20 d0  clrb  [ %i0 + 0xd0 ]
a00c1bd0:  c0 2a 60 19  clrb  [ %o1 + 0x19 ]
a00c1bd4:  c0 2a 60 01  clrb  [ %o1 + 1 ]
a00c1bd8:  c0 2a 60 07  clrb  [ %o1 + 7 ]
a00c1bdc:  80 a4 20 02  cmp  %l0, 2
a00c1be0:  02 80 00 3a  be  0xa00c1cc8
a00c1be4:  c0 2a 60 0a  clrb  [ %o1 + 0xa ]
a00c1be8:  80 a4 20 03  cmp  %l0, 3
a00c1bec:  12 80 00 3a  bne  0xa00c1cd4
a00c1bf0:  90 10 00 10  mov  %l0, %o0
a00c1bf4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c1bf8:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c1bfc:  90 10 20 03  mov  3, %o0
a00c1c00:  40 02 1a fa  call  0xa01487e8
a00c1c04:  92 10 20 06  mov  6, %o1
a00c1c08:  10 80 00 51  b  0xa00c1d4c
a00c1c0c:  b0 10 20 00  clr  %i0
a00c1c10:  d2 02 e0 b0  ld  [ %o3 + 0xb0 ], %o1
a00c1c14:  80 a2 60 00  cmp  %o1, 0
a00c1c18:  02 bf ff c9  be  0xa00c1b3c
a00c1c1c:  01 00 00 00  nop
a00c1c20:  40 00 50 c7  call  0xa00d5f3c
a00c1c24:  c0 22 e0 b0  clr  [ %o3 + 0xb0 ]
a00c1c28:  40 00 5c f5  call  0xa00d8ffc
a00c1c2c:  01 00 00 00  nop
a00c1c30:  94 16 22 90  or  %i0, 0x290, %o2
a00c1c34:  f0 02 a1 1c  ld  [ %o2 + 0x11c ], %i0
a00c1c38:  80 a6 20 00  cmp  %i0, 0
a00c1c3c:  06 bf ff c7  bl  0xa00c1b58
a00c1c40:  01 00 00 00  nop
a00c1c44:  40 01 8b 7f  call  0xa0124a40
a00c1c48:  01 00 00 00  nop
a00c1c4c:  80 8a 20 ff  btst  0xff, %o0
a00c1c50:  12 bf ff c2  bne  0xa00c1b58
a00c1c54:  01 00 00 00  nop
a00c1c58:  40 01 8b 65  call  0xa01249ec
a00c1c5c:  01 00 00 00  nop
a00c1c60:  30 bf ff be  b,a   0xa00c1b58
a00c1c64:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c1c68:  10 bf ff a5  b  0xa00c1afc
a00c1c6c:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c1c70:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c1c74:  a0 12 21 28  or  %o0, 0x128, %l0	! 0xa802d128
a00c1c78:  9e 10 20 30  mov  0x30, %o7
a00c1c7c:  82 10 20 35  mov  0x35, %g1
a00c1c80:  98 10 20 0d  mov  0xd, %o4
a00c1c84:  9a 10 20 36  mov  0x36, %o5
a00c1c88:  96 10 20 2b  mov  0x2b, %o3
a00c1c8c:  c2 2a 21 28  stb  %g1, [ %o0 + 0x128 ]
a00c1c90:  d8 2c 20 05  stb  %o4, [ %l0 + 5 ]
a00c1c94:  da 2c 20 01  stb  %o5, [ %l0 + 1 ]
a00c1c98:  de 2c 20 03  stb  %o7, [ %l0 + 3 ]
a00c1c9c:  d6 2c 20 04  stb  %o3, [ %l0 + 4 ]
a00c1ca0:  de 2c 20 02  stb  %o7, [ %l0 + 2 ]
a00c1ca4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c1ca8:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c1cac:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c1cb0:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00c1cb4:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c1cb8:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c1cbc:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c1cc0:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c1cc4:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c1cc8:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c1ccc:  94 13 e1 28  or  %o7, 0x128, %o2	! 0xa802d128
a00c1cd0:  90 10 20 02  mov  2, %o0
a00c1cd4:  40 02 1a c5  call  0xa01487e8
a00c1cd8:  92 10 20 06  mov  6, %o1
a00c1cdc:  10 80 00 1c  b  0xa00c1d4c
a00c1ce0:  b0 10 20 00  clr  %i0
a00c1ce4:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c1ce8:  10 bf ff 85  b  0xa00c1afc
a00c1cec:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c1cf0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c1cf4:  92 12 e1 08  or  %o3, 0x108, %o1	! 0xa802d108
a00c1cf8:  b0 10 20 30  mov  0x30, %i0
a00c1cfc:  9a 10 20 35  mov  0x35, %o5
a00c1d00:  9e 10 20 0d  mov  0xd, %o7
a00c1d04:  a0 10 20 36  mov  0x36, %l0
a00c1d08:  94 10 20 2b  mov  0x2b, %o2
a00c1d0c:  da 2a e1 08  stb  %o5, [ %o3 + 0x108 ]
a00c1d10:  de 2a 60 05  stb  %o7, [ %o1 + 5 ]
a00c1d14:  e0 2a 60 01  stb  %l0, [ %o1 + 1 ]
a00c1d18:  f0 2a 60 03  stb  %i0, [ %o1 + 3 ]
a00c1d1c:  d4 2a 60 04  stb  %o2, [ %o1 + 4 ]
a00c1d20:  f0 2a 60 02  stb  %i0, [ %o1 + 2 ]
a00c1d24:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c1d28:  9a 12 20 98  or  %o0, 0x98, %o5	! 0xa802d098
a00c1d2c:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00c1d30:  c0 2b 20 98  clrb  [ %o4 + 0x98 ]	! 0xa802b098
a00c1d34:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00c1d38:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00c1d3c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00c1d40:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00c1d44:  10 bf ff ac  b  0xa00c1bf4
a00c1d48:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00c1d4c:  81 c7 e0 08  ret
a00c1d50:  81 e8 00 00  restore
