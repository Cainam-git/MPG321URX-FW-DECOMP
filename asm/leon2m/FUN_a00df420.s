# leon2m FUN_a00df420 0xa00df420-0xa00df450 (48 bytes)
a00df420:  9d e3 bf 98  save  %sp, -104, %sp
a00df424:  31 30 02 c0  sethi  %hi(0xc00b0000), %i0
a00df428:  67 fe b3 8a  call  0x4008c250
a00df42c:  90 16 20 14  or  %i0, 0x14, %o0	! 0xc00b0014
a00df430:  80 8a 20 01  btst  1, %o0
a00df434:  02 bf ff fd  be  0xa00df428
a00df438:  01 00 00 00  nop
a00df43c:  67 fe b3 85  call  0x4008c250
a00df440:  11 30 02 c0  sethi  %hi(0xc00b0000), %o0
a00df444:  b0 0a 20 ff  and  %o0, 0xff, %i0
a00df448:  81 c7 e0 08  ret
a00df44c:  81 e8 00 00  restore
