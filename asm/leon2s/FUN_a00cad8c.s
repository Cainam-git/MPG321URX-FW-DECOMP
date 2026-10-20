# leon2s FUN_a00cad8c 0xa00cad8c-0xa00caee4 (344 bytes)  [FUN_a00caedc = unreachable ret/restore tail, merged]
a00cad8c:  9d e3 bf 98  save  %sp, -104, %sp
a00cad90:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00cad94:  82 06 00 18  add  %i0, %i0, %g1
a00cad98:  82 00 40 18  add  %g1, %i0, %g1
a00cad9c:  a1 28 60 03  sll  %g1, 3, %l0
a00cada0:  03 3f ff 3f  sethi  %hi(0xfffcfc00), %g1
a00cada4:  33 2a 01 e2  sethi  %hi(0xa8078800), %i1
a00cada8:  b8 16 63 b0  or  %i1, 0x3b0, %i4	! 0xa8078bb0
a00cadac:  b4 10 63 ff  or  %g1, 0x3ff, %i2
a00cadb0:  c2 07 00 10  ld  [ %i4 + %l0 ], %g1
a00cadb4:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00cadb8:  82 08 40 1a  and  %g1, %i2, %g1
a00cadbc:  82 10 40 0d  or  %g1, %o5, %g1
a00cadc0:  37 2a 01 f4  sethi  %hi(0xa807d000), %i3
a00cadc4:  c2 27 00 10  st  %g1, [ %i4 + %l0 ]
a00cadc8:  90 10 00 18  mov  %i0, %o0
a00cadcc:  7f ff fa 73  call  0xa00c9798
a00cadd0:  92 16 e2 50  or  %i3, 0x250, %o1
a00cadd4:  80 8a 20 ff  btst  0xff, %o0
a00cadd8:  32 80 00 0b  bne,a   0xa00cae04
a00caddc:  c2 07 00 10  ld  [ %i4 + %l0 ], %g1
a00cade0:  82 16 e2 50  or  %i3, 0x250, %g1
a00cade4:  d8 08 60 01  ldub  [ %g1 + 1 ], %o4
a00cade8:  82 0b 20 03  and  %o4, 3, %g1
a00cadec:  83 28 60 08  sll  %g1, 8, %g1
a00cadf0:  da 0e e2 50  ldub  [ %i3 + 0x250 ], %o5
a00cadf4:  80 8b 20 0c  btst  0xc, %o4
a00cadf8:  02 80 00 05  be  0xa00cae0c
a00cadfc:  82 00 40 0d  add  %g1, %o5, %g1
a00cae00:  c2 07 00 10  ld  [ %i4 + %l0 ], %g1
a00cae04:  10 80 00 08  b  0xa00cae24
a00cae08:  82 08 40 1a  and  %g1, %i2, %g1
a00cae0c:  83 28 60 10  sll  %g1, 0x10, %g1
a00cae10:  80 a0 60 00  cmp  %g1, 0
a00cae14:  02 80 00 0a  be  0xa00cae3c
a00cae18:  1b 00 00 c0  sethi  %hi(0x30000), %o5
a00cae1c:  c2 07 00 10  ld  [ %i4 + %l0 ], %g1
a00cae20:  82 10 40 0d  or  %g1, %o5, %g1
a00cae24:  10 80 00 2d  b  0xa00caed8
a00cae28:  c2 27 00 10  st  %g1, [ %i4 + %l0 ]
a00cae2c:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00cae30:  82 2b 40 01  andn  %o5, %g1, %g1
a00cae34:  10 80 00 1b  b  0xa00caea0
a00cae38:  c2 27 00 10  st  %g1, [ %i4 + %l0 ]
a00cae3c:  a0 04 00 1c  add  %l0, %i4, %l0
a00cae40:  7f ff f2 67  call  0xa00c77dc
a00cae44:  d0 0c 20 09  ldub  [ %l0 + 9 ], %o0
a00cae48:  7f ff fb a0  call  0xa00c9cc8
a00cae4c:  d0 0c 20 09  ldub  [ %l0 + 9 ], %o0
a00cae50:  10 80 00 07  b  0xa00cae6c
a00cae54:  b6 10 20 1e  mov  0x1e, %i3
a00cae58:  40 3b da 4f  call  0xa0fc1794
a00cae5c:  01 00 00 00  nop
a00cae60:  80 8e e0 ff  btst  0xff, %i3
a00cae64:  22 bf ff f2  be,a   0xa00cae2c
a00cae68:  da 07 00 10  ld  [ %i4 + %l0 ], %o5
a00cae6c:  82 06 00 18  add  %i0, %i0, %g1
a00cae70:  82 00 40 18  add  %g1, %i0, %g1
a00cae74:  a1 28 60 03  sll  %g1, 3, %l0
a00cae78:  b8 16 63 b0  or  %i1, 0x3b0, %i4
a00cae7c:  82 04 00 1c  add  %l0, %i4, %g1
a00cae80:  13 2a 01 f3  sethi  %hi(0xa807cc00), %o1
a00cae84:  92 12 62 51  or  %o1, 0x251, %o1	! 0xa807ce51
a00cae88:  7f ff dd 80  call  0xa00c2488
a00cae8c:  d0 08 60 09  ldub  [ %g1 + 9 ], %o0
a00cae90:  80 8a 20 ff  btst  0xff, %o0
a00cae94:  b6 06 ff ff  add  %i3, -1, %i3
a00cae98:  02 bf ff f0  be  0xa00cae58
a00cae9c:  90 10 20 0a  mov  0xa, %o0
a00caea0:  33 2a 01 f3  sethi  %hi(0xa807cc00), %i1
a00caea4:  82 10 20 04  mov  4, %g1
a00caea8:  c2 2e 62 50  stb  %g1, [ %i1 + 0x250 ]
a00caeac:  9a 10 20 00  clr  %o5
a00caeb0:  9a 03 60 01  inc  %o5
a00caeb4:  82 0b 60 ff  and  %o5, 0xff, %g1
a00caeb8:  80 a0 60 80  cmp  %g1, 0x80
a00caebc:  08 bf ff fe  bleu  0xa00caeb4
a00caec0:  9a 03 60 01  inc  %o5
a00caec4:  b2 16 62 50  or  %i1, 0x250, %i1
a00caec8:  b4 10 20 74  mov  0x74, %i2
a00caecc:  b6 10 20 60  mov  0x60, %i3
a00caed0:  7f ff f4 88  call  0xa00c80f0
a00caed4:  99 e8 20 81  restore  %g0, 0x81, %o4
a00caed8:  01 00 00 00  nop
a00caedc:  81 c7 e0 08  ret
a00caee0:  81 e8 00 00  restore
