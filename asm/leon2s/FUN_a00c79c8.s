# leon2s FUN_a00c79c8 0xa00c79c8-0xa00c7a4c (132 bytes)
a00c79c8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c79cc:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00c79d0:  80 a2 20 03  cmp  %o0, 3
a00c79d4:  96 10 61 a8  or  %g1, 0x1a8, %o3
a00c79d8:  94 10 20 00  clr  %o2
a00c79dc:  12 80 00 14  bne  0xa00c7a2c
a00c79e0:  98 10 20 00  clr  %o4
a00c79e4:  92 10 00 0b  mov  %o3, %o1
a00c79e8:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c79ec:  83 2b 60 02  sll  %o5, 2, %g1
a00c79f0:  82 00 40 0d  add  %g1, %o5, %g1
a00c79f4:  96 00 40 09  add  %g1, %o1, %o3
a00c79f8:  98 10 20 00  clr  %o4
a00c79fc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c7a00:  98 03 20 01  inc  %o4
a00c7a04:  82 0b 20 ff  and  %o4, 0xff, %g1
a00c7a08:  80 a0 60 04  cmp  %g1, 4
a00c7a0c:  08 bf ff fc  bleu  0xa00c79fc
a00c7a10:  c0 2a c0 0d  clrb  [ %o3 + %o5 ]
a00c7a14:  94 02 a0 01  inc  %o2
a00c7a18:  82 0a a0 ff  and  %o2, 0xff, %g1
a00c7a1c:  80 a0 60 02  cmp  %g1, 2
a00c7a20:  28 bf ff f3  bleu,a   0xa00c79ec
a00c7a24:  9a 0a a0 ff  and  %o2, 0xff, %o5
a00c7a28:  30 80 00 07  b,a   0xa00c7a44
a00c7a2c:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00c7a30:  98 03 20 01  inc  %o4
a00c7a34:  82 0b 20 ff  and  %o4, 0xff, %g1
a00c7a38:  80 a0 60 04  cmp  %g1, 4
a00c7a3c:  08 bf ff fc  bleu  0xa00c7a2c
a00c7a40:  c0 2a c0 0d  clrb  [ %o3 + %o5 ]
a00c7a44:  81 c3 e0 08  retl
a00c7a48:  01 00 00 00  nop
