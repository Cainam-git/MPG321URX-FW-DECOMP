# leon2m FUN_a01439d8 0xa01439d8-0xa0143bc4 (492 bytes)
a01439d8:  9d e3 bf 98  save  %sp, -104, %sp
a01439dc:  90 10 20 03  mov  3, %o0
a01439e0:  7f ff c7 47  call  0xa01356fc
a01439e4:  92 10 20 00  clr  %o1
a01439e8:  82 0e 20 ff  and  %i0, 0xff, %g1
a01439ec:  9a 08 60 f0  and  %g1, 0xf0, %o5
a01439f0:  80 a3 60 10  cmp  %o5, 0x10
a01439f4:  02 80 00 0f  be  0xa0143a30
a01439f8:  80 a3 60 20  cmp  %o5, 0x20
a01439fc:  02 80 00 32  be  0xa0143ac4
a0143a00:  80 a3 60 40  cmp  %o5, 0x40
a0143a04:  02 80 00 39  be  0xa0143ae8
a0143a08:  92 0e 60 ff  and  %i1, 0xff, %o1
a0143a0c:  80 a0 60 00  cmp  %g1, 0
a0143a10:  02 80 00 46  be  0xa0143b28
a0143a14:  90 10 20 ff  mov  0xff, %o0
a0143a18:  80 a0 60 01  cmp  %g1, 1
a0143a1c:  02 80 00 42  be  0xa0143b24
a0143a20:  80 a0 60 02  cmp  %g1, 2
a0143a24:  12 80 00 66  bne  0xa0143bbc
a0143a28:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0143a2c:  30 80 00 3c  b,a   0xa0143b1c
a0143a30:  80 a0 60 12  cmp  %g1, 0x12
a0143a34:  02 80 00 09  be  0xa0143a58
a0143a38:  9a 10 20 02  mov  2, %o5
a0143a3c:  80 a0 60 12  cmp  %g1, 0x12
a0143a40:  14 80 00 33  bg  0xa0143b0c
a0143a44:  80 a0 60 13  cmp  %g1, 0x13
a0143a48:  80 a0 60 11  cmp  %g1, 0x11
a0143a4c:  02 80 00 03  be  0xa0143a58
a0143a50:  9a 10 20 01  mov  1, %o5
a0143a54:  9a 10 20 00  clr  %o5
a0143a58:  9e 0b 60 ff  and  %o5, 0xff, %o7
a0143a5c:  99 2b e0 04  sll  %o7, 4, %o4
a0143a60:  96 23 00 0f  sub  %o4, %o7, %o3
a0143a64:  15 2a 00 b7  sethi  %hi(0xa802dc00), %o2
a0143a68:  9b 2a e0 03  sll  %o3, 3, %o5
a0143a6c:  82 12 a3 30  or  %o2, 0x330, %g1
a0143a70:  d2 00 40 0d  ld  [ %g1 + %o5 ], %o1
a0143a74:  91 32 60 0c  srl  %o1, 0xc, %o0
a0143a78:  7f fe e7 6a  call  0xa00fd820
a0143a7c:  90 0a 20 0f  and  %o0, 0xf, %o0
a0143a80:  90 0a 20 ff  and  %o0, 0xff, %o0
a0143a84:  80 a2 20 b1  cmp  %o0, 0xb1
a0143a88:  02 80 00 49  be  0xa0143bac
a0143a8c:  01 00 00 00  nop
a0143a90:  80 a2 20 51  cmp  %o0, 0x51
a0143a94:  22 80 00 38  be,a   0xa0143b74
a0143a98:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0143a9c:  14 80 00 26  bg  0xa0143b34
a0143aa0:  80 a2 20 71  cmp  %o0, 0x71
a0143aa4:  80 a2 20 31  cmp  %o0, 0x31
a0143aa8:  02 80 00 35  be  0xa0143b7c
a0143aac:  80 a2 20 41  cmp  %o0, 0x41
a0143ab0:  12 80 00 43  bne  0xa0143bbc
a0143ab4:  01 00 00 00  nop
a0143ab8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0143abc:  40 00 37 fa  call  0xa0151aa4
a0143ac0:  91 e8 20 02  restore  %g0, 2, %o0
a0143ac4:  82 00 7f e0  add  %g1, -32, %g1
a0143ac8:  80 a0 60 07  cmp  %g1, 7
a0143acc:  18 80 00 3c  bgu  0xa0143bbc
a0143ad0:  1b 00 03 8c  sethi  %hi(0xe3000), %o5
a0143ad4:  91 28 60 02  sll  %g1, 2, %o0
a0143ad8:  92 13 60 54  or  %o5, 0x54, %o1
a0143adc:  f0 02 40 08  ld  [ %o1 + %o0 ], %i0
a0143ae0:  81 c6 00 00  jmp  %i0
a0143ae4:  01 00 00 00  nop
a0143ae8:  82 00 7f c0  add  %g1, -64, %g1
a0143aec:  80 a0 60 05  cmp  %g1, 5
a0143af0:  18 80 00 33  bgu  0xa0143bbc
a0143af4:  19 00 03 8c  sethi  %hi(0xe3000), %o4
a0143af8:  83 28 60 02  sll  %g1, 2, %g1
a0143afc:  96 13 20 3c  or  %o4, 0x3c, %o3
a0143b00:  d4 02 c0 01  ld  [ %o3 + %g1 ], %o2
a0143b04:  81 c2 80 00  jmp  %o2
a0143b08:  01 00 00 00  nop
a0143b0c:  12 bf ff d2  bne  0xa0143a54
a0143b10:  9a 10 20 03  mov  3, %o5	! 0x3
a0143b14:  10 bf ff d2  b  0xa0143a5c
a0143b18:  9e 0b 60 ff  and  %o5, 0xff, %o7
a0143b1c:  40 00 37 e2  call  0xa0151aa4
a0143b20:  91 e8 20 f0  restore  %g0, 0xf0, %o0
a0143b24:  90 10 20 0f  mov  0xf, %o0
a0143b28:  40 00 37 df  call  0xa0151aa4
a0143b2c:  01 00 00 00  nop
a0143b30:  30 80 00 23  b,a   0xa0143bbc
a0143b34:  02 80 00 15  be  0xa0143b88
a0143b38:  80 a2 20 71  cmp  %o0, 0x71
a0143b3c:  14 80 00 08  bg  0xa0143b5c
a0143b40:  80 a2 20 81  cmp  %o0, 0x81
a0143b44:  80 a2 20 61  cmp  %o0, 0x61
a0143b48:  12 80 00 1d  bne  0xa0143bbc
a0143b4c:  01 00 00 00  nop
a0143b50:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0143b54:  40 00 37 d4  call  0xa0151aa4
a0143b58:  91 e8 20 08  restore  %g0, 8, %o0
a0143b5c:  12 80 00 18  bne  0xa0143bbc
a0143b60:  01 00 00 00  nop
a0143b64:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0143b68:  40 00 37 cf  call  0xa0151aa4
a0143b6c:  91 e8 20 20  restore  %g0, 0x20, %o0
a0143b70:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0143b74:  40 00 37 cc  call  0xa0151aa4
a0143b78:  91 e8 20 04  restore  %g0, 4, %o0
a0143b7c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0143b80:  40 00 37 c9  call  0xa0151aa4
a0143b84:  91 e8 20 01  restore  %g0, 1, %o0
a0143b88:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0143b8c:  40 00 37 c6  call  0xa0151aa4
a0143b90:  91 e8 20 10  restore  %g0, 0x10, %o0
a0143b94:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0143b98:  40 00 37 c3  call  0xa0151aa4
a0143b9c:  91 e8 20 80  restore  %g0, 0x80, %o0
a0143ba0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a0143ba4:  40 00 37 c0  call  0xa0151aa4
a0143ba8:  91 e8 20 40  restore  %g0, 0x40, %o0
a0143bac:  7f ff b0 1d  call  0xa012fc20
a0143bb0:  01 00 00 00  nop
a0143bb4:  10 bf ff b7  b  0xa0143a90
a0143bb8:  90 0a 20 ff  and  %o0, 0xff, %o0
a0143bbc:  81 c7 e0 08  ret
a0143bc0:  81 e8 00 00  restore
