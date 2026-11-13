! trap_set_irq_level_part1  (FUN_a00606f8)
!
! Read PSR and isolate the current interrupt level field.
! Note: Ghidra piece 1 of the routine 0xA00606F8..0xA006071F, not callable on its own; unreached: software-
!   trap slots (0x800+) are overlaid by trap_save_crash_state.
! Name basis: descriptive - PIL field (PSR bits 8..11) set from %i0, old PIL returned in %i0, rett %l2+4; no
!   reference to 0xA00606F8
!
! Matching notes
! --------------
! leon2s FUN_a00606f8 @ 0xa00606f8  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00606f8
	.type FUN_a00606f8, #function
FUN_a00606f8:
! Unreached: written as a software-trap handler, but no slot leads here (the software-trap slots from
! 0xA0060800 on hold trap_save_crash_state and other code). It sets the interrupt level to the value
! the caller passed in %o0 (%i0 in this window) and gives the old level back in the same register.
	rd  %psr, %l4                     ! %l4 = PSR
	srl  %l4, 8, %l5                  ! %l5 = PSR >> 8: the old interrupt level in the low four bits
	.size FUN_a00606f8, .-FUN_a00606f8
