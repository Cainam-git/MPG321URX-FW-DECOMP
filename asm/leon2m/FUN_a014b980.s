# leon2m FUN_a014b980 0xa014b980-0xa014ba68 (232 bytes)  [FUN_a014ba60 = unreachable ret/restore tail, merged]
a014b980:  9d e3 bf 98  save  %sp, -104, %sp
a014b984:  90 0e 20 ff  and  %i0, 0xff, %o0
a014b988:  80 a2 20 fe  cmp  %o0, 0xfe
a014b98c:  22 80 00 12  be,a   0xa014b9d4
a014b990:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014b994:  7f ff 66 01  call  0xa0125198
a014b998:  01 00 00 00  nop
a014b99c:  7f ff da 1f  call  0xa0142218
a014b9a0:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b9a4:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b9a8:  80 a2 20 01  cmp  %o0, 1
a014b9ac:  22 80 00 2a  be,a   0xa014ba54
a014b9b0:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014b9b4:  04 80 00 20  ble  0xa014ba34
a014b9b8:  80 a2 20 02  cmp  %o0, 2
a014b9bc:  02 80 00 23  be  0xa014ba48
a014b9c0:  80 a2 20 03  cmp  %o0, 3
a014b9c4:  12 80 00 26  bne  0xa014ba5c
a014b9c8:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014b9cc:  10 80 00 18  b  0xa014ba2c
a014b9d0:  b0 10 20 81  mov  0x81, %i0
a014b9d4:  90 10 20 51  mov  0x51, %o0
a014b9d8:  7f ff b4 92  call  0xa0138c20
a014b9dc:  92 10 00 19  mov  %i1, %o1
a014b9e0:  90 10 20 61  mov  0x61, %o0
a014b9e4:  7f ff b4 8f  call  0xa0138c20
a014b9e8:  92 10 00 19  mov  %i1, %o1
a014b9ec:  7f ff 7c e0  call  0xa012ad6c
a014b9f0:  01 00 00 00  nop
a014b9f4:  90 0a 20 ff  and  %o0, 0xff, %o0
a014b9f8:  80 a2 20 01  cmp  %o0, 1
a014b9fc:  02 80 00 03  be  0xa014ba08
a014ba00:  90 10 20 81  mov  0x81, %o0
a014ba04:  90 10 20 71  mov  0x71, %o0
a014ba08:  7f ff b4 86  call  0xa0138c20
a014ba0c:  92 10 00 19  mov  %i1, %o1
a014ba10:  7f ff 7c d7  call  0xa012ad6c
a014ba14:  01 00 00 00  nop
a014ba18:  82 0a 20 ff  and  %o0, 0xff, %g1
a014ba1c:  80 a0 60 01  cmp  %g1, 1
a014ba20:  02 80 00 0b  be  0xa014ba4c
a014ba24:  01 00 00 00  nop
a014ba28:  b0 10 20 81  mov  0x81, %i0	! 0x81
a014ba2c:  7f ff b4 7d  call  0xa0138c20
a014ba30:  81 e8 00 00  restore
a014ba34:  80 a2 20 00  cmp  %o0, 0
a014ba38:  12 80 00 09  bne  0xa014ba5c
a014ba3c:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014ba40:  7f ff b4 78  call  0xa0138c20
a014ba44:  91 e8 20 51  restore  %g0, 0x51, %o0
a014ba48:  b2 0e 60 ff  and  %i1, 0xff, %i1
a014ba4c:  7f ff b4 75  call  0xa0138c20
a014ba50:  91 e8 20 71  restore  %g0, 0x71, %o0
a014ba54:  7f ff b4 73  call  0xa0138c20
a014ba58:  91 e8 20 61  restore  %g0, 0x61, %o0
a014ba5c:  01 00 00 00  nop
a014ba60:  81 c7 e0 08  ret
a014ba64:  81 e8 00 00  restore
