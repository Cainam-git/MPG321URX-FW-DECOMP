# leon2s FUN_a007aac4 0xa007aac4-0xa007ab94 (208 bytes)
a007aac4:  9d e3 bf 90  save  %sp, -112, %sp
a007aac8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a007aacc:  21 3f ff c0  sethi  %hi(0xffff0000), %l0
a007aad0:  13 00 00 08  sethi  %hi(0x2000), %o1
a007aad4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007aad8:  96 0e a0 ff  and  %i2, 0xff, %o3
a007aadc:  92 12 60 64  or  %o1, 0x64, %o1
a007aae0:  94 14 20 ff  or  %l0, 0xff, %o2
a007aae4:  82 07 80 19  add  %fp, %i1, %g1
a007aae8:  9a 06 40 19  add  %i1, %i1, %o5
a007aaec:  f4 2f bf f0  stb  %i2, [ %fp + -16 ]
a007aaf0:  f6 2f bf f1  stb  %i3, [ %fp + -15 ]
a007aaf4:  f8 2f bf f2  stb  %i4, [ %fp + -14 ]
a007aaf8:  fa 2f bf f3  stb  %i5, [ %fp + -13 ]
a007aafc:  80 a6 60 03  cmp  %i1, 3
a007ab00:  90 10 00 18  mov  %i0, %o0
a007ab04:  08 80 00 18  bleu  0xa007ab64
a007ab08:  97 2a e0 08  sll  %o3, 8, %o3
a007ab0c:  40 00 b2 5f  call  0xa00a7488
a007ab10:  01 00 00 00  nop
a007ab14:  96 0e e0 ff  and  %i3, 0xff, %o3
a007ab18:  13 00 00 09  sethi  %hi(0x2400), %o1
a007ab1c:  92 12 60 64  or  %o1, 0x64, %o1	! 0x2464
a007ab20:  97 2a e0 08  sll  %o3, 8, %o3
a007ab24:  90 10 00 18  mov  %i0, %o0
a007ab28:  40 00 b2 58  call  0xa00a7488
a007ab2c:  94 14 20 ff  or  %l0, 0xff, %o2
a007ab30:  96 0f 20 ff  and  %i4, 0xff, %o3
a007ab34:  13 00 00 0a  sethi  %hi(0x2800), %o1
a007ab38:  92 12 60 64  or  %o1, 0x64, %o1	! 0x2864
a007ab3c:  97 2a e0 08  sll  %o3, 8, %o3
a007ab40:  90 10 00 18  mov  %i0, %o0
a007ab44:  40 00 b2 51  call  0xa00a7488
a007ab48:  94 14 20 ff  or  %l0, 0xff, %o2
a007ab4c:  13 00 00 0c  sethi  %hi(0x3000), %o1
a007ab50:  96 0f 60 ff  and  %i5, 0xff, %o3
a007ab54:  90 10 00 18  mov  %i0, %o0
a007ab58:  92 12 60 64  or  %o1, 0x64, %o1
a007ab5c:  10 80 00 09  b  0xa007ab80
a007ab60:  94 14 20 ff  or  %l0, 0xff, %o2
a007ab64:  d6 08 7f f0  ldub  [ %g1 + -16 ], %o3
a007ab68:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007ab6c:  82 10 62 fc  or  %g1, 0x2fc, %g1	! 0xa00b3afc
a007ab70:  15 3f ff c0  sethi  %hi(0xffff0000), %o2
a007ab74:  d2 10 40 0d  lduh  [ %g1 + %o5 ], %o1
a007ab78:  90 10 00 18  mov  %i0, %o0
a007ab7c:  94 12 a0 ff  or  %o2, 0xff, %o2
a007ab80:  40 00 b2 42  call  0xa00a7488
a007ab84:  97 2a e0 08  sll  %o3, 8, %o3
a007ab88:  01 00 00 00  nop
a007ab8c:  81 c7 e0 08  ret
a007ab90:  81 e8 00 00  restore
