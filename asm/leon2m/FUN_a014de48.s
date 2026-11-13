# leon2m FUN_a014de48 0xa014de48-0xa014deec (164 bytes)
a014de48:  90 0a 20 ff  and  %o0, 0xff, %o0
a014de4c:  80 a2 20 01  cmp  %o0, 1
a014de50:  02 80 00 0b  be  0xa014de7c
a014de54:  98 10 20 01  mov  1, %o4
a014de58:  80 a2 20 01  cmp  %o0, 1
a014de5c:  04 80 00 1d  ble  0xa014ded0
a014de60:  80 a2 20 02  cmp  %o0, 2
a014de64:  02 80 00 06  be  0xa014de7c
a014de68:  98 10 20 02  mov  2, %o4
a014de6c:  80 a2 20 03  cmp  %o0, 3
a014de70:  02 80 00 03  be  0xa014de7c
a014de74:  98 10 20 03  mov  3, %o4
a014de78:  98 10 3f ff  mov  -1, %o4
a014de7c:  82 0b 20 ff  and  %o4, 0xff, %g1
a014de80:  80 a0 60 04  cmp  %g1, 4
a014de84:  18 80 00 18  bgu  0xa014dee4
a014de88:  9b 28 60 04  sll  %g1, 4, %o5
a014de8c:  90 23 40 01  sub  %o5, %g1, %o0
a014de90:  17 2a 00 b7  sethi  %hi(0xa802dc00), %o3
a014de94:  99 2a 20 03  sll  %o0, 3, %o4
a014de98:  82 12 e3 30  or  %o3, 0x330, %g1
a014de9c:  da 00 40 0c  ld  [ %g1 + %o4 ], %o5
a014dea0:  91 33 60 0c  srl  %o5, 0xc, %o0
a014dea4:  9a 0a 20 0f  and  %o0, 0xf, %o5
a014dea8:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a014deac:  82 0a 60 01  and  %o1, 1, %g1
a014deb0:  96 12 e2 24  or  %o3, 0x224, %o3
a014deb4:  9a 5b 60 2a  smul  %o5, 0x2a, %o5
a014deb8:  d2 12 c0 0d  lduh  [ %o3 + %o5 ], %o1
a014debc:  99 28 60 04  sll  %g1, 4, %o4
a014dec0:  90 0a 7f ef  and  %o1, -17, %o0
a014dec4:  82 12 00 0c  or  %o0, %o4, %g1
a014dec8:  10 80 00 07  b  0xa014dee4
a014decc:  c2 32 c0 0d  sth  %g1, [ %o3 + %o5 ]
a014ded0:  80 a2 20 00  cmp  %o0, 0
a014ded4:  02 bf ff ea  be  0xa014de7c
a014ded8:  98 10 20 00  clr  %o4
a014dedc:  10 bf ff e8  b  0xa014de7c
a014dee0:  98 10 3f ff  mov  -1, %o4
a014dee4:  81 c3 e0 08  retl
a014dee8:  01 00 00 00  nop
