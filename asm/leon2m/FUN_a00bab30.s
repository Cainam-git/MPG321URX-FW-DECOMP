# leon2m FUN_a00bab30 0xa00bab30-0xa00bab80 (80 bytes)
a00bab30:  82 0a 20 ff  and  %o0, 0xff, %g1
a00bab34:  80 a0 60 02  cmp  %g1, 2
a00bab38:  02 80 00 0a  be  0xa00bab60
a00bab3c:  90 0a 60 ff  and  %o1, 0xff, %o0
a00bab40:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00bab44:  80 a0 60 03  cmp  %g1, 3
a00bab48:  02 80 00 09  be  0xa00bab6c
a00bab4c:  90 10 00 0d  mov  %o5, %o0
a00bab50:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00bab54:  82 13 60 d0  or  %o5, 0xd0, %g1	! 0xa802d0d0
a00bab58:  10 80 00 08  b  0xa00bab78
a00bab5c:  d0 08 40 08  ldub  [ %g1 + %o0 ], %o0
a00bab60:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bab64:  10 bf ff fd  b  0xa00bab58
a00bab68:  82 10 60 40  or  %g1, 0x40, %g1	! 0xa802d040
a00bab6c:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00bab70:  92 12 20 98  or  %o0, 0x98, %o1	! 0xa802d098
a00bab74:  d0 0a 40 0d  ldub  [ %o1 + %o5 ], %o0
a00bab78:  81 c3 e0 08  retl
a00bab7c:  90 0a 20 ff  and  %o0, 0xff, %o0
