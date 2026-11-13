# leon2m FUN_a0152e28 0xa0152e28-0xa0152f70 (296 bytes)
a0152e28:  9d e3 bf 90  save  %sp, -112, %sp
a0152e2c:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a0152e30:  da 00 63 d0  ld  [ %g1 + 0x3d0 ], %o5	! 0xa802e3d0
a0152e34:  80 a3 60 00  cmp  %o5, 0
a0152e38:  c0 2f bf f7  clrb  [ %fp + -9 ]
a0152e3c:  06 80 00 1d  bl  0xa0152eb0
a0152e40:  9a 10 20 01  mov  1, %o5
a0152e44:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0152e48:  c2 0a a1 a7  ldub  [ %o2 + 0x1a7 ], %g1	! 0xa802e1a7
a0152e4c:  80 a0 60 07  cmp  %g1, 7
a0152e50:  08 80 00 13  bleu  0xa0152e9c
a0152e54:  21 00 03 c4  sethi  %hi(0xf1000), %l0
a0152e58:  a2 0b 60 ff  and  %o5, 0xff, %l1
a0152e5c:  80 a4 60 00  cmp  %l1, 0
a0152e60:  02 80 00 3a  be  0xa0152f48
a0152e64:  a0 10 20 00  clr  %l0
a0152e68:  90 10 20 00  clr  %o0
a0152e6c:  7f ff 73 81  call  0xa012fc70
a0152e70:  a0 04 20 01  inc  %l0
a0152e74:  90 0a 20 ff  and  %o0, 0xff, %o0
a0152e78:  92 10 00 18  mov  %i0, %o1
a0152e7c:  7f ff fe e9  call  0xa0152a20
a0152e80:  94 07 bf f7  add  %fp, -9, %o2
a0152e84:  90 0c 20 ff  and  %l0, 0xff, %o0
a0152e88:  80 a2 00 11  cmp  %o0, %l1
a0152e8c:  0a bf ff f8  bcs  0xa0152e6c
a0152e90:  92 10 00 18  mov  %i0, %o1
a0152e94:  10 80 00 2f  b  0xa0152f50
a0152e98:  90 10 20 ff  mov  0xff, %o0
a0152e9c:  97 28 60 02  sll  %g1, 2, %o3
a0152ea0:  9e 14 22 6c  or  %l0, 0x26c, %o7
a0152ea4:  d8 03 c0 0b  ld  [ %o7 + %o3 ], %o4
a0152ea8:  81 c3 00 00  jmp  %o4
a0152eac:  01 00 00 00  nop
a0152eb0:  90 10 20 51  mov  0x51, %o0	! 0x51
a0152eb4:  92 10 00 18  mov  %i0, %o1
a0152eb8:  7f ff fe da  call  0xa0152a20
a0152ebc:  94 07 bf f7  add  %fp, -9, %o2
a0152ec0:  90 10 20 61  mov  0x61, %o0
a0152ec4:  92 10 00 18  mov  %i0, %o1
a0152ec8:  7f ff fe d6  call  0xa0152a20
a0152ecc:  94 07 bf f7  add  %fp, -9, %o2
a0152ed0:  7f ff 5f a7  call  0xa012ad6c
a0152ed4:  01 00 00 00  nop
a0152ed8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0152edc:  80 a2 20 01  cmp  %o0, 1
a0152ee0:  02 80 00 03  be  0xa0152eec
a0152ee4:  90 10 20 81  mov  0x81, %o0
a0152ee8:  90 10 20 71  mov  0x71, %o0
a0152eec:  92 10 00 18  mov  %i0, %o1
a0152ef0:  7f ff fe cc  call  0xa0152a20
a0152ef4:  94 07 bf f7  add  %fp, -9, %o2
a0152ef8:  7f ff 5f 9d  call  0xa012ad6c
a0152efc:  01 00 00 00  nop
a0152f00:  92 0a 20 ff  and  %o0, 0xff, %o1
a0152f04:  80 a2 60 01  cmp  %o1, 1
a0152f08:  02 80 00 03  be  0xa0152f14
a0152f0c:  90 10 20 71  mov  0x71, %o0
a0152f10:  90 10 20 81  mov  0x81, %o0
a0152f14:  92 10 00 18  mov  %i0, %o1
a0152f18:  7f ff fe c2  call  0xa0152a20
a0152f1c:  94 07 bf f7  add  %fp, -9, %o2
a0152f20:  10 80 00 0b  b  0xa0152f4c
a0152f24:  92 10 00 18  mov  %i0, %o1
a0152f28:  10 bf ff cc  b  0xa0152e58
a0152f2c:  9a 10 20 04  mov  4, %o5
a0152f30:  10 bf ff ca  b  0xa0152e58
a0152f34:  9a 10 20 03  mov  3, %o5
a0152f38:  10 bf ff c8  b  0xa0152e58
a0152f3c:  9a 10 20 02  mov  2, %o5
a0152f40:  10 bf ff c6  b  0xa0152e58
a0152f44:  9a 10 20 01  mov  1, %o5
a0152f48:  92 10 00 18  mov  %i0, %o1
a0152f4c:  90 10 20 ff  mov  0xff, %o0
a0152f50:  7f ff fe b4  call  0xa0152a20
a0152f54:  94 07 bf f7  add  %fp, -9, %o2
a0152f58:  da 0f bf f7  ldub  [ %fp + -9 ], %o5
a0152f5c:  a2 03 40 0d  add  %o5, %o5, %l1
a0152f60:  b0 04 40 0d  add  %l1, %o5, %i0
a0152f64:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0152f68:  81 c7 e0 08  ret
a0152f6c:  81 e8 00 00  restore
