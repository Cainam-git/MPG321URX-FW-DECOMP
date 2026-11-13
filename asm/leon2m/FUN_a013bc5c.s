# leon2m FUN_a013bc5c 0xa013bc5c-0xa013bd00 (164 bytes)
a013bc5c:  9d e3 bf 98  save  %sp, -104, %sp
a013bc60:  40 00 04 3b  call  0xa013cd4c
a013bc64:  90 0e 20 ff  and  %i0, 0xff, %o0
a013bc68:  d6 12 20 16  lduh  [ %o0 + 0x16 ], %o3
a013bc6c:  83 2a e0 10  sll  %o3, 0x10, %g1
a013bc70:  99 30 60 11  srl  %g1, 0x11, %o4
a013bc74:  95 30 60 10  srl  %g1, 0x10, %o2
a013bc78:  9f 2a e0 11  sll  %o3, 0x11, %o7
a013bc7c:  9b 33 e0 10  srl  %o7, 0x10, %o5
a013bc80:  c2 12 20 0e  lduh  [ %o0 + 0xe ], %g1
a013bc84:  80 a0 40 0d  cmp  %g1, %o5
a013bc88:  08 80 00 04  bleu  0xa013bc98
a013bc8c:  98 03 00 0b  add  %o4, %o3, %o4
a013bc90:  d8 32 20 0e  sth  %o4, [ %o0 + 0xe ]
a013bc94:  82 10 00 0c  mov  %o4, %g1
a013bc98:  93 28 60 10  sll  %g1, 0x10, %o1
a013bc9c:  97 32 60 10  srl  %o1, 0x10, %o3
a013bca0:  b0 22 c0 0a  sub  %o3, %o2, %i0
a013bca4:  99 36 20 1f  srl  %i0, 0x1f, %o4
a013bca8:  9f 32 60 11  srl  %o1, 0x11, %o7
a013bcac:  da 12 20 1e  lduh  [ %o0 + 0x1e ], %o5
a013bcb0:  94 06 00 0c  add  %i0, %o4, %o2
a013bcb4:  80 a3 40 0f  cmp  %o5, %o7
a013bcb8:  08 80 00 03  bleu  0xa013bcc4
a013bcbc:  83 3a a0 01  sra  %o2, 1, %g1
a013bcc0:  c2 32 20 1e  sth  %g1, [ %o0 + 0x1e ]
a013bcc4:  d8 12 20 10  lduh  [ %o0 + 0x10 ], %o4
a013bcc8:  83 2b 20 10  sll  %o4, 0x10, %g1
a013bccc:  95 30 60 11  srl  %g1, 0x11, %o2
a013bcd0:  f0 12 20 20  lduh  [ %o0 + 0x20 ], %i0
a013bcd4:  80 a6 00 0a  cmp  %i0, %o2
a013bcd8:  08 80 00 08  bleu  0xa013bcf8
a013bcdc:  9b 30 60 10  srl  %g1, 0x10, %o5
a013bce0:  c2 12 20 18  lduh  [ %o0 + 0x18 ], %g1
a013bce4:  9e 23 40 01  sub  %o5, %g1, %o7
a013bce8:  9b 33 e0 1f  srl  %o7, 0x1f, %o5
a013bcec:  92 03 c0 0d  add  %o7, %o5, %o1
a013bcf0:  97 3a 60 01  sra  %o1, 1, %o3
a013bcf4:  d6 32 20 20  sth  %o3, [ %o0 + 0x20 ]
a013bcf8:  81 c7 e0 08  ret
a013bcfc:  81 e8 00 00  restore
