# leon2s FUN_a00db9d4 0xa00db9d4-0xa00dba70 (156 bytes)
a00db9d4:  9d e3 bf 80  save  %sp, -128, %sp
a00db9d8:  a0 07 bf e0  add  %fp, -32, %l0
a00db9dc:  92 10 20 00  clr  %o1
a00db9e0:  94 10 20 13  mov  0x13, %o2
a00db9e4:  40 3b 96 f2  call  0xa0fc15ac
a00db9e8:  90 10 00 10  mov  %l0, %o0
a00db9ec:  da 07 bf f0  ld  [ %fp + -16 ], %o5
a00db9f0:  03 00 20 00  sethi  %hi(0x800000), %g1
a00db9f4:  9a 13 40 01  or  %o5, %g1, %o5
a00db9f8:  03 00 10 00  sethi  %hi(0x400000), %g1
a00db9fc:  82 2b 40 01  andn  %o5, %g1, %g1
a00dba00:  1b 00 0f c0  sethi  %hi(0x3f0000), %o5
a00dba04:  9a 28 40 0d  andn  %g1, %o5, %o5
a00dba08:  c2 07 bf e0  ld  [ %fp + -32 ], %g1
a00dba0c:  17 3c 00 00  sethi  %hi(0xf0000000), %o3
a00dba10:  96 28 40 0b  andn  %g1, %o3, %o3
a00dba14:  03 00 05 00  sethi  %hi(0x140000), %g1
a00dba18:  9a 13 40 01  or  %o5, %g1, %o5
a00dba1c:  03 04 00 00  sethi  %hi(0x10000000), %g1
a00dba20:  96 12 c0 01  or  %o3, %g1, %o3
a00dba24:  03 00 00 20  sethi  %hi(0x8000), %g1
a00dba28:  9a 13 40 01  or  %o5, %g1, %o5
a00dba2c:  03 00 00 10  sethi  %hi(0x4000), %g1
a00dba30:  9a 13 40 01  or  %o5, %g1, %o5
a00dba34:  19 03 c0 00  sethi  %hi(0xf000000), %o4
a00dba38:  03 01 c0 00  sethi  %hi(0x7000000), %g1
a00dba3c:  98 2a c0 0c  andn  %o3, %o4, %o4
a00dba40:  98 13 00 01  or  %o4, %g1, %o4
a00dba44:  03 00 00 04  sethi  %hi(0x1000), %g1
a00dba48:  82 2b 40 01  andn  %o5, %g1, %g1
a00dba4c:  d8 27 bf e0  st  %o4, [ %fp + -32 ]
a00dba50:  c2 27 bf f0  st  %g1, [ %fp + -16 ]
a00dba54:  90 10 00 10  mov  %l0, %o0
a00dba58:  92 10 20 01  mov  1, %o1
a00dba5c:  7f ff eb fe  call  0xa00d6a54
a00dba60:  94 10 20 01  mov  1, %o2
a00dba64:  01 00 00 00  nop
a00dba68:  81 c7 e0 08  ret
a00dba6c:  81 e8 00 00  restore
