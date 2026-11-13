# leon2m FUN_a015e818 0xa015e818-0xa015e880 (104 bytes)
a015e818:  9d e3 bf 98  save  %sp, -104, %sp
a015e81c:  b0 10 20 00  clr  %i0
a015e820:  80 a6 00 1a  cmp  %i0, %i2
a015e824:  16 80 00 15  bge  0xa015e878
a015e828:  01 00 00 00  nop
a015e82c:  30 80 00 05  b,a   0xa015e840
a015e830:  b0 06 20 01  inc  %i0
a015e834:  80 a6 00 1a  cmp  %i0, %i2
a015e838:  16 80 00 10  bge  0xa015e878
a015e83c:  01 00 00 00  nop
a015e840:  40 00 00 4c  call  0xa015e970
a015e844:  01 00 00 00  nop
a015e848:  83 2a 20 18  sll  %o0, 0x18, %g1
a015e84c:  83 38 60 18  sra  %g1, 0x18, %g1
a015e850:  9a 18 60 0a  xor  %g1, 0xa, %o5
a015e854:  80 a0 00 0d  cmp  %g0, %o5
a015e858:  98 60 3f ff  subx  %g0, -1, %o4
a015e85c:  82 18 60 0d  xor  %g1, 0xd, %g1
a015e860:  80 a0 00 01  cmp  %g0, %g1
a015e864:  9a 60 3f ff  subx  %g0, -1, %o5
a015e868:  80 93 00 0d  orcc  %o4, %o5, %g0
a015e86c:  02 bf ff f1  be  0xa015e830
a015e870:  d0 2e 40 18  stb  %o0, [ %i1 + %i0 ]
a015e874:  b0 06 20 01  inc  %i0
a015e878:  81 c7 e0 08  ret
a015e87c:  81 e8 00 00  restore
