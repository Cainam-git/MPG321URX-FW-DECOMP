# leon2m FUN_a00ca878 0xa00ca878-0xa00cab68 (752 bytes)
a00ca878:  9d e3 bf 98  save  %sp, -104, %sp
a00ca87c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ca880:  80 a6 20 02  cmp  %i0, 2
a00ca884:  02 80 00 6c  be  0xa00caa34
a00ca888:  80 a6 20 03  cmp  %i0, 3
a00ca88c:  02 80 00 93  be  0xa00caad8
a00ca890:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00ca894:  c2 0a 60 d6  ldub  [ %o1 + 0xd6 ], %g1	! 0xa802d0d6
a00ca898:  96 08 60 ff  and  %g1, 0xff, %o3
a00ca89c:  94 02 ff d0  add  %o3, -48, %o2
a00ca8a0:  82 0a a0 ff  and  %o2, 0xff, %g1
a00ca8a4:  80 a0 60 01  cmp  %g1, 1
a00ca8a8:  18 80 00 ae  bgu  0xa00cab60
a00ca8ac:  9a 10 20 ff  mov  0xff, %o5
a00ca8b0:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ca8b4:  9e 12 a2 90  or  %o2, 0x290, %o7	! 0xa802d290
a00ca8b8:  90 08 60 01  and  %g1, 1, %o0
a00ca8bc:  d6 03 e1 dc  ld  [ %o7 + 0x1dc ], %o3
a00ca8c0:  13 00 00 20  sethi  %hi(0x8000), %o1
a00ca8c4:  82 2a c0 09  andn  %o3, %o1, %g1
a00ca8c8:  9b 2a 20 0f  sll  %o0, 0xf, %o5
a00ca8cc:  98 10 40 0d  or  %g1, %o5, %o4
a00ca8d0:  80 a6 20 02  cmp  %i0, 2
a00ca8d4:  02 80 00 5b  be  0xa00caa40
a00ca8d8:  d8 23 e1 dc  st  %o4, [ %o7 + 0x1dc ]
a00ca8dc:  80 a6 20 03  cmp  %i0, 3
a00ca8e0:  02 80 00 81  be  0xa00caae4
a00ca8e4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ca8e8:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00ca8ec:  c2 08 60 d7  ldub  [ %g1 + 0xd7 ], %g1	! 0xa802d0d7
a00ca8f0:  90 08 60 ff  and  %g1, 0xff, %o0
a00ca8f4:  98 02 3f d0  add  %o0, -48, %o4
a00ca8f8:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00ca8fc:  80 a3 60 01  cmp  %o5, 1
a00ca900:  18 80 00 98  bgu  0xa00cab60
a00ca904:  9a 10 20 ff  mov  0xff, %o5
a00ca908:  92 12 a2 90  or  %o2, 0x290, %o1
a00ca90c:  80 a6 20 02  cmp  %i0, 2
a00ca910:  02 80 00 4f  be  0xa00caa4c
a00ca914:  d8 2a 61 e0  stb  %o4, [ %o1 + 0x1e0 ]
a00ca918:  80 a6 20 03  cmp  %i0, 3
a00ca91c:  02 80 00 8b  be  0xa00cab48
a00ca920:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ca924:  c2 0b 20 d8  ldub  [ %o4 + 0xd8 ], %g1	! 0xa802d0d8
a00ca928:  9a 08 60 ff  and  %g1, 0xff, %o5
a00ca92c:  98 03 7f d0  add  %o5, -48, %o4
a00ca930:  82 0b 20 ff  and  %o4, 0xff, %g1
a00ca934:  80 a0 60 01  cmp  %g1, 1
a00ca938:  18 80 00 8a  bgu  0xa00cab60
a00ca93c:  9a 10 20 ff  mov  0xff, %o5
a00ca940:  90 12 a2 90  or  %o2, 0x290, %o0
a00ca944:  80 a6 20 02  cmp  %i0, 2
a00ca948:  02 80 00 44  be  0xa00caa58
a00ca94c:  d8 2a 21 e1  stb  %o4, [ %o0 + 0x1e1 ]
a00ca950:  80 a6 20 03  cmp  %i0, 3
a00ca954:  02 80 00 80  be  0xa00cab54
a00ca958:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00ca95c:  c2 0b e0 d9  ldub  [ %o7 + 0xd9 ], %g1	! 0xa802d0d9
a00ca960:  9a 08 60 ff  and  %g1, 0xff, %o5
a00ca964:  98 03 7f d0  add  %o5, -48, %o4
a00ca968:  82 0b 20 ff  and  %o4, 0xff, %g1
a00ca96c:  80 a0 60 08  cmp  %g1, 8
a00ca970:  18 80 00 7c  bgu  0xa00cab60
a00ca974:  9a 10 20 ff  mov  0xff, %o5
a00ca978:  90 12 a2 90  or  %o2, 0x290, %o0
a00ca97c:  40 00 40 69  call  0xa00dab20
a00ca980:  d8 2a 21 df  stb  %o4, [ %o0 + 0x1df ]
a00ca984:  7f ff b7 d2  call  0xa00b88cc
a00ca988:  01 00 00 00  nop
a00ca98c:  80 a6 20 02  cmp  %i0, 2
a00ca990:  02 80 00 35  be  0xa00caa64
a00ca994:  80 a6 20 03  cmp  %i0, 3
a00ca998:  02 80 00 55  be  0xa00caaec
a00ca99c:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ca9a0:  94 13 20 78  or  %o4, 0x78, %o2	! 0xa802d078
a00ca9a4:  9e 10 20 30  mov  0x30, %o7
a00ca9a8:  92 10 20 35  mov  0x35, %o1
a00ca9ac:  9a 10 20 36  mov  0x36, %o5
a00ca9b0:  90 10 20 2b  mov  0x2b, %o0
a00ca9b4:  82 10 20 0d  mov  0xd, %g1
a00ca9b8:  d2 2b 20 78  stb  %o1, [ %o4 + 0x78 ]
a00ca9bc:  da 2a a0 01  stb  %o5, [ %o2 + 1 ]
a00ca9c0:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00ca9c4:  d0 2a a0 04  stb  %o0, [ %o2 + 4 ]
a00ca9c8:  c2 2a a0 05  stb  %g1, [ %o2 + 5 ]
a00ca9cc:  80 a6 20 02  cmp  %i0, 2
a00ca9d0:  02 80 00 32  be  0xa00caa98
a00ca9d4:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00ca9d8:  80 a6 20 03  cmp  %i0, 3
a00ca9dc:  02 80 00 51  be  0xa00cab20
a00ca9e0:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ca9e4:  9a 13 20 d0  or  %o4, 0xd0, %o5	! 0xa802d0d0
a00ca9e8:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00ca9ec:  c0 2a 60 9c  clrb  [ %o1 + 0x9c ]	! 0xa802b09c
a00ca9f0:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00ca9f4:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00ca9f8:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00ca9fc:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00caa00:  80 a6 20 02  cmp  %i0, 2
a00caa04:  02 80 00 2e  be  0xa00caabc
a00caa08:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00caa0c:  80 a6 20 03  cmp  %i0, 3
a00caa10:  12 80 00 2e  bne  0xa00caac8
a00caa14:  90 10 00 18  mov  %i0, %o0
a00caa18:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00caa1c:  94 12 a1 08  or  %o2, 0x108, %o2	! 0xa802d108
a00caa20:  90 10 20 03  mov  3, %o0
a00caa24:  40 01 f7 71  call  0xa01487e8
a00caa28:  92 10 20 06  mov  6, %o1
a00caa2c:  10 80 00 4d  b  0xa00cab60
a00caa30:  9a 10 20 00  clr  %o5
a00caa34:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00caa38:  10 bf ff 98  b  0xa00ca898
a00caa3c:  c2 08 60 46  ldub  [ %g1 + 0x46 ], %g1	! 0xa802d046
a00caa40:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00caa44:  10 bf ff ab  b  0xa00ca8f0
a00caa48:  c2 0b e0 47  ldub  [ %o7 + 0x47 ], %g1	! 0xa802d047
a00caa4c:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00caa50:  10 bf ff b6  b  0xa00ca928
a00caa54:  c2 0a e0 48  ldub  [ %o3 + 0x48 ], %g1	! 0xa802d048
a00caa58:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00caa5c:  10 bf ff c1  b  0xa00ca960
a00caa60:  c2 0a 60 49  ldub  [ %o1 + 0x49 ], %g1	! 0xa802d049
a00caa64:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00caa68:  b0 13 e1 28  or  %o7, 0x128, %i0	! 0xa802d128
a00caa6c:  94 10 20 30  mov  0x30, %o2
a00caa70:  82 10 20 35  mov  0x35, %g1
a00caa74:  96 10 20 0d  mov  0xd, %o3
a00caa78:  92 10 20 36  mov  0x36, %o1
a00caa7c:  98 10 20 2b  mov  0x2b, %o4
a00caa80:  c2 2b e1 28  stb  %g1, [ %o7 + 0x128 ]
a00caa84:  d6 2e 20 05  stb  %o3, [ %i0 + 5 ]
a00caa88:  d2 2e 20 01  stb  %o1, [ %i0 + 1 ]
a00caa8c:  d4 2e 20 03  stb  %o2, [ %i0 + 3 ]
a00caa90:  d8 2e 20 04  stb  %o4, [ %i0 + 4 ]
a00caa94:  d4 2e 20 02  stb  %o2, [ %i0 + 2 ]
a00caa98:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00caa9c:  b0 12 a0 40  or  %o2, 0x40, %i0	! 0xa802d040
a00caaa0:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00caaa4:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]	! 0xa802b09a
a00caaa8:  c0 2a a0 40  clrb  [ %o2 + 0x40 ]
a00caaac:  c0 2e 20 19  clrb  [ %i0 + 0x19 ]
a00caab0:  c0 2e 20 01  clrb  [ %i0 + 1 ]
a00caab4:  c0 2e 20 07  clrb  [ %i0 + 7 ]
a00caab8:  c0 2e 20 0a  clrb  [ %i0 + 0xa ]
a00caabc:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a00caac0:  94 16 21 28  or  %i0, 0x128, %o2	! 0xa802d128
a00caac4:  90 10 20 02  mov  2, %o0
a00caac8:  40 01 f7 48  call  0xa01487e8
a00caacc:  92 10 20 06  mov  6, %o1
a00caad0:  10 80 00 24  b  0xa00cab60
a00caad4:  9a 10 20 00  clr  %o5
a00caad8:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00caadc:  10 bf ff 6f  b  0xa00ca898
a00caae0:  c2 0a 20 9e  ldub  [ %o0 + 0x9e ], %g1	! 0xa802d09e
a00caae4:  10 bf ff 83  b  0xa00ca8f0
a00caae8:  c2 0b 20 9f  ldub  [ %o4 + 0x9f ], %g1
a00caaec:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00caaf0:  90 12 61 08  or  %o1, 0x108, %o0	! 0xa802d108
a00caaf4:  b0 10 20 30  mov  0x30, %i0
a00caaf8:  96 10 20 35  mov  0x35, %o3
a00caafc:  98 10 20 0d  mov  0xd, %o4
a00cab00:  94 10 20 36  mov  0x36, %o2
a00cab04:  9a 10 20 2b  mov  0x2b, %o5
a00cab08:  d6 2a 61 08  stb  %o3, [ %o1 + 0x108 ]
a00cab0c:  d8 2a 20 05  stb  %o4, [ %o0 + 5 ]
a00cab10:  d4 2a 20 01  stb  %o2, [ %o0 + 1 ]
a00cab14:  f0 2a 20 03  stb  %i0, [ %o0 + 3 ]
a00cab18:  da 2a 20 04  stb  %o5, [ %o0 + 4 ]
a00cab1c:  f0 2a 20 02  stb  %i0, [ %o0 + 2 ]
a00cab20:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cab24:  9e 12 20 98  or  %o0, 0x98, %o7	! 0xa802d098
a00cab28:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00cab2c:  c0 28 60 98  clrb  [ %g1 + 0x98 ]	! 0xa802b098
a00cab30:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]
a00cab34:  c0 2b e0 19  clrb  [ %o7 + 0x19 ]
a00cab38:  c0 2b e0 01  clrb  [ %o7 + 1 ]
a00cab3c:  c0 2b e0 07  clrb  [ %o7 + 7 ]
a00cab40:  10 bf ff b6  b  0xa00caa18
a00cab44:  c0 2b e0 0a  clrb  [ %o7 + 0xa ]
a00cab48:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00cab4c:  10 bf ff 77  b  0xa00ca928
a00cab50:  c2 0b e0 a0  ldub  [ %o7 + 0xa0 ], %g1	! 0xa802d0a0
a00cab54:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00cab58:  10 bf ff 82  b  0xa00ca960
a00cab5c:  c2 0a e0 a1  ldub  [ %o3 + 0xa1 ], %g1	! 0xa802d0a1
a00cab60:  81 c7 e0 08  ret
a00cab64:  91 e8 00 0d  restore  %g0, %o5, %o0
