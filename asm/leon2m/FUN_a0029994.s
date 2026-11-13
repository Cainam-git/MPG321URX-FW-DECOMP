# leon2m FUN_a0029994 0xa0029994-0xa0029aac (280 bytes)
a0029994:  9d e3 bf 98  save  %sp, -104, %sp
a0029998:  17 27 c0 00  sethi  %hi(0x9f000000), %o3
a002999c:  90 12 e0 90  or  %o3, 0x90, %o0	! 0x9f000090
a00299a0:  92 10 20 00  clr  %o1
a00299a4:  40 00 0a 31  call  0xa002c268
a00299a8:  94 10 20 02  mov  2, %o2
a00299ac:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a00299b0:  92 10 20 02  mov  2, %o1
a00299b4:  94 10 20 02  mov  2, %o2
a00299b8:  40 00 0a 2c  call  0xa002c268
a00299bc:  90 14 60 28  or  %l1, 0x28, %o0
a00299c0:  40 00 0a 24  call  0xa002c250
a00299c4:  90 14 60 70  or  %l1, 0x70, %o0
a00299c8:  a4 10 00 08  mov  %o0, %l2
a00299cc:  40 00 0a 21  call  0xa002c250
a00299d0:  90 14 60 38  or  %l1, 0x38, %o0
a00299d4:  a0 2c 80 08  andn  %l2, %o0, %l0
a00299d8:  15 00 00 3f  sethi  %hi(0xfc00), %o2
a00299dc:  92 12 a3 ff  or  %o2, 0x3ff, %o1	! 0xffff
a00299e0:  91 32 20 10  srl  %o0, 0x10, %o0
a00299e4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00299e8:  a4 0a 00 09  and  %o0, %o1, %l2
a00299ec:  a0 0c 00 09  and  %l0, %o1, %l0
a00299f0:  b0 10 61 70  or  %g1, 0x170, %i0
a00299f4:  b2 10 20 00  clr  %i1
a00299f8:  98 10 20 01  mov  1, %o4
a00299fc:  b5 2b 00 19  sll  %o4, %i1, %i2
a0029a00:  80 8e 80 10  btst  %i2, %l0
a0029a04:  22 80 00 0f  be,a   0xa0029a40
a0029a08:  b2 06 60 01  inc  %i1
a0029a0c:  c2 06 20 40  ld  [ %i0 + 0x40 ], %g1
a0029a10:  80 a0 60 00  cmp  %g1, 0
a0029a14:  22 80 00 0b  be,a   0xa0029a40
a0029a18:  b2 06 60 01  inc  %i1
a0029a1c:  92 10 00 1a  mov  %i2, %o1
a0029a20:  80 8e 80 12  btst  %i2, %l2
a0029a24:  02 80 00 1b  be  0xa0029a90
a0029a28:  90 14 60 70  or  %l1, 0x70, %o0
a0029a2c:  9f c0 40 00  call  %g1
a0029a30:  b2 06 60 01  inc  %i1
a0029a34:  92 10 00 1a  mov  %i2, %o1
a0029a38:  40 00 0a 09  call  0xa002c25c
a0029a3c:  90 14 60 70  or  %l1, 0x70, %o0
a0029a40:  b0 06 20 04  add  %i0, 4, %i0
a0029a44:  80 a6 60 05  cmp  %i1, 5
a0029a48:  08 bf ff ed  bleu  0xa00299fc
a0029a4c:  98 10 20 01  mov  1, %o4
a0029a50:  23 27 c0 80  sethi  %hi(0x9f020000), %l1
a0029a54:  90 14 60 34  or  %l1, 0x34, %o0	! 0x9f020034
a0029a58:  40 00 0a 01  call  0xa002c25c
a0029a5c:  92 10 20 02  mov  2, %o1
a0029a60:  31 27 c0 00  sethi  %hi(0x9f000000), %i0
a0029a64:  90 16 20 9c  or  %i0, 0x9c, %o0	! 0x9f00009c
a0029a68:  40 00 09 fd  call  0xa002c25c
a0029a6c:  92 10 20 02  mov  2, %o1
a0029a70:  90 14 60 28  or  %l1, 0x28, %o0
a0029a74:  92 10 20 00  clr  %o1
a0029a78:  40 00 09 fc  call  0xa002c268
a0029a7c:  94 10 20 02  mov  2, %o2
a0029a80:  b0 16 20 90  or  %i0, 0x90, %i0
a0029a84:  b2 10 20 02  mov  2, %i1
a0029a88:  40 00 09 f8  call  0xa002c268
a0029a8c:  95 e8 20 02  restore  %g0, 2, %o2
a0029a90:  40 00 09 f3  call  0xa002c25c
a0029a94:  b2 06 60 01  inc  %i1
a0029a98:  da 06 20 40  ld  [ %i0 + 0x40 ], %o5
a0029a9c:  9f c3 40 00  call  %o5
a0029aa0:  b0 06 20 04  add  %i0, 4, %i0
a0029aa4:  10 bf ff e9  b  0xa0029a48
a0029aa8:  80 a6 60 05  cmp  %i1, 5
