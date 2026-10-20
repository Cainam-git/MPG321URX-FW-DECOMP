# leon2s FUN_a008ced8 0xa008ced8-0xa008d0b8 (480 bytes)
a008ced8:  9d e3 bf 98  save  %sp, -104, %sp
a008cedc:  03 33 c0 49  sethi  %hi(0xcf012400), %g1
a008cee0:  82 10 60 48  or  %g1, 0x48, %g1	! 0xcf012448
a008cee4:  c0 20 40 00  clr  [ %g1 ]
a008cee8:  40 00 02 46  call  0xa008d800
a008ceec:  01 00 00 00  nop
a008cef0:  90 0a 20 ff  and  %o0, 0xff, %o0
a008cef4:  80 a2 20 81  cmp  %o0, 0x81
a008cef8:  18 80 00 03  bgu  0xa008cf04
a008cefc:  9a 10 20 50  mov  0x50, %o5
a008cf00:  9a 10 20 03  mov  3, %o5
a008cf04:  03 33 c0 51  sethi  %hi(0xcf014400), %g1
a008cf08:  82 10 63 60  or  %g1, 0x360, %g1	! 0xcf014760
a008cf0c:  da 20 40 00  st  %o5, [ %g1 ]
a008cf10:  90 10 20 00  clr  %o0
a008cf14:  92 10 20 40  mov  0x40, %o1
a008cf18:  40 00 93 7a  call  0xa00b1d00
a008cf1c:  94 10 20 50  mov  0x50, %o2
a008cf20:  90 10 20 01  mov  1, %o0
a008cf24:  92 10 20 40  mov  0x40, %o1
a008cf28:  40 00 93 76  call  0xa00b1d00
a008cf2c:  94 10 20 50  mov  0x50, %o2
a008cf30:  90 10 20 02  mov  2, %o0
a008cf34:  92 10 20 40  mov  0x40, %o1
a008cf38:  40 00 93 72  call  0xa00b1d00
a008cf3c:  94 10 20 20  mov  0x20, %o2
a008cf40:  25 33 c0 51  sethi  %hi(0xcf014400), %l2
a008cf44:  90 10 20 03  mov  3, %o0
a008cf48:  92 10 20 40  mov  0x40, %o1
a008cf4c:  40 00 93 6d  call  0xa00b1d00
a008cf50:  94 10 20 20  mov  0x20, %o2
a008cf54:  a0 14 a3 54  or  %l2, 0x354, %l0
a008cf58:  c2 04 00 00  ld  [ %l0 ], %g1
a008cf5c:  82 10 60 10  or  %g1, 0x10, %g1
a008cf60:  c2 24 00 00  st  %g1, [ %l0 ]
a008cf64:  90 10 20 05  mov  5, %o0
a008cf68:  92 10 20 40  mov  0x40, %o1
a008cf6c:  40 00 93 65  call  0xa00b1d00
a008cf70:  94 10 20 40  mov  0x40, %o2
a008cf74:  c2 04 00 00  ld  [ %l0 ], %g1
a008cf78:  82 10 60 20  or  %g1, 0x20, %g1
a008cf7c:  92 10 20 40  mov  0x40, %o1
a008cf80:  c2 24 00 00  st  %g1, [ %l0 ]
a008cf84:  94 10 20 40  mov  0x40, %o2
a008cf88:  40 00 93 5e  call  0xa00b1d00
a008cf8c:  90 10 20 07  mov  7, %o0
a008cf90:  82 14 a3 c0  or  %l2, 0x3c0, %g1
a008cf94:  c0 20 40 00  clr  [ %g1 ]
a008cf98:  82 14 a3 c4  or  %l2, 0x3c4, %g1
a008cf9c:  c0 20 40 00  clr  [ %g1 ]
a008cfa0:  82 14 a3 c8  or  %l2, 0x3c8, %g1
a008cfa4:  c0 20 40 00  clr  [ %g1 ]
a008cfa8:  9a 14 a3 cc  or  %l2, 0x3cc, %o5
a008cfac:  82 10 20 0c  mov  0xc, %g1
a008cfb0:  c2 23 40 00  st  %g1, [ %o5 ]
a008cfb4:  9a 14 a3 88  or  %l2, 0x388, %o5
a008cfb8:  82 10 20 f1  mov  0xf1, %g1
a008cfbc:  c2 23 40 00  st  %g1, [ %o5 ]
a008cfc0:  82 10 20 f0  mov  0xf0, %g1
a008cfc4:  c2 23 40 00  st  %g1, [ %o5 ]
a008cfc8:  9a 14 a3 90  or  %l2, 0x390, %o5
a008cfcc:  82 10 20 01  mov  1, %g1
a008cfd0:  c2 23 40 00  st  %g1, [ %o5 ]
a008cfd4:  c0 23 40 00  clr  [ %o5 ]
a008cfd8:  40 00 91 ef  call  0xa00b1794
a008cfdc:  90 10 20 01  mov  1, %o0
a008cfe0:  94 10 20 22  mov  0x22, %o2
a008cfe4:  82 14 a2 c0  or  %l2, 0x2c0, %g1
a008cfe8:  d4 20 40 00  st  %o2, [ %g1 ]
a008cfec:  96 10 20 08  mov  8, %o3
a008cff0:  a2 14 a2 c4  or  %l2, 0x2c4, %l1
a008cff4:  d6 24 40 00  st  %o3, [ %l1 ]
a008cff8:  9a 10 20 80  mov  0x80, %o5
a008cffc:  82 14 a2 fc  or  %l2, 0x2fc, %g1
a008d000:  da 20 40 00  st  %o5, [ %g1 ]
a008d004:  98 10 20 81  mov  0x81, %o4
a008d008:  d8 20 40 00  st  %o4, [ %g1 ]
a008d00c:  da 20 40 00  st  %o5, [ %g1 ]
a008d010:  82 14 a3 00  or  %l2, 0x300, %g1
a008d014:  d4 20 40 00  st  %o2, [ %g1 ]
a008d018:  a0 14 a3 04  or  %l2, 0x304, %l0
a008d01c:  d6 24 00 00  st  %o3, [ %l0 ]
a008d020:  82 14 a3 3c  or  %l2, 0x33c, %g1
a008d024:  da 20 40 00  st  %o5, [ %g1 ]
a008d028:  d8 20 40 00  st  %o4, [ %g1 ]
a008d02c:  da 20 40 00  st  %o5, [ %g1 ]
a008d030:  40 00 91 d9  call  0xa00b1794
a008d034:  90 10 20 01  mov  1, %o0
a008d038:  c0 24 40 00  clr  [ %l1 ]
a008d03c:  c0 24 00 00  clr  [ %l0 ]
a008d040:  40 00 01 f0  call  0xa008d800
a008d044:  01 00 00 00  nop
a008d048:  90 0a 20 ff  and  %o0, 0xff, %o0
a008d04c:  80 a2 20 81  cmp  %o0, 0x81
a008d050:  08 80 00 0f  bleu  0xa008d08c
a008d054:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a008d058:  9a 14 a3 74  or  %l2, 0x374, %o5
a008d05c:  82 10 20 02  mov  2, %g1
a008d060:  90 10 20 04  mov  4, %o0
a008d064:  92 10 20 80  mov  0x80, %o1
a008d068:  94 10 20 80  mov  0x80, %o2
a008d06c:  c2 23 40 00  st  %g1, [ %o5 ]
a008d070:  40 00 93 24  call  0xa00b1d00
a008d074:  01 00 00 00  nop
a008d078:  90 10 20 06  mov  6, %o0	! 0x6
a008d07c:  92 10 20 80  mov  0x80, %o1
a008d080:  40 00 93 20  call  0xa00b1d00
a008d084:  94 10 20 80  mov  0x80, %o2
a008d088:  1b 33 c0 49  sethi  %hi(0xcf012400), %o5
a008d08c:  98 13 60 9c  or  %o5, 0x9c, %o4	! 0xcf01249c
a008d090:  82 10 20 20  mov  0x20, %g1
a008d094:  c2 23 00 00  st  %g1, [ %o4 ]
a008d098:  82 13 60 98  or  %o5, 0x98, %g1
a008d09c:  c0 20 40 00  clr  [ %g1 ]
a008d0a0:  82 13 60 94  or  %o5, 0x94, %g1
a008d0a4:  c0 20 40 00  clr  [ %g1 ]
a008d0a8:  9a 13 60 90  or  %o5, 0x90, %o5
a008d0ac:  c0 23 40 00  clr  [ %o5 ]
a008d0b0:  81 c7 e0 08  ret
a008d0b4:  81 e8 00 00  restore
