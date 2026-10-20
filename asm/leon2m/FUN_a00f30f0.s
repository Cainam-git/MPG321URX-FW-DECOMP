# leon2m FUN_a00f30f0 0xa00f30f0-0xa00f3134 (68 bytes)
a00f30f0:  9a 0a 60 ff  and  %o1, 0xff, %o5
a00f30f4:  da 22 00 00  st  %o5, [ %o0 ]
a00f30f8:  83 32 60 08  srl  %o1, 8, %g1
a00f30fc:  9b 32 60 10  srl  %o1, 0x10, %o5
a00f3100:  82 08 60 ff  and  %g1, 0xff, %g1
a00f3104:  92 0b 60 ff  and  %o5, 0xff, %o1
a00f3108:  c2 22 20 04  st  %g1, [ %o0 + 4 ]
a00f310c:  d2 22 20 08  st  %o1, [ %o0 + 8 ]
a00f3110:  9a 10 20 00  clr  %o5
a00f3114:  01 00 00 00  nop
a00f3118:  9a 03 60 01  inc  %o5
a00f311c:  90 0b 60 ff  and  %o5, 0xff, %o0
a00f3120:  80 a2 20 09  cmp  %o0, 9
a00f3124:  08 bf ff fc  bleu  0xa00f3114
a00f3128:  01 00 00 00  nop
a00f312c:  81 c3 e0 08  retl
a00f3130:  01 00 00 00  nop
