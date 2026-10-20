# leon2s FUN_a009c87c 0xa009c87c-0xa009c8ac (48 bytes)
a009c87c:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c880:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009c884:  9a 5a 21 90  smul  %o0, 0x190, %o5
a009c888:  82 10 63 e0  or  %g1, 0x3e0, %g1
a009c88c:  9a 03 40 01  add  %o5, %g1, %o5
a009c890:  c0 2b 60 04  clrb  [ %o5 + 4 ]
a009c894:  c0 2b 60 01  clrb  [ %o5 + 1 ]
a009c898:  c0 2b 60 2d  clrb  [ %o5 + 0x2d ]
a009c89c:  92 10 20 00  clr  %o1
a009c8a0:  82 13 c0 00  mov  %o7, %g1
a009c8a4:  7f ff ff d1  call  0xa009c7e8
a009c8a8:  9e 10 40 00  mov  %g1, %o7
