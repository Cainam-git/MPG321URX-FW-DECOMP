# leon2s FUN_a00734d8 0xa00734d8-0xa0073500 (40 bytes)
a00734d8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00734dc:  9a 02 00 08  add  %o0, %o0, %o5
a00734e0:  9a 03 40 08  add  %o5, %o0, %o5
a00734e4:  03 2a 01 f3  sethi  %hi(0xa807cc00), %g1
a00734e8:  82 10 60 64  or  %g1, 0x64, %g1	! 0xa807cc64
a00734ec:  9b 2b 60 03  sll  %o5, 3, %o5
a00734f0:  9a 03 40 01  add  %o5, %g1, %o5
a00734f4:  82 10 20 01  mov  1, %g1
a00734f8:  81 c3 e0 08  retl
a00734fc:  c2 2b 60 02  stb  %g1, [ %o5 + 2 ]
