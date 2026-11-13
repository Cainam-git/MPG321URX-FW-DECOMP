# leon2m FUN_a014a428 0xa014a428-0xa014a4d8 (176 bytes)
a014a428:  9d e3 bf 98  save  %sp, -104, %sp
a014a42c:  7f ff 6b 5b  call  0xa0125198
a014a430:  90 0e 20 ff  and  %i0, 0xff, %o0
a014a434:  7f ff df 79  call  0xa0142218
a014a438:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a43c:  7f ff df 62  call  0xa01421c4
a014a440:  90 0a 20 ff  and  %o0, 0xff, %o0
a014a444:  82 0a 20 ff  and  %o0, 0xff, %g1
a014a448:  b0 10 20 00  clr  %i0
a014a44c:  90 10 20 10  mov  0x10, %o0
a014a450:  80 a0 60 71  cmp  %g1, 0x71
a014a454:  02 80 00 1b  be  0xa014a4c0
a014a458:  92 10 20 01  mov  1, %o1
a014a45c:  80 a0 60 81  cmp  %g1, 0x81
a014a460:  02 80 00 15  be  0xa014a4b4
a014a464:  b0 10 3f ff  mov  -1, %i0
a014a468:  82 0e 60 ff  and  %i1, 0xff, %g1
a014a46c:  9a 18 60 02  xor  %g1, 2, %o5
a014a470:  98 0e 20 ff  and  %i0, 0xff, %o4
a014a474:  80 a0 60 01  cmp  %g1, 1
a014a478:  90 10 00 0c  mov  %o4, %o0
a014a47c:  b2 10 20 00  clr  %i1
a014a480:  02 80 00 06  be  0xa014a498
a014a484:  82 10 20 01  mov  1, %g1
a014a488:  80 a0 00 0d  cmp  %g0, %o5
a014a48c:  92 60 3f ff  subx  %g0, -1, %o1
a014a490:  9a 02 40 09  add  %o1, %o1, %o5
a014a494:  82 10 00 0d  mov  %o5, %g1
a014a498:  80 a3 20 ff  cmp  %o4, 0xff
a014a49c:  02 80 00 0d  be  0xa014a4d0
a014a4a0:  92 08 60 03  and  %g1, 3, %o1
a014a4a4:  7f ff 82 4d  call  0xa012add8
a014a4a8:  31 2a 00 b8  sethi  %hi(0xa802e000), %i0
a014a4ac:  40 00 25 31  call  0xa0153970
a014a4b0:  91 ee 21 a0  restore  %i0, 0x1a0, %o0
a014a4b4:  b0 10 20 01  mov  1, %i0
a014a4b8:  90 10 20 20  mov  0x20, %o0
a014a4bc:  92 10 20 01  mov  1, %o1
a014a4c0:  40 00 1d 79  call  0xa0151aa4
a014a4c4:  01 00 00 00  nop
a014a4c8:  10 bf ff e9  b  0xa014a46c
a014a4cc:  82 0e 60 ff  and  %i1, 0xff, %g1
a014a4d0:  81 c7 e0 08  ret
a014a4d4:  81 e8 00 00  restore
