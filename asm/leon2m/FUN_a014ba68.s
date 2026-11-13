# leon2m FUN_a014ba68 0xa014ba68-0xa014bac4 (92 bytes)
a014ba68:  9d e3 bf 98  save  %sp, -104, %sp
a014ba6c:  7f ff b4 fc  call  0xa0138e5c
a014ba70:  b0 10 20 01  mov  1, %i0
a014ba74:  90 0a 20 ff  and  %o0, 0xff, %o0
a014ba78:  80 a2 20 01  cmp  %o0, 1
a014ba7c:  02 80 00 10  be  0xa014babc
a014ba80:  b0 0e 20 07  and  %i0, 7, %i0
a014ba84:  04 80 00 0a  ble  0xa014baac
a014ba88:  b0 10 20 02  mov  2, %i0
a014ba8c:  80 a2 20 02  cmp  %o0, 2
a014ba90:  02 80 00 0a  be  0xa014bab8
a014ba94:  80 a2 20 03  cmp  %o0, 3
a014ba98:  b0 10 20 03  mov  3, %i0
a014ba9c:  32 80 00 07  bne,a   0xa014bab8
a014baa0:  b0 10 20 04  mov  4, %i0
a014baa4:  10 80 00 06  b  0xa014babc
a014baa8:  b0 0e 20 07  and  %i0, 7, %i0
a014baac:  80 a2 20 00  cmp  %o0, 0
a014bab0:  10 bf ff fb  b  0xa014ba9c
a014bab4:  b0 10 20 00  clr  %i0
a014bab8:  b0 0e 20 07  and  %i0, 7, %i0
a014babc:  81 c7 e0 08  ret
a014bac0:  81 e8 00 00  restore
