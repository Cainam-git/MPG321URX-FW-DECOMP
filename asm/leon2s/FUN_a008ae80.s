# leon2s FUN_a008ae80 0xa008ae80-0xa008b2b4 (1076 bytes)
a008ae80:  9d e3 bf 98  save  %sp, -104, %sp
a008ae84:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008ae88:  82 06 3f ff  add  %i0, -1, %g1
a008ae8c:  80 a0 60 12  cmp  %g1, 0x12
a008ae90:  18 80 01 08  bgu  0xa008b2b0
a008ae94:  1b 28 02 2b  sethi  %hi(0xa008ac00), %o5
a008ae98:  83 28 60 02  sll  %g1, 2, %g1
a008ae9c:  9a 13 62 34  or  %o5, 0x234, %o5
a008aea0:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a008aea4:  81 c0 40 00  jmp  %g1
a008aea8:  01 00 00 00  nop
a008aeac:  80 8e 60 ff  btst  0xff, %i1
a008aeb0:  02 80 01 00  be  0xa008b2b0
a008aeb4:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008aeb8:  9a 13 21 d4  or  %o4, 0x1d4, %o5	! 0xcf0111d4
a008aebc:  c2 03 40 00  ld  [ %o5 ], %g1
a008aec0:  10 80 00 08  b  0xa008aee0
a008aec4:  82 08 7f fe  and  %g1, -2, %g1
a008aec8:  80 8e 60 ff  btst  0xff, %i1
a008aecc:  02 80 00 f9  be  0xa008b2b0
a008aed0:  19 33 c0 44  sethi  %hi(0xcf011000), %o4
a008aed4:  9a 13 21 d4  or  %o4, 0x1d4, %o5	! 0xcf0111d4
a008aed8:  c2 03 40 00  ld  [ %o5 ], %g1
a008aedc:  82 10 60 01  or  %g1, 1, %g1
a008aee0:  c2 23 40 00  st  %g1, [ %o5 ]
a008aee4:  9a 13 21 18  or  %o4, 0x118, %o5
a008aee8:  c2 03 40 00  ld  [ %o5 ], %g1
a008aeec:  82 10 60 01  or  %g1, 1, %g1
a008aef0:  c2 23 40 00  st  %g1, [ %o5 ]
a008aef4:  c2 03 40 00  ld  [ %o5 ], %g1
a008aef8:  82 08 7f fe  and  %g1, -2, %g1
a008aefc:  c2 23 40 00  st  %g1, [ %o5 ]
a008af00:  9a 13 21 dc  or  %o4, 0x1dc, %o5
a008af04:  c2 03 40 00  ld  [ %o5 ], %g1
a008af08:  82 10 60 08  or  %g1, 8, %g1
a008af0c:  c2 23 40 00  st  %g1, [ %o5 ]
a008af10:  c2 03 40 00  ld  [ %o5 ], %g1
a008af14:  82 08 7f f7  and  %g1, -9, %g1
a008af18:  c2 23 40 00  st  %g1, [ %o5 ]
a008af1c:  98 13 21 48  or  %o4, 0x148, %o4
a008af20:  c2 03 00 00  ld  [ %o4 ], %g1
a008af24:  82 10 60 80  or  %g1, 0x80, %g1
a008af28:  c2 23 00 00  st  %g1, [ %o4 ]
a008af2c:  30 80 00 e1  b,a   0xa008b2b0
a008af30:  80 8e 60 ff  btst  0xff, %i1
a008af34:  12 80 00 06  bne  0xa008af4c
a008af38:  9a 10 20 f4  mov  0xf4, %o5
a008af3c:  30 80 00 dd  b,a   0xa008b2b0
a008af40:  80 8e 60 ff  btst  0xff, %i1
a008af44:  02 80 00 db  be  0xa008b2b0
a008af48:  9a 10 20 f2  mov  0xf2, %o5
a008af4c:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008af50:  10 80 00 08  b  0xa008af70
a008af54:  82 10 60 c0  or  %g1, 0xc0, %g1	! 0xcf0110c0
a008af58:  80 8e 60 ff  btst  0xff, %i1
a008af5c:  02 80 00 d5  be  0xa008b2b0
a008af60:  03 33 c0 44  sethi  %hi(0xcf011000), %g1
a008af64:  82 10 61 48  or  %g1, 0x148, %g1	! 0xcf011148
a008af68:  c0 20 40 00  clr  [ %g1 ]
a008af6c:  9a 10 20 87  mov  0x87, %o5
a008af70:  da 20 40 00  st  %o5, [ %g1 ]
a008af74:  30 80 00 cf  b,a   0xa008b2b0
a008af78:  80 8e 60 ff  btst  0xff, %i1
a008af7c:  02 80 00 1c  be  0xa008afec
a008af80:  90 10 20 00  clr  %o0
a008af84:  92 10 21 27  mov  0x127, %o1
a008af88:  94 10 20 20  mov  0x20, %o2
a008af8c:  40 00 6e 0b  call  0xa00a67b8
a008af90:  96 10 20 01  mov  1, %o3
a008af94:  90 10 20 00  clr  %o0
a008af98:  92 10 21 27  mov  0x127, %o1
a008af9c:  94 10 20 10  mov  0x10, %o2
a008afa0:  40 00 6e 06  call  0xa00a67b8
a008afa4:  96 10 20 01  mov  1, %o3
a008afa8:  90 10 20 00  clr  %o0
a008afac:  92 10 21 29  mov  0x129, %o1
a008afb0:  94 10 20 04  mov  4, %o2
a008afb4:  40 00 6e 01  call  0xa00a67b8
a008afb8:  96 10 20 01  mov  1, %o3
a008afbc:  90 10 20 00  clr  %o0
a008afc0:  92 10 21 29  mov  0x129, %o1
a008afc4:  94 10 20 01  mov  1, %o2
a008afc8:  40 00 6d fc  call  0xa00a67b8
a008afcc:  96 10 20 01  mov  1, %o3
a008afd0:  90 10 20 00  clr  %o0
a008afd4:  92 10 21 29  mov  0x129, %o1
a008afd8:  94 10 20 02  mov  2, %o2
a008afdc:  40 00 6d f7  call  0xa00a67b8
a008afe0:  96 10 20 01  mov  1, %o3
a008afe4:  10 80 00 38  b  0xa008b0c4
a008afe8:  b0 10 20 00  clr  %i0
a008afec:  92 10 21 27  mov  0x127, %o1
a008aff0:  94 10 20 20  mov  0x20, %o2
a008aff4:  40 00 6d f1  call  0xa00a67b8
a008aff8:  96 10 20 00  clr  %o3
a008affc:  90 10 20 00  clr  %o0
a008b000:  92 10 21 27  mov  0x127, %o1
a008b004:  94 10 20 10  mov  0x10, %o2
a008b008:  40 00 6d ec  call  0xa00a67b8
a008b00c:  96 10 20 00  clr  %o3
a008b010:  90 10 20 00  clr  %o0
a008b014:  92 10 21 29  mov  0x129, %o1
a008b018:  94 10 20 04  mov  4, %o2
a008b01c:  40 00 6d e7  call  0xa00a67b8
a008b020:  96 10 20 00  clr  %o3
a008b024:  90 10 20 00  clr  %o0
a008b028:  92 10 21 29  mov  0x129, %o1
a008b02c:  94 10 20 01  mov  1, %o2
a008b030:  40 00 6d e2  call  0xa00a67b8
a008b034:  96 10 20 00  clr  %o3
a008b038:  90 10 20 00  clr  %o0
a008b03c:  92 10 21 29  mov  0x129, %o1
a008b040:  94 10 20 02  mov  2, %o2
a008b044:  40 00 6d dd  call  0xa00a67b8
a008b048:  96 10 20 00  clr  %o3
a008b04c:  10 80 00 3b  b  0xa008b138
a008b050:  b0 10 20 00  clr  %i0
a008b054:  80 8e 60 ff  btst  0xff, %i1
a008b058:  02 80 00 1f  be  0xa008b0d4
a008b05c:  90 10 20 01  mov  1, %o0
a008b060:  92 10 21 27  mov  0x127, %o1
a008b064:  94 10 20 20  mov  0x20, %o2
a008b068:  40 00 6d d4  call  0xa00a67b8
a008b06c:  96 10 20 01  mov  1, %o3
a008b070:  90 10 20 01  mov  1, %o0
a008b074:  92 10 21 27  mov  0x127, %o1
a008b078:  94 10 20 10  mov  0x10, %o2
a008b07c:  40 00 6d cf  call  0xa00a67b8
a008b080:  96 10 20 01  mov  1, %o3
a008b084:  90 10 20 01  mov  1, %o0
a008b088:  92 10 21 29  mov  0x129, %o1
a008b08c:  94 10 20 04  mov  4, %o2
a008b090:  40 00 6d ca  call  0xa00a67b8
a008b094:  96 10 20 01  mov  1, %o3
a008b098:  90 10 20 01  mov  1, %o0
a008b09c:  92 10 21 29  mov  0x129, %o1
a008b0a0:  94 10 20 01  mov  1, %o2
a008b0a4:  40 00 6d c5  call  0xa00a67b8
a008b0a8:  96 10 20 01  mov  1, %o3
a008b0ac:  90 10 20 01  mov  1, %o0
a008b0b0:  92 10 21 29  mov  0x129, %o1
a008b0b4:  94 10 20 02  mov  2, %o2
a008b0b8:  40 00 6d c0  call  0xa00a67b8
a008b0bc:  96 10 20 01  mov  1, %o3
a008b0c0:  b0 10 20 01  mov  1, %i0
a008b0c4:  b2 10 21 37  mov  0x137, %i1
a008b0c8:  b4 10 20 02  mov  2, %i2
a008b0cc:  10 80 00 1e  b  0xa008b144
a008b0d0:  b6 10 20 00  clr  %i3
a008b0d4:  92 10 21 27  mov  0x127, %o1
a008b0d8:  94 10 20 20  mov  0x20, %o2
a008b0dc:  40 00 6d b7  call  0xa00a67b8
a008b0e0:  96 10 20 00  clr  %o3
a008b0e4:  90 10 20 01  mov  1, %o0
a008b0e8:  92 10 21 27  mov  0x127, %o1
a008b0ec:  94 10 20 10  mov  0x10, %o2
a008b0f0:  40 00 6d b2  call  0xa00a67b8
a008b0f4:  96 10 20 00  clr  %o3
a008b0f8:  90 10 20 01  mov  1, %o0
a008b0fc:  92 10 21 29  mov  0x129, %o1
a008b100:  94 10 20 04  mov  4, %o2
a008b104:  40 00 6d ad  call  0xa00a67b8
a008b108:  96 10 20 00  clr  %o3
a008b10c:  90 10 20 01  mov  1, %o0
a008b110:  92 10 21 29  mov  0x129, %o1
a008b114:  94 10 20 01  mov  1, %o2
a008b118:  40 00 6d a8  call  0xa00a67b8
a008b11c:  96 10 20 00  clr  %o3
a008b120:  90 10 20 01  mov  1, %o0
a008b124:  92 10 21 29  mov  0x129, %o1
a008b128:  94 10 20 02  mov  2, %o2
a008b12c:  40 00 6d a3  call  0xa00a67b8
a008b130:  96 10 20 00  clr  %o3
a008b134:  b0 10 20 01  mov  1, %i0
a008b138:  b2 10 21 37  mov  0x137, %i1
a008b13c:  b4 10 20 02  mov  2, %i2
a008b140:  b6 10 20 01  mov  1, %i3
a008b144:  40 00 6d 9d  call  0xa00a67b8
a008b148:  81 e8 00 00  restore
a008b14c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008b150:  10 80 00 04  b  0xa008b160
a008b154:  b0 10 20 00  clr  %i0
a008b158:  b2 0e 60 ff  and  %i1, 0xff, %i1
a008b15c:  b0 10 20 01  mov  1, %i0
a008b160:  40 00 5a 94  call  0xa00a1bb0
a008b164:  81 e8 00 00  restore
a008b168:  80 8e 60 ff  btst  0xff, %i1
a008b16c:  02 80 00 26  be  0xa008b204
a008b170:  90 10 20 00  clr  %o0
a008b174:  92 10 20 55  mov  0x55, %o1
a008b178:  94 10 20 80  mov  0x80, %o2
a008b17c:  40 00 6e c7  call  0xa00a6c98
a008b180:  96 10 20 01  mov  1, %o3
a008b184:  90 10 20 00  clr  %o0
a008b188:  92 10 20 58  mov  0x58, %o1
a008b18c:  94 10 20 80  mov  0x80, %o2
a008b190:  40 00 6e c2  call  0xa00a6c98
a008b194:  96 10 20 01  mov  1, %o3
a008b198:  90 10 20 00  clr  %o0
a008b19c:  92 10 20 5a  mov  0x5a, %o1
a008b1a0:  94 10 20 80  mov  0x80, %o2
a008b1a4:  40 00 6e bd  call  0xa00a6c98
a008b1a8:  96 10 20 01  mov  1, %o3
a008b1ac:  7f c4 ed 3a  call  0x9f1c6694
a008b1b0:  90 10 20 00  clr  %o0
a008b1b4:  80 8a 20 ff  btst  0xff, %o0
a008b1b8:  02 80 00 0a  be  0xa008b1e0
a008b1bc:  90 10 20 00  clr  %o0
a008b1c0:  92 10 20 7d  mov  0x7d, %o1
a008b1c4:  94 10 20 10  mov  0x10, %o2
a008b1c8:  40 00 6e b4  call  0xa00a6c98
a008b1cc:  96 10 20 01  mov  1, %o3
a008b1d0:  b0 10 20 00  clr  %i0
a008b1d4:  b2 10 20 7e  mov  0x7e, %i1
a008b1d8:  10 80 00 09  b  0xa008b1fc
a008b1dc:  b4 10 20 ff  mov  0xff, %i2
a008b1e0:  92 10 20 7d  mov  0x7d, %o1
a008b1e4:  94 10 20 10  mov  0x10, %o2
a008b1e8:  40 00 6e ac  call  0xa00a6c98
a008b1ec:  96 10 20 00  clr  %o3
a008b1f0:  b0 10 20 00  clr  %i0
a008b1f4:  b2 10 20 7e  mov  0x7e, %i1
a008b1f8:  b4 10 20 00  clr  %i2
a008b1fc:  40 00 6e 81  call  0xa00a6c00
a008b200:  81 e8 00 00  restore
a008b204:  92 10 20 55  mov  0x55, %o1
a008b208:  94 10 20 80  mov  0x80, %o2
a008b20c:  40 00 6e a3  call  0xa00a6c98
a008b210:  96 10 20 00  clr  %o3
a008b214:  90 10 20 00  clr  %o0
a008b218:  92 10 20 58  mov  0x58, %o1
a008b21c:  94 10 20 80  mov  0x80, %o2
a008b220:  40 00 6e 9e  call  0xa00a6c98
a008b224:  96 10 20 00  clr  %o3
a008b228:  10 80 00 1d  b  0xa008b29c
a008b22c:  b0 10 20 00  clr  %i0
a008b230:  80 8e 60 ff  btst  0xff, %i1
a008b234:  02 80 00 10  be  0xa008b274
a008b238:  90 10 20 01  mov  1, %o0
a008b23c:  92 10 20 55  mov  0x55, %o1
a008b240:  94 10 20 80  mov  0x80, %o2
a008b244:  40 00 6e 95  call  0xa00a6c98
a008b248:  96 10 20 01  mov  1, %o3
a008b24c:  90 10 20 01  mov  1, %o0
a008b250:  92 10 20 58  mov  0x58, %o1
a008b254:  94 10 20 80  mov  0x80, %o2
a008b258:  40 00 6e 90  call  0xa00a6c98
a008b25c:  96 10 20 01  mov  1, %o3
a008b260:  b0 10 20 01  mov  1, %i0
a008b264:  b2 10 20 5a  mov  0x5a, %i1
a008b268:  b4 10 20 80  mov  0x80, %i2
a008b26c:  10 80 00 0f  b  0xa008b2a8
a008b270:  b6 10 20 01  mov  1, %i3
a008b274:  92 10 20 55  mov  0x55, %o1
a008b278:  94 10 20 80  mov  0x80, %o2
a008b27c:  40 00 6e 87  call  0xa00a6c98
a008b280:  96 10 20 00  clr  %o3
a008b284:  90 10 20 01  mov  1, %o0
a008b288:  92 10 20 58  mov  0x58, %o1
a008b28c:  94 10 20 80  mov  0x80, %o2
a008b290:  40 00 6e 82  call  0xa00a6c98
a008b294:  96 10 20 00  clr  %o3
a008b298:  b0 10 20 01  mov  1, %i0
a008b29c:  b2 10 20 5a  mov  0x5a, %i1
a008b2a0:  b4 10 20 80  mov  0x80, %i2
a008b2a4:  b6 10 20 00  clr  %i3
a008b2a8:  40 00 6e 7c  call  0xa00a6c98
a008b2ac:  81 e8 00 00  restore
a008b2b0:  01 00 00 00  nop
