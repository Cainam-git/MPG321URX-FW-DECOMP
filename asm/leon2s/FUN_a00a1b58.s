# leon2s FUN_a00a1b58 0xa00a1b58-0xa00a1b80 (40 bytes)
a00a1b58:  9d e3 bf 98  save  %sp, -104, %sp
a00a1b5c:  03 2a 01 f5  sethi  %hi(0xa807d400), %g1
a00a1b60:  82 10 63 e0  or  %g1, 0x3e0, %g1	! 0xa807d7e0
a00a1b64:  b0 5e 21 90  smul  %i0, 0x190, %i0
a00a1b68:  b0 06 00 01  add  %i0, %g1, %i0
a00a1b6c:  82 10 20 01  mov  1, %g1
a00a1b70:  7f ff ff c4  call  0xa00a1a80
a00a1b74:  c2 2e 20 03  stb  %g1, [ %i0 + 3 ]
a00a1b78:  81 c7 e0 08  ret
a00a1b7c:  91 e8 20 00  restore  %g0, 0, %o0
