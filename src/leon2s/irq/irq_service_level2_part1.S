! irq_service_level2_part1  (FUN_a00609fc)
!
! Enter the level-2 interrupt service routine (leaf, no handlers).
! Note: Ghidra piece 1 of the routine 0xA00609FC..0xA0060A57, not callable on its own; leaf routine:
!   acknowledges and re-enables the line without calling anything.
! Name basis: proven - vector table 0xA8076040 slot 1 = 0xA00609FC; bit 0x4 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a00609fc @ 0xa00609fc  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00609fc
	.type FUN_a00609fc, #function
FUN_a00609fc:
! Service routine of interrupt level 2 (entry 2 of the vector table at 0xA8076040),
! called by irq_entry. The level has no source handlers: the routine masks the level, marks it
! active in 0x9F120028, writes bit 0x4 to 0x9F120034 and to the LEON2 interrupt clear
! register, drops the active bit and unmasks the level again.
	sethi  %hi(0x9f100000), %o3       ! %o3 = 0x9F100000 (LEON2 interrupt registers)
	.size FUN_a00609fc, .-FUN_a00609fc
