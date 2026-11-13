! irq_service_level7_part1  (FUN_a0060dc0)
!
! Mask interrupt 7 (bit 0x80) in the LEON2 interrupt mask (leaf, no handlers).
! Note: Ghidra piece 1 of the routine 0xA0060DC0..0xA0060E1B, not callable on its own; leaf routine:
!   acknowledges and re-enables the line without calling anything.
! Name basis: proven - vector table 0xA8076040 slot 6 = 0xA0060DC0; bit 0x80 masked, cleared (0x9F120034,
!   0x9F10009C) and unmasked, nothing called
!
! Matching notes
! --------------
! leon2s FUN_a0060dc0 @ 0xa0060dc0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060dc0
	.type FUN_a0060dc0, #function
FUN_a0060dc0:
! Service routine of interrupt level 7 (entry 7 of the vector table at 0xA8076040),
! called by irq_entry. The level has no source handlers: the routine masks the level, marks it
! active in 0x9F120028, writes bit 0x80 to 0x9F120034 and to the LEON2 interrupt clear
! register, drops the active bit and unmasks the level again.
	sethi  %hi(0x9f100000), %o3       ! %o3 = 0x9F100000 (LEON2 interrupt registers)
	or  %o3, 0x90, %o2                ! %o2 = the LEON2 interrupt mask register
	ld  [ %o2 ], %g1                  ! read the interrupt mask
	and  %g1, -129, %g1               ! clear bit 0x80: level 7 masked while it is served
	.size FUN_a0060dc0, .-FUN_a0060dc0
