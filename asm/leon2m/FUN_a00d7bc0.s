# leon2m FUN_a00d7bc0 0xa00d7bc0-0xa00d7d48 (392 bytes)
a00d7bc0:  9d e3 bf 98  save  %sp, -104, %sp
a00d7bc4:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a00d7bc8:  98 14 62 90  or  %l1, 0x290, %o4	! 0xa802d290
a00d7bcc:  da 03 20 ac  ld  [ %o4 + 0xac ], %o5
a00d7bd0:  03 00 03 00  sethi  %hi(0xc0000), %g1
a00d7bd4:  80 8b 40 01  btst  %o5, %g1
a00d7bd8:  12 80 00 18  bne  0xa00d7c38
a00d7bdc:  f0 0b 20 44  ldub  [ %o4 + 0x44 ], %i0
a00d7be0:  9a 14 62 90  or  %l1, 0x290, %o5
a00d7be4:  d4 0b 60 11  ldub  [ %o5 + 0x11 ], %o2
a00d7be8:  80 a2 a0 01  cmp  %o2, 1
a00d7bec:  22 80 00 24  be,a   0xa00d7c7c
a00d7bf0:  c2 0b 61 81  ldub  [ %o5 + 0x181 ], %g1
a00d7bf4:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d7bf8:  80 a0 60 07  cmp  %g1, 7
a00d7bfc:  38 80 00 02  bgu,a   0xa00d7c04
a00d7c00:  82 10 20 07  mov  7, %g1
a00d7c04:  80 a0 60 05  cmp  %g1, 5
a00d7c08:  18 80 00 09  bgu  0xa00d7c2c
a00d7c0c:  b0 10 20 00  clr  %i0
a00d7c10:  1b 00 01 ce  sethi  %hi(0x73800), %o5
a00d7c14:  a1 28 60 02  sll  %g1, 2, %l0
a00d7c18:  98 13 62 c0  or  %o5, 0x2c0, %o4
a00d7c1c:  de 03 00 10  ld  [ %o4 + %l0 ], %o7
a00d7c20:  81 c3 c0 00  jmp  %o7
a00d7c24:  01 00 00 00  nop
a00d7c28:  b0 10 20 19  mov  0x19, %i0	! 0x19
a00d7c2c:  b0 0e 20 1b  and  %i0, 0x1b, %i0
a00d7c30:  40 01 d2 d9  call  0xa014c794
a00d7c34:  81 e8 00 00  restore
a00d7c38:  40 01 cf 8c  call  0xa014ba68
a00d7c3c:  a0 10 20 00  clr  %l0
a00d7c40:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d7c44:  80 a2 20 02  cmp  %o0, 2
a00d7c48:  22 80 00 02  be,a   0xa00d7c50
a00d7c4c:  a0 10 20 01  mov  1, %l0
a00d7c50:  40 01 d0 48  call  0xa014bd70
a00d7c54:  90 10 20 00  clr  %o0
a00d7c58:  92 0a 20 ff  and  %o0, 0xff, %o1
a00d7c5c:  80 a2 60 01  cmp  %o1, 1
a00d7c60:  22 80 00 02  be,a   0xa00d7c68
a00d7c64:  a0 10 20 01  mov  1, %l0
a00d7c68:  80 8c 20 ff  btst  0xff, %l0
a00d7c6c:  22 bf ff de  be,a   0xa00d7be4
a00d7c70:  9a 14 62 90  or  %l1, 0x290, %o5
a00d7c74:  10 bf ff e0  b  0xa00d7bf4
a00d7c78:  b0 10 20 01  mov  1, %i0
a00d7c7c:  80 a0 60 04  cmp  %g1, 4
a00d7c80:  28 bf ff de  bleu,a   0xa00d7bf8
a00d7c84:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d7c88:  80 a0 60 06  cmp  %g1, 6
a00d7c8c:  18 bf ff db  bgu  0xa00d7bf8
a00d7c90:  82 0e 20 ff  and  %i0, 0xff, %g1
a00d7c94:  d6 03 60 a8  ld  [ %o5 + 0xa8 ], %o3
a00d7c98:  80 8a e8 00  btst  0x800, %o3
a00d7c9c:  32 bf ff d6  bne,a   0xa00d7bf4
a00d7ca0:  b0 10 20 03  mov  3, %i0
a00d7ca4:  10 bf ff d6  b  0xa00d7bfc
a00d7ca8:  80 a0 60 07  cmp  %g1, 7
a00d7cac:  82 14 62 90  or  %l1, 0x290, %g1
a00d7cb0:  d0 00 60 ac  ld  [ %g1 + 0xac ], %o0
a00d7cb4:  31 00 03 00  sethi  %hi(0xc0000), %i0
a00d7cb8:  80 8a 00 18  btst  %o0, %i0
a00d7cbc:  12 80 00 12  bne  0xa00d7d04
a00d7cc0:  98 14 62 90  or  %l1, 0x290, %o4
a00d7cc4:  e2 03 20 a8  ld  [ %o4 + 0xa8 ], %l1
a00d7cc8:  80 8c 68 00  btst  0x800, %l1
a00d7ccc:  22 80 00 07  be,a   0xa00d7ce8
a00d7cd0:  b0 10 20 13  mov  0x13, %i0
a00d7cd4:  d6 0b 21 81  ldub  [ %o4 + 0x181 ], %o3
a00d7cd8:  80 a2 e0 04  cmp  %o3, 4
a00d7cdc:  02 bf ff d4  be  0xa00d7c2c
a00d7ce0:  b0 10 20 18  mov  0x18, %i0
a00d7ce4:  b0 10 20 13  mov  0x13, %i0
a00d7ce8:  b0 0e 20 1b  and  %i0, 0x1b, %i0
a00d7cec:  40 01 d2 aa  call  0xa014c794
a00d7cf0:  81 e8 00 00  restore
a00d7cf4:  10 bf ff ce  b  0xa00d7c2c
a00d7cf8:  b0 10 20 11  mov  0x11, %i0
a00d7cfc:  10 bf ff cc  b  0xa00d7c2c
a00d7d00:  b0 10 20 18  mov  0x18, %i0
a00d7d04:  40 01 cf 59  call  0xa014ba68
a00d7d08:  a0 10 20 00  clr  %l0
a00d7d0c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00d7d10:  80 a2 60 02  cmp  %o1, 2
a00d7d14:  22 80 00 02  be,a   0xa00d7d1c
a00d7d18:  a0 10 20 01  mov  1, %l0
a00d7d1c:  40 01 d0 15  call  0xa014bd70
a00d7d20:  90 10 20 00  clr  %o0
a00d7d24:  94 0a 20 ff  and  %o0, 0xff, %o2
a00d7d28:  80 a2 a0 01  cmp  %o2, 1
a00d7d2c:  22 80 00 02  be,a   0xa00d7d34
a00d7d30:  a0 10 20 01  mov  1, %l0
a00d7d34:  80 8c 20 ff  btst  0xff, %l0
a00d7d38:  12 bf ff bd  bne  0xa00d7c2c
a00d7d3c:  b0 10 20 1a  mov  0x1a, %i0
a00d7d40:  10 bf ff e1  b  0xa00d7cc4
a00d7d44:  98 14 62 90  or  %l1, 0x290, %o4
