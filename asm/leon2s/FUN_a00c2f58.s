# leon2s FUN_a00c2f58 0xa00c2f58-0xa00c30e4 (396 bytes)
a00c2f58:  9d e3 bf 98  save  %sp, -104, %sp
a00c2f5c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00c2f60:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00c2f64:  aa 10 61 e8  or  %g1, 0x1e8, %l5
a00c2f68:  40 3b fc 3f  call  0xa0fc2064
a00c2f6c:  a9 2e 20 04  sll  %i0, 4, %l4
a00c2f70:  a4 05 00 15  add  %l4, %l5, %l2
a00c2f74:  c2 04 a0 08  ld  [ %l2 + 8 ], %g1
a00c2f78:  90 22 00 01  sub  %o0, %g1, %o0
a00c2f7c:  80 a2 20 64  cmp  %o0, 0x64
a00c2f80:  08 80 00 56  bleu  0xa00c30d8
a00c2f84:  ac 10 20 00  clr  %l6
a00c2f88:  94 10 20 01  mov  1, %o2
a00c2f8c:  96 10 20 01  mov  1, %o3
a00c2f90:  90 10 00 18  mov  %i0, %o0
a00c2f94:  40 3b ce c3  call  0xa0fb6aa0
a00c2f98:  92 10 20 bb  mov  0xbb, %o1
a00c2f9c:  92 10 20 ca  mov  0xca, %o1
a00c2fa0:  40 3b ce 85  call  0xa0fb69b4
a00c2fa4:  90 10 00 18  mov  %i0, %o0
a00c2fa8:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00c2fac:  92 10 20 c9  mov  0xc9, %o1
a00c2fb0:  40 3b ce 81  call  0xa0fb69b4
a00c2fb4:  90 10 00 18  mov  %i0, %o0
a00c2fb8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c2fbc:  a3 2c 60 08  sll  %l1, 8, %l1
a00c2fc0:  a2 04 40 08  add  %l1, %o0, %l1
a00c2fc4:  92 10 20 ce  mov  0xce, %o1
a00c2fc8:  40 3b ce 7b  call  0xa0fb69b4
a00c2fcc:  90 10 00 18  mov  %i0, %o0
a00c2fd0:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00c2fd4:  90 10 00 18  mov  %i0, %o0
a00c2fd8:  40 3b ce 77  call  0xa0fb69b4
a00c2fdc:  92 10 20 cd  mov  0xcd, %o1
a00c2fe0:  a3 2c 60 10  sll  %l1, 0x10, %l1
a00c2fe4:  a1 2c 20 08  sll  %l0, 8, %l0
a00c2fe8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c2fec:  a7 34 60 10  srl  %l1, 0x10, %l3
a00c2ff0:  a0 04 00 08  add  %l0, %o0, %l0
a00c2ff4:  80 a4 e0 10  cmp  %l3, 0x10
a00c2ff8:  a1 2c 20 10  sll  %l0, 0x10, %l0
a00c2ffc:  82 60 20 00  subx  %g0, 0, %g1
a00c3000:  a3 34 20 10  srl  %l0, 0x10, %l1
a00c3004:  82 08 60 01  and  %g1, 1, %g1
a00c3008:  80 a4 60 05  cmp  %l1, 5
a00c300c:  18 80 00 03  bgu  0xa00c3018
a00c3010:  9a 10 20 01  mov  1, %o5
a00c3014:  9a 10 20 00  clr  %o5
a00c3018:  80 88 40 0d  btst  %g1, %o5
a00c301c:  02 80 00 27  be  0xa00c30b8
a00c3020:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c3024:  da 05 00 15  ld  [ %l4 + %l5 ], %o5
a00c3028:  03 00 07 c0  sethi  %hi(0x1f0000), %g1
a00c302c:  80 8b 40 01  btst  %o5, %g1
a00c3030:  12 80 00 22  bne  0xa00c30b8
a00c3034:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00c3038:  29 2a 01 e3  sethi  %hi(0xa8078c00), %l4
a00c303c:  a0 15 20 88  or  %l4, 0x88, %l0	! 0xa8078c88
a00c3040:  c2 0c 00 18  ldub  [ %l0 + %i0 ], %g1
a00c3044:  80 a0 60 04  cmp  %g1, 4
a00c3048:  08 80 00 0b  bleu  0xa00c3074
a00c304c:  82 00 60 01  inc  %g1
a00c3050:  11 27 c6 dd  sethi  %hi(0x9f1b7400), %o0
a00c3054:  90 12 21 80  or  %o0, 0x180, %o0	! 0x9f1b7580
a00c3058:  92 10 00 18  mov  %i0, %o1
a00c305c:  40 3a ff fa  call  0xa0f83044
a00c3060:  94 10 00 11  mov  %l1, %o2
a00c3064:  c0 2c 00 18  clrb  [ %l0 + %i0 ]
a00c3068:  ac 10 20 01  mov  1, %l6
a00c306c:  c2 0c 00 18  ldub  [ %l0 + %i0 ], %g1
a00c3070:  82 00 60 01  inc  %g1
a00c3074:  80 a4 64 00  cmp  %l1, 0x400
a00c3078:  18 80 00 0b  bgu  0xa00c30a4
a00c307c:  c2 2c 00 18  stb  %g1, [ %l0 + %i0 ]
a00c3080:  80 a4 63 00  cmp  %l1, 0x300
a00c3084:  18 80 00 03  bgu  0xa00c3090
a00c3088:  9a 10 20 01  mov  1, %o5
a00c308c:  9a 10 20 00  clr  %o5
a00c3090:  80 a4 e0 08  cmp  %l3, 8
a00c3094:  82 40 20 00  addx  %g0, 0, %g1
a00c3098:  80 8b 40 01  btst  %o5, %g1
a00c309c:  22 80 00 0a  be,a   0xa00c30c4
a00c30a0:  da 04 80 00  ld  [ %l2 ], %o5
a00c30a4:  9a 15 20 88  or  %l4, 0x88, %o5
a00c30a8:  c2 0b 40 18  ldub  [ %o5 + %i0 ], %g1
a00c30ac:  82 00 60 01  inc  %g1
a00c30b0:  10 80 00 04  b  0xa00c30c0
a00c30b4:  c2 2b 40 18  stb  %g1, [ %o5 + %i0 ]
a00c30b8:  82 10 60 88  or  %g1, 0x88, %g1
a00c30bc:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a00c30c0:  da 04 80 00  ld  [ %l2 ], %o5
a00c30c4:  03 00 07 c0  sethi  %hi(0x1f0000), %g1
a00c30c8:  82 2b 40 01  andn  %o5, %g1, %g1
a00c30cc:  40 3b fb e6  call  0xa0fc2064
a00c30d0:  c2 24 80 00  st  %g1, [ %l2 ]
a00c30d4:  d0 24 a0 08  st  %o0, [ %l2 + 8 ]
a00c30d8:  b0 0d a0 01  and  %l6, 1, %i0
a00c30dc:  81 c7 e0 08  ret
a00c30e0:  81 e8 00 00  restore
