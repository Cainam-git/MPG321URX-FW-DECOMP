# leon2m FUN_a00b2a1c 0xa00b2a1c-0xa00b2c18 (508 bytes)
a00b2a1c:  9d e3 bf 98  save  %sp, -104, %sp
a00b2a20:  21 2a 00 b3  sethi  %hi(0xa802cc00), %l0
a00b2a24:  96 14 23 f4  or  %l0, 0x3f4, %o3	! 0xa802cff4
a00b2a28:  c2 12 e0 12  lduh  [ %o3 + 0x12 ], %g1
a00b2a2c:  80 a0 60 05  cmp  %g1, 5
a00b2a30:  02 80 00 33  be  0xa00b2afc
a00b2a34:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00b2a38:  98 14 23 f4  or  %l0, 0x3f4, %o4
a00b2a3c:  d6 13 20 10  lduh  [ %o4 + 0x10 ], %o3
a00b2a40:  80 a2 e0 04  cmp  %o3, 4
a00b2a44:  02 80 00 3a  be  0xa00b2b2c
a00b2a48:  a2 12 a2 90  or  %o2, 0x290, %l1
a00b2a4c:  9a 12 a2 90  or  %o2, 0x290, %o5
a00b2a50:  d8 0b 61 e4  ldub  [ %o5 + 0x1e4 ], %o4
a00b2a54:  80 a3 20 01  cmp  %o4, 1
a00b2a58:  02 80 00 6e  be  0xa00b2c10
a00b2a5c:  01 00 00 00  nop
a00b2a60:  d0 0b 61 e5  ldub  [ %o5 + 0x1e5 ], %o0
a00b2a64:  80 a2 20 01  cmp  %o0, 1
a00b2a68:  02 80 00 6a  be  0xa00b2c10
a00b2a6c:  9a 14 23 f4  or  %l0, 0x3f4, %o5
a00b2a70:  d2 0b 60 3f  ldub  [ %o5 + 0x3f ], %o1
a00b2a74:  80 a2 60 00  cmp  %o1, 0
a00b2a78:  22 80 00 37  be,a   0xa00b2b54
a00b2a7c:  e2 13 60 18  lduh  [ %o5 + 0x18 ], %l1
a00b2a80:  de 13 60 18  lduh  [ %o5 + 0x18 ], %o7
a00b2a84:  23 3f ff e0  sethi  %hi(0xffff8000), %l1
a00b2a88:  96 0b c0 11  and  %o7, %l1, %o3
a00b2a8c:  9b 2a e0 10  sll  %o3, 0x10, %o5
a00b2a90:  80 a3 60 00  cmp  %o5, 0
a00b2a94:  12 80 00 52  bne  0xa00b2bdc
a00b2a98:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00b2a9c:  d8 0c 60 55  ldub  [ %l1 + 0x55 ], %o4	! 0xa8025c55
a00b2aa0:  82 03 20 02  add  %o4, 2, %g1
a00b2aa4:  90 12 a2 90  or  %o2, 0x290, %o0
a00b2aa8:  92 08 60 03  and  %g1, 3, %o1
a00b2aac:  d4 0a 21 e2  ldub  [ %o0 + 0x1e2 ], %o2
a00b2ab0:  80 a2 a0 02  cmp  %o2, 2
a00b2ab4:  08 80 00 06  bleu  0xa00b2acc
a00b2ab8:  d2 2c 60 55  stb  %o1, [ %l1 + 0x55 ]
a00b2abc:  c2 0c 60 55  ldub  [ %l1 + 0x55 ], %g1
a00b2ac0:  80 a0 60 01  cmp  %g1, 1
a00b2ac4:  02 80 00 4f  be  0xa00b2c00
a00b2ac8:  9a 00 7f ff  add  %g1, -1, %o5
a00b2acc:  90 10 20 03  mov  3, %o0
a00b2ad0:  d2 0c 60 55  ldub  [ %l1 + 0x55 ], %o1
a00b2ad4:  7f ff f7 0f  call  0xa00b0710
a00b2ad8:  01 00 00 00  nop
a00b2adc:  da 0c 60 55  ldub  [ %l1 + 0x55 ], %o5
a00b2ae0:  90 03 7f fe  add  %o5, -2, %o0
a00b2ae4:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00b2ae8:  80 a4 60 01  cmp  %l1, 1
a00b2aec:  08 80 00 49  bleu  0xa00b2c10
a00b2af0:  96 14 23 f4  or  %l0, 0x3f4, %o3
a00b2af4:  10 80 00 33  b  0xa00b2bc0
a00b2af8:  d8 12 e0 0e  lduh  [ %o3 + 0xe ], %o4
a00b2afc:  90 12 a2 90  or  %o2, 0x290, %o0
a00b2b00:  d8 02 21 dc  ld  [ %o0 + 0x1dc ], %o4
a00b2b04:  1b 10 00 00  sethi  %hi(0x40000000), %o5
a00b2b08:  80 8b 00 0d  btst  %o4, %o5
a00b2b0c:  02 bf ff cc  be  0xa00b2a3c
a00b2b10:  98 14 23 f4  or  %l0, 0x3f4, %o4
a00b2b14:  d2 0a e0 3f  ldub  [ %o3 + 0x3f ], %o1
a00b2b18:  80 a2 60 00  cmp  %o1, 0
a00b2b1c:  02 80 00 3d  be  0xa00b2c10
a00b2b20:  01 00 00 00  nop
a00b2b24:  10 bf ff c7  b  0xa00b2a40
a00b2b28:  d6 13 20 10  lduh  [ %o4 + 0x10 ], %o3
a00b2b2c:  de 04 61 dc  ld  [ %l1 + 0x1dc ], %o7
a00b2b30:  80 a3 e0 00  cmp  %o7, 0
a00b2b34:  16 bf ff c7  bge  0xa00b2a50
a00b2b38:  9a 12 a2 90  or  %o2, 0x290, %o5
a00b2b3c:  c2 0b 20 3f  ldub  [ %o4 + 0x3f ], %g1
a00b2b40:  80 a0 60 00  cmp  %g1, 0
a00b2b44:  02 80 00 33  be  0xa00b2c10
a00b2b48:  01 00 00 00  nop
a00b2b4c:  10 bf ff c2  b  0xa00b2a54
a00b2b50:  d8 0b 61 e4  ldub  [ %o5 + 0x1e4 ], %o4
a00b2b54:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00b2b58:  9e 0c 40 01  and  %l1, %g1, %o7
a00b2b5c:  97 2b e0 10  sll  %o7, 0x10, %o3
a00b2b60:  80 a2 e0 00  cmp  %o3, 0
a00b2b64:  02 80 00 21  be  0xa00b2be8
a00b2b68:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a00b2b6c:  d2 0c 60 55  ldub  [ %l1 + 0x55 ], %o1	! 0xa8025c55
a00b2b70:  03 15 55 55  sethi  %hi(0x55555400), %g1
a00b2b74:  94 02 60 01  add  %o1, 1, %o2
a00b2b78:  9e 10 61 56  or  %g1, 0x156, %o7
a00b2b7c:  80 5a 80 0f  smul  %o2, %o7, %g0
a00b2b80:  9b 40 00 00  rd  %y, %o5
a00b2b84:  96 03 40 0d  add  %o5, %o5, %o3
a00b2b88:  90 02 c0 0d  add  %o3, %o5, %o0
a00b2b8c:  98 22 80 08  sub  %o2, %o0, %o4
a00b2b90:  d8 2c 60 55  stb  %o4, [ %l1 + 0x55 ]
a00b2b94:  92 0b 20 ff  and  %o4, 0xff, %o1
a00b2b98:  90 10 20 02  mov  2, %o0
a00b2b9c:  7f ff f6 dd  call  0xa00b0710
a00b2ba0:  01 00 00 00  nop
a00b2ba4:  da 0c 60 55  ldub  [ %l1 + 0x55 ], %o5
a00b2ba8:  90 03 7f fe  add  %o5, -2, %o0
a00b2bac:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00b2bb0:  80 a4 60 01  cmp  %l1, 1
a00b2bb4:  08 80 00 17  bleu  0xa00b2c10
a00b2bb8:  96 14 23 f4  or  %l0, 0x3f4, %o3
a00b2bbc:  d8 12 e0 0e  lduh  [ %o3 + 0xe ], %o4
a00b2bc0:  92 0b 60 ff  and  %o5, 0xff, %o1
a00b2bc4:  03 3f ff e0  sethi  %hi(0xffff8000), %g1
a00b2bc8:  9e 2b 00 01  andn  %o4, %g1, %o7
a00b2bcc:  9b 2a 60 0f  sll  %o1, 0xf, %o5
a00b2bd0:  a0 13 c0 0d  or  %o7, %o5, %l0
a00b2bd4:  10 80 00 0f  b  0xa00b2c10
a00b2bd8:  e0 32 e0 0e  sth  %l0, [ %o3 + 0xe ]
a00b2bdc:  c2 0c 60 55  ldub  [ %l1 + 0x55 ], %g1
a00b2be0:  10 bf ff b1  b  0xa00b2aa4
a00b2be4:  82 00 60 03  add  %g1, 3, %g1
a00b2be8:  d4 0c 60 55  ldub  [ %l1 + 0x55 ], %o2
a00b2bec:  98 02 a0 01  add  %o2, 1, %o4
a00b2bf0:  92 0b 20 01  and  %o4, 1, %o1
a00b2bf4:  d2 2c 60 55  stb  %o1, [ %l1 + 0x55 ]
a00b2bf8:  10 bf ff e9  b  0xa00b2b9c
a00b2bfc:  90 10 20 01  mov  1, %o0
a00b2c00:  da 2c 60 55  stb  %o5, [ %l1 + 0x55 ]
a00b2c04:  90 10 20 03  mov  3, %o0
a00b2c08:  10 bf ff b3  b  0xa00b2ad4
a00b2c0c:  d2 0c 60 55  ldub  [ %l1 + 0x55 ], %o1
a00b2c10:  81 c7 e0 08  ret
a00b2c14:  81 e8 00 00  restore
