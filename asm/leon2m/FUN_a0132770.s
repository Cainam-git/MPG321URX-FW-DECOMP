# leon2m FUN_a0132770 0xa0132770-0xa01327e0 (112 bytes)
a0132770:  90 0a 20 ff  and  %o0, 0xff, %o0
a0132774:  80 a2 20 01  cmp  %o0, 1
a0132778:  02 80 00 0c  be  0xa01327a8
a013277c:  01 00 00 00  nop
a0132780:  04 80 00 0e  ble  0xa01327b8
a0132784:  80 a2 20 02  cmp  %o0, 2
a0132788:  02 80 00 04  be  0xa0132798
a013278c:  80 a2 20 04  cmp  %o0, 4
a0132790:  12 80 00 11  bne  0xa01327d4
a0132794:  01 00 00 00  nop
a0132798:  90 10 20 03  mov  3, %o0	! 0x3
a013279c:  82 13 c0 00  mov  %o7, %g1
a01327a0:  7f ff 2d f5  call  0xa00fdf74
a01327a4:  9e 10 40 00  mov  %g1, %o7
a01327a8:  90 10 20 02  mov  2, %o0
a01327ac:  82 13 c0 00  mov  %o7, %g1
a01327b0:  7f ff 2d f1  call  0xa00fdf74
a01327b4:  9e 10 40 00  mov  %g1, %o7
a01327b8:  80 a2 20 00  cmp  %o0, 0
a01327bc:  12 80 00 06  bne  0xa01327d4
a01327c0:  01 00 00 00  nop
a01327c4:  90 10 20 01  mov  1, %o0	! 0x1
a01327c8:  82 13 c0 00  mov  %o7, %g1
a01327cc:  7f ff 2d ea  call  0xa00fdf74
a01327d0:  9e 10 40 00  mov  %g1, %o7
a01327d4:  01 00 00 00  nop
a01327d8:  81 c3 e0 08  retl
a01327dc:  01 00 00 00  nop
