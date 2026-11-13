# leon2m FUN_a00290e4 0xa00290e4-0xa0029128 (68 bytes)
a00290e4:  81 c5 40 00  jmp  %l5
a00290e8:  81 cd 80 00  rett  %l6
a00290ec:  aa 10 00 11  mov  %l1, %l5
a00290f0:  ac 10 00 12  mov  %l2, %l6
a00290f4:  a1 48 00 00  rd  %psr, %l0
a00290f8:  a0 14 2f 00  or  %l0, 0xf00, %l0
a00290fc:  81 8c 00 00  mov  %l0, %psr
a0029100:  81 8c 20 20  wr  %l0, 0x20, %psr
a0029104:  01 00 00 00  nop
a0029108:  01 00 00 00  nop
a002910c:  01 00 00 00  nop
a0029110:  29 2a 00 ff  sethi  %hi(0xa803fc00), %l4
a0029114:  a8 15 23 60  or  %l4, 0x360, %l4	! 0xa803ff60
a0029118:  e6 25 20 00  st  %l3, [ %l4 ]
a002911c:  ea 25 20 04  st  %l5, [ %l4 + 4 ]
a0029120:  ec 25 20 08  st  %l6, [ %l4 + 8 ]
a0029124:  81 e8 00 00  restore
