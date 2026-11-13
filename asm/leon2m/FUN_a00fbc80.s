# leon2m FUN_a00fbc80 0xa00fbc80-0xa00fbdcc (332 bytes)
a00fbc80:  9d e3 bf 80  save  %sp, -128, %sp
a00fbc84:  80 8e 20 ff  btst  0xff, %i0
a00fbc88:  12 80 00 4f  bne  0xa00fbdc4
a00fbc8c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00fbc90:  80 a6 60 00  cmp  %i1, 0
a00fbc94:  02 80 00 17  be  0xa00fbcf0
a00fbc98:  80 a6 60 01  cmp  %i1, 1
a00fbc9c:  02 80 00 31  be  0xa00fbd60
a00fbca0:  80 a6 60 02  cmp  %i1, 2
a00fbca4:  02 80 00 3b  be  0xa00fbd90
a00fbca8:  80 a6 60 03  cmp  %i1, 3
a00fbcac:  02 80 00 21  be  0xa00fbd30
a00fbcb0:  92 10 20 03  mov  3, %o1
a00fbcb4:  7f ff ff 91  call  0xa00fbaf8
a00fbcb8:  90 10 20 00  clr  %o0
a00fbcbc:  17 34 01 00  sethi  %hi(0xd0040000), %o3
a00fbcc0:  90 12 e0 2c  or  %o3, 0x2c, %o0	! 0xd004002c
a00fbcc4:  d8 02 00 00  ld  [ %o0 ], %o4
a00fbcc8:  15 20 00 00  sethi  %hi(0x80000000), %o2
a00fbccc:  92 2b 00 0a  andn  %o4, %o2, %o1
a00fbcd0:  d2 22 00 00  st  %o1, [ %o0 ]
a00fbcd4:  c0 27 bf e4  clr  [ %fp + -28 ]
a00fbcd8:  92 07 bf e4  add  %fp, -28, %o1
a00fbcdc:  94 10 20 00  clr  %o2
a00fbce0:  96 10 20 00  clr  %o3
a00fbce4:  7f ff fd d4  call  0xa00fb434
a00fbce8:  90 10 20 0a  mov  0xa, %o0
a00fbcec:  30 80 00 36  b,a   0xa00fbdc4
a00fbcf0:  92 10 20 00  clr  %o1
a00fbcf4:  7f ff ff 81  call  0xa00fbaf8
a00fbcf8:  90 10 20 00  clr  %o0
a00fbcfc:  13 34 01 00  sethi  %hi(0xd0040000), %o1
a00fbd00:  82 12 60 2c  or  %o1, 0x2c, %g1	! 0xd004002c
a00fbd04:  d8 00 40 00  ld  [ %g1 ], %o4
a00fbd08:  11 20 00 00  sethi  %hi(0x80000000), %o0
a00fbd0c:  9a 2b 00 08  andn  %o4, %o0, %o5
a00fbd10:  da 20 40 00  st  %o5, [ %g1 ]
a00fbd14:  c0 27 bf f4  clr  [ %fp + -12 ]
a00fbd18:  92 07 bf f4  add  %fp, -12, %o1
a00fbd1c:  94 10 20 00  clr  %o2
a00fbd20:  96 10 20 00  clr  %o3
a00fbd24:  7f ff fd c4  call  0xa00fb434
a00fbd28:  90 10 20 0a  mov  0xa, %o0
a00fbd2c:  30 80 00 26  b,a   0xa00fbdc4
a00fbd30:  7f ff ff 72  call  0xa00fbaf8
a00fbd34:  90 10 20 00  clr  %o0
a00fbd38:  1b 34 01 00  sethi  %hi(0xd0040000), %o5
a00fbd3c:  9e 13 60 2c  or  %o5, 0x2c, %o7	! 0xd004002c
a00fbd40:  f2 03 c0 00  ld  [ %o7 ], %i1
a00fbd44:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00fbd48:  b0 16 40 01  or  %i1, %g1, %i0
a00fbd4c:  f0 23 c0 00  st  %i0, [ %o7 ]
a00fbd50:  96 10 20 13  mov  0x13, %o3
a00fbd54:  d6 27 bf e8  st  %o3, [ %fp + -24 ]
a00fbd58:  10 bf ff f1  b  0xa00fbd1c
a00fbd5c:  92 07 bf e8  add  %fp, -24, %o1
a00fbd60:  92 10 20 03  mov  3, %o1
a00fbd64:  7f ff ff 65  call  0xa00fbaf8
a00fbd68:  90 10 20 00  clr  %o0
a00fbd6c:  33 34 01 00  sethi  %hi(0xd0040000), %i1
a00fbd70:  94 16 60 2c  or  %i1, 0x2c, %o2	! 0xd004002c
a00fbd74:  f0 02 80 00  ld  [ %o2 ], %i0
a00fbd78:  1f 20 00 00  sethi  %hi(0x80000000), %o7
a00fbd7c:  96 2e 00 0f  andn  %i0, %o7, %o3
a00fbd80:  d6 22 80 00  st  %o3, [ %o2 ]
a00fbd84:  c0 27 bf f0  clr  [ %fp + -16 ]
a00fbd88:  10 bf ff e5  b  0xa00fbd1c
a00fbd8c:  92 07 bf f0  add  %fp, -16, %o1
a00fbd90:  92 10 20 03  mov  3, %o1
a00fbd94:  7f ff ff 59  call  0xa00fbaf8
a00fbd98:  90 10 20 00  clr  %o0
a00fbd9c:  15 34 01 00  sethi  %hi(0xd0040000), %o2
a00fbda0:  9a 12 a0 2c  or  %o2, 0x2c, %o5	! 0xd004002c
a00fbda4:  d2 03 40 00  ld  [ %o5 ], %o1
a00fbda8:  19 20 00 00  sethi  %hi(0x80000000), %o4
a00fbdac:  90 12 40 0c  or  %o1, %o4, %o0
a00fbdb0:  d0 23 40 00  st  %o0, [ %o5 ]
a00fbdb4:  82 10 20 03  mov  3, %g1
a00fbdb8:  c2 27 bf ec  st  %g1, [ %fp + -20 ]
a00fbdbc:  10 bf ff d8  b  0xa00fbd1c
a00fbdc0:  92 07 bf ec  add  %fp, -20, %o1
a00fbdc4:  81 c7 e0 08  ret
a00fbdc8:  91 e8 20 01  restore  %g0, 1, %o0
