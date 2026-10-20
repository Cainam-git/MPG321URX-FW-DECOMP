# leon2s FUN_a0095e08 0xa0095e08-0xa0095e9c (148 bytes)
a0095e08:  9d e3 bf 98  save  %sp, -104, %sp
a0095e0c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a0095e10:  80 a6 20 01  cmp  %i0, 1
a0095e14:  18 80 00 21  bgu  0xa0095e98
a0095e18:  80 a6 20 00  cmp  %i0, 0
a0095e1c:  12 80 00 0d  bne  0xa0095e50
a0095e20:  80 a6 20 01  cmp  %i0, 1
a0095e24:  7f ff 69 78  call  0xa0070404
a0095e28:  01 00 00 00  nop
a0095e2c:  80 8a 20 ff  btst  0xff, %o0
a0095e30:  32 80 00 18  bne,a   0xa0095e90
a0095e34:  b0 10 20 00  clr  %i0
a0095e38:  7f ff ef 5d  call  0xa0091bac
a0095e3c:  90 10 20 00  clr  %o0
a0095e40:  80 8a 20 ff  btst  0xff, %o0
a0095e44:  02 80 00 15  be  0xa0095e98
a0095e48:  90 10 20 00  clr  %o0
a0095e4c:  30 80 00 0d  b,a   0xa0095e80
a0095e50:  12 80 00 12  bne  0xa0095e98
a0095e54:  01 00 00 00  nop
a0095e58:  7f ff 69 6f  call  0xa0070414
a0095e5c:  01 00 00 00  nop
a0095e60:  80 8a 20 ff  btst  0xff, %o0
a0095e64:  32 80 00 0b  bne,a   0xa0095e90
a0095e68:  b0 10 20 01  mov  1, %i0
a0095e6c:  7f ff ef 50  call  0xa0091bac
a0095e70:  90 10 20 01  mov  1, %o0
a0095e74:  80 8a 20 ff  btst  0xff, %o0
a0095e78:  02 80 00 08  be  0xa0095e98
a0095e7c:  90 10 20 01  mov  1, %o0
a0095e80:  7f ff fc 88  call  0xa00950a0
a0095e84:  92 10 20 09  mov  9, %o1
a0095e88:  7f ff ed bc  call  0xa0091578
a0095e8c:  81 e8 00 00  restore
a0095e90:  7f ff ff ba  call  0xa0095d78
a0095e94:  81 e8 00 00  restore
a0095e98:  01 00 00 00  nop
