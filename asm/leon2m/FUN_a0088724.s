# leon2m FUN_a0088724 0xa0088724-0xa0089f10 (1608 bytes)
a0088724:  9d e3 bb e8  save  %sp, -1048, %sp
a0088728:  98 10 20 00  clr  %o4
a008872c:  9a 10 20 00  clr  %o5
a0088730:  d8 3f bf f0  std  %o4, [ %fp + -16 ]
a0088734:  d8 3f bf d0  std  %o4, [ %fp + -48 ]
a0088738:  d8 3f bf d8  std  %o4, [ %fp + -40 ]
a008873c:  d8 3f bf e0  std  %o4, [ %fp + -32 ]
a0088740:  40 02 ff d0  call  0xa0148680
a0088744:  d8 3f bf e8  std  %o4, [ %fp + -24 ]
a0088748:  80 8a 20 ff  btst  0xff, %o0
a008874c:  a0 10 20 00  clr  %l0
a0088750:  02 80 05 ee  be  0xa0089f08
a0088754:  a2 10 20 01  mov  1, %l1
a0088758:  a4 07 bf d0  add  %fp, -48, %l2
a008875c:  90 07 bc 4f  add  %fp, -945, %o0
a0088760:  92 07 bc 4c  add  %fp, -948, %o1
a0088764:  40 02 ff cd  call  0xa0148698
a0088768:  94 10 00 12  mov  %l2, %o2
a008876c:  d0 0f bf d1  ldub  [ %fp + -47 ], %o0
a0088770:  82 0a 20 7f  and  %o0, 0x7f, %g1
a0088774:  82 00 60 03  add  %g1, 3, %g1
a0088778:  80 a0 60 00  cmp  %g1, 0
a008877c:  02 80 00 0d  be  0xa00887b0
a0088780:  c2 37 bc 4c  sth  %g1, [ %fp + -948 ]
a0088784:  94 07 bf f8  add  %fp, -8, %o2
a0088788:  96 00 7f ff  add  %g1, -1, %o3
a008878c:  9f 2a e0 10  sll  %o3, 0x10, %o7
a0088790:  93 33 e0 10  srl  %o7, 0x10, %o1
a0088794:  9a 02 80 09  add  %o2, %o1, %o5
a0088798:  d8 0b 7f d8  ldub  [ %o5 + -40 ], %o4
a008879c:  80 a2 60 00  cmp  %o1, 0
a00887a0:  a0 1c 00 0c  xor  %l0, %o4, %l0
a00887a4:  12 bf ff f9  bne  0xa0088788
a00887a8:  82 10 00 0b  mov  %o3, %g1
a00887ac:  d6 37 bc 4c  sth  %o3, [ %fp + -948 ]
a00887b0:  a0 0c 20 ff  and  %l0, 0xff, %l0
a00887b4:  80 a4 20 6e  cmp  %l0, 0x6e
a00887b8:  12 80 05 d4  bne  0xa0089f08
a00887bc:  c2 0f bf d2  ldub  [ %fp + -46 ], %g1
a00887c0:  80 a0 60 0c  cmp  %g1, 0xc
a00887c4:  02 80 00 3f  be  0xa00888c0
a00887c8:  37 2a 00 ab  sethi  %hi(0xa802ac00), %i3
a00887cc:  14 80 00 30  bg  0xa008888c
a00887d0:  80 a0 60 d0  cmp  %g1, 0xd0
a00887d4:  80 a0 60 03  cmp  %g1, 3
a00887d8:  22 80 00 d2  be,a   0xa0088b20
a00887dc:  23 00 03 ff  sethi  %hi(0xffc00), %l1
a00887e0:  14 80 00 3c  bg  0xa00888d0
a00887e4:  80 a0 60 07  cmp  %g1, 7
a00887e8:  80 a0 60 01  cmp  %g1, 1
a00887ec:  12 80 00 30  bne  0xa00888ac
a00887f0:  80 8c 60 ff  btst  0xff, %l1
a00887f4:  e2 0f bc 4f  ldub  [ %fp + -945 ], %l1
a00887f8:  a6 10 20 0a  mov  0xa, %l3
a00887fc:  9a 10 20 00  clr  %o5
a0088800:  96 07 bf f8  add  %fp, -8, %o3
a0088804:  94 03 60 01  add  %o5, 1, %o2
a0088808:  af 2b 60 10  sll  %o5, 0x10, %l7
a008880c:  ad 35 e0 10  srl  %l7, 0x10, %l6
a0088810:  ab 2a a0 10  sll  %o2, 0x10, %l5
a0088814:  a8 02 c0 16  add  %o3, %l6, %l4
a0088818:  a1 35 60 10  srl  %l5, 0x10, %l0
a008881c:  c0 2d 3f b0  clrb  [ %l4 + -80 ]
a0088820:  80 a4 20 27  cmp  %l0, 0x27
a0088824:  08 bf ff f8  bleu  0xa0088804
a0088828:  9a 10 00 0a  mov  %o2, %o5
a008882c:  d6 0c a0 03  ldub  [ %l2 + 3 ], %o3
a0088830:  82 10 20 6e  mov  0x6e, %g1
a0088834:  ba 10 3f 88  mov  -120, %i5
a0088838:  b8 10 20 02  mov  2, %i4
a008883c:  37 00 03 ff  sethi  %hi(0xffc00), %i3
a0088840:  c2 2f bf a8  stb  %g1, [ %fp + -88 ]
a0088844:  fa 2f bf a9  stb  %i5, [ %fp + -87 ]
a0088848:  f8 2f bf aa  stb  %i4, [ %fp + -86 ]
a008884c:  c0 2f bf ab  clrb  [ %fp + -85 ]
a0088850:  d6 2f bf ac  stb  %o3, [ %fp + -84 ]
a0088854:  c0 2f bf ad  clrb  [ %fp + -83 ]
a0088858:  90 16 e1 a8  or  %i3, 0x1a8, %o0
a008885c:  40 01 5a 45  call  0xa00df170
a0088860:  92 0a e0 ff  and  %o3, 0xff, %o1
a0088864:  c2 0c a0 03  ldub  [ %l2 + 3 ], %g1
a0088868:  80 a0 60 ff  cmp  %g1, 0xff
a008886c:  38 80 00 fb  bgu,a   0xa0088c58
a0088870:  a0 10 20 01  mov  1, %l0
a0088874:  1b 00 00 a0  sethi  %hi(0x28000), %o5
a0088878:  99 28 60 02  sll  %g1, 2, %o4
a008887c:  92 13 62 54  or  %o5, 0x254, %o1
a0088880:  d0 02 40 0c  ld  [ %o1 + %o4 ], %o0
a0088884:  81 c2 00 00  jmp  %o0
a0088888:  01 00 00 00  nop
a008888c:  02 80 00 b3  be  0xa0088b58
a0088890:  80 a0 60 d0  cmp  %g1, 0xd0
a0088894:  14 80 00 52  bg  0xa00889dc
a0088898:  80 a0 60 f3  cmp  %g1, 0xf3
a008889c:  80 a0 60 c0  cmp  %g1, 0xc0
a00888a0:  02 80 00 e4  be  0xa0088c30
a00888a4:  92 10 00 12  mov  %l2, %o1
a00888a8:  80 8c 60 ff  btst  0xff, %l1
a00888ac:  02 80 05 97  be  0xa0089f08
a00888b0:  01 00 00 00  nop
a00888b4:  40 00 21 c9  call  0xa0090fd8
a00888b8:  01 00 00 00  nop
a00888bc:  30 80 05 93  b,a   0xa0089f08
a00888c0:  d6 0e e3 99  ldub  [ %i3 + 0x399 ], %o3
a00888c4:  aa 12 e0 03  or  %o3, 3, %l5
a00888c8:  10 bf ff f8  b  0xa00888a8
a00888cc:  ea 2e e3 99  stb  %l5, [ %i3 + 0x399 ]
a00888d0:  12 bf ff f7  bne  0xa00888ac
a00888d4:  80 8c 60 ff  btst  0xff, %l1
a00888d8:  1f 00 03 ff  sethi  %hi(0xffc00), %o7
a00888dc:  90 13 e1 b8  or  %o7, 0x1b8, %o0	! 0xffdb8
a00888e0:  40 01 5a 24  call  0xa00df170
a00888e4:  b8 10 20 4e  mov  0x4e, %i4
a00888e8:  e0 2f be d8  stb  %l0, [ %fp + -296 ]
a00888ec:  a0 10 20 06  mov  6, %l0
a00888f0:  e0 2f be d9  stb  %l0, [ %fp + -295 ]
a00888f4:  f8 2f be da  stb  %i4, [ %fp + -294 ]
a00888f8:  e2 0f bc 4f  ldub  [ %fp + -945 ], %l1
a00888fc:  90 10 20 00  clr  %o0
a0088900:  40 02 f3 58  call  0xa0145660
a0088904:  92 10 20 03  mov  3, %o1
a0088908:  a9 2a 20 10  sll  %o0, 0x10, %l4
a008890c:  ad 35 20 10  srl  %l4, 0x10, %l6
a0088910:  80 a5 a0 03  cmp  %l6, 3
a0088914:  12 80 01 1c  bne  0xa0088d84
a0088918:  a0 10 20 03  mov  3, %l0
a008891c:  40 02 ed 55  call  0xa0143e70
a0088920:  90 10 20 00  clr  %o0
a0088924:  80 8a 20 ff  btst  0xff, %o0
a0088928:  12 80 00 ef  bne  0xa0088ce4
a008892c:  96 14 3f 80  or  %l0, -128, %o3
a0088930:  e0 2f be db  stb  %l0, [ %fp + -293 ]
a0088934:  92 10 20 00  clr  %o1
a0088938:  40 02 f3 4a  call  0xa0145660
a008893c:  90 10 20 00  clr  %o0
a0088940:  95 2a 20 10  sll  %o0, 0x10, %o2
a0088944:  83 32 a0 10  srl  %o2, 0x10, %g1
a0088948:  9f 28 60 02  sll  %g1, 2, %o7
a008894c:  a0 03 c0 01  add  %o7, %g1, %l0
a0088950:  b9 34 20 07  srl  %l0, 7, %i4
a0088954:  a8 04 00 10  add  %l0, %l0, %l4
a0088958:  92 10 20 01  mov  1, %o1
a008895c:  f8 2f be dc  stb  %i4, [ %fp + -292 ]
a0088960:  e8 2f be dd  stb  %l4, [ %fp + -291 ]
a0088964:  40 02 f3 3f  call  0xa0145660
a0088968:  90 10 20 00  clr  %o0
a008896c:  ad 2a 20 10  sll  %o0, 0x10, %l6
a0088970:  91 35 a0 10  srl  %l6, 0x10, %o0
a0088974:  bb 2a 20 02  sll  %o0, 2, %i5
a0088978:  98 07 40 08  add  %i5, %o0, %o4
a008897c:  9b 33 20 07  srl  %o4, 7, %o5
a0088980:  92 03 00 0c  add  %o4, %o4, %o1
a0088984:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0088988:  a6 10 20 50  mov  0x50, %l3
a008898c:  da 2f be de  stb  %o5, [ %fp + -290 ]
a0088990:  d2 2f be df  stb  %o1, [ %fp + -289 ]
a0088994:  e6 2a e3 9e  stb  %l3, [ %o3 + 0x39e ]
a0088998:  94 07 be d8  add  %fp, -296, %o2
a008899c:  98 10 20 00  clr  %o4
a00889a0:  82 10 20 00  clr  %g1
a00889a4:  e4 08 40 0a  ldub  [ %g1 + %o2 ], %l2
a00889a8:  ee 0a e3 9e  ldub  [ %o3 + 0x39e ], %l7
a00889ac:  98 03 20 01  inc  %o4
a00889b0:  9a 1c 80 17  xor  %l2, %l7, %o5
a00889b4:  82 0b 20 ff  and  %o4, 0xff, %g1
a00889b8:  80 a0 60 08  cmp  %g1, 8
a00889bc:  0a bf ff fa  bcs  0xa00889a4
a00889c0:  da 2a e3 9e  stb  %o5, [ %o3 + 0x39e ]
a00889c4:  da 28 40 0a  stb  %o5, [ %g1 + %o2 ]
a00889c8:  90 0c 60 ff  and  %l1, 0xff, %o0
a00889cc:  40 02 ff 37  call  0xa01486a8
a00889d0:  92 10 20 09  mov  9, %o1
a00889d4:  10 bf ff b5  b  0xa00888a8
a00889d8:  a2 10 20 00  clr  %l1
a00889dc:  12 bf ff b4  bne  0xa00888ac
a00889e0:  80 8c 60 ff  btst  0xff, %l1
a00889e4:  37 00 03 ff  sethi  %hi(0xffc00), %i3
a00889e8:  40 01 59 e2  call  0xa00df170
a00889ec:  90 16 e1 d0  or  %i3, 0x1d0, %o0	! 0xffdd0
a00889f0:  23 00 03 ff  sethi  %hi(0xffc00), %l1
a00889f4:  92 14 61 e0  or  %l1, 0x1e0, %o1	! 0xffde0
a00889f8:  94 10 21 37  mov  0x137, %o2
a00889fc:  e2 0f bc 4f  ldub  [ %fp + -945 ], %l1
a0088a00:  40 02 cf c4  call  0xa013c910
a0088a04:  90 07 bd 78  add  %fp, -648, %o0
a0088a08:  2f 00 03 ff  sethi  %hi(0xffc00), %l7
a0088a0c:  92 15 e3 18  or  %l7, 0x318, %o1	! 0xfff18
a0088a10:  94 10 21 28  mov  0x128, %o2
a0088a14:  40 02 cf bf  call  0xa013c910
a0088a18:  90 07 bc 50  add  %fp, -944, %o0
a0088a1c:  40 02 ee 1f  call  0xa0144298
a0088a20:  90 10 20 00  clr  %o0
a0088a24:  fa 0c a0 03  ldub  [ %l2 + 3 ], %i5
a0088a28:  94 0a 20 ff  and  %o0, 0xff, %o2
a0088a2c:  d2 0c a0 04  ldub  [ %l2 + 4 ], %o1
a0088a30:  90 1a a0 01  xor  %o2, 1, %o0
a0088a34:  82 0f 60 ff  and  %i5, 0xff, %g1
a0088a38:  80 a0 00 08  cmp  %g0, %o0
a0088a3c:  9f 28 60 08  sll  %g1, 8, %o7
a0088a40:  a0 0a 60 ff  and  %o1, 0xff, %l0
a0088a44:  90 13 c0 10  or  %o7, %l0, %o0
a0088a48:  b8 60 20 00  subx  %g0, 0, %i4
a0088a4c:  a8 0f 20 0f  and  %i4, 0xf, %l4
a0088a50:  99 2a 20 10  sll  %o0, 0x10, %o4
a0088a54:  a7 33 20 10  srl  %o4, 0x10, %l3
a0088a58:  9e 05 21 27  add  %l4, 0x127, %o7
a0088a5c:  ac 10 20 6e  mov  0x6e, %l6
a0088a60:  9a 10 3f e3  mov  -29, %o5
a0088a64:  80 a4 c0 0f  cmp  %l3, %o7
a0088a68:  ec 2f be b0  stb  %l6, [ %fp + -336 ]
a0088a6c:  da 2f be b2  stb  %o5, [ %fp + -334 ]
a0088a70:  fa 2f be b3  stb  %i5, [ %fp + -333 ]
a0088a74:  d2 2f be b4  stb  %o1, [ %fp + -332 ]
a0088a78:  08 80 00 9d  bleu  0xa0088cec
a0088a7c:  a6 10 00 08  mov  %o0, %l3
a0088a80:  a4 10 3f a3  mov  -93, %l2
a0088a84:  e4 2f be b1  stb  %l2, [ %fp + -335 ]
a0088a88:  98 10 20 00  clr  %o4
a0088a8c:  94 07 bf f8  add  %fp, -8, %o2
a0088a90:  96 10 20 20  mov  0x20, %o3
a0088a94:  92 0b 20 ff  and  %o4, 0xff, %o1
a0088a98:  98 03 20 01  inc  %o4
a0088a9c:  a6 02 80 09  add  %o2, %o1, %l3
a0088aa0:  aa 0b 20 ff  and  %o4, 0xff, %l5
a0088aa4:  80 a5 60 20  cmp  %l5, 0x20
a0088aa8:  0a bf ff fb  bcs  0xa0088a94
a0088aac:  d6 2c fe bd  stb  %o3, [ %l3 + -323 ]
a0088ab0:  a4 10 20 25  mov  0x25, %l2
a0088ab4:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a0088ab8:  92 0c a0 ff  and  %l2, 0xff, %o1
a0088abc:  9e 10 20 50  mov  0x50, %o7
a0088ac0:  de 2a 23 9e  stb  %o7, [ %o0 + 0x39e ]
a0088ac4:  80 a2 60 00  cmp  %o1, 0
a0088ac8:  94 07 be b0  add  %fp, -336, %o2
a0088acc:  98 10 20 00  clr  %o4
a0088ad0:  02 80 00 0a  be  0xa0088af8
a0088ad4:  96 10 20 00  clr  %o3
a0088ad8:  e0 0a c0 0a  ldub  [ %o3 + %o2 ], %l0
a0088adc:  d6 0a 23 9e  ldub  [ %o0 + 0x39e ], %o3
a0088ae0:  82 1c 00 0b  xor  %l0, %o3, %g1
a0088ae4:  98 03 20 01  inc  %o4
a0088ae8:  96 0b 20 ff  and  %o4, 0xff, %o3
a0088aec:  80 a2 c0 09  cmp  %o3, %o1
a0088af0:  0a bf ff fa  bcs  0xa0088ad8
a0088af4:  c2 2a 23 9e  stb  %g1, [ %o0 + 0x39e ]
a0088af8:  aa 0c a0 ff  and  %l2, 0xff, %l5
a0088afc:  b6 05 60 01  add  %l5, 1, %i3
a0088b00:  ee 0a 23 9e  ldub  [ %o0 + 0x39e ], %l7
a0088b04:  a5 2e e0 10  sll  %i3, 0x10, %l2
a0088b08:  ee 2a c0 0a  stb  %l7, [ %o3 + %o2 ]
a0088b0c:  90 0c 60 ff  and  %l1, 0xff, %o0
a0088b10:  40 02 fe e6  call  0xa01486a8
a0088b14:  93 34 a0 10  srl  %l2, 0x10, %o1
a0088b18:  10 bf ff 64  b  0xa00888a8
a0088b1c:  a2 10 20 00  clr  %l1
a0088b20:  90 14 61 88  or  %l1, 0x188, %o0
a0088b24:  e6 0f bc 4f  ldub  [ %fp + -945 ], %l3
a0088b28:  40 01 59 92  call  0xa00df170
a0088b2c:  d2 0f bf d3  ldub  [ %fp + -45 ], %o1
a0088b30:  c2 0f bf d3  ldub  [ %fp + -45 ], %g1
a0088b34:  80 a0 60 fe  cmp  %g1, 0xfe
a0088b38:  18 80 00 3c  bgu  0xa0088c28
a0088b3c:  ac 10 20 01  mov  1, %l6
a0088b40:  19 00 00 9f  sethi  %hi(0x27c00), %o4
a0088b44:  83 28 60 02  sll  %g1, 2, %g1
a0088b48:  9a 13 22 58  or  %o4, 0x258, %o5
a0088b4c:  d2 03 40 01  ld  [ %o5 + %g1 ], %o1
a0088b50:  81 c2 40 00  jmp  %o1
a0088b54:  01 00 00 00  nop
a0088b58:  92 10 00 12  mov  %l2, %o1
a0088b5c:  40 01 2a bd  call  0xa00d3650
a0088b60:  d0 0f bc 4f  ldub  [ %fp + -945 ], %o0
a0088b64:  10 bf ff 51  b  0xa00888a8
a0088b68:  a2 10 20 00  clr  %l1
a0088b6c:  c2 0c a0 03  ldub  [ %l2 + 3 ], %g1
a0088b70:  80 a0 60 f9  cmp  %g1, 0xf9
a0088b74:  02 80 00 18  be  0xa0088bd4
a0088b78:  a2 07 bf 80  add  %fp, -128, %l1
a0088b7c:  80 a0 60 f9  cmp  %g1, 0xf9
a0088b80:  14 80 01 61  bg  0xa0089104
a0088b84:  80 a0 60 fa  cmp  %g1, 0xfa
a0088b88:  80 a0 60 f8  cmp  %g1, 0xf8
a0088b8c:  32 bf ff 47  bne,a   0xa00888a8
a0088b90:  a2 10 00 16  mov  %l6, %l1
a0088b94:  d2 0c a0 04  ldub  [ %l2 + 4 ], %o1
a0088b98:  80 a2 60 66  cmp  %o1, 0x66
a0088b9c:  32 bf ff 43  bne,a   0xa00888a8
a0088ba0:  a2 10 00 16  mov  %l6, %l1
a0088ba4:  c2 0c a0 05  ldub  [ %l2 + 5 ], %g1
a0088ba8:  80 a0 60 99  cmp  %g1, 0x99
a0088bac:  32 bf ff 3f  bne,a   0xa00888a8
a0088bb0:  a2 10 00 16  mov  %l6, %l1
a0088bb4:  d0 0c a0 06  ldub  [ %l2 + 6 ], %o0
a0088bb8:  80 a2 20 55  cmp  %o0, 0x55
a0088bbc:  32 bf ff 3b  bne,a   0xa00888a8
a0088bc0:  a2 10 00 16  mov  %l6, %l1
a0088bc4:  de 0c a0 07  ldub  [ %l2 + 7 ], %o7
a0088bc8:  80 a3 e0 aa  cmp  %o7, 0xaa
a0088bcc:  32 bf ff 37  bne,a   0xa00888a8
a0088bd0:  a2 10 00 16  mov  %l6, %l1
a0088bd4:  92 10 20 01  mov  1, %o1
a0088bd8:  40 03 0a 37  call  0xa014b4b4
a0088bdc:  90 10 20 fe  mov  0xfe, %o0
a0088be0:  98 10 20 02  mov  2, %o4
a0088be4:  aa 10 20 6e  mov  0x6e, %l5
a0088be8:  a8 10 3f 83  mov  -125, %l4
a0088bec:  d8 2f bf 82  stb  %o4, [ %fp + -126 ]
a0088bf0:  ea 2f bf 80  stb  %l5, [ %fp + -128 ]
a0088bf4:  40 02 fb a3  call  0xa0147a80
a0088bf8:  e8 2f bf 81  stb  %l4, [ %fp + -127 ]
a0088bfc:  40 02 fb a3  call  0xa0147a88
a0088c00:  d0 2f bf 83  stb  %o0, [ %fp + -125 ]
a0088c04:  15 2a 00 ab  sethi  %hi(0xa802ac00), %o2
a0088c08:  9a 10 20 50  mov  0x50, %o5
a0088c0c:  d0 2f bf 84  stb  %o0, [ %fp + -124 ]
a0088c10:  da 2a a3 9e  stb  %o5, [ %o2 + 0x39e ]
a0088c14:  90 0c e0 ff  and  %l3, 0xff, %o0
a0088c18:  94 10 00 11  mov  %l1, %o2
a0088c1c:  92 10 20 05  mov  5, %o1
a0088c20:  40 02 fe a2  call  0xa01486a8
a0088c24:  01 00 00 00  nop
a0088c28:  10 bf ff 20  b  0xa00888a8
a0088c2c:  a2 10 00 16  mov  %l6, %l1
a0088c30:  40 01 27 9a  call  0xa00d2a98
a0088c34:  d0 0f bc 4f  ldub  [ %fp + -945 ], %o0
a0088c38:  10 bf ff 1c  b  0xa00888a8
a0088c3c:  a2 10 20 00  clr  %l1
a0088c40:  40 02 fb dc  call  0xa0147bb0
a0088c44:  90 10 20 00  clr  %o0
a0088c48:  80 a2 20 05  cmp  %o0, 5
a0088c4c:  12 80 01 dd  bne  0xa00893c0
a0088c50:  82 10 20 01  mov  1, %g1
a0088c54:  a0 10 20 01  mov  1, %l0
a0088c58:  a4 10 3f ff  mov  -1, %l2
a0088c5c:  e0 2f bf ab  stb  %l0, [ %fp + -85 ]
a0088c60:  e4 2f bf af  stb  %l2, [ %fp + -81 ]
a0088c64:  c0 2f bf ae  clrb  [ %fp + -82 ]
a0088c68:  c0 2f bf b0  clrb  [ %fp + -80 ]
a0088c6c:  c0 2f bf b1  clrb  [ %fp + -79 ]
a0088c70:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0088c74:  94 0c e0 ff  and  %l3, 0xff, %o2
a0088c78:  a8 10 20 50  mov  0x50, %l4
a0088c7c:  e8 2a e3 9e  stb  %l4, [ %o3 + 0x39e ]
a0088c80:  80 a2 a0 00  cmp  %o2, 0
a0088c84:  98 10 20 00  clr  %o4
a0088c88:  02 80 00 0b  be  0xa0088cb4
a0088c8c:  9a 10 20 00  clr  %o5
a0088c90:  b6 03 7f a8  add  %o5, -88, %i3
a0088c94:  ec 0e c0 1e  ldub  [ %i3 + %fp ], %l6
a0088c98:  ee 0a e3 9e  ldub  [ %o3 + 0x39e ], %l7
a0088c9c:  98 03 20 01  inc  %o4
a0088ca0:  aa 1d 80 17  xor  %l6, %l7, %l5
a0088ca4:  9a 0b 20 ff  and  %o4, 0xff, %o5
a0088ca8:  80 a3 40 0a  cmp  %o5, %o2
a0088cac:  0a bf ff f9  bcs  0xa0088c90
a0088cb0:  ea 2a e3 9e  stb  %l5, [ %o3 + 0x39e ]
a0088cb4:  90 0c e0 ff  and  %l3, 0xff, %o0
a0088cb8:  ba 02 20 01  add  %o0, 1, %i5
a0088cbc:  f8 0a e3 9e  ldub  [ %o3 + 0x39e ], %i4
a0088cc0:  a7 2f 60 10  sll  %i5, 0x10, %l3
a0088cc4:  96 03 7f a8  add  %o5, -88, %o3
a0088cc8:  f8 2a c0 1e  stb  %i4, [ %o3 + %fp ]
a0088ccc:  90 0c 60 ff  and  %l1, 0xff, %o0
a0088cd0:  93 34 e0 10  srl  %l3, 0x10, %o1
a0088cd4:  40 02 fe 75  call  0xa01486a8
a0088cd8:  94 07 bf a8  add  %fp, -88, %o2
a0088cdc:  10 bf fe f3  b  0xa00888a8
a0088ce0:  a2 10 20 00  clr  %l1
a0088ce4:  10 bf ff 14  b  0xa0088934
a0088ce8:  d6 2f be db  stb  %o3, [ %fp + -293 ]
a0088cec:  96 23 c0 08  sub  %o7, %o0, %o3
a0088cf0:  9b 2a e0 10  sll  %o3, 0x10, %o5
a0088cf4:  bb 33 60 10  srl  %o5, 0x10, %i5
a0088cf8:  80 a7 60 20  cmp  %i5, 0x20
a0088cfc:  08 80 00 34  bleu  0xa0088dcc
a0088d00:  a0 10 00 0b  mov  %o3, %l0
a0088d04:  ac 10 3f a3  mov  -93, %l6
a0088d08:  ec 2f be b1  stb  %l6, [ %fp + -335 ]
a0088d0c:  a0 10 20 20  mov  0x20, %l0
a0088d10:  a4 10 20 25  mov  0x25, %l2
a0088d14:  40 02 ed 61  call  0xa0144298
a0088d18:  90 10 20 00  clr  %o0
a0088d1c:  b8 0a 20 ff  and  %o0, 0xff, %i4
a0088d20:  80 a7 20 01  cmp  %i4, 1
a0088d24:  02 80 00 2e  be  0xa0088ddc
a0088d28:  91 2c 20 10  sll  %l0, 0x10, %o0
a0088d2c:  9f 32 20 10  srl  %o0, 0x10, %o7
a0088d30:  80 a3 e0 00  cmp  %o7, 0
a0088d34:  02 bf ff 60  be  0xa0088ab4
a0088d38:  94 10 20 00  clr  %o2
a0088d3c:  93 2c e0 10  sll  %l3, 0x10, %o1
a0088d40:  97 32 60 10  srl  %o1, 0x10, %o3
a0088d44:  90 07 bf f8  add  %fp, -8, %o0
a0088d48:  92 02 00 0b  add  %o0, %o3, %o1
a0088d4c:  9a 0a a0 ff  and  %o2, 0xff, %o5
a0088d50:  ac 02 c0 0d  add  %o3, %o5, %l6
a0088d54:  80 a5 a1 36  cmp  %l6, 0x136
a0088d58:  18 bf ff 57  bgu  0xa0088ab4
a0088d5c:  b8 02 40 0d  add  %o1, %o5, %i4
a0088d60:  94 02 a0 01  inc  %o2
a0088d64:  d8 0f 3d 80  ldub  [ %i4 + -640 ], %o4
a0088d68:  9a 02 00 0d  add  %o0, %o5, %o5
a0088d6c:  a8 0a a0 ff  and  %o2, 0xff, %l4
a0088d70:  80 a5 00 0f  cmp  %l4, %o7
a0088d74:  0a bf ff f6  bcs  0xa0088d4c
a0088d78:  d8 2b 7e bd  stb  %o4, [ %o5 + -323 ]
a0088d7c:  10 bf ff 4f  b  0xa0088ab8
a0088d80:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a0088d84:  90 10 20 00  clr  %o0
a0088d88:  40 02 f2 36  call  0xa0145660
a0088d8c:  92 10 20 03  mov  3, %o1
a0088d90:  95 2a 20 10  sll  %o0, 0x10, %o2
a0088d94:  83 32 a0 10  srl  %o2, 0x10, %g1
a0088d98:  80 a0 60 02  cmp  %g1, 2
a0088d9c:  02 bf fe e0  be  0xa008891c
a0088da0:  a0 10 20 01  mov  1, %l0
a0088da4:  90 10 20 00  clr  %o0
a0088da8:  40 02 f2 2e  call  0xa0145660
a0088dac:  92 10 20 03  mov  3, %o1
a0088db0:  ab 2a 20 10  sll  %o0, 0x10, %l5
a0088db4:  b7 35 60 10  srl  %l5, 0x10, %i3
a0088db8:  ae 1e e0 01  xor  %i3, 1, %l7
a0088dbc:  80 a0 00 17  cmp  %g0, %l7
a0088dc0:  a4 60 3f ff  subx  %g0, -1, %l2
a0088dc4:  10 bf fe d6  b  0xa008891c
a0088dc8:  a0 04 80 12  add  %l2, %l2, %l0
a0088dcc:  a8 02 ff 83  add  %o3, -125, %l4
a0088dd0:  e8 2f be b1  stb  %l4, [ %fp + -335 ]
a0088dd4:  10 bf ff d0  b  0xa0088d14
a0088dd8:  a4 02 e0 05  add  %o3, 5, %l2
a0088ddc:  83 2c 20 10  sll  %l0, 0x10, %g1
a0088de0:  9f 30 60 10  srl  %g1, 0x10, %o7
a0088de4:  80 a3 e0 00  cmp  %o7, 0
a0088de8:  02 bf ff 33  be  0xa0088ab4
a0088dec:  96 10 20 00  clr  %o3
a0088df0:  a1 2c e0 10  sll  %l3, 0x10, %l0
a0088df4:  95 34 20 10  srl  %l0, 0x10, %o2
a0088df8:  90 07 bf f8  add  %fp, -8, %o0
a0088dfc:  92 02 00 0a  add  %o0, %o2, %o1
a0088e00:  9a 0a e0 ff  and  %o3, 0xff, %o5
a0088e04:  ae 02 80 0d  add  %o2, %o5, %l7
a0088e08:  80 a5 e1 27  cmp  %l7, 0x127
a0088e0c:  18 bf ff 2a  bgu  0xa0088ab4
a0088e10:  ba 02 40 0d  add  %o1, %o5, %i5
a0088e14:  96 02 e0 01  inc  %o3
a0088e18:  e6 0f 7c 58  ldub  [ %i5 + -936 ], %l3
a0088e1c:  aa 02 00 0d  add  %o0, %o5, %l5
a0088e20:  b6 0a e0 ff  and  %o3, 0xff, %i3
a0088e24:  80 a6 c0 0f  cmp  %i3, %o7
a0088e28:  0a bf ff f6  bcs  0xa0088e00
a0088e2c:  e6 2d 7e bd  stb  %l3, [ %l5 + -323 ]
a0088e30:  10 bf ff 22  b  0xa0088ab8
a0088e34:  11 2a 00 ab  sethi  %hi(0xa802ac00), %o0
a0088e38:  c2 0c a0 05  ldub  [ %l2 + 5 ], %g1
a0088e3c:  80 a0 60 01  cmp  %g1, 1
a0088e40:  02 80 00 1c  be  0xa0088eb0
a0088e44:  80 a0 60 02  cmp  %g1, 2
a0088e48:  02 80 00 11  be  0xa0088e8c
a0088e4c:  80 a0 60 04  cmp  %g1, 4
a0088e50:  02 80 00 04  be  0xa0088e60
a0088e54:  80 a0 60 05  cmp  %g1, 5
a0088e58:  12 bf fe 94  bne  0xa00888a8
a0088e5c:  a2 10 00 16  mov  %l6, %l1
a0088e60:  40 02 eb 6d  call  0xa0143c14
a0088e64:  90 10 20 00  clr  %o0
a0088e68:  80 8a 20 ff  btst  0xff, %o0
a0088e6c:  22 bf fe 8f  be,a   0xa00888a8
a0088e70:  a2 10 00 16  mov  %l6, %l1
a0088e74:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0088e78:  e4 0b 63 99  ldub  [ %o5 + 0x399 ], %l2	! 0xa802af99
a0088e7c:  82 14 a0 20  or  %l2, 0x20, %g1
a0088e80:  c2 2b 63 99  stb  %g1, [ %o5 + 0x399 ]
a0088e84:  10 bf fe 89  b  0xa00888a8
a0088e88:  a2 10 00 16  mov  %l6, %l1
a0088e8c:  40 02 eb 62  call  0xa0143c14
a0088e90:  90 10 20 00  clr  %o0
a0088e94:  b6 0a 20 ff  and  %o0, 0xff, %i3
a0088e98:  80 a6 e0 01  cmp  %i3, 1
a0088e9c:  02 bf ff 63  be  0xa0088c28
a0088ea0:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0088ea4:  e0 0b 63 99  ldub  [ %o5 + 0x399 ], %l0	! 0xa802af99
a0088ea8:  10 bf ff f6  b  0xa0088e80
a0088eac:  82 14 20 40  or  %l0, 0x40, %g1
a0088eb0:  40 02 eb 59  call  0xa0143c14
a0088eb4:  90 10 20 00  clr  %o0
a0088eb8:  80 8a 20 ff  btst  0xff, %o0
a0088ebc:  12 80 00 0f  bne  0xa0088ef8
a0088ec0:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0088ec4:  ee 0b 63 99  ldub  [ %o5 + 0x399 ], %l7	! 0xa802af99
a0088ec8:  10 bf ff ee  b  0xa0088e80
a0088ecc:  82 15 e0 10  or  %l7, 0x10, %g1
a0088ed0:  c2 0c a0 05  ldub  [ %l2 + 5 ], %g1
a0088ed4:  80 a0 60 0d  cmp  %g1, 0xd
a0088ed8:  18 80 00 11  bgu  0xa0088f1c
a0088edc:  9a 10 20 01  mov  1, %o5
a0088ee0:  19 00 00 9f  sethi  %hi(0x27c00), %o4
a0088ee4:  95 28 60 02  sll  %g1, 2, %o2
a0088ee8:  9a 13 22 20  or  %o4, 0x220, %o5
a0088eec:  de 03 40 0a  ld  [ %o5 + %o2 ], %o7
a0088ef0:  81 c3 c0 00  jmp  %o7
a0088ef4:  01 00 00 00  nop
a0088ef8:  40 02 eb 47  call  0xa0143c14
a0088efc:  90 10 20 00  clr  %o0	! 0x0
a0088f00:  aa 0a 20 ff  and  %o0, 0xff, %l5
a0088f04:  80 a5 60 01  cmp  %l5, 1
a0088f08:  02 bf ff ef  be  0xa0088ec4
a0088f0c:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0088f10:  10 bf fe 66  b  0xa00888a8
a0088f14:  a2 10 00 16  mov  %l6, %l1
a0088f18:  9a 10 20 0a  mov  0xa, %o5
a0088f1c:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a0088f20:  40 01 2e 5a  call  0xa00d4888
a0088f24:  da 2d 22 98  stb  %o5, [ %l4 + 0x298 ]	! 0xa802d298
a0088f28:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0088f2c:  e2 0b 63 99  ldub  [ %o5 + 0x399 ], %l1	! 0xa802af99
a0088f30:  10 bf ff d4  b  0xa0088e80
a0088f34:  82 14 60 01  or  %l1, 1, %g1
a0088f38:  10 bf ff f9  b  0xa0088f1c
a0088f3c:  9a 10 20 05  mov  5, %o5
a0088f40:  10 bf ff f7  b  0xa0088f1c
a0088f44:  9a 10 20 08  mov  8, %o5
a0088f48:  10 bf ff f5  b  0xa0088f1c
a0088f4c:  9a 10 20 09  mov  9, %o5
a0088f50:  10 bf ff f3  b  0xa0088f1c
a0088f54:  9a 10 20 04  mov  4, %o5
a0088f58:  10 bf ff f1  b  0xa0088f1c
a0088f5c:  9a 10 20 03  mov  3, %o5
a0088f60:  10 bf ff ef  b  0xa0088f1c
a0088f64:  9a 10 20 02  mov  2, %o5
a0088f68:  10 bf ff ed  b  0xa0088f1c
a0088f6c:  9a 10 20 01  mov  1, %o5
a0088f70:  c2 0c a0 05  ldub  [ %l2 + 5 ], %g1
a0088f74:  80 a0 60 01  cmp  %g1, 1
a0088f78:  02 80 00 14  be  0xa0088fc8
a0088f7c:  80 a0 60 02  cmp  %g1, 2
a0088f80:  32 bf ff eb  bne,a   0xa0088f2c
a0088f84:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0088f88:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0088f8c:  d0 04 62 90  ld  [ %l1 + 0x290 ], %o0	! 0xa802d290
a0088f90:  03 00 00 20  sethi  %hi(0x8000), %g1
a0088f94:  92 2a 00 01  andn  %o0, %g1, %o1
a0088f98:  10 bf ff e4  b  0xa0088f28
a0088f9c:  d2 24 62 90  st  %o1, [ %l1 + 0x290 ]
a0088fa0:  c2 0c a0 05  ldub  [ %l2 + 5 ], %g1
a0088fa4:  80 a0 60 01  cmp  %g1, 1
a0088fa8:  02 80 00 12  be  0xa0088ff0
a0088fac:  80 a0 60 02  cmp  %g1, 2
a0088fb0:  22 80 00 0c  be,a   0xa0088fe0
a0088fb4:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0088fb8:  40 01 2e 45  call  0xa00d48cc
a0088fbc:  01 00 00 00  nop
a0088fc0:  10 bf ff db  b  0xa0088f2c
a0088fc4:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0088fc8:  27 2a 00 b4  sethi  %hi(0xa802d000), %l3
a0088fcc:  f8 04 e2 90  ld  [ %l3 + 0x290 ], %i4	! 0xa802d290
a0088fd0:  3b 00 00 20  sethi  %hi(0x8000), %i5
a0088fd4:  96 17 00 1d  or  %i4, %i5, %o3
a0088fd8:  10 bf ff d4  b  0xa0088f28
a0088fdc:  d6 24 e2 90  st  %o3, [ %l3 + 0x290 ]
a0088fe0:  fa 03 62 90  ld  [ %o5 + 0x290 ], %i5
a0088fe4:  82 0f 77 ff  and  %i5, -2049, %g1
a0088fe8:  10 bf ff f4  b  0xa0088fb8
a0088fec:  c2 23 62 90  st  %g1, [ %o5 + 0x290 ]
a0088ff0:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0088ff4:  d6 03 62 90  ld  [ %o5 + 0x290 ], %o3	! 0xa802d290
a0088ff8:  10 bf ff fc  b  0xa0088fe8
a0088ffc:  82 12 e8 00  or  %o3, 0x800, %g1
a0089000:  ac 10 20 00  clr  %l6
a0089004:  10 bf fe 29  b  0xa00888a8
a0089008:  a2 10 00 16  mov  %l6, %l1
a008900c:  da 0c a0 05  ldub  [ %l2 + 5 ], %o5
a0089010:  80 a3 60 0d  cmp  %o5, 0xd
a0089014:  12 80 00 0c  bne  0xa0089044
a0089018:  92 0b 60 ff  and  %o5, 0xff, %o1
a008901c:  23 2a 00 b4  sethi  %hi(0xa802d000), %l1
a0089020:  a6 14 62 90  or  %l1, 0x290, %l3	! 0xa802d290
a0089024:  fa 04 e0 a8  ld  [ %l3 + 0xa8 ], %i5
a0089028:  96 17 68 00  or  %i5, 0x800, %o3
a008902c:  b8 10 20 04  mov  4, %i4
a0089030:  f8 2c e1 81  stb  %i4, [ %l3 + 0x181 ]
a0089034:  40 01 49 c1  call  0xa00db738
a0089038:  d6 24 e0 a8  st  %o3, [ %l3 + 0xa8 ]
a008903c:  da 0c a0 05  ldub  [ %l2 + 5 ], %o5
a0089040:  92 0b 60 ff  and  %o5, 0xff, %o1
a0089044:  80 a2 60 0e  cmp  %o1, 0xe
a0089048:  12 80 00 0c  bne  0xa0089078
a008904c:  98 0b 60 ff  and  %o5, 0xff, %o4
a0089050:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0089054:  82 13 62 90  or  %o5, 0x290, %g1	! 0xa802d290
a0089058:  d4 00 60 a8  ld  [ %g1 + 0xa8 ], %o2
a008905c:  90 12 a8 00  or  %o2, 0x800, %o0
a0089060:  9e 10 20 05  mov  5, %o7
a0089064:  de 28 61 81  stb  %o7, [ %g1 + 0x181 ]
a0089068:  40 01 49 b4  call  0xa00db738
a008906c:  d0 20 60 a8  st  %o0, [ %g1 + 0xa8 ]
a0089070:  da 0c a0 05  ldub  [ %l2 + 5 ], %o5
a0089074:  98 0b 60 ff  and  %o5, 0xff, %o4
a0089078:  80 a3 20 0f  cmp  %o4, 0xf
a008907c:  32 bf ff ac  bne,a   0xa0088f2c
a0089080:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089084:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a0089088:  a8 14 22 90  or  %l0, 0x290, %l4	! 0xa802d290
a008908c:  f6 05 20 a8  ld  [ %l4 + 0xa8 ], %i3
a0089090:  aa 16 e8 00  or  %i3, 0x800, %l5
a0089094:  ae 10 20 06  mov  6, %l7
a0089098:  ee 2d 21 81  stb  %l7, [ %l4 + 0x181 ]
a008909c:  40 01 49 a7  call  0xa00db738
a00890a0:  ea 25 20 a8  st  %l5, [ %l4 + 0xa8 ]
a00890a4:  10 bf ff a2  b  0xa0088f2c
a00890a8:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00890ac:  de 0c a0 04  ldub  [ %l2 + 4 ], %o7
a00890b0:  80 a3 e0 2a  cmp  %o7, 0x2a
a00890b4:  12 80 00 08  bne  0xa00890d4
a00890b8:  01 00 00 00  nop
a00890bc:  ea 0c a0 05  ldub  [ %l2 + 5 ], %l5
a00890c0:  a8 5d 63 20  smul  %l5, 0x320, %l4
a00890c4:  a0 05 25 00  add  %l4, 0x500, %l0
a00890c8:  95 2c 20 10  sll  %l0, 0x10, %o2
a00890cc:  40 03 00 51  call  0xa0149210
a00890d0:  91 32 a0 10  srl  %o2, 0x10, %o0
a00890d4:  40 02 91 20  call  0xa012d554
a00890d8:  90 10 00 12  mov  %l2, %o0
a00890dc:  2f 2a 00 b8  sethi  %hi(0xa802e000), %l7
a00890e0:  e4 0d e2 20  ldub  [ %l7 + 0x220 ], %l2	! 0xa802e220
a00890e4:  80 8c a0 20  btst  0x20, %l2
a00890e8:  22 bf ff 91  be,a   0xa0088f2c
a00890ec:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00890f0:  37 00 04 00  sethi  %hi(0x100000), %i3
a00890f4:  40 01 58 1f  call  0xa00df170
a00890f8:  90 16 e0 40  or  %i3, 0x40, %o0	! 0x100040
a00890fc:  10 bf ff 8c  b  0xa0088f2c
a0089100:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089104:  32 bf fd e9  bne,a   0xa00888a8
a0089108:  a2 10 00 16  mov  %l6, %l1
a008910c:  b8 07 bf 00  add  %fp, -256, %i4
a0089110:  92 10 20 00  clr  %o1
a0089114:  94 10 20 80  mov  0x80, %o2
a0089118:  2b 2a 00 ab  sethi  %hi(0xa802ac00), %l5
a008911c:  40 03 39 73  call  0xa01576e8
a0089120:  90 10 00 1c  mov  %i4, %o0
a0089124:  ba 0c e0 ff  and  %l3, 0xff, %i5
a0089128:  a8 15 63 9a  or  %l5, 0x39a, %l4
a008912c:  e0 0c a0 04  ldub  [ %l2 + 4 ], %l0
a0089130:  e6 0c a0 06  ldub  [ %l2 + 6 ], %l3
a0089134:  ee 0c a0 05  ldub  [ %l2 + 5 ], %l7
a0089138:  d0 15 20 02  lduh  [ %l4 + 2 ], %o0
a008913c:  94 10 20 6e  mov  0x6e, %o2
a0089140:  9e 10 3f 85  mov  -123, %o7
a0089144:  82 10 20 20  mov  0x20, %g1
a0089148:  d4 2f bf 80  stb  %o2, [ %fp + -128 ]
a008914c:  e0 2f bf 85  stb  %l0, [ %fp + -123 ]
a0089150:  d0 2f bf 86  stb  %o0, [ %fp + -122 ]
a0089154:  de 2f bf 81  stb  %o7, [ %fp + -127 ]
a0089158:  c2 2f bf 84  stb  %g1, [ %fp + -124 ]
a008915c:  92 10 20 50  mov  0x50, %o1
a0089160:  37 2a 00 ab  sethi  %hi(0xa802ac00), %i3
a0089164:  d2 2e e3 9e  stb  %o1, [ %i3 + 0x39e ]	! 0xa802af9e
a0089168:  e0 2d 63 9a  stb  %l0, [ %l5 + 0x39a ]
a008916c:  ee 2f bf 82  stb  %l7, [ %fp + -126 ]
a0089170:  e6 2f bf 83  stb  %l3, [ %fp + -125 ]
a0089174:  90 10 00 1d  mov  %i5, %o0
a0089178:  92 10 20 07  mov  7, %o1
a008917c:  40 02 fd 4b  call  0xa01486a8
a0089180:  94 10 00 11  mov  %l1, %o2
a0089184:  a0 0c e0 ff  and  %l3, 0xff, %l0
a0089188:  96 04 20 20  add  %l0, 0x20, %o3
a008918c:  80 a2 e0 80  cmp  %o3, 0x80
a0089190:  14 80 00 03  bg  0xa008919c
a0089194:  82 10 21 00  mov  0x100, %g1
a0089198:  82 10 20 80  mov  0x80, %g1
a008919c:  c2 35 20 02  sth  %g1, [ %l4 + 2 ]
a00891a0:  98 04 a0 07  add  %l2, 7, %o4
a00891a4:  d0 0d 63 9a  ldub  [ %l5 + 0x39a ], %o0
a00891a8:  92 10 20 a0  mov  0xa0, %o1
a00891ac:  94 10 00 10  mov  %l0, %o2
a00891b0:  40 02 fa 38  call  0xa0147a90
a00891b4:  96 10 20 20  mov  0x20, %o3
a00891b8:  98 15 63 9a  or  %l5, 0x39a, %o4
a00891bc:  9a 04 20 20  add  %l0, 0x20, %o5
a00891c0:  c2 13 20 02  lduh  [ %o4 + 2 ], %g1
a00891c4:  80 a3 40 01  cmp  %o5, %g1
a00891c8:  26 bf fd b8  bl,a   0xa00888a8
a00891cc:  a2 10 00 16  mov  %l6, %l1
a00891d0:  80 a0 60 80  cmp  %g1, 0x80
a00891d4:  02 80 03 01  be  0xa0089dd8
a00891d8:  29 2a 00 ab  sethi  %hi(0xa802ac00), %l4
a00891dc:  d0 0d 23 9a  ldub  [ %l4 + 0x39a ], %o0	! 0xa802af9a
a00891e0:  98 10 00 1c  mov  %i4, %o4
a00891e4:  92 10 20 a0  mov  0xa0, %o1
a00891e8:  94 10 20 80  mov  0x80, %o2
a00891ec:  40 02 fa 2b  call  0xa0147a98
a00891f0:  96 10 20 80  mov  0x80, %o3
a00891f4:  b8 15 63 9a  or  %l5, 0x39a, %i4
a00891f8:  c0 2f 20 01  clrb  [ %i4 + 1 ]
a00891fc:  92 10 00 1c  mov  %i4, %o1
a0089200:  98 10 20 00  clr  %o4
a0089204:  90 07 bf f8  add  %fp, -8, %o0
a0089208:  96 10 20 00  clr  %o3
a008920c:  94 0b 20 ff  and  %o4, 0xff, %o2
a0089210:  82 02 00 0a  add  %o0, %o2, %g1
a0089214:  de 08 7f 08  ldub  [ %g1 + -248 ], %o7
a0089218:  a0 03 20 01  add  %o4, 1, %l0
a008921c:  94 02 c0 0f  add  %o3, %o7, %o2
a0089220:  80 8c 20 80  btst  0x80, %l0
a0089224:  96 10 00 0a  mov  %o2, %o3
a0089228:  02 bf ff f9  be  0xa008920c
a008922c:  98 10 00 10  mov  %l0, %o4
a0089230:  80 8a a0 ff  btst  0xff, %o2
a0089234:  12 80 02 ee  bne  0xa0089dec
a0089238:  d4 2a 60 01  stb  %o2, [ %o1 + 1 ]
a008923c:  d0 0c a0 26  ldub  [ %l2 + 0x26 ], %o0
a0089240:  d6 0f bf 7f  ldub  [ %fp + -129 ], %o3
a0089244:  80 a2 c0 08  cmp  %o3, %o0
a0089248:  02 bf fe 78  be  0xa0088c28
a008924c:  98 10 20 50  mov  0x50, %o4
a0089250:  d8 2e e3 9e  stb  %o4, [ %i3 + 0x39e ]
a0089254:  e6 2c 60 03  stb  %l3, [ %l1 + 3 ]
a0089258:  9a 10 20 6e  mov  0x6e, %o5
a008925c:  92 10 3f 85  mov  -123, %o1
a0089260:  a6 10 3f ef  mov  -17, %l3
a0089264:  da 2c 40 00  stb  %o5, [ %l1 ]
a0089268:  d2 2c 60 01  stb  %o1, [ %l1 + 1 ]
a008926c:  ee 2c 60 02  stb  %l7, [ %l1 + 2 ]
a0089270:  e6 2c 60 04  stb  %l3, [ %l1 + 4 ]
a0089274:  d0 2c 60 05  stb  %o0, [ %l1 + 5 ]
a0089278:  d6 2c 60 06  stb  %o3, [ %l1 + 6 ]
a008927c:  90 10 00 1d  mov  %i5, %o0
a0089280:  94 10 00 11  mov  %l1, %o2
a0089284:  10 bf fe 67  b  0xa0088c20
a0089288:  92 10 20 07  mov  7, %o1
a008928c:  9a 10 3f ff  mov  -1, %o5
a0089290:  da 2f bf af  stb  %o5, [ %fp + -81 ]
a0089294:  82 10 20 32  mov  0x32, %g1
a0089298:  c2 2f bf b1  stb  %g1, [ %fp + -79 ]
a008929c:  da 2f bf ae  stb  %o5, [ %fp + -82 ]
a00892a0:  10 bf fe 74  b  0xa0088c70
a00892a4:  c0 2f bf b0  clrb  [ %fp + -80 ]
a00892a8:  40 02 f0 98  call  0xa0145508
a00892ac:  90 10 20 02  mov  2, %o0
a00892b0:  40 02 f0 96  call  0xa0145508
a00892b4:  90 10 20 03  mov  3, %o0
a00892b8:  40 01 3a ca  call  0xa00d7de0
a00892bc:  01 00 00 00  nop
a00892c0:  40 01 3e 85  call  0xa00d8cd4
a00892c4:  01 00 00 00  nop
a00892c8:  10 bf ff 19  b  0xa0088f2c
a00892cc:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00892d0:  40 01 4c 43  call  0xa00dc3dc
a00892d4:  01 00 00 00  nop
a00892d8:  10 bf ff 15  b  0xa0088f2c
a00892dc:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00892e0:  3b 2a 00 90  sethi  %hi(0xa8024000), %i5
a00892e4:  d8 0f 60 28  ldub  [ %i5 + 0x28 ], %o4	! 0xa8024028
a00892e8:  9a 10 3f ff  mov  -1, %o5
a00892ec:  da 2f bf af  stb  %o5, [ %fp + -81 ]
a00892f0:  d8 2f bf b1  stb  %o4, [ %fp + -79 ]
a00892f4:  10 bf ff eb  b  0xa00892a0
a00892f8:  c0 2f bf ae  clrb  [ %fp + -82 ]
a00892fc:  a0 07 bf 80  add  %fp, -128, %l0
a0089300:  90 10 00 12  mov  %l2, %o0
a0089304:  40 01 19 f2  call  0xa00cfacc
a0089308:  92 10 00 10  mov  %l0, %o1
a008930c:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0089310:  ba 10 20 50  mov  0x50, %i5
a0089314:  fa 2a e3 9e  stb  %i5, [ %o3 + 0x39e ]
a0089318:  98 10 20 00  clr  %o4
a008931c:  82 10 20 00  clr  %g1
a0089320:  e2 08 40 10  ldub  [ %g1 + %l0 ], %l1
a0089324:  d0 0a e3 9e  ldub  [ %o3 + 0x39e ], %o0
a0089328:  98 03 20 01  inc  %o4
a008932c:  9a 1c 40 08  xor  %l1, %o0, %o5
a0089330:  82 0b 20 ff  and  %o4, 0xff, %g1
a0089334:  80 a0 60 0a  cmp  %g1, 0xa
a0089338:  0a bf ff fa  bcs  0xa0089320
a008933c:  da 2a e3 9e  stb  %o5, [ %o3 + 0x39e ]
a0089340:  da 28 40 10  stb  %o5, [ %g1 + %l0 ]
a0089344:  90 0c e0 ff  and  %l3, 0xff, %o0
a0089348:  94 10 00 10  mov  %l0, %o2
a008934c:  10 bf fe 35  b  0xa0088c20
a0089350:  92 10 20 0b  mov  0xb, %o1
a0089354:  e6 0c a0 04  ldub  [ %l2 + 4 ], %l3
a0089358:  80 a4 e0 00  cmp  %l3, 0
a008935c:  12 bf fd 53  bne  0xa00888a8
a0089360:  a2 10 00 16  mov  %l6, %l1
a0089364:  d0 0c a0 05  ldub  [ %l2 + 5 ], %o0
a0089368:  9a 02 3f ff  add  %o0, -1, %o5
a008936c:  82 0b 60 ff  and  %o5, 0xff, %g1
a0089370:  80 a0 60 02  cmp  %g1, 2
a0089374:  92 0a 20 ff  and  %o0, 0xff, %o1
a0089378:  ba 60 20 00  subx  %g0, 0, %i5
a008937c:  a2 1a 60 ff  xor  %o1, 0xff, %l1
a0089380:  80 a0 00 11  cmp  %g0, %l1
a0089384:  b8 0f 60 01  and  %i5, 1, %i4
a0089388:  96 60 3f ff  subx  %g0, -1, %o3
a008938c:  80 97 00 0b  orcc  %i4, %o3, %g0
a0089390:  02 bf fd 46  be  0xa00888a8
a0089394:  a2 10 00 16  mov  %l6, %l1
a0089398:  19 2a 00 90  sethi  %hi(0xa8024000), %o4
a008939c:  10 bf fd 43  b  0xa00888a8
a00893a0:  d0 2b 20 28  stb  %o0, [ %o4 + 0x28 ]	! 0xa8024028
a00893a4:  40 02 eb bd  call  0xa0144298
a00893a8:  90 10 20 00  clr  %o0
a00893ac:  90 0a 20 ff  and  %o0, 0xff, %o0
a00893b0:  80 a2 20 01  cmp  %o0, 1
a00893b4:  22 80 00 30  be,a   0xa0089474
a00893b8:  d0 2f bf ab  stb  %o0, [ %fp + -85 ]
a00893bc:  82 10 20 01  mov  1, %g1
a00893c0:  c2 2f bf af  stb  %g1, [ %fp + -81 ]
a00893c4:  10 bf fe 29  b  0xa0088c68
a00893c8:  c0 2f bf ae  clrb  [ %fp + -82 ]
a00893cc:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a00893d0:  d8 0a e2 9a  ldub  [ %o3 + 0x29a ], %o4	! 0xa802d29a
a00893d4:  10 bf ff c6  b  0xa00892ec
a00893d8:  9a 10 20 64  mov  0x64, %o5
a00893dc:  2f 2a 00 b4  sethi  %hi(0xa802d000), %l7
a00893e0:  a0 15 e2 90  or  %l7, 0x290, %l0	! 0xa802d290
a00893e4:  ec 04 21 1c  ld  [ %l0 + 0x11c ], %l6
a00893e8:  2b 20 00 00  sethi  %hi(0x80000000), %l5
a00893ec:  a8 2d 80 15  andn  %l6, %l5, %l4
a00893f0:  e8 24 21 1c  st  %l4, [ %l0 + 0x11c ]
a00893f4:  94 10 20 64  mov  0x64, %o2
a00893f8:  d6 0c 20 09  ldub  [ %l0 + 9 ], %o3
a00893fc:  d4 2f bf af  stb  %o2, [ %fp + -81 ]
a0089400:  10 bf ff bd  b  0xa00892f4
a0089404:  d6 2f bf b1  stb  %o3, [ %fp + -79 ]
a0089408:  40 02 eb a4  call  0xa0144298
a008940c:  90 10 20 00  clr  %o0
a0089410:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089414:  80 a2 20 01  cmp  %o0, 1
a0089418:  02 80 00 16  be  0xa0089470
a008941c:  9e 10 20 64  mov  0x64, %o7
a0089420:  de 2f bf af  stb  %o7, [ %fp + -81 ]
a0089424:  c0 2f bf ae  clrb  [ %fp + -82 ]
a0089428:  40 01 2b 8a  call  0xa00d4250
a008942c:  c0 2f bf b0  clrb  [ %fp + -80 ]
a0089430:  10 bf fe 10  b  0xa0088c70
a0089434:  d0 2f bf b1  stb  %o0, [ %fp + -79 ]
a0089438:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a008943c:  c2 08 62 a1  ldub  [ %g1 + 0x2a1 ], %g1	! 0xa802d2a1
a0089440:  90 10 3f aa  mov  -86, %o0
a0089444:  d0 2f bf af  stb  %o0, [ %fp + -81 ]
a0089448:  c0 2f bf ae  clrb  [ %fp + -82 ]
a008944c:  80 a0 60 07  cmp  %g1, 7
a0089450:  18 80 00 16  bgu  0xa00894a8
a0089454:  c0 2f bf b0  clrb  [ %fp + -80 ]
a0089458:  25 00 00 9f  sethi  %hi(0x27c00), %l2
a008945c:  93 28 60 02  sll  %g1, 2, %o1
a0089460:  9a 14 a2 00  or  %l2, 0x200, %o5
a0089464:  d8 03 40 09  ld  [ %o5 + %o1 ], %o4
a0089468:  81 c3 00 00  jmp  %o4
a008946c:  01 00 00 00  nop
a0089470:  d0 2f bf ab  stb  %o0, [ %fp + -85 ]
a0089474:  10 bf ff d3  b  0xa00893c0
a0089478:  82 10 3f ff  mov  -1, %g1
a008947c:  82 10 3f aa  mov  -86, %g1
a0089480:  10 bf fd fc  b  0xa0088c70
a0089484:  c2 2f bf b1  stb  %g1, [ %fp + -79 ]
a0089488:  10 bf ff fe  b  0xa0089480
a008948c:  82 10 20 68  mov  0x68, %g1
a0089490:  10 bf ff fc  b  0xa0089480
a0089494:  82 10 20 5a  mov  0x5a, %g1
a0089498:  10 bf ff fa  b  0xa0089480
a008949c:  82 10 20 28  mov  0x28, %g1
a00894a0:  10 bf ff f8  b  0xa0089480
a00894a4:  82 10 20 7e  mov  0x7e, %g1
a00894a8:  10 bf ff f6  b  0xa0089480
a00894ac:  82 10 20 46  mov  0x46, %g1
a00894b0:  40 02 eb 7a  call  0xa0144298
a00894b4:  90 10 20 00  clr  %o0
a00894b8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00894bc:  80 a2 20 01  cmp  %o0, 1
a00894c0:  02 bf ff ec  be  0xa0089470
a00894c4:  94 10 20 64  mov  0x64, %o2
a00894c8:  d4 2f bf af  stb  %o2, [ %fp + -81 ]
a00894cc:  c0 2f bf ae  clrb  [ %fp + -82 ]
a00894d0:  40 01 2b 25  call  0xa00d4164
a00894d4:  c0 2f bf b0  clrb  [ %fp + -80 ]
a00894d8:  10 bf fd e6  b  0xa0088c70
a00894dc:  d0 2f bf b1  stb  %o0, [ %fp + -79 ]
a00894e0:  40 02 eb 6e  call  0xa0144298
a00894e4:  90 10 20 00  clr  %o0
a00894e8:  90 0a 20 ff  and  %o0, 0xff, %o0
a00894ec:  80 a2 20 01  cmp  %o0, 1
a00894f0:  02 bf ff e0  be  0xa0089470
a00894f4:  9e 10 20 64  mov  0x64, %o7
a00894f8:  de 2f bf af  stb  %o7, [ %fp + -81 ]
a00894fc:  c0 2f bf ae  clrb  [ %fp + -82 ]
a0089500:  40 01 2c 16  call  0xa00d4558
a0089504:  c0 2f bf b0  clrb  [ %fp + -80 ]
a0089508:  10 bf fd da  b  0xa0088c70
a008950c:  d0 2f bf b1  stb  %o0, [ %fp + -79 ]
a0089510:  40 02 eb 62  call  0xa0144298
a0089514:  90 10 20 00  clr  %o0
a0089518:  90 0a 20 ff  and  %o0, 0xff, %o0
a008951c:  80 a2 20 01  cmp  %o0, 1
a0089520:  02 bf ff d4  be  0xa0089470
a0089524:  98 10 20 64  mov  0x64, %o4
a0089528:  d8 2f bf af  stb  %o4, [ %fp + -81 ]
a008952c:  c0 2f bf ae  clrb  [ %fp + -82 ]
a0089530:  40 01 2b a1  call  0xa00d43b4
a0089534:  c0 2f bf b0  clrb  [ %fp + -80 ]
a0089538:  10 bf fd ce  b  0xa0088c70
a008953c:  d0 2f bf b1  stb  %o0, [ %fp + -79 ]
a0089540:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a0089544:  10 bf ff a4  b  0xa00893d4
a0089548:  d8 0c a2 a4  ldub  [ %l2 + 0x2a4 ], %o4	! 0xa802d2a4
a008954c:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0089550:  10 bf ff a1  b  0xa00893d4
a0089554:  d8 0b 62 a3  ldub  [ %o5 + 0x2a3 ], %o4	! 0xa802d2a3
a0089558:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a008955c:  10 bf ff 9e  b  0xa00893d4
a0089560:  d8 0a 62 a2  ldub  [ %o1 + 0x2a2 ], %o4	! 0xa802d2a2
a0089564:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0089568:  11 00 03 ff  sethi  %hi(0xffc00), %o0
a008956c:  f8 08 62 a1  ldub  [ %g1 + 0x2a1 ], %i4
a0089570:  ba 12 21 80  or  %o0, 0x180, %i5
a0089574:  b6 10 20 0b  mov  0xb, %i3
a0089578:  d6 0f 40 1c  ldub  [ %i5 + %i4 ], %o3
a008957c:  10 bf ff a1  b  0xa0089400
a0089580:  f6 2f bf af  stb  %i3, [ %fp + -81 ]
a0089584:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a0089588:  c2 02 62 90  ld  [ %o1 + 0x290 ], %g1	! 0xa802d290
a008958c:  83 30 60 0f  srl  %g1, 0xf, %g1
a0089590:  98 08 60 01  and  %g1, 1, %o4
a0089594:  9a 10 20 02  mov  2, %o5
a0089598:  a4 10 20 02  mov  2, %l2
a008959c:  9a 23 40 0c  sub  %o5, %o4, %o5
a00895a0:  e4 2f bf af  stb  %l2, [ %fp + -81 ]
a00895a4:  10 bf ff 54  b  0xa00892f4
a00895a8:  da 2f bf b1  stb  %o5, [ %fp + -79 ]
a00895ac:  90 10 3f ff  mov  -1, %o0
a00895b0:  d0 2f bf af  stb  %o0, [ %fp + -81 ]
a00895b4:  d0 2f bf ae  stb  %o0, [ %fp + -82 ]
a00895b8:  10 bf fd ad  b  0xa0088c6c
a00895bc:  c0 2f bf b0  clrb  [ %fp + -80 ]
a00895c0:  9a 10 3f ff  mov  -1, %o5
a00895c4:  da 2f bf af  stb  %o5, [ %fp + -81 ]
a00895c8:  10 bf ff 34  b  0xa0089298
a00895cc:  82 10 20 12  mov  0x12, %g1
a00895d0:  9a 10 3f ff  mov  -1, %o5
a00895d4:  da 2f bf af  stb  %o5, [ %fp + -81 ]
a00895d8:  10 bf ff 30  b  0xa0089298
a00895dc:  82 10 20 6f  mov  0x6f, %g1
a00895e0:  ba 10 3f ff  mov  -1, %i5
a00895e4:  fa 2f bf af  stb  %i5, [ %fp + -81 ]
a00895e8:  fa 2f bf ae  stb  %i5, [ %fp + -82 ]
a00895ec:  40 02 f1 43  call  0xa0145af8
a00895f0:  90 10 20 07  mov  7, %o0
a00895f4:  b9 32 20 08  srl  %o0, 8, %i4
a00895f8:  10 bf ff 8e  b  0xa0089430
a00895fc:  f8 2f bf b0  stb  %i4, [ %fp + -80 ]
a0089600:  ac 10 20 04  mov  4, %l6
a0089604:  ec 2f bf af  stb  %l6, [ %fp + -81 ]
a0089608:  10 bf ff e7  b  0xa00895a4
a008960c:  9a 10 20 03  mov  3, %o5
a0089610:  aa 10 20 08  mov  8, %l5
a0089614:  ea 2f bf af  stb  %l5, [ %fp + -81 ]
a0089618:  10 bf ff e3  b  0xa00895a4
a008961c:  9a 10 20 01  mov  1, %o5
a0089620:  a8 10 3f ff  mov  -1, %l4
a0089624:  e8 2f bf af  stb  %l4, [ %fp + -81 ]
a0089628:  e8 2f bf ae  stb  %l4, [ %fp + -82 ]
a008962c:  90 10 20 00  clr  %o0
a0089630:  40 02 f0 0c  call  0xa0145660
a0089634:  92 10 20 01  mov  1, %o1
a0089638:  a1 2a 20 10  sll  %o0, 0x10, %l0
a008963c:  95 34 20 10  srl  %l0, 0x10, %o2
a0089640:  9f 2a a0 02  sll  %o2, 2, %o7
a0089644:  98 03 c0 0a  add  %o7, %o2, %o4
a0089648:  a5 33 20 07  srl  %o4, 7, %l2
a008964c:  82 03 00 0c  add  %o4, %o4, %g1
a0089650:  10 bf ff 8c  b  0xa0089480
a0089654:  e4 2f bf b0  stb  %l2, [ %fp + -80 ]
a0089658:  9a 10 3f ff  mov  -1, %o5
a008965c:  da 2f bf ae  stb  %o5, [ %fp + -82 ]
a0089660:  92 10 20 00  clr  %o1
a0089664:  40 02 ef ff  call  0xa0145660
a0089668:  90 10 20 00  clr  %o0
a008966c:  93 2a 20 10  sll  %o0, 0x10, %o1
a0089670:  83 32 60 10  srl  %o1, 0x10, %g1
a0089674:  a0 58 60 64  smul  %g1, 0x64, %l0
a0089678:  90 10 20 00  clr  %o0
a008967c:  40 02 ef f9  call  0xa0145660
a0089680:  92 10 20 00  clr  %o1
a0089684:  91 2a 20 10  sll  %o0, 0x10, %o0
a0089688:  bb 32 20 10  srl  %o0, 0x10, %i5
a008968c:  b8 5f 60 64  smul  %i5, 0x64, %i4
a0089690:  b7 37 20 10  srl  %i4, 0x10, %i3
a0089694:  97 34 20 08  srl  %l0, 8, %o3
a0089698:  f6 2f bf af  stb  %i3, [ %fp + -81 ]
a008969c:  d6 2f bf b0  stb  %o3, [ %fp + -80 ]
a00896a0:  10 bf fd 74  b  0xa0088c70
a00896a4:  e0 2f bf b1  stb  %l0, [ %fp + -79 ]
a00896a8:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a00896ac:  d6 06 e2 90  ld  [ %i3 + 0x290 ], %o3	! 0xa802d290
a00896b0:  10 bf ff b8  b  0xa0089590
a00896b4:  83 32 e0 0b  srl  %o3, 0xb, %g1
a00896b8:  2f 2a 00 b4  sethi  %hi(0xa802d000), %l7
a00896bc:  10 bf ff 46  b  0xa00893d4
a00896c0:  d8 0d e2 a7  ldub  [ %l7 + 0x2a7 ], %o4	! 0xa802d2a7
a00896c4:  2d 2a 00 b4  sethi  %hi(0xa802d000), %l6
a00896c8:  10 bf ff 43  b  0xa00893d4
a00896cc:  d8 0d a2 a6  ldub  [ %l6 + 0x2a6 ], %o4	! 0xa802d2a6
a00896d0:  2b 2a 00 b4  sethi  %hi(0xa802d000), %l5
a00896d4:  10 bf ff 40  b  0xa00893d4
a00896d8:  d8 0d 62 a5  ldub  [ %l5 + 0x2a5 ], %o4	! 0xa802d2a5
a00896dc:  29 2a 00 b4  sethi  %hi(0xa802d000), %l4
a00896e0:  c2 0d 22 ae  ldub  [ %l4 + 0x2ae ], %g1	! 0xa802d2ae
a00896e4:  a0 10 20 03  mov  3, %l0
a00896e8:  e0 2f bf af  stb  %l0, [ %fp + -81 ]
a00896ec:  c0 2f bf ae  clrb  [ %fp + -82 ]
a00896f0:  80 a0 60 05  cmp  %g1, 5
a00896f4:  02 80 00 1a  be  0xa008975c
a00896f8:  c0 2f bf b0  clrb  [ %fp + -80 ]
a00896fc:  80 a0 60 06  cmp  %g1, 6
a0089700:  02 80 00 15  be  0xa0089754
a0089704:  80 a0 60 07  cmp  %g1, 7
a0089708:  02 80 00 11  be  0xa008974c
a008970c:  80 a0 60 08  cmp  %g1, 8
a0089710:  02 80 00 0d  be  0xa0089744
a0089714:  80 a0 60 0c  cmp  %g1, 0xc
a0089718:  02 80 00 09  be  0xa008973c
a008971c:  80 a0 60 0d  cmp  %g1, 0xd
a0089720:  22 bf ff 58  be,a   0xa0089480
a0089724:  82 10 20 10  mov  0x10, %g1
a0089728:  10 bf ff 56  b  0xa0089480
a008972c:  82 10 20 01  mov  1, %g1
a0089730:  2f 2a 00 b4  sethi  %hi(0xa802d000), %l7
a0089734:  10 bf ff 28  b  0xa00893d4
a0089738:  d8 0d e2 a0  ldub  [ %l7 + 0x2a0 ], %o4	! 0xa802d2a0
a008973c:  10 bf ff 51  b  0xa0089480
a0089740:  82 10 20 0f  mov  0xf, %g1
a0089744:  10 bf ff 4f  b  0xa0089480
a0089748:  82 10 20 54  mov  0x54, %g1
a008974c:  10 bf ff 4d  b  0xa0089480
a0089750:  82 10 20 53  mov  0x53, %g1
a0089754:  10 bf ff 4b  b  0xa0089480
a0089758:  82 10 20 12  mov  0x12, %g1
a008975c:  10 bf ff 49  b  0xa0089480
a0089760:  82 10 20 11  mov  0x11, %g1
a0089764:  c2 0c a0 05  ldub  [ %l2 + 5 ], %g1
a0089768:  80 a0 60 50  cmp  %g1, 0x50
a008976c:  02 80 00 14  be  0xa00897bc
a0089770:  9a 10 20 02  mov  2, %o5
a0089774:  80 a0 60 78  cmp  %g1, 0x78
a0089778:  22 80 00 11  be,a   0xa00897bc
a008977c:  9a 10 20 01  mov  1, %o5
a0089780:  40 01 39 10  call  0xa00d7bc0
a0089784:  01 00 00 00  nop
a0089788:  10 bf fd e9  b  0xa0088f2c
a008978c:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089790:  da 0c a0 05  ldub  [ %l2 + 5 ], %o5
a0089794:  80 a3 60 64  cmp  %o5, 0x64
a0089798:  28 80 00 05  bleu,a   0xa00897ac
a008979c:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00897a0:  9a 10 20 64  mov  0x64, %o5
a00897a4:  da 2c a0 05  stb  %o5, [ %l2 + 5 ]
a00897a8:  25 2a 00 b4  sethi  %hi(0xa802d000), %l2
a00897ac:  40 01 2b d3  call  0xa00d46f8
a00897b0:  da 2c a2 a7  stb  %o5, [ %l2 + 0x2a7 ]	! 0xa802d2a7
a00897b4:  10 bf fd de  b  0xa0088f2c
a00897b8:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00897bc:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00897c0:  10 bf ff f0  b  0xa0089780
a00897c4:  da 2b 22 d4  stb  %o5, [ %o4 + 0x2d4 ]	! 0xa802d2d4
a00897c8:  da 0c a0 05  ldub  [ %l2 + 5 ], %o5
a00897cc:  80 a3 60 64  cmp  %o5, 0x64
a00897d0:  08 80 00 04  bleu  0xa00897e0
a00897d4:  21 2a 00 b4  sethi  %hi(0xa802d000), %l0
a00897d8:  9a 10 20 64  mov  0x64, %o5
a00897dc:  da 2c a0 05  stb  %o5, [ %l2 + 5 ]
a00897e0:  40 01 2b b9  call  0xa00d46c4
a00897e4:  da 2c 22 a6  stb  %o5, [ %l0 + 0x2a6 ]
a00897e8:  10 bf fd d1  b  0xa0088f2c
a00897ec:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00897f0:  da 0c a0 05  ldub  [ %l2 + 5 ], %o5
a00897f4:  80 a3 60 64  cmp  %o5, 0x64
a00897f8:  08 80 00 04  bleu  0xa0089808
a00897fc:  37 2a 00 b4  sethi  %hi(0xa802d000), %i3
a0089800:  9a 10 20 64  mov  0x64, %o5
a0089804:  da 2c a0 05  stb  %o5, [ %l2 + 5 ]
a0089808:  40 01 2b a2  call  0xa00d4690
a008980c:  da 2e e2 a5  stb  %o5, [ %i3 + 0x2a5 ]
a0089810:  10 bf fd c7  b  0xa0088f2c
a0089814:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089818:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008981c:  e6 0c a0 05  ldub  [ %l2 + 5 ], %l3
a0089820:  d6 03 22 90  ld  [ %o4 + 0x290 ], %o3
a0089824:  a4 13 22 90  or  %o4, 0x290, %l2
a0089828:  80 8a e8 00  btst  0x800, %o3
a008982c:  02 80 00 06  be  0xa0089844
a0089830:  e6 2c a0 10  stb  %l3, [ %l2 + 0x10 ]
a0089834:  b8 0a f7 ff  and  %o3, -2049, %i4
a0089838:  f8 23 22 90  st  %i4, [ %o4 + 0x290 ]
a008983c:  40 02 f8 6c  call  0xa01479ec
a0089840:  90 10 20 00  clr  %o0
a0089844:  40 01 2c 4b  call  0xa00d4970
a0089848:  01 00 00 00  nop
a008984c:  10 bf fd b8  b  0xa0088f2c
a0089850:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089854:  c2 0c a0 05  ldub  [ %l2 + 5 ], %g1
a0089858:  80 a0 60 03  cmp  %g1, 3
a008985c:  02 80 00 1a  be  0xa00898c4
a0089860:  80 a0 60 11  cmp  %g1, 0x11
a0089864:  02 80 00 0c  be  0xa0089894
a0089868:  80 a0 60 12  cmp  %g1, 0x12
a008986c:  02 80 00 3f  be  0xa0089968
a0089870:  80 a0 60 13  cmp  %g1, 0x13
a0089874:  02 80 00 39  be  0xa0089958
a0089878:  80 a0 60 0f  cmp  %g1, 0xf
a008987c:  02 80 00 33  be  0xa0089948
a0089880:  80 a0 60 10  cmp  %g1, 0x10
a0089884:  02 80 00 2d  be  0xa0089938
a0089888:  80 a0 60 01  cmp  %g1, 1
a008988c:  02 80 00 12  be  0xa00898d4
a0089890:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a0089894:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a0089898:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a008989c:  82 10 20 05  mov  5, %g1
a00898a0:  c2 2b 60 1e  stb  %g1, [ %o5 + 0x1e ]
a00898a4:  ae 13 22 90  or  %o4, 0x290, %l7
a00898a8:  d2 0d e0 1e  ldub  [ %l7 + 0x1e ], %o1
a00898ac:  40 03 00 33  call  0xa0149978
a00898b0:  90 10 20 00  clr  %o0
a00898b4:  40 01 3e 61  call  0xa00d9238
a00898b8:  01 00 00 00  nop
a00898bc:  10 bf fd 9c  b  0xa0088f2c
a00898c0:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00898c4:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a00898c8:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a00898cc:  10 bf ff f5  b  0xa00898a0
a00898d0:  82 10 20 02  mov  2, %g1
a00898d4:  aa 13 22 90  or  %o4, 0x290, %l5
a00898d8:  10 bf ff f3  b  0xa00898a4
a00898dc:  c0 2d 60 1e  clrb  [ %l5 + 0x1e ]
a00898e0:  d0 0c a0 05  ldub  [ %l2 + 5 ], %o0
a00898e4:  80 a2 20 64  cmp  %o0, 0x64
a00898e8:  08 80 00 04  bleu  0xa00898f8
a00898ec:  01 00 00 00  nop
a00898f0:  90 10 20 64  mov  0x64, %o0	! 0x64
a00898f4:  d0 2c a0 05  stb  %o0, [ %l2 + 5 ]
a00898f8:  40 01 2a 04  call  0xa00d4108
a00898fc:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089900:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089904:  e8 0b 63 99  ldub  [ %o5 + 0x399 ], %l4	! 0xa802af99
a0089908:  10 bf fd 5e  b  0xa0088e80
a008990c:  82 15 20 02  or  %l4, 2, %g1
a0089910:  d0 0c a0 05  ldub  [ %l2 + 5 ], %o0
a0089914:  80 a2 20 64  cmp  %o0, 0x64
a0089918:  08 80 00 04  bleu  0xa0089928
a008991c:  01 00 00 00  nop
a0089920:  90 10 20 64  mov  0x64, %o0	! 0x64
a0089924:  d0 2c a0 05  stb  %o0, [ %l2 + 5 ]
a0089928:  40 01 2a e5  call  0xa00d44bc
a008992c:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089930:  10 bf ff f5  b  0xa0089904
a0089934:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089938:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008993c:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a0089940:  10 bf ff d8  b  0xa00898a0
a0089944:  82 10 20 0d  mov  0xd, %g1
a0089948:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008994c:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a0089950:  10 bf ff d4  b  0xa00898a0
a0089954:  82 10 20 0c  mov  0xc, %g1
a0089958:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008995c:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a0089960:  10 bf ff d0  b  0xa00898a0
a0089964:  82 10 20 07  mov  7, %g1
a0089968:  19 2a 00 b4  sethi  %hi(0xa802d000), %o4
a008996c:  9a 13 22 90  or  %o4, 0x290, %o5	! 0xa802d290
a0089970:  10 bf ff cc  b  0xa00898a0
a0089974:  82 10 20 06  mov  6, %g1
a0089978:  d0 0c a0 05  ldub  [ %l2 + 5 ], %o0
a008997c:  80 a2 20 64  cmp  %o0, 0x64
a0089980:  08 80 00 04  bleu  0xa0089990
a0089984:  01 00 00 00  nop
a0089988:  90 10 20 64  mov  0x64, %o0	! 0x64
a008998c:  d0 2c a0 05  stb  %o0, [ %l2 + 5 ]
a0089990:  40 01 2a 5f  call  0xa00d430c
a0089994:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089998:  10 bf ff db  b  0xa0089904
a008999c:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00899a0:  40 02 ea 6c  call  0xa0144350
a00899a4:  90 10 20 00  clr  %o0
a00899a8:  98 0a 20 ff  and  %o0, 0xff, %o4
a00899ac:  80 a3 20 01  cmp  %o4, 1
a00899b0:  32 bf fb be  bne,a   0xa00888a8
a00899b4:  a2 10 00 16  mov  %l6, %l1
a00899b8:  40 02 f7 59  call  0xa014771c
a00899bc:  90 10 20 00  clr  %o0
a00899c0:  10 bf ff d1  b  0xa0089904
a00899c4:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00899c8:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a00899cc:  da 0c a0 05  ldub  [ %l2 + 5 ], %o5
a00899d0:  98 12 a2 90  or  %o2, 0x290, %o4
a00899d4:  9e 10 20 03  mov  3, %o7
a00899d8:  80 a3 60 64  cmp  %o5, 0x64
a00899dc:  08 80 00 04  bleu  0xa00899ec
a00899e0:  de 2b 20 11  stb  %o7, [ %o4 + 0x11 ]
a00899e4:  9a 10 20 64  mov  0x64, %o5
a00899e8:  da 2c a0 05  stb  %o5, [ %l2 + 5 ]
a00899ec:  40 01 3f 50  call  0xa00d972c
a00899f0:  da 2b 20 14  stb  %o5, [ %o4 + 0x14 ]
a00899f4:  10 bf fd 4e  b  0xa0088f2c
a00899f8:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a00899fc:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0089a00:  98 13 62 90  or  %o5, 0x290, %o4	! 0xa802d290
a0089a04:  da 0c a0 05  ldub  [ %l2 + 5 ], %o5
a0089a08:  90 10 20 03  mov  3, %o0
a0089a0c:  80 a3 60 64  cmp  %o5, 0x64
a0089a10:  08 80 00 04  bleu  0xa0089a20
a0089a14:  d0 2b 20 11  stb  %o0, [ %o4 + 0x11 ]
a0089a18:  9a 10 20 64  mov  0x64, %o5
a0089a1c:  da 2c a0 05  stb  %o5, [ %l2 + 5 ]
a0089a20:  40 01 2b 03  call  0xa00d462c
a0089a24:  da 2b 20 13  stb  %o5, [ %o4 + 0x13 ]
a0089a28:  10 bf fd 41  b  0xa0088f2c
a0089a2c:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089a30:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0089a34:  da 0c a0 05  ldub  [ %l2 + 5 ], %o5
a0089a38:  98 10 62 90  or  %g1, 0x290, %o4
a0089a3c:  92 10 20 03  mov  3, %o1
a0089a40:  80 a3 60 64  cmp  %o5, 0x64
a0089a44:  08 80 00 04  bleu  0xa0089a54
a0089a48:  d2 2b 20 11  stb  %o1, [ %o4 + 0x11 ]
a0089a4c:  9a 10 20 64  mov  0x64, %o5
a0089a50:  da 2c a0 05  stb  %o5, [ %l2 + 5 ]
a0089a54:  40 01 2a e9  call  0xa00d45f8
a0089a58:  da 2b 20 12  stb  %o5, [ %o4 + 0x12 ]
a0089a5c:  10 bf fd 34  b  0xa0088f2c
a0089a60:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089a64:  c2 0c a0 05  ldub  [ %l2 + 5 ], %g1
a0089a68:  80 a0 60 0b  cmp  %g1, 0xb
a0089a6c:  18 80 00 42  bgu  0xa0089b74
a0089a70:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0089a74:  17 00 00 9f  sethi  %hi(0x27c00), %o3
a0089a78:  a5 28 60 02  sll  %g1, 2, %l2
a0089a7c:  a6 12 e1 d0  or  %o3, 0x1d0, %l3
a0089a80:  e0 04 c0 12  ld  [ %l3 + %l2 ], %l0
a0089a84:  81 c4 00 00  jmp  %l0
a0089a88:  01 00 00 00  nop
a0089a8c:  2b 2a 00 b4  sethi  %hi(0xa802d000), %l5
a0089a90:  a0 15 62 90  or  %l5, 0x290, %l0	! 0xa802d290
a0089a94:  e8 0c 20 11  ldub  [ %l0 + 0x11 ], %l4
a0089a98:  80 a5 20 09  cmp  %l4, 9
a0089a9c:  32 80 00 06  bne,a   0xa0089ab4
a0089aa0:  f6 0c a0 05  ldub  [ %l2 + 5 ], %i3
a0089aa4:  ae 10 20 01  mov  1, %l7
a0089aa8:  40 01 3f 2f  call  0xa00d9764
a0089aac:  ee 2c 20 11  stb  %l7, [ %l0 + 0x11 ]
a0089ab0:  f6 0c a0 05  ldub  [ %l2 + 5 ], %i3
a0089ab4:  40 01 38 cb  call  0xa00d7de0
a0089ab8:  f6 2c 20 0a  stb  %i3, [ %l0 + 0xa ]
a0089abc:  40 01 2b b7  call  0xa00d4998
a0089ac0:  01 00 00 00  nop
a0089ac4:  10 bf fd 1a  b  0xa0088f2c
a0089ac8:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089acc:  11 2a 00 b4  sethi  %hi(0xa802d000), %o0
a0089ad0:  a0 12 22 90  or  %o0, 0x290, %l0	! 0xa802d290
a0089ad4:  da 0c 20 11  ldub  [ %l0 + 0x11 ], %o5
a0089ad8:  80 a3 60 09  cmp  %o5, 9
a0089adc:  32 80 00 07  bne,a   0xa0089af8
a0089ae0:  d4 0c a0 05  ldub  [ %l2 + 5 ], %o2
a0089ae4:  9e 10 20 01  mov  1, %o7
a0089ae8:  de 2c 20 11  stb  %o7, [ %l0 + 0x11 ]
a0089aec:  40 01 3f 1e  call  0xa00d9764
a0089af0:  01 00 00 00  nop
a0089af4:  d4 0c a0 05  ldub  [ %l2 + 5 ], %o2
a0089af8:  40 01 3c 77  call  0xa00d8cd4
a0089afc:  d4 2c 20 09  stb  %o2, [ %l0 + 9 ]
a0089b00:  30 bf ff ef  b,a   0xa0089abc
a0089b04:  98 10 20 03  mov  3, %o4
a0089b08:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0089b0c:  96 13 62 90  or  %o5, 0x290, %o3	! 0xa802d290
a0089b10:  e2 0a e0 11  ldub  [ %o3 + 0x11 ], %l1
a0089b14:  ba 0b 20 ff  and  %o4, 0xff, %i5
a0089b18:  80 a4 40 1d  cmp  %l1, %i5
a0089b1c:  22 bf fb 63  be,a   0xa00888a8
a0089b20:  a2 10 00 16  mov  %l6, %l1
a0089b24:  d8 2a e0 11  stb  %o4, [ %o3 + 0x11 ]
a0089b28:  40 01 3f 0f  call  0xa00d9764
a0089b2c:  01 00 00 00  nop
a0089b30:  10 bf fc ff  b  0xa0088f2c
a0089b34:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089b38:  10 bf ff f4  b  0xa0089b08
a0089b3c:  98 10 20 07  mov  7, %o4
a0089b40:  10 bf ff f2  b  0xa0089b08
a0089b44:  98 10 20 00  clr  %o4
a0089b48:  10 bf ff f0  b  0xa0089b08
a0089b4c:  98 10 20 06  mov  6, %o4
a0089b50:  10 bf ff ee  b  0xa0089b08
a0089b54:  98 10 20 05  mov  5, %o4
a0089b58:  10 bf ff ec  b  0xa0089b08
a0089b5c:  98 10 20 01  mov  1, %o4
a0089b60:  10 bf ff ea  b  0xa0089b08
a0089b64:  98 10 20 02  mov  2, %o4
a0089b68:  10 bf ff e8  b  0xa0089b08
a0089b6c:  98 10 20 09  mov  9, %o4
a0089b70:  1b 2a 00 b4  sethi  %hi(0xa802d000), %o5
a0089b74:  b8 13 62 90  or  %o5, 0x290, %i4	! 0xa802d290
a0089b78:  10 bf ff e5  b  0xa0089b0c
a0089b7c:  d8 0f 20 11  ldub  [ %i4 + 0x11 ], %o4
a0089b80:  d2 0c a0 01  ldub  [ %l2 + 1 ], %o1
a0089b84:  80 a2 60 82  cmp  %o1, 0x82
a0089b88:  08 bf fc 3b  bleu  0xa0088c74
a0089b8c:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0089b90:  da 0c a0 04  ldub  [ %l2 + 4 ], %o5
a0089b94:  80 a3 60 ef  cmp  %o5, 0xef
a0089b98:  02 80 00 0f  be  0xa0089bd4
a0089b9c:  94 1b 60 e1  xor  %o5, 0xe1, %o2
a0089ba0:  80 a0 00 0a  cmp  %g0, %o2
a0089ba4:  98 60 3f ff  subx  %g0, -1, %o4
a0089ba8:  9e 1b 60 e9  xor  %o5, 0xe9, %o7
a0089bac:  80 a0 00 0f  cmp  %g0, %o7
a0089bb0:  9a 60 3f ff  subx  %g0, -1, %o5
a0089bb4:  80 93 00 0d  orcc  %o4, %o5, %g0
a0089bb8:  32 80 00 02  bne,a   0xa0089bc0
a0089bbc:  a6 10 20 1e  mov  0x1e, %l3
a0089bc0:  90 10 00 12  mov  %l2, %o0
a0089bc4:  40 01 15 c4  call  0xa00cf2d4
a0089bc8:  92 07 bf a8  add  %fp, -88, %o1
a0089bcc:  10 bf fc 2a  b  0xa0088c74
a0089bd0:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0089bd4:  10 bf ff fb  b  0xa0089bc0
a0089bd8:  a6 10 20 22  mov  0x22, %l3
a0089bdc:  d0 0c a0 04  ldub  [ %l2 + 4 ], %o0
a0089be0:  80 a2 20 10  cmp  %o0, 0x10
a0089be4:  02 80 00 34  be  0xa0089cb4
a0089be8:  80 a2 20 11  cmp  %o0, 0x11
a0089bec:  02 80 00 2b  be  0xa0089c98
a0089bf0:  80 a2 20 13  cmp  %o0, 0x13
a0089bf4:  12 bf fc 20  bne  0xa0088c74
a0089bf8:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0089bfc:  96 10 3f a0  mov  -96, %o3
a0089c00:  ae 10 20 3e  mov  0x3e, %l7
a0089c04:  d6 2f bf ae  stb  %o3, [ %fp + -82 ]
a0089c08:  ee 2f bf af  stb  %l7, [ %fp + -81 ]
a0089c0c:  b8 10 3f bb  mov  -69, %i4
a0089c10:  b6 10 3f cc  mov  -52, %i3
a0089c14:  f8 2f bf b0  stb  %i4, [ %fp + -80 ]
a0089c18:  10 bf fc 16  b  0xa0088c70
a0089c1c:  f6 2f bf b1  stb  %i3, [ %fp + -79 ]
a0089c20:  d0 0c a0 04  ldub  [ %l2 + 4 ], %o0
a0089c24:  80 a2 20 15  cmp  %o0, 0x15
a0089c28:  02 80 00 14  be  0xa0089c78
a0089c2c:  80 a2 20 25  cmp  %o0, 0x25
a0089c30:  12 bf fc 11  bne  0xa0088c74
a0089c34:  17 2a 00 ab  sethi  %hi(0xa802ac00), %o3
a0089c38:  40 02 93 00  call  0xa012e838
a0089c3c:  b8 10 3f bb  mov  -69, %i4
a0089c40:  40 02 93 00  call  0xa012e840
a0089c44:  d0 2f bf ae  stb  %o0, [ %fp + -82 ]
a0089c48:  10 bf ff f2  b  0xa0089c10
a0089c4c:  d0 2f bf af  stb  %o0, [ %fp + -81 ]
a0089c50:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0089c54:  d0 00 63 38  ld  [ %g1 + 0x338 ], %o0	! 0xa802d338
a0089c58:  82 10 20 01  mov  1, %g1
a0089c5c:  80 8a 20 80  btst  0x80, %o0
a0089c60:  c0 2f bf ae  clrb  [ %fp + -82 ]
a0089c64:  c2 2f bf af  stb  %g1, [ %fp + -81 ]
a0089c68:  02 bf fc 01  be  0xa0088c6c
a0089c6c:  c0 2f bf b0  clrb  [ %fp + -80 ]
a0089c70:  10 bf fc 00  b  0xa0088c70
a0089c74:  c2 2f bf b1  stb  %g1, [ %fp + -79 ]
a0089c78:  40 02 92 ed  call  0xa012e82c
a0089c7c:  a4 10 3f bb  mov  -69, %l2
a0089c80:  9e 10 3f aa  mov  -86, %o7
a0089c84:  d0 2f bf ae  stb  %o0, [ %fp + -82 ]
a0089c88:  de 2f bf af  stb  %o7, [ %fp + -81 ]
a0089c8c:  e4 2f bf b0  stb  %l2, [ %fp + -80 ]
a0089c90:  10 bf fd fc  b  0xa0089480
a0089c94:  82 10 3f cc  mov  -52, %g1
a0089c98:  ac 10 3f bb  mov  -69, %l6
a0089c9c:  aa 10 3f cc  mov  -52, %l5
a0089ca0:  ec 2f bf b0  stb  %l6, [ %fp + -80 ]
a0089ca4:  ea 2f bf b1  stb  %l5, [ %fp + -79 ]
a0089ca8:  c0 2f bf ae  clrb  [ %fp + -82 ]
a0089cac:  10 bf fb f1  b  0xa0088c70
a0089cb0:  c0 2f bf af  clrb  [ %fp + -81 ]
a0089cb4:  a8 10 20 05  mov  5, %l4
a0089cb8:  a0 10 20 3d  mov  0x3d, %l0
a0089cbc:  94 10 20 0c  mov  0xc, %o2
a0089cc0:  e8 2f bf ae  stb  %l4, [ %fp + -82 ]
a0089cc4:  e0 2f bf b0  stb  %l0, [ %fp + -80 ]
a0089cc8:  10 bf ff f9  b  0xa0089cac
a0089ccc:  d4 2f bf b1  stb  %o2, [ %fp + -79 ]
a0089cd0:  b6 10 3f ff  mov  -1, %i3
a0089cd4:  ba 10 20 02  mov  2, %i5
a0089cd8:  b8 10 20 01  mov  1, %i4
a0089cdc:  f6 2f bf af  stb  %i3, [ %fp + -81 ]
a0089ce0:  fa 2f bf b0  stb  %i5, [ %fp + -80 ]
a0089ce4:  f8 2f bf b1  stb  %i4, [ %fp + -79 ]
a0089ce8:  10 bf fb e2  b  0xa0088c70
a0089cec:  f6 2f bf ae  stb  %i3, [ %fp + -82 ]
a0089cf0:  17 2a 00 b4  sethi  %hi(0xa802d000), %o3
a0089cf4:  d8 0a e2 aa  ldub  [ %o3 + 0x2aa ], %o4	! 0xa802d2aa
a0089cf8:  10 bf fd 7d  b  0xa00892ec
a0089cfc:  9a 10 20 13  mov  0x13, %o5
a0089d00:  a0 10 20 04  mov  4, %l0
a0089d04:  c0 2f bf ae  clrb  [ %fp + -82 ]
a0089d08:  e0 2f bf af  stb  %l0, [ %fp + -81 ]
a0089d0c:  c0 2f bf b0  clrb  [ %fp + -80 ]
a0089d10:  40 02 e7 c1  call  0xa0143c14
a0089d14:  90 10 20 00  clr  %o0
a0089d18:  80 8a 20 ff  btst  0xff, %o0
a0089d1c:  22 bf fb d5  be,a   0xa0088c70
a0089d20:  e0 2f bf b1  stb  %l0, [ %fp + -79 ]
a0089d24:  40 02 e7 bc  call  0xa0143c14
a0089d28:  90 10 20 00  clr  %o0
a0089d2c:  ae 0a 20 ff  and  %o0, 0xff, %l7
a0089d30:  80 a5 e0 01  cmp  %l7, 1
a0089d34:  32 bf fd d3  bne,a   0xa0089480
a0089d38:  82 10 20 01  mov  1, %g1
a0089d3c:  10 bf fd d1  b  0xa0089480
a0089d40:  82 10 20 02  mov  2, %g1
a0089d44:  15 2a 00 b4  sethi  %hi(0xa802d000), %o2
a0089d48:  c2 0a a2 98  ldub  [ %o2 + 0x298 ], %g1	! 0xa802d298
a0089d4c:  9e 10 3f ff  mov  -1, %o7
a0089d50:  de 2f bf af  stb  %o7, [ %fp + -81 ]
a0089d54:  c0 2f bf ae  clrb  [ %fp + -82 ]
a0089d58:  80 a0 60 0a  cmp  %g1, 0xa
a0089d5c:  18 bf ff f8  bgu  0xa0089d3c
a0089d60:  c0 2f bf b0  clrb  [ %fp + -80 ]
a0089d64:  2d 00 00 9f  sethi  %hi(0x27c00), %l6
a0089d68:  a9 28 60 02  sll  %g1, 2, %l4
a0089d6c:  aa 15 a1 a4  or  %l6, 0x1a4, %l5
a0089d70:  e0 05 40 14  ld  [ %l5 + %l4 ], %l0
a0089d74:  81 c4 00 00  jmp  %l0
a0089d78:  01 00 00 00  nop
a0089d7c:  d0 0c a0 05  ldub  [ %l2 + 5 ], %o0
a0089d80:  80 a2 20 64  cmp  %o0, 0x64
a0089d84:  08 80 00 04  bleu  0xa0089d94
a0089d88:  01 00 00 00  nop
a0089d8c:  90 10 20 64  mov  0x64, %o0	! 0x64
a0089d90:  d0 2c a0 05  stb  %o0, [ %l2 + 5 ]
a0089d94:  40 01 29 08  call  0xa00d41b4
a0089d98:  90 0a 20 ff  and  %o0, 0xff, %o0
a0089d9c:  10 bf fe da  b  0xa0089904
a0089da0:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089da4:  40 01 49 4e  call  0xa00dc2dc
a0089da8:  01 00 00 00  nop
a0089dac:  10 bf fc 60  b  0xa0088f2c
a0089db0:  1b 2a 00 ab  sethi  %hi(0xa802ac00), %o5
a0089db4:  40 02 f7 7f  call  0xa0147bb0
a0089db8:  90 10 20 00  clr  %o0
a0089dbc:  80 a2 20 05  cmp  %o0, 5
a0089dc0:  02 bf fa ba  be  0xa00888a8
a0089dc4:  a2 10 00 16  mov  %l6, %l1
a0089dc8:  40 01 2e 60  call  0xa00d5748
a0089dcc:  01 00 00 00  nop
a0089dd0:  10 bf fa b7  b  0xa00888ac
a0089dd4:  80 8c 60 ff  btst  0xff, %l1
a0089dd8:  98 10 00 1c  mov  %i4, %o4
a0089ddc:  d0 0d 63 9a  ldub  [ %l5 + 0x39a ], %o0
a0089de0:  92 10 20 a0  mov  0xa0, %o1
a0089de4:  10 bf fd 02  b  0xa00891ec
a0089de8:  94 10 20 00  clr  %o2
a0089dec:  96 10 20 50  mov  0x50, %o3
a0089df0:  e4 0d 63 9a  ldub  [ %l5 + 0x39a ], %l2
a0089df4:  d6 2e e3 9e  stb  %o3, [ %i3 + 0x39e ]
a0089df8:  ee 2c 60 02  stb  %l7, [ %l1 + 2 ]
a0089dfc:  aa 10 20 6e  mov  0x6e, %l5
a0089e00:  b6 10 3f 85  mov  -123, %i3
a0089e04:  ae 10 3f ee  mov  -18, %l7
a0089e08:  ea 2c 40 00  stb  %l5, [ %l1 ]
a0089e0c:  f6 2c 60 01  stb  %i3, [ %l1 + 1 ]
a0089e10:  e6 2c 60 03  stb  %l3, [ %l1 + 3 ]
a0089e14:  ee 2c 60 04  stb  %l7, [ %l1 + 4 ]
a0089e18:  e4 2c 60 05  stb  %l2, [ %l1 + 5 ]
a0089e1c:  10 bf fd 18  b  0xa008927c
a0089e20:  d4 2c 60 06  stb  %o2, [ %l1 + 6 ]
a0089e24:  d4 0c a0 05  ldub  [ %l2 + 5 ], %o2
a0089e28:  90 5a a0 32  smul  %o2, 0x32, %o0
a0089e2c:  de 0c a0 04  ldub  [ %l2 + 4 ], %o7
a0089e30:  80 a3 e0 00  cmp  %o7, 0
a0089e34:  02 80 00 03  be  0xa0089e40
a0089e38:  82 02 2b b8  add  %o0, 0xbb8, %g1
a0089e3c:  82 10 3f ff  mov  -1, %g1
a0089e40:  ab 28 60 10  sll  %g1, 0x10, %l5
a0089e44:  29 00 00 05  sethi  %hi(0x1400), %l4
a0089e48:  9b 35 60 10  srl  %l5, 0x10, %o5
a0089e4c:  a0 15 22 75  or  %l4, 0x275, %l0
a0089e50:  80 a3 40 10  cmp  %o5, %l0
a0089e54:  18 80 00 08  bgu  0xa0089e74
a0089e58:  2f 00 00 06  sethi  %hi(0x1800), %l7
a0089e5c:  9a 10 20 02  mov  2, %o5
a0089e60:  03 2a 00 b4  sethi  %hi(0xa802d000), %g1
a0089e64:  10 bf ff 31  b  0xa0089b28
a0089e68:  da 28 62 a1  stb  %o5, [ %g1 + 0x2a1 ]	! 0xa802d2a1
a0089e6c:  10 bf fd 85  b  0xa0089480
a0089e70:  82 10 20 0d  mov  0xd, %g1
a0089e74:  a4 15 e3 57  or  %l7, 0x357, %l2
a0089e78:  80 a3 40 12  cmp  %o5, %l2
a0089e7c:  18 80 00 08  bgu  0xa0089e9c
a0089e80:  27 00 00 07  sethi  %hi(0x1c00), %l3
a0089e84:  10 bf ff f7  b  0xa0089e60
a0089e88:  9a 10 20 01  mov  1, %o5
a0089e8c:  10 bf fd 7d  b  0xa0089480
a0089e90:  82 10 20 08  mov  8, %g1
a0089e94:  10 bf fd 7b  b  0xa0089480
a0089e98:  82 10 20 09  mov  9, %g1
a0089e9c:  b6 14 e2 a9  or  %l3, 0x2a9, %i3
a0089ea0:  80 a3 40 1b  cmp  %o5, %i3
a0089ea4:  18 80 00 0c  bgu  0xa0089ed4
a0089ea8:  39 00 00 08  sethi  %hi(0x2000), %i4
a0089eac:  10 bf ff ed  b  0xa0089e60
a0089eb0:  9a 10 20 05  mov  5, %o5
a0089eb4:  10 bf fd 73  b  0xa0089480
a0089eb8:  82 10 20 0a  mov  0xa, %g1
a0089ebc:  10 bf fd 71  b  0xa0089480
a0089ec0:  82 10 20 04  mov  4, %g1
a0089ec4:  10 bf fd 6f  b  0xa0089480
a0089ec8:  82 10 20 03  mov  3, %g1
a0089ecc:  10 bf fd 6d  b  0xa0089480
a0089ed0:  82 10 20 05  mov  5, %g1
a0089ed4:  96 17 22 2d  or  %i4, 0x22d, %o3
a0089ed8:  80 a3 40 0b  cmp  %o5, %o3
a0089edc:  38 80 00 04  bgu,a   0xa0089eec
a0089ee0:  23 00 00 0a  sethi  %hi(0x2800), %l1
a0089ee4:  10 bf ff df  b  0xa0089e60
a0089ee8:  9a 10 20 06  mov  6, %o5
a0089eec:  ba 14 60 9f  or  %l1, 0x9f, %i5
a0089ef0:  80 a3 40 1d  cmp  %o5, %i5
a0089ef4:  38 bf ff db  bgu,a   0xa0089e60
a0089ef8:  9a 10 20 07  mov  7, %o5
a0089efc:  13 2a 00 b4  sethi  %hi(0xa802d000), %o1
a0089f00:  10 bf ff 0a  b  0xa0089b28
a0089f04:  c0 2a 62 a1  clrb  [ %o1 + 0x2a1 ]	! 0xa802d2a1
a0089f08:  81 c7 e0 08  ret
a0089f0c:  81 e8 00 00  restore
