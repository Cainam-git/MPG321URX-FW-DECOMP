# leon2m FUN_a014faa8 0xa014faa8-0xa014fb84 (220 bytes)
a014faa8:  9d e3 bf 98  save  %sp, -104, %sp
a014faac:  03 2a 00 a9  sethi  %hi(0xa802a400), %g1
a014fab0:  d2 08 60 a8  ldub  [ %g1 + 0xa8 ], %o1	! 0xa802a4a8
a014fab4:  80 a2 60 ff  cmp  %o1, 0xff
a014fab8:  02 80 00 04  be  0xa014fac8
a014fabc:  b2 10 60 a8  or  %g1, 0xa8, %i1
a014fac0:  7f ff 3a 82  call  0xa011e4c8
a014fac4:  90 10 20 10  mov  0x10, %o0
a014fac8:  d2 0e 60 01  ldub  [ %i1 + 1 ], %o1
a014facc:  80 a2 60 ff  cmp  %o1, 0xff
a014fad0:  22 80 00 05  be,a   0xa014fae4
a014fad4:  d2 0e 60 02  ldub  [ %i1 + 2 ], %o1
a014fad8:  7f ff 3a 7c  call  0xa011e4c8
a014fadc:  90 10 20 11  mov  0x11, %o0
a014fae0:  d2 0e 60 02  ldub  [ %i1 + 2 ], %o1
a014fae4:  80 a2 60 ff  cmp  %o1, 0xff
a014fae8:  22 80 00 05  be,a   0xa014fafc
a014faec:  d2 0e 60 03  ldub  [ %i1 + 3 ], %o1
a014faf0:  7f ff 3a 76  call  0xa011e4c8
a014faf4:  90 10 20 12  mov  0x12, %o0
a014faf8:  d2 0e 60 03  ldub  [ %i1 + 3 ], %o1
a014fafc:  80 a2 60 ff  cmp  %o1, 0xff
a014fb00:  22 80 00 05  be,a   0xa014fb14
a014fb04:  d2 0e 60 04  ldub  [ %i1 + 4 ], %o1
a014fb08:  7f ff 3a 70  call  0xa011e4c8
a014fb0c:  90 10 20 13  mov  0x13, %o0
a014fb10:  d2 0e 60 04  ldub  [ %i1 + 4 ], %o1
a014fb14:  80 a2 60 ff  cmp  %o1, 0xff
a014fb18:  22 80 00 05  be,a   0xa014fb2c
a014fb1c:  d2 0e 60 05  ldub  [ %i1 + 5 ], %o1
a014fb20:  7f ff 3a 6a  call  0xa011e4c8
a014fb24:  90 10 20 14  mov  0x14, %o0
a014fb28:  d2 0e 60 05  ldub  [ %i1 + 5 ], %o1
a014fb2c:  80 a2 60 ff  cmp  %o1, 0xff
a014fb30:  22 80 00 05  be,a   0xa014fb44
a014fb34:  d2 0e 60 06  ldub  [ %i1 + 6 ], %o1
a014fb38:  7f ff 3a 64  call  0xa011e4c8
a014fb3c:  90 10 20 15  mov  0x15, %o0
a014fb40:  d2 0e 60 06  ldub  [ %i1 + 6 ], %o1
a014fb44:  80 a2 60 ff  cmp  %o1, 0xff
a014fb48:  22 80 00 05  be,a   0xa014fb5c
a014fb4c:  d2 0e 60 07  ldub  [ %i1 + 7 ], %o1
a014fb50:  7f ff 3a 5e  call  0xa011e4c8
a014fb54:  90 10 20 16  mov  0x16, %o0
a014fb58:  d2 0e 60 07  ldub  [ %i1 + 7 ], %o1
a014fb5c:  80 a2 60 ff  cmp  %o1, 0xff
a014fb60:  02 80 00 05  be  0xa014fb74
a014fb64:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a014fb68:  7f ff 3a 58  call  0xa011e4c8
a014fb6c:  90 10 20 17  mov  0x17, %o0
a014fb70:  11 2a 00 b3  sethi  %hi(0xa802cc00), %o0
a014fb74:  f2 0a 20 85  ldub  [ %o0 + 0x85 ], %i1	! 0xa802cc85
a014fb78:  7f ff 3a 54  call  0xa011e4c8
a014fb7c:  91 e8 20 18  restore  %g0, 0x18, %o0
a014fb80:  01 00 00 00  nop
