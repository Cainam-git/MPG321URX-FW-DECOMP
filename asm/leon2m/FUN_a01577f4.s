# leon2m FUN_a01577f4 0xa01577f4-0xa0157858 (100 bytes)
a01577f4:  9d e3 be c8  save  %sp, -312, %sp
a01577f8:  82 10 22 08  mov  0x208, %g1
a01577fc:  c2 37 bf 34  sth  %g1, [ %fp + -204 ]
a0157800:  82 10 3f ff  mov  -1, %g1
a0157804:  c2 37 bf 36  sth  %g1, [ %fp + -202 ]
a0157808:  1b 1f ff ff  sethi  %hi(0x7ffffc00), %o5
a015780c:  9a 13 63 ff  or  %o5, 0x3ff, %o5	! 0x7fffffff
a0157810:  03 2a 00 aa  sethi  %hi(0xa802a800), %g1
a0157814:  f4 27 a0 4c  st  %i2, [ %fp + 0x4c ]
a0157818:  f6 27 a0 50  st  %i3, [ %fp + 0x50 ]
a015781c:  f8 27 a0 54  st  %i4, [ %fp + 0x54 ]
a0157820:  fa 27 a0 58  st  %i5, [ %fp + 0x58 ]
a0157824:  f0 27 bf 38  st  %i0, [ %fp + -200 ]
a0157828:  f0 27 bf 28  st  %i0, [ %fp + -216 ]
a015782c:  d0 00 62 18  ld  [ %g1 + 0x218 ], %o0
a0157830:  da 27 bf 3c  st  %o5, [ %fp + -196 ]
a0157834:  da 27 bf 30  st  %o5, [ %fp + -208 ]
a0157838:  94 10 00 19  mov  %i1, %o2
a015783c:  92 07 bf 28  add  %fp, -216, %o1
a0157840:  40 00 00 88  call  0xa0157a60
a0157844:  96 07 a0 4c  add  %fp, 0x4c, %o3
a0157848:  c2 07 bf 28  ld  [ %fp + -216 ], %g1
a015784c:  c0 28 40 00  clrb  [ %g1 ]
a0157850:  81 c7 e0 08  ret
a0157854:  91 e8 00 08  restore  %g0, %o0, %o0
