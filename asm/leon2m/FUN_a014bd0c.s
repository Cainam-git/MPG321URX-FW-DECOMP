# leon2m FUN_a014bd0c 0xa014bd0c-0xa014bd70 (100 bytes)  [FUN_a014bd68 = unreachable ret/restore tail, merged]
a014bd0c:  9d e3 bf 98  save  %sp, -104, %sp
a014bd10:  82 0e 20 ff  and  %i0, 0xff, %g1
a014bd14:  80 a0 60 00  cmp  %g1, 0
a014bd18:  02 80 00 11  be  0xa014bd5c
a014bd1c:  b0 10 20 00  clr  %i0
a014bd20:  90 10 20 01  mov  1, %o0
a014bd24:  80 a0 60 01  cmp  %g1, 1
a014bd28:  02 80 00 09  be  0xa014bd4c
a014bd2c:  b0 10 20 01  mov  1, %i0
a014bd30:  80 a0 60 02  cmp  %g1, 2
a014bd34:  02 80 00 06  be  0xa014bd4c
a014bd38:  90 10 20 03  mov  3, %o0
a014bd3c:  80 a0 60 03  cmp  %g1, 3
a014bd40:  12 80 00 09  bne  0xa014bd64
a014bd44:  b0 10 20 02  mov  2, %i0
a014bd48:  30 80 00 05  b,a   0xa014bd5c
a014bd4c:  7f ff b7 07  call  0xa0139968
a014bd50:  01 00 00 00  nop
a014bd54:  7f ff bb 39  call  0xa013aa38
a014bd58:  81 e8 00 00  restore
a014bd5c:  7f ff b7 03  call  0xa0139968
a014bd60:  81 e8 00 00  restore
a014bd64:  01 00 00 00  nop
a014bd68:  81 c7 e0 08  ret
a014bd6c:  81 e8 00 00  restore
