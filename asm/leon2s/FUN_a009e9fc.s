# leon2s FUN_a009e9fc 0xa009e9fc-0xa009ea1c (32 bytes)
a009e9fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a009ea00:  9a 02 00 08  add  %o0, %o0, %o5
a009ea04:  9a 03 40 08  add  %o5, %o0, %o5
a009ea08:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a009ea0c:  9b 2b 60 03  sll  %o5, 3, %o5
a009ea10:  82 10 62 50  or  %g1, 0x250, %g1
a009ea14:  81 c3 e0 08  retl
a009ea18:  c0 20 40 0d  clr  [ %g1 + %o5 ]
