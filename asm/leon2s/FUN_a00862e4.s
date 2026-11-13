# leon2s FUN_a00862e4 0xa00862e4-0xa0086360 (124 bytes)
a00862e4:  9d e3 bf 98  save  %sp, -104, %sp
a00862e8:  a6 10 20 00  clr  %l3
a00862ec:  a1 2e e0 18  sll  %i3, 0x18, %l0
a00862f0:  a1 3c 20 18  sra  %l0, 0x18, %l0
a00862f4:  a2 0e 20 ff  and  %i0, 0xff, %l1
a00862f8:  a4 0e 60 ff  and  %i1, 0xff, %l2
a00862fc:  90 10 00 11  mov  %l1, %o0
a0086300:  92 10 00 12  mov  %l2, %o1
a0086304:  94 10 00 1a  mov  %i2, %o2
a0086308:  96 10 00 10  mov  %l0, %o3
a008630c:  7f ff ff 49  call  0xa0086030
a0086310:  98 10 00 1c  mov  %i4, %o4
a0086314:  90 10 00 11  mov  %l1, %o0
a0086318:  92 10 00 12  mov  %l2, %o1
a008631c:  94 10 00 10  mov  %l0, %o2
a0086320:  7f ff ff 8d  call  0xa0086154
a0086324:  96 10 00 1c  mov  %i4, %o3
a0086328:  80 8a 20 ff  btst  0xff, %o0
a008632c:  02 80 00 08  be  0xa008634c
a0086330:  82 0c e0 ff  and  %l3, 0xff, %g1
a0086334:  a6 04 e0 01  inc  %l3
a0086338:  82 0c e0 ff  and  %l3, 0xff, %g1
a008633c:  80 a0 60 09  cmp  %g1, 9
a0086340:  08 bf ff ec  bleu  0xa00862f0
a0086344:  a1 2e e0 18  sll  %i3, 0x18, %l0
a0086348:  82 0c e0 ff  and  %l3, 0xff, %g1
a008634c:  82 18 60 0a  xor  %g1, 0xa, %g1
a0086350:  80 a0 00 01  cmp  %g0, %g1
a0086354:  b0 40 20 00  addx  %g0, 0, %i0
a0086358:  81 c7 e0 08  ret
a008635c:  81 e8 00 00  restore
