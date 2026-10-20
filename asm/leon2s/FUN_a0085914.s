# leon2s FUN_a0085914 0xa0085914-0xa0085b14 (512 bytes)
a0085914:  9d e3 bf 98  save  %sp, -104, %sp
a0085918:  80 8e 20 ff  btst  0xff, %i0
a008591c:  02 80 00 21  be  0xa00859a0
a0085920:  19 33 c0 43  sethi  %hi(0xcf010c00), %o4
a0085924:  9a 13 20 08  or  %o4, 8, %o5	! 0xcf010c08
a0085928:  c2 03 40 00  ld  [ %o5 ], %g1
a008592c:  82 10 60 10  or  %g1, 0x10, %g1
a0085930:  82 08 60 ff  and  %g1, 0xff, %g1
a0085934:  c2 23 40 00  st  %g1, [ %o5 ]
a0085938:  da 03 00 00  ld  [ %o4 ], %o5
a008593c:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0085940:  98 10 61 00  or  %g1, 0x100, %o4	! 0xa807cd00
a0085944:  9a 0b 7f f8  and  %o5, -8, %o5
a0085948:  c2 0b 20 01  ldub  [ %o4 + 1 ], %g1
a008594c:  80 a0 60 04  cmp  %g1, 4
a0085950:  12 80 00 04  bne  0xa0085960
a0085954:  b6 10 00 0d  mov  %o5, %i3
a0085958:  10 80 00 06  b  0xa0085970
a008595c:  b6 13 60 02  or  %o5, 2, %i3
a0085960:  c2 0b 20 01  ldub  [ %o4 + 1 ], %g1
a0085964:  80 a0 60 02  cmp  %g1, 2
a0085968:  22 80 00 02  be,a   0xa0085970
a008596c:  b6 13 60 01  or  %o5, 1, %i3
a0085970:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0085974:  c2 08 61 2d  ldub  [ %g1 + 0x12d ], %g1	! 0xa807cd2d
a0085978:  80 a0 60 02  cmp  %g1, 2
a008597c:  12 80 00 04  bne  0xa008598c
a0085980:  80 a0 60 04  cmp  %g1, 4
a0085984:  10 80 00 04  b  0xa0085994
a0085988:  b6 06 e0 01  inc  %i3
a008598c:  22 80 00 02  be,a   0xa0085994
a0085990:  b6 06 e0 02  add  %i3, 2, %i3
a0085994:  9a 0e e0 ff  and  %i3, 0xff, %o5
a0085998:  10 80 00 53  b  0xa0085ae4
a008599c:  03 33 c0 43  sethi  %hi(0xcf010c00), %g1
a00859a0:  1b 33 c0 43  sethi  %hi(0xcf010c00), %o5
a00859a4:  c2 03 40 00  ld  [ %o5 ], %g1
a00859a8:  82 10 60 10  or  %g1, 0x10, %g1
a00859ac:  82 08 60 ff  and  %g1, 0xff, %g1
a00859b0:  c2 23 40 00  st  %g1, [ %o5 ]
a00859b4:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a00859b8:  82 10 62 dc  or  %g1, 0x2dc, %g1	! 0xcf0116dc
a00859bc:  c2 00 40 00  ld  [ %g1 ], %g1
a00859c0:  b4 08 7f f8  and  %g1, -8, %i2
a00859c4:  90 10 20 00  clr  %o0
a00859c8:  40 00 87 bb  call  0xa00a78b4
a00859cc:  92 10 20 03  mov  3, %o1
a00859d0:  90 0a 20 0f  and  %o0, 0xf, %o0
a00859d4:  80 a2 20 04  cmp  %o0, 4
a00859d8:  12 80 00 25  bne  0xa0085a6c
a00859dc:  b6 10 00 1a  mov  %i2, %i3
a00859e0:  7f ff ff c4  call  0xa00858f0
a00859e4:  90 10 20 00  clr  %o0
a00859e8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00859ec:  80 a2 20 81  cmp  %o0, 0x81
a00859f0:  32 80 00 06  bne,a   0xa0085a08
a00859f4:  80 a2 20 71  cmp  %o0, 0x71
a00859f8:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a00859fc:  d2 08 61 4d  ldub  [ %g1 + 0x14d ], %o1	! 0xa807a94d
a0085a00:  10 80 00 07  b  0xa0085a1c
a0085a04:  90 10 20 00  clr  %o0
a0085a08:  32 80 00 0a  bne,a   0xa0085a30
a0085a0c:  80 a2 20 51  cmp  %o0, 0x51
a0085a10:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a0085a14:  d2 08 61 4d  ldub  [ %g1 + 0x14d ], %o1	! 0xa807a94d
a0085a18:  90 10 20 01  mov  1, %o0
a0085a1c:  40 00 a1 52  call  0xa00adf64
a0085a20:  01 00 00 00  nop
a0085a24:  90 0a 20 ff  and  %o0, 0xff, %o0
a0085a28:  10 80 00 1e  b  0xa0085aa0
a0085a2c:  80 a2 20 01  cmp  %o0, 1
a0085a30:  12 80 00 04  bne  0xa0085a40
a0085a34:  80 a2 20 61  cmp  %o0, 0x61
a0085a38:  10 80 00 05  b  0xa0085a4c
a0085a3c:  90 10 20 00  clr  %o0
a0085a40:  12 80 00 1a  bne  0xa0085aa8
a0085a44:  b6 16 a0 02  or  %i2, 2, %i3
a0085a48:  90 10 20 01  mov  1, %o0
a0085a4c:  40 00 73 e3  call  0xa00a29d8
a0085a50:  b6 16 a0 01  or  %i2, 1, %i3
a0085a54:  90 0a 20 ff  and  %o0, 0xff, %o0
a0085a58:  80 a2 20 01  cmp  %o0, 1
a0085a5c:  32 80 00 13  bne,a   0xa0085aa8
a0085a60:  b6 16 a0 02  or  %i2, 2, %i3
a0085a64:  10 80 00 12  b  0xa0085aac
a0085a68:  90 10 20 00  clr  %o0
a0085a6c:  90 10 20 00  clr  %o0
a0085a70:  40 00 87 91  call  0xa00a78b4
a0085a74:  92 10 20 03  mov  3, %o1
a0085a78:  90 0a 20 0f  and  %o0, 0xf, %o0
a0085a7c:  80 a2 20 02  cmp  %o0, 2
a0085a80:  12 80 00 0b  bne  0xa0085aac
a0085a84:  90 10 20 00  clr  %o0
a0085a88:  7f ff ff 9a  call  0xa00858f0
a0085a8c:  90 10 20 00  clr  %o0
a0085a90:  90 0a 20 ff  and  %o0, 0xff, %o0
a0085a94:  80 a2 20 81  cmp  %o0, 0x81
a0085a98:  02 80 00 04  be  0xa0085aa8
a0085a9c:  80 a2 20 71  cmp  %o0, 0x71
a0085aa0:  32 80 00 02  bne,a   0xa0085aa8
a0085aa4:  b6 16 a0 01  or  %i2, 1, %i3
a0085aa8:  90 10 20 00  clr  %o0
a0085aac:  40 00 87 82  call  0xa00a78b4
a0085ab0:  92 10 20 6f  mov  0x6f, %o1
a0085ab4:  80 8a 20 08  btst  8, %o0
a0085ab8:  02 80 00 09  be  0xa0085adc
a0085abc:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a0085ac0:  82 0e e0 07  and  %i3, 7, %g1
a0085ac4:  80 a0 60 02  cmp  %g1, 2
a0085ac8:  32 80 00 04  bne,a   0xa0085ad8
a0085acc:  b6 06 e0 01  inc  %i3
a0085ad0:  82 0e ff f8  and  %i3, -8, %g1
a0085ad4:  b6 10 60 04  or  %g1, 4, %i3
a0085ad8:  03 33 c0 45  sethi  %hi(0xcf011400), %g1
a0085adc:  9a 0e e0 ff  and  %i3, 0xff, %o5
a0085ae0:  82 10 62 dc  or  %g1, 0x2dc, %g1
a0085ae4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0085ae8:  da 20 40 00  st  %o5, [ %g1 ]
a0085aec:  90 10 00 18  mov  %i0, %o0
a0085af0:  92 10 20 00  clr  %o1
a0085af4:  94 10 20 08  mov  8, %o2
a0085af8:  40 00 87 92  call  0xa00a7940
a0085afc:  96 10 20 01  mov  1, %o3
a0085b00:  b2 10 20 00  clr  %i1
a0085b04:  b4 10 20 08  mov  8, %i2
a0085b08:  40 00 87 8e  call  0xa00a7940
a0085b0c:  97 e8 20 00  restore  %g0, 0, %o3
a0085b10:  01 00 00 00  nop
