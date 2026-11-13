# leon2m FUN_a013aa38 0xa013aa38-0xa013aae4 (172 bytes)
a013aa38:  9d e3 bf 90  save  %sp, -112, %sp
a013aa3c:  90 10 3f ff  mov  -1, %o0
a013aa40:  d0 27 bf f4  st  %o0, [ %fp + -12 ]
a013aa44:  90 10 20 02  mov  2, %o0
a013aa48:  92 10 20 20  mov  0x20, %o1
a013aa4c:  94 07 bf f4  add  %fp, -12, %o2
a013aa50:  67 fd 46 a0  call  0x4008c4d0
a013aa54:  96 10 20 01  mov  1, %o3
a013aa58:  c2 07 bf f4  ld  [ %fp + -12 ], %g1
a013aa5c:  80 a0 60 00  cmp  %g1, 0
a013aa60:  b0 0e 20 ff  and  %i0, 0xff, %i0
a013aa64:  02 80 00 10  be  0xa013aaa4
a013aa68:  a0 10 20 64  mov  0x64, %l0
a013aa6c:  67 fd 49 cd  call  0x4008d1a0
a013aa70:  90 10 20 01  mov  1, %o0
a013aa74:  90 10 20 02  mov  2, %o0
a013aa78:  92 10 20 20  mov  0x20, %o1
a013aa7c:  94 07 bf f4  add  %fp, -12, %o2
a013aa80:  67 fd 46 94  call  0x4008c4d0
a013aa84:  96 10 20 01  mov  1, %o3
a013aa88:  a0 04 3f ff  add  %l0, -1, %l0
a013aa8c:  80 a4 20 00  cmp  %l0, 0
a013aa90:  02 80 00 0f  be  0xa013aacc
a013aa94:  d2 07 bf f4  ld  [ %fp + -12 ], %o1
a013aa98:  80 a2 60 00  cmp  %o1, 0
a013aa9c:  12 bf ff f4  bne  0xa013aa6c
a013aaa0:  01 00 00 00  nop
a013aaa4:  98 0e 20 ff  and  %i0, 0xff, %o4
a013aaa8:  1b 10 80 00  sethi  %hi(0x42000000), %o5
a013aaac:  96 13 00 0d  or  %o4, %o5, %o3
a013aab0:  d6 27 bf f4  st  %o3, [ %fp + -12 ]
a013aab4:  90 10 20 02  mov  2, %o0
a013aab8:  92 10 20 20  mov  0x20, %o1
a013aabc:  94 07 bf f4  add  %fp, -12, %o2
a013aac0:  67 fd 46 ce  call  0x4008c5f8
a013aac4:  96 10 20 01  mov  1, %o3
a013aac8:  30 80 00 05  b,a   0xa013aadc
a013aacc:  d4 07 bf f4  ld  [ %fp + -12 ], %o2
a013aad0:  80 a2 a0 00  cmp  %o2, 0
a013aad4:  02 bf ff f5  be  0xa013aaa8
a013aad8:  98 0e 20 ff  and  %i0, 0xff, %o4
a013aadc:  81 c7 e0 08  ret
a013aae0:  81 e8 00 00  restore
