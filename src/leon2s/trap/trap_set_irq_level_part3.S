! trap_set_irq_level_part3  (FUN_a0060710)
!
! Write PSR, return the previous level in %i0 and resume past the trap.
! Note: Ghidra piece 3 of the routine 0xA00606F8..0xA006071F, not callable on its own.
! Name basis: descriptive - PIL field (PSR bits 8..11) set from %i0, old PIL returned in %i0, rett %l2+4; no
!   reference to 0xA00606F8
!
! Matching notes
! --------------
! leon2s FUN_a0060710 @ 0xa0060710  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0060710
	.type FUN_a0060710, #function
FUN_a0060710:
! Part 3 of trap_set_irq_level (0xA00606F8..0xA006071F).
	mov  %l4, %psr                    ! write PSR
	and  %l5, 0xf, %i0                ! %i0 = the old level (0..15), seen by the caller in %o0
	jmp  %l2                          ! jump to the instruction after the 'ta' (its nPC)
	rett  %l2 + 4                     ! delay slot: return from the trap
	.size FUN_a0060710, .-FUN_a0060710
