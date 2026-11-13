# leon2s FUN_a00dbe74 0xa00dbe74-0xa00dbed4 (96 bytes)  [FUN_a00dbecc = unreachable ret/restore tail, merged]
a00dbe74:  9d e3 bf 98  save  %sp, -104, %sp
a00dbe78:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbe7c:  c2 08 60 41  ldub  [ %g1 + 0x41 ], %g1	! 0xa8078841
a00dbe80:  80 88 60 30  btst  0x30, %g1
a00dbe84:  02 80 00 05  be  0xa00dbe98
a00dbe88:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbe8c:  7f ff fe 3e  call  0xa00db784
a00dbe90:  01 00 00 00  nop
a00dbe94:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbe98:  da 08 60 32  ldub  [ %g1 + 0x32 ], %o5	! 0xa8078832
a00dbe9c:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbea0:  82 10 60 30  or  %g1, 0x30, %g1	! 0xa8078830
a00dbea4:  d8 08 40 0d  ldub  [ %g1 + %o5 ], %o4
a00dbea8:  03 2a 01 e2  sethi  %hi(0xa8078800), %g1
a00dbeac:  82 10 60 28  or  %g1, 0x28, %g1	! 0xa8078828
a00dbeb0:  c2 08 40 0d  ldub  [ %g1 + %o5 ], %g1
a00dbeb4:  80 a0 40 0c  cmp  %g1, %o4
a00dbeb8:  12 80 00 04  bne  0xa00dbec8
a00dbebc:  01 00 00 00  nop
a00dbec0:  7f ff ff 73  call  0xa00dbc8c
a00dbec4:  81 e8 00 00  restore
a00dbec8:  01 00 00 00  nop
a00dbecc:  81 c7 e0 08  ret
a00dbed0:  81 e8 00 00  restore
