! trap_raise_software_trap_2  (FUN_a00606f0)
!
! Return to the caller and raise software trap 2 in the delay slot.
! Note: Sits in the trap table slot of type 0x6F.
! Name basis: descriptive - the two instructions 'retl; ta 2'
!
! Matching notes
! --------------
! leon2s FUN_a00606f0 @ 0xa00606f0  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a00606f0
	.type FUN_a00606f0, #function
FUN_a00606f0:
! This slot (trap type 0x6F) holds a two-instruction routine, not a trap handler: return to the caller
! and raise software trap 2 in the delay slot. In the SPARC ABI software trap 2 is the divide-by-zero
! trap; the main processor has the same pair at 0xA0029430. In this program the slot of trap type 0x82
! (0xA0060820) lies inside trap_save_crash_state.
	retl                              ! return to the caller
	ta  2                             ! delay slot: raise software trap 2 (trap type 0x82)
	.size FUN_a00606f0, .-FUN_a00606f0
