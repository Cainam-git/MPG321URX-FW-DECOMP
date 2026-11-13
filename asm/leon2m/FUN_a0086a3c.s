# leon2m FUN_a0086a3c 0xa0086a3c-0xa0086ac8 (140 bytes)
a0086a3c:  9d e3 bf 98  save  %sp, -104, %sp
a0086a40:  40 03 03 39  call  0xa0147724
a0086a44:  01 00 00 00  nop
a0086a48:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0086a4c:  d2 13 63 68  lduh  [ %o5 + 0x368 ], %o1	! 0xa802af68
a0086a50:  82 22 00 09  sub  %o0, %o1, %g1
a0086a54:  d0 33 63 68  sth  %o0, [ %o5 + 0x368 ]
a0086a58:  99 28 60 10  sll  %g1, 0x10, %o4
a0086a5c:  1f 2a 00 ab  sethi  %hi(0xa802ac00), %o7
a0086a60:  90 10 00 01  mov  %g1, %o0
a0086a64:  99 33 20 10  srl  %o4, 0x10, %o4
a0086a68:  92 10 20 00  clr  %o1
a0086a6c:  82 10 20 00  clr  %g1
a0086a70:  10 80 00 07  b  0xa0086a8c
a0086a74:  94 13 e3 6a  or  %o7, 0x36a, %o2
a0086a78:  92 02 60 01  inc  %o1
a0086a7c:  82 0a 60 ff  and  %o1, 0xff, %g1
a0086a80:  80 a0 60 16  cmp  %g1, 0x16
a0086a84:  18 80 00 0c  bgu  0xa0086ab4
a0086a88:  c0 32 80 0b  clrh  [ %o2 + %o3 ]
a0086a8c:  96 00 40 01  add  %g1, %g1, %o3
a0086a90:  c2 12 80 0b  lduh  [ %o2 + %o3 ], %g1
a0086a94:  80 a0 40 0c  cmp  %g1, %o4
a0086a98:  0a bf ff f8  bcs  0xa0086a78
a0086a9c:  9a 20 40 08  sub  %g1, %o0, %o5
a0086aa0:  92 02 60 01  inc  %o1
a0086aa4:  82 0a 60 ff  and  %o1, 0xff, %g1
a0086aa8:  80 a0 60 16  cmp  %g1, 0x16
a0086aac:  08 bf ff f8  bleu  0xa0086a8c
a0086ab0:  da 32 80 0b  sth  %o5, [ %o2 + %o3 ]
a0086ab4:  94 13 e3 6a  or  %o7, 0x36a, %o2
a0086ab8:  90 06 00 18  add  %i0, %i0, %o0
a0086abc:  f0 12 80 08  lduh  [ %o2 + %o0 ], %i0
a0086ac0:  81 c7 e0 08  ret
a0086ac4:  81 e8 00 00  restore
