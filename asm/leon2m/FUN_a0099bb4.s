# leon2m FUN_a0099bb4 0xa0099bb4-0xa0099c0c (88 bytes)
a0099bb4:  9d e3 bf 98  save  %sp, -104, %sp
a0099bb8:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a0099bbc:  a0 12 62 90  or  %o1, 0x290, %l0	! 0xa802d290
a0099bc0:  40 00 3d ff  call  0xa00a93bc
a0099bc4:  d0 0c 20 ac  ldub  [ %l0 + 0xac ], %o0
a0099bc8:  23 2a 00 97  sethi  %hi(0xa8025c00), %l1
a0099bcc:  d0 0c 60 55  ldub  [ %l1 + 0x55 ], %o0	! 0xa8025c55
a0099bd0:  d0 2c 20 ac  stb  %o0, [ %l0 + 0xac ]
a0099bd4:  90 10 20 2a  mov  0x2a, %o0
a0099bd8:  40 00 56 1d  call  0xa00af44c
a0099bdc:  92 10 20 03  mov  3, %o1
a0099be0:  9a 10 20 b3  mov  0xb3, %o5
a0099be4:  03 2a 00 ab  sethi  %hi(0xa802ac00), %g1
a0099be8:  da 20 63 ec  st  %o5, [ %g1 + 0x3ec ]	! 0xa802afec
a0099bec:  90 10 20 02  mov  2, %o0
a0099bf0:  40 00 3e 98  call  0xa00a9650
a0099bf4:  92 10 20 01  mov  1, %o1
a0099bf8:  40 01 02 d7  call  0xa00da754
a0099bfc:  d0 0c 20 ac  ldub  [ %l0 + 0xac ], %o0
a0099c00:  c0 2c 60 55  clrb  [ %l1 + 0x55 ]
a0099c04:  81 c7 e0 08  ret
a0099c08:  81 e8 00 00  restore
