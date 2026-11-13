# leon2s FUN_a009e9cc 0xa009e9cc-0xa009e9fc (48 bytes)
a009e9cc:  90 0a 20 ff  and  %o0, 0xff, %o0
a009e9d0:  9a 02 00 08  add  %o0, %o0, %o5
a009e9d4:  9a 03 40 08  add  %o5, %o0, %o5
a009e9d8:  19 2a 01 f5  sethi  %hi(0xa807d400), %o4
a009e9dc:  98 13 22 50  or  %o4, 0x250, %o4	! 0xa807d650
a009e9e0:  9b 2b 60 03  sll  %o5, 3, %o5
a009e9e4:  82 10 20 0f  mov  0xf, %g1
a009e9e8:  96 03 40 0c  add  %o5, %o4, %o3
a009e9ec:  c2 2a e0 05  stb  %g1, [ %o3 + 5 ]
a009e9f0:  82 10 20 05  mov  5, %g1
a009e9f4:  81 c3 e0 08  retl
a009e9f8:  c2 23 00 0d  st  %g1, [ %o4 + %o5 ]
