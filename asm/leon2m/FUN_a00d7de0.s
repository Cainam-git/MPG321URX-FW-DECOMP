# leon2m FUN_a00d7de0 0xa00d7de0-0xa00d8034 (596 bytes)
a00d7de0:  9d e3 bf 98  save  %sp, -104, %sp
a00d7de4:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00d7de8:  9a 16 22 90  or  %i0, 0x290, %o5	! 0xa802d290
a00d7dec:  c2 0b 60 0a  ldub  [ %o5 + 0xa ], %g1
a00d7df0:  80 a0 60 64  cmp  %g1, 0x64
a00d7df4:  38 80 00 02  bgu,a   0xa00d7dfc
a00d7df8:  82 10 20 64  mov  0x64, %g1
a00d7dfc:  c2 2b 60 0a  stb  %g1, [ %o5 + 0xa ]
a00d7e00:  90 10 20 00  clr  %o0
a00d7e04:  40 01 b8 39  call  0xa0145ee8
a00d7e08:  92 10 20 00  clr  %o1
a00d7e0c:  40 01 cf d9  call  0xa014bd70
a00d7e10:  90 10 20 00  clr  %o0
a00d7e14:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d7e18:  80 a2 20 01  cmp  %o0, 1
a00d7e1c:  02 80 00 38  be  0xa00d7efc
a00d7e20:  98 16 22 90  or  %i0, 0x290, %o4
a00d7e24:  40 01 ae ae  call  0xa01438dc
a00d7e28:  90 10 20 00  clr  %o0
a00d7e2c:  82 0a 20 ff  and  %o0, 0xff, %g1
a00d7e30:  80 a0 60 01  cmp  %g1, 1
a00d7e34:  02 80 00 24  be  0xa00d7ec4
a00d7e38:  90 16 22 90  or  %i0, 0x290, %o0
a00d7e3c:  d2 0a 21 81  ldub  [ %o0 + 0x181 ], %o1
a00d7e40:  82 02 7f fc  add  %o1, -4, %g1
a00d7e44:  98 08 60 ff  and  %g1, 0xff, %o4
a00d7e48:  80 a3 20 02  cmp  %o4, 2
a00d7e4c:  38 80 00 07  bgu,a   0xa00d7e68
a00d7e50:  d6 0a 21 78  ldub  [ %o0 + 0x178 ], %o3
a00d7e54:  d4 02 20 a8  ld  [ %o0 + 0xa8 ], %o2
a00d7e58:  80 8a a8 00  btst  0x800, %o2
a00d7e5c:  12 80 00 74  bne  0xa00d802c
a00d7e60:  01 00 00 00  nop
a00d7e64:  d6 0a 21 78  ldub  [ %o0 + 0x178 ], %o3
a00d7e68:  80 a2 e0 01  cmp  %o3, 1
a00d7e6c:  02 80 00 64  be  0xa00d7ffc
a00d7e70:  1f 00 06 61  sethi  %hi(0x198400), %o7
a00d7e74:  d0 0a 20 0a  ldub  [ %o0 + 0xa ], %o0
a00d7e78:  80 a2 20 46  cmp  %o0, 0x46
a00d7e7c:  18 80 00 50  bgu  0xa00d7fbc
a00d7e80:  01 00 00 00  nop
a00d7e84:  40 01 f7 6f  call  0xa0155c40
a00d7e88:  01 00 00 00  nop
a00d7e8c:  17 00 06 61  sethi  %hi(0x198400), %o3
a00d7e90:  40 01 f6 68  call  0xa0155830
a00d7e94:  d2 02 e3 54  ld  [ %o3 + 0x354 ], %o1	! 0x198754
a00d7e98:  15 00 06 61  sethi  %hi(0x198400), %o2
a00d7e9c:  40 01 f6 df  call  0xa0155a18
a00d7ea0:  d2 02 a3 58  ld  [ %o2 + 0x358 ], %o1	! 0x198758
a00d7ea4:  03 00 06 61  sethi  %hi(0x198400), %g1
a00d7ea8:  40 01 f6 39  call  0xa015578c
a00d7eac:  d2 00 63 5c  ld  [ %g1 + 0x35c ], %o1	! 0x19875c
a00d7eb0:  40 01 f4 c3  call  0xa01551bc
a00d7eb4:  01 00 00 00  nop
a00d7eb8:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00d7ebc:  40 01 cf 8d  call  0xa014bcf0
a00d7ec0:  81 e8 00 00  restore
a00d7ec4:  40 01 ce e9  call  0xa014ba68
a00d7ec8:  01 00 00 00  nop
a00d7ecc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d7ed0:  80 a2 20 02  cmp  %o0, 2
a00d7ed4:  02 80 00 0a  be  0xa00d7efc
a00d7ed8:  98 16 22 90  or  %i0, 0x290, %o4
a00d7edc:  04 80 00 50  ble  0xa00d801c
a00d7ee0:  80 a2 20 01  cmp  %o0, 1
a00d7ee4:  80 a2 20 03  cmp  %o0, 3
a00d7ee8:  02 80 00 05  be  0xa00d7efc
a00d7eec:  80 a2 20 04  cmp  %o0, 4
a00d7ef0:  32 bf ff d3  bne,a   0xa00d7e3c
a00d7ef4:  90 16 22 90  or  %i0, 0x290, %o0
a00d7ef8:  98 16 22 90  or  %i0, 0x290, %o4
a00d7efc:  d6 0b 21 81  ldub  [ %o4 + 0x181 ], %o3
a00d7f00:  94 02 ff fc  add  %o3, -4, %o2
a00d7f04:  92 0a a0 ff  and  %o2, 0xff, %o1
a00d7f08:  80 a2 60 02  cmp  %o1, 2
a00d7f0c:  18 80 00 06  bgu  0xa00d7f24
a00d7f10:  21 00 06 61  sethi  %hi(0x198400), %l0
a00d7f14:  da 03 20 a8  ld  [ %o4 + 0xa8 ], %o5
a00d7f18:  80 8b 68 00  btst  0x800, %o5
a00d7f1c:  12 80 00 44  bne  0xa00d802c
a00d7f20:  01 00 00 00  nop
a00d7f24:  de 0c 21 2e  ldub  [ %l0 + 0x12e ], %o7
a00d7f28:  e0 0b 20 0a  ldub  [ %o4 + 0xa ], %l0
a00d7f2c:  90 10 00 0f  mov  %o7, %o0
a00d7f30:  80 a3 e0 46  cmp  %o7, 0x46
a00d7f34:  18 80 00 16  bgu  0xa00d7f8c
a00d7f38:  de 2b 20 0a  stb  %o7, [ %o4 + 0xa ]
a00d7f3c:  40 01 f7 41  call  0xa0155c40
a00d7f40:  01 00 00 00  nop
a00d7f44:  1f 00 06 61  sethi  %hi(0x198400), %o7
a00d7f48:  d2 03 e3 54  ld  [ %o7 + 0x354 ], %o1	! 0x198754
a00d7f4c:  40 01 f6 39  call  0xa0155830
a00d7f50:  01 00 00 00  nop
a00d7f54:  1b 00 06 61  sethi  %hi(0x198400), %o5
a00d7f58:  40 01 f6 b0  call  0xa0155a18
a00d7f5c:  d2 03 63 58  ld  [ %o5 + 0x358 ], %o1	! 0x198758
a00d7f60:  17 00 06 61  sethi  %hi(0x198400), %o3
a00d7f64:  d2 02 e3 5c  ld  [ %o3 + 0x35c ], %o1	! 0x19875c
a00d7f68:  40 01 f6 09  call  0xa015578c
a00d7f6c:  01 00 00 00  nop
a00d7f70:  40 01 f4 93  call  0xa01551bc
a00d7f74:  01 00 00 00  nop
a00d7f78:  40 01 cf 5e  call  0xa014bcf0
a00d7f7c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d7f80:  90 16 22 90  or  %i0, 0x290, %o0
a00d7f84:  10 80 00 2a  b  0xa00d802c
a00d7f88:  e0 2a 20 0a  stb  %l0, [ %o0 + 0xa ]
a00d7f8c:  90 03 ff ba  add  %o7, -70, %o0
a00d7f90:  40 01 f7 2c  call  0xa0155c40
a00d7f94:  01 00 00 00  nop
a00d7f98:  15 00 06 61  sethi  %hi(0x198400), %o2
a00d7f9c:  40 01 f6 25  call  0xa0155830
a00d7fa0:  d2 02 a3 48  ld  [ %o2 + 0x348 ], %o1	! 0x198748
a00d7fa4:  03 00 06 61  sethi  %hi(0x198400), %g1
a00d7fa8:  40 01 f6 9c  call  0xa0155a18
a00d7fac:  d2 00 63 4c  ld  [ %g1 + 0x34c ], %o1	! 0x19874c
a00d7fb0:  19 00 06 61  sethi  %hi(0x198400), %o4
a00d7fb4:  10 bf ff ed  b  0xa00d7f68
a00d7fb8:  d2 03 23 50  ld  [ %o4 + 0x350 ], %o1	! 0x198750
a00d7fbc:  40 01 f7 21  call  0xa0155c40
a00d7fc0:  90 02 3f ba  add  %o0, -70, %o0
a00d7fc4:  19 00 06 61  sethi  %hi(0x198400), %o4
a00d7fc8:  40 01 f6 1a  call  0xa0155830
a00d7fcc:  d2 03 23 48  ld  [ %o4 + 0x348 ], %o1	! 0x198748
a00d7fd0:  21 00 06 61  sethi  %hi(0x198400), %l0
a00d7fd4:  40 01 f6 91  call  0xa0155a18
a00d7fd8:  d2 04 23 4c  ld  [ %l0 + 0x34c ], %o1	! 0x19874c
a00d7fdc:  31 00 06 61  sethi  %hi(0x198400), %i0
a00d7fe0:  40 01 f5 eb  call  0xa015578c
a00d7fe4:  d2 06 23 50  ld  [ %i0 + 0x350 ], %o1	! 0x198750
a00d7fe8:  40 01 f4 75  call  0xa01551bc
a00d7fec:  01 00 00 00  nop
a00d7ff0:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00d7ff4:  40 01 cf 3f  call  0xa014bcf0
a00d7ff8:  81 e8 00 00  restore
a00d7ffc:  da 0b e1 2e  ldub  [ %o7 + 0x12e ], %o5
a00d8000:  e0 0a 20 0a  ldub  [ %o0 + 0xa ], %l0
a00d8004:  da 2a 20 0a  stb  %o5, [ %o0 + 0xa ]
a00d8008:  80 a3 60 46  cmp  %o5, 0x46
a00d800c:  08 bf ff cc  bleu  0xa00d7f3c
a00d8010:  90 10 00 0d  mov  %o5, %o0
a00d8014:  10 bf ff df  b  0xa00d7f90
a00d8018:  90 03 7f ba  add  %o5, -70, %o0
a00d801c:  32 bf ff 88  bne,a   0xa00d7e3c
a00d8020:  90 16 22 90  or  %i0, 0x290, %o0
a00d8024:  10 bf ff b6  b  0xa00d7efc
a00d8028:  98 16 22 90  or  %i0, 0x290, %o4
a00d802c:  81 c7 e0 08  ret
a00d8030:  81 e8 00 00  restore
