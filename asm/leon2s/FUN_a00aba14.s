# leon2s FUN_a00aba14 0xa00aba14-0xa00aba4c (56 bytes)
a00aba14:  90 0a 20 ff  and  %o0, 0xff, %o0
a00aba18:  1b 2a 01 f7  sethi  %hi(0xa807dc00), %o5
a00aba1c:  9a 13 60 18  or  %o5, 0x18, %o5	! 0xa807dc18
a00aba20:  90 5a 21 2c  smul  %o0, 0x12c, %o0
a00aba24:  82 02 00 0d  add  %o0, %o5, %g1
a00aba28:  c0 2b 40 08  clrb  [ %o5 + %o0 ]
a00aba2c:  c0 28 60 06  clrb  [ %g1 + 6 ]
a00aba30:  c0 28 60 2e  clrb  [ %g1 + 0x2e ]
a00aba34:  c0 28 60 b5  clrb  [ %g1 + 0xb5 ]
a00aba38:  c0 28 60 dc  clrb  [ %g1 + 0xdc ]
a00aba3c:  c0 28 60 ef  clrb  [ %g1 + 0xef ]
a00aba40:  c0 28 60 02  clrb  [ %g1 + 2 ]
a00aba44:  81 c3 e0 08  retl
a00aba48:  c0 28 60 04  clrb  [ %g1 + 4 ]
