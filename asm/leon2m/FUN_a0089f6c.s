# leon2m FUN_a0089f6c 0xa0089f6c-0xa008a034 (200 bytes)
a0089f6c:  9d e3 bf 70  save  %sp, -144, %sp
a0089f70:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0089f74:  96 12 22 90  or  %o0, 0x290, %o3	! 0xa802d290
a0089f78:  d8 02 e0 a8  ld  [ %o3 + 0xa8 ], %o4
a0089f7c:  96 10 20 01  mov  1, %o3
a0089f80:  94 10 20 6e  mov  0x6e, %o2
a0089f84:  92 10 3f 88  mov  -120, %o1
a0089f88:  82 10 20 02  mov  2, %g1
a0089f8c:  9a 10 3f e6  mov  -26, %o5
a0089f90:  d4 2f bf d0  stb  %o2, [ %fp + -48 ]
a0089f94:  d2 2f bf d1  stb  %o1, [ %fp + -47 ]
a0089f98:  c2 2f bf d2  stb  %g1, [ %fp + -46 ]
a0089f9c:  da 2f bf d4  stb  %o5, [ %fp + -44 ]
a0089fa0:  80 8b 20 80  btst  0x80, %o4
a0089fa4:  c0 2f bf d3  clrb  [ %fp + -45 ]
a0089fa8:  c0 2f bf d5  clrb  [ %fp + -43 ]
a0089fac:  c0 2f bf d6  clrb  [ %fp + -42 ]
a0089fb0:  d6 2f bf d7  stb  %o3, [ %fp + -41 ]
a0089fb4:  12 80 00 13  bne  0xa008a000
a0089fb8:  c0 2f bf d8  clrb  [ %fp + -40 ]
a0089fbc:  c0 2f bf d9  clrb  [ %fp + -39 ]
a0089fc0:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a0089fc4:  9e 10 20 50  mov  0x50, %o7
a0089fc8:  de 2a 63 9e  stb  %o7, [ %o1 + 0x39e ]
a0089fcc:  a0 07 bf d0  add  %fp, -48, %l0
a0089fd0:  96 10 20 00  clr  %o3
a0089fd4:  98 10 20 00  clr  %o4
a0089fd8:  94 10 20 50  mov  0x50, %o2
a0089fdc:  c2 0b 00 10  ldub  [ %o4 + %l0 ], %g1
a0089fe0:  96 02 e0 01  inc  %o3
a0089fe4:  9a 18 40 0a  xor  %g1, %o2, %o5
a0089fe8:  98 0a e0 ff  and  %o3, 0xff, %o4
a0089fec:  80 a3 20 0a  cmp  %o4, 0xa
a0089ff0:  0a bf ff fb  bcs  0xa0089fdc
a0089ff4:  94 10 00 0d  mov  %o5, %o2
a0089ff8:  10 80 00 04  b  0xa008a008
a0089ffc:  94 12 22 90  or  %o0, 0x290, %o2
a008a000:  10 bf ff f0  b  0xa0089fc0
a008a004:  d6 2f bf d9  stb  %o3, [ %fp + -39 ]
a008a008:  da 2b 00 10  stb  %o5, [ %o4 + %l0 ]
a008a00c:  da 2a 63 9e  stb  %o5, [ %o1 + 0x39e ]
a008a010:  40 03 11 1a  call  0xa014e478
a008a014:  d0 0a a0 1e  ldub  [ %o2 + 0x1e ], %o0
a008a018:  90 0a 20 ff  and  %o0, 0xff, %o0
a008a01c:  94 10 00 10  mov  %l0, %o2
a008a020:  40 02 f9 a2  call  0xa01486a8
a008a024:  92 10 20 0b  mov  0xb, %o1
a008a028:  01 00 00 00  nop
a008a02c:  81 c7 e0 08  ret
a008a030:  81 e8 00 00  restore
