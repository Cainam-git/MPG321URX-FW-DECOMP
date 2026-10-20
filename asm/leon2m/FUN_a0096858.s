# leon2m FUN_a0096858 0xa0096858-0xa0096b54 (764 bytes)
a0096858:  9d e3 bf 98  save  %sp, -104, %sp
a009685c:  90 10 20 00  clr  %o0
a0096860:  40 02 c1 58  call  0xa0146dc0
a0096864:  92 10 20 00  clr  %o1
a0096868:  23 2a 00 b3  sethi  %hi(0xa802cc00), %l1
a009686c:  96 14 63 f4  or  %l1, 0x3f4, %o3	! 0xa802cff4
a0096870:  31 2a 00 b4  sethi  %hi(0xa802d000), %i0
a0096874:  d8 12 e0 18  lduh  [ %o3 + 0x18 ], %o4
a0096878:  a0 16 22 90  or  %i0, 0x290, %l0
a009687c:  11 00 00 10  sethi  %hi(0x4000), %o0
a0096880:  da 0c 20 4a  ldub  [ %l0 + 0x4a ], %o5
a0096884:  82 2b 00 08  andn  %o4, %o0, %g1
a0096888:  80 a3 60 01  cmp  %o5, 1
a009688c:  02 80 00 8a  be  0xa0096ab4
a0096890:  c2 32 e0 18  sth  %g1, [ %o3 + 0x18 ]
a0096894:  7f ff b3 d4  call  0xa00837e4
a0096898:  01 00 00 00  nop
a009689c:  92 0a 20 ff  and  %o0, 0xff, %o1
a00968a0:  80 a2 60 01  cmp  %o1, 1
a00968a4:  02 80 00 7f  be  0xa0096aa0
a00968a8:  90 10 20 00  clr  %o0
a00968ac:  7f ff b3 ce  call  0xa00837e4
a00968b0:  01 00 00 00  nop
a00968b4:  94 0a 20 ff  and  %o0, 0xff, %o2
a00968b8:  80 a2 a0 01  cmp  %o2, 1
a00968bc:  22 80 00 68  be,a   0xa0096a5c
a00968c0:  de 04 20 b0  ld  [ %l0 + 0xb0 ], %o7
a00968c4:  7f ff b3 c8  call  0xa00837e4
a00968c8:  01 00 00 00  nop
a00968cc:  a0 0a 20 ff  and  %o0, 0xff, %l0
a00968d0:  80 a4 20 01  cmp  %l0, 1
a00968d4:  02 80 00 48  be  0xa00969f4
a00968d8:  a0 16 22 90  or  %i0, 0x290, %l0
a00968dc:  13 00 04 20  sethi  %hi(0x108000), %o1
a00968e0:  b0 16 22 90  or  %i0, 0x290, %i0
a00968e4:  90 12 61 20  or  %o1, 0x120, %o0
a00968e8:  21 2a 00 97  sethi  %hi(0xa8025c00), %l0
a00968ec:  d2 0e 21 a4  ldub  [ %i0 + 0x1a4 ], %o1
a00968f0:  40 01 22 20  call  0xa00df170
a00968f4:  d4 0c 20 56  ldub  [ %l0 + 0x56 ], %o2
a00968f8:  d0 0e 21 a4  ldub  [ %i0 + 0x1a4 ], %o0
a00968fc:  80 a2 20 03  cmp  %o0, 3
a0096900:  02 80 00 1e  be  0xa0096978
a0096904:  d8 0c 20 56  ldub  [ %l0 + 0x56 ], %o4
a0096908:  80 a3 20 03  cmp  %o4, 3
a009690c:  02 80 00 1c  be  0xa009697c
a0096910:  92 10 20 00  clr  %o1
a0096914:  40 02 b3 b2  call  0xa01437dc
a0096918:  90 10 20 32  mov  0x32, %o0
a009691c:  90 10 20 00  clr  %o0
a0096920:  40 02 c6 52  call  0xa0148268
a0096924:  92 10 20 01  mov  1, %o1
a0096928:  90 10 20 01  mov  1, %o0
a009692c:  40 02 c6 4f  call  0xa0148268
a0096930:  92 10 20 01  mov  1, %o1
a0096934:  d6 0c 20 56  ldub  [ %l0 + 0x56 ], %o3
a0096938:  80 a2 e0 05  cmp  %o3, 5
a009693c:  02 80 00 64  be  0xa0096acc
a0096940:  c2 0c 20 56  ldub  [ %l0 + 0x56 ], %g1
a0096944:  80 a0 60 06  cmp  %g1, 6
a0096948:  02 80 00 72  be  0xa0096b10
a009694c:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0
a0096950:  80 a2 20 04  cmp  %o0, 4
a0096954:  02 80 00 67  be  0xa0096af0
a0096958:  01 00 00 00  nop
a009695c:  7f ff b3 a2  call  0xa00837e4
a0096960:  01 00 00 00  nop
a0096964:  92 0a 20 ff  and  %o0, 0xff, %o1
a0096968:  80 a2 60 01  cmp  %o1, 1
a009696c:  12 80 00 78  bne  0xa0096b4c
a0096970:  b0 10 20 00  clr  %i0
a0096974:  30 80 00 1e  b,a   0xa00969ec
a0096978:  92 10 20 00  clr  %o1
a009697c:  40 01 0c 1f  call  0xa00d99f8
a0096980:  90 10 20 02  mov  2, %o0
a0096984:  40 02 b6 c2  call  0xa014448c
a0096988:  90 10 20 00  clr  %o0
a009698c:  40 02 b7 1c  call  0xa01445fc
a0096990:  90 0a 20 ff  and  %o0, 0xff, %o0
a0096994:  80 8a 20 ff  btst  0xff, %o0
a0096998:  02 80 00 07  be  0xa00969b4
a009699c:  90 10 20 00  clr  %o0
a00969a0:  e0 06 20 ac  ld  [ %i0 + 0xac ], %l0
a00969a4:  31 00 04 00  sethi  %hi(0x100000), %i0
a00969a8:  80 8c 00 18  btst  %l0, %i0
a00969ac:  12 80 00 34  bne  0xa0096a7c
a00969b0:  94 14 63 f4  or  %l1, 0x3f4, %o2
a00969b4:  40 02 c6 2d  call  0xa0148268
a00969b8:  92 10 20 01  mov  1, %o1
a00969bc:  90 10 20 01  mov  1, %o0
a00969c0:  40 02 c6 2a  call  0xa0148268
a00969c4:  92 10 20 01  mov  1, %o1
a00969c8:  90 10 20 04  mov  4, %o0
a00969cc:  92 10 20 01  mov  1, %o1
a00969d0:  40 02 cf c1  call  0xa014a8d4
a00969d4:  94 10 23 e8  mov  0x3e8, %o2
a00969d8:  7f ff b3 83  call  0xa00837e4
a00969dc:  b0 10 20 02  mov  2, %i0
a00969e0:  80 8a 20 ff  btst  0xff, %o0
a00969e4:  32 80 00 02  bne,a   0xa00969ec
a00969e8:  b0 10 20 00  clr  %i0
a00969ec:  40 02 cc 81  call  0xa0149bf0
a00969f0:  81 e8 00 00  restore
a00969f4:  da 04 20 a8  ld  [ %l0 + 0xa8 ], %o5
a00969f8:  80 8b 60 80  btst  0x80, %o5
a00969fc:  02 bf ff b9  be  0xa00968e0
a0096a00:  13 00 04 20  sethi  %hi(0x108000), %o1
a0096a04:  98 14 63 f4  or  %l1, 0x3f4, %o4
a0096a08:  da 13 20 04  lduh  [ %o4 + 4 ], %o5
a0096a0c:  11 3f ff e0  sethi  %hi(0xffff8000), %o0
a0096a10:  82 0b 40 08  and  %o5, %o0, %g1
a0096a14:  97 28 60 10  sll  %g1, 0x10, %o3
a0096a18:  80 a2 e0 00  cmp  %o3, 0
a0096a1c:  12 80 00 46  bne  0xa0096b34
a0096a20:  92 13 64 00  or  %o5, 0x400, %o1
a0096a24:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0096a28:  40 00 79 96  call  0xa00b5080
a0096a2c:  c0 20 63 ec  clr  [ %g1 + 0x3ec ]	! 0xa802afec
a0096a30:  d6 04 20 a8  ld  [ %l0 + 0xa8 ], %o3
a0096a34:  9a 0a ff 7f  and  %o3, -129, %o5
a0096a38:  40 02 39 43  call  0xa0124f44
a0096a3c:  da 24 20 a8  st  %o5, [ %l0 + 0xa8 ]
a0096a40:  40 01 0d d1  call  0xa00da184
a0096a44:  01 00 00 00  nop
a0096a48:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a0096a4c:  de 0b 20 8e  ldub  [ %o4 + 0x8e ], %o7	! 0xa802b08e
a0096a50:  94 13 e0 02  or  %o7, 2, %o2
a0096a54:  10 bf ff a2  b  0xa00968dc
a0096a58:  d4 2b 20 8e  stb  %o2, [ %o4 + 0x8e ]
a0096a5c:  80 a3 e0 00  cmp  %o7, 0
a0096a60:  02 bf ff 99  be  0xa00968c4
a0096a64:  01 00 00 00  nop
a0096a68:  40 00 f7 cc  call  0xa00d4998
a0096a6c:  c0 24 20 b0  clr  [ %l0 + 0xb0 ]
a0096a70:  40 00 fd 33  call  0xa00d5f3c
a0096a74:  01 00 00 00  nop
a0096a78:  30 bf ff 93  b,a   0xa00968c4
a0096a7c:  da 12 a0 0a  lduh  [ %o2 + 0xa ], %o5
a0096a80:  9e 13 60 40  or  %o5, 0x40, %o7
a0096a84:  23 00 00 04  sethi  %hi(0x1000), %l1
a0096a88:  de 32 a0 0a  sth  %o7, [ %o2 + 0xa ]
a0096a8c:  92 14 63 88  or  %l1, 0x388, %o1
a0096a90:  7f ff bf c8  call  0xa00869b0
a0096a94:  90 10 20 14  mov  0x14, %o0
a0096a98:  10 bf ff c7  b  0xa00969b4
a0096a9c:  90 10 20 00  clr  %o0
a0096aa0:  40 00 fd 03  call  0xa00d5eac
a0096aa4:  c0 2c 20 4a  clrb  [ %l0 + 0x4a ]
a0096aa8:  40 01 0d eb  call  0xa00da254
a0096aac:  01 00 00 00  nop
a0096ab0:  30 bf ff 7f  b,a   0xa00968ac
a0096ab4:  40 02 98 bd  call  0xa013cda8
a0096ab8:  90 10 20 01  mov  1, %o0
a0096abc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0096ac0:  40 01 ca 6d  call  0xa0109474
a0096ac4:  92 10 20 00  clr  %o1
a0096ac8:  30 bf ff 73  b,a   0xa0096894
a0096acc:  7f ff b3 46  call  0xa00837e4
a0096ad0:  01 00 00 00  nop
a0096ad4:  80 8a 20 ff  btst  0xff, %o0
a0096ad8:  32 bf ff 9b  bne,a   0xa0096944
a0096adc:  c2 0c 20 56  ldub  [ %l0 + 0x56 ], %g1
a0096ae0:  40 02 cc 44  call  0xa0149bf0
a0096ae4:  90 10 20 02  mov  2, %o0
a0096ae8:  10 bf ff 97  b  0xa0096944
a0096aec:  c2 0c 20 56  ldub  [ %l0 + 0x56 ], %g1
a0096af0:  7f ff b3 3d  call  0xa00837e4
a0096af4:  01 00 00 00  nop
a0096af8:  80 8a 20 ff  btst  0xff, %o0
a0096afc:  12 bf ff 98  bne  0xa009695c
a0096b00:  01 00 00 00  nop
a0096b04:  40 02 cc 3b  call  0xa0149bf0
a0096b08:  90 10 20 02  mov  2, %o0	! 0x2
a0096b0c:  30 bf ff 94  b,a   0xa009695c
a0096b10:  7f ff b3 35  call  0xa00837e4
a0096b14:  01 00 00 00  nop
a0096b18:  80 8a 20 ff  btst  0xff, %o0
a0096b1c:  32 bf ff 8d  bne,a   0xa0096950
a0096b20:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0
a0096b24:  40 02 cc 33  call  0xa0149bf0
a0096b28:  90 10 20 02  mov  2, %o0
a0096b2c:  10 bf ff 89  b  0xa0096950
a0096b30:  d0 0c 20 56  ldub  [ %l0 + 0x56 ], %o0
a0096b34:  d2 33 20 04  sth  %o1, [ %o4 + 4 ]
a0096b38:  90 10 20 04  mov  4, %o0
a0096b3c:  7f ff a7 5c  call  0xa00808ac
a0096b40:  92 10 20 00  clr  %o1
a0096b44:  10 bf ff b9  b  0xa0096a28
a0096b48:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0096b4c:  81 c7 e0 08  ret
a0096b50:  81 e8 00 00  restore
