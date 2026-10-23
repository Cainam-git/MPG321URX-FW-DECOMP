# leon2m FUN_a012b370 0xa012b370-0xa012b394 (36 bytes)
a012b370:  90 0a 20 ff  and  %o0, 0xff, %o0
a012b374:  9b 2a 20 03  sll  %o0, 3, %o5
a012b378:  82 03 40 08  add  %o5, %o0, %g1
a012b37c:  1b 2a 00 b8  sethi  %hi(0xa802e000), %o5
a012b380:  90 00 40 01  add  %g1, %g1, %o0
a012b384:  9a 13 61 16  or  %o5, 0x116, %o5
a012b388:  82 02 00 0d  add  %o0, %o5, %g1
a012b38c:  81 c3 e0 08  retl
a012b390:  d0 10 60 0e  lduh  [ %g1 + 0xe ], %o0
