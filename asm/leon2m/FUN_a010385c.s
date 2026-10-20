# leon2m FUN_a010385c 0xa010385c-0xa01038c0 (100 bytes)
a010385c:  1b 33 c0 3a  sethi  %hi(0xcf00e800), %o5
a0103860:  98 13 62 c8  or  %o5, 0x2c8, %o4	! 0xcf00eac8
a0103864:  d6 03 00 00  ld  [ %o4 ], %o3
a0103868:  c2 03 00 00  ld  [ %o4 ], %g1
a010386c:  94 13 61 c4  or  %o5, 0x1c4, %o2
a0103870:  82 08 7f ef  and  %g1, -17, %g1
a0103874:  9a 10 00 0a  mov  %o2, %o5
a0103878:  c2 23 00 00  st  %g1, [ %o4 ]
a010387c:  80 8a 20 ff  btst  0xff, %o0
a0103880:  02 80 00 07  be  0xa010389c
a0103884:  01 00 00 00  nop
a0103888:  d8 02 80 00  ld  [ %o2 ], %o4
a010388c:  90 13 20 80  or  %o4, 0x80, %o0
a0103890:  d0 22 80 00  st  %o0, [ %o2 ]
a0103894:  10 80 00 06  b  0xa01038ac
a0103898:  9a 0a e0 ff  and  %o3, 0xff, %o5
a010389c:  c2 02 80 00  ld  [ %o2 ], %g1
a01038a0:  94 08 7f 7f  and  %g1, -129, %o2
a01038a4:  d4 23 40 00  st  %o2, [ %o5 ]
a01038a8:  9a 0a e0 ff  and  %o3, 0xff, %o5
a01038ac:  11 33 c0 3a  sethi  %hi(0xcf00e800), %o0
a01038b0:  96 12 22 c8  or  %o0, 0x2c8, %o3	! 0xcf00eac8
a01038b4:  da 22 c0 00  st  %o5, [ %o3 ]
a01038b8:  81 c3 e0 08  retl
a01038bc:  01 00 00 00  nop
