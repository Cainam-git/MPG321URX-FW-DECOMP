# leon2m FUN_a00bbabc 0xa00bbabc-0xa00bbda0 (740 bytes)
a00bbabc:  9d e3 bf 98  save  %sp, -104, %sp
a00bbac0:  7f ff fe a8  call  0xa00bb560
a00bbac4:  90 10 20 02  mov  2, %o0
a00bbac8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00bbacc:  80 a2 20 10  cmp  %o0, 0x10
a00bbad0:  02 80 00 2c  be  0xa00bbb80
a00bbad4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00bbad8:  14 80 00 08  bg  0xa00bbaf8
a00bbadc:  80 a2 20 40  cmp  %o0, 0x40
a00bbae0:  80 a2 20 02  cmp  %o0, 2
a00bbae4:  02 80 00 50  be  0xa00bbc24
a00bbae8:  80 a2 20 04  cmp  %o0, 4
a00bbaec:  12 80 00 ab  bne  0xa00bbd98
a00bbaf0:  01 00 00 00  nop
a00bbaf4:  30 80 00 80  b,a   0xa00bbcf4
a00bbaf8:  02 80 00 3d  be  0xa00bbbec
a00bbafc:  80 a2 20 40  cmp  %o0, 0x40
a00bbb00:  14 80 00 2d  bg  0xa00bbbb4
a00bbb04:  80 a2 20 80  cmp  %o0, 0x80
a00bbb08:  80 a2 20 20  cmp  %o0, 0x20
a00bbb0c:  12 80 00 a3  bne  0xa00bbd98
a00bbb10:  17 2a 00 ac  sethi  %hi(0xa802b000), %o3
a00bbb14:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bbb18:  c0 2a e0 9a  clrb  [ %o3 + 0x9a ]
a00bbb1c:  9a 12 a0 40  or  %o2, 0x40, %o5
a00bbb20:  98 10 20 00  clr  %o4
a00bbb24:  82 10 20 00  clr  %g1
a00bbb28:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbb2c:  98 03 20 01  inc  %o4
a00bbb30:  82 0b 20 ff  and  %o4, 0xff, %g1
a00bbb34:  80 a0 60 31  cmp  %g1, 0x31
a00bbb38:  28 bf ff fd  bleu,a   0xa00bbb2c
a00bbb3c:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbb40:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bbb44:  b4 13 61 28  or  %o5, 0x128, %i2	! 0xa802d128
a00bbb48:  b2 10 20 36  mov  0x36, %i1
a00bbb4c:  b0 10 20 2d  mov  0x2d, %i0
a00bbb50:  a0 10 20 30  mov  0x30, %l0
a00bbb54:  82 10 20 35  mov  0x35, %g1
a00bbb58:  f2 2e a0 01  stb  %i1, [ %i2 + 1 ]
a00bbb5c:  f0 2e a0 04  stb  %i0, [ %i2 + 4 ]
a00bbb60:  a2 10 20 0d  mov  0xd, %l1
a00bbb64:  c2 2b 61 28  stb  %g1, [ %o5 + 0x128 ]
a00bbb68:  e0 2e a0 03  stb  %l0, [ %i2 + 3 ]
a00bbb6c:  e2 2e a0 05  stb  %l1, [ %i2 + 5 ]
a00bbb70:  e0 2e a0 02  stb  %l0, [ %i2 + 2 ]
a00bbb74:  b0 10 20 02  mov  2, %i0
a00bbb78:  40 02 33 1c  call  0xa01487e8
a00bbb7c:  93 e8 20 06  restore  %g0, 6, %o1
a00bbb80:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00bbb84:  9a 13 20 40  or  %o4, 0x40, %o5
a00bbb88:  c0 2b e0 9a  clrb  [ %o7 + 0x9a ]
a00bbb8c:  98 10 20 00  clr  %o4
a00bbb90:  82 10 20 00  clr  %g1
a00bbb94:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbb98:  98 03 20 01  inc  %o4
a00bbb9c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00bbba0:  80 a0 60 31  cmp  %g1, 0x31
a00bbba4:  28 bf ff fd  bleu,a   0xa00bbb98
a00bbba8:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbbac:  10 bf ff e6  b  0xa00bbb44
a00bbbb0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bbbb4:  12 80 00 79  bne  0xa00bbd98
a00bbbb8:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00bbbbc:  c0 28 60 9a  clrb  [ %g1 + 0x9a ]	! 0xa802b09a
a00bbbc0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bbbc4:  9a 13 60 40  or  %o5, 0x40, %o5	! 0xa802d040
a00bbbc8:  98 10 20 00  clr  %o4
a00bbbcc:  82 10 20 00  clr  %g1
a00bbbd0:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbbd4:  98 03 20 01  inc  %o4
a00bbbd8:  82 0b 20 ff  and  %o4, 0xff, %g1
a00bbbdc:  80 a0 60 31  cmp  %g1, 0x31
a00bbbe0:  28 bf ff fd  bleu,a   0xa00bbbd4
a00bbbe4:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbbe8:  30 80 00 6c  b,a   0xa00bbd98
a00bbbec:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00bbbf0:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bbbf4:  c0 2a 60 9a  clrb  [ %o1 + 0x9a ]
a00bbbf8:  9a 12 20 40  or  %o0, 0x40, %o5
a00bbbfc:  98 10 20 00  clr  %o4
a00bbc00:  82 10 20 00  clr  %g1
a00bbc04:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbc08:  98 03 20 01  inc  %o4
a00bbc0c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00bbc10:  80 a0 60 31  cmp  %g1, 0x31
a00bbc14:  28 bf ff fd  bleu,a   0xa00bbc08
a00bbc18:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbc1c:  10 bf ff ca  b  0xa00bbb44
a00bbc20:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bbc24:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bbc28:  a2 16 a0 40  or  %i2, 0x40, %l1	! 0xa802d040
a00bbc2c:  a0 10 20 00  clr  %l0
a00bbc30:  b0 10 20 00  clr  %i0
a00bbc34:  b2 10 20 02  mov  2, %i1
a00bbc38:  b4 10 20 02  mov  2, %i2
a00bbc3c:  92 10 00 1a  mov  %i2, %o1
a00bbc40:  40 02 62 7f  call  0xa015463c
a00bbc44:  90 10 00 18  mov  %i0, %o0
a00bbc48:  94 0a 20 ff  and  %o0, 0xff, %o2
a00bbc4c:  b2 06 60 01  inc  %i1
a00bbc50:  92 10 00 1a  mov  %i2, %o1
a00bbc54:  80 a2 a0 ff  cmp  %o2, 0xff
a00bbc58:  02 80 00 09  be  0xa00bbc7c
a00bbc5c:  90 10 00 18  mov  %i0, %o0
a00bbc60:  40 02 62 77  call  0xa015463c
a00bbc64:  01 00 00 00  nop
a00bbc68:  90 0a 20 ff  and  %o0, 0xff, %o0
a00bbc6c:  d2 0c 40 1a  ldub  [ %l1 + %i2 ], %o1
a00bbc70:  80 a2 00 09  cmp  %o0, %o1
a00bbc74:  12 80 00 07  bne  0xa00bbc90
a00bbc78:  80 a6 a0 07  cmp  %i2, 7
a00bbc7c:  b4 0e 60 ff  and  %i1, 0xff, %i2
a00bbc80:  80 a6 a0 06  cmp  %i2, 6
a00bbc84:  08 bf ff ef  bleu  0xa00bbc40
a00bbc88:  92 10 00 1a  mov  %i2, %o1
a00bbc8c:  80 a6 a0 07  cmp  %i2, 7
a00bbc90:  02 80 00 08  be  0xa00bbcb0
a00bbc94:  90 10 00 18  mov  %i0, %o0
a00bbc98:  a0 04 20 01  inc  %l0
a00bbc9c:  b0 0c 20 ff  and  %l0, 0xff, %i0
a00bbca0:  80 a6 20 82  cmp  %i0, 0x82
a00bbca4:  08 bf ff e5  bleu  0xa00bbc38
a00bbca8:  b2 10 20 02  mov  2, %i1
a00bbcac:  90 10 20 ff  mov  0xff, %o0
a00bbcb0:  96 0a 20 ff  and  %o0, 0xff, %o3
a00bbcb4:  80 a2 e0 82  cmp  %o3, 0x82
a00bbcb8:  38 80 00 28  bgu,a   0xa00bbd58
a00bbcbc:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00bbcc0:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00bbcc4:  c0 2b 60 9a  clrb  [ %o5 + 0x9a ]	! 0xa802b09a
a00bbcc8:  33 2a 00 b4  sethi  %hi(0xa802d000), %i1
a00bbccc:  9a 16 60 40  or  %i1, 0x40, %o5	! 0xa802d040
a00bbcd0:  98 10 20 00  clr  %o4
a00bbcd4:  82 10 20 00  clr  %g1
a00bbcd8:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbcdc:  98 03 20 01  inc  %o4
a00bbce0:  82 0b 20 ff  and  %o4, 0xff, %g1
a00bbce4:  80 a0 60 31  cmp  %g1, 0x31
a00bbce8:  28 bf ff fd  bleu,a   0xa00bbcdc
a00bbcec:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbcf0:  30 80 00 2a  b,a   0xa00bbd98
a00bbcf4:  7f ff ff 05  call  0xa00bb908
a00bbcf8:  90 10 20 02  mov  2, %o0
a00bbcfc:  92 0a 20 ff  and  %o0, 0xff, %o1
a00bbd00:  15 00 06 60  sethi  %hi(0x198000), %o2
a00bbd04:  40 00 8d 1b  call  0xa00df170
a00bbd08:  90 12 a2 98  or  %o2, 0x298, %o0	! 0x198298
a00bbd0c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bbd10:  35 2a 00 ac  sethi  %hi(0xa802b000), %i2
a00bbd14:  9a 10 60 40  or  %g1, 0x40, %o5
a00bbd18:  c0 2e a0 9a  clrb  [ %i2 + 0x9a ]
a00bbd1c:  98 10 20 00  clr  %o4
a00bbd20:  82 10 20 00  clr  %g1
a00bbd24:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbd28:  98 03 20 01  inc  %o4
a00bbd2c:  82 0b 20 ff  and  %o4, 0xff, %g1
a00bbd30:  80 a0 60 31  cmp  %g1, 0x31
a00bbd34:  28 bf ff fd  bleu,a   0xa00bbd28
a00bbd38:  c0 2b 40 01  clrb  [ %o5 + %g1 ]
a00bbd3c:  11 00 06 60  sethi  %hi(0x198000), %o0
a00bbd40:  92 10 20 00  clr  %o1
a00bbd44:  40 00 8d 0b  call  0xa00df170
a00bbd48:  90 12 22 b0  or  %o0, 0x2b0, %o0
a00bbd4c:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00bbd50:  10 80 00 12  b  0xa00bbd98
a00bbd54:  c0 2a 60 99  clrb  [ %o1 + 0x99 ]	! 0xa802b099
a00bbd58:  94 14 61 28  or  %l1, 0x128, %o2
a00bbd5c:  98 10 20 36  mov  0x36, %o4
a00bbd60:  9e 10 20 30  mov  0x30, %o7
a00bbd64:  b0 10 20 35  mov  0x35, %i0
a00bbd68:  a0 10 20 0d  mov  0xd, %l0
a00bbd6c:  f0 2c 61 28  stb  %i0, [ %l1 + 0x128 ]
a00bbd70:  de 2a a0 03  stb  %o7, [ %o2 + 3 ]
a00bbd74:  d8 2a a0 04  stb  %o4, [ %o2 + 4 ]
a00bbd78:  e0 2a a0 05  stb  %l0, [ %o2 + 5 ]
a00bbd7c:  d8 2a a0 01  stb  %o4, [ %o2 + 1 ]
a00bbd80:  de 2a a0 02  stb  %o7, [ %o2 + 2 ]
a00bbd84:  90 10 20 02  mov  2, %o0
a00bbd88:  40 02 32 98  call  0xa01487e8
a00bbd8c:  92 10 20 06  mov  6, %o1
a00bbd90:  10 bf ff cd  b  0xa00bbcc4
a00bbd94:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a00bbd98:  81 c7 e0 08  ret
a00bbd9c:  81 e8 00 00  restore
