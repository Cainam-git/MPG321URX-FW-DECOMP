# leon2s FUN_a00d38a8 0xa00d38a8-0xa00d3c40 (920 bytes)
a00d38a8:  9d e3 bf 98  save  %sp, -104, %sp
a00d38ac:  03 2a 01 e3  sethi  %hi(0xa8078c00), %g1
a00d38b0:  c2 08 60 37  ldub  [ %g1 + 0x37 ], %g1	! 0xa8078c37
a00d38b4:  80 a0 60 00  cmp  %g1, 0
a00d38b8:  12 80 00 1a  bne  0xa00d3920
a00d38bc:  80 a0 60 01  cmp  %g1, 1
a00d38c0:  92 10 21 b4  mov  0x1b4, %o1
a00d38c4:  40 3b 8b 2e  call  0xa0fb657c
a00d38c8:  90 10 20 00  clr  %o0
a00d38cc:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00d38d0:  a0 14 21 48  or  %l0, 0x148, %l0	! 0xa807d548
a00d38d4:  90 0a 20 03  and  %o0, 3, %o0
a00d38d8:  d0 24 20 04  st  %o0, [ %l0 + 4 ]
a00d38dc:  92 10 21 c6  mov  0x1c6, %o1
a00d38e0:  40 3b 8b 27  call  0xa0fb657c
a00d38e4:  90 10 20 00  clr  %o0
a00d38e8:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00d38ec:  92 10 21 c7  mov  0x1c7, %o1
a00d38f0:  40 3b 8b 23  call  0xa0fb657c
a00d38f4:  90 10 20 00  clr  %o0
a00d38f8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d38fc:  91 2a 20 08  sll  %o0, 8, %o0
a00d3900:  90 02 00 11  add  %o0, %l1, %o0
a00d3904:  d0 34 20 1c  sth  %o0, [ %l0 + 0x1c ]
a00d3908:  92 10 21 ca  mov  0x1ca, %o1
a00d390c:  40 3b 8b 1c  call  0xa0fb657c
a00d3910:  90 10 20 00  clr  %o0
a00d3914:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00d3918:  10 80 00 1b  b  0xa00d3984
a00d391c:  90 10 20 00  clr  %o0
a00d3920:  12 80 00 1f  bne  0xa00d399c
a00d3924:  80 a0 60 02  cmp  %g1, 2
a00d3928:  92 10 21 b4  mov  0x1b4, %o1
a00d392c:  40 3b 8b 14  call  0xa0fb657c
a00d3930:  90 10 20 01  mov  1, %o0
a00d3934:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00d3938:  a0 14 21 48  or  %l0, 0x148, %l0	! 0xa807d548
a00d393c:  90 0a 20 03  and  %o0, 3, %o0
a00d3940:  d0 24 20 04  st  %o0, [ %l0 + 4 ]
a00d3944:  92 10 21 c6  mov  0x1c6, %o1
a00d3948:  40 3b 8b 0d  call  0xa0fb657c
a00d394c:  90 10 20 01  mov  1, %o0
a00d3950:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00d3954:  92 10 21 c7  mov  0x1c7, %o1
a00d3958:  40 3b 8b 09  call  0xa0fb657c
a00d395c:  90 10 20 01  mov  1, %o0
a00d3960:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3964:  91 2a 20 08  sll  %o0, 8, %o0
a00d3968:  90 02 00 11  add  %o0, %l1, %o0
a00d396c:  d0 34 20 1c  sth  %o0, [ %l0 + 0x1c ]
a00d3970:  92 10 21 ca  mov  0x1ca, %o1
a00d3974:  40 3b 8b 02  call  0xa0fb657c
a00d3978:  90 10 20 01  mov  1, %o0
a00d397c:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00d3980:  90 10 20 01  mov  1, %o0
a00d3984:  40 3b 8a fe  call  0xa0fb657c
a00d3988:  92 10 21 cb  mov  0x1cb, %o1
a00d398c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3990:  91 2a 20 08  sll  %o0, 8, %o0
a00d3994:  10 80 00 a0  b  0xa00d3c14
a00d3998:  90 02 00 11  add  %o0, %l1, %o0
a00d399c:  12 80 00 1a  bne  0xa00d3a04
a00d39a0:  80 a0 60 03  cmp  %g1, 3
a00d39a4:  92 10 25 04  mov  0x504, %o1
a00d39a8:  40 3b 8c 03  call  0xa0fb69b4
a00d39ac:  90 10 20 00  clr  %o0
a00d39b0:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00d39b4:  a0 14 21 48  or  %l0, 0x148, %l0	! 0xa807d548
a00d39b8:  90 0a 20 03  and  %o0, 3, %o0
a00d39bc:  d0 24 20 04  st  %o0, [ %l0 + 4 ]
a00d39c0:  92 10 25 16  mov  0x516, %o1
a00d39c4:  40 3b 8b fc  call  0xa0fb69b4
a00d39c8:  90 10 20 00  clr  %o0
a00d39cc:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00d39d0:  92 10 25 17  mov  0x517, %o1
a00d39d4:  40 3b 8b f8  call  0xa0fb69b4
a00d39d8:  90 10 20 00  clr  %o0
a00d39dc:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d39e0:  91 2a 20 08  sll  %o0, 8, %o0
a00d39e4:  90 02 00 11  add  %o0, %l1, %o0
a00d39e8:  d0 34 20 1c  sth  %o0, [ %l0 + 0x1c ]
a00d39ec:  92 10 25 1a  mov  0x51a, %o1
a00d39f0:  40 3b 8b f1  call  0xa0fb69b4
a00d39f4:  90 10 20 00  clr  %o0
a00d39f8:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00d39fc:  10 80 00 1b  b  0xa00d3a68
a00d3a00:  90 10 20 00  clr  %o0
a00d3a04:  12 80 00 1d  bne  0xa00d3a78
a00d3a08:  80 a0 60 04  cmp  %g1, 4
a00d3a0c:  92 10 25 04  mov  0x504, %o1
a00d3a10:  40 3b 8b e9  call  0xa0fb69b4
a00d3a14:  90 10 20 01  mov  1, %o0
a00d3a18:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00d3a1c:  a0 14 21 48  or  %l0, 0x148, %l0	! 0xa807d548
a00d3a20:  90 0a 20 03  and  %o0, 3, %o0
a00d3a24:  d0 24 20 04  st  %o0, [ %l0 + 4 ]
a00d3a28:  92 10 25 16  mov  0x516, %o1
a00d3a2c:  40 3b 8b e2  call  0xa0fb69b4
a00d3a30:  90 10 20 01  mov  1, %o0
a00d3a34:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00d3a38:  92 10 25 17  mov  0x517, %o1
a00d3a3c:  40 3b 8b de  call  0xa0fb69b4
a00d3a40:  90 10 20 01  mov  1, %o0
a00d3a44:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3a48:  91 2a 20 08  sll  %o0, 8, %o0
a00d3a4c:  90 02 00 11  add  %o0, %l1, %o0
a00d3a50:  d0 34 20 1c  sth  %o0, [ %l0 + 0x1c ]
a00d3a54:  92 10 25 1a  mov  0x51a, %o1
a00d3a58:  40 3b 8b d7  call  0xa0fb69b4
a00d3a5c:  90 10 20 01  mov  1, %o0
a00d3a60:  a2 0a 20 ff  and  %o0, 0xff, %l1
a00d3a64:  90 10 20 01  mov  1, %o0
a00d3a68:  40 3b 8b d3  call  0xa0fb69b4
a00d3a6c:  92 10 25 1b  mov  0x51b, %o1
a00d3a70:  10 bf ff c8  b  0xa00d3990
a00d3a74:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3a78:  12 80 00 31  bne  0xa00d3b3c
a00d3a7c:  80 a0 60 05  cmp  %g1, 5
a00d3a80:  94 10 20 06  mov  6, %o2
a00d3a84:  90 10 20 00  clr  %o0
a00d3a88:  40 3b 8c 5e  call  0xa0fb6c00
a00d3a8c:  92 10 20 73  mov  0x73, %o1
a00d3a90:  92 10 20 74  mov  0x74, %o1
a00d3a94:  40 3b 8c 49  call  0xa0fb6bb8
a00d3a98:  90 10 20 00  clr  %o0
a00d3a9c:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00d3aa0:  a0 14 21 48  or  %l0, 0x148, %l0	! 0xa807d548
a00d3aa4:  90 0a 20 03  and  %o0, 3, %o0
a00d3aa8:  d0 24 20 04  st  %o0, [ %l0 + 4 ]
a00d3aac:  94 10 20 18  mov  0x18, %o2
a00d3ab0:  90 10 20 00  clr  %o0
a00d3ab4:  40 3b 8c 53  call  0xa0fb6c00
a00d3ab8:  92 10 20 73  mov  0x73, %o1
a00d3abc:  92 10 20 74  mov  0x74, %o1
a00d3ac0:  40 3b 8c 3e  call  0xa0fb6bb8
a00d3ac4:  90 10 20 00  clr  %o0
a00d3ac8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3acc:  d0 34 20 1c  sth  %o0, [ %l0 + 0x1c ]
a00d3ad0:  94 10 20 19  mov  0x19, %o2
a00d3ad4:  90 10 20 00  clr  %o0
a00d3ad8:  40 3b 8c 4a  call  0xa0fb6c00
a00d3adc:  92 10 20 73  mov  0x73, %o1
a00d3ae0:  92 10 20 74  mov  0x74, %o1
a00d3ae4:  40 3b 8c 35  call  0xa0fb6bb8
a00d3ae8:  90 10 20 00  clr  %o0
a00d3aec:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3af0:  c2 14 20 1c  lduh  [ %l0 + 0x1c ], %g1
a00d3af4:  91 2a 20 08  sll  %o0, 8, %o0
a00d3af8:  90 02 00 01  add  %o0, %g1, %o0
a00d3afc:  d0 34 20 1c  sth  %o0, [ %l0 + 0x1c ]
a00d3b00:  94 10 20 1c  mov  0x1c, %o2
a00d3b04:  90 10 20 00  clr  %o0
a00d3b08:  40 3b 8c 3e  call  0xa0fb6c00
a00d3b0c:  92 10 20 73  mov  0x73, %o1
a00d3b10:  92 10 20 74  mov  0x74, %o1
a00d3b14:  40 3b 8c 29  call  0xa0fb6bb8
a00d3b18:  90 10 20 00  clr  %o0
a00d3b1c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3b20:  d0 34 20 20  sth  %o0, [ %l0 + 0x20 ]
a00d3b24:  90 10 20 00  clr  %o0
a00d3b28:  92 10 20 73  mov  0x73, %o1
a00d3b2c:  40 3b 8c 35  call  0xa0fb6c00
a00d3b30:  94 10 20 1d  mov  0x1d, %o2
a00d3b34:  10 80 00 32  b  0xa00d3bfc
a00d3b38:  90 10 20 00  clr  %o0
a00d3b3c:  12 80 00 38  bne  0xa00d3c1c
a00d3b40:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00d3b44:  94 10 20 06  mov  6, %o2
a00d3b48:  90 10 20 01  mov  1, %o0
a00d3b4c:  40 3b 8c 2d  call  0xa0fb6c00
a00d3b50:  92 10 20 73  mov  0x73, %o1
a00d3b54:  92 10 20 74  mov  0x74, %o1
a00d3b58:  40 3b 8c 18  call  0xa0fb6bb8
a00d3b5c:  90 10 20 01  mov  1, %o0
a00d3b60:  21 2a 01 f5  sethi  %hi(0xa807d400), %l0
a00d3b64:  a0 14 21 48  or  %l0, 0x148, %l0	! 0xa807d548
a00d3b68:  90 0a 20 03  and  %o0, 3, %o0
a00d3b6c:  d0 24 20 04  st  %o0, [ %l0 + 4 ]
a00d3b70:  94 10 20 18  mov  0x18, %o2
a00d3b74:  90 10 20 01  mov  1, %o0
a00d3b78:  40 3b 8c 22  call  0xa0fb6c00
a00d3b7c:  92 10 20 73  mov  0x73, %o1
a00d3b80:  92 10 20 74  mov  0x74, %o1
a00d3b84:  40 3b 8c 0d  call  0xa0fb6bb8
a00d3b88:  90 10 20 01  mov  1, %o0
a00d3b8c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3b90:  d0 34 20 1c  sth  %o0, [ %l0 + 0x1c ]
a00d3b94:  94 10 20 19  mov  0x19, %o2
a00d3b98:  90 10 20 01  mov  1, %o0
a00d3b9c:  40 3b 8c 19  call  0xa0fb6c00
a00d3ba0:  92 10 20 73  mov  0x73, %o1
a00d3ba4:  92 10 20 74  mov  0x74, %o1
a00d3ba8:  40 3b 8c 04  call  0xa0fb6bb8
a00d3bac:  90 10 20 01  mov  1, %o0
a00d3bb0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3bb4:  c2 14 20 1c  lduh  [ %l0 + 0x1c ], %g1
a00d3bb8:  91 2a 20 08  sll  %o0, 8, %o0
a00d3bbc:  90 02 00 01  add  %o0, %g1, %o0
a00d3bc0:  d0 34 20 1c  sth  %o0, [ %l0 + 0x1c ]
a00d3bc4:  94 10 20 1c  mov  0x1c, %o2
a00d3bc8:  90 10 20 01  mov  1, %o0
a00d3bcc:  40 3b 8c 0d  call  0xa0fb6c00
a00d3bd0:  92 10 20 73  mov  0x73, %o1
a00d3bd4:  92 10 20 74  mov  0x74, %o1
a00d3bd8:  40 3b 8b f8  call  0xa0fb6bb8
a00d3bdc:  90 10 20 01  mov  1, %o0
a00d3be0:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3be4:  d0 34 20 20  sth  %o0, [ %l0 + 0x20 ]
a00d3be8:  90 10 20 01  mov  1, %o0
a00d3bec:  92 10 20 73  mov  0x73, %o1
a00d3bf0:  40 3b 8c 04  call  0xa0fb6c00
a00d3bf4:  94 10 20 1d  mov  0x1d, %o2
a00d3bf8:  90 10 20 01  mov  1, %o0
a00d3bfc:  40 3b 8b ef  call  0xa0fb6bb8
a00d3c00:  92 10 20 74  mov  0x74, %o1
a00d3c04:  90 0a 20 ff  and  %o0, 0xff, %o0
a00d3c08:  91 2a 20 08  sll  %o0, 8, %o0
a00d3c0c:  c2 14 20 20  lduh  [ %l0 + 0x20 ], %g1
a00d3c10:  90 02 00 01  add  %o0, %g1, %o0
a00d3c14:  d0 34 20 20  sth  %o0, [ %l0 + 0x20 ]
a00d3c18:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00d3c1c:  98 10 61 48  or  %g1, 0x148, %o4	! 0xa807d548
a00d3c20:  03 00 00 09  sethi  %hi(0x2400), %g1
a00d3c24:  9a 10 63 10  or  %g1, 0x310, %o5	! 0x2710
a00d3c28:  c2 13 20 1c  lduh  [ %o4 + 0x1c ], %g1
a00d3c2c:  80 a0 40 0d  cmp  %g1, %o5
a00d3c30:  38 80 00 02  bgu,a   0xa00d3c38
a00d3c34:  da 33 20 1c  sth  %o5, [ %o4 + 0x1c ]
a00d3c38:  81 c7 e0 08  ret
a00d3c3c:  81 e8 00 00  restore
