# leon2m FUN_a0143bc4 0xa0143bc4-0xa0143c14 (80 bytes)
a0143bc4:  9d e3 bf 98  save  %sp, -104, %sp
a0143bc8:  7f ff 85 74  call  0xa0125198
a0143bcc:  90 0e 20 ff  and  %i0, 0xff, %o0
a0143bd0:  7f ff f9 92  call  0xa0142218
a0143bd4:  90 0a 20 ff  and  %o0, 0xff, %o0
a0143bd8:  9e 0a 20 ff  and  %o0, 0xff, %o7
a0143bdc:  97 2b e0 03  sll  %o7, 3, %o3
a0143be0:  94 02 c0 0f  add  %o3, %o7, %o2
a0143be4:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a0143be8:  98 02 80 0a  add  %o2, %o2, %o4
a0143bec:  82 12 61 16  or  %o1, 0x116, %g1
a0143bf0:  d0 10 40 0c  lduh  [ %g1 + %o4 ], %o0
a0143bf4:  9b 32 20 0c  srl  %o0, 0xc, %o5
a0143bf8:  80 a3 60 05  cmp  %o5, 5
a0143bfc:  12 80 00 03  bne  0xa0143c08
a0143c00:  b0 10 20 00  clr  %i0
a0143c04:  b0 10 20 02  mov  2, %i0
a0143c08:  b0 0e 20 02  and  %i0, 2, %i0
a0143c0c:  81 c7 e0 08  ret
a0143c10:  81 e8 00 00  restore
