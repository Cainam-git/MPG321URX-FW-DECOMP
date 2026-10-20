# leon2m FUN_a002ef0c 0xa002ef0c-0xa002efd4 (200 bytes)
a002ef0c:  9d e3 bf 98  save  %sp, -104, %sp
a002ef10:  92 10 20 54  mov  0x54, %o1
a002ef14:  58 01 8c d0  call  0x92254
a002ef18:  90 10 20 00  clr  %o0
a002ef1c:  1b 33 c0 46  sethi  %hi(0xcf011800), %o5
a002ef20:  80 8a 20 03  btst  3, %o0
a002ef24:  12 80 00 06  bne  0xa002ef3c
a002ef28:  82 13 62 a0  or  %o5, 0x2a0, %g1
a002ef2c:  c2 00 40 00  ld  [ %g1 ], %g1
a002ef30:  80 88 60 0f  btst  0xf, %g1
a002ef34:  02 80 00 0d  be  0xa002ef68
a002ef38:  98 13 62 a4  or  %o5, 0x2a4, %o4
a002ef3c:  19 33 c0 1a  sethi  %hi(0xcf006800), %o4
a002ef40:  9e 13 23 30  or  %o4, 0x330, %o7	! 0xcf006b30
a002ef44:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a002ef48:  c0 23 c0 00  clr  [ %o7 ]
a002ef4c:  96 13 23 34  or  %o4, 0x334, %o3
a002ef50:  da 03 61 e0  ld  [ %o5 + 0x1e0 ], %o5
a002ef54:  c0 22 c0 00  clr  [ %o3 ]
a002ef58:  80 a3 60 00  cmp  %o5, 0
a002ef5c:  02 80 00 16  be  0xa002efb4
a002ef60:  90 10 20 00  clr  %o0
a002ef64:  30 80 00 11  b,a   0xa002efa8
a002ef68:  d0 03 00 00  ld  [ %o4 ], %o0
a002ef6c:  80 8a 20 80  btst  0x80, %o0
a002ef70:  12 bf ff f3  bne  0xa002ef3c
a002ef74:  96 13 62 a8  or  %o5, 0x2a8, %o3
a002ef78:  d2 02 c0 00  ld  [ %o3 ], %o1
a002ef7c:  80 8a 60 80  btst  0x80, %o1
a002ef80:  12 bf ff ef  bne  0xa002ef3c
a002ef84:  9a 13 62 ac  or  %o5, 0x2ac, %o5
a002ef88:  d4 03 40 00  ld  [ %o5 ], %o2
a002ef8c:  80 8a a0 80  btst  0x80, %o2
a002ef90:  32 bf ff ec  bne,a   0xa002ef40
a002ef94:  19 33 c0 1a  sethi  %hi(0xcf006800), %o4
a002ef98:  58 02 fd f0  call  0xee758
a002ef9c:  01 00 00 00  nop
a002efa0:  10 bf ff e8  b  0xa002ef40
a002efa4:  19 33 c0 1a  sethi  %hi(0xcf006800), %o4
a002efa8:  9f c3 40 00  call  %o5
a002efac:  01 00 00 00  nop
a002efb0:  90 10 20 00  clr  %o0	! 0x0
a002efb4:  7f ff fd 04  call  0xa002e3c4
a002efb8:  92 10 20 01  mov  1, %o1
a002efbc:  11 2a 00 b2  sethi  %hi(0xa802c800), %o0
a002efc0:  d2 02 21 e4  ld  [ %o0 + 0x1e4 ], %o1	! 0xa802c9e4
a002efc4:  82 12 60 01  or  %o1, 1, %g1
a002efc8:  c2 22 21 e4  st  %g1, [ %o0 + 0x1e4 ]
a002efcc:  81 c7 e0 08  ret
a002efd0:  81 e8 00 00  restore
