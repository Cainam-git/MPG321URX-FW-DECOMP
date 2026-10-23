# leon2m FUN_a012cee4 0xa012cee4-0xa012cf10 (44 bytes)
a012cee4:  19 2a 00 b8  sethi  %hi(0xa802e000), %o4
a012cee8:  98 13 21 a0  or  %o4, 0x1a0, %o4	! 0xa802e1a0
a012ceec:  03 3f c0 00  sethi  %hi(0xff000000), %g1
a012cef0:  da 03 20 34  ld  [ %o4 + 0x34 ], %o5
a012cef4:  91 2a 20 10  sll  %o0, 0x10, %o0
a012cef8:  82 10 60 ff  or  %g1, 0xff, %g1
a012cefc:  9a 0b 40 01  and  %o5, %g1, %o5
a012cf00:  91 32 20 08  srl  %o0, 8, %o0
a012cf04:  9a 13 40 08  or  %o5, %o0, %o5
a012cf08:  81 c3 e0 08  retl
a012cf0c:  da 23 20 34  st  %o5, [ %o4 + 0x34 ]
