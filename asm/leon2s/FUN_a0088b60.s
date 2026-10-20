# leon2s FUN_a0088b60 0xa0088b60-0xa0088c5c (252 bytes)
a0088b60:  9d e3 bf 90  save  %sp, -112, %sp
a0088b64:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0088b68:  7f ff ff e2  call  0xa0088af0
a0088b6c:  90 10 00 18  mov  %i0, %o0
a0088b70:  80 8a 20 ff  btst  0xff, %o0
a0088b74:  02 80 00 38  be  0xa0088c54
a0088b78:  01 00 00 00  nop
a0088b7c:  7f ff f6 ca  call  0xa00866a4
a0088b80:  01 00 00 00  nop
a0088b84:  80 8a 20 ff  btst  0xff, %o0
a0088b88:  02 80 00 10  be  0xa0088bc8
a0088b8c:  a2 10 20 00  clr  %l1
a0088b90:  80 a6 20 00  cmp  %i0, 0
a0088b94:  12 80 00 0e  bne  0xa0088bcc
a0088b98:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0088b9c:  90 10 20 00  clr  %o0
a0088ba0:  92 10 20 90  mov  0x90, %o1
a0088ba4:  94 10 21 11  mov  0x111, %o2
a0088ba8:  7f ff f5 fd  call  0xa008639c
a0088bac:  96 07 bf f7  add  %fp, -9, %o3
a0088bb0:  80 8a 20 ff  btst  0xff, %o0
a0088bb4:  12 80 00 28  bne  0xa0088c54
a0088bb8:  c2 0f bf f7  ldub  [ %fp + -9 ], %g1
a0088bbc:  80 88 60 01  btst  1, %g1
a0088bc0:  12 80 00 25  bne  0xa0088c54
a0088bc4:  a2 10 20 00  clr  %l1
a0088bc8:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0088bcc:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0088bd0:  a1 2c 20 04  sll  %l0, 4, %l0
a0088bd4:  98 10 61 f0  or  %g1, 0x1f0, %o4
a0088bd8:  e0 28 61 f0  stb  %l0, [ %g1 + 0x1f0 ]
a0088bdc:  92 10 20 40  mov  0x40, %o1
a0088be0:  94 10 20 50  mov  0x50, %o2
a0088be4:  96 10 20 00  clr  %o3
a0088be8:  7f ff f5 fb  call  0xa00863d4
a0088bec:  90 10 00 18  mov  %i0, %o0
a0088bf0:  19 27 c6 c0  sethi  %hi(0x9f1b0000), %o4
a0088bf4:  98 13 20 00  mov  %o4, %o4	! 0x9f1b0000
a0088bf8:  98 04 00 0c  add  %l0, %o4, %o4
a0088bfc:  92 10 20 10  mov  0x10, %o1
a0088c00:  94 10 20 50  mov  0x50, %o2
a0088c04:  96 10 20 0f  mov  0xf, %o3
a0088c08:  7f ff f5 fe  call  0xa0086400
a0088c0c:  90 10 00 18  mov  %i0, %o0
a0088c10:  7f ff ff b8  call  0xa0088af0
a0088c14:  90 10 00 18  mov  %i0, %o0
a0088c18:  a2 04 60 01  inc  %l1
a0088c1c:  80 8a 20 ff  btst  0xff, %o0
a0088c20:  02 80 00 0d  be  0xa0088c54
a0088c24:  9a 0c 60 ff  and  %l1, 0xff, %o5
a0088c28:  03 33 c0 62  sethi  %hi(0xcf018800), %g1
a0088c2c:  82 10 60 84  or  %g1, 0x84, %g1	! 0xcf018884
a0088c30:  c2 00 40 00  ld  [ %g1 ], %g1
a0088c34:  80 88 60 80  btst  0x80, %g1
a0088c38:  12 80 00 07  bne  0xa0088c54
a0088c3c:  80 a3 60 0f  cmp  %o5, 0xf
a0088c40:  08 bf ff e3  bleu  0xa0088bcc
a0088c44:  a0 0c 60 ff  and  %l1, 0xff, %l0
a0088c48:  9a 10 20 01  mov  1, %o5
a0088c4c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0088c50:  da 28 62 0a  stb  %o5, [ %g1 + 0x20a ]	! 0xa8078a0a
a0088c54:  81 c7 e0 08  ret
a0088c58:  81 e8 00 00  restore
