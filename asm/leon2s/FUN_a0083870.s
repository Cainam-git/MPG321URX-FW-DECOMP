# leon2s FUN_a0083870 0xa0083870-0xa0083e28 (1464 bytes)
a0083870:  9d e3 bf 98  save  %sp, -104, %sp
a0083874:  03 33 c0 62  sethi  %hi(0xcf018800), %g1
a0083878:  82 10 60 84  or  %g1, 0x84, %g1	! 0xcf018884
a008387c:  d4 00 40 00  ld  [ %g1 ], %o2
a0083880:  03 33 c0 65  sethi  %hi(0xcf019400), %g1
a0083884:  82 10 60 84  or  %g1, 0x84, %g1	! 0xcf019484
a0083888:  d6 00 40 00  ld  [ %g1 ], %o3
a008388c:  03 33 c0 66  sethi  %hi(0xcf019800), %g1
a0083890:  82 10 60 84  or  %g1, 0x84, %g1	! 0xcf019884
a0083894:  d8 00 40 00  ld  [ %g1 ], %o4
a0083898:  03 33 c0 67  sethi  %hi(0xcf019c00), %g1
a008389c:  82 10 60 84  or  %g1, 0x84, %g1	! 0xcf019c84
a00838a0:  da 00 40 00  ld  [ %g1 ], %o5
a00838a4:  03 33 c0 68  sethi  %hi(0xcf01a000), %g1
a00838a8:  82 10 60 84  or  %g1, 0x84, %g1	! 0xcf01a084
a00838ac:  c2 00 40 00  ld  [ %g1 ], %g1
a00838b0:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00838b4:  a0 10 00 0a  mov  %o2, %l0
a00838b8:  a2 10 00 0b  mov  %o3, %l1
a00838bc:  a4 10 00 0c  mov  %o4, %l2
a00838c0:  a6 10 00 0d  mov  %o5, %l3
a00838c4:  80 8e 20 01  btst  1, %i0
a00838c8:  02 80 00 66  be  0xa0083a60
a00838cc:  a8 10 00 01  mov  %g1, %l4
a00838d0:  7f ff b2 d5  call  0xa0070424
a00838d4:  01 00 00 00  nop
a00838d8:  80 8a 20 ff  btst  0xff, %o0
a00838dc:  02 80 00 0a  be  0xa0083904
a00838e0:  80 8c 20 08  btst  8, %l0
a00838e4:  02 80 00 05  be  0xa00838f8
a00838e8:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00838ec:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1	! 0xa80789e0
a00838f0:  10 80 00 04  b  0xa0083900
a00838f4:  82 10 60 04  or  %g1, 4, %g1
a00838f8:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1
a00838fc:  82 08 7f fb  and  %g1, -5, %g1
a0083900:  c2 2b 61 e0  stb  %g1, [ %o5 + 0x1e0 ]
a0083904:  7f ff b1 ac  call  0xa006ffb4
a0083908:  01 00 00 00  nop
a008390c:  80 8a 20 ff  btst  0xff, %o0
a0083910:  02 80 00 0a  be  0xa0083938
a0083914:  80 8c 60 08  btst  8, %l1
a0083918:  02 80 00 05  be  0xa008392c
a008391c:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083920:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1	! 0xa80789e0
a0083924:  10 80 00 04  b  0xa0083934
a0083928:  82 10 60 08  or  %g1, 8, %g1
a008392c:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1
a0083930:  82 08 7f f7  and  %g1, -9, %g1
a0083934:  c2 2b 61 e0  stb  %g1, [ %o5 + 0x1e0 ]
a0083938:  7f ff b1 a3  call  0xa006ffc4
a008393c:  01 00 00 00  nop
a0083940:  80 8a 20 ff  btst  0xff, %o0
a0083944:  02 80 00 0a  be  0xa008396c
a0083948:  80 8c a0 08  btst  8, %l2
a008394c:  02 80 00 05  be  0xa0083960
a0083950:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083954:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1	! 0xa80789e0
a0083958:  10 80 00 04  b  0xa0083968
a008395c:  82 10 60 10  or  %g1, 0x10, %g1
a0083960:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1
a0083964:  82 08 7f ef  and  %g1, -17, %g1
a0083968:  c2 2b 61 e0  stb  %g1, [ %o5 + 0x1e0 ]
a008396c:  7f ff b1 9a  call  0xa006ffd4
a0083970:  01 00 00 00  nop
a0083974:  80 8a 20 ff  btst  0xff, %o0
a0083978:  02 80 00 0a  be  0xa00839a0
a008397c:  80 8c e0 08  btst  8, %l3
a0083980:  02 80 00 05  be  0xa0083994
a0083984:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083988:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1	! 0xa80789e0
a008398c:  10 80 00 04  b  0xa008399c
a0083990:  82 10 60 20  or  %g1, 0x20, %g1
a0083994:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1
a0083998:  82 08 7f df  and  %g1, -33, %g1
a008399c:  c2 2b 61 e0  stb  %g1, [ %o5 + 0x1e0 ]
a00839a0:  7f ff b1 91  call  0xa006ffe4
a00839a4:  01 00 00 00  nop
a00839a8:  80 8a 20 ff  btst  0xff, %o0
a00839ac:  02 80 00 0a  be  0xa00839d4
a00839b0:  80 8d 20 08  btst  8, %l4
a00839b4:  02 80 00 05  be  0xa00839c8
a00839b8:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a00839bc:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1	! 0xa80789e0
a00839c0:  10 80 00 04  b  0xa00839d0
a00839c4:  82 10 60 40  or  %g1, 0x40, %g1
a00839c8:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1
a00839cc:  82 08 7f bf  and  %g1, -65, %g1
a00839d0:  c2 2b 61 e0  stb  %g1, [ %o5 + 0x1e0 ]
a00839d4:  7f ff b2 8c  call  0xa0070404
a00839d8:  01 00 00 00  nop
a00839dc:  80 8a 20 ff  btst  0xff, %o0
a00839e0:  02 80 00 0e  be  0xa0083a18
a00839e4:  90 10 20 00  clr  %o0
a00839e8:  92 10 20 00  clr  %o1
a00839ec:  40 00 91 7b  call  0xa00a7fd8
a00839f0:  94 10 20 09  mov  9, %o2
a00839f4:  80 8a 20 02  btst  2, %o0
a00839f8:  02 80 00 05  be  0xa0083a0c
a00839fc:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083a00:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1	! 0xa80789e0
a0083a04:  10 80 00 04  b  0xa0083a14
a0083a08:  82 10 60 01  or  %g1, 1, %g1
a0083a0c:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1
a0083a10:  82 08 7f fe  and  %g1, -2, %g1
a0083a14:  c2 2b 61 e0  stb  %g1, [ %o5 + 0x1e0 ]
a0083a18:  7f ff b2 7f  call  0xa0070414
a0083a1c:  01 00 00 00  nop
a0083a20:  80 8a 20 ff  btst  0xff, %o0
a0083a24:  02 80 00 10  be  0xa0083a64
a0083a28:  80 8e 20 02  btst  2, %i0
a0083a2c:  90 10 20 01  mov  1, %o0
a0083a30:  92 10 20 00  clr  %o1
a0083a34:  40 00 91 69  call  0xa00a7fd8
a0083a38:  94 10 20 09  mov  9, %o2
a0083a3c:  80 8a 20 02  btst  2, %o0
a0083a40:  02 80 00 05  be  0xa0083a54
a0083a44:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083a48:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1	! 0xa80789e0
a0083a4c:  10 80 00 04  b  0xa0083a5c
a0083a50:  82 10 60 02  or  %g1, 2, %g1
a0083a54:  c2 0b 61 e0  ldub  [ %o5 + 0x1e0 ], %g1
a0083a58:  82 08 7f fd  and  %g1, -3, %g1
a0083a5c:  c2 2b 61 e0  stb  %g1, [ %o5 + 0x1e0 ]
a0083a60:  80 8e 20 02  btst  2, %i0
a0083a64:  02 80 00 ef  be  0xa0083e20
a0083a68:  31 2a 01 e2  sethi  %hi(0xa8078800), %i0
a0083a6c:  7f ff b2 6e  call  0xa0070424
a0083a70:  c0 26 21 e4  clr  [ %i0 + 0x1e4 ]	! 0xa80789e4
a0083a74:  80 8a 20 ff  btst  0xff, %o0
a0083a78:  02 80 00 1b  be  0xa0083ae4
a0083a7c:  98 0c 20 ff  and  %l0, 0xff, %o4
a0083a80:  80 8b 20 40  btst  0x40, %o4
a0083a84:  02 80 00 0f  be  0xa0083ac0
a0083a88:  80 8c 20 80  btst  0x80, %l0
a0083a8c:  9a 0b 20 3f  and  %o4, 0x3f, %o5
a0083a90:  03 33 c0 62  sethi  %hi(0xcf018800), %g1
a0083a94:  82 10 60 84  or  %g1, 0x84, %g1	! 0xcf018884
a0083a98:  9a 13 60 40  or  %o5, 0x40, %o5
a0083a9c:  da 20 40 00  st  %o5, [ %g1 ]
a0083aa0:  80 8b 20 08  btst  8, %o4
a0083aa4:  02 80 00 04  be  0xa0083ab4
a0083aa8:  c2 06 21 e4  ld  [ %i0 + 0x1e4 ], %g1
a0083aac:  10 80 00 03  b  0xa0083ab8
a0083ab0:  82 10 60 01  or  %g1, 1, %g1
a0083ab4:  82 10 60 02  or  %g1, 2, %g1
a0083ab8:  c2 26 21 e4  st  %g1, [ %i0 + 0x1e4 ]
a0083abc:  80 8c 20 80  btst  0x80, %l0
a0083ac0:  02 80 00 09  be  0xa0083ae4
a0083ac4:  82 0b 20 3f  and  %o4, 0x3f, %g1
a0083ac8:  1b 33 c0 62  sethi  %hi(0xcf018800), %o5
a0083acc:  d8 06 21 e4  ld  [ %i0 + 0x1e4 ], %o4
a0083ad0:  82 10 60 80  or  %g1, 0x80, %g1
a0083ad4:  9a 13 60 84  or  %o5, 0x84, %o5
a0083ad8:  98 13 20 04  or  %o4, 4, %o4
a0083adc:  c2 23 40 00  st  %g1, [ %o5 ]
a0083ae0:  d8 26 21 e4  st  %o4, [ %i0 + 0x1e4 ]
a0083ae4:  7f ff b1 34  call  0xa006ffb4
a0083ae8:  01 00 00 00  nop
a0083aec:  80 8a 20 ff  btst  0xff, %o0
a0083af0:  02 80 00 1e  be  0xa0083b68
a0083af4:  98 0c 60 ff  and  %l1, 0xff, %o4
a0083af8:  80 8b 20 40  btst  0x40, %o4
a0083afc:  02 80 00 11  be  0xa0083b40
a0083b00:  80 8c 60 80  btst  0x80, %l1
a0083b04:  9a 0b 20 3f  and  %o4, 0x3f, %o5
a0083b08:  03 33 c0 65  sethi  %hi(0xcf019400), %g1
a0083b0c:  9a 13 60 40  or  %o5, 0x40, %o5
a0083b10:  82 10 60 84  or  %g1, 0x84, %g1
a0083b14:  da 20 40 00  st  %o5, [ %g1 ]
a0083b18:  80 8b 20 08  btst  8, %o4
a0083b1c:  02 80 00 05  be  0xa0083b30
a0083b20:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a0083b24:  c2 02 e1 e4  ld  [ %o3 + 0x1e4 ], %g1	! 0xa80789e4
a0083b28:  10 80 00 04  b  0xa0083b38
a0083b2c:  82 10 60 08  or  %g1, 8, %g1
a0083b30:  c2 02 e1 e4  ld  [ %o3 + 0x1e4 ], %g1
a0083b34:  82 10 60 10  or  %g1, 0x10, %g1
a0083b38:  c2 22 e1 e4  st  %g1, [ %o3 + 0x1e4 ]
a0083b3c:  80 8c 60 80  btst  0x80, %l1
a0083b40:  02 80 00 0a  be  0xa0083b68
a0083b44:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a0083b48:  9a 0b 20 3f  and  %o4, 0x3f, %o5
a0083b4c:  03 33 c0 65  sethi  %hi(0xcf019400), %g1
a0083b50:  d8 02 e1 e4  ld  [ %o3 + 0x1e4 ], %o4
a0083b54:  9a 13 60 80  or  %o5, 0x80, %o5
a0083b58:  82 10 60 84  or  %g1, 0x84, %g1
a0083b5c:  98 13 20 20  or  %o4, 0x20, %o4
a0083b60:  da 20 40 00  st  %o5, [ %g1 ]
a0083b64:  d8 22 e1 e4  st  %o4, [ %o3 + 0x1e4 ]
a0083b68:  7f ff b1 17  call  0xa006ffc4
a0083b6c:  01 00 00 00  nop
a0083b70:  80 8a 20 ff  btst  0xff, %o0
a0083b74:  02 80 00 1e  be  0xa0083bec
a0083b78:  98 0c a0 ff  and  %l2, 0xff, %o4
a0083b7c:  80 8b 20 40  btst  0x40, %o4
a0083b80:  02 80 00 11  be  0xa0083bc4
a0083b84:  80 8c a0 80  btst  0x80, %l2
a0083b88:  9a 0b 20 3f  and  %o4, 0x3f, %o5
a0083b8c:  03 33 c0 66  sethi  %hi(0xcf019800), %g1
a0083b90:  9a 13 60 40  or  %o5, 0x40, %o5
a0083b94:  82 10 60 84  or  %g1, 0x84, %g1
a0083b98:  da 20 40 00  st  %o5, [ %g1 ]
a0083b9c:  80 8b 20 08  btst  8, %o4
a0083ba0:  02 80 00 05  be  0xa0083bb4
a0083ba4:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a0083ba8:  c2 02 e1 e4  ld  [ %o3 + 0x1e4 ], %g1	! 0xa80789e4
a0083bac:  10 80 00 04  b  0xa0083bbc
a0083bb0:  82 10 60 40  or  %g1, 0x40, %g1
a0083bb4:  c2 02 e1 e4  ld  [ %o3 + 0x1e4 ], %g1
a0083bb8:  82 10 60 80  or  %g1, 0x80, %g1
a0083bbc:  c2 22 e1 e4  st  %g1, [ %o3 + 0x1e4 ]
a0083bc0:  80 8c a0 80  btst  0x80, %l2
a0083bc4:  02 80 00 0a  be  0xa0083bec
a0083bc8:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a0083bcc:  9a 0b 20 3f  and  %o4, 0x3f, %o5
a0083bd0:  03 33 c0 66  sethi  %hi(0xcf019800), %g1
a0083bd4:  d8 02 e1 e4  ld  [ %o3 + 0x1e4 ], %o4
a0083bd8:  9a 13 60 80  or  %o5, 0x80, %o5
a0083bdc:  82 10 60 84  or  %g1, 0x84, %g1
a0083be0:  98 13 21 00  or  %o4, 0x100, %o4
a0083be4:  da 20 40 00  st  %o5, [ %g1 ]
a0083be8:  d8 22 e1 e4  st  %o4, [ %o3 + 0x1e4 ]
a0083bec:  7f ff b0 fa  call  0xa006ffd4
a0083bf0:  01 00 00 00  nop
a0083bf4:  80 8a 20 ff  btst  0xff, %o0
a0083bf8:  02 80 00 20  be  0xa0083c78
a0083bfc:  98 0c e0 ff  and  %l3, 0xff, %o4
a0083c00:  80 8b 20 40  btst  0x40, %o4
a0083c04:  02 80 00 12  be  0xa0083c4c
a0083c08:  80 8c e0 80  btst  0x80, %l3
a0083c0c:  9a 0b 20 3f  and  %o4, 0x3f, %o5
a0083c10:  03 33 c0 67  sethi  %hi(0xcf019c00), %g1
a0083c14:  9a 13 60 40  or  %o5, 0x40, %o5
a0083c18:  82 10 60 84  or  %g1, 0x84, %g1
a0083c1c:  da 20 40 00  st  %o5, [ %g1 ]
a0083c20:  80 8b 20 08  btst  8, %o4
a0083c24:  02 80 00 05  be  0xa0083c38
a0083c28:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a0083c2c:  c2 02 e1 e4  ld  [ %o3 + 0x1e4 ], %g1	! 0xa80789e4
a0083c30:  10 80 00 04  b  0xa0083c40
a0083c34:  1b 00 00 08  sethi  %hi(0x2000), %o5
a0083c38:  c2 02 e1 e4  ld  [ %o3 + 0x1e4 ], %g1
a0083c3c:  1b 00 00 10  sethi  %hi(0x4000), %o5
a0083c40:  82 10 40 0d  or  %g1, %o5, %g1
a0083c44:  c2 22 e1 e4  st  %g1, [ %o3 + 0x1e4 ]
a0083c48:  80 8c e0 80  btst  0x80, %l3
a0083c4c:  02 80 00 0b  be  0xa0083c78
a0083c50:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a0083c54:  9a 0b 20 3f  and  %o4, 0x3f, %o5
a0083c58:  d8 02 e1 e4  ld  [ %o3 + 0x1e4 ], %o4
a0083c5c:  03 00 00 20  sethi  %hi(0x8000), %g1
a0083c60:  98 13 00 01  or  %o4, %g1, %o4
a0083c64:  03 33 c0 67  sethi  %hi(0xcf019c00), %g1
a0083c68:  9a 13 60 80  or  %o5, 0x80, %o5
a0083c6c:  82 10 60 84  or  %g1, 0x84, %g1
a0083c70:  da 20 40 00  st  %o5, [ %g1 ]
a0083c74:  d8 22 e1 e4  st  %o4, [ %o3 + 0x1e4 ]
a0083c78:  7f ff b0 db  call  0xa006ffe4
a0083c7c:  01 00 00 00  nop
a0083c80:  80 8a 20 ff  btst  0xff, %o0
a0083c84:  02 80 00 20  be  0xa0083d04
a0083c88:  98 0d 20 ff  and  %l4, 0xff, %o4
a0083c8c:  80 8b 20 40  btst  0x40, %o4
a0083c90:  02 80 00 12  be  0xa0083cd8
a0083c94:  80 8d 20 80  btst  0x80, %l4
a0083c98:  9a 0b 20 3f  and  %o4, 0x3f, %o5
a0083c9c:  03 33 c0 68  sethi  %hi(0xcf01a000), %g1
a0083ca0:  9a 13 60 40  or  %o5, 0x40, %o5
a0083ca4:  82 10 60 84  or  %g1, 0x84, %g1
a0083ca8:  da 20 40 00  st  %o5, [ %g1 ]
a0083cac:  80 8b 20 08  btst  8, %o4
a0083cb0:  02 80 00 05  be  0xa0083cc4
a0083cb4:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a0083cb8:  c2 02 e1 e4  ld  [ %o3 + 0x1e4 ], %g1	! 0xa80789e4
a0083cbc:  10 80 00 04  b  0xa0083ccc
a0083cc0:  1b 00 00 40  sethi  %hi(0x10000), %o5
a0083cc4:  c2 02 e1 e4  ld  [ %o3 + 0x1e4 ], %g1
a0083cc8:  1b 00 00 80  sethi  %hi(0x20000), %o5
a0083ccc:  82 10 40 0d  or  %g1, %o5, %g1
a0083cd0:  c2 22 e1 e4  st  %g1, [ %o3 + 0x1e4 ]
a0083cd4:  80 8d 20 80  btst  0x80, %l4
a0083cd8:  02 80 00 0b  be  0xa0083d04
a0083cdc:  17 2a 01 e2  sethi  %hi(0xa8078800), %o3
a0083ce0:  9a 0b 20 3f  and  %o4, 0x3f, %o5
a0083ce4:  d8 02 e1 e4  ld  [ %o3 + 0x1e4 ], %o4
a0083ce8:  03 00 01 00  sethi  %hi(0x40000), %g1
a0083cec:  98 13 00 01  or  %o4, %g1, %o4
a0083cf0:  03 33 c0 68  sethi  %hi(0xcf01a000), %g1
a0083cf4:  9a 13 60 80  or  %o5, 0x80, %o5
a0083cf8:  82 10 60 84  or  %g1, 0x84, %g1
a0083cfc:  da 20 40 00  st  %o5, [ %g1 ]
a0083d00:  d8 22 e1 e4  st  %o4, [ %o3 + 0x1e4 ]
a0083d04:  7f ff b1 c0  call  0xa0070404
a0083d08:  01 00 00 00  nop
a0083d0c:  80 8a 20 ff  btst  0xff, %o0
a0083d10:  02 80 00 1f  be  0xa0083d8c
a0083d14:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083d18:  c2 0b 61 e8  ldub  [ %o5 + 0x1e8 ], %g1	! 0xa80789e8
a0083d1c:  80 a0 60 00  cmp  %g1, 0
a0083d20:  12 80 00 0c  bne  0xa0083d50
a0083d24:  80 a0 60 01  cmp  %g1, 1
a0083d28:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0083d2c:  c2 08 61 e0  ldub  [ %g1 + 0x1e0 ], %g1	! 0xa80789e0
a0083d30:  80 88 60 01  btst  1, %g1
a0083d34:  22 80 00 06  be,a   0xa0083d4c
a0083d38:  c2 0b 61 e8  ldub  [ %o5 + 0x1e8 ], %g1
a0083d3c:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083d40:  c2 03 61 e4  ld  [ %o5 + 0x1e4 ], %g1	! 0xa80789e4
a0083d44:  10 80 00 0c  b  0xa0083d74
a0083d48:  82 10 62 00  or  %g1, 0x200, %g1
a0083d4c:  80 a0 60 01  cmp  %g1, 1
a0083d50:  12 80 00 0b  bne  0xa0083d7c
a0083d54:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0083d58:  c2 08 61 e0  ldub  [ %g1 + 0x1e0 ], %g1	! 0xa80789e0
a0083d5c:  80 88 60 01  btst  1, %g1
a0083d60:  12 80 00 07  bne  0xa0083d7c
a0083d64:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0083d68:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083d6c:  c2 03 61 e4  ld  [ %o5 + 0x1e4 ], %g1	! 0xa80789e4
a0083d70:  82 10 64 00  or  %g1, 0x400, %g1
a0083d74:  c2 23 61 e4  st  %g1, [ %o5 + 0x1e4 ]
a0083d78:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0083d7c:  c2 08 61 e0  ldub  [ %g1 + 0x1e0 ], %g1	! 0xa80789e0
a0083d80:  82 08 60 01  and  %g1, 1, %g1
a0083d84:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083d88:  c2 2b 61 e8  stb  %g1, [ %o5 + 0x1e8 ]	! 0xa80789e8
a0083d8c:  7f ff b1 a2  call  0xa0070414
a0083d90:  01 00 00 00  nop
a0083d94:  80 8a 20 ff  btst  0xff, %o0
a0083d98:  02 80 00 22  be  0xa0083e20
a0083d9c:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083da0:  c2 0b 61 e9  ldub  [ %o5 + 0x1e9 ], %g1	! 0xa80789e9
a0083da4:  80 a0 60 00  cmp  %g1, 0
a0083da8:  12 80 00 0d  bne  0xa0083ddc
a0083dac:  80 a0 60 01  cmp  %g1, 1
a0083db0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0083db4:  c2 08 61 e0  ldub  [ %g1 + 0x1e0 ], %g1	! 0xa80789e0
a0083db8:  80 88 60 02  btst  2, %g1
a0083dbc:  02 80 00 07  be  0xa0083dd8
a0083dc0:  c2 0b 61 e9  ldub  [ %o5 + 0x1e9 ], %g1
a0083dc4:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083dc8:  c2 03 61 e4  ld  [ %o5 + 0x1e4 ], %g1	! 0xa80789e4
a0083dcc:  82 10 68 00  or  %g1, 0x800, %g1
a0083dd0:  10 80 00 0e  b  0xa0083e08
a0083dd4:  c2 23 61 e4  st  %g1, [ %o5 + 0x1e4 ]
a0083dd8:  80 a0 60 01  cmp  %g1, 1
a0083ddc:  12 80 00 0c  bne  0xa0083e0c
a0083de0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0083de4:  c2 08 61 e0  ldub  [ %g1 + 0x1e0 ], %g1	! 0xa80789e0
a0083de8:  80 88 60 02  btst  2, %g1
a0083dec:  12 80 00 08  bne  0xa0083e0c
a0083df0:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0083df4:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0083df8:  da 00 61 e4  ld  [ %g1 + 0x1e4 ], %o5	! 0xa80789e4
a0083dfc:  19 00 00 04  sethi  %hi(0x1000), %o4
a0083e00:  9a 13 40 0c  or  %o5, %o4, %o5
a0083e04:  da 20 61 e4  st  %o5, [ %g1 + 0x1e4 ]
a0083e08:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a0083e0c:  c2 08 61 e0  ldub  [ %g1 + 0x1e0 ], %g1	! 0xa80789e0
a0083e10:  83 30 60 01  srl  %g1, 1, %g1
a0083e14:  82 08 60 01  and  %g1, 1, %g1
a0083e18:  1b 2a 01 e2  sethi  %hi(0xa8078800), %o5
a0083e1c:  c2 2b 61 e9  stb  %g1, [ %o5 + 0x1e9 ]	! 0xa80789e9
a0083e20:  81 c7 e0 08  ret
a0083e24:  81 e8 00 00  restore
