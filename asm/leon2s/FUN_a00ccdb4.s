# leon2s FUN_a00ccdb4 0xa00ccdb4-0xa00ccf0c (344 bytes)
a00ccdb4:  9d e3 bf 80  save  %sp, -128, %sp
a00ccdb8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ccdbc:  a0 06 00 18  add  %i0, %i0, %l0
a00ccdc0:  a0 04 00 18  add  %l0, %i0, %l0
a00ccdc4:  25 2a 01 e2  sethi  %hi(0xa8078800), %l2
a00ccdc8:  a1 2c 20 03  sll  %l0, 3, %l0
a00ccdcc:  a2 14 a3 b0  or  %l2, 0x3b0, %l1
a00ccdd0:  da 04 40 10  ld  [ %l1 + %l0 ], %o5
a00ccdd4:  03 00 00 c0  sethi  %hi(0x30000), %g1
a00ccdd8:  82 2b 40 01  andn  %o5, %g1, %g1
a00ccddc:  1b 00 00 40  sethi  %hi(0x10000), %o5
a00ccde0:  82 10 40 0d  or  %g1, %o5, %g1
a00ccde4:  c2 24 40 10  st  %g1, [ %l1 + %l0 ]
a00ccde8:  7f ff ff 3b  call  0xa00ccad4
a00ccdec:  90 10 00 18  mov  %i0, %o0
a00ccdf0:  92 10 20 00  clr  %o1
a00ccdf4:  7f ff ee 73  call  0xa00c87c0
a00ccdf8:  90 10 00 18  mov  %i0, %o0
a00ccdfc:  a6 07 bf e8  add  %fp, -24, %l3
a00cce00:  90 10 00 18  mov  %i0, %o0
a00cce04:  92 10 00 13  mov  %l3, %o1
a00cce08:  7f ff ec fc  call  0xa00c81f8
a00cce0c:  94 10 20 08  mov  8, %o2
a00cce10:  c2 04 40 10  ld  [ %l1 + %l0 ], %g1
a00cce14:  83 30 60 12  srl  %g1, 0x12, %g1
a00cce18:  80 88 60 01  btst  1, %g1
a00cce1c:  12 80 00 07  bne  0xa00cce38
a00cce20:  90 10 00 18  mov  %i0, %o0
a00cce24:  92 10 20 00  clr  %o1
a00cce28:  94 10 21 2f  mov  0x12f, %o2
a00cce2c:  96 10 20 01  mov  1, %o3
a00cce30:  10 80 00 06  b  0xa00cce48
a00cce34:  98 10 20 00  clr  %o4
a00cce38:  92 10 20 00  clr  %o1
a00cce3c:  94 10 21 2f  mov  0x12f, %o2
a00cce40:  96 10 20 01  mov  1, %o3
a00cce44:  98 10 20 01  mov  1, %o4
a00cce48:  40 3b ac a1  call  0xa0fb80cc
a00cce4c:  01 00 00 00  nop
a00cce50:  7f ff eb 6a  call  0xa00c7bf8
a00cce54:  90 10 00 18  mov  %i0, %o0
a00cce58:  80 8a 20 ff  btst  0xff, %o0
a00cce5c:  12 80 00 1c  bne  0xa00ccecc
a00cce60:  9a 06 00 18  add  %i0, %i0, %o5
a00cce64:  90 10 00 18  mov  %i0, %o0
a00cce68:  7f ff ed 1d  call  0xa00c82dc
a00cce6c:  92 07 bf f0  add  %fp, -16, %o1
a00cce70:  80 8a 20 ff  btst  0xff, %o0
a00cce74:  12 80 00 16  bne  0xa00ccecc
a00cce78:  9a 06 00 18  add  %i0, %i0, %o5
a00cce7c:  90 10 00 18  mov  %i0, %o0
a00cce80:  7f ff eb 93  call  0xa00c7ccc
a00cce84:  92 10 20 01  mov  1, %o1
a00cce88:  90 10 00 18  mov  %i0, %o0
a00cce8c:  7f ff ed 35  call  0xa00c8360
a00cce90:  92 07 bf e7  add  %fp, -25, %o1
a00cce94:  80 8a 20 ff  btst  0xff, %o0
a00cce98:  12 80 00 0d  bne  0xa00ccecc
a00cce9c:  9a 06 00 18  add  %i0, %i0, %o5
a00ccea0:  7f ff ed 69  call  0xa00c8444
a00ccea4:  90 10 00 18  mov  %i0, %o0
a00ccea8:  90 10 00 18  mov  %i0, %o0
a00cceac:  92 10 00 13  mov  %l3, %o1
a00cceb0:  7f ff ed cd  call  0xa00c85e4
a00cceb4:  94 10 20 00  clr  %o2
a00cceb8:  7f ff ed 95  call  0xa00c850c
a00ccebc:  90 10 00 18  mov  %i0, %o0
a00ccec0:  80 8a 20 ff  btst  0xff, %o0
a00ccec4:  02 80 00 0a  be  0xa00cceec
a00ccec8:  9a 06 00 18  add  %i0, %i0, %o5
a00ccecc:  9a 03 40 18  add  %o5, %i0, %o5
a00cced0:  96 14 a3 b0  or  %l2, 0x3b0, %o3
a00cced4:  9b 2b 60 03  sll  %o5, 3, %o5
a00cced8:  c2 02 c0 0d  ld  [ %o3 + %o5 ], %g1
a00ccedc:  19 00 00 c0  sethi  %hi(0x30000), %o4
a00ccee0:  82 10 40 0c  or  %g1, %o4, %g1
a00ccee4:  10 80 00 07  b  0xa00ccf00
a00ccee8:  c2 22 c0 0d  st  %g1, [ %o3 + %o5 ]
a00cceec:  90 10 00 18  mov  %i0, %o0
a00ccef0:  7f ff ed e6  call  0xa00c8688
a00ccef4:  92 10 00 13  mov  %l3, %o1
a00ccef8:  7f ff ed f1  call  0xa00c86bc
a00ccefc:  90 10 00 18  mov  %i0, %o0
a00ccf00:  01 00 00 00  nop
a00ccf04:  81 c7 e0 08  ret
a00ccf08:  81 e8 00 00  restore
