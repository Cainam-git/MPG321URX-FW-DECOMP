# leon2m FUN_a0080af0 0xa0080af0-0xa0080bc0 (208 bytes)
a0080af0:  9d e3 bf 98  save  %sp, -104, %sp
a0080af4:  11 00 03 fb  sethi  %hi(0xfec00), %o0
a0080af8:  40 01 79 9e  call  0xa00df170
a0080afc:  90 12 21 a0  or  %o0, 0x1a0, %o0	! 0xfeda0
a0080b00:  80 8e 20 ff  btst  0xff, %i0
a0080b04:  02 80 00 04  be  0xa0080b14
a0080b08:  01 00 00 00  nop
a0080b0c:  40 01 61 3c  call  0xa00d8ffc
a0080b10:  81 e8 00 00  restore
a0080b14:  40 01 66 69  call  0xa00da4b8
a0080b18:  01 00 00 00  nop
a0080b1c:  40 01 5c 8b  call  0xa00d7d48
a0080b20:  01 00 00 00  nop
a0080b24:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0080b28:  d4 08 63 40  ldub  [ %g1 + 0x340 ], %o2	! 0xa802af40
a0080b2c:  80 a2 20 00  cmp  %o0, 0
a0080b30:  12 80 00 0f  bne  0xa0080b6c
a0080b34:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a0080b38:  98 12 62 90  or  %o1, 0x290, %o4	! 0xa802d290
a0080b3c:  d2 0b 21 b4  ldub  [ %o4 + 0x1b4 ], %o1
a0080b40:  80 a2 40 0a  cmp  %o1, %o2
a0080b44:  02 bf ff f2  be  0xa0080b0c
a0080b48:  01 00 00 00  nop
a0080b4c:  d4 03 20 a8  ld  [ %o4 + 0xa8 ], %o2
a0080b50:  80 8a a8 00  btst  0x800, %o2
a0080b54:  12 80 00 16  bne  0xa0080bac
a0080b58:  01 00 00 00  nop
a0080b5c:  40 01 6c 65  call  0xa00dbcf0
a0080b60:  01 00 00 00  nop
a0080b64:  40 01 61 26  call  0xa00d8ffc
a0080b68:  81 e8 00 00  restore
a0080b6c:  17 2a 00 b3  sethi  %hi(0xa802cc00), %o3
a0080b70:  da 12 e3 fe  lduh  [ %o3 + 0x3fe ], %o5	! 0xa802cffe
a0080b74:  80 8b 60 80  btst  0x80, %o5
a0080b78:  12 bf ff f1  bne  0xa0080b3c
a0080b7c:  98 12 62 90  or  %o1, 0x290, %o4
a0080b80:  d6 03 20 a8  ld  [ %o4 + 0xa8 ], %o3
a0080b84:  9f 2a e0 03  sll  %o3, 3, %o7
a0080b88:  82 0b e8 00  and  %o7, 0x800, %g1
a0080b8c:  9a 0a f7 ff  and  %o3, -2049, %o5
a0080b90:  b0 13 40 01  or  %o5, %g1, %i0
a0080b94:  de 0b 21 88  ldub  [ %o4 + 0x188 ], %o7
a0080b98:  d0 0b 21 87  ldub  [ %o4 + 0x187 ], %o0
a0080b9c:  d0 2b 21 81  stb  %o0, [ %o4 + 0x181 ]
a0080ba0:  f0 23 20 a8  st  %i0, [ %o4 + 0xa8 ]
a0080ba4:  10 bf ff e6  b  0xa0080b3c
a0080ba8:  de 2b 21 82  stb  %o7, [ %o4 + 0x182 ]
a0080bac:  40 01 6a e3  call  0xa00db738
a0080bb0:  01 00 00 00  nop
a0080bb4:  40 01 61 12  call  0xa00d8ffc
a0080bb8:  81 e8 00 00  restore
a0080bbc:  01 00 00 00  nop
