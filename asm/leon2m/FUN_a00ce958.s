# leon2m FUN_a00ce958 0xa00ce958-0xa00ce9c0 (104 bytes)
a00ce958:  9d e3 bf 98  save  %sp, -104, %sp
a00ce95c:  9f 2e 60 10  sll  %i1, 0x10, %o7
a00ce960:  99 33 e0 10  srl  %o7, 0x10, %o4
a00ce964:  80 a3 20 38  cmp  %o4, 0x38
a00ce968:  9a 60 20 00  subx  %g0, 0, %o5
a00ce96c:  96 0e 40 0d  and  %i1, %o5, %o3
a00ce970:  93 2a e0 10  sll  %o3, 0x10, %o1
a00ce974:  b3 32 60 10  srl  %o1, 0x10, %i1
a00ce978:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00ce97c:  11 00 06 60  sethi  %hi(0x198000), %o0
a00ce980:  94 10 00 19  mov  %i1, %o2
a00ce984:  92 10 00 18  mov  %i0, %o1
a00ce988:  40 00 41 fa  call  0xa00df170
a00ce98c:  90 12 23 00  or  %o0, 0x300, %o0
a00ce990:  03 00 00 40  sethi  %hi(0x10000), %g1
a00ce994:  94 10 60 00  mov  %g1, %o2	! 0x10000
a00ce998:  b3 2e 60 09  sll  %i1, 9, %i1
a00ce99c:  94 06 40 0a  add  %i1, %o2, %o2
a00ce9a0:  90 10 00 18  mov  %i0, %o0
a00ce9a4:  92 10 20 00  clr  %o1
a00ce9a8:  96 10 21 80  mov  0x180, %o3
a00ce9ac:  40 01 f2 35  call  0xa014b280
a00ce9b0:  98 10 20 01  mov  1, %o4
a00ce9b4:  67 fe f9 49  call  0x4008ced8
a00ce9b8:  81 e8 00 00  restore
a00ce9bc:  01 00 00 00  nop
