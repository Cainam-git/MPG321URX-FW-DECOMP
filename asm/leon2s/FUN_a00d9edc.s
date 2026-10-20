# leon2s FUN_a00d9edc 0xa00d9edc-0xa00da030 (340 bytes)
a00d9edc:  9d e3 bf 80  save  %sp, -128, %sp
a00d9ee0:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00d9ee4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d9ee8:  d8 0c e0 32  ldub  [ %l3 + 0x32 ], %o4
a00d9eec:  82 10 60 00  mov  %g1, %g1
a00d9ef0:  d6 08 40 0c  ldub  [ %g1 + %o4 ], %o3
a00d9ef4:  82 02 c0 0b  add  %o3, %o3, %g1
a00d9ef8:  82 00 40 0b  add  %g1, %o3, %g1
a00d9efc:  83 28 60 02  sll  %g1, 2, %g1
a00d9f00:  82 20 40 0b  sub  %g1, %o3, %g1
a00d9f04:  9a 5b 20 b0  smul  %o4, 0xb0, %o5
a00d9f08:  9a 03 40 01  add  %o5, %g1, %o5
a00d9f0c:  03 2a 01 e8  sethi  %hi(0xa807a000), %g1
a00d9f10:  82 10 63 98  or  %g1, 0x398, %g1	! 0xa807a398
a00d9f14:  a4 03 40 01  add  %o5, %g1, %l2
a00d9f18:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00d9f1c:  82 10 60 62  or  %g1, 0x62, %g1	! 0xa8079c62
a00d9f20:  99 2b 20 04  sll  %o4, 4, %o4
a00d9f24:  98 03 00 01  add  %o4, %g1, %o4
a00d9f28:  a0 07 bf e0  add  %fp, -32, %l0
a00d9f2c:  e2 0b 00 0b  ldub  [ %o4 + %o3 ], %l1
a00d9f30:  90 10 00 10  mov  %l0, %o0
a00d9f34:  7f ff f1 fc  call  0xa00d6724
a00d9f38:  92 10 00 12  mov  %l2, %o1
a00d9f3c:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a00d9f40:  b4 0e a0 3f  and  %i2, 0x3f, %i2
a00d9f44:  19 00 0f c0  sethi  %hi(0x3f0000), %o4
a00d9f48:  98 28 40 0c  andn  %g1, %o4, %o4
a00d9f4c:  b5 2e a0 10  sll  %i2, 0x10, %i2
a00d9f50:  98 13 00 1a  or  %o4, %i2, %o4
a00d9f54:  b0 0e 20 01  and  %i0, 1, %i0
a00d9f58:  1b 00 00 20  sethi  %hi(0x8000), %o5
a00d9f5c:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00d9f60:  b1 2e 20 0f  sll  %i0, 0xf, %i0
a00d9f64:  9a 13 40 18  or  %o5, %i0, %o5
a00d9f68:  b2 0e 60 01  and  %i1, 1, %i1
a00d9f6c:  03 00 00 10  sethi  %hi(0x4000), %g1
a00d9f70:  82 2b 40 01  andn  %o5, %g1, %g1
a00d9f74:  b3 2e 60 0e  sll  %i1, 0xe, %i1
a00d9f78:  82 10 40 19  or  %g1, %i1, %g1
a00d9f7c:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a00d9f80:  90 10 00 10  mov  %l0, %o0
a00d9f84:  7f ff f2 52  call  0xa00d68cc
a00d9f88:  92 10 00 12  mov  %l2, %o1
a00d9f8c:  80 a4 60 00  cmp  %l1, 0
a00d9f90:  12 80 00 14  bne  0xa00d9fe0
a00d9f94:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d9f98:  80 a4 40 08  cmp  %l1, %o0
a00d9f9c:  1a 80 00 23  bcc  0xa00da028
a00d9fa0:  94 10 20 00  clr  %o2
a00d9fa4:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d9fa8:  92 10 60 9c  or  %g1, 0x9c, %o1	! 0xa807609c
a00d9fac:  c2 0c e0 32  ldub  [ %l3 + 0x32 ], %g1
a00d9fb0:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00d9fb4:  83 28 60 02  sll  %g1, 2, %g1
a00d9fb8:  d6 02 40 01  ld  [ %o1 + %g1 ], %o3
a00d9fbc:  d8 0c 80 0d  ldub  [ %l2 + %o5 ], %o4
a00d9fc0:  94 02 a0 01  inc  %o2
a00d9fc4:  9b 2b 60 02  sll  %o5, 2, %o5
a00d9fc8:  82 0a a0 ff  and  %o2, 0xff, %g1
a00d9fcc:  d8 22 c0 0d  st  %o4, [ %o3 + %o5 ]
a00d9fd0:  80 a0 40 08  cmp  %g1, %o0
a00d9fd4:  0a bf ff f7  bcs  0xa00d9fb0
a00d9fd8:  c2 0c e0 32  ldub  [ %l3 + 0x32 ], %g1
a00d9fdc:  30 80 00 13  b,a   0xa00da028
a00d9fe0:  80 a2 20 00  cmp  %o0, 0
a00d9fe4:  02 80 00 11  be  0xa00da028
a00d9fe8:  94 10 20 00  clr  %o2
a00d9fec:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00d9ff0:  96 10 60 9c  or  %g1, 0x9c, %o3	! 0xa807609c
a00d9ff4:  c2 0c e0 32  ldub  [ %l3 + 0x32 ], %g1
a00d9ff8:  83 28 60 02  sll  %g1, 2, %g1
a00d9ffc:  98 0a a0 ff  and  %o2, 0xff, %o4
a00da000:  da 02 c0 01  ld  [ %o3 + %g1 ], %o5
a00da004:  83 2b 20 02  sll  %o4, 2, %g1
a00da008:  82 00 40 0d  add  %g1, %o5, %g1
a00da00c:  da 0c 80 0c  ldub  [ %l2 + %o4 ], %o5
a00da010:  94 02 a0 01  inc  %o2
a00da014:  98 0a a0 ff  and  %o2, 0xff, %o4
a00da018:  da 20 60 c0  st  %o5, [ %g1 + 0xc0 ]
a00da01c:  80 a3 00 08  cmp  %o4, %o0
a00da020:  0a bf ff f6  bcs  0xa00d9ff8
a00da024:  c2 0c e0 32  ldub  [ %l3 + 0x32 ], %g1
a00da028:  81 c7 e0 08  ret
a00da02c:  81 e8 00 00  restore
