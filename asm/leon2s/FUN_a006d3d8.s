# leon2s FUN_a006d3d8 0xa006d3d8-0xa006d414 (60 bytes)
a006d3d8:  03 2a 01 ea  sethi  %hi(0xa807a800), %g1
a006d3dc:  94 10 60 24  or  %g1, 0x24, %o2	! 0xa807a824
a006d3e0:  98 10 20 00  clr  %o4
a006d3e4:  96 10 20 01  mov  1, %o3
a006d3e8:  82 0b 20 ff  and  %o4, 0xff, %g1
a006d3ec:  9b 28 60 02  sll  %g1, 2, %o5
a006d3f0:  9a 03 40 01  add  %o5, %g1, %o5
a006d3f4:  98 03 20 01  inc  %o4
a006d3f8:  9b 2b 60 02  sll  %o5, 2, %o5
a006d3fc:  82 0b 20 ff  and  %o4, 0xff, %g1
a006d400:  80 a0 60 08  cmp  %g1, 8
a006d404:  08 bf ff fa  bleu  0xa006d3ec
a006d408:  d6 2a 80 0d  stb  %o3, [ %o2 + %o5 ]
a006d40c:  81 c3 e0 08  retl
a006d410:  01 00 00 00  nop
