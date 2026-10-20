# leon2m FUN_a013cea0 0xa013cea0-0xa013cecc (44 bytes)
a013cea0:  90 0a 20 ff  and  %o0, 0xff, %o0
a013cea4:  9b 2a 20 04  sll  %o0, 4, %o5
a013cea8:  82 23 40 08  sub  %o5, %o0, %g1
a013ceac:  1b 2a 00 b7  sethi  %hi(0xa802dc00), %o5
a013ceb0:  91 28 60 03  sll  %g1, 3, %o0
a013ceb4:  9a 13 63 30  or  %o5, 0x330, %o5
a013ceb8:  82 02 00 0d  add  %o0, %o5, %g1
a013cebc:  da 00 60 70  ld  [ %g1 + 0x70 ], %o5
a013cec0:  91 33 60 0e  srl  %o5, 0xe, %o0
a013cec4:  81 c3 e0 08  retl
a013cec8:  90 0a 20 03  and  %o0, 3, %o0
