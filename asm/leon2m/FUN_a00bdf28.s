# leon2m FUN_a00bdf28 0xa00bdf28-0xa00be0a0 (376 bytes)
a00bdf28:  9d e3 bf 98  save  %sp, -104, %sp
a00bdf2c:  92 10 20 00  clr  %o1
a00bdf30:  40 02 59 c3  call  0xa015463c
a00bdf34:  90 10 20 43  mov  0x43, %o0
a00bdf38:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bdf3c:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]	! 0xa802d078
a00bdf40:  b2 16 a0 78  or  %i2, 0x78, %i1
a00bdf44:  90 10 20 62  mov  0x62, %o0
a00bdf48:  d0 2e 60 01  stb  %o0, [ %i1 + 1 ]
a00bdf4c:  92 10 20 02  mov  2, %o1
a00bdf50:  40 02 59 bb  call  0xa015463c
a00bdf54:  90 10 20 43  mov  0x43, %o0
a00bdf58:  d0 2e 60 02  stb  %o0, [ %i1 + 2 ]
a00bdf5c:  92 10 20 03  mov  3, %o1
a00bdf60:  40 02 59 b7  call  0xa015463c
a00bdf64:  90 10 20 43  mov  0x43, %o0
a00bdf68:  d0 2e 60 03  stb  %o0, [ %i1 + 3 ]
a00bdf6c:  92 10 20 04  mov  4, %o1
a00bdf70:  40 02 59 b3  call  0xa015463c
a00bdf74:  90 10 20 43  mov  0x43, %o0
a00bdf78:  d0 2e 60 04  stb  %o0, [ %i1 + 4 ]
a00bdf7c:  92 10 20 05  mov  5, %o1
a00bdf80:  40 02 59 af  call  0xa015463c
a00bdf84:  90 10 20 43  mov  0x43, %o0
a00bdf88:  d0 2e 60 05  stb  %o0, [ %i1 + 5 ]
a00bdf8c:  92 10 20 06  mov  6, %o1
a00bdf90:  40 02 59 ab  call  0xa015463c
a00bdf94:  90 10 20 43  mov  0x43, %o0
a00bdf98:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bdf9c:  82 10 62 74  or  %g1, 0x274, %g1	! 0xa802d274
a00bdfa0:  da 08 60 02  ldub  [ %g1 + 2 ], %o5
a00bdfa4:  d0 2e 60 06  stb  %o0, [ %i1 + 6 ]
a00bdfa8:  80 a3 60 00  cmp  %o5, 0
a00bdfac:  92 10 20 00  clr  %o1
a00bdfb0:  08 80 00 0e  bleu  0xa00bdfe8
a00bdfb4:  94 10 20 00  clr  %o2
a00bdfb8:  9e 10 00 01  mov  %g1, %o7
a00bdfbc:  90 10 00 0d  mov  %o5, %o0
a00bdfc0:  96 10 20 00  clr  %o3
a00bdfc4:  82 02 c0 0f  add  %o3, %o7, %g1
a00bdfc8:  98 02 c0 19  add  %o3, %i1, %o4
a00bdfcc:  94 02 a0 01  inc  %o2
a00bdfd0:  da 08 60 03  ldub  [ %g1 + 3 ], %o5
a00bdfd4:  96 0a a0 ff  and  %o2, 0xff, %o3
a00bdfd8:  da 2b 20 07  stb  %o5, [ %o4 + 7 ]
a00bdfdc:  80 a2 00 0b  cmp  %o0, %o3
a00bdfe0:  18 bf ff f9  bgu  0xa00bdfc4
a00bdfe4:  92 02 40 0d  add  %o1, %o5, %o1
a00bdfe8:  94 16 a0 78  or  %i2, 0x78, %o2
a00bdfec:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bdff0:  96 10 20 0d  mov  0xd, %o3
a00bdff4:  d6 2a a0 15  stb  %o3, [ %o2 + 0x15 ]
a00bdff8:  80 a6 20 02  cmp  %i0, 2
a00bdffc:  02 80 00 10  be  0xa00be03c
a00be000:  d2 2a a0 14  stb  %o1, [ %o2 + 0x14 ]
a00be004:  80 a6 20 03  cmp  %i0, 3
a00be008:  02 80 00 19  be  0xa00be06c
a00be00c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00be010:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00be014:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00be018:  c0 28 60 9c  clrb  [ %g1 + 0x9c ]
a00be01c:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00be020:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00be024:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00be028:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00be02c:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00be030:  b4 16 a0 78  or  %i2, 0x78, %i2
a00be034:  40 02 29 ed  call  0xa01487e8
a00be038:  93 e8 20 16  restore  %g0, 0x16, %o1
a00be03c:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be040:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00be044:  9a 12 60 40  or  %o1, 0x40, %o5
a00be048:  c0 2b e0 9a  clrb  [ %o7 + 0x9a ]
a00be04c:  c0 2a 60 40  clrb  [ %o1 + 0x40 ]
a00be050:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00be054:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00be058:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00be05c:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00be060:  b4 16 a0 78  or  %i2, 0x78, %i2
a00be064:  40 02 29 e1  call  0xa01487e8
a00be068:  93 e8 20 16  restore  %g0, 0x16, %o1
a00be06c:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00be070:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00be074:  9a 16 60 98  or  %i1, 0x98, %o5
a00be078:  c0 2e 60 98  clrb  [ %i1 + 0x98 ]
a00be07c:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00be080:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00be084:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00be088:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00be08c:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00be090:  b4 16 a0 78  or  %i2, 0x78, %i2
a00be094:  40 02 29 d5  call  0xa01487e8
a00be098:  93 e8 20 16  restore  %g0, 0x16, %o1
a00be09c:  01 00 00 00  nop
