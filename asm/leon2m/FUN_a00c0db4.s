# leon2m FUN_a00c0db4 0xa00c0db4-0xa00c0de0 (44 bytes)
a00c0db4:  90 0a 20 ff  and  %o0, 0xff, %o0
a00c0db8:  80 a2 20 00  cmp  %o0, 0
a00c0dbc:  02 80 00 05  be  0xa00c0dd0
a00c0dc0:  9a 10 20 01  mov  1, %o5
a00c0dc4:  80 a2 20 04  cmp  %o0, 4
a00c0dc8:  12 80 00 04  bne  0xa00c0dd8
a00c0dcc:  01 00 00 00  nop
a00c0dd0:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00c0dd4:  da 28 60 9b  stb  %o5, [ %g1 + 0x9b ]	! 0xa802b09b
a00c0dd8:  81 c3 e0 08  retl
a00c0ddc:  01 00 00 00  nop
