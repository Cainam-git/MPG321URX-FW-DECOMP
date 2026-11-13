# leon2m FUN_a012fc20 0xa012fc20-0xa012fc70 (80 bytes)
a012fc20:  11 2a 00 a9  sethi  %hi(0xa802a400), %o0
a012fc24:  d8 0a 20 4c  ldub  [ %o0 + 0x4c ], %o4	! 0xa802a44c
a012fc28:  83 2b 20 04  sll  %o4, 4, %g1
a012fc2c:  9a 20 40 0c  sub  %g1, %o4, %o5
a012fc30:  9b 2b 60 03  sll  %o5, 3, %o5
a012fc34:  80 a3 20 ff  cmp  %o4, 0xff
a012fc38:  02 80 00 0c  be  0xa012fc68
a012fc3c:  90 10 3f ff  mov  -1, %o0
a012fc40:  19 2a 00 b7  sethi  %hi(0xa802dc00), %o4
a012fc44:  82 13 23 30  or  %o4, 0x330, %g1	! 0xa802df30
a012fc48:  d0 00 40 0d  ld  [ %g1 + %o5 ], %o0
a012fc4c:  9b 32 20 0c  srl  %o0, 0xc, %o5
a012fc50:  98 0b 60 0f  and  %o5, 0xf, %o4
a012fc54:  11 2a 00 b8  sethi  %hi(0xa802e000), %o0
a012fc58:  82 12 22 24  or  %o0, 0x224, %g1	! 0xa802e224
a012fc5c:  9a 5b 20 2a  smul  %o4, 0x2a, %o5
a012fc60:  98 03 40 01  add  %o5, %g1, %o4
a012fc64:  d0 0b 20 0a  ldub  [ %o4 + 0xa ], %o0
a012fc68:  81 c3 e0 08  retl
a012fc6c:  90 0a 20 ff  and  %o0, 0xff, %o0
