# leon2s FUN_a0089058 0xa0089058-0xa0089090 (56 bytes)
a0089058:  92 0a 60 ff  and  %o1, 0xff, %o1
a008905c:  9a 0a 20 ff  and  %o0, 0xff, %o5
a0089060:  80 a3 40 09  cmp  %o5, %o1
a0089064:  18 80 00 09  bgu  0xa0089088
a0089068:  98 10 20 00  clr  %o4
a008906c:  96 10 20 01  mov  1, %o3
a0089070:  83 2a c0 0d  sll  %o3, %o5, %g1
a0089074:  90 02 20 01  inc  %o0
a0089078:  9a 0a 20 ff  and  %o0, 0xff, %o5
a008907c:  80 a3 40 09  cmp  %o5, %o1
a0089080:  08 bf ff fc  bleu  0xa0089070
a0089084:  98 10 40 0c  or  %g1, %o4, %o4
a0089088:  81 c3 e0 08  retl
a008908c:  90 0b 20 ff  and  %o4, 0xff, %o0
