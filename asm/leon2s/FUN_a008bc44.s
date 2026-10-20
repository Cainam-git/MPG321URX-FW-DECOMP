# leon2s FUN_a008bc44 0xa008bc44-0xa008bd1c (216 bytes)
a008bc44:  9d e3 bf 98  save  %sp, -104, %sp
a008bc48:  a4 10 20 00  clr  %l2
a008bc4c:  b0 0c a0 ff  and  %l2, 0xff, %i0
a008bc50:  92 10 20 50  mov  0x50, %o1
a008bc54:  40 00 6b d9  call  0xa00a6bb8
a008bc58:  90 10 00 18  mov  %i0, %o0
a008bc5c:  80 8a 20 40  btst  0x40, %o0
a008bc60:  12 80 00 1e  bne  0xa008bcd8
a008bc64:  a3 2e 20 02  sll  %i0, 2, %l1
a008bc68:  40 00 98 ff  call  0xa00b2064
a008bc6c:  01 00 00 00  nop
a008bc70:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a008bc74:  a0 10 63 4c  or  %g1, 0x34c, %l0	! 0xa8078b4c
a008bc78:  c2 04 00 11  ld  [ %l0 + %l1 ], %g1
a008bc7c:  90 22 00 01  sub  %o0, %g1, %o0
a008bc80:  80 a2 20 32  cmp  %o0, 0x32
a008bc84:  28 80 00 19  bleu,a   0xa008bce8
a008bc88:  a4 04 a0 01  inc  %l2
a008bc8c:  40 00 98 f6  call  0xa00b2064
a008bc90:  01 00 00 00  nop
a008bc94:  d0 24 00 11  st  %o0, [ %l0 + %l1 ]
a008bc98:  7f ff ff 0f  call  0xa008b8d4
a008bc9c:  90 10 00 18  mov  %i0, %o0
a008bca0:  03 2a 01 d9  sethi  %hi(0xa8076400), %g1
a008bca4:  80 8a 20 ff  btst  0xff, %o0
a008bca8:  12 80 00 04  bne  0xa008bcb8
a008bcac:  98 10 62 a0  or  %g1, 0x2a0, %o4
a008bcb0:  10 80 00 04  b  0xa008bcc0
a008bcb4:  c0 2b 00 18  clrb  [ %o4 + %i0 ]
a008bcb8:  82 10 20 01  mov  1, %g1
a008bcbc:  c2 2b 00 18  stb  %g1, [ %o4 + %i0 ]
a008bcc0:  90 10 00 18  mov  %i0, %o0
a008bcc4:  92 10 20 04  mov  4, %o1
a008bcc8:  40 00 6c be  call  0xa00a6fc0
a008bccc:  94 10 20 40  mov  0x40, %o2
a008bcd0:  10 80 00 06  b  0xa008bce8
a008bcd4:  a4 04 a0 01  inc  %l2
a008bcd8:  03 2a 01 d9  sethi  %hi(0xa8076400), %g1
a008bcdc:  82 10 62 a0  or  %g1, 0x2a0, %g1	! 0xa80766a0
a008bce0:  c0 28 40 18  clrb  [ %g1 + %i0 ]
a008bce4:  a4 04 a0 01  inc  %l2
a008bce8:  82 0c a0 ff  and  %l2, 0xff, %g1
a008bcec:  80 a0 60 01  cmp  %g1, 1
a008bcf0:  08 bf ff d8  bleu  0xa008bc50
a008bcf4:  b0 0c a0 ff  and  %l2, 0xff, %i0
a008bcf8:  1b 2a 01 d9  sethi  %hi(0xa8076400), %o5
a008bcfc:  82 13 62 a0  or  %o5, 0x2a0, %g1	! 0xa80766a0
a008bd00:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a008bd04:  f0 0b 62 a0  ldub  [ %o5 + 0x2a0 ], %i0
a008bd08:  82 00 40 01  add  %g1, %g1, %g1
a008bd0c:  b0 16 00 01  or  %i0, %g1, %i0
a008bd10:  b0 0e 20 ff  and  %i0, 0xff, %i0
a008bd14:  81 c7 e0 08  ret
a008bd18:  81 e8 00 00  restore
