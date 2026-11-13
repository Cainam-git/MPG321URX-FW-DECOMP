# leon2s FUN_a0092db8 0xa0092db8-0xa0093034 (636 bytes)
a0092db8:  9d e3 be 68  save  %sp, -408, %sp
a0092dbc:  03 2a 01 e5  sethi  %hi(0xa8079400), %g1
a0092dc0:  a0 10 61 5c  or  %g1, 0x15c, %l0	! 0xa807955c
a0092dc4:  90 10 20 00  clr  %o0
a0092dc8:  9e 07 bf f8  add  %fp, -8, %o7
a0092dcc:  82 0a 20 ff  and  %o0, 0xff, %g1
a0092dd0:  83 28 60 02  sll  %g1, 2, %g1
a0092dd4:  da 04 00 01  ld  [ %l0 + %g1 ], %o5
a0092dd8:  90 02 20 01  inc  %o0
a0092ddc:  82 00 40 0f  add  %g1, %o7, %g1
a0092de0:  99 33 60 18  srl  %o5, 0x18, %o4
a0092de4:  97 33 60 10  srl  %o5, 0x10, %o3
a0092de8:  95 33 60 08  srl  %o5, 8, %o2
a0092dec:  92 0a 20 ff  and  %o0, 0xff, %o1
a0092df0:  da 28 7f 83  stb  %o5, [ %g1 + -125 ]
a0092df4:  d8 28 7f 80  stb  %o4, [ %g1 + -128 ]
a0092df8:  d6 28 7f 81  stb  %o3, [ %g1 + -127 ]
a0092dfc:  80 a2 60 17  cmp  %o1, 0x17
a0092e00:  08 bf ff f3  bleu  0xa0092dcc
a0092e04:  d4 28 7f 82  stb  %o2, [ %g1 + -126 ]
a0092e08:  90 10 20 60  mov  0x60, %o0
a0092e0c:  82 0a 20 ff  and  %o0, 0xff, %g1
a0092e10:  9a 02 20 01  add  %o0, 1, %o5
a0092e14:  82 03 c0 01  add  %o7, %g1, %g1
a0092e18:  c0 28 7f 80  clrb  [ %g1 + -128 ]
a0092e1c:  80 8b 60 80  btst  0x80, %o5
a0092e20:  02 bf ff fb  be  0xa0092e0c
a0092e24:  90 10 00 0d  mov  %o5, %o0
a0092e28:  d6 0f bf 86  ldub  [ %fp + -122 ], %o3
a0092e2c:  c2 0f bf 87  ldub  [ %fp + -121 ], %g1
a0092e30:  19 2a 01 e5  sethi  %hi(0xa8079400), %o4
a0092e34:  97 2a e0 08  sll  %o3, 8, %o3
a0092e38:  98 13 21 38  or  %o4, 0x138, %o4
a0092e3c:  96 02 c0 01  add  %o3, %g1, %o3
a0092e40:  c2 13 20 0a  lduh  [ %o4 + 0xa ], %g1
a0092e44:  da 13 20 08  lduh  [ %o4 + 8 ], %o5
a0092e48:  9a 23 40 01  sub  %o5, %g1, %o5
a0092e4c:  97 2a e0 10  sll  %o3, 0x10, %o3
a0092e50:  03 2a aa aa  sethi  %hi(0xaaaaa800), %g1
a0092e54:  82 10 62 ab  or  %g1, 0x2ab, %g1	! 0xaaaaaaab
a0092e58:  97 32 e0 10  srl  %o3, 0x10, %o3
a0092e5c:  80 52 c0 01  umul  %o3, %g1, %g0
a0092e60:  97 40 00 00  rd  %y, %o3
a0092e64:  82 10 20 7f  mov  0x7f, %g1
a0092e68:  c2 2f be c8  stb  %g1, [ %fp + -312 ]
a0092e6c:  82 10 3f 80  mov  -128, %g1
a0092e70:  c2 2f be c9  stb  %g1, [ %fp + -311 ]
a0092e74:  82 10 20 06  mov  6, %g1
a0092e78:  c2 2f be cb  stb  %g1, [ %fp + -309 ]
a0092e7c:  82 10 20 01  mov  1, %g1
a0092e80:  c2 2f be cd  stb  %g1, [ %fp + -307 ]
a0092e84:  d4 13 20 0c  lduh  [ %o4 + 0xc ], %o2
a0092e88:  82 10 20 02  mov  2, %g1
a0092e8c:  d8 13 20 0e  lduh  [ %o4 + 0xe ], %o4
a0092e90:  9a 23 40 0a  sub  %o5, %o2, %o5
a0092e94:  c2 2f be cf  stb  %g1, [ %fp + -305 ]
a0092e98:  9a 23 40 0c  sub  %o5, %o4, %o5
a0092e9c:  82 10 3f 88  mov  -120, %g1
a0092ea0:  da 37 bf 70  sth  %o5, [ %fp + -144 ]
a0092ea4:  d4 37 bf 72  sth  %o2, [ %fp + -142 ]
a0092ea8:  d8 37 bf 74  sth  %o4, [ %fp + -140 ]
a0092eac:  c2 2f be d1  stb  %g1, [ %fp + -303 ]
a0092eb0:  a1 32 e0 01  srl  %o3, 1, %l0
a0092eb4:  c0 2f be ca  clrb  [ %fp + -310 ]
a0092eb8:  c0 2f be cc  clrb  [ %fp + -308 ]
a0092ebc:  c0 2f be ce  clrb  [ %fp + -306 ]
a0092ec0:  c0 2f be d0  clrb  [ %fp + -304 ]
a0092ec4:  90 10 20 00  clr  %o0
a0092ec8:  82 0a 20 ff  and  %o0, 0xff, %g1
a0092ecc:  82 03 c0 01  add  %o7, %g1, %g1
a0092ed0:  90 02 20 01  inc  %o0
a0092ed4:  da 08 7f 80  ldub  [ %g1 + -128 ], %o5
a0092ed8:  98 0a 20 ff  and  %o0, 0xff, %o4
a0092edc:  80 a3 20 14  cmp  %o4, 0x14
a0092ee0:  08 bf ff fa  bleu  0xa0092ec8
a0092ee4:  da 28 7e da  stb  %o5, [ %g1 + -294 ]
a0092ee8:  82 10 20 7f  mov  0x7f, %g1
a0092eec:  c2 2f be e7  stb  %g1, [ %fp + -281 ]
a0092ef0:  82 10 20 01  mov  1, %g1
a0092ef4:  c2 2f be e9  stb  %g1, [ %fp + -279 ]
a0092ef8:  c0 2f be e8  clrb  [ %fp + -280 ]
a0092efc:  90 10 20 00  clr  %o0
a0092f00:  82 0a 20 ff  and  %o0, 0xff, %g1
a0092f04:  82 03 c0 01  add  %o7, %g1, %g1
a0092f08:  90 02 20 01  inc  %o0
a0092f0c:  da 08 7f 95  ldub  [ %g1 + -107 ], %o5
a0092f10:  98 0a 20 ff  and  %o0, 0xff, %o4
a0092f14:  80 a3 20 1b  cmp  %o4, 0x1b
a0092f18:  08 bf ff fa  bleu  0xa0092f00
a0092f1c:  da 28 7e f2  stb  %o5, [ %g1 + -270 ]
a0092f20:  82 10 20 7f  mov  0x7f, %g1
a0092f24:  c2 2f bf 06  stb  %g1, [ %fp + -250 ]
a0092f28:  82 10 20 02  mov  2, %g1
a0092f2c:  c2 2f bf 08  stb  %g1, [ %fp + -248 ]
a0092f30:  c0 2f bf 07  clrb  [ %fp + -249 ]
a0092f34:  90 10 20 00  clr  %o0
a0092f38:  82 0a 20 ff  and  %o0, 0xff, %g1
a0092f3c:  82 03 c0 01  add  %o7, %g1, %g1
a0092f40:  90 02 20 01  inc  %o0
a0092f44:  da 08 7f b1  ldub  [ %g1 + -79 ], %o5
a0092f48:  98 0a 20 ff  and  %o0, 0xff, %o4
a0092f4c:  80 a3 20 1b  cmp  %o4, 0x1b
a0092f50:  08 bf ff fa  bleu  0xa0092f38
a0092f54:  da 28 7f 11  stb  %o5, [ %g1 + -239 ]
a0092f58:  82 10 20 7f  mov  0x7f, %g1
a0092f5c:  c2 2f bf 25  stb  %g1, [ %fp + -219 ]
a0092f60:  82 10 20 03  mov  3, %g1
a0092f64:  c2 2f bf 27  stb  %g1, [ %fp + -217 ]
a0092f68:  c0 2f bf 26  clrb  [ %fp + -218 ]
a0092f6c:  90 10 20 00  clr  %o0
a0092f70:  82 0a 20 ff  and  %o0, 0xff, %g1
a0092f74:  82 03 c0 01  add  %o7, %g1, %g1
a0092f78:  90 02 20 01  inc  %o0
a0092f7c:  da 08 7f cd  ldub  [ %g1 + -51 ], %o5
a0092f80:  98 0a 20 ff  and  %o0, 0xff, %o4
a0092f84:  80 a3 20 1b  cmp  %o4, 0x1b
a0092f88:  08 bf ff fa  bleu  0xa0092f70
a0092f8c:  da 28 7f 30  stb  %o5, [ %g1 + -208 ]
a0092f90:  82 10 20 7f  mov  0x7f, %g1
a0092f94:  c2 2f bf 44  stb  %g1, [ %fp + -188 ]
a0092f98:  82 10 20 04  mov  4, %g1
a0092f9c:  c2 2f bf 46  stb  %g1, [ %fp + -186 ]
a0092fa0:  c0 2f bf 45  clrb  [ %fp + -187 ]
a0092fa4:  90 10 20 00  clr  %o0
a0092fa8:  82 0a 20 ff  and  %o0, 0xff, %g1
a0092fac:  82 03 c0 01  add  %o7, %g1, %g1
a0092fb0:  90 02 20 01  inc  %o0
a0092fb4:  da 08 7f e9  ldub  [ %g1 + -23 ], %o5
a0092fb8:  98 0a 20 ff  and  %o0, 0xff, %o4
a0092fbc:  80 a3 20 16  cmp  %o4, 0x16
a0092fc0:  08 bf ff fa  bleu  0xa0092fa8
a0092fc4:  da 28 7f 4f  stb  %o5, [ %g1 + -177 ]
a0092fc8:  d4 17 bf 70  lduh  [ %fp + -144 ], %o2
a0092fcc:  83 32 a0 08  srl  %o2, 8, %g1
a0092fd0:  c2 2f bf 5f  stb  %g1, [ %fp + -161 ]
a0092fd4:  82 10 20 7f  mov  0x7f, %g1
a0092fd8:  c2 2f bf 63  stb  %g1, [ %fp + -157 ]
a0092fdc:  82 10 20 40  mov  0x40, %g1
a0092fe0:  d2 17 bf 72  lduh  [ %fp + -142 ], %o1
a0092fe4:  d0 17 bf 74  lduh  [ %fp + -140 ], %o0
a0092fe8:  c2 2f bf 64  stb  %g1, [ %fp + -156 ]
a0092fec:  9b 32 60 08  srl  %o1, 8, %o5
a0092ff0:  99 32 20 08  srl  %o0, 8, %o4
a0092ff4:  97 34 20 08  srl  %l0, 8, %o3
a0092ff8:  82 10 20 05  mov  5, %g1
a0092ffc:  d2 2f bf 60  stb  %o1, [ %fp + -160 ]
a0093000:  d0 2f bf 62  stb  %o0, [ %fp + -158 ]
a0093004:  da 2f bf 61  stb  %o5, [ %fp + -159 ]
a0093008:  c2 2f bf 65  stb  %g1, [ %fp + -155 ]
a009300c:  d8 2f bf 66  stb  %o4, [ %fp + -154 ]
a0093010:  d6 2f bf 68  stb  %o3, [ %fp + -152 ]
a0093014:  d4 2f bf 5e  stb  %o2, [ %fp + -162 ]
a0093018:  e0 2f bf 67  stb  %l0, [ %fp + -153 ]
a009301c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0093020:  7f ff fe 49  call  0xa0092944
a0093024:  92 07 be c8  add  %fp, -312, %o1
a0093028:  01 00 00 00  nop
a009302c:  81 c7 e0 08  ret
a0093030:  81 e8 00 00  restore
