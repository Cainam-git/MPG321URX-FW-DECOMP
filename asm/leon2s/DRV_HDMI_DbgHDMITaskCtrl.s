# leon2s DRV_HDMI_DbgHDMITaskCtrl 0xa00a3250-0xa00a32d0 (128 bytes)
a00a3250:  9d e3 bf 98  save  %sp, -104, %sp
a00a3254:  11 28 02 d3  sethi  %hi(0xa00b4c00), %o0
a00a3258:  7f ff 40 9b  call  0xa00734c4
a00a325c:  90 12 20 c0  or  %o0, 0xc0, %o0	! 0xa00b4cc0
a00a3260:  c2 0e 20 03  ldub  [ %i0 + 3 ], %g1
a00a3264:  80 a0 60 00  cmp  %g1, 0
a00a3268:  12 80 00 0c  bne  0xa00a3298
a00a326c:  da 0e 20 07  ldub  [ %i0 + 7 ], %o5
a00a3270:  80 a3 60 00  cmp  %o5, 0
a00a3274:  02 80 00 05  be  0xa00a3288
a00a3278:  90 10 20 00  clr  %o0
a00a327c:  7f ff 40 b1  call  0xa0073540
a00a3280:  b0 10 20 00  clr  %i0
a00a3284:  30 80 00 11  b,a   0xa00a32c8
a00a3288:  7f ff 40 ce  call  0xa00735c0
a00a328c:  90 10 20 00  clr  %o0
a00a3290:  10 80 00 0e  b  0xa00a32c8
a00a3294:  b0 10 20 00  clr  %i0
a00a3298:  80 a0 60 01  cmp  %g1, 1
a00a329c:  12 80 00 0b  bne  0xa00a32c8
a00a32a0:  b0 10 20 00  clr  %i0
a00a32a4:  80 a3 60 00  cmp  %o5, 0
a00a32a8:  02 80 00 05  be  0xa00a32bc
a00a32ac:  90 10 20 01  mov  1, %o0
a00a32b0:  7f ff e4 18  call  0xa009c310
a00a32b4:  01 00 00 00  nop
a00a32b8:  30 80 00 04  b,a   0xa00a32c8
a00a32bc:  7f ff e3 f2  call  0xa009c284
a00a32c0:  90 10 20 01  mov  1, %o0
a00a32c4:  b0 10 20 00  clr  %i0
a00a32c8:  81 c7 e0 08  ret
a00a32cc:  81 e8 00 00  restore
