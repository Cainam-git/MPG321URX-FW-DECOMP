# leon2s FUN_a0073c24 0xa0073c24-0xa0073c44 (32 bytes)
a0073c24:  90 0a 20 ff  and  %o0, 0xff, %o0
a0073c28:  9a 02 00 08  add  %o0, %o0, %o5
a0073c2c:  9a 03 40 08  add  %o5, %o0, %o5
a0073c30:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a0073c34:  9b 2b 60 03  sll  %o5, 3, %o5
a0073c38:  82 10 60 64  or  %g1, 0x64, %g1
a0073c3c:  81 c3 e0 08  retl
a0073c40:  d2 28 40 0d  stb  %o1, [ %g1 + %o5 ]
