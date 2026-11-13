# leon2s FUN_a0087074 0xa0087074-0xa00870a4 (48 bytes)
a0087074:  90 0a 20 ff  and  %o0, 0xff, %o0
a0087078:  82 02 00 08  add  %o0, %o0, %g1
a008707c:  82 00 40 08  add  %g1, %o0, %g1
a0087080:  1b 2a 01 f3  sethi  %hi(0xa807cc00), %o5
a0087084:  82 00 40 01  add  %g1, %g1, %g1
a0087088:  9a 13 61 2e  or  %o5, 0x12e, %o5
a008708c:  82 00 40 0d  add  %g1, %o5, %g1
a0087090:  c2 08 60 01  ldub  [ %g1 + 1 ], %g1
a0087094:  82 18 60 14  xor  %g1, 0x14, %g1
a0087098:  80 a0 00 01  cmp  %g0, %g1
a008709c:  81 c3 e0 08  retl
a00870a0:  90 60 3f ff  subx  %g0, -1, %o0
