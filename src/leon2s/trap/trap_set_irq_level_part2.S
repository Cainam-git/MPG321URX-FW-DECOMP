! trap_set_irq_level_part2  (FUN_a0060700)
!
! Replace the PSR interrupt level with the value from %i0.
! Note: Ghidra piece 2 of the routine 0xA00606F8..0xA006071F, not callable on its own.
! Name basis: descriptive - PIL field (PSR bits 8..11) set from %i0, old PIL returned in %i0, rett %l2+4; no
!   reference to 0xA00606F8
!
! Matching notes
! --------------
! leon2s FUN_a0060700 @ 0xa0060700  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060700
	.type FUN_a0060700, #function
FUN_a0060700:
! Part 2 of trap_set_irq_level (0xA00606F8..0xA006071F).
	andn  %l4, 0xf00, %l4             ! PSR without its interrupt level
	sll  %i0, 8, %i0                  ! the new level, moved to bits 8..11
	and  %i0, 0xf00, %i0              ! keep only those four bits
	or  %i0, %l4, %l4                 ! PSR with the new level
	.size FUN_a0060700, .-FUN_a0060700
