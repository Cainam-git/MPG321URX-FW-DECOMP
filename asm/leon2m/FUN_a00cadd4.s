# leon2m FUN_a00cadd4 0xa00cadd4-0xa00cae64 (144 bytes)
a00cadd4:  9d e3 bf 98  save  %sp, -104, %sp
a00cadd8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00caddc:  80 a6 20 02  cmp  %i0, 2
a00cade0:  02 80 00 19  be  0xa00cae44
a00cade4:  80 a6 20 03  cmp  %i0, 3
a00cade8:  02 80 00 1a  be  0xa00cae50
a00cadec:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a00cadf0:  c2 0a 60 d9  ldub  [ %o1 + 0xd9 ], %g1	! 0xa802d0d9
a00cadf4:  94 08 60 ff  and  %g1, 0xff, %o2
a00cadf8:  98 02 bf d0  add  %o2, -48, %o4
a00cadfc:  9a 0b 20 ff  and  %o4, 0xff, %o5
a00cae00:  80 a3 60 01  cmp  %o5, 1
a00cae04:  18 80 00 16  bgu  0xa00cae5c
a00cae08:  82 10 20 ff  mov  0xff, %g1
a00cae0c:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a00cae10:  40 00 3f 44  call  0xa00dab20
a00cae14:  d8 2a e0 70  stb  %o4, [ %o3 + 0x70 ]	! 0xa802d470
a00cae18:  7f ff b6 ad  call  0xa00b88cc
a00cae1c:  01 00 00 00  nop
a00cae20:  7f ff bf 13  call  0xa00baa6c
a00cae24:  90 10 00 18  mov  %i0, %o0
a00cae28:  7f ff be ca  call  0xa00ba950
a00cae2c:  90 10 00 18  mov  %i0, %o0
a00cae30:  90 10 00 18  mov  %i0, %o0
a00cae34:  7f ff bf 53  call  0xa00bab80
a00cae38:  92 10 20 06  mov  6, %o1
a00cae3c:  10 80 00 08  b  0xa00cae5c
a00cae40:  82 10 20 00  clr  %g1
a00cae44:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00cae48:  10 bf ff eb  b  0xa00cadf4
a00cae4c:  c2 08 60 49  ldub  [ %g1 + 0x49 ], %g1	! 0xa802d049
a00cae50:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a00cae54:  10 bf ff e8  b  0xa00cadf4
a00cae58:  c2 0a 20 a1  ldub  [ %o0 + 0xa1 ], %g1	! 0xa802d0a1
a00cae5c:  81 c7 e0 08  ret
a00cae60:  91 e8 00 01  restore  %g0, %g1, %o0
