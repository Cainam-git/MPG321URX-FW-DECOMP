# leon2m FUN_a00dd6c8 0xa00dd6c8-0xa00dd7f0 (296 bytes)
a00dd6c8:  9d e3 bf 98  save  %sp, -104, %sp
a00dd6cc:  90 10 20 00  clr  %o0
a00dd6d0:  80 a6 20 02  cmp  %i0, 2
a00dd6d4:  02 80 00 43  be  0xa00dd7e0
a00dd6d8:  98 06 3f ff  add  %i0, -1, %o4
a00dd6dc:  80 a3 20 01  cmp  %o4, 1
a00dd6e0:  18 80 00 1e  bgu  0xa00dd758
a00dd6e4:  94 10 20 01  mov  1, %o2
a00dd6e8:  13 2a 00 ac  sethi  %hi(0xa802b000), %o1
a00dd6ec:  40 00 a8 54  call  0xa010783c
a00dd6f0:  d4 2a 60 ad  stb  %o2, [ %o1 + 0xad ]	! 0xa802b0ad
a00dd6f4:  40 00 a8 64  call  0xa0107884
a00dd6f8:  90 10 20 00  clr  %o0
a00dd6fc:  40 00 a8 74  call  0xa01078cc
a00dd700:  90 10 20 00  clr  %o0
a00dd704:  40 00 a8 84  call  0xa0107914
a00dd708:  90 10 20 00  clr  %o0
a00dd70c:  40 00 a7 d4  call  0xa010765c
a00dd710:  90 10 20 00  clr  %o0
a00dd714:  40 00 a7 ea  call  0xa01076bc
a00dd718:  90 10 20 00  clr  %o0
a00dd71c:  40 00 a8 00  call  0xa010771c
a00dd720:  90 10 20 00  clr  %o0
a00dd724:  40 00 a8 16  call  0xa010777c
a00dd728:  90 10 20 00  clr  %o0
a00dd72c:  40 00 a8 2c  call  0xa01077dc
a00dd730:  90 10 20 00  clr  %o0
a00dd734:  40 00 a7 88  call  0xa0107554
a00dd738:  90 10 20 00  clr  %o0
a00dd73c:  40 00 a7 af  call  0xa01075f8
a00dd740:  90 10 20 00  clr  %o0
a00dd744:  90 10 20 00  clr  %o0
a00dd748:  40 00 a8 85  call  0xa010795c
a00dd74c:  31 00 06 63  sethi  %hi(0x198c00), %i0
a00dd750:  40 00 05 fc  call  0xa00def40
a00dd754:  91 ee 20 60  restore  %i0, 0x60, %o0
a00dd758:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00dd75c:  1f 2a 00 ac  sethi  %hi(0xa802b000), %o7
a00dd760:  19 33 c0 26  sethi  %hi(0xcf009800), %o4
a00dd764:  c0 28 60 ae  clrb  [ %g1 + 0xae ]
a00dd768:  c0 2b e0 ad  clrb  [ %o7 + 0xad ]
a00dd76c:  96 13 23 b8  or  %o4, 0x3b8, %o3
a00dd770:  c0 22 c0 00  clr  [ %o3 ]
a00dd774:  40 00 a8 32  call  0xa010783c
a00dd778:  90 10 20 01  mov  1, %o0
a00dd77c:  40 00 a8 42  call  0xa0107884
a00dd780:  90 10 20 01  mov  1, %o0
a00dd784:  40 00 a8 52  call  0xa01078cc
a00dd788:  90 10 20 01  mov  1, %o0
a00dd78c:  40 00 a8 62  call  0xa0107914
a00dd790:  90 10 20 01  mov  1, %o0
a00dd794:  40 00 a7 b2  call  0xa010765c
a00dd798:  90 10 20 01  mov  1, %o0
a00dd79c:  40 00 a7 c8  call  0xa01076bc
a00dd7a0:  90 10 20 01  mov  1, %o0
a00dd7a4:  40 00 a7 de  call  0xa010771c
a00dd7a8:  90 10 20 01  mov  1, %o0
a00dd7ac:  40 00 a7 f4  call  0xa010777c
a00dd7b0:  90 10 20 01  mov  1, %o0
a00dd7b4:  40 00 a8 0a  call  0xa01077dc
a00dd7b8:  90 10 20 01  mov  1, %o0
a00dd7bc:  40 00 a7 66  call  0xa0107554
a00dd7c0:  90 10 20 01  mov  1, %o0
a00dd7c4:  40 00 a7 8d  call  0xa01075f8
a00dd7c8:  90 10 20 01  mov  1, %o0
a00dd7cc:  40 00 a8 64  call  0xa010795c
a00dd7d0:  90 10 20 01  mov  1, %o0
a00dd7d4:  11 00 06 63  sethi  %hi(0x198c00), %o0
a00dd7d8:  40 00 05 da  call  0xa00def40
a00dd7dc:  91 ea 20 78  restore  %o0, 0x78, %o0
a00dd7e0:  9a 10 20 01  mov  1, %o5
a00dd7e4:  03 2a 00 ac  sethi  %hi(0xa802b000), %g1
a00dd7e8:  10 bf ff bd  b  0xa00dd6dc
a00dd7ec:  da 28 60 ae  stb  %o5, [ %g1 + 0xae ]	! 0xa802b0ae
