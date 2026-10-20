# leon2s FUN_a00af98c 0xa00af98c-0xa00afbbc (560 bytes)
a00af98c:  9d e3 bf 98  save  %sp, -104, %sp
a00af990:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00af994:  90 10 00 18  mov  %i0, %o0
a00af998:  92 10 20 46  mov  0x46, %o1
a00af99c:  7f ff dc 99  call  0xa00a6c00
a00af9a0:  94 10 20 13  mov  0x13, %o2
a00af9a4:  90 10 00 18  mov  %i0, %o0
a00af9a8:  92 10 20 d3  mov  0xd3, %o1
a00af9ac:  94 10 20 04  mov  4, %o2
a00af9b0:  7f ff dc ba  call  0xa00a6c98
a00af9b4:  96 10 20 00  clr  %o3
a00af9b8:  35 2a 01 f7  sethi  %hi(0xa807dc00), %i2
a00af9bc:  82 16 a0 18  or  %i2, 0x18, %g1	! 0xa807dc18
a00af9c0:  9a 5e 21 2c  smul  %i0, 0x12c, %o5
a00af9c4:  9a 03 40 01  add  %o5, %g1, %o5
a00af9c8:  c2 0b 61 15  ldub  [ %o5 + 0x115 ], %g1
a00af9cc:  80 a0 60 00  cmp  %g1, 0
a00af9d0:  02 80 00 06  be  0xa00af9e8
a00af9d4:  90 10 00 18  mov  %i0, %o0
a00af9d8:  92 10 20 4d  mov  0x4d, %o1
a00af9dc:  94 10 20 80  mov  0x80, %o2
a00af9e0:  10 80 00 05  b  0xa00af9f4
a00af9e4:  96 10 20 00  clr  %o3
a00af9e8:  92 10 20 4d  mov  0x4d, %o1
a00af9ec:  94 10 20 80  mov  0x80, %o2
a00af9f0:  96 10 20 01  mov  1, %o3
a00af9f4:  7f ff dc a9  call  0xa00a6c98
a00af9f8:  01 00 00 00  nop
a00af9fc:  96 10 20 00  clr  %o3	! 0x0
a00afa00:  90 10 00 18  mov  %i0, %o0
a00afa04:  92 10 20 03  mov  3, %o1
a00afa08:  7f ff dc a4  call  0xa00a6c98
a00afa0c:  94 10 20 20  mov  0x20, %o2
a00afa10:  90 10 00 18  mov  %i0, %o0
a00afa14:  92 10 20 bc  mov  0xbc, %o1
a00afa18:  7f ff dc 7a  call  0xa00a6c00
a00afa1c:  94 10 20 d0  mov  0xd0, %o2
a00afa20:  90 10 00 18  mov  %i0, %o0
a00afa24:  92 10 20 39  mov  0x39, %o1
a00afa28:  94 10 20 08  mov  8, %o2
a00afa2c:  7f ff dc 9b  call  0xa00a6c98
a00afa30:  96 10 20 01  mov  1, %o3
a00afa34:  90 10 00 18  mov  %i0, %o0
a00afa38:  92 10 20 43  mov  0x43, %o1
a00afa3c:  94 10 20 10  mov  0x10, %o2
a00afa40:  7f ff dc 96  call  0xa00a6c98
a00afa44:  96 10 20 01  mov  1, %o3
a00afa48:  90 10 00 18  mov  %i0, %o0
a00afa4c:  92 10 24 04  mov  0x404, %o1
a00afa50:  94 10 20 01  mov  1, %o2
a00afa54:  7f ff dc 91  call  0xa00a6c98
a00afa58:  96 10 20 01  mov  1, %o3
a00afa5c:  80 a6 20 00  cmp  %i0, 0
a00afa60:  22 80 00 0c  be,a   0xa00afa90
a00afa64:  90 10 20 00  clr  %o0
a00afa68:  13 00 02 43  sethi  %hi(0x90c00), %o1
a00afa6c:  15 00 03 15  sethi  %hi(0xc5400), %o2
a00afa70:  90 10 00 18  mov  %i0, %o0
a00afa74:  92 12 61 fe  or  %o1, 0x1fe, %o1
a00afa78:  7f ff ff 91  call  0xa00af8bc
a00afa7c:  94 12 a0 27  or  %o2, 0x27, %o2
a00afa80:  7f ff ff b3  call  0xa00af94c
a00afa84:  90 10 00 18  mov  %i0, %o0
a00afa88:  10 80 00 38  b  0xa00afb68
a00afa8c:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00afa90:  7f c4 5a c4  call  0x9f1c65a0
a00afa94:  92 10 20 03  mov  3, %o1
a00afa98:  21 00 02 43  sethi  %hi(0x90c00), %l0
a00afa9c:  23 00 03 15  sethi  %hi(0xc5400), %l1
a00afaa0:  94 14 60 27  or  %l1, 0x27, %o2	! 0xc5427
a00afaa4:  92 14 21 fe  or  %l0, 0x1fe, %o1
a00afaa8:  7f ff ff 85  call  0xa00af8bc
a00afaac:  90 10 20 00  clr  %o0
a00afab0:  7f ff ff a7  call  0xa00af94c
a00afab4:  90 10 20 00  clr  %o0
a00afab8:  90 10 20 00  clr  %o0
a00afabc:  7f c4 5a b9  call  0x9f1c65a0
a00afac0:  92 10 20 02  mov  2, %o1
a00afac4:  94 14 60 27  or  %l1, 0x27, %o2
a00afac8:  92 14 21 fe  or  %l0, 0x1fe, %o1
a00afacc:  7f ff ff 7c  call  0xa00af8bc
a00afad0:  90 10 20 00  clr  %o0
a00afad4:  7f ff ff 9e  call  0xa00af94c
a00afad8:  90 10 20 00  clr  %o0
a00afadc:  90 10 20 00  clr  %o0
a00afae0:  7f c4 5a b0  call  0x9f1c65a0
a00afae4:  92 10 20 01  mov  1, %o1
a00afae8:  94 14 60 27  or  %l1, 0x27, %o2
a00afaec:  92 14 21 fe  or  %l0, 0x1fe, %o1
a00afaf0:  7f ff ff 73  call  0xa00af8bc
a00afaf4:  90 10 20 00  clr  %o0
a00afaf8:  7f ff ff 95  call  0xa00af94c
a00afafc:  90 10 20 00  clr  %o0
a00afb00:  90 10 20 00  clr  %o0
a00afb04:  7f c4 5a a7  call  0x9f1c65a0
a00afb08:  92 10 20 00  clr  %o1
a00afb0c:  92 14 21 fe  or  %l0, 0x1fe, %o1
a00afb10:  94 14 60 27  or  %l1, 0x27, %o2
a00afb14:  7f ff ff 6a  call  0xa00af8bc
a00afb18:  90 10 20 00  clr  %o0
a00afb1c:  7f ff ff 8c  call  0xa00af94c
a00afb20:  90 10 20 00  clr  %o0
a00afb24:  82 16 a0 18  or  %i2, 0x18, %g1
a00afb28:  c2 08 61 12  ldub  [ %g1 + 0x112 ], %g1
a00afb2c:  80 a0 60 00  cmp  %g1, 0
a00afb30:  02 80 00 0e  be  0xa00afb68
a00afb34:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00afb38:  1b 33 c0 11  sethi  %hi(0xcf004400), %o5
a00afb3c:  9a 13 62 b0  or  %o5, 0x2b0, %o5	! 0xcf0046b0
a00afb40:  c2 03 40 00  ld  [ %o5 ], %g1
a00afb44:  82 10 60 01  or  %g1, 1, %g1
a00afb48:  c2 23 40 00  st  %g1, [ %o5 ]
a00afb4c:  c2 03 40 00  ld  [ %o5 ], %g1
a00afb50:  82 10 60 02  or  %g1, 2, %g1
a00afb54:  c2 23 40 00  st  %g1, [ %o5 ]
a00afb58:  c2 03 40 00  ld  [ %o5 ], %g1
a00afb5c:  82 10 60 04  or  %g1, 4, %g1
a00afb60:  c2 23 40 00  st  %g1, [ %o5 ]
a00afb64:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00afb68:  82 5e 21 2c  smul  %i0, 0x12c, %g1
a00afb6c:  9a 13 60 18  or  %o5, 0x18, %o5
a00afb70:  9a 00 40 0d  add  %g1, %o5, %o5
a00afb74:  c2 0b 61 16  ldub  [ %o5 + 0x116 ], %g1
a00afb78:  80 a0 60 00  cmp  %g1, 0
a00afb7c:  d2 0b 61 26  ldub  [ %o5 + 0x126 ], %o1
a00afb80:  02 80 00 06  be  0xa00afb98
a00afb84:  94 10 20 00  clr  %o2
a00afb88:  c2 0b 61 12  ldub  [ %o5 + 0x112 ], %g1
a00afb8c:  80 a0 60 00  cmp  %g1, 0
a00afb90:  22 80 00 02  be,a   0xa00afb98
a00afb94:  94 10 20 01  mov  1, %o2
a00afb98:  7f c4 1a f2  call  0x9f1b6760
a00afb9c:  90 10 00 18  mov  %i0, %o0
a00afba0:  90 10 00 18  mov  %i0, %o0
a00afba4:  7f ff dc 05  call  0xa00a6bb8
a00afba8:  92 10 20 2d  mov  0x2d, %o1
a00afbac:  b4 0a 20 fc  and  %o0, 0xfc, %i2
a00afbb0:  7f ff dc 14  call  0xa00a6c00
a00afbb4:  93 e8 20 2d  restore  %g0, 0x2d, %o1
a00afbb8:  01 00 00 00  nop
