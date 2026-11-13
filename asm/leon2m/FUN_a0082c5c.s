# leon2m FUN_a0082c5c 0xa0082c5c-0xa0082dc4 (360 bytes)
a0082c5c:  9d e3 bf 98  save  %sp, -104, %sp
a0082c60:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a0082c64:  96 14 e2 90  or  %l3, 0x290, %o3	! 0xa802d290
a0082c68:  da 0a e0 39  ldub  [ %o3 + 0x39 ], %o5
a0082c6c:  e4 0a e0 37  ldub  [ %o3 + 0x37 ], %l2
a0082c70:  92 03 7f ff  add  %o5, -1, %o1
a0082c74:  9b 3a 60 1f  sra  %o1, 0x1f, %o5
a0082c78:  81 83 60 00  mov  %o5, %y
a0082c7c:  01 00 00 00  nop
a0082c80:  01 00 00 00  nop
a0082c84:  01 00 00 00  nop
a0082c88:  90 7a 40 12  sdiv  %o1, %l2, %o0
a0082c8c:  9e 5a 00 12  smul  %o0, %l2, %o7
a0082c90:  98 22 40 0f  sub  %o1, %o7, %o4
a0082c94:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0082c98:  a0 03 20 01  add  %o4, 1, %l0
a0082c9c:  92 10 20 07  mov  7, %o1
a0082ca0:  40 03 0a 70  call  0xa0145660
a0082ca4:  90 10 00 18  mov  %i0, %o0
a0082ca8:  a8 10 00 08  mov  %o0, %l4
a0082cac:  90 10 00 18  mov  %i0, %o0
a0082cb0:  40 03 0a 6c  call  0xa0145660
a0082cb4:  92 10 20 0b  mov  0xb, %o1
a0082cb8:  a0 0c 20 ff  and  %l0, 0xff, %l0
a0082cbc:  03 00 03 fb  sethi  %hi(0xfec00), %g1
a0082cc0:  b0 10 00 08  mov  %o0, %i0
a0082cc4:  90 10 62 80  or  %g1, 0x280, %o0
a0082cc8:  92 10 00 12  mov  %l2, %o1
a0082ccc:  94 10 00 10  mov  %l0, %o2
a0082cd0:  40 01 71 28  call  0xa00df170
a0082cd4:  a3 2d 20 10  sll  %l4, 0x10, %l1
a0082cd8:  a3 34 60 10  srl  %l1, 0x10, %l1
a0082cdc:  83 3c 60 1f  sra  %l1, 0x1f, %g1
a0082ce0:  81 80 60 00  mov  %g1, %y
a0082ce4:  01 00 00 00  nop
a0082ce8:  01 00 00 00  nop
a0082cec:  01 00 00 00  nop
a0082cf0:  94 7c 40 12  sdiv  %l1, %l2, %o2
a0082cf4:  95 32 a0 01  srl  %o2, 1, %o2
a0082cf8:  a6 02 80 0a  add  %o2, %o2, %l3
a0082cfc:  96 5c c0 12  smul  %l3, %l2, %o3
a0082d00:  9e 24 40 0b  sub  %l1, %o3, %o7
a0082d04:  99 3b e0 1f  sra  %o7, 0x1f, %o4
a0082d08:  92 1b 00 0f  xor  %o4, %o7, %o1
a0082d0c:  98 22 40 0c  sub  %o1, %o4, %o4
a0082d10:  9b 2e 20 10  sll  %i0, 0x10, %o5
a0082d14:  92 0b 20 ff  and  %o4, 0xff, %o1
a0082d18:  a7 33 60 10  srl  %o5, 0x10, %l3
a0082d1c:  11 00 03 fb  sethi  %hi(0xfec00), %o0
a0082d20:  94 02 80 0a  add  %o2, %o2, %o2
a0082d24:  83 32 60 01  srl  %o1, 1, %g1
a0082d28:  a8 04 3f ff  add  %l0, -1, %l4
a0082d2c:  96 10 00 10  mov  %l0, %o3
a0082d30:  90 12 22 a0  or  %o0, 0x2a0, %o0
a0082d34:  9a 10 00 13  mov  %l3, %o5
a0082d38:  9e 04 00 10  add  %l0, %l0, %o7
a0082d3c:  80 a4 00 01  cmp  %l0, %g1
a0082d40:  18 80 00 05  bgu  0xa0082d54
a0082d44:  a4 10 00 0a  mov  %o2, %l2
a0082d48:  98 03 ff fe  add  %o7, -2, %o4
a0082d4c:  a4 02 a0 02  add  %o2, 2, %l2
a0082d50:  92 0b 20 ff  and  %o4, 0xff, %o1
a0082d54:  95 2c a0 10  sll  %l2, 0x10, %o2
a0082d58:  95 32 a0 10  srl  %o2, 0x10, %o2
a0082d5c:  82 5a 80 14  smul  %o2, %l4, %g1
a0082d60:  98 0b 20 ff  and  %o4, 0xff, %o4
a0082d64:  a8 00 40 0c  add  %g1, %o4, %l4
a0082d68:  b0 05 00 18  add  %l4, %i0, %i0
a0082d6c:  9f 2e 20 10  sll  %i0, 0x10, %o7
a0082d70:  a1 33 e0 10  srl  %o7, 0x10, %l0
a0082d74:  98 10 00 09  mov  %o1, %o4
a0082d78:  40 01 70 fe  call  0xa00df170
a0082d7c:  92 10 00 10  mov  %l0, %o1
a0082d80:  99 2c a0 10  sll  %l2, 0x10, %o4
a0082d84:  a8 24 00 13  sub  %l0, %l3, %l4
a0082d88:  83 33 20 10  srl  %o4, 0x10, %g1
a0082d8c:  13 00 06 9b  sethi  %hi(0x1a6c00), %o1
a0082d90:  94 05 00 01  add  %l4, %g1, %o2
a0082d94:  90 12 63 08  or  %o1, 0x308, %o0
a0082d98:  80 a2 80 11  cmp  %o2, %l1
a0082d9c:  04 80 00 03  ble  0xa0082da8
a0082da0:  a0 10 00 18  mov  %i0, %l0
a0082da4:  a0 06 3f ff  add  %i0, -1, %l0
a0082da8:  a3 2c 20 10  sll  %l0, 0x10, %l1
a0082dac:  40 01 70 f1  call  0xa00df170
a0082db0:  93 34 60 10  srl  %l1, 0x10, %o1
a0082db4:  e4 36 40 00  sth  %l2, [ %i1 ]
a0082db8:  e0 36 80 00  sth  %l0, [ %i2 ]
a0082dbc:  81 c7 e0 08  ret
a0082dc0:  81 e8 00 00  restore
