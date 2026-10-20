# leon2m FUN_a00fbf5c 0xa00fbf5c-0xa00fbfd4 (120 bytes)
a00fbf5c:  9d e3 bf 98  save  %sp, -104, %sp
a00fbf60:  17 34 01 00  sethi  %hi(0xd0040000), %o3
a00fbf64:  15 00 02 6a  sethi  %hi(0x9a800), %o2
a00fbf68:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00fbf6c:  94 12 a0 14  or  %o2, 0x14, %o2
a00fbf70:  90 10 20 0c  mov  0xc, %o0
a00fbf74:  92 10 21 00  mov  0x100, %o1
a00fbf78:  80 a6 20 01  cmp  %i0, 1
a00fbf7c:  02 80 00 0a  be  0xa00fbfa4
a00fbf80:  98 10 00 0b  mov  %o3, %o4
a00fbf84:  d6 02 c0 00  ld  [ %o3 ], %o3
a00fbf88:  13 20 00 00  sethi  %hi(0x80000000), %o1
a00fbf8c:  90 2a c0 09  andn  %o3, %o1, %o0
a00fbf90:  d0 23 00 00  st  %o0, [ %o4 ]
a00fbf94:  90 10 20 0c  mov  0xc, %o0
a00fbf98:  67 fe 36 74  call  0x40089968
a00fbf9c:  92 10 21 00  mov  0x100, %o1
a00fbfa0:  30 80 00 0a  b,a   0xa00fbfc8
a00fbfa4:  d8 02 c0 00  ld  [ %o3 ], %o4
a00fbfa8:  03 20 00 00  sethi  %hi(0x80000000), %g1
a00fbfac:  9a 13 00 01  or  %o4, %g1, %o5
a00fbfb0:  da 22 c0 00  st  %o5, [ %o3 ]
a00fbfb4:  67 fe 3a 33  call  0x4008a880
a00fbfb8:  01 00 00 00  nop
a00fbfbc:  90 10 20 0c  mov  0xc, %o0	! 0xc
a00fbfc0:  67 fe 36 18  call  0x40089820
a00fbfc4:  92 10 21 00  mov  0x100, %o1
a00fbfc8:  01 00 00 00  nop
a00fbfcc:  81 c7 e0 08  ret
a00fbfd0:  81 e8 00 00  restore
