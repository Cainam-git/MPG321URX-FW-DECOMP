# leon2m FUN_a00df80c 0xa00df80c-0xa00df864 (80 bytes)
a00df80c:  17 2a 00 ad  sethi  %hi(0xa802b400), %o3
a00df810:  da 02 e1 30  ld  [ %o3 + 0x130 ], %o5	! 0xa802b530
a00df814:  03 00 06 64  sethi  %hi(0x199000), %g1
a00df818:  80 a3 60 0c  cmp  %o5, 0xc
a00df81c:  18 80 00 0a  bgu  0xa00df844
a00df820:  92 10 62 88  or  %g1, 0x288, %o1
a00df824:  91 2b 60 02  sll  %o5, 2, %o0
a00df828:  13 00 01 fd  sethi  %hi(0x7f400), %o1
a00df82c:  9a 12 62 98  or  %o1, 0x298, %o5	! 0x7f698
a00df830:  d8 03 40 08  ld  [ %o5 + %o0 ], %o4
a00df834:  81 c3 00 00  jmp  %o4
a00df838:  01 00 00 00  nop
a00df83c:  03 00 06 64  sethi  %hi(0x199000), %g1
a00df840:  92 10 62 90  or  %g1, 0x290, %o1	! 0x199290
a00df844:  9a 12 e1 30  or  %o3, 0x130, %o5
a00df848:  17 00 06 64  sethi  %hi(0x199000), %o3
a00df84c:  90 12 e2 98  or  %o3, 0x298, %o0	! 0x199298
a00df850:  d6 03 60 08  ld  [ %o5 + 8 ], %o3
a00df854:  d4 03 60 04  ld  [ %o5 + 4 ], %o2
a00df858:  82 13 c0 00  mov  %o7, %g1
a00df85c:  7f ff fe 45  call  0xa00df170
a00df860:  9e 10 40 00  mov  %g1, %o7
