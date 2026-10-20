# leon2s FUN_a006d414 0xa006d414-0xa006d46c (88 bytes)
a006d414:  90 0a 20 ff  and  %o0, 0xff, %o0
a006d418:  83 2a 20 02  sll  %o0, 2, %g1
a006d41c:  82 00 40 08  add  %g1, %o0, %g1
a006d420:  80 a2 20 08  cmp  %o0, 8
a006d424:  08 80 00 0d  bleu  0xa006d458
a006d428:  9b 28 60 02  sll  %g1, 2, %o5
a006d42c:  1b 2a 01 ea  sethi  %hi(0xa807a800), %o5
a006d430:  80 a2 20 ff  cmp  %o0, 0xff
a006d434:  12 80 00 0c  bne  0xa006d464
a006d438:  82 13 60 24  or  %o5, 0x24, %g1
a006d43c:  d2 28 60 64  stb  %o1, [ %g1 + 0x64 ]
a006d440:  d2 2b 60 24  stb  %o1, [ %o5 + 0x24 ]
a006d444:  d2 28 60 14  stb  %o1, [ %g1 + 0x14 ]
a006d448:  d2 28 60 28  stb  %o1, [ %g1 + 0x28 ]
a006d44c:  d2 28 60 3c  stb  %o1, [ %g1 + 0x3c ]
a006d450:  10 80 00 05  b  0xa006d464
a006d454:  d2 28 60 50  stb  %o1, [ %g1 + 0x50 ]
a006d458:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a006d45c:  82 10 60 24  or  %g1, 0x24, %g1	! 0xa807a824
a006d460:  d2 28 40 0d  stb  %o1, [ %g1 + %o5 ]
a006d464:  81 c3 e0 08  retl
a006d468:  01 00 00 00  nop
