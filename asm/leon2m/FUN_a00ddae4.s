# leon2m FUN_a00ddae4 0xa00ddae4-0xa00ddbe0 (48 bytes)
a00ddae4:  82 0a 20 ff  and  %o0, 0xff, %g1
a00ddae8:  80 a0 60 0a  cmp  %g1, 0xa
a00ddaec:  18 80 00 3b  bgu  0xa00ddbd8
a00ddaf0:  90 10 3f ff  mov  -1, %o0
a00ddaf4:  11 00 01 f6  sethi  %hi(0x7d800), %o0
a00ddaf8:  83 28 60 02  sll  %g1, 2, %g1
a00ddafc:  9a 12 20 b4  or  %o0, 0xb4, %o5
a00ddb00:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a00ddb04:  81 c3 00 00  jmp  %o4
a00ddb08:  01 00 00 00  nop
a00ddb0c:  10 80 00 33  b  0xa00ddbd8
a00ddb10:  90 10 3f ff  mov  -1, %o0	! 0xffffffff
a00ddb14:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a00ddb18:  82 10 63 58  or  %g1, 0x358, %g1	! 0xcf03cf58
a00ddb1c:  da 00 40 00  ld  [ %g1 ], %o5
a00ddb20:  10 80 00 2e  b  0xa00ddbd8
a00ddb24:  90 10 00 0d  mov  %o5, %o0
a00ddb28:  19 33 c0 f3  sethi  %hi(0xcf03cc00), %o4
a00ddb2c:  82 13 23 54  or  %o4, 0x354, %g1	! 0xcf03cf54
a00ddb30:  da 00 40 00  ld  [ %g1 ], %o5
a00ddb34:  10 80 00 29  b  0xa00ddbd8
a00ddb38:  90 10 00 0d  mov  %o5, %o0
a00ddb3c:  11 33 c0 f3  sethi  %hi(0xcf03cc00), %o0
a00ddb40:  82 12 23 30  or  %o0, 0x330, %g1	! 0xcf03cf30
a00ddb44:  da 00 40 00  ld  [ %g1 ], %o5
a00ddb48:  10 80 00 24  b  0xa00ddbd8
a00ddb4c:  90 10 00 0d  mov  %o5, %o0
a00ddb50:  1b 33 c0 f3  sethi  %hi(0xcf03cc00), %o5
a00ddb54:  82 13 63 2c  or  %o5, 0x32c, %g1	! 0xcf03cf2c
a00ddb58:  da 00 40 00  ld  [ %g1 ], %o5
a00ddb5c:  10 80 00 1f  b  0xa00ddbd8
a00ddb60:  90 10 00 0d  mov  %o5, %o0
a00ddb64:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a00ddb68:  82 10 63 28  or  %g1, 0x328, %g1	! 0xcf03cf28
a00ddb6c:  da 00 40 00  ld  [ %g1 ], %o5
a00ddb70:  10 80 00 1a  b  0xa00ddbd8
a00ddb74:  90 10 00 0d  mov  %o5, %o0
a00ddb78:  19 33 c0 f3  sethi  %hi(0xcf03cc00), %o4
a00ddb7c:  82 13 23 24  or  %o4, 0x324, %g1	! 0xcf03cf24
a00ddb80:  da 00 40 00  ld  [ %g1 ], %o5
a00ddb84:  10 80 00 15  b  0xa00ddbd8
a00ddb88:  90 10 00 0d  mov  %o5, %o0
a00ddb8c:  11 33 c0 f3  sethi  %hi(0xcf03cc00), %o0
a00ddb90:  82 12 23 20  or  %o0, 0x320, %g1	! 0xcf03cf20
a00ddb94:  da 00 40 00  ld  [ %g1 ], %o5
a00ddb98:  10 80 00 10  b  0xa00ddbd8
a00ddb9c:  90 10 00 0d  mov  %o5, %o0
a00ddba0:  1b 33 c0 f3  sethi  %hi(0xcf03cc00), %o5
a00ddba4:  82 13 63 1c  or  %o5, 0x31c, %g1	! 0xcf03cf1c
a00ddba8:  da 00 40 00  ld  [ %g1 ], %o5
a00ddbac:  10 80 00 0b  b  0xa00ddbd8
a00ddbb0:  90 10 00 0d  mov  %o5, %o0
a00ddbb4:  03 33 c0 f3  sethi  %hi(0xcf03cc00), %g1
a00ddbb8:  82 10 63 18  or  %g1, 0x318, %g1	! 0xcf03cf18
a00ddbbc:  da 00 40 00  ld  [ %g1 ], %o5
a00ddbc0:  10 80 00 06  b  0xa00ddbd8
a00ddbc4:  90 10 00 0d  mov  %o5, %o0
a00ddbc8:  19 33 c0 f3  sethi  %hi(0xcf03cc00), %o4
a00ddbcc:  82 13 23 14  or  %o4, 0x314, %g1	! 0xcf03cf14
a00ddbd0:  da 00 40 00  ld  [ %g1 ], %o5
a00ddbd4:  90 10 00 0d  mov  %o5, %o0
a00ddbd8:  81 c3 e0 08  retl
a00ddbdc:  90 0a 20 ff  and  %o0, 0xff, %o0
