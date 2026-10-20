# leon2m FUN_a0098a74 0xa0098a74-0xa0098c08 (404 bytes)
a0098a74:  9d e3 bf 98  save  %sp, -104, %sp
a0098a78:  1f 09 24 92  sethi  %hi(0x24924800), %o7
a0098a7c:  a0 13 e1 25  or  %o7, 0x125, %l0	! 0x24924925
a0098a80:  27 2a 00 ab  sethi  %hi(0xa802ac00), %l3
a0098a84:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a0098a88:  de 0c 60 56  ldub  [ %l1 + 0x56 ], %o7	! 0xa8025c56
a0098a8c:  d6 04 e3 ec  ld  [ %l3 + 0x3ec ], %o3
a0098a90:  92 02 ff 6e  add  %o3, -146, %o1
a0098a94:  80 53 c0 10  umul  %o7, %l0, %g0
a0098a98:  91 40 00 00  rd  %y, %o0
a0098a9c:  80 52 40 10  umul  %o1, %l0, %g0
a0098aa0:  97 40 00 00  rd  %y, %o3
a0098aa4:  98 23 c0 08  sub  %o7, %o0, %o4
a0098aa8:  82 22 40 0b  sub  %o1, %o3, %g1
a0098aac:  9b 33 20 01  srl  %o4, 1, %o5
a0098ab0:  98 02 00 0d  add  %o0, %o5, %o4
a0098ab4:  93 30 60 01  srl  %g1, 1, %o1
a0098ab8:  9a 02 c0 09  add  %o3, %o1, %o5
a0098abc:  93 33 20 02  srl  %o4, 2, %o1
a0098ac0:  91 2a 60 03  sll  %o1, 3, %o0
a0098ac4:  82 22 00 09  sub  %o0, %o1, %g1
a0098ac8:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0098acc:  90 23 c0 01  sub  %o7, %g1, %o0
a0098ad0:  97 33 60 02  srl  %o5, 2, %o3
a0098ad4:  98 0a 60 ff  and  %o1, 0xff, %o4
a0098ad8:  94 14 a2 90  or  %l2, 0x290, %o2
a0098adc:  80 a2 c0 0c  cmp  %o3, %o4
a0098ae0:  02 80 00 11  be  0xa0098b24
a0098ae4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0098ae8:  d0 0a a0 08  ldub  [ %o2 + 8 ], %o0
a0098aec:  80 52 00 10  umul  %o0, %l0, %g0
a0098af0:  99 40 00 00  rd  %y, %o4
a0098af4:  9a 22 00 0c  sub  %o0, %o4, %o5
a0098af8:  93 33 60 01  srl  %o5, 1, %o1
a0098afc:  82 03 00 09  add  %o4, %o1, %g1
a0098b00:  a3 30 60 02  srl  %g1, 2, %l1
a0098b04:  a1 2c 60 03  sll  %l1, 3, %l0
a0098b08:  94 24 00 11  sub  %l0, %l1, %o2
a0098b0c:  9e 22 00 0a  sub  %o0, %o2, %o7
a0098b10:  90 0b e0 ff  and  %o7, 0xff, %o0
a0098b14:  40 00 42 2a  call  0xa00a93bc
a0098b18:  a2 14 a2 90  or  %l2, 0x290, %l1
a0098b1c:  10 80 00 14  b  0xa0098b6c
a0098b20:  21 09 24 92  sethi  %hi(0x24924800), %l0
a0098b24:  40 00 42 26  call  0xa00a93bc
a0098b28:  01 00 00 00  nop
a0098b2c:  d0 0c 60 56  ldub  [ %l1 + 0x56 ], %o0
a0098b30:  80 52 00 10  umul  %o0, %l0, %g0
a0098b34:  93 40 00 00  rd  %y, %o1
a0098b38:  96 22 00 09  sub  %o0, %o1, %o3
a0098b3c:  9b 32 e0 01  srl  %o3, 1, %o5
a0098b40:  98 02 40 0d  add  %o1, %o5, %o4
a0098b44:  83 33 20 02  srl  %o4, 2, %g1
a0098b48:  a3 28 60 03  sll  %g1, 3, %l1
a0098b4c:  a0 24 40 01  sub  %l1, %g1, %l0
a0098b50:  94 22 00 10  sub  %o0, %l0, %o2
a0098b54:  92 0a a0 ff  and  %o2, 0xff, %o1
a0098b58:  90 10 20 01  mov  1, %o0
a0098b5c:  40 00 3d 78  call  0xa00a813c
a0098b60:  94 10 20 00  clr  %o2
a0098b64:  a2 14 a2 90  or  %l2, 0x290, %l1
a0098b68:  21 09 24 92  sethi  %hi(0x24924800), %l0
a0098b6c:  de 0c 60 08  ldub  [ %l1 + 8 ], %o7
a0098b70:  a0 14 21 25  or  %l0, 0x125, %l0
a0098b74:  80 53 c0 10  umul  %o7, %l0, %g0
a0098b78:  93 40 00 00  rd  %y, %o1
a0098b7c:  a4 23 c0 09  sub  %o7, %o1, %l2
a0098b80:  9b 34 a0 01  srl  %l2, 1, %o5
a0098b84:  98 02 40 0d  add  %o1, %o5, %o4
a0098b88:  83 33 20 02  srl  %o4, 2, %g1
a0098b8c:  95 28 60 03  sll  %g1, 3, %o2
a0098b90:  90 22 80 01  sub  %o2, %g1, %o0
a0098b94:  96 23 c0 08  sub  %o7, %o0, %o3
a0098b98:  90 0a e0 ff  and  %o3, 0xff, %o0
a0098b9c:  40 00 42 ad  call  0xa00a9650
a0098ba0:  92 10 20 00  clr  %o1
a0098ba4:  d4 0c 60 08  ldub  [ %l1 + 8 ], %o2
a0098ba8:  80 52 80 10  umul  %o2, %l0, %g0
a0098bac:  93 40 00 00  rd  %y, %o1
a0098bb0:  a4 22 80 09  sub  %o2, %o1, %l2
a0098bb4:  9b 34 a0 01  srl  %l2, 1, %o5
a0098bb8:  98 02 40 0d  add  %o1, %o5, %o4
a0098bbc:  a1 33 20 02  srl  %o4, 2, %l0
a0098bc0:  83 2c 20 03  sll  %l0, 3, %g1
a0098bc4:  a2 20 40 10  sub  %g1, %l0, %l1
a0098bc8:  90 22 80 11  sub  %o2, %l1, %o0
a0098bcc:  92 0a 20 ff  and  %o0, 0xff, %o1
a0098bd0:  90 10 20 01  mov  1, %o0
a0098bd4:  40 00 3d 5a  call  0xa00a813c
a0098bd8:  94 10 20 01  mov  1, %o2
a0098bdc:  9e 10 20 2a  mov  0x2a, %o7
a0098be0:  de 24 e3 ec  st  %o7, [ %l3 + 0x3ec ]
a0098be4:  90 10 20 00  clr  %o0
a0098be8:  40 00 41 09  call  0xa00a900c
a0098bec:  92 10 20 01  mov  1, %o1
a0098bf0:  25 2a 00 ac  sethi  %hi(0xa802b000), %l2
a0098bf4:  d6 0c a0 8e  ldub  [ %l2 + 0x8e ], %o3	! 0xa802b08e
a0098bf8:  a6 12 e0 02  or  %o3, 2, %l3
a0098bfc:  e6 2c a0 8e  stb  %l3, [ %l2 + 0x8e ]
a0098c00:  81 c7 e0 08  ret
a0098c04:  81 e8 00 00  restore
