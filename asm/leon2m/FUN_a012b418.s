# leon2m FUN_a012b418 0xa012b418-0xa012b454 (60 bytes)
a012b418:  90 0a 20 ff  and  %o0, 0xff, %o0
a012b41c:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a012b420:  9a 5a 20 16  smul  %o0, 0x16, %o5
a012b424:  82 10 60 ae  or  %g1, 0xae, %g1
a012b428:  9a 03 40 01  add  %o5, %g1, %o5
a012b42c:  d6 2b 60 0b  stb  %o3, [ %o5 + 0xb ]
a012b430:  d2 2b 60 08  stb  %o1, [ %o5 + 8 ]
a012b434:  d4 2b 60 0a  stb  %o2, [ %o5 + 0xa ]
a012b438:  92 0a 60 ff  and  %o1, 0xff, %o1
a012b43c:  94 0a a0 ff  and  %o2, 0xff, %o2
a012b440:  96 0a e0 ff  and  %o3, 0xff, %o3
a012b444:  98 0b 20 ff  and  %o4, 0xff, %o4
a012b448:  82 13 c0 00  mov  %o7, %g1
a012b44c:  40 00 32 2f  call  0xa0137d08
a012b450:  9e 10 40 00  mov  %g1, %o7
