# leon2m FUN_a00b3ed0 0xa00b3ed0-0xa00b4144 (628 bytes)
a00b3ed0:  9d e3 bf 80  save  %sp, -128, %sp
a00b3ed4:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00b3ed8:  80 a6 60 01  cmp  %i1, 1
a00b3edc:  02 80 00 22  be  0xa00b3f64
a00b3ee0:  a0 10 00 1b  mov  %i3, %l0
a00b3ee4:  90 1e 60 13  xor  %i1, 0x13, %o0
a00b3ee8:  80 a0 00 08  cmp  %g0, %o0
a00b3eec:  98 60 3f ff  subx  %g0, -1, %o4
a00b3ef0:  82 1e 60 27  xor  %i1, 0x27, %g1
a00b3ef4:  80 a0 00 01  cmp  %g0, %g1
a00b3ef8:  9a 60 3f ff  subx  %g0, -1, %o5
a00b3efc:  80 93 00 0d  orcc  %o4, %o5, %g0
a00b3f00:  32 80 00 11  bne,a   0xa00b3f44
a00b3f04:  a0 06 ff fe  add  %i3, -2, %l0
a00b3f08:  aa 10 20 07  mov  7, %l5
a00b3f0c:  ac 10 20 1c  mov  0x1c, %l6
a00b3f10:  a6 10 20 0b  mov  0xb, %l3
a00b3f14:  a8 10 20 1f  mov  0x1f, %l4
a00b3f18:  80 8e 20 ff  btst  0xff, %i0
a00b3f1c:  12 80 00 18  bne  0xa00b3f7c
a00b3f20:  90 10 20 01  mov  1, %o0
a00b3f24:  90 10 20 01  mov  1, %o0
a00b3f28:  92 10 20 00  clr  %o1
a00b3f2c:  40 02 4b 45  call  0xa0146c40
a00b3f30:  94 10 20 00  clr  %o2
a00b3f34:  b0 10 20 02  mov  2, %i0
a00b3f38:  b2 10 20 00  clr  %i1
a00b3f3c:  40 02 4b 41  call  0xa0146c40
a00b3f40:  95 e8 20 00  restore  %g0, 0, %o2
a00b3f44:  aa 10 20 02  mov  2, %l5
a00b3f48:  ac 10 20 03  mov  3, %l6
a00b3f4c:  a6 10 20 04  mov  4, %l3
a00b3f50:  80 8e 20 ff  btst  0xff, %i0
a00b3f54:  02 bf ff f4  be  0xa00b3f24
a00b3f58:  a8 10 20 05  mov  5, %l4
a00b3f5c:  10 80 00 08  b  0xa00b3f7c
a00b3f60:  90 10 20 01  mov  1, %o0
a00b3f64:  a0 06 ff fd  add  %i3, -3, %l0
a00b3f68:  aa 10 20 02  mov  2, %l5
a00b3f6c:  ac 10 20 03  mov  3, %l6
a00b3f70:  a6 10 20 04  mov  4, %l3
a00b3f74:  10 bf ff e9  b  0xa00b3f18
a00b3f78:  a8 10 20 04  mov  4, %l4
a00b3f7c:  92 10 20 00  clr  %o1
a00b3f80:  40 02 4b 30  call  0xa0146c40
a00b3f84:  94 10 20 00  clr  %o2
a00b3f88:  90 10 20 02  mov  2, %o0
a00b3f8c:  92 10 20 00  clr  %o1
a00b3f90:  40 02 4b 2c  call  0xa0146c40
a00b3f94:  94 10 20 00  clr  %o2
a00b3f98:  90 10 20 02  mov  2, %o0
a00b3f9c:  92 10 20 00  clr  %o1
a00b3fa0:  94 10 20 00  clr  %o2
a00b3fa4:  96 10 20 00  clr  %o3
a00b3fa8:  98 10 20 00  clr  %o4
a00b3fac:  9a 10 20 0e  mov  0xe, %o5
a00b3fb0:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00b3fb4:  c0 23 a0 60  clr  [ %sp + 0x60 ]
a00b3fb8:  c0 23 a0 64  clr  [ %sp + 0x64 ]
a00b3fbc:  c0 23 a0 68  clr  [ %sp + 0x68 ]
a00b3fc0:  40 02 49 af  call  0xa014667c
a00b3fc4:  c0 23 a0 6c  clr  [ %sp + 0x6c ]
a00b3fc8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00b3fcc:  b6 0e a0 ff  and  %i2, 0xff, %i3
a00b3fd0:  98 06 40 01  add  %i1, %g1, %o4
a00b3fd4:  b4 06 40 19  add  %i1, %i1, %i2
a00b3fd8:  9a 03 00 0c  add  %o4, %o4, %o5
a00b3fdc:  b0 06 80 19  add  %i2, %i1, %i0
a00b3fe0:  9e 03 40 0c  add  %o5, %o4, %o7
a00b3fe4:  b3 2e e0 03  sll  %i3, 3, %i1
a00b3fe8:  93 2b e0 03  sll  %o7, 3, %o1
a00b3fec:  96 06 40 1b  add  %i1, %i3, %o3
a00b3ff0:  95 2e 20 03  sll  %i0, 3, %o2
a00b3ff4:  a3 2a e0 02  sll  %o3, 2, %l1
a00b3ff8:  a0 02 a0 18  add  %o2, 0x18, %l0
a00b3ffc:  a4 02 60 17  add  %o1, 0x17, %l2
a00b4000:  90 10 20 02  mov  2, %o0
a00b4004:  92 10 00 10  mov  %l0, %o1
a00b4008:  94 04 60 16  add  %l1, 0x16, %o2
a00b400c:  96 10 00 12  mov  %l2, %o3
a00b4010:  98 04 60 19  add  %l1, 0x19, %o4
a00b4014:  40 02 4a 17  call  0xa0146870
a00b4018:  9a 10 20 00  clr  %o5
a00b401c:  aa 0d 60 ff  and  %l5, 0xff, %l5
a00b4020:  ac 0d a0 ff  and  %l6, 0xff, %l6
a00b4024:  90 10 20 02  mov  2, %o0
a00b4028:  92 10 20 00  clr  %o1
a00b402c:  94 10 20 00  clr  %o2
a00b4030:  96 10 20 01  mov  1, %o3
a00b4034:  98 10 00 15  mov  %l5, %o4
a00b4038:  9a 10 00 16  mov  %l6, %o5
a00b403c:  40 02 4a 3c  call  0xa014692c
a00b4040:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00b4044:  a6 0c e0 ff  and  %l3, 0xff, %l3
a00b4048:  a8 0d 20 ff  and  %l4, 0xff, %l4
a00b404c:  90 10 20 02  mov  2, %o0
a00b4050:  92 10 20 01  mov  1, %o1
a00b4054:  94 10 20 00  clr  %o2
a00b4058:  96 10 20 00  clr  %o3
a00b405c:  98 10 00 13  mov  %l3, %o4
a00b4060:  9a 10 00 14  mov  %l4, %o5
a00b4064:  40 02 4a 32  call  0xa014692c
a00b4068:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00b406c:  90 10 20 02  mov  2, %o0
a00b4070:  92 10 20 02  mov  2, %o1
a00b4074:  94 10 20 00  clr  %o2
a00b4078:  96 10 20 00  clr  %o3
a00b407c:  98 10 20 00  clr  %o4
a00b4080:  9a 10 20 00  clr  %o5
a00b4084:  40 02 4a 2a  call  0xa014692c
a00b4088:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00b408c:  90 10 20 01  mov  1, %o0
a00b4090:  92 10 20 00  clr  %o1
a00b4094:  94 10 20 00  clr  %o2
a00b4098:  96 10 20 00  clr  %o3
a00b409c:  98 10 20 00  clr  %o4
a00b40a0:  9a 10 20 0e  mov  0xe, %o5
a00b40a4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00b40a8:  c0 23 a0 60  clr  [ %sp + 0x60 ]
a00b40ac:  c0 23 a0 64  clr  [ %sp + 0x64 ]
a00b40b0:  c0 23 a0 68  clr  [ %sp + 0x68 ]
a00b40b4:  40 02 49 72  call  0xa014667c
a00b40b8:  c0 23 a0 6c  clr  [ %sp + 0x6c ]
a00b40bc:  92 10 00 10  mov  %l0, %o1
a00b40c0:  96 10 00 12  mov  %l2, %o3
a00b40c4:  98 04 60 55  add  %l1, 0x55, %o4
a00b40c8:  90 10 20 01  mov  1, %o0
a00b40cc:  94 04 60 52  add  %l1, 0x52, %o2
a00b40d0:  40 02 49 e8  call  0xa0146870
a00b40d4:  9a 10 20 00  clr  %o5
a00b40d8:  98 10 00 15  mov  %l5, %o4
a00b40dc:  9a 10 00 16  mov  %l6, %o5
a00b40e0:  90 10 20 01  mov  1, %o0
a00b40e4:  92 10 20 00  clr  %o1
a00b40e8:  94 10 20 00  clr  %o2
a00b40ec:  96 10 20 01  mov  1, %o3
a00b40f0:  40 02 4a 0f  call  0xa014692c
a00b40f4:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00b40f8:  98 10 00 13  mov  %l3, %o4
a00b40fc:  9a 10 00 14  mov  %l4, %o5
a00b4100:  90 10 20 01  mov  1, %o0
a00b4104:  92 10 20 01  mov  1, %o1
a00b4108:  94 10 20 00  clr  %o2
a00b410c:  96 10 20 00  clr  %o3
a00b4110:  40 02 4a 07  call  0xa014692c
a00b4114:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00b4118:  c0 23 a0 5c  clr  [ %sp + 0x5c ]
a00b411c:  90 10 20 01  mov  1, %o0
a00b4120:  92 10 20 02  mov  2, %o1
a00b4124:  94 10 20 00  clr  %o2
a00b4128:  96 10 20 00  clr  %o3
a00b412c:  98 10 20 00  clr  %o4
a00b4130:  40 02 49 ff  call  0xa014692c
a00b4134:  9a 10 20 00  clr  %o5
a00b4138:  01 00 00 00  nop
a00b413c:  81 c7 e0 08  ret
a00b4140:  81 e8 00 00  restore
