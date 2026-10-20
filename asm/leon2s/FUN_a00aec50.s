# leon2s FUN_a00aec50 0xa00aec50-0xa00aee08 (440 bytes)
a00aec50:  9d e3 bf 98  save  %sp, -104, %sp
a00aec54:  80 8e 60 ff  btst  0xff, %i1
a00aec58:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00aec5c:  b2 10 20 00  clr  %i1
a00aec60:  02 80 00 0e  be  0xa00aec98
a00aec64:  21 2a 01 e4  sethi  %hi(0xa8079000), %l0
a00aec68:  90 10 00 18  mov  %i0, %o0
a00aec6c:  92 10 20 00  clr  %o1
a00aec70:  7f ff e0 d4  call  0xa00a6fc0
a00aec74:  94 10 20 04  mov  4, %o2
a00aec78:  90 10 00 18  mov  %i0, %o0
a00aec7c:  92 10 24 e0  mov  0x4e0, %o1
a00aec80:  7f ff df e0  call  0xa00a6c00
a00aec84:  94 10 20 08  mov  8, %o2
a00aec88:  40 00 0c f7  call  0xa00b2064
a00aec8c:  b0 0e 60 01  and  %i1, 1, %i0
a00aec90:  10 80 00 5c  b  0xa00aee00
a00aec94:  d0 24 23 28  st  %o0, [ %l0 + 0x328 ]
a00aec98:  40 00 0c f3  call  0xa00b2064
a00aec9c:  a2 10 00 10  mov  %l0, %l1
a00aeca0:  c2 04 23 28  ld  [ %l0 + 0x328 ], %g1
a00aeca4:  90 22 00 01  sub  %o0, %g1, %o0
a00aeca8:  80 a2 20 10  cmp  %o0, 0x10
a00aecac:  18 80 00 03  bgu  0xa00aecb8
a00aecb0:  82 10 20 01  mov  1, %g1
a00aecb4:  82 10 20 00  clr  %g1
a00aecb8:  80 88 60 ff  btst  0xff, %g1
a00aecbc:  12 80 00 46  bne  0xa00aedd4
a00aecc0:  90 10 00 18  mov  %i0, %o0
a00aecc4:  7f ff fa 69  call  0xa00ad668
a00aecc8:  90 10 00 18  mov  %i0, %o0
a00aeccc:  80 8a 20 ff  btst  0xff, %o0
a00aecd0:  02 80 00 0d  be  0xa00aed04
a00aecd4:  92 10 20 85  mov  0x85, %o1
a00aecd8:  90 10 00 18  mov  %i0, %o0
a00aecdc:  7f ff df b7  call  0xa00a6bb8
a00aece0:  92 10 24 e0  mov  0x4e0, %o1
a00aece4:  80 8a 20 08  btst  8, %o0
a00aece8:  22 80 00 46  be,a   0xa00aee00
a00aecec:  b0 0e 60 01  and  %i1, 1, %i0
a00aecf0:  90 10 00 18  mov  %i0, %o0
a00aecf4:  92 10 24 e0  mov  0x4e0, %o1
a00aecf8:  7f ff df c2  call  0xa00a6c00
a00aecfc:  94 10 20 08  mov  8, %o2
a00aed00:  30 80 00 31  b,a   0xa00aedc4
a00aed04:  7f ff df ad  call  0xa00a6bb8
a00aed08:  90 10 00 18  mov  %i0, %o0
a00aed0c:  b2 0a 20 ff  and  %o0, 0xff, %i1
a00aed10:  92 10 20 86  mov  0x86, %o1
a00aed14:  7f ff df a9  call  0xa00a6bb8
a00aed18:  90 10 00 18  mov  %i0, %o0
a00aed1c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00aed20:  b3 2e 60 08  sll  %i1, 8, %i1
a00aed24:  b2 16 40 08  or  %i1, %o0, %i1
a00aed28:  92 10 20 87  mov  0x87, %o1
a00aed2c:  7f ff df a3  call  0xa00a6bb8
a00aed30:  90 10 00 18  mov  %i0, %o0
a00aed34:  90 0a 20 ff  and  %o0, 0xff, %o0
a00aed38:  b3 2e 60 08  sll  %i1, 8, %i1
a00aed3c:  b2 16 40 08  or  %i1, %o0, %i1
a00aed40:  90 10 00 18  mov  %i0, %o0
a00aed44:  7f ff df 9d  call  0xa00a6bb8
a00aed48:  92 10 20 d7  mov  0xd7, %o1
a00aed4c:  80 8a 20 10  btst  0x10, %o0
a00aed50:  02 80 00 04  be  0xa00aed60
a00aed54:  90 10 00 18  mov  %i0, %o0
a00aed58:  10 80 00 08  b  0xa00aed78
a00aed5c:  b3 36 60 03  srl  %i1, 3, %i1
a00aed60:  7f ff df 96  call  0xa00a6bb8
a00aed64:  92 10 20 d7  mov  0xd7, %o1
a00aed68:  80 8a 20 04  btst  4, %o0
a00aed6c:  32 80 00 02  bne,a   0xa00aed74
a00aed70:  b3 36 60 02  srl  %i1, 2, %i1
a00aed74:  90 10 00 18  mov  %i0, %o0
a00aed78:  7f ff df 90  call  0xa00a6bb8
a00aed7c:  92 10 20 d5  mov  0xd5, %o1
a00aed80:  80 8a 20 20  btst  0x20, %o0
a00aed84:  32 80 00 02  bne,a   0xa00aed8c
a00aed88:  b3 36 60 01  srl  %i1, 1, %i1
a00aed8c:  03 00 00 20  sethi  %hi(0x8000), %g1
a00aed90:  80 a6 40 01  cmp  %i1, %g1
a00aed94:  12 80 00 1a  bne  0xa00aedfc
a00aed98:  b2 10 20 00  clr  %i1
a00aed9c:  90 10 00 18  mov  %i0, %o0
a00aeda0:  7f ff e0 76  call  0xa00a6f78
a00aeda4:  92 10 20 00  clr  %o1
a00aeda8:  80 8a 20 04  btst  4, %o0
a00aedac:  22 80 00 15  be,a   0xa00aee00
a00aedb0:  b0 0e 60 01  and  %i1, 1, %i0
a00aedb4:  90 10 00 18  mov  %i0, %o0
a00aedb8:  92 10 20 00  clr  %o1
a00aedbc:  7f ff e0 81  call  0xa00a6fc0
a00aedc0:  94 10 20 04  mov  4, %o2
a00aedc4:  40 00 0c a8  call  0xa00b2064
a00aedc8:  b2 10 20 01  mov  1, %i1
a00aedcc:  10 80 00 0c  b  0xa00aedfc
a00aedd0:  d0 24 63 28  st  %o0, [ %l1 + 0x328 ]
a00aedd4:  92 10 20 00  clr  %o1
a00aedd8:  7f ff e0 7a  call  0xa00a6fc0
a00aeddc:  94 10 20 04  mov  4, %o2
a00aede0:  90 10 00 18  mov  %i0, %o0
a00aede4:  92 10 24 e0  mov  0x4e0, %o1
a00aede8:  7f ff df 86  call  0xa00a6c00
a00aedec:  94 10 20 08  mov  8, %o2
a00aedf0:  40 00 0c 9d  call  0xa00b2064
a00aedf4:  b2 10 20 01  mov  1, %i1
a00aedf8:  d0 24 23 28  st  %o0, [ %l0 + 0x328 ]
a00aedfc:  b0 0e 60 01  and  %i1, 1, %i0
a00aee00:  81 c7 e0 08  ret
a00aee04:  81 e8 00 00  restore
