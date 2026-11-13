# leon2s FUN_a00daa98 0xa00daa98-0xa00dabf8 (352 bytes)
a00daa98:  9d e3 bf 80  save  %sp, -128, %sp
a00daa9c:  23 2a 01 e1  sethi  %hi(0xa8078400), %l1
a00daaa0:  d8 0c 63 fc  ldub  [ %l1 + 0x3fc ], %o4	! 0xa80787fc
a00daaa4:  82 0b 20 0f  and  %o4, 0xf, %g1
a00daaa8:  9a 00 40 01  add  %g1, %g1, %o5
a00daaac:  9a 03 40 01  add  %o5, %g1, %o5
a00daab0:  03 2a 01 e7  sethi  %hi(0xa8079c00), %g1
a00daab4:  13 2a 01 e7  sethi  %hi(0xa8079c00), %o1
a00daab8:  82 10 60 50  or  %g1, 0x50, %g1
a00daabc:  9b 2b 60 04  sll  %o5, 4, %o5
a00daac0:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00daac4:  92 12 60 98  or  %o1, 0x98, %o1
a00daac8:  e0 08 40 0c  ldub  [ %g1 + %o4 ], %l0
a00daacc:  92 03 40 09  add  %o5, %o1, %o1
a00daad0:  c0 2c e0 3b  clrb  [ %l3 + 0x3b ]
a00daad4:  7f ff ef 14  call  0xa00d6724
a00daad8:  90 07 bf e0  add  %fp, -32, %o0
a00daadc:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a00daae0:  83 30 60 08  srl  %g1, 8, %g1
a00daae4:  80 88 60 80  btst  0x80, %g1
a00daae8:  02 80 00 07  be  0xa00dab04
a00daaec:  b0 10 20 00  clr  %i0
a00daaf0:  7f ff ff be  call  0xa00da9e8
a00daaf4:  01 00 00 00  nop
a00daaf8:  80 8a 20 ff  btst  0xff, %o0
a00daafc:  32 80 00 02  bne,a   0xa00dab04
a00dab00:  b0 10 20 01  mov  1, %i0
a00dab04:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00dab08:  c2 0c a0 3c  ldub  [ %l2 + 0x3c ], %g1	! 0xa807883c
a00dab0c:  82 10 40 18  or  %g1, %i0, %g1
a00dab10:  80 88 60 ff  btst  0xff, %g1
a00dab14:  12 80 00 1c  bne  0xa00dab84
a00dab18:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a00dab1c:  7f ff fe e4  call  0xa00da6ac
a00dab20:  01 00 00 00  nop
a00dab24:  7f ff ff 45  call  0xa00da838
a00dab28:  01 00 00 00  nop
a00dab2c:  80 a4 20 00  cmp  %l0, 0
a00dab30:  1b 2a 01 d8  sethi  %hi(0xa8076000), %o5
a00dab34:  12 80 00 09  bne  0xa00dab58
a00dab38:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00dab3c:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1	! 0xa8078832
a00dab40:  83 28 60 02  sll  %g1, 2, %g1
a00dab44:  9a 13 60 a4  or  %o5, 0xa4, %o5
a00dab48:  da 03 40 01  ld  [ %o5 + %g1 ], %o5
a00dab4c:  c2 03 6c cc  ld  [ %o5 + 0xccc ], %g1
a00dab50:  10 80 00 08  b  0xa00dab70
a00dab54:  82 10 60 10  or  %g1, 0x10, %g1
a00dab58:  c2 0a e0 32  ldub  [ %o3 + 0x32 ], %g1
a00dab5c:  83 28 60 02  sll  %g1, 2, %g1
a00dab60:  9a 13 60 a4  or  %o5, 0xa4, %o5
a00dab64:  da 03 40 01  ld  [ %o5 + %g1 ], %o5
a00dab68:  c2 03 6c cc  ld  [ %o5 + 0xccc ], %g1
a00dab6c:  82 10 60 20  or  %g1, 0x20, %g1
a00dab70:  c2 23 6c cc  st  %g1, [ %o5 + 0xccc ]
a00dab74:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dab78:  40 3b 8d 92  call  0xa0fbe1c0
a00dab7c:  d0 08 60 32  ldub  [ %g1 + 0x32 ], %o0	! 0xa8078832
a00dab80:  c2 07 bf f0  ld  [ %fp + -16 ], %g1
a00dab84:  83 30 60 08  srl  %g1, 8, %g1
a00dab88:  80 88 60 40  btst  0x40, %g1
a00dab8c:  94 0e 20 ff  and  %i0, 0xff, %o2
a00dab90:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a00dab94:  02 80 00 09  be  0xa00dabb8
a00dab98:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dab9c:  82 10 60 38  or  %g1, 0x38, %g1	! 0xa8078838
a00daba0:  da 0a e0 32  ldub  [ %o3 + 0x32 ], %o5
a00daba4:  c0 28 40 0d  clrb  [ %g1 + %o5 ]
a00daba8:  82 10 20 01  mov  1, %g1
a00dabac:  c2 2c e0 3b  stb  %g1, [ %l3 + 0x3b ]
a00dabb0:  10 80 00 06  b  0xa00dabc8
a00dabb4:  c0 2c a0 3c  clrb  [ %l2 + 0x3c ]
a00dabb8:  98 10 60 38  or  %g1, 0x38, %o4
a00dabbc:  da 0a e0 32  ldub  [ %o3 + 0x32 ], %o5
a00dabc0:  82 10 20 04  mov  4, %g1
a00dabc4:  c2 2b 00 0d  stb  %g1, [ %o4 + %o5 ]
a00dabc8:  c2 0c 63 fc  ldub  [ %l1 + 0x3fc ], %g1
a00dabcc:  82 00 60 01  inc  %g1
a00dabd0:  82 08 60 0f  and  %g1, 0xf, %g1
a00dabd4:  c2 2c 63 fc  stb  %g1, [ %l1 + 0x3fc ]
a00dabd8:  80 a2 a0 00  cmp  %o2, 0
a00dabdc:  02 80 00 05  be  0xa00dabf0
a00dabe0:  b0 10 20 01  mov  1, %i0
a00dabe4:  7f ff ff 5f  call  0xa00da960
a00dabe8:  90 10 20 00  clr  %o0
a00dabec:  b0 10 20 00  clr  %i0
a00dabf0:  81 c7 e0 08  ret
a00dabf4:  81 e8 00 00  restore
