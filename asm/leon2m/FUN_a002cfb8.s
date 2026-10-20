# leon2m FUN_a002cfb8 0xa002cfb8-0xa002d10c (340 bytes)
a002cfb8:  9d e3 bf 98  save  %sp, -104, %sp
a002cfbc:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a002cfc0:  96 10 20 01  mov  1, %o3
a002cfc4:  da 03 20 c0  ld  [ %o4 + 0xc0 ], %o5
a002cfc8:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a002cfcc:  80 a3 60 00  cmp  %o5, 0
a002cfd0:  02 80 00 05  be  0xa002cfe4
a002cfd4:  d6 28 62 42  stb  %o3, [ %g1 + 0x242 ]
a002cfd8:  d2 03 20 c0  ld  [ %o4 + 0xc0 ], %o1
a002cfdc:  90 02 7f ff  add  %o1, -1, %o0
a002cfe0:  d0 23 20 c0  st  %o0, [ %o4 + 0xc0 ]
a002cfe4:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a002cfe8:  d4 03 62 3c  ld  [ %o5 + 0x23c ], %o2	! 0xa802d63c
a002cfec:  82 02 a0 01  add  %o2, 1, %g1
a002cff0:  80 a0 60 04  cmp  %g1, 4
a002cff4:  28 80 00 05  bleu,a   0xa002d008
a002cff8:  c2 23 62 3c  st  %g1, [ %o5 + 0x23c ]
a002cffc:  19 2a 00 b5  sethi  %hi(0xa802d400), %o4
a002d000:  d6 2b 22 4c  stb  %o3, [ %o4 + 0x24c ]	! 0xa802d64c
a002d004:  c0 23 62 3c  clr  [ %o5 + 0x23c ]
a002d008:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a002d00c:  de 03 62 50  ld  [ %o5 + 0x250 ], %o7	! 0xa802d650
a002d010:  82 03 e0 01  add  %o7, 1, %g1
a002d014:  80 a0 60 31  cmp  %g1, 0x31
a002d018:  28 80 00 05  bleu,a   0xa002d02c
a002d01c:  c2 23 62 50  st  %g1, [ %o5 + 0x250 ]
a002d020:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a002d024:  d6 28 62 40  stb  %o3, [ %g1 + 0x240 ]	! 0xa802d640
a002d028:  c0 23 62 50  clr  [ %o5 + 0x250 ]
a002d02c:  1b 2a 00 b5  sethi  %hi(0xa802d400), %o5
a002d030:  d0 03 62 44  ld  [ %o5 + 0x244 ], %o0	! 0xa802d644
a002d034:  82 02 20 01  add  %o0, 1, %g1
a002d038:  80 a0 61 f3  cmp  %g1, 0x1f3
a002d03c:  28 80 00 05  bleu,a   0xa002d050
a002d040:  c2 23 62 44  st  %g1, [ %o5 + 0x244 ]
a002d044:  13 2a 00 b5  sethi  %hi(0xa802d400), %o1
a002d048:  d6 2a 62 41  stb  %o3, [ %o1 + 0x241 ]	! 0xa802d641
a002d04c:  c0 23 62 44  clr  [ %o5 + 0x244 ]
a002d050:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a002d054:  da 0a a0 bc  ldub  [ %o2 + 0xbc ], %o5	! 0xa802b0bc
a002d058:  80 a3 60 00  cmp  %o5, 0
a002d05c:  22 80 00 0c  be,a   0xa002d08c
a002d060:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a002d064:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a002d068:  d8 03 60 b8  ld  [ %o5 + 0xb8 ], %o4	! 0xa802b0b8
a002d06c:  82 03 20 01  add  %o4, 1, %g1
a002d070:  80 a0 60 7f  cmp  %g1, 0x7f
a002d074:  28 80 00 12  bleu,a   0xa002d0bc
a002d078:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a002d07c:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a002d080:  d6 2b e0 bd  stb  %o3, [ %o7 + 0xbd ]	! 0xa802b0bd
a002d084:  c0 23 60 b8  clr  [ %o5 + 0xb8 ]
a002d088:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a002d08c:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a002d090:  90 13 20 c4  or  %o4, 0xc4, %o0	! 0xa802b0c4
a002d094:  d4 02 e2 48  ld  [ %o3 + 0x248 ], %o2
a002d098:  da 02 20 04  ld  [ %o0 + 4 ], %o5
a002d09c:  82 02 a0 01  add  %o2, 1, %g1
a002d0a0:  92 03 60 01  add  %o5, 1, %o1
a002d0a4:  d4 02 20 0c  ld  [ %o0 + 0xc ], %o2
a002d0a8:  c2 22 e2 48  st  %g1, [ %o3 + 0x248 ]
a002d0ac:  80 a2 a0 00  cmp  %o2, 0
a002d0b0:  02 80 00 11  be  0xa002d0f4
a002d0b4:  d2 22 20 04  st  %o1, [ %o0 + 4 ]
a002d0b8:  30 80 00 0d  b,a   0xa002d0ec
a002d0bc:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a002d0c0:  90 13 20 c4  or  %o4, 0xc4, %o0	! 0xa802b0c4
a002d0c4:  d4 02 e2 48  ld  [ %o3 + 0x248 ], %o2
a002d0c8:  c2 23 60 b8  st  %g1, [ %o5 + 0xb8 ]
a002d0cc:  da 02 20 04  ld  [ %o0 + 4 ], %o5
a002d0d0:  82 02 a0 01  add  %o2, 1, %g1
a002d0d4:  92 03 60 01  add  %o5, 1, %o1
a002d0d8:  d4 02 20 0c  ld  [ %o0 + 0xc ], %o2
a002d0dc:  c2 22 e2 48  st  %g1, [ %o3 + 0x248 ]
a002d0e0:  80 a2 a0 00  cmp  %o2, 0
a002d0e4:  02 80 00 04  be  0xa002d0f4
a002d0e8:  d2 22 20 04  st  %o1, [ %o0 + 4 ]
a002d0ec:  9f c2 80 00  call  %o2
a002d0f0:  90 10 20 00  clr  %o0
a002d0f4:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a002d0f8:  d2 03 e0 b4  ld  [ %o7 + 0xb4 ], %o1	! 0xa802b0b4
a002d0fc:  90 02 60 01  add  %o1, 1, %o0
a002d100:  d0 23 e0 b4  st  %o0, [ %o7 + 0xb4 ]
a002d104:  81 c7 e0 08  ret
a002d108:  81 e8 00 00  restore
