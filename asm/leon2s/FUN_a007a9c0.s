# leon2s FUN_a007a9c0 0xa007a9c0-0xa007aac4 (260 bytes)
a007a9c0:  9d e3 bf 98  save  %sp, -104, %sp
a007a9c4:  82 0e 20 ff  and  %i0, 0xff, %g1
a007a9c8:  82 18 60 02  xor  %g1, 2, %g1
a007a9cc:  80 a0 00 01  cmp  %g0, %g1
a007a9d0:  a6 40 20 00  addx  %g0, 0, %l3
a007a9d4:  29 2a 01 f5  sethi  %hi(0xa807d400), %l4
a007a9d8:  9a 15 22 80  or  %l4, 0x280, %o5	! 0xa807d680
a007a9dc:  82 5c e0 b0  smul  %l3, 0xb0, %g1
a007a9e0:  c2 0b 40 01  ldub  [ %o5 + %g1 ], %g1
a007a9e4:  80 a0 60 00  cmp  %g1, 0
a007a9e8:  02 80 00 25  be  0xa007aa7c
a007a9ec:  a4 10 20 00  clr  %l2
a007a9f0:  a0 0c a0 ff  and  %l2, 0xff, %l0
a007a9f4:  82 0e 60 ff  and  %i1, 0xff, %g1
a007a9f8:  83 38 40 10  sra  %g1, %l0, %g1
a007a9fc:  80 88 60 01  btst  1, %g1
a007aa00:  02 80 00 18  be  0xa007aa60
a007aa04:  a4 04 a0 01  inc  %l2
a007aa08:  a2 04 00 10  add  %l0, %l0, %l1
a007aa0c:  90 10 20 01  mov  1, %o0
a007aa10:  92 10 20 10  mov  0x10, %o1
a007aa14:  80 a4 20 03  cmp  %l0, 3
a007aa18:  18 80 00 12  bgu  0xa007aa60
a007aa1c:  94 0e 20 ff  and  %i0, 0xff, %o2
a007aa20:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007aa24:  82 10 63 70  or  %g1, 0x370, %g1	! 0xa00b3b70
a007aa28:  40 00 b2 7f  call  0xa00a7424
a007aa2c:  d6 10 40 11  lduh  [ %g1 + %l1 ], %o3
a007aa30:  da 0e 80 10  ldub  [ %i2 + %l0 ], %o5
a007aa34:  d6 16 c0 11  lduh  [ %i3 + %l1 ], %o3
a007aa38:  03 28 02 ce  sethi  %hi(0xa00b3800), %g1
a007aa3c:  9a 0b 60 0f  and  %o5, 0xf, %o5
a007aa40:  97 2a e0 08  sll  %o3, 8, %o3
a007aa44:  82 10 63 18  or  %g1, 0x318, %g1
a007aa48:  15 3f c0 00  sethi  %hi(0xff000000), %o2
a007aa4c:  d2 10 40 11  lduh  [ %g1 + %l1 ], %o1
a007aa50:  96 13 40 0b  or  %o5, %o3, %o3
a007aa54:  94 12 a0 f0  or  %o2, 0xf0, %o2
a007aa58:  40 00 b2 8c  call  0xa00a7488
a007aa5c:  90 0e 20 ff  and  %i0, 0xff, %o0
a007aa60:  82 5c e0 b0  smul  %l3, 0xb0, %g1
a007aa64:  9a 15 22 80  or  %l4, 0x280, %o5
a007aa68:  da 0b 40 01  ldub  [ %o5 + %g1 ], %o5
a007aa6c:  82 0c a0 ff  and  %l2, 0xff, %g1
a007aa70:  80 a0 40 0d  cmp  %g1, %o5
a007aa74:  0a bf ff e0  bcs  0xa007a9f4
a007aa78:  a0 0c a0 ff  and  %l2, 0xff, %l0
a007aa7c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a007aa80:  90 10 00 18  mov  %i0, %o0
a007aa84:  7f ff fd 73  call  0xa007a050
a007aa88:  b2 0e 60 0f  and  %i1, 0xf, %i1
a007aa8c:  90 10 00 18  mov  %i0, %o0
a007aa90:  7f ff ff 43  call  0xa007a79c
a007aa94:  92 10 00 19  mov  %i1, %o1
a007aa98:  90 10 00 18  mov  %i0, %o0
a007aa9c:  7f ff fd 81  call  0xa007a0a0
a007aaa0:  92 10 00 19  mov  %i1, %o1
a007aaa4:  90 10 00 18  mov  %i0, %o0
a007aaa8:  7f ff fe e8  call  0xa007a648
a007aaac:  92 10 00 19  mov  %i1, %o1
a007aab0:  40 00 db 39  call  0xa00b1794
a007aab4:  90 10 20 01  mov  1, %o0
a007aab8:  7f ff fb da  call  0xa0079a20
a007aabc:  81 e8 00 00  restore
a007aac0:  01 00 00 00  nop
