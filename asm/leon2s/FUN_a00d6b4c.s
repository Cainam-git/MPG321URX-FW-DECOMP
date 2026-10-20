# leon2s FUN_a00d6b4c 0xa00d6b4c-0xa00d6b98 (76 bytes)
a00d6b4c:  c2 0a 40 00  ldub  [ %o1 ], %g1
a00d6b50:  83 30 60 04  srl  %g1, 4, %g1
a00d6b54:  82 00 7f ff  add  %g1, -1, %g1
a00d6b58:  9b 30 60 1f  srl  %g1, 0x1f, %o5
a00d6b5c:  9a 00 40 0d  add  %g1, %o5, %o5
a00d6b60:  9b 3b 60 01  sra  %o5, 1, %o5
a00d6b64:  80 88 60 01  btst  1, %g1
a00d6b68:  02 80 00 03  be  0xa00d6b74
a00d6b6c:  82 10 00 0d  mov  %o5, %g1
a00d6b70:  82 03 60 01  add  %o5, 1, %g1
a00d6b74:  82 08 60 ff  and  %g1, 0xff, %g1
a00d6b78:  82 02 40 01  add  %o1, %g1, %g1
a00d6b7c:  da 08 60 03  ldub  [ %g1 + 3 ], %o5
a00d6b80:  c2 0a 00 00  ldub  [ %o0 ], %g1
a00d6b84:  9a 0b 60 7f  and  %o5, 0x7f, %o5
a00d6b88:  82 08 7f 80  and  %g1, -128, %g1
a00d6b8c:  82 10 40 0d  or  %g1, %o5, %g1
a00d6b90:  81 c3 e0 08  retl
a00d6b94:  c2 2a 00 00  stb  %g1, [ %o0 ]
