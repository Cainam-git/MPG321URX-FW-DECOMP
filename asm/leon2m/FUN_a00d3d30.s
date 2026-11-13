# leon2m FUN_a00d3d30 0xa00d3d30-0xa00d3dbc (140 bytes)
a00d3d30:  9d e3 bf 98  save  %sp, -104, %sp
a00d3d34:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a00d3d38:  c2 08 62 9a  ldub  [ %g1 + 0x29a ], %g1	! 0xa802d29a
a00d3d3c:  80 a0 60 46  cmp  %g1, 0x46
a00d3d40:  08 80 00 0d  bleu  0xa00d3d74
a00d3d44:  90 00 7f ba  add  %g1, -70, %o0
a00d3d48:  40 02 07 be  call  0xa0155c40
a00d3d4c:  01 00 00 00  nop
a00d3d50:  19 00 06 61  sethi  %hi(0x198400), %o4
a00d3d54:  40 02 06 b7  call  0xa0155830
a00d3d58:  d2 03 23 48  ld  [ %o4 + 0x348 ], %o1	! 0x198748
a00d3d5c:  17 00 06 61  sethi  %hi(0x198400), %o3
a00d3d60:  40 02 07 2e  call  0xa0155a18
a00d3d64:  d2 02 e3 4c  ld  [ %o3 + 0x34c ], %o1	! 0x19874c
a00d3d68:  15 00 06 61  sethi  %hi(0x198400), %o2
a00d3d6c:  10 80 00 0d  b  0xa00d3da0
a00d3d70:  d2 02 a3 50  ld  [ %o2 + 0x350 ], %o1	! 0x198750
a00d3d74:  40 02 07 b3  call  0xa0155c40
a00d3d78:  90 10 00 01  mov  %g1, %o0
a00d3d7c:  31 00 06 61  sethi  %hi(0x198400), %i0
a00d3d80:  40 02 06 ac  call  0xa0155830
a00d3d84:  d2 06 23 54  ld  [ %i0 + 0x354 ], %o1	! 0x198754
a00d3d88:  1f 00 06 61  sethi  %hi(0x198400), %o7
a00d3d8c:  d2 03 e3 58  ld  [ %o7 + 0x358 ], %o1	! 0x198758
a00d3d90:  40 02 07 22  call  0xa0155a18
a00d3d94:  01 00 00 00  nop
a00d3d98:  1b 00 06 61  sethi  %hi(0x198400), %o5
a00d3d9c:  d2 03 63 5c  ld  [ %o5 + 0x35c ], %o1	! 0x19875c
a00d3da0:  40 02 06 7b  call  0xa015578c
a00d3da4:  01 00 00 00  nop
a00d3da8:  40 02 05 05  call  0xa01551bc
a00d3dac:  01 00 00 00  nop
a00d3db0:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00d3db4:  81 c7 e0 08  ret
a00d3db8:  81 e8 00 00  restore
