! irq_service_level8_part1  (FUN_a0060e1c)
!
! Enter the level-8 interrupt service routine (leaf, no handlers).
! Note: Ghidra piece 1 of the routine 0xA0060E1C..0xA0060E77, not callable on its own.
! Name basis: proven - vector table 0xA8076040 slot 7 = 0xA0060E1C; bit 0x100 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060e1c @ 0xa0060e1c  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060e1c
	.type FUN_a0060e1c, #function
FUN_a0060e1c:
! Service routine of interrupt level 8 (entry 8 of the vector table at 0xA8076040),
! called by irq_entry. The level has no source handlers: the routine masks the level, marks it
! active in 0x9F120028, writes bit 0x100 to 0x9F120034 and to the LEON2 interrupt clear
! register, drops the active bit and unmasks the level again.
	sethi  %hi(0x9f100000), %o3       ! %o3 = 0x9F100000 (LEON2 interrupt registers)
	.size FUN_a0060e1c, .-FUN_a0060e1c
