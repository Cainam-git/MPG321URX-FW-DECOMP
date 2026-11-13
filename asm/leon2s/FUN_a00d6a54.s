# leon2s FUN_a00d6a54 0xa00d6a54-0xa00d6b4c (248 bytes)
a00d6a54:  9d e3 bf 88  save  %sp, -120, %sp
a00d6a58:  90 10 00 18  mov  %i0, %o0
a00d6a5c:  7f ff ff 9c  call  0xa00d68cc
a00d6a60:  92 07 bf e8  add  %fp, -24, %o1
a00d6a64:  b2 0e 60 ff  and  %i1, 0xff, %i1
a00d6a68:  80 a6 60 01  cmp  %i1, 1
a00d6a6c:  02 80 00 05  be  0xa00d6a80
a00d6a70:  80 a6 60 03  cmp  %i1, 3
a00d6a74:  22 80 00 1f  be,a   0xa00d6af0
a00d6a78:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d6a7c:  30 80 00 32  b,a   0xa00d6b44
a00d6a80:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d6a84:  80 a2 20 00  cmp  %o0, 0
a00d6a88:  02 80 00 2f  be  0xa00d6b44
a00d6a8c:  96 10 20 00  clr  %o3
a00d6a90:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d6a94:  d8 08 60 32  ldub  [ %g1 + 0x32 ], %o4	! 0xa8078832
a00d6a98:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00d6a9c:  82 10 60 08  or  %g1, 8, %g1	! 0xa8078808
a00d6aa0:  c2 08 40 0c  ldub  [ %g1 + %o4 ], %g1
a00d6aa4:  9a 00 40 01  add  %g1, %g1, %o5
a00d6aa8:  9a 03 40 01  add  %o5, %g1, %o5
a00d6aac:  9b 2b 60 02  sll  %o5, 2, %o5
a00d6ab0:  9a 23 40 01  sub  %o5, %g1, %o5
a00d6ab4:  98 5b 20 b0  smul  %o4, 0xb0, %o4
a00d6ab8:  03 2a 01 e8  sethi  %hi(0xa807a000), %g1
a00d6abc:  9a 03 40 0c  add  %o5, %o4, %o5
a00d6ac0:  82 10 63 98  or  %g1, 0x398, %g1
a00d6ac4:  94 03 40 01  add  %o5, %g1, %o2
a00d6ac8:  92 07 bf f8  add  %fp, -8, %o1
a00d6acc:  98 0a e0 ff  and  %o3, 0xff, %o4
a00d6ad0:  82 02 40 0c  add  %o1, %o4, %g1
a00d6ad4:  96 02 e0 01  inc  %o3
a00d6ad8:  c2 08 7f f0  ldub  [ %g1 + -16 ], %g1
a00d6adc:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d6ae0:  80 a3 40 08  cmp  %o5, %o0
a00d6ae4:  0a bf ff fa  bcs  0xa00d6acc
a00d6ae8:  c2 2a 80 0c  stb  %g1, [ %o2 + %o4 ]
a00d6aec:  30 80 00 16  b,a   0xa00d6b44
a00d6af0:  80 a2 20 00  cmp  %o0, 0
a00d6af4:  02 80 00 14  be  0xa00d6b44
a00d6af8:  96 10 20 00  clr  %o3
a00d6afc:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00d6b00:  c2 08 63 ff  ldub  [ %g1 + 0x3ff ], %g1	! 0xa80787ff
a00d6b04:  82 08 60 0f  and  %g1, 0xf, %g1
a00d6b08:  9a 00 40 01  add  %g1, %g1, %o5
a00d6b0c:  9a 03 40 01  add  %o5, %g1, %o5
a00d6b10:  03 2a 01 e9  sethi  %hi(0xa807a400), %g1
a00d6b14:  9b 2b 60 04  sll  %o5, 4, %o5
a00d6b18:  82 10 61 20  or  %g1, 0x120, %g1
a00d6b1c:  94 03 40 01  add  %o5, %g1, %o2
a00d6b20:  92 07 bf f8  add  %fp, -8, %o1
a00d6b24:  98 0a e0 ff  and  %o3, 0xff, %o4
a00d6b28:  82 02 40 0c  add  %o1, %o4, %g1
a00d6b2c:  96 02 e0 01  inc  %o3
a00d6b30:  c2 08 7f f0  ldub  [ %g1 + -16 ], %g1
a00d6b34:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d6b38:  80 a3 40 08  cmp  %o5, %o0
a00d6b3c:  0a bf ff fa  bcs  0xa00d6b24
a00d6b40:  c2 2a 80 0c  stb  %g1, [ %o2 + %o4 ]
a00d6b44:  81 c7 e0 08  ret
a00d6b48:  81 e8 00 00  restore
