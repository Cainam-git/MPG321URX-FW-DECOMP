# leon2m FUN_a00be0f0 0xa00be0f0-0xa00be140 (80 bytes)
a00be0f0:  9d e3 bf 98  save  %sp, -104, %sp
a00be0f4:  1f 2a 00 b4  sethi  %hi(0xa802d000), %o7
a00be0f8:  d6 03 e3 3c  ld  [ %o7 + 0x33c ], %o3	! 0xa802d33c
a00be0fc:  95 32 e0 16  srl  %o3, 0x16, %o2
a00be100:  90 0a a0 01  and  %o2, 1, %o0
a00be104:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00be108:  9a 12 60 78  or  %o1, 0x78, %o5	! 0xa802d078
a00be10c:  82 02 20 30  add  %o0, 0x30, %g1
a00be110:  98 10 20 30  mov  0x30, %o4
a00be114:  c2 2b 60 09  stb  %g1, [ %o5 + 9 ]
a00be118:  d8 2b 60 08  stb  %o4, [ %o5 + 8 ]
a00be11c:  d8 2b 60 07  stb  %o4, [ %o5 + 7 ]
a00be120:  7f ff f2 c7  call  0xa00bac3c
a00be124:  90 10 20 46  mov  0x46, %o0
a00be128:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00be12c:  7f ff f2 09  call  0xa00ba950
a00be130:  90 10 00 18  mov  %i0, %o0
a00be134:  7f ff f2 ac  call  0xa00babe4
a00be138:  93 e8 20 0b  restore  %g0, 0xb, %o1
a00be13c:  01 00 00 00  nop
