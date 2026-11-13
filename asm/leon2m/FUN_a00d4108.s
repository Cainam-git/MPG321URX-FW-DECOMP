# leon2m FUN_a00d4108 0xa00d4108-0xa00d4164 (92 bytes)
a00d4108:  9d e3 bf 98  save  %sp, -104, %sp
a00d410c:  40 01 c0 c2  call  0xa0144414
a00d4110:  b2 10 20 14  mov  0x14, %i1
a00d4114:  9a 0e 20 ff  and  %i0, 0xff, %o5
a00d4118:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00d411c:  80 a3 60 64  cmp  %o5, 0x64
a00d4120:  08 80 00 03  bleu  0xa00d412c
a00d4124:  b6 10 20 01  mov  1, %i3
a00d4128:  9a 10 20 64  mov  0x64, %o5
a00d412c:  9f 2b 60 06  sll  %o5, 6, %o7
a00d4130:  94 23 c0 0d  sub  %o7, %o5, %o2
a00d4134:  1b 14 7a e1  sethi  %hi(0x51eb8400), %o5
a00d4138:  98 13 61 1f  or  %o5, 0x11f, %o4	! 0x51eb851f
a00d413c:  80 5a 80 0c  smul  %o2, %o4, %g0
a00d4140:  97 40 00 00  rd  %y, %o3
a00d4144:  93 3a e0 05  sra  %o3, 5, %o1
a00d4148:  83 3a a0 1f  sra  %o2, 0x1f, %g1
a00d414c:  90 22 40 01  sub  %o1, %g1, %o0
a00d4150:  b5 2a 20 10  sll  %o0, 0x10, %i2
a00d4154:  b5 36 a0 10  srl  %i2, 0x10, %i2
a00d4158:  40 01 c5 ac  call  0xa0145808
a00d415c:  81 e8 00 00  restore
a00d4160:  01 00 00 00  nop
