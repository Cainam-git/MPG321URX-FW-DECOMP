# leon2m FUN_a0082b00 0xa0082b00-0xa0082c0c (268 bytes)
a0082b00:  9d e3 bf 78  save  %sp, -136, %sp
a0082b04:  13 00 03 fb  sethi  %hi(0xfec00), %o1
a0082b08:  92 12 60 f0  or  %o1, 0xf0, %o1	! 0xfecf0
a0082b0c:  94 10 20 1b  mov  0x1b, %o2
a0082b10:  40 02 e7 80  call  0xa013c910
a0082b14:  90 07 bf d8  add  %fp, -40, %o0
a0082b18:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0082b1c:  da 08 62 af  ldub  [ %g1 + 0x2af ], %o5	! 0xa802d2af
a0082b20:  80 a3 60 00  cmp  %o5, 0
a0082b24:  90 10 20 01  mov  1, %o0
a0082b28:  12 80 00 1c  bne  0xa0082b98
a0082b2c:  92 10 20 00  clr  %o1
a0082b30:  92 10 20 00  clr  %o1
a0082b34:  68 00 2e 24  call  0x4008e3c4
a0082b38:  90 10 20 00  clr  %o0
a0082b3c:  40 02 93 ae  call  0xa01279f4
a0082b40:  01 00 00 00  nop
a0082b44:  15 2a 00 b3  sethi  %hi(0xa802cc00), %o2
a0082b48:  80 8a 20 ff  btst  0xff, %o0
a0082b4c:  12 80 00 17  bne  0xa0082ba8
a0082b50:  9a 12 a3 f4  or  %o2, 0x3f4, %o5
a0082b54:  d0 13 60 04  lduh  [ %o5 + 4 ], %o0
a0082b58:  96 12 21 00  or  %o0, 0x100, %o3
a0082b5c:  80 8a 21 00  btst  0x100, %o0
a0082b60:  12 80 00 08  bne  0xa0082b80
a0082b64:  98 0a 3e ff  and  %o0, -257, %o4
a0082b68:  40 02 87 e4  call  0xa0124af8
a0082b6c:  d6 33 60 04  sth  %o3, [ %o5 + 4 ]
a0082b70:  40 02 87 d0  call  0xa0124ab0
a0082b74:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0082b78:  10 80 00 0e  b  0xa0082bb0
a0082b7c:  d2 0c 23 54  ldub  [ %l0 + 0x354 ], %o1	! 0xa802af54
a0082b80:  40 02 87 ba  call  0xa0124a68
a0082b84:  d8 33 60 04  sth  %o4, [ %o5 + 4 ]
a0082b88:  40 02 87 ee  call  0xa0124b40
a0082b8c:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0082b90:  10 80 00 08  b  0xa0082bb0
a0082b94:  d2 0c 23 54  ldub  [ %l0 + 0x354 ], %o1	! 0xa802af54
a0082b98:  40 03 2a 37  call  0xa014d474
a0082b9c:  01 00 00 00  nop
a0082ba0:  10 bf ff e5  b  0xa0082b34
a0082ba4:  92 10 20 00  clr  %o1	! 0x0
a0082ba8:  21 2a 00 ab  sethi  %hi(0xa802ac00), %l0
a0082bac:  d2 0c 23 54  ldub  [ %l0 + 0x354 ], %o1	! 0xa802af54
a0082bb0:  82 02 40 09  add  %o1, %o1, %g1
a0082bb4:  96 00 40 09  add  %g1, %o1, %o3
a0082bb8:  9a 07 bf f8  add  %fp, -8, %o5
a0082bbc:  9e 02 c0 0d  add  %o3, %o5, %o7
a0082bc0:  d6 0b ff e2  ldub  [ %o7 + -30 ], %o3
a0082bc4:  d2 0b ff e0  ldub  [ %o7 + -32 ], %o1
a0082bc8:  d4 0b ff e1  ldub  [ %o7 + -31 ], %o2
a0082bcc:  90 10 20 00  clr  %o0
a0082bd0:  40 03 0d 06  call  0xa0145fe8
a0082bd4:  98 10 20 00  clr  %o4
a0082bd8:  d8 0c 23 54  ldub  [ %l0 + 0x354 ], %o4
a0082bdc:  11 0e 38 e3  sethi  %hi(0x38e38c00), %o0
a0082be0:  96 03 20 01  add  %o4, 1, %o3
a0082be4:  94 12 22 39  or  %o0, 0x239, %o2
a0082be8:  80 52 c0 0a  umul  %o3, %o2, %g0
a0082bec:  93 40 00 00  rd  %y, %o1
a0082bf0:  83 32 60 01  srl  %o1, 1, %g1
a0082bf4:  9b 28 60 03  sll  %g1, 3, %o5
a0082bf8:  9e 03 40 01  add  %o5, %g1, %o7
a0082bfc:  98 22 c0 0f  sub  %o3, %o7, %o4
a0082c00:  d8 2c 23 54  stb  %o4, [ %l0 + 0x354 ]
a0082c04:  81 c7 e0 08  ret
a0082c08:  81 e8 00 00  restore
