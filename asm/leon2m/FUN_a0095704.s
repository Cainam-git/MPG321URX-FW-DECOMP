# leon2m FUN_a0095704 0xa0095704-0xa0095778 (116 bytes)
a0095704:  9d e3 bf 98  save  %sp, -104, %sp
a0095708:  40 00 4d 60  call  0xa00a8c88
a009570c:  01 00 00 00  nop
a0095710:  40 00 4a ed  call  0xa00a82c4
a0095714:  01 00 00 00  nop
a0095718:  1f 2a 00 97  sethi  %hi(0xa8025c00), %o7
a009571c:  d8 0b e0 55  ldub  [ %o7 + 0x55 ], %o4	! 0xa8025c55
a0095720:  17 2a 00 b5  sethi  %hi(0xa802d400), %o3
a0095724:  d8 2a e0 0b  stb  %o4, [ %o3 + 0xb ]	! 0xa802d40b
a0095728:  40 00 92 97  call  0xa00ba184
a009572c:  90 10 20 01  mov  1, %o0
a0095730:  94 10 20 40  mov  0x40, %o2
a0095734:  13 2a 00 ab  sethi  %hi(0xa802ac00), %o1
a0095738:  d4 22 63 ec  st  %o2, [ %o1 + 0x3ec ]	! 0xa802afec
a009573c:  90 10 20 01  mov  1, %o0
a0095740:  40 00 4f c4  call  0xa00a9650
a0095744:  92 10 20 01  mov  1, %o1
a0095748:  90 10 20 01  mov  1, %o0
a009574c:  40 00 4f 47  call  0xa00a9468
a0095750:  92 10 20 02  mov  2, %o1
a0095754:  90 10 20 00  clr  %o0
a0095758:  40 00 77 5f  call  0xa00b34d4
a009575c:  92 10 20 01  mov  1, %o1
a0095760:  1b 2a 00 ac  sethi  %hi(0xa802b000), %o5
a0095764:  d0 0b 60 8e  ldub  [ %o5 + 0x8e ], %o0	! 0xa802b08e
a0095768:  82 12 20 02  or  %o0, 2, %g1
a009576c:  c2 2b 60 8e  stb  %g1, [ %o5 + 0x8e ]
a0095770:  81 c7 e0 08  ret
a0095774:  81 e8 00 00  restore
