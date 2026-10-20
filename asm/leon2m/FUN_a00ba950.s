# leon2m FUN_a00ba950 0xa00ba950-0xa00ba9d0 (128 bytes)
a00ba950:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ba954:  90 0a 20 ff  and  %o0, 0xff, %o0
a00ba958:  80 a2 20 02  cmp  %o0, 2
a00ba95c:  02 80 00 10  be  0xa00ba99c
a00ba960:  9a 13 20 40  or  %o4, 0x40, %o5
a00ba964:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00ba968:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00ba96c:  96 12 a0 98  or  %o2, 0x98, %o3
a00ba970:  80 a2 20 03  cmp  %o0, 3
a00ba974:  02 80 00 0e  be  0xa00ba9ac
a00ba978:  9a 13 20 d0  or  %o4, 0xd0, %o5
a00ba97c:  15 2a 00 ac  sethi  %hi(0xa802b000), %o2
a00ba980:  c0 2a a0 9c  clrb  [ %o2 + 0x9c ]	! 0xa802b09c
a00ba984:  c0 2b 20 d0  clrb  [ %o4 + 0xd0 ]
a00ba988:  c0 2b 60 19  clrb  [ %o5 + 0x19 ]
a00ba98c:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a00ba990:  c0 2b 60 07  clrb  [ %o5 + 7 ]
a00ba994:  10 80 00 0d  b  0xa00ba9c8
a00ba998:  c0 2b 60 0a  clrb  [ %o5 + 0xa ]
a00ba99c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00ba9a0:  c0 28 60 9a  clrb  [ %g1 + 0x9a ]	! 0xa802b09a
a00ba9a4:  10 bf ff f9  b  0xa00ba988
a00ba9a8:  c0 2b 20 40  clrb  [ %o4 + 0x40 ]
a00ba9ac:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00ba9b0:  c0 2a 20 98  clrb  [ %o0 + 0x98 ]	! 0xa802b098
a00ba9b4:  c0 2a a0 98  clrb  [ %o2 + 0x98 ]
a00ba9b8:  c0 2a e0 19  clrb  [ %o3 + 0x19 ]
a00ba9bc:  c0 2a e0 01  clrb  [ %o3 + 1 ]
a00ba9c0:  c0 2a e0 07  clrb  [ %o3 + 7 ]
a00ba9c4:  c0 2a e0 0a  clrb  [ %o3 + 0xa ]
a00ba9c8:  81 c3 e0 08  retl
a00ba9cc:  01 00 00 00  nop
