# leon2m FUN_a00bad4c 0xa00bad4c-0xa00badc0 (116 bytes)
a00bad4c:  03 14 7a e1  sethi  %hi(0x51eb8400), %g1
a00bad50:  98 0a 20 ff  and  %o0, 0xff, %o4
a00bad54:  9a 10 61 1f  or  %g1, 0x11f, %o5
a00bad58:  80 53 00 0d  umul  %o4, %o5, %g0
a00bad5c:  97 40 00 00  rd  %y, %o3
a00bad60:  97 32 e0 05  srl  %o3, 5, %o3
a00bad64:  82 0a e0 ff  and  %o3, 0xff, %g1
a00bad68:  9a 58 60 64  smul  %g1, 0x64, %o5
a00bad6c:  90 22 00 0d  sub  %o0, %o5, %o0
a00bad70:  19 33 33 33  sethi  %hi(0xcccccc00), %o4
a00bad74:  9a 0a 20 ff  and  %o0, 0xff, %o5
a00bad78:  82 13 20 cd  or  %o4, 0xcd, %g1
a00bad7c:  80 53 40 01  umul  %o5, %g1, %g0
a00bad80:  99 40 00 00  rd  %y, %o4
a00bad84:  99 33 20 03  srl  %o4, 3, %o4
a00bad88:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00bad8c:  83 2b 60 02  sll  %o5, 2, %g1
a00bad90:  82 00 40 0d  add  %g1, %o5, %g1
a00bad94:  9a 00 40 01  add  %g1, %g1, %o5
a00bad98:  90 22 00 0d  sub  %o0, %o5, %o0
a00bad9c:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00bada0:  9a 10 60 78  or  %g1, 0x78, %o5	! 0xa802d078
a00bada4:  96 02 e0 30  add  %o3, 0x30, %o3
a00bada8:  98 03 20 30  add  %o4, 0x30, %o4
a00badac:  90 02 20 30  add  %o0, 0x30, %o0
a00badb0:  d0 2b 60 09  stb  %o0, [ %o5 + 9 ]
a00badb4:  d6 2b 60 07  stb  %o3, [ %o5 + 7 ]
a00badb8:  81 c3 e0 08  retl
a00badbc:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
