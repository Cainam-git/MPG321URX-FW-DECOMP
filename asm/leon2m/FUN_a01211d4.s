# leon2m FUN_a01211d4 0xa01211d4-0xa0121258 (132 bytes)
a01211d4:  9d e3 bf 98  save  %sp, -104, %sp
a01211d8:  b0 0e 20 ff  and  %i0, 0xff, %i0
a01211dc:  92 10 20 04  mov  4, %o1
a01211e0:  7f ff 42 2c  call  0xa00f1a90
a01211e4:  90 10 00 18  mov  %i0, %o0
a01211e8:  82 0a 20 03  and  %o0, 3, %g1
a01211ec:  92 10 20 03  mov  3, %o1
a01211f0:  80 a0 60 03  cmp  %g1, 3
a01211f4:  02 80 00 10  be  0xa0121234
a01211f8:  90 10 00 18  mov  %i0, %o0
a01211fc:  92 10 20 03  mov  3, %o1
a0121200:  7f ff 42 24  call  0xa00f1a90
a0121204:  90 10 00 18  mov  %i0, %o0
a0121208:  80 8a 20 20  btst  0x20, %o0
a012120c:  90 10 00 18  mov  %i0, %o0
a0121210:  92 10 20 11  mov  0x11, %o1
a0121214:  12 80 00 0f  bne  0xa0121250
a0121218:  b0 10 20 00  clr  %i0
a012121c:  7f ff 43 60  call  0xa00f1f9c
a0121220:  01 00 00 00  nop
a0121224:  90 0a 20 04  and  %o0, 4, %o0
a0121228:  80 a0 00 08  cmp  %g0, %o0
a012122c:  10 80 00 09  b  0xa0121250
a0121230:  b0 40 20 00  addx  %g0, 0, %i0
a0121234:  7f ff 42 17  call  0xa00f1a90
a0121238:  01 00 00 00  nop
a012123c:  92 10 20 8f  mov  0x8f, %o1	! 0x8f
a0121240:  7f ff 41 14  call  0xa00f1690
a0121244:  90 0a 20 01  and  %o0, 1, %o0
a0121248:  10 bf ff f8  b  0xa0121228
a012124c:  90 0a 20 04  and  %o0, 4, %o0
a0121250:  81 c7 e0 08  ret
a0121254:  81 e8 00 00  restore
