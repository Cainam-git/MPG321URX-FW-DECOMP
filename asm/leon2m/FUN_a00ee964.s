# leon2m FUN_a00ee964 0xa00ee964-0xa00eec44 (736 bytes)
a00ee964:  9d e3 bf 98  save  %sp, -104, %sp
a00ee968:  80 a7 25 35  cmp  %i4, 0x535
a00ee96c:  d2 07 a0 5c  ld  [ %fp + 0x5c ], %o1
a00ee970:  04 80 00 0b  ble  0xa00ee99c
a00ee974:  90 10 20 00  clr  %o0
a00ee978:  80 a7 27 4a  cmp  %i4, 0x74a
a00ee97c:  04 80 00 08  ble  0xa00ee99c
a00ee980:  90 10 20 01  mov  1, %o0
a00ee984:  80 a7 29 60  cmp  %i4, 0x960
a00ee988:  04 80 00 05  ble  0xa00ee99c
a00ee98c:  90 10 20 02  mov  2, %o0
a00ee990:  80 a7 2a 6b  cmp  %i4, 0xa6b
a00ee994:  14 80 00 a2  bg  0xa00eec1c
a00ee998:  90 10 20 03  mov  3, %o0
a00ee99c:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ee9a0:  21 2a 00 ad  sethi  %hi(0xa802b400), %l0
a00ee9a4:  9f 2e 20 02  sll  %i0, 2, %o7
a00ee9a8:  96 14 61 8c  or  %l1, 0x18c, %o3
a00ee9ac:  9a 14 23 30  or  %l0, 0x330, %o5
a00ee9b0:  d4 02 c0 0f  ld  [ %o3 + %o7 ], %o2
a00ee9b4:  c2 03 40 0f  ld  [ %o5 + %o7 ], %g1
a00ee9b8:  98 00 40 01  add  %g1, %g1, %o4
a00ee9bc:  b8 02 80 0a  add  %o2, %o2, %i4
a00ee9c0:  23 2a 00 9a  sethi  %hi(0xa8026800), %l1
a00ee9c4:  a0 14 61 98  or  %l1, 0x198, %l0	! 0xa8026998
a00ee9c8:  9e 03 00 01  add  %o4, %g1, %o7
a00ee9cc:  96 07 00 0a  add  %i4, %o2, %o3
a00ee9d0:  98 03 c0 10  add  %o7, %l0, %o4
a00ee9d4:  b8 02 c0 10  add  %o3, %l0, %i4
a00ee9d8:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a00ee9dc:  c2 0f 20 01  ldub  [ %i4 + 1 ], %g1
a00ee9e0:  a2 5b 60 64  smul  %o5, 0x64, %l1
a00ee9e4:  d4 0b 20 02  ldub  [ %o4 + 2 ], %o2
a00ee9e8:  e0 0f 20 02  ldub  [ %i4 + 2 ], %l0
a00ee9ec:  9e 58 60 64  smul  %g1, 0x64, %o7
a00ee9f0:  96 04 40 0a  add  %l1, %o2, %o3
a00ee9f4:  82 03 c0 10  add  %o7, %l0, %g1
a00ee9f8:  9a 02 c0 01  add  %o3, %g1, %o5
a00ee9fc:  99 2a 60 06  sll  %o1, 6, %o4
a00eea00:  a1 3b 60 01  sra  %o5, 1, %l0
a00eea04:  98 03 00 09  add  %o4, %o1, %o4
a00eea08:  80 a7 60 00  cmp  %i5, 0
a00eea0c:  a2 10 00 08  mov  %o0, %l1
a00eea10:  02 80 00 3c  be  0xa00eeb00
a00eea14:  ba 03 00 10  add  %o4, %l0, %i5
a00eea18:  39 3f ff fa  sethi  %hi(0xffffe800), %i4
a00eea1c:  90 17 20 90  or  %i4, 0x90, %o0	! 0xffffe890
a00eea20:  9a 07 40 08  add  %i5, %o0, %o5
a00eea24:  80 a3 6c b2  cmp  %o5, 0xcb2
a00eea28:  38 80 00 3e  bgu,a   0xa00eeb20
a00eea2c:  1b 3f ff fb  sethi  %hi(0xffffec00), %o5
a00eea30:  17 1f 81 f8  sethi  %hi(0x7e07e000), %o3
a00eea34:  9e 12 e0 7f  or  %o3, 0x7f, %o7	! 0x7e07e07f
a00eea38:  80 5b 40 0f  smul  %o5, %o7, %g0
a00eea3c:  83 40 00 00  rd  %y, %g1
a00eea40:  99 38 60 05  sra  %g1, 5, %o4
a00eea44:  95 3b 60 1f  sra  %o5, 0x1f, %o2
a00eea48:  b8 23 00 0a  sub  %o4, %o2, %i4
a00eea4c:  80 a7 20 ff  cmp  %i4, 0xff
a00eea50:  02 80 00 63  be  0xa00eebdc
a00eea54:  90 10 00 18  mov  %i0, %o0
a00eea58:  11 3f ff fa  sethi  %hi(0xffffe800), %o0
a00eea5c:  ba 12 20 90  or  %o0, 0x90, %i5	! 0xffffe890
a00eea60:  9a 04 00 1d  add  %l0, %i5, %o5
a00eea64:  80 a3 6c b2  cmp  %o5, 0xcb2
a00eea68:  38 80 00 3c  bgu,a   0xa00eeb58
a00eea6c:  1b 3f ff fb  sethi  %hi(0xffffec00), %o5
a00eea70:  17 1f 81 f8  sethi  %hi(0x7e07e000), %o3
a00eea74:  9e 12 e0 7f  or  %o3, 0x7f, %o7	! 0x7e07e07f
a00eea78:  80 5b 40 0f  smul  %o5, %o7, %g0
a00eea7c:  83 40 00 00  rd  %y, %g1
a00eea80:  95 38 60 05  sra  %g1, 5, %o2
a00eea84:  99 3b 60 1f  sra  %o5, 0x1f, %o4
a00eea88:  82 22 80 0c  sub  %o2, %o4, %g1
a00eea8c:  80 a0 60 ff  cmp  %g1, 0xff
a00eea90:  02 80 00 37  be  0xa00eeb6c
a00eea94:  92 10 22 8e  mov  0x28e, %o1
a00eea98:  90 10 00 18  mov  %i0, %o0
a00eea9c:  7f ff c6 45  call  0xa00e03b0
a00eeaa0:  94 17 20 80  or  %i4, 0x80, %o2
a00eeaa4:  a1 2c 60 0a  sll  %l1, 0xa, %l0
a00eeaa8:  92 10 20 06  mov  6, %o1
a00eeaac:  94 10 20 06  mov  6, %o2
a00eeab0:  96 14 20 80  or  %l0, 0x80, %o3
a00eeab4:  7f ff d5 6e  call  0xa00e406c
a00eeab8:  90 10 00 18  mov  %i0, %o0
a00eeabc:  7f ff c5 3a  call  0xa00dffa4
a00eeac0:  90 10 20 01  mov  1, %o0
a00eeac4:  ba 14 00 1c  or  %l0, %i4, %i5
a00eeac8:  90 10 00 18  mov  %i0, %o0
a00eeacc:  92 10 20 06  mov  6, %o1
a00eead0:  94 10 20 06  mov  6, %o2
a00eead4:  7f ff d5 66  call  0xa00e406c
a00eead8:  96 17 60 80  or  %i5, 0x80, %o3
a00eeadc:  90 10 00 18  mov  %i0, %o0
a00eeae0:  96 10 00 1d  mov  %i5, %o3
a00eeae4:  92 10 20 06  mov  6, %o1
a00eeae8:  7f ff d5 61  call  0xa00e406c
a00eeaec:  94 10 20 06  mov  6, %o2
a00eeaf0:  7f ff c5 2d  call  0xa00dffa4
a00eeaf4:  90 10 20 01  mov  1, %o0
a00eeaf8:  10 80 00 51  b  0xa00eec3c
a00eeafc:  b0 10 20 00  clr  %i0
a00eeb00:  39 3f ff fa  sethi  %hi(0xffffe800), %i4
a00eeb04:  ba 24 00 0c  sub  %l0, %o4, %i5
a00eeb08:  90 17 20 90  or  %i4, 0x90, %o0
a00eeb0c:  9a 07 40 08  add  %i5, %o0, %o5
a00eeb10:  80 a3 6c b2  cmp  %o5, 0xcb2
a00eeb14:  08 bf ff c8  bleu  0xa00eea34
a00eeb18:  17 1f 81 f8  sethi  %hi(0x7e07e000), %o3
a00eeb1c:  1b 3f ff fb  sethi  %hi(0xffffec00), %o5
a00eeb20:  92 13 62 6c  or  %o5, 0x26c, %o1	! 0xffffee6c
a00eeb24:  9a 07 40 09  add  %i5, %o1, %o5
a00eeb28:  80 a3 6c b2  cmp  %o5, 0xcb2
a00eeb2c:  18 80 00 2c  bgu  0xa00eebdc
a00eeb30:  90 10 00 18  mov  %i0, %o0
a00eeb34:  1f 1f 81 f8  sethi  %hi(0x7e07e000), %o7
a00eeb38:  82 13 e0 7f  or  %o7, 0x7f, %g1	! 0x7e07e07f
a00eeb3c:  80 5b 40 01  smul  %o5, %g1, %g0
a00eeb40:  99 40 00 00  rd  %y, %o4
a00eeb44:  b9 3b 20 05  sra  %o4, 5, %i4
a00eeb48:  95 3b 60 1f  sra  %o5, 0x1f, %o2
a00eeb4c:  90 27 00 0a  sub  %i4, %o2, %o0
a00eeb50:  10 bf ff bf  b  0xa00eea4c
a00eeb54:  b8 12 20 40  or  %o0, 0x40, %i4
a00eeb58:  92 13 62 6c  or  %o5, 0x26c, %o1
a00eeb5c:  9a 04 00 09  add  %l0, %o1, %o5
a00eeb60:  80 a3 6c b2  cmp  %o5, 0xcb2
a00eeb64:  08 80 00 16  bleu  0xa00eebbc
a00eeb68:  1f 1f 81 f8  sethi  %hi(0x7e07e000), %o7
a00eeb6c:  90 10 00 18  mov  %i0, %o0
a00eeb70:  92 10 22 8e  mov  0x28e, %o1
a00eeb74:  7f ff c6 0f  call  0xa00e03b0
a00eeb78:  94 10 20 ff  mov  0xff, %o2
a00eeb7c:  7f ff c3 24  call  0xa00df80c
a00eeb80:  01 00 00 00  nop
a00eeb84:  7f ff c8 0f  call  0xa00e0bc0
a00eeb88:  01 00 00 00  nop
a00eeb8c:  17 14 7a e1  sethi  %hi(0x51eb8400), %o3
a00eeb90:  a2 12 e1 1f  or  %o3, 0x11f, %l1	! 0x51eb851f
a00eeb94:  80 5c 00 11  smul  %l0, %l1, %g0
a00eeb98:  b1 40 00 00  rd  %y, %i0
a00eeb9c:  93 3e 20 05  sra  %i0, 5, %o1
a00eeba0:  b8 5a 60 64  smul  %o1, 0x64, %i4
a00eeba4:  94 24 00 1c  sub  %l0, %i4, %o2
a00eeba8:  21 00 06 67  sethi  %hi(0x199c00), %l0
a00eebac:  7f ff c1 71  call  0xa00df170
a00eebb0:  90 14 23 60  or  %l0, 0x360, %o0	! 0x199f60
a00eebb4:  10 80 00 22  b  0xa00eec3c
a00eebb8:  b0 10 3f ff  mov  -1, %i0
a00eebbc:  82 13 e0 7f  or  %o7, 0x7f, %g1
a00eebc0:  80 5b 40 01  smul  %o5, %g1, %g0
a00eebc4:  99 40 00 00  rd  %y, %o4
a00eebc8:  91 3b 20 05  sra  %o4, 5, %o0
a00eebcc:  95 3b 60 1f  sra  %o5, 0x1f, %o2
a00eebd0:  ba 22 00 0a  sub  %o0, %o2, %i5
a00eebd4:  10 bf ff ae  b  0xa00eea8c
a00eebd8:  82 17 60 40  or  %i5, 0x40, %g1
a00eebdc:  92 10 22 8e  mov  0x28e, %o1
a00eebe0:  7f ff c5 f4  call  0xa00e03b0
a00eebe4:  94 10 20 ff  mov  0xff, %o2
a00eebe8:  7f ff c3 09  call  0xa00df80c
a00eebec:  a3 3f 60 1f  sra  %i5, 0x1f, %l1
a00eebf0:  7f ff c7 f4  call  0xa00e0bc0
a00eebf4:  01 00 00 00  nop
a00eebf8:  1b 14 7a e1  sethi  %hi(0x51eb8400), %o5
a00eebfc:  92 13 61 1f  or  %o5, 0x11f, %o1	! 0x51eb851f
a00eec00:  80 5f 40 09  smul  %i5, %o1, %g0
a00eec04:  97 40 00 00  rd  %y, %o3
a00eec08:  a1 3a e0 05  sra  %o3, 5, %l0
a00eec0c:  92 24 00 11  sub  %l0, %l1, %o1
a00eec10:  b0 5a 60 64  smul  %o1, 0x64, %i0
a00eec14:  10 bf ff e5  b  0xa00eeba8
a00eec18:  94 27 40 18  sub  %i5, %i0, %o2
a00eec1c:  7f ff c2 fc  call  0xa00df80c
a00eec20:  b0 10 3f ff  mov  -1, %i0
a00eec24:  7f ff c7 e7  call  0xa00e0bc0
a00eec28:  01 00 00 00  nop
a00eec2c:  11 00 06 67  sethi  %hi(0x199c00), %o0
a00eec30:  90 12 22 f0  or  %o0, 0x2f0, %o0	! 0x199ef0
a00eec34:  7f ff c1 4f  call  0xa00df170
a00eec38:  92 10 00 1c  mov  %i4, %o1
a00eec3c:  81 c7 e0 08  ret
a00eec40:  81 e8 00 00  restore
