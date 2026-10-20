# leon2s FUN_a00958d4 0xa00958d4-0xa0095c30 (860 bytes)  [FUN_a0095c28 = unreachable ret/restore tail, merged]
a00958d4:  9d e3 bf 98  save  %sp, -104, %sp
a00958d8:  a6 10 00 18  mov  %i0, %l3
a00958dc:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00958e0:  7f ff f0 4c  call  0xa0091a10
a00958e4:  90 10 00 18  mov  %i0, %o0
a00958e8:  80 8a 20 ff  btst  0xff, %o0
a00958ec:  02 80 00 c5  be  0xa0095c00
a00958f0:  83 2e 20 03  sll  %i0, 3, %g1
a00958f4:  82 20 40 18  sub  %g1, %i0, %g1
a00958f8:  25 2a 01 f5  sethi  %hi(0xa807d400), %l2
a00958fc:  b3 28 60 02  sll  %g1, 2, %i1
a0095900:  a2 14 a1 80  or  %l2, 0x180, %l1
a0095904:  a0 06 40 11  add  %i1, %l1, %l0
a0095908:  c2 04 20 14  ld  [ %l0 + 0x14 ], %g1
a009590c:  83 30 60 0c  srl  %g1, 0xc, %g1
a0095910:  80 88 60 01  btst  1, %g1
a0095914:  02 80 00 bb  be  0xa0095c00
a0095918:  01 00 00 00  nop
a009591c:  7f ff f0 a4  call  0xa0091bac
a0095920:  90 10 00 18  mov  %i0, %o0
a0095924:  80 8a 20 ff  btst  0xff, %o0
a0095928:  32 80 00 af  bne,a   0xa0095be4
a009592c:  c2 04 40 19  ld  [ %l1 + %i1 ], %g1
a0095930:  11 28 01 a4  sethi  %hi(0xa0069000), %o0
a0095934:  92 10 00 18  mov  %i0, %o1
a0095938:  7f ff 75 c3  call  0xa0073044
a009593c:  90 12 23 98  or  %o0, 0x398, %o0
a0095940:  90 10 00 18  mov  %i0, %o0
a0095944:  7f ff fd d7  call  0xa00950a0
a0095948:  92 10 20 00  clr  %o1
a009594c:  90 10 00 18  mov  %i0, %o0
a0095950:  7f ff fd d4  call  0xa00950a0
a0095954:  92 10 20 03  mov  3, %o1
a0095958:  11 28 01 a4  sethi  %hi(0xa0069000), %o0
a009595c:  92 10 00 18  mov  %i0, %o1
a0095960:  7f ff 75 b9  call  0xa0073044
a0095964:  90 12 23 d0  or  %o0, 0x3d0, %o0
a0095968:  c2 04 40 19  ld  [ %l1 + %i1 ], %g1
a009596c:  83 30 60 1d  srl  %g1, 0x1d, %g1
a0095970:  90 10 00 18  mov  %i0, %o0
a0095974:  80 88 60 01  btst  1, %g1
a0095978:  02 80 00 04  be  0xa0095988
a009597c:  92 10 20 02  mov  2, %o1
a0095980:  90 10 00 18  mov  %i0, %o0
a0095984:  92 10 20 01  mov  1, %o1
a0095988:  7f ff fd c6  call  0xa00950a0
a009598c:  a2 14 a1 80  or  %l2, 0x180, %l1
a0095990:  83 2e 20 03  sll  %i0, 3, %g1
a0095994:  82 20 40 18  sub  %g1, %i0, %g1
a0095998:  a1 28 60 02  sll  %g1, 2, %l0
a009599c:  b2 04 00 11  add  %l0, %l1, %i1
a00959a0:  c2 06 60 14  ld  [ %i1 + 0x14 ], %g1
a00959a4:  83 30 60 0d  srl  %g1, 0xd, %g1
a00959a8:  80 88 60 01  btst  1, %g1
a00959ac:  22 80 00 0b  be,a   0xa00959d8
a00959b0:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a00959b4:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a00959b8:  92 10 00 18  mov  %i0, %o1
a00959bc:  7f ff 75 a2  call  0xa0073044
a00959c0:  90 12 20 48  or  %o0, 0x48, %o0
a00959c4:  7f ff fd 7b  call  0xa0094fb0
a00959c8:  d0 0e 60 15  ldub  [ %i1 + 0x15 ], %o0
a00959cc:  7f ff ef f9  call  0xa00919b0
a00959d0:  90 10 00 18  mov  %i0, %o0
a00959d4:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a00959d8:  92 10 00 18  mov  %i0, %o1
a00959dc:  7f ff 75 9a  call  0xa0073044
a00959e0:  90 12 20 08  or  %o0, 8, %o0
a00959e4:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00959e8:  90 10 00 18  mov  %i0, %o0
a00959ec:  80 88 60 10  btst  0x10, %g1
a00959f0:  02 80 00 04  be  0xa0095a00
a00959f4:  92 10 20 05  mov  5, %o1
a00959f8:  90 10 00 18  mov  %i0, %o0
a00959fc:  92 10 20 06  mov  6, %o1
a0095a00:  7f ff fd a8  call  0xa00950a0
a0095a04:  01 00 00 00  nop
a0095a08:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095a0c:  92 10 00 18  mov  %i0, %o1
a0095a10:  7f ff 75 8d  call  0xa0073044
a0095a14:  90 12 20 80  or  %o0, 0x80, %o0
a0095a18:  90 10 00 18  mov  %i0, %o0
a0095a1c:  7f ff fd a1  call  0xa00950a0
a0095a20:  92 10 20 11  mov  0x11, %o1
a0095a24:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095a28:  90 12 20 b8  or  %o0, 0xb8, %o0	! 0xa00694b8
a0095a2c:  7f ff 75 86  call  0xa0073044
a0095a30:  92 10 00 18  mov  %i0, %o1
a0095a34:  83 2e 20 03  sll  %i0, 3, %g1
a0095a38:  82 20 40 18  sub  %g1, %i0, %g1
a0095a3c:  83 28 60 02  sll  %g1, 2, %g1
a0095a40:  9a 14 a1 80  or  %l2, 0x180, %o5
a0095a44:  c2 03 40 01  ld  [ %o5 + %g1 ], %g1
a0095a48:  80 88 60 10  btst  0x10, %g1
a0095a4c:  12 80 00 08  bne  0xa0095a6c
a0095a50:  80 88 60 08  btst  8, %g1
a0095a54:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095a58:  7f ff 76 9b  call  0xa00734c4
a0095a5c:  90 12 20 f8  or  %o0, 0xf8, %o0	! 0xa00694f8
a0095a60:  90 10 00 18  mov  %i0, %o0
a0095a64:  10 80 00 13  b  0xa0095ab0
a0095a68:  92 10 20 0a  mov  0xa, %o1
a0095a6c:  22 80 00 0a  be,a   0xa0095a94
a0095a70:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095a74:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095a78:  7f ff 76 93  call  0xa00734c4
a0095a7c:  90 12 21 28  or  %o0, 0x128, %o0	! 0xa0069528
a0095a80:  90 10 00 18  mov  %i0, %o0
a0095a84:  7f ff fd 87  call  0xa00950a0
a0095a88:  92 10 20 0c  mov  0xc, %o1
a0095a8c:  10 80 00 05  b  0xa0095aa0
a0095a90:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095a94:  7f ff 76 8c  call  0xa00734c4
a0095a98:  90 12 21 10  or  %o0, 0x110, %o0	! 0xa0069510
a0095a9c:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095aa0:  7f ff 76 89  call  0xa00734c4
a0095aa4:  90 12 21 40  or  %o0, 0x140, %o0	! 0xa0069540
a0095aa8:  90 10 00 18  mov  %i0, %o0
a0095aac:  92 10 20 0b  mov  0xb, %o1
a0095ab0:  7f ff fd 7c  call  0xa00950a0
a0095ab4:  b0 0c e0 ff  and  %l3, 0xff, %i0
a0095ab8:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095abc:  92 10 00 18  mov  %i0, %o1
a0095ac0:  7f ff 75 61  call  0xa0073044
a0095ac4:  90 12 21 58  or  %o0, 0x158, %o0
a0095ac8:  90 10 00 18  mov  %i0, %o0
a0095acc:  7f ff fd 75  call  0xa00950a0
a0095ad0:  92 10 20 08  mov  8, %o1
a0095ad4:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095ad8:  92 10 00 18  mov  %i0, %o1
a0095adc:  7f ff 75 5a  call  0xa0073044
a0095ae0:  90 12 21 90  or  %o0, 0x190, %o0
a0095ae4:  90 10 00 18  mov  %i0, %o0
a0095ae8:  7f ff fd 6e  call  0xa00950a0
a0095aec:  92 10 20 07  mov  7, %o1
a0095af0:  83 2e 20 03  sll  %i0, 3, %g1
a0095af4:  82 20 40 18  sub  %g1, %i0, %g1
a0095af8:  b3 28 60 02  sll  %g1, 2, %i1
a0095afc:  a0 14 a1 80  or  %l2, 0x180, %l0
a0095b00:  d2 04 00 19  ld  [ %l0 + %i1 ], %o1
a0095b04:  93 32 60 05  srl  %o1, 5, %o1
a0095b08:  92 0a 60 01  and  %o1, 1, %o1
a0095b0c:  7f ff fa 10  call  0xa009434c
a0095b10:  90 10 00 18  mov  %i0, %o0
a0095b14:  c2 04 00 19  ld  [ %l0 + %i1 ], %g1
a0095b18:  83 30 60 1e  srl  %g1, 0x1e, %g1
a0095b1c:  80 88 60 01  btst  1, %g1
a0095b20:  32 80 00 0a  bne,a   0xa0095b48
a0095b24:  c2 04 00 19  ld  [ %l0 + %i1 ], %g1
a0095b28:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095b2c:  92 10 00 18  mov  %i0, %o1
a0095b30:  7f ff 75 45  call  0xa0073044
a0095b34:  90 12 21 d0  or  %o0, 0x1d0, %o0
a0095b38:  90 10 00 18  mov  %i0, %o0
a0095b3c:  7f ff fd 59  call  0xa00950a0
a0095b40:  92 10 20 04  mov  4, %o1
a0095b44:  c2 04 00 19  ld  [ %l0 + %i1 ], %g1
a0095b48:  80 88 60 10  btst  0x10, %g1
a0095b4c:  02 80 00 07  be  0xa0095b68
a0095b50:  90 10 00 18  mov  %i0, %o0
a0095b54:  92 10 20 00  clr  %o1
a0095b58:  94 10 21 23  mov  0x123, %o2
a0095b5c:  96 10 20 08  mov  8, %o3
a0095b60:  10 80 00 06  b  0xa0095b78
a0095b64:  98 10 20 01  mov  1, %o4
a0095b68:  92 10 20 00  clr  %o1
a0095b6c:  94 10 21 23  mov  0x123, %o2
a0095b70:  96 10 20 08  mov  8, %o3
a0095b74:  98 10 20 00  clr  %o4
a0095b78:  40 00 49 55  call  0xa00a80cc
a0095b7c:  01 00 00 00  nop
a0095b80:  11 28 01 a5  sethi  %hi(0xa0069400), %o0
a0095b84:  92 10 00 18  mov  %i0, %o1
a0095b88:  7f ff 75 2f  call  0xa0073044
a0095b8c:  90 12 22 08  or  %o0, 0x208, %o0
a0095b90:  7f ff fc 31  call  0xa0094c54
a0095b94:  90 10 00 18  mov  %i0, %o0
a0095b98:  90 10 00 18  mov  %i0, %o0
a0095b9c:  7f ff fd 41  call  0xa00950a0
a0095ba0:  92 10 20 0f  mov  0xf, %o1
a0095ba4:  90 10 00 18  mov  %i0, %o0
a0095ba8:  7f ff fd 3e  call  0xa00950a0
a0095bac:  92 10 20 0d  mov  0xd, %o1
a0095bb0:  7f ff ef e3  call  0xa0091b3c
a0095bb4:  90 10 00 18  mov  %i0, %o0
a0095bb8:  83 2e 20 03  sll  %i0, 3, %g1
a0095bbc:  82 20 40 18  sub  %g1, %i0, %g1
a0095bc0:  9a 14 a1 80  or  %l2, 0x180, %o5
a0095bc4:  99 28 60 02  sll  %g1, 2, %o4
a0095bc8:  c2 03 40 0c  ld  [ %o5 + %o4 ], %g1
a0095bcc:  83 30 60 1d  srl  %g1, 0x1d, %g1
a0095bd0:  80 88 60 01  btst  1, %g1
a0095bd4:  02 80 00 14  be  0xa0095c24
a0095bd8:  82 03 00 0d  add  %o4, %o5, %g1
a0095bdc:  10 80 00 07  b  0xa0095bf8
a0095be0:  f2 08 60 17  ldub  [ %g1 + 0x17 ], %i1
a0095be4:  83 30 60 1d  srl  %g1, 0x1d, %g1
a0095be8:  80 88 60 01  btst  1, %g1
a0095bec:  02 80 00 0e  be  0xa0095c24
a0095bf0:  01 00 00 00  nop
a0095bf4:  f2 0c 20 17  ldub  [ %l0 + 0x17 ], %i1
a0095bf8:  40 00 4f 1e  call  0xa00a9870
a0095bfc:  81 e8 00 00  restore
a0095c00:  7f ff ef eb  call  0xa0091bac
a0095c04:  90 10 00 18  mov  %i0, %o0
a0095c08:  80 8a 20 ff  btst  0xff, %o0
a0095c0c:  02 80 00 06  be  0xa0095c24
a0095c10:  90 10 00 18  mov  %i0, %o0
a0095c14:  7f ff fd 23  call  0xa00950a0
a0095c18:  92 10 20 09  mov  9, %o1
a0095c1c:  7f ff ee 57  call  0xa0091578
a0095c20:  81 e8 00 00  restore
a0095c24:  01 00 00 00  nop
a0095c28:  81 c7 e0 08  ret
a0095c2c:  81 e8 00 00  restore
