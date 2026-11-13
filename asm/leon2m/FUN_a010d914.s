# leon2m FUN_a010d914 0xa010d914-0xa010daf8 (344 bytes)
a010d914:  9d e3 bf 98  save  %sp, -104, %sp
a010d918:  b0 0e 20 ff  and  %i0, 0xff, %i0
a010d91c:  9e 10 00 19  mov  %i1, %o7
a010d920:  03 2a 00 b5  sethi  %hi(0xa802d400), %g1
a010d924:  80 a6 20 01  cmp  %i0, 1
a010d928:  02 80 00 4c  be  0xa010da58
a010d92c:  b2 10 63 04  or  %g1, 0x304, %i1
a010d930:  f4 2e 60 26  stb  %i2, [ %i1 + 0x26 ]
a010d934:  de 2e 60 25  stb  %o7, [ %i1 + 0x25 ]
a010d938:  80 a6 20 01  cmp  %i0, 1
a010d93c:  08 80 00 38  bleu  0xa010da1c
a010d940:  b4 0e a0 ff  and  %i2, 0xff, %i2
a010d944:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010d948:  b6 17 22 c4  or  %i4, 0x2c4, %i3	! 0x19aec4
a010d94c:  b8 10 20 00  clr  %i4
a010d950:  83 2f 20 02  sll  %i4, 2, %g1
a010d954:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010d958:  b8 07 20 01  inc  %i4
a010d95c:  f4 27 60 14  st  %i2, [ %i5 + 0x14 ]
a010d960:  80 a7 20 01  cmp  %i4, 1
a010d964:  08 bf ff fc  bleu  0xa010d954
a010d968:  83 2f 20 02  sll  %i4, 2, %g1
a010d96c:  80 a6 20 01  cmp  %i0, 1
a010d970:  08 80 00 25  bleu  0xa010da04
a010d974:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010d978:  39 00 06 6b  sethi  %hi(0x19ac00), %i4
a010d97c:  b6 17 22 bc  or  %i4, 0x2bc, %i3	! 0x19aebc
a010d980:  b8 10 20 00  clr  %i4
a010d984:  83 2f 20 02  sll  %i4, 2, %g1
a010d988:  fa 06 c0 01  ld  [ %i3 + %g1 ], %i5
a010d98c:  b8 07 20 01  inc  %i4
a010d990:  f4 27 60 14  st  %i2, [ %i5 + 0x14 ]
a010d994:  80 a7 20 01  cmp  %i4, 1
a010d998:  08 bf ff fc  bleu  0xa010d988
a010d99c:  83 2f 20 02  sll  %i4, 2, %g1
a010d9a0:  82 0b e0 ff  and  %o7, 0xff, %g1
a010d9a4:  80 a0 60 08  cmp  %g1, 8
a010d9a8:  18 80 00 09  bgu  0xa010d9cc
a010d9ac:  b6 10 20 20  mov  0x20, %i3
a010d9b0:  3b 00 02 ac  sethi  %hi(0xab000), %i5
a010d9b4:  b7 28 60 02  sll  %g1, 2, %i3
a010d9b8:  b8 17 63 f8  or  %i5, 0x3f8, %i4
a010d9bc:  f4 07 00 1b  ld  [ %i4 + %i3 ], %i2
a010d9c0:  81 c6 80 00  jmp  %i2
a010d9c4:  01 00 00 00  nop
a010d9c8:  b6 10 20 20  mov  0x20, %i3	! 0x20
a010d9cc:  f6 2e 60 24  stb  %i3, [ %i1 + 0x24 ]
a010d9d0:  ba 10 22 00  mov  0x200, %i5
a010d9d4:  80 a6 20 00  cmp  %i0, 0
a010d9d8:  32 80 00 18  bne,a   0xa010da38
a010d9dc:  83 2f 60 10  sll  %i5, 0x10, %g1
a010d9e0:  b3 2f 60 10  sll  %i5, 0x10, %i1
a010d9e4:  82 17 40 19  or  %i5, %i1, %g1
a010d9e8:  3b 34 00 c8  sethi  %hi(0xd0032000), %i5
a010d9ec:  b8 17 60 04  or  %i5, 4, %i4	! 0xd0032004
a010d9f0:  82 10 60 01  or  %g1, 1, %g1
a010d9f4:  c2 27 00 00  st  %g1, [ %i4 ]
a010d9f8:  31 34 00 e8  sethi  %hi(0xd003a000), %i0
a010d9fc:  10 80 00 3c  b  0xa010daec
a010da00:  b8 16 20 04  or  %i0, 4, %i4	! 0xd003a004
a010da04:  b9 2e 20 02  sll  %i0, 2, %i4
a010da08:  ba 10 62 bc  or  %g1, 0x2bc, %i5
a010da0c:  f6 07 40 1c  ld  [ %i5 + %i4 ], %i3
a010da10:  f4 26 e0 14  st  %i2, [ %i3 + 0x14 ]
a010da14:  10 bf ff e4  b  0xa010d9a4
a010da18:  82 0b e0 ff  and  %o7, 0xff, %g1
a010da1c:  03 00 06 6b  sethi  %hi(0x19ac00), %g1
a010da20:  b9 2e 20 02  sll  %i0, 2, %i4
a010da24:  ba 10 62 c4  or  %g1, 0x2c4, %i5
a010da28:  f6 07 40 1c  ld  [ %i5 + %i4 ], %i3
a010da2c:  f4 26 e0 14  st  %i2, [ %i3 + 0x14 ]
a010da30:  10 bf ff d0  b  0xa010d970
a010da34:  80 a6 20 01  cmp  %i0, 1
a010da38:  b8 17 40 01  or  %i5, %g1, %i4
a010da3c:  31 34 00 c8  sethi  %hi(0xd0032000), %i0
a010da40:  82 17 20 01  or  %i4, 1, %g1
a010da44:  b6 16 20 08  or  %i0, 8, %i3
a010da48:  35 34 00 e8  sethi  %hi(0xd003a000), %i2
a010da4c:  c2 26 c0 00  st  %g1, [ %i3 ]
a010da50:  10 80 00 27  b  0xa010daec
a010da54:  b8 16 a0 08  or  %i2, 8, %i4
a010da58:  37 2a 00 b6  sethi  %hi(0xa802d800), %i3
a010da5c:  10 bf ff b5  b  0xa010d930
a010da60:  b2 16 e0 04  or  %i3, 4, %i1	! 0xa802d804
a010da64:  b4 10 20 20  mov  0x20, %i2
a010da68:  f4 2e 60 24  stb  %i2, [ %i1 + 0x24 ]
a010da6c:  33 00 00 04  sethi  %hi(0x1000), %i1
a010da70:  10 bf ff d9  b  0xa010d9d4
a010da74:  ba 16 62 00  or  %i1, 0x200, %i5	! 0x1200
a010da78:  82 10 20 10  mov  0x10, %g1
a010da7c:  c2 2e 60 24  stb  %g1, [ %i1 + 0x24 ]
a010da80:  10 bf ff d5  b  0xa010d9d4
a010da84:  ba 10 21 00  mov  0x100, %i5
a010da88:  b4 10 20 10  mov  0x10, %i2
a010da8c:  3b 00 00 08  sethi  %hi(0x2000), %i5
a010da90:  f4 2e 60 24  stb  %i2, [ %i1 + 0x24 ]
a010da94:  10 bf ff d0  b  0xa010d9d4
a010da98:  ba 17 61 00  or  %i5, 0x100, %i5
a010da9c:  b6 10 20 10  mov  0x10, %i3
a010daa0:  3b 00 00 10  sethi  %hi(0x4000), %i5
a010daa4:  f6 2e 60 24  stb  %i3, [ %i1 + 0x24 ]
a010daa8:  10 bf ff cb  b  0xa010d9d4
a010daac:  ba 17 61 00  or  %i5, 0x100, %i5
a010dab0:  b8 10 20 10  mov  0x10, %i4
a010dab4:  3b 00 00 18  sethi  %hi(0x6000), %i5
a010dab8:  f8 2e 60 24  stb  %i4, [ %i1 + 0x24 ]
a010dabc:  10 bf ff c6  b  0xa010d9d4
a010dac0:  ba 17 61 00  or  %i5, 0x100, %i5
a010dac4:  ba 10 20 10  mov  0x10, %i5
a010dac8:  fa 2e 60 24  stb  %i5, [ %i1 + 0x24 ]
a010dacc:  3b 00 00 20  sethi  %hi(0x8000), %i5
a010dad0:  10 bf ff c1  b  0xa010d9d4
a010dad4:  ba 17 61 00  or  %i5, 0x100, %i5	! 0x8100
a010dad8:  82 10 20 10  mov  0x10, %g1
a010dadc:  3b 00 00 28  sethi  %hi(0xa000), %i5
a010dae0:  c2 2e 60 24  stb  %g1, [ %i1 + 0x24 ]
a010dae4:  10 bf ff bc  b  0xa010d9d4
a010dae8:  ba 17 61 00  or  %i5, 0x100, %i5
a010daec:  c2 27 00 00  st  %g1, [ %i4 ]
a010daf0:  81 c7 e0 08  ret
a010daf4:  81 e8 00 00  restore
