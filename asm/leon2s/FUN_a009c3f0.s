# leon2s FUN_a009c3f0 0xa009c3f0-0xa009c434 (68 bytes)
a009c3f0:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c3f4:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009c3f8:  90 5a 20 34  smul  %o0, 0x34, %o0
a009c3fc:  82 10 63 00  or  %g1, 0x300, %g1
a009c400:  90 02 00 01  add  %o0, %g1, %o0
a009c404:  d6 02 20 04  ld  [ %o0 + 4 ], %o3
a009c408:  98 10 20 00  clr  %o4
a009c40c:  15 00 00 80  sethi  %hi(0x20000), %o2
a009c410:  98 03 20 01  inc  %o4
a009c414:  da 02 e0 28  ld  [ %o3 + 0x28 ], %o5
a009c418:  82 0b 20 ff  and  %o4, 0xff, %g1
a009c41c:  80 a0 60 31  cmp  %g1, 0x31
a009c420:  08 bf ff fc  bleu  0xa009c410
a009c424:  9a 0b 40 0a  and  %o5, %o2, %o5
a009c428:  80 a0 00 0d  cmp  %g0, %o5
a009c42c:  81 c3 e0 08  retl
a009c430:  90 60 3f ff  subx  %g0, -1, %o0
