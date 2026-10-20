# leon2s FUN_a00b1028 0xa00b1028-0xa00b115c (308 bytes)
a00b1028:  9d e3 bf 98  save  %sp, -104, %sp
a00b102c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00b1030:  7f ff fd 44  call  0xa00b0540
a00b1034:  90 10 00 18  mov  %i0, %o0
a00b1038:  7f ff 71 f2  call  0xa008d800
a00b103c:  01 00 00 00  nop
a00b1040:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a00b1044:  94 10 63 f0  or  %g1, 0x3f0, %o2	! 0xcf0147f0
a00b1048:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b104c:  9a 5e 21 2c  smul  %i0, 0x12c, %o5
a00b1050:  82 10 60 18  or  %g1, 0x18, %g1
a00b1054:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b1058:  17 2a 01 e1  sethi  %hi(0xa8078400), %o3
a00b105c:  9a 03 40 01  add  %o5, %g1, %o5
a00b1060:  80 a2 20 81  cmp  %o0, 0x81
a00b1064:  08 80 00 0e  bleu  0xa00b109c
a00b1068:  98 12 e3 68  or  %o3, 0x368, %o4
a00b106c:  c2 02 80 00  ld  [ %o2 ], %g1
a00b1070:  82 10 60 80  or  %g1, 0x80, %g1
a00b1074:  c2 22 80 00  st  %g1, [ %o2 ]
a00b1078:  82 10 20 05  mov  5, %g1
a00b107c:  c2 2b 20 04  stb  %g1, [ %o4 + 4 ]
a00b1080:  82 10 20 02  mov  2, %g1
a00b1084:  c2 2b 20 01  stb  %g1, [ %o4 + 1 ]
a00b1088:  82 10 20 04  mov  4, %g1
a00b108c:  c2 2b 20 02  stb  %g1, [ %o4 + 2 ]
a00b1090:  82 10 20 06  mov  6, %g1
a00b1094:  c0 2a e3 68  clrb  [ %o3 + 0x368 ]
a00b1098:  c2 2b 20 03  stb  %g1, [ %o4 + 3 ]
a00b109c:  80 8e 60 ff  btst  0xff, %i1
a00b10a0:  22 80 00 05  be,a   0xa00b10b4
a00b10a4:  d0 0b 61 19  ldub  [ %o5 + 0x119 ], %o0
a00b10a8:  7f ff ea 69  call  0xa00aba4c
a00b10ac:  01 00 00 00  nop
a00b10b0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00b10b4:  7f ff 4b 60  call  0xa0083e34
a00b10b8:  01 00 00 00  nop
a00b10bc:  7f ff ff 66  call  0xa00b0e54
a00b10c0:  01 00 00 00  nop
a00b10c4:  94 10 20 01  mov  1, %o2	! 0x1
a00b10c8:  96 10 20 00  clr  %o3
a00b10cc:  90 10 00 18  mov  %i0, %o0
a00b10d0:  7f ff d7 e2  call  0xa00a7058
a00b10d4:  92 10 20 3e  mov  0x3e, %o1
a00b10d8:  92 10 20 01  mov  1, %o1
a00b10dc:  7f ff fd 43  call  0xa00b05e8
a00b10e0:  90 10 00 18  mov  %i0, %o0
a00b10e4:  7f ff f0 e5  call  0xa00ad478
a00b10e8:  90 10 20 00  clr  %o0
a00b10ec:  03 33 c0 3c  sethi  %hi(0xcf00f000), %g1
a00b10f0:  82 10 62 1c  or  %g1, 0x21c, %g1	! 0xcf00f21c
a00b10f4:  da 00 40 00  ld  [ %g1 ], %o5
a00b10f8:  9a 0b 7f a7  and  %o5, -89, %o5
a00b10fc:  da 20 40 00  st  %o5, [ %g1 ]
a00b1100:  7f ff fa af  call  0xa00afbbc
a00b1104:  90 10 00 18  mov  %i0, %o0
a00b1108:  90 10 00 18  mov  %i0, %o0
a00b110c:  92 10 20 20  mov  0x20, %o1
a00b1110:  94 10 20 02  mov  2, %o2
a00b1114:  7f ff d6 e1  call  0xa00a6c98
a00b1118:  96 10 20 01  mov  1, %o3
a00b111c:  90 10 00 18  mov  %i0, %o0
a00b1120:  92 10 20 20  mov  0x20, %o1
a00b1124:  94 10 20 02  mov  2, %o2
a00b1128:  7f ff d6 dc  call  0xa00a6c98
a00b112c:  96 10 20 00  clr  %o3
a00b1130:  90 10 00 18  mov  %i0, %o0
a00b1134:  92 10 20 3e  mov  0x3e, %o1
a00b1138:  94 10 20 01  mov  1, %o2
a00b113c:  7f ff d7 c7  call  0xa00a7058
a00b1140:  96 10 20 01  mov  1, %o3
a00b1144:  7f ff fc f5  call  0xa00b0518
a00b1148:  90 10 00 18  mov  %i0, %o0
a00b114c:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00b1150:  c0 28 62 71  clrb  [ %g1 + 0x271 ]	! 0xa807de71
a00b1154:  81 c7 e0 08  ret
a00b1158:  81 e8 00 00  restore
