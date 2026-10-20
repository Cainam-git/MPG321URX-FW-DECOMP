# leon2s FUN_a00c9e44 0xa00c9e44-0xa00ca074 (560 bytes)
a00c9e44:  9d e3 bf 98  save  %sp, -104, %sp
a00c9e48:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c9e4c:  90 10 00 18  mov  %i0, %o0
a00c9e50:  92 10 20 00  clr  %o1
a00c9e54:  94 10 20 02  mov  2, %o2
a00c9e58:  40 3b b8 31  call  0xa0fb7f1c
a00c9e5c:  96 10 20 01  mov  1, %o3
a00c9e60:  90 10 00 18  mov  %i0, %o0
a00c9e64:  92 10 20 00  clr  %o1
a00c9e68:  94 10 20 02  mov  2, %o2
a00c9e6c:  40 3b b8 2c  call  0xa0fb7f1c
a00c9e70:  96 10 20 00  clr  %o3
a00c9e74:  37 2a 01 f5  sethi  %hi(0xa807d400), %i3
a00c9e78:  c2 0e e2 2c  ldub  [ %i3 + 0x22c ], %g1	! 0xa807d62c
a00c9e7c:  80 a0 60 00  cmp  %g1, 0
a00c9e80:  02 80 00 05  be  0xa00c9e94
a00c9e84:  9a 10 20 03  mov  3, %o5
a00c9e88:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00c9e8c:  10 80 00 07  b  0xa00c9ea8
a00c9e90:  da 28 60 87  stb  %o5, [ %g1 + 0x87 ]	! 0xa807d087
a00c9e94:  15 2a 01 f4  sethi  %hi(0xa807d000), %o2
a00c9e98:  94 12 a0 87  or  %o2, 0x87, %o2	! 0xa807d087
a00c9e9c:  90 10 27 34  mov  0x734, %o0
a00c9ea0:  40 3b 4d 10  call  0xa0f9d2e0
a00c9ea4:  92 10 20 01  mov  1, %o1
a00c9ea8:  13 2a 01 f3  sethi  %hi(0xa807cc00), %o1
a00c9eac:  82 10 20 00  clr  %g1
a00c9eb0:  96 12 63 08  or  %o1, 0x308, %o3
a00c9eb4:  98 00 60 01  add  %g1, 1, %o4
a00c9eb8:  83 28 60 10  sll  %g1, 0x10, %g1
a00c9ebc:  83 30 60 10  srl  %g1, 0x10, %g1
a00c9ec0:  9b 2b 20 10  sll  %o4, 0x10, %o5
a00c9ec4:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c9ec8:  c0 2a c0 01  clrb  [ %o3 + %g1 ]
a00c9ecc:  80 a3 61 7e  cmp  %o5, 0x17e
a00c9ed0:  08 bf ff f9  bleu  0xa00c9eb4
a00c9ed4:  82 10 00 0c  mov  %o4, %g1
a00c9ed8:  94 10 20 05  mov  5, %o2
a00c9edc:  92 12 63 08  or  %o1, 0x308, %o1
a00c9ee0:  90 10 00 18  mov  %i0, %o0
a00c9ee4:  96 10 20 00  clr  %o3
a00c9ee8:  7f ff fe af  call  0xa00c99a4
a00c9eec:  98 10 2c 00  mov  0xc00, %o4
a00c9ef0:  c2 0e e2 2c  ldub  [ %i3 + 0x22c ], %g1
a00c9ef4:  80 a0 60 00  cmp  %g1, 0
a00c9ef8:  02 80 00 12  be  0xa00c9f40
a00c9efc:  15 2a 01 f3  sethi  %hi(0xa807cc00), %o2
a00c9f00:  03 27 c7 07  sethi  %hi(0x9f1c1c00), %g1
a00c9f04:  92 10 60 a8  or  %g1, 0xa8, %o1	! 0x9f1c1ca8
a00c9f08:  94 12 a3 08  or  %o2, 0x308, %o2
a00c9f0c:  82 10 20 00  clr  %g1
a00c9f10:  96 00 60 01  add  %g1, 1, %o3
a00c9f14:  83 28 60 10  sll  %g1, 0x10, %g1
a00c9f18:  83 30 60 10  srl  %g1, 0x10, %g1
a00c9f1c:  d8 0a 40 01  ldub  [ %o1 + %g1 ], %o4
a00c9f20:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00c9f24:  9b 33 60 10  srl  %o5, 0x10, %o5
a00c9f28:  d8 2a 80 01  stb  %o4, [ %o2 + %g1 ]
a00c9f2c:  80 a3 61 7f  cmp  %o5, 0x17f
a00c9f30:  08 bf ff f8  bleu  0xa00c9f10
a00c9f34:  82 10 00 0b  mov  %o3, %g1
a00c9f38:  10 80 00 07  b  0xa00c9f54
a00c9f3c:  37 2a 01 f3  sethi  %hi(0xa807cc00), %i3
a00c9f40:  94 12 a3 08  or  %o2, 0x308, %o2
a00c9f44:  90 10 25 b4  mov  0x5b4, %o0
a00c9f48:  40 3b 4c e6  call  0xa0f9d2e0
a00c9f4c:  92 10 21 80  mov  0x180, %o1
a00c9f50:  37 2a 01 f3  sethi  %hi(0xa807cc00), %i3
a00c9f54:  98 10 2c 00  mov  0xc00, %o4
a00c9f58:  94 10 20 03  mov  3, %o2
a00c9f5c:  96 10 20 00  clr  %o3
a00c9f60:  90 10 00 18  mov  %i0, %o0
a00c9f64:  7f ff fe 90  call  0xa00c99a4
a00c9f68:  92 16 e3 08  or  %i3, 0x308, %o1
a00c9f6c:  90 10 00 18  mov  %i0, %o0
a00c9f70:  7f ff fe fa  call  0xa00c9b58
a00c9f74:  92 10 2c 00  mov  0xc00, %o1
a00c9f78:  90 10 00 18  mov  %i0, %o0
a00c9f7c:  7f ff ff 9b  call  0xa00c9de8
a00c9f80:  92 10 2c 00  mov  0xc00, %o1
a00c9f84:  90 10 00 18  mov  %i0, %o0
a00c9f88:  92 10 20 0f  mov  0xf, %o1
a00c9f8c:  94 10 20 c0  mov  0xc0, %o2
a00c9f90:  40 3b b7 e3  call  0xa0fb7f1c
a00c9f94:  96 10 20 01  mov  1, %o3
a00c9f98:  90 10 00 18  mov  %i0, %o0
a00c9f9c:  92 10 20 00  clr  %o1
a00c9fa0:  40 3b b7 d0  call  0xa0fb7ee0
a00c9fa4:  94 10 20 00  clr  %o2
a00c9fa8:  90 10 00 18  mov  %i0, %o0
a00c9fac:  92 10 20 03  mov  3, %o1
a00c9fb0:  40 3b b7 cc  call  0xa0fb7ee0
a00c9fb4:  94 10 20 01  mov  1, %o2
a00c9fb8:  90 10 00 18  mov  %i0, %o0
a00c9fbc:  40 3b b7 f9  call  0xa0fb7fa0
a00c9fc0:  92 10 20 02  mov  2, %o1
a00c9fc4:  80 8a 20 20  btst  0x20, %o0
a00c9fc8:  02 bf ff fd  be  0xa00c9fbc
a00c9fcc:  90 10 00 18  mov  %i0, %o0
a00c9fd0:  92 10 20 02  mov  2, %o1
a00c9fd4:  40 3b b7 c3  call  0xa0fb7ee0
a00c9fd8:  94 10 20 40  mov  0x40, %o2
a00c9fdc:  90 10 00 18  mov  %i0, %o0
a00c9fe0:  92 10 20 03  mov  3, %o1
a00c9fe4:  94 10 20 01  mov  1, %o2
a00c9fe8:  40 3b b7 cd  call  0xa0fb7f1c
a00c9fec:  96 10 20 00  clr  %o3
a00c9ff0:  90 10 00 18  mov  %i0, %o0
a00c9ff4:  92 16 e3 08  or  %i3, 0x308, %o1
a00c9ff8:  94 10 20 06  mov  6, %o2
a00c9ffc:  7f ff ff 4b  call  0xa00c9d28
a00ca000:  96 10 2c 00  mov  0xc00, %o3
a00ca004:  82 10 20 00  clr  %g1
a00ca008:  9a 00 60 01  add  %g1, 1, %o5
a00ca00c:  83 2b 60 10  sll  %o5, 0x10, %g1
a00ca010:  83 30 60 10  srl  %g1, 0x10, %g1
a00ca014:  80 a0 61 7f  cmp  %g1, 0x17f
a00ca018:  08 bf ff fc  bleu  0xa00ca008
a00ca01c:  82 10 00 0d  mov  %o5, %g1
a00ca020:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ca024:  92 10 61 88  or  %g1, 0x188, %o1	! 0xa807cd88
a00ca028:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00ca02c:  94 10 63 08  or  %g1, 0x308, %o2	! 0xa807cf08
a00ca030:  82 10 20 00  clr  %g1
a00ca034:  99 28 60 10  sll  %g1, 0x10, %o4
a00ca038:  96 00 60 01  add  %g1, 1, %o3
a00ca03c:  99 33 20 10  srl  %o4, 0x10, %o4
a00ca040:  82 03 00 0a  add  %o4, %o2, %g1
a00ca044:  c2 08 61 60  ldub  [ %g1 + 0x160 ], %g1
a00ca048:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00ca04c:  9b 33 60 10  srl  %o5, 0x10, %o5
a00ca050:  c2 2a 40 0c  stb  %g1, [ %o1 + %o4 ]
a00ca054:  80 a3 60 1f  cmp  %o5, 0x1f
a00ca058:  08 bf ff f7  bleu  0xa00ca034
a00ca05c:  82 10 00 0b  mov  %o3, %g1
a00ca060:  b2 10 20 0f  mov  0xf, %i1
a00ca064:  b4 10 20 c0  mov  0xc0, %i2
a00ca068:  40 3b b7 ad  call  0xa0fb7f1c
a00ca06c:  97 e8 20 00  restore  %g0, 0, %o3
a00ca070:  01 00 00 00  nop
