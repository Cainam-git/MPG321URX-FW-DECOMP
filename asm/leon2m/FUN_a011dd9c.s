# leon2m FUN_a011dd9c 0xa011dd9c-0xa011e028 (44 bytes)
a011dd9c:  82 0a 20 ff  and  %o0, 0xff, %g1
a011dda0:  80 a0 60 1a  cmp  %g1, 0x1a
a011dda4:  18 80 00 9f  bgu  0xa011e020
a011dda8:  11 00 02 f4  sethi  %hi(0xbd000), %o0
a011ddac:  83 28 60 02  sll  %g1, 2, %g1
a011ddb0:  9a 12 23 84  or  %o0, 0x384, %o5
a011ddb4:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a011ddb8:  81 c3 00 00  jmp  %o4
a011ddbc:  01 00 00 00  nop
a011ddc0:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011ddc4:  96 13 61 30  or  %o5, 0x130, %o3	! 0xcf016130
a011ddc8:  82 0a 60 03  and  %o1, 3, %g1
a011ddcc:  99 2a 60 10  sll  %o1, 0x10, %o4
a011ddd0:  c2 22 c0 00  st  %g1, [ %o3 ]
a011ddd4:  9a 13 61 2c  or  %o5, 0x12c, %o5
a011ddd8:  93 33 20 12  srl  %o4, 0x12, %o1
a011dddc:  d2 23 40 00  st  %o1, [ %o5 ]
a011dde0:  30 80 00 90  b,a   0xa011e020
a011dde4:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011dde8:  96 13 60 cc  or  %o5, 0xcc, %o3	! 0xcf0164cc
a011ddec:  90 0a 60 03  and  %o1, 3, %o0
a011ddf0:  99 2a 60 10  sll  %o1, 0x10, %o4
a011ddf4:  d0 22 c0 00  st  %o0, [ %o3 ]
a011ddf8:  9a 13 60 d0  or  %o5, 0xd0, %o5
a011ddfc:  93 33 20 12  srl  %o4, 0x12, %o1
a011de00:  d2 23 40 00  st  %o1, [ %o5 ]
a011de04:  30 80 00 87  b,a   0xa011e020
a011de08:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011de0c:  90 13 60 a0  or  %o5, 0xa0, %o0	! 0xcf0164a0
a011de10:  82 0a 60 03  and  %o1, 3, %g1
a011de14:  99 2a 60 10  sll  %o1, 0x10, %o4
a011de18:  c2 22 00 00  st  %g1, [ %o0 ]
a011de1c:  9a 13 60 a4  or  %o5, 0xa4, %o5
a011de20:  93 33 20 12  srl  %o4, 0x12, %o1
a011de24:  d2 23 40 00  st  %o1, [ %o5 ]
a011de28:  30 80 00 7e  b,a   0xa011e020
a011de2c:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011de30:  96 13 60 74  or  %o5, 0x74, %o3	! 0xcf016474
a011de34:  82 0a 60 03  and  %o1, 3, %g1
a011de38:  99 2a 60 10  sll  %o1, 0x10, %o4
a011de3c:  c2 22 c0 00  st  %g1, [ %o3 ]
a011de40:  9a 13 60 78  or  %o5, 0x78, %o5
a011de44:  93 33 20 12  srl  %o4, 0x12, %o1
a011de48:  d2 23 40 00  st  %o1, [ %o5 ]
a011de4c:  30 80 00 75  b,a   0xa011e020
a011de50:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011de54:  96 13 60 48  or  %o5, 0x48, %o3	! 0xcf016448
a011de58:  90 0a 60 03  and  %o1, 3, %o0
a011de5c:  99 2a 60 10  sll  %o1, 0x10, %o4
a011de60:  d0 22 c0 00  st  %o0, [ %o3 ]
a011de64:  9a 13 60 4c  or  %o5, 0x4c, %o5
a011de68:  93 33 20 12  srl  %o4, 0x12, %o1
a011de6c:  d2 23 40 00  st  %o1, [ %o5 ]
a011de70:  30 80 00 6c  b,a   0xa011e020
a011de74:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011de78:  90 13 60 40  or  %o5, 0x40, %o0	! 0xcf016440
a011de7c:  82 0a 60 03  and  %o1, 3, %g1
a011de80:  99 2a 60 10  sll  %o1, 0x10, %o4
a011de84:  c2 22 00 00  st  %g1, [ %o0 ]
a011de88:  9a 13 60 44  or  %o5, 0x44, %o5
a011de8c:  93 33 20 12  srl  %o4, 0x12, %o1
a011de90:  d2 23 40 00  st  %o1, [ %o5 ]
a011de94:  30 80 00 63  b,a   0xa011e020
a011de98:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011de9c:  90 13 60 38  or  %o5, 0x38, %o0	! 0xcf016438
a011dea0:  96 0a 60 03  and  %o1, 3, %o3
a011dea4:  99 2a 60 10  sll  %o1, 0x10, %o4
a011dea8:  d6 22 00 00  st  %o3, [ %o0 ]
a011deac:  9a 13 60 3c  or  %o5, 0x3c, %o5
a011deb0:  93 33 20 12  srl  %o4, 0x12, %o1
a011deb4:  d2 23 40 00  st  %o1, [ %o5 ]
a011deb8:  30 80 00 5a  b,a   0xa011e020
a011debc:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011dec0:  82 0a 60 03  and  %o1, 3, %g1
a011dec4:  99 2a 60 10  sll  %o1, 0x10, %o4
a011dec8:  96 12 20 30  or  %o0, 0x30, %o3
a011decc:  c2 22 c0 00  st  %g1, [ %o3 ]
a011ded0:  9a 12 20 34  or  %o0, 0x34, %o5
a011ded4:  93 33 20 12  srl  %o4, 0x12, %o1
a011ded8:  d2 23 40 00  st  %o1, [ %o5 ]
a011dedc:  30 80 00 51  b,a   0xa011e020
a011dee0:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011dee4:  9a 0a 60 03  and  %o1, 3, %o5
a011dee8:  96 12 20 28  or  %o0, 0x28, %o3
a011deec:  da 22 c0 00  st  %o5, [ %o3 ]
a011def0:  99 2a 60 10  sll  %o1, 0x10, %o4
a011def4:  9a 12 20 2c  or  %o0, 0x2c, %o5
a011def8:  93 33 20 12  srl  %o4, 0x12, %o1
a011defc:  d2 23 40 00  st  %o1, [ %o5 ]
a011df00:  30 80 00 48  b,a   0xa011e020
a011df04:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011df08:  9a 12 20 20  or  %o0, 0x20, %o5	! 0xcf016420
a011df0c:  82 0a 60 03  and  %o1, 3, %g1
a011df10:  c2 23 40 00  st  %g1, [ %o5 ]
a011df14:  99 2a 60 10  sll  %o1, 0x10, %o4
a011df18:  9a 12 20 24  or  %o0, 0x24, %o5
a011df1c:  93 33 20 12  srl  %o4, 0x12, %o1
a011df20:  d2 23 40 00  st  %o1, [ %o5 ]
a011df24:  30 80 00 3f  b,a   0xa011e020
a011df28:  11 33 c0 59  sethi  %hi(0xcf016400), %o0
a011df2c:  9a 12 20 18  or  %o0, 0x18, %o5	! 0xcf016418
a011df30:  96 0a 60 03  and  %o1, 3, %o3
a011df34:  d6 23 40 00  st  %o3, [ %o5 ]
a011df38:  99 2a 60 10  sll  %o1, 0x10, %o4
a011df3c:  9a 12 20 1c  or  %o0, 0x1c, %o5
a011df40:  93 33 20 12  srl  %o4, 0x12, %o1
a011df44:  d2 23 40 00  st  %o1, [ %o5 ]
a011df48:  30 80 00 36  b,a   0xa011e020
a011df4c:  1b 33 c0 59  sethi  %hi(0xcf016400), %o5
a011df50:  96 13 60 10  or  %o5, 0x10, %o3	! 0xcf016410
a011df54:  82 0a 60 03  and  %o1, 3, %g1
a011df58:  99 2a 60 10  sll  %o1, 0x10, %o4
a011df5c:  c2 22 c0 00  st  %g1, [ %o3 ]
a011df60:  9a 13 60 14  or  %o5, 0x14, %o5
a011df64:  93 33 20 12  srl  %o4, 0x12, %o1
a011df68:  d2 23 40 00  st  %o1, [ %o5 ]
a011df6c:  30 80 00 2d  b,a   0xa011e020
a011df70:  1b 33 c0 58  sethi  %hi(0xcf016000), %o5
a011df74:  90 13 61 a8  or  %o5, 0x1a8, %o0	! 0xcf0161a8
a011df78:  96 0a 60 03  and  %o1, 3, %o3
a011df7c:  99 2a 60 10  sll  %o1, 0x10, %o4
a011df80:  d6 22 00 00  st  %o3, [ %o0 ]
a011df84:  9a 13 61 a4  or  %o5, 0x1a4, %o5
a011df88:  93 33 20 12  srl  %o4, 0x12, %o1
a011df8c:  d2 23 40 00  st  %o1, [ %o5 ]
a011df90:  30 80 00 24  b,a   0xa011e020
a011df94:  11 33 c0 58  sethi  %hi(0xcf016000), %o0
a011df98:  82 0a 60 03  and  %o1, 3, %g1
a011df9c:  99 2a 60 10  sll  %o1, 0x10, %o4
a011dfa0:  96 12 21 90  or  %o0, 0x190, %o3
a011dfa4:  c2 22 c0 00  st  %g1, [ %o3 ]
a011dfa8:  9a 12 21 8c  or  %o0, 0x18c, %o5
a011dfac:  93 33 20 12  srl  %o4, 0x12, %o1
a011dfb0:  d2 23 40 00  st  %o1, [ %o5 ]
a011dfb4:  30 80 00 1b  b,a   0xa011e020
a011dfb8:  11 33 c0 58  sethi  %hi(0xcf016000), %o0
a011dfbc:  9a 0a 60 03  and  %o1, 3, %o5
a011dfc0:  96 12 21 78  or  %o0, 0x178, %o3
a011dfc4:  da 22 c0 00  st  %o5, [ %o3 ]
a011dfc8:  99 2a 60 10  sll  %o1, 0x10, %o4
a011dfcc:  9a 12 21 74  or  %o0, 0x174, %o5
a011dfd0:  93 33 20 12  srl  %o4, 0x12, %o1
a011dfd4:  d2 23 40 00  st  %o1, [ %o5 ]
a011dfd8:  30 80 00 12  b,a   0xa011e020
a011dfdc:  11 33 c0 58  sethi  %hi(0xcf016000), %o0
a011dfe0:  9a 12 21 60  or  %o0, 0x160, %o5	! 0xcf016160
a011dfe4:  82 0a 60 03  and  %o1, 3, %g1
a011dfe8:  c2 23 40 00  st  %g1, [ %o5 ]
a011dfec:  99 2a 60 10  sll  %o1, 0x10, %o4
a011dff0:  9a 12 21 5c  or  %o0, 0x15c, %o5
a011dff4:  93 33 20 12  srl  %o4, 0x12, %o1
a011dff8:  d2 23 40 00  st  %o1, [ %o5 ]
a011dffc:  30 80 00 09  b,a   0xa011e020
a011e000:  11 33 c0 58  sethi  %hi(0xcf016000), %o0
a011e004:  9a 12 21 48  or  %o0, 0x148, %o5	! 0xcf016148
a011e008:  96 0a 60 03  and  %o1, 3, %o3
a011e00c:  d6 23 40 00  st  %o3, [ %o5 ]
a011e010:  99 2a 60 10  sll  %o1, 0x10, %o4
a011e014:  9a 12 21 44  or  %o0, 0x144, %o5
a011e018:  93 33 20 12  srl  %o4, 0x12, %o1
a011e01c:  d2 23 40 00  st  %o1, [ %o5 ]
a011e020:  81 c3 e0 08  retl
a011e024:  01 00 00 00  nop
