# leon2s FUN_a0074c48 0xa0074c48-0xa0074c78 (48 bytes)
a0074c48:  90 0a 20 ff  and  %o0, 0xff, %o0
a0074c4c:  82 02 00 08  add  %o0, %o0, %g1
a0074c50:  82 00 40 08  add  %g1, %o0, %g1
a0074c54:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0074c58:  83 28 60 03  sll  %g1, 3, %g1
a0074c5c:  9a 13 60 64  or  %o5, 0x64, %o5
a0074c60:  82 00 40 0d  add  %g1, %o5, %g1
a0074c64:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a0074c68:  82 18 60 01  xor  %g1, 1, %g1
a0074c6c:  80 a0 00 01  cmp  %g0, %g1
a0074c70:  81 c3 e0 08  retl
a0074c74:  90 60 3f ff  subx  %g0, -1, %o0
