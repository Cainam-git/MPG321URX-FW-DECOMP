# leon2m FUN_a00bf7dc 0xa00bf7dc-0xa00bfb28 (844 bytes)
a00bf7dc:  9d e3 bf 98  save  %sp, -104, %sp
a00bf7e0:  92 10 20 07  mov  7, %o1
a00bf7e4:  40 02 17 9f  call  0xa0145660
a00bf7e8:  90 10 20 00  clr  %o0
a00bf7ec:  b2 10 00 08  mov  %o0, %i1
a00bf7f0:  92 10 20 08  mov  8, %o1
a00bf7f4:  40 02 17 9b  call  0xa0145660
a00bf7f8:  90 10 20 00  clr  %o0
a00bf7fc:  a1 2e 60 10  sll  %i1, 0x10, %l0
a00bf800:  17 00 00 05  sethi  %hi(0x1400), %o3
a00bf804:  a1 34 20 10  srl  %l0, 0x10, %l0
a00bf808:  94 1c 00 0b  xor  %l0, %o3, %o2
a00bf80c:  91 2a 20 10  sll  %o0, 0x10, %o0
a00bf810:  80 a0 00 0a  cmp  %g0, %o2
a00bf814:  91 32 20 10  srl  %o0, 0x10, %o0
a00bf818:  9a 60 3f ff  subx  %g0, -1, %o5
a00bf81c:  92 1a 25 a0  xor  %o0, 0x5a0, %o1
a00bf820:  80 a0 00 09  cmp  %g0, %o1
a00bf824:  35 2a 00 b4  sethi  %hi(0xa802d000), %i2
a00bf828:  96 16 a0 78  or  %i2, 0x78, %o3	! 0xa802d078
a00bf82c:  82 10 20 30  mov  0x30, %g1
a00bf830:  98 60 3f ff  subx  %g0, -1, %o4
a00bf834:  c2 2a e0 08  stb  %g1, [ %o3 + 8 ]
a00bf838:  80 8b 40 0c  btst  %o5, %o4
a00bf83c:  02 80 00 32  be  0xa00bf904
a00bf840:  c2 2a e0 07  stb  %g1, [ %o3 + 7 ]
a00bf844:  82 10 20 3f  mov  0x3f, %g1
a00bf848:  c2 2a e0 09  stb  %g1, [ %o3 + 9 ]
a00bf84c:  92 10 20 00  clr  %o1
a00bf850:  40 02 53 7b  call  0xa015463c
a00bf854:  90 10 20 49  mov  0x49, %o0
a00bf858:  b2 16 a0 78  or  %i2, 0x78, %i1
a00bf85c:  94 10 20 62  mov  0x62, %o2
a00bf860:  d0 2e a0 78  stb  %o0, [ %i2 + 0x78 ]
a00bf864:  d4 2e 60 01  stb  %o2, [ %i1 + 1 ]
a00bf868:  92 10 20 02  mov  2, %o1
a00bf86c:  40 02 53 74  call  0xa015463c
a00bf870:  90 10 20 49  mov  0x49, %o0
a00bf874:  d0 2e 60 02  stb  %o0, [ %i1 + 2 ]
a00bf878:  92 10 20 03  mov  3, %o1
a00bf87c:  40 02 53 70  call  0xa015463c
a00bf880:  90 10 20 49  mov  0x49, %o0
a00bf884:  d0 2e 60 03  stb  %o0, [ %i1 + 3 ]
a00bf888:  92 10 20 04  mov  4, %o1
a00bf88c:  40 02 53 6c  call  0xa015463c
a00bf890:  90 10 20 49  mov  0x49, %o0
a00bf894:  d0 2e 60 04  stb  %o0, [ %i1 + 4 ]
a00bf898:  92 10 20 05  mov  5, %o1
a00bf89c:  40 02 53 68  call  0xa015463c
a00bf8a0:  90 10 20 49  mov  0x49, %o0
a00bf8a4:  d0 2e 60 05  stb  %o0, [ %i1 + 5 ]
a00bf8a8:  90 10 20 49  mov  0x49, %o0
a00bf8ac:  40 02 53 64  call  0xa015463c
a00bf8b0:  92 10 20 06  mov  6, %o1
a00bf8b4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bf8b8:  96 10 20 0d  mov  0xd, %o3
a00bf8bc:  d6 2e 60 0a  stb  %o3, [ %i1 + 0xa ]
a00bf8c0:  80 a6 20 02  cmp  %i0, 2
a00bf8c4:  02 80 00 30  be  0xa00bf984
a00bf8c8:  d0 2e 60 06  stb  %o0, [ %i1 + 6 ]
a00bf8cc:  80 a6 20 03  cmp  %i0, 3
a00bf8d0:  02 80 00 39  be  0xa00bf9b4
a00bf8d4:  19 2a 00 ac  sethi  %hi(0xa802b000), %o4
a00bf8d8:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00bf8dc:  9a 14 20 d0  or  %l0, 0xd0, %o5	! 0xa802d0d0
a00bf8e0:  c0 2b 20 9c  clrb  [ %o4 + 0x9c ]
a00bf8e4:  c0 2c 20 d0  clrb  [ %l0 + 0xd0 ]
a00bf8e8:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bf8ec:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bf8f0:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bf8f4:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bf8f8:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bf8fc:  40 02 23 bb  call  0xa01487e8
a00bf900:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bf904:  82 1c 2d 70  xor  %l0, 0xd70, %g1
a00bf908:  80 a0 00 01  cmp  %g0, %g1
a00bf90c:  9e 60 3f ff  subx  %g0, -1, %o7
a00bf910:  80 8b c0 0c  btst  %o7, %o4
a00bf914:  12 bf ff cd  bne  0xa00bf848
a00bf918:  82 10 20 3e  mov  0x3e, %g1
a00bf91c:  92 1c 2f 00  xor  %l0, 0xf00, %o1
a00bf920:  80 a0 00 09  cmp  %g0, %o1
a00bf924:  94 60 3f ff  subx  %g0, -1, %o2
a00bf928:  9a 1a 24 38  xor  %o0, 0x438, %o5
a00bf92c:  80 a0 00 0d  cmp  %g0, %o5
a00bf930:  92 60 3f ff  subx  %g0, -1, %o1
a00bf934:  80 8a 80 09  btst  %o2, %o1
a00bf938:  12 bf ff c4  bne  0xa00bf848
a00bf93c:  82 10 20 3d  mov  0x3d, %g1
a00bf940:  9e 1a 28 70  xor  %o0, 0x870, %o7
a00bf944:  80 a0 00 0f  cmp  %g0, %o7
a00bf948:  b2 60 3f ff  subx  %g0, -1, %i1
a00bf94c:  80 8a 80 19  btst  %o2, %i1
a00bf950:  12 bf ff be  bne  0xa00bf848
a00bf954:  82 10 20 3c  mov  0x3c, %g1
a00bf958:  94 1c 2a 00  xor  %l0, 0xa00, %o2
a00bf95c:  80 a0 00 0a  cmp  %g0, %o2
a00bf960:  82 60 3f ff  subx  %g0, -1, %g1
a00bf964:  80 88 40 09  btst  %g1, %o1
a00bf968:  32 bf ff b8  bne,a   0xa00bf848
a00bf96c:  82 10 20 3b  mov  0x3b, %g1
a00bf970:  80 88 40 0c  btst  %g1, %o4
a00bf974:  02 80 00 1c  be  0xa00bf9e4
a00bf978:  98 1c 27 80  xor  %l0, 0x780, %o4
a00bf97c:  10 bf ff b3  b  0xa00bf848
a00bf980:  82 10 20 3a  mov  0x3a, %g1
a00bf984:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bf988:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00bf98c:  9a 12 60 40  or  %o1, 0x40, %o5
a00bf990:  c0 2a 20 9a  clrb  [ %o0 + 0x9a ]
a00bf994:  c0 2a 60 40  clrb  [ %o1 + 0x40 ]
a00bf998:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bf99c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bf9a0:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bf9a4:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bf9a8:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bf9ac:  40 02 23 8f  call  0xa01487e8
a00bf9b0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bf9b4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00bf9b8:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00bf9bc:  9a 13 e0 98  or  %o7, 0x98, %o5
a00bf9c0:  c0 28 60 98  clrb  [ %g1 + 0x98 ]
a00bf9c4:  c0 2b e0 98  clrb  [ %o7 + 0x98 ]
a00bf9c8:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00bf9cc:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00bf9d0:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00bf9d4:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00bf9d8:  b4 16 a0 78  or  %i2, 0x78, %i2
a00bf9dc:  40 02 23 83  call  0xa01487e8
a00bf9e0:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bf9e4:  80 a0 00 0c  cmp  %g0, %o4
a00bf9e8:  98 60 3f ff  subx  %g0, -1, %o4
a00bf9ec:  82 1a 24 b0  xor  %o0, 0x4b0, %g1
a00bf9f0:  80 a0 00 01  cmp  %g0, %g1
a00bf9f4:  9a 60 3f ff  subx  %g0, -1, %o5
a00bf9f8:  80 8b 00 0d  btst  %o4, %o5
a00bf9fc:  12 bf ff 93  bne  0xa00bf848
a00bfa00:  82 10 20 39  mov  0x39, %g1
a00bfa04:  80 8b 00 09  btst  %o4, %o1
a00bfa08:  12 bf ff 90  bne  0xa00bf848
a00bfa0c:  82 10 20 38  mov  0x38, %g1
a00bfa10:  9e 1c 26 90  xor  %l0, 0x690, %o7
a00bfa14:  80 a0 00 0f  cmp  %g0, %o7
a00bfa18:  92 60 3f ff  subx  %g0, -1, %o1
a00bfa1c:  b2 1a 24 1a  xor  %o0, 0x41a, %i1
a00bfa20:  80 a0 00 19  cmp  %g0, %i1
a00bfa24:  94 60 3f ff  subx  %g0, -1, %o2
a00bfa28:  80 8a 40 0a  btst  %o1, %o2
a00bfa2c:  12 bf ff 87  bne  0xa00bf848
a00bfa30:  82 10 20 37  mov  0x37, %g1
a00bfa34:  98 1c 26 40  xor  %l0, 0x640, %o4
a00bfa38:  80 a0 00 0c  cmp  %g0, %o4
a00bfa3c:  9a 60 3f ff  subx  %g0, -1, %o5
a00bfa40:  82 1a 23 84  xor  %o0, 0x384, %g1
a00bfa44:  80 a0 00 01  cmp  %g0, %g1
a00bfa48:  98 60 3f ff  subx  %g0, -1, %o4
a00bfa4c:  80 8b 40 0c  btst  %o5, %o4
a00bfa50:  22 80 00 04  be,a   0xa00bfa60
a00bfa54:  96 1c 25 a0  xor  %l0, 0x5a0, %o3
a00bfa58:  10 bf ff 7c  b  0xa00bf848
a00bfa5c:  82 10 20 36  mov  0x36, %g1
a00bfa60:  80 a0 00 0b  cmp  %g0, %o3
a00bfa64:  82 60 3f ff  subx  %g0, -1, %g1
a00bfa68:  80 88 40 0c  btst  %g1, %o4
a00bfa6c:  02 80 00 06  be  0xa00bfa84
a00bfa70:  80 88 40 0a  btst  %g1, %o2
a00bfa74:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bfa78:  82 10 20 35  mov  0x35, %g1
a00bfa7c:  10 bf ff 74  b  0xa00bf84c
a00bfa80:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bfa84:  02 80 00 06  be  0xa00bfa9c
a00bfa88:  b2 1c 25 56  xor  %l0, 0x556, %i1
a00bfa8c:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bfa90:  82 10 20 34  mov  0x34, %g1
a00bfa94:  10 bf ff 6e  b  0xa00bf84c
a00bfa98:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bfa9c:  80 a0 00 19  cmp  %g0, %i1
a00bfaa0:  94 60 3f ff  subx  %g0, -1, %o2
a00bfaa4:  92 1a 23 00  xor  %o0, 0x300, %o1
a00bfaa8:  80 a0 00 09  cmp  %g0, %o1
a00bfaac:  96 60 3f ff  subx  %g0, -1, %o3
a00bfab0:  80 8a 80 0b  btst  %o2, %o3
a00bfab4:  02 80 00 06  be  0xa00bfacc
a00bfab8:  82 1c 25 00  xor  %l0, 0x500, %g1
a00bfabc:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bfac0:  82 10 20 33  mov  0x33, %g1
a00bfac4:  10 bf ff 62  b  0xa00bf84c
a00bfac8:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bfacc:  80 a0 00 01  cmp  %g0, %g1
a00bfad0:  9e 60 3f ff  subx  %g0, -1, %o7
a00bfad4:  9a 1a 24 00  xor  %o0, 0x400, %o5
a00bfad8:  80 a0 00 0d  cmp  %g0, %o5
a00bfadc:  90 60 3f ff  subx  %g0, -1, %o0
a00bfae0:  80 8b c0 08  btst  %o7, %o0
a00bfae4:  02 80 00 06  be  0xa00bfafc
a00bfae8:  98 1c 24 00  xor  %l0, 0x400, %o4
a00bfaec:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bfaf0:  82 10 20 32  mov  0x32, %g1
a00bfaf4:  10 bf ff 56  b  0xa00bf84c
a00bfaf8:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bfafc:  80 a0 00 0c  cmp  %g0, %o4
a00bfb00:  a0 60 3f ff  subx  %g0, -1, %l0
a00bfb04:  80 8c 00 0b  btst  %l0, %o3
a00bfb08:  02 80 00 05  be  0xa00bfb1c
a00bfb0c:  9a 16 a0 78  or  %i2, 0x78, %o5
a00bfb10:  82 10 20 31  mov  0x31, %g1
a00bfb14:  10 bf ff 4e  b  0xa00bf84c
a00bfb18:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00bfb1c:  82 10 20 30  mov  0x30, %g1
a00bfb20:  10 bf ff 4b  b  0xa00bf84c
a00bfb24:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
