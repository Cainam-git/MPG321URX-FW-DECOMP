! irq_service_level9_part1  (FUN_a0060e78)
!
! Enter the level-9 interrupt service routine (leaf, no handlers).
! Note: Ghidra piece 1 of the routine 0xA0060E78..0xA0060ED3, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 8 = 0xA0060E78; bit 0x200 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060e78 @ 0xa0060e78  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060e78
	.type FUN_a0060e78, #function
FUN_a0060e78:
! Service routine of interrupt level 9 (entry 9 of the vector table at 0xA8076040),
! called by irq_entry. The level has no source handlers: the routine masks the level, marks it
! active in 0x9F120028, writes bit 0x200 to 0x9F120034 and to the LEON2 interrupt clear
! register, drops the active bit and unmasks the level again.
	sethi  %hi(0x9f100000), %o3       ! %o3 = 0x9F100000 (LEON2 interrupt registers)
	or  %o3, 0x90, %o2                ! %o2 = the LEON2 interrupt mask register
	.size FUN_a0060e78, .-FUN_a0060e78
