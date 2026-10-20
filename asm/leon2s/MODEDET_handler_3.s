# leon2s MODEDET_handler_3 0xa009dd40-0xa009dfa8 (616 bytes)
a009dd40:  9d e3 bf 98  save  %sp, -104, %sp
a009dd44:  a0 0e 20 ff  and  %i0, 0xff, %l0
a009dd48:  a8 10 00 18  mov  %i0, %l4
a009dd4c:  80 a4 20 01  cmp  %l0, 1
a009dd50:  12 80 00 03  bne  0xa009dd5c
a009dd54:  a4 10 20 02  mov  2, %l2
a009dd58:  a4 10 20 03  mov  3, %l2
a009dd5c:  2b 2a 01 f6  sethi  %hi(0xa807d800), %l5
a009dd60:  a6 15 63 00  or  %l5, 0x300, %l3	! 0xa807db00
a009dd64:  a2 5c 20 34  smul  %l0, 0x34, %l1
a009dd68:  d2 04 c0 11  ld  [ %l3 + %l1 ], %o1
a009dd6c:  92 02 60 b4  add  %o1, 0xb4, %o1
a009dd70:  40 00 25 8f  call  0xa00a73ac
a009dd74:  90 10 20 02  mov  2, %o0
a009dd78:  82 04 00 10  add  %l0, %l0, %g1
a009dd7c:  82 00 40 10  add  %g1, %l0, %g1
a009dd80:  2f 2a 01 f5  sethi  %hi(0xa807d400), %l7
a009dd84:  99 28 60 03  sll  %g1, 3, %o4
a009dd88:  92 15 e2 50  or  %l7, 0x250, %o1
a009dd8c:  9a 03 00 09  add  %o4, %o1, %o5
a009dd90:  d4 0b 60 04  ldub  [ %o5 + 4 ], %o2
a009dd94:  80 a2 a0 00  cmp  %o2, 0
a009dd98:  02 80 00 6f  be  0xa009df54
a009dd9c:  17 2a 01 e1  sethi  %hi(0xa8078400), %o3
a009dda0:  c2 02 e2 34  ld  [ %o3 + 0x234 ], %g1	! 0xa8078634
a009dda4:  94 02 bf ff  add  %o2, -1, %o2
a009dda8:  ac 10 00 0b  mov  %o3, %l6
a009ddac:  80 88 60 04  btst  4, %g1
a009ddb0:  02 80 00 09  be  0xa009ddd4
a009ddb4:  d4 2b 60 04  stb  %o2, [ %o5 + 4 ]
a009ddb8:  92 06 20 41  add  %i0, 0x41, %o1
a009ddbc:  93 2a 60 18  sll  %o1, 0x18, %o1
a009ddc0:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009ddc4:  90 12 23 20  or  %o0, 0x320, %o0	! 0xa006ab20
a009ddc8:  93 3a 60 18  sra  %o1, 0x18, %o1
a009ddcc:  7f ff 54 9e  call  0xa0073044
a009ddd0:  94 0a a0 ff  and  %o2, 0xff, %o2
a009ddd4:  40 00 09 7d  call  0xa00a03c8
a009ddd8:  90 10 00 10  mov  %l0, %o0
a009dddc:  90 0a 20 ff  and  %o0, 0xff, %o0
a009dde0:  80 a2 20 01  cmp  %o0, 1
a009dde4:  02 80 00 06  be  0xa009ddfc
a009dde8:  92 10 20 04  mov  4, %o1
a009ddec:  c2 04 c0 11  ld  [ %l3 + %l1 ], %g1
a009ddf0:  c2 00 60 44  ld  [ %g1 + 0x44 ], %g1
a009ddf4:  83 30 60 08  srl  %g1, 8, %g1
a009ddf8:  92 08 60 0f  and  %g1, 0xf, %o1
a009ddfc:  7f ff fe a0  call  0xa009d87c
a009de00:  90 10 00 10  mov  %l0, %o0
a009de04:  23 2a 01 f5  sethi  %hi(0xa807d400), %l1
a009de08:  9a 5c 21 90  smul  %l0, 0x190, %o5
a009de0c:  82 14 63 e0  or  %l1, 0x3e0, %g1
a009de10:  b0 03 40 01  add  %o5, %g1, %i0
a009de14:  40 00 09 6d  call  0xa00a03c8
a009de18:  90 10 00 10  mov  %l0, %o0
a009de1c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009de20:  80 a2 20 01  cmp  %o0, 1
a009de24:  02 80 00 08  be  0xa009de44
a009de28:  9a 10 20 04  mov  4, %o5
a009de2c:  9a 15 63 00  or  %l5, 0x300, %o5
a009de30:  82 5c 20 34  smul  %l0, 0x34, %g1
a009de34:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a009de38:  c2 00 60 44  ld  [ %g1 + 0x44 ], %g1
a009de3c:  83 30 60 08  srl  %g1, 8, %g1
a009de40:  9a 08 60 0f  and  %g1, 0xf, %o5
a009de44:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009de48:  da 2e 20 2c  stb  %o5, [ %i0 + 0x2c ]
a009de4c:  a6 10 63 00  or  %g1, 0x300, %l3
a009de50:  a4 5c 20 34  smul  %l0, 0x34, %l2
a009de54:  9a 14 63 e0  or  %l1, 0x3e0, %o5
a009de58:  d4 04 c0 12  ld  [ %l3 + %l2 ], %o2
a009de5c:  82 5c 21 90  smul  %l0, 0x190, %g1
a009de60:  b0 00 40 0d  add  %g1, %o5, %i0
a009de64:  d8 02 a0 50  ld  [ %o2 + 0x50 ], %o4
a009de68:  da 16 20 20  lduh  [ %i0 + 0x20 ], %o5
a009de6c:  c2 02 a0 50  ld  [ %o2 + 0x50 ], %g1
a009de70:  83 28 60 10  sll  %g1, 0x10, %g1
a009de74:  9b 2b 60 10  sll  %o5, 0x10, %o5
a009de78:  9b 33 60 10  srl  %o5, 0x10, %o5
a009de7c:  83 30 60 10  srl  %g1, 0x10, %g1
a009de80:  82 20 40 0d  sub  %g1, %o5, %g1
a009de84:  9b 38 60 1f  sra  %g1, 0x1f, %o5
a009de88:  82 1b 40 01  xor  %o5, %g1, %g1
a009de8c:  82 20 40 0d  sub  %g1, %o5, %g1
a009de90:  80 a0 60 01  cmp  %g1, 1
a009de94:  14 80 00 42  bg  0xa009df9c
a009de98:  d8 36 20 20  sth  %o4, [ %i0 + 0x20 ]
a009de9c:  82 04 00 10  add  %l0, %l0, %g1
a009dea0:  82 00 40 10  add  %g1, %l0, %g1
a009dea4:  93 28 60 03  sll  %g1, 3, %o1
a009dea8:  90 15 e2 50  or  %l7, 0x250, %o0
a009deac:  98 02 40 08  add  %o1, %o0, %o4
a009deb0:  c2 0b 20 04  ldub  [ %o4 + 4 ], %g1
a009deb4:  80 a0 60 02  cmp  %g1, 2
a009deb8:  08 80 00 0b  bleu  0xa009dee4
a009debc:  da 05 a2 34  ld  [ %l6 + 0x234 ], %o5
a009dec0:  82 10 20 03  mov  3, %g1
a009dec4:  80 8b 60 04  btst  4, %o5
a009dec8:  02 80 00 35  be  0xa009df9c
a009decc:  c2 2b 20 04  stb  %g1, [ %o4 + 4 ]
a009ded0:  92 05 20 41  add  %l4, 0x41, %o1
a009ded4:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009ded8:  93 2a 60 18  sll  %o1, 0x18, %o1
a009dedc:  10 80 00 2e  b  0xa009df94
a009dee0:  90 12 23 58  or  %o0, 0x358, %o0
a009dee4:  c0 2b 20 05  clrb  [ %o4 + 5 ]
a009dee8:  da 02 a0 38  ld  [ %o2 + 0x38 ], %o5
a009deec:  d6 02 a0 3c  ld  [ %o2 + 0x3c ], %o3
a009def0:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a009def4:  d8 02 a0 4c  ld  [ %o2 + 0x4c ], %o4
a009def8:  82 10 60 a8  or  %g1, 0xa8, %g1
a009defc:  c2 08 40 10  ldub  [ %g1 + %l0 ], %g1
a009df00:  9b 33 60 10  srl  %o5, 0x10, %o5
a009df04:  99 33 20 10  srl  %o4, 0x10, %o4
a009df08:  99 2b 00 01  sll  %o4, %g1, %o4
a009df0c:  9b 2b 40 01  sll  %o5, %g1, %o5
a009df10:  82 10 20 05  mov  5, %g1
a009df14:  c2 22 00 09  st  %g1, [ %o0 + %o1 ]
a009df18:  da 36 20 1a  sth  %o5, [ %i0 + 0x1a ]
a009df1c:  d6 36 20 1c  sth  %o3, [ %i0 + 0x1c ]
a009df20:  d8 36 20 1e  sth  %o4, [ %i0 + 0x1e ]
a009df24:  40 00 07 dd  call  0xa009fe98
a009df28:  90 10 00 10  mov  %l0, %o0
a009df2c:  7f ff e5 38  call  0xa009740c
a009df30:  90 10 00 10  mov  %l0, %o0
a009df34:  82 04 80 13  add  %l2, %l3, %g1
a009df38:  d2 00 60 20  ld  [ %g1 + 0x20 ], %o1
a009df3c:  c0 2e 20 06  clrb  [ %i0 + 6 ]
a009df40:  92 02 60 38  add  %o1, 0x38, %o1
a009df44:  40 00 25 1a  call  0xa00a73ac
a009df48:  90 10 20 18  mov  0x18, %o0
a009df4c:  10 80 00 15  b  0xa009dfa0
a009df50:  b0 10 20 01  mov  1, %i0
a009df54:  82 0c a0 ff  and  %l2, 0xff, %g1
a009df58:  9a 00 40 01  add  %g1, %g1, %o5
a009df5c:  9a 03 40 01  add  %o5, %g1, %o5
a009df60:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a009df64:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a009df68:  9b 2b 60 03  sll  %o5, 3, %o5
a009df6c:  9a 03 40 01  add  %o5, %g1, %o5
a009df70:  c2 02 e2 34  ld  [ %o3 + 0x234 ], %g1
a009df74:  c0 22 40 0c  clr  [ %o1 + %o4 ]
a009df78:  80 88 60 04  btst  4, %g1
a009df7c:  02 80 00 08  be  0xa009df9c
a009df80:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a009df84:  92 06 20 41  add  %i0, 0x41, %o1
a009df88:  11 28 01 aa  sethi  %hi(0xa006a800), %o0
a009df8c:  93 2a 60 18  sll  %o1, 0x18, %o1
a009df90:  90 12 23 88  or  %o0, 0x388, %o0
a009df94:  7f ff 54 2c  call  0xa0073044
a009df98:  93 3a 60 18  sra  %o1, 0x18, %o1
a009df9c:  b0 10 20 00  clr  %i0
a009dfa0:  81 c7 e0 08  ret
a009dfa4:  81 e8 00 00  restore
