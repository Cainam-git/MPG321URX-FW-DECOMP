# leon2s FUN_a00dba70 0xa00dba70-0xa00dbc8c (540 bytes)
a00dba70:  9d e3 bf 78  save  %sp, -136, %sp
a00dba74:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a00dba78:  1b 1f c0 00  sethi  %hi(0x7f000000), %o5
a00dba7c:  9a 28 40 0d  andn  %g1, %o5, %o5
a00dba80:  03 00 80 00  sethi  %hi(0x2000000), %g1
a00dba84:  9a 13 40 01  or  %o5, %g1, %o5
a00dba88:  19 00 3c 00  sethi  %hi(0xf00000), %o4
a00dba8c:  98 2b 40 0c  andn  %o5, %o4, %o4
a00dba90:  03 00 04 00  sethi  %hi(0x100000), %g1
a00dba94:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00dba98:  98 13 00 01  or  %o4, %g1, %o4
a00dba9c:  23 2a 01 d8  sethi  %hi(0xa8076000), %l1
a00dbaa0:  da 0c a0 32  ldub  [ %l2 + 0x32 ], %o5
a00dbaa4:  9b 2b 60 02  sll  %o5, 2, %o5
a00dbaa8:  82 14 60 a4  or  %l1, 0xa4, %g1
a00dbaac:  d8 27 bf e0  st  %o4, [ %fp + -32 ]
a00dbab0:  d4 00 40 0d  ld  [ %g1 + %o5 ], %o2
a00dbab4:  96 10 20 00  clr  %o3
a00dbab8:  92 07 bf f8  add  %fp, -8, %o1
a00dbabc:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00dbac0:  83 2b 60 02  sll  %o5, 2, %g1
a00dbac4:  82 00 40 0a  add  %g1, %o2, %g1
a00dbac8:  d8 00 6d 00  ld  [ %g1 + 0xd00 ], %o4
a00dbacc:  96 02 e0 01  inc  %o3
a00dbad0:  9a 02 40 0d  add  %o1, %o5, %o5
a00dbad4:  82 0a e0 ff  and  %o3, 0xff, %g1
a00dbad8:  80 a0 60 0f  cmp  %g1, 0xf
a00dbadc:  08 bf ff f8  bleu  0xa00dbabc
a00dbae0:  d8 2b 7f ea  stb  %o4, [ %o5 + -22 ]
a00dbae4:  96 10 20 00  clr  %o3
a00dbae8:  82 0a e0 ff  and  %o3, 0xff, %g1
a00dbaec:  82 02 40 01  add  %o1, %g1, %g1
a00dbaf0:  c2 08 7f ea  ldub  [ %g1 + -22 ], %g1
a00dbaf4:  80 a0 60 00  cmp  %g1, 0
a00dbaf8:  12 80 00 09  bne  0xa00dbb1c
a00dbafc:  82 0a e0 ff  and  %o3, 0xff, %g1
a00dbb00:  96 02 e0 01  inc  %o3
a00dbb04:  82 0a e0 ff  and  %o3, 0xff, %g1
a00dbb08:  80 a0 60 0f  cmp  %g1, 0xf
a00dbb0c:  08 bf ff f9  bleu  0xa00dbaf0
a00dbb10:  82 02 40 01  add  %o1, %g1, %g1
a00dbb14:  10 80 00 5c  b  0xa00dbc84
a00dbb18:  b0 10 20 00  clr  %i0
a00dbb1c:  80 a0 60 0f  cmp  %g1, 0xf
a00dbb20:  08 80 00 04  bleu  0xa00dbb30
a00dbb24:  82 0e 20 ff  and  %i0, 0xff, %g1
a00dbb28:  10 80 00 57  b  0xa00dbc84
a00dbb2c:  b0 10 20 00  clr  %i0
a00dbb30:  80 a0 60 01  cmp  %g1, 1
a00dbb34:  12 80 00 3e  bne  0xa00dbc2c
a00dbb38:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a00dbb3c:  92 10 20 90  mov  0x90, %o1
a00dbb40:  94 10 20 00  clr  %o2
a00dbb44:  96 10 20 00  clr  %o3
a00dbb48:  98 07 bf df  add  %fp, -33, %o4
a00dbb4c:  40 3a ea 2d  call  0xa0f96400
a00dbb50:  90 10 20 00  clr  %o0
a00dbb54:  c2 0f bf df  ldub  [ %fp + -33 ], %g1
a00dbb58:  21 2a 01 e2  sethi  %hi(0xa8078800), %l0
a00dbb5c:  c2 2c 20 46  stb  %g1, [ %l0 + 0x46 ]	! 0xa8078846
a00dbb60:  98 07 bf df  add  %fp, -33, %o4
a00dbb64:  90 10 20 00  clr  %o0
a00dbb68:  92 10 20 90  mov  0x90, %o1
a00dbb6c:  94 10 20 21  mov  0x21, %o2
a00dbb70:  40 3a ea 24  call  0xa0f96400
a00dbb74:  96 10 20 00  clr  %o3
a00dbb78:  da 0c 20 46  ldub  [ %l0 + 0x46 ], %o5
a00dbb7c:  d8 0f bf df  ldub  [ %fp + -33 ], %o4
a00dbb80:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbb84:  80 a3 60 11  cmp  %o5, 0x11
a00dbb88:  18 80 00 0c  bgu  0xa00dbbb8
a00dbb8c:  d8 28 60 43  stb  %o4, [ %g1 + 0x43 ]
a00dbb90:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a00dbb94:  1b 00 00 10  sethi  %hi(0x4000), %o5
a00dbb98:  9a 28 40 0d  andn  %g1, %o5, %o5
a00dbb9c:  03 00 00 08  sethi  %hi(0x2000), %g1
a00dbba0:  9a 13 40 01  or  %o5, %g1, %o5
a00dbba4:  82 00 70 00  add  %g1, -4096, %g1
a00dbba8:  82 2b 40 01  andn  %o5, %g1, %g1
a00dbbac:  82 08 70 ff  and  %g1, -3841, %g1
a00dbbb0:  10 80 00 0d  b  0xa00dbbe4
a00dbbb4:  82 10 63 00  or  %g1, 0x300, %g1
a00dbbb8:  80 8b 20 01  btst  1, %o4
a00dbbbc:  02 80 00 0c  be  0xa00dbbec
a00dbbc0:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a00dbbc4:  03 00 00 10  sethi  %hi(0x4000), %g1
a00dbbc8:  82 2b 40 01  andn  %o5, %g1, %g1
a00dbbcc:  1b 00 00 08  sethi  %hi(0x2000), %o5
a00dbbd0:  82 10 40 0d  or  %g1, %o5, %g1
a00dbbd4:  9a 03 70 00  add  %o5, -4096, %o5
a00dbbd8:  82 10 40 0d  or  %g1, %o5, %g1
a00dbbdc:  82 08 70 ff  and  %g1, -3841, %g1
a00dbbe0:  82 10 62 00  or  %g1, 0x200, %g1
a00dbbe4:  10 80 00 0b  b  0xa00dbc10
a00dbbe8:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a00dbbec:  03 00 00 10  sethi  %hi(0x4000), %g1
a00dbbf0:  82 2b 40 01  andn  %o5, %g1, %g1
a00dbbf4:  1b 00 00 08  sethi  %hi(0x2000), %o5
a00dbbf8:  82 10 40 0d  or  %g1, %o5, %g1
a00dbbfc:  9a 03 70 00  add  %o5, -4096, %o5
a00dbc00:  9a 28 40 0d  andn  %g1, %o5, %o5
a00dbc04:  9a 0b 70 ff  and  %o5, -3841, %o5
a00dbc08:  9a 13 62 00  or  %o5, 0x200, %o5
a00dbc0c:  da 27 bf f0  st  %o5, [ %fp + -16 ]
a00dbc10:  c2 0c a0 32  ldub  [ %l2 + 0x32 ], %g1
a00dbc14:  83 28 60 02  sll  %g1, 2, %g1
a00dbc18:  9a 14 60 a4  or  %l1, 0xa4, %o5
a00dbc1c:  da 03 40 01  ld  [ %o5 + %g1 ], %o5
a00dbc20:  c2 03 68 14  ld  [ %o5 + 0x814 ], %g1
a00dbc24:  10 80 00 10  b  0xa00dbc64
a00dbc28:  82 10 60 01  or  %g1, 1, %g1
a00dbc2c:  1b 00 00 10  sethi  %hi(0x4000), %o5
a00dbc30:  9a 28 40 0d  andn  %g1, %o5, %o5
a00dbc34:  03 00 00 08  sethi  %hi(0x2000), %g1
a00dbc38:  82 2b 40 01  andn  %o5, %g1, %g1
a00dbc3c:  1b 00 00 04  sethi  %hi(0x1000), %o5
a00dbc40:  9a 28 40 0d  andn  %g1, %o5, %o5
a00dbc44:  9a 0b 70 ff  and  %o5, -3841, %o5
a00dbc48:  c2 0c a0 32  ldub  [ %l2 + 0x32 ], %g1
a00dbc4c:  83 28 60 02  sll  %g1, 2, %g1
a00dbc50:  da 27 bf f0  st  %o5, [ %fp + -16 ]
a00dbc54:  98 14 60 a4  or  %l1, 0xa4, %o4
a00dbc58:  da 03 00 01  ld  [ %o4 + %g1 ], %o5
a00dbc5c:  c2 03 68 14  ld  [ %o5 + 0x814 ], %g1
a00dbc60:  82 08 7f fe  and  %g1, -2, %g1
a00dbc64:  c2 23 68 14  st  %g1, [ %o5 + 0x814 ]
a00dbc68:  90 07 bf e0  add  %fp, -32, %o0
a00dbc6c:  92 10 20 02  mov  2, %o1
a00dbc70:  94 10 20 01  mov  1, %o2
a00dbc74:  96 10 20 11  mov  0x11, %o3
a00dbc78:  7f ff ef 29  call  0xa00d791c
a00dbc7c:  98 10 20 13  mov  0x13, %o4
a00dbc80:  b0 10 20 01  mov  1, %i0
a00dbc84:  81 c7 e0 08  ret
a00dbc88:  81 e8 00 00  restore
