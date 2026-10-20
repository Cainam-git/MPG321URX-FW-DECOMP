# leon2s FUN_a00afd04 0xa00afd04-0xa00afd3c (56 bytes)
a00afd04:  9d e3 bf 98  save  %sp, -104, %sp
a00afd08:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00afd0c:  03 2a 01 f7  sethi  %hi(0xa807dc00), %g1
a00afd10:  82 10 60 18  or  %g1, 0x18, %g1	! 0xa807dc18
a00afd14:  9a 5e 21 2c  smul  %i0, 0x12c, %o5
a00afd18:  9a 03 40 01  add  %o5, %g1, %o5
a00afd1c:  f2 2b 61 15  stb  %i1, [ %o5 + 0x115 ]
a00afd20:  7f ff f0 b4  call  0xa00abff0
a00afd24:  90 10 00 18  mov  %i0, %o0
a00afd28:  7f ff f2 51  call  0xa00ac66c
a00afd2c:  90 10 00 18  mov  %i0, %o0
a00afd30:  7f ff ff 17  call  0xa00af98c
a00afd34:  81 e8 00 00  restore
a00afd38:  01 00 00 00  nop
