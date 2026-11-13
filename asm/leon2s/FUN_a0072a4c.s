# leon2s FUN_a0072a4c 0xa0072a4c-0xa0072b04 (184 bytes)
a0072a4c:  9d e3 bf 98  save  %sp, -104, %sp
a0072a50:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0072a54:  80 a6 20 00  cmp  %i0, 0
a0072a58:  22 80 00 06  be,a   0xa0072a70
a0072a5c:  b6 0e e0 ff  and  %i3, 0xff, %i3
a0072a60:  80 a6 20 01  cmp  %i0, 1
a0072a64:  22 80 00 15  be,a   0xa0072ab8
a0072a68:  b6 0e e0 ff  and  %i3, 0xff, %i3
a0072a6c:  30 80 00 24  b,a   0xa0072afc
a0072a70:  80 a6 00 1b  cmp  %i0, %i3
a0072a74:  1a 80 00 22  bcc  0xa0072afc
a0072a78:  b0 10 20 00  clr  %i0
a0072a7c:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0072a80:  9b 2b 60 02  sll  %o5, 2, %o5
a0072a84:  82 0e 60 ff  and  %i1, 0xff, %g1
a0072a88:  11 27 c2 80  sethi  %hi(0x9f0a0000), %o0
a0072a8c:  82 00 40 0d  add  %g1, %o5, %g1
a0072a90:  90 12 21 00  or  %o0, 0x100, %o0
a0072a94:  90 00 40 08  add  %g1, %o0, %o0
a0072a98:  7f ff bb 8d  call  0xa00618cc
a0072a9c:  d2 06 80 0d  ld  [ %i2 + %o5 ], %o1
a0072aa0:  b0 06 20 01  inc  %i0
a0072aa4:  82 0e 20 ff  and  %i0, 0xff, %g1
a0072aa8:  80 a0 40 1b  cmp  %g1, %i3
a0072aac:  0a bf ff f5  bcs  0xa0072a80
a0072ab0:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0072ab4:  30 80 00 12  b,a   0xa0072afc
a0072ab8:  80 a6 e0 00  cmp  %i3, 0
a0072abc:  02 80 00 10  be  0xa0072afc
a0072ac0:  b0 10 20 00  clr  %i0
a0072ac4:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0072ac8:  9b 2b 60 02  sll  %o5, 2, %o5
a0072acc:  82 0e 60 ff  and  %i1, 0xff, %g1
a0072ad0:  11 27 c4 c0  sethi  %hi(0x9f130000), %o0
a0072ad4:  82 00 40 0d  add  %g1, %o5, %g1
a0072ad8:  90 12 21 00  or  %o0, 0x100, %o0
a0072adc:  90 00 40 08  add  %g1, %o0, %o0
a0072ae0:  7f ff bb 7b  call  0xa00618cc
a0072ae4:  d2 06 80 0d  ld  [ %i2 + %o5 ], %o1
a0072ae8:  b0 06 20 01  inc  %i0
a0072aec:  82 0e 20 ff  and  %i0, 0xff, %g1
a0072af0:  80 a0 40 1b  cmp  %g1, %i3
a0072af4:  0a bf ff f5  bcs  0xa0072ac8
a0072af8:  9a 0e 20 ff  and  %i0, 0xff, %o5
a0072afc:  81 c7 e0 08  ret
a0072b00:  81 e8 00 00  restore
