# leon2m FUN_a00dd83c 0xa00dd83c-0xa00dd868 (44 bytes)
a00dd83c:  c2 4a 00 00  ldsb  [ %o0 ], %g1
a00dd840:  80 a0 60 00  cmp  %g1, 0
a00dd844:  02 80 00 07  be  0xa00dd860
a00dd848:  9a 10 20 00  clr  %o5
a00dd84c:  90 02 20 01  inc  %o0
a00dd850:  c2 4a 00 00  ldsb  [ %o0 ], %g1
a00dd854:  80 a0 60 00  cmp  %g1, 0
a00dd858:  12 bf ff fd  bne  0xa00dd84c
a00dd85c:  9a 03 60 01  inc  %o5
a00dd860:  81 c3 e0 08  retl
a00dd864:  90 10 00 0d  mov  %o5, %o0
