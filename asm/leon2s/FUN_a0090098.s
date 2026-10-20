# leon2s FUN_a0090098 0xa0090098-0xa0090100 (104 bytes)
a0090098:  9d e3 bf 98  save  %sp, -104, %sp
a009009c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a00900a0:  92 10 21 44  mov  0x144, %o1
a00900a4:  40 00 59 36  call  0xa00a657c
a00900a8:  90 10 00 18  mov  %i0, %o0
a00900ac:  82 0a 20 e0  and  %o0, 0xe0, %g1
a00900b0:  92 10 20 3a  mov  0x3a, %o1
a00900b4:  80 a0 60 60  cmp  %g1, 0x60
a00900b8:  02 80 00 08  be  0xa00900d8
a00900bc:  90 10 00 18  mov  %i0, %o0
a00900c0:  7f ff ff cc  call  0xa008fff0
a00900c4:  90 10 00 18  mov  %i0, %o0
a00900c8:  80 8a 20 ff  btst  0xff, %o0
a00900cc:  92 10 20 3a  mov  0x3a, %o1
a00900d0:  02 80 00 06  be  0xa00900e8
a00900d4:  90 10 00 18  mov  %i0, %o0
a00900d8:  40 00 5a 18  call  0xa00a6938
a00900dc:  01 00 00 00  nop
a00900e0:  10 80 00 05  b  0xa00900f4
a00900e4:  91 2a 20 11  sll  %o0, 0x11, %o0
a00900e8:  40 00 5a 14  call  0xa00a6938
a00900ec:  92 10 20 3a  mov  0x3a, %o1
a00900f0:  91 2a 20 10  sll  %o0, 0x10, %o0
a00900f4:  b1 32 20 10  srl  %o0, 0x10, %i0
a00900f8:  81 c7 e0 08  ret
a00900fc:  81 e8 00 00  restore
