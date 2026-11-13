# leon2m FUN_a00c29d8 0xa00c29d8-0xa00c2bd8 (512 bytes)
a00c29d8:  9d e3 bf 98  save  %sp, -104, %sp
a00c29dc:  a0 0e 20 ff  and  %i0, 0xff, %l0
a00c29e0:  80 a4 20 02  cmp  %l0, 2
a00c29e4:  02 80 00 55  be  0xa00c2b38
a00c29e8:  80 a4 20 03  cmp  %l0, 3
a00c29ec:  02 80 00 5c  be  0xa00c2b5c
a00c29f0:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c29f4:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00c29f8:  94 08 60 ff  and  %g1, 0xff, %o2
a00c29fc:  96 02 bf d0  add  %o2, -48, %o3
a00c2a00:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00c2a04:  80 a3 60 04  cmp  %o5, 4
a00c2a08:  18 80 00 72  bgu  0xa00c2bd0
a00c2a0c:  b0 10 20 ff  mov  0xff, %i0
a00c2a10:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00c2a14:  31 2a 00 b3  sethi  %hi(0xa802cc00), %i0
a00c2a18:  d6 2b e3 cf  stb  %o3, [ %o7 + 0x3cf ]
a00c2a1c:  d8 16 23 f8  lduh  [ %i0 + 0x3f8 ], %o4
a00c2a20:  17 00 00 18  sethi  %hi(0x6000), %o3
a00c2a24:  80 8a c0 0c  btst  %o3, %o4
a00c2a28:  02 80 00 47  be  0xa00c2b44
a00c2a2c:  01 00 00 00  nop
a00c2a30:  80 a4 20 02  cmp  %l0, 2
a00c2a34:  02 80 00 24  be  0xa00c2ac4
a00c2a38:  80 a4 20 03  cmp  %l0, 3
a00c2a3c:  02 80 00 4b  be  0xa00c2b68
a00c2a40:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00c2a44:  94 12 e0 78  or  %o3, 0x78, %o2	! 0xa802d078
a00c2a48:  9e 10 20 30  mov  0x30, %o7
a00c2a4c:  90 10 20 35  mov  0x35, %o0
a00c2a50:  b0 10 20 36  mov  0x36, %i0
a00c2a54:  98 10 20 2b  mov  0x2b, %o4
a00c2a58:  9a 10 20 0d  mov  0xd, %o5
a00c2a5c:  d0 2a e0 78  stb  %o0, [ %o3 + 0x78 ]
a00c2a60:  f0 2a a0 01  stb  %i0, [ %o2 + 1 ]
a00c2a64:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00c2a68:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00c2a6c:  da 2a a0 05  stb  %o5, [ %o2 + 5 ]
a00c2a70:  80 a4 20 02  cmp  %l0, 2
a00c2a74:  02 80 00 21  be  0xa00c2af8
a00c2a78:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00c2a7c:  80 a4 20 03  cmp  %l0, 3
a00c2a80:  02 80 00 47  be  0xa00c2b9c
a00c2a84:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00c2a88:  b0 13 20 d0  or  %o4, 0xd0, %i0	! 0xa802d0d0
a00c2a8c:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00c2a90:  c0 2a e0 9c  clrb  [ %o3 + 0x9c ]	! 0xa802b09c
a00c2a94:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00c2a98:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00c2a9c:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00c2aa0:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00c2aa4:  80 a4 20 02  cmp  %l0, 2
a00c2aa8:  02 80 00 1d  be  0xa00c2b1c
a00c2aac:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00c2ab0:  80 a4 20 03  cmp  %l0, 3
a00c2ab4:  12 80 00 1d  bne  0xa00c2b28
a00c2ab8:  90 10 00 10  mov  %l0, %o0
a00c2abc:  10 80 00 42  b  0xa00c2bc4
a00c2ac0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c2ac4:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c2ac8:  a0 12 a1 28  or  %o2, 0x128, %l0	! 0xa802d128
a00c2acc:  90 10 20 30  mov  0x30, %o0
a00c2ad0:  98 10 20 35  mov  0x35, %o4
a00c2ad4:  9a 10 20 0d  mov  0xd, %o5
a00c2ad8:  92 10 20 36  mov  0x36, %o1
a00c2adc:  82 10 20 2b  mov  0x2b, %g1
a00c2ae0:  d8 2a a1 28  stb  %o4, [ %o2 + 0x128 ]
a00c2ae4:  da 2c 20 05  stb  %o5, [ %l0 + 5 ]
a00c2ae8:  d2 2c 20 01  stb  %o1, [ %l0 + 1 ]
a00c2aec:  d0 2c 20 03  stb  %o0, [ %l0 + 3 ]
a00c2af0:  c2 2c 20 04  stb  %g1, [ %l0 + 4 ]
a00c2af4:  d0 2c 20 02  stb  %o0, [ %l0 + 2 ]
a00c2af8:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00c2afc:  94 14 20 40  or  %l0, 0x40, %o2	! 0xa802d040
a00c2b00:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00c2b04:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]	! 0xa802b09a
a00c2b08:  c0 2c 20 40  clrb  [ %l0 + 0x40 ]
a00c2b0c:  c0 2a a0 19  clrb  [ %o2 + 0x19 ]
a00c2b10:  c0 2a a0 01  clrb  [ %o2 + 1 ]
a00c2b14:  c0 2a a0 07  clrb  [ %o2 + 7 ]
a00c2b18:  c0 2a a0 0a  clrb  [ %o2 + 0xa ]
a00c2b1c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c2b20:  94 12 21 28  or  %o0, 0x128, %o2	! 0xa802d128
a00c2b24:  90 10 20 02  mov  2, %o0
a00c2b28:  40 02 17 30  call  0xa01487e8
a00c2b2c:  92 10 20 06  mov  6, %o1
a00c2b30:  10 80 00 28  b  0xa00c2bd0
a00c2b34:  b0 10 20 00  clr  %i0
a00c2b38:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00c2b3c:  10 bf ff af  b  0xa00c29f8
a00c2b40:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00c2b44:  7f ff 39 25  call  0xa0090fd8
a00c2b48:  01 00 00 00  nop
a00c2b4c:  7f ff 39 18  call  0xa0090fac
a00c2b50:  01 00 00 00  nop
a00c2b54:  10 bf ff b8  b  0xa00c2a34
a00c2b58:  80 a4 20 02  cmp  %l0, 2
a00c2b5c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00c2b60:  10 bf ff a6  b  0xa00c29f8
a00c2b64:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00c2b68:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00c2b6c:  9e 12 61 08  or  %o1, 0x108, %o7	! 0xa802d108
a00c2b70:  b0 10 20 30  mov  0x30, %i0
a00c2b74:  82 10 20 35  mov  0x35, %g1
a00c2b78:  90 10 20 0d  mov  0xd, %o0
a00c2b7c:  a0 10 20 36  mov  0x36, %l0
a00c2b80:  96 10 20 2b  mov  0x2b, %o3
a00c2b84:  c2 2a 61 08  stb  %g1, [ %o1 + 0x108 ]
a00c2b88:  d0 2b e0 05  stb  %o0, [ %o7 + 5 ]
a00c2b8c:  e0 2b e0 01  stb  %l0, [ %o7 + 1 ]
a00c2b90:  f0 2b e0 03  stb  %i0, [ %o7 + 3 ]
a00c2b94:  d6 2b e0 04  stb  %o3, [ %o7 + 4 ]
a00c2b98:  f0 2b e0 02  stb  %i0, [ %o7 + 2 ]
a00c2b9c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00c2ba0:  9e 13 60 98  or  %o5, 0x98, %o7	! 0xa802d098
a00c2ba4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c2ba8:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00c2bac:  c0 2b 60 98  clrb  [ %o5 + 0x98 ]
a00c2bb0:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00c2bb4:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00c2bb8:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00c2bbc:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00c2bc0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00c2bc4:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00c2bc8:  10 bf ff d8  b  0xa00c2b28
a00c2bcc:  90 10 20 03  mov  3, %o0
a00c2bd0:  81 c7 e0 08  ret
a00c2bd4:  81 e8 00 00  restore
