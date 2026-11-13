# leon2m FUN_a0148974 0xa0148974-0xa0148a24 (176 bytes)
a0148974:  9d e3 bf 98  save  %sp, -104, %sp
a0148978:  40 00 29 7e  call  0xa0152f70
a014897c:  b0 10 3f ff  mov  -1, %i0
a0148980:  90 0a 20 ff  and  %o0, 0xff, %o0
a0148984:  80 a2 20 09  cmp  %o0, 9
a0148988:  02 80 00 12  be  0xa01489d0
a014898c:  13 2a 00 b8  sethi  %hi(0xa802e000), %o1
a0148990:  04 80 00 08  ble  0xa01489b0
a0148994:  80 a2 20 08  cmp  %o0, 8
a0148998:  80 a2 20 0a  cmp  %o0, 0xa
a014899c:  02 80 00 0f  be  0xa01489d8
a01489a0:  80 a2 20 0b  cmp  %o0, 0xb
a01489a4:  12 80 00 1e  bne  0xa0148a1c
a01489a8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01489ac:  30 80 00 13  b,a   0xa01489f8
a01489b0:  32 80 00 1b  bne,a   0xa0148a1c
a01489b4:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01489b8:  03 2a 00 b8  sethi  %hi(0xa802e000), %g1
a01489bc:  d0 08 61 26  ldub  [ %g1 + 0x126 ], %o0	! 0xa802e126
a01489c0:  7f ff 71 e0  call  0xa0125140
a01489c4:  01 00 00 00  nop
a01489c8:  10 80 00 14  b  0xa0148a18
a01489cc:  b0 10 00 08  mov  %o0, %i0
a01489d0:  10 bf ff fc  b  0xa01489c0
a01489d4:  d0 0a 61 38  ldub  [ %o1 + 0x138 ], %o0
a01489d8:  7f ff 88 e5  call  0xa012ad6c
a01489dc:  01 00 00 00  nop
a01489e0:  80 8a 20 ff  btst  0xff, %o0
a01489e4:  02 80 00 0b  be  0xa0148a10
a01489e8:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a01489ec:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a01489f0:  10 bf ff f4  b  0xa01489c0
a01489f4:  d0 0a e1 5c  ldub  [ %o3 + 0x15c ], %o0	! 0xa802e15c
a01489f8:  7f ff 88 dd  call  0xa012ad6c
a01489fc:  01 00 00 00  nop
a0148a00:  80 8a 20 ff  btst  0xff, %o0
a0148a04:  02 bf ff fb  be  0xa01489f0
a0148a08:  17 2a 00 b8  sethi  %hi(0xa802e000), %o3
a0148a0c:  15 2a 00 b8  sethi  %hi(0xa802e000), %o2
a0148a10:  10 bf ff ec  b  0xa01489c0
a0148a14:  d0 0a a1 4a  ldub  [ %o2 + 0x14a ], %o0	! 0xa802e14a
a0148a18:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0148a1c:  81 c7 e0 08  ret
a0148a20:  81 e8 00 00  restore
