# leon2m FUN_a00dd814 0xa00dd814-0xa00dd83c (40 bytes)
a00dd814:  80 a2 20 01  cmp  %o0, 1
a00dd818:  02 80 00 05  be  0xa00dd82c
a00dd81c:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00dd820:  11 2a 00 ac  sethi  %hi(0xa802b000), %o0
a00dd824:  10 80 00 03  b  0xa00dd830
a00dd828:  c0 2a 20 ac  clrb  [ %o0 + 0xac ]	! 0xa802b0ac
a00dd82c:  d0 28 60 ac  stb  %o0, [ %g1 + 0xac ]
a00dd830:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00dd834:  81 c3 e0 08  retl
a00dd838:  d2 20 60 a8  st  %o1, [ %g1 + 0xa8 ]	! 0xa802b0a8
