# leon2m FUN_a00e9c80 0xa00e9c80-0xa00ea1f0 (452 bytes)
a00e9c80:  9d e3 bf 80  save  %sp, -128, %sp
a00e9c84:  90 10 20 09  mov  9, %o0
a00e9c88:  92 10 00 18  mov  %i0, %o1
a00e9c8c:  7f ff d8 ca  call  0xa00dffb4
a00e9c90:  94 10 00 1b  mov  %i3, %o2
a00e9c94:  90 10 00 18  mov  %i0, %o0
a00e9c98:  f2 27 a0 48  st  %i1, [ %fp + 0x48 ]
a00e9c9c:  92 10 00 19  mov  %i1, %o1
a00e9ca0:  f4 27 a0 4c  st  %i2, [ %fp + 0x4c ]
a00e9ca4:  7f ff d7 eb  call  0xa00dfc50
a00e9ca8:  94 10 00 1a  mov  %i2, %o2
a00e9cac:  82 07 3f ec  add  %i4, -20, %g1
a00e9cb0:  80 a0 60 3c  cmp  %g1, 0x3c
a00e9cb4:  18 80 01 3d  bgu  0xa00ea1a8
a00e9cb8:  fa 27 a0 58  st  %i5, [ %fp + 0x58 ]
a00e9cbc:  80 a6 ff ff  cmp  %i3, -1
a00e9cc0:  02 80 01 0d  be  0xa00ea0f4
a00e9cc4:  27 2a 00 ad  sethi  %hi(0xa802b400), %l3
a00e9cc8:  23 2a 00 98  sethi  %hi(0xa8026000), %l1
a00e9ccc:  1f 2a 00 98  sethi  %hi(0xa8026000), %o7
a00e9cd0:  99 2e e0 02  sll  %i3, 2, %o4
a00e9cd4:  a4 14 e2 68  or  %l3, 0x268, %l2
a00e9cd8:  a0 14 63 68  or  %l1, 0x368, %l0
a00e9cdc:  9a 13 e3 58  or  %o7, 0x358, %o5
a00e9ce0:  d6 04 80 0c  ld  [ %l2 + %o4 ], %o3
a00e9ce4:  d2 04 00 0c  ld  [ %l0 + %o4 ], %o1
a00e9ce8:  d4 03 40 0c  ld  [ %o5 + %o4 ], %o2
a00e9cec:  7f ff da 9a  call  0xa00e0754
a00e9cf0:  90 10 00 18  mov  %i0, %o0
a00e9cf4:  b4 5a 00 1c  smul  %o0, %i4, %i2
a00e9cf8:  33 14 7a e1  sethi  %hi(0x51eb8400), %i1
a00e9cfc:  ac 06 80 1a  add  %i2, %i2, %l6
a00e9d00:  ae 16 61 1f  or  %i1, 0x11f, %l7
a00e9d04:  80 55 80 17  umul  %l6, %l7, %g0
a00e9d08:  ab 40 00 00  rd  %y, %l5
a00e9d0c:  a9 35 60 05  srl  %l5, 5, %l4
a00e9d10:  80 a6 ff ff  cmp  %i3, -1
a00e9d14:  02 80 00 e7  be  0xa00ea0b0
a00e9d18:  e8 27 bf ec  st  %l4, [ %fp + -20 ]
a00e9d1c:  33 2a 00 9a  sethi  %hi(0xa8026800), %i1
a00e9d20:  2f 2a 00 9a  sethi  %hi(0xa8026800), %l7
a00e9d24:  2d 2a 00 ad  sethi  %hi(0xa802b400), %l6
a00e9d28:  a1 2e e0 02  sll  %i3, 2, %l0
a00e9d2c:  aa 16 60 38  or  %i1, 0x38, %l5
a00e9d30:  a8 15 e0 28  or  %l7, 0x28, %l4
a00e9d34:  a6 15 a3 08  or  %l6, 0x308, %l3
a00e9d38:  d2 05 40 10  ld  [ %l5 + %l0 ], %o1
a00e9d3c:  d4 05 00 10  ld  [ %l4 + %l0 ], %o2
a00e9d40:  d6 04 c0 10  ld  [ %l3 + %l0 ], %o3
a00e9d44:  7f ff da 84  call  0xa00e0754
a00e9d48:  90 10 00 18  mov  %i0, %o0
a00e9d4c:  1f 2a 00 ad  sethi  %hi(0xa802b400), %o7
a00e9d50:  92 13 e2 58  or  %o7, 0x258, %o1	! 0xa802b658
a00e9d54:  25 2a 00 98  sethi  %hi(0xa8026000), %l2
a00e9d58:  23 2a 00 98  sethi  %hi(0xa8026000), %l1
a00e9d5c:  aa 10 00 08  mov  %o0, %l5
a00e9d60:  9a 14 a3 48  or  %l2, 0x348, %o5
a00e9d64:  98 14 63 28  or  %l1, 0x328, %o4
a00e9d68:  d6 02 40 10  ld  [ %o1 + %l0 ], %o3
a00e9d6c:  d2 03 40 10  ld  [ %o5 + %l0 ], %o1
a00e9d70:  d4 03 00 10  ld  [ %o4 + %l0 ], %o2
a00e9d74:  90 10 00 18  mov  %i0, %o0
a00e9d78:  7f ff da 77  call  0xa00e0754
a00e9d7c:  a8 10 20 04  mov  4, %l4
a00e9d80:  d6 07 a0 58  ld  [ %fp + 0x58 ], %o3
a00e9d84:  a0 10 00 08  mov  %o0, %l0
a00e9d88:  d6 23 a0 5c  st  %o3, [ %sp + 0x5c ]
a00e9d8c:  b4 07 bf f0  add  %fp, -16, %i2
a00e9d90:  90 10 00 18  mov  %i0, %o0
a00e9d94:  d4 07 a0 4c  ld  [ %fp + 0x4c ], %o2
a00e9d98:  96 10 00 10  mov  %l0, %o3
a00e9d9c:  f4 23 a0 40  st  %i2, [ %sp + 0x40 ]
a00e9da0:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00e9da4:  98 10 00 1b  mov  %i3, %o4
a00e9da8:  9a 10 00 15  mov  %l5, %o5
a00e9dac:  7f ff ff 62  call  0xa00e9b34
a00e9db0:  01 00 00 00  nop
a00e9db4:  00 00 00 08  unimp  0x8
a00e9db8:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a00e9dbc:  90 38 00 0a  xnor  %g0, %o2, %o0
a00e9dc0:  80 a0 00 08  cmp  %g0, %o0
a00e9dc4:  d6 07 bf f0  ld  [ %fp + -16 ], %o3
a00e9dc8:  ba 60 3f ff  subx  %g0, -1, %i5
a00e9dcc:  82 38 00 0b  xnor  %g0, %o3, %g1
a00e9dd0:  80 a0 00 01  cmp  %g0, %g1
a00e9dd4:  b8 60 3f ff  subx  %g0, -1, %i4
a00e9dd8:  80 8f 40 1c  btst  %i5, %i4
a00e9ddc:  12 80 00 fc  bne  0xa00ea1cc
a00e9de0:  a2 10 00 10  mov  %l0, %l1
a00e9de4:  ae 10 00 0a  mov  %o2, %l7
a00e9de8:  ac 10 00 0b  mov  %o3, %l6
a00e9dec:  b8 10 00 0a  mov  %o2, %i4
a00e9df0:  ba 10 00 0b  mov  %o3, %i5
a00e9df4:  b2 10 20 00  clr  %i1
a00e9df8:  80 a6 60 00  cmp  %i1, 0
a00e9dfc:  34 80 00 02  bg,a   0xa00e9e04
a00e9e00:  a8 10 20 01  mov  1, %l4
a00e9e04:  a6 10 20 00  clr  %l3
a00e9e08:  10 80 00 0c  b  0xa00e9e38
a00e9e0c:  a4 10 20 00  clr  %l2
a00e9e10:  80 a4 e0 00  cmp  %l3, 0
a00e9e14:  02 80 00 67  be  0xa00e9fb0
a00e9e18:  de 07 a0 58  ld  [ %fp + 0x58 ], %o7
a00e9e1c:  80 a0 00 12  cmp  %g0, %l2
a00e9e20:  9a 60 3f ff  subx  %g0, -1, %o5
a00e9e24:  80 a0 00 13  cmp  %g0, %l3
a00e9e28:  94 60 3f ff  subx  %g0, -1, %o2
a00e9e2c:  80 93 40 0a  orcc  %o5, %o2, %g0
a00e9e30:  22 80 00 27  be,a   0xa00e9ecc
a00e9e34:  b2 06 60 01  inc  %i1
a00e9e38:  80 a4 a0 00  cmp  %l2, 0
a00e9e3c:  12 bf ff f6  bne  0xa00e9e14
a00e9e40:  80 a4 e0 00  cmp  %l3, 0
a00e9e44:  d4 07 a0 58  ld  [ %fp + 0x58 ], %o2
a00e9e48:  d4 23 a0 5c  st  %o2, [ %sp + 0x5c ]
a00e9e4c:  a0 04 00 14  add  %l0, %l4, %l0
a00e9e50:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00e9e54:  d4 07 a0 4c  ld  [ %fp + 0x4c ], %o2
a00e9e58:  96 10 00 10  mov  %l0, %o3
a00e9e5c:  98 10 00 1b  mov  %i3, %o4
a00e9e60:  9a 10 00 15  mov  %l5, %o5
a00e9e64:  f4 23 a0 40  st  %i2, [ %sp + 0x40 ]
a00e9e68:  90 10 00 18  mov  %i0, %o0
a00e9e6c:  7f ff ff 32  call  0xa00e9b34
a00e9e70:  01 00 00 00  nop
a00e9e74:  00 00 00 08  unimp  0x8
a00e9e78:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a00e9e7c:  9e 38 00 0a  xnor  %g0, %o2, %o7
a00e9e80:  80 a0 00 0f  cmp  %g0, %o7
a00e9e84:  d6 07 bf f0  ld  [ %fp + -16 ], %o3
a00e9e88:  98 60 3f ff  subx  %g0, -1, %o4
a00e9e8c:  92 38 00 0b  xnor  %g0, %o3, %o1
a00e9e90:  80 a0 00 09  cmp  %g0, %o1
a00e9e94:  9a 60 3f ff  subx  %g0, -1, %o5
a00e9e98:  80 8b 00 0d  btst  %o4, %o5
a00e9e9c:  02 80 00 71  be  0xa00ea060
a00e9ea0:  80 a7 40 0b  cmp  %i5, %o3
a00e9ea4:  a0 24 00 14  sub  %l0, %l4, %l0
a00e9ea8:  a4 10 20 01  mov  1, %l2
a00e9eac:  80 a0 00 12  cmp  %g0, %l2
a00e9eb0:  9a 60 3f ff  subx  %g0, -1, %o5
a00e9eb4:  80 a0 00 13  cmp  %g0, %l3
a00e9eb8:  94 60 3f ff  subx  %g0, -1, %o2
a00e9ebc:  80 93 40 0a  orcc  %o5, %o2, %g0
a00e9ec0:  12 bf ff df  bne  0xa00e9e3c
a00e9ec4:  80 a4 a0 00  cmp  %l2, 0
a00e9ec8:  b2 06 60 01  inc  %i1
a00e9ecc:  80 a6 60 01  cmp  %i1, 1
a00e9ed0:  04 bf ff cb  ble  0xa00e9dfc
a00e9ed4:  80 a6 60 00  cmp  %i1, 0
a00e9ed8:  80 a6 ff ff  cmp  %i3, -1
a00e9edc:  02 80 00 8d  be  0xa00ea110
a00e9ee0:  33 2a 00 98  sethi  %hi(0xa8026000), %i1
a00e9ee4:  a0 04 40 10  add  %l1, %l0, %l0
a00e9ee8:  2b 2a 00 98  sethi  %hi(0xa8026000), %l5
a00e9eec:  29 2a 00 ad  sethi  %hi(0xa802b400), %l4
a00e9ef0:  b7 2e e0 02  sll  %i3, 2, %i3
a00e9ef4:  b5 3c 20 01  sra  %l0, 1, %i2
a00e9ef8:  a6 16 63 48  or  %i1, 0x348, %l3
a00e9efc:  a4 15 63 28  or  %l5, 0x328, %l2
a00e9f00:  a2 15 22 58  or  %l4, 0x258, %l1
a00e9f04:  d2 04 c0 1b  ld  [ %l3 + %i3 ], %o1
a00e9f08:  d4 04 80 1b  ld  [ %l2 + %i3 ], %o2
a00e9f0c:  d6 04 40 1b  ld  [ %l1 + %i3 ], %o3
a00e9f10:  90 10 00 18  mov  %i0, %o0
a00e9f14:  7f ff da 18  call  0xa00e0774
a00e9f18:  98 10 00 1a  mov  %i2, %o4
a00e9f1c:  13 2a 00 98  sethi  %hi(0xa8026000), %o1
a00e9f20:  15 2a 00 98  sethi  %hi(0xa8026000), %o2
a00e9f24:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00e9f28:  82 12 a3 18  or  %o2, 0x318, %g1
a00e9f2c:  9e 12 22 48  or  %o0, 0x248, %o7
a00e9f30:  9a 12 63 38  or  %o1, 0x338, %o5
a00e9f34:  d4 00 40 1b  ld  [ %g1 + %i3 ], %o2
a00e9f38:  d2 03 40 1b  ld  [ %o5 + %i3 ], %o1
a00e9f3c:  d6 03 c0 1b  ld  [ %o7 + %i3 ], %o3
a00e9f40:  98 10 00 1a  mov  %i2, %o4
a00e9f44:  7f ff da 0c  call  0xa00e0774
a00e9f48:  90 10 00 18  mov  %i0, %o0
a00e9f4c:  82 10 00 1d  mov  %i5, %g1
a00e9f50:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00e9f54:  92 12 e0 38  or  %o3, 0x38, %o1	! 0xa8026838
a00e9f58:  19 2a 00 9a  sethi  %hi(0xa8026800), %o4
a00e9f5c:  3b 2a 00 ad  sethi  %hi(0xa802b400), %i5
a00e9f60:  94 13 20 28  or  %o4, 0x28, %o2
a00e9f64:  80 a0 40 16  cmp  %g1, %l6
a00e9f68:  04 80 00 03  ble  0xa00e9f74
a00e9f6c:  96 17 63 08  or  %i5, 0x308, %o3
a00e9f70:  82 10 00 16  mov  %l6, %g1
a00e9f74:  80 a7 00 17  cmp  %i4, %l7
a00e9f78:  16 80 00 03  bge  0xa00e9f84
a00e9f7c:  98 10 00 1c  mov  %i4, %o4
a00e9f80:  98 10 00 17  mov  %l7, %o4
a00e9f84:  ac 00 40 0c  add  %g1, %o4, %l6
a00e9f88:  af 35 a0 1f  srl  %l6, 0x1f, %l7
a00e9f8c:  98 05 80 17  add  %l6, %l7, %o4
a00e9f90:  d6 02 c0 1b  ld  [ %o3 + %i3 ], %o3
a00e9f94:  90 10 00 18  mov  %i0, %o0
a00e9f98:  d2 02 40 1b  ld  [ %o1 + %i3 ], %o1
a00e9f9c:  d4 02 80 1b  ld  [ %o2 + %i3 ], %o2
a00e9fa0:  7f ff d9 f5  call  0xa00e0774
a00e9fa4:  99 3b 20 01  sra  %o4, 1, %o4
a00e9fa8:  10 80 00 90  b  0xa00ea1e8
a00e9fac:  b0 10 20 00  clr  %i0
a00e9fb0:  a2 24 40 14  sub  %l1, %l4, %l1
a00e9fb4:  d2 07 a0 48  ld  [ %fp + 0x48 ], %o1
a00e9fb8:  d4 07 a0 4c  ld  [ %fp + 0x4c ], %o2
a00e9fbc:  96 10 00 11  mov  %l1, %o3
a00e9fc0:  98 10 00 1b  mov  %i3, %o4
a00e9fc4:  9a 10 00 15  mov  %l5, %o5
a00e9fc8:  de 23 a0 5c  st  %o7, [ %sp + 0x5c ]
a00e9fcc:  f4 23 a0 40  st  %i2, [ %sp + 0x40 ]
a00e9fd0:  90 10 00 18  mov  %i0, %o0
a00e9fd4:  7f ff fe d8  call  0xa00e9b34
a00e9fd8:  01 00 00 00  nop
a00e9fdc:  00 00 00 08  unimp  0x8
a00e9fe0:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a00e9fe4:  96 38 00 0a  xnor  %g0, %o2, %o3
a00e9fe8:  80 a0 00 0b  cmp  %g0, %o3
a00e9fec:  d6 07 bf f0  ld  [ %fp + -16 ], %o3
a00e9ff0:  98 60 3f ff  subx  %g0, -1, %o4
a00e9ff4:  92 38 00 0b  xnor  %g0, %o3, %o1
a00e9ff8:  80 a0 00 09  cmp  %g0, %o1
a00e9ffc:  9a 60 3f ff  subx  %g0, -1, %o5
a00ea000:  80 8b 00 0d  btst  %o4, %o5
a00ea004:  02 80 00 05  be  0xa00ea018
a00ea008:  80 a2 c0 16  cmp  %o3, %l6
a00ea00c:  a2 04 40 14  add  %l1, %l4, %l1
a00ea010:  10 bf ff 83  b  0xa00e9e1c
a00ea014:  a6 10 20 01  mov  1, %l3
a00ea018:  04 80 00 03  ble  0xa00ea024
a00ea01c:  9a 10 00 0b  mov  %o3, %o5
a00ea020:  9a 10 00 16  mov  %l6, %o5
a00ea024:  80 a2 80 17  cmp  %o2, %l7
a00ea028:  16 80 00 03  bge  0xa00ea034
a00ea02c:  82 10 00 0a  mov  %o2, %g1
a00ea030:  82 10 00 17  mov  %l7, %g1
a00ea034:  82 23 40 01  sub  %o5, %g1, %g1
a00ea038:  d0 07 bf ec  ld  [ %fp + -20 ], %o0
a00ea03c:  80 a0 40 08  cmp  %g1, %o0
a00ea040:  2a bf ff f4  bcs,a   0xa00ea010
a00ea044:  a2 04 40 14  add  %l1, %l4, %l1
a00ea048:  b8 10 00 0a  mov  %o2, %i4
a00ea04c:  80 a4 60 04  cmp  %l1, 4
a00ea050:  14 bf ff 73  bg  0xa00e9e1c
a00ea054:  ba 10 00 0b  mov  %o3, %i5
a00ea058:  10 bf ff 71  b  0xa00e9e1c
a00ea05c:  a6 10 20 01  mov  1, %l3
a00ea060:  04 80 00 03  ble  0xa00ea06c
a00ea064:  9a 10 00 1d  mov  %i5, %o5
a00ea068:  9a 10 00 0b  mov  %o3, %o5
a00ea06c:  80 a7 00 0a  cmp  %i4, %o2
a00ea070:  16 80 00 03  bge  0xa00ea07c
a00ea074:  82 10 00 1c  mov  %i4, %g1
a00ea078:  82 10 00 0a  mov  %o2, %g1
a00ea07c:  82 23 40 01  sub  %o5, %g1, %g1
a00ea080:  d0 07 bf ec  ld  [ %fp + -20 ], %o0
a00ea084:  80 a0 40 08  cmp  %g1, %o0
a00ea088:  2a 80 00 08  bcs,a   0xa00ea0a8
a00ea08c:  a0 24 00 14  sub  %l0, %l4, %l0
a00ea090:  ae 10 00 0a  mov  %o2, %l7
a00ea094:  80 a4 20 4b  cmp  %l0, 0x4b
a00ea098:  04 bf ff 5e  ble  0xa00e9e10
a00ea09c:  ac 10 00 0b  mov  %o3, %l6
a00ea0a0:  10 bf ff 83  b  0xa00e9eac
a00ea0a4:  a4 10 20 01  mov  1, %l2
a00ea0a8:  10 bf ff 5a  b  0xa00e9e10
a00ea0ac:  a4 10 20 01  mov  1, %l2
a00ea0b0:  15 2a 00 9a  sethi  %hi(0xa8026800), %o2
a00ea0b4:  92 12 a0 38  or  %o2, 0x38, %o1	! 0xa8026838
a00ea0b8:  17 2a 00 9a  sethi  %hi(0xa8026800), %o3
a00ea0bc:  94 12 e0 28  or  %o3, 0x28, %o2	! 0xa8026828
a00ea0c0:  11 2a 00 ad  sethi  %hi(0xa802b400), %o0
a00ea0c4:  96 12 23 08  or  %o0, 0x308, %o3	! 0xa802b708
a00ea0c8:  7f ff d9 a3  call  0xa00e0754
a00ea0cc:  90 10 00 18  mov  %i0, %o0
a00ea0d0:  aa 10 00 08  mov  %o0, %l5
a00ea0d4:  03 2a 00 98  sethi  %hi(0xa8026000), %g1
a00ea0d8:  3b 2a 00 98  sethi  %hi(0xa8026000), %i5
a00ea0dc:  39 2a 00 ad  sethi  %hi(0xa802b400), %i4
a00ea0e0:  90 10 00 18  mov  %i0, %o0
a00ea0e4:  92 10 63 48  or  %g1, 0x348, %o1
a00ea0e8:  94 17 63 28  or  %i5, 0x328, %o2
a00ea0ec:  10 bf ff 23  b  0xa00e9d78
a00ea0f0:  96 17 22 58  or  %i4, 0x258, %o3
a00ea0f4:  13 2a 00 98  sethi  %hi(0xa8026000), %o1
a00ea0f8:  15 2a 00 98  sethi  %hi(0xa8026000), %o2
a00ea0fc:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00ea100:  92 12 63 68  or  %o1, 0x368, %o1
a00ea104:  94 12 a3 58  or  %o2, 0x358, %o2
a00ea108:  10 bf fe f9  b  0xa00e9cec
a00ea10c:  96 12 e2 68  or  %o3, 0x268, %o3
a00ea110:  b6 04 40 10  add  %l1, %l0, %i3
a00ea114:  2b 2a 00 98  sethi  %hi(0xa8026000), %l5
a00ea118:  29 2a 00 98  sethi  %hi(0xa8026000), %l4
a00ea11c:  27 2a 00 ad  sethi  %hi(0xa802b400), %l3
a00ea120:  92 15 63 48  or  %l5, 0x348, %o1
a00ea124:  94 15 23 28  or  %l4, 0x328, %o2
a00ea128:  96 14 e2 58  or  %l3, 0x258, %o3
a00ea12c:  90 10 00 18  mov  %i0, %o0
a00ea130:  7f ff d9 91  call  0xa00e0774
a00ea134:  99 3e e0 01  sra  %i3, 1, %o4
a00ea138:  25 2a 00 98  sethi  %hi(0xa8026000), %l2
a00ea13c:  23 2a 00 98  sethi  %hi(0xa8026000), %l1
a00ea140:  35 2a 00 ad  sethi  %hi(0xa802b400), %i2
a00ea144:  90 10 00 18  mov  %i0, %o0
a00ea148:  92 14 a3 38  or  %l2, 0x338, %o1
a00ea14c:  94 14 63 18  or  %l1, 0x318, %o2
a00ea150:  96 16 a2 48  or  %i2, 0x248, %o3
a00ea154:  7f ff d9 88  call  0xa00e0774
a00ea158:  99 3e e0 01  sra  %i3, 1, %o4
a00ea15c:  80 a7 40 16  cmp  %i5, %l6
a00ea160:  04 80 00 03  ble  0xa00ea16c
a00ea164:  82 10 00 1d  mov  %i5, %g1
a00ea168:  82 10 00 16  mov  %l6, %g1
a00ea16c:  80 a7 00 17  cmp  %i4, %l7
a00ea170:  16 80 00 03  bge  0xa00ea17c
a00ea174:  98 10 00 1c  mov  %i4, %o4
a00ea178:  98 10 00 17  mov  %l7, %o4
a00ea17c:  b2 00 40 0c  add  %g1, %o4, %i1
a00ea180:  b9 36 60 1f  srl  %i1, 0x1f, %i4
a00ea184:  2f 2a 00 9a  sethi  %hi(0xa8026800), %l7
a00ea188:  2d 2a 00 9a  sethi  %hi(0xa8026800), %l6
a00ea18c:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00ea190:  98 06 40 1c  add  %i1, %i4, %o4
a00ea194:  90 10 00 18  mov  %i0, %o0
a00ea198:  92 15 e0 38  or  %l7, 0x38, %o1
a00ea19c:  94 15 a0 28  or  %l6, 0x28, %o2
a00ea1a0:  10 bf ff 80  b  0xa00e9fa0
a00ea1a4:  96 14 23 08  or  %l0, 0x308, %o3
a00ea1a8:  7f ff d5 99  call  0xa00df80c
a00ea1ac:  b0 10 3f ff  mov  -1, %i0
a00ea1b0:  7f ff da 84  call  0xa00e0bc0
a00ea1b4:  01 00 00 00  nop
a00ea1b8:  11 00 06 67  sethi  %hi(0x199c00), %o0
a00ea1bc:  90 12 21 20  or  %o0, 0x120, %o0	! 0x199d20
a00ea1c0:  7f ff d3 ec  call  0xa00df170
a00ea1c4:  92 10 00 1c  mov  %i4, %o1
a00ea1c8:  30 80 00 08  b,a   0xa00ea1e8
a00ea1cc:  7f ff d5 90  call  0xa00df80c
a00ea1d0:  31 00 06 67  sethi  %hi(0x199c00), %i0
a00ea1d4:  7f ff da 7b  call  0xa00e0bc0
a00ea1d8:  01 00 00 00  nop
a00ea1dc:  7f ff d3 e5  call  0xa00df170
a00ea1e0:  90 16 21 50  or  %i0, 0x150, %o0
a00ea1e4:  b0 10 3f ff  mov  -1, %i0
a00ea1e8:  81 c7 e0 08  ret
a00ea1ec:  81 e8 00 00  restore
