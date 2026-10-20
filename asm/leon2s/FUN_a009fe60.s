# leon2s FUN_a009fe60 0xa009fe60-0xa009fe98 (56 bytes)
a009fe60:  90 0a 20 ff  and  %o0, 0xff, %o0
a009fe64:  03 2a 01 f6  sethi  %hi(0xa807d800), %g1
a009fe68:  82 10 63 00  or  %g1, 0x300, %g1	! 0xa807db00
a009fe6c:  90 5a 20 34  smul  %o0, 0x34, %o0
a009fe70:  90 02 00 01  add  %o0, %g1, %o0
a009fe74:  da 02 20 14  ld  [ %o0 + 0x14 ], %o5
a009fe78:  c2 03 60 4c  ld  [ %o5 + 0x4c ], %g1
a009fe7c:  82 10 60 01  or  %g1, 1, %g1
a009fe80:  c2 23 60 4c  st  %g1, [ %o5 + 0x4c ]
a009fe84:  c2 03 60 4c  ld  [ %o5 + 0x4c ], %g1
a009fe88:  82 08 7f fe  and  %g1, -2, %g1
a009fe8c:  c2 23 60 4c  st  %g1, [ %o5 + 0x4c ]
a009fe90:  81 c3 e0 08  retl
a009fe94:  01 00 00 00  nop
