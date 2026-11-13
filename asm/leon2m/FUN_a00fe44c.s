# leon2m FUN_a00fe44c 0xa00fe44c-0xa00fe47c (48 bytes)
a00fe44c:  91 2a 20 10  sll  %o0, 0x10, %o0
a00fe450:  99 32 20 18  srl  %o0, 0x18, %o4
a00fe454:  1b 33 c0 26  sethi  %hi(0xcf009800), %o5
a00fe458:  82 0b 20 13  and  %o4, 0x13, %g1
a00fe45c:  98 13 63 b4  or  %o5, 0x3b4, %o4
a00fe460:  91 32 20 10  srl  %o0, 0x10, %o0
a00fe464:  c2 23 00 00  st  %g1, [ %o4 ]
a00fe468:  9a 13 63 b8  or  %o5, 0x3b8, %o5
a00fe46c:  90 0a 20 ff  and  %o0, 0xff, %o0
a00fe470:  d0 23 40 00  st  %o0, [ %o5 ]
a00fe474:  81 c3 e0 08  retl
a00fe478:  01 00 00 00  nop
