# leon2s FUN_a00d6890 0xa00d6890-0xa00d68cc (60 bytes)
a00d6890:  9d e3 bf 98  save  %sp, -104, %sp
a00d6894:  90 0e 60 ff  and  %i1, 0xff, %o0
a00d6898:  7f ff ff 89  call  0xa00d66bc
a00d689c:  92 0e a0 ff  and  %i2, 0xff, %o1
a00d68a0:  b2 92 20 00  orcc  %o0, 0, %i1
a00d68a4:  02 80 00 07  be  0xa00d68c0
a00d68a8:  01 00 00 00  nop
a00d68ac:  c2 0e 20 12  ldub  [ %i0 + 0x12 ], %g1
a00d68b0:  82 10 60 20  or  %g1, 0x20, %g1
a00d68b4:  c2 2e 20 12  stb  %g1, [ %i0 + 0x12 ]
a00d68b8:  7f ff ff 9b  call  0xa00d6724
a00d68bc:  81 e8 00 00  restore
a00d68c0:  01 00 00 00  nop
a00d68c4:  81 c7 e0 08  ret
a00d68c8:  81 e8 00 00  restore
