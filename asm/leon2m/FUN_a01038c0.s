# leon2m FUN_a01038c0 0xa01038c0-0xa01042c8 (2568 bytes)
a01038c0:  9d e3 bf 48  save  %sp, -184, %sp
a01038c4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01038c8:  e6 0f a0 5f  ldub  [ %fp + 0x5f ], %l3
a01038cc:  40 00 76 63  call  0xa0121258
a01038d0:  90 10 00 18  mov  %i0, %o0
a01038d4:  c2 17 00 00  lduh  [ %i4 ], %g1
a01038d8:  da 17 20 0a  lduh  [ %i4 + 0xa ], %o5
a01038dc:  c2 37 bf ec  sth  %g1, [ %fp + -20 ]
a01038e0:  80 8a 20 ff  btst  0xff, %o0
a01038e4:  12 80 01 ad  bne  0xa0103f98
a01038e8:  da 37 bf f2  sth  %o5, [ %fp + -14 ]
a01038ec:  80 a6 20 01  cmp  %i0, 1
a01038f0:  22 80 00 9d  be,a   0xa0103b64
a01038f4:  d0 16 e0 0c  lduh  [ %i3 + 0xc ], %o0
a01038f8:  90 10 00 18  mov  %i0, %o0
a01038fc:  7f ff bb 83  call  0xa00f2708
a0103900:  92 10 20 82  mov  0x82, %o1
a0103904:  a9 2a 20 10  sll  %o0, 0x10, %l4
a0103908:  de 17 bf ec  lduh  [ %fp + -20 ], %o7
a010390c:  a5 35 20 10  srl  %l4, 0x10, %l2
a0103910:  a2 24 80 0f  sub  %l2, %o7, %l1
a0103914:  a0 04 60 04  add  %l1, 4, %l0
a0103918:  80 a4 20 08  cmp  %l0, 8
a010391c:  18 80 00 04  bgu  0xa010392c
a0103920:  96 10 00 0f  mov  %o7, %o3
a0103924:  96 10 00 08  mov  %o0, %o3
a0103928:  d0 37 bf ec  sth  %o0, [ %fp + -20 ]
a010392c:  d8 1f 20 18  ldd  [ %i4 + 0x18 ], %o4
a0103930:  95 2a e0 10  sll  %o3, 0x10, %o2
a0103934:  82 5b 20 64  smul  %o4, 0x64, %g1
a0103938:  92 53 60 64  umul  %o5, 0x64, %o1
a010393c:  91 40 00 00  rd  %y, %o0
a0103940:  ad 32 a0 10  srl  %o2, 0x10, %l6
a0103944:  90 00 40 08  add  %g1, %o0, %o0
a0103948:  94 10 20 00  clr  %o2
a010394c:  40 01 46 2f  call  0xa0155208
a0103950:  96 10 00 16  mov  %l6, %o3
a0103954:  ea 16 e0 02  lduh  [ %i3 + 2 ], %l5
a0103958:  94 10 20 00  clr  %o2
a010395c:  40 01 46 2b  call  0xa0155208
a0103960:  96 10 00 15  mov  %l5, %o3
a0103964:  92 82 60 05  addcc  %o1, 5, %o1
a0103968:  90 42 20 00  addx  %o0, 0, %o0
a010396c:  94 10 20 00  clr  %o2
a0103970:  40 01 46 26  call  0xa0155208
a0103974:  96 10 20 0a  mov  0xa, %o3
a0103978:  d2 37 bf ee  sth  %o1, [ %fp + -18 ]
a010397c:  92 10 20 62  mov  0x62, %o1
a0103980:  7f ff bb 1e  call  0xa00f25f8
a0103984:  90 10 00 18  mov  %i0, %o0
a0103988:  a0 10 00 08  mov  %o0, %l0
a010398c:  92 10 20 64  mov  0x64, %o1
a0103990:  7f ff bb 1a  call  0xa00f25f8
a0103994:  90 10 00 18  mov  %i0, %o0
a0103998:  b4 0e a0 ff  and  %i2, 0xff, %i2
a010399c:  80 a6 a0 00  cmp  %i2, 0
a01039a0:  02 80 00 8a  be  0xa0103bc8
a01039a4:  92 10 00 08  mov  %o0, %o1
a01039a8:  23 2a 00 b5  sethi  %hi(0xa802d400), %l1
a01039ac:  d6 04 62 a4  ld  [ %l1 + 0x2a4 ], %o3	! 0xa802d6a4
a01039b0:  e4 12 e0 30  lduh  [ %o3 + 0x30 ], %l2
a01039b4:  e8 12 e0 32  lduh  [ %o3 + 0x32 ], %l4
a01039b8:  d8 12 e0 0a  lduh  [ %o3 + 0xa ], %o4
a01039bc:  9e 04 80 14  add  %l2, %l4, %o7
a01039c0:  90 03 c0 0c  add  %o7, %o4, %o0
a01039c4:  da 17 bf ee  lduh  [ %fp + -18 ], %o5
a01039c8:  80 a3 40 08  cmp  %o5, %o0
a01039cc:  90 10 00 0d  mov  %o5, %o0
a01039d0:  d8 12 e0 30  lduh  [ %o3 + 0x30 ], %o4
a01039d4:  c2 12 e0 32  lduh  [ %o3 + 0x32 ], %g1
a01039d8:  14 80 00 7e  bg  0xa0103bd0
a01039dc:  da 12 e0 0a  lduh  [ %o3 + 0xa ], %o5
a01039e0:  ac 03 00 01  add  %o4, %g1, %l6
a01039e4:  aa 05 80 0d  add  %l6, %o5, %l5
a01039e8:  a0 05 60 01  add  %l5, 1, %l0
a01039ec:  e0 37 bf ee  sth  %l0, [ %fp + -18 ]
a01039f0:  90 10 00 10  mov  %l0, %o0
a01039f4:  95 2a 60 10  sll  %o1, 0x10, %o2
a01039f8:  a9 32 a0 10  srl  %o2, 0x10, %l4
a01039fc:  d6 04 62 a4  ld  [ %l1 + 0x2a4 ], %o3
a0103a00:  d4 12 e0 0a  lduh  [ %o3 + 0xa ], %o2
a0103a04:  80 a2 80 14  cmp  %o2, %l4
a0103a08:  02 80 00 85  be  0xa0103c1c
a0103a0c:  a1 2a 20 10  sll  %o0, 0x10, %l0
a0103a10:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0103a14:  95 33 e0 10  srl  %o7, 0x10, %o2
a0103a18:  90 10 00 18  mov  %i0, %o0
a0103a1c:  7f ff ba 9b  call  0xa00f2488
a0103a20:  92 10 20 5b  mov  0x5b, %o1
a0103a24:  da 07 20 20  ld  [ %i4 + 0x20 ], %o5
a0103a28:  17 00 04 00  sethi  %hi(0x100000), %o3
a0103a2c:  80 8b 40 0b  btst  %o5, %o3
a0103a30:  12 80 00 b3  bne  0xa0103cfc
a0103a34:  d2 04 62 a4  ld  [ %l1 + 0x2a4 ], %o1
a0103a38:  90 10 00 18  mov  %i0, %o0
a0103a3c:  92 10 20 5e  mov  0x5e, %o1
a0103a40:  7f ff ba 92  call  0xa00f2488
a0103a44:  d4 17 bf ec  lduh  [ %fp + -20 ], %o2
a0103a48:  a4 07 bf a8  add  %fp, -88, %l2
a0103a4c:  92 10 00 1b  mov  %i3, %o1
a0103a50:  94 10 20 3c  mov  0x3c, %o2
a0103a54:  40 00 e3 af  call  0xa013c910
a0103a58:  90 10 00 12  mov  %l2, %o0
a0103a5c:  90 10 00 18  mov  %i0, %o0
a0103a60:  92 10 20 53  mov  0x53, %o1
a0103a64:  94 10 20 f0  mov  0xf0, %o2
a0103a68:  7f ff ba 31  call  0xa00f232c
a0103a6c:  96 10 20 00  clr  %o3
a0103a70:  80 a6 20 03  cmp  %i0, 3
a0103a74:  08 80 00 91  bleu  0xa0103cb8
a0103a78:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a0103a7c:  40 00 75 f7  call  0xa0121258
a0103a80:  90 10 00 18  mov  %i0, %o0
a0103a84:  80 8a 20 ff  btst  0xff, %o0
a0103a88:  02 80 00 73  be  0xa0103c54
a0103a8c:  96 10 20 01  mov  1, %o3
a0103a90:  94 10 20 40  mov  0x40, %o2
a0103a94:  90 10 00 18  mov  %i0, %o0
a0103a98:  7f ff ba 25  call  0xa00f232c
a0103a9c:  92 10 20 50  mov  0x50, %o1
a0103aa0:  92 10 20 7c  mov  0x7c, %o1
a0103aa4:  7f ff b9 ec  call  0xa00f2254
a0103aa8:  90 10 00 18  mov  %i0, %o0
a0103aac:  a8 0a 20 ff  and  %o0, 0xff, %l4
a0103ab0:  93 35 20 04  srl  %l4, 4, %o1
a0103ab4:  a2 02 60 03  add  %o1, 3, %l1
a0103ab8:  92 10 20 55  mov  0x55, %o1
a0103abc:  7f ff b9 e6  call  0xa00f2254
a0103ac0:  90 10 00 18  mov  %i0, %o0
a0103ac4:  98 0a 3f f0  and  %o0, -16, %o4
a0103ac8:  9e 14 40 0c  or  %l1, %o4, %o7
a0103acc:  9a 13 ff 80  or  %o7, -128, %o5
a0103ad0:  94 0b 60 ff  and  %o5, 0xff, %o2
a0103ad4:  90 10 00 18  mov  %i0, %o0
a0103ad8:  7f ff b9 f0  call  0xa00f2298
a0103adc:  92 10 20 55  mov  0x55, %o1
a0103ae0:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a0103ae4:  82 13 62 6c  or  %o5, 0x26c, %g1	! 0xcf01166c
a0103ae8:  d6 00 40 00  ld  [ %g1 ], %o3
a0103aec:  90 0a e0 03  and  %o3, 3, %o0
a0103af0:  80 a6 00 08  cmp  %i0, %o0
a0103af4:  32 80 00 06  bne,a   0xa0103b0c
a0103af8:  92 10 00 1b  mov  %i3, %o1
a0103afc:  80 a4 e0 00  cmp  %l3, 0
a0103b00:  32 80 00 0c  bne,a   0xa0103b30
a0103b04:  c2 16 e0 10  lduh  [ %i3 + 0x10 ], %g1
a0103b08:  92 10 00 1b  mov  %i3, %o1
a0103b0c:  94 10 20 3c  mov  0x3c, %o2
a0103b10:  40 00 e3 80  call  0xa013c910
a0103b14:  90 10 00 12  mov  %l2, %o0
a0103b18:  40 00 75 d0  call  0xa0121258
a0103b1c:  90 10 00 18  mov  %i0, %o0
a0103b20:  80 8a 20 ff  btst  0xff, %o0
a0103b24:  12 80 00 90  bne  0xa0103d64
a0103b28:  92 10 20 54  mov  0x54, %o1
a0103b2c:  c2 16 e0 10  lduh  [ %i3 + 0x10 ], %g1
a0103b30:  de 17 20 04  lduh  [ %i4 + 4 ], %o7
a0103b34:  80 a0 40 0f  cmp  %g1, %o7
a0103b38:  12 80 00 07  bne  0xa0103b54
a0103b3c:  90 10 00 18  mov  %i0, %o0
a0103b40:  e4 16 e0 12  lduh  [ %i3 + 0x12 ], %l2
a0103b44:  f6 17 20 0c  lduh  [ %i4 + 0xc ], %i3
a0103b48:  80 a4 80 1b  cmp  %l2, %i3
a0103b4c:  22 80 01 1c  be,a   0xa0103fbc
a0103b50:  92 10 20 90  mov  0x90, %o1
a0103b54:  92 10 20 90  mov  0x90, %o1
a0103b58:  94 10 20 20  mov  0x20, %o2
a0103b5c:  10 80 01 d6  b  0xa01042b4
a0103b60:  96 10 20 01  mov  1, %o3
a0103b64:  80 a2 2f 00  cmp  %o0, 0xf00
a0103b68:  32 bf ff 65  bne,a   0xa01038fc
a0103b6c:  90 10 00 18  mov  %i0, %o0
a0103b70:  d2 16 e0 0e  lduh  [ %i3 + 0xe ], %o1
a0103b74:  80 a2 68 70  cmp  %o1, 0x870
a0103b78:  32 bf ff 61  bne,a   0xa01038fc
a0103b7c:  90 10 00 18  mov  %i0, %o0
a0103b80:  d4 16 e0 10  lduh  [ %i3 + 0x10 ], %o2
a0103b84:  80 a2 a1 08  cmp  %o2, 0x108
a0103b88:  32 bf ff 5d  bne,a   0xa01038fc
a0103b8c:  90 10 00 18  mov  %i0, %o0
a0103b90:  d6 16 e0 12  lduh  [ %i3 + 0x12 ], %o3
a0103b94:  80 a2 e1 0e  cmp  %o3, 0x10e
a0103b98:  32 bf ff 59  bne,a   0xa01038fc
a0103b9c:  90 10 00 18  mov  %i0, %o0
a0103ba0:  d8 16 e0 02  lduh  [ %i3 + 2 ], %o4
a0103ba4:  80 a3 26 40  cmp  %o4, 0x640
a0103ba8:  28 bf ff 55  bleu,a   0xa01038fc
a0103bac:  90 10 00 18  mov  %i0, %o0
a0103bb0:  92 10 20 50  mov  0x50, %o1
a0103bb4:  7f ff b9 a8  call  0xa00f2254
a0103bb8:  90 10 20 01  mov  1, %o0
a0103bbc:  94 0a 20 df  and  %o0, 0xdf, %o2
a0103bc0:  10 80 00 fb  b  0xa0103fac
a0103bc4:  90 10 20 01  mov  1, %o0
a0103bc8:  d0 17 bf ee  lduh  [ %fp + -18 ], %o0
a0103bcc:  23 2a 00 b5  sethi  %hi(0xa802d400), %l1
a0103bd0:  a5 2c 20 10  sll  %l0, 0x10, %l2
a0103bd4:  95 2a 60 10  sll  %o1, 0x10, %o2
a0103bd8:  9f 34 a0 10  srl  %l2, 0x10, %o7
a0103bdc:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0103be0:  99 32 a0 10  srl  %o2, 0x10, %o4
a0103be4:  82 03 c0 0c  add  %o7, %o4, %g1
a0103be8:  97 33 60 10  srl  %o5, 0x10, %o3
a0103bec:  80 a2 c0 01  cmp  %o3, %g1
a0103bf0:  14 bf ff 83  bg  0xa01039fc
a0103bf4:  a9 32 a0 10  srl  %o2, 0x10, %l4
a0103bf8:  90 04 00 09  add  %l0, %o1, %o0
a0103bfc:  92 02 20 10  add  %o0, 0x10, %o1
a0103c00:  d2 37 bf ee  sth  %o1, [ %fp + -18 ]
a0103c04:  d6 04 62 a4  ld  [ %l1 + 0x2a4 ], %o3
a0103c08:  d4 12 e0 0a  lduh  [ %o3 + 0xa ], %o2
a0103c0c:  80 a2 80 14  cmp  %o2, %l4
a0103c10:  12 bf ff 80  bne  0xa0103a10
a0103c14:  90 10 00 09  mov  %o1, %o0
a0103c18:  a1 2a 20 10  sll  %o0, 0x10, %l0
a0103c1c:  95 34 20 10  srl  %l0, 0x10, %o2
a0103c20:  d6 12 e0 2a  lduh  [ %o3 + 0x2a ], %o3
a0103c24:  80 a2 80 0b  cmp  %o2, %o3
a0103c28:  1a bf ff 7b  bcc  0xa0103a14
a0103c2c:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0103c30:  03 00 06 6a  sethi  %hi(0x19a800), %g1
a0103c34:  90 10 60 58  or  %g1, 0x58, %o0	! 0x19a858
a0103c38:  7f ff 6d 4e  call  0xa00df170
a0103c3c:  92 10 00 18  mov  %i0, %o1
a0103c40:  ec 04 62 a4  ld  [ %l1 + 0x2a4 ], %l6
a0103c44:  ea 15 a0 2a  lduh  [ %l6 + 0x2a ], %l5
a0103c48:  ea 37 bf ee  sth  %l5, [ %fp + -18 ]
a0103c4c:  10 bf ff 71  b  0xa0103a10
a0103c50:  90 10 00 15  mov  %l5, %o0
a0103c54:  94 10 20 40  mov  0x40, %o2
a0103c58:  90 10 00 18  mov  %i0, %o0
a0103c5c:  7f ff b9 b4  call  0xa00f232c
a0103c60:  92 10 20 50  mov  0x50, %o1
a0103c64:  90 10 00 18  mov  %i0, %o0
a0103c68:  7f ff b9 7b  call  0xa00f2254
a0103c6c:  92 10 20 7c  mov  0x7c, %o1
a0103c70:  ac 0a 20 ff  and  %o0, 0xff, %l6
a0103c74:  92 10 20 55  mov  0x55, %o1
a0103c78:  7f ff b9 77  call  0xa00f2254
a0103c7c:  90 10 00 18  mov  %i0, %o0
a0103c80:  a1 35 a0 04  srl  %l6, 4, %l0
a0103c84:  aa 04 20 03  add  %l0, 3, %l5
a0103c88:  94 0a 20 f0  and  %o0, 0xf0, %o2
a0103c8c:  94 12 80 15  or  %o2, %l5, %o2
a0103c90:  90 10 00 18  mov  %i0, %o0
a0103c94:  7f ff b9 81  call  0xa00f2298
a0103c98:  92 10 20 55  mov  0x55, %o1
a0103c9c:  90 10 00 18  mov  %i0, %o0
a0103ca0:  92 10 20 55  mov  0x55, %o1
a0103ca4:  94 10 20 80  mov  0x80, %o2
a0103ca8:  7f ff b9 a1  call  0xa00f232c
a0103cac:  96 10 20 00  clr  %o3
a0103cb0:  10 bf ff 8d  b  0xa0103ae4
a0103cb4:  1b 33 c0 45  sethi  %hi(0xcf011400), %o5
a0103cb8:  a0 12 e2 80  or  %o3, 0x280, %l0
a0103cbc:  92 10 20 7c  mov  0x7c, %o1
a0103cc0:  7f ff b9 65  call  0xa00f2254
a0103cc4:  90 10 00 18  mov  %i0, %o0
a0103cc8:  82 0a 20 ff  and  %o0, 0xff, %g1
a0103ccc:  91 30 60 04  srl  %g1, 4, %o0
a0103cd0:  ac 06 00 10  add  %i0, %l0, %l6
a0103cd4:  d0 2d a0 15  stb  %o0, [ %l6 + 0x15 ]
a0103cd8:  90 10 00 18  mov  %i0, %o0
a0103cdc:  7f ff ba 8b  call  0xa00f2708
a0103ce0:  92 10 20 77  mov  0x77, %o1
a0103ce4:  aa 06 00 18  add  %i0, %i0, %l5
a0103ce8:  15 3f ff e0  sethi  %hi(0xffff8000), %o2
a0103cec:  a2 05 40 10  add  %l5, %l0, %l1
a0103cf0:  a8 2a 00 0a  andn  %o0, %o2, %l4
a0103cf4:  10 bf ff 62  b  0xa0103a7c
a0103cf8:  e8 34 60 1a  sth  %l4, [ %l1 + 0x1a ]
a0103cfc:  e4 12 60 32  lduh  [ %o1 + 0x32 ], %l2
a0103d00:  d8 12 60 30  lduh  [ %o1 + 0x30 ], %o4
a0103d04:  9e 03 00 12  add  %o4, %l2, %o7
a0103d08:  9b 2b e0 10  sll  %o7, 0x10, %o5
a0103d0c:  95 33 60 10  srl  %o5, 0x10, %o2
a0103d10:  90 10 00 18  mov  %i0, %o0
a0103d14:  7f ff b9 dd  call  0xa00f2488
a0103d18:  92 10 20 62  mov  0x62, %o1
a0103d1c:  e0 04 62 a4  ld  [ %l1 + 0x2a4 ], %l0
a0103d20:  c2 14 20 0a  lduh  [ %l0 + 0xa ], %g1
a0103d24:  d6 17 bf f2  lduh  [ %fp + -14 ], %o3
a0103d28:  aa 20 40 0b  sub  %g1, %o3, %l5
a0103d2c:  ad 35 60 1f  srl  %l5, 0x1f, %l6
a0103d30:  90 05 40 16  add  %l5, %l6, %o0
a0103d34:  d4 14 20 32  lduh  [ %l0 + 0x32 ], %o2
a0103d38:  e8 14 20 30  lduh  [ %l0 + 0x30 ], %l4
a0103d3c:  a4 05 00 0a  add  %l4, %o2, %l2
a0103d40:  93 3a 20 01  sra  %o0, 1, %o1
a0103d44:  98 04 80 09  add  %l2, %o1, %o4
a0103d48:  a3 2b 20 10  sll  %o4, 0x10, %l1
a0103d4c:  95 34 60 10  srl  %l1, 0x10, %o2
a0103d50:  90 10 00 18  mov  %i0, %o0
a0103d54:  7f ff b9 cd  call  0xa00f2488
a0103d58:  92 10 20 6f  mov  0x6f, %o1
a0103d5c:  10 bf ff 38  b  0xa0103a3c
a0103d60:  90 10 00 18  mov  %i0, %o0
a0103d64:  7f ff b9 3c  call  0xa00f2254
a0103d68:  90 10 00 18  mov  %i0, %o0
a0103d6c:  aa 10 00 08  mov  %o0, %l5
a0103d70:  92 10 20 50  mov  0x50, %o1
a0103d74:  7f ff b9 38  call  0xa00f2254
a0103d78:  90 10 00 18  mov  %i0, %o0
a0103d7c:  a8 10 00 08  mov  %o0, %l4
a0103d80:  90 10 00 18  mov  %i0, %o0
a0103d84:  7f ff b9 34  call  0xa00f2254
a0103d88:  92 10 20 88  mov  0x88, %o1
a0103d8c:  80 a6 a0 00  cmp  %i2, 0
a0103d90:  12 80 00 74  bne  0xa0103f60
a0103d94:  ac 10 00 08  mov  %o0, %l6
a0103d98:  90 10 00 18  mov  %i0, %o0
a0103d9c:  92 10 20 54  mov  0x54, %o1
a0103da0:  7f ff b9 3e  call  0xa00f2298
a0103da4:  94 10 20 00  clr  %o2
a0103da8:  1f 33 c0 4a  sethi  %hi(0xcf012800), %o7
a0103dac:  a2 13 e0 90  or  %o7, 0x90, %l1	! 0xcf012890
a0103db0:  e4 04 40 00  ld  [ %l1 ], %l2
a0103db4:  d2 04 40 00  ld  [ %l1 ], %o1
a0103db8:  98 0a 7f fe  and  %o1, -2, %o4
a0103dbc:  d8 24 40 00  st  %o4, [ %l1 ]
a0103dc0:  9a 13 e1 90  or  %o7, 0x190, %o5
a0103dc4:  e6 03 40 00  ld  [ %o5 ], %l3
a0103dc8:  82 0c ff fe  and  %l3, -2, %g1
a0103dcc:  c2 23 40 00  st  %g1, [ %o5 ]
a0103dd0:  90 10 00 18  mov  %i0, %o0
a0103dd4:  7f ff b7 2f  call  0xa00f1a90
a0103dd8:  92 10 20 04  mov  4, %o1
a0103ddc:  96 0a 20 0f  and  %o0, 0xf, %o3
a0103de0:  80 a2 e0 01  cmp  %o3, 1
a0103de4:  04 80 00 7f  ble  0xa0103fe0
a0103de8:  a6 10 00 12  mov  %l2, %l3
a0103dec:  90 10 00 18  mov  %i0, %o0
a0103df0:  7f ff b7 28  call  0xa00f1a90
a0103df4:  92 10 20 04  mov  4, %o1
a0103df8:  9a 0a 20 03  and  %o0, 3, %o5
a0103dfc:  80 a3 60 03  cmp  %o5, 3
a0103e00:  02 80 00 72  be  0xa0103fc8
a0103e04:  94 10 20 07  mov  7, %o2
a0103e08:  90 10 00 18  mov  %i0, %o0
a0103e0c:  7f ff b9 23  call  0xa00f2298
a0103e10:  92 10 20 6e  mov  0x6e, %o1
a0103e14:  92 10 20 0c  mov  0xc, %o1
a0103e18:  7f ff b7 b3  call  0xa00f1ce4
a0103e1c:  90 10 00 18  mov  %i0, %o0
a0103e20:  a5 2a 20 10  sll  %o0, 0x10, %l2
a0103e24:  92 10 20 0e  mov  0xe, %o1
a0103e28:  7f ff b7 af  call  0xa00f1ce4
a0103e2c:  90 10 00 18  mov  %i0, %o0
a0103e30:  95 2a 20 10  sll  %o0, 0x10, %o2
a0103e34:  a1 34 a0 10  srl  %l2, 0x10, %l0
a0103e38:  93 32 a0 10  srl  %o2, 0x10, %o1
a0103e3c:  98 24 00 09  sub  %l0, %o1, %o4
a0103e40:  83 3b 20 1f  sra  %o4, 0x1f, %g1
a0103e44:  9e 18 40 0c  xor  %g1, %o4, %o7
a0103e48:  a2 23 c0 01  sub  %o7, %g1, %l1
a0103e4c:  80 a4 60 00  cmp  %l1, 0
a0103e50:  04 80 00 ee  ble  0xa0104208
a0103e54:  90 10 00 18  mov  %i0, %o0
a0103e58:  7f ff b7 0e  call  0xa00f1a90
a0103e5c:  92 10 20 56  mov  0x56, %o1
a0103e60:  80 8a 20 01  btst  1, %o0
a0103e64:  02 80 00 d2  be  0xa01041ac
a0103e68:  96 10 20 01  mov  1, %o3
a0103e6c:  90 10 20 0a  mov  0xa, %o0
a0103e70:  40 00 77 57  call  0xa0121bcc
a0103e74:  d2 17 bf aa  lduh  [ %fp + -86 ], %o1
a0103e78:  92 10 20 dc  mov  0xdc, %o1
a0103e7c:  7f ff ba 23  call  0xa00f2708
a0103e80:  90 10 00 18  mov  %i0, %o0
a0103e84:  a2 10 00 08  mov  %o0, %l1
a0103e88:  92 10 20 de  mov  0xde, %o1
a0103e8c:  7f ff ba 1f  call  0xa00f2708
a0103e90:  90 10 00 18  mov  %i0, %o0
a0103e94:  a4 10 00 08  mov  %o0, %l2
a0103e98:  92 10 20 dc  mov  0xdc, %o1
a0103e9c:  7f ff ba 1b  call  0xa00f2708
a0103ea0:  90 10 00 18  mov  %i0, %o0
a0103ea4:  97 2a 20 10  sll  %o0, 0x10, %o3
a0103ea8:  a1 32 e0 10  srl  %o3, 0x10, %l0
a0103eac:  92 10 20 de  mov  0xde, %o1
a0103eb0:  7f ff ba 16  call  0xa00f2708
a0103eb4:  90 10 00 18  mov  %i0, %o0
a0103eb8:  95 2a 20 10  sll  %o0, 0x10, %o2
a0103ebc:  93 32 a0 10  srl  %o2, 0x10, %o1
a0103ec0:  98 24 00 09  sub  %l0, %o1, %o4
a0103ec4:  83 3b 20 1f  sra  %o4, 0x1f, %g1
a0103ec8:  9e 18 40 0c  xor  %g1, %o4, %o7
a0103ecc:  90 23 c0 01  sub  %o7, %g1, %o0
a0103ed0:  80 a2 20 01  cmp  %o0, 1
a0103ed4:  14 80 00 80  bg  0xa01040d4
a0103ed8:  94 10 20 40  mov  0x40, %o2
a0103edc:  92 0c e0 ff  and  %l3, 0xff, %o1
a0103ee0:  15 33 c0 4a  sethi  %hi(0xcf012800), %o2
a0103ee4:  a6 12 a0 90  or  %o2, 0x90, %l3	! 0xcf012890
a0103ee8:  d2 24 c0 00  st  %o1, [ %l3 ]
a0103eec:  94 0d 60 ff  and  %l5, 0xff, %o2
a0103ef0:  90 10 00 18  mov  %i0, %o0
a0103ef4:  7f ff b8 e9  call  0xa00f2298
a0103ef8:  92 10 20 54  mov  0x54, %o1
a0103efc:  90 10 00 18  mov  %i0, %o0
a0103f00:  94 0d 20 ff  and  %l4, 0xff, %o2
a0103f04:  7f ff b8 e5  call  0xa00f2298
a0103f08:  92 10 20 50  mov  0x50, %o1
a0103f0c:  90 10 00 18  mov  %i0, %o0
a0103f10:  94 0d a0 ff  and  %l6, 0xff, %o2
a0103f14:  7f ff b8 e1  call  0xa00f2298
a0103f18:  92 10 20 88  mov  0x88, %o1
a0103f1c:  80 a6 a0 00  cmp  %i2, 0
a0103f20:  22 bf ff 04  be,a   0xa0103b30
a0103f24:  c2 16 e0 10  lduh  [ %i3 + 0x10 ], %g1
a0103f28:  21 33 c0 3a  sethi  %hi(0xcf00e800), %l0
a0103f2c:  b4 14 22 c8  or  %l0, 0x2c8, %i2	! 0xcf00eac8
a0103f30:  ea 06 80 00  ld  [ %i2 ], %l5
a0103f34:  d0 06 80 00  ld  [ %i2 ], %o0
a0103f38:  9a 0a 3f ef  and  %o0, -17, %o5
a0103f3c:  da 26 80 00  st  %o5, [ %i2 ]
a0103f40:  ac 14 21 c4  or  %l0, 0x1c4, %l6
a0103f44:  e2 05 80 00  ld  [ %l6 ], %l1
a0103f48:  96 0c 7f 7f  and  %l1, -129, %o3
a0103f4c:  d6 25 80 00  st  %o3, [ %l6 ]
a0103f50:  a8 0d 60 ff  and  %l5, 0xff, %l4
a0103f54:  e8 26 80 00  st  %l4, [ %i2 ]
a0103f58:  10 bf fe f6  b  0xa0103b30
a0103f5c:  c2 16 e0 10  lduh  [ %i3 + 0x10 ], %g1
a0103f60:  15 33 c0 3a  sethi  %hi(0xcf00e800), %o2
a0103f64:  a6 12 a2 c8  or  %o2, 0x2c8, %l3	! 0xcf00eac8
a0103f68:  de 04 c0 00  ld  [ %l3 ], %o7
a0103f6c:  d0 04 c0 00  ld  [ %l3 ], %o0
a0103f70:  a0 0a 3f ef  and  %o0, -17, %l0
a0103f74:  e0 24 c0 00  st  %l0, [ %l3 ]
a0103f78:  a2 12 a1 c4  or  %o2, 0x1c4, %l1
a0103f7c:  d2 04 40 00  ld  [ %l1 ], %o1
a0103f80:  98 12 60 80  or  %o1, 0x80, %o4
a0103f84:  d8 24 40 00  st  %o4, [ %l1 ]
a0103f88:  a4 0b e0 ff  and  %o7, 0xff, %l2
a0103f8c:  e4 24 c0 00  st  %l2, [ %l3 ]
a0103f90:  10 bf ff 83  b  0xa0103d9c
a0103f94:  90 10 00 18  mov  %i0, %o0
a0103f98:  92 10 20 50  mov  0x50, %o1
a0103f9c:  7f ff b8 ae  call  0xa00f2254
a0103fa0:  90 10 00 18  mov  %i0, %o0
a0103fa4:  94 0a 20 df  and  %o0, 0xdf, %o2
a0103fa8:  90 10 00 18  mov  %i0, %o0
a0103fac:  7f ff b8 bb  call  0xa00f2298
a0103fb0:  92 10 20 50  mov  0x50, %o1
a0103fb4:  10 bf fe 5e  b  0xa010392c
a0103fb8:  d6 17 bf ec  lduh  [ %fp + -20 ], %o3
a0103fbc:  94 10 20 20  mov  0x20, %o2
a0103fc0:  10 80 00 bd  b  0xa01042b4
a0103fc4:  96 10 20 00  clr  %o3
a0103fc8:  90 10 00 18  mov  %i0, %o0
a0103fcc:  92 10 20 6e  mov  0x6e, %o1
a0103fd0:  7f ff b8 b2  call  0xa00f2298
a0103fd4:  94 10 20 07  mov  7, %o2
a0103fd8:  10 bf ff c2  b  0xa0103ee0
a0103fdc:  92 0c e0 ff  and  %l3, 0xff, %o1
a0103fe0:  94 10 20 07  mov  7, %o2
a0103fe4:  90 10 00 18  mov  %i0, %o0
a0103fe8:  7f ff b8 ac  call  0xa00f2298
a0103fec:  92 10 20 6e  mov  0x6e, %o1
a0103ff0:  90 10 00 18  mov  %i0, %o0
a0103ff4:  92 10 20 00  clr  %o1
a0103ff8:  7f ff d3 8d  call  0xa00f8e2c
a0103ffc:  e2 17 bf be  lduh  [ %fp + -66 ], %l1
a0104000:  90 10 00 18  mov  %i0, %o0
a0104004:  7f ff d3 90  call  0xa00f8e44
a0104008:  92 10 20 05  mov  5, %o1
a010400c:  90 10 20 0a  mov  0xa, %o0
a0104010:  40 00 76 ef  call  0xa0121bcc
a0104014:  d2 17 bf aa  lduh  [ %fp + -86 ], %o1
a0104018:  92 10 20 dc  mov  0xdc, %o1
a010401c:  7f ff b9 bb  call  0xa00f2708
a0104020:  90 10 00 18  mov  %i0, %o0
a0104024:  9f 2a 20 10  sll  %o0, 0x10, %o7
a0104028:  a5 33 e0 10  srl  %o7, 0x10, %l2
a010402c:  90 10 00 18  mov  %i0, %o0
a0104030:  7f ff b9 b6  call  0xa00f2708
a0104034:  92 10 20 de  mov  0xde, %o1
a0104038:  83 2a 20 10  sll  %o0, 0x10, %g1
a010403c:  9b 30 60 10  srl  %g1, 0x10, %o5
a0104040:  96 24 80 0d  sub  %l2, %o5, %o3
a0104044:  91 3a e0 1f  sra  %o3, 0x1f, %o0
a0104048:  a0 1a 00 0b  xor  %o0, %o3, %l0
a010404c:  94 24 00 08  sub  %l0, %o0, %o2
a0104050:  80 a2 a0 01  cmp  %o2, 1
a0104054:  14 80 00 73  bg  0xa0104220
a0104058:  03 00 00 3f  sethi  %hi(0xfc00), %g1
a010405c:  91 2c 60 10  sll  %l1, 0x10, %o0
a0104060:  93 32 20 10  srl  %o0, 0x10, %o1
a0104064:  7f ff d3 78  call  0xa00f8e44
a0104068:  90 10 00 18  mov  %i0, %o0
a010406c:  90 10 20 0a  mov  0xa, %o0
a0104070:  40 00 76 d7  call  0xa0121bcc
a0104074:  d2 17 bf aa  lduh  [ %fp + -86 ], %o1
a0104078:  92 10 20 dc  mov  0xdc, %o1
a010407c:  7f ff b9 a3  call  0xa00f2708
a0104080:  90 10 00 18  mov  %i0, %o0
a0104084:  97 2a 20 10  sll  %o0, 0x10, %o3
a0104088:  a1 32 e0 10  srl  %o3, 0x10, %l0
a010408c:  92 10 20 de  mov  0xde, %o1
a0104090:  7f ff b9 9e  call  0xa00f2708
a0104094:  90 10 00 18  mov  %i0, %o0
a0104098:  a5 2a 20 10  sll  %o0, 0x10, %l2
a010409c:  95 34 a0 10  srl  %l2, 0x10, %o2
a01040a0:  92 24 00 0a  sub  %l0, %o2, %o1
a01040a4:  99 3a 60 1f  sra  %o1, 0x1f, %o4
a01040a8:  9e 1b 00 09  xor  %o4, %o1, %o7
a01040ac:  a2 23 c0 0c  sub  %o7, %o4, %l1
a01040b0:  90 10 00 18  mov  %i0, %o0
a01040b4:  92 10 20 6e  mov  0x6e, %o1
a01040b8:  80 a4 60 01  cmp  %l1, 1
a01040bc:  04 bf ff 88  ble  0xa0103edc
a01040c0:  94 10 20 47  mov  0x47, %o2
a01040c4:  7f ff b8 75  call  0xa00f2298
a01040c8:  01 00 00 00  nop
a01040cc:  10 bf ff 85  b  0xa0103ee0
a01040d0:  92 0c e0 ff  and  %l3, 0xff, %o1
a01040d4:  96 10 20 01  mov  1, %o3
a01040d8:  90 10 00 18  mov  %i0, %o0
a01040dc:  7f ff b8 94  call  0xa00f232c
a01040e0:  92 10 20 6e  mov  0x6e, %o1
a01040e4:  90 10 20 0a  mov  0xa, %o0
a01040e8:  40 00 76 b9  call  0xa0121bcc
a01040ec:  d2 17 bf aa  lduh  [ %fp + -86 ], %o1
a01040f0:  93 2c 60 10  sll  %l1, 0x10, %o1
a01040f4:  a1 32 60 10  srl  %o1, 0x10, %l0
a01040f8:  90 10 00 18  mov  %i0, %o0
a01040fc:  7f ff b9 83  call  0xa00f2708
a0104100:  92 10 20 dc  mov  0xdc, %o1
a0104104:  99 2a 20 10  sll  %o0, 0x10, %o4
a0104108:  83 33 20 10  srl  %o4, 0x10, %g1
a010410c:  9e 24 00 01  sub  %l0, %g1, %o7
a0104110:  91 3b e0 1f  sra  %o7, 0x1f, %o0
a0104114:  9a 1a 00 0f  xor  %o0, %o7, %o5
a0104118:  a2 23 40 08  sub  %o5, %o0, %l1
a010411c:  80 a4 60 05  cmp  %l1, 5
a0104120:  14 80 00 11  bg  0xa0104164
a0104124:  92 10 20 0e  mov  0xe, %o1
a0104128:  9f 2c a0 10  sll  %l2, 0x10, %o7
a010412c:  a1 33 e0 10  srl  %o7, 0x10, %l0
a0104130:  90 10 00 18  mov  %i0, %o0
a0104134:  7f ff b9 75  call  0xa00f2708
a0104138:  92 10 20 de  mov  0xde, %o1
a010413c:  91 2a 20 10  sll  %o0, 0x10, %o0
a0104140:  9b 32 20 10  srl  %o0, 0x10, %o5
a0104144:  a2 24 00 0d  sub  %l0, %o5, %l1
a0104148:  97 3c 60 1f  sra  %l1, 0x1f, %o3
a010414c:  94 1a c0 11  xor  %o3, %l1, %o2
a0104150:  a4 22 80 0b  sub  %o2, %o3, %l2
a0104154:  80 a4 a0 05  cmp  %l2, 5
a0104158:  24 bf ff 62  ble,a   0xa0103ee0
a010415c:  92 0c e0 ff  and  %l3, 0xff, %o1
a0104160:  92 10 20 0e  mov  0xe, %o1
a0104164:  7f ff b6 e0  call  0xa00f1ce4
a0104168:  90 10 00 18  mov  %i0, %o0
a010416c:  a4 10 00 08  mov  %o0, %l2
a0104170:  90 10 00 18  mov  %i0, %o0
a0104174:  7f ff b6 dc  call  0xa00f1ce4
a0104178:  92 10 20 0c  mov  0xc, %o1
a010417c:  99 2a 20 10  sll  %o0, 0x10, %o4
a0104180:  95 33 20 10  srl  %o4, 0x10, %o2
a0104184:  90 10 00 18  mov  %i0, %o0
a0104188:  7f ff b6 f0  call  0xa00f1d48
a010418c:  92 10 20 0e  mov  0xe, %o1
a0104190:  83 2c a0 10  sll  %l2, 0x10, %g1
a0104194:  95 30 60 10  srl  %g1, 0x10, %o2
a0104198:  90 10 00 18  mov  %i0, %o0
a010419c:  7f ff b6 eb  call  0xa00f1d48
a01041a0:  92 10 20 0c  mov  0xc, %o1
a01041a4:  10 bf ff 4f  b  0xa0103ee0
a01041a8:  92 0c e0 ff  and  %l3, 0xff, %o1
a01041ac:  94 10 20 01  mov  1, %o2
a01041b0:  90 10 00 18  mov  %i0, %o0
a01041b4:  7f ff b6 6a  call  0xa00f1b5c
a01041b8:  92 10 20 56  mov  0x56, %o1
a01041bc:  90 10 00 18  mov  %i0, %o0
a01041c0:  7f ff b6 c9  call  0xa00f1ce4
a01041c4:  92 10 20 0e  mov  0xe, %o1
a01041c8:  a2 10 00 08  mov  %o0, %l1
a01041cc:  90 10 00 18  mov  %i0, %o0
a01041d0:  7f ff b6 c5  call  0xa00f1ce4
a01041d4:  92 10 20 0c  mov  0xc, %o1
a01041d8:  9b 2a 20 10  sll  %o0, 0x10, %o5
a01041dc:  95 33 60 10  srl  %o5, 0x10, %o2
a01041e0:  90 10 00 18  mov  %i0, %o0
a01041e4:  7f ff b6 d9  call  0xa00f1d48
a01041e8:  92 10 20 0e  mov  0xe, %o1
a01041ec:  97 2c 60 10  sll  %l1, 0x10, %o3
a01041f0:  95 32 e0 10  srl  %o3, 0x10, %o2
a01041f4:  90 10 00 18  mov  %i0, %o0
a01041f8:  7f ff b6 d4  call  0xa00f1d48
a01041fc:  92 10 20 0c  mov  0xc, %o1
a0104200:  10 bf ff 1c  b  0xa0103e70
a0104204:  90 10 20 0a  mov  0xa, %o0
a0104208:  92 10 20 56  mov  0x56, %o1
a010420c:  94 10 20 01  mov  1, %o2
a0104210:  7f ff b6 53  call  0xa00f1b5c
a0104214:  96 10 20 00  clr  %o3
a0104218:  10 bf ff 16  b  0xa0103e70
a010421c:  90 10 20 0a  mov  0xa, %o0
a0104220:  92 10 63 ff  or  %g1, 0x3ff, %o1
a0104224:  7f ff d3 02  call  0xa00f8e2c
a0104228:  90 10 00 18  mov  %i0, %o0
a010422c:  90 10 00 18  mov  %i0, %o0
a0104230:  7f ff d3 05  call  0xa00f8e44
a0104234:  92 10 20 05  mov  5, %o1
a0104238:  90 10 20 0a  mov  0xa, %o0
a010423c:  40 00 76 64  call  0xa0121bcc
a0104240:  d2 17 bf aa  lduh  [ %fp + -86 ], %o1
a0104244:  92 10 20 dc  mov  0xdc, %o1
a0104248:  7f ff b9 30  call  0xa00f2708
a010424c:  90 10 00 18  mov  %i0, %o0
a0104250:  9b 2a 20 10  sll  %o0, 0x10, %o5
a0104254:  a5 33 60 10  srl  %o5, 0x10, %l2
a0104258:  92 10 20 de  mov  0xde, %o1
a010425c:  7f ff b9 2b  call  0xa00f2708
a0104260:  90 10 00 18  mov  %i0, %o0
a0104264:  97 2a 20 10  sll  %o0, 0x10, %o3
a0104268:  91 32 e0 10  srl  %o3, 0x10, %o0
a010426c:  a0 24 80 08  sub  %l2, %o0, %l0
a0104270:  95 3c 20 1f  sra  %l0, 0x1f, %o2
a0104274:  92 1a 80 10  xor  %o2, %l0, %o1
a0104278:  98 22 40 0a  sub  %o1, %o2, %o4
a010427c:  80 a3 20 01  cmp  %o4, 1
a0104280:  24 bf ff 78  ble,a   0xa0104060
a0104284:  91 2c 60 10  sll  %l1, 0x10, %o0
a0104288:  90 10 00 18  mov  %i0, %o0
a010428c:  7f ff d2 e8  call  0xa00f8e2c
a0104290:  92 10 20 01  mov  1, %o1
a0104294:  90 10 00 18  mov  %i0, %o0
a0104298:  7f ff d2 eb  call  0xa00f8e44
a010429c:  92 10 20 05  mov  5, %o1
a01042a0:  90 10 20 0a  mov  0xa, %o0
a01042a4:  40 00 76 4a  call  0xa0121bcc
a01042a8:  d2 17 bf aa  lduh  [ %fp + -86 ], %o1
a01042ac:  10 bf ff 6d  b  0xa0104060
a01042b0:  91 2c 60 10  sll  %l1, 0x10, %o0
a01042b4:  7f ff b8 1e  call  0xa00f232c
a01042b8:  01 00 00 00  nop
a01042bc:  01 00 00 00  nop
a01042c0:  81 c7 e0 08  ret
a01042c4:  81 e8 00 00  restore
