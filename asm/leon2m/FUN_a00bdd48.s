# leon2m FUN_a00bdd48 0xa00bdd48-0xa00bdd90 (72 bytes)
a00bdd48:  9d e3 bf 98  save  %sp, -104, %sp
a00bdd4c:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00bdd50:  d0 0a a3 eb  ldub  [ %o2 + 0x3eb ], %o0	! 0xa802d3eb
a00bdd54:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00bdd58:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00bdd5c:  98 02 20 30  add  %o0, 0x30, %o4
a00bdd60:  82 10 20 30  mov  0x30, %g1
a00bdd64:  d8 2b 60 09  stb  %o4, [ %o5 + 9 ]
a00bdd68:  c2 2b 60 08  stb  %g1, [ %o5 + 8 ]
a00bdd6c:  c2 2b 60 07  stb  %g1, [ %o5 + 7 ]
a00bdd70:  7f ff f3 b3  call  0xa00bac3c
a00bdd74:  90 10 20 3b  mov  0x3b, %o0
a00bdd78:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00bdd7c:  7f ff f2 f5  call  0xa00ba950
a00bdd80:  90 10 00 18  mov  %i0, %o0
a00bdd84:  7f ff f3 98  call  0xa00babe4
a00bdd88:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00bdd8c:  01 00 00 00  nop
