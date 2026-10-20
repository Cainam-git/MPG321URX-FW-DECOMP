# leon2m FUN_a0107a20 0xa0107a20-0xa0107b9c (380 bytes)  [FUN_a0107b94 = unreachable ret/restore tail, merged]
a0107a20:  9d e3 bf 98  save  %sp, -104, %sp
a0107a24:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0107a28:  80 a3 60 02  cmp  %o5, 2
a0107a2c:  18 80 00 59  bgu  0xa0107b90
a0107a30:  82 0e 60 ff  and  %i1, 0xff, %g1
a0107a34:  80 a0 60 01  cmp  %g1, 1
a0107a38:  02 80 00 2d  be  0xa0107aec
a0107a3c:  80 a0 00 0d  cmp  %g0, %o5
a0107a40:  b2 60 3f ff  subx  %g0, -1, %i1
a0107a44:  b4 1b 60 02  xor  %o5, 2, %i2
a0107a48:  80 a0 00 1a  cmp  %g0, %i2
a0107a4c:  9e 60 3f ff  subx  %g0, -1, %o7
a0107a50:  80 96 40 0f  orcc  %i1, %o7, %g0
a0107a54:  12 80 00 16  bne  0xa0107aac
a0107a58:  03 2a 00 9e  sethi  %hi(0xa8027800), %g1
a0107a5c:  94 06 3f ff  add  %i0, -1, %o2
a0107a60:  b0 0a a0 ff  and  %o2, 0xff, %i0
a0107a64:  80 a6 20 01  cmp  %i0, 1
a0107a68:  18 80 00 4a  bgu  0xa0107b90
a0107a6c:  33 2a 00 9e  sethi  %hi(0xa8027800), %i1
a0107a70:  de 0e 62 82  ldub  [ %i1 + 0x282 ], %o7	! 0xa8027a82
a0107a74:  90 10 20 06  mov  6, %o0
a0107a78:  80 a3 e0 01  cmp  %o7, 1
a0107a7c:  02 80 00 04  be  0xa0107a8c
a0107a80:  92 10 20 01  mov  1, %o1
a0107a84:  90 10 20 06  mov  6, %o0
a0107a88:  92 10 20 02  mov  2, %o1
a0107a8c:  7f ff db 7d  call  0xa00fe880
a0107a90:  94 10 20 00  clr  %o2
a0107a94:  11 33 c0 f0  sethi  %hi(0xcf03c000), %o0
a0107a98:  b4 12 22 b8  or  %o0, 0x2b8, %i2	! 0xcf03c2b8
a0107a9c:  c2 06 80 00  ld  [ %i2 ], %g1
a0107aa0:  98 08 7f df  and  %g1, -33, %o4
a0107aa4:  d8 26 80 00  st  %o4, [ %i2 ]
a0107aa8:  30 80 00 3a  b,a   0xa0107b90
a0107aac:  d8 08 62 82  ldub  [ %g1 + 0x282 ], %o4
a0107ab0:  90 10 20 06  mov  6, %o0
a0107ab4:  80 a3 20 01  cmp  %o4, 1
a0107ab8:  02 80 00 04  be  0xa0107ac8
a0107abc:  92 10 20 02  mov  2, %o1
a0107ac0:  90 10 20 06  mov  6, %o0
a0107ac4:  92 10 20 01  mov  1, %o1
a0107ac8:  7f ff db 6e  call  0xa00fe880
a0107acc:  94 10 20 00  clr  %o2
a0107ad0:  1b 33 c0 f0  sethi  %hi(0xcf03c000), %o5
a0107ad4:  90 13 63 48  or  %o5, 0x348, %o0	! 0xcf03c348
a0107ad8:  d2 02 00 00  ld  [ %o0 ], %o1
a0107adc:  96 0a 7f df  and  %o1, -33, %o3
a0107ae0:  d6 22 00 00  st  %o3, [ %o0 ]
a0107ae4:  10 bf ff df  b  0xa0107a60
a0107ae8:  94 06 3f ff  add  %i0, -1, %o2
a0107aec:  90 60 3f ff  subx  %g0, -1, %o0
a0107af0:  9a 1b 60 02  xor  %o5, 2, %o5
a0107af4:  80 a0 00 0d  cmp  %g0, %o5
a0107af8:  98 60 3f ff  subx  %g0, -1, %o4
a0107afc:  80 92 00 0c  orcc  %o0, %o4, %g0
a0107b00:  02 80 00 12  be  0xa0107b48
a0107b04:  82 06 3f ff  add  %i0, -1, %g1
a0107b08:  35 33 c0 f0  sethi  %hi(0xcf03c000), %i2
a0107b0c:  92 16 a3 48  or  %i2, 0x348, %o1	! 0xcf03c348
a0107b10:  f2 02 40 00  ld  [ %o1 ], %i1
a0107b14:  1f 2a 00 9e  sethi  %hi(0xa8027800), %o7
a0107b18:  d6 0b e2 82  ldub  [ %o7 + 0x282 ], %o3	! 0xa8027a82
a0107b1c:  94 16 60 20  or  %i1, 0x20, %o2
a0107b20:  d4 22 40 00  st  %o2, [ %o1 ]
a0107b24:  90 10 20 06  mov  6, %o0
a0107b28:  80 a2 e0 01  cmp  %o3, 1
a0107b2c:  02 80 00 04  be  0xa0107b3c
a0107b30:  92 10 20 02  mov  2, %o1
a0107b34:  90 10 20 06  mov  6, %o0
a0107b38:  92 10 20 01  mov  1, %o1
a0107b3c:  7f ff db 51  call  0xa00fe880
a0107b40:  94 10 20 09  mov  9, %o2
a0107b44:  82 06 3f ff  add  %i0, -1, %g1
a0107b48:  b0 08 60 ff  and  %g1, 0xff, %i0
a0107b4c:  80 a6 20 01  cmp  %i0, 1
a0107b50:  18 80 00 10  bgu  0xa0107b90
a0107b54:  15 33 c0 f0  sethi  %hi(0xcf03c000), %o2
a0107b58:  98 12 a2 b8  or  %o2, 0x2b8, %o4	! 0xcf03c2b8
a0107b5c:  d2 03 00 00  ld  [ %o4 ], %o1
a0107b60:  1b 2a 00 9e  sethi  %hi(0xa8027800), %o5
a0107b64:  d0 0b 62 82  ldub  [ %o5 + 0x282 ], %o0	! 0xa8027a82
a0107b68:  96 12 60 20  or  %o1, 0x20, %o3
a0107b6c:  d6 23 00 00  st  %o3, [ %o4 ]
a0107b70:  b0 10 20 06  mov  6, %i0
a0107b74:  80 a2 20 01  cmp  %o0, 1
a0107b78:  02 80 00 04  be  0xa0107b88
a0107b7c:  b2 10 20 01  mov  1, %i1
a0107b80:  b0 10 20 06  mov  6, %i0
a0107b84:  b2 10 20 02  mov  2, %i1
a0107b88:  7f ff db 3e  call  0xa00fe880
a0107b8c:  95 e8 20 09  restore  %g0, 9, %o2
a0107b90:  01 00 00 00  nop
a0107b94:  81 c7 e0 08  ret
a0107b98:  81 e8 00 00  restore
