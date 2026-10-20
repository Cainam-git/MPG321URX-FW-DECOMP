# leon2m FUN_a00d7a70 0xa00d7a70-0xa00d7b20 (176 bytes)
a00d7a70:  9d e3 bf 78  save  %sp, -136, %sp
a00d7a74:  90 10 20 01  mov  1, %o0
a00d7a78:  7f ff f9 77  call  0xa00d6054
a00d7a7c:  92 07 bf e8  add  %fp, -24, %o1
a00d7a80:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00d7a84:  80 a6 20 00  cmp  %i0, 0
a00d7a88:  90 10 20 01  mov  1, %o0
a00d7a8c:  12 80 00 0f  bne  0xa00d7ac8
a00d7a90:  92 10 20 00  clr  %o1
a00d7a94:  d8 1f bf e8  ldd  [ %fp + -24 ], %o4
a00d7a98:  d4 1f bf f0  ldd  [ %fp + -16 ], %o2
a00d7a9c:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a00d7aa0:  d4 3f bf e0  std  %o2, [ %fp + -32 ]
a00d7aa4:  92 07 bf d8  add  %fp, -40, %o1
a00d7aa8:  40 01 c8 39  call  0xa0149b8c
a00d7aac:  90 10 20 01  mov  1, %o0
a00d7ab0:  40 01 c9 25  call  0xa0149f44
a00d7ab4:  90 10 20 01  mov  1, %o0
a00d7ab8:  80 a6 20 00  cmp  %i0, 0
a00d7abc:  02 80 00 16  be  0xa00d7b14
a00d7ac0:  90 10 20 32  mov  0x32, %o0
a00d7ac4:  30 80 00 0f  b,a   0xa00d7b00
a00d7ac8:  40 01 d6 6b  call  0xa014d474
a00d7acc:  01 00 00 00  nop
a00d7ad0:  d8 1f bf e8  ldd  [ %fp + -24 ], %o4
a00d7ad4:  d4 1f bf f0  ldd  [ %fp + -16 ], %o2
a00d7ad8:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a00d7adc:  d4 3f bf e0  std  %o2, [ %fp + -32 ]
a00d7ae0:  92 07 bf d8  add  %fp, -40, %o1
a00d7ae4:  40 01 c8 2a  call  0xa0149b8c
a00d7ae8:  90 10 20 01  mov  1, %o0
a00d7aec:  40 01 c9 16  call  0xa0149f44
a00d7af0:  90 10 20 01  mov  1, %o0
a00d7af4:  80 a6 20 00  cmp  %i0, 0
a00d7af8:  02 80 00 07  be  0xa00d7b14
a00d7afc:  90 10 20 32  mov  0x32, %o0
a00d7b00:  40 01 af 37  call  0xa01437dc
a00d7b04:  01 00 00 00  nop
a00d7b08:  90 10 20 01  mov  1, %o0	! 0x1
a00d7b0c:  40 01 d6 5a  call  0xa014d474
a00d7b10:  92 10 20 01  mov  1, %o1
a00d7b14:  01 00 00 00  nop
a00d7b18:  81 c7 e0 08  ret
a00d7b1c:  81 e8 00 00  restore
