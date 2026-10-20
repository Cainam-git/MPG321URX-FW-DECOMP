# leon2m FUN_a014dc28 0xa014dc28-0xa014dc74 (76 bytes)
a014dc28:  9d e3 bf 98  save  %sp, -104, %sp
a014dc2c:  7f ff 0c ff  call  0xa0111028
a014dc30:  90 10 20 02  mov  2, %o0
a014dc34:  a0 0e 20 ff  and  %i0, 0xff, %l0
a014dc38:  b0 10 20 02  mov  2, %i0
a014dc3c:  80 8c 20 01  btst  1, %l0
a014dc40:  12 80 00 07  bne  0xa014dc5c
a014dc44:  90 10 20 01  mov  1, %o0
a014dc48:  80 8c 20 02  btst  2, %l0
a014dc4c:  02 80 00 08  be  0xa014dc6c
a014dc50:  01 00 00 00  nop
a014dc54:  7f ff 0d 0d  call  0xa0111088
a014dc58:  81 e8 00 00  restore
a014dc5c:  7f ff 0d 0b  call  0xa0111088
a014dc60:  01 00 00 00  nop
a014dc64:  10 bf ff fa  b  0xa014dc4c
a014dc68:  80 8c 20 02  btst  2, %l0
a014dc6c:  81 c7 e0 08  ret
a014dc70:  81 e8 00 00  restore
