# leon2s FUN_a00add8c 0xa00add8c-0xa00adf64 (472 bytes)
a00add8c:  9d e3 bf 98  save  %sp, -104, %sp
a00add90:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00add94:  7f c4 62 24  call  0x9f1c6624
a00add98:  90 10 00 18  mov  %i0, %o0
a00add9c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00adda0:  7f ff ff ea  call  0xa00add48
a00adda4:  90 10 00 18  mov  %i0, %o0
a00adda8:  a0 10 00 08  mov  %o0, %l0
a00addac:  7f c4 62 1e  call  0x9f1c6624
a00addb0:  90 10 00 18  mov  %i0, %o0
a00addb4:  b1 2e 20 02  sll  %i0, 2, %i0
a00addb8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00addbc:  b0 06 00 08  add  %i0, %o0, %i0
a00addc0:  80 a0 60 03  cmp  %g1, 3
a00addc4:  18 80 00 21  bgu  0xa00ade48
a00addc8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00addcc:  80 a6 60 01  cmp  %i1, 1
a00addd0:  12 80 00 05  bne  0xa00adde4
a00addd4:  15 33 c0 51  sethi  %hi(0xcf014400), %o2
a00addd8:  94 12 a3 58  or  %o2, 0x358, %o2	! 0xcf014758
a00adddc:  10 80 00 21  b  0xa00ade60
a00adde0:  82 00 40 01  add  %g1, %g1, %g1
a00adde4:  94 12 a3 58  or  %o2, 0x358, %o2
a00adde8:  80 a6 60 02  cmp  %i1, 2
a00addec:  02 80 00 2d  be  0xa00adea0
a00addf0:  98 00 40 01  add  %g1, %g1, %o4
a00addf4:  80 a6 60 04  cmp  %i1, 4
a00addf8:  96 00 40 01  add  %g1, %g1, %o3
a00addfc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ade00:  12 80 00 05  bne  0xa00ade14
a00ade04:  13 2a 01 f7  sethi  %hi(0xa807dc00), %o1
a00ade08:  15 33 c0 51  sethi  %hi(0xcf014400), %o2
a00ade0c:  10 80 00 3a  b  0xa00adef4
a00ade10:  94 12 a3 58  or  %o2, 0x358, %o2	! 0xcf014758
a00ade14:  19 33 c0 51  sethi  %hi(0xcf014400), %o4
a00ade18:  9a 10 20 03  mov  3, %o5
a00ade1c:  98 13 23 58  or  %o4, 0x358, %o4
a00ade20:  9b 2b 40 0b  sll  %o5, %o3, %o5
a00ade24:  d6 03 00 00  ld  [ %o4 ], %o3
a00ade28:  82 10 20 01  mov  1, %g1
a00ade2c:  d4 0a 62 70  ldub  [ %o1 + 0x270 ], %o2
a00ade30:  83 28 40 18  sll  %g1, %i0, %g1
a00ade34:  9a 2a c0 0d  andn  %o3, %o5, %o5
a00ade38:  82 2a 80 01  andn  %o2, %g1, %g1
a00ade3c:  da 23 00 00  st  %o5, [ %o4 ]
a00ade40:  10 80 00 47  b  0xa00adf5c
a00ade44:  c2 2a 62 70  stb  %g1, [ %o1 + 0x270 ]
a00ade48:  80 a6 60 01  cmp  %i1, 1
a00ade4c:  12 80 00 0e  bne  0xa00ade84
a00ade50:  a0 04 3f fc  add  %l0, -4, %l0
a00ade54:  15 33 c0 51  sethi  %hi(0xcf014400), %o2
a00ade58:  94 12 a3 5c  or  %o2, 0x35c, %o2	! 0xcf01475c
a00ade5c:  82 04 00 10  add  %l0, %l0, %g1
a00ade60:  9a 10 20 03  mov  3, %o5
a00ade64:  9b 2b 40 01  sll  %o5, %g1, %o5
a00ade68:  13 2a 01 f7  sethi  %hi(0xa807dc00), %o1
a00ade6c:  99 2e 40 18  sll  %i1, %i0, %o4
a00ade70:  c2 02 80 00  ld  [ %o2 ], %g1
a00ade74:  d6 0a 62 70  ldub  [ %o1 + 0x270 ], %o3
a00ade78:  82 10 40 0d  or  %g1, %o5, %g1
a00ade7c:  10 80 00 28  b  0xa00adf1c
a00ade80:  98 13 00 0b  or  %o4, %o3, %o4
a00ade84:  80 a6 60 02  cmp  %i1, 2
a00ade88:  12 80 00 14  bne  0xa00aded8
a00ade8c:  80 a6 60 04  cmp  %i1, 4
a00ade90:  98 0c 20 ff  and  %l0, 0xff, %o4
a00ade94:  15 33 c0 51  sethi  %hi(0xcf014400), %o2
a00ade98:  94 12 a3 5c  or  %o2, 0x35c, %o2	! 0xcf01475c
a00ade9c:  98 03 00 0c  add  %o4, %o4, %o4
a00adea0:  82 10 20 03  mov  3, %g1
a00adea4:  da 02 80 00  ld  [ %o2 ], %o5
a00adea8:  83 28 40 0c  sll  %g1, %o4, %g1
a00adeac:  82 2b 40 01  andn  %o5, %g1, %g1
a00adeb0:  13 2a 01 f7  sethi  %hi(0xa807dc00), %o1
a00adeb4:  99 2e 40 0c  sll  %i1, %o4, %o4
a00adeb8:  9a 10 20 01  mov  1, %o5
a00adebc:  d6 0a 62 70  ldub  [ %o1 + 0x270 ], %o3
a00adec0:  9b 2b 40 18  sll  %o5, %i0, %o5
a00adec4:  82 10 40 0c  or  %g1, %o4, %g1
a00adec8:  9a 2a c0 0d  andn  %o3, %o5, %o5
a00adecc:  c2 22 80 00  st  %g1, [ %o2 ]
a00aded0:  10 80 00 23  b  0xa00adf5c
a00aded4:  da 2a 62 70  stb  %o5, [ %o1 + 0x270 ]
a00aded8:  82 0c 20 ff  and  %l0, 0xff, %g1
a00adedc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00adee0:  12 80 00 12  bne  0xa00adf28
a00adee4:  13 2a 01 f7  sethi  %hi(0xa807dc00), %o1
a00adee8:  15 33 c0 51  sethi  %hi(0xcf014400), %o2
a00adeec:  94 12 a3 5c  or  %o2, 0x35c, %o2	! 0xcf01475c
a00adef0:  96 00 40 01  add  %g1, %g1, %o3
a00adef4:  82 10 20 03  mov  3, %g1
a00adef8:  83 28 40 0b  sll  %g1, %o3, %g1
a00adefc:  d8 02 80 00  ld  [ %o2 ], %o4
a00adf00:  9a 10 20 01  mov  1, %o5
a00adf04:  82 2b 00 01  andn  %o4, %g1, %g1
a00adf08:  99 2b 40 18  sll  %o5, %i0, %o4
a00adf0c:  9b 2b 40 0b  sll  %o5, %o3, %o5
a00adf10:  d6 0a 62 70  ldub  [ %o1 + 0x270 ], %o3
a00adf14:  82 10 40 0d  or  %g1, %o5, %g1
a00adf18:  98 2a c0 0c  andn  %o3, %o4, %o4
a00adf1c:  c2 22 80 00  st  %g1, [ %o2 ]
a00adf20:  10 80 00 0f  b  0xa00adf5c
a00adf24:  d8 2a 62 70  stb  %o4, [ %o1 + 0x270 ]
a00adf28:  82 00 40 01  add  %g1, %g1, %g1
a00adf2c:  15 33 c0 51  sethi  %hi(0xcf014400), %o2
a00adf30:  9a 10 20 03  mov  3, %o5
a00adf34:  94 12 a3 5c  or  %o2, 0x35c, %o2
a00adf38:  9b 2b 40 01  sll  %o5, %g1, %o5
a00adf3c:  d8 02 80 00  ld  [ %o2 ], %o4
a00adf40:  82 10 20 01  mov  1, %g1
a00adf44:  d6 0a 62 70  ldub  [ %o1 + 0x270 ], %o3
a00adf48:  83 28 40 18  sll  %g1, %i0, %g1
a00adf4c:  9a 2b 00 0d  andn  %o4, %o5, %o5
a00adf50:  82 2a c0 01  andn  %o3, %g1, %g1
a00adf54:  da 22 80 00  st  %o5, [ %o2 ]
a00adf58:  c2 2a 62 70  stb  %g1, [ %o1 + 0x270 ]
a00adf5c:  81 c7 e0 08  ret
a00adf60:  81 e8 00 00  restore
