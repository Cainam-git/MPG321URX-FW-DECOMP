# leon2m FUN_a00869b0 0xa00869b0-0xa0086a3c (140 bytes)
a00869b0:  9d e3 bf 98  save  %sp, -104, %sp
a00869b4:  40 03 03 5c  call  0xa0147724
a00869b8:  01 00 00 00  nop
a00869bc:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00869c0:  d2 13 63 68  lduh  [ %o5 + 0x368 ], %o1	! 0xa802af68
a00869c4:  82 22 00 09  sub  %o0, %o1, %g1
a00869c8:  d0 33 63 68  sth  %o0, [ %o5 + 0x368 ]
a00869cc:  99 28 60 10  sll  %g1, 0x10, %o4
a00869d0:  1f 2a 00 ab  sethi  %hi(0xa802ac00), %o7
a00869d4:  90 10 00 01  mov  %g1, %o0
a00869d8:  99 33 20 10  srl  %o4, 0x10, %o4
a00869dc:  92 10 20 00  clr  %o1
a00869e0:  82 10 20 00  clr  %g1
a00869e4:  10 80 00 07  b  0xa0086a00
a00869e8:  94 13 e3 6a  or  %o7, 0x36a, %o2
a00869ec:  92 02 60 01  inc  %o1
a00869f0:  82 0a 60 ff  and  %o1, 0xff, %g1
a00869f4:  80 a0 60 16  cmp  %g1, 0x16
a00869f8:  18 80 00 0c  bgu  0xa0086a28
a00869fc:  c0 32 80 0b  clrh  [ %o2 + %o3 ]
a0086a00:  96 00 40 01  add  %g1, %g1, %o3
a0086a04:  c2 12 80 0b  lduh  [ %o2 + %o3 ], %g1
a0086a08:  80 a0 40 0c  cmp  %g1, %o4
a0086a0c:  0a bf ff f8  bcs  0xa00869ec
a0086a10:  9a 20 40 08  sub  %g1, %o0, %o5
a0086a14:  92 02 60 01  inc  %o1
a0086a18:  82 0a 60 ff  and  %o1, 0xff, %g1
a0086a1c:  80 a0 60 16  cmp  %g1, 0x16
a0086a20:  08 bf ff f8  bleu  0xa0086a00
a0086a24:  da 32 80 0b  sth  %o5, [ %o2 + %o3 ]
a0086a28:  94 13 e3 6a  or  %o7, 0x36a, %o2
a0086a2c:  90 06 00 18  add  %i0, %i0, %o0
a0086a30:  f2 32 80 08  sth  %i1, [ %o2 + %o0 ]
a0086a34:  81 c7 e0 08  ret
a0086a38:  81 e8 00 00  restore
