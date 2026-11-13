# leon2m FUN_a0120a18 0xa0120a18-0xa0120b38 (288 bytes)
a0120a18:  9d e3 bf 98  save  %sp, -104, %sp
a0120a1c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0120a20:  92 10 20 12  mov  0x12, %o1
a0120a24:  7f ff 45 f3  call  0xa00f21f0
a0120a28:  90 10 00 18  mov  %i0, %o0
a0120a2c:  13 00 00 07  sethi  %hi(0x1c00), %o1
a0120a30:  9e 12 63 ff  or  %o1, 0x3ff, %o7	! 0x1fff
a0120a34:  96 0a 00 0f  and  %o0, %o7, %o3
a0120a38:  9a 02 ff 6d  add  %o3, -147, %o5
a0120a3c:  95 2b 60 10  sll  %o5, 0x10, %o2
a0120a40:  83 32 a0 10  srl  %o2, 0x10, %g1
a0120a44:  98 12 62 ad  or  %o1, 0x2ad, %o4
a0120a48:  90 10 00 18  mov  %i0, %o0
a0120a4c:  80 a0 40 0c  cmp  %g1, %o4
a0120a50:  18 80 00 1b  bgu  0xa0120abc
a0120a54:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0120a58:  13 01 6e 36  sethi  %hi(0x5b8d800), %o1
a0120a5c:  81 80 00 00  mov  %g0, %y
a0120a60:  01 00 00 00  nop
a0120a64:  01 00 00 00  nop
a0120a68:  01 00 00 00  nop
a0120a6c:  82 72 40 0b  udiv  %o1, %o3, %g1
a0120a70:  11 14 7a e1  sethi  %hi(0x51eb8400), %o0
a0120a74:  96 00 60 32  add  %g1, 0x32, %o3
a0120a78:  98 12 21 1f  or  %o0, 0x11f, %o4
a0120a7c:  80 52 c0 0c  umul  %o3, %o4, %g0
a0120a80:  9f 40 00 00  rd  %y, %o7
a0120a84:  9b 33 e0 05  srl  %o7, 5, %o5
a0120a88:  da 34 21 e8  sth  %o5, [ %l0 + 0x1e8 ]
a0120a8c:  da 14 21 e8  lduh  [ %l0 + 0x1e8 ], %o5
a0120a90:  90 10 00 18  mov  %i0, %o0
a0120a94:  92 10 20 2e  mov  0x2e, %o1
a0120a98:  94 10 20 80  mov  0x80, %o2
a0120a9c:  80 a3 61 4c  cmp  %o5, 0x14c
a0120aa0:  08 80 00 21  bleu  0xa0120b24
a0120aa4:  96 10 20 01  mov  1, %o3
a0120aa8:  90 10 00 18  mov  %i0, %o0
a0120aac:  92 10 20 2e  mov  0x2e, %o1
a0120ab0:  94 10 20 80  mov  0x80, %o2
a0120ab4:  10 80 00 1c  b  0xa0120b24
a0120ab8:  96 10 20 00  clr  %o3
a0120abc:  7f ff 62 06  call  0xa00f92d4
a0120ac0:  01 00 00 00  nop
a0120ac4:  96 0a 20 ff  and  %o0, 0xff, %o3
a0120ac8:  92 10 20 57  mov  0x57, %o1
a0120acc:  80 a2 e0 01  cmp  %o3, 1
a0120ad0:  02 80 00 06  be  0xa0120ae8
a0120ad4:  90 10 00 18  mov  %i0, %o0
a0120ad8:  21 2a 00 b2  sethi  %hi(0xa802c800), %l0
a0120adc:  82 10 3f ff  mov  -1, %g1
a0120ae0:  10 bf ff eb  b  0xa0120a8c
a0120ae4:  c2 34 21 e8  sth  %g1, [ %l0 + 0x1e8 ]
a0120ae8:  7f ff 44 7f  call  0xa00f1ce4
a0120aec:  01 00 00 00  nop
a0120af0:  94 02 20 01  add  %o0, 1, %o2
a0120af4:  03 00 00 75  sethi  %hi(0x1d400), %g1
a0120af8:  93 2a a0 10  sll  %o2, 0x10, %o1
a0120afc:  91 32 60 10  srl  %o1, 0x10, %o0
a0120b00:  98 10 60 c0  or  %g1, 0xc0, %o4
a0120b04:  9b 3b 20 1f  sra  %o4, 0x1f, %o5
a0120b08:  81 83 60 00  mov  %o5, %y
a0120b0c:  01 00 00 00  nop
a0120b10:  01 00 00 00  nop
a0120b14:  01 00 00 00  nop
a0120b18:  82 7b 00 08  sdiv  %o4, %o0, %g1
a0120b1c:  10 bf ff dc  b  0xa0120a8c
a0120b20:  c2 34 21 e8  sth  %g1, [ %l0 + 0x1e8 ]
a0120b24:  7f ff 45 51  call  0xa00f2068
a0120b28:  01 00 00 00  nop
a0120b2c:  f0 14 21 e8  lduh  [ %l0 + 0x1e8 ], %i0
a0120b30:  81 c7 e0 08  ret
a0120b34:  81 e8 00 00  restore
