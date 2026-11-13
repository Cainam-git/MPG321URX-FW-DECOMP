# leon2m FUN_a0149e8c 0xa0149e8c-0xa0149f44 (184 bytes)
a0149e8c:  9d e3 bf 98  save  %sp, -104, %sp
a0149e90:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0149e94:  80 a6 20 01  cmp  %i0, 1
a0149e98:  02 80 00 0b  be  0xa0149ec4
a0149e9c:  90 10 20 01  mov  1, %o0
a0149ea0:  80 a6 20 01  cmp  %i0, 1
a0149ea4:  04 80 00 23  ble  0xa0149f30
a0149ea8:  80 a6 20 02  cmp  %i0, 2
a0149eac:  02 80 00 06  be  0xa0149ec4
a0149eb0:  90 10 20 02  mov  2, %o0
a0149eb4:  80 a6 20 03  cmp  %i0, 3
a0149eb8:  02 80 00 03  be  0xa0149ec4
a0149ebc:  90 10 20 03  mov  3, %o0
a0149ec0:  90 10 3f ff  mov  -1, %o0
a0149ec4:  b2 0a 20 ff  and  %o0, 0xff, %i1
a0149ec8:  80 a6 60 03  cmp  %i1, 3
a0149ecc:  38 80 00 15  bgu,a   0xa0149f20
a0149ed0:  11 00 06 9b  sethi  %hi(0x1a6c00), %o0
a0149ed4:  92 10 20 03  mov  3, %o1
a0149ed8:  7f ff 94 c5  call  0xa012f1ec
a0149edc:  90 10 00 19  mov  %i1, %o0
a0149ee0:  7f ff cb b2  call  0xa013cda8
a0149ee4:  90 10 00 19  mov  %i1, %o0
a0149ee8:  92 10 20 00  clr  %o1
a0149eec:  7f fe fd 62  call  0xa0109474
a0149ef0:  90 0a 20 ff  and  %o0, 0xff, %o0
a0149ef4:  7f ff cd e4  call  0xa013d684
a0149ef8:  90 10 00 19  mov  %i1, %o0
a0149efc:  7f ff ce 87  call  0xa013d918
a0149f00:  90 10 00 19  mov  %i1, %o0
a0149f04:  67 fd 0c a7  call  0x4008d1a0
a0149f08:  90 10 20 64  mov  0x64, %o0
a0149f0c:  7f ff cb a7  call  0xa013cda8
a0149f10:  90 10 00 19  mov  %i1, %o0
a0149f14:  b0 0a 20 ff  and  %o0, 0xff, %i0
a0149f18:  7f fe fd 57  call  0xa0109474
a0149f1c:  93 e8 20 01  restore  %g0, 1, %o1
a0149f20:  7f fe 54 94  call  0xa00df170
a0149f24:  90 12 21 d8  or  %o0, 0x1d8, %o0
a0149f28:  10 bf ff eb  b  0xa0149ed4
a0149f2c:  b2 10 20 00  clr  %i1
a0149f30:  80 a6 20 00  cmp  %i0, 0
a0149f34:  02 bf ff e4  be  0xa0149ec4
a0149f38:  90 10 20 00  clr  %o0
a0149f3c:  10 bf ff e2  b  0xa0149ec4
a0149f40:  90 10 3f ff  mov  -1, %o0
