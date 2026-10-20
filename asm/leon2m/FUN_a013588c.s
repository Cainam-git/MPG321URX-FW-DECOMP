# leon2m FUN_a013588c 0xa013588c-0xa0135ae8 (604 bytes)
a013588c:  9d e3 bf 80  save  %sp, -128, %sp
a0135890:  91 2e 60 10  sll  %i1, 0x10, %o0
a0135894:  98 10 20 00  clr  %o4
a0135898:  9a 10 20 00  clr  %o5
a013589c:  83 32 20 10  srl  %o0, 0x10, %g1
a01358a0:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a01358a4:  80 a0 60 0f  cmp  %g1, 0xf
a01358a8:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a01358ac:  08 80 00 03  bleu  0xa01358b8
a01358b0:  a4 10 00 19  mov  %i1, %l2
a01358b4:  a4 10 20 10  mov  0x10, %l2
a01358b8:  93 2e 20 10  sll  %i0, 0x10, %o1
a01358bc:  9b 32 60 10  srl  %o1, 0x10, %o5
a01358c0:  a9 2e 60 10  sll  %i1, 0x10, %l4
a01358c4:  a1 32 60 14  srl  %o1, 0x14, %l0
a01358c8:  aa 0b 60 0f  and  %o5, 0xf, %l5
a01358cc:  23 2a 00 b2  sethi  %hi(0xa802c800), %l1
a01358d0:  27 2a 00 b2  sethi  %hi(0xa802c800), %l3
a01358d4:  10 80 00 04  b  0xa01358e4
a01358d8:  b1 35 20 10  srl  %l4, 0x10, %i0
a01358dc:  7f ff fe 00  call  0xa01350dc
a01358e0:  01 00 00 00  nop
a01358e4:  d6 0c 63 97  ldub  [ %l1 + 0x397 ], %o3
a01358e8:  d8 0c e3 96  ldub  [ %l3 + 0x396 ], %o4
a01358ec:  82 0a e0 ff  and  %o3, 0xff, %g1
a01358f0:  94 0b 20 ff  and  %o4, 0xff, %o2
a01358f4:  9e 22 80 01  sub  %o2, %g1, %o7
a01358f8:  92 0a e0 ff  and  %o3, 0xff, %o1
a01358fc:  94 0b 20 ff  and  %o4, 0xff, %o2
a0135900:  80 a2 40 0a  cmp  %o1, %o2
a0135904:  18 80 00 09  bgu  0xa0135928
a0135908:  82 03 e0 24  add  %o7, 0x24, %g1
a013590c:  90 0b 20 ff  and  %o4, 0xff, %o0
a0135910:  98 0a e0 ff  and  %o3, 0xff, %o4
a0135914:  80 a2 40 0a  cmp  %o1, %o2
a0135918:  9a 22 00 0c  sub  %o0, %o4, %o5
a013591c:  1a 80 00 03  bcc  0xa0135928
a0135920:  82 10 20 24  mov  0x24, %g1
a0135924:  82 03 7f ff  add  %o5, -1, %g1
a0135928:  9b 28 60 14  sll  %g1, 0x14, %o5
a013592c:  97 33 60 10  srl  %o5, 0x10, %o3
a0135930:  80 a6 00 0b  cmp  %i0, %o3
a0135934:  18 bf ff ea  bgu  0xa01358dc
a0135938:  80 a6 20 00  cmp  %i0, 0
a013593c:  02 80 00 45  be  0xa0135a50
a0135940:  9e 10 20 00  clr  %o7
a0135944:  9b 35 20 10  srl  %l4, 0x10, %o5
a0135948:  31 2a 00 b6  sethi  %hi(0xa802d800), %i0
a013594c:  a8 16 22 6c  or  %i0, 0x26c, %l4	! 0xa802da6c
a0135950:  aa 0d 60 ff  and  %l5, 0xff, %l5
a0135954:  90 07 bf e8  add  %fp, -24, %o0
a0135958:  b0 10 00 0d  mov  %o5, %i0
a013595c:  95 2b e0 10  sll  %o7, 0x10, %o2
a0135960:  83 32 a0 10  srl  %o2, 0x10, %g1
a0135964:  92 23 40 01  sub  %o5, %g1, %o1
a0135968:  80 a2 60 0f  cmp  %o1, 0xf
a013596c:  24 80 00 02  ble,a   0xa0135974
a0135970:  a4 26 40 0f  sub  %i1, %o7, %l2
a0135974:  92 00 40 1a  add  %g1, %i2, %o1
a0135978:  94 10 20 00  clr  %o2
a013597c:  9a 10 20 00  clr  %o5
a0135980:  97 2b 60 02  sll  %o5, 2, %o3
a0135984:  98 02 c0 09  add  %o3, %o1, %o4
a0135988:  c2 0a 40 0b  ldub  [ %o1 + %o3 ], %g1
a013598c:  da 0b 20 01  ldub  [ %o4 + 1 ], %o5
a0135990:  83 28 60 08  sll  %g1, 8, %g1
a0135994:  82 00 40 0d  add  %g1, %o5, %g1
a0135998:  da 0b 20 02  ldub  [ %o4 + 2 ], %o5
a013599c:  83 28 60 08  sll  %g1, 8, %g1
a01359a0:  82 00 40 0d  add  %g1, %o5, %g1
a01359a4:  da 0b 20 03  ldub  [ %o4 + 3 ], %o5
a01359a8:  83 28 60 08  sll  %g1, 8, %g1
a01359ac:  82 00 40 0d  add  %g1, %o5, %g1
a01359b0:  94 02 a0 01  inc  %o2
a01359b4:  9a 0a a0 ff  and  %o2, 0xff, %o5
a01359b8:  80 a3 60 04  cmp  %o5, 4
a01359bc:  0a bf ff f1  bcs  0xa0135980
a01359c0:  c2 22 00 0b  st  %g1, [ %o0 + %o3 ]
a01359c4:  d4 0c 63 97  ldub  [ %l1 + 0x397 ], %o2
a01359c8:  82 0c a0 ff  and  %l2, 0xff, %g1
a01359cc:  96 0a a0 ff  and  %o2, 0xff, %o3
a01359d0:  99 28 60 10  sll  %g1, 0x10, %o4
a01359d4:  9b 2c 20 18  sll  %l0, 0x18, %o5
a01359d8:  82 03 40 0c  add  %o5, %o4, %g1
a01359dc:  93 2a e0 02  sll  %o3, 2, %o1
a01359e0:  9a 02 40 0b  add  %o1, %o3, %o5
a01359e4:  99 2d 60 08  sll  %l5, 8, %o4
a01359e8:  96 00 40 0c  add  %g1, %o4, %o3
a01359ec:  92 02 e0 07  add  %o3, 7, %o1
a01359f0:  9b 2b 60 02  sll  %o5, 2, %o5
a01359f4:  d2 25 00 0d  st  %o1, [ %l4 + %o5 ]
a01359f8:  96 03 40 14  add  %o5, %l4, %o3
a01359fc:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a0135a00:  d8 07 bf e8  ld  [ %fp + -24 ], %o4
a0135a04:  94 02 a0 01  inc  %o2
a0135a08:  c2 22 e0 10  st  %g1, [ %o3 + 0x10 ]
a0135a0c:  d8 22 e0 04  st  %o4, [ %o3 + 4 ]
a0135a10:  92 0a a0 ff  and  %o2, 0xff, %o1
a0135a14:  c2 07 bf ec  ld  [ %fp + -20 ], %g1
a0135a18:  d8 07 bf f0  ld  [ %fp + -16 ], %o4
a0135a1c:  c2 22 e0 08  st  %g1, [ %o3 + 8 ]
a0135a20:  80 a2 60 24  cmp  %o1, 0x24
a0135a24:  08 80 00 2b  bleu  0xa0135ad0
a0135a28:  d8 22 e0 0c  st  %o4, [ %o3 + 0xc ]
a0135a2c:  c0 2c 63 97  clrb  [ %l1 + 0x397 ]
a0135a30:  94 03 e0 10  add  %o7, 0x10, %o2
a0135a34:  93 2a a0 10  sll  %o2, 0x10, %o1
a0135a38:  9f 32 60 10  srl  %o1, 0x10, %o7
a0135a3c:  80 a3 c0 18  cmp  %o7, %i0
a0135a40:  a0 04 20 01  inc  %l0
a0135a44:  9e 10 00 0a  mov  %o2, %o7
a0135a48:  0a bf ff c5  bcs  0xa013595c
a0135a4c:  9a 10 00 18  mov  %i0, %o5
a0135a50:  10 80 00 04  b  0xa0135a60
a0135a54:  c0 27 bf e4  clr  [ %fp + -28 ]
a0135a58:  7f ff fd a1  call  0xa01350dc
a0135a5c:  01 00 00 00  nop
a0135a60:  e4 0c 63 97  ldub  [ %l1 + 0x397 ], %l2
a0135a64:  e0 0c e3 96  ldub  [ %l3 + 0x396 ], %l0
a0135a68:  80 a4 80 10  cmp  %l2, %l0
a0135a6c:  12 bf ff fb  bne  0xa0135a58
a0135a70:  b2 10 20 00  clr  %i1
a0135a74:  b4 10 20 00  clr  %i2
a0135a78:  98 10 20 00  clr  %o4
a0135a7c:  83 2b 20 02  sll  %o4, 2, %g1
a0135a80:  9a 00 40 0c  add  %g1, %o4, %o5
a0135a84:  97 2b 60 02  sll  %o5, 2, %o3
a0135a88:  b0 02 e0 10  add  %o3, 0x10, %i0
a0135a8c:  90 10 20 00  clr  %o0
a0135a90:  92 0e 20 fc  and  %i0, 0xfc, %o1
a0135a94:  94 07 bf e4  add  %fp, -28, %o2
a0135a98:  67 fd 5a 8e  call  0x4008c4d0
a0135a9c:  96 10 20 01  mov  1, %o3
a0135aa0:  b4 06 a0 01  inc  %i2
a0135aa4:  98 0e a0 ff  and  %i2, 0xff, %o4
a0135aa8:  91 2b 20 02  sll  %o4, 2, %o0
a0135aac:  aa 02 00 0c  add  %o0, %o4, %l5
a0135ab0:  a9 2d 60 02  sll  %l5, 2, %l4
a0135ab4:  a2 05 20 10  add  %l4, 0x10, %l1
a0135ab8:  e6 07 bf e4  ld  [ %fp + -28 ], %l3
a0135abc:  80 a4 60 50  cmp  %l1, 0x50
a0135ac0:  04 bf ff ef  ble  0xa0135a7c
a0135ac4:  b2 16 40 13  or  %i1, %l3, %i1
a0135ac8:  10 80 00 04  b  0xa0135ad8
a0135acc:  80 a6 60 00  cmp  %i1, 0
a0135ad0:  10 bf ff d8  b  0xa0135a30
a0135ad4:  d4 2c 63 97  stb  %o2, [ %l1 + 0x397 ]
a0135ad8:  12 bf ff e7  bne  0xa0135a74
a0135adc:  b2 10 20 00  clr  %i1
a0135ae0:  81 c7 e0 08  ret
a0135ae4:  81 e8 00 00  restore
