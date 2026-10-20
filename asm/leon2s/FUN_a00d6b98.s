# leon2s FUN_a00d6b98 0xa00d6b98-0xa00d6c98 (256 bytes)
a00d6b98:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00d6b9c:  83 30 60 04  srl  %g1, 4, %g1
a00d6ba0:  82 00 7f ff  add  %g1, -1, %g1
a00d6ba4:  9b 30 60 1f  srl  %g1, 0x1f, %o5
a00d6ba8:  9a 00 40 0d  add  %g1, %o5, %o5
a00d6bac:  9b 3b 60 01  sra  %o5, 1, %o5
a00d6bb0:  80 88 60 01  btst  1, %g1
a00d6bb4:  94 10 00 09  mov  %o1, %o2
a00d6bb8:  02 80 00 03  be  0xa00d6bc4
a00d6bbc:  82 10 00 0d  mov  %o5, %g1
a00d6bc0:  82 03 60 01  add  %o5, 1, %g1
a00d6bc4:  92 08 60 ff  and  %g1, 0xff, %o1
a00d6bc8:  98 02 80 09  add  %o2, %o1, %o4
a00d6bcc:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a00d6bd0:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d6bd4:  9a 0b 60 7f  and  %o5, 0x7f, %o5
a00d6bd8:  82 08 7f 80  and  %g1, -128, %g1
a00d6bdc:  82 10 40 0d  or  %g1, %o5, %g1
a00d6be0:  c2 2a 00 00  stb  %g1, [ %o0 ]
a00d6be4:  da 0b 20 04  ldub  [ %o4 + 4 ], %o5
a00d6be8:  c2 0a 20 01  ldub  [ %o0 + 1 ], %g1
a00d6bec:  9a 0b 60 f0  and  %o5, 0xf0, %o5
a00d6bf0:  82 08 60 0f  and  %g1, 0xf, %g1
a00d6bf4:  82 10 40 0d  or  %g1, %o5, %g1
a00d6bf8:  c2 2a 20 01  stb  %g1, [ %o0 + 1 ]
a00d6bfc:  96 10 20 00  clr  %o3
a00d6c00:  9a 0a e0 ff  and  %o3, 0xff, %o5
a00d6c04:  82 02 40 0d  add  %o1, %o5, %g1
a00d6c08:  82 00 40 0a  add  %g1, %o2, %g1
a00d6c0c:  d8 08 60 05  ldub  [ %g1 + 5 ], %o4
a00d6c10:  96 02 e0 01  inc  %o3
a00d6c14:  9a 02 00 0d  add  %o0, %o5, %o5
a00d6c18:  82 0a e0 ff  and  %o3, 0xff, %g1
a00d6c1c:  80 a0 60 0f  cmp  %g1, 0xf
a00d6c20:  08 bf ff f8  bleu  0xa00d6c00
a00d6c24:  d8 2b 60 02  stb  %o4, [ %o5 + 2 ]
a00d6c28:  98 02 80 09  add  %o2, %o1, %o4
a00d6c2c:  da 0b 20 15  ldub  [ %o4 + 0x15 ], %o5
a00d6c30:  c2 0a 20 12  ldub  [ %o0 + 0x12 ], %g1
a00d6c34:  9a 0b 60 40  and  %o5, 0x40, %o5
a00d6c38:  82 08 7f bf  and  %g1, -65, %g1
a00d6c3c:  82 10 40 0d  or  %g1, %o5, %g1
a00d6c40:  c2 2a 20 12  stb  %g1, [ %o0 + 0x12 ]
a00d6c44:  da 0b 20 15  ldub  [ %o4 + 0x15 ], %o5
a00d6c48:  9a 0b 60 20  and  %o5, 0x20, %o5
a00d6c4c:  82 08 7f df  and  %g1, -33, %g1
a00d6c50:  82 10 40 0d  or  %g1, %o5, %g1
a00d6c54:  c2 2a 20 12  stb  %g1, [ %o0 + 0x12 ]
a00d6c58:  da 0b 20 15  ldub  [ %o4 + 0x15 ], %o5
a00d6c5c:  9a 0b 60 10  and  %o5, 0x10, %o5
a00d6c60:  82 08 7f ef  and  %g1, -17, %g1
a00d6c64:  82 10 40 0d  or  %g1, %o5, %g1
a00d6c68:  c2 2a 20 12  stb  %g1, [ %o0 + 0x12 ]
a00d6c6c:  da 0b 20 15  ldub  [ %o4 + 0x15 ], %o5
a00d6c70:  9a 0b 60 08  and  %o5, 8, %o5
a00d6c74:  82 08 7f f7  and  %g1, -9, %g1
a00d6c78:  82 10 40 0d  or  %g1, %o5, %g1
a00d6c7c:  c2 2a 20 12  stb  %g1, [ %o0 + 0x12 ]
a00d6c80:  da 0b 20 15  ldub  [ %o4 + 0x15 ], %o5
a00d6c84:  9a 0b 60 07  and  %o5, 7, %o5
a00d6c88:  82 08 7f f8  and  %g1, -8, %g1
a00d6c8c:  82 10 40 0d  or  %g1, %o5, %g1
a00d6c90:  81 c3 e0 08  retl
a00d6c94:  c2 2a 20 12  stb  %g1, [ %o0 + 0x12 ]
