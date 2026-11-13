# leon2s FUN_a00ccb04 0xa00ccb04-0xa00ccd20 (540 bytes)  [FUN_a00ccd18 = unreachable ret/restore tail, merged]
a00ccb04:  9d e3 bf 98  save  %sp, -104, %sp
a00ccb08:  b8 0e 20 ff  and  %i0, 0xff, %i4
a00ccb0c:  82 07 00 1c  add  %i4, %i4, %g1
a00ccb10:  82 00 40 1c  add  %g1, %i4, %g1
a00ccb14:  23 2a 01 e2  sethi  %hi(0xa8078800), %l1
a00ccb18:  a1 28 60 03  sll  %g1, 3, %l0
a00ccb1c:  b6 14 63 b0  or  %l1, 0x3b0, %i3
a00ccb20:  da 06 c0 10  ld  [ %i3 + %l0 ], %o5
a00ccb24:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00ccb28:  82 2b 40 01  andn  %o5, %g1, %g1
a00ccb2c:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00ccb30:  82 10 40 0d  or  %g1, %o5, %g1
a00ccb34:  40 3b d5 4c  call  0xa0fc2064
a00ccb38:  c2 26 c0 10  st  %g1, [ %i3 + %l0 ]
a00ccb3c:  03 2a 01 f4  sethi  %hi(0xa807d000), %g1
a00ccb40:  9b 2f 20 02  sll  %i4, 2, %o5
a00ccb44:  82 10 60 a8  or  %g1, 0xa8, %g1
a00ccb48:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a00ccb4c:  80 a2 00 01  cmp  %o0, %g1
a00ccb50:  0a 80 00 28  bcs  0xa00ccbf0
a00ccb54:  b4 10 00 18  mov  %i0, %i2
a00ccb58:  1b 2a 01 f5  sethi  %hi(0xa807d400), %o5
a00ccb5c:  c2 0b 62 36  ldub  [ %o5 + 0x236 ], %g1	! 0xa807d636
a00ccb60:  80 a0 60 ff  cmp  %g1, 0xff
a00ccb64:  02 80 00 04  be  0xa00ccb74
a00ccb68:  80 a0 40 1c  cmp  %g1, %i4
a00ccb6c:  32 80 00 22  bne,a   0xa00ccbf4
a00ccb70:  c2 06 c0 10  ld  [ %i3 + %l0 ], %g1
a00ccb74:  f0 2b 62 36  stb  %i0, [ %o5 + 0x236 ]
a00ccb78:  82 10 20 03  mov  3, %g1
a00ccb7c:  a0 04 00 1b  add  %l0, %i3, %l0
a00ccb80:  c2 2c 20 09  stb  %g1, [ %l0 + 9 ]
a00ccb84:  c0 24 20 0c  clr  [ %l0 + 0xc ]
a00ccb88:  7f ff ff d3  call  0xa00ccad4
a00ccb8c:  90 10 00 1c  mov  %i4, %o0
a00ccb90:  c0 24 20 10  clr  [ %l0 + 0x10 ]
a00ccb94:  90 10 00 1c  mov  %i4, %o0
a00ccb98:  7f ff ec 4d  call  0xa00c7ccc
a00ccb9c:  92 10 20 01  mov  1, %o1
a00ccba0:  92 10 20 04  mov  4, %o1
a00ccba4:  94 10 20 07  mov  7, %o2
a00ccba8:  7f ff ea ab  call  0xa00c7654
a00ccbac:  90 10 00 1c  mov  %i4, %o0
a00ccbb0:  40 3b d2 f9  call  0xa0fc1794
a00ccbb4:  90 10 20 14  mov  0x14, %o0
a00ccbb8:  90 10 00 1c  mov  %i4, %o0
a00ccbbc:  92 10 20 04  mov  4, %o1
a00ccbc0:  7f ff ea a5  call  0xa00c7654
a00ccbc4:  94 10 20 01  mov  1, %o2
a00ccbc8:  90 10 00 1c  mov  %i4, %o0
a00ccbcc:  92 10 20 05  mov  5, %o1
a00ccbd0:  7f ff ea a1  call  0xa00c7654
a00ccbd4:  94 10 20 01  mov  1, %o2
a00ccbd8:  90 10 00 1c  mov  %i4, %o0
a00ccbdc:  92 10 20 13  mov  0x13, %o1
a00ccbe0:  7f ff ef 02  call  0xa00c87e8
a00ccbe4:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ccbe8:  10 80 00 0b  b  0xa00ccc14
a00ccbec:  a0 10 20 00  clr  %l0
a00ccbf0:  c2 06 c0 10  ld  [ %i3 + %l0 ], %g1
a00ccbf4:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00ccbf8:  82 10 40 0d  or  %g1, %o5, %g1
a00ccbfc:  10 80 00 46  b  0xa00ccd14
a00ccc00:  c2 26 c0 10  st  %g1, [ %i3 + %l0 ]
a00ccc04:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00ccc08:  82 10 62 38  or  %g1, 0x238, %g1	! 0xa807d638
a00ccc0c:  7f ff ea 92  call  0xa00c7654
a00ccc10:  d4 08 40 0d  ldub  [ %g1 + %o5 ], %o2
a00ccc14:  9a 0c 20 ff  and  %l0, 0xff, %o5
a00ccc18:  90 10 00 1c  mov  %i4, %o0
a00ccc1c:  92 10 20 01  mov  1, %o1
a00ccc20:  80 a3 60 0f  cmp  %o5, 0xf
a00ccc24:  08 bf ff f8  bleu  0xa00ccc04
a00ccc28:  a0 04 20 01  inc  %l0
a00ccc2c:  39 2a 01 f3  sethi  %hi(0xa807cc00), %i4
a00ccc30:  9a 17 22 50  or  %i4, 0x250, %o5	! 0xa807ce50
a00ccc34:  82 10 20 01  mov  1, %g1
a00ccc38:  c2 2b 60 01  stb  %g1, [ %o5 + 1 ]
a00ccc3c:  82 10 20 03  mov  3, %g1
a00ccc40:  c2 2b 60 03  stb  %g1, [ %o5 + 3 ]
a00ccc44:  82 10 20 04  mov  4, %g1
a00ccc48:  c2 2b 60 04  stb  %g1, [ %o5 + 4 ]
a00ccc4c:  82 10 20 05  mov  5, %g1
a00ccc50:  c2 2b 60 05  stb  %g1, [ %o5 + 5 ]
a00ccc54:  82 10 20 06  mov  6, %g1
a00ccc58:  c2 2b 60 06  stb  %g1, [ %o5 + 6 ]
a00ccc5c:  82 10 20 07  mov  7, %g1
a00ccc60:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00ccc64:  98 10 20 02  mov  2, %o4
a00ccc68:  82 10 20 08  mov  8, %g1
a00ccc6c:  b0 0e a0 ff  and  %i2, 0xff, %i0
a00ccc70:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00ccc74:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00ccc78:  c0 2b 60 0b  clrb  [ %o5 + 0xb ]
a00ccc7c:  d8 2f 22 50  stb  %o4, [ %i4 + 0x250 ]
a00ccc80:  d8 2b 60 02  stb  %o4, [ %o5 + 2 ]
a00ccc84:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00ccc88:  90 10 00 18  mov  %i0, %o0
a00ccc8c:  7f ff ee d7  call  0xa00c87e8
a00ccc90:  15 00 00 20  sethi  %hi(0x8000), %o2
a00ccc94:  a0 10 20 00  clr  %l0
a00ccc98:  82 0c 20 ff  and  %l0, 0xff, %g1
a00ccc9c:  b2 17 22 50  or  %i4, 0x250, %i1
a00ccca0:  82 00 40 19  add  %g1, %i1, %g1
a00ccca4:  d4 08 60 01  ldub  [ %g1 + 1 ], %o2
a00ccca8:  90 10 00 18  mov  %i0, %o0
a00cccac:  7f ff ea 6a  call  0xa00c7654
a00cccb0:  92 10 20 01  mov  1, %o1
a00cccb4:  a0 04 20 01  inc  %l0
a00cccb8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00cccbc:  80 a0 60 0a  cmp  %g1, 0xa
a00cccc0:  28 bf ff f8  bleu,a   0xa00ccca0
a00cccc4:  b2 17 22 50  or  %i4, 0x250, %i1
a00cccc8:  90 10 00 18  mov  %i0, %o0
a00ccccc:  92 10 20 00  clr  %o1
a00cccd0:  40 3b ac c2  call  0xa0fb7fd8
a00cccd4:  94 10 20 09  mov  9, %o2
a00cccd8:  80 8a 20 02  btst  2, %o0
a00cccdc:  12 80 00 0a  bne  0xa00ccd04
a00ccce0:  9a 06 00 18  add  %i0, %i0, %o5
a00ccce4:  9a 03 40 18  add  %o5, %i0, %o5
a00ccce8:  96 14 63 b0  or  %l1, 0x3b0, %o3
a00cccec:  9b 2b 60 03  sll  %o5, 3, %o5
a00cccf0:  d8 02 c0 0d  ld  [ %o3 + %o5 ], %o4
a00cccf4:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cccf8:  82 2b 00 01  andn  %o4, %g1, %g1
a00cccfc:  10 80 00 06  b  0xa00ccd14
a00ccd00:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00ccd04:  b4 10 20 74  mov  0x74, %i2
a00ccd08:  b6 10 20 60  mov  0x60, %i3
a00ccd0c:  7f ff ec f9  call  0xa00c80f0
a00ccd10:  99 e8 20 0c  restore  %g0, 0xc, %o4
a00ccd14:  01 00 00 00  nop
a00ccd18:  81 c7 e0 08  ret
a00ccd1c:  81 e8 00 00  restore
