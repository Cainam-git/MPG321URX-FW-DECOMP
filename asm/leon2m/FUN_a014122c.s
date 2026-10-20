# leon2m FUN_a014122c 0xa014122c-0xa0141290 (100 bytes)
a014122c:  9d e3 bf 98  save  %sp, -104, %sp
a0141230:  7f ff 5f 9b  call  0xa011909c
a0141234:  a2 0e 20 ff  and  %i0, 0xff, %l1
a0141238:  b1 2c 60 04  sll  %l1, 4, %i0
a014123c:  a0 0a 20 ff  and  %o0, 0xff, %l0
a0141240:  9e 06 00 10  add  %i0, %l0, %o7
a0141244:  25 00 06 8d  sethi  %hi(0x1a3400), %l2
a0141248:  a4 14 a2 48  or  %l2, 0x248, %l2	! 0x1a3648
a014124c:  9a 03 c0 0f  add  %o7, %o7, %o5
a0141250:  7f ff 5f 93  call  0xa011909c
a0141254:  f2 2c 80 0d  stb  %i1, [ %l2 + %o5 ]
a0141258:  98 0a 20 ff  and  %o0, 0xff, %o4
a014125c:  96 06 00 0c  add  %i0, %o4, %o3
a0141260:  94 02 c0 0b  add  %o3, %o3, %o2
a0141264:  92 26 00 11  sub  %i0, %l1, %o1
a0141268:  90 02 80 12  add  %o2, %l2, %o0
a014126c:  03 00 06 8d  sethi  %hi(0x1a3400), %g1
a0141270:  a0 02 40 09  add  %o1, %o1, %l0
a0141274:  a3 2c 60 05  sll  %l1, 5, %l1
a0141278:  f2 2a 20 01  stb  %i1, [ %o0 + 1 ]
a014127c:  b0 10 62 68  or  %g1, 0x268, %i0
a0141280:  b0 04 00 18  add  %l0, %i0, %i0
a0141284:  7f ff 5e 58  call  0xa0118be4
a0141288:  93 ec 40 12  restore  %l1, %l2, %o1
a014128c:  01 00 00 00  nop
