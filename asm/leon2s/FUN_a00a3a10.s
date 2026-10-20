# leon2s FUN_a00a3a10 0xa00a3a10-0xa00a3b68 (344 bytes)
a00a3a10:  9d e3 bf 98  save  %sp, -104, %sp
a00a3a14:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a00a3a18:  a6 10 63 6c  or  %g1, 0x36c, %l3	! 0xa807db6c
a00a3a1c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00a3a20:  03 2a 01 e1  sethi  %hi(0xa8078400), %g1
a00a3a24:  a5 2e 20 02  sll  %i0, 2, %l2
a00a3a28:  a0 10 63 3c  or  %g1, 0x33c, %l0
a00a3a2c:  11 28 01 ae  sethi  %hi(0xa006b800), %o0
a00a3a30:  da 04 c0 12  ld  [ %l3 + %l2 ], %o5
a00a3a34:  c2 04 00 12  ld  [ %l0 + %l2 ], %g1
a00a3a38:  90 12 23 50  or  %o0, 0x350, %o0
a00a3a3c:  80 a3 40 01  cmp  %o5, %g1
a00a3a40:  02 80 00 06  be  0xa00a3a58
a00a3a44:  92 10 00 18  mov  %i0, %o1
a00a3a48:  7f ff 3d 7f  call  0xa0073044
a00a3a4c:  01 00 00 00  nop
a00a3a50:  c2 04 c0 12  ld  [ %l3 + %l2 ], %g1
a00a3a54:  c2 24 00 12  st  %g1, [ %l0 + %l2 ]
a00a3a58:  9a 10 20 01  mov  1, %o5
a00a3a5c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3a60:  92 10 20 40  mov  0x40, %o1
a00a3a64:  da 28 61 aa  stb  %o5, [ %g1 + 0x1aa ]
a00a3a68:  7f ff b8 bf  call  0xa0091d64
a00a3a6c:  90 10 00 18  mov  %i0, %o0
a00a3a70:  80 8a 20 40  btst  0x40, %o0
a00a3a74:  92 10 20 31  mov  0x31, %o1
a00a3a78:  02 80 00 38  be  0xa00a3b58
a00a3a7c:  90 10 00 18  mov  %i0, %o0
a00a3a80:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3a84:  82 10 61 f4  or  %g1, 0x1f4, %g1	! 0xa80791f4
a00a3a88:  d4 00 40 12  ld  [ %g1 + %l2 ], %o2
a00a3a8c:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3a90:  82 10 61 fc  or  %g1, 0x1fc, %g1	! 0xa80791fc
a00a3a94:  c2 00 40 12  ld  [ %g1 + %l2 ], %g1
a00a3a98:  95 2a a0 04  sll  %o2, 4, %o2
a00a3a9c:  94 12 80 01  or  %o2, %g1, %o2
a00a3aa0:  7f ff b8 95  call  0xa0091cf4
a00a3aa4:  94 0a a0 ff  and  %o2, 0xff, %o2
a00a3aa8:  90 10 00 18  mov  %i0, %o0
a00a3aac:  92 10 20 01  mov  1, %o1
a00a3ab0:  7f ff c4 05  call  0xa0094ac4
a00a3ab4:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a00a3ab8:  a0 14 21 f0  or  %l0, 0x1f0, %l0	! 0xa80791f0
a00a3abc:  23 2a 01 e1  sethi  %hi(0xa8078400), %l1
a00a3ac0:  d6 0c 63 33  ldub  [ %l1 + 0x333 ], %o3	! 0xa8078733
a00a3ac4:  90 10 00 18  mov  %i0, %o0
a00a3ac8:  92 10 20 04  mov  4, %o1
a00a3acc:  94 10 20 e2  mov  0xe2, %o2
a00a3ad0:  40 00 11 61  call  0xa00a8054
a00a3ad4:  c0 2c 00 18  clrb  [ %l0 + %i0 ]
a00a3ad8:  c2 0c 00 18  ldub  [ %l0 + %i0 ], %g1
a00a3adc:  82 00 40 01  add  %g1, %g1, %g1
a00a3ae0:  a2 14 63 32  or  %l1, 0x332, %l1
a00a3ae4:  d6 14 40 01  lduh  [ %l1 + %g1 ], %o3
a00a3ae8:  97 32 e0 08  srl  %o3, 8, %o3
a00a3aec:  92 10 20 04  mov  4, %o1
a00a3af0:  94 10 20 e3  mov  0xe3, %o2
a00a3af4:  40 00 11 58  call  0xa00a8054
a00a3af8:  90 10 00 18  mov  %i0, %o0
a00a3afc:  7f ff b8 1e  call  0xa0091b74
a00a3b00:  90 10 00 18  mov  %i0, %o0
a00a3b04:  7f ff b7 e1  call  0xa0091a88
a00a3b08:  90 10 00 18  mov  %i0, %o0
a00a3b0c:  7f ff b7 fd  call  0xa0091b00
a00a3b10:  90 10 00 18  mov  %i0, %o0
a00a3b14:  9b 2e 20 03  sll  %i0, 3, %o5
a00a3b18:  9a 23 40 18  sub  %o5, %i0, %o5
a00a3b1c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a3b20:  82 10 61 80  or  %g1, 0x180, %g1	! 0xa807d580
a00a3b24:  9b 2b 60 02  sll  %o5, 2, %o5
a00a3b28:  9a 03 40 01  add  %o5, %g1, %o5
a00a3b2c:  c2 03 60 14  ld  [ %o5 + 0x14 ], %g1
a00a3b30:  19 00 00 04  sethi  %hi(0x1000), %o4
a00a3b34:  82 08 77 ff  and  %g1, -2049, %g1
a00a3b38:  82 10 40 0c  or  %g1, %o4, %g1
a00a3b3c:  98 10 20 03  mov  3, %o4
a00a3b40:  d8 24 c0 12  st  %o4, [ %l3 + %l2 ]
a00a3b44:  c2 23 60 14  st  %g1, [ %o5 + 0x14 ]
a00a3b48:  03 2a 01 e4  sethi  %hi(0xa8079000), %g1
a00a3b4c:  82 10 61 e8  or  %g1, 0x1e8, %g1	! 0xa80791e8
a00a3b50:  10 80 00 04  b  0xa00a3b60
a00a3b54:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a00a3b58:  82 10 20 02  mov  2, %g1
a00a3b5c:  c2 24 c0 12  st  %g1, [ %l3 + %l2 ]
a00a3b60:  81 c7 e0 08  ret
a00a3b64:  91 e8 20 00  restore  %g0, 0, %o0
