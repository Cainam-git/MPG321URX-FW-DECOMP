! trap_return_from_ta1  (FUN_a0028810)
!
! Return from software trap 'ta 1' to the instruction after it.
! Note: Trap table slot tt 0x81 (base 0xA0028000 + 0x81 * 16); the trap does nothing else.
! Name basis: proven - position in the trap table (slot 0x81); jmp %l2 / rett %l2+4
!
! Matching notes
! --------------
! leon2m FUN_a0028810 @ 0xa0028810  MATCH (sparc-elf-as -Av8, asm)
! Kept as assembly, reproduced from the disassembly.
	.section ".text"
	.align 4
	.global FUN_a0028810
	.type FUN_a0028810, #function
FUN_a0028810:
! Slot of trap type 0x81, software trap 1 ('ta 1'). It does nothing but return: the program goes on with
! the instruction after the 'ta 1'. The reset code at 0xA0029000 raises 'ta 1' in an endless loop if
! startup_main ever returns.
	jmp  %l2                          ! jump to the instruction after the 'ta 1' (its nPC)
	rett  %l2 + 4                     ! delay slot: return from the trap; the next one comes from nPC + 4
	nop                               ! the rest of the 16-byte slot; never reached
	nop
	.size FUN_a0028810, .-FUN_a0028810
