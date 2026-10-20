# leon2m FUN_a01129e4 0xa01129e4-0xa0112b2c (328 bytes)  [FUN_a0112b24 = unreachable ret/restore tail, merged]
a01129e4:  9d e3 bf 98  save  %sp, -104, %sp
a01129e8:  82 0e 20 ff  and  %i0, 0xff, %g1
a01129ec:  92 10 00 19  mov  %i1, %o1
a01129f0:  80 a0 60 13  cmp  %g1, 0x13
a01129f4:  18 80 00 4b  bgu  0xa0112b20
a01129f8:  b2 10 00 1a  mov  %i2, %i1
a01129fc:  11 00 02 c6  sethi  %hi(0xb1800), %o0
a0112a00:  83 28 60 02  sll  %g1, 2, %g1
a0112a04:  9a 12 20 34  or  %o0, 0x34, %o5
a0112a08:  d8 03 40 01  ld  [ %o5 + %g1 ], %o4
a0112a0c:  81 c3 00 00  jmp  %o4
a0112a10:  01 00 00 00  nop
a0112a14:  17 33 c0 56  sethi  %hi(0xcf015800), %o3
a0112a18:  b0 12 e3 40  or  %o3, 0x340, %i0	! 0xcf015b40
a0112a1c:  b2 10 00 09  mov  %o1, %i1
a0112a20:  7f ff 81 c5  call  0xa00f3134
a0112a24:  81 e8 00 00  restore
a0112a28:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a0112a2c:  7f ff 81 c2  call  0xa00f3134
a0112a30:  90 16 20 80  or  %i0, 0x80, %o0	! 0xcf011880
a0112a34:  90 16 20 90  or  %i0, 0x90, %o0
a0112a38:  7f ff 81 bf  call  0xa00f3134
a0112a3c:  92 10 00 1a  mov  %i2, %o1
a0112a40:  b0 16 20 a0  or  %i0, 0xa0, %i0
a0112a44:  b2 10 00 1b  mov  %i3, %i1
a0112a48:  7f ff 81 bb  call  0xa00f3134
a0112a4c:  81 e8 00 00  restore
a0112a50:  35 33 c0 46  sethi  %hi(0xcf011800), %i2
a0112a54:  7f ff 81 b8  call  0xa00f3134
a0112a58:  90 16 a0 b0  or  %i2, 0xb0, %o0	! 0xcf0118b0
a0112a5c:  92 10 00 19  mov  %i1, %o1
a0112a60:  7f ff 81 b5  call  0xa00f3134
a0112a64:  90 16 a0 c0  or  %i2, 0xc0, %o0
a0112a68:  b0 16 a0 d0  or  %i2, 0xd0, %i0
a0112a6c:  10 bf ff f7  b  0xa0112a48
a0112a70:  b2 10 00 1b  mov  %i3, %i1
a0112a74:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a0112a78:  7f ff 81 af  call  0xa00f3134
a0112a7c:  90 16 20 e0  or  %i0, 0xe0, %o0	! 0xcf0118e0
a0112a80:  90 16 20 f0  or  %i0, 0xf0, %o0
a0112a84:  7f ff 81 ac  call  0xa00f3134
a0112a88:  92 10 00 1a  mov  %i2, %o1
a0112a8c:  b0 16 21 00  or  %i0, 0x100, %i0
a0112a90:  10 bf ff ee  b  0xa0112a48
a0112a94:  b2 10 00 1b  mov  %i3, %i1
a0112a98:  35 33 c0 46  sethi  %hi(0xcf011800), %i2
a0112a9c:  7f ff 81 a6  call  0xa00f3134
a0112aa0:  90 16 a1 10  or  %i2, 0x110, %o0	! 0xcf011910
a0112aa4:  92 10 00 19  mov  %i1, %o1
a0112aa8:  7f ff 81 a3  call  0xa00f3134
a0112aac:  90 16 a1 20  or  %i2, 0x120, %o0
a0112ab0:  b0 16 a1 30  or  %i2, 0x130, %i0
a0112ab4:  10 bf ff e5  b  0xa0112a48
a0112ab8:  b2 10 00 1b  mov  %i3, %i1
a0112abc:  31 33 c0 46  sethi  %hi(0xcf011800), %i0
a0112ac0:  7f ff 81 9d  call  0xa00f3134
a0112ac4:  90 16 21 40  or  %i0, 0x140, %o0	! 0xcf011940
a0112ac8:  90 16 21 50  or  %i0, 0x150, %o0
a0112acc:  7f ff 81 9a  call  0xa00f3134
a0112ad0:  92 10 00 1a  mov  %i2, %o1
a0112ad4:  b0 16 21 60  or  %i0, 0x160, %i0
a0112ad8:  10 bf ff dc  b  0xa0112a48
a0112adc:  b2 10 00 1b  mov  %i3, %i1
a0112ae0:  15 33 c0 46  sethi  %hi(0xcf011800), %o2
a0112ae4:  b0 12 a1 70  or  %o2, 0x170, %i0	! 0xcf011970
a0112ae8:  10 bf ff ce  b  0xa0112a20
a0112aec:  b2 10 00 09  mov  %o1, %i1
a0112af0:  37 33 c0 3d  sethi  %hi(0xcf00f400), %i3
a0112af4:  7f ff 81 90  call  0xa00f3134
a0112af8:  90 16 e1 10  or  %i3, 0x110, %o0	! 0xcf00f510
a0112afc:  b0 16 e1 20  or  %i3, 0x120, %i0
a0112b00:  7f ff 81 8d  call  0xa00f3134
a0112b04:  81 e8 00 00  restore
a0112b08:  35 33 c0 3d  sethi  %hi(0xcf00f400), %i2
a0112b0c:  7f ff 81 8a  call  0xa00f3134
a0112b10:  90 16 a1 90  or  %i2, 0x190, %o0	! 0xcf00f590
a0112b14:  b0 16 a1 a0  or  %i2, 0x1a0, %i0
a0112b18:  7f ff 81 87  call  0xa00f3134
a0112b1c:  81 e8 00 00  restore
a0112b20:  01 00 00 00  nop
a0112b24:  81 c7 e0 08  ret
a0112b28:  81 e8 00 00  restore
