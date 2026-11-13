# leon2s FUN_a00dac08 0xa00dac08-0xa00dae90 (648 bytes)
a00dac08:  9d e3 bf 98  save  %sp, -104, %sp
a00dac0c:  2b 2a 01 e2  sethi  %hi(0xa8078800), %l5
a00dac10:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dac14:  d8 0d 60 32  ldub  [ %l5 + 0x32 ], %o4
a00dac18:  82 10 60 08  or  %g1, 8, %g1
a00dac1c:  da 08 40 0c  ldub  [ %g1 + %o4 ], %o5
a00dac20:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dac24:  82 10 60 00  mov  %g1, %g1	! 0xa8078800
a00dac28:  c2 08 40 0c  ldub  [ %g1 + %o4 ], %g1
a00dac2c:  9a 1b 40 01  xor  %o5, %g1, %o5
a00dac30:  80 a0 00 0d  cmp  %g0, %o5
a00dac34:  82 40 20 00  addx  %g0, 0, %g1
a00dac38:  80 a3 20 00  cmp  %o4, 0
a00dac3c:  a4 10 00 01  mov  %g1, %l2
a00dac40:  12 80 00 09  bne  0xa00dac64
a00dac44:  a8 10 20 00  clr  %l4
a00dac48:  7f ff fc 42  call  0xa00d9d50
a00dac4c:  01 00 00 00  nop
a00dac50:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dac54:  90 1a 20 ff  xor  %o0, 0xff, %o0
a00dac58:  80 a0 00 08  cmp  %g0, %o0
a00dac5c:  82 40 20 00  addx  %g0, 0, %g1
a00dac60:  a8 10 00 01  mov  %g1, %l4
a00dac64:  da 0d 60 32  ldub  [ %l5 + 0x32 ], %o5
a00dac68:  03 2a 01 d8  sethi  %hi(0xa8076000), %g1
a00dac6c:  9b 2b 60 02  sll  %o5, 2, %o5
a00dac70:  82 10 60 9c  or  %g1, 0x9c, %g1
a00dac74:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a00dac78:  da 00 62 58  ld  [ %g1 + 0x258 ], %o5
a00dac7c:  82 14 80 14  or  %l2, %l4, %g1
a00dac80:  80 88 60 ff  btst  0xff, %g1
a00dac84:  12 80 00 06  bne  0xa00dac9c
a00dac88:  27 2a 01 e2  sethi  %hi(0xa8078800), %l3
a00dac8c:  80 8b 60 18  btst  0x18, %o5
a00dac90:  02 80 00 7e  be  0xa00dae88
a00dac94:  01 00 00 00  nop
a00dac98:  30 80 00 4c  b,a   0xa00dadc8
a00dac9c:  80 8b 60 18  btst  0x18, %o5
a00daca0:  12 80 00 4a  bne  0xa00dadc8
a00daca4:  01 00 00 00  nop
a00daca8:  7f ff fc 67  call  0xa00d9e44
a00dacac:  01 00 00 00  nop
a00dacb0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dacb4:  80 a2 20 02  cmp  %o0, 2
a00dacb8:  12 80 00 09  bne  0xa00dacdc
a00dacbc:  80 a2 20 04  cmp  %o0, 4
a00dacc0:  7f ff fd f7  call  0xa00da49c
a00dacc4:  01 00 00 00  nop
a00dacc8:  80 8a 20 ff  btst  0xff, %o0
a00daccc:  02 80 00 6f  be  0xa00dae88
a00dacd0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dacd4:  10 80 00 20  b  0xa00dad54
a00dacd8:  e0 0c e0 32  ldub  [ %l3 + 0x32 ], %l0
a00dacdc:  12 80 00 09  bne  0xa00dad00
a00dace0:  80 a0 00 12  cmp  %g0, %l2
a00dace4:  7f ff ff 6d  call  0xa00daa98
a00dace8:  01 00 00 00  nop
a00dacec:  80 8a 20 ff  btst  0xff, %o0
a00dacf0:  02 80 00 66  be  0xa00dae88
a00dacf4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dacf8:  10 80 00 28  b  0xa00dad98
a00dacfc:  e0 0c e0 32  ldub  [ %l3 + 0x32 ], %l0
a00dad00:  9a 0d 20 ff  and  %l4, 0xff, %o5
a00dad04:  82 40 20 00  addx  %g0, 0, %g1
a00dad08:  80 a8 40 0d  andncc  %g1, %o5, %g0
a00dad0c:  12 80 00 0c  bne  0xa00dad3c
a00dad10:  01 00 00 00  nop
a00dad14:  7f ff fc 52  call  0xa00d9e5c
a00dad18:  90 10 20 02  mov  2, %o0	! 0x2
a00dad1c:  a0 10 00 08  mov  %o0, %l0
a00dad20:  7f ff fc 4f  call  0xa00d9e5c
a00dad24:  90 10 20 04  mov  4, %o0
a00dad28:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00dad2c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00dad30:  80 a4 00 08  cmp  %l0, %o0
a00dad34:  0a 80 00 13  bcs  0xa00dad80
a00dad38:  01 00 00 00  nop
a00dad3c:  7f ff fd d8  call  0xa00da49c
a00dad40:  01 00 00 00  nop
a00dad44:  80 8a 20 ff  btst  0xff, %o0
a00dad48:  02 80 00 50  be  0xa00dae88
a00dad4c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dad50:  e0 0c e0 32  ldub  [ %l3 + 0x32 ], %l0
a00dad54:  9a 10 20 01  mov  1, %o5
a00dad58:  82 10 60 50  or  %g1, 0x50, %g1
a00dad5c:  da 28 40 10  stb  %o5, [ %g1 + %l0 ]
a00dad60:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dad64:  82 10 60 48  or  %g1, 0x48, %g1	! 0xa8078848
a00dad68:  40 3b 9c bf  call  0xa0fc2064
a00dad6c:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a00dad70:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dad74:  a1 2c 20 02  sll  %l0, 2, %l0
a00dad78:  10 80 00 12  b  0xa00dadc0
a00dad7c:  82 10 60 58  or  %g1, 0x58, %g1
a00dad80:  7f ff ff 46  call  0xa00daa98
a00dad84:  01 00 00 00  nop
a00dad88:  80 8a 20 ff  btst  0xff, %o0
a00dad8c:  02 80 00 3f  be  0xa00dae88
a00dad90:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dad94:  e0 0c e0 32  ldub  [ %l3 + 0x32 ], %l0
a00dad98:  9a 10 20 01  mov  1, %o5
a00dad9c:  82 10 60 48  or  %g1, 0x48, %g1
a00dada0:  da 28 40 10  stb  %o5, [ %g1 + %l0 ]
a00dada4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dada8:  82 10 60 50  or  %g1, 0x50, %g1	! 0xa8078850
a00dadac:  40 3b 9c ae  call  0xa0fc2064
a00dadb0:  c0 28 40 10  clrb  [ %g1 + %l0 ]
a00dadb4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dadb8:  a1 2c 20 02  sll  %l0, 2, %l0
a00dadbc:  82 10 60 60  or  %g1, 0x60, %g1
a00dadc0:  10 80 00 32  b  0xa00dae88
a00dadc4:  d0 20 40 10  st  %o0, [ %g1 + %l0 ]
a00dadc8:  40 3b 9c a7  call  0xa0fc2064
a00dadcc:  01 00 00 00  nop
a00dadd0:  e2 0c e0 32  ldub  [ %l3 + 0x32 ], %l1
a00dadd4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dadd8:  9b 2c 60 02  sll  %l1, 2, %o5
a00daddc:  82 10 60 58  or  %g1, 0x58, %g1
a00dade0:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a00dade4:  7f ff ff 85  call  0xa00dabf8
a00dade8:  a0 22 00 01  sub  %o0, %g1, %l0
a00dadec:  91 2a 20 10  sll  %o0, 0x10, %o0
a00dadf0:  91 32 20 10  srl  %o0, 0x10, %o0
a00dadf4:  80 a4 00 08  cmp  %l0, %o0
a00dadf8:  08 80 00 0b  bleu  0xa00dae24
a00dadfc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dae00:  a0 10 60 50  or  %g1, 0x50, %l0	! 0xa8078850
a00dae04:  c2 0c 00 11  ldub  [ %l0 + %l1 ], %g1
a00dae08:  80 a0 60 00  cmp  %g1, 0
a00dae0c:  02 80 00 06  be  0xa00dae24
a00dae10:  01 00 00 00  nop
a00dae14:  7f ff fd 5d  call  0xa00da388
a00dae18:  90 10 20 01  mov  1, %o0	! 0x1
a00dae1c:  10 80 00 1a  b  0xa00dae84
a00dae20:  c2 0c e0 32  ldub  [ %l3 + 0x32 ], %g1
a00dae24:  40 3b 9c 90  call  0xa0fc2064
a00dae28:  01 00 00 00  nop
a00dae2c:  e2 0d 60 32  ldub  [ %l5 + 0x32 ], %l1
a00dae30:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dae34:  9b 2c 60 02  sll  %l1, 2, %o5
a00dae38:  82 10 60 60  or  %g1, 0x60, %g1
a00dae3c:  c2 00 40 0d  ld  [ %g1 + %o5 ], %g1
a00dae40:  a0 22 00 01  sub  %o0, %g1, %l0
a00dae44:  90 0c a0 01  and  %l2, 1, %o0
a00dae48:  7f ff ff 6e  call  0xa00dac00
a00dae4c:  92 0d 20 01  and  %l4, 1, %o1
a00dae50:  91 2a 20 10  sll  %o0, 0x10, %o0
a00dae54:  91 32 20 10  srl  %o0, 0x10, %o0
a00dae58:  80 a4 00 08  cmp  %l0, %o0
a00dae5c:  08 80 00 0b  bleu  0xa00dae88
a00dae60:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dae64:  a0 10 60 48  or  %g1, 0x48, %l0	! 0xa8078848
a00dae68:  c2 0c 00 11  ldub  [ %l0 + %l1 ], %g1
a00dae6c:  80 a0 60 00  cmp  %g1, 0
a00dae70:  02 80 00 06  be  0xa00dae88
a00dae74:  01 00 00 00  nop
a00dae78:  7f ff fe ba  call  0xa00da960
a00dae7c:  90 10 20 01  mov  1, %o0	! 0x1
a00dae80:  c2 0d 60 32  ldub  [ %l5 + 0x32 ], %g1
a00dae84:  c0 2c 00 01  clrb  [ %l0 + %g1 ]
a00dae88:  81 c7 e0 08  ret
a00dae8c:  81 e8 00 00  restore
