! irq_service_level11_part1  (FUN_a0060fd0)
!
! Mask interrupt 11 (bit 0x800) in the LEON2 interrupt mask.
! Note: Ghidra piece 1 of the routine 0xA0060FD0..0xA006102B, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 10 = 0xA0060FD0; masks bit 0x800 of 0x9F100090, clears it
!   in 0x9F120034 / 0x9F10009C and unmasks it
!
! Matching notes
! --------------
! leon2s FUN_a0060fd0 @ 0xa0060fd0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060fd0
	.type FUN_a0060fd0, #function
FUN_a0060fd0:
! Service routine of interrupt level 11 (entry 11 of the vector table at 0xA8076040),
! called by irq_entry. The level has no source handlers: the routine masks the level, marks it
! active in 0x9F120028, writes bit 0x800 to 0x9F120034 and to the LEON2 interrupt clear
! register, drops the active bit and unmasks the level again.
	sethi  %hi(0x9f100000), %o3       ! %o3 = 0x9F100000 (LEON2 interrupt registers)
	or  %o3, 0x90, %o2                ! %o2 = the LEON2 interrupt mask register
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	and  %g1, -2049, %g1              ! clear bit 0x800: level 11 masked while it is served
	.size FUN_a0060fd0, .-FUN_a0060fd0
