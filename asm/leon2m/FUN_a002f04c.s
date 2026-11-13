# leon2m FUN_a002f04c 0xa002f04c-0xa002f088 (60 bytes)
a002f04c:  9d e3 bf 98  save  %sp, -104, %sp
a002f050:  15 33 c0 1d  sethi  %hi(0xcf007400), %o2
a002f054:  96 12 a3 30  or  %o2, 0x330, %o3	! 0xcf007730
a002f058:  92 12 a3 34  or  %o2, 0x334, %o1
a002f05c:  c0 22 c0 00  clr  [ %o3 ]
a002f060:  c0 22 40 00  clr  [ %o1 ]
a002f064:  90 10 20 03  mov  3, %o0
a002f068:  7f ff fc d7  call  0xa002e3c4
a002f06c:  92 10 20 01  mov  1, %o1
a002f070:  1b 2a 00 b2  sethi  %hi(0xa802c800), %o5
a002f074:  d0 03 61 e4  ld  [ %o5 + 0x1e4 ], %o0	! 0xa802c9e4
a002f078:  82 12 20 08  or  %o0, 8, %g1
a002f07c:  c2 23 61 e4  st  %g1, [ %o5 + 0x1e4 ]
a002f080:  81 c7 e0 08  ret
a002f084:  81 e8 00 00  restore
