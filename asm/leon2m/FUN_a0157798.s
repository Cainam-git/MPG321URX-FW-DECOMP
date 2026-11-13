# leon2m FUN_a0157798 0xa0157798-0xa01577f4 (92 bytes)
a0157798:  9d e3 be c8  save  %sp, -312, %sp
a015779c:  82 10 22 08  mov  0x208, %g1
a01577a0:  c2 37 bf 34  sth  %g1, [ %fp + -204 ]
a01577a4:  1b 1f ff ff  sethi  %hi(0x7ffffc00), %o5
a01577a8:  9a 13 63 ff  or  %o5, 0x3ff, %o5	! 0x7fffffff
a01577ac:  82 10 3f ff  mov  -1, %g1
a01577b0:  c2 37 bf 36  sth  %g1, [ %fp + -202 ]
a01577b4:  90 10 00 18  mov  %i0, %o0
a01577b8:  f6 27 a0 50  st  %i3, [ %fp + 0x50 ]
a01577bc:  f8 27 a0 54  st  %i4, [ %fp + 0x54 ]
a01577c0:  fa 27 a0 58  st  %i5, [ %fp + 0x58 ]
a01577c4:  f2 27 bf 38  st  %i1, [ %fp + -200 ]
a01577c8:  da 27 bf 3c  st  %o5, [ %fp + -196 ]
a01577cc:  f2 27 bf 28  st  %i1, [ %fp + -216 ]
a01577d0:  da 27 bf 30  st  %o5, [ %fp + -208 ]
a01577d4:  94 10 00 1a  mov  %i2, %o2
a01577d8:  92 07 bf 28  add  %fp, -216, %o1
a01577dc:  40 00 00 a1  call  0xa0157a60
a01577e0:  96 07 a0 50  add  %fp, 0x50, %o3
a01577e4:  c2 07 bf 28  ld  [ %fp + -216 ], %g1
a01577e8:  c0 28 40 00  clrb  [ %g1 ]
a01577ec:  81 c7 e0 08  ret
a01577f0:  91 e8 00 08  restore  %g0, %o0, %o0
