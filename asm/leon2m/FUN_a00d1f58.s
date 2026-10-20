# leon2m FUN_a00d1f58 0xa00d1f58-0xa00d20a4 (332 bytes)
a00d1f58:  9d e3 bf 98  save  %sp, -104, %sp
a00d1f5c:  c2 0e 20 06  ldub  [ %i0 + 6 ], %g1
a00d1f60:  80 a0 60 01  cmp  %g1, 1
a00d1f64:  02 80 00 29  be  0xa00d2008
a00d1f68:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00d1f6c:  04 80 00 06  ble  0xa00d1f84
a00d1f70:  80 a0 60 02  cmp  %g1, 2
a00d1f74:  02 80 00 15  be  0xa00d1fc8
a00d1f78:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00d1f7c:  10 80 00 48  b  0xa00d209c
a00d1f80:  b0 10 20 e3  mov  0xe3, %i0
a00d1f84:  80 a0 60 00  cmp  %g1, 0
a00d1f88:  32 80 00 45  bne,a   0xa00d209c
a00d1f8c:  b0 10 20 e3  mov  0xe3, %i0
a00d1f90:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d1f94:  c2 08 62 a1  ldub  [ %g1 + 0x2a1 ], %g1	! 0xa802d2a1
a00d1f98:  80 a0 60 02  cmp  %g1, 2
a00d1f9c:  02 80 00 38  be  0xa00d207c
a00d1fa0:  80 a0 60 01  cmp  %g1, 1
a00d1fa4:  02 80 00 3a  be  0xa00d208c
a00d1fa8:  80 a0 60 00  cmp  %g1, 0
a00d1fac:  12 80 00 04  bne  0xa00d1fbc
a00d1fb0:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a00d1fb4:  d8 0e 20 07  ldub  [ %i0 + 7 ], %o4
a00d1fb8:  d8 2a e2 02  stb  %o4, [ %o3 + 0x202 ]
a00d1fbc:  40 01 a5 1c  call  0xa013b42c
a00d1fc0:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a00d1fc4:  30 80 00 0d  b,a   0xa00d1ff8
a00d1fc8:  c2 0b 22 a1  ldub  [ %o4 + 0x2a1 ], %g1
a00d1fcc:  80 a0 60 02  cmp  %g1, 2
a00d1fd0:  02 80 00 1f  be  0xa00d204c
a00d1fd4:  80 a0 60 01  cmp  %g1, 1
a00d1fd8:  02 80 00 25  be  0xa00d206c
a00d1fdc:  80 a0 60 00  cmp  %g1, 0
a00d1fe0:  12 80 00 04  bne  0xa00d1ff0
a00d1fe4:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a00d1fe8:  da 0e 20 07  ldub  [ %i0 + 7 ], %o5
a00d1fec:  da 2a a2 04  stb  %o5, [ %o2 + 0x204 ]
a00d1ff0:  40 01 a5 1f  call  0xa013b46c
a00d1ff4:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a00d1ff8:  40 01 cc da  call  0xa0145360
a00d1ffc:  90 10 20 00  clr  %o0
a00d2000:  10 80 00 27  b  0xa00d209c
a00d2004:  b0 10 20 e0  mov  0xe0, %i0
a00d2008:  c2 0b e2 a1  ldub  [ %o7 + 0x2a1 ], %g1
a00d200c:  80 a0 60 02  cmp  %g1, 2
a00d2010:  02 80 00 0b  be  0xa00d203c
a00d2014:  80 a0 60 01  cmp  %g1, 1
a00d2018:  02 80 00 11  be  0xa00d205c
a00d201c:  80 a0 60 00  cmp  %g1, 0
a00d2020:  12 80 00 04  bne  0xa00d2030
a00d2024:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a00d2028:  d6 0e 20 07  ldub  [ %i0 + 7 ], %o3
a00d202c:  d6 2a a2 03  stb  %o3, [ %o2 + 0x203 ]
a00d2030:  40 01 a5 07  call  0xa013b44c
a00d2034:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a00d2038:  30 bf ff f0  b,a   0xa00d1ff8
a00d203c:  d0 0e 20 07  ldub  [ %i0 + 7 ], %o0
a00d2040:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a00d2044:  10 bf ff fb  b  0xa00d2030
a00d2048:  d0 28 61 f7  stb  %o0, [ %g1 + 0x1f7 ]	! 0xa802e1f7
a00d204c:  c2 0e 20 07  ldub  [ %i0 + 7 ], %g1
a00d2050:  1f 2a 00 b8  sethi  %hi(0xa802e000), %o7
a00d2054:  10 bf ff e7  b  0xa00d1ff0
a00d2058:  c2 2b e1 f8  stb  %g1, [ %o7 + 0x1f8 ]	! 0xa802e1f8
a00d205c:  da 0e 20 07  ldub  [ %i0 + 7 ], %o5
a00d2060:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a00d2064:  10 bf ff f3  b  0xa00d2030
a00d2068:  da 2a 61 fa  stb  %o5, [ %o1 + 0x1fa ]	! 0xa802e1fa
a00d206c:  d2 0e 20 07  ldub  [ %i0 + 7 ], %o1
a00d2070:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a00d2074:  10 bf ff df  b  0xa00d1ff0
a00d2078:  d2 2a 21 fb  stb  %o1, [ %o0 + 0x1fb ]	! 0xa802e1fb
a00d207c:  da 0e 20 07  ldub  [ %i0 + 7 ], %o5
a00d2080:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a00d2084:  10 bf ff ce  b  0xa00d1fbc
a00d2088:  da 2a 21 f6  stb  %o5, [ %o0 + 0x1f6 ]	! 0xa802e1f6
a00d208c:  d4 0e 20 07  ldub  [ %i0 + 7 ], %o2
a00d2090:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a00d2094:  10 bf ff ca  b  0xa00d1fbc
a00d2098:  d4 2a 61 f9  stb  %o2, [ %o1 + 0x1f9 ]	! 0xa802e1f9
a00d209c:  81 c7 e0 08  ret
a00d20a0:  81 e8 00 00  restore
