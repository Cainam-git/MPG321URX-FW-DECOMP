# leon2s FUN_a009e9a4 0xa009e9a4-0xa009e9cc (40 bytes)
a009e9a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a009e9a8:  9a 02 00 08  add  %o0, %o0, %o5
a009e9ac:  9a 03 40 08  add  %o5, %o0, %o5
a009e9b0:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009e9b4:  82 10 62 50  or  %g1, 0x250, %g1	! 0xa807d650
a009e9b8:  9b 2b 60 03  sll  %o5, 3, %o5
a009e9bc:  9a 03 40 01  add  %o5, %g1, %o5
a009e9c0:  82 10 20 01  mov  1, %g1
a009e9c4:  81 c3 e0 08  retl
a009e9c8:  c2 2b 60 0a  stb  %g1, [ %o5 + 0xa ]
