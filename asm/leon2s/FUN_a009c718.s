# leon2s FUN_a009c718 0xa009c718-0xa009c794 (124 bytes)
a009c718:  9d e3 bf 98  save  %sp, -104, %sp
a009c71c:  b0 0e 20 ff  and  %i0, 0xff, %i0
a009c720:  7f ff ff 34  call  0xa009c3f0
a009c724:  90 10 00 18  mov  %i0, %o0
a009c728:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c72c:  d0 26 40 00  st  %o0, [ %i1 ]
a009c730:  7f ff ff 5d  call  0xa009c4a4
a009c734:  90 10 00 18  mov  %i0, %o0
a009c738:  90 0a 20 ff  and  %o0, 0xff, %o0
a009c73c:  d0 26 60 04  st  %o0, [ %i1 + 4 ]
a009c740:  7f ff ff 86  call  0xa009c558
a009c744:  90 10 00 18  mov  %i0, %o0
a009c748:  d0 26 60 08  st  %o0, [ %i1 + 8 ]
a009c74c:  7f ff ff 90  call  0xa009c58c
a009c750:  90 10 00 18  mov  %i0, %o0
a009c754:  d0 26 60 0c  st  %o0, [ %i1 + 0xc ]
a009c758:  7f ff ed de  call  0xa0097ed0
a009c75c:  90 10 00 18  mov  %i0, %o0
a009c760:  d0 2e 60 10  stb  %o0, [ %i1 + 0x10 ]
a009c764:  7f ff ed db  call  0xa0097ed0
a009c768:  90 10 00 18  mov  %i0, %o0
a009c76c:  80 8a 20 ff  btst  0xff, %o0
a009c770:  02 80 00 06  be  0xa009c788
a009c774:  90 10 00 18  mov  %i0, %o0
a009c778:  7f ff ff db  call  0xa009c6e4
a009c77c:  01 00 00 00  nop
a009c780:  10 80 00 03  b  0xa009c78c
a009c784:  d0 2e 60 11  stb  %o0, [ %i1 + 0x11 ]
a009c788:  c0 2e 60 11  clrb  [ %i1 + 0x11 ]
a009c78c:  81 c7 e0 08  ret
a009c790:  81 e8 00 00  restore
