# leon2m FUN_a015d9e4 0xa015d9e4-0xa015ded4 (1264 bytes)
a015d9e4:  9d e3 bf 98  save  %sp, -104, %sp
a015d9e8:  a4 10 00 19  mov  %i1, %l2
a015d9ec:  b2 10 00 1a  mov  %i2, %i1
a015d9f0:  80 a4 a0 00  cmp  %l2, 0
a015d9f4:  02 80 00 aa  be  0xa015dc9c
a015d9f8:  aa 10 00 18  mov  %i0, %l5
a015d9fc:  7f ff fc 96  call  0xa015cc54
a015da00:  90 10 00 18  mov  %i0, %o0
a015da04:  a0 04 bf f8  add  %l2, -8, %l0
a015da08:  d2 04 20 04  ld  [ %l0 + 4 ], %o1
a015da0c:  82 06 a0 0b  add  %i2, 0xb, %g1
a015da10:  a2 0a 7f fc  and  %o1, -4, %l1
a015da14:  80 a0 60 16  cmp  %g1, 0x16
a015da18:  a6 10 00 10  mov  %l0, %l3
a015da1c:  94 10 00 11  mov  %l1, %o2
a015da20:  08 80 00 5f  bleu  0xa015db9c
a015da24:  b4 08 7f f8  and  %g1, -8, %i2
a015da28:  80 a6 80 19  cmp  %i2, %i1
a015da2c:  9a 40 20 00  addx  %g0, 0, %o5
a015da30:  83 36 a0 1f  srl  %i2, 0x1f, %g1
a015da34:  80 90 40 0d  orcc  %g1, %o5, %g0
a015da38:  12 80 01 25  bne  0xa015decc
a015da3c:  90 10 20 00  clr  %o0
a015da40:  80 a4 40 1a  cmp  %l1, %i2
a015da44:  16 80 00 88  bge  0xa015dc64
a015da48:  9a 24 40 1a  sub  %l1, %i2, %o5
a015da4c:  2d 2a 00 aa  sethi  %hi(0xa802a800), %l6
a015da50:  9e 15 a2 b8  or  %l6, 0x2b8, %o7	! 0xa802aab8
a015da54:  96 04 00 11  add  %l0, %l1, %o3
a015da58:  d0 03 e0 08  ld  [ %o7 + 8 ], %o0
a015da5c:  80 a2 00 0b  cmp  %o0, %o3
a015da60:  02 80 00 09  be  0xa015da84
a015da64:  d8 02 e0 04  ld  [ %o3 + 4 ], %o4
a015da68:  82 0b 3f fe  and  %o4, -2, %g1
a015da6c:  82 00 40 0b  add  %g1, %o3, %g1
a015da70:  da 00 60 04  ld  [ %g1 + 4 ], %o5
a015da74:  80 8b 60 01  btst  1, %o5
a015da78:  32 80 00 8b  bne,a   0xa015dca4
a015da7c:  96 10 20 00  clr  %o3
a015da80:  80 a2 00 0b  cmp  %o0, %o3
a015da84:  02 80 00 b0  be  0xa015dd44
a015da88:  98 0b 3f fc  and  %o4, -4, %o4
a015da8c:  82 03 00 11  add  %o4, %l1, %g1
a015da90:  80 a0 40 1a  cmp  %g1, %i2
a015da94:  36 80 00 a7  bge,a   0xa015dd30
a015da98:  d8 02 e0 08  ld  [ %o3 + 8 ], %o4
a015da9c:  80 8a 60 01  btst  1, %o1
a015daa0:  12 80 00 16  bne  0xa015daf8
a015daa4:  80 a2 e0 00  cmp  %o3, 0
a015daa8:  c2 04 00 00  ld  [ %l0 ], %g1
a015daac:  a8 24 00 01  sub  %l0, %g1, %l4
a015dab0:  da 05 20 04  ld  [ %l4 + 4 ], %o5
a015dab4:  02 80 00 0b  be  0xa015dae0
a015dab8:  92 0b 7f fc  and  %o5, -4, %o1
a015dabc:  82 15 a2 b8  or  %l6, 0x2b8, %g1
a015dac0:  da 00 60 08  ld  [ %g1 + 8 ], %o5
a015dac4:  80 a3 40 0b  cmp  %o5, %o3
a015dac8:  02 80 00 b5  be  0xa015dd9c
a015dacc:  82 03 00 09  add  %o4, %o1, %g1
a015dad0:  82 00 40 11  add  %g1, %l1, %g1
a015dad4:  80 a0 40 1a  cmp  %g1, %i2
a015dad8:  36 80 00 33  bge,a   0xa015dba4
a015dadc:  d8 02 e0 08  ld  [ %o3 + 8 ], %o4
a015dae0:  80 a5 20 00  cmp  %l4, 0
a015dae4:  02 80 00 05  be  0xa015daf8
a015dae8:  9a 02 40 11  add  %o1, %l1, %o5
a015daec:  80 a3 40 1a  cmp  %o5, %i2
a015daf0:  36 80 00 a4  bge,a   0xa015dd80
a015daf4:  d6 05 20 0c  ld  [ %l4 + 0xc ], %o3
a015daf8:  92 10 00 19  mov  %i1, %o1
a015dafc:  7f ff fa 18  call  0xa015c35c
a015db00:  90 10 00 15  mov  %l5, %o0
a015db04:  b0 92 20 00  orcc  %o0, 0, %i0
a015db08:  02 80 00 ee  be  0xa015dec0
a015db0c:  a0 06 3f f8  add  %i0, -8, %l0
a015db10:  c2 04 e0 04  ld  [ %l3 + 4 ], %g1
a015db14:  82 08 7f fe  and  %g1, -2, %g1
a015db18:  82 00 40 13  add  %g1, %l3, %g1
a015db1c:  80 a4 00 01  cmp  %l0, %g1
a015db20:  02 80 00 de  be  0xa015de98
a015db24:  94 04 7f fc  add  %l1, -4, %o2
a015db28:  80 a2 a0 24  cmp  %o2, 0x24
a015db2c:  18 80 00 7d  bgu  0xa015dd20
a015db30:  80 a2 a0 13  cmp  %o2, 0x13
a015db34:  9a 10 00 12  mov  %l2, %o5
a015db38:  08 80 00 0a  bleu  0xa015db60
a015db3c:  98 10 00 18  mov  %i0, %o4
a015db40:  c2 04 80 00  ld  [ %l2 ], %g1
a015db44:  c2 26 00 00  st  %g1, [ %i0 ]
a015db48:  da 04 a0 04  ld  [ %l2 + 4 ], %o5
a015db4c:  da 26 20 04  st  %o5, [ %i0 + 4 ]
a015db50:  80 a2 a0 1b  cmp  %o2, 0x1b
a015db54:  9a 04 a0 08  add  %l2, 8, %o5
a015db58:  18 80 00 63  bgu  0xa015dce4
a015db5c:  98 06 20 08  add  %i0, 8, %o4
a015db60:  c2 03 40 00  ld  [ %o5 ], %g1
a015db64:  c2 23 00 00  st  %g1, [ %o4 ]
a015db68:  9a 03 60 04  add  %o5, 4, %o5
a015db6c:  c2 03 40 00  ld  [ %o5 ], %g1
a015db70:  98 03 20 04  add  %o4, 4, %o4
a015db74:  c2 23 00 00  st  %g1, [ %o4 ]
a015db78:  da 03 60 04  ld  [ %o5 + 4 ], %o5
a015db7c:  da 23 20 04  st  %o5, [ %o4 + 4 ]
a015db80:  92 10 00 12  mov  %l2, %o1
a015db84:  7f ff f7 4f  call  0xa015b8c0
a015db88:  90 10 00 15  mov  %l5, %o0
a015db8c:  7f ff fc 38  call  0xa015cc6c
a015db90:  90 10 00 15  mov  %l5, %o0
a015db94:  10 80 00 ce  b  0xa015decc
a015db98:  90 10 00 18  mov  %i0, %o0
a015db9c:  10 bf ff a3  b  0xa015da28
a015dba0:  b4 10 20 10  mov  0x10, %i2
a015dba4:  d6 02 e0 0c  ld  [ %o3 + 0xc ], %o3
a015dba8:  d8 22 e0 08  st  %o4, [ %o3 + 8 ]
a015dbac:  d6 23 20 0c  st  %o3, [ %o4 + 0xc ]
a015dbb0:  d6 05 20 0c  ld  [ %l4 + 0xc ], %o3
a015dbb4:  d8 05 20 08  ld  [ %l4 + 8 ], %o4
a015dbb8:  a0 10 00 14  mov  %l4, %l0
a015dbbc:  94 02 bf fc  add  %o2, -4, %o2
a015dbc0:  d8 22 e0 08  st  %o4, [ %o3 + 8 ]
a015dbc4:  d6 23 20 0c  st  %o3, [ %o4 + 0xc ]
a015dbc8:  a2 10 00 01  mov  %g1, %l1
a015dbcc:  80 a2 a0 24  cmp  %o2, 0x24
a015dbd0:  18 80 00 ad  bgu  0xa015de84
a015dbd4:  b0 04 20 08  add  %l0, 8, %i0
a015dbd8:  90 10 00 18  mov  %i0, %o0
a015dbdc:  80 a2 a0 13  cmp  %o2, 0x13
a015dbe0:  08 80 00 18  bleu  0xa015dc40
a015dbe4:  9a 10 00 12  mov  %l2, %o5
a015dbe8:  c2 04 80 00  ld  [ %l2 ], %g1
a015dbec:  c2 24 20 08  st  %g1, [ %l0 + 8 ]
a015dbf0:  da 04 a0 04  ld  [ %l2 + 4 ], %o5
a015dbf4:  da 24 20 0c  st  %o5, [ %l0 + 0xc ]
a015dbf8:  80 a2 a0 1b  cmp  %o2, 0x1b
a015dbfc:  9a 04 a0 08  add  %l2, 8, %o5
a015dc00:  08 80 00 10  bleu  0xa015dc40
a015dc04:  90 04 20 10  add  %l0, 0x10, %o0
a015dc08:  c2 04 a0 08  ld  [ %l2 + 8 ], %g1
a015dc0c:  c2 24 20 10  st  %g1, [ %l0 + 0x10 ]
a015dc10:  da 04 a0 0c  ld  [ %l2 + 0xc ], %o5
a015dc14:  da 24 20 14  st  %o5, [ %l0 + 0x14 ]
a015dc18:  80 a2 a0 23  cmp  %o2, 0x23
a015dc1c:  9a 04 a0 10  add  %l2, 0x10, %o5
a015dc20:  08 80 00 08  bleu  0xa015dc40
a015dc24:  90 04 20 18  add  %l0, 0x18, %o0
a015dc28:  c2 04 a0 10  ld  [ %l2 + 0x10 ], %g1
a015dc2c:  c2 24 20 18  st  %g1, [ %l0 + 0x18 ]
a015dc30:  da 04 a0 14  ld  [ %l2 + 0x14 ], %o5
a015dc34:  da 24 20 1c  st  %o5, [ %l0 + 0x1c ]
a015dc38:  9a 04 a0 18  add  %l2, 0x18, %o5
a015dc3c:  90 04 20 20  add  %l0, 0x20, %o0
a015dc40:  c2 03 40 00  ld  [ %o5 ], %g1
a015dc44:  c2 22 00 00  st  %g1, [ %o0 ]
a015dc48:  9a 03 60 04  add  %o5, 4, %o5
a015dc4c:  c2 03 40 00  ld  [ %o5 ], %g1
a015dc50:  90 02 20 04  add  %o0, 4, %o0
a015dc54:  c2 22 00 00  st  %g1, [ %o0 ]
a015dc58:  da 03 60 04  ld  [ %o5 + 4 ], %o5
a015dc5c:  da 22 20 04  st  %o5, [ %o0 + 4 ]
a015dc60:  9a 24 40 1a  sub  %l1, %i2, %o5
a015dc64:  80 a3 60 0f  cmp  %o5, 0xf
a015dc68:  18 80 00 11  bgu  0xa015dcac
a015dc6c:  c2 04 20 04  ld  [ %l0 + 4 ], %g1
a015dc70:  82 08 60 01  and  %g1, 1, %g1
a015dc74:  82 10 40 11  or  %g1, %l1, %g1
a015dc78:  c2 24 20 04  st  %g1, [ %l0 + 4 ]
a015dc7c:  9a 04 00 11  add  %l0, %l1, %o5
a015dc80:  c2 03 60 04  ld  [ %o5 + 4 ], %g1
a015dc84:  82 10 60 01  or  %g1, 1, %g1
a015dc88:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a015dc8c:  7f ff fb f8  call  0xa015cc6c
a015dc90:  90 10 00 15  mov  %l5, %o0
a015dc94:  10 80 00 8e  b  0xa015decc
a015dc98:  90 04 20 08  add  %l0, 8, %o0
a015dc9c:  7f ff f9 b0  call  0xa015c35c
a015dca0:  81 e8 00 00  restore
a015dca4:  10 bf ff 7e  b  0xa015da9c
a015dca8:  98 10 20 00  clr  %o4
a015dcac:  82 08 60 01  and  %g1, 1, %g1
a015dcb0:  82 10 40 1a  or  %g1, %i2, %g1
a015dcb4:  c2 24 20 04  st  %g1, [ %l0 + 4 ]
a015dcb8:  92 04 00 1a  add  %l0, %i2, %o1
a015dcbc:  82 13 60 01  or  %o5, 1, %g1
a015dcc0:  9a 02 40 0d  add  %o1, %o5, %o5
a015dcc4:  c2 22 60 04  st  %g1, [ %o1 + 4 ]
a015dcc8:  c2 03 60 04  ld  [ %o5 + 4 ], %g1
a015dccc:  82 10 60 01  or  %g1, 1, %g1
a015dcd0:  c2 23 60 04  st  %g1, [ %o5 + 4 ]
a015dcd4:  92 02 60 08  add  %o1, 8, %o1
a015dcd8:  7f ff f6 fa  call  0xa015b8c0
a015dcdc:  90 10 00 15  mov  %l5, %o0
a015dce0:  30 bf ff eb  b,a   0xa015dc8c
a015dce4:  c2 04 a0 08  ld  [ %l2 + 8 ], %g1
a015dce8:  c2 26 20 08  st  %g1, [ %i0 + 8 ]
a015dcec:  da 04 a0 0c  ld  [ %l2 + 0xc ], %o5
a015dcf0:  da 26 20 0c  st  %o5, [ %i0 + 0xc ]
a015dcf4:  80 a2 a0 23  cmp  %o2, 0x23
a015dcf8:  9a 04 a0 10  add  %l2, 0x10, %o5
a015dcfc:  08 bf ff 99  bleu  0xa015db60
a015dd00:  98 06 20 10  add  %i0, 0x10, %o4
a015dd04:  c2 04 a0 10  ld  [ %l2 + 0x10 ], %g1
a015dd08:  c2 26 20 10  st  %g1, [ %i0 + 0x10 ]
a015dd0c:  da 04 a0 14  ld  [ %l2 + 0x14 ], %o5
a015dd10:  da 26 20 14  st  %o5, [ %i0 + 0x14 ]
a015dd14:  9a 04 a0 18  add  %l2, 0x18, %o5
a015dd18:  10 bf ff 92  b  0xa015db60
a015dd1c:  98 06 20 18  add  %i0, 0x18, %o4
a015dd20:  7f ff 7a fc  call  0xa013c910
a015dd24:  92 10 00 12  mov  %l2, %o1
a015dd28:  10 bf ff 97  b  0xa015db84
a015dd2c:  92 10 00 12  mov  %l2, %o1
a015dd30:  d6 02 e0 0c  ld  [ %o3 + 0xc ], %o3
a015dd34:  d8 22 e0 08  st  %o4, [ %o3 + 8 ]
a015dd38:  d6 23 20 0c  st  %o3, [ %o4 + 0xc ]
a015dd3c:  10 bf ff c9  b  0xa015dc60
a015dd40:  a2 10 00 01  mov  %g1, %l1
a015dd44:  9a 03 00 11  add  %o4, %l1, %o5
a015dd48:  82 06 a0 10  add  %i2, 0x10, %g1
a015dd4c:  80 a3 40 01  cmp  %o5, %g1
a015dd50:  06 bf ff 54  bl  0xa015daa0
a015dd54:  80 8a 60 01  btst  1, %o1
a015dd58:  82 23 40 1a  sub  %o5, %i2, %g1
a015dd5c:  98 04 00 1a  add  %l0, %i2, %o4
a015dd60:  82 10 60 01  or  %g1, 1, %g1
a015dd64:  c2 23 20 04  st  %g1, [ %o4 + 4 ]
a015dd68:  da 04 20 04  ld  [ %l0 + 4 ], %o5
a015dd6c:  9a 0b 60 01  and  %o5, 1, %o5
a015dd70:  92 13 40 1a  or  %o5, %i2, %o1
a015dd74:  d8 23 e0 08  st  %o4, [ %o7 + 8 ]
a015dd78:  10 bf ff c5  b  0xa015dc8c
a015dd7c:  d2 24 20 04  st  %o1, [ %l0 + 4 ]
a015dd80:  d8 05 20 08  ld  [ %l4 + 8 ], %o4
a015dd84:  a0 10 00 14  mov  %l4, %l0
a015dd88:  94 02 bf fc  add  %o2, -4, %o2
a015dd8c:  d8 22 e0 08  st  %o4, [ %o3 + 8 ]
a015dd90:  d6 23 20 0c  st  %o3, [ %o4 + 0xc ]
a015dd94:  10 bf ff 8e  b  0xa015dbcc
a015dd98:  a2 10 00 0d  mov  %o5, %l1
a015dd9c:  ae 00 40 11  add  %g1, %l1, %l7
a015dda0:  9a 06 a0 10  add  %i2, 0x10, %o5
a015dda4:  80 a5 c0 0d  cmp  %l7, %o5
a015dda8:  06 bf ff 4f  bl  0xa015dae4
a015ddac:  80 a5 20 00  cmp  %l4, 0
a015ddb0:  d6 05 20 0c  ld  [ %l4 + 0xc ], %o3
a015ddb4:  d8 05 20 08  ld  [ %l4 + 8 ], %o4
a015ddb8:  94 02 bf fc  add  %o2, -4, %o2
a015ddbc:  d8 22 e0 08  st  %o4, [ %o3 + 8 ]
a015ddc0:  d6 23 20 0c  st  %o3, [ %o4 + 0xc ]
a015ddc4:  80 a2 a0 24  cmp  %o2, 0x24
a015ddc8:  18 80 00 39  bgu  0xa015deac
a015ddcc:  b0 05 20 08  add  %l4, 8, %i0
a015ddd0:  80 a2 a0 13  cmp  %o2, 0x13
a015ddd4:  9a 10 00 12  mov  %l2, %o5
a015ddd8:  08 80 00 18  bleu  0xa015de38
a015dddc:  98 10 00 18  mov  %i0, %o4
a015dde0:  c2 04 80 00  ld  [ %l2 ], %g1
a015dde4:  c2 25 20 08  st  %g1, [ %l4 + 8 ]
a015dde8:  da 04 a0 04  ld  [ %l2 + 4 ], %o5
a015ddec:  da 25 20 0c  st  %o5, [ %l4 + 0xc ]
a015ddf0:  80 a2 a0 1b  cmp  %o2, 0x1b
a015ddf4:  9a 04 a0 08  add  %l2, 8, %o5
a015ddf8:  08 80 00 10  bleu  0xa015de38
a015ddfc:  98 05 20 10  add  %l4, 0x10, %o4
a015de00:  c2 04 a0 08  ld  [ %l2 + 8 ], %g1
a015de04:  c2 25 20 10  st  %g1, [ %l4 + 0x10 ]
a015de08:  da 04 a0 0c  ld  [ %l2 + 0xc ], %o5
a015de0c:  da 25 20 14  st  %o5, [ %l4 + 0x14 ]
a015de10:  80 a2 a0 23  cmp  %o2, 0x23
a015de14:  9a 04 a0 10  add  %l2, 0x10, %o5
a015de18:  08 80 00 08  bleu  0xa015de38
a015de1c:  98 05 20 18  add  %l4, 0x18, %o4
a015de20:  c2 04 a0 10  ld  [ %l2 + 0x10 ], %g1
a015de24:  c2 25 20 18  st  %g1, [ %l4 + 0x18 ]
a015de28:  da 04 a0 14  ld  [ %l2 + 0x14 ], %o5
a015de2c:  da 25 20 1c  st  %o5, [ %l4 + 0x1c ]
a015de30:  9a 04 a0 18  add  %l2, 0x18, %o5
a015de34:  98 05 20 20  add  %l4, 0x20, %o4
a015de38:  c2 03 40 00  ld  [ %o5 ], %g1
a015de3c:  c2 23 00 00  st  %g1, [ %o4 ]
a015de40:  9a 03 60 04  add  %o5, 4, %o5
a015de44:  c2 03 40 00  ld  [ %o5 ], %g1
a015de48:  98 03 20 04  add  %o4, 4, %o4
a015de4c:  c2 23 00 00  st  %g1, [ %o4 ]
a015de50:  da 03 60 04  ld  [ %o5 + 4 ], %o5
a015de54:  da 23 20 04  st  %o5, [ %o4 + 4 ]
a015de58:  9a 25 c0 1a  sub  %l7, %i2, %o5
a015de5c:  9a 13 60 01  or  %o5, 1, %o5
a015de60:  98 05 00 1a  add  %l4, %i2, %o4
a015de64:  da 23 20 04  st  %o5, [ %o4 + 4 ]
a015de68:  c2 05 20 04  ld  [ %l4 + 4 ], %g1
a015de6c:  82 08 60 01  and  %g1, 1, %g1
a015de70:  82 10 40 1a  or  %g1, %i2, %g1
a015de74:  9a 15 a2 b8  or  %l6, 0x2b8, %o5
a015de78:  c2 25 20 04  st  %g1, [ %l4 + 4 ]
a015de7c:  10 bf ff 44  b  0xa015db8c
a015de80:  d8 23 60 08  st  %o4, [ %o5 + 8 ]
a015de84:  90 10 00 18  mov  %i0, %o0
a015de88:  7f ff 7a a2  call  0xa013c910
a015de8c:  92 10 00 12  mov  %l2, %o1
a015de90:  10 bf ff 75  b  0xa015dc64
a015de94:  9a 24 40 1a  sub  %l1, %i2, %o5
a015de98:  c2 04 20 04  ld  [ %l0 + 4 ], %g1
a015de9c:  82 08 7f fc  and  %g1, -4, %g1
a015dea0:  a2 04 40 01  add  %l1, %g1, %l1
a015dea4:  10 bf ff 6f  b  0xa015dc60
a015dea8:  a0 10 00 13  mov  %l3, %l0
a015deac:  92 10 00 12  mov  %l2, %o1
a015deb0:  7f ff 7a 98  call  0xa013c910
a015deb4:  90 10 00 18  mov  %i0, %o0
a015deb8:  10 bf ff e9  b  0xa015de5c
a015debc:  9a 25 c0 1a  sub  %l7, %i2, %o5
a015dec0:  7f ff fb 6b  call  0xa015cc6c
a015dec4:  90 10 00 15  mov  %l5, %o0
a015dec8:  90 10 20 00  clr  %o0
a015decc:  81 c7 e0 08  ret
a015ded0:  91 e8 00 08  restore  %g0, %o0, %o0
