# leon2m FUN_a0150b08 0xa0150b08-0xa0150b8c (132 bytes)
a0150b08:  9d e3 bf 78  save  %sp, -136, %sp
a0150b0c:  91 36 60 01  srl  %i1, 1, %o0
a0150b10:  82 0a 20 7f  and  %o0, 0x7f, %g1
a0150b14:  80 a6 20 01  cmp  %i0, 1
a0150b18:  02 80 00 13  be  0xa0150b64
a0150b1c:  9a 00 60 40  add  %g1, 0x40, %o5
a0150b20:  80 a6 20 01  cmp  %i0, 1
a0150b24:  1a 80 00 09  bcc  0xa0150b48
a0150b28:  80 a6 20 02  cmp  %i0, 2
a0150b2c:  15 00 20 00  sethi  %hi(0x800000), %o2
a0150b30:  92 12 a0 03  or  %o2, 3, %o1	! 0x800003
a0150b34:  d2 27 bf d8  st  %o1, [ %fp + -40 ]
a0150b38:  f2 2f bf dc  stb  %i1, [ %fp + -36 ]
a0150b3c:  da 2f bf dd  stb  %o5, [ %fp + -35 ]
a0150b40:  10 80 00 0e  b  0xa0150b78
a0150b44:  da 2f bf f3  stb  %o5, [ %fp + -13 ]
a0150b48:  12 80 00 0c  bne  0xa0150b78
a0150b4c:  19 00 00 e0  sethi  %hi(0x38000), %o4
a0150b50:  d8 27 bf d8  st  %o4, [ %fp + -40 ]
a0150b54:  f2 2f bf ec  stb  %i1, [ %fp + -20 ]
a0150b58:  da 2f bf ed  stb  %o5, [ %fp + -19 ]
a0150b5c:  10 80 00 07  b  0xa0150b78
a0150b60:  da 2f bf eb  stb  %o5, [ %fp + -21 ]
a0150b64:  96 10 23 80  mov  0x380, %o3
a0150b68:  d6 27 bf d8  st  %o3, [ %fp + -40 ]
a0150b6c:  f2 2f bf e4  stb  %i1, [ %fp + -28 ]
a0150b70:  da 2f bf e5  stb  %o5, [ %fp + -27 ]
a0150b74:  da 2f bf e3  stb  %o5, [ %fp + -29 ]
a0150b78:  7f fe 96 64  call  0xa00f6508
a0150b7c:  90 07 bf d8  add  %fp, -40, %o0
a0150b80:  01 00 00 00  nop
a0150b84:  81 c7 e0 08  ret
a0150b88:  81 e8 00 00  restore
