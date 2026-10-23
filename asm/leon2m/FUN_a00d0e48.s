# leon2m FUN_a00d0e48 0xa00d0e48-0xa00d0f68 (288 bytes)
a00d0e48:  94 0a a0 ff  and  %o2, 0xff, %o2
a00d0e4c:  82 10 20 6e  mov  0x6e, %g1
a00d0e50:  80 a2 a0 00  cmp  %o2, 0
a00d0e54:  12 80 00 07  bne  0xa00d0e70
a00d0e58:  c2 2a 40 00  stb  %g1, [ %o1 ]
a00d0e5c:  94 10 3f 86  mov  -122, %o2
a00d0e60:  9a 10 3f c0  mov  -64, %o5
a00d0e64:  d4 2a 60 01  stb  %o2, [ %o1 + 1 ]
a00d0e68:  10 80 00 37  b  0xa00d0f44
a00d0e6c:  da 2a 60 02  stb  %o5, [ %o1 + 2 ]
a00d0e70:  80 a2 a0 01  cmp  %o2, 1
a00d0e74:  12 80 00 35  bne  0xa00d0f48
a00d0e78:  d6 0a 20 03  ldub  [ %o0 + 3 ], %o3
a00d0e7c:  94 1a e0 63  xor  %o3, 0x63, %o2
a00d0e80:  80 a0 00 0a  cmp  %g0, %o2
a00d0e84:  98 60 3f ff  subx  %g0, -1, %o4
a00d0e88:  9a 1a e0 31  xor  %o3, 0x31, %o5
a00d0e8c:  80 a0 00 0d  cmp  %g0, %o5
a00d0e90:  82 60 3f ff  subx  %g0, -1, %g1
a00d0e94:  80 93 00 01  orcc  %o4, %g1, %g0
a00d0e98:  32 80 00 25  bne,a   0xa00d0f2c
a00d0e9c:  82 10 3f 86  mov  -122, %g1
a00d0ea0:  80 a2 e0 32  cmp  %o3, 0x32
a00d0ea4:  02 80 00 21  be  0xa00d0f28
a00d0ea8:  80 a2 e0 27  cmp  %o3, 0x27
a00d0eac:  02 80 00 1f  be  0xa00d0f28
a00d0eb0:  80 a2 e0 28  cmp  %o3, 0x28
a00d0eb4:  02 80 00 1d  be  0xa00d0f28
a00d0eb8:  80 a2 e0 35  cmp  %o3, 0x35
a00d0ebc:  02 80 00 1b  be  0xa00d0f28
a00d0ec0:  80 a2 e0 36  cmp  %o3, 0x36
a00d0ec4:  02 80 00 19  be  0xa00d0f28
a00d0ec8:  80 a2 e0 39  cmp  %o3, 0x39
a00d0ecc:  02 80 00 17  be  0xa00d0f28
a00d0ed0:  80 a2 e0 3a  cmp  %o3, 0x3a
a00d0ed4:  02 80 00 15  be  0xa00d0f28
a00d0ed8:  94 1a e0 34  xor  %o3, 0x34, %o2
a00d0edc:  80 a0 00 0a  cmp  %g0, %o2
a00d0ee0:  98 60 3f ff  subx  %g0, -1, %o4
a00d0ee4:  9a 1a e0 30  xor  %o3, 0x30, %o5
a00d0ee8:  80 a0 00 0d  cmp  %g0, %o5
a00d0eec:  82 60 3f ff  subx  %g0, -1, %g1
a00d0ef0:  80 93 00 01  orcc  %o4, %g1, %g0
a00d0ef4:  32 80 00 0e  bne,a   0xa00d0f2c
a00d0ef8:  82 10 3f 93  mov  -109, %g1
a00d0efc:  80 a2 e0 38  cmp  %o3, 0x38
a00d0f00:  02 80 00 0f  be  0xa00d0f3c
a00d0f04:  80 a2 e0 3c  cmp  %o3, 0x3c
a00d0f08:  02 80 00 09  be  0xa00d0f2c
a00d0f0c:  82 10 3f 93  mov  -109, %g1
a00d0f10:  d6 0a 20 06  ldub  [ %o0 + 6 ], %o3
a00d0f14:  80 a2 e0 40  cmp  %o3, 0x40
a00d0f18:  22 80 00 05  be,a   0xa00d0f2c
a00d0f1c:  82 10 3f c5  mov  -59, %g1
a00d0f20:  10 80 00 03  b  0xa00d0f2c
a00d0f24:  82 10 3f 95  mov  -107, %g1
a00d0f28:  82 10 3f 86  mov  -122, %g1
a00d0f2c:  c2 2a 60 01  stb  %g1, [ %o1 + 1 ]
a00d0f30:  82 10 3f d0  mov  -48, %g1
a00d0f34:  10 80 00 04  b  0xa00d0f44
a00d0f38:  c2 2a 60 02  stb  %g1, [ %o1 + 2 ]
a00d0f3c:  10 bf ff fc  b  0xa00d0f2c
a00d0f40:  82 10 3f 93  mov  -109, %g1
a00d0f44:  d6 0a 20 03  ldub  [ %o0 + 3 ], %o3
a00d0f48:  d6 2a 60 03  stb  %o3, [ %o1 + 3 ]
a00d0f4c:  d4 0a 20 04  ldub  [ %o0 + 4 ], %o2
a00d0f50:  d4 2a 60 04  stb  %o2, [ %o1 + 4 ]
a00d0f54:  da 0a 20 05  ldub  [ %o0 + 5 ], %o5
a00d0f58:  da 2a 60 05  stb  %o5, [ %o1 + 5 ]
a00d0f5c:  d8 0a 20 06  ldub  [ %o0 + 6 ], %o4
a00d0f60:  81 c3 e0 08  retl
a00d0f64:  d8 2a 60 06  stb  %o4, [ %o1 + 6 ]
