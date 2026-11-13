# leon2s FUN_a0086c48 0xa0086c48-0xa0086df4 (428 bytes)
a0086c48:  9d e3 bf 98  save  %sp, -104, %sp
a0086c4c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0086c50:  9a 06 00 18  add  %i0, %i0, %o5
a0086c54:  9a 03 40 18  add  %o5, %i0, %o5
a0086c58:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0086c5c:  82 10 61 2e  or  %g1, 0x12e, %g1	! 0xa807cd2e
a0086c60:  9a 03 40 0d  add  %o5, %o5, %o5
a0086c64:  9a 03 40 01  add  %o5, %g1, %o5
a0086c68:  d8 0b 60 03  ldub  [ %o5 + 3 ], %o4
a0086c6c:  d8 2e 60 01  stb  %o4, [ %i1 + 1 ]
a0086c70:  c2 0b 60 02  ldub  [ %o5 + 2 ], %g1
a0086c74:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0086c78:  82 10 20 01  mov  1, %g1
a0086c7c:  c2 2e 60 03  stb  %g1, [ %i1 + 3 ]
a0086c80:  82 10 20 06  mov  6, %g1
a0086c84:  80 a6 20 00  cmp  %i0, 0
a0086c88:  12 80 00 4a  bne  0xa0086db0
a0086c8c:  c2 2e 60 02  stb  %g1, [ %i1 + 2 ]
a0086c90:  17 2a 01 f3  sethi  %hi(0xa807cc00), %o3
a0086c94:  94 12 e1 68  or  %o3, 0x168, %o2	! 0xa807cd68
a0086c98:  c2 0a a0 01  ldub  [ %o2 + 1 ], %g1
a0086c9c:  80 a3 00 01  cmp  %o4, %g1
a0086ca0:  28 80 00 05  bleu,a   0xa0086cb4
a0086ca4:  da 0e 40 00  ldub  [ %i1 ], %o5
a0086ca8:  c2 0a a0 01  ldub  [ %o2 + 1 ], %g1
a0086cac:  c2 2e 60 01  stb  %g1, [ %i1 + 1 ]
a0086cb0:  da 0e 40 00  ldub  [ %i1 ], %o5
a0086cb4:  c2 0a e1 68  ldub  [ %o3 + 0x168 ], %g1
a0086cb8:  80 a3 40 01  cmp  %o5, %g1
a0086cbc:  08 80 00 05  bleu  0xa0086cd0
a0086cc0:  82 10 20 1e  mov  0x1e, %g1
a0086cc4:  c2 0a e1 68  ldub  [ %o3 + 0x168 ], %g1
a0086cc8:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0086ccc:  82 10 20 1e  mov  0x1e, %g1
a0086cd0:  c2 2a e1 68  stb  %g1, [ %o3 + 0x168 ]
a0086cd4:  82 10 20 04  mov  4, %g1
a0086cd8:  c2 2a a0 01  stb  %g1, [ %o2 + 1 ]
a0086cdc:  7f ff ff bf  call  0xa0086bd8
a0086ce0:  01 00 00 00  nop
a0086ce4:  80 8a 20 ff  btst  0xff, %o0
a0086ce8:  02 80 00 41  be  0xa0086dec
a0086cec:  01 00 00 00  nop
a0086cf0:  7f ff fb 00  call  0xa00858f0
a0086cf4:  90 10 20 00  clr  %o0	! 0x0
a0086cf8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0086cfc:  80 a2 20 71  cmp  %o0, 0x71
a0086d00:  12 80 00 0a  bne  0xa0086d28
a0086d04:  b0 10 3f ff  mov  -1, %i0
a0086d08:  40 00 99 5d  call  0xa00ad27c
a0086d0c:  90 10 20 00  clr  %o0
a0086d10:  90 0a 20 ff  and  %o0, 0xff, %o0
a0086d14:  80 a2 20 01  cmp  %o0, 1
a0086d18:  32 80 00 11  bne,a   0xa0086d5c
a0086d1c:  90 0e 20 ff  and  %i0, 0xff, %o0
a0086d20:  10 80 00 0b  b  0xa0086d4c
a0086d24:  90 10 20 00  clr  %o0
a0086d28:  80 a2 20 81  cmp  %o0, 0x81
a0086d2c:  12 80 00 0c  bne  0xa0086d5c
a0086d30:  90 0e 20 ff  and  %i0, 0xff, %o0
a0086d34:  40 00 99 52  call  0xa00ad27c
a0086d38:  90 10 20 01  mov  1, %o0
a0086d3c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0086d40:  80 a2 20 01  cmp  %o0, 1
a0086d44:  32 80 00 06  bne,a   0xa0086d5c
a0086d48:  90 0e 20 ff  and  %i0, 0xff, %o0
a0086d4c:  40 00 7f 9b  call  0xa00a6bb8
a0086d50:  92 10 20 80  mov  0x80, %o1
a0086d54:  b0 10 00 08  mov  %o0, %i0
a0086d58:  90 0e 20 ff  and  %i0, 0xff, %o0
a0086d5c:  80 a2 20 ff  cmp  %o0, 0xff
a0086d60:  02 80 00 23  be  0xa0086dec
a0086d64:  82 8a 20 03  andcc  %o0, 3, %g1
a0086d68:  12 80 00 04  bne  0xa0086d78
a0086d6c:  80 a0 60 01  cmp  %g1, 1
a0086d70:  10 80 00 09  b  0xa0086d94
a0086d74:  82 10 20 06  mov  6, %g1
a0086d78:  12 80 00 04  bne  0xa0086d88
a0086d7c:  80 a0 60 02  cmp  %g1, 2
a0086d80:  10 80 00 05  b  0xa0086d94
a0086d84:  82 10 20 0a  mov  0xa, %g1
a0086d88:  32 80 00 03  bne,a   0xa0086d94
a0086d8c:  82 10 20 1e  mov  0x1e, %g1
a0086d90:  82 10 20 14  mov  0x14, %g1
a0086d94:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0086d98:  82 0a 20 1c  and  %o0, 0x1c, %g1
a0086d9c:  83 38 60 02  sra  %g1, 2, %g1
a0086da0:  da 0e 40 00  ldub  [ %i1 ], %o5
a0086da4:  c2 2e 60 01  stb  %g1, [ %i1 + 1 ]
a0086da8:  10 80 00 11  b  0xa0086dec
a0086dac:  da 2e 60 02  stb  %o5, [ %i1 + 2 ]
a0086db0:  17 2a 01 f3  sethi  %hi(0xa807cc00), %o3
a0086db4:  9a 12 e1 00  or  %o3, 0x100, %o5	! 0xa807cd00
a0086db8:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a0086dbc:  80 a3 00 01  cmp  %o4, %g1
a0086dc0:  28 80 00 05  bleu,a   0xa0086dd4
a0086dc4:  da 0e 40 00  ldub  [ %i1 ], %o5
a0086dc8:  c2 0b 60 01  ldub  [ %o5 + 1 ], %g1
a0086dcc:  c2 2e 60 01  stb  %g1, [ %i1 + 1 ]
a0086dd0:  da 0e 40 00  ldub  [ %i1 ], %o5
a0086dd4:  c2 0a e1 00  ldub  [ %o3 + 0x100 ], %g1
a0086dd8:  80 a3 40 01  cmp  %o5, %g1
a0086ddc:  08 80 00 04  bleu  0xa0086dec
a0086de0:  01 00 00 00  nop
a0086de4:  c2 0a e1 00  ldub  [ %o3 + 0x100 ], %g1
a0086de8:  c2 2e 40 00  stb  %g1, [ %i1 ]
a0086dec:  81 c7 e0 08  ret
a0086df0:  81 e8 00 00  restore
