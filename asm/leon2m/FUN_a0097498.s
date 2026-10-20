# leon2m FUN_a0097498 0xa0097498-0xa0097508 (112 bytes)
a0097498:  9d e3 bf 98  save  %sp, -104, %sp
a009749c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a00974a0:  96 13 62 90  or  %o5, 0x290, %o3	! 0xa802d290
a00974a4:  13 2a 00 b3  sethi  %hi(0xa802cc00), %o1
a00974a8:  d4 0a e1 a0  ldub  [ %o3 + 0x1a0 ], %o2
a00974ac:  82 0a a0 ff  and  %o2, 0xff, %g1
a00974b0:  d8 12 63 f4  lduh  [ %o1 + 0x3f4 ], %o4
a00974b4:  11 00 00 10  sethi  %hi(0x4000), %o0
a00974b8:  98 13 00 08  or  %o4, %o0, %o4
a00974bc:  80 a0 60 00  cmp  %g1, 0
a00974c0:  02 80 00 06  be  0xa00974d8
a00974c4:  9a 00 40 0b  add  %g1, %o3, %o5
a00974c8:  c2 0b 61 9b  ldub  [ %o5 + 0x19b ], %g1
a00974cc:  de 0b 61 97  ldub  [ %o5 + 0x197 ], %o7
a00974d0:  c2 2a e1 a2  stb  %g1, [ %o3 + 0x1a2 ]
a00974d4:  de 2a e1 a1  stb  %o7, [ %o3 + 0x1a1 ]
a00974d8:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a00974dc:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00974e0:  d4 2a 23 ea  stb  %o2, [ %o0 + 0x3ea ]
a00974e4:  d8 32 63 f4  sth  %o4, [ %o1 + 0x3f4 ]
a00974e8:  40 00 76 e6  call  0xa00b5080
a00974ec:  c0 23 63 ec  clr  [ %o5 + 0x3ec ]
a00974f0:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00974f4:  d6 0a 60 8e  ldub  [ %o1 + 0x8e ], %o3	! 0xa802b08e
a00974f8:  94 12 e0 02  or  %o3, 2, %o2
a00974fc:  d4 2a 60 8e  stb  %o2, [ %o1 + 0x8e ]
a0097500:  81 c7 e0 08  ret
a0097504:  81 e8 00 00  restore
