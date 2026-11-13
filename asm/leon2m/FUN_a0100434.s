# leon2m FUN_a0100434 0xa0100434-0xa0100468 (52 bytes)
a0100434:  9d e3 bf 98  save  %sp, -104, %sp
a0100438:  90 0e 20 ff  and  %i0, 0xff, %o0
a010043c:  7f ff c5 95  call  0xa00f1a90
a0100440:  92 10 20 04  mov  4, %o1
a0100444:  92 0a 20 ff  and  %o0, 0xff, %o1
a0100448:  83 32 60 02  srl  %o1, 2, %g1
a010044c:  90 0a 60 03  and  %o1, 3, %o0
a0100450:  80 a2 20 03  cmp  %o0, 3
a0100454:  02 80 00 03  be  0xa0100460
a0100458:  b0 08 60 03  and  %g1, 3, %i0
a010045c:  b0 10 20 ff  mov  0xff, %i0
a0100460:  81 c7 e0 08  ret
a0100464:  81 e8 00 00  restore
