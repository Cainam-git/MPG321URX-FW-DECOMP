# leon2m FUN_a00a4f68 0xa00a4f68-0xa00a50c4 (348 bytes)
a00a4f68:  9d e3 bf 98  save  %sp, -104, %sp
a00a4f6c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00a4f70:  98 10 62 90  or  %g1, 0x290, %o4	! 0xa802d290
a00a4f74:  c2 03 20 ac  ld  [ %o4 + 0xac ], %g1
a00a4f78:  1b 00 10 00  sethi  %hi(0x400000), %o5
a00a4f7c:  80 88 40 0d  btst  %g1, %o5
a00a4f80:  12 80 00 4c  bne  0xa00a50b0
a00a4f84:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a4f88:  92 10 40 0d  or  %g1, %o5, %o1
a00a4f8c:  a3 32 60 16  srl  %o1, 0x16, %l1
a00a4f90:  d2 23 20 ac  st  %o1, [ %o4 + 0xac ]
a00a4f94:  a0 0c 60 01  and  %l1, 1, %l0
a00a4f98:  90 10 20 05  mov  5, %o0
a00a4f9c:  92 10 20 08  mov  8, %o1
a00a4fa0:  94 10 20 04  mov  4, %o2
a00a4fa4:  96 10 27 92  mov  0x792, %o3
a00a4fa8:  98 10 20 00  clr  %o4
a00a4fac:  40 02 86 b5  call  0xa0146a80
a00a4fb0:  a2 0c 20 ff  and  %l0, 0xff, %l1
a00a4fb4:  80 a4 60 00  cmp  %l1, 0
a00a4fb8:  02 80 00 22  be  0xa00a5040
a00a4fbc:  a0 10 20 00  clr  %l0
a00a4fc0:  96 0c 20 ff  and  %l0, 0xff, %o3
a00a4fc4:  94 02 e0 09  add  %o3, 9, %o2
a00a4fc8:  93 2a a0 10  sll  %o2, 0x10, %o1
a00a4fcc:  98 04 20 1e  add  %l0, 0x1e, %o4
a00a4fd0:  90 10 20 00  clr  %o0
a00a4fd4:  93 32 60 10  srl  %o1, 0x10, %o1
a00a4fd8:  98 0b 20 ff  and  %o4, 0xff, %o4
a00a4fdc:  94 10 20 08  mov  8, %o2
a00a4fe0:  96 10 20 01  mov  1, %o3
a00a4fe4:  40 02 86 cf  call  0xa0146b20
a00a4fe8:  9a 10 20 00  clr  %o5
a00a4fec:  a0 04 20 01  inc  %l0
a00a4ff0:  90 0c 20 ff  and  %l0, 0xff, %o0
a00a4ff4:  80 a2 20 03  cmp  %o0, 3
a00a4ff8:  08 bf ff f3  bleu  0xa00a4fc4
a00a4ffc:  96 0c 20 ff  and  %l0, 0xff, %o3
a00a5000:  80 a4 60 00  cmp  %l1, 0
a00a5004:  12 80 00 21  bne  0xa00a5088
a00a5008:  90 10 20 03  mov  3, %o0
a00a500c:  92 10 20 08  mov  8, %o1
a00a5010:  94 10 20 05  mov  5, %o2
a00a5014:  96 10 27 92  mov  0x792, %o3
a00a5018:  40 02 86 9a  call  0xa0146a80
a00a501c:  98 10 20 00  clr  %o4
a00a5020:  90 10 20 0e  mov  0xe, %o0
a00a5024:  92 10 20 08  mov  8, %o1
a00a5028:  94 10 20 05  mov  5, %o2
a00a502c:  96 10 29 92  mov  0x992, %o3
a00a5030:  40 02 86 94  call  0xa0146a80
a00a5034:  98 10 20 00  clr  %o4
a00a5038:  10 80 00 1e  b  0xa00a50b0
a00a503c:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00a5040:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a5044:  90 03 20 09  add  %o4, 9, %o0
a00a5048:  83 2a 20 10  sll  %o0, 0x10, %g1
a00a504c:  9e 04 20 22  add  %l0, 0x22, %o7
a00a5050:  9a 10 20 00  clr  %o5
a00a5054:  93 30 60 10  srl  %g1, 0x10, %o1
a00a5058:  98 0b e0 ff  and  %o7, 0xff, %o4
a00a505c:  90 10 20 00  clr  %o0
a00a5060:  94 10 20 08  mov  8, %o2
a00a5064:  40 02 86 af  call  0xa0146b20
a00a5068:  96 10 20 01  mov  1, %o3
a00a506c:  a0 04 20 01  inc  %l0
a00a5070:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00a5074:  80 a3 60 03  cmp  %o5, 3
a00a5078:  08 bf ff f3  bleu  0xa00a5044
a00a507c:  98 0c 20 ff  and  %l0, 0xff, %o4
a00a5080:  10 bf ff e1  b  0xa00a5004
a00a5084:  80 a4 60 00  cmp  %l1, 0
a00a5088:  92 10 20 08  mov  8, %o1
a00a508c:  94 10 20 05  mov  5, %o2
a00a5090:  96 10 29 92  mov  0x992, %o3
a00a5094:  40 02 86 7b  call  0xa0146a80
a00a5098:  98 10 20 00  clr  %o4
a00a509c:  90 10 20 0e  mov  0xe, %o0
a00a50a0:  92 10 20 08  mov  8, %o1
a00a50a4:  94 10 20 05  mov  5, %o2
a00a50a8:  10 bf ff e2  b  0xa00a5030
a00a50ac:  96 10 27 92  mov  0x792, %o3
a00a50b0:  da 0a a0 8e  ldub  [ %o2 + 0x8e ], %o5
a00a50b4:  96 13 60 02  or  %o5, 2, %o3
a00a50b8:  d6 2a a0 8e  stb  %o3, [ %o2 + 0x8e ]
a00a50bc:  81 c7 e0 08  ret
a00a50c0:  81 e8 00 00  restore
