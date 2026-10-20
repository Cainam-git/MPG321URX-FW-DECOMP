# leon2m FUN_a00dac38 0xa00dac38-0xa00db054 (1052 bytes)
a00dac38:  9d e3 bf 40  save  %sp, -192, %sp
a00dac3c:  40 01 ab af  call  0xa0145af8
a00dac40:  90 10 20 02  mov  2, %o0
a00dac44:  83 2a 20 10  sll  %o0, 0x10, %g1
a00dac48:  91 30 60 10  srl  %g1, 0x10, %o0
a00dac4c:  80 a2 20 01  cmp  %o0, 1
a00dac50:  02 80 00 e3  be  0xa00dafdc
a00dac54:  b8 10 20 14  mov  0x14, %i4
a00dac58:  92 10 20 08  mov  8, %o1
a00dac5c:  40 01 aa 81  call  0xa0145660
a00dac60:  90 10 20 00  clr  %o0
a00dac64:  92 10 20 07  mov  7, %o1
a00dac68:  40 01 aa 7e  call  0xa0145660
a00dac6c:  90 10 20 00  clr  %o0
a00dac70:  92 10 20 01  mov  1, %o1
a00dac74:  40 01 aa 7b  call  0xa0145660
a00dac78:  90 10 20 00  clr  %o0
a00dac7c:  ac 10 00 08  mov  %o0, %l6
a00dac80:  92 10 20 00  clr  %o1
a00dac84:  40 01 aa 77  call  0xa0145660
a00dac88:  90 10 20 00  clr  %o0
a00dac8c:  a0 10 00 08  mov  %o0, %l0
a00dac90:  92 10 20 0a  mov  0xa, %o1
a00dac94:  40 01 aa 73  call  0xa0145660
a00dac98:  90 10 20 00  clr  %o0
a00dac9c:  92 0e a0 ff  and  %i2, 0xff, %o1
a00daca0:  80 a2 60 01  cmp  %o1, 1
a00daca4:  02 80 00 9d  be  0xa00daf18
a00daca8:  a4 10 00 08  mov  %o0, %l2
a00dacac:  40 00 b8 6a  call  0xa0108e54
a00dacb0:  23 00 06 62  sethi  %hi(0x198800), %l1
a00dacb4:  9b 2c 20 10  sll  %l0, 0x10, %o5
a00dacb8:  a9 33 60 10  srl  %o5, 0x10, %l4
a00dacbc:  19 00 06 62  sethi  %hi(0x198800), %o4
a00dacc0:  92 0a 20 ff  and  %o0, 0xff, %o1
a00dacc4:  90 13 21 70  or  %o4, 0x170, %o0
a00dacc8:  40 00 11 2a  call  0xa00df170
a00daccc:  94 10 00 14  mov  %l4, %o2
a00dacd0:  40 00 b8 61  call  0xa0108e54
a00dacd4:  a1 2c a0 10  sll  %l2, 0x10, %l0
a00dacd8:  92 0a 20 ff  and  %o0, 0xff, %o1
a00dacdc:  a5 34 20 10  srl  %l0, 0x10, %l2
a00dace0:  94 10 00 12  mov  %l2, %o2
a00dace4:  40 00 11 23  call  0xa00df170
a00dace8:  90 14 61 50  or  %l1, 0x150, %o0
a00dacec:  40 00 b8 5a  call  0xa0108e54
a00dacf0:  ad 2d a0 10  sll  %l6, 0x10, %l6
a00dacf4:  17 00 06 62  sethi  %hi(0x198800), %o3
a00dacf8:  92 0a 20 ff  and  %o0, 0xff, %o1
a00dacfc:  90 12 e1 90  or  %o3, 0x190, %o0
a00dad00:  40 00 11 1c  call  0xa00df170
a00dad04:  95 35 a0 10  srl  %l6, 0x10, %o2
a00dad08:  1f 04 18 93  sethi  %hi(0x10624c00), %o7
a00dad0c:  94 13 e1 d3  or  %o7, 0x1d3, %o2	! 0x10624dd3
a00dad10:  80 56 00 0a  umul  %i0, %o2, %g0
a00dad14:  93 40 00 00  rd  %y, %o1
a00dad18:  03 00 06 62  sethi  %hi(0x198800), %g1
a00dad1c:  93 32 60 06  srl  %o1, 6, %o1
a00dad20:  40 00 11 14  call  0xa00df170
a00dad24:  90 10 61 b0  or  %g1, 0x1b0, %o0
a00dad28:  11 37 d2 a4  sethi  %hi(0xdf4a9000), %o0
a00dad2c:  ba 12 23 69  or  %o0, 0x369, %i5	! 0xdf4a9369
a00dad30:  80 56 00 1d  umul  %i0, %i5, %g0
a00dad34:  b7 40 00 00  rd  %y, %i3
a00dad38:  93 36 e0 0b  srl  %i3, 0xb, %o1
a00dad3c:  35 00 06 62  sethi  %hi(0x198800), %i2
a00dad40:  90 16 a1 d8  or  %i2, 0x1d8, %o0	! 0x1989d8
a00dad44:  94 10 00 09  mov  %o1, %o2
a00dad48:  40 00 11 0a  call  0xa00df170
a00dad4c:  96 10 00 09  mov  %o1, %o3
a00dad50:  33 2a 00 b8  sethi  %hi(0xa802e000), %i1
a00dad54:  f0 0e 61 a7  ldub  [ %i1 + 0x1a7 ], %i0	! 0xa802e1a7
a00dad58:  80 a0 00 18  cmp  %g0, %i0
a00dad5c:  aa 60 3f ff  subx  %g0, -1, %l5
a00dad60:  ae 1e 20 02  xor  %i0, 2, %l7
a00dad64:  80 a0 00 17  cmp  %g0, %l7
a00dad68:  a6 60 3f ff  subx  %g0, -1, %l3
a00dad6c:  80 95 40 13  orcc  %l5, %l3, %g0
a00dad70:  02 80 00 42  be  0xa00dae78
a00dad74:  80 a4 a0 00  cmp  %l2, 0
a00dad78:  02 80 00 09  be  0xa00dad9c
a00dad7c:  a0 5d 23 e8  smul  %l4, 0x3e8, %l0
a00dad80:  a6 5d 28 70  smul  %l4, 0x870, %l3
a00dad84:  81 80 00 00  mov  %g0, %y
a00dad88:  01 00 00 00  nop
a00dad8c:  01 00 00 00  nop
a00dad90:  01 00 00 00  nop
a00dad94:  a8 74 c0 12  udiv  %l3, %l2, %l4
a00dad98:  a0 5d 23 e8  smul  %l4, 0x3e8, %l0
a00dad9c:  40 01 b5 e9  call  0xa0148540
a00dada0:  90 10 20 00  clr  %o0
a00dada4:  80 8a 20 ff  btst  0xff, %o0
a00dada8:  02 80 00 8f  be  0xa00dafe4
a00dadac:  9a 0f 20 ff  and  %i4, 0xff, %o5
a00dadb0:  39 37 d2 a4  sethi  %hi(0xdf4a9000), %i4
a00dadb4:  ac 17 23 69  or  %i4, 0x369, %l6	! 0xdf4a9369
a00dadb8:  80 54 00 16  umul  %l0, %l6, %g0
a00dadbc:  a5 40 00 00  rd  %y, %l2
a00dadc0:  83 34 a0 0b  srl  %l2, 0xb, %g1
a00dadc4:  80 a0 62 bb  cmp  %g1, 0x2bb
a00dadc8:  18 80 00 92  bgu  0xa00db010
a00dadcc:  a0 10 20 02  mov  2, %l0
a00dadd0:  40 01 39 fd  call  0xa01295c4
a00dadd4:  01 00 00 00  nop
a00dadd8:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00daddc:  82 0c 20 ff  and  %l0, 0xff, %g1
a00dade0:  80 a6 00 01  cmp  %i0, %g1
a00dade4:  02 80 00 90  be  0xa00db024
a00dade8:  01 00 00 00  nop
a00dadec:  40 01 39 f3  call  0xa01295b8
a00dadf0:  90 10 00 01  mov  %g1, %o0
a00dadf4:  11 00 06 60  sethi  %hi(0x198000), %o0
a00dadf8:  40 01 39 f3  call  0xa01295c4
a00dadfc:  b6 12 23 80  or  %o0, 0x380, %i3	! 0x198380
a00dae00:  ba 0a 20 ff  and  %o0, 0xff, %i5
a00dae04:  b4 5f 60 58  smul  %i5, 0x58, %i2
a00dae08:  82 06 80 1b  add  %i2, %i3, %g1
a00dae0c:  d8 18 60 50  ldd  [ %g1 + 0x50 ], %o4
a00dae10:  b2 06 c0 1a  add  %i3, %i2, %i1
a00dae14:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a00dae18:  d0 18 60 10  ldd  [ %g1 + 0x10 ], %o0
a00dae1c:  d8 1e 40 00  ldd  [ %i1 ], %o4
a00dae20:  d0 3f bf b0  std  %o0, [ %fp + -80 ]
a00dae24:  d4 18 60 08  ldd  [ %g1 + 8 ], %o2
a00dae28:  e0 18 60 18  ldd  [ %g1 + 0x18 ], %l0
a00dae2c:  e4 18 60 20  ldd  [ %g1 + 0x20 ], %l2
a00dae30:  e8 18 60 28  ldd  [ %g1 + 0x28 ], %l4
a00dae34:  ec 18 60 30  ldd  [ %g1 + 0x30 ], %l6
a00dae38:  f8 18 60 38  ldd  [ %g1 + 0x38 ], %i4
a00dae3c:  f4 18 60 40  ldd  [ %g1 + 0x40 ], %i2
a00dae40:  f0 18 60 48  ldd  [ %g1 + 0x48 ], %i0
a00dae44:  d8 3f bf a0  std  %o4, [ %fp + -96 ]
a00dae48:  d4 3f bf a8  std  %o2, [ %fp + -88 ]
a00dae4c:  e0 3f bf b8  std  %l0, [ %fp + -72 ]
a00dae50:  e4 3f bf c0  std  %l2, [ %fp + -64 ]
a00dae54:  e8 3f bf c8  std  %l4, [ %fp + -56 ]
a00dae58:  ec 3f bf d0  std  %l6, [ %fp + -48 ]
a00dae5c:  f8 3f bf d8  std  %i4, [ %fp + -40 ]
a00dae60:  f4 3f bf e0  std  %i2, [ %fp + -32 ]
a00dae64:  f0 3f bf e8  std  %i0, [ %fp + -24 ]
a00dae68:  90 07 bf a0  add  %fp, -96, %o0
a00dae6c:  40 01 b5 62  call  0xa01483f4
a00dae70:  92 10 20 01  mov  1, %o1
a00dae74:  30 80 00 6c  b,a   0xa00db024
a00dae78:  40 01 39 d3  call  0xa01295c4
a00dae7c:  01 00 00 00  nop
a00dae80:  92 0a 20 ff  and  %o0, 0xff, %o1
a00dae84:  80 a2 60 01  cmp  %o1, 1
a00dae88:  02 80 00 67  be  0xa00db024
a00dae8c:  01 00 00 00  nop
a00dae90:  40 01 39 ca  call  0xa01295b8
a00dae94:  90 10 20 01  mov  1, %o0	! 0x1
a00dae98:  40 01 39 cb  call  0xa01295c4
a00dae9c:  21 00 06 60  sethi  %hi(0x198000), %l0
a00daea0:  98 0a 20 ff  and  %o0, 0xff, %o4
a00daea4:  96 5b 20 58  smul  %o4, 0x58, %o3
a00daea8:  a2 14 23 80  or  %l0, 0x380, %l1
a00daeac:  9e 02 c0 11  add  %o3, %l1, %o7
a00daeb0:  d8 1b e0 50  ldd  [ %o7 + 0x50 ], %o4
a00daeb4:  94 04 40 0b  add  %l1, %o3, %o2
a00daeb8:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a00daebc:  d0 1b e0 10  ldd  [ %o7 + 0x10 ], %o0
a00daec0:  d8 1a 80 00  ldd  [ %o2 ], %o4
a00daec4:  d0 3f bf b0  std  %o0, [ %fp + -80 ]
a00daec8:  d4 1b e0 08  ldd  [ %o7 + 8 ], %o2
a00daecc:  e0 1b e0 18  ldd  [ %o7 + 0x18 ], %l0
a00daed0:  e4 1b e0 20  ldd  [ %o7 + 0x20 ], %l2
a00daed4:  e8 1b e0 28  ldd  [ %o7 + 0x28 ], %l4
a00daed8:  ec 1b e0 30  ldd  [ %o7 + 0x30 ], %l6
a00daedc:  f8 1b e0 38  ldd  [ %o7 + 0x38 ], %i4
a00daee0:  f4 1b e0 40  ldd  [ %o7 + 0x40 ], %i2
a00daee4:  f0 1b e0 48  ldd  [ %o7 + 0x48 ], %i0
a00daee8:  d8 3f bf a0  std  %o4, [ %fp + -96 ]
a00daeec:  d4 3f bf a8  std  %o2, [ %fp + -88 ]
a00daef0:  e0 3f bf b8  std  %l0, [ %fp + -72 ]
a00daef4:  e4 3f bf c0  std  %l2, [ %fp + -64 ]
a00daef8:  e8 3f bf c8  std  %l4, [ %fp + -56 ]
a00daefc:  ec 3f bf d0  std  %l6, [ %fp + -48 ]
a00daf00:  f8 3f bf d8  std  %i4, [ %fp + -40 ]
a00daf04:  f4 3f bf e0  std  %i2, [ %fp + -32 ]
a00daf08:  f0 3f bf e8  std  %i0, [ %fp + -24 ]
a00daf0c:  90 07 bf a0  add  %fp, -96, %o0
a00daf10:  10 80 00 29  b  0xa00dafb4
a00daf14:  92 10 20 00  clr  %o1
a00daf18:  40 01 39 ab  call  0xa01295c4
a00daf1c:  01 00 00 00  nop
a00daf20:  94 0a 20 ff  and  %o0, 0xff, %o2
a00daf24:  80 a2 a0 01  cmp  %o2, 1
a00daf28:  02 80 00 3f  be  0xa00db024
a00daf2c:  01 00 00 00  nop
a00daf30:  40 01 39 a2  call  0xa01295b8
a00daf34:  90 10 20 01  mov  1, %o0	! 0x1
a00daf38:  1b 00 06 60  sethi  %hi(0x198000), %o5
a00daf3c:  40 01 39 a2  call  0xa01295c4
a00daf40:  a0 13 63 80  or  %o5, 0x380, %l0	! 0x198380
a00daf44:  98 0a 20 ff  and  %o0, 0xff, %o4
a00daf48:  a2 5b 20 58  smul  %o4, 0x58, %l1
a00daf4c:  9e 04 40 10  add  %l1, %l0, %o7
a00daf50:  d8 1b e0 50  ldd  [ %o7 + 0x50 ], %o4
a00daf54:  96 04 00 11  add  %l0, %l1, %o3
a00daf58:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a00daf5c:  d0 1b e0 10  ldd  [ %o7 + 0x10 ], %o0
a00daf60:  d8 1a c0 00  ldd  [ %o3 ], %o4
a00daf64:  d0 3f bf b0  std  %o0, [ %fp + -80 ]
a00daf68:  d4 1b e0 08  ldd  [ %o7 + 8 ], %o2
a00daf6c:  e0 1b e0 18  ldd  [ %o7 + 0x18 ], %l0
a00daf70:  e4 1b e0 20  ldd  [ %o7 + 0x20 ], %l2
a00daf74:  e8 1b e0 28  ldd  [ %o7 + 0x28 ], %l4
a00daf78:  ec 1b e0 30  ldd  [ %o7 + 0x30 ], %l6
a00daf7c:  f8 1b e0 38  ldd  [ %o7 + 0x38 ], %i4
a00daf80:  f4 1b e0 40  ldd  [ %o7 + 0x40 ], %i2
a00daf84:  f0 1b e0 48  ldd  [ %o7 + 0x48 ], %i0
a00daf88:  d8 3f bf a0  std  %o4, [ %fp + -96 ]
a00daf8c:  d4 3f bf a8  std  %o2, [ %fp + -88 ]
a00daf90:  e0 3f bf b8  std  %l0, [ %fp + -72 ]
a00daf94:  e4 3f bf c0  std  %l2, [ %fp + -64 ]
a00daf98:  e8 3f bf c8  std  %l4, [ %fp + -56 ]
a00daf9c:  ec 3f bf d0  std  %l6, [ %fp + -48 ]
a00dafa0:  f8 3f bf d8  std  %i4, [ %fp + -40 ]
a00dafa4:  f4 3f bf e0  std  %i2, [ %fp + -32 ]
a00dafa8:  f0 3f bf e8  std  %i0, [ %fp + -24 ]
a00dafac:  90 07 bf a0  add  %fp, -96, %o0
a00dafb0:  92 10 20 01  mov  1, %o1
a00dafb4:  40 01 b5 10  call  0xa01483f4
a00dafb8:  27 2a 00 b8  sethi  %hi(0xa802e000), %l3
a00dafbc:  e8 0c e3 d3  ldub  [ %l3 + 0x3d3 ], %l4	! 0xa802e3d3
a00dafc0:  80 a0 00 14  cmp  %g0, %l4
a00dafc4:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a00dafc8:  90 40 20 00  addx  %g0, 0, %o0
a00dafcc:  d2 13 63 ca  lduh  [ %o5 + 0x3ca ], %o1
a00dafd0:  40 00 b3 9d  call  0xa0107e44
a00dafd4:  94 10 20 01  mov  1, %o2
a00dafd8:  30 80 00 13  b,a   0xa00db024
a00dafdc:  10 bf ff 1f  b  0xa00dac58
a00dafe0:  b8 10 20 05  mov  5, %i4
a00dafe4:  91 35 a0 10  srl  %l6, 0x10, %o0
a00dafe8:  aa 03 62 58  add  %o5, 0x258, %l5
a00dafec:  80 a2 00 15  cmp  %o0, %l5
a00daff0:  06 bf ff 78  bl  0xa00dadd0
a00daff4:  a0 10 20 02  mov  2, %l0
a00daff8:  ae 03 64 b0  add  %o5, 0x4b0, %l7
a00daffc:  80 a2 00 17  cmp  %o0, %l7
a00db000:  06 bf ff 74  bl  0xa00dadd0
a00db004:  a0 10 20 01  mov  1, %l0
a00db008:  10 bf ff 72  b  0xa00dadd0
a00db00c:  a0 10 20 00  clr  %l0
a00db010:  80 a0 65 13  cmp  %g1, 0x513
a00db014:  08 bf ff 6f  bleu  0xa00dadd0
a00db018:  a0 10 20 01  mov  1, %l0
a00db01c:  10 bf ff 6d  b  0xa00dadd0
a00db020:  a0 10 20 00  clr  %l0
a00db024:  40 01 2e 15  call  0xa0126878
a00db028:  2d 00 06 62  sethi  %hi(0x198800), %l6
a00db02c:  40 01 39 66  call  0xa01295c4
a00db030:  b9 2a 20 10  sll  %o0, 0x10, %i4
a00db034:  a5 37 20 10  srl  %i4, 0x10, %l2
a00db038:  94 0a 20 ff  and  %o0, 0xff, %o2
a00db03c:  90 15 a1 f8  or  %l6, 0x1f8, %o0
a00db040:  40 00 10 4c  call  0xa00df170
a00db044:  92 10 00 12  mov  %l2, %o1
a00db048:  01 00 00 00  nop
a00db04c:  81 c7 e0 08  ret
a00db050:  81 e8 00 00  restore
