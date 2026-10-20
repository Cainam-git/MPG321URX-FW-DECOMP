# leon2m FUN_a0080c10 0xa0080c10-0xa0081e0c (4212 bytes)
a0080c10:  9d e3 bf 98  save  %sp, -104, %sp
a0080c14:  35 2a 00 ab  sethi  %hi(0xa802ac00), %i2
a0080c18:  c2 0e a3 41  ldub  [ %i2 + 0x341 ], %g1	! 0xa802af41
a0080c1c:  80 88 60 01  btst  1, %g1
a0080c20:  b0 10 20 3f  mov  0x3f, %i0
a0080c24:  12 80 04 78  bne  0xa0081e04
a0080c28:  b2 10 20 00  clr  %i1
a0080c2c:  40 03 0c e3  call  0xa0143fb8
a0080c30:  01 00 00 00  nop
a0080c34:  80 8a 20 ff  btst  0xff, %o0
a0080c38:  12 80 00 9d  bne  0xa0080eac
a0080c3c:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a0080c40:  40 03 0c da  call  0xa0143fa8
a0080c44:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0080c48:  92 0a 20 ff  and  %o0, 0xff, %o1
a0080c4c:  c2 0c 23 49  ldub  [ %l0 + 0x349 ], %g1
a0080c50:  80 a2 40 01  cmp  %o1, %g1
a0080c54:  02 80 00 04  be  0xa0080c64
a0080c58:  80 a0 60 00  cmp  %g1, 0
a0080c5c:  02 80 04 35  be  0xa0081d30
a0080c60:  01 00 00 00  nop
a0080c64:  40 03 0c d1  call  0xa0143fa8
a0080c68:  ac 10 20 00  clr  %l6	! 0x0
a0080c6c:  d0 2c 23 49  stb  %o0, [ %l0 + 0x349 ]
a0080c70:  10 80 00 11  b  0xa0080cb4
a0080c74:  a4 10 20 00  clr  %l2
a0080c78:  80 a4 a0 01  cmp  %l2, 1
a0080c7c:  02 80 01 a0  be  0xa00812fc
a0080c80:  80 a4 a0 02  cmp  %l2, 2
a0080c84:  02 80 01 c8  be  0xa00813a4
a0080c88:  80 a4 a0 03  cmp  %l2, 3
a0080c8c:  02 80 01 dd  be  0xa0081400
a0080c90:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a0080c94:  80 8b 20 ff  btst  0xff, %o4
a0080c98:  12 80 00 0f  bne  0xa0080cd4
a0080c9c:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a0080ca0:  ac 05 a0 01  inc  %l6
a0080ca4:  a4 0d a0 ff  and  %l6, 0xff, %l2
a0080ca8:  80 a4 a0 03  cmp  %l2, 3
a0080cac:  38 80 01 b7  bgu,a   0xa0081388
a0080cb0:  f2 0e a3 41  ldub  [ %i2 + 0x341 ], %i1
a0080cb4:  80 a4 a0 00  cmp  %l2, 0
a0080cb8:  12 bf ff f0  bne  0xa0080c78
a0080cbc:  98 10 20 00  clr  %o4
a0080cc0:  98 10 20 01  mov  1, %o4
a0080cc4:  80 8b 20 ff  btst  0xff, %o4
a0080cc8:  22 bf ff f7  be,a   0xa0080ca4
a0080ccc:  ac 05 a0 01  inc  %l6
a0080cd0:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a0080cd4:  d8 0a 23 4a  ldub  [ %o0 + 0x34a ], %o4	! 0xa802af4a
a0080cd8:  80 a3 20 00  cmp  %o4, 0
a0080cdc:  12 80 00 14  bne  0xa0080d2c
a0080ce0:  3b 2a 00 ab  sethi  %hi(0xa802ac00), %i5
a0080ce4:  2b 2a 00 ab  sethi  %hi(0xa802ac00), %l5
a0080ce8:  82 15 63 60  or  %l5, 0x360, %g1	! 0xa802af60
a0080cec:  98 10 20 00  clr  %o4
a0080cf0:  9a 10 20 00  clr  %o5
a0080cf4:  92 17 63 50  or  %i5, 0x350, %o1
a0080cf8:  94 10 20 3f  mov  0x3f, %o2
a0080cfc:  96 10 3f ff  mov  -1, %o3
a0080d00:  d6 28 40 0d  stb  %o3, [ %g1 + %o5 ]
a0080d04:  d4 2a 40 0d  stb  %o2, [ %o1 + %o5 ]
a0080d08:  98 03 20 01  inc  %o4
a0080d0c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0080d10:  80 a3 60 03  cmp  %o5, 3
a0080d14:  28 bf ff fc  bleu,a   0xa0080d04
a0080d18:  d6 28 40 0d  stb  %o3, [ %g1 + %o5 ]
a0080d1c:  b6 10 20 01  mov  1, %i3
a0080d20:  2f 2a 00 ab  sethi  %hi(0xa802ac00), %l7
a0080d24:  f6 2a 23 4a  stb  %i3, [ %o0 + 0x34a ]
a0080d28:  c0 2d e3 64  clrb  [ %l7 + 0x364 ]
a0080d2c:  82 17 63 50  or  %i5, 0x350, %g1
a0080d30:  f8 08 40 12  ldub  [ %g1 + %l2 ], %i4
a0080d34:  80 a7 20 3f  cmp  %i4, 0x3f
a0080d38:  02 80 00 1c  be  0xa0080da8
a0080d3c:  80 a4 a0 02  cmp  %l2, 2
a0080d40:  02 80 00 09  be  0xa0080d64
a0080d44:  90 10 20 06  mov  6, %o0
a0080d48:  80 a4 a0 02  cmp  %l2, 2
a0080d4c:  14 80 01 79  bg  0xa0081330
a0080d50:  80 a4 a0 03  cmp  %l2, 3
a0080d54:  80 a4 a0 01  cmp  %l2, 1
a0080d58:  02 80 00 03  be  0xa0080d64
a0080d5c:  90 10 20 05  mov  5, %o0
a0080d60:  90 10 20 04  mov  4, %o0
a0080d64:  40 00 17 36  call  0xa0086a3c
a0080d68:  01 00 00 00  nop
a0080d6c:  91 2a 20 10  sll  %o0, 0x10, %o0
a0080d70:  80 a2 20 00  cmp  %o0, 0
a0080d74:  02 80 00 60  be  0xa0080ef4
a0080d78:  a8 17 63 50  or  %i5, 0x350, %l4
a0080d7c:  80 a4 a0 00  cmp  %l2, 0
a0080d80:  12 80 00 50  bne  0xa0080ec0
a0080d84:  80 a4 a0 01  cmp  %l2, 1
a0080d88:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0080d8c:  d2 0b 63 45  ldub  [ %o5 + 0x345 ], %o1	! 0xa802af45
a0080d90:  80 8a 60 01  btst  1, %o1
a0080d94:  02 80 00 53  be  0xa0080ee0
a0080d98:  82 10 20 01  mov  1, %g1
a0080d9c:  80 a0 60 00  cmp  %g1, 0
a0080da0:  32 80 00 55  bne,a   0xa0080ef4
a0080da4:  a8 17 63 50  or  %i5, 0x350, %l4
a0080da8:  40 03 0b 9b  call  0xa0143c14
a0080dac:  90 10 00 12  mov  %l2, %o0
a0080db0:  27 2a 00 b3  sethi  %hi(0xa802cc00), %l3
a0080db4:  82 14 e3 f4  or  %l3, 0x3f4, %g1	! 0xa802cff4
a0080db8:  f8 10 60 04  lduh  [ %g1 + 4 ], %i4
a0080dbc:  37 00 00 18  sethi  %hi(0x6000), %i3
a0080dc0:  aa 0e c0 1c  and  %i3, %i4, %l5
a0080dc4:  2f 00 00 08  sethi  %hi(0x2000), %l7
a0080dc8:  a8 1d 40 17  xor  %l5, %l7, %l4
a0080dcc:  80 a0 00 14  cmp  %g0, %l4
a0080dd0:  98 60 20 00  subx  %g0, 0, %o4
a0080dd4:  b6 0b 00 08  and  %o4, %o0, %i3
a0080dd8:  a0 0e e0 ff  and  %i3, 0xff, %l0
a0080ddc:  80 a4 20 04  cmp  %l0, 4
a0080de0:  a2 10 20 3f  mov  0x3f, %l1
a0080de4:  aa 10 20 00  clr  %l5
a0080de8:  39 2a 00 b4  sethi  %hi(0xa802d000), %i4
a0080dec:  02 80 02 94  be  0xa008183c
a0080df0:  29 2a 00 ab  sethi  %hi(0xa802ac00), %l4
a0080df4:  40 03 0c ce  call  0xa014412c
a0080df8:  01 00 00 00  nop
a0080dfc:  80 a0 00 12  cmp  %g0, %l2
a0080e00:  ee 07 22 90  ld  [ %i4 + 0x290 ], %l7
a0080e04:  99 35 e0 09  srl  %l7, 9, %o4
a0080e08:  9e 60 3f ff  subx  %g0, -1, %o7
a0080e0c:  80 8b 00 0f  btst  %o4, %o7
a0080e10:  02 80 01 f8  be  0xa00815f0
a0080e14:  80 8a 20 ff  btst  0xff, %o0
a0080e18:  12 80 00 03  bne  0xa0080e24
a0080e1c:  82 10 20 01  mov  1, %g1
a0080e20:  82 10 20 00  clr  %g1
a0080e24:  82 08 60 ff  and  %g1, 0xff, %g1
a0080e28:  80 a0 60 01  cmp  %g1, 1
a0080e2c:  02 80 01 f9  be  0xa0081610
a0080e30:  d2 0d 23 64  ldub  [ %l4 + 0x364 ], %o1
a0080e34:  90 10 20 01  mov  1, %o0
a0080e38:  da 0d 23 64  ldub  [ %l4 + 0x364 ], %o5
a0080e3c:  95 2a 00 12  sll  %o0, %l2, %o2
a0080e40:  82 2b 40 0a  andn  %o5, %o2, %g1
a0080e44:  c2 2d 23 64  stb  %g1, [ %l4 + 0x364 ]
a0080e48:  80 8d 60 ff  btst  0xff, %l5
a0080e4c:  12 80 01 f7  bne  0xa0081628
a0080e50:  29 2a 00 ab  sethi  %hi(0xa802ac00), %l4
a0080e54:  92 14 e3 f4  or  %l3, 0x3f4, %o1
a0080e58:  90 10 20 01  mov  1, %o0
a0080e5c:  da 0a 60 1c  ldub  [ %o1 + 0x1c ], %o5
a0080e60:  95 2a 00 12  sll  %o0, %l2, %o2
a0080e64:  98 15 23 60  or  %l4, 0x360, %o4
a0080e68:  82 2b 40 0a  andn  %o5, %o2, %g1
a0080e6c:  ee 0b 00 12  ldub  [ %o4 + %l2 ], %l7
a0080e70:  c2 2a 60 1c  stb  %g1, [ %o1 + 0x1c ]
a0080e74:  80 a5 c0 10  cmp  %l7, %l0
a0080e78:  02 80 00 81  be  0xa008107c
a0080e7c:  96 10 20 3f  mov  0x3f, %o3
a0080e80:  aa 17 63 50  or  %i5, 0x350, %l5
a0080e84:  96 10 20 3f  mov  0x3f, %o3
a0080e88:  80 a4 20 0a  cmp  %l0, 0xa
a0080e8c:  18 80 00 36  bgu  0xa0080f64
a0080e90:  d6 2d 40 12  stb  %o3, [ %l5 + %l2 ]
a0080e94:  13 00 00 80  sethi  %hi(0x20000), %o1
a0080e98:  9f 2c 20 02  sll  %l0, 2, %o7
a0080e9c:  ae 12 61 c0  or  %o1, 0x1c0, %l7
a0080ea0:  e0 05 c0 0f  ld  [ %l7 + %o7 ], %l0
a0080ea4:  81 c4 00 00  jmp  %l0
a0080ea8:  01 00 00 00  nop
a0080eac:  c0 2a 23 49  clrb  [ %o0 + 0x349 ]
a0080eb0:  40 03 0c 45  call  0xa0143fc4
a0080eb4:  90 10 20 00  clr  %o0
a0080eb8:  10 bf ff 6e  b  0xa0080c70
a0080ebc:  ac 10 20 00  clr  %l6
a0080ec0:  02 80 02 7c  be  0xa00818b0
a0080ec4:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0080ec8:  80 a4 a0 02  cmp  %l2, 2
a0080ecc:  02 80 02 a7  be  0xa0081968
a0080ed0:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0080ed4:  80 a4 a0 03  cmp  %l2, 3
a0080ed8:  02 80 02 ea  be  0xa0081a80
a0080edc:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a0080ee0:  82 10 20 00  clr  %g1
a0080ee4:  80 a0 60 00  cmp  %g1, 0
a0080ee8:  02 bf ff b0  be  0xa0080da8
a0080eec:  01 00 00 00  nop
a0080ef0:  a8 17 63 50  or  %i5, 0x350, %l4
a0080ef4:  d8 0d 00 12  ldub  [ %l4 + %l2 ], %o4
a0080ef8:  ba 10 20 3f  mov  0x3f, %i5
a0080efc:  80 a4 a0 00  cmp  %l2, 0
a0080f00:  12 80 01 0f  bne  0xa008133c
a0080f04:  fa 2d 00 12  stb  %i5, [ %l4 + %l2 ]
a0080f08:  2b 2a 00 ab  sethi  %hi(0xa802ac00), %l5
a0080f0c:  f6 0d 63 45  ldub  [ %l5 + 0x345 ], %i3	! 0xa802af45
a0080f10:  ae 0e ff fe  and  %i3, -2, %l7
a0080f14:  ee 2d 63 45  stb  %l7, [ %l5 + 0x345 ]
a0080f18:  10 80 00 5a  b  0xa0081080
a0080f1c:  82 0b 20 ff  and  %o4, 0xff, %g1
a0080f20:  40 03 0c 83  call  0xa014412c
a0080f24:  01 00 00 00  nop
a0080f28:  80 a0 00 12  cmp  %g0, %l2
a0080f2c:  c2 07 22 90  ld  [ %i4 + 0x290 ], %g1
a0080f30:  a3 30 60 09  srl  %g1, 9, %l1
a0080f34:  a6 60 3f ff  subx  %g0, -1, %l3
a0080f38:  80 8c 40 13  btst  %l1, %l3
a0080f3c:  02 80 03 a9  be  0xa0081de0
a0080f40:  80 8a 20 ff  btst  0xff, %o0
a0080f44:  12 80 00 03  bne  0xa0080f50
a0080f48:  90 10 20 01  mov  1, %o0
a0080f4c:  90 10 20 00  clr  %o0
a0080f50:  94 1a 20 01  xor  %o0, 1, %o2
a0080f54:  80 a0 00 0a  cmp  %g0, %o2
a0080f58:  98 60 20 00  subx  %g0, 0, %o4
a0080f5c:  b8 0b 20 06  and  %o4, 6, %i4
a0080f60:  a2 07 20 04  add  %i4, 4, %l1
a0080f64:  96 0c 60 ff  and  %l1, 0xff, %o3
a0080f68:  90 1a e0 04  xor  %o3, 4, %o0
a0080f6c:  80 a0 00 08  cmp  %g0, %o0
a0080f70:  94 60 3f ff  subx  %g0, -1, %o2
a0080f74:  82 1a e0 0a  xor  %o3, 0xa, %g1
a0080f78:  80 a0 00 01  cmp  %g0, %g1
a0080f7c:  b8 60 3f ff  subx  %g0, -1, %i4
a0080f80:  80 92 80 1c  orcc  %o2, %i4, %g0
a0080f84:  02 80 00 07  be  0xa0080fa0
a0080f88:  a0 1a e0 0a  xor  %o3, 0xa, %l0
a0080f8c:  9a 17 63 50  or  %i5, 0x350, %o5
a0080f90:  e2 2b 40 12  stb  %l1, [ %o5 + %l2 ]
a0080f94:  a2 10 20 0f  mov  0xf, %l1
a0080f98:  96 10 20 0f  mov  0xf, %o3
a0080f9c:  a0 1a e0 0a  xor  %o3, 0xa, %l0
a0080fa0:  80 a0 00 10  cmp  %g0, %l0
a0080fa4:  98 60 3f ff  subx  %g0, -1, %o4
a0080fa8:  aa 1a e0 04  xor  %o3, 4, %l5
a0080fac:  80 a0 00 15  cmp  %g0, %l5
a0080fb0:  ba 60 3f ff  subx  %g0, -1, %i5
a0080fb4:  80 93 00 1d  orcc  %o4, %i5, %g0
a0080fb8:  12 80 00 15  bne  0xa008100c
a0080fbc:  80 a4 a0 02  cmp  %l2, 2
a0080fc0:  a6 1a e0 0f  xor  %o3, 0xf, %l3
a0080fc4:  80 a0 00 13  cmp  %g0, %l3
a0080fc8:  ae 60 3f ff  subx  %g0, -1, %l7
a0080fcc:  92 1a e0 18  xor  %o3, 0x18, %o1
a0080fd0:  80 a0 00 09  cmp  %g0, %o1
a0080fd4:  9e 60 3f ff  subx  %g0, -1, %o7
a0080fd8:  80 95 c0 0f  orcc  %l7, %o7, %g0
a0080fdc:  12 80 00 0c  bne  0xa008100c
a0080fe0:  80 a4 a0 02  cmp  %l2, 2
a0080fe4:  90 1a e0 1c  xor  %o3, 0x1c, %o0
a0080fe8:  80 a0 00 08  cmp  %g0, %o0
a0080fec:  94 60 3f ff  subx  %g0, -1, %o2
a0080ff0:  82 1a e0 25  xor  %o3, 0x25, %g1
a0080ff4:  80 a0 00 01  cmp  %g0, %g1
a0080ff8:  b8 60 3f ff  subx  %g0, -1, %i4
a0080ffc:  80 92 80 1c  orcc  %o2, %i4, %g0
a0081000:  02 80 02 7b  be  0xa00819ec
a0081004:  aa 1a e0 2a  xor  %o3, 0x2a, %l5
a0081008:  80 a4 a0 02  cmp  %l2, 2
a008100c:  02 80 01 bb  be  0xa00816f8
a0081010:  80 a4 a0 02  cmp  %l2, 2
a0081014:  14 80 01 a9  bg  0xa00816b8
a0081018:  80 a4 a0 03  cmp  %l2, 3
a008101c:  80 a4 a0 01  cmp  %l2, 1
a0081020:  22 80 03 29  be,a   0xa0081cc4
a0081024:  a2 04 60 01  inc  %l1
a0081028:  80 a2 e0 3f  cmp  %o3, 0x3f
a008102c:  02 80 00 12  be  0xa0081074
a0081030:  80 a4 a0 02  cmp  %l2, 2
a0081034:  02 80 02 13  be  0xa0081880
a0081038:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a008103c:  14 80 01 ea  bg  0xa00817e4
a0081040:  80 a4 a0 03  cmp  %l2, 3
a0081044:  80 a4 a0 01  cmp  %l2, 1
a0081048:  02 80 03 43  be  0xa0081d54
a008104c:  ea 13 23 42  lduh  [ %o4 + 0x342 ], %l5
a0081050:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a0081054:  e2 13 23 42  lduh  [ %o4 + 0x342 ], %l1	! 0xa802af42
a0081058:  82 0c 7b de  and  %l1, -1058, %g1
a008105c:  c2 33 23 42  sth  %g1, [ %o4 + 0x342 ]
a0081060:  15 3f ff ef  sethi  %hi(0xffffbc00), %o2
a0081064:  e6 13 23 42  lduh  [ %o4 + 0x342 ], %l3
a0081068:  b8 12 a1 ef  or  %o2, 0x1ef, %i4
a008106c:  92 0c c0 1c  and  %l3, %i4, %o1
a0081070:  d2 33 23 42  sth  %o1, [ %o4 + 0x342 ]
a0081074:  82 15 23 60  or  %l4, 0x360, %g1
a0081078:  f6 28 40 12  stb  %i3, [ %g1 + %l2 ]
a008107c:  82 10 00 0b  mov  %o3, %g1
a0081080:  a6 08 60 ff  and  %g1, 0xff, %l3
a0081084:  80 a4 e0 3f  cmp  %l3, 0x3f
a0081088:  02 bf ff 06  be  0xa0080ca0
a008108c:  a2 10 00 01  mov  %g1, %l1
a0081090:  40 00 24 3d  call  0xa008a184
a0081094:  90 10 00 13  mov  %l3, %o0
a0081098:  80 a4 e0 00  cmp  %l3, 0
a008109c:  12 80 00 29  bne  0xa0081140
a00810a0:  9a 04 7f f1  add  %l1, -15, %o5
a00810a4:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00810a8:  a8 16 e2 90  or  %i3, 0x290, %l4	! 0xa802d290
a00810ac:  aa 10 20 01  mov  1, %l5
a00810b0:  a0 10 20 00  clr  %l0
a00810b4:  10 80 00 11  b  0xa00810f8
a00810b8:  90 10 20 00  clr  %o0
a00810bc:  80 a2 20 01  cmp  %o0, 1
a00810c0:  02 80 00 96  be  0xa0081318
a00810c4:  80 a2 20 02  cmp  %o0, 2
a00810c8:  02 80 00 c0  be  0xa00813c8
a00810cc:  80 a2 20 03  cmp  %o0, 3
a00810d0:  22 80 01 00  be,a   0xa00814d0
a00810d4:  ee 0d 20 1f  ldub  [ %l4 + 0x1f ], %l7
a00810d8:  80 8b 60 ff  btst  0xff, %o5
a00810dc:  12 80 00 0e  bne  0xa0081114
a00810e0:  01 00 00 00  nop
a00810e4:  a0 04 20 01  inc  %l0
a00810e8:  90 0c 20 ff  and  %l0, 0xff, %o0
a00810ec:  80 a2 20 03  cmp  %o0, 3
a00810f0:  18 80 00 11  bgu  0xa0081134
a00810f4:  80 8d 60 ff  btst  0xff, %l5
a00810f8:  80 a2 20 00  cmp  %o0, 0
a00810fc:  12 bf ff f0  bne  0xa00810bc
a0081100:  9a 10 20 00  clr  %o5
a0081104:  9a 10 20 01  mov  1, %o5
a0081108:  80 8b 60 ff  btst  0xff, %o5
a008110c:  22 bf ff f7  be,a   0xa00810e8
a0081110:  a0 04 20 01  inc  %l0
a0081114:  40 03 0a c0  call  0xa0143c14
a0081118:  01 00 00 00  nop
a008111c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0081120:  80 a2 20 03  cmp  %o0, 3
a0081124:  28 bf ff f1  bleu,a   0xa00810e8
a0081128:  a0 04 20 01  inc  %l0
a008112c:  aa 10 20 00  clr  %l5
a0081130:  80 8d 60 ff  btst  0xff, %l5
a0081134:  12 80 00 e3  bne  0xa00814c0
a0081138:  90 10 20 03  mov  3, %o0
a008113c:  9a 04 7f f1  add  %l1, -15, %o5
a0081140:  a8 0b 60 ff  and  %o5, 0xff, %l4
a0081144:  80 a5 20 03  cmp  %l4, 3
a0081148:  08 80 00 e7  bleu  0xa00814e4
a008114c:  ae 04 7f fc  add  %l1, -4, %l7
a0081150:  9e 0d e0 ff  and  %l7, 0xff, %o7
a0081154:  80 a3 e0 04  cmp  %o7, 4
a0081158:  98 04 7f f6  add  %l1, -10, %o4
a008115c:  96 60 20 00  subx  %g0, 0, %o3
a0081160:  ba 0b 20 ff  and  %o4, 0xff, %i5
a0081164:  80 a7 60 04  cmp  %i5, 4
a0081168:  b6 60 20 00  subx  %g0, 0, %i3
a008116c:  a0 16 c0 0b  or  %i3, %o3, %l0
a0081170:  80 8c 20 01  btst  1, %l0
a0081174:  22 80 00 a9  be,a   0xa0081418
a0081178:  a8 04 7f e0  add  %l1, -32, %l4
a008117c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0081180:  a2 12 22 90  or  %o0, 0x290, %l1	! 0xa802d290
a0081184:  a8 10 20 01  mov  1, %l4
a0081188:  a0 10 20 00  clr  %l0
a008118c:  10 80 00 11  b  0xa00811d0
a0081190:  90 10 20 00  clr  %o0
a0081194:  80 a2 20 01  cmp  %o0, 1
a0081198:  02 80 00 94  be  0xa00813e8
a008119c:  80 a2 20 02  cmp  %o0, 2
a00811a0:  02 80 01 0c  be  0xa00815d0
a00811a4:  80 a2 20 03  cmp  %o0, 3
a00811a8:  22 80 01 49  be,a   0xa00816cc
a00811ac:  c2 0c 60 1f  ldub  [ %l1 + 0x1f ], %g1
a00811b0:  80 8b 60 ff  btst  0xff, %o5
a00811b4:  12 80 00 0e  bne  0xa00811ec
a00811b8:  01 00 00 00  nop
a00811bc:  a0 04 20 01  inc  %l0
a00811c0:  90 0c 20 ff  and  %l0, 0xff, %o0
a00811c4:  80 a2 20 03  cmp  %o0, 3
a00811c8:  18 80 00 11  bgu  0xa008120c
a00811cc:  80 8d 20 ff  btst  0xff, %l4
a00811d0:  80 a2 20 00  cmp  %o0, 0
a00811d4:  12 bf ff f0  bne  0xa0081194
a00811d8:  9a 10 20 00  clr  %o5
a00811dc:  9a 10 20 01  mov  1, %o5
a00811e0:  80 8b 60 ff  btst  0xff, %o5
a00811e4:  22 bf ff f7  be,a   0xa00811c0
a00811e8:  a0 04 20 01  inc  %l0
a00811ec:  40 03 0a 8a  call  0xa0143c14
a00811f0:  01 00 00 00  nop
a00811f4:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00811f8:  80 a3 60 04  cmp  %o5, 4
a00811fc:  28 bf ff f1  bleu,a   0xa00811c0
a0081200:  a0 04 20 01  inc  %l0
a0081204:  a8 10 20 00  clr  %l4
a0081208:  80 8d 20 ff  btst  0xff, %l4
a008120c:  22 bf fe a6  be,a   0xa0080ca4
a0081210:  ac 05 a0 01  inc  %l6
a0081214:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a0081218:  aa 15 22 90  or  %l4, 0x290, %l5	! 0xa802d290
a008121c:  a8 10 20 01  mov  1, %l4
a0081220:  a2 10 20 00  clr  %l1
a0081224:  a0 10 20 00  clr  %l0
a0081228:  10 80 00 11  b  0xa008126c
a008122c:  2f 2a 00 ab  sethi  %hi(0xa802ac00), %l7
a0081230:  80 a4 20 01  cmp  %l0, 1
a0081234:  02 80 01 99  be  0xa0081898
a0081238:  80 a4 20 02  cmp  %l0, 2
a008123c:  02 80 01 c3  be  0xa0081948
a0081240:  80 a4 20 03  cmp  %l0, 3
a0081244:  22 80 02 a2  be,a   0xa0081ccc
a0081248:  de 0d 60 1f  ldub  [ %l5 + 0x1f ], %o7
a008124c:  80 8b 60 ff  btst  0xff, %o5
a0081250:  12 80 00 0f  bne  0xa008128c
a0081254:  80 a4 00 12  cmp  %l0, %l2
a0081258:  a2 04 60 01  inc  %l1
a008125c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0081260:  80 a4 20 03  cmp  %l0, 3
a0081264:  38 80 01 a8  bgu,a   0xa0081904
a0081268:  a4 0d 20 ff  and  %l4, 0xff, %l2
a008126c:  80 a4 20 00  cmp  %l0, 0
a0081270:  12 bf ff f0  bne  0xa0081230
a0081274:  9a 10 20 00  clr  %o5
a0081278:  9a 10 20 01  mov  1, %o5
a008127c:  80 8b 60 ff  btst  0xff, %o5
a0081280:  22 bf ff f7  be,a   0xa008125c
a0081284:  a2 04 60 01  inc  %l1
a0081288:  80 a4 00 12  cmp  %l0, %l2
a008128c:  02 bf ff f3  be  0xa0081258
a0081290:  80 a4 20 02  cmp  %l0, 2
a0081294:  02 80 00 09  be  0xa00812b8
a0081298:  90 10 20 06  mov  6, %o0
a008129c:  80 a4 20 02  cmp  %l0, 2
a00812a0:  14 80 01 a7  bg  0xa008193c
a00812a4:  80 a4 20 03  cmp  %l0, 3
a00812a8:  80 a4 20 01  cmp  %l0, 1
a00812ac:  02 80 00 03  be  0xa00812b8
a00812b0:  90 10 20 05  mov  5, %o0
a00812b4:  90 10 20 04  mov  4, %o0
a00812b8:  40 00 15 e1  call  0xa0086a3c
a00812bc:  01 00 00 00  nop
a00812c0:  91 2a 20 10  sll  %o0, 0x10, %o0
a00812c4:  80 a2 20 00  cmp  %o0, 0
a00812c8:  22 bf ff e5  be,a   0xa008125c
a00812cc:  a2 04 60 01  inc  %l1
a00812d0:  80 a4 20 00  cmp  %l0, 0
a00812d4:  12 80 02 83  bne  0xa0081ce0
a00812d8:  80 a4 20 01  cmp  %l0, 1
a00812dc:  e0 0d e3 45  ldub  [ %l7 + 0x345 ], %l0
a00812e0:  80 8c 20 01  btst  1, %l0
a00812e4:  12 80 00 03  bne  0xa00812f0
a00812e8:  82 10 20 01  mov  1, %g1
a00812ec:  82 10 20 00  clr  %g1
a00812f0:  82 20 00 01  neg  %g1
a00812f4:  10 bf ff d9  b  0xa0081258
a00812f8:  a8 08 40 14  and  %g1, %l4, %l4
a00812fc:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a0081300:  da 0a a2 af  ldub  [ %o2 + 0x2af ], %o5	! 0xa802d2af
a0081304:  80 a3 60 00  cmp  %o5, 0
a0081308:  02 bf fe 64  be  0xa0080c98
a008130c:  80 8b 20 ff  btst  0xff, %o4
a0081310:  10 bf fe 6d  b  0xa0080cc4
a0081314:  98 10 20 01  mov  1, %o4
a0081318:  d6 0d 20 1f  ldub  [ %l4 + 0x1f ], %o3
a008131c:  80 a2 e0 00  cmp  %o3, 0
a0081320:  02 bf ff 6f  be  0xa00810dc
a0081324:  80 8b 60 ff  btst  0xff, %o5
a0081328:  10 bf ff 78  b  0xa0081108
a008132c:  9a 10 20 01  mov  1, %o5
a0081330:  12 bf fe 8c  bne  0xa0080d60
a0081334:  90 10 20 07  mov  7, %o0
a0081338:  30 bf fe 8b  b,a   0xa0080d64
a008133c:  80 a4 a0 01  cmp  %l2, 1
a0081340:  02 80 01 31  be  0xa0081804
a0081344:  80 a4 a0 02  cmp  %l2, 2
a0081348:  02 80 01 5d  be  0xa00818bc
a008134c:  80 a4 a0 03  cmp  %l2, 3
a0081350:  02 80 02 47  be  0xa0081c6c
a0081354:  80 a4 a0 04  cmp  %l2, 4
a0081358:  02 80 02 6d  be  0xa0081d0c
a008135c:  80 a4 a0 02  cmp  %l2, 2
a0081360:  22 80 01 5c  be,a   0xa00818d0
a0081364:  98 03 20 02  add  %o4, 2, %o4
a0081368:  14 80 01 c9  bg  0xa0081a8c
a008136c:  80 a4 a0 03  cmp  %l2, 3
a0081370:  80 a4 a0 01  cmp  %l2, 1
a0081374:  32 bf ff 43  bne,a   0xa0081080
a0081378:  82 0b 20 ff  and  %o4, 0xff, %g1
a008137c:  98 03 20 01  inc  %o4
a0081380:  10 bf ff 40  b  0xa0081080
a0081384:  82 0b 20 ff  and  %o4, 0xff, %g1
a0081388:  ac 0e 7f f7  and  %i1, -9, %l6
a008138c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0081390:  80 a6 20 3f  cmp  %i0, 0x3f
a0081394:  02 80 02 9c  be  0xa0081e04
a0081398:  ec 2e a3 41  stb  %l6, [ %i2 + 0x341 ]
a008139c:  40 00 23 7a  call  0xa008a184
a00813a0:  81 e8 00 00  restore
a00813a4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00813a8:  e0 0c 62 af  ldub  [ %l1 + 0x2af ], %l0	! 0xa802d2af
a00813ac:  9e 04 3f fc  add  %l0, -4, %o7
a00813b0:  96 0b e0 ff  and  %o7, 0xff, %o3
a00813b4:  80 a2 e0 03  cmp  %o3, 3
a00813b8:  18 bf fe 38  bgu  0xa0080c98
a00813bc:  80 8b 20 ff  btst  0xff, %o4
a00813c0:  10 bf fe 41  b  0xa0080cc4
a00813c4:  98 10 20 01  mov  1, %o4
a00813c8:  de 0d 20 1f  ldub  [ %l4 + 0x1f ], %o7
a00813cc:  98 03 ff fc  add  %o7, -4, %o4
a00813d0:  ba 0b 20 ff  and  %o4, 0xff, %i5
a00813d4:  80 a7 60 03  cmp  %i5, 3
a00813d8:  18 bf ff 41  bgu  0xa00810dc
a00813dc:  80 8b 60 ff  btst  0xff, %o5
a00813e0:  10 bf ff 4a  b  0xa0081108
a00813e4:  9a 10 20 01  mov  1, %o5
a00813e8:  ea 0c 60 1f  ldub  [ %l1 + 0x1f ], %l5
a00813ec:  80 a5 60 00  cmp  %l5, 0
a00813f0:  02 bf ff 71  be  0xa00811b4
a00813f4:  80 8b 60 ff  btst  0xff, %o5
a00813f8:  10 bf ff 7a  b  0xa00811e0
a00813fc:  9a 10 20 01  mov  1, %o5
a0081400:  e6 0d 22 af  ldub  [ %l4 + 0x2af ], %l3
a0081404:  80 a4 e0 07  cmp  %l3, 7
a0081408:  12 bf fe 24  bne  0xa0080c98
a008140c:  80 8b 20 ff  btst  0xff, %o4
a0081410:  10 bf fe 2d  b  0xa0080cc4
a0081414:  98 10 20 01  mov  1, %o4
a0081418:  9a 0d 20 ff  and  %l4, 0xff, %o5
a008141c:  80 a3 60 03  cmp  %o5, 3
a0081420:  18 80 00 be  bgu  0xa0081718
a0081424:  b8 04 7f c8  add  %l1, -56, %i4
a0081428:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a008142c:  a2 16 e2 90  or  %i3, 0x290, %l1	! 0xa802d290
a0081430:  a4 10 20 01  mov  1, %l2
a0081434:  a0 10 20 00  clr  %l0
a0081438:  10 80 00 11  b  0xa008147c
a008143c:  90 10 20 00  clr  %o0
a0081440:  80 a2 20 01  cmp  %o0, 1
a0081444:  02 80 00 a7  be  0xa00816e0
a0081448:  80 a2 20 02  cmp  %o0, 2
a008144c:  02 80 00 f4  be  0xa008181c
a0081450:  80 a2 20 03  cmp  %o0, 3
a0081454:  22 80 01 27  be,a   0xa00818f0
a0081458:  d2 0c 60 1f  ldub  [ %l1 + 0x1f ], %o1
a008145c:  80 8b 60 ff  btst  0xff, %o5
a0081460:  12 80 00 0e  bne  0xa0081498
a0081464:  01 00 00 00  nop
a0081468:  a0 04 20 01  inc  %l0
a008146c:  90 0c 20 ff  and  %l0, 0xff, %o0
a0081470:  80 a2 20 03  cmp  %o0, 3
a0081474:  18 80 00 11  bgu  0xa00814b8
a0081478:  80 8c a0 ff  btst  0xff, %l2
a008147c:  80 a2 20 00  cmp  %o0, 0
a0081480:  12 bf ff f0  bne  0xa0081440
a0081484:  9a 10 20 00  clr  %o5
a0081488:  9a 10 20 01  mov  1, %o5
a008148c:  80 8b 60 ff  btst  0xff, %o5
a0081490:  22 bf ff f7  be,a   0xa008146c
a0081494:  a0 04 20 01  inc  %l0
a0081498:  40 03 09 df  call  0xa0143c14
a008149c:  01 00 00 00  nop
a00814a0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00814a4:  80 a2 20 08  cmp  %o0, 8
a00814a8:  28 bf ff f1  bleu,a   0xa008146c
a00814ac:  a0 04 20 01  inc  %l0
a00814b0:  a4 10 20 00  clr  %l2
a00814b4:  80 8c a0 ff  btst  0xff, %l2
a00814b8:  02 bf fd fa  be  0xa0080ca0
a00814bc:  90 10 20 24  mov  0x24, %o0
a00814c0:  40 00 23 31  call  0xa008a184
a00814c4:  ac 05 a0 01  inc  %l6
a00814c8:  10 bf fd f8  b  0xa0080ca8
a00814cc:  a4 0d a0 ff  and  %l6, 0xff, %l2
a00814d0:  80 a5 e0 07  cmp  %l7, 7
a00814d4:  12 bf ff 02  bne  0xa00810dc
a00814d8:  80 8b 60 ff  btst  0xff, %o5
a00814dc:  10 bf ff 0b  b  0xa0081108
a00814e0:  9a 10 20 01  mov  1, %o5
a00814e4:  90 10 20 13  mov  0x13, %o0
a00814e8:  40 00 23 27  call  0xa008a184
a00814ec:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00814f0:  a2 14 a2 90  or  %l2, 0x290, %l1	! 0xa802d290
a00814f4:  a4 10 20 01  mov  1, %l2
a00814f8:  a0 10 20 00  clr  %l0
a00814fc:  10 80 00 11  b  0xa0081540
a0081500:  90 10 20 00  clr  %o0
a0081504:  80 a2 20 01  cmp  %o0, 1
a0081508:  02 80 00 2c  be  0xa00815b8
a008150c:  80 a2 20 02  cmp  %o0, 2
a0081510:  02 80 00 62  be  0xa0081698
a0081514:  80 a2 20 03  cmp  %o0, 3
a0081518:  22 80 00 7b  be,a   0xa0081704
a008151c:  d4 0c 60 1f  ldub  [ %l1 + 0x1f ], %o2
a0081520:  80 8b 60 ff  btst  0xff, %o5
a0081524:  12 80 00 0e  bne  0xa008155c
a0081528:  01 00 00 00  nop
a008152c:  a0 04 20 01  inc  %l0
a0081530:  90 0c 20 ff  and  %l0, 0xff, %o0
a0081534:  80 a2 20 03  cmp  %o0, 3
a0081538:  18 80 00 11  bgu  0xa008157c
a008153c:  80 8c a0 ff  btst  0xff, %l2
a0081540:  80 a2 20 00  cmp  %o0, 0
a0081544:  12 bf ff f0  bne  0xa0081504
a0081548:  9a 10 20 00  clr  %o5
a008154c:  9a 10 20 01  mov  1, %o5
a0081550:  80 8b 60 ff  btst  0xff, %o5
a0081554:  22 bf ff f7  be,a   0xa0081530
a0081558:  a0 04 20 01  inc  %l0
a008155c:  40 03 09 ae  call  0xa0143c14
a0081560:  01 00 00 00  nop
a0081564:  82 0a 20 ff  and  %o0, 0xff, %g1
a0081568:  80 a0 60 04  cmp  %g1, 4
a008156c:  28 bf ff f1  bleu,a   0xa0081530
a0081570:  a0 04 20 01  inc  %l0
a0081574:  a4 10 20 00  clr  %l2
a0081578:  80 8c a0 ff  btst  0xff, %l2
a008157c:  22 bf fd ca  be,a   0xa0080ca4
a0081580:  ac 05 a0 01  inc  %l6
a0081584:  c2 0e a3 41  ldub  [ %i2 + 0x341 ], %g1
a0081588:  80 88 60 08  btst  8, %g1
a008158c:  32 bf fd c6  bne,a   0xa0080ca4
a0081590:  ac 05 a0 01  inc  %l6
a0081594:  80 8e 60 ff  btst  0xff, %i1
a0081598:  32 bf fd c3  bne,a   0xa0080ca4
a008159c:  ac 05 a0 01  inc  %l6
a00815a0:  a2 10 60 08  or  %g1, 8, %l1
a00815a4:  e2 2e a3 41  stb  %l1, [ %i2 + 0x341 ]
a00815a8:  40 00 22 f7  call  0xa008a184
a00815ac:  90 10 20 14  mov  0x14, %o0
a00815b0:  10 bf fd bd  b  0xa0080ca4
a00815b4:  ac 05 a0 01  inc  %l6
a00815b8:  ea 0c 60 1f  ldub  [ %l1 + 0x1f ], %l5
a00815bc:  80 a5 60 00  cmp  %l5, 0
a00815c0:  02 bf ff d9  be  0xa0081524
a00815c4:  80 8b 60 ff  btst  0xff, %o5
a00815c8:  10 bf ff e2  b  0xa0081550
a00815cc:  9a 10 20 01  mov  1, %o5
a00815d0:  d4 0c 60 1f  ldub  [ %l1 + 0x1f ], %o2
a00815d4:  b8 02 bf fc  add  %o2, -4, %i4
a00815d8:  92 0f 20 ff  and  %i4, 0xff, %o1
a00815dc:  80 a2 60 03  cmp  %o1, 3
a00815e0:  18 bf fe f5  bgu  0xa00811b4
a00815e4:  80 8b 60 ff  btst  0xff, %o5
a00815e8:  10 bf fe fe  b  0xa00811e0
a00815ec:  9a 10 20 01  mov  1, %o5
a00815f0:  40 03 0a 80  call  0xa0143ff0
a00815f4:  90 10 00 12  mov  %l2, %o0
a00815f8:  82 0a 20 ff  and  %o0, 0xff, %g1
a00815fc:  82 08 60 ff  and  %g1, 0xff, %g1
a0081600:  80 a0 60 01  cmp  %g1, 1
a0081604:  12 bf fe 0d  bne  0xa0080e38
a0081608:  90 10 20 01  mov  1, %o0
a008160c:  d2 0d 23 64  ldub  [ %l4 + 0x364 ], %o1
a0081610:  83 28 40 12  sll  %g1, %l2, %g1
a0081614:  82 10 40 09  or  %g1, %o1, %g1
a0081618:  c2 2d 23 64  stb  %g1, [ %l4 + 0x364 ]
a008161c:  80 8d 60 ff  btst  0xff, %l5
a0081620:  02 bf fe 0d  be  0xa0080e54
a0081624:  29 2a 00 ab  sethi  %hi(0xa802ac00), %l4
a0081628:  98 14 e3 f4  or  %l3, 0x3f4, %o4
a008162c:  de 13 20 04  lduh  [ %o4 + 4 ], %o7
a0081630:  17 00 00 18  sethi  %hi(0x6000), %o3
a0081634:  aa 0a c0 0f  and  %o3, %o7, %l5
a0081638:  29 00 00 10  sethi  %hi(0x4000), %l4
a008163c:  80 a5 40 14  cmp  %l5, %l4
a0081640:  12 80 00 0a  bne  0xa0081668
a0081644:  ee 07 22 90  ld  [ %i4 + 0x290 ], %l7
a0081648:  80 8d e2 00  btst  0x200, %l7
a008164c:  02 80 01 17  be  0xa0081aa8
a0081650:  82 17 22 90  or  %i4, 0x290, %g1
a0081654:  d2 00 60 a8  ld  [ %g1 + 0xa8 ], %o1
a0081658:  03 00 00 20  sethi  %hi(0x8000), %g1
a008165c:  80 8a 40 01  btst  %o1, %g1
a0081660:  12 80 01 12  bne  0xa0081aa8
a0081664:  01 00 00 00  nop
a0081668:  40 02 98 dd  call  0xa01279dc
a008166c:  01 00 00 00  nop
a0081670:  94 0a 20 ff  and  %o0, 0xff, %o2
a0081674:  80 a2 a0 01  cmp  %o2, 1
a0081678:  02 80 01 c5  be  0xa0081d8c
a008167c:  80 a4 a0 04  cmp  %l2, 4
a0081680:  02 80 01 89  be  0xa0081ca4
a0081684:  9e 10 3f ff  mov  -1, %o7
a0081688:  29 2a 00 ab  sethi  %hi(0xa802ac00), %l4
a008168c:  96 15 23 60  or  %l4, 0x360, %o3	! 0xa802af60
a0081690:  10 bf fd f1  b  0xa0080e54
a0081694:  de 2a c0 12  stb  %o7, [ %o3 + %l2 ]
a0081698:  f8 0c 60 1f  ldub  [ %l1 + 0x1f ], %i4
a008169c:  a6 07 3f fc  add  %i4, -4, %l3
a00816a0:  92 0c e0 ff  and  %l3, 0xff, %o1
a00816a4:  80 a2 60 03  cmp  %o1, 3
a00816a8:  18 bf ff 9f  bgu  0xa0081524
a00816ac:  80 8b 60 ff  btst  0xff, %o5
a00816b0:  10 bf ff a8  b  0xa0081550
a00816b4:  9a 10 20 01  mov  1, %o5
a00816b8:  12 bf fe 5d  bne  0xa008102c
a00816bc:  80 a2 e0 3f  cmp  %o3, 0x3f
a00816c0:  a2 04 60 03  add  %l1, 3, %l1
a00816c4:  10 bf fe 59  b  0xa0081028
a00816c8:  96 0c 60 ff  and  %l1, 0xff, %o3
a00816cc:  80 a0 60 07  cmp  %g1, 7
a00816d0:  12 bf fe b9  bne  0xa00811b4
a00816d4:  80 8b 60 ff  btst  0xff, %o5
a00816d8:  10 bf fe c2  b  0xa00811e0
a00816dc:  9a 10 20 01  mov  1, %o5
a00816e0:  d6 0c 60 1f  ldub  [ %l1 + 0x1f ], %o3
a00816e4:  80 a2 e0 00  cmp  %o3, 0
a00816e8:  02 bf ff 5e  be  0xa0081460
a00816ec:  80 8b 60 ff  btst  0xff, %o5
a00816f0:  10 bf ff 67  b  0xa008148c
a00816f4:  9a 10 20 01  mov  1, %o5
a00816f8:  a2 04 60 02  add  %l1, 2, %l1
a00816fc:  10 bf fe 4b  b  0xa0081028
a0081700:  96 0c 60 ff  and  %l1, 0xff, %o3
a0081704:  80 a2 a0 07  cmp  %o2, 7
a0081708:  12 bf ff 87  bne  0xa0081524
a008170c:  80 8b 60 ff  btst  0xff, %o5
a0081710:  10 bf ff 90  b  0xa0081550
a0081714:  9a 10 20 01  mov  1, %o5
a0081718:  a0 0f 20 ff  and  %i4, 0xff, %l0
a008171c:  80 a4 20 03  cmp  %l0, 3
a0081720:  38 80 00 95  bgu,a   0xa0081974
a0081724:  a6 04 7f cd  add  %l1, -51, %l3
a0081728:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a008172c:  a4 12 a2 90  or  %o2, 0x290, %l2	! 0xa802d290
a0081730:  a6 10 20 01  mov  1, %l3
a0081734:  a2 10 20 00  clr  %l1
a0081738:  10 80 00 11  b  0xa008177c
a008173c:  a0 10 20 00  clr  %l0
a0081740:  80 a4 20 01  cmp  %l0, 1
a0081744:  02 80 00 65  be  0xa00818d8
a0081748:  80 a4 20 02  cmp  %l0, 2
a008174c:  02 80 01 4e  be  0xa0081c84
a0081750:  80 a4 20 03  cmp  %l0, 3
a0081754:  22 80 01 72  be,a   0xa0081d1c
a0081758:  f6 0c a0 1f  ldub  [ %l2 + 0x1f ], %i3
a008175c:  80 8b 60 ff  btst  0xff, %o5
a0081760:  12 80 00 0e  bne  0xa0081798
a0081764:  01 00 00 00  nop
a0081768:  a2 04 60 01  inc  %l1
a008176c:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0081770:  80 a4 20 03  cmp  %l0, 3
a0081774:  18 80 00 16  bgu  0xa00817cc
a0081778:  80 8c e0 ff  btst  0xff, %l3
a008177c:  80 a4 20 00  cmp  %l0, 0
a0081780:  12 bf ff f0  bne  0xa0081740
a0081784:  9a 10 20 00  clr  %o5
a0081788:  9a 10 20 01  mov  1, %o5
a008178c:  80 8b 60 ff  btst  0xff, %o5
a0081790:  22 bf ff f7  be,a   0xa008176c
a0081794:  a2 04 60 01  inc  %l1
a0081798:  40 03 09 1f  call  0xa0143c14
a008179c:  90 10 00 10  mov  %l0, %o0
a00817a0:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00817a4:  80 a3 60 04  cmp  %o5, 4
a00817a8:  28 bf ff f1  bleu,a   0xa008176c
a00817ac:  a2 04 60 01  inc  %l1
a00817b0:  40 03 09 b0  call  0xa0143e70
a00817b4:  90 10 00 10  mov  %l0, %o0
a00817b8:  80 8a 20 ff  btst  0xff, %o0
a00817bc:  32 bf ff ec  bne,a   0xa008176c
a00817c0:  a2 04 60 01  inc  %l1
a00817c4:  a6 10 20 00  clr  %l3
a00817c8:  80 8c e0 ff  btst  0xff, %l3
a00817cc:  02 bf fd 35  be  0xa0080ca0
a00817d0:  90 10 20 3c  mov  0x3c, %o0
a00817d4:  40 00 22 6c  call  0xa008a184
a00817d8:  ac 05 a0 01  inc  %l6
a00817dc:  10 bf fd 33  b  0xa0080ca8
a00817e0:  a4 0d a0 ff  and  %l6, 0xff, %l2
a00817e4:  12 bf fe 1c  bne  0xa0081054
a00817e8:  19 2a 00 ab  sethi  %hi(0xa802ac00), %o4
a00817ec:  1f 3f ff f7  sethi  %hi(0xffffdc00), %o7
a00817f0:  da 13 23 42  lduh  [ %o4 + 0x342 ], %o5
a00817f4:  82 13 e2 f7  or  %o7, 0x2f7, %g1
a00817f8:  ae 0b 40 01  and  %o5, %g1, %l7
a00817fc:  10 bf fe 19  b  0xa0081060
a0081800:  ee 33 23 42  sth  %l7, [ %o4 + 0x342 ]
a0081804:  39 2a 00 ab  sethi  %hi(0xa802ac00), %i4
a0081808:  d0 0f 23 45  ldub  [ %i4 + 0x345 ], %o0	! 0xa802af45
a008180c:  82 0a 3f fd  and  %o0, -3, %g1
a0081810:  c2 2f 23 45  stb  %g1, [ %i4 + 0x345 ]
a0081814:  10 bf fe db  b  0xa0081380
a0081818:  98 03 20 01  inc  %o4
a008181c:  de 0c 60 1f  ldub  [ %l1 + 0x1f ], %o7
a0081820:  98 03 ff fc  add  %o7, -4, %o4
a0081824:  ba 0b 20 ff  and  %o4, 0xff, %i5
a0081828:  80 a7 60 03  cmp  %i5, 3
a008182c:  18 bf ff 0d  bgu  0xa0081460
a0081830:  80 8b 60 ff  btst  0xff, %o5
a0081834:  10 bf ff 16  b  0xa008148c
a0081838:  9a 10 20 01  mov  1, %o5
a008183c:  d6 0d 23 64  ldub  [ %l4 + 0x364 ], %o3
a0081840:  91 3a c0 12  sra  %o3, %l2, %o0
a0081844:  40 03 0a 3a  call  0xa014412c
a0081848:  ae 0a 20 01  and  %o0, 1, %l7
a008184c:  80 a0 00 12  cmp  %g0, %l2
a0081850:  d4 07 22 90  ld  [ %i4 + 0x290 ], %o2
a0081854:  9b 32 a0 09  srl  %o2, 9, %o5
a0081858:  92 60 3f ff  subx  %g0, -1, %o1
a008185c:  80 8b 40 09  btst  %o5, %o1
a0081860:  02 80 01 3f  be  0xa0081d5c
a0081864:  80 8a 20 ff  btst  0xff, %o0
a0081868:  02 80 00 8e  be  0xa0081aa0
a008186c:  90 10 20 01  mov  1, %o0
a0081870:  80 a5 c0 08  cmp  %l7, %o0
a0081874:  32 bf fd 60  bne,a   0xa0080df4
a0081878:  aa 10 20 01  mov  1, %l5
a008187c:  30 bf fd 5e  b,a   0xa0080df4
a0081880:  21 3f ff fb  sethi  %hi(0xffffec00), %l0
a0081884:  da 13 23 42  lduh  [ %o4 + 0x342 ], %o5
a0081888:  82 14 23 7b  or  %l0, 0x37b, %g1
a008188c:  ae 0b 40 01  and  %o5, %g1, %l7
a0081890:  10 bf fd f4  b  0xa0081060
a0081894:  ee 33 23 42  sth  %l7, [ %o4 + 0x342 ]
a0081898:  f6 0d 60 1f  ldub  [ %l5 + 0x1f ], %i3
a008189c:  80 a6 e0 00  cmp  %i3, 0
a00818a0:  02 bf fe 6c  be  0xa0081250
a00818a4:  80 8b 60 ff  btst  0xff, %o5
a00818a8:  10 bf fe 75  b  0xa008127c
a00818ac:  9a 10 20 01  mov  1, %o5
a00818b0:  d4 0a e3 45  ldub  [ %o3 + 0x345 ], %o2
a00818b4:  10 bf fd 38  b  0xa0080d94
a00818b8:  80 8a a0 02  btst  2, %o2
a00818bc:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a00818c0:  d4 0a 63 45  ldub  [ %o1 + 0x345 ], %o2	! 0xa802af45
a00818c4:  9a 0a bf fb  and  %o2, -5, %o5
a00818c8:  da 2a 63 45  stb  %o5, [ %o1 + 0x345 ]
a00818cc:  98 03 20 02  add  %o4, 2, %o4
a00818d0:  10 bf fd ec  b  0xa0081080
a00818d4:  82 0b 20 ff  and  %o4, 0xff, %g1
a00818d8:  c2 0c a0 1f  ldub  [ %l2 + 0x1f ], %g1
a00818dc:  80 a0 60 00  cmp  %g1, 0
a00818e0:  02 bf ff a0  be  0xa0081760
a00818e4:  80 8b 60 ff  btst  0xff, %o5
a00818e8:  10 bf ff a9  b  0xa008178c
a00818ec:  9a 10 20 01  mov  1, %o5
a00818f0:  80 a2 60 07  cmp  %o1, 7
a00818f4:  12 bf fe db  bne  0xa0081460
a00818f8:  80 8b 60 ff  btst  0xff, %o5
a00818fc:  10 bf fe e4  b  0xa008148c
a0081900:  9a 10 20 01  mov  1, %o5
a0081904:  80 a4 a0 01  cmp  %l2, 1
a0081908:  32 bf fc e7  bne,a   0xa0080ca4
a008190c:  ac 05 a0 01  inc  %l6
a0081910:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a0081914:  f0 0e 62 af  ldub  [ %i1 + 0x2af ], %i0	! 0xa802d2af
a0081918:  80 a6 20 00  cmp  %i0, 0
a008191c:  12 80 01 35  bne  0xa0081df0
a0081920:  b2 10 20 01  mov  1, %i1
a0081924:  a2 1c e0 0a  xor  %l3, 0xa, %l1
a0081928:  80 a0 00 11  cmp  %g0, %l1
a008192c:  aa 60 20 00  subx  %g0, 0, %l5
a0081930:  ae 0d 7f fa  and  %l5, -6, %l7
a0081934:  10 bf fc db  b  0xa0080ca0
a0081938:  b0 05 e0 0e  add  %l7, 0xe, %i0
a008193c:  12 bf fe 5e  bne  0xa00812b4
a0081940:  90 10 20 07  mov  7, %o0
a0081944:  30 bf fe 5d  b,a   0xa00812b8
a0081948:  d8 0d 60 1f  ldub  [ %l5 + 0x1f ], %o4
a008194c:  ba 03 3f fc  add  %o4, -4, %i5
a0081950:  96 0f 60 ff  and  %i5, 0xff, %o3
a0081954:  80 a2 e0 03  cmp  %o3, 3
a0081958:  18 bf fe 3e  bgu  0xa0081250
a008195c:  80 8b 60 ff  btst  0xff, %o5
a0081960:  10 bf fe 47  b  0xa008127c
a0081964:  9a 10 20 01  mov  1, %o5
a0081968:  de 0c 23 45  ldub  [ %l0 + 0x345 ], %o7
a008196c:  10 bf fd 0a  b  0xa0080d94
a0081970:  80 8b e0 04  btst  4, %o7
a0081974:  a4 0c e0 ff  and  %l3, 0xff, %l2
a0081978:  80 a4 a0 03  cmp  %l2, 3
a008197c:  18 80 00 4f  bgu  0xa0081ab8
a0081980:  b8 04 7f db  add  %l1, -37, %i4
a0081984:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0081988:  a4 14 62 90  or  %l1, 0x290, %l2	! 0xa802d290
a008198c:  a6 10 20 01  mov  1, %l3
a0081990:  a2 10 20 00  clr  %l1
a0081994:  10 80 00 11  b  0xa00819d8
a0081998:  a0 10 20 00  clr  %l0
a008199c:  80 a4 20 01  cmp  %l0, 1
a00819a0:  02 80 00 e7  be  0xa0081d3c
a00819a4:  80 a4 20 02  cmp  %l0, 2
a00819a8:  02 80 00 f1  be  0xa0081d6c
a00819ac:  80 a4 20 03  cmp  %l0, 3
a00819b0:  22 80 01 03  be,a   0xa0081dbc
a00819b4:  d2 0c a0 1f  ldub  [ %l2 + 0x1f ], %o1
a00819b8:  80 8b 60 ff  btst  0xff, %o5
a00819bc:  12 80 00 99  bne  0xa0081c20
a00819c0:  01 00 00 00  nop
a00819c4:  a2 04 60 01  inc  %l1
a00819c8:  a0 0c 60 ff  and  %l1, 0xff, %l0
a00819cc:  80 a4 20 03  cmp  %l0, 3
a00819d0:  18 80 00 a1  bgu  0xa0081c54
a00819d4:  80 8c e0 ff  btst  0xff, %l3
a00819d8:  80 a4 20 00  cmp  %l0, 0
a00819dc:  12 bf ff f0  bne  0xa008199c
a00819e0:  9a 10 20 00  clr  %o5
a00819e4:  10 bf ff f5  b  0xa00819b8
a00819e8:  9a 10 20 01  mov  1, %o5
a00819ec:  80 a0 00 15  cmp  %g0, %l5
a00819f0:  ba 60 3f ff  subx  %g0, -1, %i5
a00819f4:  98 1a e0 38  xor  %o3, 0x38, %o4
a00819f8:  80 a0 00 0c  cmp  %g0, %o4
a00819fc:  9a 60 3f ff  subx  %g0, -1, %o5
a0081a00:  80 97 40 0d  orcc  %i5, %o5, %g0
a0081a04:  12 bf fd 82  bne  0xa008100c
a0081a08:  80 a4 a0 02  cmp  %l2, 2
a0081a0c:  92 1a e0 33  xor  %o3, 0x33, %o1
a0081a10:  80 a0 00 09  cmp  %g0, %o1
a0081a14:  9e 60 3f ff  subx  %g0, -1, %o7
a0081a18:  ae 1a e0 2e  xor  %o3, 0x2e, %l7
a0081a1c:  80 a0 00 17  cmp  %g0, %l7
a0081a20:  a0 60 3f ff  subx  %g0, -1, %l0
a0081a24:  80 93 c0 10  orcc  %o7, %l0, %g0
a0081a28:  12 bf fd 79  bne  0xa008100c
a0081a2c:  80 a4 a0 02  cmp  %l2, 2
a0081a30:  82 1a e0 20  xor  %o3, 0x20, %g1
a0081a34:  80 a0 00 01  cmp  %g0, %g1
a0081a38:  b8 60 3f ff  subx  %g0, -1, %i4
a0081a3c:  94 1a e0 21  xor  %o3, 0x21, %o2
a0081a40:  80 a0 00 0a  cmp  %g0, %o2
a0081a44:  a6 60 3f ff  subx  %g0, -1, %l3
a0081a48:  80 97 00 13  orcc  %i4, %l3, %g0
a0081a4c:  12 bf fd 70  bne  0xa008100c
a0081a50:  80 a4 a0 02  cmp  %l2, 2
a0081a54:  98 1a e0 22  xor  %o3, 0x22, %o4
a0081a58:  80 a0 00 0c  cmp  %g0, %o4
a0081a5c:  9a 60 3f ff  subx  %g0, -1, %o5
a0081a60:  ba 1a e0 23  xor  %o3, 0x23, %i5
a0081a64:  80 a0 00 1d  cmp  %g0, %i5
a0081a68:  90 60 3f ff  subx  %g0, -1, %o0
a0081a6c:  80 93 40 08  orcc  %o5, %o0, %g0
a0081a70:  22 bf fd 6f  be,a   0xa008102c
a0081a74:  80 a2 e0 3f  cmp  %o3, 0x3f
a0081a78:  10 bf fd 65  b  0xa008100c
a0081a7c:  80 a4 a0 02  cmp  %l2, 2
a0081a80:  e2 0c e3 45  ldub  [ %l3 + 0x345 ], %l1
a0081a84:  10 bf fc c4  b  0xa0080d94
a0081a88:  80 8c 60 08  btst  8, %l1
a0081a8c:  32 bf fd 7d  bne,a   0xa0081080
a0081a90:  82 0b 20 ff  and  %o4, 0xff, %g1
a0081a94:  98 03 20 03  add  %o4, 3, %o4
a0081a98:  10 bf fd 7a  b  0xa0081080
a0081a9c:  82 0b 20 ff  and  %o4, 0xff, %g1
a0081aa0:  10 bf ff 74  b  0xa0081870
a0081aa4:  90 10 20 00  clr  %o0
a0081aa8:  7f ff fb b4  call  0xa0080978
a0081aac:  01 00 00 00  nop
a0081ab0:  10 bf fe f4  b  0xa0081680
a0081ab4:  80 a4 a0 04  cmp  %l2, 4
a0081ab8:  a0 0f 20 ff  and  %i4, 0xff, %l0
a0081abc:  80 a4 20 03  cmp  %l0, 3
a0081ac0:  08 bf fe 80  bleu  0xa00814c0
a0081ac4:  90 10 20 29  mov  0x29, %o0
a0081ac8:  82 04 7f d2  add  %l1, -46, %g1
a0081acc:  94 08 60 ff  and  %g1, 0xff, %o2
a0081ad0:  80 a2 a0 03  cmp  %o2, 3
a0081ad4:  38 bf fc 74  bgu,a   0xa0080ca4
a0081ad8:  ac 05 a0 01  inc  %l6
a0081adc:  40 00 21 aa  call  0xa008a184
a0081ae0:  90 10 20 32  mov  0x32, %o0
a0081ae4:  10 bf fc 70  b  0xa0080ca4
a0081ae8:  ac 05 a0 01  inc  %l6
a0081aec:  10 bf fd 1e  b  0xa0080f64
a0081af0:  a2 10 20 01  mov  1, %l1
a0081af4:  10 bf fd 1c  b  0xa0080f64
a0081af8:  a2 10 20 00  clr  %l1
a0081afc:  10 bf fd 1a  b  0xa0080f64
a0081b00:  a2 10 20 3e  mov  0x3e, %l1
a0081b04:  10 bf fd 18  b  0xa0080f64
a0081b08:  a2 10 20 02  mov  2, %l1
a0081b0c:  40 03 08 d9  call  0xa0143e70
a0081b10:  90 10 00 12  mov  %l2, %o0
a0081b14:  96 0a 20 ff  and  %o0, 0xff, %o3
a0081b18:  80 a2 e0 01  cmp  %o3, 1
a0081b1c:  02 bf fd 12  be  0xa0080f64
a0081b20:  a2 10 20 38  mov  0x38, %l1
a0081b24:  40 03 08 fa  call  0xa0143f0c
a0081b28:  90 10 00 12  mov  %l2, %o0
a0081b2c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0081b30:  80 a4 20 01  cmp  %l0, 1
a0081b34:  02 bf fd 0c  be  0xa0080f64
a0081b38:  a2 10 20 33  mov  0x33, %l1
a0081b3c:  40 03 08 76  call  0xa0143d14
a0081b40:  90 10 00 12  mov  %l2, %o0
a0081b44:  80 8a 20 ff  btst  0xff, %o0
a0081b48:  22 bf fd 07  be,a   0xa0080f64
a0081b4c:  a2 10 20 2e  mov  0x2e, %l1
a0081b50:  9e 14 e3 f4  or  %l3, 0x3f4, %o7
a0081b54:  a2 10 20 01  mov  1, %l1
a0081b58:  e6 0b e0 1c  ldub  [ %o7 + 0x1c ], %l3
a0081b5c:  93 2c 40 12  sll  %l1, %l2, %o1
a0081b60:  ae 12 40 13  or  %o1, %l3, %l7
a0081b64:  ee 2b e0 1c  stb  %l7, [ %o7 + 0x1c ]
a0081b68:  10 bf fc ff  b  0xa0080f64
a0081b6c:  a2 10 20 2e  mov  0x2e, %l1
a0081b70:  40 03 08 69  call  0xa0143d14
a0081b74:  90 10 00 12  mov  %l2, %o0
a0081b78:  80 8a 20 ff  btst  0xff, %o0
a0081b7c:  02 bf fc fa  be  0xa0080f64
a0081b80:  a2 10 20 25  mov  0x25, %l1
a0081b84:  94 14 e3 f4  or  %l3, 0x3f4, %o2
a0081b88:  aa 10 20 01  mov  1, %l5
a0081b8c:  d8 0a a0 1c  ldub  [ %o2 + 0x1c ], %o4
a0081b90:  9b 2d 40 12  sll  %l5, %l2, %o5
a0081b94:  90 13 40 0c  or  %o5, %o4, %o0
a0081b98:  10 bf fc f3  b  0xa0080f64
a0081b9c:  d0 2a a0 1c  stb  %o0, [ %o2 + 0x1c ]
a0081ba0:  40 03 08 5d  call  0xa0143d14
a0081ba4:  90 10 00 12  mov  %l2, %o0
a0081ba8:  80 8a 20 ff  btst  0xff, %o0
a0081bac:  22 bf fc ee  be,a   0xa0080f64
a0081bb0:  a2 10 20 1c  mov  0x1c, %l1
a0081bb4:  9e 14 e3 f4  or  %l3, 0x3f4, %o7
a0081bb8:  a2 10 20 01  mov  1, %l1
a0081bbc:  e6 0b e0 1c  ldub  [ %o7 + 0x1c ], %l3
a0081bc0:  93 2c 40 12  sll  %l1, %l2, %o1
a0081bc4:  ae 12 40 13  or  %o1, %l3, %l7
a0081bc8:  ee 2b e0 1c  stb  %l7, [ %o7 + 0x1c ]
a0081bcc:  10 bf fc e6  b  0xa0080f64
a0081bd0:  a2 10 20 1c  mov  0x1c, %l1
a0081bd4:  82 15 23 60  or  %l4, 0x360, %g1
a0081bd8:  f8 08 40 12  ldub  [ %g1 + %l2 ], %i4
a0081bdc:  80 a7 20 0a  cmp  %i4, 0xa
a0081be0:  22 bf fc e1  be,a   0xa0080f64
a0081be4:  a2 10 20 20  mov  0x20, %l1
a0081be8:  10 bf fc e0  b  0xa0080f68
a0081bec:  96 0c 60 ff  and  %l1, 0xff, %o3
a0081bf0:  40 03 08 49  call  0xa0143d14
a0081bf4:  90 10 00 12  mov  %l2, %o0
a0081bf8:  80 8a 20 ff  btst  0xff, %o0
a0081bfc:  02 bf fc da  be  0xa0080f64
a0081c00:  a2 10 20 18  mov  0x18, %l1
a0081c04:  90 14 e3 f4  or  %l3, 0x3f4, %o0
a0081c08:  a0 10 20 01  mov  1, %l0
a0081c0c:  d6 0a 20 1c  ldub  [ %o0 + 0x1c ], %o3
a0081c10:  ab 2c 00 12  sll  %l0, %l2, %l5
a0081c14:  9a 15 40 0b  or  %l5, %o3, %o5
a0081c18:  10 bf fc d3  b  0xa0080f64
a0081c1c:  da 2a 20 1c  stb  %o5, [ %o0 + 0x1c ]
a0081c20:  40 03 07 fd  call  0xa0143c14
a0081c24:  90 10 00 10  mov  %l0, %o0
a0081c28:  90 0a 20 ff  and  %o0, 0xff, %o0
a0081c2c:  80 a2 20 04  cmp  %o0, 4
a0081c30:  28 bf ff 66  bleu,a   0xa00819c8
a0081c34:  a2 04 60 01  inc  %l1
a0081c38:  40 03 08 b5  call  0xa0143f0c
a0081c3c:  90 10 00 10  mov  %l0, %o0
a0081c40:  80 8a 20 ff  btst  0xff, %o0
a0081c44:  32 bf ff 61  bne,a   0xa00819c8
a0081c48:  a2 04 60 01  inc  %l1
a0081c4c:  a6 10 20 00  clr  %l3
a0081c50:  80 8c e0 ff  btst  0xff, %l3
a0081c54:  02 bf fc 13  be  0xa0080ca0
a0081c58:  90 10 20 37  mov  0x37, %o0
a0081c5c:  40 00 21 4a  call  0xa008a184
a0081c60:  ac 05 a0 01  inc  %l6
a0081c64:  10 bf fc 11  b  0xa0080ca8
a0081c68:  a4 0d a0 ff  and  %l6, 0xff, %l2
a0081c6c:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0081c70:  e0 0a e3 45  ldub  [ %o3 + 0x345 ], %l0	! 0xa802af45
a0081c74:  9e 0c 3f f7  and  %l0, -9, %o7
a0081c78:  de 2a e3 45  stb  %o7, [ %o3 + 0x345 ]
a0081c7c:  10 bf ff 87  b  0xa0081a98
a0081c80:  98 03 20 03  add  %o4, 3, %o4
a0081c84:  e8 0c a0 1f  ldub  [ %l2 + 0x1f ], %l4
a0081c88:  aa 05 3f fc  add  %l4, -4, %l5
a0081c8c:  ae 0d 60 ff  and  %l5, 0xff, %l7
a0081c90:  80 a5 e0 03  cmp  %l7, 3
a0081c94:  18 bf fe b3  bgu  0xa0081760
a0081c98:  80 8b 60 ff  btst  0xff, %o5
a0081c9c:  10 bf fe bc  b  0xa008178c
a0081ca0:  9a 10 20 01  mov  1, %o5
a0081ca4:  29 2a 00 ab  sethi  %hi(0xa802ac00), %l4
a0081ca8:  aa 10 3f ff  mov  -1, %l5
a0081cac:  90 15 23 60  or  %l4, 0x360, %o0
a0081cb0:  ea 2a 20 03  stb  %l5, [ %o0 + 3 ]
a0081cb4:  ea 2d 23 60  stb  %l5, [ %l4 + 0x360 ]
a0081cb8:  ea 2a 20 01  stb  %l5, [ %o0 + 1 ]
a0081cbc:  10 bf fc 66  b  0xa0080e54
a0081cc0:  ea 2a 20 02  stb  %l5, [ %o0 + 2 ]
a0081cc4:  10 bf fc d9  b  0xa0081028
a0081cc8:  96 0c 60 ff  and  %l1, 0xff, %o3
a0081ccc:  80 a3 e0 07  cmp  %o7, 7
a0081cd0:  12 bf fd 60  bne  0xa0081250
a0081cd4:  80 8b 60 ff  btst  0xff, %o5
a0081cd8:  10 bf fd 69  b  0xa008127c
a0081cdc:  9a 10 20 01  mov  1, %o5
a0081ce0:  02 80 00 3c  be  0xa0081dd0
a0081ce4:  d2 0d e3 45  ldub  [ %l7 + 0x345 ], %o1
a0081ce8:  80 a4 20 02  cmp  %l0, 2
a0081cec:  02 80 00 3b  be  0xa0081dd8
a0081cf0:  f8 0d e3 45  ldub  [ %l7 + 0x345 ], %i4
a0081cf4:  80 a4 20 03  cmp  %l0, 3
a0081cf8:  12 bf fd 7e  bne  0xa00812f0
a0081cfc:  82 10 20 00  clr  %g1
a0081d00:  d4 0d e3 45  ldub  [ %l7 + 0x345 ], %o2
a0081d04:  10 bf fd 78  b  0xa00812e4
a0081d08:  80 8a a0 08  btst  8, %o2
a0081d0c:  23 2a 00 ab  sethi  %hi(0xa802ac00), %l1
a0081d10:  c0 2c 63 45  clrb  [ %l1 + 0x345 ]	! 0xa802af45
a0081d14:  10 bf fc db  b  0xa0081080
a0081d18:  82 0b 20 ff  and  %o4, 0xff, %g1
a0081d1c:  80 a6 e0 07  cmp  %i3, 7
a0081d20:  12 bf fe 90  bne  0xa0081760
a0081d24:  80 8b 60 ff  btst  0xff, %o5
a0081d28:  10 bf fe 99  b  0xa008178c
a0081d2c:  9a 10 20 01  mov  1, %o5
a0081d30:  40 00 21 15  call  0xa008a184
a0081d34:  90 10 20 3d  mov  0x3d, %o0
a0081d38:  30 bf fb cb  b,a   0xa0080c64
a0081d3c:  d6 0c a0 1f  ldub  [ %l2 + 0x1f ], %o3
a0081d40:  80 a2 e0 00  cmp  %o3, 0
a0081d44:  32 bf ff 1d  bne,a   0xa00819b8
a0081d48:  9a 10 20 01  mov  1, %o5
a0081d4c:  10 bf ff 1c  b  0xa00819bc
a0081d50:  80 8b 60 ff  btst  0xff, %o5
a0081d54:  10 bf fc c2  b  0xa008105c
a0081d58:  82 0d 77 bd  and  %l5, -2115, %g1
a0081d5c:  40 03 08 a5  call  0xa0143ff0
a0081d60:  90 10 00 12  mov  %l2, %o0
a0081d64:  10 bf fe c3  b  0xa0081870
a0081d68:  90 0a 20 ff  and  %o0, 0xff, %o0
a0081d6c:  de 0c a0 1f  ldub  [ %l2 + 0x1f ], %o7
a0081d70:  98 03 ff fc  add  %o7, -4, %o4
a0081d74:  ba 0b 20 ff  and  %o4, 0xff, %i5
a0081d78:  80 a7 60 03  cmp  %i5, 3
a0081d7c:  28 bf ff 0f  bleu,a   0xa00819b8
a0081d80:  9a 10 20 01  mov  1, %o5
a0081d84:  10 bf ff 0e  b  0xa00819bc
a0081d88:  80 8b 60 ff  btst  0xff, %o5
a0081d8c:  40 02 97 0e  call  0xa01279c4
a0081d90:  01 00 00 00  nop
a0081d94:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0081d98:  80 a3 60 02  cmp  %o5, 2
a0081d9c:  22 bf fe 39  be,a   0xa0081680
a0081da0:  80 a4 a0 04  cmp  %l2, 4
a0081da4:  40 02 8b 67  call  0xa0124b40
a0081da8:  01 00 00 00  nop
a0081dac:  40 02 8b 2f  call  0xa0124a68
a0081db0:  01 00 00 00  nop
a0081db4:  10 bf fe 33  b  0xa0081680
a0081db8:  80 a4 a0 04  cmp  %l2, 4
a0081dbc:  80 a2 60 07  cmp  %o1, 7
a0081dc0:  22 bf fe fe  be,a   0xa00819b8
a0081dc4:  9a 10 20 01  mov  1, %o5
a0081dc8:  10 bf fe fd  b  0xa00819bc
a0081dcc:  80 8b 60 ff  btst  0xff, %o5
a0081dd0:  10 bf fd 45  b  0xa00812e4
a0081dd4:  80 8a 60 02  btst  2, %o1
a0081dd8:  10 bf fd 43  b  0xa00812e4
a0081ddc:  80 8f 20 04  btst  4, %i4
a0081de0:  40 03 08 84  call  0xa0143ff0
a0081de4:  90 10 00 12  mov  %l2, %o0
a0081de8:  10 bf fc 5a  b  0xa0080f50
a0081dec:  90 0a 20 ff  and  %o0, 0xff, %o0
a0081df0:  40 03 08 c9  call  0xa0144114
a0081df4:  01 00 00 00  nop
a0081df8:  a6 0a 20 ff  and  %o0, 0xff, %l3
a0081dfc:  10 bf fe cc  b  0xa008192c
a0081e00:  80 a0 00 13  cmp  %g0, %l3
a0081e04:  81 c7 e0 08  ret
a0081e08:  81 e8 00 00  restore
