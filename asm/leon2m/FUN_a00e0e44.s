# leon2m FUN_a00e0e44 0xa00e0e44-0xa00e108c (116 bytes)
a00e0e44:  9d e3 bf 70  save  %sp, -144, %sp
a00e0e48:  39 2a 00 b5  sethi  %hi(0xa802d400), %i4
a00e0e4c:  c2 07 22 58  ld  [ %i4 + 0x258 ], %g1	! 0xa802d658
a00e0e50:  80 a6 00 01  cmp  %i0, %g1
a00e0e54:  1a 80 00 8c  bcc  0xa00e1084
a00e0e58:  37 2a 00 b5  sethi  %hi(0xa802d400), %i3
a00e0e5c:  35 00 02 03  sethi  %hi(0x80c00), %i2
a00e0e60:  d0 06 e2 54  ld  [ %i3 + 0x254 ], %o0
a00e0e64:  c2 0a 00 18  ldub  [ %o0 + %i0 ], %g1
a00e0e68:  80 a0 60 3d  cmp  %g1, 0x3d
a00e0e6c:  18 80 00 20  bgu  0xa00e0eec
a00e0e70:  96 10 20 00  clr  %o3
a00e0e74:  93 28 60 02  sll  %g1, 2, %o1
a00e0e78:  9a 16 a1 30  or  %i2, 0x130, %o5
a00e0e7c:  d8 03 40 09  ld  [ %o5 + %o1 ], %o4
a00e0e80:  81 c3 00 00  jmp  %o4
a00e0e84:  01 00 00 00  nop
a00e0e88:  91 3b e0 18  sra  %o7, 0x18, %o0
a00e0e8c:  7f ff f9 92  call  0xa00df4d4
a00e0e90:  01 00 00 00  nop
a00e0e94:  b0 06 20 01  inc  %i0
a00e0e98:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e0e9c:  d0 0e 00 0a  ldub  [ %i0 + %o2 ], %o0
a00e0ea0:  80 a2 20 00  cmp  %o0, 0
a00e0ea4:  12 bf ff f9  bne  0xa00e0e88
a00e0ea8:  9f 2a 20 18  sll  %o0, 0x18, %o7
a00e0eac:  13 00 03 fb  sethi  %hi(0xfec00), %o1
a00e0eb0:  7f ff f8 b0  call  0xa00df170
a00e0eb4:  90 12 63 90  or  %o1, 0x390, %o0	! 0xfef90
a00e0eb8:  10 80 00 08  b  0xa00e0ed8
a00e0ebc:  b0 06 20 01  inc  %i0
a00e0ec0:  e6 06 e2 54  ld  [ %i3 + 0x254 ], %l3
a00e0ec4:  17 00 06 65  sethi  %hi(0x199400), %o3
a00e0ec8:  90 12 e2 58  or  %o3, 0x258, %o0	! 0x199658
a00e0ecc:  7f ff f8 a9  call  0xa00df170
a00e0ed0:  d2 0c c0 18  ldub  [ %l3 + %i0 ], %o1
a00e0ed4:  b0 06 20 01  inc  %i0
a00e0ed8:  e6 07 22 58  ld  [ %i4 + 0x258 ], %l3
a00e0edc:  80 a6 00 13  cmp  %i0, %l3
a00e0ee0:  0a bf ff e1  bcs  0xa00e0e64
a00e0ee4:  d0 06 e2 54  ld  [ %i3 + 0x254 ], %o0
a00e0ee8:  30 80 00 67  b,a   0xa00e1084
a00e0eec:  21 00 06 65  sethi  %hi(0x199400), %l0
a00e0ef0:  7f ff f9 58  call  0xa00df450
a00e0ef4:  90 14 22 78  or  %l0, 0x278, %o0	! 0x199678
a00e0ef8:  10 bf ff f8  b  0xa00e0ed8
a00e0efc:  b0 06 20 01  inc  %i0
a00e0f00:  92 07 bf f8  add  %fp, -8, %o1
a00e0f04:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e0f08:  98 10 20 03  mov  3, %o4
a00e0f0c:  90 0a e0 ff  and  %o3, 0xff, %o0
a00e0f10:  b0 06 20 01  inc  %i0
a00e0f14:  a8 02 40 08  add  %o1, %o0, %l4
a00e0f18:  fa 0a 80 18  ldub  [ %o2 + %i0 ], %i5
a00e0f1c:  fa 2d 3f f0  stb  %i5, [ %l4 + -16 ]
a00e0f20:  98 83 3f ff  addcc  %o4, -1, %o4
a00e0f24:  1c bf ff fa  bpos  0xa00e0f0c
a00e0f28:  96 02 e0 01  inc  %o3
a00e0f2c:  c2 0f bf e8  ldub  [ %fp + -24 ], %g1
a00e0f30:  80 a0 60 ff  cmp  %g1, 0xff
a00e0f34:  e4 0f bf e9  ldub  [ %fp + -23 ], %l2
a00e0f38:  e6 0f bf ea  ldub  [ %fp + -22 ], %l3
a00e0f3c:  e8 0f bf eb  ldub  [ %fp + -21 ], %l4
a00e0f40:  02 80 00 03  be  0xa00e0f4c
a00e0f44:  9a 10 20 04  mov  4, %o5
a00e0f48:  9a 10 00 01  mov  %g1, %o5
a00e0f4c:  21 00 06 65  sethi  %hi(0x199400), %l0
a00e0f50:  82 14 22 2c  or  %l0, 0x22c, %g1	! 0x19962c
a00e0f54:  9b 2b 60 03  sll  %o5, 3, %o5
a00e0f58:  94 03 40 01  add  %o5, %g1, %o2
a00e0f5c:  e0 00 40 0d  ld  [ %g1 + %o5 ], %l0
a00e0f60:  e2 02 a0 04  ld  [ %o2 + 4 ], %l1
a00e0f64:  80 a4 00 11  cmp  %l0, %l1
a00e0f68:  14 bf ff db  bg  0xa00e0ed4
a00e0f6c:  90 10 00 10  mov  %l0, %o0
a00e0f70:  92 10 00 12  mov  %l2, %o1
a00e0f74:  94 10 00 13  mov  %l3, %o2
a00e0f78:  40 00 1b ce  call  0xa00e7eb0
a00e0f7c:  96 10 00 14  mov  %l4, %o3
a00e0f80:  10 bf ff f9  b  0xa00e0f64
a00e0f84:  a0 04 20 01  inc  %l0
a00e0f88:  92 07 bf f8  add  %fp, -8, %o1
a00e0f8c:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e0f90:  98 10 20 07  mov  7, %o4
a00e0f94:  ae 0a e0 ff  and  %o3, 0xff, %l7
a00e0f98:  b0 06 20 01  inc  %i0
a00e0f9c:  aa 02 40 17  add  %o1, %l7, %l5
a00e0fa0:  ec 0a 80 18  ldub  [ %o2 + %i0 ], %l6
a00e0fa4:  ec 2d 7f f0  stb  %l6, [ %l5 + -16 ]
a00e0fa8:  98 83 3f ff  addcc  %o4, -1, %o4
a00e0fac:  1c bf ff fa  bpos  0xa00e0f94
a00e0fb0:  96 02 e0 01  inc  %o3
a00e0fb4:  de 0f bf e9  ldub  [ %fp + -23 ], %o7
a00e0fb8:  91 2b e0 08  sll  %o7, 8, %o0
a00e0fbc:  d8 0f bf e8  ldub  [ %fp + -24 ], %o4
a00e0fc0:  fa 0f bf ea  ldub  [ %fp + -22 ], %i5
a00e0fc4:  92 12 00 1d  or  %o0, %i5, %o1
a00e0fc8:  80 a3 20 ff  cmp  %o4, 0xff
a00e0fcc:  e6 0f bf eb  ldub  [ %fp + -21 ], %l3
a00e0fd0:  e8 0f bf ec  ldub  [ %fp + -20 ], %l4
a00e0fd4:  ea 0f bf ed  ldub  [ %fp + -19 ], %l5
a00e0fd8:  ec 0f bf ee  ldub  [ %fp + -18 ], %l6
a00e0fdc:  ee 0f bf ef  ldub  [ %fp + -17 ], %l7
a00e0fe0:  02 80 00 03  be  0xa00e0fec
a00e0fe4:  9a 10 20 04  mov  4, %o5
a00e0fe8:  9a 10 00 0c  mov  %o4, %o5
a00e0fec:  21 00 06 65  sethi  %hi(0x199400), %l0
a00e0ff0:  a3 2b 60 03  sll  %o5, 3, %l1
a00e0ff4:  82 14 22 2c  or  %l0, 0x22c, %g1
a00e0ff8:  e0 00 40 11  ld  [ %g1 + %l1 ], %l0
a00e0ffc:  a4 04 40 01  add  %l1, %g1, %l2
a00e1000:  e2 04 a0 04  ld  [ %l2 + 4 ], %l1
a00e1004:  80 a4 00 11  cmp  %l0, %l1
a00e1008:  14 bf ff b3  bg  0xa00e0ed4
a00e100c:  a5 2a 60 10  sll  %o1, 0x10, %l2
a00e1010:  ba 10 20 01  mov  1, %i5
a00e1014:  90 10 00 10  mov  %l0, %o0
a00e1018:  ee 23 a0 5c  st  %l7, [ %sp + 0x5c ]
a00e101c:  fa 23 a0 60  st  %i5, [ %sp + 0x60 ]
a00e1020:  93 34 a0 10  srl  %l2, 0x10, %o1
a00e1024:  94 10 00 13  mov  %l3, %o2
a00e1028:  96 10 00 14  mov  %l4, %o3
a00e102c:  98 10 00 15  mov  %l5, %o4
a00e1030:  7f ff fc 41  call  0xa00e0134
a00e1034:  9a 10 00 16  mov  %l6, %o5
a00e1038:  a0 04 20 01  inc  %l0
a00e103c:  80 a4 00 11  cmp  %l0, %l1
a00e1040:  04 bf ff f6  ble  0xa00e1018
a00e1044:  90 10 00 10  mov  %l0, %o0
a00e1048:  10 bf ff a4  b  0xa00e0ed8
a00e104c:  b0 06 20 01  inc  %i0
a00e1050:  92 07 bf f8  add  %fp, -8, %o1
a00e1054:  d4 06 e2 54  ld  [ %i3 + 0x254 ], %o2
a00e1058:  98 10 20 01  mov  1, %o4
a00e105c:  ae 0a e0 ff  and  %o3, 0xff, %l7
a00e1060:  b0 06 20 01  inc  %i0
a00e1064:  aa 02 40 17  add  %o1, %l7, %l5
a00e1068:  e4 0a 80 18  ldub  [ %o2 + %i0 ], %l2
a00e106c:  e4 2d 7f f0  stb  %l2, [ %l5 + -16 ]
a00e1070:  98 83 3f ff  addcc  %o4, -1, %o4
a00e1074:  1c bf ff fa  bpos  0xa00e105c
a00e1078:  96 02 e0 01  inc  %o3
a00e107c:  10 bf ff 97  b  0xa00e0ed8
a00e1080:  b0 06 20 01  inc  %i0
a00e1084:  10 80 00 00  b  0xa00e1084
a00e1088:  01 00 00 00  nop
