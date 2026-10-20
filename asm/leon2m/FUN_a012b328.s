# leon2m FUN_a012b328 0xa012b328-0xa012b350 (40 bytes)
a012b328:  90 0a 20 ff  and  %o0, 0xff, %o0
a012b32c:  03 2a 00 b6  sethi  %hi(0xa802d800), %g1
a012b330:  9a 5a 20 16  smul  %o0, 0x16, %o5
a012b334:  82 10 60 ae  or  %g1, 0xae, %g1
a012b338:  9a 03 40 01  add  %o5, %g1, %o5
a012b33c:  d2 2b 60 03  stb  %o1, [ %o5 + 3 ]
a012b340:  92 0a 60 ff  and  %o1, 0xff, %o1
a012b344:  82 13 c0 00  mov  %o7, %g1
a012b348:  40 00 31 e9  call  0xa0137aec
a012b34c:  9e 10 40 00  mov  %g1, %o7
