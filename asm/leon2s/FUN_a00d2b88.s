# leon2s FUN_a00d2b88 0xa00d2b88-0xa00d2c38 (176 bytes)
a00d2b88:  1b 2a 01 e3  sethi  %hi(0xa8078c00), %o5
a00d2b8c:  c2 0b 60 34  ldub  [ %o5 + 0x34 ], %g1	! 0xa8078c34
a00d2b90:  80 a0 60 01  cmp  %g1, 1
a00d2b94:  12 80 00 04  bne  0xa00d2ba4
a00d2b98:  90 10 20 00  clr  %o0
a00d2b9c:  c0 2b 60 34  clrb  [ %o5 + 0x34 ]
a00d2ba0:  90 10 20 01  mov  1, %o0
a00d2ba4:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d2ba8:  c2 08 60 38  ldub  [ %g1 + 0x38 ], %g1	! 0xa8078c38
a00d2bac:  80 a0 60 00  cmp  %g1, 0
a00d2bb0:  22 80 00 06  be,a   0xa00d2bc8
a00d2bb4:  90 10 20 01  mov  1, %o0
a00d2bb8:  80 a0 60 04  cmp  %g1, 4
a00d2bbc:  12 80 00 04  bne  0xa00d2bcc
a00d2bc0:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00d2bc4:  90 10 20 01  mov  1, %o0
a00d2bc8:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00d2bcc:  98 10 61 48  or  %g1, 0x148, %o4	! 0xa807d548
a00d2bd0:  17 2a 01 e3  sethi  %hi(0xa8078c00), %o3
a00d2bd4:  da 03 20 04  ld  [ %o4 + 4 ], %o5
a00d2bd8:  c2 02 e0 2c  ld  [ %o3 + 0x2c ], %g1
a00d2bdc:  80 a3 40 01  cmp  %o5, %g1
a00d2be0:  22 80 00 05  be,a   0xa00d2bf4
a00d2be4:  17 2a 01 e3  sethi  %hi(0xa8078c00), %o3
a00d2be8:  da 22 e0 2c  st  %o5, [ %o3 + 0x2c ]	! 0xa8078c2c
a00d2bec:  90 10 20 01  mov  1, %o0
a00d2bf0:  17 2a 01 e3  sethi  %hi(0xa8078c00), %o3
a00d2bf4:  da 13 20 1c  lduh  [ %o4 + 0x1c ], %o5
a00d2bf8:  c2 12 e0 28  lduh  [ %o3 + 0x28 ], %g1
a00d2bfc:  80 a3 40 01  cmp  %o5, %g1
a00d2c00:  02 80 00 04  be  0xa00d2c10
a00d2c04:  19 2a 01 de  sethi  %hi(0xa8077800), %o4
a00d2c08:  da 32 e0 28  sth  %o5, [ %o3 + 0x28 ]
a00d2c0c:  90 10 20 01  mov  1, %o0
a00d2c10:  17 2a 01 d9  sethi  %hi(0xa8076400), %o3
a00d2c14:  da 13 21 dc  lduh  [ %o4 + 0x1dc ], %o5
a00d2c18:  c2 12 e2 ac  lduh  [ %o3 + 0x2ac ], %g1
a00d2c1c:  80 a0 40 0d  cmp  %g1, %o5
a00d2c20:  02 80 00 04  be  0xa00d2c30
a00d2c24:  01 00 00 00  nop
a00d2c28:  da 32 e2 ac  sth  %o5, [ %o3 + 0x2ac ]
a00d2c2c:  90 10 20 01  mov  1, %o0
a00d2c30:  81 c3 e0 08  retl
a00d2c34:  90 0a 20 01  and  %o0, 1, %o0
