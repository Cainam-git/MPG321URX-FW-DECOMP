# leon2m FUN_a0080978 0xa0080978-0xa0080af0 (376 bytes)
a0080978:  9d e3 bf 98  save  %sp, -104, %sp
a008097c:  40 01 f6 c0  call  0xa00fe47c
a0080980:  01 00 00 00  nop
a0080984:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a0080988:  a2 10 00 08  mov  %o0, %l1
a008098c:  b2 12 63 f4  or  %o1, 0x3f4, %i1
a0080990:  d8 16 60 04  lduh  [ %i1 + 4 ], %o4
a0080994:  11 00 00 18  sethi  %hi(0x6000), %o0
a0080998:  82 0a 00 0c  and  %o0, %o4, %g1
a008099c:  1b 00 00 10  sethi  %hi(0x4000), %o5
a00809a0:  80 a0 40 0d  cmp  %g1, %o5
a00809a4:  12 80 00 51  bne  0xa0080ae8
a00809a8:  01 00 00 00  nop
a00809ac:  40 02 9b e0  call  0xa012792c
a00809b0:  01 00 00 00  nop
a00809b4:  80 8a 20 ff  btst  0xff, %o0
a00809b8:  12 80 00 4c  bne  0xa0080ae8
a00809bc:  01 00 00 00  nop
a00809c0:  40 02 9b e1  call  0xa0127944
a00809c4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00809c8:  80 8a 20 ff  btst  0xff, %o0
a00809cc:  12 80 00 47  bne  0xa0080ae8
a00809d0:  01 00 00 00  nop
a00809d4:  40 02 9b b1  call  0xa0127898
a00809d8:  31 00 03 fb  sethi  %hi(0xfec00), %i0
a00809dc:  da 16 60 04  lduh  [ %i1 + 4 ], %o5
a00809e0:  11 00 00 18  sethi  %hi(0x6000), %o0
a00809e4:  82 2b 40 08  andn  %o5, %o0, %g1
a00809e8:  c2 36 60 04  sth  %g1, [ %i1 + 4 ]
a00809ec:  40 01 79 e1  call  0xa00df170
a00809f0:  90 16 21 68  or  %i0, 0x168, %o0
a00809f4:  40 02 8e 72  call  0xa01243bc
a00809f8:  90 10 20 01  mov  1, %o0
a00809fc:  9e 14 22 90  or  %l0, 0x290, %o7
a0080a00:  d6 03 e1 f4  ld  [ %o7 + 0x1f4 ], %o3
a0080a04:  15 10 00 00  sethi  %hi(0x40000000), %o2
a0080a08:  80 8a c0 0a  btst  %o3, %o2
a0080a0c:  02 80 00 31  be  0xa0080ad0
a0080a10:  01 00 00 00  nop
a0080a14:  40 02 90 4b  call  0xa0124b40
a0080a18:  b2 14 22 90  or  %l0, 0x290, %i1
a0080a1c:  40 02 90 13  call  0xa0124a68
a0080a20:  01 00 00 00  nop
a0080a24:  d2 06 61 f4  ld  [ %i1 + 0x1f4 ], %o1
a0080a28:  99 32 60 1e  srl  %o1, 0x1e, %o4
a0080a2c:  40 02 8e 64  call  0xa01243bc
a0080a30:  90 0b 20 01  and  %o4, 1, %o0
a0080a34:  40 01 63 d1  call  0xa00d9978
a0080a38:  b0 10 20 00  clr  %i0
a0080a3c:  40 01 67 46  call  0xa00da754
a0080a40:  d0 0e 60 ac  ldub  [ %i1 + 0xac ], %o0
a0080a44:  40 02 93 d1  call  0xa0125988
a0080a48:  b2 10 20 01  mov  1, %i1
a0080a4c:  40 02 9b de  call  0xa01279c4
a0080a50:  01 00 00 00  nop
a0080a54:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0080a58:  80 a4 20 01  cmp  %l0, 1
a0080a5c:  12 80 00 23  bne  0xa0080ae8
a0080a60:  90 10 20 00  clr  %o0
a0080a64:  40 02 9b b5  call  0xa0127938
a0080a68:  01 00 00 00  nop
a0080a6c:  40 02 9b b9  call  0xa0127950
a0080a70:  90 10 20 00  clr  %o0	! 0x0
a0080a74:  40 02 9b 9c  call  0xa01278e4
a0080a78:  90 10 20 00  clr  %o0
a0080a7c:  1f 00 03 fb  sethi  %hi(0xfec00), %o7
a0080a80:  90 13 e1 88  or  %o7, 0x188, %o0	! 0xfed88
a0080a84:  40 01 79 bb  call  0xa00df170
a0080a88:  01 00 00 00  nop
a0080a8c:  40 02 9b d1  call  0xa01279d0
a0080a90:  90 10 20 00  clr  %o0	! 0x0
a0080a94:  40 02 9b 97  call  0xa01278f0
a0080a98:  90 10 20 00  clr  %o0
a0080a9c:  40 02 9b b0  call  0xa012795c
a0080aa0:  90 10 20 00  clr  %o0
a0080aa4:  92 10 20 00  clr  %o1
a0080aa8:  40 00 38 f1  call  0xa008ee6c
a0080aac:  90 10 20 ff  mov  0xff, %o0
a0080ab0:  17 00 00 3f  sethi  %hi(0xfc00), %o3
a0080ab4:  94 12 e2 df  or  %o3, 0x2df, %o2	! 0xfedf
a0080ab8:  40 01 f6 65  call  0xa00fe44c
a0080abc:  90 0a 80 11  and  %o2, %l1, %o0
a0080ac0:  40 02 97 83  call  0xa01268cc
a0080ac4:  90 10 20 00  clr  %o0
a0080ac8:  40 03 11 99  call  0xa014512c
a0080acc:  81 e8 00 00  restore
a0080ad0:  40 02 90 1c  call  0xa0124b40
a0080ad4:  b2 14 22 90  or  %l0, 0x290, %i1
a0080ad8:  40 02 8f f6  call  0xa0124ab0
a0080adc:  01 00 00 00  nop
a0080ae0:  10 bf ff d2  b  0xa0080a28
a0080ae4:  d2 06 61 f4  ld  [ %i1 + 0x1f4 ], %o1
a0080ae8:  81 c7 e0 08  ret
a0080aec:  81 e8 00 00  restore
